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

#include "powerschemeitem.h"

namespace mvvm_folders
{

PowerSchemeItem::PowerSchemeItem()
    : BasePreferenceItem<PowerSchemeItem>("PowerSchemeItem")
{
    addProperty(propertyToString(ACTION), "");
    addProperty(propertyToString(NAME), "");
    addProperty(propertyToString(DEFAULT), false);
    addProperty(propertyToString(MONITOR_AC), 0);
    addProperty(propertyToString(HARD_DISK_AC), 0);
    addProperty(propertyToString(STANDBY_AC), 0);
    addProperty(propertyToString(HIBERNATE_AC), 0);
    addProperty(propertyToString(MONITOR_DC), 0);
    addProperty(propertyToString(HARD_DISK_DC), 0);
    addProperty(propertyToString(STANDBY_DC), 0);
    addProperty(propertyToString(HIBERNATE_DC), 0);
}

PowerSchemeItem::PowerSchemeItem(const PowerSchemeItem &other)
    : BasePreferenceItem<PowerSchemeItem>("PowerSchemeItem")
{
    copyProperty<std::string>(ACTION, other);
    copyProperty<std::string>(NAME, other);
    copyProperty<bool>(DEFAULT, other);
    copyProperty<int>(MONITOR_AC, other);
    copyProperty<int>(HARD_DISK_AC, other);
    copyProperty<int>(STANDBY_AC, other);
    copyProperty<int>(HIBERNATE_AC, other);
    copyProperty<int>(MONITOR_DC, other);
    copyProperty<int>(HARD_DISK_DC, other);
    copyProperty<int>(STANDBY_DC, other);
    copyProperty<int>(HIBERNATE_DC, other);
}

constexpr const char *PowerSchemeItem::propertyToString(const PowerSchemeItem::PropertyType &type)
{
    switch (type)
    {
    case ACTION:
        return "action";
    case NAME:
        return "name";
    case DEFAULT:
        return "default";
    case MONITOR_AC:
        return "monitorAc";
    case HARD_DISK_AC:
        return "hardDiskAc";
    case STANDBY_AC:
        return "standbyAc";
    case HIBERNATE_AC:
        return "hibernateAc";
    case MONITOR_DC:
        return "monitorDc";
    case HARD_DISK_DC:
        return "hardDiskDc";
    case STANDBY_DC:
        return "standbyDc";
    case HIBERNATE_DC:
        return "hibernateDc";
    }

    return "";
}

}
