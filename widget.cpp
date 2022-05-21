#include "widget.h"
#include "ui_widget.h"
#include <iostream>

using namespace std;

    // Codigo generado automaticamente. Constructor de la ventana.
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("Calculadora");
}

    // Codigo generado automaticamente. Destructor de la ventana.
Widget::~Widget()
{
    delete ui;
}


    // Se ejecuta cuando se presiona el boton de resolver
void Widget::on_btnResolver_clicked()
{

    float num1 = ui->inputNum1->text().toFloat();   // Se optiene el valor del primer input
    float num2 = ui->inputNum2->text().toFloat();   // Se optiene el valor del primer input
    float resultado;

    switch(ui->comboOpe->currentIndex()) {  // Segun lo que se seleccione en el ComboBox
        case 0:     // En caso de seleccionar suma
            __asm__(
                "FLD %1;"   // FLD carga un valor de punto flotante
                "FLD %2;"
                "FADDP;"    // FADDP suma de punto flotante
                "FSTP %0;" : "=m"(resultado) : "g"(num1), "g"(num2) // FSTP almacena un valor de punto flotante
            );

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));   // El resiltado de imprime en la interfaz
            break;


        case 1:
            __asm__(
                "FLD %1;"   // FLD carga un valor de punto flotante
                "FLD %2;"
                "FSUBP;"    // FSUBP resta de punto flotante
                "FSTP %0;" : "=m"(resultado) : "g"(num2), "g"(num1) // FSTP almacena un valor de punto flotante
            );

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));   // El resiltado de imprime en la interfaz
            break;


        case 2:
            __asm__(
                "FLD %1;"   // FLD carga un valor de punto flotante
                "FLD %2;"
                "FMULP;"    // FMULP multiplicacion de punto flotante
                "FSTP %0;" : "=m"(resultado) : "g"(num1), "g"(num2) // FSTP almacena un valor de punto flotante
            );

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));   // El resiltado de imprime en la interfaz
            break;


        case 3:
            __asm__(
                "FLD %1;"   // FLD carga un valor de punto flotante
                "FLD %2;"
                "FDIVP;"    // FDIVP division de punto flotante
                "FSTP %0;" : "=m"(resultado) : "g"(num2), "g"(num1) // FSTP almacena un valor de punto flotante
            );

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));   // El resiltado de imprime en la interfaz
            break;


        case 4:
            __asm__ __volatile__(
                "FLD %1;"   // FLD carga un valor de punto flotante
                "FSQRT;"    // FSQRT raiz cuadrada
                "FSTP %0;" : "=g"(resultado) : "g"(num1)    // FSTP almacena un valor de punto flotante
            );

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));   // El resiltado de imprime en la interfaz
            ui->inputNum2->setText(""); // Solo se toma el valor del primer input. El segundo input se resetea para evitar confusiones
            break;


        case 5: {
            float dosAngulo = 180.0f;

            __asm__ __volatile__(   "FLD %1;"   // FLD carga un valor de punto flotante
                                    "FLD %2;"
                                    "FLDPI;"    // FLDPI carga el calor de PI
                                    "FMULP;"    // FMULP multiplicacion de punto flotante
                                    "FDIVP;"    // FDIVP division de punto flotante
                                    "FSIN;"     // FSIN operacion seno
                                    "FSTP %0;" : "=m"(resultado) : "g"(dosAngulo), "g"(num1)    // FSTP almacena un valor de punto flotante
                                    );

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));   // El resiltado de imprime en la interfaz
            ui->inputNum2->setText("");  // Solo se toma el valor del primer input. El segundo input se resetea para evitar confusiones
            break;
        }


        case 6:{
            float dosAngulo = 180.0f, radianes;

            radianes = num1 * 3.141592 / dosAngulo;     // Conversion a radianes

            __asm__ __volatile__(   "FLD %1;"   // FLD carga un valor de punto flotante
                                    "FCOS;"     // FCOS operacion coseno
                                    "FSTP %0;" : "=m"(resultado) : "m"(radianes)    // FSTP almacena un valor de punto flotante
            );

            if(resultado < 0.000001)    // se imprime como resultado 3.13196x10-7 en vez de 0
                resultado = 0;

            ui->labelResultado->setText("Resultado = " + QString::number(resultado));   // El resiltado de imprime en la interfaz
            ui->inputNum2->setText("");     // Solo se toma el valor del primer input. El segundo input se resetea para evitar confusiones
            break;
        }
    }

}

