#ifndef DBPELIS_H
#define DBPELIS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "desbloquear.h"
#include "importar.h"
#include "ordenar.h"

namespace Ui {
    class dbpelis;
}

class dbpelis : public QDialog {
    Q_OBJECT
public:
    dbpelis(QWidget *parent = 0);
    ~dbpelis();
    void Valor(QString valor, QString Usuario);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private:
    Ui::dbpelis *ui;
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
    QString IDUser;
//    QFont font;
//    QColor color, color1;
//    QPen pen;
//    QPen pen1;

private slots:
    void on_pushButton_12_clicked();
    void cambiaFila(QModelIndex actual);
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();
    void on_comboBox_currentIndexChanged(QString busca);
    void inicio();
    void orden();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_2_clicked();
    //void imprimir(QPrinter*, QString Orden, QString Fuente, QString Color, QString Color2);

};

#endif // DBPELIS_H
