#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <QDialog>
#include "ayuda.h"
#include <QSqlDatabase>

namespace Ui {
class Calculadora;
}

class Calculadora : public QDialog
{
    Q_OBJECT
    
public:
    explicit Calculadora(QWidget *parent = 0);
    ~Calculadora();
    QString Terminado;
    
private slots:
    void on_pushButton_28_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_21_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void Cambio();
    void on_horizontalSlider_2_valueChanged(int value);
    void on_pushButton_2_clicked();
    void on_pushButton_30_clicked();
    void on_pushButton_32_clicked();
    void on_pushButton_33_clicked();
    void on_pushButton_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_34_clicked();

private:
    Ui::Calculadora *ui;
    QString Memoria;
    QString Valor;
    int Decimales;
    int Enteros;
    QSqlDatabase db;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QString Stilo;
    Ayuda *ayuda;
    double Aritmetica;
    //double Resultado;
    //double Memoria;
    int Conversion;
    int ValueCambio;
    QString Signo;

};

#endif // CALCULADORA_H
