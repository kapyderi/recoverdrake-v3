#ifndef CONVAUDIO_H
#define CONVAUDIO_H

#include <QDialog>
#include <drakeprocesos.h>
#include <QTimer>
#include <QSqlDatabase>
#include "phonon/MediaObject"
#include "phonon/AudioOutput"
#include <phonon/Effect>
#include "sonido.h"

namespace Ui {
    class ConvAudio;
}

class ConvAudio : public QDialog
{
    Q_OBJECT

public:
    explicit ConvAudio(QWidget *parent = 0);
    ~ConvAudio();
    void Valor(QString valor, Phonon::MediaObject *mediaObject, Phonon::AudioOutput *audioOutput, Phonon::Path path, Phonon::Effect *effect);

signals:
     void Cerrar();

protected:
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private:
    Ui::ConvAudio *ui;
    int CierreTotal;
    QString user;
    DrakeProcesos *mib;
    QTimer *timer;
    QSqlDatabase db;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QString Audio;
    QString Calidad;
    Phonon::Effect *Effect;
    Phonon::MediaObject *MediaObject;
    Phonon::AudioOutput *AudioOutput;
    Phonon::Path Path;
    QString Stilo;

private slots:
    void Ecualizar(QString Valor, int band1, int band2, int band3, int band4, int band5, int band6, int band7, int band8, int band9, int band10);
    void on_pushButton_9_clicked();
    void on_pushButton_27_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void ProcesarValor(QString ValorComand);
    void mibprogreso(QString Dat);
    void update();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void tableClicked(int row, int column);
    void on_pushButton_24_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_clicked();
    void final();
};

#endif // CONVAUDIO_H
