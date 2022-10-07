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

#ifndef PREFERENCES_EDITOR_FILE_DIALOG_UTILS_H
#define PREFERENCES_EDITOR_FILE_DIALOG_UTILS_H

#include "gui.h"

#include <QDialog>

namespace Ui
{
class EditorPreferencesDialog;
}

namespace preferences_editor
{
class ISnapInManager;

class PREFERENCES_EDITOR_GUI_EXPORT EditorPreferencesDialog : public QDialog
{
    Q_OBJECT
public:
    // construction and destruction
    EditorPreferencesDialog(QWidget *parent = nullptr, ISnapInManager *manager = nullptr);
    ~EditorPreferencesDialog();

private:
    Ui::EditorPreferencesDialog *ui;

private:
    EditorPreferencesDialog(const EditorPreferencesDialog &) = delete;            // copy ctor
    EditorPreferencesDialog(EditorPreferencesDialog &&)      = delete;            // move ctor
    EditorPreferencesDialog &operator=(const EditorPreferencesDialog &) = delete; // copy assignment
    EditorPreferencesDialog &operator=(EditorPreferencesDialog &&) = delete;      // move assignment
};

} // namespace preferences_editor

#endif //PREFERENCES_EDITOR_FILE_DIALOG_UTILS_H
