#ifndef BORRAR_H
#define BORRAR_H

#include <QDialog>
#include "ayuda.h"
#include "drakeprocesos.h"
#include <QSqlDatabase>

namespace Ui {
class Borrar;
}

class Borrar : public QDialog
{
    Q_OBJECT

public:
    explicit Borrar(QWidget *parent = 0);
    ~Borrar();
    void Valor(QString valor);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private slots:
    void mibFin();
    void mibEscribir(QString valor);
    void on_pushButton_2_clicked();
    void Cambio();
    void Cambio1();
    void on_pushButton_3_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::Borrar *ui;
    Ayuda *ayuda;
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
    DrakeProcesos *mib;
    QString Log;
    QSqlDatabase db;
    QString user;
    QString Tipo;
    QString Buscar;
    int Formato;

};

#endif // BORRAR_H
