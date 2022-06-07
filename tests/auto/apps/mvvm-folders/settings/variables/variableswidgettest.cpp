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
#include "variables/variableswidget.h"
#include "variables/variablesmodelbuilder.h"

const std::string dataPath = "../../../../../data/preferences/user/settings/variables/";

using namespace mvvm_folders;

namespace tests
{

void VariablesWidgetTest::test()
{
    std::ifstream file;

    file.open(dataPath + "environment.xml", std::ifstream::in);

    QVERIFY(file.good());

    if (file.good())
    {
        auto variables = EnvironmentVariables_(file, ::xsd::cxx::tree::flags::dont_validate);
        auto modelBuilder = std::make_unique<VariablesModelBuilder>();
        auto model = modelBuilder->schemaToModel(variables);

        auto variablesWidget = std::make_unique<VariablesWidget>();
        auto containerItem = model->topItem();
        auto variablesContainer = dynamic_cast<VariablesContainerItem*>(containerItem);

        if (variablesContainer)
        {
            variablesWidget->setItem(variablesContainer->children().back());
            variablesWidget->show();
        }

        QTest::qWait(10000);
    }

    file.close();
}

}

QTEST_MAIN(tests::VariablesWidgetTest)

