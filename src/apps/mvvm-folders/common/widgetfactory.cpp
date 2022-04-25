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

#include "widgetfactory.h"

#include <map>
#include <memory>

#include "drives/driveswidget.h"
#include "files/fileswidget.h"
#include "folders/folderview.h"
#include "ini/iniwidget.h"
#include "shares/shareswidget.h"
#include "shortcuts/shortcutswidget.h"
#include "variables/variableswidget.h"

namespace mvvm_folders
{

class WidgetFactoryPrivate
{
public:
    std::map<std::string, std::function<std::unique_ptr<PreferenceWidgetInterface>() > > constructors{};
};

WidgetFactory::WidgetFactory()
    : d(std::make_unique<WidgetFactoryPrivate>())
{
    registerItem("DrivesItem", [](){ return std::make_unique<DrivesWidget>(); });
    registerItem("FilesItem", [](){ return std::make_unique<FilesWidget>(); });
    // TODO: FoldersWidget
    registerItem("IniItem", [](){ return std::make_unique<IniWidget>(); });
    registerItem("SharesItem", [](){ return std::make_unique<SharesWidget>(); });
    registerItem("ShortcutsItem", [](){ return std::make_unique<ShortcutsWidget>(); });
    registerItem("VariablesItem", [](){ return std::make_unique<VariablesWidget>(); });
}

WidgetFactory::~WidgetFactory() = default;

void WidgetFactory::registerItem(const std::string &type,
                                 std::function<std::unique_ptr<PreferenceWidgetInterface>() > func)
{
    d->constructors[type] = func;
}

std::unique_ptr<PreferenceWidgetInterface> WidgetFactory::create(const std::string &type) const
{
    auto func = d->constructors.find(type);

    if (func != d->constructors.end())
    {
        return func->second();
    }

    return nullptr;
}

}