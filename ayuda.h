#ifndef AYUDA_H
#define AYUDA_H

#include <QDialog>
#include "ayuda.h"

namespace Ui {
class Ayuda;
}

class Ayuda : public QDialog
{
    Q_OBJECT
    
public:
    explicit Ayuda(QWidget *parent = 0);
    ~Ayuda();
    void Valor(QString valor);
    
private slots:
    void on_pushButton_clicked();
    void on_listWidget_currentTextChanged(const QString &currentText);
    void on_lineEdit_textChanged(const QString &arg1);
    void on_listWidget_2_currentTextChanged(const QString &currentText);    
    void Comprobar();

private:
    Ui::Ayuda *ui;
    int Pestana;
    QStringList indice;
    Ayuda *ayuda;

};

#endif // AYUDA_H
