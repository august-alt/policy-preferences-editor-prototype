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

#include "vpnoptionswidgettest.h"

#include <fstream>

#include <network_options/vpnitem.h>
#include <network_options/vpnoptionswidget.h>
#include <network_options/basenetworkitem.h>
#include <network_options/networkcontaineritem.h>
#include <network_options/networkmodelbuilder.h>

const std::string dataPath = "../../../../../../data/preferences/machine/control_panel/network_options/";

using namespace mvvm_folders;

namespace tests 
{
std::unique_ptr<VpnOptionsWidget> VpnOptionsWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<VpnOptionsWidget> vpnOptionsWidget = nullptr;

    try {
        auto files = NetworkOptions_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<NetworkModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        vpnOptionsWidget = std::make_unique<VpnOptionsWidget>();
        auto containerItem = model->topItem();
        auto networkContainer = dynamic_cast<NetworkContainerItem<VpnItem>*>(containerItem);

        if (!networkContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        vpnOptionsWidget->setItem(networkContainer->children().back());
        vpnOptionsWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return vpnOptionsWidget;
}

void VpnOptionsWidgetTest::test()
{

}
void VpnOptionsWidgetTest::checkBoxesState()
{
    QFETCH(QString, dataPath);
    QFETCH(bool, displayProgressCheckBoxState);
    QFETCH(bool, includeCheckBoxState);
    QFETCH(bool, promptCheckBoxState);
    QFETCH(bool, redailCheckBoxState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto displayProgressCheckBox = widget->findChild<QCheckBox*>("displayProgressCheckBox");
    auto includeCheckBox = widget->findChild<QCheckBox*>("includeCheckBox");
    auto promptCheckBox = widget->findChild<QCheckBox*>("promptCheckBox");
    auto redailCheckBox = widget->findChild<QCheckBox*>("redailCheckBox");

    QTest::qWait(1000);

    QVERIFY(displayProgressCheckBox);
    QVERIFY(includeCheckBox);
    QVERIFY(promptCheckBox);
    QVERIFY(redailCheckBox);

    QCOMPARE(displayProgressCheckBox->isChecked(), displayProgressCheckBoxState);
    QCOMPARE(includeCheckBox->isChecked(), includeCheckBoxState);
    QCOMPARE(promptCheckBox->isChecked(), promptCheckBoxState);
    QCOMPARE(redailCheckBox->isChecked(), redailCheckBoxState);
}
void VpnOptionsWidgetTest::checkBoxesState_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("displayProgressCheckBoxState");
    QTest::addColumn<bool>("includeCheckBoxState");
    QTest::addColumn<bool>("promptCheckBoxState");
    QTest::addColumn<bool>("redailCheckBoxState");

    QTest::addRow("Options-on")  << QString::fromStdString(dataPath + "options_on.xml") << true << true << true << true;
    QTest::addRow("Options-off")  << QString::fromStdString(dataPath + "options_off.xml") << false << false << false << false;

}

}

QTEST_MAIN(tests::VpnOptionsWidgetTest)

