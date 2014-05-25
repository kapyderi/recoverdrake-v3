#ifndef TOTALSINCRONO_H
#define TOTALSINCRONO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "sincrono.h"
#include "omision.h"
#include "ayuda.h"

namespace Ui {
class TotalSincrono;
}

class TotalSincrono : public QDialog
{
    Q_OBJECT
    
public:
    explicit TotalSincrono(QWidget *parent = 0);
    ~TotalSincrono();
    void Valor(QString valor, QString Log);
    QSqlTableModel *Model;

signals:
    void Cerrar();

protected:
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);
    
public slots:
    void Refrescar(int Valor,QString Value);

private:
    Ui::TotalSincrono *ui;
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
    int CierreTotal;
    sincrono *Sincro;
    int cantidad;    
    int ActualRow;
    QString Ref;
    Omision *Omitir;
    QString Stilo;
    QString log;
    Ayuda *ayuda;
    QString Idioma;

private slots:
    void on_pushButton_12_clicked();
    void inicio();
    void on_pushButton_10_clicked();
    void cambiaFila(QModelIndex actual);
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_14_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);

};

#endif // TOTALSINCRONO_H
