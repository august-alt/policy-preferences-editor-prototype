/***********************************************************************************************************************
**
** Copyright (C) 2022 BaseALT Ltd. <org@basealt.ru>
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
#include "concatenatetreesproxymodel.h"
#include "concatenatetreesproxymodel_p.h"

#include <QSize>

namespace preferences_editor
{
ConcatenateTreesProxyModel::ConcatenateTreesProxyModel(QObject *parent)
    : QAbstractProxyModel(parent)
    , d_ptr(new ConcatenateTreesProxyModelPrivate())
{}

ConcatenateTreesProxyModel::~ConcatenateTreesProxyModel() {}

void ConcatenateTreesProxyModel::addSourceModel(QAbstractItemModel *sourceModel)
{
    Q_D(ConcatenateTreesProxyModel);
    if (!sourceModel || d->models.contains(sourceModel))
    {
        return;
    }

    connect(sourceModel, &QAbstractItemModel::dataChanged, d, &ConcatenateTreesProxyModelPrivate::dataChanged);
    connect(sourceModel, &QAbstractItemModel::rowsInserted, d, &ConcatenateTreesProxyModelPrivate::rowsInserted);
    connect(sourceModel, &QAbstractItemModel::rowsRemoved, d, &ConcatenateTreesProxyModelPrivate::rowsRemoved);
    connect(sourceModel,
            &QAbstractItemModel::rowsAboutToBeInserted,
            d,
            &ConcatenateTreesProxyModelPrivate::rowsAboutToBeInserted);
    connect(sourceModel,
            &QAbstractItemModel::rowsAboutToBeRemoved,
            d,
            &ConcatenateTreesProxyModelPrivate::rowsAboutToBeRemoved);
    connect(sourceModel, &QAbstractItemModel::columnsInserted, d, &ConcatenateTreesProxyModelPrivate::columnsInserted);
    connect(sourceModel, &QAbstractItemModel::columnsRemoved, d, &ConcatenateTreesProxyModelPrivate::columnsRemoved);
    connect(sourceModel,
            &QAbstractItemModel::columnsAboutToBeInserted,
            d,
            &ConcatenateTreesProxyModelPrivate::columnsAboutToBeInserted);
    connect(sourceModel,
            &QAbstractItemModel::columnsAboutToBeRemoved,
            d,
            &ConcatenateTreesProxyModelPrivate::columnsAboutToBeRemoved);
    connect(sourceModel,
            &QAbstractItemModel::layoutAboutToBeChanged,
            d,
            &ConcatenateTreesProxyModelPrivate::layoutAboutToBeChanged);
    connect(sourceModel, &QAbstractItemModel::layoutChanged, d, &ConcatenateTreesProxyModelPrivate::layoutChanged);

    connect(sourceModel,
            &QAbstractItemModel::modelAboutToBeReset,
            d,
            &ConcatenateTreesProxyModelPrivate::modelAboutToBeReset);
    connect(sourceModel, &QAbstractItemModel::modelReset, d, &ConcatenateTreesProxyModelPrivate::modelReset);

    // TODO: Update row and column count.

    d->models.insert(sourceModel);
}

void ConcatenateTreesProxyModel::removeSourceModel(QAbstractItemModel *sourceModel)
{
    Q_D(ConcatenateTreesProxyModel);
    if (!d->models.contains(sourceModel))
    {
        return;
    }
    disconnect(sourceModel, nullptr, d, nullptr);

    // TODO: Update row and column count.

    d->models.remove(sourceModel);
}

QModelIndex ConcatenateTreesProxyModel::mapFromSource(const QModelIndex &sourceIndex) const
{
    Q_UNUSED(sourceIndex);

    return QModelIndex();
}

QModelIndex ConcatenateTreesProxyModel::mapToSource(const QModelIndex &proxyIndex) const
{
    Q_UNUSED(proxyIndex);

    return QModelIndex();
}

QVariant ConcatenateTreesProxyModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(index);
    Q_UNUSED(role);

    return QVariant();
}

bool ConcatenateTreesProxyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(index);
    Q_UNUSED(value);
    Q_UNUSED(role);

    return false;
}

QMap<int, QVariant> ConcatenateTreesProxyModel::itemData(const QModelIndex &proxyIndex) const
{
    Q_UNUSED(proxyIndex);

    return QMap<int, QVariant>();
}

bool ConcatenateTreesProxyModel::setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles)
{
    Q_UNUSED(index);
    Q_UNUSED(roles);

    return false;
}

Qt::ItemFlags ConcatenateTreesProxyModel::flags(const QModelIndex &index) const
{
    Q_UNUSED(index);

    return Qt::NoItemFlags;
}

QModelIndex ConcatenateTreesProxyModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(row);
    Q_UNUSED(column);
    Q_UNUSED(parent);

    return QModelIndex();
}

QModelIndex ConcatenateTreesProxyModel::parent(const QModelIndex &index) const
{
    Q_UNUSED(index);

    return QModelIndex();
}

int ConcatenateTreesProxyModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return 0;
}

QVariant ConcatenateTreesProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(section);
    Q_UNUSED(orientation);
    Q_UNUSED(role);

    return QVariant();
}

int ConcatenateTreesProxyModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return 0;
}

QStringList ConcatenateTreesProxyModel::mimeTypes() const
{
    return {};
}

QMimeData *ConcatenateTreesProxyModel::mimeData(const QModelIndexList &indexes) const
{
    Q_UNUSED(indexes);

    return nullptr;
}

bool ConcatenateTreesProxyModel::canDropMimeData(
    const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(data);
    Q_UNUSED(action);
    Q_UNUSED(row);
    Q_UNUSED(column);
    Q_UNUSED(parent);

    return false;
}

bool ConcatenateTreesProxyModel::dropMimeData(
    const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    Q_UNUSED(data);
    Q_UNUSED(action);
    Q_UNUSED(row);
    Q_UNUSED(column);
    Q_UNUSED(parent);

    return false;
}

QSize ConcatenateTreesProxyModel::span(const QModelIndex &index) const
{
    Q_UNUSED(index);

    return {};
}

} // namespace preferences_editor
