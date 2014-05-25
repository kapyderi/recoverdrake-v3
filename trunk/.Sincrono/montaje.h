#ifndef MONTAJE_H
#define MONTAJE_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Montaje;
}

class Montaje : public QDialog
{
    Q_OBJECT
    
public:
    explicit Montaje(QWidget *parent = 0);
    ~Montaje();
    
private slots:
    void on_pushButton_7_clicked();
    void UsbInfo();

private:
    Ui::Montaje *ui;
    QString Media;
    QStringList Lista;
    QString Value1;
    QString Value2;
    QString Value3;
    QString Value4;
    QString Value5;
    QString Value6;
    QString Parte1;
    QString Parte2;
    QString Parte3;
    QString Peso;
    QString Value0;
    QStringList Valor;
    QString LabelOld;
    QString getTalla(QString Peso);
    QString activo1;
    QSqlDatabase db;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QString Stilo;

};

#endif // MONTAJE_H
