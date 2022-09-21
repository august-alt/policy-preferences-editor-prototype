#ifndef FOLDEROPTIONSVISTAITEM_H
#define FOLDEROPTIONSVISTAITEM_H

#include <mvvm/model/compounditem.h>

namespace mvvm_folders
{

class FoldersOptionsVistaItem : public ModelView::CompoundItem
{
public:
    static inline const std::string ACTION = "action";
    static inline const std::string ALWAYS_SHOW_ICONS = "alwaysShowIcons";
    static inline const std::string ALWAYS_SHOW_MENUS = "alwaysShowMenus";
    static inline const std::string DISOLAY_ICON_THUMB = "displayIconThumb";
    static inline const std::string DISPLAY_FILE_SIZE = "displayFileSize";
    static inline const std::string DISPLAY_SIMPLE_FOLDERS = "displaySimpleFolders";
    static inline const std::string FULL_PATH = "fullPath";
    static inline const std::string HIDDEN = "hidden";
    static inline const std::string HIDE_FILE_EXT = "hideFileExt";
    static inline const std::string SHOW_SUPER_HIDDEN = "showSuperHidden";
    static inline const std::string SEPARETE_PROCESS = "separateProcess";
    static inline const std::string CLASSIC_VIEW_STATE = "classicViewState";
    static inline const std::string PERSIST_BROWSERS = "persistBrowsers";
    static inline const std::string SHOW_DRIVE_LETTER = "showDriveLetter";
    static inline const std::string SHOW_COMP_COLOR = "showCompColor";
    static inline const std::string SHOW_INFO_TIP = "showInfoTip";
    static inline const std::string SHOW_PREVIEW_HANDLERS = "showPreviewHandlers";
    static inline const std::string USE_CHECK_BOXES = "useCheckBoxes";
    static inline const std::string USE_SHARING_WIZARD = "useSharingWizard";
    static inline const std::string LIST_VIEW_TYPING = "listViewTyping";

    FoldersOptionsVistaItem();
    FoldersOptionsVistaItem(const FoldersOptionsVistaItem &other);
};

}

Q_DECLARE_METATYPE(::mvvm_folders::FoldersOptionsVistaItem)


#endif // FOLDEROPTIONSVISTAITEM_H
