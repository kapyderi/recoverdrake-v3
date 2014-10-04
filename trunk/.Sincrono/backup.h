#ifndef BACKUP_H
#define BACKUP_H

#include <QDialog>
#include <QSqlDatabase>
#include "ayuda.h"

namespace Ui {
class Backup;
}

class Backup : public QDialog
{
    Q_OBJECT
    
public:
    explicit Backup(QWidget *parent = 0);
    ~Backup();
    void Valor(QString valor);

signals:
    void Cerrar();

protected:
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);
    
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void Comprobar();
    void on_pushButton_2_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void Comprobar1();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();

private:
    Ui::Backup *ui;
    QString user;
    QSqlDatabase db;
    QSqlDatabase DB;
    QSqlDatabase DBackup;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QString Backp;
    QString Corte, Eth, Idioma, Video, Fuente, Red, Miscelanea, Color, ConvAudio, Cancion, Canal, Radio, Checkeo, LReport;
    QString Registro, TamCorte, Correo, Skin, Velocidad, Vnc, Resolucion, Grabacion, Wifi, Control, Ecualizador, LMail;
    QString Menu, Chat, Vista, SVideo, Formato, LClave, LNwifi, LMusica, LBwifi, LRadio, LTelevision, LUser, LAccesos;
    QString LVnc, LPelis, LMenu, Estilo, LSincro, Lid3, Calculadora, LClaves, LAscii, Pais, LBic, LModelo, LLineas, LCampos, LDocument;
    int CierreTotal;
    QString Stilo;
    Ayuda *ayuda;

};

#endif // BACKUP_H
