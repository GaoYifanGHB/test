#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPainter>
#include<QPoint>
#include<cstdio>
#include"digitmananger.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void drawGrid(int len,int width,int height);
    void initGridSize(int l,int w,int h);
    void drawOneGrid(int x,int y,QColor color);
    void drawAllGrid(int xs, int ys,int xe,int ye, QColor color);
    DigitMananger dm;
    void test(int w, int l);
protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::Widget *ui;

    int gridsize;
};

#endif // WIDGET_H
