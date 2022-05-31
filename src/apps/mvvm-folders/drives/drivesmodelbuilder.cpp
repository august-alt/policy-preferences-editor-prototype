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

#include "drivesmodelbuilder.h"

#include "drivescontaineritem.h"
#include "drivesitem.h"

#include "common/commonitem.h"

namespace mvvm_folders
{

DrivesModelBuilder::DrivesModelBuilder()
    : BaseModelBuilder()
{
}

std::unique_ptr<PreferencesModel> DrivesModelBuilder::schemaToModel(std::unique_ptr<Drives> &drivesSource)
{
    auto model = std::make_unique<PreferencesModel>();

    for (const auto& drivesSchema : drivesSource->Drive())
    {
        auto properties = drivesSchema.Properties();
        for (const auto& currentProperties : properties)
        {
            int thisDriveIndex = getDrivesCheckboxIndex(currentProperties.thisDrive().present() ? currentProperties.thisDrive()->c_str() : "");
            int allDrivesIndex = getDrivesCheckboxIndex(currentProperties.allDrives().present() ? currentProperties.allDrives()->c_str() : "");

            std::string actionState = getActionCheckboxState(currentProperties.action() ? currentProperties.action()->c_str() : "");

            auto sessionItem = model->insertItem<DrivesContainerItem>(model->rootItem());

            auto drives = sessionItem->children().back();
            drives->setProperty(DrivesItem::ACTION, actionState);
            drives->setProperty(DrivesItem::PATH, currentProperties.path().c_str());
            drives->setProperty(DrivesItem::PERSISTENT, static_cast<bool>(currentProperties.persistent()));
            drives->setProperty(DrivesItem::LABEL, currentProperties.label().present() ? currentProperties.label()->c_str() : "");
            drives->setProperty(DrivesItem::LETTER, currentProperties.letter().c_str());
            drives->setProperty(DrivesItem::USER_NAME, currentProperties.userName().present() ? currentProperties.userName()->c_str() : "");
            drives->setProperty(DrivesItem::CPASSWORD, currentProperties.cpassword().present() ? currentProperties.cpassword()->c_str() : "");
            drives->setProperty(DrivesItem::USE_LETTER, static_cast<bool>(currentProperties.useLetter()));
            drives->setProperty(DrivesItem::THIS_DRIVE, thisDriveIndex);
            drives->setProperty(DrivesItem::ALL_DRIVES, allDrivesIndex);
            drives->setProperty(DrivesItem::USE_EXISTING, !currentProperties.useLetter());

            auto common = (sessionItem->children()[sessionItem->childrenCount() - 2]);
            common->setProperty(CommonItem::NAME, drivesSchema.name().c_str());
            common->setProperty(CommonItem::CHANGED, drivesSchema.changed().present() ? drivesSchema.changed()->c_str() : "");
            common->setProperty(CommonItem::DESC, drivesSchema.desc().present() ? drivesSchema.desc()->c_str() : "");
            common->setProperty(CommonItem::BYPASS_ERRORS, static_cast<bool>(drivesSchema.bypassErrors().get()));
            common->setProperty(CommonItem::USER_CONTEXT, static_cast<bool>(drivesSchema.userContext().get()));
            common->setProperty(CommonItem::REMOVE_POLICY, static_cast<bool>(drivesSchema.removePolicy().get()));
        }
    }

    return model;
}

std::unique_ptr<Drives> DrivesModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    auto drives = std::make_unique<Drives>("{8FDDCC1A-0C3C-43cd-A6B4-71A6DF20DA8C}");

    QString dateOfChange(QDate::currentDate().toString(Qt::ISODate)
                       + " "
                       + QTime::currentTime().toString("hh:mm:ss"));

    for (const auto& containerItem : model->topItems())
    {
        if (auto drivesContainer = dynamic_cast<DrivesContainerItem*>(containerItem); drivesContainer)
        {
            auto driveModel = drivesContainer->getDrives();
            auto commonModel = drivesContainer->getCommon();

            auto drive = Drive_t(
                                "{935D1B74-9CB8-4e3c-9914-7DD559B7A417}",
                                dateOfChange.toStdString(),
                                ""
                                );

            auto properties = DriveProperties_t(driveModel.property<std::string>(DrivesItem::PATH),
                                                driveModel.property<bool>(DrivesItem::PERSISTENT),
                                                driveModel.property<bool>(DrivesItem::USE_LETTER),
                                                driveModel.property<std::string>(DrivesItem::LETTER));
            properties.action(driveModel.property<std::string>(DrivesItem::ACTION));
            properties.path(driveModel.property<std::string>(DrivesItem::PATH));
            properties.label(driveModel.property<std::string>(DrivesItem::LABEL));
            properties.userName(driveModel.property<std::string>(DrivesItem::USER_NAME));
            properties.cpassword(driveModel.property<std::string>(DrivesItem::CPASSWORD));
            properties.thisDrive(driveModel.property<std::string>(DrivesItem::THIS_DRIVE));
            properties.allDrives(driveModel.property<std::string>(DrivesItem::ALL_DRIVES));

            drive.Properties().push_back(properties);

            drive.name(commonModel.property<std::string>(CommonItem::NAME));
            drive.changed(commonModel.property<std::string>(CommonItem::CHANGED));
            drive.desc(commonModel.property<std::string>(CommonItem::DESC));
            drive.bypassErrors(commonModel.property<bool>(CommonItem::BYPASS_ERRORS));
            drive.userContext(commonModel.property<bool>(CommonItem::USER_CONTEXT));
            drive.removePolicy(commonModel.property<bool>(CommonItem::REMOVE_POLICY));

            drives->Drive().push_back(drive);
        }
    }

    return drives;
}

int DrivesModelBuilder::getDrivesCheckboxIndex(const std::string &data)
{
    if (data.compare("NOCHANGE") == 0)
    {
        return 0;
    }

    if (data.compare("HIDE") == 0)
    {
        return 1;
    }

    if (data.compare("SHOW") == 0)
    {
        return 2;
    }

    return 0;
}

}

