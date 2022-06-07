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

#include "ini/inicontaineritem.h"
#include "ini/iniitem.h"
#include "ini/iniwidget.h"
#include "ini/inimodelbuilder.h"

const std::string dataPath = "../../../../../data/preferences/user/settings/ini/";

using namespace mvvm_folders;

namespace tests
{

void IniWidgetTest::test()
{
    std::ifstream file;

    file.open(dataPath + "ini_files.xml", std::ifstream::in);

    QVERIFY(file.good());

    if (file.good())
    {
        auto ini = IniFiles_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<IniModelBuilder>();
        auto model = modelBuilder->schemaToModel(ini);

        auto iniWidget = std::make_unique<IniWidget>();
        auto containerItem = model->topItem();
        auto iniContainer = dynamic_cast<IniContainerItem*>(containerItem);

        if (iniContainer)
        {
            iniWidget->setItem(iniContainer->children().back());
            iniWidget->show();
        }

        QTest::qWait(10000);
    }

    file.close();
}

}

QTEST_MAIN(tests::IniWidgetTest)

