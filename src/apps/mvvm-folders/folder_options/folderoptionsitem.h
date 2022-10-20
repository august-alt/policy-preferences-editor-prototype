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

#ifndef MVVM_FOLDERS_FOLDER_OPTIONS_ITEM_H
#define MVVM_FOLDERS_FOLDER_OPTIONS_ITEM_H

#include <mvvm/model/compounditem.h>

namespace mvvm_folders
{

//! Drives item representation for editor.

class FolderOptionsItem : public ModelView::CompoundItem
{
public:
    static inline const std::string NO_NETCRAWLING = "noNetCrawlingType";
    static inline const std::string fOLDER_CONTENTS_INFO_TIP = "folderContentsInfoTip";
    static inline const std::string FRIENDLY_TREE = "friendlyTree";
    static inline const std::string FULL_PATH_ADDRESS = "fullPathAddress";
    static inline const std::string FULL_PATH = "fullPath";
    static inline const std::string DISAIBLE_THUMBNAIL_CACHE = "DisableThumbnailCache";
    static inline const std::string HIDDEN = "Hidden";
    static inline const std::string HIDE_FILE_EXT = "HideFileExt";
    static inline const std::string SEPERATE_PROCESS = "SeparateProcess";
    static inline const std::string SHOW_SUPER_HIDDEN = "ShowSuperHidden";
    static inline const std::string PERSIST_BROWSERS = "PersistBrowsers";
    static inline const std::string CLASSIC_VIEW_STATE = "ClassicViewState";
    static inline const std::string SHOW_CONTROL_PANEL = "ShowControlPanel";
    static inline const std::string SHOW_COMP_COLOR = "ShowCompColor";
    static inline const std::string SHOW_INFO_TIP = "ShowInfoTip";
    static inline const std::string FORCE_GUEST = "ForceGuest";
    static inline const std::string WEB_VIEW_BARRICADE = "WebViewBarricade";


    FolderOptionsItem();
    FolderOptionsItem(const FolderOptionsItem &other);
};

}

Q_DECLARE_METATYPE(::mvvm_folders::FolderOptionsItem)

#endif//MVVM_FOLDERS_FOLDER_OPTIONS_ITEM_H
