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

#include "datasourcewidget.h"
#include "ui_datasourcewidget.h"

#include "datasourceitem.h"

#include <mvvm/factories/viewmodelfactory.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>

#include <QDataWidgetMapper>

namespace  mvvm_folders
{

DataSourceWidget::DataSourceWidget(QWidget *parent, DataSourceItem *item)
    : PreferenceWidgetInterface(parent)
    , m_item(item)
    , view_model(nullptr)
    , delegate(std::make_unique<ModelView::ViewModelDelegate>())
    , mapper(nullptr)
    , ui(new Ui::DataSourceWidget())
{
    ui->setupUi(this);

    on_actionComboBox_currentIndexChanged(ui->actionComboBox->currentIndex());
}

DataSourceWidget::~DataSourceWidget()
{
    delete ui;
}

void DataSourceWidget::setItem(ModelView::SessionItem* item)
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
    mapper->addMapping(ui->dataSourceLineEdit, 2);
    mapper->addMapping(ui->driverLineEdit, 3);
    mapper->addMapping(ui->descriptionLineEdit, 4);
    mapper->addMapping(ui->userNameLineEdit, 5);
    mapper->addMapping(ui->passwordLineEdit, 6);
    mapper->addMapping(ui->confirmPasswordLineEdit, 6);
    mapper->addMapping(ui->userDataSourceRadioButton, 7);
    mapper->addMapping(ui->systemDataSourceRadioButton, 8);

    mapper->setCurrentModelIndex(view_model->index(0, 1));
}

bool DataSourceWidget::validate()
{
    return true;
}

QString DataSourceWidget::name() const
{
    return "General";
}

}
