#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "coloritem.h"
#include<iostream>
using namespace std;


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
signals:
    void sendColor(vector<QColor>,vector<int>);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
