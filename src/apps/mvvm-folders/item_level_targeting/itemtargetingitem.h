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

#ifndef ITEMTARGETINGITEM_H
#define ITEMTARGETINGITEM_H

#include <mvvm/model/compounditem.h>

namespace mvvm_folders
{

//! Drives item representation for editor.

class ItemTargetingItem : public ModelView::CompoundItem
{
public:
    static inline const std::string NAME = "name";

    ItemTargetingItem();
    ItemTargetingItem(const ItemTargetingItem &other);
};

}

Q_DECLARE_METATYPE(::mvvm_folders::ItemTargetingItem)

#endif // ITEMTARGETINGITEM_H

------------------------------------

#ifndef MVVM_MODEL_GROUPITEM_H
#define MVVM_MODEL_GROUPITEM_H

#include "mvvm/model/sessionitem.h"
#include <vector>

namespace ModelView {

//! Group item holds collection of predefined items.
//! Intended for the inheritance.

class MVVM_MODEL_EXPORT GroupItem : public SessionItem {
public:
    static inline const std::string T_GROUP_ITEMS = "T_GROUP_ITEMS";

    ~GroupItem() override;

    int currentIndex() const;

    const SessionItem* currentItem() const;
    SessionItem* currentItem();

    std::string currentType() const;
    void setCurrentType(const std::string& model_type);

protected:
    GroupItem(model_type modelType);
    void setCurrentIndex(int index);
    template <typename T> void addToGroup(const std::string& text = {}, bool make_selected = false);
    void updateCombo();

    int m_index_to_select;
    std::vector<std::string> m_item_text;
};

//! Adds an item of a given type to the group.
//! @param 'text' defines a text to be shown in ComboEditor when selecting an item in a group.
//! @param make_selected defines whether the item should be selected by default.
template <typename T> void GroupItem::addToGroup(const std::string& text, bool make_selected)
{
    m_item_text.push_back(text.empty() ? T().modelType() : text);
    insertItem<T>(TagRow::append(T_GROUP_ITEMS));
    if (make_selected)
        m_index_to_select = m_item_text.size() - 1;
    updateCombo();
}

} // namespace ModelView

#endif // MVVM_MODEL_GROUPITEM_H
