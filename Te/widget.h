#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPainter>
#include<QPoint>
#include<cstdio>
#include"editdigitdialog.h"
#include<QMouseEvent>
#include"digitmananger.h"
#include<QMessageBox>



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    //定义当前操作
    const static int NORMAL = 0;
    const static int EDITDIGIT   = 1;
    const static int  MOVEDIGIT = 2;
    int handleState;


    explicit Widget(QWidget *parent = 0);
    ~Widget();
    EditDigitDialog *edg;
    bool f;
    //画出坐标格
    void drawGrid();
    //初始化做表格长度
    void initGridSize();
    //画一个坐标为x,y的方格
    void drawOneGrid(int x,int y,QColor color);
    //在一个举行区域上画出图上颜色
    void drawAllGrid(int xs, int ys,int xe,int ye, QColor color);
    //在生成一个矩形区域的数码小块
    void drawDigitRect();
    //数码小块管理类
    DigitMananger dm;
    //设置生成数码迷彩的长宽高
    void setSize(int l,int w,int h);
    //设置颜色队列与比例
    void setColors(vector<QColor>cls,vector<int>rs);
    //设置窗口要进行的操作
    void setHandleState(int handleState);
    //根据已经设置的条件创建数码迷彩
    void createDigitMap();
public slots:
    void getDigit(Digit,int);
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void wheelEvent(QWheelEvent *event);


private:
    Ui::Widget *ui;
    //颜色队列
    vector<QColor>cls;
    //颜色比例队列
    vector<int>rls;
    //由绝对坐标获得相对坐标
    int toRX(int x);
    int toRY(int y);

    int dx;
    int dy;

    int gridsize;
    //图形的长宽高
    int h;
    int l;
    int w;


    //移动过程中正在操作的小块编号
    int moveNum;
};

#endif // WIDGET_H
