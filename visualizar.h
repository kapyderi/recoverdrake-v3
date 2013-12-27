#ifndef VISUALIZAR_H
#define VISUALIZAR_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlDatabase>

namespace Ui {
    class Visualizar;
}

class Visualizar : public QDialog {
    Q_OBJECT
public:
    Visualizar(QWidget *parent = 0);
    ~Visualizar();
    void Valor(QString valor, QString Tipo, QString ValorReg);

signals:
    void Cerrar();
    void Cerrando();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private:
    Ui::Visualizar *ui;
    QSqlTableModel *Model;
    QSqlDatabase db;
    int CierreTotal;
    int TipoS;

private slots:
    void on_pushButton_clicked();

};

#endif // VISUALIZAR_H
