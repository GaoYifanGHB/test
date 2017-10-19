#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPainter>
#include<QPoint>
#include<cstdio>


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
protected:
    void paintEvent(QPaintEvent *);


private:
    Ui::Widget *ui;
    int gridsize;
};

#endif // WIDGET_H
