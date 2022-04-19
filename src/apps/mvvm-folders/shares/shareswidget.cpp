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

#include "shareswidget.h"
#include "ui_shareswidget.h"

#include "sharesitem.h"

#include <mvvm/factories/viewmodelfactory.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>

#include <QDataWidgetMapper>

namespace  mvvm_folders
{

SharesWidget::SharesWidget(QWidget *parent, SharesItem *item)
    : QWidget(parent)
    , m_item(item)
    , view_model(nullptr)
    , delegate(std::make_unique<ModelView::ViewModelDelegate>())
    , mapper(nullptr)
    , ui(new Ui::SharesWidget())
{
    ui->setupUi(this);

    on_actionComboBox_currentIndexChanged(ui->actionComboBox->currentIndex());
}

SharesWidget::~SharesWidget()
{
    delete ui;
}

void SharesWidget::setItem(ModelView::SessionItem* item)
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
    mapper->addMapping(ui->shareNameLineEdit, 1);
    mapper->addMapping(ui->folderPathLineEdit, 2);
    mapper->addMapping(ui->commentLineEdit, 3);
    mapper->addMapping(ui->updateAllRegularShares, 4);
    mapper->addMapping(ui->updateAllHiddenShares, 5);
    mapper->addMapping(ui->updateAllAdministrativeDrives, 6);
    mapper->addMapping(ui->allowThisNumberOfUsers, 7);
    mapper->addMapping(ui->userLimitLabel, 8);
    // TODO: Implement user limit.
    // TODO: Implement access based enumeration.

    mapper->setCurrentModelIndex(view_model->index(0, 1));
}

void SharesWidget::submit()
{
    if (mapper)
    {
        mapper->submit();
    }
}

void SharesWidget::on_actionComboBox_currentIndexChanged(int index)
{
    Q_UNUSED(index);
}

}
