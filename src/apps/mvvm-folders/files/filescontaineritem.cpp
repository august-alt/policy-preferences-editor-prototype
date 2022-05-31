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

#include "filescontaineritem.h"

#include "common/commonitem.h"
#include "filesitem.h"

#include <mvvm/signals/itemmapper.h>

namespace mvvm_folders
{

FilesContainerItem::FilesContainerItem()
    : ModelView::CompoundItem("FilesContainerItem")
{
    addProperty(NAME, "")->setDisplayName(QObject::tr("Name").toStdString())->setEditable(false);
    addProperty(ORDER, 0)->setDisplayName(QObject::tr("Order").toStdString())->setEditable(false);
    addProperty(ACTION, "")->setDisplayName(QObject::tr("Action").toStdString())->setEditable(false);
    addProperty(FROM_PATH, "")->setDisplayName(QObject::tr("Source").toStdString())->setEditable(false);
    addProperty(TARGET_PATH, "")->setDisplayName(QObject::tr("Target").toStdString())->setEditable(false);

    addProperty<CommonItem>(COMMON)->setVisible(false);
    addProperty<FilesItem>(FILES)->setVisible(false);
}

CommonItem* FilesContainerItem::getCommon() const
{
    return static_cast<CommonItem*>(children()[childrenCount() - 2]);
}

void FilesContainerItem::setCommon(const CommonItem &item)
{
    setProperty(COMMON, item);
}

FilesItem *FilesContainerItem::getFiles() const
{
    return static_cast<FilesItem*>(children().back());
}

void FilesContainerItem::setFiles(const FilesItem &item)
{
    setProperty(FILES, item);
}

void FilesContainerItem::setupListeners()
{
    auto onChildPropertyChange = [&](SessionItem* item, std::string property)
    {
        if (auto filesItem = dynamic_cast<FilesItem*>(item))
        {
            if (property == ACTION)
            {
                setProperty(ACTION, filesItem->property<std::string>(ACTION));
            }

            if (property == FROM_PATH)
            {
                setProperty(FROM_PATH, filesItem->property<std::string>(FROM_PATH));
            }

            if (property == TARGET_PATH)
            {
                auto name = QUrl(QString::fromStdString(filesItem->property<std::string>(TARGET_PATH))).fileName()
                        .toStdString();
                setProperty(NAME, name);
                setProperty(TARGET_PATH, filesItem->property<std::string>(TARGET_PATH));
            }
        }
    };

    this->mapper()->setOnChildPropertyChange(onChildPropertyChange, nullptr);
}

}
