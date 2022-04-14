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

#include <QApplication>
#include <QLocale>
#include <QTreeView>

#include <mvvm/model/compounditem.h>
#include <mvvm/model/sessionmodel.h>
#include <mvvm/signals/itemmapper.h>
#include <mvvm/viewmodel/defaultviewmodel.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>

#include "preferenceswidget.h"

#include "folderitem.h"

using namespace ModelView;

int main(int argc, char** argv)
{
    QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));

    QApplication app(argc, argv);

    SessionModel model;    
    model.insertItem<mvvm_folders::FolderItem>();
    model.insertItem<mvvm_folders::FolderItem>();
    model.insertItem<mvvm_folders::FolderItem>();
    model.insertItem<mvvm_folders::FolderItem>();


    mvvm_folders::PreferencesWidget widget(&model);
    widget.show();

    return app.exec();
}
