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

#include "driveswidgettest.h"

#include "drives/drivescontaineritem.h"
#include "drives/drivesitem.h"
#include "drives/driveswidget.h"
#include "drives/drivesmodelbuilder.h"

#include <fstream>

const std::string dataPath = "../../../../../data/preferences/user/settings/drives/";

namespace tests
{

using namespace mvvm_folders;

void DrivesWidgetTest::test()
{
    std::ifstream file;

    file.open(dataPath + "drive_maps.xml", std::ifstream::in);

    QVERIFY(file.good());

    if (file.good())
    {
            auto drives = Drives_(file, ::xsd::cxx::tree::flags::dont_validate);
            auto modelBuilder = std::make_unique<DrivesModelBuilder>();
            auto model = modelBuilder->schemaToModel(drives);

            auto drivesWidget = DrivesWidget();
            auto containerItem = model->topItem();
            if (auto drivesContainer = dynamic_cast<DrivesContainerItem*>(containerItem); drivesContainer)
            {
                drivesWidget.setItem(drivesContainer->children().back());
                drivesWidget.show();
            }

        QTest::qWait(10000);
    }

    file.close();
}

}

QTEST_MAIN(tests::DrivesWidgetTest)

