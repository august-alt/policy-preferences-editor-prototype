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

#include "shortcutsmodelbuilder.h"

#include "shortcutscontaineritem.h"
#include "shortcutsitem.h"

#include "common/commonitem.h"

namespace mvvm_folders
{

ShortcutsModelBuilder::ShortcutsModelBuilder()
    : BaseModelBuilder()
{
}

std::unique_ptr<PreferencesModel> ShortcutsModelBuilder::schemaToModel(std::unique_ptr<Shortcuts> &shortcutsSource)
{
    auto model = std::make_unique<PreferencesModel>();

    for (const auto& shortcutsSchema : shortcutsSource->Shortcut())
    {
        auto properties = shortcutsSchema.Properties();
        for (const auto& currentProperties : properties)
        {
            std::string actionState = getActionCheckboxState(getOptionalPropertyData(currentProperties.action()).c_str());
            int iconIndex = static_cast<int>(getOptionalPropertyData(currentProperties.iconIndex()));

            auto sessionItem = model->insertItem<ShortcutsContainerItem>(model->rootItem());

            auto shortcuts = sessionItem->getShortcuts();
            shortcuts->setProperty(ShortcutsItem::ACTION, actionState);
            shortcuts->setProperty(ShortcutsItem::PIDL, getOptionalPropertyData(currentProperties.pidl()).c_str());
            shortcuts->setProperty(ShortcutsItem::SHORTCUT_PATH, currentProperties.shortcutPath().c_str());
            shortcuts->setProperty(ShortcutsItem::TARGET_TYPE, currentProperties.targetType().c_str());
            shortcuts->setProperty(ShortcutsItem::TARGET_PATH, currentProperties.targetPath().c_str());
            shortcuts->setProperty(ShortcutsItem::ARGUMENTS, getOptionalPropertyData(currentProperties.arguments()).c_str());
            shortcuts->setProperty(ShortcutsItem::START_IN, getOptionalPropertyData(currentProperties.startIn()).c_str());
            // TODO: Implement shortcut key. SHORTCUT_KEY
            shortcuts->setProperty(ShortcutsItem::WINDOW, getOptionalPropertyData(currentProperties.window()).c_str());
            shortcuts->setProperty(ShortcutsItem::COMMENT, getOptionalPropertyData(currentProperties.comment()).c_str());
            shortcuts->setProperty(ShortcutsItem::ICON_PATH, getOptionalPropertyData(currentProperties.iconPath()).c_str());
            shortcuts->setProperty(ShortcutsItem::ICON_INDEX, iconIndex);

            auto common = sessionItem->getCommon();
            setCommonItemData(common, shortcutsSchema);
        }
    }

    return model;
}

std::unique_ptr<Shortcuts> ShortcutsModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    Q_UNUSED(model);

    return nullptr;
}

}

