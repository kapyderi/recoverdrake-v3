#ifndef SUBTITULOS_H
#define SUBTITULOS_H

#include <QDialog>
#include "drakeprocesos.h"
#include <QSqlDatabase>

namespace Ui {
    class Subtitulos;
}

class Subtitulos : public QDialog {
    Q_OBJECT
public:
    Subtitulos(QWidget *parent = 0);
    ~Subtitulos();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Subtitulos *ui;
    QString PeliOrigen;
    QString SubOrigen;
    QString PeliDestino;
    QString user;
    QString Peli;
    QString Sub;
    QString Final;
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

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void mibFin();
    void mibEscribir(QString valor);
};

#endif // SUBTITULOS_H
