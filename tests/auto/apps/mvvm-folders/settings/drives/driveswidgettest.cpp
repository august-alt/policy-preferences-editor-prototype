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

#include "driveswidgettest.h"

#include "drives/drivescontaineritem.h"
#include "drives/drivesitem.h"
#include "drives/drivesmodelbuilder.h"
#include "drives/driveswidget.h"

#include "plugins/common/exceptionhandler.h"

#include <fstream>

const std::string dataPath = "../../../../../data/preferences/user/settings/drives/";

using namespace mvvm_folders;

namespace tests
{
std::unique_ptr<DrivesWidget> DrivesWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    std::unique_ptr<DrivesWidget> folderWidget = nullptr;

    bool ok = file.good();
    if (!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    auto operation = [&]() {
        auto folder       = Drives_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<DrivesModelBuilder>();
        auto model        = modelBuilder->schemaToModel(folder);

        folderWidget         = std::make_unique<DrivesWidget>();
        auto containerItem   = model->topItem();
        auto folderContainer = dynamic_cast<DrivesContainerItem *>(containerItem);

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

void DrivesWidgetTest::displayWidgetTest()
{
    std::ifstream file;

    auto folderWidget = readXmlFile(QString::fromStdString(dataPath + "drive_maps.xml"));

    QVERIFY(folderWidget);

    QTest::qWait(10000);
}

void DrivesWidgetTest::actionCreateDrivesWidgetTest()
{
    QFETCH(QString, dataPath);
    QFETCH(QString, action);
    QFETCH(bool, pathLabel_2State);
    QFETCH(QString, pathLineEditText);
    QFETCH(bool, pathLineEditState);
    QFETCH(bool, pathToolButtonState);
    QFETCH(bool, reconnectCheckBoxState);
    QFETCH(bool, driveRadioButtonState);
    QFETCH(QString, driveRadioButtonText);
    QFETCH(bool, firstAvailableRadioButtonState);
    QFETCH(QString, firstAvailableRadioButtonText);
    QFETCH(bool, driveComboBoxState);
    QFETCH(bool, thisGroupBoxState);
    QFETCH(bool, hideAllRadioButtonState);
    QFETCH(bool, noChangeAllRadioButtonState);
    QFETCH(bool, showAllRadioButtonState);

    auto widget = readXmlFile(dataPath);

    auto actionComboBox            = widget->findChild<QComboBox *>("actionComboBox");
    auto pathLabel_2               = widget->findChild<QLabel *>("pathLabel_2");
    auto pathLineEdit              = widget->findChild<QLineEdit *>("pathLineEdit");
    auto pathToolButton            = widget->findChild<QToolButton *>("pathToolButton");
    auto reconnectCheckBox         = widget->findChild<QCheckBox *>("reconnectCheckBox");
    auto driveRadioButton          = widget->findChild<QRadioButton *>("driveRadioButton");
    auto firstAvailableRadioButton = widget->findChild<QRadioButton *>("firstAvailableRadioButton");
    auto driveComboBox             = widget->findChild<QComboBox *>("driveComboBox");
    auto thisGroupBox              = widget->findChild<QGroupBox *>("thisGroupBox");
    auto hideAllRadioButton        = widget->findChild<QRadioButton *>("hideAllRadioButton");
    auto noChangeAllRadioButton    = widget->findChild<QRadioButton *>("noChangeAllRadioButton");
    auto showAllRadioButton        = widget->findChild<QRadioButton *>("showAllRadioButton");

    QVERIFY(actionComboBox);
    QVERIFY(pathLabel_2);
    QVERIFY(pathLineEdit);
    QVERIFY(pathToolButton);
    QVERIFY(reconnectCheckBox);
    QVERIFY(driveRadioButton);
    QVERIFY(firstAvailableRadioButton);
    QVERIFY(driveComboBox);
    QVERIFY(thisGroupBox);
    QVERIFY(hideAllRadioButton);
    QVERIFY(noChangeAllRadioButton);
    QVERIFY(showAllRadioButton);

    QCOMPARE(actionComboBox->currentText(), action);
    QCOMPARE(pathLabel_2->isEnabled(), pathLabel_2State);
    QCOMPARE(pathLineEdit->text(), pathLineEditText);
    QCOMPARE(pathLineEdit->isEnabled(), pathLineEditState);
    QCOMPARE(pathToolButton->isEnabled(), pathToolButtonState);
    QCOMPARE(reconnectCheckBox->isEnabled(), reconnectCheckBoxState);
    QCOMPARE(driveRadioButton->isEnabled(), driveRadioButtonState);
    QCOMPARE(driveRadioButton->text(), driveRadioButtonText);
    QCOMPARE(firstAvailableRadioButton->isEnabled(), firstAvailableRadioButtonState);
    QCOMPARE(firstAvailableRadioButton->text(), firstAvailableRadioButtonText);
    QCOMPARE(driveComboBox->isEnabled(), driveComboBoxState);
    QCOMPARE(thisGroupBox->isEnabled(), thisGroupBoxState);
    QCOMPARE(hideAllRadioButton->isEnabled(), hideAllRadioButtonState);
    QCOMPARE(noChangeAllRadioButton->isEnabled(), noChangeAllRadioButtonState);
    QCOMPARE(showAllRadioButton->isEnabled(), showAllRadioButtonState);
}

void DrivesWidgetTest::actionCreateDrivesWidgetTest_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<QString>("action");
    QTest::addColumn<bool>("pathLabel_2State");
    QTest::addColumn<QString>("pathLineEditText");
    QTest::addColumn<bool>("pathLineEditState");
    QTest::addColumn<bool>("pathToolButtonState");

    QTest::addColumn<bool>("reconnectCheckBoxState");
    QTest::addColumn<bool>("driveRadioButtonState");
    QTest::addColumn<QString>("driveRadioButtonText");
    QTest::addColumn<bool>("firstAvailableRadioButtonState");
    QTest::addColumn<QString>("firstAvailableRadioButtonText");
    QTest::addColumn<bool>("driveComboBoxState");

    QTest::addColumn<bool>("thisGroupBoxState");
    QTest::addColumn<bool>("hideAllRadioButtonState");
    QTest::addColumn<bool>("noChangeAllRadioButtonState");
    QTest::addColumn<bool>("showAllRadioButtonState");

    QTest::addRow("Create") << QString::fromStdString(dataPath
                                                      + "drive_maps_action_create_with_no_path.xml")
                            << "Create" << true << "" << true << true << true << false
                            << "Use:" << false << "Use first available, starting at:" << false
                            << false << true << true << true;

    QTest::addRow("Replace") << QString::fromStdString(
        dataPath + "drive_maps_action_replace_with_no_path.xml")
                             << "Replace" << true << "" << true << true << true << false
                             << "Use:" << false << "Use first available, starting at:" << false
                             << false << true << true << true;

    QTest::addRow("Update") << QString::fromStdString(dataPath
                                                      + "drive_maps_action_update_with_no_path.xml")
                            << "Update" << true << "" << true << true << true << true
                            << "Existing:" << false << "Use first available, starting at:" << true
                            << true << true << true << true;

    QTest::addRow("Delete") << QString::fromStdString(dataPath
                                                      + "drive_maps_action_delete_with_no_path.xml")
                            << "Delete" << false << "" << false << false << false << true
                            << "Delete:" << true << "Delete all, starting at:" << true << false
                            << true << true << true;

    QTest::addRow("Create_with_path")
        << QString::fromStdString(dataPath + "drive_maps_action_create_with_path.xml") << "Create"
        << true << "C:\\path\\user1.txt" << true << true << true << true << "Use:" << true
        << "Use first available, starting at:" << true << true << true << true << true;

    QTest::addRow("Replace_with_path")
        << QString::fromStdString(dataPath + "drive_maps_action_replace_with_path.xml") << "Replace"
        << true << "C:\\path\\user1.txt" << true << true << true << true << "Use:" << true
        << "Use first available, starting at:" << true << true << true << true << true;

    QTest::addRow("Update_with_path")
        << QString::fromStdString(dataPath + "drive_maps_action_update_with_path.xml") << "Update"
        << true << "C:\\path\\user1.txt" << true << true << true << true << "Use:" << true
        << "Use first available, starting at:" << true << true << true << true << true;

    QTest::addRow("Delete_with_path")
        << QString::fromStdString(dataPath + "drive_maps_action_delete_with_path.xml") << "Delete"
        << false << "C:\\path\\user1.txt" << false << false << false << true << "Delete:" << true
        << "Delete all, starting at:" << true << false << true << true << true;
}

} // namespace tests

QTEST_MAIN(tests::DrivesWidgetTest)
