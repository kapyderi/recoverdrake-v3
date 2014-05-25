#ifndef MRPM_H
#define MRPM_H

#include <QDialog>
#include "drakeprocesos.h"
#include <QSqlDatabase>
#include "ayuda.h"

namespace Ui {
    class Mrpm;
}

class Mrpm : public QDialog
{
    Q_OBJECT

public:
    explicit Mrpm(QWidget *parent = 0);
    ~Mrpm();    
    void Valor(QString valor, QString Logs);

signals:
    void Cerrar();

protected:
    void closeEvent(QCloseEvent *event);
    virtual bool eventFilter(QObject *, QEvent *);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void ProcesarValor(QString ValorComand);
    void mibprogreso(QString Dat);
    void on_pushButton_8_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void Comprobar();
    void on_pushButton_16_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void Recibir();
    void on_pushButton_19_clicked();

private:
    Ui::Mrpm *ui;
    QStringList lista;
    QString Value0;
    QString Value1;
    QString Value2;
    QString user;
    QString Distro;
    QString getDatos();
    QString getPack(QString activo);
    QString getRpm2(QString activo);
    int Comprobado;
    DrakeProcesos *mib;   
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
    int Opcion;
    QString Stilo;
    QString Log;
    int TotalProceso;    
    QString Comprueba;
    QStringList Listado;
    int Situacion;
    int Evento;
    Ayuda *ayuda;
    QStringList Posicion;
    int Totalizar;

};

#endif // MRPM_H
