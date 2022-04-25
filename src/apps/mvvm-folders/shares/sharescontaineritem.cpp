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

#include "sharescontaineritem.h"

#include "common/commonitem.h"
#include "sharesitem.h"

#include <mvvm/signals/itemmapper.h>

namespace mvvm_folders
{

SharesContainerItem::SharesContainerItem()
    : ModelView::CompoundItem("SharesContainerItem")
{
    addProperty(NAME, "")->setDisplayName(QObject::tr("Name").toStdString())->setEditable(false);
    addProperty(ORDER, 0)->setDisplayName(QObject::tr("Order").toStdString())->setEditable(false);
    addProperty(ACTION, "")->setDisplayName(QObject::tr("Action").toStdString())->setEditable(false);
    addProperty(PATH, "")->setDisplayName(QObject::tr("Path").toStdString())->setEditable(false);
    addProperty(USER_LIMIT, "")->setDisplayName(QObject::tr("User Limit").toStdString())->setEditable(false);
    addProperty(ACCESS_BASED_ENUMERATION, "")->setDisplayName(QObject::tr("ABE").toStdString())->setEditable(false);

    addProperty<CommonItem>(COMMON)->setVisible(false);
    addProperty<SharesItem>(SHARES)->setVisible(false);
}

CommonItem SharesContainerItem::getCommon() const
{
    return property<CommonItem>(COMMON);
}

void SharesContainerItem::setCommon(const CommonItem &item)
{
    setProperty(COMMON, item);
}

SharesItem SharesContainerItem::getShares() const
{
    return property<SharesItem>(SHARES);
}

void SharesContainerItem::setShares(const SharesItem &item)
{
    setProperty(SHARES, item);
}

void SharesContainerItem::setupListeners()
{
    auto onChildPropertyChange = [&](SessionItem* item, std::string property)
    {
        if (auto sharesItem = dynamic_cast<SharesItem*>(item))
        {
            if (property == ACTION)
            {
                setProperty(ACTION, sharesItem->property<std::string>(ACTION));
            }

            if (property == PATH)
            {
                setProperty(NAME, sharesItem->property<std::string>(PATH));
                setProperty(PATH, sharesItem->property<std::string>(PATH));
            }

            if (property == USER_LIMIT)
            {
                setProperty(USER_LIMIT, sharesItem->property<int>(USER_LIMIT));
            }

            if (property == ACCESS_BASED_ENUMERATION)
            {
                setProperty(ACCESS_BASED_ENUMERATION, sharesItem->property<std::string>(ACCESS_BASED_ENUMERATION));
            }
        }
    };

    this->mapper()->setOnChildPropertyChange(onChildPropertyChange, nullptr);
}

}
