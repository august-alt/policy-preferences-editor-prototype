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

#include "immediatetaskswidget.h"
#include "ui_immediatetaskswidget.h"

#include <mvvm/model/sessionitem.h>

#include <mvvm/factories/viewmodelfactory.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>

#include <QDataWidgetMapper>

namespace  mvvm_folders
{

ImmediateTasksWidget::ImmediateTasksWidget(QWidget *parent, ImmediateTasksItem *item)
    : PreferenceWidgetInterface(parent)
    , m_item(item)
    , view_model(nullptr)
    , delegate(std::make_unique<ModelView::ViewModelDelegate>())
    , mapper(nullptr)
    , ui(new Ui::ImmediateTasksWidget())
{
    ui->setupUi(this);
}

ImmediateTasksWidget::~ImmediateTasksWidget()
{
    delete ui;
}

void ImmediateTasksWidget::setItem(ModelView::SessionItem* item)
{
    view_model = ModelView::Factory::CreatePropertyFlatViewModel(item->model());
    view_model->setRootSessionItem(item);

    mapper = std::make_unique<QDataWidgetMapper>();

    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setOrientation(Qt::Vertical);

    mapper->setModel(view_model.get());
    mapper->setItemDelegate(delegate.get());
    mapper->setRootIndex(QModelIndex());

    // TODO: Implement.

    mapper->setCurrentModelIndex(view_model->index(0, 1));
}

bool ImmediateTasksWidget::validate()
{
    // TODO: Implement.

    return true;
}

void ImmediateTasksWidget::submit()
{
    if (mapper && validate())
    {
        mapper->submit();

        emit dataChanged();
    }
}

void ImmediateTasksWidget::on_actionComboBox_currentIndexChanged(int index)
{
    Q_UNUSED(index);
}

}

