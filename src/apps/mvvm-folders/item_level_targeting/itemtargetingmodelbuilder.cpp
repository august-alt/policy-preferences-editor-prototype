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

#include "itemtargetingmodelbuilder.h"

//#include "itemtargetingcontaineritem.h"
//#include "batterypresentitem.h"


#include "common/commonitem.h"

namespace mvvm_folders
{

ItemTargetingModelBuilder::ItemTargetingModelBuilder()
    : BaseModelBuilder()
{
}

//std::unique_ptr<PreferencesModel> ItemTargetingModelBuilder::schemaToModel(std::unique_ptr<ItemTargeting> &itemTargeting)
//{
//    auto model = std::make_unique<PreferencesModel>();

//    for (const auto& targetSchema : itemTargeting->----())
//    {
//        auto sessionItem = model->insertItem<ItemTargetingContainerItem>(model->rootItem());

//        for (const auto& properties: targetSchema.Properties())
//        {
//            auto target = sessionItem->getTarget();
//            target->setProperty(BatteryPresent::ACTION, getActionCheckboxState(getOptionalPropertyData(properties.action()).c_str()));
//            target->setProperty(BatteryPresent::PATH, properties.path().c_str());

//            auto common = sessionItem->getCommon();
//            setCommonItemData(common, targetSchema);
//        }
//    }

//    return model;
//}

//std::unique_ptr<ItemTargeting> ItemTargetingModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
//{
//    auto folders = std::make_unique<ItemTargeting>("{}");

//    for (const auto& containerItem : model->topItems())
//    {
//        if (auto targetContainer = dynamic_cast<ItemTargetingContainerItem*>(containerItem); targetContainer)
//        {
//            auto targetModel = targetContainer->getTarget();
//            auto commonModel = targetContainer->getCommon();

//            auto target = createRootElement<Target_t>("{}");

//            auto properties = FolderProperties_t(targetModel->property<std::string>(ItemTargeting::PATH));
//            properties.action(targetModel->property<std::string>(ItemTargeting::ACTION));

//            setCommonModelData(target, commonModel);
//            target.Properties().push_back(properties);

//            target->ItemTargeting().push_back(target);
//        }
//    }

//    return folders;
//}

}

