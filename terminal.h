#ifndef TERMINAL_H
#define TERMINAL_H

#include <QDialog>
#include "qtermwidget.h"
#include "ayuda.h"
#include <QSqlDatabase>

namespace Ui {
class Terminal;
}

class Terminal : public QDialog
{
    Q_OBJECT

public:
    explicit Terminal(QWidget *parent = 0);
    ~Terminal();
    void Valor(QString valor);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private:
    Ui::Terminal *ui;
    QTermWidget *consola, *consola1, *consola2;
    QString User;
    QFont font;
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

private slots:
    void finalizar();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void closeTab(int index);
    void on_comboBox_2_currentIndexChanged(const QString &arg1);
    void on_fontComboBox_currentIndexChanged(const QString &arg1);

};

#endif // TERMINAL_H
