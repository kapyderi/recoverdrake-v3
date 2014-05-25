#ifndef USBLIVE_H
#define USBLIVE_H

#include <QDialog>
#include <QTableWidgetItem>
#include "drakeprocesos.h"
#include <QSqlDatabase>

namespace Ui {
    class UsbLive;
}

class UsbLive : public QDialog
{
    Q_OBJECT

public:
    explicit UsbLive(QWidget *parent = 0);
    ~UsbLive();

private slots:
    void on_pushButton_23_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_17_clicked();
    void Multiboot();
    void on_pushButton_21_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_18_clicked();
    void on_tableWidget_itemSelectionChanged();
    void on_tabWidget_currentChanged(int index);
    void on_pushButton_6_clicked();
    void on_pushButton_9_clicked();
    void UsbInfo();
    void on_pushButton_11_clicked();
    void on_pushButton_7_clicked();
    void on_checkBox_clicked();
    void on_checkBox_2_clicked();
    void on_checkBox_3_clicked();
    void on_checkBox_4_clicked();
    void on_checkBox_5_clicked();
    void on_checkBox_6_clicked();
    void on_checkBox_7_clicked();
    void on_checkBox_19_clicked();
    void on_checkBox_9_clicked();
    void on_checkBox_8_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_6_clicked();
    void on_radioButton_10_clicked();
    void on_radioButton_clicked();
    void on_radioButton_5_clicked();
    void on_radioButton_9_clicked();
    void on_radioButton_13_clicked();
    void on_radioButton_14_clicked();
    void on_radioButton_17_clicked();
    void on_radioButton_18_clicked();
    void on_radioButton_39_clicked();
    void on_radioButton_40_clicked();
    void on_radioButton_43_clicked();
    void on_radioButton_44_clicked();
    void on_radioButton_55_clicked();
    void on_radioButton_56_clicked();
    void on_radioButton_51_clicked();
    void on_radioButton_52_clicked();
    void on_radioButton_47_clicked();
    void on_radioButton_48_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_12_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void mibReferencia(QString comando);    
    void mibprogreso(QString Dat);
    void Arranque();
    void ProbarUSB();
    void tableClicked(int row, int column);
    void Enable();
    void Disabled();

private:
    Ui::UsbLive *ui;
    QString user;
    QString Distro;
    QString Media;
    QString fileName;
    QString fileName1;
    QString fileName2;
    QString fileName3;
    QString fileName4;
    QString fileName5;
    QString fileName6;
    QString fileName7;
    QString fileName8;
    QString fileName9;
    QStringList Lista;
    QString Value0;
    QStringList Valor;
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
    int Duplicado;    
    QString getTalla(QString Peso);
    QString getTree(QString Tree);
    QString getLs(QString ruta, QString Dato);
    QString getGrub(QString grub);
    QString getIso(QString iso);
    QString DatoComand;
    DrakeProcesos *mib;
    QString grub2;
    QString getPack();
    int Control;
    QStringList comandos;
    QString Tamano;
    QString activo1, activo2, activo3, activo4, activo5;
    QStringList grub;
    QStringList LeeIso;
    QString DistroTip;
    float TamanoTotal;
    QString TipMandriva;
    QString TipPCLinuxOS;
    QString TipFedora;
    QString TipUbuntu;
    QString TipArchLinux;
    QString TipCentOS;
    QString TipDebian;
    QString TipKnoppix;
    QString TipOpenSUSE;
    QString TipLinuxMint;
    QString LabelOld;
    QString getCompara(QString Valor, QString Ruta);
    QString getDistroIns(QString dev, QString distro);
    int Ctrl;
    QString Valor1;
    int Marcado;
    QString qemu;
    QStringList MdCfg;
    QStringList PlCfg;
    QStringList FdCfg;
    QStringList UbCfg;
    QStringList AlCfg;
    QStringList CtCfg;
    QStringList DbCfg;
    QStringList KnCfg;
    QStringList OsCfg;
    QStringList LmCfg;
    QStringList MenuCfg;
    QSqlDatabase db;
    QString fileNameDirectori;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QString dist;
    QString ruta;
    QString Localizar;
    QString Stilo;

};

#endif // USBLIVE_H
