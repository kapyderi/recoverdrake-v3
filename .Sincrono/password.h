#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
    class password;
}

class password : public QDialog {
    Q_OBJECT
public:
    password(QWidget *parent = 0);
    ~password();
    void Dato(QString valor);
    QString DatoUser;
    QString DatoPregunta;
    QString Local;
    QSqlDatabase db;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::password *ui;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QString Stilo;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

};

#endif // PASSWORD_H
