#ifndef QRCODE_H
#define QRCODE_H

#include <QDialog>
#include "QR/qrwidget.h"
#include <QHash>
#include "ayuda.h"
#include <QSqlDatabase>

namespace Ui {
class qrcode;
}

class qrcode : public QDialog
{
    Q_OBJECT

public:
    explicit qrcode(QWidget *parent = 0);
    ~qrcode();
    void Valor(QString valor);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::qrcode *ui;
    QRWidget  *qr;
    QString path;
    QString saveMessage;
    QHash<QString, QString> extByMessage;
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

};

#endif // QRCODE_H
