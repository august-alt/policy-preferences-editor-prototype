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

#include "preferenceswidget.h"
#include "ui_preferenceswidget.h"

#include <mvvm/model/compounditem.h>
#include <mvvm/model/sessionmodel.h>
#include <mvvm/signals/itemmapper.h>
#include <mvvm/viewmodel/defaultviewmodel.h>
#include <mvvm/viewmodel/topitemsviewmodel.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>
#include <mvvm/viewmodel/propertytableviewmodel.h>

#include "files/fileswidget.h"

namespace mvvm_folders
{

PreferencesWidget::PreferencesWidget(ModelView::SessionModel *model, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PreferencesWidget())
    , m_verticalViewModel(nullptr)
    , m_horizontalViewModel(nullptr)
    , m_selectionModel(std::make_unique<QItemSelectionModel>())
    , m_delegate(std::make_unique<ModelView::ViewModelDelegate>())
{
    ui->setupUi(this);

    setModel(model);

    setupConnections();
}

PreferencesWidget::~PreferencesWidget()
{
    delete ui;
}

void PreferencesWidget::setModel(ModelView::SessionModel *model)
{
    if (!model)
    {
        return;
    }

    // setting up left tree
    m_verticalViewModel = std::make_unique<ModelView::TopItemsViewModel>(model);
    ui->treeView->setModel(m_verticalViewModel.get());
    ui->treeView->setItemDelegate(m_delegate.get());
    ui->treeView->expandAll();
    ui->treeView->resizeColumnToContents(0);

    // setting up right table
    m_horizontalViewModel = std::make_unique<ModelView::PropertyTableViewModel>(model);
    ui->tableView->setModel(m_horizontalViewModel.get());
    ui->tableView->setItemDelegate(m_delegate.get());
    ui->tableView->header()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView->selectionModel()->select(QModelIndex(), QItemSelectionModel::Select);
}

void PreferencesWidget::setupConnections()
{
    connect(ui->treeView->selectionModel(),
                    &QItemSelectionModel::selectionChanged,
            [&](const QItemSelection &selected, const QItemSelection &deselected)
    {
        Q_UNUSED(deselected);
        if (selected.isEmpty() || selected.first().indexes().isEmpty())
        {
            return;
        }

        auto indexes = selected.indexes();
        if (!indexes.empty())
        {
            if (ui->contentScrollArea->widget()->layout())
            {
                delete ui->contentScrollArea->takeWidget();
            }

            auto files_widget = new mvvm_folders::FilesWidget(this);
            ui->contentScrollArea->setWidget(files_widget);

            auto item = m_verticalViewModel->sessionItemFromIndex(indexes.at(0));
            ui->commonWidget->setItem(item->children().front());
            files_widget->setItem(item->children().back());
        }
    });
}

}
