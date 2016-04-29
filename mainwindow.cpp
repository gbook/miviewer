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

    renderer = vtkSmartPointer<vtkRenderer>::New();
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
    cout<<"Hi there!"<<endl;
    LoadImage();
}


/* ---------------------------------------------- */
/* ---------- LoadImage ------------------------- */
/* ---------------------------------------------- */
void MainWindow::LoadImage() {
    cout<<"TestingA"<<endl;
    OpenFileDialog *fileOpen = new OpenFileDialog(this);
    if (fileOpen->exec() == QDialog::Accepted) {
        cout<<"TestingB"<<endl;
        /* check if they actually selected any filenames */
        QStringList filenames = fileOpen->GetFilenames();
        if (filenames.count() > 0) {
            cout<<"TestingC"<<endl;
            /* get the loading parameters */
            QHash<QString, int> loadParams = fileOpen->GetLoadParams();
            MIViewImage *img = new MIViewImage();
            img->SetFilenames(filenames);
            img->SetLoadParams(loadParams);
            images.append(*img);
            cout<<"TestingC.1"<<endl;

            /* try to load the image */
            QString msg = images.last().Load();

            /* now render the image on the vtkImageViewer */
            imageViewer = vtkSmartPointer<vtkImageViewer2>::New();
            imageViewer->SetInputConnection(images.last().reader->GetOutputPort());
            imageViewer->Render();
            imageViewer->GetRenderer()->ResetCamera();
            imageViewer->Render();
            cout<<"TestingC.2"<<endl;

            imageViewer->GetRenderWindow()->GetInteractor()->Start();
            //renderWindowInteractor->Start();

            cout<<"TestingC.3"<<endl;

            // VTK/Qt wedded
            ui->qvtkWidget->SetRenderWindow(imageViewer->GetRenderWindow());
            imageViewer->SetupInteractor(ui->qvtkWidget->GetInteractor());
            cout<<"TestingC.4"<<endl;

            ui->qvtkWidget->show();
            cout<<"TestingD"<<endl;
        }
    }
    else {
        cout<<"File dialog not successful?"<<endl;
    }
}
