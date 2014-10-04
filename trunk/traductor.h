#ifndef TRADUCTOR_H
#define TRADUCTOR_H

#include <QDialog>
#include "ayuda.h"
#include <QSqlDatabase>
#include "terminal.h"

namespace Ui {
class Traductor;
}

class Traductor : public QDialog
{
    Q_OBJECT

public:
    explicit Traductor(QWidget *parent = 0);
    ~Traductor();
    void Valor(QString valor);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Traductor *ui;
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
    QSqlDatabase db;
    QString user;
    Terminal *termino;

};

#endif // TRADUCTOR_H
