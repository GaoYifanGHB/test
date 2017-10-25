#ifndef EDITDIGITDIALOG_H
#define EDITDIGITDIALOG_H

#include <QDialog>
#include"digit.h"
#include<QPainter>
#include<QMouseEvent>
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
    void setDigit(Digit d,int n);
    void initGridSize(int l,int w);
    void drawOneGrid(int,int,QColor );
    ~EditDigitDialog();
signals:
    void sendDigit(Digit,int);
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void on_buttonBox_accepted();

private:
    Digit d;
    int n;
    int toRX(int x);
    int toRY(int y);
    int gridsize;
    Ui::EditDigitDialog *ui;
};

#endif // EDITDIGITDIALOG_H
