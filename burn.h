#ifndef BURN_H
#define BURN_H

#include <QDialog>
#include "localizador.h"
#include "drakeprocesos1.h"
#include <QSqlDatabase>
#include <QFileSystemModel>
#include <QTimer>

namespace Ui {
    class burn;
}

class burn : public QDialog {
    Q_OBJECT
public:
    burn(QWidget *parent = 0);
    ~burn();    
    QString getSize(QString Dir);
    QString getMulti();
    void Valor(QString valor);
    QFileSystemModel *model;
    QTimer *Contador;

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void closeEvent(QCloseEvent *event);

private:
    Ui::burn *ui;      
    QStringList listaArchivos;
    float tamanio;
    float limite;
    QString user;
    QString velocidad;
    QString Dev;
    QString resolucion;
    QString Audio;
    DrakeProcesos1 *mib;
    QString getPack();
    QString getInfo();
    QString getInfo1();   
    QString getDir();
    QString getCDRom();
    QString cdrdao;
    QString cdrkit;
    QString ffmpeg;
    QString dvdauthor;
    QString dvdrwtools;
    QString vcdimager;
    QString cdparanoia;
    QString dvdbackup;
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
    int CierreTotal;
    int Opcion;
    QString Peso;
    QString Tipo;
    QString Localizado;
    int Estado;
    QString Grabando;
    QString Directorio;
    QString TipoMedio;
    QString TipCD;
    QString Multi;
    QString Sesion;
    int Libre;
    int Inicio;
    int Fin;
    QString compara;
    int Copia;
    int Counter;
    QString path;
    QString Distro;
    QString dist;
    QString Localizar;

private slots:
    void on_pushButton_20_clicked();
    void on_comboBox_2_currentIndexChanged(QString );
    void on_pushButton_19_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_pushButton_18_clicked();
    void on_pushButton_14_clicked();
    void on_groupBox_7_clicked();
    void on_checkBox_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_13_clicked();
    void on_comboBox_currentIndexChanged(QString );
    void on_pushButton_16_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void mibprogreso(QString Dat);
    void Refrescar();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void Recuento();
    void Contar();
    void Refresco();
    void Info();
    void Comprobar();
    void Value(QString Valor);
    void Cargar(QString Valor);
    void Comprobar1();
    void Comprobar2();
    void Comprobar3();
    void Comprobar4();
    void Comprobar5();

};

#endif // BURN_H
