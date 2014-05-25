#ifndef CLAVES_H
#define CLAVES_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlDatabase>

namespace Ui {
    class claves;
}

class claves : public QDialog {
    Q_OBJECT
public:
    explicit claves(QWidget *parent = 0);
    ~claves();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::claves *ui;
    QSqlTableModel *Model;
       int fila;
       int id;
    QString Cantidad;
    QString Cantidad1;
    int Administrador;
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

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void cambiaFila(QModelIndex actual);
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void Mostrar();
};

#endif // CLAVES_H
