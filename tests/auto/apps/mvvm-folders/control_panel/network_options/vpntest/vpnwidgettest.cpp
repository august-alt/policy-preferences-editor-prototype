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

#include "vpnwidgettest.h"

#include <fstream>

#include <network_options/vpnitem.h>
#include <network_options/vpnwidget.h>
#include <network_options/basenetworkitem.h>
#include <network_options/networkcontaineritem.h>
#include <network_options/networkmodelbuilder.h>

const std::string dataPath = "../../../../../../data/preferences/machine/control_panel/network_options/";

using namespace mvvm_folders;

namespace tests 
{

std::unique_ptr<VpnWidget> VpnWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<VpnWidget> vpnWidget = nullptr;

    try {
        auto files = NetworkOptions_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<NetworkModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        vpnWidget = std::make_unique<VpnWidget>();
        auto containerItem = model->topItem();
        auto networkContainer = dynamic_cast<NetworkContainerItem<VpnItem>*>(containerItem);

        if (!networkContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        vpnWidget->setItem(networkContainer->children().back());
        vpnWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return vpnWidget;
}

void VpnWidgetTest::actionWidgetStateTest()
{
    QFETCH(QString, dataPath);
    QFETCH(QString, action);
    QFETCH(bool,    ipaddressLineEditState);
    QFETCH(bool,    ipaddressLabelState);
    QFETCH(bool,    connectionNameLineEditState);
    QFETCH(bool,    showIconCheckBoxState);
    QFETCH(bool,    userConnectionRadioButtonState);
    QFETCH(bool,    allUsersConnectionRadioButtonState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto ipaddressLabel                 = widget->findChild<QLabel*>        ("ipaddressLabel");
    auto ipaddressLineEdit              = widget->findChild<QLineEdit*>     ("ipaddressLineEdit");
    auto connectionNameLineEdit         = widget->findChild<QLineEdit*>     ("connectionNameLineEdit");
    auto showIconCheckBox               = widget->findChild<QCheckBox*>     ("showIconCheckBox");
    auto userConnectionRadioButton      = widget->findChild<QRadioButton*>  ("userConnectionRadioButton");
    auto allUsersConnectionRadioButton  = widget->findChild<QRadioButton*>  ("allUsersConnectionRadioButton");
    auto actionComboBox                 = widget->findChild<QComboBox*>     ("actionComboBox");

    QTest::qWait(1000);

    QVERIFY(ipaddressLabel);
    QVERIFY(ipaddressLineEdit);
    QVERIFY(connectionNameLineEdit);
    QVERIFY(showIconCheckBox);
    QVERIFY(userConnectionRadioButton);
    QVERIFY(allUsersConnectionRadioButton);
    QVERIFY(actionComboBox);

    QCOMPARE(actionComboBox                 ->currentText(),    action);
    QCOMPARE(ipaddressLabel                 ->isEnabled(),      ipaddressLabelState);
    QCOMPARE(ipaddressLineEdit              ->isEnabled(),      ipaddressLineEditState);
    QCOMPARE(connectionNameLineEdit         ->isEnabled(),      connectionNameLineEditState);
    QCOMPARE(showIconCheckBox               ->isEnabled(),      showIconCheckBoxState);
    QCOMPARE(userConnectionRadioButton      ->isChecked(),      userConnectionRadioButtonState);
    QCOMPARE(allUsersConnectionRadioButton  ->isChecked(),      allUsersConnectionRadioButtonState);

}
void VpnWidgetTest::actionWidgetStateTest_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<QString>("action");
    QTest::addColumn<bool>("ipaddressLabelState");
    QTest::addColumn<bool>("ipaddressLineEditState");
    QTest::addColumn<bool>("connectionNameLineEditState");
    QTest::addColumn<bool>("showIconCheckBoxState");
    QTest::addColumn<bool>("userConnectionRadioButtonState");
    QTest::addColumn<bool>("allUsersConnectionRadioButtonState");

    QTest::addRow("Replace") << QString::fromStdString(dataPath + "replace_vpn.xml") << "Replace" << true << true << true << true << true << false;
    QTest::addRow("Create")  << QString::fromStdString(dataPath + "create_vpn.xml")  << "Create"  << true << true << true << true << true << false;
    QTest::addRow("Update")  << QString::fromStdString(dataPath + "update_vpn.xml")  << "Update"  << true << true << true << true << true << false;
    QTest::addRow("Delete")  << QString::fromStdString(dataPath + "delete_vpn.xml")  << "Delete"  << false << false << true << false << true << false;
}

void VpnWidgetTest::checkBoxesStateDNS()
{
    QFETCH(QString, dataPath);
    QFETCH(bool,    useDnsCheckBoxState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto useDnsCheckBox = widget->findChild<QCheckBox*>("useDnsCheckBox");

    QTest::qWait(1000);

    QVERIFY(useDnsCheckBox);

    QCOMPARE(useDnsCheckBox->isChecked(), useDnsCheckBoxState);
}
void VpnWidgetTest::checkBoxesStateDNS_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("useDnsCheckBoxState");

    QTest::addRow("CreateDNS")  << QString::fromStdString(dataPath + "createDns_vpn.xml") << true;
}

}

QTEST_MAIN(tests::VpnWidgetTest)

