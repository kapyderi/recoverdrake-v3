#ifndef EXAMEN_H
#define EXAMEN_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class examen;
}

class examen : public QDialog
{
    Q_OBJECT
    
public:
    explicit examen(QWidget *parent = 0);
    ~examen();
    void Valor(QString valor);
    int Value;

signals:
    void Cerrar();

protected:
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);
    
private slots:
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
    void pregunta();
    void ramdom();
    void AccesoPregunta();
    void AccesoRamdom();
    void on_pushButton_3_clicked();

private:
    Ui::examen *ui;
    int Examen;
    QString CntTest;
    QString RespTest1;
    QString RespTest2;
    QString RespTest3;
    QSqlDatabase db;
    int Suma;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    int CierreTotal;
    int Siguiente;
    QString Stilo;

};

#endif // EXAMEN_H
