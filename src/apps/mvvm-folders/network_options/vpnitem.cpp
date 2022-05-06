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

#include "vpnitem.h"

namespace mvvm_folders
{

VpnItem::VpnItem()
    : BaseNetworkItem("VpnItem")
{
    addProperty(propertyToString(ACTION), "");
    addProperty(propertyToString(USER), false);
    addProperty(propertyToString(NAME), "");
    addProperty(propertyToString(IP_ADDRESS), "");
    addProperty(propertyToString(USE_DNS), false);
    addProperty(propertyToString(DIAL_FIRST), "");
    addProperty(propertyToString(TRAY_ICON), false);
    addProperty(propertyToString(SHOW_PROGRESS), false);
    addProperty(propertyToString(SHOW_PASSWORD), false);
    addProperty(propertyToString(SHOW_DOMAIN), false);
    addProperty(propertyToString(REDIAL_COUNT), 0);
    addProperty(propertyToString(REDIAL_PAUSE), 0);
    addProperty(propertyToString(IDLE_DISCONNECT), false);
    addProperty(propertyToString(RECONNECT), false);
    addProperty(propertyToString(CUSTOM_SETTINGS), false);
    addProperty(propertyToString(SECURE_PASSWORD), false);
    addProperty(propertyToString(SECURE_DATA), false);
    addProperty(propertyToString(USE_LOGON), false);
    addProperty(propertyToString(VPN_STRATEGY), "");
    addProperty(propertyToString(ENCRYPTION_TYPE), "");
    addProperty(propertyToString(EAP), false);
    addProperty(propertyToString(PAP), false);
    addProperty(propertyToString(SPAP), false);
    addProperty(propertyToString(MS_CHAP), false);
    addProperty(propertyToString(OLD_MS_CHAP), false);
    addProperty(propertyToString(MS_CHAP_V2), false);
    addProperty(propertyToString(SYSTEM), false);
}

VpnItem::VpnItem(const VpnItem &other)
    : BaseNetworkItem("VpnItem")
{
    copyProperty<std::string>(ACTION, other);
    copyProperty<bool>(USER, other);
    copyProperty<std::string>(NAME, other);
    copyProperty<std::string>(IP_ADDRESS, other);
    copyProperty<bool>(USE_DNS, other);
    copyProperty<std::string>(DIAL_FIRST, other);
    copyProperty<bool>(TRAY_ICON, other);
    copyProperty<bool>(SHOW_PROGRESS, other);
    copyProperty<bool>(SHOW_PASSWORD, other);
    copyProperty<bool>(SHOW_DOMAIN, other);
    copyProperty<int>(REDIAL_COUNT, other);
    copyProperty<int>(REDIAL_PAUSE, other);
    copyProperty<bool>(IDLE_DISCONNECT, other);
    copyProperty<bool>(RECONNECT, other);
    copyProperty<bool>(CUSTOM_SETTINGS, other);
    copyProperty<bool>(SECURE_PASSWORD, other);
    copyProperty<bool>(SECURE_DATA, other);
    copyProperty<bool>(USE_LOGON, other);
    copyProperty<std::string>(VPN_STRATEGY, other);
    copyProperty<std::string>(ENCRYPTION_TYPE, other);
    copyProperty<bool>(EAP, other);
    copyProperty<bool>(PAP, other);
    copyProperty<bool>(SPAP, other);
    copyProperty<bool>(MS_CHAP, other);
    copyProperty<bool>(OLD_MS_CHAP, other);
    copyProperty<bool>(MS_CHAP_V2, other);
    copyProperty<bool>(SYSTEM, other);
}

constexpr const char *VpnItem::propertyToString(const VpnItem::PropertyType &type)
{
    switch (type)
    {
    case ACTION:
        return "action";
    case USER:
        return "user";
    case NAME:
        return "name";
    case IP_ADDRESS:
        return "ipAddress";
    case USE_DNS:
        return "useDNS";
    case DIAL_FIRST:
        return "dialFirst";
    case TRAY_ICON:
        return "trayIcon";
    case SHOW_PROGRESS:
        return "showProgress";
    case SHOW_PASSWORD:
        return "showPassword";
    case SHOW_DOMAIN:
        return "showDomain";
    case REDIAL_COUNT:
        return "redialCount";
    case REDIAL_PAUSE:
        return "redialPause";
    case IDLE_DISCONNECT:
        return "idleDisconnect";
    case RECONNECT:
        return "reconnect";
    case CUSTOM_SETTINGS:
        return "customSettings";
    case SECURE_PASSWORD:
        return "securePassword";
    case SECURE_DATA:
        return "secureData";
    case USE_LOGON:
        return "useLogon";
    case VPN_STRATEGY:
        return "vpnStrategy";
    case ENCRYPTION_TYPE:
        return "encryptionType";
    case EAP:
        return "eap";
    case PAP:
        return "pap";
    case SPAP:
        return "spap";
    case CHAP:
        return "chap";
    case MS_CHAP:
        return "msChap";
    case OLD_MS_CHAP:
        return "oldMsChap";
    case MS_CHAP_V2:
        return "msChapV2";
    case SYSTEM:
        return "system";
    case TYPICAL:
        return "typical";
    case ADVANCED:
        return "advanced";
    case USE_OTHER:
        return "useOther";
    default:
        break;
    }

    return "";
}

}
