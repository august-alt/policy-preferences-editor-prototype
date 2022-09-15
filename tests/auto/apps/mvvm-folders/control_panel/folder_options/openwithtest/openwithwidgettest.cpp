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

#include "openwithwidgettest.h"

#include <fstream>

#include <folder_options/openwithitem.h>
#include <folder_options/openwithwidget.h>
#include <folder_options/folderoptionsmodelbuilder.h>
#include <folder_options/folderoptionswidget.h>

//const std::string dataPath = "../../../../data/preferences/";
const std::string dataPath = "/home/antpro/Develop/policy-preferences-editor-prototype/tests/data/preferences/machine/control_panel/folder_options/";

using namespace mvvm_folders;

namespace tests
{
std::unique_ptr<OpenWithWidget> OpenWithWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<OpenWithWidget> openWidget = nullptr;

    try {
        auto files = FolderOptions_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<FolderOptionsModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        openWidget = std::make_unique<OpenWithWidget>();
        auto containerItem = model->topItem();
        auto openrContainer = dynamic_cast<OpenWithItem*>(containerItem);

        if (!openrContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        openWidget->setItem(openrContainer->children().back());
        openWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return openWidget;
}

void OpenWithWidgetTest::checkWidget()
{
    QFETCH(QString, dataPath);
    QFETCH(bool, fileProgramLineEditState);
    QFETCH(bool, associatedProgramLineEditState);
    QFETCH(bool, defaultCheckBoxState);
    QFETCH(bool, associatedProgramToolButtonState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto fileProgramLineEdit            = widget->findChild<QLineEdit*>     ("fileProgramLineEdit");
    auto associatedProgramLineEdit      = widget->findChild<QLineEdit*>     ("associatedProgramLineEdit");
    auto associatedProgramToolButton    = widget->findChild<QToolButton*>   ("associatedProgramToolButton");
    auto defaultCheckBox                = widget->findChild<QCheckBox*>     ("associatedProgramToolButton");

    QTest::qWait(1000);

    QVERIFY(fileProgramLineEdit);
    QVERIFY(associatedProgramLineEdit);
    QVERIFY(associatedProgramToolButton);
    QVERIFY(defaultCheckBox);

    QCOMPARE(fileProgramLineEdit        ->isEnabled(), fileProgramLineEditState);
    QCOMPARE(associatedProgramLineEdit  ->isEnabled(), associatedProgramLineEditState);
    QCOMPARE(associatedProgramToolButton->isEnabled(), associatedProgramToolButtonState);
    QCOMPARE(defaultCheckBox            ->isEnabled(), defaultCheckBoxState);

}

void OpenWithWidgetTest::checkWidget_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("fileProgramLineEditState");
    QTest::addColumn<bool>("associatedProgramLineEditState");
    QTest::addColumn<bool>("associatedProgramToolButtonState");
    QTest::addColumn<bool>("defaultCheckBoxState");

    QTest::addRow("Open") << QString::fromStdString(dataPath + "openwith.xml") << true << true  << true << true ;

}

}

QTEST_MAIN(tests::OpenWithWidgetTest)

