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

#include "sharesmodelbuilder.h"

#include "sharescontaineritem.h"
#include "sharesitem.h"

#include "common/commonitem.h"

namespace mvvm_folders
{

SharesModelBuilder::SharesModelBuilder()
    : BaseModelBuilder()
{
}

std::unique_ptr<PreferencesModel> SharesModelBuilder::schemaToModel(std::unique_ptr<NetworkShareSettings> &shares)
{
    auto model = std::make_unique<PreferencesModel>();

    for (const auto& sharesSchema : shares->NetShare())
    {
        for (const auto& properties : sharesSchema.Properties())
        {
            auto sessionItem = model->insertItem<SharesContainerItem>(model->rootItem());
            auto shareItem = sessionItem->getShares();
            shareItem->setProperty(SharesItem::ACTION, getOptionalPropertyData(properties.action()).c_str());
            shareItem->setProperty(SharesItem::NAME, properties.name().c_str());
            shareItem->setProperty(SharesItem::PATH, properties.path().c_str());
            shareItem->setProperty(SharesItem::COMMENT, properties.comment().c_str());
            shareItem->setProperty(SharesItem::ALL_REGULAR, getOptionalPropertyData(properties.allRegular()));
            shareItem->setProperty(SharesItem::ALL_HIDDEN, getOptionalPropertyData(properties.allHidden()));
            shareItem->setProperty(SharesItem::ALL_ADMIN_DRIVE, getOptionalPropertyData(properties.allAdminDrive()));
            shareItem->setProperty(SharesItem::LIMIT_USERS, getOptionalPropertyData(properties.limitUsers()).c_str());
            shareItem->setProperty(SharesItem::USER_LIMIT, static_cast<int>(getOptionalPropertyData(properties.userLimit())));
            shareItem->setProperty(SharesItem::ACCESS_BASED_ENUMERATION, getOptionalPropertyData(properties.abe()).c_str());

            auto common = sessionItem->getCommon();
            setCommonItemData(common, sharesSchema);
        }
    }

    return model;
}

std::unique_ptr<NetworkShareSettings> SharesModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    Q_UNUSED(model);

    return nullptr;
}

}

