#include <QApplication>
#include "widget.h"
#include"digitmananger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
    return 0;
}
