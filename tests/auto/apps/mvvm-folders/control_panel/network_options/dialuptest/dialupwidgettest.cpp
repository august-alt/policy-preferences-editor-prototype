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

#include "dialupwidgettest.h"

#include <fstream>

#include <network_options/dialupitem.h>
#include <network_options/dialupwidget.h>
#include <network_options/basenetworkitem.h>
#include <network_options/networkcontaineritem.h>
#include <network_options/networkmodelbuilder.h>

//const std::string dataPath = "../../../../data/preferences/";

const std::string dataPath = "/home/antpro/Develop/policy-preferences-editor-prototype/tests/data/preferences/machine/control_panel/network_options/";

using namespace mvvm_folders;

namespace tests 
{
std::unique_ptr<DialUpWidget> DialUpWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<DialUpWidget> dialUpWidget = nullptr;

    try {
        auto files = NetworkOptions_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<NetworkModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        dialUpWidget = std::make_unique<DialUpWidget>();
        auto containerItem = model->topItem();
        auto networkContainer = dynamic_cast<NetworkContainerItem<DialUpItem>*>(containerItem);

        if (!networkContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        dialUpWidget->setItem(networkContainer->children().back());
        dialUpWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return dialUpWidget;
}

void DialUpWidgetTest::WidgetState()
{
    QFETCH(QString, dataPath);
    QFETCH(bool, userRadioButtonState);
    QFETCH(bool, systemRadioButtonState);
    QFETCH(bool, connectionLineEditState);
    QFETCH(bool, phoneLineEditState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto userRadioButton = widget->findChild<QRadioButton*>("userRadioButton");
    auto systemRadioButton = widget->findChild<QRadioButton*>("systemRadioButton");
    auto connectionLineEdit = widget->findChild<QLineEdit*>("connectionLineEdit");
    auto phoneLineEdit = widget->findChild<QLineEdit*>("phoneLineEdit");

    QTest::qWait(1000);

    QVERIFY(userRadioButton);
    QVERIFY(systemRadioButton);
    QVERIFY(connectionLineEdit);
    QVERIFY(phoneLineEdit);

    QCOMPARE(userRadioButton->isChecked(), userRadioButtonState);
    QCOMPARE(systemRadioButton->isChecked(), systemRadioButtonState);
    QCOMPARE(connectionLineEdit->isEnabled(), connectionLineEditState);
    QCOMPARE(phoneLineEdit->isEnabled(), phoneLineEditState);
}
void DialUpWidgetTest::WidgetState_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("userRadioButtonState");
    QTest::addColumn<bool>("systemRadioButtonState");
    QTest::addColumn<bool>("connectionLineEditState");
    QTest::addColumn<bool>("phoneLineEditState");

    QTest::addRow("DialUp")  << QString::fromStdString(dataPath + "dialup.xml") << false << true << true << true ;
    QTest::addRow("DialUp1")  << QString::fromStdString(dataPath + "dialup1.xml") << true << false << true << true ;
}

}

QTEST_MAIN(tests::DialUpWidgetTest)

