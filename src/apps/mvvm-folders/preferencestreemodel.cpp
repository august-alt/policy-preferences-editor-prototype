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

#include "preferencestreemodel.h"

#include "common/preferencecategoryitem.h"

#include <mvvm/model/groupitem.h>

#include "power_options/powercontaineritem.h"
#include "power_options/poweroptionsitem.h"
#include "power_options/powerschemeitem.h"

#include "printers/printercontaineritem.h"
#include "printers/localprinteritem.h"
#include "printers/tcpprinteritem.h"
#include "printers/sharedprinterwidget.h"

namespace
{

class FolderItem : public ModelView::GroupItem
{
public:
    FolderItem()
        : ModelView::GroupItem("FolderGroupItem")
    {
    }
};

}

namespace mvvm_folders
{

PreferencesTreeModel::PreferencesTreeModel()
    : ModelView::SessionModel("PreferencesTreeModel")
{
    registerItem<FolderItem>();
    registerItem<PreferenceCategoryItem>();

    populateModel();
}

void PreferencesTreeModel::populateModel()
{
    std::vector<std::string> drivesTypeIds
    {
        "DrivesContainerItem"
    };

    std::vector<std::string> variablesTypeIds
    {
        "VariablesContainerItem"
    };

    std::vector<std::string> filesTypeIds
    {
        "FilesContainerItem"
    };

    std::vector<std::string> foldersTypeIds
    {
        "FolderContainerItem"
    };

    std::vector<std::string> iniTypeIds
    {
        "IniContainerItem"
    };

    std::vector<std::string> registryTypeIds
    {
        "RegistryContainerItem"
    };

    std::vector<std::string> sharesTypeIds
    {
        "SharesContainerItem"
    };

    std::vector<std::string> shortcutsTypeIds
    {
        "ShortcutsContainerItem"
    };

    std::vector<std::string> dataSourceTypeIds
    {
        "DataSourceContainerItem"
    };

    std::vector<std::string> deviceTypeIds
    {
        "DeviceContainerItem"
    };

    std::vector<std::string> localGroupTypeIds
    {
        "LocalGroupContainerItem"
    };

    std::vector<std::string> networkTypeIds
    {
        "NetworkContainerItem"
    };

    std::vector<std::string> powerTypeIds
    {
        typeid(PowerContainerItem<PowerOptionsItem>).name(),
        typeid(PowerContainerItem<PowerSchemeItem>).name()
    };

    std::vector<std::string> printerTypeIds
    {
        typeid(PrinterContainerItem<SharedPrinterItem>).name(),
        typeid(PrinterContainerItem<TcpPrinterItem>).name(),
        typeid(PrinterContainerItem<LocalPrinterItem>).name(),
    };

    auto machineNamespace = insertItem<FolderItem>(this->rootItem());
    machineNamespace->setDisplayName("Machine");

    auto machinePreferencesItem = insertItem<FolderItem>(machineNamespace);
    machinePreferencesItem->setDisplayName("Preferences");

    auto machineSystemSettingsItem = insertItem<FolderItem>(machinePreferencesItem);
    machineSystemSettingsItem->setDisplayName("System Settings");

    auto machineVariablesItems = insertItem<PreferenceCategoryItem>(machineSystemSettingsItem);
    machineVariablesItems->setDisplayName("Environment");
    machineVariablesItems->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, variablesTypeIds);

    auto machineFilesItem = insertItem<PreferenceCategoryItem>(machineSystemSettingsItem);
    machineFilesItem->setDisplayName("Files");
    machineFilesItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, filesTypeIds);

    auto machineFoldersItem = insertItem<PreferenceCategoryItem>(machineSystemSettingsItem);
    machineFoldersItem->setDisplayName("Folders");
    machineFoldersItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, foldersTypeIds);

    auto machineIniItem = insertItem<PreferenceCategoryItem>(machineSystemSettingsItem);
    machineIniItem->setDisplayName("Ini Files");
    machineIniItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, iniTypeIds);

    auto machineRegistryItem = insertItem<PreferenceCategoryItem>(machineSystemSettingsItem);
    machineRegistryItem->setDisplayName("Registry");
    machineRegistryItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, registryTypeIds);

    auto sharesItem = insertItem<PreferenceCategoryItem>(machineSystemSettingsItem);
    sharesItem->setDisplayName("Network Shares");
    sharesItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, sharesTypeIds);

    auto machineShortcutsItems = insertItem<PreferenceCategoryItem>(machineSystemSettingsItem);
    machineShortcutsItems->setDisplayName("Shortcuts");
    machineShortcutsItems->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, shortcutsTypeIds);

    auto machineControlPanelSettingsItem = insertItem<FolderItem>(machinePreferencesItem);
    machineControlPanelSettingsItem->setDisplayName("Control Panel Settings");

    auto machineDataSourceItem = insertItem<PreferenceCategoryItem>(machineControlPanelSettingsItem);
    machineDataSourceItem->setDisplayName("Data Sources");
    machineDataSourceItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, dataSourceTypeIds);

    auto machineDeviceItem = insertItem<PreferenceCategoryItem>(machineControlPanelSettingsItem);
    machineDeviceItem->setDisplayName("Devices");
    machineDeviceItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, deviceTypeIds);

    auto machineLocalUsersAndGroupsItem = insertItem<PreferenceCategoryItem>(machineControlPanelSettingsItem);
    machineLocalUsersAndGroupsItem->setDisplayName("Local Users And Groups");
    machineLocalUsersAndGroupsItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, localGroupTypeIds);

    auto machineNetworkOptionsItem = insertItem<PreferenceCategoryItem>(machineControlPanelSettingsItem);
    machineNetworkOptionsItem->setDisplayName("Network Options");
    machineNetworkOptionsItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, networkTypeIds);

    auto machinePowerOptionsItem = insertItem<PreferenceCategoryItem>(machineControlPanelSettingsItem);
    machinePowerOptionsItem->setDisplayName("Power Options");
    machinePowerOptionsItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, powerTypeIds);

    auto machinePrintersItem = insertItem<PreferenceCategoryItem>(machineControlPanelSettingsItem);
    machinePrintersItem->setDisplayName("Printers");
    machinePrintersItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, printerTypeIds);

//======================================================================================================================

    auto userNamespace = insertItem<FolderItem>(this->rootItem());
    userNamespace->setDisplayName("User");

    auto userPreferencesItem = insertItem<FolderItem>(userNamespace);
    userPreferencesItem->setDisplayName("Preferences");

    auto userSystemSettingsItem = insertItem<FolderItem>(userPreferencesItem);
    userSystemSettingsItem->setDisplayName("System Settings");

    auto userDrivesItem = insertItem<PreferenceCategoryItem>(userSystemSettingsItem);
    userDrivesItem->setDisplayName("Drive Maps");
    userDrivesItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, drivesTypeIds);

    auto userVariablesItems = insertItem<PreferenceCategoryItem>(userSystemSettingsItem);
    userVariablesItems->setDisplayName("Environment");
    userVariablesItems->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, variablesTypeIds);

    auto userFilesItem = insertItem<PreferenceCategoryItem>(userSystemSettingsItem);
    userFilesItem->setDisplayName("Files");
    userFilesItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, filesTypeIds);

    auto userFoldersItem = insertItem<PreferenceCategoryItem>(userSystemSettingsItem);
    userFoldersItem->setDisplayName("Folders");
    userFoldersItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, foldersTypeIds);

    auto userIniItem = insertItem<PreferenceCategoryItem>(userSystemSettingsItem);
    userIniItem->setDisplayName("Ini Files");
    userIniItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, iniTypeIds);

    auto userRegistryItem = insertItem<PreferenceCategoryItem>(userSystemSettingsItem);
    userRegistryItem->setDisplayName("Registry");
    userRegistryItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, registryTypeIds);

    auto userShortcutsItems = insertItem<PreferenceCategoryItem>(userSystemSettingsItem);
    userShortcutsItems->setDisplayName("Shortcuts");
    userShortcutsItems->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, shortcutsTypeIds);

    auto userControlPanelSettingsItem = insertItem<FolderItem>(userPreferencesItem);
    userControlPanelSettingsItem->setDisplayName("Control Panel Settings");

    auto userDataSourceItem = insertItem<PreferenceCategoryItem>(userControlPanelSettingsItem);
    userDataSourceItem->setDisplayName("Data Sources");
    userDataSourceItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, dataSourceTypeIds);

    auto userDeviceItem = insertItem<PreferenceCategoryItem>(userControlPanelSettingsItem);
    userDeviceItem->setDisplayName("Devices");
    userDeviceItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, deviceTypeIds);

    auto userLocalUsersAndGroupsItem = insertItem<PreferenceCategoryItem>(userControlPanelSettingsItem);
    userLocalUsersAndGroupsItem->setDisplayName("Local Users And Groups");
    userLocalUsersAndGroupsItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, localGroupTypeIds);

    auto userNetworkOptionsItem = insertItem<PreferenceCategoryItem>(userControlPanelSettingsItem);
    userNetworkOptionsItem->setDisplayName("Network Options");
    userNetworkOptionsItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, networkTypeIds);

    auto userPowerOptionsItem = insertItem<PreferenceCategoryItem>(userControlPanelSettingsItem);
    userPowerOptionsItem->setDisplayName("Power Options");
    userPowerOptionsItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, powerTypeIds);

    auto userPrintersItem = insertItem<PreferenceCategoryItem>(userControlPanelSettingsItem);
    userPrintersItem->setDisplayName("Printers");
    userPrintersItem->setProperty<std::vector<std::string>>(PreferenceCategoryItem::TYPE, printerTypeIds);
}

}
