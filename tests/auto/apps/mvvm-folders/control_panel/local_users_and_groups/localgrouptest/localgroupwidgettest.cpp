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

#include "localgroupwidgettest.h"

#include <fstream>

#include "local_users_and_groups/localgroupcontaineritem.h"
#include "local_users_and_groups/localgroupitem.h"
#include "local_users_and_groups/localgroupwidget.h"
#include "local_users_and_groups/groupmodelbuilder.h"

const std::string dataPath = "../../../../data/preferences/";

using namespace mvvm_folders;

namespace tests 
{

void LocalGroupWidgetTest::test()
{

}

std::unique_ptr<LocalGroupWidget> LocalGroupWidgetTest::readXmlFile(const QString &dataPath)
{
//    std::ifstream file;

//    file.open(dataPath.toStdString(), std::ifstream::in);

//    bool ok = file.good();
//    if (!ok)
//    {
//        qWarning() << "Failed to read file: " << dataPath;
//        return nullptr;
//    }

//    std::unique_ptr<LocalGroupWidget> localGroupWidget = nullptr;

//    auto group = Groups_ (file, ::xsd::cxx::tree::flags::dont_validate);
//    auto modelBuilder = std::make_unique<GroupModelBuilder>();
//    auto model = modelBuilder->schemaToModel(group);

//    localGroupWidget = std::make_unique<LocalGroupWidget>();
//    auto containerItem = model->topItem();
//    auto filesContainer = dynamic_cast<LocalGroupContainerItem<LocalGroupItem>*>(containerItem);


//    if (!filesContainer)
//    {
//        qWarning() << "Unable to read ini container!";
//        return nullptr;
//    }

//    localGroupWidget->setItem(filesContainer->children().back());
//    localGroupWidget->show();

//    file.close();

//    return localGroupWidget;
    return nullptr;
}

}

QTEST_MAIN(tests::LocalGroupWidgetTest)
