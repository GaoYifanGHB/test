#include "digitmainwindow.h"
#include "ui_digitmainwindow.h"

DigitMainWindow::DigitMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DigitMainWindow)
{
    ui->setupUi(this);
    childWidget=new Widget(this);
    childWidget->setGeometry(width()/10,height()/10,width()*4/5,height()*4/5);
    vector<QColor>cs;
    vector<int> rs;
    //    //灰色
    //    cs.push_back(QColor(110,110,110));
    //    rs.push_back(3);
    //    //土红色
    //    cs.push_back(QColor(70,60,30));
    //    rs.push_back(3);
    //    //黑色
    //    cs.push_back(QColor(40,40,40));
    //    rs.push_back(3);
    //    //绿色
    //    cs.push_back(QColor(7,75,60));
    //    rs.push_back(3);
    //灰色
    cs.push_back(QColor(10,25,40));
    rs.push_back(3);
    //土红色
    cs.push_back(QColor(0,35,80));
    rs.push_back(3);
    //黑色
    cs.push_back(QColor(100,135,150));
    rs.push_back(3);
    //绿色
    cs.push_back(QColor(70,90,110));
    rs.push_back(3);

    this->cls=cs;
    this->rls=rs;
    this->l=1200;
    this->w=1500;
    this->h=400;

    childWidget->setSize(1200,1500,400);
    childWidget->setColors(cs,rs);
    childWidget->createDigitMap();
    childWidget->setHandleState(Widget::NORMAL);
    childWidget->show();
}

DigitMainWindow::~DigitMainWindow()
{
    delete childWidget;
    delete ui;
}

void DigitMainWindow::setSize(int l, int w, int h)
{
    this->l=l;
    this->w=w;
    this->h=h;
    colordg=new Dialog(this);
    connect(colordg,SIGNAL(sendColor(vector<QColor>,vector<int>)),this,SLOT(setColors(vector<QColor>,vector<int>)));
    colordg->show();
}

void DigitMainWindow::setColors(vector<QColor> cls, vector<int> rls)
{
    this->cls=cls;
    this->rls=rls;
    childWidget->setSize(this->l,this->w,this->h);
    childWidget->setColors(cls,rls);
    childWidget->createDigitMap();
    childWidget->update();
}

void DigitMainWindow::paintEvent(QPaintEvent *event)
{
    childWidget->setGeometry(width()/10,height()/20,width()*4/5,height()*9/10);
}

void DigitMainWindow::on_actionNew_triggered()
{
    sizedg=new setSizeDialog(this);
    connect(sizedg,SIGNAL(sendSize(int,int,int)),this,SLOT(setSize(int,int,int)));
    sizedg->show();
}




void DigitMainWindow::on_radioButton_released()
{
    if(ui->radioButton->isChecked())
        childWidget->setHandleState(Widget::EDITDIGIT);
    else
        childWidget->setHandleState(Widget::NORMAL);

}

void DigitMainWindow::on_radioButton_2_released()
{
    if(ui->radioButton_2->isChecked())
        childWidget->setHandleState(Widget::MOVEDIGIT);
    else
        childWidget->setHandleState(Widget::NORMAL);
}

void DigitMainWindow::on_actionSave_triggered()
{
    QString qfilename=QFileDialog::getSaveFileName(this,tr("保存文件"),"defalut.g","*.g",0);
    if(!qfilename.isNull()){
        string filename=qfilename.toStdString();
        cout<<filename<<endl;
        fileHandle=new FileHandle(filename);
        fileHandle->setSize(this->l,this->w,this->h);
        fileHandle->setColorList(cls,rls);
        fileHandle->setDigitManager(childWidget->dm);
        fileHandle->save();
    }
}

void DigitMainWindow::on_actionOpen_triggered()
{
    QString qfilename=QFileDialog::getOpenFileName(this,tr("打开文件"),"default.g","*.g",0);
    if(!qfilename.isNull()){
        string filename=qfilename.toStdString();
        cout<<filename<<endl;

        fileHandle=new FileHandle(filename);
        fileHandle->read();
        DigitMananger dm=fileHandle->getDigitManager();
        childWidget->dm=dm;
        fileHandle->getSize(l,w,h);
        childWidget->setSize(l,w,h);
        fileHandle->getColorList(cls,rls);
        childWidget->setColors(cls,rls);
        childWidget->update();
    }

}
