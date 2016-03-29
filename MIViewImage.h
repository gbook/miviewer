#ifndef MIVIEWIMAGE_H
#define MIVIEWIMAGE_H

#include <QStringList>
#include <QList>
#include <QHash>
#include <vtkSmartPointer.h>
#include <vtkStringArray.h>
#include <vtkDICOMImageReader.h>

class MIViewImage
{
public:
    MIViewImage();
    ~MIViewImage();

    void SetFilenames(QStringList fnames);
    void SetLoadParams(QHash<QString, int> params);
    QString Load();
    vtkSmartPointer<vtkDICOMImageReader> reader = vtkSmartPointer<vtkDICOMImageReader>::New();

private:
    QStringList filenames;
    QHash<QString, int> loadParams;
    QString LoadDICOM();
};

#endif // MIVIEWIMAGE_H
