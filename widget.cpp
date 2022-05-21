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


void Widget::on_btnResolver_clicked()
{

    float num1 = ui->inputNum1->text().toFloat();
    float num2 = ui->inputNum2->text().toFloat();
    float resultado;

    switch(ui->comboOpe->currentIndex()) {
        case 0:
            __asm__(
                "FLD %1;"
                "FLD %2;"
                "FADDP;"
                "FSTP %0;" : "=m"(resultado) : "g"(num1), "g"(num2)
            );

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));
            break;


        case 1:
            __asm__(
                "FLD %1;"
                "FLD %2;"
                "FSUBP;"
                "FSTP %0;" : "=m"(resultado) : "g"(num2), "g"(num1)
            );

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));
            break;


        case 2:
            __asm__(
                "FLD %1;"
                "FLD %2;"
                "FMULP;"
                "FSTP %0;" : "=m"(resultado) : "g"(num1), "g"(num2)
            );

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));
            break;


        case 3:
            __asm__(
                "FLD %1;"
                "FLD %2;"
                "FDIVP;"
                "FSTP %0;" : "=m"(resultado) : "g"(num2), "g"(num1)
            );

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));
            break;


        case 4:
            __asm__ __volatile__(
                "FLD %1;"
                "FSQRT;"
                "FSTP %0;" : "=g"(resultado) : "g"(num1)
            );

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));
            ui->inputNum2->setText("");
            break;


        case 5: {
            float dosAngulo = 180.0f;

            __asm__ __volatile__(   "FLD %1;"
                                    "FLD %2;"
                                    "FLDPI;"
                                    "FMULP;"
                                    "FDIVP;"
                                    "FSIN;"
                                    "FSTP %0;" : "=m"(resultado) : "g"(dosAngulo), "g"(num1)
                                    );

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));
            ui->inputNum2->setText("");
            break;
        }


        case 6:{
            float dosAngulo = 180.0f, radianes;

            radianes = num1 * 3.141592 / dosAngulo;

            __asm__ __volatile__(   "FLD %1;"
                                    "FCOS;"
                                    "FSTP %0;" : "=m"(resultado) : "m"(radianes)
            );

            if(resultado < 0.000001)
                resultado = 0;

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));
            ui->inputNum2->setText("");
            break;
        }
    }

}

