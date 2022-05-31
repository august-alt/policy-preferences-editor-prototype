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

#include "foldermodelbuilder.h"

#include "foldercontaineritem.h"
#include "folderitem.h"

#include "common/commonitem.h"

namespace mvvm_folders
{

FolderModelBuilder::FolderModelBuilder()
    : BaseModelBuilder()
{
}

template <typename SchemaType>
void mvvm_folders::FolderModelBuilder::setCommonItemData(CommonItem* common, const SchemaType& schema)
{
    common->setProperty(CommonItem::NAME, schema.name().c_str());
    common->setProperty(CommonItem::CHANGED, getOptionalPropertyData(schema.changed()).c_str());
    common->setProperty(CommonItem::DESC, getOptionalPropertyData(schema.desc()).c_str());
    common->setProperty(CommonItem::BYPASS_ERRORS, getOptionalPropertyData(schema.bypassErrors()));
    common->setProperty(CommonItem::USER_CONTEXT, getOptionalPropertyData(schema.userContext()));
    common->setProperty(CommonItem::REMOVE_POLICY, getOptionalPropertyData(schema.removePolicy()));
}

std::unique_ptr<PreferencesModel> FolderModelBuilder::schemaToModel(std::unique_ptr<Folders> &folderSource)
{
    Q_UNUSED(folderSource);

    auto model = std::make_unique<PreferencesModel>();

    for (const auto& foldersSchema : folderSource->Folder())
    {
        auto sessionItem = model->insertItem<FolderContainerItem>(model->rootItem());

        for (const auto& properties: foldersSchema.Properties())
        {
            auto folders = sessionItem->getFolder();
            folders->setProperty(FolderItem::ACTION, getActionCheckboxState(getOptionalPropertyData(properties.action()).c_str()));
            folders->setProperty(FolderItem::PATH, properties.path().c_str());
            folders->setProperty(FolderItem::READONLY, properties.readOnly());
            folders->setProperty(FolderItem::ARCHIVE, properties.archive());
            folders->setProperty(FolderItem::HIDDEN, properties.hidden());
            folders->setProperty(FolderItem::DELETE_IGNORE_ERRORS, getOptionalPropertyData(properties.deleteIgnoreErrors()));
            folders->setProperty(FolderItem::DELETE_FILES, getOptionalPropertyData(properties.deleteFiles()));
            folders->setProperty(FolderItem::DELETE_SUB_FOLDERS, getOptionalPropertyData(properties.deleteSubFolders()));
            folders->setProperty(FolderItem::DELETE_FOLDER, getOptionalPropertyData(properties.deleteFolder()));
            folders->setProperty(FolderItem::READONLY, properties.readOnly());
            folders->setProperty(FolderItem::ARCHIVE, properties.archive());
            folders->setProperty(FolderItem::HIDDEN, properties.hidden());

            auto common = sessionItem->getCommon();
            setCommonItemData(common, foldersSchema);
        }
    }

    return model;
}

std::unique_ptr<Folders> FolderModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    Q_UNUSED(model);

    return nullptr;
}

}

