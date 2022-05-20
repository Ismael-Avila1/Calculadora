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

    int num1 = ui->inputNum1->text().toInt();
    int num2 = ui->inputNum2->text().toInt();

    int resultado;

    switch(ui->comboOpe->currentIndex()) {

    case 0:
        ui->labelResultado->setText("Resultado = " + QString::number(num1 + num2));
        break;

    case 1:
        ui->labelResultado->setText("Resultado = " + QString::number(num1 - num2));
        break;

    case 2:
        ui->labelResultado->setText("Resultado = " + QString::number(num1 * num2));
        break;

    case 3:
        ui->labelResultado->setText("Resultado = " + QString::number(num1 / num2));
        break;

    case 4:
        ui->labelResultado->setText("Resultado = " + QString::number(num1 ^ num2));
        break;
    }


}

