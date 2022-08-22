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

const std::string dataPath = "../../../../data/preferences/";

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

    file.close();

    return vpnWidget;
}

void VpnWidgetTest::test()
{

}
void VpnWidgetTest::actionWidgetStateTest()
{
    QFETCH(QString, dataPath);
    QFETCH(QString, action);
    QFETCH(QString, connectionNameLineEditState);
    QFETCH(QString, ipaddressLabelText);
    QFETCH(bool, useDnsCheckBoxState);
    QFETCH(QString, dialLabeleEditState);
    QFETCH(bool, showIconCheckBoxState);
    QFETCH(bool, userConnectionRadioButtonState);
    QFETCH(bool, allUsersConnectionRadioButtonState);

    auto widget = readXmlFile(dataPath);

    auto actionComboBox = widget->findChild<QComboBox*>("actionComboBox");
    auto connectionNameLineEdit = widget->findChild<QLineEdit*>("connectionNameLineEdit");
    auto ipaddressLineEdit = widget->findChild<QLineEdit*>("ipaddressLineEdit");
    auto useDnsCheckBox = widget->findChild<QCheckBox*>("useDnsCheckBox");
    auto showIconCheckBox = widget->findChild<QCheckBox*>("showIconCheckBox");
    auto userConnectionRadioButton = widget->findChild<QRadioButton*>("userConnectionRadioButton");
    auto allUsersConnectionRadioButton = widget->findChild<QRadioButton*>("allUsersConnectionRadioButton");


    QTest::qWait(1000);

    QVERIFY(actionComboBox);
    QVERIFY(connectionNameLineEdit);
    QVERIFY(ipaddressLineEdit);
    QVERIFY(useDnsCheckBox);
    QVERIFY(showIconCheckBox);
// to do for radiobutton

    QCOMPARE(actionComboBox->currentText(), action);
    QCOMPARE(connectionNameLineEdit->text(), connectionNameLineEditState);
    QCOMPARE(ipaddressLineEdit->text(), ipaddressLineEditState);
    QCOMPARE(useDnsCheckBox->isEnabled(), useDnsCheckBoxState);
    QCOMPARE(showIconCheckBox->isEnabled(), showIconCheckBoxState);
//    QCOMPARE(archiveCheckBox->isEnabled(), groupBoxState);
//    QCOMPARE(readOnlyCheckBox->isEnabled(), groupBoxState);
//    QCOMPARE(archiveCheckBox->isChecked(), archiveCheckBoxState);

}
void VpnWidgetTest::actionWidgetStateTest_data()
{

}
void VpnWidgetTest::checkBoxesStateTest()
{

}
void VpnWidgetTest::checkBoxesStateTest_data()
{

}
void VpnWidgetTest::lineEditTest()
{

}
void VpnWidgetTest::lineEditTest_data()
{

}
void VpnWidgetTest::radioButtonStateTest()
{

}
void VpnWidgetTest::radioButtonStateTest_data()
{

}


}

QTEST_MAIN(tests::VpnWidgetTest)

