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

#include "powerschemewidgettest.h"

#include <fstream>

#include <power_options/powerschemeitem.h>
#include <power_options/powerschemewidget.h>
#include <power_options/powermodelbuilder.h>
#include <power_options/powercontaineritem.h>

const std::string dataPath = "../../../../data/preferences/";

using namespace mvvm_folders;

namespace tests 
{
std::unique_ptr<PowerSchemeWidget> PowerSchemeWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<PowerSchemeWidget> schemeWidget = nullptr;

    try {
        auto files = PowerOptions_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<PowerModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        schemeWidget = std::make_unique<PowerSchemeWidget>();
        auto containerItem = model->topItem();
        auto powerContainer = dynamic_cast<PowerContainerItem<PowerSchemeItem>*>(containerItem);

        if (!powerContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        schemeWidget->setItem(powerContainer->children().back());
        schemeWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return schemeWidget;
}

void PowerSchemeWidgetTest::test()
{
    QFETCH(QString, dataPath);
    QFETCH(QString, actionText);
    QFETCH(QString, nameComboBoxText);
    QFETCH(QString, monitorDcComboBoxText);
    QFETCH(QString, monitorAcComboBoxText);
    QFETCH(QString, hardDiskDcComboBoxText);
    QFETCH(QString, hardDiskAcComboBoxText);
    QFETCH(QString, standbyDcComboBoxText);
    QFETCH(QString, standbyAcComboBoxText);
    QFETCH(QString, hibernateDcComboBoxText);
    QFETCH(QString, hibernateAcComboBoxText);
    QFETCH(bool,    defaultCheckBoxState);
    QFETCH(bool,    powerGroupBoxState);
    QFETCH(bool,    settingGroupBoxState);
    QFETCH(bool,    computerLabelState);
    QFETCH(bool,    dcPowerLabelState);
    QFETCH(bool,    acPowerLabelState);
    QFETCH(bool,    monitorLabelState);
    QFETCH(bool,    hardDiskLabelState);
    QFETCH(bool,    standbyLabelState);
    QFETCH(bool,    hibernateLabelState);

    auto widget = readXmlFile(dataPath);
    QVERIFY(widget);

    auto action                 = widget ->findChild<QComboBox*>   ("action");
    auto nameComboBox           = widget ->findChild<QComboBox*>   ("nameComboBox");
    auto monitorDcComboBox      = widget ->findChild<QComboBox*>   ("monitorDcComboBox");
    auto monitorAcComboBox      = widget ->findChild<QComboBox*>   ("monitorAcComboBox");
    auto hardDiskDcComboBox     = widget ->findChild<QComboBox*>   ("hardDiskDcComboBox");
    auto hardDiskAcComboBox     = widget ->findChild<QComboBox*>   ("hardDiskAcComboBox");
    auto standbyDcComboBox      = widget ->findChild<QComboBox*>   ("standbyDcComboBox");
    auto standbyAcComboBox      = widget ->findChild<QComboBox*>   ("standbyAcComboBox");
    auto hibernateDcComboBox    = widget ->findChild<QComboBox*>   ("hibernateDcComboBox");
    auto hibernateAcComboBox    = widget ->findChild<QComboBox*>   ("hibernateAcComboBox");
    auto defaultCheckBox        = widget ->findChild<QCheckBox*>   ("defaultCheckBox");
    auto powerGroupBox          = widget ->findChild<QGroupBox*>   ("powerGroupBox");
    auto settingGroupBox        = widget ->findChild<QGroupBox*>   ("settingGroupBox");
    auto computerLabel          = widget ->findChild<QLabel*>      ("computerLabel");
    auto dcPowerLabel           = widget ->findChild<QLabel*>      ("dcPowerLabel");
    auto acPowerLabel           = widget ->findChild<QLabel*>      ("acPowerLabel");
    auto monitorLabel           = widget ->findChild<QLabel*>      ("monitorLabel");
    auto hardDiskLabel          = widget ->findChild<QLabel*>      ("hardDiskLabel");
    auto standbyLabel           = widget ->findChild<QLabel*>      ("standbyLabel");
    auto hibernateLabel         = widget ->findChild<QLabel*>      ("hibernateLabel");

    QTest::qWait(1000);

    QVERIFY(action);
    QVERIFY(nameComboBox);
    QVERIFY(monitorDcComboBox);
    QVERIFY(monitorAcComboBox);
    QVERIFY(hardDiskDcComboBox);
    QVERIFY(hardDiskAcComboBox);
    QVERIFY(standbyDcComboBox);
    QVERIFY(standbyAcComboBox);
    QVERIFY(hibernateDcComboBox);
    QVERIFY(hibernateAcComboBox);
    QVERIFY(defaultCheckBox);
    QVERIFY(powerGroupBox);
    QVERIFY(settingGroupBox);
    QVERIFY(computerLabel);
    QVERIFY(dcPowerLabel);
    QVERIFY(acPowerLabel);
    QVERIFY(monitorLabel);
    QVERIFY(hardDiskLabel);
    QVERIFY(standbyLabel);
    QVERIFY(hibernateLabel);

    QCOMPARE(action              -> currentText(), actionText);
    QCOMPARE(nameComboBox        -> currentText(), nameComboBoxText);
    QCOMPARE(monitorDcComboBox   -> currentText(), monitorDcComboBoxText);
    QCOMPARE(monitorAcComboBox   -> currentText(), monitorAcComboBoxText);
    QCOMPARE(hardDiskDcComboBox  -> currentText(), hardDiskDcComboBoxText);
    QCOMPARE(hardDiskAcComboBox  -> currentText(), hardDiskAcComboBoxText);
    QCOMPARE(standbyDcComboBox   -> currentText(), standbyDcComboBoxText);
    QCOMPARE(standbyAcComboBox   -> currentText(), standbyAcComboBoxText);
    QCOMPARE(hibernateDcComboBox -> currentText(), hibernateDcComboBoxText);
    QCOMPARE(hibernateAcComboBox -> currentText(), hibernateAcComboBoxText);
    QCOMPARE(defaultCheckBox     -> isEnabled(), defaultCheckBoxState);
    QCOMPARE(powerGroupBox       -> isEnabled(), powerGroupBoxState);
    QCOMPARE(settingGroupBox     -> isEnabled(), settingGroupBoxState);
    QCOMPARE(computerLabel       -> isEnabled(), computerLabelState);
    QCOMPARE(dcPowerLabel        -> isEnabled(), dcPowerLabelState);
    QCOMPARE(acPowerLabel        -> isEnabled(), acPowerLabelState);
    QCOMPARE(monitorLabel        -> isEnabled(), monitorLabelState);
    QCOMPARE(hardDiskLabel       -> isEnabled(), hardDiskLabelState);
    QCOMPARE(standbyLabel        -> isEnabled(), standbyLabelState);
    QCOMPARE(hibernateLabel      -> isEnabled(), hibernateLabelState);

}

void PowerSchemeWidgetTest::test_data()
{
    QTest::addColumn<QString> ("dataPath");
    QTest::addColumn<QString> ("action");
    QTest::addColumn<QString> ("nameComboBox");
    QTest::addColumn<QString> ("monitorDcComboBox");
    QTest::addColumn<QString> ("monitorAcComboBox");
    QTest::addColumn<QString> ("hardDiskDcComboBox");
    QTest::addColumn<QString> ("hardDiskAcComboBox");
    QTest::addColumn<QString> ("standbyDcComboBox");
    QTest::addColumn<QString> ("standbyAcComboBox");
    QTest::addColumn<QString> ("hibernateDcComboBox");
    QTest::addColumn<QString> ("hibernateAcComboBox");
    QTest::addColumn<QString> ("defaultCheckBox");
    QTest::addColumn<QString> ("powerGroupBox");
    QTest::addColumn<QString> ("settingGroupBox");
    QTest::addColumn<QString> ("computerLabel");
    QTest::addColumn<QString> ("dcPowerLabel");
    QTest::addColumn<QString> ("acPowerLabel");
    QTest::addColumn<QString> ("monitorLabel");
    QTest::addColumn<QString> ("hardDiskLabel");
    QTest::addColumn<QString> ("standbyLabel");
    QTest::addColumn<QString> ("hibernateLabel");

    QTest::addRow("Plan") << QString::fromStdString(dataPath + "plan.xml")
                          << "Update" << "Home/Office desc"
                          << "After 1 min" << "After 1 min"
                          << "After 3 min" << "After 3 min"
                          << "After 1 min" << "After 1 min"
                          << "After 1 min" << "After 1 min"
                          << true << true << true << true << true
                          << true << true << true << true << true;

}

}

QTEST_MAIN(tests::PowerSchemeWidgetTest)

