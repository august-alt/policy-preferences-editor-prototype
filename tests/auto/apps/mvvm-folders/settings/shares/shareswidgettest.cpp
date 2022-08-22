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

#include "shareswidgettest.h"

#include <fstream>

#include "shares/sharescontaineritem.h"
#include "shares/sharesitem.h"
#include "shares/sharesmodelbuilder.h"
#include "shares/shareswidget.h"

#include "plugins/common/exceptionhandler.h"

const std::string dataPath = "../../../../../data/preferences/machine/settings/shares/";

using namespace mvvm_folders;

namespace tests
{
std::unique_ptr<SharesWidget> SharesWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    std::unique_ptr<SharesWidget> sharesWidget = nullptr;

    bool ok = file.good();
    if (!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    auto operation = [&]() {
        auto shares       = NetworkShareSettings_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<SharesModelBuilder>();
        auto model        = modelBuilder->schemaToModel(shares);

        sharesWidget         = std::make_unique<SharesWidget>();
        auto containerItem   = model->topItem();
        auto sharesContainer = dynamic_cast<SharesContainerItem *>(containerItem);

        if (!sharesContainer)
        {
            qWarning() << "Unable to read shares container!";
        }

        sharesWidget->setItem(sharesContainer->children().back());
        sharesWidget->show();
    };

    auto errorHandler = [&](const std::string &error) { qWarning() << error.c_str(); };

    preferences_editor::ExceptionHandler::handleOperation(operation, errorHandler);

    file.close();

    return sharesWidget;
}

void SharesWidgetTest::displayWdigetTest()
{
    std::ifstream file;

    auto sharesWidget = readXmlFile(QString::fromStdString(dataPath + "network_shares.xml"));

    QVERIFY(sharesWidget);

    QTest::qWait(1000);
}

void SharesWidgetTest::radioButtonsTest()
{
    QFETCH(QString, localDataPath);
    QFETCH(bool, noChangeUsersState);
    QFETCH(bool, maximumAllowedUsersState);
    QFETCH(bool, allowThisNumberOfUsersState);
    QFETCH(int, numberOfUsers);

    std::ifstream file;

    auto sharesWidget = readXmlFile(localDataPath);

    QVERIFY(sharesWidget);

    auto noChangeUsersRadioButton       = sharesWidget->findChild<QRadioButton *>("noChangeUsers");
    auto maximumAllowedUsersRadioButton = sharesWidget->findChild<QRadioButton *>(
        "maximumAllowedUsers");
    auto allowThisNumberOfUsersRadioButton = sharesWidget->findChild<QRadioButton *>(
        "allowThisNumberOfUsers");
    auto numberOfUsersSpinBox = sharesWidget->findChild<QSpinBox *>("numberOfUsers");

    QVERIFY(noChangeUsersRadioButton);
    QVERIFY(maximumAllowedUsersRadioButton);
    QVERIFY(allowThisNumberOfUsersRadioButton);
    QVERIFY(numberOfUsersSpinBox);

    QCOMPARE(noChangeUsersRadioButton->isChecked(), noChangeUsersState);
    QCOMPARE(maximumAllowedUsersRadioButton->isChecked(), maximumAllowedUsersState);
    QCOMPARE(allowThisNumberOfUsersRadioButton->isChecked(), allowThisNumberOfUsersState);
    QCOMPARE(numberOfUsersSpinBox->text(), QString::number(numberOfUsers));
}

void SharesWidgetTest::radioButtonsTest_data()
{
    QTest::addColumn<QString>("localDataPath");
    QTest::addColumn<bool>("noChangeUsersState");
    QTest::addColumn<bool>("maximumAllowedUsersState");
    QTest::addColumn<bool>("allowThisNumberOfUsersState");
    QTest::addColumn<int>("numberOfUsers");

    QTest::newRow("No change") << QString::fromStdString(dataPath + "no_change_network_shares.xml")
                               << true << false << false << 0;
    QTest::newRow("Maximum") << QString::fromStdString(dataPath + "maximum_network_shares.xml")
                             << false << true << false << 0;
    QTest::newRow("10 Users") << QString::fromStdString(dataPath + "10_users_network_shares.xml")
                              << false << false << true << 10;
}

void SharesWidgetTest::actionStateTest()
{
    QFETCH(QString, localDataPath);
    QFETCH(QString, actionState);
    QFETCH(bool, modifiersEnabled);
    QFETCH(bool, groupBoxesEnabled);

    std::ifstream file;

    auto sharesWidget = readXmlFile(localDataPath);

    QVERIFY(sharesWidget);

    auto actionComboBox = sharesWidget->findChild<QComboBox *>("actionComboBox");
    auto modifiersFrame = sharesWidget->findChild<QFrame *>("modifiersFrame");
    auto userFrame      = sharesWidget->findChild<QFrame *>("userFrame");
    auto accessFrame    = sharesWidget->findChild<QFrame *>("accessFrame");

    QVERIFY(actionComboBox);
    QVERIFY(modifiersFrame);
    QVERIFY(userFrame);
    QVERIFY(accessFrame);

    QCOMPARE(actionComboBox->currentText(), actionState);
    QCOMPARE(modifiersFrame->isEnabled(), modifiersEnabled);
    QCOMPARE(userFrame->isEnabled(), groupBoxesEnabled);
    QCOMPARE(accessFrame->isEnabled(), groupBoxesEnabled);
}

void SharesWidgetTest::actionStateTest_data()
{
    QTest::addColumn<QString>("localDataPath");
    QTest::addColumn<QString>("actionState");
    QTest::addColumn<bool>("modifiersEnabled");
    QTest::addColumn<bool>("groupBoxesEnabled");

    QTest::newRow("Create") << QString::fromStdString(dataPath + "create_network_shares.xml")
                            << "Create" << false << true;
    QTest::newRow("Update") << QString::fromStdString(dataPath + "update_network_shares.xml")
                            << "Update" << true << true;
    QTest::newRow("Delete") << QString::fromStdString(dataPath + "delete_network_shares.xml")
                            << "Delete" << true << false;
    QTest::newRow("Replace") << QString::fromStdString(dataPath + "replace_network_shares.xml")
                             << "Replace" << false << true;
}

void SharesWidgetTest::modifiersTest()
{
    QFETCH(QString, localDataPath);
    QFETCH(bool, updateAllRegularSharesState);
    QFETCH(bool, updateAllHiddenSharesState);
    QFETCH(bool, updateAllAdministrativeDrivesState);

    std::ifstream file;

    auto sharesWidget = readXmlFile(localDataPath);

    QVERIFY(sharesWidget);

    auto updateAllRegularShares = sharesWidget->findChild<QCheckBox *>("updateAllRegularShares");
    auto updateAllHiddenShares  = sharesWidget->findChild<QCheckBox *>("updateAllHiddenShares");
    auto updateAllAdministrativeDrives = sharesWidget->findChild<QCheckBox *>(
        "updateAllAdministrativeDrives");

    QCOMPARE(updateAllRegularShares->isChecked(), updateAllRegularSharesState);
    QCOMPARE(updateAllHiddenShares->isChecked(), updateAllHiddenSharesState);
    QCOMPARE(updateAllAdministrativeDrives->isChecked(), updateAllAdministrativeDrivesState);
}

void SharesWidgetTest::modifiersTest_data()
{
    QTest::addColumn<QString>("localDataPath");
    QTest::addColumn<bool>("updateAllRegularSharesState");
    QTest::addColumn<bool>("updateAllHiddenSharesState");
    QTest::addColumn<bool>("updateAllAdministrativeDrivesState");

    QTest::newRow("On") << QString::fromStdString(dataPath + "modifiers_on__network_shares.xml")
                        << true << true << true;
    QTest::newRow("Off") << QString::fromStdString(dataPath + "modifiers_off_network_shares.xml")
                         << false << false << false;
}

} // namespace tests

QTEST_MAIN(tests::SharesWidgetTest)
