#ifndef IMPORTAR_H
#define IMPORTAR_H

#include <QDialog>
#include <QSqlDatabase>
#include "separador.h"

namespace Ui {
class importar;
}

class importar : public QDialog
{
    Q_OBJECT
    
public:
    explicit importar(QWidget *parent = 0);
    ~importar();
    void Valor(QStringList datos, int Tipo, QString Usuario);
    QString Resultado;
    QStringList Recepcion;
    QStringList Emision;
    QString Receptor;
    QString Prueba;
    QString ReceptorComp;
    QStringList RDatos;
    QString titulo,titulo1,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico;
    QString policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis;
    QString soporte,posicion,visionada,duracion,color,vose,formato,director;
    Separador *Separa;
    QString SaltoLine;
    QString SaltoDat;
    int Control;
    
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::importar *ui;
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
    int Base;
    QString User;
    int Cambio;

};

#endif // IMPORTAR_H
