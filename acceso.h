#ifndef ACCESO_H
#define ACCESO_H

#include <QDialog>
#include <QSqlTableModel>
#include <QKeyEvent>
#include <password.h>
#include <QSqlDatabase>
#include "ayuda.h"
#include <QTimer>

namespace Ui {
    class acceso;
}

class acceso : public QDialog {
    Q_OBJECT
public:
    acceso(QWidget *parent = 0);
    ~acceso();
    bool correcto;
    QString Usuar;
    QString Nucleo;
    QString Distro;
    QString Serial;
    QString Clave;
    QString Comp;
    QString Ver;
    QString ContraClave;
    QString Clav;

protected:
    void changeEvent(QEvent *e);
    void keyPressEvent( QKeyEvent* e );
    void tecla();
    void User();
    virtual bool eventFilter(QObject *, QEvent *);

private:
    Ui::acceso *ui;
    QSqlTableModel *Model;
    int contador; 
    QString Nivel;
    QString getCaps();
    QString getSerial();
    password *pass;
    QSqlDatabase db;
    QString calculo(QString Serie);
    QString sustituir(int num1);
    QString sustituir1(QString Valor);
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    int Valor;
    QString Stilo;
    QString CapsLock;
    Ayuda *ayuda;
    QString Valor1;
    QString Valor4;
    QString Valor5;
    int Registro;
    int Limitacion;
    QTimer *timer;

private slots:         
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();    
    void on_comboBox_currentIndexChanged();
    int randInt(int low, int high);
    void on_pushButton_4_clicked();
    void ramdomize();
    void Comprobar();
    void Mostrar();
    void Mostrar1();   
    void on_lineEdit_2_textChanged(QString Value);
    void Spanish();
    void English();
    void Cambiar();
    void hora();

};

#endif // ACCESO_H
