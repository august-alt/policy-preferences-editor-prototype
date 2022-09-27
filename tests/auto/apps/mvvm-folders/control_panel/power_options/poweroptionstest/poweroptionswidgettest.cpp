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

#include "poweroptionswidgettest.h"

#include <fstream>

#include <power_options/poweroptionsitem.h>
#include <power_options/poweroptionswidget.h>
#include <power_options/powermodelbuilder.h>
#include <power_options/powercontaineritem.h>

const std::string dataPath = "../../../../../../data/preferences/";

using namespace mvvm_folders;

namespace tests 
{

std::unique_ptr<PowerOptionsWidget> PowerOptionsWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<PowerOptionsWidget> powerWidget = nullptr;

    try {
        auto files = PowerOptions_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<PowerModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        powerWidget = std::make_unique<PowerOptionsWidget>();
        auto containerItem = model->topItem();
        auto powerContainer = dynamic_cast<PowerContainerItem<PowerOptionsItem>*>(containerItem);

        if (!powerContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        powerWidget->setItem(powerContainer->children().back());
        powerWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return powerWidget;
}

void PowerOptionsWidgetTest::checkBox()
{
    QFETCH(QString, dataPath);
    QFETCH(bool, showIconLabelState);
    QFETCH(bool, promptPasswordLabelState);
    QFETCH(bool, enableHibernationLabelState);

    auto widget = readXmlFile(dataPath);
    QVERIFY(widget);

    auto showIconLabel          = widget->findChild<QLabel*>("showIconLabel");
    auto promptPasswordLabel    = widget->findChild<QLabel*>("promptPasswordLabel");
    auto enableHibernationLabel = widget->findChild<QLabel*>("enableHibernationLabel");

    QTest::qWait(1000);

    QVERIFY(showIconLabel);
    QVERIFY(promptPasswordLabel);
    QVERIFY(enableHibernationLabel);

    QCOMPARE(showIconLabel          ->isEnabled(), showIconLabelState);
    QCOMPARE(promptPasswordLabel    ->isEnabled(), promptPasswordLabelState);
    QCOMPARE(enableHibernationLabel ->isEnabled(), enableHibernationLabelState);

}

void PowerOptionsWidgetTest::checkBox_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<QString>("showIconLabelState");
    QTest::addColumn<bool>("promptPasswordLabelState");
    QTest::addColumn<bool>("enableHibernationLabelState");

    QTest::addRow("Power") << QString::fromStdString(dataPath + "poweroptions.xml") << false << true << true ;

}

void PowerOptionsWidgetTest::comboBox()
{
    QFETCH(QString, dataPath);
    QFETCH(QString, closeLidComboBoxText);
    QFETCH(QString, pressPowerBtnComboBoxText);
    QFETCH(QString, pressSleepBtnComboBoxText);
    QFETCH(bool, closeLidLabelState);
    QFETCH(bool, pressPowerBtnLabelState);
    QFETCH(bool, pressSleepBtnLabelState);

    auto widget = readXmlFile(dataPath);
    QVERIFY(widget);

    auto closeLidComboBox      = widget->findChild<QComboBox*>("closeLidComboBox");
    auto pressPowerBtnComboBox = widget->findChild<QComboBox*>("pressPowerBtnComboBox");
    auto pressSleepBtnComboBox = widget->findChild<QComboBox*>("pressSleepBtnComboBox");
    auto closeLidLabel         = widget->findChild<QLabel*>   ("closeLidLabel");
    auto pressPowerBtnLabel    = widget->findChild<QLabel*>   ("pressPowerBtnLabel");
    auto pressSleepBtnLabel    = widget->findChild<QLabel*>   ("pressSleepBtnLabel");


    QTest::qWait(1000);

    QVERIFY(closeLidComboBox);
    QVERIFY(pressPowerBtnComboBox);
    QVERIFY(pressSleepBtnComboBox);
    QVERIFY(closeLidLabel);
    QVERIFY(pressPowerBtnLabel);
    QVERIFY(pressSleepBtnLabel);

    QCOMPARE(closeLidComboBox      ->currentText(), closeLidComboBoxText);
    QCOMPARE(pressPowerBtnComboBox ->currentText(), pressPowerBtnComboBoxText);
    QCOMPARE(pressSleepBtnComboBox ->currentText(), pressSleepBtnComboBoxText);
    QCOMPARE(closeLidLabel         ->isEnabled(),   closeLidLabelState);
    QCOMPARE(pressPowerBtnLabel    ->isEnabled(),   pressPowerBtnLabelState);
    QCOMPARE(pressSleepBtnLabel    ->isEnabled(),   pressSleepBtnLabelState);
}

void PowerOptionsWidgetTest::comboBox_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<QString>("closeLidComboBoxText");
    QTest::addColumn<bool>("pressPowerBtnComboBoxText");
    QTest::addColumn<bool>("pressSleepBtnComboBoxText");
    QTest::addColumn<bool>("closeLidLabelState");
    QTest::addColumn<bool>("pressPowerBtnLabelState");
    QTest::addColumn<bool>("pressSleepBtnLabelState");

    QTest::addRow("Power") << QString::fromStdString(dataPath + "poweroptions.xml") << "Stand By" << "Shutdown" << "Shutdown" << true << true << true;

}

}

QTEST_MAIN(tests::PowerOptionsWidgetTest)

