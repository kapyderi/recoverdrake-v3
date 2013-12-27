#ifndef TORRENTS_H
#define TORRENTS_H

#include <QDialog>
#include "drakeprocesos.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>

namespace Ui {
    class torrents;
}

class torrents : public QDialog {
    Q_OBJECT
public:
    torrents(QWidget *parent = 0);
    ~torrents();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::torrents *ui;
    QString fileNameOrigen;
    QString fileNameDirectori;
    QString user;
    DrakeProcesos *mib;
    void crearIcono();
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    void setIcono();
    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    void crearAcciones();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void Comprobar();
    void mibFin();
    void mibEscribir(QString valor);
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

};

#endif // TORRENTS_H
