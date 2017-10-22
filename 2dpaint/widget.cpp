#include "widget.h"
#include "ui_widget.h"
#include<QThread>
//#include<QtTest/QTest>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    f=true;
}

Widget::~Widget()
{
    delete ui;
}


//画出网格
void Widget::test(int w, int l)
{
    if(f){
        dm.initAll();
        dm.addDigitToRect(-(w/2),-l/2,(w/2)-1,l/2-1);
        vector<QColor>cls;
        cls.push_back(QColor(110,110,110));
        cls.push_back(QColor(70,60,30));
        cls.push_back(QColor(40,40,40));
        cls.push_back(QColor(40,70,40));
        vector<int>rls;
        rls.push_back(3);
        rls.push_back(2);
        rls.push_back(2);
        rls.push_back(5);
        dm.setColorList(cls);
        dm.setColorRatio(rls);
        dm.drawAllDigltColor();
        dm.showAll(w,l);

    }
    drawAllGrid(-(w/2),-l/2,(w/2)-1,l/2-1,QColor(40,70,40));
    f=false;
    cout<<"着色"<<endl;
    vector<Digit> ds=dm.getDigitList();
    for(int i=0;i<ds.size();i++){
        for(int j=0;j<ds[i].getLength();j++){
            for(int k=0;k<ds[i].getWidth();k++){
                if(ds[i].mat[j][k]){
                    drawOneGrid(ds[i].getLocationX()+k,ds[i].getLocationY()+j,ds[i].getColor());
                }

            }
        }
    }
}



void Widget::drawGrid(int l, int w, int h)
{
    QPainter painters(this);
    QPainter painters1(this);
    //    cout<<"huaxian"<<endl;
    initGridSize(l,w,h);
    l/=10;
    w/=10;
    h/=10;
    int cl=height()/2;
    int cw=width()/2;
    test(w,l);

//    drawOneGrid(0,0,Qt::red);
    //画横线
    for(int i=-l/2-h;i<=l/2+h;i++){
        if(i>=-l/2&&i<=l/2){
            painters.drawLine(QPoint(cw-(w/2+h)*gridsize,cl+i*gridsize),QPoint(cw+(w/2+h)*gridsize,cl+i*gridsize));
        }else{
            painters.drawLine(QPoint(cw-w/2*gridsize,cl+i*gridsize),QPoint(cw+w/2*gridsize,cl+i*gridsize));
        }
    }
    //画竖线
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
    double m=l>w?l:w;
    m+=2*h;
    double n=height()>width()?height():width();
    n*=0.9;
    gridsize=(int)(n/m*10.0);
}

void Widget::paintEvent(QPaintEvent *event){
    int l=1200;
    int w=1500;
    int h=100;

    drawGrid(l,w,h);
}

void Widget::drawOneGrid(int x, int y, QColor color)
{
    QPainter *painters=new QPainter(this);
    int cl=height()/2;
    int cw=width()/2;
    painters->fillRect(QRect(QPoint(cw+(x)*gridsize,cl+(y)*gridsize),QPoint(cw+(x+1)*gridsize,cl+(y+1)*gridsize)), QBrush(color));

}
void Widget::drawAllGrid(int xs, int ys,int xe,int ye, QColor color)
{
    QPainter *painters=new QPainter(this);
    int cl=height()/2;
    int cw=width()/2;
    painters->fillRect(QRect(QPoint(cw+xs*gridsize,cl+ys*gridsize),QPoint(cw+(xe+1)*gridsize,cl+(ye+1)*gridsize)), QBrush(color));

}

