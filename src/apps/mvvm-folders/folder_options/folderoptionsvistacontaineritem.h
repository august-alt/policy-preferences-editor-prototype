#ifndef FOLDEROPTIONSVISTACONTAINERITEM_H
#define FOLDEROPTIONSVISTACONTAINERITEM_H

#include <mvvm/model/compounditem.h>

#include "interfaces/containeriteminterface.h"

namespace mvvm_folders
{

class CommonItem;
class BaseNetworkItem;

template <typename FolderOptionVistaItem>
class FolderOptionsVistaContainerItem : public ModelView::CompoundItem, public ContainerItemInterface
{
public:
    static inline const std::string NAME = "name";
    static inline const std::string ORDER = "order";
    static inline const std::string ACTION = "action";
    static inline const std::string ASSOCIATION = "association";

    static inline const std::string COMMON        = "common";
    static inline const std::string FOLDER_OPTION = "network";

    explicit FolderOptionsVistaContainerItem();

    CommonItem* getCommon() const;
    void setCommon(const CommonItem& item);

    FolderOptionVistaItem* getFolderOption() const;
    void setFolderOption(const FolderOptionVistaItem &item);

    void setupListeners() override;
};

}

#include "folderoptionsvistacontaineritem.inl"

#endif // FOLDEROPTIONSVISTACONTAINERITEM_H
