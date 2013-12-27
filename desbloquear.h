#ifndef DESBLOQUEAR_H
#define DESBLOQUEAR_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
    class Desbloquear;
}

class Desbloquear : public QDialog {
    Q_OBJECT
public:
    Desbloquear(QWidget *parent = 0);
    ~Desbloquear();
    bool correcto;
    QString Resultado;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Desbloquear *ui;
    QString Usuario;
    QSqlDatabase db;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // DESBLOQUEAR_H
