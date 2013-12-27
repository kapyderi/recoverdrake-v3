#ifndef MD5SUM_H
#define MD5SUM_H

#include <QDialog>
#include <QTimer>
#include "drakeprocesos.h"
#include <QSqlDatabase>

namespace Ui {
    class md5sum;
}

class md5sum : public QDialog {
    Q_OBJECT
public:
    md5sum(QWidget *parent = 0);
    ~md5sum();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::md5sum *ui;
    QString user;
    QTimer *Contador;
    QString fileNameOrigen;
    QString fileNameOrigen1;
    DrakeProcesos *mib;
    QString Val1;
    QString Val2;
    QStringList Valor1;
    QStringList Valor2;
    QStringList comandos;
    int Comp1;
    int Comp2;
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
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void Contar();
    void mibFin();
    void mibEscribir(QString valor);

};

#endif // MD5SUM_H
