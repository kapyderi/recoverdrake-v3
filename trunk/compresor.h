#ifndef COMPRESOR_H
#define COMPRESOR_H

#include <QDialog>
#include "ayuda.h"
#include <QSqlDatabase>
#include <QFileDialog>
#include <QTableWidgetItem>
#include "drakeprocesos.h"

namespace Ui {
class compresor;
}

class compresor : public QDialog
{
    Q_OBJECT

public:
    explicit compresor(QWidget *parent = 0);
    ~compresor();
    void Valor(QString valor, QString Logs);
    QString getSize(QString Dir);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();
    void ValorRuta(QStringList valor);
    void Comprobar();
    void Comprobar1();
    void Listado(QString Valor);
    void on_pushButton_2_clicked();
    void Value(QString Valor);
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
    void Empaquet();
    void on_pushButton_4_clicked();
    void Comprobar2();
    void mibFin();
    void mibEscribir(QString valor);
    void ProcesarValor(QString ValorComand);
    void mibprogreso(QString Dat);
    void Comprobar3();
    void on_checkBox_clicked();
    void on_checkBox_3_clicked();
    void on_checkBox_4_clicked();
    void on_pushButton_7_clicked();
    void Comprobar4();
    void Comprobar5();
    void ValorRuta1(QStringList valor);
    void Comprobar6();
    void on_pushButton_6_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_8_clicked();

private:
    Ui::compresor *ui;
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
    QSqlDatabase db;
    QString user;
    QFileDialog *fdlg;
    QFileDialog *fdlg1;
    QStringList Lista;
    int Posicion;
    int TipoCom;    
    QString Paquet;
    QString getDir(QString Ruta);
    QList<QTableWidgetItem *> items;
    int Evento;
    int Totalizar;
    int TotalProceso;
    DrakeProcesos *mib;
    QString Log;
    QString FullRute;
    QString FullDirectori;
    int NoMessage;
    int TipoClick;
    QString LPaquet;
    QString getListado(QString Comando);
    QStringList ListaD;
    QList<QTableWidgetItem *> itemsD;

};

#endif // COMPRESOR_H
