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
    dialog.setNameFilter(trUtf8("DICOM (*.dcm *.acr *.nema *.img);;Nifti (*.nii *.nii.gz *.img *.hdr);;PAR/REC (*.par *.rec);;Image (*.jpg *.jpeg *.png *.tif *.tiff *.gif)"));
    if (dialog.exec()) {
        filenames = dialog.selectedFiles();
        int numFiles = filenames.count();
        if (numFiles == 1)
            ui->lblNumSelectedFiles->setText(QString("%1 file selected").arg(numFiles));
        else
            ui->lblNumSelectedFiles->setText(QString("%1 files selected").arg(numFiles));
    }
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
