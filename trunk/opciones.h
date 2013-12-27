#ifndef OPCIONES_H
#define OPCIONES_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlDatabase>

namespace Ui {
    class opciones;
}

class opciones : public QDialog {
    Q_OBJECT
public:
    opciones(QWidget *parent = 0);
    ~opciones();
    void iniciar();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::opciones *ui;
    QSqlTableModel *Model;
    QSqlTableModel *Model1;
    QSqlTableModel *Model2;
    QSqlTableModel *Model3;
    QSqlTableModel *Model4;
    QSqlTableModel *Model5;
    QSqlTableModel *Model6;
    QSqlTableModel *Model7;
    QSqlTableModel *Model8;
    QSqlTableModel *Model9;
    QSqlTableModel *Model10;
    QSqlTableModel *Model11;
    QSqlTableModel *Model12;
    QSqlTableModel *Model13;
    QSqlTableModel *Model14;
    QSqlTableModel *Model15;
    QSqlTableModel *Model16;
    QSqlTableModel *Model17;
    QSqlTableModel *Model18;
    QSqlTableModel *Model19;
    QSqlTableModel *Model20;
    QSqlTableModel *Model21;
    QSqlTableModel *Model22;
    int id;
    int fila;
    int fila1;
    int fila2;
    int fila3;
    int fila4;
    int fila5;
    int fila6;
    int fila7;
    int fila8;
    int fila9;
    int fila10;
    int fila11;
    int fila12;
    int fila13;
    int fila14;
    int fila15;
    int fila16;
    int fila17;
    int fila18;
    int fila19;
    QString cantidad;
    QString cantidad1;
    QString cantidad2;
    QString cantidad3;
    QString cantidad4;
    QString cantidad5;
    QString cantidad6;
    QString cantidad7;
    QString cantidad8;
    QString cantidad9;
    QString cantidad10;
    QString cantidad11;
    QString cantidad12;
    QString cantidad13;
    QString cantidad14;
    QString cantidad15;
    QString cantidad16;
    QString cantidad17;
    QString cantidad18;
    QString cantidad19;
    QString cantidad20;
    QString cantidad21;
    QString cantidad22;
    QString cantidad23;
    QString cantidad24;
    QString cantidad25;
    QString cantidad26;
    QString cantidad27;
    QString cantidad28;
    QString cantidad29;
    QString cantidad30;
    QString cantidad31;
    QString cantidad32;
    QString cantidad33;
    QString cantidad34;
    QString cantidad35;
    QString cantidad36;
    QString cantidad37;
    QString cantidad38;
    QString cantidad39;
    QString cantidad40;
    QString cantidad41;
    QString cantidad42;
    QString cantidad43;
    QString cantidad44;
    QString cantidad45;
    QString cantidad46;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString cantidad50;
    QString cantidad51;
    QString cantidad52;
    QString cantidad53;
    QString cantidad54;
    QString cantidad55;
    QString cantidad56;
    QString cantidad57;
    QString cantidad58;
    QString cantidad59;
    QString cantidad60;
    QString banda1;
    QString banda2;
    QString banda3;
    QString banda4;
    QString banda5;
    QString banda6;
    QString banda7;
    QString banda8;
    QString banda9;
    QString banda10;
    QString Cdrom;
    QString DatoTalla;
    QString DatoNegro;
    QString getPack();
    QString getPack1(QString Valor);
    QString Localizar;
    int Save;
    int Retro;
    QSqlDatabase db;
    QString user;
    QString Stilo;
    QString getRpm(QString Valor);

private slots:
    void changeStyle(QString stilo);
    void on_pushButton_10_clicked();
    void on_pushButton_9_clicked();
    void on_comboBox_2_currentIndexChanged(QString f);
    void on_comboBox_currentIndexChanged(QString f);
    void on_fontComboBox_currentFontChanged(QFont f);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void cambiaFila(QModelIndex actual);
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_8_clicked();
    void Eth();
    void Wlan();
    void Spanish();
    void English();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void Comprobar();
};

#endif // OPCIONES_H
