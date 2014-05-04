#ifndef REPORT_H
#define REPORT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "ayuda.h"

namespace Ui {
class Report;
}

class Report : public QDialog
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = 0);
    ~Report();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);

private slots:
    void on_pushButton_4_clicked();
    void cambiaFila(QModelIndex actual);
    void cambiaFila1(QModelIndex actual);
    void cambiaFila2(QModelIndex actual);
    void cambiaFila3(QModelIndex actual);
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_10_clicked();
    void on_comboBox_3_currentIndexChanged(const QString &arg1);
    void on_pushButton_8_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_6_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Report *ui;
    QSqlTableModel *Model;
    QSqlTableModel *Model1;
    QSqlTableModel *Model2;
    QSqlTableModel *Model3;
    QSqlDatabase db;
    int id;
    int fila;
    QString Cantidad;
    QString DatoRev;
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
    int Llamada;

};

#endif // REPORT_H
