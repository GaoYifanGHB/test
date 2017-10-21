#include "widget.h"
#include "ui_widget.h"
#include<QThread>
//#include<QtTest/QTest>
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


//画出网格
void Widget::test(int w, int l)
{
    dm.initAll();
    dm.addDigitToRect(-(w/2),-l/2,(w/2),l/2);
    dm.printCheck(-(w/2),-l/2,(w/2)+1,l/2+1);
    vector<QColor>cls;
    cls.push_back(QColor(180,0,90));
    cls.push_back(QColor(0,255,0));
    cls.push_back(QColor(0,155,0));
    vector<int>rls;
    rls.push_back(1);
    rls.push_back(1);
    rls.push_back(1);
    dm.setColorList(cls);
    dm.setColorRatio(rls);
    dm.drawAllDigltColor();
    drawAllGrid(-(w/2),-l/2,(w/2),l/2,QColor(0,155,0));
    cout<<"着色"<<endl;
    vector<Digit> ds=dm.getDigitList();
    for(int i=0;i<ds.size();i++){
        for(int j=0;j<ds[i].getLength();j++){
            for(int k=0;k<ds[i].getWidth();k++){
                if(ds[i].mat[j][k]){
                    drawOneGrid(ds[i].getLocationX()+j,ds[i].getLocationY()+k,ds[i].getColor());
//                    QThread::sleep(100);
//                    QTest::qWait(10);
                }
            }
        }
    }
    cout<<"完成"<<endl;
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
    drawOneGrid(0,0,Qt::red);
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
    int l=700;
    int w=800;
    int h=100;

    drawGrid(l,w,h);
}

void Widget::drawOneGrid(int x, int y, QColor color)
{
    QPainter *painters=new QPainter(this);
    int cl=height()/2;
    int cw=width()/2;
    painters->fillRect(QRect(QPoint(cw+(x-1)*gridsize,cl+(y-1)*gridsize),QPoint(cw+(x)*gridsize,cl+(y)*gridsize)), QBrush(color));

}
void Widget::drawAllGrid(int xs, int ys,int xe,int ye, QColor color)
{
    QPainter *painters=new QPainter(this);
    int cl=height()/2;
    int cw=width()/2;
    painters->fillRect(QRect(QPoint(cw+xs*gridsize,cl+ys*gridsize),QPoint(cw+(xe+1)*gridsize,cl+(ye+1)*gridsize)), QBrush(color));

}

