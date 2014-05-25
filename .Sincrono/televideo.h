#ifndef TELEVIDEO_H
#define TELEVIDEO_H

#include <QDialog>
#include <QModelIndex>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include "phonon/MediaObject"
#include "phonon/AudioOutput"
#include <phonon/Effect>
#include "ayuda.h"

namespace Ui {
    class Televideo;
}

class Televideo : public QDialog {
    Q_OBJECT
public:
    Televideo(QWidget *parent = 0);
    ~Televideo();
    void Valor(Phonon::MediaObject *mediaObject, Phonon::AudioOutput *audioOutput, Phonon::Path path, Phonon::Effect *effect);

protected:
    void changeEvent(QEvent *e);
    virtual void mouseDoubleClickEvent( QMouseEvent* );
    virtual bool eventFilter(QObject *obj, QEvent *event);
    virtual bool event( QEvent* e );
    void mouse();

private slots:
    void on_pushButton_7_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void cambiaFila(QModelIndex actual);
    void tableClicked();
    void play();
    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void Comprobar();

private:
    Ui::Televideo *ui;
    QSqlTableModel *Model;
    QSqlTableModel *Model1;
    QString Emisora;
    int ActualRow;
    int filaVideo;
    int id;
    int w;
    int h;
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
    Phonon::Effect *Effect;
    Phonon::MediaObject *MediaObject;
    Phonon::AudioOutput *AudioOutput;
    Phonon::Path Path;
    QString Value;
    QString Stilo;
    Ayuda *ayuda;

};

#endif // TELEVIDEO_H
