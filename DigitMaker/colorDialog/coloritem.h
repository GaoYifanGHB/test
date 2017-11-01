#ifndef COLORITEM_H
#define COLORITEM_H

#include <QWidget>
#include<QRect>
#include<QMouseEvent>
#include <QPainter>
#include<QColorDialog>
#include<iostream>
using namespace std;

namespace Ui {
class ColorItem;
}

class ColorItem : public QWidget
{
    Q_OBJECT
    
public:
    explicit ColorItem(QWidget *parent = 0);
    QColor color;
    QRect rect;
    void setData(int num,QColor color);
    int getNum();
    ~ColorItem();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
private:
    Ui::ColorItem *ui;
};

#endif // COLORITEM_H
