﻿/***********************************************************************************************************************
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

#ifndef MVVM_FOLDERS_POWER_OPTIONS_ITEM_H
#define MVVM_FOLDERS_POWER_OPTIONS_ITEM_H

#include "common/basepreferenceitem.h"

namespace mvvm_folders
{

//! Drives item representation for editor.

class PowerOptionsItem : public BasePreferenceItem<PowerOptionsItem>
{
public:
    enum PropertyType
    {
        CLOSE_LID          = 0,
        PRESS_POWER_BUTTON = 1,
        PRESS_SLEEP_BUTTON = 2,
        SHOW_ICON          = 3,
        PROMPT_PASSWORD    = 4,
        ENABLE_HIBERNATION = 5,
        NAME               = 6
    };

    PowerOptionsItem();
    PowerOptionsItem(const PowerOptionsItem &other);

    constexpr static const char* propertyToString(const PropertyType& type);
};

}

Q_DECLARE_METATYPE(::mvvm_folders::PowerOptionsItem)

#endif//MVVM_FOLDERS_POWER_OPTIONS_ITEM_H
