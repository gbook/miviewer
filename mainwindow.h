#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QList>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include "MIViewImage.h"
#include "OpenFileDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /* list of images */
    QList<MIViewImage> images;

private slots:
    void on_mnuFileExit_triggered();

    void on_action_Open_triggered();

    void on_btnAddImage_clicked();

private:
    Ui::MainWindow *ui;

    void LoadImage();
};

#endif // MAINWINDOW_H
