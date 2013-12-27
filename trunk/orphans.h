#ifndef ORPHANS_H
#define ORPHANS_H

#include <QDialog>
#include "drakeprocesos.h"
#include <QSqlDatabase>

namespace Ui {
    class orphans;
}

class orphans : public QDialog
{
    Q_OBJECT

public:
    explicit orphans(QWidget *parent = 0);
    ~orphans();
    void Valor(QString valor);

signals:
    void Cerrar();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_13_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void ProcesarValor(QString ValorComand);
    void mibprogreso(QString Dat);
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_8_clicked();

private:
    Ui::orphans *ui;
    QString getRpm();
    QStringList lista;
    QString Value;
    QString Distro;
    QString Value0;
    QString user;
    DrakeProcesos *mib;
    int grabar;
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

#endif // ORPHANS_H
