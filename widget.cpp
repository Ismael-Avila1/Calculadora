#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("Calculadora");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnResolver_clicked()
{
    switch(ui->comboOpe->currentIndex()) {

    case 0:
        ui->labelResultado->setText(QString::number(ui->inputNum1->text().toInt() + ui->inputNum2->text().toInt()));
        break;

    case 1:
        ui->labelResultado->setText(QString::number(ui->inputNum1->text().toInt() - ui->inputNum2->text().toInt()));
        break;

    case 2:
        ui->labelResultado->setText(QString::number(ui->inputNum1->text().toInt() * ui->inputNum2->text().toInt()));
        break;

    case 3:
        ui->labelResultado->setText(QString::number(ui->inputNum1->text().toInt() / ui->inputNum2->text().toInt()));
        break;

    case 4:
        ui->labelResultado->setText(QString::number(ui->inputNum1->text().toInt() ^ ui->inputNum2->text().toInt()));
        break;
    }


}

