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

#ifndef MVVM_FOLDERS_SCHEDULECONDITIONSWIN7_WIDGET_H
#define MVVM_FOLDERS_SCHEDULECONDITIONSWIN7_WIDGET_H

#include "interfaces/preferenceswidgetinterface.h"

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class ScheduleConditionsWin7Widget; }
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

class ScheduleConditionsWin7Item;

//! ScheduleConditionsWin7 representation for editor.

class ScheduleConditionsWin7Widget : public PreferenceWidgetInterface
{
public:
    Q_OBJECT

public:
    explicit ScheduleConditionsWin7Widget(QWidget* parent = nullptr, ScheduleConditionsWin7Item* item = nullptr);
    ~ScheduleConditionsWin7Widget() override;

    void setItem(ModelView::SessionItem *item) override;

    bool validate() override;

public slots:
    void submit() override;

private slots:
    void on_actionComboBox_currentIndexChanged(int index);

private:
    ScheduleConditionsWin7Widget(const ScheduleConditionsWin7Widget&)            = delete;   // copy ctor
    ScheduleConditionsWin7Widget(ScheduleConditionsWin7Widget&&)                 = delete;   // move ctor
    ScheduleConditionsWin7Widget& operator=(const ScheduleConditionsWin7Widget&) = delete;   // copy assignment
    ScheduleConditionsWin7Widget& operator=(ScheduleConditionsWin7Widget&&)      = delete;   // move assignment

private:
    //!< Underlying item of this view.
    ScheduleConditionsWin7Item* m_item {nullptr};

    std::unique_ptr<ModelView::ViewModel> view_model;
    std::unique_ptr<ModelView::ViewModelDelegate> delegate;
    std::unique_ptr<QDataWidgetMapper> mapper;

private:
    Ui::ScheduleConditionsWin7Widget *ui {nullptr};
};

}

#endif//MVVM_FOLDERS_SCHEDULECONDITIONSWIN7_WIDGET_H

