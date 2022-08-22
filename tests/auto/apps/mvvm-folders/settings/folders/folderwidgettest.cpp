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

#include "folderwidgettest.h"

#include <fstream>

#include "folders/foldercontaineritem.h"
#include "folders/folderitem.h"
#include "folders/foldermodelbuilder.h"
#include "folders/folderwidget.h"

#include "plugins/common/exceptionhandler.h"

const std::string dataPath = "../../../../../data/preferences/user/settings/folders/";

using namespace mvvm_folders;

namespace tests
{
std::unique_ptr<FolderWidget> FolderWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    std::unique_ptr<FolderWidget> folderWidget = nullptr;

    bool ok = file.good();
    if (!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    auto operation = [&]() {
        auto folder       = Folders_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<FolderModelBuilder>();
        auto model        = modelBuilder->schemaToModel(folder);

        folderWidget         = std::make_unique<FolderWidget>();
        auto containerItem   = model->topItem();
        auto folderContainer = dynamic_cast<FolderContainerItem *>(containerItem);

        if (!folderContainer)
        {
            qWarning() << "Unable to read folder container!";
        }

        folderWidget->setItem(folderContainer->children().back());
        folderWidget->show();
    };

    auto errorHandler = [&](const std::string &error) { qWarning() << error.c_str(); };

    preferences_editor::ExceptionHandler::handleOperation(operation, errorHandler);

    file.close();

    return folderWidget;
}

void FolderWidgetTest::displayWidgetTest()
{
    std::ifstream file;

    auto folderWidget = readXmlFile(QString::fromStdString(dataPath + "all_checkboxes_checked.xml"));

    QVERIFY(folderWidget);

    QTest::qWait(10000);
}

void FolderWidgetTest::actionStateTest()
{
    QFETCH(QString, localDataPath);
    QFETCH(QString, action);
    QFETCH(bool, settingsEnabled);

    std::ifstream file;

    auto folderWidget = readXmlFile(localDataPath);

    QVERIFY(folderWidget);

    auto actionComboBox = folderWidget->findChild<QComboBox *>("actionComboBox");
    auto settingsWidget = folderWidget->findChild<QWidget *>("settingsWidget");

    QVERIFY(actionComboBox);
    QVERIFY(settingsWidget);

    QCOMPARE(actionComboBox->currentText(), action);
    QCOMPARE(settingsWidget->isEnabled(), settingsEnabled);
}

void FolderWidgetTest::actionStateTest_data()
{
    QTest::addColumn<QString>("localDataPath");
    QTest::addColumn<QString>("action");
    QTest::addColumn<bool>("settingsEnabled");

    QTest::newRow("Create") << QString::fromStdString(dataPath + "create_folders.xml") << "Create"
                            << false;
    QTest::newRow("Replace") << QString::fromStdString(dataPath + "replace_folders.xml")
                             << "Replace" << true;
    QTest::newRow("Update") << QString::fromStdString(dataPath + "update_folders.xml") << "Update"
                            << false;
    QTest::newRow("Delete") << QString::fromStdString(dataPath + "delete_folders.xml") << "Delete"
                            << true;
}

void FolderWidgetTest::booleanValuesTest()
{
    QFETCH(QString, localDataPath);
    QFETCH(bool, controlsState);

    std::ifstream file;

    auto folderWidget = readXmlFile(localDataPath);

    QVERIFY(folderWidget);

    auto allowDeletionOfReadOnly = folderWidget->findChild<QCheckBox *>("allowDeletionOfReadOnly");
    auto deleteAllFiles          = folderWidget->findChild<QCheckBox *>("deleteAllFiles");
    auto deleteThisFolder        = folderWidget->findChild<QCheckBox *>("deleteThisFolder");
    auto ignoreErrors            = folderWidget->findChild<QCheckBox *>("ignoreErrors");
    auto recursiveDelete         = folderWidget->findChild<QCheckBox *>("recursiveDelete");

    auto archive  = folderWidget->findChild<QCheckBox *>("archive");
    auto hidden   = folderWidget->findChild<QCheckBox *>("hidden");
    auto readOnly = folderWidget->findChild<QCheckBox *>("readOnly");

    QVERIFY(allowDeletionOfReadOnly);
    QVERIFY(deleteAllFiles);
    QVERIFY(deleteThisFolder);
    QVERIFY(ignoreErrors);
    QVERIFY(recursiveDelete);

    QVERIFY(archive);
    QVERIFY(hidden);
    QVERIFY(readOnly);

    QCOMPARE(allowDeletionOfReadOnly->isChecked(), controlsState);
    QCOMPARE(deleteAllFiles->isChecked(), controlsState);
    QCOMPARE(deleteThisFolder->isChecked(), controlsState);
    QCOMPARE(ignoreErrors->isChecked(), controlsState);
    QCOMPARE(recursiveDelete->isChecked(), controlsState);

    QCOMPARE(archive->isChecked(), controlsState);
    QCOMPARE(hidden->isChecked(), controlsState);
    QCOMPARE(readOnly->isChecked(), controlsState);
}

void FolderWidgetTest::booleanValuesTest_data()
{
    QTest::addColumn<QString>("localDataPath");
    QTest::addColumn<bool>("controlsState");

    QTest::newRow("Enabled") << QString::fromStdString(dataPath + "all_checkboxes_checked.xml")
                             << true;
    QTest::newRow("Disabled") << QString::fromStdString(dataPath + "all_checkboxes_empty.xml")
                              << false;
}

} // namespace tests

QTEST_MAIN(tests::FolderWidgetTest)
