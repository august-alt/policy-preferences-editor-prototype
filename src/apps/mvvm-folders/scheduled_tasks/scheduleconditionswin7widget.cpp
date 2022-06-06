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

#include "scheduleconditionswin7widget.h"
#include "ui_scheduleconditionswin7widget.h"

#include "scheduleconditionswin7item.h"

#include <mvvm/factories/viewmodelfactory.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>

#include <QDataWidgetMapper>

namespace  mvvm_folders
{

ScheduleConditionsWin7Widget::ScheduleConditionsWin7Widget(QWidget *parent, ScheduleConditionsWin7Item *item)
    : PreferenceWidgetInterface(parent)
    , m_item(item)
    , view_model(nullptr)
    , delegate(std::make_unique<ModelView::ViewModelDelegate>())
    , mapper(nullptr)
    , ui(new Ui::ScheduleConditionsWin7Widget())
{
    ui->setupUi(this);

    on_actionComboBox_currentIndexChanged(ui->actionComboBox->currentIndex());
}

ScheduleConditionsWin7Widget::~ScheduleConditionsWin7Widget()
{
    delete ui;
}

void ScheduleConditionsWin7Widget::setItem(ModelView::SessionItem* item)
{
    view_model = ModelView::Factory::CreatePropertyFlatViewModel(item->model());
    view_model->setRootSessionItem(item);

    mapper = std::make_unique<QDataWidgetMapper>();

    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setOrientation(Qt::Vertical);

    mapper->setModel(view_model.get());
    mapper->setItemDelegate(delegate.get());
    mapper->setRootIndex(QModelIndex());    

    mapper->addMapping(ui->actionComboBox, 0);
    // TODO: Implement.

    mapper->setCurrentModelIndex(view_model->index(0, 1));
}

bool ScheduleConditionsWin7Widget::validate()
{
    // TODO: Implement.
    
    return true;
}

void ScheduleConditionsWin7Widget::submit()
{
    if (mapper && validate())
    {
        mapper->submit();

        emit dataChanged();
    }
}

void ScheduleConditionsWin7Widget::on_actionComboBox_currentIndexChanged(int index)
{
    Q_UNUSED(index);
}

}

