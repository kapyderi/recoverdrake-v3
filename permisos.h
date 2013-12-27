#ifndef PERMISOS_H
#define PERMISOS_H

#include <QDialog>
#include "drakeprocesos.h"
#include <QSqlDatabase>

namespace Ui {
class Permisos;
}

class Permisos : public QDialog
{
    Q_OBJECT
    
public:
    explicit Permisos(QWidget *parent = 0);
    ~Permisos();
    
private:
    Ui::Permisos *ui;
    QString user;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QSqlDatabase db;
    DrakeProcesos *mib;
    QString LecturaU, LecturaG, LecturaO, EscrituraU, EscrituraG, EscrituraO, EjecucionU, EjecucionG, EjecucionO;
    QString Stilo;

private slots:
    void on_pushButton_clicked();
    void on_lineEdit_textChanged(QString );
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void Comprobar();
    void Revisar();
    void Verificar();
    void Permisive();

};

#endif // PERMISOS_H
