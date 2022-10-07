/***********************************************************************************************************************
**
** Copyright (C) 2022 BaseALT Ltd. <org@basealt.ru>
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

#ifndef MVVM_FOLDERS_SCRIPTS_POWER_SHELL_WIDGET_H
#define MVVM_FOLDERS_SCRIPTS_POWER_SHELL_WIDGET_H

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class ScriptsPowerShellWidget; }
QT_END_NAMESPACE

namespace preferences_editor
{

class ScriptsPowerShellWidget : public QWidget
{
public:
    Q_OBJECT
public:
    explicit ScriptsPowerShellWidget(QWidget *parent = nullptr);
    ~ScriptsPowerShellWidget();

private:
    ScriptsPowerShellWidget(const ScriptsPowerShellWidget&)            = delete;   // copy ctor
    ScriptsPowerShellWidget(ScriptsPowerShellWidget&&)                 = delete;   // move ctor
    ScriptsPowerShellWidget& operator=(const ScriptsPowerShellWidget&) = delete;   // copy assignment
    ScriptsPowerShellWidget& operator=(ScriptsPowerShellWidget&&)      = delete;   // move assignment

private:
    Ui::ScriptsPowerShellWidget* ui;
};

}

#endif//MVVM_FOLDERS_SCRIPTS_POWER_SHELL_WIDGET_H
