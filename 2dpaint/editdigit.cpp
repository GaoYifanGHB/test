#include "editdigit.h"
#include "ui_editdigit.h"

EditDigit::EditDigit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditDigit)
{
    ui->setupUi(this);
}

void EditDigit::setDigit(Digit d)
{
    this->d=d;
}

//EditDigit::EditDigit(QWidget *parent, Digit d)
//{
//    this->d=d;
//    EditDigit(parent);
//}

void EditDigit::initGridSize(int l, int w)
{
    double m=l>w?l:w;
    double n=height()>width()?height():width();
    n*=0.6;
    gridsize=(int)(n/m*10.0);

}

EditDigit::~EditDigit()
{
    delete ui;
}
void EditDigit::drawOneGrid(int x, int y, QColor color)
{
    QPainter *painters=new QPainter(this);
    int cl=height()/2;
    int cw=width()/2;
    painters->fillRect(QRect(QPoint(cw+(x)*gridsize,cl+(y)*gridsize),QPoint(cw+(x+1)*gridsize,cl+(y+1)*gridsize)), QBrush(color));

}
void EditDigit::paintEvent(QPaintEvent *event)
{
    QPainter *painters=new QPainter(this);
    int cy=height()/2;
    int cx=width()/2;
    initGridSize(d.getWidth(),d.getLength());
    gridsize=25;
    cout<<d.getWidth()<<" "<<d.getLength()<<endl;
    int w=d.getWidth();int l=d.getLength();
    int xs=-w/2,xe=w/2,ys=-l/2,ye=l/2;
    if(w%2)xe++;if(l%2)ye++;
    for(int i=xs;i<=xe;i++){
        painters->drawLine(QPoint(cx+i*gridsize,cy+ys*gridsize),QPoint(cx+i*gridsize,cy+ye*gridsize));
    }
    for(int j=ys;j<=ye;j++){
        painters->drawLine(QPoint(cx+xs*gridsize,cy+j*gridsize),QPoint(cx+xe*gridsize,cy+j*gridsize));
    }
    for(int i=0;i<d.getLength();i++){
        for(int j=0;j<d.getWidth();j++){
            if(d.mat[i][j]){
                drawOneGrid(xs+j,ys+i,d.getColor());
            }
        }
    }
}

