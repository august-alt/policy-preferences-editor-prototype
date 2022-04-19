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

#ifndef NODEEDITORCORE_FolderItemCONTROLLER_H
#define NODEEDITORCORE_FolderItemCONTROLLER_H

#include <mvvm/signals/itemlistener.h>
#include <memory>

namespace mvvm_folders
{

class FolderItem;
class FolderView;

//! Establishes communications between FolderItem and FolderView.
//! Provides updates of view content, when underlying item changes.
//! Similarly, provides update of item's properties while view is updated.

class FolderItemController : public ModelView::ItemListener<FolderItem> {
public:
    FolderItemController(FolderItem* item, FolderView* view);
    ~FolderItemController() override;

    void updateItemFromView();
    void updateViewFromItem();

protected:
    void subscribe() override;

private:
    struct FolderItemControllerImpl;

    std::unique_ptr<FolderItemControllerImpl> p_impl;
};

} // namespace NodeEditor

#endif // NODEEDITORCORE_FolderItemCONTROLLER_H
