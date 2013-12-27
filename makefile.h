#ifndef MAKEFILE_H
#define MAKEFILE_H

#include <QDialog>
#include "drakeprocesos.h"
#include <QSqlDatabase>

namespace Ui {
class makefile;
}

class makefile : public QDialog
{
    Q_OBJECT
    
public:
    explicit makefile(QWidget *parent = 0);
    ~makefile();
    void Valor(QString valor);

protected:
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

signals:
    void Cerrar();
    
private slots:
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
    void Instalar();
    void Desinstalar();
    void on_pushButton_3_clicked();
    void Comprobar();
    void mibFin();
    void mibEscribir(QString valor);
    void Instalacion();
    void Desinstalacion();

private:
    Ui::makefile *ui;
    QString fileNameOrigen;
    QString user;
    DrakeProcesos *mib;
    QString Valor1;
    QString Valor2;
    QString fileNameDirectori;
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
    QString getName(QString Validar);
    QString Stilo;

};

#endif // MAKEFILE_H
