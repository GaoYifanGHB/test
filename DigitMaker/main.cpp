#include <QApplication>
#include "digitmainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DigitMainWindow w;
    w.show();
    
    return a.exec();
}
