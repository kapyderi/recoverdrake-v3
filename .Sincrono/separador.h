#ifndef SEPARADOR_H
#define SEPARADOR_H

#include <QDialog>

namespace Ui {
class Separador;
}

class Separador : public QDialog
{
    Q_OBJECT
    
public:
    explicit Separador(QWidget *parent = 0);
    ~Separador();
    void Valor(QString datos);
    QString SaltoDato;
    QString Separa;
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Separador *ui;  

};

#endif // SEPARADOR_H
