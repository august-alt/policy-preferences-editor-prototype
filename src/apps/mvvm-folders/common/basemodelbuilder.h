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

#ifndef MVVM_FOLDERS_BASE_MODEL_BUILDER_H
#define MVVM_FOLDERS_BASE_MODEL_BUILDER_H

#include <string>

#include "commonitem.h"

#include <QDate>
#include <QString>

namespace mvvm_folders
{

class BaseModelBuilder
{
public:
    virtual ~BaseModelBuilder() = default;

protected:
    BaseModelBuilder() = default;

    BaseModelBuilder(const BaseModelBuilder&)            = delete;   // copy ctor
    BaseModelBuilder(BaseModelBuilder&&)                 = delete;   // move ctor
    BaseModelBuilder& operator=(const BaseModelBuilder&) = delete;   // copy assignment
    BaseModelBuilder& operator=(BaseModelBuilder&&)      = delete;   // move assignment

    template <template <typename> typename OptionalType, typename T>
    T getOptionalPropertyData(const OptionalType<T>& data)
    {
        if (data.present())
        {
            return data.get();
        }
        else
        {
            return T();
        }
    }

    std::string getActionCheckboxState(const std::string& data);

    template <typename SchemaType>
    void setCommonItemData(CommonItem* common, const SchemaType& schema)
    {
        common->setProperty(CommonItem::NAME, schema.name().c_str());
        common->setProperty(CommonItem::CHANGED, getOptionalPropertyData(schema.changed()).c_str());
        common->setProperty(CommonItem::DESC, getOptionalPropertyData(schema.desc()).c_str());
        common->setProperty(CommonItem::BYPASS_ERRORS, getOptionalPropertyData(schema.bypassErrors()));
        common->setProperty(CommonItem::USER_CONTEXT, getOptionalPropertyData(schema.userContext()));
        common->setProperty(CommonItem::REMOVE_POLICY, getOptionalPropertyData(schema.removePolicy()));
    }

    template <typename CommonData>
    void setCommonModelData(CommonData& data, const mvvm_folders::CommonItem* commonModel)
    {
        data.name(commonModel->property<std::string>(CommonItem::NAME));
        data.changed(commonModel->property<std::string>(CommonItem::CHANGED));
        data.desc(commonModel->property<std::string>(CommonItem::DESC));
        data.bypassErrors(commonModel->property<bool>(CommonItem::BYPASS_ERRORS));
        data.userContext(commonModel->property<bool>(CommonItem::USER_CONTEXT));
        data.removePolicy(commonModel->property<bool>(CommonItem::REMOVE_POLICY));
    }

    template <typename T>
    T createRootElement(const std::string& guid)
    {
        QString dateOfChange(QDate::currentDate().toString(Qt::ISODate)
                           + " "
                           + QTime::currentTime().toString("hh:mm:ss"));

        return T(
                 guid,
                 dateOfChange.toStdString(),
                 ""
                 );
    }
};

}

#endif//MVVM_FOLDERS_BASE_MODEL_BUILDER_H
