#ifndef EDITDIGIT_H
#define EDITDIGIT_H

#include <QWidget>
#include "digit.h"
#include <QPainter>
#include <QColor>
#include <iostream>
using namespace std;
namespace Ui {
class EditDigit;
}

class EditDigit : public QWidget
{
    Q_OBJECT
    
public:
    explicit EditDigit(QWidget *parent = 0);
//    explicit EditDigit(QWidget *parent = 0,Digit d);
    void setDigit(Digit d);
    void initGridSize(int l,int w);
    void drawOneGrid(int,int,QColor );
    ~EditDigit();
protected:
     void paintEvent(QPaintEvent *event);
private:
    Ui::EditDigit *ui;
    Digit d;
    int gridsize;
};

#endif // EDITDIGIT_H
