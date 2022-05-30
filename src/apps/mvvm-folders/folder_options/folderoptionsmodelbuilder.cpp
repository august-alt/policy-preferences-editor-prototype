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

#include "folderoptionsmodelbuilder.h"

#include "folderoptionscontaineritem.h"
#include "folderoptionsitem.h"

#include "common/commonitem.h"

namespace mvvm_folders
{

std::unique_ptr<PreferencesModel> FolderOptionsModelBuilder::schemaToModel(std::unique_ptr<FolderOptions> &folderOptionsSource)
{
    Q_UNUSED(folderOptionsSource);

    auto model = std::make_unique<PreferencesModel>();

    // TODO: Implement.

    return model;
}

std::unique_ptr<FolderOptions> FolderOptionsModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    Q_UNUSED(model);

    return nullptr;
}

}

