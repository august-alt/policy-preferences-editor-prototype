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

#include "commonitem.h"

namespace mvvm_folders
{

CommonItem::CommonItem()
    : ModelView::CompoundItem("CommonItem")
{
    addProperty(NAME, "");
    addProperty(CHANGED, false);
    addProperty(DESC, "");
    addProperty(BYPASS_ERRORS, false);
    addProperty(USER_CONTEXT, false);
    addProperty(REMOVE_POLICY, false);
}

QString CommonItem::name() const
{
    return property<QString>(NAME);
}

void CommonItem::setName(const QString &newName)
{
    setProperty(NAME, newName);
}

bool CommonItem::changed() const
{
    return property<bool>(CHANGED);
}

void CommonItem::setChanged(bool state)
{
    setProperty(CHANGED, state);
}

QString CommonItem::desc() const
{
    return property<QString>(DESC);
}

void CommonItem::setDesc(const QString &newDesc)
{
    setProperty(DESC, newDesc);
}

bool CommonItem::bypassErrors() const
{
    return property<bool>(BYPASS_ERRORS);
}

void CommonItem::setBypassErrors(bool state)
{
    setProperty(BYPASS_ERRORS, state);
}

bool CommonItem::userContext() const
{
    return property<bool>(USER_CONTEXT);
}

void CommonItem::setUserContext(bool state)
{
    setProperty(USER_CONTEXT, state);
}

bool CommonItem::removePolicy() const
{
    return property<bool>(REMOVE_POLICY);
}

void CommonItem::setRemovePolicy(bool state)
{
    setProperty(REMOVE_POLICY, state);
}

}
