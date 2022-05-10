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

#include "powercontaineritem.h"

#include "common/commonitem.h"
#include "poweroptionsitem.h"

#include <mvvm/signals/itemmapper.h>

namespace mvvm_folders
{

PowerContainerItem::PowerContainerItem()
    : ModelView::CompoundItem("PowerContainerItem")
{
    addProperty(NAME, "")->setDisplayName(QObject::tr("Name").toStdString())->setEditable(false);
    addProperty(ORDER, 0)->setDisplayName(QObject::tr("Order").toStdString())->setEditable(false);
    addProperty(ACTION, "")->setDisplayName(QObject::tr("Action").toStdString())->setEditable(false);

    addProperty<CommonItem>(COMMON)->setVisible(false);
    addProperty<PowerOptionsItem>(POWER)->setVisible(false);
}

CommonItem PowerContainerItem::getCommon() const
{
    return property<CommonItem>(COMMON);
}

void PowerContainerItem::setCommon(const CommonItem &item)
{
    setProperty(COMMON, item);
}

PowerOptionsItem PowerContainerItem::getPower() const
{
    return property<PowerOptionsItem>(POWER);
}

void PowerContainerItem::setPower(const PowerOptionsItem &item)
{
    setProperty(POWER, item);
}

void PowerContainerItem::setupListeners()
{
    auto onChildPropertyChange = [&](SessionItem* item, std::string property)
    {
        if (auto powerItem = dynamic_cast<PowerOptionsItem*>(item))
        {
            if (property == ACTION)
            {
                setProperty(ACTION, powerItem->property<std::string>(ACTION));
            }

            if (property == NAME)
            {
                setProperty(NAME, powerItem->property<std::string>(NAME));
            }
        }
    };

    this->mapper()->setOnChildPropertyChange(onChildPropertyChange, nullptr);
}

}
