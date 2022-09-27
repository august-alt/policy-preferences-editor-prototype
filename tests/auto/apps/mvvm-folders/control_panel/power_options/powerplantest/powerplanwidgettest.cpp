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

#include "powerplanwidgettest.h"

#include <fstream>

#include <power_options/powerplanitem.h>
#include <power_options/powerplanwidget.h>
#include <power_options/powermodelbuilder.h>
#include <power_options/powercontaineritem.h>

const std::string dataPath = "../../../../data/preferences/";

using namespace mvvm_folders;

namespace tests 
{
std::unique_ptr<PowerPlanWidget> PowerPlanWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<PowerPlanWidget> planWidget = nullptr;

    try {
        auto files = PowerOptions_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<PowerModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        planWidget = std::make_unique<PowerPlanWidget>();
        auto containerItem = model->topItem();
        auto powerContainer = dynamic_cast<PowerContainerItem<PowerPlanItem>*>(containerItem);

        if (!powerContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        planWidget->setItem(powerContainer->children().back());
        planWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return planWidget;
}

void PowerPlanWidgetTest::test()
{
    QFETCH(QString, dataPath);
    QFETCH(bool,    labelState);
    QFETCH(QString, actionText);
    QFETCH(QString, comboBoxText);
    QFETCH(bool,    setPowerPlanCheckBoxState);
    QFETCH(bool,    treeViewState);

    auto widget = readXmlFile(dataPath);
    QVERIFY(widget);

    auto label                = widget ->findChild<QLabel*>   ("label");
    auto action               = widget ->findChild<QComboBox*>("action");
    auto comboBox             = widget ->findChild<QComboBox*>("comboBox");
    auto setPowerPlanCheckBox = widget ->findChild<QCheckBox*>("setPowerPlanCheckBox");
    auto treeView             = widget ->findChild<QTreeView*>("treeView");

    QTest::qWait(1000);

    QVERIFY(label);
    QVERIFY(action);
    QVERIFY(comboBox);
    QVERIFY(setPowerPlanCheckBox);
    QVERIFY(treeView);

    QCOMPARE(label                  -> isEnabled(), labelState);
    QCOMPARE(action                 -> currentText(), actionText);
    QCOMPARE(comboBox               -> currentText(), comboBoxText);
    QCOMPARE(setPowerPlanCheckBox   -> isEnabled(), setPowerPlanCheckBoxState);
    QCOMPARE(treeView               -> isEnabled(), treeViewState);

}

void PowerPlanWidgetTest::test_data()
{
    QTest::addColumn<QString> ("dataPath");
    QTest::addColumn<bool>    ("label");
    QTest::addColumn<QString> ("action");
    QTest::addColumn<QString> ("comboBox");
    QTest::addColumn<bool>    ("setPowerPlanCheckBox");
    QTest::addColumn<bool>    ("treeView");

    QTest::addRow("Plan") << QString::fromStdString(dataPath + "plan.xml") << true << "Update" << "Balanced" << true << true ;                             ;

}

}

QTEST_MAIN(tests::PowerPlanWidgetTest)

