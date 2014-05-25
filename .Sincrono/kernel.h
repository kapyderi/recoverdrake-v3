#ifndef KERNEL_H
#define KERNEL_H

#include <QDialog>
#include <QSqlDatabase>
#include "drakeprocesos1.h"

namespace Ui {
class Kernel;
}

class Kernel : public QDialog
{
    Q_OBJECT
    
public:
    explicit Kernel(QWidget *parent = 0);
    ~Kernel();
    void Valor(QString valor);

signals:
    void Cerrar();

protected:
    void closeEvent(QCloseEvent *event);
    
private slots:
    void on_pushButton_3_clicked();
    void Comprobar();
    void Comprobar1();
    void Comprobar2();
    void Comprobar3();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void mibprogreso(QString Dat);
    void on_pushButton_9_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();

private:
    Ui::Kernel *ui;
    int CierreTotal;
    QSqlDatabase db;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QString user;
    DrakeProcesos1 *mib;
    int Opcion;
    QString getEnlace();
    QString Config;
    QString getLink();
    QString Stilo;

};

#endif // KERNEL_H
