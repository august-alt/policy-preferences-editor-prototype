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

#ifndef MVVM_FOLDERS_STARTADVANCEDWINXP_WIDGET_H
#define MVVM_FOLDERS_STARTADVANCEDWINXP_WIDGET_H

#include "interfaces/preferenceswidgetinterface.h"

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class StartAdvancedWinXPWidget; }
QT_END_NAMESPACE

class QDataWidgetMapper;

namespace ModelView
{
    class ViewModel;
    class ViewModelDelegate;
    class SessionItem;
}

namespace mvvm_folders
{

class StartAdvancedWinXpItem;

//! StartAdvancedWinXp representation for editor.

class StartAdvancedWinXPWidget : public PreferenceWidgetInterface
{
public:
    Q_OBJECT

public:
    explicit StartAdvancedWinXPWidget(QWidget* parent = nullptr, StartAdvancedWinXpItem* item = nullptr);
    ~StartAdvancedWinXPWidget() override;

    void setItem(ModelView::SessionItem *item) override;

    bool validate() override;

public slots:
    void submit() override;

private slots:
    void on_actionComboBox_currentIndexChanged(int index);

private:
    StartAdvancedWinXPWidget(const StartAdvancedWinXPWidget&)            = delete;   // copy ctor
    StartAdvancedWinXPWidget(StartAdvancedWinXPWidget&&)                 = delete;   // move ctor
    StartAdvancedWinXPWidget& operator=(const StartAdvancedWinXPWidget&) = delete;   // copy assignment
    StartAdvancedWinXPWidget& operator=(StartAdvancedWinXPWidget&&)      = delete;   // move assignment

private:
    //!< Underlying item of this view.
    StartAdvancedWinXpItem* m_item {nullptr};

    std::unique_ptr<ModelView::ViewModel> view_model;
    std::unique_ptr<ModelView::ViewModelDelegate> delegate;
    std::unique_ptr<QDataWidgetMapper> mapper;

private:
    Ui::StartAdvancedWinXPWidget *ui {nullptr};
};

}

#endif//MVVM_FOLDERS_STARTADVANCEDWINXP_WIDGET_H

