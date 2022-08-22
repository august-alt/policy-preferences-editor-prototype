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

#include "mainwindow.h"
#include "mainwindowsettings.h"
#include "ui_mainwindow.h"

#include "aboutdialog.h"

#include "commandlineoptions.h"

#include "treevieweventfilter.h"

#include "editorpreferencesdialog.h"

#include "../io/registryfileformat.h"

#include "../io/genericreader.h"
#include "../io/registryfileformat.h"

#include "../io/policyfileformat.h"

#include "../io/inifile.h"

#include "../plugins/storage/smb/smbfile.h"

#include "../core/isnapinmanager.h"

void registerResources()
{
    Q_INIT_RESOURCE(translations);
}

namespace preferences_editor
{
class MainWindowPrivate
{
public:
    std::unique_ptr<QStandardItemModel> model    = nullptr;
    std::unique_ptr<MainWindowSettings> settings = nullptr;

    std::unique_ptr<QSortFilterProxyModel> itemNameSortModel = nullptr;
    std::unique_ptr<QSortFilterProxyModel> itemRoleSortModel = nullptr;
    std::unique_ptr<QSortFilterProxyModel> searchModel       = nullptr;

    ISnapInManager *manager = nullptr;

    std::vector<std::unique_ptr<QTranslator>> translators{};
    QString localeName{};

    QString itemName{};

    QIcon windowIcon{};

    CommandLineOptions options{};

    std::unique_ptr<TreeViewEventFilter> eventFilter = nullptr;

    MainWindowPrivate()
        : eventFilter(new TreeViewEventFilter())
    {}

private:
    MainWindowPrivate(const MainWindowPrivate &) = delete;            // copy ctor
    MainWindowPrivate(MainWindowPrivate &&)      = delete;            // move ctor
    MainWindowPrivate &operator=(const MainWindowPrivate &) = delete; // copy assignment
    MainWindowPrivate &operator=(MainWindowPrivate &&) = delete;      // move assignment
};

MainWindow::MainWindow(CommandLineOptions &options, QWidget *parent, ISnapInManager *manager)
    : QMainWindow(parent)
    , d(new MainWindowPrivate())
    , ui(new Ui::MainWindow())
{
    registerResources();

    d->manager = manager;

    d->options = options;

    ui->setupUi(this);

    ui->treeView->installEventFilter(d->eventFilter.get());

    d->settings = std::make_unique<MainWindowSettings>(this, ui);
    d->settings->restoreSettings();

    createLanguageMenu();

    connect(d->eventFilter.get(), &TreeViewEventFilter::onEnter, this, [&]() {
        ui->treeView->clicked(ui->treeView->currentIndex());
    });

    connect(ui->actionOpenPolicyDirectory, &QAction::triggered, this, &MainWindow::onDirectoryOpen);
    connect(ui->actionSaveRegistrySource,
            &QAction::triggered,
            this,
            &MainWindow::onRegistrySourceSave);
    connect(ui->treeView, &QTreeView::clicked, [&](const QModelIndex &index) {
        qWarning() << index.data().toString();
    });
    connect(ui->treeView, &QTreeView::clicked, [&](const QModelIndex &index) {
        d->itemName = index.data().toString();
    });

    QLocale locale(!d->localeName.trimmed().isEmpty() ? d->localeName.replace("-", "_")
                                                      : QLocale::system().name().replace("-", "_"));
    std::unique_ptr<QTranslator> qtTranslator = std::make_unique<QTranslator>();
    qtTranslator->load(locale, "gui", "_", ":/");
    QCoreApplication::installTranslator(qtTranslator.get());
    d->translators.push_back(std::move(qtTranslator));
    d->localeName = locale.name().replace("_", "-");
    ui->retranslateUi(this);

    d->windowIcon = QIcon(":logo.png");

    QGuiApplication::setWindowIcon(d->windowIcon);

    if (d->options.policyBundle.isEmpty())
    {
        d->options.policyBundle = "/usr/share/PolicyDefinitions";
    }

    loadPolicyBundleFolder(d->options.policyBundle, d->localeName);

    for (auto &snapIn : manager->getSnapIns())
    {
        if (snapIn->getRootNode())
        {
            ui->treeView->setModel(snapIn->getRootNode());
            ui->treeView->setColumnHidden(1, true);
            ui->treeView->resizeColumnToContents(0);
        }
    }

    if (!d->options.path.isEmpty())
    {
        onIniFileOpen(d->options.path + "/gpt.ini");
    }

    if (!d->options.policyName.isEmpty())
    {
        setWindowTitle("Preferences Editor - " + d->options.policyName);
    }

    connect(ui->searchLineEdit, &QLineEdit::textChanged, [&](const QString &text) {
        d->searchModel->setFilterFixedString(text);
    });
}

MainWindow::~MainWindow()
{
    delete d;

    delete ui;
}

void MainWindow::setLanguage(const QString &language)
{
    d->localeName = language;
}

QString MainWindow::getLanguage() const
{
    return d->localeName;
}

void MainWindow::setAdmxPath(const QString &admxPath)
{
    if (d->options.policyBundle.trimmed().isEmpty())
    {
        d->options.policyBundle = admxPath;
    }
}

QString MainWindow::getAdmxPath() const
{
    return d->options.policyBundle;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    d->settings->saveSettings();

    QMainWindow::closeEvent(event);
}

void preferences_editor::MainWindow::loadPolicyBundleFolder(const QString &path,
                                                            const QString &locale)
{
    Q_UNUSED(path);
    Q_UNUSED(locale);
}

void MainWindow::onDirectoryOpen()
{
    std::unique_ptr<QFileDialog> fileDialog = std::make_unique<QFileDialog>(this);

    fileDialog->setDirectory(QDir::homePath());
    fileDialog->setFileMode(QFileDialog::Directory);
    fileDialog->setSupportedSchemes(QStringList(QStringLiteral("file")));

    fileDialog->setLabelText(QFileDialog::Accept, tr("Open"));
    fileDialog->setLabelText(QFileDialog::FileName, tr("File name"));
    fileDialog->setLabelText(QFileDialog::LookIn, tr("Look in"));
    fileDialog->setLabelText(QFileDialog::Reject, tr("Cancel"));
    fileDialog->setLabelText(QFileDialog::FileType, tr("File type"));

    fileDialog->setNameFilter(QObject::tr("All files (*.*)"));
    fileDialog->setOptions(QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
                           | QFileDialog::DontUseNativeDialog);

    fileDialog->setWindowIcon(d->windowIcon);
    fileDialog->setWindowTitle(tr("Open Directory"));

    if (fileDialog->exec() == QDialog::Accepted)
    {
        d->options.policyBundle = fileDialog->selectedUrls()[0].toLocalFile();
        loadPolicyBundleFolder(d->options.policyBundle, d->localeName);
    }
}

void MainWindow::onRegistrySourceSave()
{
    ui->statusbar->showMessage(tr("Applied changes for policy: ") + d->itemName);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionManual_triggered() {}

void MainWindow::on_actionAbout_triggered()
{
    auto about = new AboutDialog(this);
    about->show();
}

void MainWindow::on_actionPreferences_triggered()
{
    auto snapInManagementWidget = new EditorPreferencesDialog(this, d->manager);

    snapInManagementWidget->show();
}

void MainWindow::onLanguageChanged(QAction *action)
{
    for (const auto &translator : d->translators)
    {
        qApp->removeTranslator(translator.get());
    }
    d->translators.clear();

    QString language = action->data().toString();

    std::unique_ptr<QTranslator> qtTranslator = std::make_unique<QTranslator>();
    bool loadResult                           = qtTranslator->load("gui_" + language + ".qm", ":/");
    QCoreApplication::installTranslator(qtTranslator.get());
    d->translators.push_back(std::move(qtTranslator));
    qWarning() << "Load language " << language << loadResult;

    QLocale locale(language);

    d->localeName = locale.name().replace("_", "-");

    loadPolicyBundleFolder(d->options.policyBundle, d->localeName);

    ui->retranslateUi(this);

    ui->treeView->selectionModel()->clearSelection();
}

void MainWindow::onIniFileOpen(const QString &path)
{
    qWarning() << "Path recieved: " << path;

    auto stringvalues = std::make_unique<std::string>();

    try
    {
        if (path.startsWith("smb://"))
        {
            preferences_editor::smb::SmbFile smbLocationItemFile(path);
            smbLocationItemFile.open(QFile::ReadOnly);
            stringvalues->resize(smbLocationItemFile.size(), 0);
            smbLocationItemFile.read(&stringvalues->at(0), smbLocationItemFile.size());
            smbLocationItemFile.close();
        }
        else
        {
            QFile registryFile(path);
            registryFile.open(QFile::ReadWrite);
            stringvalues->resize(registryFile.size(), 0);
            registryFile.read(&stringvalues->at(0), registryFile.size());
            registryFile.close();
        }

        auto iss = std::make_unique<std::istringstream>(*stringvalues);
        std::string pluginName("ini");

        auto reader  = std::make_unique<io::GenericReader>();
        auto iniFile = reader->load<io::IniFile, io::PolicyFileFormat<io::IniFile>>(*iss,
                                                                                    pluginName);
        if (!iniFile)
        {
            qWarning() << "Unable to load registry file contents.";
            return;
        }

        auto sections = iniFile->getAllSections();

        if (d->options.policyName.isEmpty() && sections->find("General") != sections->end())
        {
            auto &generalValues = (*sections)["General"];

            auto displayName = generalValues.find("displayName");

            if (displayName != generalValues.end())
            {
                qWarning() << "display name " << displayName.value().c_str();

                setWindowTitle(
                    QString::fromStdString("PREFERENCES_EDITOR - " + displayName.value()));
            }
        }
    }
    catch (std::exception &e)
    {
        qWarning() << "Warning: Unable to read file: " << qPrintable(path)
                   << " description: " << e.what();
    }
}

void MainWindow::createLanguageMenu()
{
    QActionGroup *langGroup = new QActionGroup(this);
    langGroup->setExclusive(true);

    connect(langGroup, &QActionGroup::triggered, this, &MainWindow::onLanguageChanged);

    QString defaultLocale = d->localeName.left(QLocale::system().name().lastIndexOf('_'));
    QDir dir(":/");
    QStringList fileNames = dir.entryList(QStringList("gui_*.qm"));

    QMenu *menu = new QMenu(this);
    ui->actionLanguage->setMenu(menu);

    for (QString locale : fileNames)
    {
        locale.truncate(locale.lastIndexOf('.'));
        locale.remove(0, locale.lastIndexOf('_') + 1);

        QString language = QLocale::languageToString(QLocale(locale).language());

        QAction *action = new QAction(language, this);
        action->setCheckable(true);
        action->setData(locale);

        menu->addAction(action);
        langGroup->addAction(action);

        if (defaultLocale == locale)
        {
            action->setChecked(true);
        }
    }
}

} // namespace preferences_editor
