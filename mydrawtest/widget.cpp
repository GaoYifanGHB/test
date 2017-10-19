#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}
void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPen pen(Qt::green,5,Qt::DotLine,Qt::RoundCap,Qt::RoundJoin);
    painter.setPen(pen);
    QRectF rectangle(70.0,40.0,80.0,60.0);
    int startAngle=30*16;
    int spanAngle=120*16;
    painter.drawArc(rectangle,startAngle,spanAngle);
}

Widget::~Widget()
{
    delete ui;
}
