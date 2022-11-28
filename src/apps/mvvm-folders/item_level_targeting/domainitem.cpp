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

#include "domainitem.h"

namespace mvvm_folders
{

DomainItem::DomainItem()
    : ModelView::CompoundItem("domainItem")
{
    addProperty(DOMAIN_NAME, "");
    addProperty(USER_LOGGED, "");
    addProperty(COMP_IN_DOMAIN, "");
}

DomainItem::DomainItem(const DomainItem &other)
    : ModelView::CompoundItem("domainItem")
{
    addProperty(DOMAIN_NAME, other.domainName());
    addProperty(USER_LOGGED, other.userLogged());
    addProperty(COMP_IN_DOMAIN, other.compInDomain());
}

QString DomainItem::domainName() const
{
    return property<QString>(DOMAIN_NAME);
}

void DomainItem::setDomainName(const QString &domainName)
{
    setProperty(DOMAIN_NAME, domainName);
}

bool DomainItem::userLogged() const
{
    return property<bool>(USER_LOGGED);
}

void DomainItem::setUserLogged(bool state)
{
    setProperty(USER_LOGGED, userLogged());
}

bool DomainItem::compInDomain() const
{
    return property<bool>(COMP_IN_DOMAIN);
}

void DomainItem::setCompInDomain(bool state)
{
    setProperty(COMP_IN_DOMAIN, compInDomain());
}

}

