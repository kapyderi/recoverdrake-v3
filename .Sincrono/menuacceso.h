#ifndef MENUACCESO_H
#define MENUACCESO_H

#include <QDialog>
#include <QSqlTableModel>
#include "drakeprocesos.h"
#include <QSqlDatabase>

namespace Ui {
    class MenuAcceso;
}

class MenuAcceso : public QDialog
{
    Q_OBJECT

public:
    explicit MenuAcceso(QWidget *parent = 0);
    ~MenuAcceso();

private slots:
    void on_pushButton_4_clicked();
    void cambiaFila(QModelIndex actual);
    void on_pushButton_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MenuAcceso *ui;
    QSqlTableModel *Model;
    int id;
    int fila;
    QString Value0;
    QString Value1;
    QString Value2;
    QString Value3;
    QString Value4;
    QString Value5;
    QString Value6;
    QString Value7;
    QString Value8;
    QString Valor;
    QString user;
    DrakeProcesos *mib;
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

#endif // MENUACCESO_H
