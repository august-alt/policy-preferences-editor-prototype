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

#include "iniwidgettest.h"

#include <fstream>
#include <iostream>

#include "ini/inicontaineritem.h"
#include "ini/iniitem.h"
#include "ini/iniwidget.h"
#include "ini/inimodelbuilder.h"

const std::string dataPath = "../../../../../data/preferences/user/settings/ini/";

using namespace mvvm_folders;

namespace tests
{

std::unique_ptr<IniWidget> IniWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    auto ini = IniFiles_(file, ::xsd::cxx::tree::flags::dont_validate);
    auto modelBuilder = std::make_unique<IniModelBuilder>();
    auto model = modelBuilder->schemaToModel(ini);

    auto iniWidget = std::make_unique<IniWidget>();
    auto containerItem = model->topItem();
    auto iniContainer = dynamic_cast<IniContainerItem*>(containerItem);

    if (!iniContainer)
    {
        qWarning() << "Unable to read ini container!";
        return nullptr;
    }

    file.close();

    iniWidget->setItem(iniContainer->children().back());
    iniWidget->show();

    return iniWidget;
}

void IniWidgetTest::displayWidgetTest()
{
    std::ifstream file;

    auto iniWidget = readXmlFile(QString::fromStdString(dataPath + "ini_files.xml"));

    QTest::qWait(10000);
}

void IniWidgetTest::propertyTest()
{
    QFETCH(QString, dataPath);

    QFETCH(QString, filePath);

    QFETCH(QString, section);
    QFETCH(bool, sectionEnabled);

    QFETCH(QString, property);
    QFETCH(bool, propertyEnabled);

    QFETCH(QString, value);
    QFETCH(bool, valueEnabled);

    auto iniWidget = readXmlFile(dataPath);

    QVERIFY(iniWidget);

    QCOMPARE(iniWidget->findChild<QLineEdit*>("pathLineEdit")->text(), filePath);

    QCOMPARE(iniWidget->findChild<QLineEdit*>("sectionLineEdit")->text(), section);
    QCOMPARE(iniWidget->findChild<QLineEdit*>("sectionLineEdit")->isEnabled(), sectionEnabled);

    QCOMPARE(iniWidget->findChild<QLineEdit*>("propertyLineEdit")->text(), property);
    QCOMPARE(iniWidget->findChild<QLineEdit*>("propertyLineEdit")->isEnabled(), propertyEnabled);

    QCOMPARE(iniWidget->findChild<QLineEdit*>("valueLineEdit")->text(), value);
    QCOMPARE(iniWidget->findChild<QLineEdit*>("valueLineEdit")->isEnabled(), valueEnabled);
}

void IniWidgetTest::propertyTest_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<QString>("filePath");
    QTest::addColumn<QString>("section");
    QTest::addColumn<bool>("sectionEnabled");
    QTest::addColumn<QString>("property");
    QTest::addColumn<bool>("propertyEnabled");
    QTest::addColumn<QString>("value");
    QTest::addColumn<bool>("valueEnabled");

    QTest::newRow("default") << QString::fromStdString(dataPath + "ini_files.xml")
                               << "path" << "volume" << true << "property" << true << "value" << true;

    QTest::newRow("empty_value") << QString::fromStdString(dataPath + "empty_value_ini_files.xml")
                                 << "C:\\Users\\Administrator\\Documents\\test.ini"
                                 << "Section" << true << "Property" << true << "" << true;

    QTest::newRow("empty_property") << QString::fromStdString(dataPath + "empty_property_ini_files.xml")
                                    << "C:\\Users\\Administrator\\Documents\\test.ini"
                                    << "Section" << true << "" << true << "" << false;

    QTest::newRow("empty_section") << QString::fromStdString(dataPath + "empty_section_ini_files.xml")
                                   << "C:\\Users\\Administrator\\Documents\\test.ini"
                                   << "" << true << "" << false << "" << false;

    QTest::newRow("empty_all") << QString::fromStdString(dataPath + "empty_all_ini_files.xml")
                               << "" << "" << false << "" << false << "" << false;
}

void IniWidgetTest::actionStateTest()
{
    QFETCH(QString, dataPath);
    QFETCH(QString, action);
    QFETCH(bool, valueEnabled);

    auto iniWidget = readXmlFile(dataPath);

    QVERIFY(iniWidget);

    QCOMPARE(iniWidget->findChild<QComboBox*>("actionComboBox")->currentText(), action);
    QCOMPARE(iniWidget->findChild<QLineEdit*>("valueLineEdit")->isEnabled(), valueEnabled);

    QTest::qWait(1000);
}

void IniWidgetTest::actionStateTest_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<QString>("action");
    QTest::addColumn<bool>("valueEnabled");

    QTest::newRow("create")  << QString::fromStdString(dataPath + "create_ini_files.xml")  << "Create"  << true;
    QTest::newRow("update")  << QString::fromStdString(dataPath + "update_ini_files.xml")  << "Update"  << true;
    QTest::newRow("replace") << QString::fromStdString(dataPath + "replace_ini_files.xml") << "Replace" << true;
    QTest::newRow("delete")  << QString::fromStdString(dataPath + "delete_ini_files.xml")  << "Delete"  << false;
}

}

QTEST_MAIN(tests::IniWidgetTest)

