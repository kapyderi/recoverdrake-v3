#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog {
    Q_OBJECT
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
    QString Spain;
    QString English;
    QString Anterior;
    QString query2;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Dialog *ui;
    QSqlDatabase db;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
};

#endif // DIALOG_H
