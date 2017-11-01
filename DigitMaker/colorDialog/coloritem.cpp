#include "coloritem.h"
#include "ui_coloritem.h"

ColorItem::ColorItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorItem)
{
    ui->setupUi(this);
    this->color=QColor(0,0,0);
    rect.setRect(135,1,20,20);
}

void ColorItem::setData(int num, QColor color)
{
    this->ui->lineEdit->setText(QString::number(num));
    this->color=color;
//    this->update();
}

int ColorItem::getNum()
{
    QString s=ui->lineEdit->text();
    return s.toInt();
}

ColorItem::~ColorItem()
{
    delete ui;
}

void ColorItem::paintEvent(QPaintEvent *)
{

    QPainter *painters =new QPainter(this);
    painters->fillRect(rect,QBrush(this->color));
    delete painters;
}

void ColorItem::mousePressEvent(QMouseEvent *event)
{
    if(rect.contains(event->pos())){
//        this->color=QColor(0,255,0);
        this->color = QColorDialog::getColor(Qt::black);
    }
    this->update();
}
