#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<widget.h>
#include<QColor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event);

private:
    Widget *w;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
