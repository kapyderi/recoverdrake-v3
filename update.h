#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>
#include "drakeprocesos.h"
#include <QSqlDatabase>

namespace Ui {
    class Update;
}

class Update : public QDialog
{
    Q_OBJECT

public:
    explicit Update(QWidget *parent = 0);
    ~Update();
    void Valor(QString valor);

signals:
    void Cerrar();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_13_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_3_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void ProcesarValor(QString ValorComand);
    void mibprogreso(QString Dat);
    void on_pushButton_10_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_11_clicked();

private:
    Ui::Update *ui;
    QString getDatos();
    QStringList lista;
    QStringList ValueDat;
    QString Value;
    QString Value0;
    QString Value1;
    QString Value2;
    QString Value3;
    QString Value4;
    QString user;
    DrakeProcesos *mib;
    QString getRpm();
    QString getRpm2(QString Value);
    QSqlDatabase db;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    int CierreTotal;
    QString Stilo;

};

#endif // UPDATE_H
