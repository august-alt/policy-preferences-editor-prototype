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

#ifndef PREFERENCES_EDITOR_MAINWINDOW_H
#define PREFERENCES_EDITOR_MAINWINDOW_H

#include "gui.h"

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

namespace model
{
namespace registry
{
class AbstractRegistrySource;
class Registry;
} // namespace registry
} // namespace model

namespace preferences_editor
{
class CommandLineOptions;
class MainWindowPrivate;
class ISnapInManager;

class PREFERENCES_EDITOR_GUI_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // construction and destruction
    MainWindow(CommandLineOptions &options, QWidget *parent = 0, ISnapInManager *manager = 0);
    ~MainWindow();

    void setLanguage(const QString &language);
    QString getLanguage() const;

    void setAdmxPath(const QString &admxPath);
    QString getAdmxPath() const;

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_actionManual_triggered();

private:
    MainWindowPrivate *const d;

    Ui::MainWindow *ui;

private slots:
    void onDirectoryOpen();
    void onRegistrySourceSave();

    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_actionPreferences_triggered();

    void onLanguageChanged(QAction *action);

private:
    void onIniFileOpen(const QString &path);

    void loadPolicyBundleFolder(const QString &path, const QString &locale);

    void createLanguageMenu();

private:
    MainWindow(const MainWindow &) = delete;            // copy ctor
    MainWindow(MainWindow &&)      = delete;            // move ctor
    MainWindow &operator=(const MainWindow &) = delete; // copy assignment
    MainWindow &operator=(MainWindow &&) = delete;      // move assignment
};
} // namespace preferences_editor

#endif // PREFERENCES_EDITOR_MAINWINDOW_H
