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

#include "fileswidget.h"
#include "ui_fileswidget.h"

namespace mvvm_folders
{

enum ViewMode
{
    CREATE__MODE = 0,
    REPLACE_MODE = 1,
    UPDATE__MODE = 2,
    DELETE__MODE = 3
};

void FilesWidget::on_actionComboBox_currentIndexChanged(int index)
{
    bool createMode = false;
    bool deleteMode = false;
    switch (index)
    {
    case ViewMode::CREATE__MODE:
        createMode = true;
        break;
    case ViewMode::UPDATE__MODE:
    case ViewMode::REPLACE_MODE:
        break;
    case ViewMode::DELETE__MODE:
        deleteMode = true;
        break;
    default:
        break;
    }

    ui->supressErrorsCheckBox->setDisabled(createMode);

    ui->archive->setDisabled(deleteMode);
    ui->hidden->setDisabled(deleteMode);
    ui->readOnly->setDisabled(deleteMode);
    ui->sourceLineEdit->setDisabled(deleteMode);
    ui->sourceToolButton->setDisabled(deleteMode);

    if (deleteMode)
    {
        ui->sourceLineEdit->clear();
        ui->destinationLabel->setText(tr("Delete file(s):"));
    }
    else
    {
        ui->destinationLabel->setText(tr("Destination file:"));
    }
}

void FilesWidget::on_sourceToolButton_clicked()
{
    std::unique_ptr<QFileDialog> fileDialog = std::make_unique<QFileDialog>(this);

    fileDialog->setDirectory(QDir::homePath());
    fileDialog->setFileMode(QFileDialog::AnyFile);
    fileDialog->setSupportedSchemes(QStringList(QStringLiteral("file")));

    fileDialog->setLabelText(QFileDialog::Accept, tr("Open"));
    fileDialog->setLabelText(QFileDialog::FileName, tr("File name"));
    fileDialog->setLabelText(QFileDialog::LookIn, tr("Look in"));
    fileDialog->setLabelText(QFileDialog::Reject, tr("Cancel"));
    fileDialog->setLabelText(QFileDialog::FileType, tr("File type"));

    fileDialog->setNameFilter(QObject::tr("All files (*.*)"));
    fileDialog->setOptions(QFileDialog::DontResolveSymlinks | QFileDialog::DontUseNativeDialog);

    fileDialog->setWindowTitle(tr("Open Directory"));

    if (fileDialog->exec() == QDialog::Accepted)
    {
        ui->sourceLineEdit->setText(fileDialog->selectedUrls()[0].toLocalFile());
    }
}

void FilesWidget::on_destinationToolButton_clicked()
{
    std::unique_ptr<QFileDialog> fileDialog = std::make_unique<QFileDialog>(this);

    QFileDialog::Options options;
    if (fileMode)
    {
        fileDialog->setFileMode(QFileDialog::AnyFile);
        options = QFileDialog::DontResolveSymlinks | QFileDialog::DontUseNativeDialog;
    }
    else
    {
        fileDialog->setFileMode(QFileDialog::Directory);
        options = QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks | QFileDialog::DontUseNativeDialog;
    }

    fileDialog->setDirectory(QDir::homePath());
    fileDialog->setSupportedSchemes(QStringList(QStringLiteral("file")));

    fileDialog->setLabelText(QFileDialog::Accept, tr("Open"));
    fileDialog->setLabelText(QFileDialog::FileName, tr("File name"));
    fileDialog->setLabelText(QFileDialog::LookIn, tr("Look in"));
    fileDialog->setLabelText(QFileDialog::Reject, tr("Cancel"));
    fileDialog->setLabelText(QFileDialog::FileType, tr("File type"));

    fileDialog->setNameFilter(QObject::tr("All files (*.*)"));
    fileDialog->setOptions(options);

    fileDialog->setWindowTitle(tr("Open Directory"));

    if (fileDialog->exec() == QDialog::Accepted)
    {
        ui->destinationLineEdit->setText(fileDialog->selectedUrls()[0].toLocalFile());
    }
}

void FilesWidget::on_sourceLineEdit_textChanged(const QString &text)
{
    if (text.contains('*') || text.contains('?'))
    {
        fileMode = false;

        ui->destinationLabel->setText(tr("Destination folder:"));
    }
    else
    {
        fileMode = true;

        ui->destinationLabel->setText(tr("Destination file:"));
    }
}

void FilesWidget::submit()
{
    if (mapper && validate())
    {
        mapper->submit();

        emit dataChanged();
    }
}

}
