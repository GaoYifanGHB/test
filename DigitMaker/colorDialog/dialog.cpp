#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,new ColorItem);
    item->setSizeHint(QSize(0,30));
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
        cout<<t<<" ";
        cls.push_back(color);
    }
    cout<<endl;
    emit sendColor(cls,rls);
    this->close();
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}
