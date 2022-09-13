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

#ifndef MVVM_FOLDERS_PREFERENCE_READER_INTERFACE_H
#define MVVM_FOLDERS_PREFERENCE_READER_INTERFACE_H

#include <memory>
#include <string>

#include "common/preferencesmodel.h"

namespace mvvm_folders
{
class PreferenceReaderInterface
{
public:
    PreferenceReaderInterface()          = default;
    virtual ~PreferenceReaderInterface() = default;

    virtual std::string getType() const = 0;

    virtual std::unique_ptr<PreferencesModel> read(const std::string path) = 0;
};

} // namespace mvvm_folders

#endif //MVVM_FOLDERS_PREFERENCE_READER_INTERFACE_H