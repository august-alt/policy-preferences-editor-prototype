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

#ifndef MVVM_FOLDERS_STARTWINXP_WIDGET_H
#define MVVM_FOLDERS_STARTWINXP_WIDGET_H

#include "interfaces/preferenceswidgetinterface.h"

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class StartWinXpWidget; }
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

class StartWinXpItem;

//! StartWinXp representation for editor.

class StartWinXpWidget : public PreferenceWidgetInterface
{
public:
    Q_OBJECT

public:
    explicit StartWinXpWidget(QWidget* parent = nullptr, StartWinXpItem* item = nullptr);
    ~StartWinXpWidget() override;

    void setItem(ModelView::SessionItem *item) override;

    bool validate() override;

public slots:
    void submit() override;

private slots:
    void on_actionComboBox_currentIndexChanged(int index);

private:
    StartWinXpWidget(const StartWinXpWidget&)            = delete;   // copy ctor
    StartWinXpWidget(StartWinXpWidget&&)                 = delete;   // move ctor
    StartWinXpWidget& operator=(const StartWinXpWidget&) = delete;   // copy assignment
    StartWinXpWidget& operator=(StartWinXpWidget&&)      = delete;   // move assignment

private:
    //!< Underlying item of this view.
    StartWinXpItem* m_item {nullptr};

    std::unique_ptr<ModelView::ViewModel> view_model;
    std::unique_ptr<ModelView::ViewModelDelegate> delegate;
    std::unique_ptr<QDataWidgetMapper> mapper;

private:
    Ui::StartWinXpWidget *ui {nullptr};
};

}

#endif//MVVM_FOLDERS_STARTWINXP_WIDGET_H

