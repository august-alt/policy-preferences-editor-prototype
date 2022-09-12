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

#include <QAbstractItemModel>
#include <QDebug>
#include <QSize>

namespace preferences_editor
{
ConcatenateTreesProxyModel::ConcatenateTreesProxyModel(QObject *parent)
    : QAbstractProxyModel(parent)
    , d_ptr(new ConcatenateTreesProxyModelPrivate(this))
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
    Q_D(const ConcatenateTreesProxyModel);
    if (!sourceIndex.isValid())
    {
        return QModelIndex();
    }
    const QAbstractItemModel *sourceModel = sourceIndex.model();
    if (!d->models.contains(const_cast<QAbstractItemModel *>(sourceModel)))
    {
        qWarning() << "ConcatenateTreesProxyModel::mapFromSource index from wrong model passed.";
        return QModelIndex();
    }

    // TODO: Implement row and column calculation.

    return createIndex(sourceIndex.row(), sourceIndex.column(), sourceIndex.internalPointer());
}

QModelIndex ConcatenateTreesProxyModel::mapToSource(const QModelIndex &proxyIndex) const
{
    Q_D(const ConcatenateTreesProxyModel);
    if (!proxyIndex.isValid())
    {
        return QModelIndex();
    }

    if (proxyIndex.model() != this)
    {
        qWarning() << "ConcatenateTreesProxyModel::mapToSource index from wrong model passed.";
        return QModelIndex();
    }

    int row                               = proxyIndex.row();
    const QAbstractItemModel *sourceModel = d->sourceModelForRow(row);

    if (!sourceModel)
    {
        return QModelIndex();
    }

    return sourceModel->index(row, proxyIndex.column());
}

QVariant ConcatenateTreesProxyModel::data(const QModelIndex &index, int role) const
{
    const QModelIndex sourceIndex = mapToSource(index);
    if (sourceIndex.isValid())
    {
        return sourceIndex.data(role);
    }

    return QVariant();
}

bool ConcatenateTreesProxyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    const QModelIndex sourceIndex = mapToSource(index);
    if (!sourceIndex.isValid())
    {
        return false;
    }
    QAbstractItemModel *sourceModel = const_cast<QAbstractItemModel *>(sourceIndex.model());

    return sourceModel->setData(sourceIndex, value, role);
}

QMap<int, QVariant> ConcatenateTreesProxyModel::itemData(const QModelIndex &proxyIndex) const
{
    const QModelIndex sourceIndex = mapToSource(proxyIndex);
    if (!sourceIndex.isValid())
    {
        return QMap<int, QVariant>();
    }

    return sourceIndex.model()->itemData(sourceIndex);
}

bool ConcatenateTreesProxyModel::setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles)
{
    const QModelIndex sourceIndex = mapToSource(index);
    if (!sourceIndex.isValid())
    {
        return false;
    }

    QAbstractItemModel *sourceModel = const_cast<QAbstractItemModel *>(sourceIndex.model());

    return sourceModel->setItemData(sourceIndex, roles);
}

Qt::ItemFlags ConcatenateTreesProxyModel::flags(const QModelIndex &index) const
{
    Q_UNUSED(index);

    return Qt::NoItemFlags;
}

QModelIndex ConcatenateTreesProxyModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_D(const ConcatenateTreesProxyModel);
    if (!hasIndex(row, column, parent))
    {
        return QModelIndex();
    }

    QAbstractItemModel *sourceModel = d->sourceModelForRow(row);

    return mapFromSource(sourceModel->index(row, column));
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
    Q_D(const ConcatenateTreesProxyModel);
    if (d->models.isEmpty())
    {
        return {};
    }
    QAbstractItemModel *firstModel = const_cast<QAbstractItemModel *>(*d->models.begin());

    return firstModel->mimeTypes();
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
