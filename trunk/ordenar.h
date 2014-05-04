#ifndef ORDENAR_H
#define ORDENAR_H

#include <QDialog>

namespace Ui {
class ordenar;
}

class ordenar : public QDialog
{
    Q_OBJECT
    
public:
    explicit ordenar(QWidget *parent = 0);
    ~ordenar();
    QFont TLetra;
    QColor TColor, TColor1;
    QString NOrden;
    void Dato(QString valor);
    
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::ordenar *ui;
    QString Tipo;
};

#endif // ORDENAR_H
