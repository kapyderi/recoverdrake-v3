#include "torrents.h"
#include "ui_torrents.h"
#include <QFileDialog>
#include "drakesistema.h"

torrents::torrents(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::torrents)
{
    ui->setupUi(this);
    mib=0;
    drakeSistema drake;
    user = drake.getUser();
    ui->radioButton->setChecked(true);
    ui->lineEdit->setEnabled(true);
    ui->radioButton_2->setChecked(false);
    ui->lineEdit_2->setEnabled(false);
    ui->radioButton_3->setChecked(false);
    ui->lineEdit_3->setEnabled(false);
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Comprobar()));    
    crearAcciones();
    this->crearIcono();
    trayIcon->show();
    this->setIcono();
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

torrents::~torrents()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void torrents::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void torrents::on_pushButton_4_clicked()
{
    close();
}

void torrents::on_pushButton_clicked()
{
    QString path="/home/%1/Documentos/";
    path=path.arg(user);
    fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo torrent")),
                        path,trUtf8(tr("Archivo torrent (*.torrent)")));
    if (fileNameOrigen.isEmpty())
        return;
    ui->lineEdit->setText(fileNameOrigen);
}

void torrents::on_pushButton_2_clicked()
{
    QString path="/home/%1/Documentos/";
    path=path.arg(user);
    fileNameDirectori = QFileDialog::getExistingDirectory(this,QString::fromUtf8(tr("Que directorio utilizar?")),path,QFileDialog::ShowDirsOnly);
    if (fileNameDirectori.isEmpty())
        return;
    ui->lineEdit_4->setText(fileNameDirectori);
}

void torrents::Comprobar()
{
    if (ui->radioButton->isChecked() == true)
    {
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_3->setEnabled(false);
    }
    if (ui->radioButton_2->isChecked() == true)
    {
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(true);
        ui->lineEdit_3->setEnabled(false);
    }
    if (ui->radioButton_3->isChecked() == true)
    {
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_3->setEnabled(true);
    }
}

void torrents::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
}

void torrents::mibEscribir(QString valor)
{

}

void torrents::crearIcono()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
}

void torrents::setIcono()
{
    trayIcon->setIcon(QIcon(":/Imagenes/drak.png"));
}

void torrents::crearAcciones()
{
         minimizeAction = new QAction(tr("Mi&nimize"), this);
         connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

         maximizeAction = new QAction(QString::fromUtf8(tr("Ma&ximize")),this);
         connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

         restoreAction = new QAction(QString::fromUtf8(tr("&Restore")),this);
         connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

         quitAction = new QAction(QString::fromUtf8(tr("&Quit")), this);
         connect(quitAction, SIGNAL(triggered()), this, SLOT(Cerrar()));
}

void torrents::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
    case QSystemTrayIcon::DoubleClick:
        showNormal();
        break;
    default:;
    }
}

void torrents::on_pushButton_3_clicked()
{
    trayIconMenu->removeAction(quitAction);
    trayIcon->showMessage("KapTorrent a segundo plano",QString::fromUtf8(tr("La/s descarga/s seguiran corriendo en la bandeja del sistema.")),QSystemTrayIcon::Information, 3000);
    hide();
}
