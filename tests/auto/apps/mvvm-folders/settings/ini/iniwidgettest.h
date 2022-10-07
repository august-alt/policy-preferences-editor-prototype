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

#ifndef MVVM_FOLDERS_INIWIDGET_WIDGET_TEST_H
#define MVVM_FOLDERS_INIWIDGET_WIDGET_TEST_H

#include <QtTest>

#include <memory>

namespace mvvm_folders
{
    class IniWidget;
}

namespace tests
{
    class IniWidgetTest : public QObject
    {
        Q_OBJECT

    private:
        std::unique_ptr<mvvm_folders::IniWidget> readXmlFile(const QString& dataPath);

    private slots:
        void displayWidgetTest();

        void propertyTest();
        void propertyTest_data();

        void actionStateTest();
        void actionStateTest_data();
    };
}

#endif//MVVM_FOLDERS_INIWIDGET_WIDGET_TEST_H

