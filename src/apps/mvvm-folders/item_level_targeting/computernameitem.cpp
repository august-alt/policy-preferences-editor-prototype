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

#include "computernameitem.h"

namespace mvvm_folders
{

ComputerNameItem::ComputerNameItem()
    : ModelView::CompoundItem("computernameItem")
{
    addProperty(NAME, "");
    addProperty(NET_BIOS, true);
    addProperty(DNS, false);
}

ComputerNameItem::ComputerNameItem(const ComputerNameItem &other)
    : ModelView::CompoundItem("computernameItem")
{
    addProperty(NAME, other.name());
    addProperty(NET_BIOS, other.netBios());
    addProperty(DNS, other.dns());
}

QString ComputerNameItem::name() const
{
    return property<QString>(NAME);
}

void ComputerNameItem::setName(const QString& newName)
{
    setProperty(NAME, newName);
}

bool ComputerNameItem::netBios() const
{
    return property<bool>(NET_BIOS);
}
void ComputerNameItem::setNetBios(bool state)
{
    setProperty(NET_BIOS, state);
}
bool ComputerNameItem::dns() const
{
    return property<bool>(DNS);
}
void ComputerNameItem::setDns(bool state)
{
    setProperty(DNS, state);
}

}

