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

#include "drivescontaineritem.h"

#include "commonitem.h"
#include "drivesitem.h"

namespace mvvm_folders
{

DrivesContainerItem::DrivesContainerItem()
    : ModelView::CompoundItem("DrivesContainerItem")
{
    addProperty<CommonItem>(COMMON);
    addProperty<DrivesItem>(DRIVES);
}

CommonItem DrivesContainerItem::getCommon() const
{
    return property<CommonItem>(COMMON);
}

void DrivesContainerItem::setCommon(const CommonItem &item)
{
    setProperty(COMMON, item);
}

DrivesItem DrivesContainerItem::getDrives() const
{
    return property<DrivesItem>(DRIVES);
}

void DrivesContainerItem::setDrives(const DrivesItem &item)
{
    setProperty(DRIVES, item);
}

}
