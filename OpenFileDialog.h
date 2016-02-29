#ifndef OPENFILEDIALOG_H
#define OPENFILEDIALOG_H

#include <QDialog>

namespace Ui {
class OpenFileDialog;
}

class OpenFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenFileDialog(QWidget *parent = 0);
    ~OpenFileDialog();

    QStringList GetFilenames();

    QStringList filenames;

private slots:
    void on_btnSelectFiles_clicked();

    void on_btnDialogs_accepted();

    void on_btnDialogs_rejected();

private:
    Ui::OpenFileDialog *ui;
};

#endif // OPENFILEDIALOG_H
