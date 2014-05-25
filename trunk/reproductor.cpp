#include "reproductor.h"
#include "ui_reproductor.h"
#include "drakesistema.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QSqlQuery>
#include <QDesktopWidget>
#include <QTest>

Reproductor::Reproductor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reproductor)
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
    Value = "No";
    qApp->installEventFilter(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Stilo = "B";
    QSqlQuery queryDefecto(db);
    queryDefecto.exec("SELECT Defecto FROM Miscelanea WHERE id=2");
    queryDefecto.first();
    if (queryDefecto.isSelect())
        cantidadDefecto=queryDefecto.value(0).toString();
    if (cantidadDefecto == "0")
    {
        QSqlQuery query47(db);
        query47.exec("SELECT Fuente FROM Font WHERE id=2");
        query47.first();
        if (query47.isSelect())
            cantidad47=query47.value(0).toString();
        QSqlQuery query48(db);
        query48.exec("SELECT Estilo FROM Font WHERE id=2");
        query48.first();
        if (query48.isSelect())
            cantidad48=query48.value(0).toString();
        QSqlQuery query49(db);
        query49.exec("SELECT Talla FROM Font WHERE id=2");
        query49.first();
        if (query49.isSelect())
            cantidad49=query49.value(0).toString();
        if (cantidad48 == "Regular")
        {
            DatoTalla = "normal";
            DatoNegro = "normal";
        }
        if (cantidad48 == "Italic")
        {
            DatoTalla = "italic";
            DatoNegro = "normal";
        }
        if (cantidad48 == "Bold Italic")
        {
            DatoTalla = "italic";
            DatoNegro = "bold";
        }
        if (cantidad48 == "Bold")
        {
            DatoTalla = "normal";
            DatoNegro = "bold";
        }
        QSqlQuery query50(db);
        query50.exec("SELECT ColorTexto FROM Color WHERE id=2");
        query50.first();
        if (query50.isSelect())
            cantidad50=query50.value(0).toString();
        QSqlQuery query51(db);
        query51.exec("SELECT ColorFondo FROM Color WHERE id=2");
        query51.first();
        if (query51.isSelect())
            cantidad51=query51.value(0).toString();
        Stilo = "A";
    }
}

Reproductor::~Reproductor()
{
    delete ui;
}

void Reproductor::Valor(Phonon::MediaObject *mediaObject, Phonon::AudioOutput *audioOutput, Phonon::Path path, Phonon::Effect *effect)
{
    MediaObject = mediaObject;
    AudioOutput = audioOutput;
    Path = path;
    Effect = effect;
}

void Reproductor::changeEvent(QEvent *e)
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

bool Reproductor::event( QEvent* event )
{
    switch( event->type() )
    {
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

bool Reproductor::eventFilter(QObject *obj, QEvent *event)
{
    Q_UNUSED(obj);
    if (event->type() == QEvent::MouseMove)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        mouseEvent->accept();
        if (Value == "Si")
        {
            ui->widget->show();
            Reproductor::setCursor(Qt::ArrowCursor);
            Contador->start(2000);
        }
    }
    if (event->type() == QEvent::KeyRelease)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_F1)
        {
            ayuda = new Ayuda(this);
            ayuda->show();
            ayuda->Valor(tr("VideoDrake"));
            return true;
        }
    }
    return false;
}

void Reproductor::mouseDoubleClickEvent( QMouseEvent *e )
{
    e->accept();
    if (Value == "Si")
    {
        Value = "No";
        this->setWindowFlags(Qt::Dialog);        
        this->resize(w, h);
        this->showNormal();
        ui->widget->show();
        ui->pushButton_5->setText(tr("Pantalla completa"));
        Reproductor::setCursor(Qt::ArrowCursor);
        QDesktopWidget screen;
        QRect screenGeom = screen.screenGeometry(this);
        int screenCenterX = screenGeom.center().x();
        int screenCenterY = screenGeom.center().y();
        move(screenCenterX - width () / 2, screenCenterY - height() / 2);
    }
    else if (Value == "No")
    {
        Value = "Si";
        w = this->width();
        h = this->height();
        this->showMaximized();
        while(this->isMaximized())
        {
              QTest::qWait(100);
              break;
        }
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
        this->resize(QApplication::desktop()->size());
        this->show();
        ui->widget->hide();
        ui->pushButton_5->setText(tr("Pantalla normal"));
        Reproductor::setCursor(Qt::BlankCursor);
        Contador->stop();
    }
}

void Reproductor::mouse()
{
    if (Value == "Si")
    {
        if (ui->widget->isHidden())
        {
            ui->widget->show();
            Reproductor::setCursor(Qt::ArrowCursor);
            Contador->start(2000);
        }
        else
        {
            ui->widget->hide();
            Reproductor::setCursor(Qt::BlankCursor);
            Contador->stop();
        }
    }
}

void Reproductor::on_pushButton_4_clicked()
{
     if (ui->videoPlayer->isPlaying())
        ui->videoPlayer->stop();
     close();
}

void Reproductor::on_pushButton_clicked()
{
    if (listaArchivos.isEmpty())
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
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
        ui->seekSlider->setMediaObject(ui->videoPlayer->mediaObject());
        //ui->seekSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        ui->volumeSlider_5->setAudioOutput(AudioOutput);
        //ui->volumeSlider_5->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        timer->start(1000);
    }
}

void Reproductor::on_pushButton_2_clicked()
{
    QString path=tr("/home/%1/Documentos/");
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
    this->on_pushButton_clicked();
}

void Reproductor::on_pushButton_3_clicked()
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

void Reproductor::on_pushButton_6_clicked()
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

void Reproductor::on_pushButton_5_clicked()
{
    if (Value == "Si")
    {
        Value = "No";
        this->setWindowFlags(Qt::Dialog);        
        this->resize(w, h);
        this->showNormal();
        ui->widget->show();
        ui->pushButton_5->setText(tr("Pantalla completa"));
        Reproductor::setCursor(Qt::ArrowCursor);
        QDesktopWidget screen;
        QRect screenGeom = screen.screenGeometry(this);
        int screenCenterX = screenGeom.center().x();
        int screenCenterY = screenGeom.center().y();
        move(screenCenterX - width () / 2, screenCenterY - height() / 2);
    }
    else if (Value == "No")
    {
        Value = "Si";
        w = this->width();
        h = this->height();
        this->showMaximized();
        while(this->isMaximized())
        {
              QTest::qWait(100);
              break;
        }
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
        this->resize(QApplication::desktop()->size());
        this->show();
        ui->widget->hide();
        ui->pushButton_5->setText(tr("Pantalla normal"));
        Reproductor::setCursor(Qt::BlankCursor);
        Contador->stop();
    }
}

void Reproductor::update()
{
    quint64 time = ui->videoPlayer->currentTime();
    QTime displayTime((time / 3600000) % 60, (time / 60000) % 60, (time / 1000) % 60);
    ui->lcdNumber->display(displayTime.toString("hh:mm:ss"));
}

void Reproductor::Comprobar()
{
    if (Value == "Si")
    {
        if (ui->widget->isHidden() == false)
        {
            ui->widget->hide();
            Reproductor::setCursor(Qt::BlankCursor);
            Contador->stop();
        }
    }
}
