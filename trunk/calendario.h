#ifndef CALENDARIO_H
#define CALENDARIO_H

#include <QDialog>
#include <QDate>
#include <QSqlDatabase>
#include "drakeprocesos1.h"
#include "ayuda.h"

namespace Ui {
class Calendario;
}

class Calendario : public QDialog
{
    Q_OBJECT
    
public:
    explicit Calendario(QWidget *parent = 0);
    ~Calendario();
    void Valor(QString valor, QString Log);

protected:
    virtual bool eventFilter(QObject *, QEvent *);

private slots:
    void Calendar(QDate date);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void Comprobar();
    void Comprobar1();
    void on_pushButton_7_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void mibprogreso(QString Dat);
    void Consola();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::Calendario *ui;
    QSqlDatabase db;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QDate data;
    QString valor;
    QStringList Value;
    QString Stilo;
    int Posicion;
    DrakeProcesos1 *mib;
    QString log;
    QString getPropietario(QString Valor);
    QString user;
    Ayuda *ayuda;
    int Evento;
    int Segmento;

};

#endif // CALENDARIO_H
