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

#include "folderwidget.h"
#include "ui_folderswidget.h"

#include "folderitemcontroller.h"
#include "folderitem.h"

#include <mvvm/factories/viewmodelfactory.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>

#include <QDataWidgetMapper>

namespace  mvvm_folders
{

FolderWidget::FolderWidget(QWidget *parent, FolderItem *item)
    : PreferenceWidgetInterface(parent)
    , m_item(item)
    , m_controller(nullptr)
    , view_model(nullptr)
    , delegate(std::make_unique<ModelView::ViewModelDelegate>())
    , mapper(nullptr)
    , ui(new Ui::FoldersWidget())
{
    ui->setupUi(this);

//    m_controller = std::make_unique<FolderItemController>(item, this);

    on_actionComboBox_currentIndexChanged(ui->actionComboBox->currentIndex());
}

FolderWidget::~FolderWidget()
{
    delete ui;
}

char FolderWidget::action() const
{
    return ui->actionComboBox->currentIndex();
}

void FolderWidget::setAction(int newAction)
{
    ui->actionComboBox->setCurrentIndex(newAction);
}

QString FolderWidget::path() const
{
    return ui->pathLineEdit->text();
}

void FolderWidget::setPath(const QString &newPath)
{
    ui->pathLineEdit->setText(newPath);
}

bool FolderWidget::readOnly() const
{
    return ui->readOnly->isChecked();
}

void FolderWidget::setReadOnly(bool state)
{
    ui->readOnly->setChecked(state);
}

bool FolderWidget::archive() const
{
    return ui->archive->isChecked();
}

void FolderWidget::setArchive(bool state)
{
    ui->archive->setChecked(state);
}

bool FolderWidget::hidden() const
{
    return ui->hidden->isChecked();
}

void FolderWidget::setHidden(bool state)
{
    ui->hidden->setChecked(state);
}

bool FolderWidget::deleteIgnoreErrors() const
{
    return ui->ignoreErrors->isChecked();
}

void FolderWidget::setDeleteIgnoreErrors(bool state)
{
    ui->ignoreErrors->setChecked(state);
}

bool FolderWidget::deleteFiles() const
{
    return ui->deleteAllFiles->isChecked();
}

void FolderWidget::setDeleteFiles(bool state)
{
    ui->deleteAllFiles->setChecked(state);
}

bool FolderWidget::deleteSubFolders() const
{
    return ui->recursiveDelete->isChecked();
}

void FolderWidget::setDeleteSubFolders(bool state)
{
    ui->recursiveDelete->setChecked(state);
}

bool FolderWidget::deleteFolder() const
{
    return ui->deleteThisFolder->isChecked();
}

void FolderWidget::setDeleteFolder(bool state)
{
    ui->deleteThisFolder->setChecked(state);
}

void FolderWidget::setItem(ModelView::SessionItem* item)
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
    mapper->addMapping(ui->pathLineEdit, 1);
    mapper->addMapping(ui->readOnly, 2);
    mapper->addMapping(ui->archive, 3);
    mapper->addMapping(ui->hidden, 4);
    mapper->addMapping(ui->ignoreErrors, 5);
    mapper->addMapping(ui->deleteAllFiles, 6);
    mapper->addMapping(ui->recursiveDelete, 7);
    mapper->addMapping(ui->deleteThisFolder, 8);

    mapper->setCurrentModelIndex(view_model->index(0, 1));
}

bool FolderWidget::validate()
{
    return true;
}

void FolderWidget::submit()
{
    if (mapper && validate())
    {
        mapper->submit();

        emit dataChanged();
    }
}

QString FolderWidget::name() const
{
    return "General";
}

}
