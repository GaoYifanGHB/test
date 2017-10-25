#ifndef DIGITMAINWINDOW_H
#define DIGITMAINWINDOW_H

#include <QMainWindow>
#include "widget.h"
namespace Ui {
class DigitMainWindow;
}

class DigitMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DigitMainWindow(QWidget *parent = 0);
    ~DigitMainWindow();
    Widget *childWidget;
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_actionNew_triggered();

private:
    Ui::DigitMainWindow *ui;
};

#endif // DIGITMAINWINDOW_H
