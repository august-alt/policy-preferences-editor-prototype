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

#ifndef MVVM_FOLDERS_POWER_SCHEME_ITEM_H
#define MVVM_FOLDERS_POWER_SCHEME_ITEM_H

#include "common/basepreferenceitem.h"

namespace mvvm_folders
{

//! Power scheme item representation for editor.

class PowerSchemeItem : public BasePreferenceItem<PowerSchemeItem>
{
public:
    enum PropertyType
    {
        ACTION       = 0,
        NAME         = 1,
        DEFAULT      = 2,
        MONITOR_AC   = 3,
        HARD_DISK_AC = 4,
        STANDBY_AC   = 5,
        HIBERNATE_AC = 6,
        MONITOR_DC   = 7,
        HARD_DISK_DC = 8,
        STANDBY_DC   = 9,
        HIBERNATE_DC = 10
    };

    PowerSchemeItem();
    PowerSchemeItem(const PowerSchemeItem &other);

    constexpr static const char* propertyToString(const PropertyType& type);
};

}

Q_DECLARE_METATYPE(::mvvm_folders::PowerSchemeItem)

#include "powerschemeitem.inl"

#endif//MVVM_FOLDERS_POWER_SCHEME_ITEM_H
