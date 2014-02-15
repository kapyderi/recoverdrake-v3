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
    void Valor(QString valor, QString Usuario);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);
    
private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void Comprobar();
    void on_comboBox_2_activated(const QString &arg1);
    void on_lineEdit_textChanged(const QString &arg1);
    int randInt(int low, int high);
    void ramdomize();
    void cambiaFila(QModelIndex actual);
    void on_lineEdit_2_textChanged(const QString &arg1);
    void on_lineEdit_6_textChanged(const QString &arg1);
    void Encriptar();
    void Desencriptar();
    void on_pushButton_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

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
    int Bloqueo;
    QString IDUser;

};

#endif // DBCLAVES_H
