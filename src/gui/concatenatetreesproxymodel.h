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

#ifndef CONCATENATE_TREES_PROXY_MODEL_H
#define CONCATENATE_TREES_PROXY_MODEL_H

#include <QAbstractProxyModel>

namespace preferences_editor
{
class ConcatenateTreesProxyModelPrivate;
class ConcatenateTreesProxyModel : public QAbstractProxyModel
{
    Q_OBJECT
public:
    explicit ConcatenateTreesProxyModel(QObject *parent = nullptr);
    ~ConcatenateTreesProxyModel();
    Q_SCRIPTABLE void addSourceModel(QAbstractItemModel *sourceModel);
    Q_SCRIPTABLE void removeSourceModel(QAbstractItemModel *sourceModel);
    QModelIndex mapFromSource(const QModelIndex &sourceIndex) const override;
    QModelIndex mapToSource(const QModelIndex &proxyIndex) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    QMap<int, QVariant> itemData(const QModelIndex &proxyIndex) const override;
    bool setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QStringList mimeTypes() const override;
    QMimeData *mimeData(const QModelIndexList &indexes) const override;
    bool canDropMimeData(const QMimeData *data,
                         Qt::DropAction action,
                         int row,
                         int column,
                         const QModelIndex &parent) const override;
    bool dropMimeData(const QMimeData *data,
                      Qt::DropAction action,
                      int row,
                      int column,
                      const QModelIndex &parent) override;
    QSize span(const QModelIndex &index) const override;

private:
    Q_DECLARE_PRIVATE(ConcatenateTreesProxyModel)
    Q_DISABLE_COPY(ConcatenateTreesProxyModel)
};

} // namespace preferences_editor

#endif // CONCATENATE_TREES_PROXY_MODEL_H
