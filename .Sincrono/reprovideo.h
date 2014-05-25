#ifndef REPROVIDEO_H
#define REPROVIDEO_H

#include <QDialog>
#include <QTimer>
#include <QMouseEvent>

namespace Ui {
    class ReproVideo;
}

class ReproVideo : public QDialog {
    Q_OBJECT
public:
    ReproVideo(QWidget *parent = 0);
    ~ReproVideo();

protected:
    void changeEvent(QEvent *e);
    virtual bool event( QEvent* e );
    virtual bool eventFilter(QObject *obj, QEvent *event);
    virtual void mouseDoubleClickEvent( QMouseEvent* );
    void mouse();

private:
    Ui::ReproVideo *ui;
    QString listaArchivos;
    QString user;
    QTimer *timer;
    QString Peli;
    QTimer *Contador;

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

#endif // REPROVIDEO_H
