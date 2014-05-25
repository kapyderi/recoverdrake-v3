#ifndef SONIDO_H
#define SONIDO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class Sonido;
}

class Sonido : public QDialog
{
    Q_OBJECT
    
public:
    explicit Sonido(QWidget *parent = 0);
    ~Sonido();
    QString Resultado;

signals:
    void Sound(QString Valor, int band1, int band2, int band3, int band4, int band5, int band6, int band7, int band8, int band9, int band10);

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_verticalSlider_valueChanged(int value);
    void on_verticalSlider_2_valueChanged(int value);
    void on_verticalSlider_3_valueChanged(int value);
    void on_verticalSlider_4_valueChanged(int value);
    void on_verticalSlider_5_valueChanged(int value);
    void on_verticalSlider_6_valueChanged(int value);
    void on_verticalSlider_7_valueChanged(int value);
    void on_verticalSlider_8_valueChanged(int value);
    void on_verticalSlider_9_valueChanged(int value);
    void on_verticalSlider_10_valueChanged(int value);
    void Comprobar();

private:
    Ui::Sonido *ui;
    QString activar;
    QString banda1;
    QString banda2;
    QString banda3;
    QString banda4;
    QString banda5;
    QString banda6;
    QString banda7;
    QString banda8;
    QString banda9;
    QString banda10;
    QSqlDatabase db;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QSqlTableModel *Model22;
    int Valor;
    QString Stilo;

};

#endif // SONIDO_H
