#ifndef DIGITMAINWINDOW_H
#define DIGITMAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include "widget.h"
#include "setsizedialog.h"
#include "colorDialog/dialog.h"
#include "fileHandle/filehandle.h"
#include <string>
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
    setSizeDialog *sizedg;
    Dialog *colordg;
    void updateSizeShow();

public slots:
    void setSize(int l,int w,int h);
    void setColors(vector<QColor>cls,vector<int>rls);
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_actionNew_triggered();

    void on_radioButton_released();

    void on_radioButton_2_released();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();



private:
    Ui::DigitMainWindow *ui;
    int h,l,w;
    FileHandle *fileHandle;
    vector<QColor> cls;
    vector<int> rls;
};

#endif // DIGITMAINWINDOW_H
