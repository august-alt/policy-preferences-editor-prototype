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

#include "localgroupwidgettest.h"

#include <fstream>

#include "local_users_and_groups/localgroupcontaineritem.h"
#include "local_users_and_groups/localgroupitem.h"
#include "local_users_and_groups/localgroupwidget.h"
#include "local_users_and_groups/groupmodelbuilder.h"
#include "local_users_and_groups/baselocalitem.h"
#include "local_users_and_groups/groupmemberitem.h"
#include "local_users_and_groups/groupmemberdialog.h"
#include "local_users_and_groups/groupmemberitem.h"
#include "local_users_and_groups/groupmemberscontaineritem.h"
#include "local_users_and_groups/groupmemberswidget.h"


const std::string dataPath = "../../../../../../data/preferences/machine/control_panel/local_users_and_groups/";

using namespace mvvm_folders;

namespace tests
{
std::unique_ptr<LocalGroupWidget> LocalGroupWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<LocalGroupWidget> groupWidget = nullptr;

    try {
        auto files = Groups_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<GroupModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        groupWidget = std::make_unique<LocalGroupWidget>();
        auto containerItem = model->topItem();
        auto groupContainer = dynamic_cast<LocalGroupContainerItem<LocalGroupItem>*>(containerItem);

        if (!groupContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        groupWidget->setItem(groupContainer->children().back());
        groupWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return groupWidget;
}
void LocalGroupWidgetTest::lineEditCheck()
{
    QFETCH(QString, dataPath);
    QFETCH(int,     groupComboBoxState);
    QFETCH(bool,    renameLineEditState);
    QFETCH(bool,     descriptionLineEditState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto groupComboBox          = widget->findChild<QComboBox*>("groupComboBox");
    auto renameLineEdit         = widget->findChild<QLineEdit*>("renameLineEdit");
    auto descriptionLineEdit    = widget->findChild<QLineEdit*>("descriptionLineEdit");

    QTest::qWait(1000);

    QVERIFY(groupComboBox);
    QCOMPARE(groupComboBox      ->currentIndex(),   groupComboBoxState);
    QCOMPARE(renameLineEdit     ->isEnabled(),      renameLineEditState);
    QCOMPARE(descriptionLineEdit->isEnabled(),      descriptionLineEditState);
}

void LocalGroupWidgetTest::lineEditCheck_data()
{
    QTest::addColumn<QString>   ("dataPath");
    QTest::addColumn<int>       ("groupComboBoxState");
    QTest::addColumn<bool>      ("renameLineEditState");
    QTest::addColumn<bool>      ("descriptionLineEditState");

    QTest::addRow("LocalGroup")  << QString::fromStdString(dataPath + "local_users_and_groups_local_groups.xml") << 0 << true << true ;

}

void LocalGroupWidgetTest::radioButtonCheck()
{
    QFETCH(QString, dataPath);
    QFETCH(bool, doNotUserradioButtonState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto doNotUserradioButton = widget->findChild<QRadioButton*>("doNotUserradioButton");

    QTest::qWait(1000);

    QVERIFY(doNotUserradioButton);

    QCOMPARE(doNotUserradioButton->isChecked(), doNotUserradioButtonState);
}

void LocalGroupWidgetTest::radioButtonCheck_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("doNotUserradioButtonState");

    QTest::addRow("LocalGroup")  << QString::fromStdString(dataPath + "local_users_and_groups_local_groups.xml") << true ;

}

void LocalGroupWidgetTest::checkBox()
{
    QFETCH(QString,     dataPath);
    QFETCH(bool,        deleteGroupCheckBoxState);
    QFETCH(bool,        deleteUsersCheckBoxState);

    auto widget = readXmlFile(dataPath);


    QVERIFY(widget);

    auto deleteGroupCheckBox = widget->findChild<QCheckBox*>("deleteGroupCheckBox");
    auto deleteUsersCheckBox = widget->findChild<QCheckBox*>("deleteUsersCheckBox");

    QTest::qWait(1000);

    QVERIFY(deleteGroupCheckBox);

    QCOMPARE(deleteGroupCheckBox->isChecked(), deleteGroupCheckBoxState);
    QCOMPARE(deleteUsersCheckBox->isChecked(), deleteUsersCheckBoxState);
}

void LocalGroupWidgetTest::checkBox_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("deleteGroupCheckBoxState");
    QTest::addColumn<bool>("deleteUsersCheckBoxState");


    QTest::addRow("LocalGroup")  << QString::fromStdString(dataPath + "local_users_and_groups_local_groups.xml") << false << false ;
}

}

QTEST_MAIN(tests::LocalGroupWidgetTest)
