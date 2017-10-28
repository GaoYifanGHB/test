#include "widget.h"
#include "ui_widget.h"
#include<QThread>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    cls.push_back(QColor(255,255,255));
    rls.push_back(1);
    setSize(0,0,0);
    handleState=NORMAL;
}

Widget::~Widget()
{
    delete ui;
}



void Widget::createDigitMap()
{
    dm.initAll();
    //����������ε������Բʿ�
    dm.addDigitToRect(-(w/2),-l/2,(w/2)-1,l/2-1);//�м�
    dm.addDigitToRect(-(w/2),-l/2-h,(w/2)-1,-l/2-1);//��
    dm.addDigitToRect(-(w/2)-h,-l/2,-(w/2)-1,l/2-1);//��
    dm.addDigitToRect(-(w/2),l/2,(w/2)-1,l/2-1+h);//��
    dm.addDigitToRect((w/2),-l/2,(w/2)+h-1,l/2-1);//��
    //������ɫ����������
    dm.setColorList(cls);
    dm.setColorRatio(rls);
    //Ϊ�����Բʿ�Ϳɫ
    dm.drawAllDigltColor();
}

void Widget::getDigit(Digit d,int n)
{
    dm.rebuildDigit(d,n);
    this->update();
}
//--------------------------�������Բ�-----------------
void Widget::drawDigitRect()
{
    //Ϳ��ɫ����ɫ�б�����һ����ɫΪ��ɫ��
    drawAllGrid(-(w/2),-l/2,(w/2)-1,l/2-1,cls[cls.size()-1]);
    drawAllGrid(-(w/2),-l/2-h,(w/2)-1,-l/2-1,cls[cls.size()-1]);
    drawAllGrid(-(w/2)-h,-l/2,-(w/2)-1,l/2-1,cls[cls.size()-1]);
    drawAllGrid(-(w/2),l/2,(w/2)-1,l/2-1+h,cls[cls.size()-1]);
    drawAllGrid((w/2),-l/2,(w/2)+h-1,l/2-1,cls[cls.size()-1]);
    //�������Բ�С�߿�
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
//--------------------------------------------------------


//---------------------���ó�ʼ����-------------------------
//�����
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
    if(m!=0) gridsize=(int)(n/m*1.2);
    else gridsize = 0;
}
//��ɫ������
void Widget::setColors(vector<QColor> cls, vector<int> rs)
{
    this->cls=cls;
    this->rls=rs;
}

void Widget::setHandleState(int handleState)
{
    this->handleState=handleState;
}
//-----------------------------------------------------------



//-------------------��������---------------------------------
void Widget::drawGrid()
{
    QPainter painters(this);
    int cl=height()/2;
    int cw=width()/2;
    //������
    for(int i=-l/2-h;i<=l/2+h;i++){
        if(i>=-l/2&&i<=l/2){
            painters.drawLine(QPoint(cw-(w/2+h)*gridsize,cl+i*gridsize),QPoint(cw+(w/2+h)*gridsize,cl+i*gridsize));
        }else{
            painters.drawLine(QPoint(cw-w/2*gridsize,cl+i*gridsize),QPoint(cw+w/2*gridsize,cl+i*gridsize));
        }
    }
    //������
    for(int i=-w/2-h;i<=w/2+h;i++){
        if(i>=-w/2&&i<=w/2){
            painters.drawLine(QPoint(cw+i*gridsize,cl-(l/2+h)*gridsize),QPoint(cw+i*gridsize,cl+(l/2+h)*gridsize));
        }else{
            painters.drawLine(QPoint(cw+i*gridsize,cl-(l/2)*gridsize),QPoint(cw+i*gridsize,cl+(l/2)*gridsize));
        }

    }

}
//-----------------------------------------------------------

//-----------------------��ͼ�¼�------------------------------
void Widget::paintEvent(QPaintEvent *event){
    //    initGridSize();
    drawGrid();
    drawDigitRect();
}
//------------------------------------------------------------


//-------------------------����¼�-----------------------------
//��갴��
void Widget::mousePressEvent(QMouseEvent *event)
{   if(handleState==NORMAL)return;
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
            QMessageBox::information(this,tr("��ʾ"),tr("���Ǳ���ɫ"));
        }
        this->update();
    }else if(handleState==MOVEDIGIT){
        this->moveNum=i;
        if(i!=-1){
            Digit dg=dm.getDigitList()[i];
            //��¼������ĵ���digit��ʼ��������
            int cl=height()/2;
            int cw=width()/2;
            dx=event->x()- (cw+dg.getLocationX()*gridsize);
            dy=event->y()- (cl+dg.getLocationY()*gridsize);
            //������ѡ��Digit�����������һ��digit
            dm.swapDigit(i,dm.getDigitList().size()-1);
        }
    }
}
//����ƶ�
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(handleState!=MOVEDIGIT)return;
    int x=event->x()-dx;
    int y=event->y()-dy;
    if(this->moveNum!=-1){
        dm.digitList[dm.digitList.size()-1].setLocation(toRX(x),toRY(y));
    }
    this->update();
}
//���̧��
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(handleState==MOVEDIGIT){
        dm.rebuildDigit(dm.getDigitList()[dm.getDigitList().size()-1],dm.getDigitList().size()-1);
    }
    this->update();
}
//��껬�ֹ���
void Widget::wheelEvent(QWheelEvent *event)
{
    int r=event->delta();
    if(r>0)gridsize+=2;
    else if(gridsize>1) gridsize-=2;
    cout<<r<<endl;
    cout<<gridsize<<endl;
    this->update();
}
//------------------------------------------------------------

//------------------------��ȡ�������--------------------------
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
//------------------------------------------------------------

//-----------------------����Ļ��ͼɫ---------------------------
//������Ե���С����Ϳɫ
void Widget::drawOneGrid(int x, int y, QColor color)
{
    QPainter *painters=new QPainter(this);
    int cl=height()/2;
    int cw=width()/2;
    painters->fillRect(QRect(QPoint(cw+(x)*gridsize,cl+(y)*gridsize),QPoint(cw+(x+1)*gridsize,cl+(y+1)*gridsize)), QBrush(color));
    delete(painters);
}
//��һ������Ϳɫ
void Widget::drawAllGrid(int xs, int ys,int xe,int ye, QColor color)
{
    QPainter *painters=new QPainter(this);
    int cl=height()/2;
    int cw=width()/2;
    painters->fillRect(QRect(QPoint(cw+xs*gridsize,cl+ys*gridsize),QPoint(cw+(xe+1)*gridsize,cl+(ye+1)*gridsize)), QBrush(color));
    delete(painters);
}

