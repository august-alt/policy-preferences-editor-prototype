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

#include "folderitemcontroller.h"
#include "folderitem.h"
#include "folderwidget.h"

namespace mvvm_folders
{

struct FolderItemController::FolderItemControllerImpl
{
    FolderItem* m_item {nullptr};
    FolderWidget* m_view {nullptr};
    bool m_blockOnPropertyChanged {false};

    FolderItemControllerImpl(FolderItem* item, FolderWidget* view)
        : m_item(item), m_view(view)
    {
    }

    //! Updates item properties from the current view position.

    void updateItemFromView()
    {
        m_blockOnPropertyChanged = true;

//        m_item->setAction(m_view->action());
        m_item->setArchive(m_view->archive());
        m_item->setDeleteFiles(m_view->deleteFiles());
        m_item->setDeleteFolder(m_view->deleteFolder());
        m_item->setDeleteIgnoreErrors(m_view->deleteIgnoreErrors());
        m_item->setDeleteSubFolders(m_view->deleteSubFolders());
        m_item->setHidden(m_view->hidden());
        m_item->setPath(m_view->path());
        m_item->setReadOnly(m_view->readOnly());

        m_blockOnPropertyChanged = false;
    }

    //! Updates view position and appearance using current values of item properties.

    void updateViewFromItem()
    {
//        m_view->setAction(m_item->action());
        m_view->setArchive(m_item->archive());
        m_view->setDeleteFiles(m_item->deleteFiles());
        m_view->setDeleteFolder(m_item->deleteFolder());
        m_view->setDeleteIgnoreErrors(m_item->deleteIgnoreErrors());
        m_view->setDeleteSubFolders(m_item->deleteSubFolders());
        m_view->setHidden(m_item->hidden());
        m_view->setPath(m_item->path());
        m_view->setReadOnly(m_item->readOnly());
    }
};

FolderItemController::FolderItemController(FolderItem* item, FolderWidget *view)
    : p_impl(std::make_unique<FolderItemControllerImpl>(item, view))
{
    setItem(item);
}

//! Updates item properties from the current view position.

void FolderItemController::updateItemFromView()
{
    p_impl->updateItemFromView();
}

void FolderItemController::updateViewFromItem()
{
    p_impl->updateViewFromItem();
}

FolderItemController::~FolderItemController() = default;

void FolderItemController::subscribe()
{
    auto on_property_change = [this](auto, auto)
    {
        if (p_impl->m_blockOnPropertyChanged)
        {
            return;
        }
        p_impl->updateViewFromItem();
    };
    setOnPropertyChange(on_property_change);

    p_impl->updateViewFromItem();
}

} // namespace NodeEditor
