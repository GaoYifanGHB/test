#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "coloritem.h"
#include<iostream>
#include <QFileDialog>
#include"colorHandle/colorhandle.h"
using namespace std;


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    void addItem(int r,QColor color);
    void deleteItem(int i);
    ~Dialog();
signals:
    void sendColor(vector<QColor>,vector<int>);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();


    void on_radioButton_2_released();

    void on_radioButton_3_released();


    void on_radioButton_released();

    void on_radioButton_4_released();

    void on_radioButton_5_released();

    void on_pushButton_4_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
