#ifndef BUSCA_H
#define BUSCA_H

#include <QDialog>
#include "drakeprocesos.h"
#include <QModelIndex>
#include <QTimer>
#include <QSqlDatabase>

namespace Ui {
    class Busca;
}

class Busca : public QDialog {
    Q_OBJECT
public:
    Busca(QWidget *parent = 0);
    ~Busca();
    QString user;
    QStringList lista;
    int Control;
    QString Tipo;
    QTimer *Contador;
    void Value(int value);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private:
    Ui::Busca *ui;
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
    QString Stilo;
    int CierreTotal;
    int Opcion;
    QString Peso();
    QString dato;

private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void on_tableWidget_doubleClicked(const QModelIndex &index);
    void Comprobar();
    void Verificar();
    void on_pushButton_2_clicked();
    void Contar();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void Menu();
};

#endif // BUSCA_H
