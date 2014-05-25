#ifndef DBCLAVES_H
#define DBCLAVES_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "desbloquear.h"
#include "importar.h"
#include "ordenar.h"
#include <QPen>
#include "ayuda.h"

class QPrinter;

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
    void on_pushButton_12_clicked();
    void on_pushButton_5_clicked();
    void orden();
    void on_comboBox_currentIndexChanged(QString busca);
    void on_pushButton_9_clicked();
    void Cambiar();
    void on_lineEdit_11_textChanged(const QString &arg1);
    void on_lineEdit_12_textChanged(const QString &arg1);
    void on_lineEdit_13_textChanged(const QString &arg1);
    void on_lineEdit_14_textChanged(const QString &arg1);
    void on_lineEdit_15_textChanged(const QString &arg1);

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
    Ayuda *ayuda;
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
    QFont font;
    QColor color, color1;
    QPen pen;
    QPen pen1;
    QString NomOrden;
    QString DesencriptarUser(QString Userid, QString Enc1, QString Enc2, QString Enc3, int Tipo);

};

#endif // DBCLAVES_H
