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
#include <mvvm/signals/modelmapper.h>
#include <mvvm/viewmodel/defaultviewmodel.h>
#include <mvvm/viewmodel/viewmodeldelegate.h>

#include "preferenceswidget.h"

#include "shortcuts/shortcutscontaineritem.h"
#include "shortcuts/shortcutsitem.h"

#include "common/preferencecategoryitem.h"

using namespace ModelView;
using namespace mvvm_folders;

int main(int argc, char** argv)
{
    QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));

    QApplication app(argc, argv);

    SessionModel model;

    auto drivesItem = model.insertItem<PreferenceCategoryItem>();
    drivesItem->setDisplayName("Drives");
    drivesItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "DrivesContainerItem");

    auto filesItem = model.insertItem<PreferenceCategoryItem>();
    filesItem->setDisplayName("Files");
    filesItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "FilesContainerItem");

    auto iniItem = model.insertItem<PreferenceCategoryItem>();
    iniItem->setDisplayName("Ini");
    iniItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "IniContainerItem");

    auto sharesItem = model.insertItem<PreferenceCategoryItem>();
    sharesItem->setDisplayName("Shares");
    sharesItem->setProperty<std::string>(PreferenceCategoryItem::TYPE, "SharesContainerItem");

    auto shortcutsItems = model.insertItem<PreferenceCategoryItem>();
    shortcutsItems->setDisplayName("Shortcuts");
    shortcutsItems->setProperty<std::string>(PreferenceCategoryItem::TYPE, "ShortcutsContainerItem");

    auto variablesItems = model.insertItem<PreferenceCategoryItem>();
    variablesItems->setDisplayName("Variables");
    variablesItems->setProperty<std::string>(PreferenceCategoryItem::TYPE, "VariablesContainerItem");

    mvvm_folders::PreferencesWidget widget(&model);
    widget.show();

    return app.exec();
}
