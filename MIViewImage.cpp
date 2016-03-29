#include "MIViewImage.h"

/* ---------------------------------------------- */
/* ---------- MIViewImage ----------------------- */
/* ---------------------------------------------- */
MIViewImage::MIViewImage()
{

}

/* ---------------------------------------------- */
/* ---------- ~MIViewImage ---------------------- */
/* ---------------------------------------------- */
MIViewImage::~MIViewImage()
{

}


/* ---------------------------------------------- */
/* ---------- SetFilenames ---------------------- */
/* ---------------------------------------------- */
void MIViewImage::SetFilenames(QStringList fnames) {
    filenames = fnames;
}


/* ---------------------------------------------- */
/* ---------- SetLoadParams --------------------- */
/* ---------------------------------------------- */
void MIViewImage::SetLoadParams(QHash<QString, int> params) {
    loadParams = params;
}


/* ---------------------------------------------- */
/* ---------- Load ------------------------------ */
/* ---------------------------------------------- */
QString MIViewImage::Load() {
    /* determine type */
    if (loadParams.value("typeauto")) {

    }
    else if (loadParams.value("typedicom")) {
        LoadDICOM();
    }
    return "";
}


/* ---------------------------------------------- */
/* ---------- LoadDICOM ------------------------- */
/* ---------------------------------------------- */
QString MIViewImage::LoadDICOM() {
    vtkSmartPointer<vtkStringArray> files = vtkSmartPointer<vtkStringArray>::New();
    files->SetNumberOfValues(filenames.count());
    for (int i=0; i< filenames.size(); i++) {
        files->SetValue(i,filenames.at(i).toLatin1().toStdString().c_str());
    }
    reader->SetFileNames(files);
    reader->Update();

    return "";
}
