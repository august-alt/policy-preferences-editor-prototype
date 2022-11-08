#ifndef ITEMTARGETINGCONTAINERITEM_H
#define ITEMTARGETINGCONTAINERITEM_H

#include <mvvm/model/compounditem.h>
#include <mvvm/model/sessionitemcontainer.h>
#include <mvvm/model/sessionitemtags.h>
#include <mvvm/model/taginfo.h>

namespace mvvm_folders
{

class ItemTargetingItem;

class ItemTargetingComtainerItem : public ModelView::CompoundItem
{
public:
    static inline const std::string ITEMS = "ITEMS";
    static inline const std::string ITEM_TARGET_ITEM = "ItemTargetItem";

    ItemTargetingComtainerItem()
        : ModelView::CompoundItem("ItemTargetingComtainerItem")
    {
        registerTag(ModelView::TagInfo::universalTag(ITEMS, {ITEM_TARGET_ITEM}), true);
    }

    ItemTargetingComtainerItem(const ItemTargetingComtainerItem&)
        : ModelView::CompoundItem("ItemTargetingComtainerItem")
    {
        registerTag(ModelView::TagInfo::universalTag(ITEMS, {ITEM_TARGET_ITEM}), true);
    }
     ItemTargetingComtainerItem* getMembers() const;
};

}

Q_DECLARE_METATYPE(::mvvm_folders::ItemTargetingComtainerItem)

#endif // ITEMTARGETINGCONTAINERITEM_H
