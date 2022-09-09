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

#ifndef CONCATENATE_TREES_PROXY_MODEL_PRIVATE_H
#define CONCATENATE_TREES_PROXY_MODEL_PRIVATE_H

#include <QAbstractItemModel>
#include <QObject>
#include <QSet>

namespace preferences_editor
{
class ConcatenateTreesProxyModel;
class ConcatenateTreesProxyModelPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(ConcatenateTreesProxyModel)

private:
    ConcatenateTreesProxyModel *q_ptr = nullptr;

    QSet<QAbstractItemModel *> models;

public:
    ConcatenateTreesProxyModelPrivate();
    virtual ~ConcatenateTreesProxyModelPrivate();

public slots:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);
    void headerDataChanged(Qt::Orientation orientation, int first, int last);
    void layoutChanged(const QList<QPersistentModelIndex> &parents, QAbstractItemModel::LayoutChangeHint hint);
    void layoutAboutToBeChanged(const QList<QPersistentModelIndex> &parents, QAbstractItemModel::LayoutChangeHint hint);

    void rowsAboutToBeInserted(const QModelIndex &parent, int first, int last);
    void rowsInserted(const QModelIndex &parent, int first, int last);

    void rowsAboutToBeRemoved(const QModelIndex &parent, int first, int last);
    void rowsRemoved(const QModelIndex &parent, int first, int last);

    void columnsAboutToBeInserted(const QModelIndex &parent, int first, int last);
    void columnsInserted(const QModelIndex &parent, int first, int last);

    void columnsAboutToBeRemoved(const QModelIndex &parent, int first, int last);
    void columnsRemoved(const QModelIndex &parent, int first, int last);

    void rowsAboutToBeMoved(const QModelIndex &parent, int start, int end, const QModelIndex &destination, int row);
    void rowsMoved(const QModelIndex &parent, int start, int end, const QModelIndex &destination, int row);

    void columnsAboutToBeMoved(const QModelIndex &parent, int start, int end, const QModelIndex &destination, int column);
    void columnsMoved(const QModelIndex &parent, int start, int end, const QModelIndex &destination, int column);

    void modelAboutToBeReset();
    void modelReset();

private:
    ConcatenateTreesProxyModelPrivate(const ConcatenateTreesProxyModelPrivate &) = delete;            // copy ctor
    ConcatenateTreesProxyModelPrivate(ConcatenateTreesProxyModelPrivate &&)      = delete;            // move ctor
    ConcatenateTreesProxyModelPrivate &operator=(const ConcatenateTreesProxyModelPrivate &) = delete; // copy assignment
    ConcatenateTreesProxyModelPrivate &operator=(ConcatenateTreesProxyModelPrivate &&) = delete;      // move assignment
};

} // namespace preferences_editor

#endif //CONCATENATE_TREES_PROXY_MODEL_PRIVATE_H
