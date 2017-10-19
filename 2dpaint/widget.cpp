#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


//»­³öÍø¸ñ
void Widget::drawGrid(int l, int w, int h)
{
    l/=10;
    w/=10;
    h/=10;
    QPainter painters(this);
    int cl=height()/2;
    int cw=width()/2;
    for(int i=-l/2-h;i<=l/2+h;i++){
        if(i>=-l/2&&i<=l/2){
            painters.drawLine(QPoint(cw-(w/2+h)*gridsize,cl+i*gridsize),QPoint(cw+(w/2+h)*gridsize,cl+i*gridsize));
        }else{
            painters.drawLine(QPoint(cw-w/2*gridsize,cl+i*gridsize),QPoint(cw+w/2*gridsize,cl+i*gridsize));
        }
    }
    for(int i=-w/2-h;i<=w/2+h;i++){
        if(i>=-w/2&&i<=w/2){
            painters.drawLine(QPoint(cw+i*gridsize,cl-(l/2+h)*gridsize),QPoint(cw+i*gridsize,cl+(l/2+h)*gridsize));
        }else{
            painters.drawLine(QPoint(cw+i*gridsize,cl-(l/2)*gridsize),QPoint(cw+i*gridsize,cl+(l/2)*gridsize));
        }

    }
}

void Widget::initGridSize(int l,int w,int h)
{
    int m=l>w?l:w;
    m+=2*h;
    l=height()>width()?height():width();
    gridsize=l/m*10;
}



void Widget::paintEvent(QPaintEvent *event){
//    gridsize=height()/50;

    int l=500;
    int w=800;
    int h=100;
    initGridSize(l,w,h);
    printf("³¤£º%d\n",height());
    printf("¿í£º%d\n",width());
    drawGrid(l,w,h);
}
