/***********************************************************************************************************************
**
** Copyright (C) 2021 BaseALT Ltd. <org@basealt.ru>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
***********************************************************************************************************************/

#include "../../core/pluginstorage.h"
#include "../../core/snapinloader.h"
#include "../../core/snapinmanager.h"

#include "../../core/compositesnapindetailsdialog.h"
#include "../../core/snapindetailsdialog.h"
#include "../../core/snapindetailsfactory.h"

#include "../../gui/commandlineparser.h"
#include "../../gui/mainwindow.h"

#include <memory>

#include <QApplication>

int main(int argc, char **argv)
{
    preferences_editor::SnapInDetailsFactory::define<preferences_editor::SnapInDetailsDialog>(
        "ISnapIn");
    preferences_editor::SnapInDetailsFactory::define<preferences_editor::CompositeSnapInDetailsDialog>(
        "ICompositeSnapIn");

    // Load plugins.
    auto snapInManager = std::make_unique<preferences_editor::SnapInManager>();

    auto snapInLoader = std::make_unique<preferences_editor::SnapInLoader>(snapInManager.get());

    auto pluginDirectory = QDir("./build/lib64/preferences_editor/plugins/");

    snapInLoader->loadSnapIns(pluginDirectory);

    for (auto &snapIn : snapInManager->getSnapIns())
    {
        snapIn->onInitialize();

        qWarning() << snapIn->getDisplayName();
    }

    // Create window.
    QApplication app(argc, argv);

    // NOTE: set app variables which will be used to
    // construct settings path
    app.setOrganizationName(QCoreApplication::translate("main", "BaseALT Ltd."));
    app.setOrganizationDomain("basealt.ru");
    app.setApplicationName("Preferences Editor");
    app.setApplicationVersion("0.2.0");

    preferences_editor::CommandLineParser parser(app);
    preferences_editor::CommandLineOptions options{};
    QString errorMessage{};

    preferences_editor::CommandLineParser::CommandLineParseResult parserResult
        = parser.parseCommandLine(&options, &errorMessage);

    QLocale locale;
    std::unique_ptr<QTranslator> qtTranslator = std::make_unique<QTranslator>();
    qtTranslator->load(locale, "gui", "_", ":/");
    std::unique_ptr<QTranslator> qtTranslator2 = std::make_unique<QTranslator>();
    qtTranslator2->load(QString("qt_").append(QLocale::system().name()),
                        QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    QCoreApplication::installTranslator(qtTranslator.get());
    QCoreApplication::installTranslator(qtTranslator2.get());

    switch (parserResult)
    {
    case preferences_editor::CommandLineParser::CommandLineError:
        printf("%s \n", qPrintable(errorMessage));
        parser.showHelp();
        return 1;
    case preferences_editor::CommandLineParser::CommandLineHelpRequested:
        parser.showHelp();
        return 0;
    case preferences_editor::CommandLineParser::CommandLineVersionRequested:
        parser.showVersion();
        return 0;
    case preferences_editor::CommandLineParser::CommandLineOk:
    default:
        break;
    }

    preferences_editor::MainWindow window(options, nullptr, snapInManager.get());
    window.show();

    return app.exec();
}
