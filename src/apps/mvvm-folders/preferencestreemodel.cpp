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
    auto machineNamespace = insertItem<FolderItem>(this->rootItem());
    machineNamespace->setDisplayName("Machine");

    auto machinePreferencesItem = insertItem<FolderItem>(machineNamespace);
    machinePreferencesItem->setDisplayName("Preferences");

    auto machineVariablesItems = insertItem<PreferenceCategoryItem>(machinePreferencesItem);
    machineVariablesItems->setDisplayName("Environment");
    machineVariablesItems->setProperty<std::string>(PreferenceCategoryItem::TYPE, "VariablesContainerItem");

    auto machineFilesItem = insertItem<PreferenceCategoryItem>(machinePreferencesItem);
    machineFilesItem->setDisplayName("Files");
    machineFilesItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "FilesContainerItem");

    auto machineFoldersItem = insertItem<PreferenceCategoryItem>(machinePreferencesItem);
    machineFoldersItem->setDisplayName("Folders");
    machineFoldersItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "FolderContainerItem");

    auto machineIniItem = insertItem<PreferenceCategoryItem>(machinePreferencesItem);
    machineIniItem->setDisplayName("Ini Files");
    machineIniItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "IniContainerItem");

    auto machineRegistryItem = insertItem<PreferenceCategoryItem>(machinePreferencesItem);
    machineRegistryItem->setDisplayName("Registry");
    machineRegistryItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "RegistryContainerItem");

    auto sharesItem = insertItem<PreferenceCategoryItem>(machinePreferencesItem);
    sharesItem->setDisplayName("Network Shares");
    sharesItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "SharesContainerItem");

    auto machineShortcutsItems = insertItem<PreferenceCategoryItem>(machinePreferencesItem);
    machineShortcutsItems->setDisplayName("Shortcuts");
    machineShortcutsItems->setProperty<std::string>(PreferenceCategoryItem::TYPE, "ShortcutsContainerItem");

//======================================================================================================================

    auto userNamespace = insertItem<FolderItem>(this->rootItem());
    userNamespace->setDisplayName("User");

    auto userPreferencesItem = insertItem<FolderItem>(userNamespace);
    userPreferencesItem->setDisplayName("Preferences");

    auto userDrivesItem = insertItem<PreferenceCategoryItem>(userPreferencesItem);
    userDrivesItem->setDisplayName("Drive Maps");
    userDrivesItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "DrivesContainerItem");

    auto userVariablesItems = insertItem<PreferenceCategoryItem>(userPreferencesItem);
    userVariablesItems->setDisplayName("Environment");
    userVariablesItems->setProperty<std::string>(PreferenceCategoryItem::TYPE, "VariablesContainerItem");

    auto userFilesItem = insertItem<PreferenceCategoryItem>(userPreferencesItem);
    userFilesItem->setDisplayName("Files");
    userFilesItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "FilesContainerItem");

    auto userFoldersItem = insertItem<PreferenceCategoryItem>(userPreferencesItem);
    userFoldersItem->setDisplayName("Folders");
    userFoldersItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "FolderContainerItem");

    auto userIniItem = insertItem<PreferenceCategoryItem>(userPreferencesItem);
    userIniItem->setDisplayName("Ini Files");
    userIniItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "IniContainerItem");

    auto userRegistryItem = insertItem<PreferenceCategoryItem>(userPreferencesItem);
    userRegistryItem->setDisplayName("Registry");
    userRegistryItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "RegistryContainerItem");

    auto userShortcutsItems = insertItem<PreferenceCategoryItem>(userPreferencesItem);
    userShortcutsItems->setDisplayName("Shortcuts");
    userShortcutsItems->setProperty<std::string>(PreferenceCategoryItem::TYPE, "ShortcutsContainerItem");
}

}
