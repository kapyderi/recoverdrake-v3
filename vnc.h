#ifndef VNC_H
#define VNC_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class vnc;
}

class vnc : public QDialog
{
    Q_OBJECT
    
public:
    explicit vnc(QWidget *parent = 0);
    ~vnc();
    
private slots:
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_lineEdit_2_editingFinished();
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();
    void Comprobar();
    void Comprobar1();
    void password();
    void password1();
    void cambiaFila(QModelIndex actual);

private:
    Ui::vnc *ui;
    QSqlTableModel *Model;
    QSqlTableModel *Model1;
    QString Cantidad;
    QString Cantidad1;
    QString Cantidad2;
    QString Cantidad3;
    QString Cantidad4;
    QString Cantidad5;
    QString Cantidad6;
    QString Cantidad7;
    QString Cantidad8;
    QString Cantidad9;
    QString Cantidad10;
    QString Cantidad11;
    QString user;
    QSqlDatabase db;
    int id;
    int fila;
    int Save;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QString Stilo;

};

#endif // VNC_H
