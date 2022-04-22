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

#include "variablescontaineritem.h"

#include "common/commonitem.h"
#include "variablesitem.h"

namespace mvvm_folders
{

VariablesContainerItem::VariablesContainerItem()
    : ModelView::CompoundItem("VariablesContainerItem")
{
    addProperty<CommonItem>(COMMON);
    addProperty<VariablesItem>(VARIABLES);
}

CommonItem VariablesContainerItem::getCommon() const
{
    return property<CommonItem>(COMMON);
}

void VariablesContainerItem::setCommon(const CommonItem &item)
{
    setProperty(COMMON, item);
}

VariablesItem VariablesContainerItem::getVariables() const
{
    return property<VariablesItem>(VARIABLES);
}

void VariablesContainerItem::setVariables(const VariablesItem &item)
{
    setProperty(VARIABLES, item);
}

}
