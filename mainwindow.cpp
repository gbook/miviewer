#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    OpenFileDialog *fileOpen = new OpenFileDialog(this);
    if (fileOpen->exec()) {
        QStringList filenames = fileOpen->GetFilenames();
        if (filenames.count() > 0) {
            MIViewImage *img = new MIViewImage();
            img->SetFilenames(filenames);
            images.append(*img);
        }
    }
}

void MainWindow::on_btnAddImage_clicked()
{
    OpenFileDialog *fileOpen = new OpenFileDialog(this);
    if (fileOpen->exec()) {
        QStringList filenames = fileOpen->GetFilenames();
    }
}
