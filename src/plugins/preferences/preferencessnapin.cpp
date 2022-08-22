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

#include "preferencessnapin.h"

#include <iostream>

#include "preferencestreemodel.h"

#include <mvvm/viewmodel/topitemsviewmodel.h>

namespace preferences_editor
{
class PreferencesSnapInPrivate
{
public:
    std::unique_ptr<mvvm_folders::PreferencesTreeModel> model = nullptr;
    std::unique_ptr<ModelView::TopItemsViewModel> viewModel   = nullptr;

public:
    PreferencesSnapInPrivate() {}

private:
    PreferencesSnapInPrivate(const PreferencesSnapInPrivate &) = delete;            // copy ctor
    PreferencesSnapInPrivate(PreferencesSnapInPrivate &&)      = delete;            // move ctor
    PreferencesSnapInPrivate &operator=(const PreferencesSnapInPrivate &) = delete; // copy assignment
    PreferencesSnapInPrivate &operator=(PreferencesSnapInPrivate &&) = delete; // move assignment
};

PreferencesSnapIn::PreferencesSnapIn()
    : AbstractSnapIn("ISnapIn",
                     "PreferencesSnapIn",
                     "Snap-in for preferences management.",
                     {1, 0, 0},
                     "GPL-2.0",
                     "Copyright (C) 2022 BaseALT Ltd. <org@basealt.ru>")
    , d(new PreferencesSnapInPrivate())
{}

void PreferencesSnapIn::onInitialize()
{
    d->model = std::make_unique<mvvm_folders::PreferencesTreeModel>();

    d->viewModel = std::make_unique<ModelView::TopItemsViewModel>(d->model.get());

    setRootNode(d->viewModel.get());

    std::cout << std::string(__PRETTY_FUNCTION__) << std::endl;
}

void PreferencesSnapIn::onShutdown()
{
    std::cout << std::string(__PRETTY_FUNCTION__) << std::endl;
}

} // namespace preferences_editor
