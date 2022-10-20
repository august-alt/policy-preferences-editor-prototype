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

#include "folderoptionsitem.h"

namespace mvvm_folders
{

FolderOptionsItem::FolderOptionsItem()
    : ModelView::CompoundItem("FolderOptionsItem")
{
    addProperty(NO_NETCRAWLING, false);
    addProperty(fOLDER_CONTENTS_INFO_TIP, true);
    addProperty(FRIENDLY_TREE, true);
    addProperty(FULL_PATH_ADDRESS, true);
    addProperty(FULL_PATH, false);
    addProperty(DISAIBLE_THUMBNAIL_CACHE, false);
    addProperty(HIDDEN, false);
    addProperty(HIDE_FILE_EXT, true);
    addProperty(SEPERATE_PROCESS, false);
    addProperty(SHOW_SUPER_HIDDEN, true);
    addProperty(PERSIST_BROWSERS, true);
    addProperty(CLASSIC_VIEW_STATE, true);
    addProperty(SHOW_CONTROL_PANEL, true);
    addProperty(SHOW_COMP_COLOR, true);
    addProperty(SHOW_INFO_TIP, true);
    addProperty(FORCE_GUEST, true);
    addProperty(WEB_VIEW_BARRICADE, true);
}

FolderOptionsItem::FolderOptionsItem(const FolderOptionsItem &other)
    : ModelView::CompoundItem("FolderOptionsItem")
{
    addProperty(NO_NETCRAWLING, other.property<bool>(NO_NETCRAWLING));
    addProperty(fOLDER_CONTENTS_INFO_TIP, other.property<bool>(fOLDER_CONTENTS_INFO_TIP));
    addProperty(FRIENDLY_TREE, other.property<bool>(FRIENDLY_TREE));
    addProperty(FULL_PATH_ADDRESS, other.property<bool>(FULL_PATH_ADDRESS));
    addProperty(FULL_PATH, other.property<bool>(FULL_PATH));
    addProperty(DISAIBLE_THUMBNAIL_CACHE, other.property<bool>(DISAIBLE_THUMBNAIL_CACHE));
    addProperty(HIDDEN, other.property<bool>(HIDDEN));
    addProperty(HIDE_FILE_EXT, other.property<bool>(HIDE_FILE_EXT));
    addProperty(SEPERATE_PROCESS, other.property<bool>(SEPERATE_PROCESS));
    addProperty(SHOW_SUPER_HIDDEN, other.property<bool>(SHOW_SUPER_HIDDEN));
    addProperty(PERSIST_BROWSERS, other.property<bool>(PERSIST_BROWSERS));
    addProperty(CLASSIC_VIEW_STATE, other.property<bool>(CLASSIC_VIEW_STATE));
    addProperty(SHOW_CONTROL_PANEL, other.property<bool>(SHOW_CONTROL_PANEL));
    addProperty(SHOW_COMP_COLOR, other.property<bool>(SHOW_COMP_COLOR));
    addProperty(SHOW_INFO_TIP, other.property<bool>(SHOW_INFO_TIP));
    addProperty(FORCE_GUEST, other.property<bool>(FORCE_GUEST));
    addProperty(WEB_VIEW_BARRICADE, other.property<bool>(WEB_VIEW_BARRICADE));
}

}
