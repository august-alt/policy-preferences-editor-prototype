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

#include "localuserwidgettest.h"

#include <fstream>

#include <local_users_and_groups/localuseritem.h>
#include <local_users_and_groups/localuserwidget.h>
#include <local_users_and_groups/baselocalitem.h>
#include <local_users_and_groups/groupmodelbuilder.h>

const std::string dataPath = "../../../../../../data/preferences/machine/control_panel/local_users_and_groups/";

using namespace mvvm_folders;

namespace tests 
{
std::unique_ptr<LocalUserWidget> LocalUserWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<LocalUserWidget> userWidget = nullptr;

    try {
        auto files = Groups_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<GroupModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        userWidget = std::make_unique<LocalUserWidget>();
        auto containerItem = model->topItem();
        auto userContainer = dynamic_cast<LocalUserItem*>(containerItem);

        if (!userContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        userWidget->setItem(userContainer->children().back());
        userWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return userWidget;
}

void LocalUserWidgetTest::lineEdit()
{
    QFETCH(QString, dataPath);
    QFETCH(int,     userComboBoxState);
    QFETCH(bool,    renameLineEditState);
    QFETCH(bool,    descriptionLineEditState);
    QFETCH(bool,    fullNameLineEditState);
    QFETCH(bool,    passwordLineEditState);
    QFETCH(bool,    confirmPasswordLineEditState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto userComboBox               = widget->findChild<QComboBox*>("userComboBox");
    auto renameLineEdit             = widget->findChild<QLineEdit*>("renameLineEdit");
    auto descriptionLineEdit        = widget->findChild<QLineEdit*>("descriptionLineEdit");
    auto fullNameLineEdit           = widget->findChild<QLineEdit*>("fullNameLineEdit");
    auto passwordLineEdit           = widget->findChild<QLineEdit*>("passwordLineEdit");
    auto confirmPasswordLineEdit    = widget->findChild<QLineEdit*>("confirmPasswordLineEdit");


    QTest::qWait(1000);

    QVERIFY(userComboBox);
    QVERIFY(renameLineEdit);
    QVERIFY(descriptionLineEdit);
    QVERIFY(fullNameLineEdit);
    QVERIFY(passwordLineEdit);
    QVERIFY(confirmPasswordLineEdit);

    QCOMPARE(userComboBox           ->currentIndex(),   userComboBoxState);
    QCOMPARE(renameLineEdit         ->isEnabled(),      renameLineEditState);
    QCOMPARE(descriptionLineEdit    ->isEnabled(),      descriptionLineEditState);
    QCOMPARE(fullNameLineEdit       ->isEnabled(),      fullNameLineEditState);
    QCOMPARE(passwordLineEdit       ->isEnabled(),      passwordLineEditState);
    QCOMPARE(confirmPasswordLineEdit->isEnabled(),      confirmPasswordLineEditState);
}

void LocalUserWidgetTest::lineEdit_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<int>("userComboBoxState");
    QTest::addColumn<bool>("renameLineEditState");
    QTest::addColumn<bool>("descriptionLineEditState");
    QTest::addColumn<bool>("fullNameLineEditState");
    QTest::addColumn<bool>("passwordLineEditState");
    QTest::addColumn<bool>("confirmPasswordLineEditState");

    QTest::addRow("LocalUser") << QString::fromStdString(dataPath + "local_users_and_groups_local_user.xml") << 0 << true << true << true << true << true ;
}

void LocalUserWidgetTest::checkBox()
{
    QFETCH(QString, dataPath);
    QFETCH(bool,    changeLogonCheckBoxState);
    QFETCH(bool,    userCannotCheckBoxState);
    QFETCH(bool,    passwordNeverCheckBoxState);
    QFETCH(bool,    accountDisabledCheckBoxState);
    QFETCH(bool,    accountNeverCheckBoxState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto changeLogonCheckBox        = widget->findChild<QCheckBox*>("changeLogonCheckBox");
    auto userCannotCheckBox         = widget->findChild<QCheckBox*>("userCannotCheckBox");
    auto passwordNeverCheckBox      = widget->findChild<QCheckBox*>("passwordNeverCheckBox");
    auto accountDisabledCheckBox    = widget->findChild<QCheckBox*>("accountDisabledCheckBox");
    auto accountNeverCheckBox       = widget->findChild<QCheckBox*>("accountNeverCheckBox");

    QTest::qWait(1000);

    QVERIFY(changeLogonCheckBox);
    QVERIFY(userCannotCheckBox);
    QVERIFY(passwordNeverCheckBox);
    QVERIFY(accountDisabledCheckBox);
    QVERIFY(accountNeverCheckBox);

    QCOMPARE(changeLogonCheckBox    ->isChecked(), changeLogonCheckBoxState);
    QCOMPARE(userCannotCheckBox     ->isChecked(), userCannotCheckBoxState);
    QCOMPARE(passwordNeverCheckBox  ->isChecked(), passwordNeverCheckBoxState);
    QCOMPARE(accountDisabledCheckBox->isChecked(), accountDisabledCheckBoxState);
    QCOMPARE(accountNeverCheckBox   ->isChecked(), accountNeverCheckBoxState);
}

void LocalUserWidgetTest::checkBox_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("changeLogonCheckBoxState");
    QTest::addColumn<bool>("userCannotCheckBoxState");
    QTest::addColumn<bool>("passwordNeverCheckBoxState");
    QTest::addColumn<bool>("accountDisabledCheckBoxState");
    QTest::addColumn<bool>("accountNeverCheckBoxState");

    QTest::addRow("LocalUser")  << QString::fromStdString(dataPath + "local_users_and_groups_local_user.xml") << true << false << false << false << true ;
}

void LocalUserWidgetTest::dateEdit()
{
    QFETCH(QString, dataPath);
    QFETCH(bool,    accountExpiresDateEditState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto accountExpiresDateEdit = widget->findChild<QDateEdit*>("accountExpiresDateEdit");

    QTest::qWait(1000);

    QVERIFY(accountExpiresDateEdit);

    QCOMPARE(accountExpiresDateEdit->isEnabled(), accountExpiresDateEditState);
}

void LocalUserWidgetTest::dateEdit_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("accountExpiresDateEditState");

    QTest::addRow("LocalUser")  << QString::fromStdString(dataPath + "local_users_and_groups_local_user.xml") << false ;
}

}

QTEST_MAIN(tests::LocalUserWidgetTest)

