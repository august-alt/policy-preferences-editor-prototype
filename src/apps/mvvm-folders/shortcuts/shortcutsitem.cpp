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

#include "shortcutsitem.h"

namespace mvvm_folders
{

ShortcutsItem::ShortcutsItem()
    : ModelView::CompoundItem("ShortcutsItem")
{
    addProperty(ACTION, "");
    addProperty(PIDL, "");
    addProperty(SHORTCUT_PATH, "");
    addProperty(TARGET_TYPE, "");
    addProperty(TARGET_PATH, "");
    addProperty(ARGUMENTS, "");
    addProperty(START_IN, "");
    addProperty(SHORTCUT_KEY, "");
    addProperty(WINDOW, "");
    addProperty(COMMENT, "");
    addProperty(ICON_PATH, "");
    addProperty(ICON_INDEX, "");
}

ShortcutsItem::ShortcutsItem(const ShortcutsItem &other)
    : ModelView::CompoundItem("ShortcutsItem")
{
    addProperty(ACTION, other.property<QString>(ACTION));
    addProperty(PIDL, other.property<QString>(PIDL));
    addProperty(SHORTCUT_PATH, other.property<QString>(SHORTCUT_PATH));
    addProperty(TARGET_TYPE, other.property<QString>(TARGET_TYPE));
    addProperty(TARGET_PATH, other.property<QString>(TARGET_PATH));
    addProperty(ARGUMENTS, other.property<QString>(ARGUMENTS));
    addProperty(START_IN, other.property<QString>(START_IN));
    addProperty(SHORTCUT_KEY, other.property<QString>(SHORTCUT_KEY));
    addProperty(WINDOW, other.property<QString>(WINDOW));
    addProperty(COMMENT, other.property<QString>(COMMENT));
    addProperty(ICON_PATH, other.property<QString>(ICON_PATH));
    addProperty(ICON_INDEX, other.property<QString>(ICON_INDEX));
}

}
