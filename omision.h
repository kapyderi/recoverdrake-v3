#ifndef OMISION_H
#define OMISION_H

#include <QDialog>
#include <QSqlDatabase>
#include "ayuda.h"

namespace Ui {
class Omision;
}

class Omision : public QDialog
{
    Q_OBJECT
    
public:
    explicit Omision(QWidget *parent = 0);
    ~Omision();
    void Valor(QString Posicion);

protected:
    virtual bool eventFilter(QObject *, QEvent *);
    
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::Omision *ui;
    QString Nombre;
    QSqlDatabase db;
    QString Codigo;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QString Stilo;
    Ayuda *ayuda;

};

#endif // OMISION_H
