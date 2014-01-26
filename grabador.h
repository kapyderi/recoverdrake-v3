#ifndef GRABADOR_H
#define GRABADOR_H

#include <QDialog>
#include <QSqlDatabase>
#include "drakeprocesos1.h"
#include "ayuda.h"
#include <QTimer>
#include "phonon/MediaObject"
#include "phonon/AudioOutput"
#include <phonon/Effect>
#include "sonido.h"
#include <QDateTime>
#include <QTimer>

namespace Ui {
class Grabador;
}

class Grabador : public QDialog
{
    Q_OBJECT
    
public:
    explicit Grabador(QWidget *parent = 0);
    ~Grabador();
    void Valor(QString valor, QString Logs, Phonon::MediaObject *mediaObject, Phonon::AudioOutput *audioOutput, Phonon::Path path, Phonon::Effect *effect);

protected:
   void closeEvent(QCloseEvent *event);
   virtual bool eventFilter(QObject *, QEvent *);

signals:
   void Cerrar();

private slots:
   void mibFin();
   void mibEscribir(QString valor);
   void on_pushButton_clicked();
   void Ecualizar(QString Valor, int band1, int band2, int band3, int band4, int band5, int band6, int band7, int band8, int band9, int band10);
   void on_pushButton_4_clicked();
   void on_pushButton_5_clicked();
   void on_lineEdit_textChanged(const QString &arg1);
   void on_pushButton_3_clicked();
   void on_pushButton_12_clicked();
   void update();
   void on_pushButton_14_clicked();
   void on_pushButton_6_clicked();
   void on_pushButton_15_clicked();
   void final();
   void on_pushButton_2_clicked();
   void Comprobar();
   void Comprobar1();
   void Comprobar2();
   void Explorar();
   void on_pushButton_7_clicked();
   void KillProceso();
   void on_pushButton_11_clicked();
   void on_pushButton_8_clicked();
   void on_pushButton_16_clicked();
   void on_tableWidget_itemSelectionChanged();
   void on_pushButton_9_clicked();
   void on_pushButton_10_clicked();
   void on_spinBox_valueChanged(int arg1);
   void on_spinBox_2_valueChanged(int arg1);
   void on_spinBox_12_valueChanged(int arg1);
   void on_spinBox_6_valueChanged(int arg1);
   void on_spinBox_4_valueChanged(int arg1);
   void on_spinBox_5_valueChanged(int arg1);
   void on_spinBox_7_valueChanged(int arg1);
   void on_spinBox_8_valueChanged(int arg1);
   void on_spinBox_10_valueChanged(int arg1);
   void on_spinBox_11_valueChanged(int arg1);
   void hora();
   void on_pushButton_13_clicked();
   void CtrlRec();
   void CtrlFin();
   void EjecutarTempo();

private:
    Ui::Grabador *ui;
    QString user;
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
    Ayuda *ayuda;
    DrakeProcesos1 *mib;
    int TotalProceso;
    Phonon::Effect *Effect;
    Phonon::MediaObject *MediaObject;
    Phonon::AudioOutput *AudioOutput;
    Phonon::Path Path;
    QString fileName;
    QTimer *timer;
    int iTcrs;
    QString LocSinkM();
    QString LocSinkD();
    QDateTime time;
    QString Dia, Dia1;
    QString Mes, Mes1;
    QString Anyo, Anyo1;
    QString Hora, Hora1;
    QString Minuto, Minuto1;
    QString Segundo, Segundo1;
    QString Revisar(QDateTime HoraI, int ValorI, int Posicion);
    QTimer *timer1;
    int Desbloqueo, Desbloqueo1;
    int Graba;
    QTimer *ControlRec;
    QTimer *ControlFin;
    QDateTime Inicio;
    QDateTime Final;
    QString PathI;
    QString Source;
    int Control;

};

#endif // GRABADOR_H
