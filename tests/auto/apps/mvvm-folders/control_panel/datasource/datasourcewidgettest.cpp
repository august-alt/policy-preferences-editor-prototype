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

#include "datasourcewidgettest.h"

#include <fstream>

#include <datasource/datasourceitem.h>
#include <datasource/datasourcecontaineritem.h>
#include <datasource/datasourcewidget.h>
#include <datasource/datasourcemodelbuilder.h>

//const std::string dataPath = "../../../../data/preferences/";

const std::string dataPath = "/home/antpro/Develop/policy-preferences-editor-prototype/tests/data/preferences/machine/control_panel/datasource/";

using namespace mvvm_folders;

namespace tests
{

std::unique_ptr<DataSourceWidget> DataSourceWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<DataSourceWidget> datasourceWidget = nullptr;

    try {
        auto files = DataSources_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<DataSourceModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        datasourceWidget = std::make_unique<DataSourceWidget>();
        auto containerItem = model->topItem();
        auto dataContainer = dynamic_cast<DataSourceContainerItem*>(containerItem);

        if (!dataContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        datasourceWidget->setItem(dataContainer->children().back());
        datasourceWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return datasourceWidget;
}

void DataSourceWidgetTest::widgetState()
{
    QFETCH(QString, dataPath);
    QFETCH(QString, action);
     QFETCH(bool, userDataSourceRadioButtonState);
    QFETCH(bool, systemDataSourceRadioButtonState);
    QFETCH(bool, dataSourceLineEditState);
    QFETCH(bool, driverLineEditState);
    QFETCH(bool, descriptionLineEditState);
    QFETCH(bool, userNameLineEditState);
    QFETCH(bool, passwordLineEditState);
    QFETCH(bool, confirmPasswordLineEditState);
    QFETCH(bool, attributesTableViewState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto actionComboBox = widget->findChild<QComboBox*>("actionComboBox");
    auto userDataSourceRadioButton = widget->findChild<QRadioButton*>("userDataSourceRadioButton");
    auto systemDataSourceRadioButton = widget->findChild<QRadioButton*>("systemDataSourceRadioButton");
    auto dataSourceLineEdit = widget->findChild<QLineEdit*>("dataSourceLineEdit");
    auto driverLineEdit = widget->findChild<QLineEdit*>("driverLineEdit");
    auto userNameLineEdit = widget->findChild<QLineEdit*>("userNameLineEdit");
    auto passwordLineEdit = widget->findChild<QLineEdit*>("passwordLineEdit");
    auto confirmPasswordLineEdit = widget->findChild<QLineEdit*>("confirmPasswordLineEdit");
    auto descriptionLineEdit = widget->findChild<QLineEdit*>("descriptionLineEdit");
    auto attributesTableView = widget->findChild<QTableView*>("attributesTableView");

    QTest::qWait(1000);

    QVERIFY(actionComboBox);
    QVERIFY(userDataSourceRadioButton);
    QVERIFY(systemDataSourceRadioButton);
    QVERIFY(dataSourceLineEdit);
    QVERIFY(driverLineEdit);
    QVERIFY(descriptionLineEdit);
    QVERIFY(userNameLineEdit);
    QVERIFY(passwordLineEdit);
    QVERIFY(confirmPasswordLineEdit);
    QVERIFY(attributesTableView);

    QCOMPARE(actionComboBox->currentText(), action);
    QCOMPARE(userDataSourceRadioButton->isEnabled(), userDataSourceRadioButtonState);
    QCOMPARE(systemDataSourceRadioButton->isChecked(), systemDataSourceRadioButtonState);
    QCOMPARE(dataSourceLineEdit->isEnabled(), dataSourceLineEditState);
    QCOMPARE(driverLineEdit->isEnabled(), driverLineEditState);
    QCOMPARE(descriptionLineEdit->isEnabled(), descriptionLineEditState);
    QCOMPARE(userNameLineEdit->isEnabled(), userNameLineEditState);
    QCOMPARE(passwordLineEdit->isEnabled(), passwordLineEditState);
    QCOMPARE(confirmPasswordLineEdit->isEnabled(), confirmPasswordLineEditState);
    QCOMPARE(attributesTableView->isEnabled(), attributesTableViewState);
}

void DataSourceWidgetTest::widgetState_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<QString>("action");
    QTest::addColumn<bool>("userDataSourceRadioButtonState");
    QTest::addColumn<bool>("systemDataSourceRadioButtonState");
    QTest::addColumn<bool>("dataSourceLineEditState");
    QTest::addColumn<bool>("driverLineEditState");
    QTest::addColumn<bool>("descriptionLineEditState");
    QTest::addColumn<bool>("userNameLineEditState");
    QTest::addColumn<bool>("passwordLineEditState");
    QTest::addColumn<bool>("confirmPasswordLineEditState");
    QTest::addColumn<bool>("attributesTableViewState");

    QTest::addRow("DataSource")  << QString::fromStdString(dataPath + "data_sources1.xml") << "Update" << false << true << true << true << true << true << true << true << true ;

}

}

QTEST_MAIN(tests::DataSourceWidgetTest)

