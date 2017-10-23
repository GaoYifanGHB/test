#include <QApplication>
#include "widget.h"
#include<QTextCodec>
#include"digitmananger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("gbk");//ַי¿צ1

    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);

    Widget w;
    w.show();
    return a.exec();
}
