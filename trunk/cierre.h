#ifndef CIERRE_H
#define CIERRE_H

#include <QDialog>
#include "QTimer"
#include <QSqlDatabase>

namespace Ui {
    class Cierre;
}

class Cierre : public QDialog
{
    Q_OBJECT

public:
    explicit Cierre(QWidget *parent = 0);
    ~Cierre();
    int DownDia;
    int DownMes;
    int DownAnyo;
    int DownHora;
    int DownMinuto;
    int DownSegundo;
    QTimer *timer;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void hora();
    void on_spinBox_valueChanged(int arg1);
    void on_spinBox_2_valueChanged(int arg1);
    void on_spinBox_6_valueChanged(int arg1);
    void on_spinBox_4_valueChanged(int arg1);
    void on_spinBox_5_valueChanged(int arg1);

private:
    Ui::Cierre *ui;
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

};

#endif // CIERRE_H
