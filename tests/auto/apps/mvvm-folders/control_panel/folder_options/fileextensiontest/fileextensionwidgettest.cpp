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

#include "fileextensionwidgettest.h"

#include <fstream>

#include <folder_options/fileextensionitem.h>
#include <folder_options/fileextensionwidget.h>
#include <folder_options/fileextensionactionitem.h>
#include <folder_options/fileextensioncontaineritem.h>
#include <folder_options/folderoptionsmodelbuilder.h>

const std::string dataPath = "../../../../../../data/preferences/machine/control_panel/folder_options/";

using namespace mvvm_folders;

namespace tests
{
std::unique_ptr<FileExtensionWidget> FileExtensionWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<FileExtensionWidget> fileWidget = nullptr;

    try {
        auto files = FolderOptions_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<FolderOptionsModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        fileWidget = std::make_unique<FileExtensionWidget>();
        auto containerItem = model->topItem();
        auto fileContainer = dynamic_cast<FileExtensionItem*>(containerItem);

        if (!fileContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        fileWidget->setItem(fileContainer->children().back());
        fileWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return fileWidget;
}
void FileExtensionWidgetTest::checkWidget()
{
    QFETCH(QString, dataPath);
    QFETCH(bool, fileExtentionLabelState);
    QFETCH(bool, classLabelState);
    QFETCH(bool, fileExtentionLineEditState);
    QFETCH(bool, classComboBoxState);
    QFETCH(bool, settingsCheckBoxState);
    QFETCH(bool, iconPathLabelState);
    QFETCH(bool, iconPathLineEditState);
    QFETCH(bool, iconPathToolButtonState);
    QFETCH(bool, iconIndexLabelState);
    QFETCH(bool, iconIndexLineEditState);
    QFETCH(bool, actionIconLabelState);
    QFETCH(bool, iconTableWidgetState);
    QFETCH(bool, newPushButtonState);
    QFETCH(bool, editPushButtonState);
    QFETCH(bool, removePushButtonState);
    QFETCH(bool, setDefaultPushButtonState);
    QFETCH(bool, openAftercheckBoxState);
    QFETCH(bool, alwaysCheckBoxState);
    QFETCH(bool, browseCheckBoxState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto fileExtentionLabel     = widget->findChild<QLabel*>      ("fileExtentionLabel");
    auto classLabel             = widget->findChild<QLabel*>      ("classLabel");
    auto fileExtentionLineEdit  = widget->findChild<QLineEdit*>   ("fileExtentionLineEdit");
    auto classComboBox          = widget->findChild<QComboBox*>   ("classComboBox");
    auto settingsCheckBox       = widget->findChild<QCheckBox*>   ("settingsCheckBox");
    auto iconPathLabel          = widget->findChild<QLabel*>      ("iconPathLabel");
    auto iconPathLineEdit       = widget->findChild<QLineEdit*>   ("iconPathLineEdit");
    auto iconPathToolButton     = widget->findChild<QToolButton*> ("iconPathToolButton");
    auto iconIndexLabel         = widget->findChild<QLabel*>      ("iconIndexLabel");
    auto iconIndexLineEdit      = widget->findChild<QLineEdit*>   ("iconIndexLineEdit");
    auto actionIconLabel        = widget->findChild<QLabel*>      ("actionIconLabel");
    auto iconTableWidget        = widget->findChild<QTableWidget*>("iconTableWidget");
    auto newPushButton          = widget->findChild<QPushButton*> ("newPushButton");
    auto editPushButton         = widget->findChild<QPushButton*> ("editPushButton");
    auto removePushButton       = widget->findChild<QPushButton*> ("removePushButton");
    auto setDefaultPushButton   = widget->findChild<QPushButton*> ("setDefaultPushButton");
    auto openAftercheckBox      = widget->findChild<QCheckBox*>   ("openAftercheckBox");
    auto alwaysCheckBox         = widget->findChild<QCheckBox*>   ("alwaysCheckBox");
    auto browseCheckBox         = widget->findChild<QCheckBox*>   ("browseCheckBox");

    QTest::qWait(1000);

    QVERIFY(fileExtentionLabel);
    QVERIFY(classLabel);
    QVERIFY(fileExtentionLineEdit);
    QVERIFY(classComboBox);
    QVERIFY(settingsCheckBox);
    QVERIFY(iconPathLabel);
    QVERIFY(iconPathLineEdit);
    QVERIFY(iconPathToolButton);
    QVERIFY(iconIndexLabel);
    QVERIFY(iconIndexLineEdit);
    QVERIFY(actionIconLabel);
    QVERIFY(iconTableWidget);
    QVERIFY(newPushButton);
    QVERIFY(editPushButton);
    QVERIFY(removePushButton);
    QVERIFY(setDefaultPushButton);
    QVERIFY(openAftercheckBox);
    QVERIFY(alwaysCheckBox);
    QVERIFY(browseCheckBox);

    QCOMPARE(fileExtentionLabel     ->isEnabled(), fileExtentionLabelState);
    QCOMPARE(classLabel             ->isEnabled(), classLabelState);
    QCOMPARE(fileExtentionLineEdit  ->isEnabled(), fileExtentionLineEditState);
    QCOMPARE(classComboBox          ->isEnabled(), classComboBoxState);
    QCOMPARE(settingsCheckBox       ->isChecked(), settingsCheckBoxState);
    QCOMPARE(iconPathLabel          ->isEnabled(), iconPathLabelState);
    QCOMPARE(iconPathLineEdit       ->isEnabled(), iconPathLineEditState);
    QCOMPARE(iconPathToolButton     ->isEnabled(), iconPathToolButtonState);
    QCOMPARE(iconIndexLabel         ->isEnabled(), iconIndexLabelState);
    QCOMPARE(iconIndexLineEdit      ->isEnabled(), iconIndexLineEditState);
    QCOMPARE(actionIconLabel        ->isEnabled(), actionIconLabelState);
    QCOMPARE(iconTableWidget        ->isEnabled(), iconTableWidgetState);
    QCOMPARE(newPushButton          ->isEnabled(), newPushButtonState);
    QCOMPARE(editPushButton         ->isEnabled(), editPushButtonState);
    QCOMPARE(removePushButton       ->isEnabled(), removePushButtonState);
    QCOMPARE(setDefaultPushButton   ->isEnabled(), setDefaultPushButtonState);
    QCOMPARE(openAftercheckBox      ->isChecked(), openAftercheckBoxState);
    QCOMPARE(alwaysCheckBox         ->isChecked(), alwaysCheckBoxState);
    QCOMPARE(browseCheckBox         ->isChecked(), browseCheckBoxState);

}

void FileExtensionWidgetTest::checkWidget_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("fileExtentionLabel");
    QTest::addColumn<bool>("classLabel");
    QTest::addColumn<bool>("fileExtentionLineEdit");
    QTest::addColumn<bool>("classComboBox");
    QTest::addColumn<bool>("settingsCheckBox");
    QTest::addColumn<bool>("iconPathLabel");
    QTest::addColumn<bool>("iconPathLineEdit");
    QTest::addColumn<bool>("iconPathToolButton");
    QTest::addColumn<bool>("iconIndexLabel");
    QTest::addColumn<bool>("iconIndexLineEdit");
    QTest::addColumn<bool>("actionIconLabel");
    QTest::addColumn<bool>("iconTableWidget");
    QTest::addColumn<bool>("newPushButton");
    QTest::addColumn<bool>("editPushButton");
    QTest::addColumn<bool>("removePushButton");
    QTest::addColumn<bool>("setDefaultPushButton");
    QTest::addColumn<bool>("openAftercheckBox");
    QTest::addColumn<bool>("alwaysCheckBox");
    QTest::addColumn<bool>("browseCheckBox");

    QTest::addRow("File") << QString::fromStdString(dataPath + "file.xml") << true << true  << true  << false << false  << false << false << false  << false << false << false  << false << false << false  << false << false << false  << false << false ;

}

}

QTEST_MAIN(tests::FileExtensionWidgetTest)
