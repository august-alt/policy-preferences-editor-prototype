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

#include "localgroupcontaineritem.h"

#include "common/commonitem.h"
#include "localgroupitem.h"

#include <mvvm/signals/itemmapper.h>

namespace mvvm_folders
{

LocalGroupContainerItem::LocalGroupContainerItem()
    : ModelView::CompoundItem("LocalGroupContainerItem")
{
    addProperty(NAME, "")->setDisplayName(QObject::tr("Name").toStdString())->setEditable(false);
    addProperty(ORDER, 0)->setDisplayName(QObject::tr("Order").toStdString())->setEditable(false);
    addProperty(ACTION, "")->setDisplayName(QObject::tr("Action").toStdString())->setEditable(false);
    addProperty(FULL_NAME, "N/A")->setDisplayName(QObject::tr("Full Name").toStdString())->setEditable(false);
    addProperty(DESCRIPTION, "")->setDisplayName(QObject::tr("Description").toStdString())->setEditable(false);

    addProperty<CommonItem>(COMMON)->setVisible(false);
    addProperty<LocalGroupItem>(LOCAL_USER_OR_GROUP)->setVisible(false);
}

CommonItem LocalGroupContainerItem::getCommon() const
{
    return property<CommonItem>(COMMON);
}

void LocalGroupContainerItem::setCommon(const CommonItem &item)
{
    setProperty(COMMON, item);
}

LocalGroupItem LocalGroupContainerItem::getLocalGroup() const
{
    return property<LocalGroupItem>(LOCAL_USER_OR_GROUP);
}

void LocalGroupContainerItem::setLocalGroup(const LocalGroupItem &item)
{
    setProperty(LOCAL_USER_OR_GROUP, item);
}

void LocalGroupContainerItem::setupListeners()
{
    auto onChildPropertyChange = [&](SessionItem* item, std::string property)
    {
        if (auto baseItem = dynamic_cast<LocalGroupItem*>(item))
        {
            if (property == ACTION)
            {
                setProperty(ACTION, baseItem->property<std::string>(ACTION));
            }

            if (property == GROUP_NAME)
            {
                setProperty(NAME, baseItem->property<std::string>(GROUP_NAME));
            }

            if (property == USER_NAME)
            {
                setProperty(NAME, baseItem->property<std::string>(USER_NAME));
            }

            if (property == DESCRIPTION)
            {
                setProperty(DESCRIPTION, baseItem->property<std::string>(DESCRIPTION));
            }

            if (property == FULL_NAME)
            {
                setProperty(FULL_NAME, baseItem->property<std::string>(FULL_NAME));
            }
        }
    };

    this->mapper()->setOnChildPropertyChange(onChildPropertyChange, nullptr);
}

}
