#include "batteryitem.h"

namespace mvvm_folders
{

BatteryItem::BatteryItem()
    : ModelView::CompoundItem("BatteryItem")
{
    addProperty(FILE_EXTENSION, "");
    addProperty(APPLICATION_PATH, "");
    addProperty(DEFAULT, false);
}

BatteryItem::BatteryItem(const BatteryItem &other)
    : ModelView::CompoundItem("BatteryItem")
{
    addProperty(FILE_EXTENSION, other.property<std::string>(FILE_EXTENSION));
    addProperty(APPLICATION_PATH, other.property<std::string>(APPLICATION_PATH));
    addProperty(DEFAULT, other.property<bool>(DEFAULT));
}

}
