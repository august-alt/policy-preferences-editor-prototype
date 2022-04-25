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

#include "inicontaineritem.h"

#include "common/commonitem.h"
#include "iniitem.h"

namespace mvvm_folders
{

IniContainerItem::IniContainerItem()
    : ModelView::CompoundItem("IniContainerItem")
{
    addProperty<CommonItem>(COMMON);
    addProperty<IniItem>(INI);
}

CommonItem IniContainerItem::getCommon() const
{
    return property<CommonItem>(COMMON);
}

void IniContainerItem::setCommon(const CommonItem &item)
{
    setProperty(COMMON, item);
}

IniItem IniContainerItem::getIni() const
{
    return property<IniItem>(INI);
}

void IniContainerItem::setIni(const IniItem &item)
{
    setProperty(INI, item);
}

void IniContainerItem::setupListeners()
{

}

}
