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

#include "drivesitem.h"

namespace mvvm_folders
{

DrivesItem::DrivesItem()
    : ModelView::CompoundItem("DrivesItem")
{
    addProperty(ACTION, "");
    addProperty(PATH, "");
    addProperty(PERSISTENT, false);
    addProperty(LABEL, "");
    addProperty(LETTER, "");
    addProperty(USER_NAME, "");
    addProperty(CPASSWORD, "");
    addProperty(USE_LETTER, "");
    addProperty(THIS_DRIVE, "");
    addProperty(ALL_DRIVES, false);
}

DrivesItem::DrivesItem(const DrivesItem &other)
    : ModelView::CompoundItem("DrivesItem")
{
    addProperty(ACTION, other.property<QString>(ACTION));
    addProperty(PATH, other.property<QString>(PATH));
    addProperty(PERSISTENT, other.property<bool>(PERSISTENT));
    addProperty(LABEL, other.property<QString>(LABEL));
    addProperty(LETTER, other.property<QString>(LETTER));
    addProperty(USER_NAME, other.property<QString>(USER_NAME));
    addProperty(CPASSWORD, other.property<QString>(CPASSWORD));
    addProperty(USE_LETTER, other.property<QString>(USE_LETTER));
    addProperty(THIS_DRIVE, other.property<QString>(THIS_DRIVE));
    addProperty(ALL_DRIVES, other.property<bool>(ALL_DRIVES));
}

}
