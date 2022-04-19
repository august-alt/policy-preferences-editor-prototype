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

#include "commonitem.h"
#include "sharesitem.h"

namespace mvvm_folders
{

SharesContainerItem::SharesContainerItem()
    : ModelView::CompoundItem("SharesContainerItem")
{
    addProperty<CommonItem>(COMMON);
    addProperty<SharesItem>(SHARES);
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

}
