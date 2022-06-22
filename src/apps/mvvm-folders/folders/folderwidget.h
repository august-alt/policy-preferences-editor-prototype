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

#ifndef MVVM_FOLDERS_FolderWidget_H
#define MVVM_FOLDERS_FolderWidget_H

#include <mvvm/model/compounditem.h>

#include "common/basepreferencewidget.h"

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class FoldersWidget; }
QT_END_NAMESPACE

class QDataWidgetMapper;

namespace ModelView
{
    class ViewModel;
    class ViewModelDelegate;
    class SessionItem;
}

namespace mvvm_folders
{

class FolderItem;

//! Folder item representation for editor.

class FolderWidget : public BasePreferenceWidget
{
public:
    Q_OBJECT

public:
    explicit FolderWidget(QWidget* parent = nullptr, FolderItem* item = nullptr);
    ~FolderWidget() override;

    void setItem(ModelView::SessionItem *item) override;

    QString name() const override;

private slots:
    void on_pathToolButton_clicked();

private slots:
    void on_actionComboBox_currentIndexChanged(int index);

private:
    FolderWidget(const FolderWidget&)            = delete;   // copy ctor
    FolderWidget(FolderWidget&&)                 = delete;   // move ctor
    FolderWidget& operator=(const FolderWidget&) = delete;   // copy assignment
    FolderWidget& operator=(FolderWidget&&)      = delete;   // move assignment

private:
    //!< Underlying item of this view.
    FolderItem* m_item {nullptr};

    std::unique_ptr<ModelView::ViewModel> view_model;
    std::unique_ptr<ModelView::ViewModelDelegate> delegate;

private:
    Ui::FoldersWidget *ui {nullptr};
};

}

#endif//MVVM_FOLDERS_FolderWidget_H
