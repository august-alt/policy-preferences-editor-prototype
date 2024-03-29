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

#include "vpnwidget.h"
#include "ui_vpnwidget.h"

namespace mvvm_folders
{

enum ViewMode
{
    CREATE__MODE = 0,
    REPLACE_MODE = 1,
    UPDATE__MODE = 2,
    DELETE__MODE = 3
};

void VpnWidget::on_actionComboBox_currentIndexChanged(int index)
{
    bool deleteMode = (index == ViewMode::DELETE__MODE);

    ui->ipaddressLabel->setDisabled(deleteMode);
    ui->ipaddressLineEdit->setDisabled(deleteMode);

    ui->useDnsCheckBox->setDisabled(deleteMode);
    ui->firstConnectGroupBox->setDisabled(deleteMode);
    ui->showIconCheckBox->setDisabled(deleteMode);
}
}
