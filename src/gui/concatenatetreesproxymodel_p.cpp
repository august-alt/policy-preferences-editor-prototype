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

#include "concatenatetreesproxymodel_p.h"

namespace preferences_editor
{
ConcatenateTreesProxyModelPrivate::ConcatenateTreesProxyModelPrivate(ConcatenateTreesProxyModel *model)
    : q_ptr(model)
    , models()
{}

ConcatenateTreesProxyModelPrivate::~ConcatenateTreesProxyModelPrivate() {}

QAbstractItemModel *ConcatenateTreesProxyModelPrivate::sourceModelForRow(int &row) const
{
    Q_UNUSED(row);
    return nullptr;
}

void ConcatenateTreesProxyModelPrivate::dataChanged(const QModelIndex &topLeft,
                                                    const QModelIndex &bottomRight,
                                                    const QVector<int> &roles)
{
    Q_UNUSED(topLeft);
    Q_UNUSED(bottomRight);
    Q_UNUSED(roles);
}

void ConcatenateTreesProxyModelPrivate::headerDataChanged(Qt::Orientation orientation, int first, int last)
{
    Q_UNUSED(orientation);
    Q_UNUSED(first);
    Q_UNUSED(last);
}

void ConcatenateTreesProxyModelPrivate::layoutChanged(const QList<QPersistentModelIndex> &parents,
                                                      QAbstractItemModel::LayoutChangeHint hint)
{
    Q_UNUSED(parents);
    Q_UNUSED(hint);
}

void ConcatenateTreesProxyModelPrivate::layoutAboutToBeChanged(const QList<QPersistentModelIndex> &parents,
                                                               QAbstractItemModel::LayoutChangeHint hint)
{
    Q_UNUSED(parents);
    Q_UNUSED(hint);
}

void ConcatenateTreesProxyModelPrivate::rowsAboutToBeInserted(const QModelIndex &parent, int first, int last)
{
    Q_UNUSED(parent);
    Q_UNUSED(first);
    Q_UNUSED(last);
}

void ConcatenateTreesProxyModelPrivate::rowsInserted(const QModelIndex &parent, int first, int last)
{
    Q_UNUSED(parent);
    Q_UNUSED(first);
    Q_UNUSED(last);
}

void ConcatenateTreesProxyModelPrivate::rowsAboutToBeRemoved(const QModelIndex &parent, int first, int last)
{
    Q_UNUSED(parent);
    Q_UNUSED(first);
    Q_UNUSED(last);
}

void ConcatenateTreesProxyModelPrivate::rowsRemoved(const QModelIndex &parent, int first, int last)
{
    Q_UNUSED(parent);
    Q_UNUSED(first);
    Q_UNUSED(last);
}

void ConcatenateTreesProxyModelPrivate::columnsAboutToBeInserted(const QModelIndex &parent, int first, int last)
{
    Q_UNUSED(parent);
    Q_UNUSED(first);
    Q_UNUSED(last);
}

void ConcatenateTreesProxyModelPrivate::columnsInserted(const QModelIndex &parent, int first, int last)
{
    Q_UNUSED(parent);
    Q_UNUSED(first);
    Q_UNUSED(last);
}

void ConcatenateTreesProxyModelPrivate::columnsAboutToBeRemoved(const QModelIndex &parent, int first, int last)
{
    Q_UNUSED(parent);
    Q_UNUSED(first);
    Q_UNUSED(last);
}

void ConcatenateTreesProxyModelPrivate::columnsRemoved(const QModelIndex &parent, int first, int last)
{
    Q_UNUSED(parent);
    Q_UNUSED(first);
    Q_UNUSED(last);
}

void ConcatenateTreesProxyModelPrivate::rowsAboutToBeMoved(
    const QModelIndex &parent, int start, int end, const QModelIndex &destination, int row)
{
    Q_UNUSED(parent);
    Q_UNUSED(start);
    Q_UNUSED(end);
    Q_UNUSED(destination);
    Q_UNUSED(row);
}

void ConcatenateTreesProxyModelPrivate::rowsMoved(
    const QModelIndex &parent, int start, int end, const QModelIndex &destination, int row)
{
    Q_UNUSED(parent);
    Q_UNUSED(start);
    Q_UNUSED(end);
    Q_UNUSED(destination);
    Q_UNUSED(row);
}

void ConcatenateTreesProxyModelPrivate::columnsAboutToBeMoved(
    const QModelIndex &parent, int start, int end, const QModelIndex &destination, int column)
{
    Q_UNUSED(parent);
    Q_UNUSED(start);
    Q_UNUSED(end);
    Q_UNUSED(destination);
    Q_UNUSED(column);
}

void ConcatenateTreesProxyModelPrivate::columnsMoved(
    const QModelIndex &parent, int start, int end, const QModelIndex &destination, int column)
{
    Q_UNUSED(parent);
    Q_UNUSED(start);
    Q_UNUSED(end);
    Q_UNUSED(destination);
    Q_UNUSED(column);
}

void ConcatenateTreesProxyModelPrivate::modelAboutToBeReset() {}

void ConcatenateTreesProxyModelPrivate::modelReset() {}

} // namespace preferences_editor
