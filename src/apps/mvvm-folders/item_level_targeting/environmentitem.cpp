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

#include "environmentitem.h"

namespace mvvm_folders
{

EnvironmentItem::EnvironmentItem()
    : ModelView::CompoundItem("environmentItem")
{
    addProperty(ENV_NAME, "");
    addProperty(ENV_VALUE, "");
}

EnvironmentItem::EnvironmentItem(const EnvironmentItem &other)
    : ModelView::CompoundItem("environmentItem")
{
    addProperty(ENV_NAME, other.envName());
    addProperty(ENV_VALUE, other.envValue());
}

QString EnvironmentItem::envName() const
{
    return property<QString>(ENV_NAME);
}

void EnvironmentItem::setEnvName(const QString &envName)
{
    setProperty(ENV_NAME, envName);
}

QString EnvironmentItem::envValue() const
{
    return property<QString>(ENV_VALUE);
}

void EnvironmentItem::setEnvValue(const QString &envValue)
{
    setProperty(ENV_VALUE, envValue);
}

}

