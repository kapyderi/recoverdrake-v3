#ifndef TEXTENCRIP_H
#define TEXTENCRIP_H

#include <QDialog>
#include "ayuda.h"
#include <QSqlDatabase>
#include <QGraphicsScene>
#include <QTextCursor>

namespace Ui {
class textencrip;
}

class textencrip : public QDialog
{
    Q_OBJECT

public:
    explicit textencrip(QWidget *parent = 0);
    ~textencrip();
    void Valor(QString valor, QString Logs);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_5_clicked();
    void on_fontComboBox_2_currentIndexChanged(const QString &arg1);
    void on_sizeSpin_2_valueChanged(const QString &arg1);
    void on_btnBold_2_toggled(bool checked);
    void Comprobar();
    void on_textEdit_2_textChanged();
    void Comprobar1();
    void on_btnItalic_2_toggled(bool checked);

    void on_btnUnder_2_toggled(bool checked);

    void on_btnColor_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_btnLeft_2_clicked();

    void on_btnCenter_2_clicked();

    void on_btnRigth_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::textencrip *ui;
    Ayuda *ayuda;
    QSqlDatabase db;
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
    QString Log;
    QTextCursor cursor;
    QString user;

};

#endif // TEXTENCRIP_H
