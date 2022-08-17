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

#include "variableswidgettest.h"

#include <fstream>

#include "variables/variablescontaineritem.h"
#include "variables/variablesitem.h"
#include "variables/variablesmodelbuilder.h"
#include "variables/variableswidget.h"

#include "plugins/common/exceptionhandler.h"

const std::string dataPath = "../../../../../data/preferences/user/settings/variables/";

using namespace mvvm_folders;

namespace tests
{
std::unique_ptr<VariablesWidget> VariablesWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    std::unique_ptr<VariablesWidget> variablesWidget = nullptr;

    bool ok = file.good();
    if (!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    auto operation = [&]() {
        auto variables    = EnvironmentVariables_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<VariablesModelBuilder>();
        auto model        = modelBuilder->schemaToModel(variables);

        variablesWidget         = std::make_unique<VariablesWidget>();
        auto containerItem      = model->topItem();
        auto variablesContainer = dynamic_cast<VariablesContainerItem *>(containerItem);

        if (!variablesContainer)
        {
            qWarning() << "Unable to read variables container!";
        }

        variablesWidget->setItem(variablesContainer->children().back());
        variablesWidget->show();
    };

    auto errorHandler = [&](const std::string &error) { qWarning() << error.c_str(); };

    preferences_editor::ExceptionHandler::handleOperation(operation, errorHandler);

    file.close();

    return variablesWidget;
}

void VariablesWidgetTest::displayWdigetTest()
{
    std::ifstream file;

    auto variablesWidget = readXmlFile(QString::fromStdString(dataPath + "environment.xml"));

    QVERIFY(variablesWidget);

    QTest::qWait(1000);
}

void VariablesWidgetTest::pathVariableTest()
{
    QFETCH(QString, localDataPath);
    QFETCH(QString, variableName);
    QFETCH(bool, pathCheckBoxEnabled);
    QFETCH(bool, partialCheckBoxEnabled);
    QFETCH(bool, pathCheckBoxChecked);

    std::ifstream file;

    auto folderWidget = readXmlFile(localDataPath);

    QVERIFY(folderWidget);

    auto nameLineEdit    = folderWidget->findChild<QLineEdit *>("nameLineEdit");
    auto pathCheckBox    = folderWidget->findChild<QCheckBox *>("pathCheckBox");
    auto partialCheckBox = folderWidget->findChild<QCheckBox *>("partialCheckBox");

    QVERIFY(nameLineEdit);
    QVERIFY(pathCheckBox);
    QVERIFY(partialCheckBox);

    QCOMPARE(nameLineEdit->text(), variableName);

    QCOMPARE(pathCheckBox->isEnabled(), pathCheckBoxEnabled);
    QCOMPARE(partialCheckBox->isEnabled(), partialCheckBoxEnabled);
    QCOMPARE(pathCheckBox->isChecked(), pathCheckBoxChecked);

    QTest::qWait(5000);
}

void VariablesWidgetTest::pathVariableTest_data()
{
    QTest::addColumn<QString>("localDataPath");
    QTest::addColumn<QString>("variableName");
    QTest::addColumn<bool>("pathCheckBoxEnabled");
    QTest::addColumn<bool>("partialCheckBoxEnabled");
    QTest::addColumn<bool>("pathCheckBoxChecked");

    QTest::newRow("Is Path") << QString::fromStdString(dataPath + "path.xml") << "PATH" << false
                             << true << true;
    QTest::newRow("Is Not Path") << QString::fromStdString(dataPath + "environment.xml") << "name"
                                 << false << false << false;
}

void VariablesWidgetTest::variableTypeTest() {}

void VariablesWidgetTest::variableTypeTest_data() {}

} // namespace tests

QTEST_MAIN(tests::VariablesWidgetTest)
