#include "mainwindow.h"
#include "ui_mainwindow.h"


/* ---------------------------------------------- */
/* ---------- MainWindow ------------------------ */
/* ---------------------------------------------- */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //renderer = vtkSmartPointer<vtkRenderer>::New();
    imageViewer = vtkSmartPointer<vtkImageViewer2>::New();

    renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    imageViewer->SetupInteractor(renderWindowInteractor);

    // VTK/Qt wedded
    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderWindowInteractor);
}


/* ---------------------------------------------- */
/* ---------- ~MainWindow ----------------------- */
/* ---------------------------------------------- */
MainWindow::~MainWindow()
{
    delete ui;
}


/* ---------------------------------------------- */
/* ---------- on_mnuFileExit_triggered ---------- */
/* ---------------------------------------------- */
void MainWindow::on_mnuFileExit_triggered()
{
    exit(0);
}


/* ---------------------------------------------- */
/* ---------- on_action_Open_triggered ---------- */
/* ---------------------------------------------- */
void MainWindow::on_action_Open_triggered()
{
    LoadImage();
}


/* ---------------------------------------------- */
/* ---------- on_btnAddImage_clicked ------------ */
/* ---------------------------------------------- */
void MainWindow::on_btnAddImage_clicked()
{
    LoadImage();
}


/* ---------------------------------------------- */
/* ---------- LoadImage ------------------------- */
/* ---------------------------------------------- */
void MainWindow::LoadImage() {
    OpenFileDialog *fileOpen = new OpenFileDialog(this);
    if (fileOpen->exec()) {
        /* check if they actually selected any filenames */
        QStringList filenames = fileOpen->GetFilenames();
        if (filenames.count() > 0) {
            /* get the loading parameters */
            QHash<QString, int> loadParams = fileOpen->GetLoadParams();
            MIViewImage *img = new MIViewImage();
            img->SetFilenames(filenames);
            img->SetLoadParams(loadParams);
            images.append(*img);

            /* try to load the image */
            QString msg = images.last().Load();

            /* now render the image on the vtkImageViewer */
            imageViewer->SetInputConnection(images.last().reader->GetOutputPort());
            imageViewer->Render();
            imageViewer->GetRenderer()->ResetCamera();
            imageViewer->Render();

            renderWindowInteractor->Start();
        }
    }
}
