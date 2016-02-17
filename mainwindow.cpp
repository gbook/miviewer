#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MIViewImage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mnuFileExit_triggered()
{
    exit(0);
}

void MainWindow::on_action_Open_triggered()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open DICOM/ACR/NEMA"), "", tr("DICOM files (*.dcm *.acr *.dicom *.IMG *.nema)"));

}
