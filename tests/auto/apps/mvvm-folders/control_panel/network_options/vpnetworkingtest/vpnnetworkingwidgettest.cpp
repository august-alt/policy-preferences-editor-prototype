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

#include "vpnnetworkingwidgettest.h"

#include <fstream>

#include <network_options/vpnitem.h>
#include <network_options/vpnnetworkingwidget.h>
#include <network_options/basenetworkitem.h>
#include <network_options/networkcontaineritem.h>
#include <network_options/networkmodelbuilder.h>

const std::string dataPath = "../../../../../../data/preferences/machine/control_panel/network_options/";

using namespace mvvm_folders;

namespace tests 
{
std::unique_ptr<VpnNetworkingWidget> VpnNetworkingWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<VpnNetworkingWidget> vpnNetworkingWidget = nullptr;

    try {
        auto files = NetworkOptions_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<NetworkModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        vpnNetworkingWidget = std::make_unique<VpnNetworkingWidget>();
        auto containerItem = model->topItem();
        auto networkContainer = dynamic_cast<NetworkContainerItem<VpnItem>*>(containerItem);

        if (!networkContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        vpnNetworkingWidget->setItem(networkContainer->children().back());
        vpnNetworkingWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return vpnNetworkingWidget;
}

void VpnNetworkingWidgetTest::test()
{

}

void VpnNetworkingWidgetTest::comboBoxeState()
{
    QFETCH(QString, dataPath);
    QFETCH(bool,    typeLabelState);
    QFETCH(QString, typeComboBoxState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto typeLabel      = widget->findChild<QLabel*>    ("typeLabel");
    auto typeComboBox   = widget->findChild<QComboBox*> ("typeComboBox");

    QTest::qWait(1000);

    QVERIFY(typeLabel);
    QVERIFY(typeComboBox);

    QCOMPARE(typeLabel      ->isEnabled(),      typeLabelState);
    QCOMPARE(typeComboBox   ->currentText(),    typeComboBoxState);
}
void VpnNetworkingWidgetTest::comboBoxeState_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("typeLabelState");
    QTest::addColumn<QString>("typeComboBoxState");

    QTest::addRow("Options-on")  << QString::fromStdString(dataPath + "options_on.xml") << true << "Automatic" ;
}
}
QTEST_MAIN(tests::VpnNetworkingWidgetTest)

