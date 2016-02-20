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

private slots:
    void on_buttonBox_2_accepted();

private:
    Ui::OpenFileDialog *ui;
};

#endif // OPENFILEDIALOG_H
