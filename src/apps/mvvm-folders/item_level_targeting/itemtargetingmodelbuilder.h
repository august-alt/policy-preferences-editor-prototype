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

#ifndef MVVM_FOLDERS_ITEM_LEVEL_TARGETING_MODEL_BUILDER_H
#define MVVM_FOLDERS_ITEM_LEVEL_TARGETING_MODEL_BUILDER_H

#include <memory>

#include "common/basemodelbuilder.h"
#include "common/preferencesmodel.h"
//#include "schemas/filtersschema.h"

namespace mvvm_folders
{

class CommonItem;

class ItemTargetingModelBuilder : public BaseModelBuilder
{
public:
    ItemTargetingModelBuilder();

//    std::unique_ptr<PreferencesModel> schemaToModel(std::unique_ptr<ItemTargeting>& folderOptions);

//    std::unique_ptr<ItemTargeting> modelToSchema(std::unique_ptr<PreferencesModel>& model);
};

}

#endif // MVVM_FOLDERS_ITEM_LEVEL_TARGETING_MODEL_BUILDER_H
