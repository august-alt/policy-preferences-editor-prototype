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

#include "common/commonitem.h"

namespace mvvm_folders
{

FolderOptionsModelBuilder::FolderOptionsModelBuilder()
    : BaseModelBuilder()
{
}

std::unique_ptr<PreferencesModel> FolderOptionsModelBuilder::schemaToModel(std::unique_ptr<FolderOptions> &folderOptionsSource)
{
    auto model = std::make_unique<PreferencesModel>();
    for (const auto& folderoptionsSchema : folderOptionsSource->FileType())
    {
        auto sessionItem = model->insertItem<FolderOptionsContainerItem<FileExtensionItem>>(model->rootItem());

        for (const auto& properties: folderoptionsSchema.Properties())
        {
            auto open = sessionItem->getFolderOption();
            auto action = properties.action();
            auto state = getActionCheckboxState(action.present() ? action->c_str() : "");
            open->setProperty(FolderOptionsItem::ACTION, state);

            auto common = sessionItem->getCommon();
            setCommonItemData(common, folderoptionsSchema);

        }
        for (const auto& properties:folderoptionsSchema.Properties())
        {
            auto fileEx = sessionItem->getFolderOption();
            auto action = properties.action();
            auto state = getActionCheckboxState(action.present() ? action->c_str() : "");
            fileEx->setProperty(FileExtensionItem::propertyToString(FileExtensionItem::ICON_INDEX), "");
            fileEx->setProperty(FileExtensionItem::propertyToString(FileExtensionItem::ICON_INDEX), "");
            fileEx->setProperty(FileExtensionItem::propertyToString(FileExtensionItem::FILE_EXT), "");
            fileEx->setProperty(FileExtensionItem::propertyToString(FileExtensionItem::CONFIRM_OPEN), "");
            fileEx->setProperty(FileExtensionItem::propertyToString(FileExtensionItem::CONFIG_ACTIONS), "");
            fileEx->setProperty(FileExtensionItem::propertyToString(FileExtensionItem::APP_PROG_ID), "");
            fileEx->setProperty(FileExtensionItem::propertyToString(FileExtensionItem::APPLICATION), "");
            fileEx->setProperty(FileExtensionItem::propertyToString(FileExtensionItem::ALWAYS_SHOW), "");
            fileEx->setProperty(FileExtensionItem::propertyToString(FileExtensionItem::ACTIONS), "");
            fileEx->setProperty(FileExtensionItem::propertyToString(FileExtensionItem::ACTION), "");

            auto common = sessionItem->getCommon();
            setCommonItemData(common, folderoptionsSchema);
        }
        for (const auto& properties: folderoptionsSchema.Properties())
        {
            auto open = sessionItem->getFolderOption();
            auto action = properties.action();
            auto state = getActionCheckboxState(action.present() ? action->c_str() : "");
            open->setProperty(OpenWithItem::ACTION, state);
            open->setProperty(OpenWithItem::FILE_EXTENSION, state);
            open->setProperty(OpenWithItem::APPLICATION_PATH, state);
            open->setProperty(OpenWithItem::DEFAULT, state);

            auto common = sessionItem->getCommon();
            setCommonItemData(common, folderoptionsSchema);

        }
    }

    return model;
}

std::unique_ptr<FolderOptions> FolderOptionsModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    Q_UNUSED(model);

    return nullptr;
}

}

