#ifndef ID3MP3_H
#define ID3MP3_H

#include <QDialog>
#include <QSqlDatabase>
#include "drakeprocesos1.h"
#include "ayuda.h"
#include <QTimer>
#include "phonon/MediaObject"
#include "phonon/AudioOutput"
#include <phonon/Effect>
#include "sonido.h"

namespace Ui {
    class id3mp3;
}

class id3mp3 : public QDialog
{
    Q_OBJECT

public:
    explicit id3mp3(QWidget *parent = 0);
    ~id3mp3();
     void Valor(QString valor, QString Logs, Phonon::MediaObject *mediaObject, Phonon::AudioOutput *audioOutput, Phonon::Path path, Phonon::Effect *effect);

protected:
    void closeEvent(QCloseEvent *event);
    virtual bool eventFilter(QObject *, QEvent *);

signals:
    void Cerrar();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void Comprobar();
    void Comprobar1();
    void Comprobar2();
    void Comprobar3();
    void mibFin();
    void mibEscribir(QString valor);
    void ProcesarValor(QString ValorComand);
    void update();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_5_clicked();
    void Ecualizar(QString Valor, int band1, int band2, int band3, int band4, int band5, int band6, int band7, int band8, int band9, int band10);
    void on_pushButton_4_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void Analizar();
    void on_tableWidget_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void final();
    void Comprobar4();
    void Comprobar5();
    void Comprobar6();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_24_clicked();
    void Ordenando();

private:
    Ui::id3mp3 *ui;
    QString user;
    QString mp3Title;
    QString mp3Artist;
    QString mp3Album;
    QString mp3Year;
    QString mp3Comment;
    QString mp3Track;
    QString mp3Genre;
    QString Valmp3Title;
    QString Valmp3Artist;
    QString Valmp3Album;
    QString Valmp3Year;
    QString Valmp3Comment;
    QString Valmp3Track;
    QString Valmp3Genre;
    QString fileNameOrigen;
    QString fileName2;
    QString fileName1;
    QString ruta;
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
    QTimer *timer;
    QString Audio;
    QString Calidad;
    Phonon::Effect *Effect;
    Phonon::MediaObject *MediaObject;
    Phonon::AudioOutput *AudioOutput;
    int Evento;
    Phonon::Path Path;
    QStringList listaArchivos;
    int Totalizar;
    int ControlNum;
    int Ordenar;
    QString getDisc(QString Valor);
    QString OtroDirectorio;

};

#endif // ID3MP3_H
