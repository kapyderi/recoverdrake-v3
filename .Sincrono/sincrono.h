#ifndef SINCRONO_H
#define SINCRONO_H

#include <QDialog>
#include <QSqlDatabase>
#include "drakeprocesos1.h"
#include "calendario.h"
#include "ayuda.h"
#include <QTableWidgetItem>
#include <QTimer>

namespace Ui {
    class sincrono;
}

class sincrono : public QDialog {
    Q_OBJECT
public:
    sincrono(QWidget *parent = 0);
    ~sincrono();
    void Valor(QString Ref, QString Valor1, QString Valor2, QString Valor3, QString Valor4, QString Valor5, QString Valor6, int Value, QString Log, QString Pos);
    QString Update;

signals:
    void Terminado(int Valor, QString Value);

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private:
    Ui::sincrono *ui;
    QString user;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QSqlDatabase db;
    int Evento;
    DrakeProcesos1 *mib;
    Calendario *fecha;
    Ayuda *ayuda;
    QString blkid();
    QString getMount(QString Dev);
    QString getLocal(QString Dev);
    QString Omitir;
    QString Referencia;
    int Sincronizador;
    QString getPropietario(QString Valor);
    QString Stilo;
    int NoSincro;
    QString log;
    QColor colorAnt;
    QList<QTableWidgetItem *> itemsa;
    QList<QTableWidgetItem *> items;
    QList<QTableWidgetItem *> items1;
    QList<QTableWidgetItem *> items2;
    int TotalProceso;
    int Totalizar;
    QString Comprueba;
    QTimer *Contad;
    int Value;
    int Counter;
    int ContadorC;
    int Marca;
    int Destruir;

private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void mibprogreso(QString Dat);
    void Comprobar();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();    
    void on_lineEdit_2_textChanged(const QString &arg1);
    void on_lineEdit_textChanged(const QString &arg1);
    void ProcesarValor(QString ValorComand);
    void on_lineEdit_2_editingFinished();
    void on_lineEdit_editingFinished();
    void Montaje();
    void Verificar();

};

#endif // SINCRONO_H
