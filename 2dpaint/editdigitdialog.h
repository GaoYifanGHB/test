#ifndef EDITDIGITDIALOG_H
#define EDITDIGITDIALOG_H

#include <QDialog>
#include"digit.h"
#include<QPainter>
#include<iostream>
using namespace std;

namespace Ui {
class EditDigitDialog;
}

class EditDigitDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditDigitDialog(QWidget *parent = 0);
    void setDigit(Digit d);
    void initGridSize(int l,int w);
    void drawOneGrid(int,int,QColor );
    ~EditDigitDialog();
protected:
    void paintEvent(QPaintEvent *event);
private:
    Digit d;
    int gridsize;
    Ui::EditDigitDialog *ui;
};

#endif // EDITDIGITDIALOG_H
