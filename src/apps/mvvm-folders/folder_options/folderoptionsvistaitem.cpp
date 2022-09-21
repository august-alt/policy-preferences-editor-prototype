
#include "folderoptionsvistaitem.h"

namespace mvvm_folders
{

FoldersOptionsVistaItem::FoldersOptionsVistaItem()
    : ModelView::CompoundItem("FoldersOptionsVistaItem")
{
    addProperty(ACTION, "");
    addProperty(ALWAYS_SHOW_ICONS, false);
    addProperty(ALWAYS_SHOW_MENUS, false);
    addProperty(DISOLAY_ICON_THUMB, true);
    addProperty(DISPLAY_FILE_SIZE, true);
    addProperty(DISPLAY_SIMPLE_FOLDERS, true);
    addProperty(FULL_PATH, false);
    addProperty(HIDDEN, "");
    addProperty(HIDE_FILE_EXT, true);
    addProperty(SHOW_SUPER_HIDDEN, true);
    addProperty(SEPARETE_PROCESS, false);
    addProperty(CLASSIC_VIEW_STATE, true);
    addProperty(PERSIST_BROWSERS, false);
    addProperty(SHOW_DRIVE_LETTER, true);
    addProperty(SHOW_COMP_COLOR, true);
    addProperty(SHOW_INFO_TIP, true);
    addProperty(SHOW_PREVIEW_HANDLERS, true);
    addProperty(USE_CHECK_BOXES, false);
    addProperty(USE_SHARING_WIZARD, true);
    addProperty(LIST_VIEW_TYPING, "");

}

FoldersOptionsVistaItem::FoldersOptionsVistaItem(const FoldersOptionsVistaItem &other)
    : ModelView::CompoundItem("FoldersOptionsVistaItem")
{
    addProperty(ACTION, other.property<QString>(ACTION));
    addProperty(ALWAYS_SHOW_ICONS, other.property<bool>(ALWAYS_SHOW_ICONS));
    addProperty(ALWAYS_SHOW_MENUS, other.property<bool>(ALWAYS_SHOW_MENUS));
    addProperty(DISOLAY_ICON_THUMB, other.property<bool>(DISOLAY_ICON_THUMB));
    addProperty(DISPLAY_FILE_SIZE, other.property<bool>(DISPLAY_FILE_SIZE));
    addProperty(DISPLAY_SIMPLE_FOLDERS, other.property<bool>(DISPLAY_SIMPLE_FOLDERS));
    addProperty(FULL_PATH, other.property<bool>(FULL_PATH));
    addProperty(HIDDEN, other.property<std::string>(HIDDEN));
    addProperty(HIDE_FILE_EXT, other.property<bool>(HIDE_FILE_EXT));
    addProperty(SHOW_SUPER_HIDDEN, other.property<bool>(SHOW_SUPER_HIDDEN));
    addProperty(SEPARETE_PROCESS, other.property<bool>(SEPARETE_PROCESS));
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
