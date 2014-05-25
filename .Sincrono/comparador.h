#ifndef COMPARADOR_H
#define COMPARADOR_H

#include <QDialog>
#include <QSqlDatabase>
#include <QTableWidgetItem>
#include "ayuda.h"

namespace Ui {
class Comparador;
}

class Comparador : public QDialog
{
    Q_OBJECT
    
public:
    explicit Comparador(QWidget *parent = 0);
    ~Comparador();
    void Valor(QString valor, QString Logs);

signals:
    void Cerrar();

protected:
    void closeEvent(QCloseEvent *event);
    virtual bool eventFilter(QObject *, QEvent *);
    
private slots:
    void on_pushButton_clicked();
    void Comprobar();
    void Comprobar1();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_6_clicked();
    void on_tableWidget_itemSelectionChanged();
    void on_pushButton_12_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_14_clicked();

private:
    Ui::Comparador *ui;    
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
    QString user;
    QString Stilo;
    QString Log;
    Ayuda *ayuda;
    int Evento;
    QList<QTableWidgetItem *> itemsa;
    QList<QTableWidgetItem *> items;
    QList<QTableWidgetItem *> items1;
    QList<QTableWidgetItem *> items2;
    int Tipo;

};

#endif // COMPARADOR_H
