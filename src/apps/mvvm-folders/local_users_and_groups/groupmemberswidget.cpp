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

#include "groupmemberswidget.h"
#include "ui_groupmemberswidget.h"

#include "groupmemberscontaineritem.h"

#include <mvvm/factories/viewmodelfactory.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>

#include <QDataWidgetMapper>

namespace  mvvm_folders
{

GroupMembersWidget::GroupMembersWidget(QWidget *parent, GroupMembersContainerItem *item)
    : PreferenceWidgetInterface(parent)
    , m_item(item)
    , view_model(nullptr)
    , delegate(std::make_unique<ModelView::ViewModelDelegate>())
    , mapper(nullptr)
    , ui(new Ui::GroupMembersWidget())
{
    ui->setupUi(this);
}

GroupMembersWidget::~GroupMembersWidget()
{
    delete ui;
}

void GroupMembersWidget::setItem(ModelView::SessionItem* item)
{
    m_item = dynamic_cast<GroupMembersContainerItem*>(item);

    view_model = ModelView::Factory::CreateDefaultViewModel(item->model());
    view_model->setRootSessionItem(item);

    ui->membersTreeView->setModel(view_model.get());
    ui->membersTreeView->setItemDelegate(delegate.get());
    ui->membersTreeView->header()->setSectionResizeMode(QHeaderView::Stretch);

    mapper->setCurrentModelIndex(view_model->index(0, 0));
}

bool GroupMembersWidget::validate()
{
    // TODO: Implement.

    return true;
}

void GroupMembersWidget::submit()
{
    if (mapper && validate())
    {
        mapper->submit();

        emit dataChanged();
    }
}

}
