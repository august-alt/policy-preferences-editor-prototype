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

#include "interfaces/preferenceswidgetinterface.h"

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
class FolderItemController;

//! Folder item representation for editor.

class FolderWidget : public PreferenceWidgetInterface
{
public:
    Q_OBJECT

public:
    explicit FolderWidget(QWidget* parent = nullptr, FolderItem* item = nullptr);
    ~FolderWidget() override;

    char action() const;
    void setAction(int action);

    QString path() const;
    void setPath(const QString& path);

    bool readOnly() const;
    void setReadOnly(bool state);

    bool archive() const;
    void setArchive(bool state);

    bool hidden() const;
    void setHidden(bool state);

    bool deleteIgnoreErrors() const;
    void setDeleteIgnoreErrors(bool state);

    bool deleteFiles() const;
    void setDeleteFiles(bool state);

    bool deleteSubFolders() const;
    void setDeleteSubFolders(bool state);

    bool deleteFolder() const;
    void setDeleteFolder(bool state);

    void setItem(ModelView::SessionItem *item) override;

    bool validate() override;

signals:
    void dataChanged() override;

public slots:
    void submit() override;

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

    std::unique_ptr<FolderItemController> m_controller;

    std::unique_ptr<ModelView::ViewModel> view_model;
    std::unique_ptr<ModelView::ViewModelDelegate> delegate;
    std::unique_ptr<QDataWidgetMapper> mapper;

private:
    Ui::FoldersWidget *ui {nullptr};
};

}

#endif//MVVM_FOLDERS_FolderWidget_H
