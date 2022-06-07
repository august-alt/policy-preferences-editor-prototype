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
            setCommonItemData(common, filesSchema);
        }
    }

    return model;
}

std::unique_ptr<Files> FilesModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    auto files = std::make_unique<Files>("{215B2E53-57CE-475c-80FE-9EEC14635851}");

    for (const auto& containerItem : model->topItems())
    {
        if (auto filesContainer = dynamic_cast<FilesContainerItem*>(containerItem); filesContainer)
        {
            auto driveModel = filesContainer->getFiles();
            auto commonModel = filesContainer->getCommon();

            auto file = createRootElement<File_t>("{50BE44C8-567A-4ed1-B1D0-9234FE1F38AF}");

            auto properties = FileProperties_t(driveModel->property<std::string>(FilesItem::FROM_PATH),
                                               driveModel->property<std::string>(FilesItem::TARGET_PATH));
            properties.action(driveModel->property<std::string>(FilesItem::ACTION));
            properties.action(driveModel->property<std::string>(FilesItem::SUPPRESS));
            properties.action(driveModel->property<std::string>(FilesItem::READONLY));
            properties.action(driveModel->property<std::string>(FilesItem::ARCHIVE));
            properties.action(driveModel->property<std::string>(FilesItem::HIDDEN));

            setCommonModelData(file, commonModel);
            file.Properties().push_back(properties);

            files->File().push_back(file);
        }
    }

    return files;
}

}

