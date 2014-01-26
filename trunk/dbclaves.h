#ifndef DBCLAVES_H
#define DBCLAVES_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "desbloquear.h"
#include "importar.h"
#include "ordenar.h"

namespace Ui {
class dbclaves;
}

class dbclaves : public QDialog
{
    Q_OBJECT
    
public:
    explicit dbclaves(QWidget *parent = 0);
    ~dbclaves();
    void Valor(QString valor);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);
    
private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::dbclaves *ui;
    QSqlTableModel *Model;
    QSqlDatabase db;
    int id;
    int fila;
    QString user;
    QString fileNameOrigen;
    QString Cantidad;
    QString DatoRev;
    Desbloquear *pass;
    ordenar *Orden;
    importar *import;
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

#endif // DBCLAVES_H
