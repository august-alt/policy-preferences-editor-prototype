/***********************************************************************************************************************/

#ifndef MVVM_FOLDERS_NETWORK_MODEL_BUILDER_H
#define MVVM_FOLDERS_NETWORK_MODEL_BUILDER_H

#include <memory>

#include "common/basemodelbuilder.h"
#include "common/preferencesmodel.h"
#include "schemas/devicesschema.h"

namespace mvvm_folders
{
class DeviceModelBuilder : public BaseModelBuilder
{
public:
    DeviceModelBuilder();

    std::unique_ptr<PreferencesModel> schemaToModel(std::unique_ptr<Devices>& device);

    std::unique_ptr<Devices> modelToSchema(std::unique_ptr<PreferencesModel>& model);
};
}

#endif // MVVM_FOLDERS_NETWORK_MODEL_BUILDER_H

