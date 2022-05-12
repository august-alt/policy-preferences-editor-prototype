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

#include "printercontaineritem.h"

#include "common/commonitem.h"
#include "localprinteritem.h"

#include <mvvm/signals/itemmapper.h>

namespace mvvm_folders
{

PrinterContainerItem::PrinterContainerItem()
    : ModelView::CompoundItem("PrinterContainerItem")
{
    addProperty(NAME, "")->setDisplayName(QObject::tr("Name").toStdString())->setEditable(false);
    addProperty(ORDER, 0)->setDisplayName(QObject::tr("Order").toStdString())->setEditable(false);
    addProperty(ACTION, "")->setDisplayName(QObject::tr("Action").toStdString())->setEditable(false);
    addProperty(PATH, QObject::tr("N/A").toStdString())->setDisplayName(QObject::tr("Path").toStdString())->setEditable(false);
    addProperty(DEFAULT, QObject::tr("N/A").toStdString())->setDisplayName(QObject::tr("Default").toStdString())->setEditable(false);

    addProperty<CommonItem>(COMMON)->setVisible(false);
    addProperty<LocalPrinterItem>(PRINTER)->setVisible(false);
}

CommonItem PrinterContainerItem::getCommon() const
{
    return property<CommonItem>(COMMON);
}

void PrinterContainerItem::setCommon(const CommonItem &item)
{
    setProperty(COMMON, item);
}

LocalPrinterItem PrinterContainerItem::getPrinter() const
{
    return property<LocalPrinterItem>(PRINTER);
}

void PrinterContainerItem::setPrinter(const LocalPrinterItem &item)
{
    setProperty(PRINTER, item);
}

void PrinterContainerItem::setupListeners()
{
    auto onChildPropertyChange = [&](SessionItem* item, std::string property)
    {
        if (auto localPrinterItem = dynamic_cast<LocalPrinterItem*>(item))
        {
            if (property == ACTION)
            {
                setProperty(ACTION, localPrinterItem->property<std::string>(ACTION));
            }

            if (property == NAME)
            {
                setProperty(NAME, localPrinterItem->property<std::string>(NAME));
            }

            if (property == PATH)
            {
                setProperty(PATH, localPrinterItem->property<std::string>(PATH));
            }

            if (property == DEFAULT)
            {
                setProperty(DEFAULT, localPrinterItem->property<bool>(DEFAULT)
                            ? "Yes"
                            : "No");
            }
        }
    };

    this->mapper()->setOnChildPropertyChange(onChildPropertyChange, nullptr);
}

}

