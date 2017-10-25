#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    w=new Widget(this);
    w->setGeometry(width()/10,height()/20,width()*4/5,height()*9/10);
    vector<QColor>cs;
    vector<int> rs;
    cs.push_back(QColor(110,110,110));
    cs.push_back(QColor(70,60,30));
    cs.push_back(QColor(40,40,40));
    cs.push_back(QColor(7,75,60));
    rs.push_back(3);
    rs.push_back(3);
    rs.push_back(3);
    rs.push_back(3);
    w->setSize(1800,2000,400);
    w->setColors(cs,rs);
    w->setHandleState(Widget::NORMAL);
    w->createDigitMap();
    w->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    w->setGeometry(width()/10,height()/18,width()*4/5,height()*8/9);
    w->update();
}
