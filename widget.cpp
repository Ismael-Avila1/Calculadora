#include "widget.h"
#include "ui_widget.h"
#include <iostream>

using namespace std;

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


int suma(int n1, int n2);
int resta(int n1, int n2);
int multiplicacion(int n1, int n2);
int division(int n1, int n2);
int potencia(int n1, int n2);

void Widget::on_btnResolver_clicked()
{

    int num1 = ui->inputNum1->text().toInt();
    int num2 = ui->inputNum2->text().toInt();

    switch(ui->comboOpe->currentIndex()) {

    case 0:
        ui->labelResultado->setText("Resultado = " + QString::number(suma(num1, num2)));
        break;

    case 1:
        ui->labelResultado->setText("Resultado = " + QString::number(resta(num1, num2)));
        break;

    case 2:
        ui->labelResultado->setText("Resultado = " + QString::number(multiplicacion(num1, num2)));
        break;

    case 3:
        ui->labelResultado->setText("Resultado = " + QString::number(division(num1, num2)));
        break;

    case 4:
        ui->labelResultado->setText("Resultado = " + QString::number(potencia(num1, num2)));
        break;
    }

}


int suma(int n1, int n2) {
    int resultado;

    // __asm__();

    return resultado;
}


int resta(int n1, int n2) {
    int resultado;

    // __asm__();

    return resultado;
}


int multiplicacion(int n1, int n2) {
    int resultado;

    // __asm__();

    return resultado;
}


int division(int n1, int n2) {
    int resultado;

    // __asm__();

    return resultado;
}


int potencia(int n1, int n2) {
    int resultado;

    // __asm__();

    return resultado;
}

