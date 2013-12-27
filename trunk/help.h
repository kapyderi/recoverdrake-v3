#ifndef HELP_H
#define HELP_H

#include <QDialog>

namespace Ui {
    class help;
}

class help : public QDialog {
    Q_OBJECT
public:
    help(QWidget *parent = 0);
    ~help();
    void Valor(QString valor);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::help *ui;
    int CierreTotal;
};

#endif // HELP_H
