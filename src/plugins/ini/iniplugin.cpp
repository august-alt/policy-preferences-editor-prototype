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

#include "../../core/plugin.h"

#include "iniformat.h"

namespace preferences_editor
{
class IniPlugin : public Plugin
{
public:
    IniPlugin()
        : Plugin("ini")
    {
        PREFERENCES_EDITOR_REGISTER_PLUGIN_CLASS(typeid(io::PolicyFileFormat<io::IniFile>).name(),
                                                 IniFormat);
    }
};
} // namespace preferences_editor

PREFERENCES_EDITOR_EXPORT_PLUGIN(inifile, preferences_editor::IniPlugin)
