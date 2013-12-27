#include "reprovideo.h"
#include "ui_reprovideo.h"
#include "drakesistema.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QTime>

ReproVideo::ReproVideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReproVideo)
{    
    ui->setupUi(this);
    drakeSistema drake;
    user = drake.getUser();
    ui->lcdNumber->display("00:00:00");
    ui->pushButton->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    setMouseTracking(true);
    timer = new QTimer(this);
    Contador = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(Contador, SIGNAL(timeout()), this, SLOT(Comprobar()));
    Contador->stop();
    timer->stop();
    qApp->installEventFilter(this);
}

ReproVideo::~ReproVideo()
{
    delete ui;
}

void ReproVideo::changeEvent(QEvent *e)
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

bool ReproVideo::event( QEvent* event )
{
    switch( event->type() )
    {
    case QEvent::MouseButtonPress:
            this->mouse();
            break;
    case QEvent::KeyPress:
            this->mouse();
            break;
    case QEvent::MouseMove:            
    case QEvent::Leave:
    case QEvent::Enter:
    default:
            return QDialog::event( event );
            break;
    }
    return false;
}

bool ReproVideo::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::MouseMove)
  {
    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    if (ReproVideo::isFullScreen() == true)
    {
        if (ui->widget->isHidden() == true)
        {
            ui->widget->show();
            ReproVideo::setCursor(Qt::ArrowCursor);
            Contador->start(2000);
        }
    }
  }
  return false;
}

void ReproVideo::mouseDoubleClickEvent( QMouseEvent */*e*/ )
{    
    if (ReproVideo::isFullScreen() == true)
    {
        ReproVideo::showNormal();
        ui->widget->show();
        ui->pushButton_5->setText(tr("Pantalla completa"));
        ReproVideo::setCursor(Qt::ArrowCursor);
    }
    else if (ReproVideo::isFullScreen() == false)
    {
        ReproVideo::showFullScreen();
        ui->widget->hide();
        ui->pushButton_5->setText(tr("Pantalla normal"));
        ReproVideo::setCursor(Qt::BlankCursor);
        Contador->stop();
    }
}

void ReproVideo::mouse()
{
    if (ReproVideo::isFullScreen() == true)
    {
        ui->pushButton_5->setText(tr("Pantalla normal"));
        if (ui->widget->isHidden() == true)
        {
            ui->widget->show();
            ReproVideo::setCursor(Qt::ArrowCursor);
            Contador->start(2000);
        }
        else
        {
            ui->widget->hide();
            ReproVideo::setCursor(Qt::BlankCursor);
            Contador->stop();
        }
    }
}

void ReproVideo::on_pushButton_4_clicked()
{
     ui->videoPlayer->stop();
     close();
}

void ReproVideo::on_pushButton_clicked()
{
    if (listaArchivos.isEmpty())
    {
        QMessageBox m;
        m.setText(tr("No has seleccionado ninguna pelicula, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        ui->videoPlayer->load(Phonon::MediaSource(listaArchivos));
        ui->videoPlayer->play();
        ui->pushButton->setEnabled(false);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->volumeSlider->setAudioOutput(ui->videoPlayer->audioOutput());
        ui->volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        ui->seekSlider->setMediaObject(ui->videoPlayer->mediaObject());
        ui->seekSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        timer->start(1000);
    }
}

void ReproVideo::on_pushButton_2_clicked()
{
    QString path="/home/%1/Documentos/";
    path=path.arg(user);
    listaArchivos=QFileDialog::getOpenFileName
     (this,tr("Abrir Archivo"),path,
        "Todos los archivos (*.*)");
    if(listaArchivos.isEmpty() )
    {
        return;
    }
    QFile file(listaArchivos);
    Peli = QFileInfo(file).fileName();
    ui->label->setText(""+Peli+"");
    ui->pushButton->setEnabled(true);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}

void ReproVideo::on_pushButton_3_clicked()
{
    ui->videoPlayer->stop();
    ui->videoPlayer->pause();
    ui->pushButton->setEnabled(true);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    timer->stop();
    ui->lcdNumber->display("00:00:00");
}

void ReproVideo::on_pushButton_6_clicked()
{
    if (ui->videoPlayer->isPaused())
    {
        ui->videoPlayer->play();
    }
    else
    {
        ui->videoPlayer->pause();
    }
}

void ReproVideo::on_pushButton_5_clicked()
{
    if (ReproVideo::isFullScreen() == true)
    {
        ReproVideo::showNormal();
        ui->widget->show();
        ReproVideo::setCursor(Qt::ArrowCursor);
        ui->pushButton_5->setText(tr("Pantalla completa"));
    }
    else if (ReproVideo::isFullScreen() == false)
    {
        ReproVideo::showFullScreen();
        ui->widget->hide();
        ReproVideo::setCursor(Qt::BlankCursor);
        ui->pushButton_5->setText(tr("Pantalla normal"));
    }
}

void ReproVideo::update()
{
    quint64 time = ui->videoPlayer->currentTime();
    QTime displayTime((time / 3600000) % 60, (time / 60000) % 60, (time / 1000) % 60);
    ui->lcdNumber->display(displayTime.toString("hh:mm:ss"));
}

void ReproVideo::Comprobar()
{
    if (ReproVideo::isFullScreen() == true)
    {
        if (ui->widget->isHidden() == false)
        {
            ui->widget->hide();
            ReproVideo::setCursor(Qt::BlankCursor);
            Contador->stop();
        }
    }
}
