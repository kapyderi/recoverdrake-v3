#ifndef TERMINAL_H
#define TERMINAL_H

#include <QDialog>
#include "qtermwidget.h"

namespace Ui {
class Terminal;
}

class Terminal : public QDialog
{
    Q_OBJECT

public:
    explicit Terminal(QWidget *parent = 0);
    ~Terminal();

private:
    Ui::Terminal *ui;
    QTermWidget *consola;
    QString User;
    QFont font ;

private slots:
    void finalizar();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void closeTab(int index);

};

#endif // TERMINAL_H
