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

#include "networkcontaineritem.h"

#include "common/commonitem.h"
#include "basenetworkitem.h"

#include <mvvm/signals/itemmapper.h>

namespace mvvm_folders
{

NetworkContainerItem::NetworkContainerItem()
    : ModelView::CompoundItem("NetworkContainerItem")
{
    addProperty<CommonItem>(COMMON);
    addProperty<BaseNetworkItem>(NETWORK);
}

CommonItem NetworkContainerItem::getCommon() const
{
    return property<CommonItem>(COMMON);
}

void NetworkContainerItem::setCommon(const CommonItem &item)
{
    setProperty(COMMON, item);
}

BaseNetworkItem NetworkContainerItem::getNetwork() const
{
    return property<BaseNetworkItem>(NETWORK);
}

void NetworkContainerItem::setNetwork(const BaseNetworkItem &item)
{
    setProperty(NETWORK, item);
}

void NetworkContainerItem::setupListeners()
{
    auto onChildPropertyChange = [&](SessionItem* item, std::string property)
    {
        if (auto networkItem = dynamic_cast<BaseNetworkItem*>(item))
        {
            // TODO: Implement.
            Q_UNUSED(property);
        }
    };

    this->mapper()->setOnChildPropertyChange(onChildPropertyChange, nullptr);
}

}
