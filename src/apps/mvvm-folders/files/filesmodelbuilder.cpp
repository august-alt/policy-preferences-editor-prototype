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

std::unique_ptr<PreferencesModel> FilesModelBuilder::schemaToModel(std::unique_ptr<Files> &filesSource)
{
    auto model = std::make_unique<PreferencesModel>();

    for (const auto& filesSchema : filesSource->File())
    {
        auto properties = filesSchema.Properties();
        auto files = FilesItem();

        // TODO: Implement attributes and correct schema.

        auto common = CommonItem();
        common.setProperty(CommonItem::NAME, filesSchema.name().c_str());
        common.setProperty(CommonItem::CHANGED, filesSchema.changed()->c_str());
        common.setProperty(CommonItem::DESC, filesSchema.desc()->c_str());
        common.setProperty(CommonItem::BYPASS_ERRORS, filesSchema.bypassErrors().get());
        common.setProperty(CommonItem::USER_CONTEXT, filesSchema.userContext().get());
        common.setProperty(CommonItem::REMOVE_POLICY, filesSchema.removePolicy().get());

        auto sessionItem = model->insertItem<FilesContainerItem>(model->rootItem());
        sessionItem->setCommon(common);
    }

    return model;
}

std::unique_ptr<Files> FilesModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    Q_UNUSED(model);

    return nullptr;
}

}

