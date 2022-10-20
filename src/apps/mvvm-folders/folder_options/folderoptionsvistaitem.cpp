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

#include "folderoptionsvistaitem.h"

namespace mvvm_folders
{

FolderOptionsVistaItem::FolderOptionsVistaItem()
    : ModelView::CompoundItem("FolderOptionsVistaItem")
{
    addProperty(ALWAYS_SHOW_ICON, false);
    addProperty(ALWAYS_SHOW_MENUS , true);
    addProperty(DISPLAY_ICON_THUMB, true);
    addProperty(DISPLAY_FILE_SIZE, true);
    addProperty(DISPLAY_SIMPLE_FOLDERS, false);
    addProperty(FULL_PATH, false);
    addProperty(HIDDEN, "");
    addProperty(HIDE_FILE_EXT, true);
    addProperty(SHOW_SUPER_HIDDEN, false);
    addProperty(SEPARATE_PROCESS, true);
    addProperty(CLASSIC_VIEW_STATE, true);
    addProperty(PERSIST_BROWSERS, true);
    addProperty(SHOW_DRIVE_LETTER, true);
    addProperty(SHOW_COMP_COLOR, true);
    addProperty(SHOW_INFO_TIP, true);
    addProperty(SHOW_PREVIEW_HANDLERS, true);
    addProperty(USE_CHECK_BOXES, true);
    addProperty(USE_SHARING_WIZARD, true);
    addProperty(LIST_VIEW_TYPING, "");
}

FolderOptionsVistaItem::FolderOptionsVistaItem(const FolderOptionsVistaItem &other)
    : ModelView::CompoundItem("FolderOptionsVistaItem")
{
    addProperty(ALWAYS_SHOW_ICON, other.property<bool>(ALWAYS_SHOW_ICON));
    addProperty(ALWAYS_SHOW_MENUS, other.property<bool>(ALWAYS_SHOW_MENUS));
    addProperty(DISPLAY_ICON_THUMB, other.property<bool>(DISPLAY_ICON_THUMB));
    addProperty(DISPLAY_FILE_SIZE, other.property<bool>(DISPLAY_FILE_SIZE));
    addProperty(DISPLAY_SIMPLE_FOLDERS, other.property<bool>(DISPLAY_SIMPLE_FOLDERS));
    addProperty(FULL_PATH, other.property<bool>(FULL_PATH));
    addProperty(HIDDEN, other.property<std::string>(HIDDEN));
    addProperty(HIDE_FILE_EXT, other.property<bool>(HIDE_FILE_EXT));
    addProperty(SHOW_SUPER_HIDDEN, other.property<bool>(SHOW_SUPER_HIDDEN));
    addProperty(SEPARATE_PROCESS, other.property<bool>(SEPARATE_PROCESS));
    addProperty(CLASSIC_VIEW_STATE, other.property<bool>(CLASSIC_VIEW_STATE));
    addProperty(PERSIST_BROWSERS, other.property<bool>(PERSIST_BROWSERS));
    addProperty(SHOW_DRIVE_LETTER, other.property<bool>(SHOW_DRIVE_LETTER));
    addProperty(SHOW_COMP_COLOR, other.property<bool>(SHOW_COMP_COLOR));
    addProperty(SHOW_INFO_TIP, other.property<bool>(SHOW_INFO_TIP));
    addProperty(SHOW_PREVIEW_HANDLERS, other.property<bool>(SHOW_PREVIEW_HANDLERS));
    addProperty(USE_CHECK_BOXES, other.property<bool>(USE_CHECK_BOXES));
    addProperty(USE_SHARING_WIZARD, other.property<bool>(USE_SHARING_WIZARD));
    addProperty(LIST_VIEW_TYPING, other.property<std::string>(LIST_VIEW_TYPING));
}

}
