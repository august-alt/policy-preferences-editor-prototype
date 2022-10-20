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

#ifndef MVVM_FOLDERS_FOLDEROPTIONSVISTAITEM_H
#define MVVM_FOLDERS_FOLDEROPTIONSVISTAITEM_H

//#ifndef MVVM_FOLDERS_OPEN_WITH_ITEM_H
//#define MVVM_FOLDERS_OPEN_WITH_ITEM_H

#include <mvvm/model/compounditem.h>

namespace mvvm_folders
{

//! Drives item representation for editor.

class FolderOptionsVistaItem : public ModelView::CompoundItem
{
public:
    static inline const std::string ACTION = "action";
    static inline const std::string ALWAYS_SHOW_ICON = "alwaysShowIcons";
    static inline const std::string ALWAYS_SHOW_MENUS = "alwaysShowMenus";
    static inline const std::string DISPLAY_ICON_THUMB = "displayIconThumb";
    static inline const std::string DISPLAY_FILE_SIZE = "displayFileSize";
    static inline const std::string DISPLAY_SIMPLE_FOLDERS = "displaySimpleFolders";
    static inline const std::string FULL_PATH = "fullPath";
    static inline const std::string HIDDEN = "hidden";
    static inline const std::string HIDE_FILE_EXT = "hideFileExt";
    static inline const std::string SHOW_SUPER_HIDDEN = "showSuperHidden";
    static inline const std::string SEPARATE_PROCESS = "separateProcess";
    static inline const std::string CLASSIC_VIEW_STATE = "classicViewState";
    static inline const std::string PERSIST_BROWSERS = "persistBrowsers";
    static inline const std::string SHOW_DRIVE_LETTER = "showDriveLetter";
    static inline const std::string SHOW_COMP_COLOR = "showCompColor";
    static inline const std::string SHOW_INFO_TIP = "showInfoTip";
    static inline const std::string SHOW_PREVIEW_HANDLERS = "showPreviewHandlers";
    static inline const std::string USE_CHECK_BOXES = "useCheckBoxes";
    static inline const std::string USE_SHARING_WIZARD = "useSharingWizard";
    static inline const std::string LIST_VIEW_TYPING = "listViewTyping";

    FolderOptionsVistaItem();
    FolderOptionsVistaItem(const FolderOptionsVistaItem &other);
};

}

Q_DECLARE_METATYPE(::mvvm_folders::FolderOptionsVistaItem)

//#endif//MVVM_FOLDERS_OPEN_WITH_ITEM_H

#endif // MVVM_FOLDERS_FOLDEROPTIONSVISTAITEM_H
