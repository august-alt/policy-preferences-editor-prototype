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

#include "inimodeltest.h"

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

void IniModelTest::iniFileGeneration()
{
    std::ifstream file;

    file.open(dataPath + "ini_files.xml", std::ifstream::in);

    bool ok = file.good();
    if(!ok)
    {
        qWarning() << "Failed to read file: " << dataPath.c_str() << "ini_files.xml";
        return;
    }

    auto ini = IniFiles_(file, ::xsd::cxx::tree::flags::dont_validate);
    auto modelBuilder = std::make_unique<IniModelBuilder>();
    auto model = modelBuilder->schemaToModel(ini);

    file.close();

    auto schema = modelBuilder->modelToSchema(model);

    std::cout << *schema << std::endl;
}

}

QTEST_MAIN(tests::IniModelTest)

