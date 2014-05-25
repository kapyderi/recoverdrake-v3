#ifndef URPMI_H
#define URPMI_H

#include <QDialog>
#include "drakeprocesos.h"
#include <QSqlDatabase>

namespace Ui {
    class urpmi;
}

class urpmi : public QDialog {
    Q_OBJECT
public:
    urpmi(QWidget *parent = 0);
    ~urpmi();
    void Valor(QString alor);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *event);

private:
    Ui::urpmi *ui;
    DrakeProcesos *mib;
    QString Distro;
    QStringList lista;
    QString Value0;
    QString Value1;
    QString Value2;
    QString Value3;
    QString Value4;
    QString repo;
    QString dist;
    QString arqt;
    QString getDatos();
    QString getDatos1();
    int Cambio;
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

private slots:
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_2_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void ProcesarValor(QString ValorComand);
    void mibprogreso(QString Dat);
    void on_pushButton_3_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_5_clicked();
};

#endif // URPMI_H
