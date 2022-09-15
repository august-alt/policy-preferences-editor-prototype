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

#include "folderoptionswidgettest.h"

#include <fstream>

#include <folder_options/folderoptionsitem.h>
#include <folder_options/folderoptionswidget.h>
#include <folder_options/folderoptionscontaineritem.h>
#include <folder_options/folderoptionsmodelbuilder.h>

const std::string dataPath = "../../../../../../data/preferences/machine/control_panel/folder_options/";

using namespace mvvm_folders;

namespace tests
{
std::unique_ptr<FolderOptionsWidget> FolderOptionsWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<FolderOptionsWidget> folderWidget = nullptr;

    try {
        auto files = FolderOptions_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<FolderOptionsModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        folderWidget = std::make_unique<FolderOptionsWidget>();
        auto containerItem = model->topItem();
        auto folderContainer = dynamic_cast<FolderOptionsItem*>(containerItem);

        if (!folderContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        folderWidget->setItem(folderContainer->children().back());
        folderWidget->show();
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }

    file.close();

    return folderWidget;
}
void FolderOptionsWidgetTest::checkWidget()
{
    QFETCH(QString, dataPath);
    QFETCH(bool,    advancedSettingsLabelState);
    QFETCH(bool,    treeViewState);
    QFETCH(bool,    restoreButtonState);

    auto widget = readXmlFile(dataPath);

    QVERIFY(widget);

    auto advancedSettingsLabel  = widget->findChild<QLabel*>        ("advancedSettingsLabel");
    auto treeView               = widget->findChild<QTreeView*>     ("treeView");
    auto restoreButton          = widget->findChild<QPushButton*>   ("restoreButton");

    QTest::qWait(1000);

    QVERIFY(advancedSettingsLabel);
    QVERIFY(treeView);
    QVERIFY(restoreButton);

    QCOMPARE(advancedSettingsLabel  ->isEnabled(), advancedSettingsLabelState);
    QCOMPARE(treeView               ->isEnabled(), treeViewState);
    QCOMPARE(restoreButton          ->isEnabled(), restoreButtonState);

}

void FolderOptionsWidgetTest::checkWidget_data()
{
    QTest::addColumn<QString>("dataPath");
    QTest::addColumn<bool>("advancedSettingsLabelState");
    QTest::addColumn<bool>("treeViewState");
    QTest::addColumn<bool>("restoreButtonState");

    QTest::addRow("Open") << QString::fromStdString(dataPath + "openwith.xml") << true << true  << true ;

}

}

QTEST_MAIN(tests::FolderOptionsWidgetTest)

