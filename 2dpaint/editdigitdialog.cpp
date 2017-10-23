#include "editdigitdialog.h"
#include "ui_editdigitdialog.h"

EditDigitDialog::EditDigitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDigitDialog)
{
    ui->setupUi(this);
}

EditDigitDialog::~EditDigitDialog()
{
    delete ui;
}
void EditDigitDialog::setDigit(Digit d,int n)
{
    this->d=d;
    this->n=n;
}
void EditDigitDialog::initGridSize(int l, int w)
{
    double m=l>w?l:w;
    double n=height()>width()?height():width();
    n*=0.6;
    gridsize=(int)(n/m*10.0);

}
void EditDigitDialog::drawOneGrid(int x, int y, QColor color)
{
    QPainter *painters=new QPainter(this);
    int cl=height()/3;
    int cw=width()/2;
    painters->fillRect(QRect(QPoint(cw+(x)*gridsize,cl+(y)*gridsize),QPoint(cw+(x+1)*gridsize,cl+(y+1)*gridsize)), QBrush(color));

}
void EditDigitDialog::paintEvent(QPaintEvent *event)
{
    QPainter *painters=new QPainter(this);
    int cy=height()/3;
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

void EditDigitDialog::mousePressEvent(QMouseEvent *event)
{
    int w=d.getWidth();int l=d.getLength();
    int xs=-w/2,ys=-l/2;
    int x=toRX(event->x());
    int y=toRY(event->y());
    d.mat[y-ys+2][x-xs]=!d.mat[y-ys+2][x-xs];
    this->update();
}

int EditDigitDialog::toRX(int x)
{
    int cw=width()/2;
    int xx=x-cw;
    if(xx<0)xx-=gridsize;
    xx/=gridsize;
    return xx;
}
int EditDigitDialog::toRY(int y)
{
    int cl=height()/2;
    int yy=y-cl;
    if(yy<0)yy-=gridsize;
    yy/=gridsize;
    return yy;
}


void EditDigitDialog::on_buttonBox_accepted()
{
    emit sendDigit(d,n);
}
