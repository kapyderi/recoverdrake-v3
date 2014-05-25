#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

#include <QDialog>
#include <QTimer>
#include <QMouseEvent>
#include <QSqlDatabase>
#include "phonon/MediaObject"
#include "phonon/AudioOutput"
#include <phonon/Effect>
#include "ayuda.h"

namespace Ui {
    class Reproductor;
}

class Reproductor : public QDialog {
    Q_OBJECT
public:
    Reproductor(QWidget *parent = 0);
    ~Reproductor();
    void Valor(Phonon::MediaObject *mediaObject, Phonon::AudioOutput *audioOutput, Phonon::Path path, Phonon::Effect *effect);

protected:
    void changeEvent(QEvent *e);
    virtual bool event( QEvent* e );
    virtual bool eventFilter(QObject *obj, QEvent *event);
    virtual void mouseDoubleClickEvent( QMouseEvent* );
    void mouse();

private:
    Ui::Reproductor *ui;
    QString listaArchivos;
    QString user;
    QTimer *timer;
    QString Peli;
    QTimer *Contador;
    QSqlDatabase db;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    int w;
    int h;
    QString Value;
    Phonon::Effect *Effect;
    Phonon::MediaObject *MediaObject;
    Phonon::AudioOutput *AudioOutput;
    Phonon::Path Path;
    QString Stilo;
    Ayuda *ayuda;

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void update();
    void Comprobar();

};

#endif // REPRODUCTOR_H
