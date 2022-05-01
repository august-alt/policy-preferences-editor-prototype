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

#include "groupmemberitem.h"
#include "groupmemberscontaineritem.h"
#include "groupmemberdialog.h"

#include <mvvm/model/sessionmodel.h>
#include <mvvm/viewmodel/viewmodel.h>

#include <QDebug>

namespace mvvm_folders
{

void GroupMembersWidget::on_addPushButton_clicked()
{
    // TODO: Implement item insertion.
}

void GroupMembersWidget::on_removePushButton_clicked()
{
    auto item = view_model->sessionItemFromIndex(ui->membersTreeView->currentIndex());
    if (item)
    {
        view_model->sessionModel()->removeItem(item->parent(), item->tagRow());
    }
}

void GroupMembersWidget::on_changePushButton_clicked()
{
    auto item = view_model->sessionItemFromIndex(ui->membersTreeView->currentIndex());
    if (item)
    {
        auto dialog = GroupMemberDialog(this, item);
        dialog.exec();
    }
}

}
