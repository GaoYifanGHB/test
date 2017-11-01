#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

void Dialog::addItem(int r, QColor color)
{
    cout<<1<<endl;
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    ui->listWidget->addItem(item);
    cout<<2<<endl;
    ColorItem *coloritem=new ColorItem;
    coloritem->setData(r,color);
    cout<<3<<endl;
    ui->listWidget->setItemWidget(item,coloritem);
    item->setSizeHint(QSize(0,30));
}

void Dialog::deleteItem(int i)
{
    QListWidgetItem *item=ui->listWidget->currentItem();
    ui->listWidget->removeItemWidget(item);
    ui->listWidget->update();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    addItem(1,QColor(0,0,0));
}

void Dialog::on_pushButton_3_clicked()
{
    vector<int>rls;
    vector<QColor>cls;
    int x= ui->listWidget->count();
    cout<<x<<endl;
    for(int i=0;i<x;i++){
        QListWidgetItem *item=ui->listWidget->item(i);
        QWidget *citem=ui->listWidget->itemWidget(item);
        int t=((ColorItem*)citem)->getNum();
        QColor color=((ColorItem*)citem)->color;
        rls.push_back(t);
        cls.push_back(color);
    }
    emit sendColor(cls,rls);
    this->close();
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}



void Dialog::on_radioButton_2_released()
{
    if(ui->radioButton_2->isChecked()){
        ui->listWidget->clear();
        addItem(1,QColor(110,110,110));
        addItem(1,QColor(70,60,30));
        addItem(1,QColor(40,40,40));
        addItem(1,QColor(7,75,60));
    }
}

void Dialog::on_radioButton_3_released()
{
    if(ui->radioButton_3->isChecked()){
        ui->listWidget->clear();
        addItem(2,QColor(10,25,40));
        addItem(2,QColor(0,35,80));
        addItem(2,QColor(100,135,150));
        addItem(3,QColor(70,90,110));
    }
}

void Dialog::on_radioButton_released()
{
    if(ui->radioButton->isChecked()){
        ui->listWidget->clear();
        addItem(2,QColor(120,70,10));
        addItem(2,QColor(160,110,45));
        addItem(4,QColor(230,217,200));
        addItem(3,QColor(115,70,20));


    }
}

void Dialog::on_radioButton_4_released()
{
    if(ui->radioButton_4->isChecked()){
        ui->listWidget->clear();
        addItem(2,QColor(20,20,20));
        addItem(2,QColor(120,120,120));
        addItem(3,QColor(170,170,170));
        addItem(4,QColor(65,65,65));
    }
}

void Dialog::on_radioButton_5_released()
{
    if(ui->radioButton_5->isChecked()){
        ui->listWidget->clear();
        addItem(4,QColor(176,176,176));
        addItem(1,QColor(100,100,100));
        addItem(7,QColor(230,230,230));
        addItem(1,QColor(75,75,75));
    }
}

void Dialog::on_pushButton_4_clicked()
{
    QString qfilename=QFileDialog::getOpenFileName(this,tr("打开文件"),"","*.jpg;*.png",0);
    if(!qfilename.isNull()){
        string filename=qfilename.toStdString();
        ColorHandle*colorhandle=new ColorHandle();
        Mat image=imread(filename);
        if(!image.data)return;
        colorhandle->calculate(image);
        ui->listWidget->clear();
        for(int i=0;i<colorhandle->getCls().size();i++){
            addItem(colorhandle->getRls()[i],colorhandle->getCls()[i]);
        }
    }
}
