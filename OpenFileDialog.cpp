#include "OpenFileDialog.h"
#include "ui_openfiledialog.h"
#include <QFileDialog>

OpenFileDialog::OpenFileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenFileDialog)
{
    ui->setupUi(this);
}

OpenFileDialog::~OpenFileDialog()
{
    delete ui;
}

QStringList OpenFileDialog::GetFilenames() {
    return filenames;
}

void OpenFileDialog::on_btnSelectFiles_clicked()
{
    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter(trUtf8("DICOM (*.dcm *.acr *.nema *.img)"));
    if (dialog.exec())
        filenames = dialog.selectedFiles();
}

void OpenFileDialog::on_btnDialogs_accepted()
{
    this->close();
}

void OpenFileDialog::on_btnDialogs_rejected()
{
    filenames.clear();
    this->close();
}
