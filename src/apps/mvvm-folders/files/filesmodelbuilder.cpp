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

#include "filesmodelbuilder.h"

#include "filescontaineritem.h"
#include "filesitem.h"

#include "common/commonitem.h"

namespace mvvm_folders
{

FilesModelBuilder::FilesModelBuilder()
    : BaseModelBuilder()
{
}

std::unique_ptr<PreferencesModel> FilesModelBuilder::schemaToModel(std::unique_ptr<Files> &filesSource)
{
    auto model = std::make_unique<PreferencesModel>();

    for (const auto& filesSchema : filesSource->File())
    {
        auto sessionItem = model->insertItem<FilesContainerItem>(model->rootItem());

        for (const auto& properties: filesSchema.Properties())
        {
            auto files = sessionItem->getFiles();
            files->setProperty(FilesItem::ACTION, getActionCheckboxState(getOptionalPropertyData(properties.action()).c_str()));
            files->setProperty(FilesItem::FROM_PATH, properties.fromPath().c_str());
            files->setProperty(FilesItem::TARGET_PATH, properties.targetPath().c_str());
            files->setProperty(FilesItem::SUPPRESS, getOptionalPropertyData(properties.suppress()));
            files->setProperty(FilesItem::READONLY, getOptionalPropertyData(properties.readOnly()));
            files->setProperty(FilesItem::ARCHIVE, getOptionalPropertyData(properties.archive()));
            files->setProperty(FilesItem::HIDDEN, getOptionalPropertyData(properties.hidden()));

            auto common = sessionItem->getCommon();
            common->setProperty(CommonItem::NAME, filesSchema.name().c_str());
            common->setProperty(CommonItem::CHANGED, getOptionalPropertyData(filesSchema.changed()).c_str());
            common->setProperty(CommonItem::DESC, getOptionalPropertyData(filesSchema.desc()).c_str());
            common->setProperty(CommonItem::BYPASS_ERRORS, getOptionalPropertyData(filesSchema.bypassErrors()));
            common->setProperty(CommonItem::USER_CONTEXT, getOptionalPropertyData(filesSchema.userContext()));
            common->setProperty(CommonItem::REMOVE_POLICY, getOptionalPropertyData(filesSchema.removePolicy()));
        }
    }

    return model;
}

std::unique_ptr<Files> FilesModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    Q_UNUSED(model);

    return nullptr;
}

}

