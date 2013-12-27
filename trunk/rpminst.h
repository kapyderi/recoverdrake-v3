#ifndef RPMINST_H
#define RPMINST_H

#include <QDialog>
#include "drakeprocesos.h"
#include <QSqlDatabase>

namespace Ui {
    class rpminst;
}

class rpminst : public QDialog
{
    Q_OBJECT

public:
    explicit rpminst(QWidget *parent = 0);
    ~rpminst();
    void Valor(int valor, QString Value);

signals:
    void Cerrar();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_15_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_13_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void ProcesarValor(QString ValorComand);
    void mibprogreso(QString Dat);

private:
    Ui::rpminst *ui;
    QString rpm;
    QString rpm1;
    QString rpm2;
    QString rpm3;
    QString rpm4;
    QString rpm5;
    QString rpm6;
    QString rpm7;
    QStringList lista;
    QString Value0;
    QString Value1;
    QString Value2;
    QString Value3;
    QString Value4;
    QString Value5;
    DrakeProcesos *mib;
    int Activo;
    int Cantidad;
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

public slots:    
    void Recuento();

};

#endif // RPMINST_H
