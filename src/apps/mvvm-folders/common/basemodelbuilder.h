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

public:
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
};

}

#endif//MVVM_FOLDERS_BASE_MODEL_BUILDER_H
