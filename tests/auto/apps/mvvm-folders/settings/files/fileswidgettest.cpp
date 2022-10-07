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

#include "fileswidgettest.h"

#include <fstream>

#include "files/filescontaineritem.h"
#include "files/filesitem.h"
#include "files/fileswidget.h"
#include "files/filesmodelbuilder.h"

const std::string dataPath = "../../../../../data/preferences/user/settings/files/";

using namespace mvvm_folders;

namespace tests
{

std::unique_ptr<FilesWidget> FilesWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<FilesWidget> filesWidget = nullptr;

    auto files = Files_(file, ::xsd::cxx::tree::flags::dont_validate);
    auto modelBuilder = std::make_unique<FilesModelBuilder>();
    auto model = modelBuilder->schemaToModel(files);

    filesWidget = std::make_unique<FilesWidget>();
    auto containerItem = model->topItem();
    auto filesContainer = dynamic_cast<FilesContainerItem*>(containerItem);


    if (!filesContainer)
    {
        qWarning() << "Unable to read ini container!";
        return nullptr;
    }

    filesWidget->setItem(filesContainer->children().back());
    filesWidget->show();

    file.close();

    return filesWidget;
}

void FilesWidgetTest::test()
{
    std::ifstream file;

    file.open(dataPath + "files.xml", std::ifstream::in);

    QVERIFY(file.good());

    if (file.good())
    {
        auto files = Files_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<FilesModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        auto filesWidget = std::make_unique<FilesWidget>();
        auto containerItem = model->topItem();
        auto filesContainer = dynamic_cast<FilesContainerItem*>(containerItem);

        if (filesContainer)
        {
            filesWidget->setItem(filesContainer->children().back());
            filesWidget->show();
        }

        QTest::qWait(1000);
    }

    file.close();
}

void FilesWidgetTest::actionWidgetStateTest()
{

    QFETCH(QString, dataPath);
    QFETCH(QString, action);
    QFETCH(bool, sourceLineEditState);
    QFETCH(QString, destinationLabelText);
    QFETCH(bool, supressErrorsCheckBoxState);
    QFETCH(bool, groupBoxState);
    QFETCH(bool, archiveCheckBoxState);

    auto widget = readXmlFile(dataPath);
    
    auto actionComboBox = widget->findChild<QComboBox*>("actionComboBox");
    auto sourceLineEdit = widget->findChild<QLineEdit*>("sourceLineEdit");
    auto destinationLabel = widget->findChild<QLabel*>("destinationLabel");
    auto supressErrorsCheckBox = widget->findChild<QCheckBox*>("supressErrorsCheckBox");
    auto hiddenCheckBox = widget->findChild<QCheckBox*>("hidden");
    auto archiveCheckBox = widget->findChild<QCheckBox*>("archive");
    auto readOnlyCheckBox = widget->findChild<QCheckBox*>("readOnly");

    QTest::qWait(1000);

    QVERIFY(actionComboBox);
    QVERIFY(sourceLineEdit);
    QVERIFY(destinationLabel);
    QVERIFY(supressErrorsCheckBox);
    QVERIFY(hiddenCheckBox);
    QVERIFY(archiveCheckBox);
    QVERIFY(readOnlyCheckBox);

    QCOMPARE(actionComboBox->currentText(), action);
    QCOMPARE(sourceLineEdit->isEnabled(), sourceLineEditState);
    QCOMPARE(destinationLabel->text(), destinationLabelText);
    QCOMPARE(supressErrorsCheckBox->isEnabled(), supressErrorsCheckBoxState);
    QCOMPARE(hiddenCheckBox->isEnabled(), groupBoxState);
    QCOMPARE(archiveCheckBox->isEnabled(), groupBoxState);
    QCOMPARE(readOnlyCheckBox->isEnabled(), groupBoxState);
    QCOMPARE(archiveCheckBox->isChecked(), archiveCheckBoxState);
}

void FilesWidgetTest::actionWidgetStateTest_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<QString>("action");
    QTest::addColumn<bool>("sourceLineEditState");
    QTest::addColumn<QString>("destinationLabelText");
    QTest::addColumn<bool>("supressErrorsCheckBoxState");
    QTest::addColumn<bool>("groupBoxState");
    QTest::addColumn<bool>("archiveCheckBoxState");
    
    QTest::addRow("Create")  << QString::fromStdString(dataPath + "create_files.xml")  << "Create"  << true  << "Destination file:"     << false << true  << true;
    QTest::addRow("Replace") << QString::fromStdString(dataPath + "replace_files.xml") << "Replace" << true  << "Destination file:"     << true  << true  << true;
    QTest::addRow("Update")  << QString::fromStdString(dataPath + "update_files.xml")  << "Update"  << true  << "Destination file:"     << true  << true  << true;
    QTest::addRow("Delete")  << QString::fromStdString(dataPath + "delete_files.xml")  << "Delete"  << false << "Delete file(s):"       << true  << false << true;
}

void FilesWidgetTest::checkBoxesStateTest()
{
    QFETCH(QString, dataPath);
    QFETCH(bool, supressErrorsCheckBox);
    QFETCH(bool, readOnly);
    QFETCH(bool, hidden);
    QFETCH(bool, archive);

    auto widget = readXmlFile(dataPath);

    auto supressErrorsCheckBoxWidget = widget->findChild<QCheckBox*>("supressErrorsCheckBox");
    auto readOnlyCheckBoxWidget = widget->findChild<QCheckBox*>("readOnly");
    auto hiddenCheckBoxWidget = widget->findChild<QCheckBox*>("hidden");
    auto archiveCheckBoWidget = widget->findChild<QCheckBox*>("archive");

    QTest::qWait(1000);

    QVERIFY(supressErrorsCheckBoxWidget);
    QVERIFY(readOnlyCheckBoxWidget);
    QVERIFY(hiddenCheckBoxWidget);
    QVERIFY(archiveCheckBoWidget);

    QCOMPARE(supressErrorsCheckBoxWidget->isChecked(), supressErrorsCheckBox);
    QCOMPARE(readOnlyCheckBoxWidget->isChecked(), readOnly);
    QCOMPARE(hiddenCheckBoxWidget->isChecked(), hidden);
    QCOMPARE(archiveCheckBoWidget->isChecked(), archive);
}

void FilesWidgetTest::checkBoxesStateTest_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("supressErrorsCheckBox");
    QTest::addColumn<bool>("readOnly");
    QTest::addColumn<bool>("hidden");
    QTest::addColumn<bool>("archive");

    QTest::addRow("unchecked") << QString::fromStdString(dataPath + "unchecked_files.xml") << false << false << false << false;
    QTest::addRow("unchecked") << QString::fromStdString(dataPath + "checked_files.xml")   << true  << true  << true  << true;
}

void FilesWidgetTest::lineEditTest()
{
    QFETCH(QString, dataPath);
    QFETCH(QString, result);

    auto widget = readXmlFile(dataPath);

    auto sourceLineEditWidget = widget->findChild<QLineEdit*>("sourceLineEdit");
    auto destinationLineEditWidget = widget->findChild<QLineEdit*>("destinationLineEdit");

    QTest::qWait(1000);

    QVERIFY(sourceLineEditWidget);
    QVERIFY(destinationLineEditWidget);

    QCOMPARE(sourceLineEditWidget->text(), result);
    QCOMPARE(destinationLineEditWidget->text(), result);
}

void FilesWidgetTest::lineEditTest_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<QString>("result");

    QTest::addRow("winPaths")   << QString::fromStdString(dataPath + "winFilenames_files.xml")   << "c:\\Windows\\user.txt";
    QTest::addRow("linuxPaths") << QString::fromStdString(dataPath + "linuxFilenames_files.xml") << "/etc/user.txt";
}

}

QTEST_MAIN(tests::FilesWidgetTest)
