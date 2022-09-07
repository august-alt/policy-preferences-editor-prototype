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

#include "datasourcemodelbuilder.h"

#include "datasourcecontaineritem.h"
#include "datasourceitem.h"

#include "common/commonitem.h"

namespace mvvm_folders
{

DataSourceModelBuilder::DataSourceModelBuilder()
    : BaseModelBuilder()
{
}

std::unique_ptr<PreferencesModel> DataSourceModelBuilder::schemaToModel(std::unique_ptr<DataSources> &dataSources)
{
    auto model = std::make_unique<PreferencesModel>();

    for (const auto& dataSourceSchema : dataSources->DataSource())
    {
        auto properties = dataSourceSchema.Properties();
        auto dataSource = DataSourceItem();
        dataSource.setProperty(DataSourceItem::ACTION, properties.action()->c_str());
        dataSource.setProperty(DataSourceItem::USERDSN, properties.userDSN().get());
        dataSource.setProperty(DataSourceItem::DSN, properties.dsn().c_str());
        dataSource.setProperty(DataSourceItem::DRIVER, properties.driver().c_str());
        dataSource.setProperty(DataSourceItem::DESCRIPTION, properties.description()->c_str());
        dataSource.setProperty(DataSourceItem::USERNAME, properties.username()->c_str());
        dataSource.setProperty(DataSourceItem::CPASSWORD, properties.cpassword()->c_str());
        dataSource.setProperty(DataSourceItem::USERSOURCE, properties.userDSN() ? true : false);
        dataSource.setProperty(DataSourceItem::SYSTEMSOURCE, properties.userDSN() ? false : true);

        auto sessionItem = model->insertItem<DataSourceContainerItem>(model->rootItem());
        sessionItem->setDataSource(dataSource);
    }

    return model;
}

std::unique_ptr<DataSources> DataSourceModelBuilder::modelToSchema(std::unique_ptr<PreferencesModel> &model)
{
    auto datasource = std::make_unique<DataSources>("{380F820F-F21B-41ac-A3CC-24D4F80F067B}");

    for (const auto& containerItem : model->topItems())
    {
        if (auto dataContainer = dynamic_cast<DataSourceContainerItem*>(containerItem); dataContainer)
        {
            auto dataModel = dataContainer->getDataSource();
            auto commonModel = dataContainer->getCommon();

            auto data = createRootElement<DataSource_t>("{5C209626-D820-4d69-8D50-1FACD6214488}");

            auto properties = Properties_t(dataModel->property<std::string>(DataSourceItem::DSN),
                                           dataModel->property<std::string>(DataSourceItem::DRIVER));
            properties.action(dataModel->property<std::string>(DataSourceItem::ACTION));
            properties.username(dataModel->property<std::string>(DataSourceItem::USERNAME));
            properties.cpassword(dataModel->property<std::string>(DataSourceItem::CPASSWORD));
            properties.description(dataModel->property<std::string>(DataSourceItem::DESCRIPTION));
//            properties.userDSN(dataModel->property<std::string>(DataSourceItem::USERDSN));

            data.Properties().push_back(properties);
            setCommonModelData(data, commonModel);

            datasource->DataSource().push_back(data);

        }
    }
    return datasource;
}

}

