#ifndef NOTAS_H
#define NOTAS_H

#include <QDialog>

namespace Ui {
    class notas;
}

class notas : public QDialog {
    Q_OBJECT
public:
    notas(QWidget *parent = 0);
    ~notas();
     QString Ultimo;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::notas *ui;
    QString user;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
};

#endif // NOTAS_H
