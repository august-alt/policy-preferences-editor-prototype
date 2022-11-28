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

#include "datematchitem.h"

namespace mvvm_folders
{

DateMatchItem::DateMatchItem()
    : ModelView::CompoundItem("dateMatchItem")
{
    addProperty(PERIODIC, "");
    addProperty(DAY, "");
    addProperty(DATE, "");
    addProperty(EVERY_YEAR, false);
    addProperty(EVERY_MONTH, false);
}

DateMatchItem::DateMatchItem(const DateMatchItem &other)
    : ModelView::CompoundItem("dateMatchItem")
{
    addProperty(PERIODIC, other.periodic());
    addProperty(DAY, other.day());
    addProperty(DATE, other.date());
    addProperty(EVERY_YEAR, other.everyYear());
    addProperty(EVERY_MONTH, other.everyMonth());
}

QString DateMatchItem::periodic() const
{
    return property<QString>(PERIODIC);
}

void DateMatchItem::setPeriodic(const QString &periodic)
{
    setProperty(PERIODIC, periodic);
}

QString DateMatchItem::day() const
{
    return property<QString>(DAY);
}

void DateMatchItem::setDay(const QString &day)
{
    setProperty(DAY, day);
}

QString DateMatchItem::date() const
{
    return property<QString>(DATE);
}

void DateMatchItem::setDate(const QString &date)
{
    setProperty(DATE, date);
}

bool DateMatchItem::everyYear() const
{
    return property<bool>(EVERY_YEAR);
}

void DateMatchItem::setEveryYear(bool state)
{
    setProperty(EVERY_YEAR, state);
}

int DateMatchItem::everyMonth() const
{
    return property<int>(EVERY_MONTH);
}

void DateMatchItem::setEveryMonth(int everyMonth)
{
    setProperty(EVERY_MONTH, everyMonth);
}

}
