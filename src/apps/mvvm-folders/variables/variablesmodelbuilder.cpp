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

#include "variablesmodelbuilder.h"

#include "variablescontaineritem.h"
#include "variablesitem.h"

#include "common/commonitem.h"

namespace mvvm_folders
{

VariablesModelBuilder::VariablesModelBuilder()
    : BaseModelBuilder()
{
}

std::unique_ptr<PreferencesModel> VariablesModelBuilder::schemaToModel(std::unique_ptr<EnvironmentVariables> &variablesSource)
{
    auto model = std::make_unique<PreferencesModel>();

    for (const auto& variablesSchema : variablesSource->EnvironmentVariable())
    {
        auto properties = variablesSchema.Properties();
        for (const auto& currentProperties : properties)
        {
            std::string actionState = getActionCheckboxState(getOptionalPropertyData(currentProperties.action()).c_str());

            auto sessionItem = model->insertItem<VariablesContainerItem>(model->rootItem());

            auto variables = sessionItem->getVariables();
            variables->setProperty(VariablesItem::ACTION, actionState);
            variables->setProperty(VariablesItem::USER, getOptionalPropertyData(currentProperties.user()));
            variables->setProperty(VariablesItem::NAME, currentProperties.name().c_str());
            variables->setProperty(VariablesItem::PARTIAL, getOptionalPropertyData(currentProperties.partial()));
            variables->setProperty(VariablesItem::VALUE, currentProperties.value().c_str());
            variables->setProperty(VariablesItem::SYSTEM, !getOptionalPropertyData(currentProperties.user()));

            auto common = sessionItem->getCommon();
            setCommonItemData(common, variablesSchema);
        }
    }

    return model;
}

std::unique_ptr<EnvironmentVariables> VariablesModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    Q_UNUSED(model);

    return nullptr;
}

}

