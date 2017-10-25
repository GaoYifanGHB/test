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
    cs.push_back(QColor(110,110,110));
    cs.push_back(QColor(70,60,30));
    cs.push_back(QColor(40,40,40));
    cs.push_back(QColor(7,75,60));
    rs.push_back(3);
    rs.push_back(3);
    rs.push_back(3);
    rs.push_back(1);
    childWidget->setSize(600,800,300);
    childWidget->setColors(cs,rs);
    childWidget->createDigitMap();
    childWidget->setHandleState(Widget::EDITDIGIT);
    childWidget->show();
}

DigitMainWindow::~DigitMainWindow()
{
    delete childWidget;
    delete ui;
}

void DigitMainWindow::paintEvent(QPaintEvent *event)
{
    childWidget->setGeometry(width()/10,height()/20,width()*4/5,height()*9/10);
}

void DigitMainWindow::on_actionNew_triggered()
{

}
