#include "setsizedialog.h"
#include "ui_setsizedialog.h"

setSizeDialog::setSizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setSizeDialog)
{
    ui->setupUi(this);
}

setSizeDialog::~setSizeDialog()
{
    delete ui;
}

void setSizeDialog::on_pushButton_2_clicked()
{
    this->close();
}

void setSizeDialog::on_pushButton_clicked()
{
    int h=ui->hei_et->text().toInt();
    int w=ui->wid_et->text().toInt();
    int l=ui->len_et->text().toInt();
    emit sendSize(l,w,h);
    this->close();
}
