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

#include "tabledetailswidget.h"
#include "ui_tabledetailswidget.h"

#include "common/preferencesdialog.h"
#include "interfaces/containeriteminterface.h"
#include "shortcuts/shortcutscontaineritem.h"

#include <mvvm/factories/viewmodelfactory.h>
#include <mvvm/model/sessionmodel.h>
#include <mvvm/viewmodel/propertytableviewmodel.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>
#include <mvvm/viewmodel/viewitem.h>

#include <QDebug>

namespace mvvm_folders
{

TableDetailsWidget::TableDetailsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TableDetailsWidget())
    , view_model(nullptr)
    , delegate(std::make_unique<ModelView::ViewModelDelegate>())
    , mapper(nullptr)
    , itemType("")
{
    ui->setupUi(this);

    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
}

TableDetailsWidget::~TableDetailsWidget()
{
    delete ui;
}

void TableDetailsWidget::setModel(ModelView::SessionModel *model)
{
    view_model = std::make_unique<ModelView::PropertyTableViewModel>(model);

    ui->treeView->setModel(view_model.get());
    ui->treeView->setItemDelegate(delegate.get());
    ui->treeView->header()->setSectionResizeMode(QHeaderView::Stretch);

    setupConnections();

    ui->treeView->setCurrentIndex(view_model->index(0, 0));
}

void TableDetailsWidget::onItemTypeChange(const std::string &newItemType)
{
    itemType = newItemType;
}

void TableDetailsWidget::on_treeView_customContextMenuRequested(const QPoint &point)
{
    if (!view_model)
    {
        return;
    }

    auto treeView = qobject_cast<QTreeView*>(sender());

    QModelIndex index = treeView->indexAt(point);

    auto view_item = view_model->itemFromIndex(index);

    QMenu menu;

    if (!view_item)
    {
        auto addItemAction = menu.addAction("Add item");
        auto add_item = [&]() {
            auto newItem = view_model->sessionModel()->insertNewItem(itemType,
                                                                     view_model->sessionModel()->rootItem());
            if (auto containerItemInterface = dynamic_cast<ContainerItemInterface*>(newItem))
            {
                containerItemInterface->setupListeners();
            }

        };
        connect(addItemAction, &QAction::triggered, add_item);
    }
    else
    {
        auto item = view_item->item()->parent();
        auto tagrow = item->tagRow();

        // inserting item of same type after given item
        auto addItemAction = menu.addAction("Add item");
        auto add_item = [&]() {
            view_model->sessionModel()->insertNewItem(item->modelType(), item->parent(), tagrow.next());
        };
        connect(addItemAction, &QAction::triggered, add_item);

        // removing item under the mouse
        auto removeItemAction = menu.addAction("Remove item");
        auto remove_item = [&]() { view_model->sessionModel()->removeItem(item->parent(), tagrow); };
        connect(removeItemAction, &QAction::triggered, remove_item);
    }

    menu.exec(treeView->mapToGlobal(point));
}

void TableDetailsWidget::on_treeView_doubleClicked(const QModelIndex &index)
{
    if (index.isValid())
    {
        auto item = view_model->sessionItemFromIndex(index);
        PreferencesDialog(item->parent(), nullptr).exec();
    }
}

void TableDetailsWidget::setupConnections()
{
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged,
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
            auto item = view_model->sessionItemFromIndex(indexes.at(0));
            ui->propertiesWidget->setItem(item->parent()->children()[item->parent()->children().size() - 2]);
        }
    });
}

}
