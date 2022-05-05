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

#ifndef MVVM_FOLDERS_VPN_ITEM_H
#define MVVM_FOLDERS_VPN_ITEM_H

#include "basenetworkitem.h"

namespace mvvm_folders
{

//! Drives item representation for editor.

class VpnItem : public BaseNetworkItem
{
public:
    enum PropertyType
    {
        ACTION          = 0,
        USER            = 1,
        NAME            = 2,
        IP_ADDRESS      = 3,
        USE_DNS         = 4,
        DIAL_FIRST      = 5,
        TRAY_ICON       = 6,
        SHOW_PROGRESS   = 7,
        SHOW_PASSWORD   = 8,
        SHOW_DOMAIN     = 9,
        REDIAL_COUNT    = 10,
        REDIAL_PAUSE    = 11,
        IDLE_DISCONNECT = 12,
        RECONNECT       = 13,
        CUSTOM_SETTINGS = 14,
        SECURE_PASSWORD = 15,
        SECURE_DATA     = 16,
        USE_LOGON       = 17,
        VPN_STRATEGY    = 18,
        ENCRYPTION_TYPE = 19,
        EAP             = 20,
        PAP             = 21,
        SPAP            = 22,
        CHAP            = 23,
        MS_CHAP         = 24,
        OLD_MS_CHAP     = 25,
        MS_CHAP_V2      = 26
    };

public:
    VpnItem();
    VpnItem(const VpnItem &other);

    constexpr static int propertyToInt(const PropertyType& type);
    constexpr static const char* propertyToString(const PropertyType& type);

private:
    template <typename T>
    inline void copyProperty(const PropertyType& type, const VpnItem &other);
};

template<typename T>
void VpnItem::copyProperty(const VpnItem::PropertyType &type, const VpnItem &other)
{
    addProperty(propertyToString(type), other.property<T>(propertyToString(type)));
}

}

Q_DECLARE_METATYPE(::mvvm_folders::VpnItem)

#endif//MVVM_FOLDERS_Vpn_ITEM_H
