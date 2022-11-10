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

#include "diskspaceitem.h"

namespace mvvm_folders
{

DiskSpaceItem::DiskSpaceItem()
    : ModelView::CompoundItem("DiskSpaceItem")
{
    addProperty(FREE_SPACE, "");
    addProperty(DRIVE_LETTER, "");
}

DiskSpaceItem::DiskSpaceItem(const DiskSpaceItem &other)
    : ModelView::CompoundItem("DiskSpaceItem")
{
    addProperty(FREE_SPACE, other.freeSpace());
    addProperty(DRIVE_LETTER, other.driveLetter());
}

QString DiskSpaceItem::freeSpace() const
{
    return property<QString>(FREE_SPACE);
}

void DiskSpaceItem::setFreeSpace(const QString &freeSpace)
{
    setProperty(FREE_SPACE, freeSpace);
}

QString DiskSpaceItem::driveLetter() const
{
    return property<QString>(DRIVE_LETTER);
}

void DiskSpaceItem::setDriveLetter(const QString &driveLetter)
{
    setProperty(DRIVE_LETTER, driveLetter);
}

}
