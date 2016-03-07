#ifndef MIVIEWIMAGE_H
#define MIVIEWIMAGE_H

#include <QStringList>

class MIViewImage
{
public:
    MIViewImage();
    ~MIViewImage();

    void SetFilenames(QStringList fnames);

private:
    QStringList filenames;

};

#endif // MIVIEWIMAGE_H
