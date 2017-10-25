#ifndef SETSIZEDIALOG_H
#define SETSIZEDIALOG_H

#include <QDialog>

namespace Ui {
class setSizeDialog;
}

class setSizeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit setSizeDialog(QWidget *parent = 0);
    ~setSizeDialog();
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
signals:
    void sendSize(int,int,int);
private:
    Ui::setSizeDialog *ui;
};

#endif // SETSIZEDIALOG_H
