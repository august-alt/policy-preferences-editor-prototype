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

#include "folderview.h"
#include "ui_foldersview.h"

#include "folderitemcontroller.h"

namespace  mvvm_folders
{

FolderView::FolderView(FolderItem *item)
    : QWidget()
    , m_item(item)
    , m_controller(nullptr)
    , ui(new Ui::FoldersView())
{
    ui->setupUi(this);

    m_controller = std::make_unique<FolderItemController>(item, this);

    on_actionComboBox_currentIndexChanged(ui->actionComboBox->currentIndex());
}

FolderView::~FolderView()
{
    delete ui;
}

char FolderView::action() const
{
    return ui->actionComboBox->currentIndex();
}

void FolderView::setAction(int newAction)
{
    ui->actionComboBox->setCurrentIndex(newAction);
}

QString FolderView::path() const
{
    return ui->pathLineEdit->text();
}

void FolderView::setPath(const QString &newPath)
{
    ui->pathLineEdit->setText(newPath);
}

bool FolderView::readOnly() const
{
    return ui->readOnly->isChecked();
}

void FolderView::setReadOnly(bool state)
{
    ui->readOnly->setChecked(state);
}

bool FolderView::archive() const
{
    return ui->archive->isChecked();
}

void FolderView::setArchive(bool state)
{
    ui->archive->setChecked(state);
}

bool FolderView::hidden() const
{
    return ui->hidden->isChecked();
}

void FolderView::setHidden(bool state)
{
    ui->hidden->setChecked(state);
}

bool FolderView::deleteIgnoreErrors() const
{
    return ui->ignoreErrors->isChecked();
}

void FolderView::setDeleteIgnoreErrors(bool state)
{
    ui->ignoreErrors->setChecked(state);
}

bool FolderView::deleteFiles() const
{
    return ui->deleteAllFiles->isChecked();
}

void FolderView::setDeleteFiles(bool state)
{
    ui->deleteAllFiles->setChecked(state);
}

bool FolderView::deleteSubFolders() const
{
    return ui->recursiveDelete->isChecked();
}

void FolderView::setDeleteSubFolders(bool state)
{
    ui->recursiveDelete->setChecked(state);
}

bool FolderView::deleteFolder() const
{
    return ui->deleteThisFolder->isChecked();
}

void FolderView::setDeleteFolder(bool state)
{
    ui->deleteThisFolder->setChecked(state);
}

}
