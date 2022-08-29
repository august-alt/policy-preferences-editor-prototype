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

#include "vpnsecuritywidgettest.h"

#include <fstream>

#include <network_options/vpnitem.h>
#include <network_options/vpnsecuritywidget.h>
#include <network_options/basenetworkitem.h>
#include <network_options/networkcontaineritem.h>
#include <network_options/networkmodelbuilder.h>

//const std::string dataPath = "../../../../data/preferences/";

const std::string dataPath = "/home/antpro/Develop/policy-preferences-editor-prototype/tests/data/preferences/machine/control_panel/network_options/";

using namespace mvvm_folders;

namespace tests 
{
std::unique_ptr<VpnSecurityWidget> VpnSecurityWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<VpnSecurityWidget> vpnSecurityWidget = nullptr;

    try {
        auto files = NetworkOptions_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<NetworkModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        vpnSecurityWidget = std::make_unique<VpnSecurityWidget>();
        auto containerItem = model->topItem();
        auto networkContainer = dynamic_cast<NetworkContainerItem<VpnItem>*>(containerItem);

        if (!networkContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        vpnSecurityWidget->setItem(networkContainer->children().back());
        vpnSecurityWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return vpnSecurityWidget;
}

void VpnSecurityWidgetTest::test()
{
//    std::ifstream file;

//    file.open(dataPath + "vpnsecuritywidget.xml", std::ifstream::in);
//    if (file.good())
//    {
       
//    }

//    file.close();
}

void VpnSecurityWidgetTest::comboBoxeState()
{
    QFETCH(QString, dataPath);
    QFETCH(QString, dataComboBoxState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto dataComboBox = widget->findChild<QComboBox*>("dataComboBox");

    QTest::qWait(1000);

    QVERIFY(dataComboBox);

    QCOMPARE(dataComboBox->currentText(), dataComboBoxState);
}

void VpnSecurityWidgetTest::comboBoxeState_data()

{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<QString>("dataComboBoxState");

    QTest::addRow("Options-on")  << QString::fromStdString(dataPath + "options_on.xml") << "None" ;
}

void VpnSecurityWidgetTest::radioButtonState()
{
    QFETCH(QString, dataPath);
    QFETCH(bool, typicalRadioButtonState);
    QFETCH(bool, advancedRadioButtonState);
    QFETCH(bool, eapRadioButtonState);
    QFETCH(bool, otherRadioButtonState);


    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto typicalRadioButton = widget->findChild<QRadioButton*>("typicalRadioButton");
    auto advancedRadioButton = widget->findChild<QRadioButton*>("advancedRadioButton");
    auto eapRadioButton = widget->findChild<QRadioButton*>("eapRadioButton");
    auto otherRadioButton = widget->findChild<QRadioButton*>("otherRadioButton");

    QTest::qWait(1000);

    QVERIFY(typicalRadioButton);
    QVERIFY(advancedRadioButton);
    QVERIFY(otherRadioButton);

    QCOMPARE(typicalRadioButton->isChecked(), typicalRadioButtonState);
    QCOMPARE(advancedRadioButton->isChecked(), advancedRadioButtonState);
    QCOMPARE(eapRadioButton->isChecked(), eapRadioButtonState);
    QCOMPARE(otherRadioButton->isChecked(), otherRadioButtonState);

}

void VpnSecurityWidgetTest::radioButtonState_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("typicalRadioButtonState");
    QTest::addColumn<bool>("advancedRadioButtonState");
    QTest::addColumn<bool>("eapRadioButtonState");
    QTest::addColumn<bool>("otherRadioButtonState");

    QTest::addRow("Options") << QString::fromStdString(dataPath + "options_on.xml") << true << false << true << false;
}

void VpnSecurityWidgetTest::checkBoxState()
{
    QFETCH(QString, dataPath);
    QFETCH(bool, passwordCheckBoxState);
    QFETCH(bool, encryptionCheckBoxState);
    QFETCH(bool, papCheckBoxState);
    QFETCH(bool, spapCheckBoxState);
    QFETCH(bool, chapCheckBoxState);
    QFETCH(bool, mschapCheckBoxState);
    QFETCH(bool, oldMschapCheckBoxState);
    QFETCH(bool, mschap2CheckBoxState);
    QFETCH(bool, useLogonCheckBoxState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto passwordCheckBox = widget->findChild<QCheckBox*>("passwordCheckBox");
    auto encryptionCheckBox = widget->findChild<QCheckBox*>("encryptionCheckBox");
    auto papCheckBox = widget->findChild<QCheckBox*>("papCheckBox");
    auto spapCheckBox = widget->findChild<QCheckBox*>("spapCheckBox");
    auto chapCheckBox = widget->findChild<QCheckBox*>("chapCheckBox");
    auto mschapCheckBox = widget->findChild<QCheckBox*>("mschapCheckBox");
    auto oldMschapCheckBox = widget->findChild<QCheckBox*>("oldMschapCheckBox");
    auto mschap2CheckBox = widget->findChild<QCheckBox*>("mschap2CheckBox");
    auto useLogonCheckBox = widget->findChild<QCheckBox*>("useLogonCheckBox");

    QTest::qWait(1000);

    QCOMPARE(passwordCheckBox->isChecked(), passwordCheckBoxState);
    QCOMPARE(encryptionCheckBox->isChecked(), encryptionCheckBoxState);
    QCOMPARE(papCheckBox->isChecked(), papCheckBoxState);
    QCOMPARE(spapCheckBox->isChecked(), spapCheckBoxState);
    QCOMPARE(chapCheckBox->isChecked(), chapCheckBoxState);
    QCOMPARE(mschapCheckBox->isChecked(), mschapCheckBoxState);
    QCOMPARE(oldMschapCheckBox->isChecked(), oldMschapCheckBoxState);
    QCOMPARE(mschap2CheckBox->isChecked(), mschap2CheckBoxState);
    QCOMPARE(useLogonCheckBox->isChecked(), useLogonCheckBoxState);
}

void VpnSecurityWidgetTest::checkBoxState_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("passwordCheckBoxState");
    QTest::addColumn<bool>("encryptionCheckBoxState");
    QTest::addColumn<bool>("papCheckBoxState");
    QTest::addColumn<bool>("spapCheckBoxState");
    QTest::addColumn<bool>("chapCheckBoxState");
    QTest::addColumn<bool>("mschapCheckBoxState");
    QTest::addColumn<bool>("oldMschapCheckBoxState");
    QTest::addColumn<bool>("mschap2CheckBoxState");
    QTest::addColumn<bool>("useLogonCheckBoxState");

    QTest::addRow("Options") << QString::fromStdString(dataPath + "options_on.xml") << true << false <<false << false << false << false << false<< false << false ;

}

}

QTEST_MAIN(tests::VpnSecurityWidgetTest)

