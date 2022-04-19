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

#include "driveswidget.h"
#include "ui_driveswidget.h"

#include "drivesitem.h"

#include <mvvm/factories/viewmodelfactory.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>

#include <QDataWidgetMapper>

namespace  mvvm_folders
{

DrivesWidget::DrivesWidget(QWidget *parent, DrivesItem *item)
    : QWidget(parent)
    , m_item(item)
    , view_model(nullptr)
    , delegate(std::make_unique<ModelView::ViewModelDelegate>())
    , mapper(nullptr)
    , ui(new Ui::DrivesWidget())
{
    ui->setupUi(this);

    on_actionComboBox_currentIndexChanged(ui->actionComboBox->currentIndex());
}

DrivesWidget::~DrivesWidget()
{
    delete ui;
}

void DrivesWidget::setItem(ModelView::SessionItem* item)
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
    mapper->addMapping(ui->pathLineEdit, 1);
    mapper->addMapping(ui->reconnectCheckBox, 2);
    mapper->addMapping(ui->labelLineEdit, 3);
    mapper->addMapping(ui->driveLetterGroupBox, 4);
    // TODO: Implement.

    mapper->setCurrentModelIndex(view_model->index(0, 1));
}

void DrivesWidget::submit()
{
    if (mapper)
    {
        mapper->submit();
    }
}

void DrivesWidget::on_actionComboBox_currentIndexChanged(int index)
{
    Q_UNUSED(index);
}

}
