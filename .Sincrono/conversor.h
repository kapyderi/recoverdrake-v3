#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <QDialog>
#include <drakeprocesos.h>
#include <QTimer>
#include <QSqlDatabase>
#include "phonon/MediaObject"
#include "phonon/AudioOutput"
#include <phonon/Effect>

namespace Ui {
    class Conversor;
}

class Conversor : public QDialog {
    Q_OBJECT
public:
    Conversor(QWidget *parent = 0);
    ~Conversor();
    void Valor(QString valor, Phonon::MediaObject *mediaObject, Phonon::AudioOutput *audioOutput, Phonon::Path path, Phonon::Effect *effect);

signals:
    void Cerrar();

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);
    void closeEvent(QCloseEvent *event);

private:
    Ui::Conversor *ui;
    QStringList listaArchivos;
    QString user;
    QString Video;
    QString Audio;
    QString Resolucion;
    QString Formato;
    QString Peso;
    DrakeProcesos *mib;
    QString Value;
    QString DatoVideo;
    QString Calidad;
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
    int CierreTotal;
    Phonon::Effect *Effect;
    Phonon::MediaObject *MediaObject;
    Phonon::AudioOutput *AudioOutput;
    Phonon::Path Path;
    QString Stilo;

private slots:
    void on_comboBox_currentIndexChanged(QString seleccion);
    void on_pushButton_6_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_2_clicked();
    void mibFin();
    void mibEscribir(QString valor);
    void ProcesarValor(QString ValorComand);
    void mibprogreso(QString Dat);
    void tableClicked(int row, int column);
    void update();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();

};

#endif // CONVERSOR_H
