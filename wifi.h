#ifndef WIFI_H
#define WIFI_H

#include <QDialog>
#include <QSqlTableModel>
#include "drakeprocesos1.h"
#include <QSqlDatabase>

namespace Ui {
    class wifi;
}

class wifi : public QDialog {
    Q_OBJECT
public:
    wifi(QWidget *parent = 0);
    ~wifi();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::wifi *ui;
    QSqlTableModel *Model;
    QSqlTableModel *Model1;
    int fila;
    int id;
    int fila1;
    int id1;
    QString Cantidad;
    QString Cantidad1;
    QString ip;
    QString MacDic;
    QString list;
    DrakeProcesos1 *mib;
    QStringList lista;
    QStringList ValorIps;
    QString val;
    int pos;
    QString Value0;
    QString user;
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

private slots:
    void on_pushButton_14_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_4_clicked();
    void cambiaFila(QModelIndex actual);
    void cambiaFila1(QModelIndex actual);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_6_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void mibprogreso(QString Dat);
    void lanzar();

};

#endif // WIFI_H
