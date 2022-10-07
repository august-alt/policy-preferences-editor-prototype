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

#include "groupmemberswidgettest.h"

#include <fstream>

#include <local_users_and_groups/baselocalitem.h>
#include <local_users_and_groups/groupmemberitem.h>
#include <local_users_and_groups/groupmemberscontaineritem.h>
#include <local_users_and_groups/groupmemberswidget.h>
#include <local_users_and_groups/groupmodelbuilder.h>

const std::string dataPath = "";

using namespace mvvm_folders;

namespace tests
{
std::unique_ptr<GroupMembersWidget> GroupMembersWidgetTest::readXmlFile(const QString &dataPath)
{
    std::ifstream file;

    file.open(dataPath.toStdString(), std::ifstream::in);

    bool ok = file.good();
    if (!ok)
    {
        qWarning() << "Failed to read file: " << dataPath;
        return nullptr;
    }

    std::unique_ptr<GroupMembersWidget> membersWidget = nullptr;

    try
    {
        auto files        = Groups_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<GroupModelBuilder>();
        auto model        = modelBuilder->schemaToModel(files);

        membersWidget       = std::make_unique<GroupMembersWidget>();
        auto containerItem  = model->topItem();
        auto groupContainer = dynamic_cast<GroupMembersContainerItem *>(containerItem);

        if (!groupContainer)
        {
            qWarning() << "Unable to read ini container!";
            return nullptr;
        }

        membersWidget->setItem(groupContainer->children().back());
        membersWidget->show();
    }
    catch (const std::exception &e)
    {
        qWarning() << e.what();
    }

    file.close();

    return membersWidget;
}

} // namespace tests

QTEST_MAIN(tests::GroupMembersWidgetTest)
