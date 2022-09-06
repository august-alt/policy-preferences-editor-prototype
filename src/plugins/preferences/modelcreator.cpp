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

#include "modelcreator.h"

#include <QDebug>

#include <fstream>

#include "files/filesmodelbuilder.h"
#include "folders/foldermodelbuilder.h"
#include "ini/inimodelbuilder.h"
#include "registry/registrymodelbuilder.h"
#include "shares/sharesmodelbuilder.h"
#include "shortcuts/shortcutsmodelbuilder.h"
#include "variables/variablesmodelbuilder.h"

#include "schemas/filesschema.h"
#include "schemas/foldersschema.h"
#include "schemas/inischema.h"
#include "schemas/registryschema.h"
#include "schemas/sharesschema.h"
#include "schemas/shortcutsschema.h"
#include "schemas/variablesschema.h"

namespace mvvm_folders
{
template<typename TModelBuilder>
class ModelBuilderAdapter
{
public:
    template<typename T>
    std::unique_ptr<PreferencesModel> schemaToModel(
        std::function<std::unique_ptr<T>(
            std::istream &, ::xsd::cxx::tree::flags f, ::xml_schema::Properties p)> xmlReader,
        const std::string &path)
    {
        std::unique_ptr<PreferencesModel> result;

        std::ifstream file;

        file.open(path, std::ifstream::in);

        bool ok = file.good();
        if (!ok)
        {
            qWarning() << "Failed to read file: " << path.c_str();
            return nullptr;
        }

        try
        {
            auto schema       = xmlReader(file,
                                    ::xsd::cxx::tree::flags::dont_validate,
                                    ::xml_schema::Properties());
            auto modelBuilder = std::make_unique<TModelBuilder>();
            result            = modelBuilder->schemaToModel(schema);
        }
        catch (const std::exception &e)
        {
            qWarning() << e.what();
        }

        file.close();

        return result;
    }
};

ModelCreator::ModelCreator() {}

void ModelCreator::populateModels(const std::string &policyPath,
                                  const std::string &policyType,
                                  std::map<std::string, std::unique_ptr<PreferencesModel>> *map)
{
    Q_UNUSED(policyPath);
    Q_UNUSED(policyType);
    Q_UNUSED(map);
}

} // namespace mvvm_folders
