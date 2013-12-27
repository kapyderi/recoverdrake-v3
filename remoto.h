#ifndef REMOTO_H
#define REMOTO_H

#include <QDialog>
#include "drakeprocesos.h"
#include <QSqlDatabase>

namespace Ui {
class remoto;
}

class remoto : public QDialog
{
    Q_OBJECT
    
public:
    explicit remoto(QWidget *parent = 0);
    ~remoto();
    
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void mibFin();

private:
    Ui::remoto *ui;
    DrakeProcesos *mib;
    QString user;
    QSqlDatabase db;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;


};

#endif // REMOTO_H
