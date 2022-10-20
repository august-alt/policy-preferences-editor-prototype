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

#include "folderoptionsmodelbuilder.h"

#include "folderoptionscontaineritem.h"
#include "folderoptionsitem.h"
#include "fileextensionactionitem.h"
#include "fileextensioncontaineritem.h"
#include "fileextensionitem.h"
#include "openwithitem.h"
#include "openwithwidget.h"
#include "folderoptionsvistaitem.h"

#include "common/commonitem.h"

namespace mvvm_folders
{

FolderOptionsModelBuilder::FolderOptionsModelBuilder()
    : BaseModelBuilder()
{
}

std::unique_ptr<PreferencesModel> FolderOptionsModelBuilder::schemaToModel(std::unique_ptr<FolderOptions> &folderOptionsSource)
{
    Q_UNUSED(folderOptionsSource);

    auto model = std::make_unique<PreferencesModel>();

    // TODO: Implement.

    return model;
}

std::unique_ptr<FolderOptions> FolderOptionsModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    auto folderOptions = std::make_unique<FolderOptions>("{8AB5F5D7-F676-48ab-A94E-1186E120EFDC}");

    for (const auto& containerItem : model->topItems())
    {
        if (auto fileContainer = dynamic_cast<FolderOptionsContainerItem<FileExtensionItem>*>(containerItem); fileContainer)
        {
            auto fileModel = fileContainer->getFolderOption();
            auto commonModel = fileContainer->getCommon();

            auto files = createRootElement<FileType_t>("{580C4D3B-7A89-44d0-92D2-C105702C7BD0}");
            auto properties = FileTypeProperties_t(fileModel.property<std::string>(FileExtensionItem::propertyToString(FileExtensionItem::FILE_EXT)),
                                                   fileModel.property<std::string>(FileExtensionItem::propertyToString(FileExtensionItem::APPLICATION)),
                                                   fileModel.property<std::string>(FileExtensionItem::propertyToString(FileExtensionItem::APP_PROG_ID)),
                                                   fileModel.property<bool>(FileExtensionItem::propertyToString(FileExtensionItem::CONFIG_ACTIONS)));
            properties.action(fileModel.property<std::string>(fileModel.propertyToString(FileExtensionItem::ACTION)));
            properties.fileExt(fileModel.property<std::string>(fileModel.propertyToString(FileExtensionItem::FILE_EXT)));
            properties.application(fileModel.property<std::string>(fileModel.propertyToString(FileExtensionItem::APPLICATION)));
            properties.appProgID(fileModel.property<std::string>(fileModel.propertyToString(FileExtensionItem::APP_PROG_ID)));
            properties.configActions(fileModel.property<bool>(fileModel.propertyToString(FileExtensionItem::CONFIG_ACTIONS)));
            properties.iconPath(fileModel.propertyToString(FileExtensionItem::ICON_PATH));
            properties.iconIndex(fileModel.propertyToString(FileExtensionItem::ICON_INDEX));
            properties.confirmOpen(fileModel.propertyToString(FileExtensionItem::CONFIRM_OPEN));
            properties.alwaysShow(fileModel.property<bool>(fileModel.propertyToString(FileExtensionItem::ALWAYS_SHOW)));
            properties.sameWindow(fileModel.propertyToString(FileExtensionItem::SAME_WINDOW));

            setCommonModelData(files, commonModel);
            files.Properties().push_back(properties);

        }

        if (auto openContainer = dynamic_cast<FolderOptionsContainerItem<OpenWithItem>*>(containerItem); openContainer)
        {

            auto openModel = openContainer->getFolderOption();
            auto commonModel = openContainer->getCommon();

            auto open = createRootElement<OpenWith_t>("{100B9C09-906A-4f5a-9C41-1BD98B6CA022}");

            auto properties = OpenWithProperties_t(openModel.property<std::string>(OpenWithItem::FILE_EXTENSION),
                                                   openModel.property<std::string>(OpenWithItem::APPLICATION_PATH));
            properties.action(openModel.property<std::string>(OpenWithItem::ACTION));

            setCommonModelData(open, commonModel);
            open.Properties().push_back(properties);
        }

        if (auto folderContainer = dynamic_cast<FolderOptionsContainerItem<FolderOptionsItem>*>(containerItem); folderContainer)
        {
            auto folderModel = folderContainer->getFolderOption();
            auto commonModel = folderContainer->getCommon();

            auto folder = createRootElement<GlobalFolderOptions_t>("{E7632293-E3FC-4fee-9CD3-584C95D8D2A0}");

            auto properties = GlobalFolderOptionsProperties_t(folderModel.property<bool>(FolderOptionsItem::NO_NETCRAWLING),
                                                              folderModel.property<bool>(FolderOptionsItem::fOLDER_CONTENTS_INFO_TIP),
                                                              folderModel.property<bool>(FolderOptionsItem::FRIENDLY_TREE),
                                                              folderModel.property<bool>(FolderOptionsItem::FULL_PATH_ADDRESS),
                                                              folderModel.property<bool>(FolderOptionsItem::FULL_PATH),
                                                              folderModel.property<bool>(FolderOptionsItem::DISAIBLE_THUMBNAIL_CACHE),
                                                              folderModel.property<std::string>(FolderOptionsItem::HIDDEN),
                                                              folderModel.property<bool>(FolderOptionsItem::HIDE_FILE_EXT),
                                                              folderModel.property<bool>(FolderOptionsItem::SEPERATE_PROCESS),
                                                              folderModel.property<bool>(FolderOptionsItem::SHOW_SUPER_HIDDEN),
                                                              folderModel.property<bool>(FolderOptionsItem::PERSIST_BROWSERS),
                                                              folderModel.property<bool>(FolderOptionsItem::CLASSIC_VIEW_STATE),
                                                              folderModel.property<bool>(FolderOptionsItem::SHOW_CONTROL_PANEL),
                                                              folderModel.property<bool>(FolderOptionsItem::SHOW_COMP_COLOR),
                                                              folderModel.property<bool>(FolderOptionsItem::SHOW_INFO_TIP),
                                                              folderModel.property<bool>(FolderOptionsItem::FORCE_GUEST),
                                                              folderModel.property<bool>(FolderOptionsItem::WEB_VIEW_BARRICADE));

            setCommonModelData(folder, commonModel);
            folder.Properties().push_back(properties);
        }

        if (auto vistaContainer = dynamic_cast<FolderOptionsContainerItem<FolderOptionsVistaItem>*>(containerItem); vistaContainer)
        {
            auto vistaModel = vistaContainer->getFolderOption();
            auto commonModel = vistaContainer->getCommon();

            auto vista = createRootElement<GlobalFolderOptionsVista_t>("{100B9C09-906A-4f5a-9C41-1BD98B6CA022}");

            auto properties = GlobalFolderOptionsVistaProperties_t(vistaModel.property<bool>(FolderOptionsVistaItem::ALWAYS_SHOW_ICON),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::ALWAYS_SHOW_MENUS),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::DISPLAY_ICON_THUMB),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::DISPLAY_FILE_SIZE),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::DISPLAY_SIMPLE_FOLDERS),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::FULL_PATH),
                                                                   vistaModel.property<std::string>(FolderOptionsVistaItem::HIDDEN),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::HIDE_FILE_EXT),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::SHOW_SUPER_HIDDEN),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::SEPARATE_PROCESS),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::CLASSIC_VIEW_STATE),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::PERSIST_BROWSERS),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::SHOW_DRIVE_LETTER),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::SHOW_COMP_COLOR),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::SHOW_INFO_TIP),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::SHOW_PREVIEW_HANDLERS),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::USE_CHECK_BOXES),
                                                                   vistaModel.property<bool>(FolderOptionsVistaItem::USE_SHARING_WIZARD),
                                                                   vistaModel.property<std::string>(FolderOptionsVistaItem::LIST_VIEW_TYPING));

            setCommonModelData(vista, commonModel);
            vista.Properties().push_back(properties);
        }
    }

    return folderOptions;
}

}
