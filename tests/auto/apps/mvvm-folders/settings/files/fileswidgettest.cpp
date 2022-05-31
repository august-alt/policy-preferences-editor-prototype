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

#include "fileswidgettest.h"

#include <fstream>

#include "files/filescontaineritem.h"
#include "files/filesitem.h"
#include "files/fileswidget.h"
#include "files/filesmodelbuilder.h"

const std::string dataPath = "../../../../../data/preferences/user/settings/files/";

using namespace mvvm_folders;

namespace tests
{

void FilesWidgetTest::test()
{
    std::ifstream file;

    file.open(dataPath + "files.xml", std::ifstream::in);

    QVERIFY(file.good());

    if (file.good())
    {
        auto files = Files_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<FilesModelBuilder>();
        auto model = modelBuilder->schemaToModel(files);

        auto filesWidget = std::make_unique<FilesWidget>();
        auto containerItem = model->topItem();
        auto filesContainer = dynamic_cast<FilesContainerItem*>(containerItem);

        if (filesContainer)
        {
            filesWidget->setItem(filesContainer->children().back());
            filesWidget->show();
        }

        QTest::qWait(10000);
    }

    file.close();
}

}

QTEST_MAIN(tests::FilesWidgetTest)
