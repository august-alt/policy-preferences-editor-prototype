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

#ifndef MVVM_FOLDERS_DATEMATCH_ITEM_H
#define MVVM_FOLDERS_DATEMATCH_ITEM_H

#include <mvvm/model/compounditem.h>

namespace mvvm_folders
{

//! DateMatch item representation for editor.

class DateMatchItem : public ModelView::CompoundItem
{
public:
    static inline const std::string PERIODIC = "periodic";
    static inline const std::string DAY = "day";
    static inline const std::string DATE = "date";
    static inline const std::string EVERY_YEAR = "everyYear";
    static inline const std::string EVERY_MONTH = "everyMonth";

    DateMatchItem();
    DateMatchItem(const DateMatchItem &other);

    QString periodic() const;
    void setPeriodic(const QString& periodic);

    QString day() const;
    void setDay(const QString& day);

    QString date() const;
    void setDate(const QString& date);

    bool everyYear() const;
    void setEveryYear(bool state);

    int everyMonth() const;
    void setEveryMonth(int everyMonth);
};

}

Q_DECLARE_METATYPE(::mvvm_folders::DateMatchItem)

#endif//MVVM_FOLDERS_DATEMATCH_ITEM_H
