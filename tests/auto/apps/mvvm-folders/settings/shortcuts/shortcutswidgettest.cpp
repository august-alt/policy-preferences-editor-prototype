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

#include "shortcutswidgettest.h"

#include <fstream>

#include "shortcuts/shortcutscontaineritem.h"
#include "shortcuts/shortcutsitem.h"
#include "shortcuts/shortcutswidget.h"
#include "shortcuts/shortcutsmodelbuilder.h"

const std::string dataPath = "../../../../../data/preferences/user/settings/shortcuts/";

using namespace mvvm_folders;

namespace tests
{

void ShortcutsWidgetTest::test()
{
    std::ifstream file;

    file.open(dataPath + "shortcuts.xml", std::ifstream::in);

    QVERIFY(file.good());

    if (file.good())
    {
        try {
            auto shortcuts = Shortcuts_(file, ::xsd::cxx::tree::flags::dont_validate);
            auto modelBuilder = std::make_unique<ShortcutsModelBuilder>();
            auto model = modelBuilder->schemaToModel(shortcuts);

            auto shortcutsWidget = std::make_unique<ShortcutsWidget>();
            auto containerItem = model->topItem();
            auto shortcutsContainer = dynamic_cast<ShortcutsContainerItem*>(containerItem);

            if (shortcutsContainer)
            {
                shortcutsWidget->setItem(shortcutsContainer->children().back());
                shortcutsWidget->show();
            }

            QTest::qWait(10000);
        }
        catch (const xsd::cxx::tree::unexpected_element<char>& e)
        {
            qWarning() << "Error an unexpected element: " << e.encountered_name().c_str() << " in namespace: "
                       << e.encountered_namespace().c_str() << " was encountered. Expected element: "
                       << e.expected_name().c_str() << " in namespace: " << e.expected_namespace().c_str();
        }
        catch (const xsd::cxx::tree::expected_element<char>& e)
        {
            qWarning() << "Error an expected element: " << e.name().c_str()
                      << " in namespace: " << e.namespace_().c_str() <<" was not encountered: ";
        }
        catch (const xsd::cxx::tree::expected_attribute<char>& e)
        {
            qWarning() <<"Error an expected attribute: " << e.name().c_str()
                      << " in namespace: " << e.namespace_().c_str() <<" was not encountered: ";
        }
        catch (const xsd::cxx::tree::unexpected_enumerator<char>& e)
        {
            qWarning() <<"Error an unexpected enumerator: " << e.enumerator().c_str();
        }
        catch (const xsd::cxx::tree::expected_text_content<char>& e)
        {
            qWarning() << "Error text content was expected for an element." << e.what();
        }
        catch (const xsd::cxx::tree::no_element_info<char>& e)
        {
            qWarning() <<"Error no information available for element: " << e.element_name().c_str();
        }
        catch (const xsd::cxx::tree::no_type_info<char>& e)
        {
            qWarning() << "Error no type information available for: " << e.type_name().c_str() << " in namespace: "
                       << e.type_namespace().c_str();
        }
        catch (const xsd::cxx::tree::duplicate_id<char>& e)
        {
            qWarning() << "Error duplicate ID value was encountered in the object model: " << e.id().c_str();
        }
        catch (const xsd::cxx::tree::no_prefix_mapping<char>& e)
        {
            qWarning() << "Error no prefix-namespace mapping was provided for prefix: " << e.prefix().c_str();
        }
        catch (const xsd::cxx::tree::bounds<char>& e)
        {
            qWarning() << "Size of argument exceeds the capacity argument: " << e.what();
        }
        catch (const xsd::cxx::tree::exception<char>& e)
        {
            qWarning() << "Verification error: " << e.what();
        }
        catch (const xsd::cxx::xml::invalid_utf16_string&)
        {
            qWarning() << "Invalid UTF-16 text in DOM model.";
        }
        catch (const xsd::cxx::xml::invalid_utf8_string&)
        {
            qWarning() << "Invalid UTF-8 text in object model.";
        }
        catch (const std::exception& e)
        {
            qWarning() << "Error: " << e.what();
        }
    }

    file.close();
}

}

QTEST_MAIN(tests::ShortcutsWidgetTest)

