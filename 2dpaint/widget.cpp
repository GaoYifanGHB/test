#include "widget.h"
#include "ui_widget.h"
#include<QThread>
//#include<QtTest/QTest>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setSize(800,1000,200);
    handleState=EDITDIGIT;
    init();

}

Widget::~Widget()
{
    delete ui;
}



void Widget::init()
{
    dm.addDigitToRect(-(w/2),-l/2,(w/2)-1,l/2-1);
    dm.addDigitToRect(-(w/2),-l/2-h,(w/2)-1,-l/2-1);
    dm.addDigitToRect(-(w/2)-h,-l/2,-(w/2)-1,l/2-1);
    dm.addDigitToRect(-(w/2),l/2,(w/2)-1,l/2-1+h);
    dm.addDigitToRect((w/2),-l/2,(w/2)+h-1,l/2-1);
    cls.push_back(QColor(110,110,110));
    cls.push_back(QColor(70,60,30));
    cls.push_back(QColor(40,40,40));
    cls.push_back(QColor(7,75,60));
    rls.push_back(3);
    rls.push_back(3);
    rls.push_back(3);
    rls.push_back(3);
    dm.setColorList(cls);
    dm.setColorRatio(rls);
    dm.drawAllDigltColor();
}

void Widget::getDigit(Digit d,int n)
{
    //    cout<<n<<"-----00000=========="<<d.getNum()<<endl;
    dm.rebuildDigit(d,n);
    this->update();
    //    dm.getDigitList()
}
//画出网格
void Widget::drawDigitRect()
{
    drawAllGrid(-(w/2),-l/2,(w/2)-1,l/2-1,cls[cls.size()-1]);
    drawAllGrid(-(w/2),-l/2-h,(w/2)-1,-l/2-1,cls[cls.size()-1]);
    drawAllGrid(-(w/2)-h,-l/2,-(w/2)-1,l/2-1,cls[cls.size()-1]);
    drawAllGrid(-(w/2),l/2,(w/2)-1,l/2-1+h,cls[cls.size()-1]);
    drawAllGrid((w/2),-l/2,(w/2)+h-1,l/2-1,cls[cls.size()-1]);
    //    cout<<"着色"<<endl;
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
    //    cout<<"板块数量："<<ds.size()<<endl;
}
//---------------------设置初始参数-------------------------
//长宽高
void Widget::setSize(int l, int w, int h)
{
    this->l=l/10;
    this->w=w/10;
    this->h=h/10;
    initGridSize();
}
void Widget::initGridSize()
{
    double m=l>w?l:w;
    m+=2*h;
    double n=height()<width()?height():width();
    gridsize=(int)(n/m*1.2);
}
//颜色及比例
void Widget::setColors(vector<QColor> cls, vector<int> rs)
{
    this->cls=cls;
    this->rls=rs;
}
//----------------------------------------------------------



//-------------------画出网格--------------------------------
void Widget::drawGrid()
{
    QPainter painters(this);
    int cl=height()/2;
    int cw=width()/2;
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

void Widget::paintEvent(QPaintEvent *event){
    initGridSize();
    drawGrid();
    drawDigitRect();
}


void Widget::mousePressEvent(QMouseEvent *event)
{
    int x=toRX(event->x());
    int y=toRY(event->y());
    int i=dm.getDigitLocal(x,y);
    if(handleState==EDITDIGIT){
        if(i!=-1){
            edg=new EditDigitDialog(this);
            edg->setDigit(dm.getDigitList()[i],i);
            connect(edg,SIGNAL(sendDigit(Digit,int)),this,SLOT(getDigit(Digit,int)));
            edg->show();
        }else{
            QMessageBox::information(this,"Tip","this is backgroud color");
        }
        this->update();
    }else if(handleState==MOVEDIGIT){
        this->moveNum=i;
        if(i!=-1){
            Digit dg=dm.getDigitList()[i];
            cout<<dg.num<<endl;
            //记录鼠标点击的点与digit初始点的坐标差
            int cl=height()/2;
            int cw=width()/2;
            dx=event->x()- (cw+dg.getLocationX()*gridsize);
            dy=event->y()- (cl+dg.getLocationY()*gridsize);
            //交换被选中Digit与链表中最后一个digit
            dm.swapDigit(i,dm.getDigitList().size()-1);
//             dm.rebuildDigit(d,n);
            //            cout<<"交换"<<i<<"  "<<dm.getDigitList().size()-1<<endl;
            //            cout<<dm.getDigitList()[dm.getDigitList().size()-1].num<<endl;
            cout<<"========="<<dm.getDigitLocal(x,y)<<endl;
            cout<<dg.getLocationX()<<endl;
            cout<<dg.getLocationY()<<endl;
        }
    }
    cout<<i<<endl;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(handleState!=MOVEDIGIT)return;
    int x=event->x()+dx;
    int y=event->y()+dy;
    cout<<x<<" "<<y<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<toRX(event->x())<<" "<<toRY(event->y())<<endl;
//    cout<<dm.getDigitList().size()<<endl;
    dm.getDigitList()[dm.getDigitList().size()-1].setLocation(toRX(x),toRY(y));
    dm.digitList[dm.digitList.size()-1].setLocation(toRX(event->x()),toRY(event->y()));
    cout<<dm.getDigitList()[dm.getDigitList().size()-1].getLocationX()<<" "<<dm.getDigitList()[dm.getDigitList().size()-1].getLocationY()<<endl;
    cout<<"========================="<<endl;
    this->update();
}

void Widget::mouseReleaseEvent(QMouseEvent *)
{

}
//--------------------获取相对坐标------------------------
int Widget::toRX(int x)
{
    int cw=width()/2;
    int xx=x-cw;
    if(xx<0)xx-=gridsize;
    xx/=gridsize;
    return xx;
}
int Widget::toRY(int y)
{
    int cl=height()/2;
    int yy=y-cl;
    if(yy<0)yy-=gridsize;
    yy/=gridsize;
    return yy;
}
//--------------------------------------------------------

void Widget::drawOneGrid(int x, int y, QColor color)
{
    QPainter *painters=new QPainter(this);
    int cl=height()/2;
    int cw=width()/2;
    painters->fillRect(QRect(QPoint(cw+(x)*gridsize,cl+(y)*gridsize),QPoint(cw+(x+1)*gridsize,cl+(y+1)*gridsize)), QBrush(color));
    delete(painters);
}
void Widget::drawAllGrid(int xs, int ys,int xe,int ye, QColor color)
{
    QPainter *painters=new QPainter(this);
    int cl=height()/2;
    int cw=width()/2;
    painters->fillRect(QRect(QPoint(cw+xs*gridsize,cl+ys*gridsize),QPoint(cw+(xe+1)*gridsize,cl+(ye+1)*gridsize)), QBrush(color));
    delete(painters);

}

