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

#include "common/commonitem.h"

#include <mvvm/signals/itemmapper.h>

namespace mvvm_folders
{

template <typename FolderOptionVistaItem>
FolderOptionsVistaContainerItem<FolderOptionVistaItem>::FolderOptionsVistaContainerItem()
    : ModelView::CompoundItem(typeid(FolderOptionsContainerItem<FolderOptionVistaItem>).name())
{
    addProperty<CommonItem>(COMMON)->setVisible(false);
    addProperty<FolderOptionVistaItem>(FOLDER_OPTION)->setVisible(false);
}

template <typename FolderOptionVistaItem>
CommonItem* FolderOptionsContainerItem<FolderOptionVistaItem>::getCommon() const
{
    return static_cast<CommonItem*>(children()[childrenCount() - 2]);
}

template <typename FolderOptionVistaItem>
void FolderOptionsContainerItem<FolderOptionVistaItem>::setCommon(const CommonItem &item)
{
    setProperty(COMMON, item);
}

template <typename FolderOptionVistaItem>
FolderOptionItem* FolderOptionsContainerItem<FolderOptionVistaItem>::getFolderOption() const
{
    return static_cast<FolderOptionItem*>(children().back());
}

template <typename FolderOptionVistaItem>
void FolderOptionsContainerItem<FolderOptionVistaItem>::setFolderOption(const FolderOptionVistaItem &item)
{
    setProperty(FOLDER_OPTION, item);
}

template <typename FolderOptionVistaItem>
void FolderOptionsContainerItem<FolderOptionVistaItem>::setupListeners()
{
    auto onChildPropertyChange = [&](SessionItem* item, std::string property)
    {
        if (auto folderOptionItem = dynamic_cast<FolderOptionVistaItem*>(item))
        {
            if (property == ACTION)
            {
                setProperty(ACTION, folderOptionItem->template property<std::string>(ACTION));
            }

            if (property == NAME)
            {
                setProperty(NAME, folderOptionItem->template property<std::string>(NAME));
            }

            if (property == ASSOCIATION)
            {
                setProperty(ASSOCIATION, folderOptionItem->template property<std::string>(ASSOCIATION));
            }
        }
    };

    this->mapper()->setOnChildPropertyChange(onChildPropertyChange, nullptr);
}

}
