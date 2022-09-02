/***********************************************************************************************************************/

#include "devicemodelbuilder.h"

#include "devicecontaineritem.h"
#include "deviceitem.h"

#include "common/commonitem.h"

namespace mvvm_folders
{

DeviceModelBuilder::DeviceModelBuilder()
    : BaseModelBuilder()
{
}

std::unique_ptr<PreferencesModel> DeviceModelBuilder::schemaToModel(std::unique_ptr<Devices> &devices)
{
    auto model = std::make_unique<PreferencesModel>();

    for (const auto& devicesschema : devices->Device())
    {
        auto sessionItem = model->insertItem<DeviceContainerItem>(model->rootItem());

        for (const auto& properties: devicesschema.Properties())
        {
            auto device = sessionItem->getDevice();
//            auto action = getActionCheckboxState(getOptionalPropertyData(properties.action()).c_str());
//            device->setProperty<std::string>(DeviceItem::propertyToString(DeviceItem::ACTION), action);

            auto common = sessionItem->getCommon();
            setCommonItemData(common, devicesschema);
        }
    }
    return model;
}

std::unique_ptr<Devices> DeviceModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    auto devices = std::make_unique<Devices>("{00000}");

    for (const auto& containerItem : model->topItems())
    {
        if (auto deviceContainer = dynamic_cast<DeviceContainerItem*>(containerItem); deviceContainer)
        {
            auto deviceModel = deviceContainer->getDevice();
            auto commonModel = deviceContainer->getCommon();
            auto device = createRootElement<Device_t>("{000000}");

//            auto properties = DeviceProperties_t(deviceModel->property<bool>(DeviceItem::propertyToString(devicenItem::)));
//            properties.deviceClass(deviceModel->propertyToString(DeviceItem::Class));


            setCommonModelData(device, commonModel);
//            device.Properties().push_back(properties);
        }
    }

    return devices;
}

}

