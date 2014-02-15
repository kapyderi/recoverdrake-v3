#include "id3mp3.h"
#include "ui_id3mp3.h"
#include "drakesistema.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlQuery>
#include <QDebug>
#include <phonon/mediaobject.h>
#include <phonon/audiooutput.h>
#include <QtMultimedia>
#include <QTimer>
#include <QTime>
#include <QTest>
#include <QTableWidgetItem>
#include <phonon/BackendCapabilities>
#include <phonon/EffectDescription>
#include <phonon/EffectWidget>
#include <phonon/EffectParameter>

id3mp3::id3mp3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::id3mp3)
{
    ui->setupUi(this);
    drakeSistema drake;
    user = drake.getUser();
    db=QSqlDatabase::database("PRINCIPAL");
    Evento = 0;
    mib = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    Stilo = "B";
    QSqlQuery queryDefecto(db);
    queryDefecto.exec("SELECT Defecto FROM Miscelanea WHERE id=2");
    queryDefecto.first();
    if (queryDefecto.isValid())
        cantidadDefecto=queryDefecto.value(0).toString();
    if (cantidadDefecto == "0")
    {
        QSqlQuery query47(db);
        query47.exec("SELECT Fuente FROM Font WHERE id=2");
        query47.first();
        if (query47.isValid())
            cantidad47=query47.value(0).toString();
        QSqlQuery query48(db);
        query48.exec("SELECT Estilo FROM Font WHERE id=2");
        query48.first();
        if (query48.isValid())
            cantidad48=query48.value(0).toString();
        QSqlQuery query49(db);
        query49.exec("SELECT Talla FROM Font WHERE id=2");
        query49.first();
        if (query49.isValid())
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
        if (query50.isValid())
            cantidad50=query50.value(0).toString();
        QSqlQuery query51(db);
        query51.exec("SELECT ColorFondo FROM Color WHERE id=2");
        query51.first();
        if (query51.isValid())
            cantidad51=query51.value(0).toString();
        Stilo = "A";
    }
    QString Anual;
    QSqlQuery query42(db);
    query42.exec("SELECT english FROM Idioma WHERE id=2");
    query42.first();
    if (query42.isValid())
        Anual=query42.value(0).toString();
    if ( Anual == "2")
    {
        ui->label_6->setText("Year");
        ui->label_15->setText("Year");
    }
    CierreTotal = 0;
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar()));
    ui->radioButton->setChecked(true);
    ui->radioButton_7->setChecked(true);
    ui->radioButton_5->setChecked(true);
    ui->groupBox_2->hide();
    ui->groupBox->show();
    connect(ui->radioButton_7,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Comprobar1()));   
    connect(ui->radioButton_5,SIGNAL(clicked()),this,SLOT(Comprobar2()));
    connect(ui->radioButton_6,SIGNAL(clicked()),this,SLOT(Comprobar2()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Comprobar2()));
    ui->lcdNumber_2->display("00:00:00");
    ui->progressBar->hide();
    ui->label->setEnabled(false);
    ui->lineEdit_9->setEnabled(false);
    ui->checkBox->setChecked(true);
    ui->lineEdit_10->setEnabled(true);
    ui->lineEdit_11->setEnabled(true);
    ui->lineEdit_12->setEnabled(true);
    ui->lineEdit_13->setEnabled(true);
    ui->lineEdit_14->setEnabled(true);
    ui->label_10->setEnabled(true);
    ui->label_11->setEnabled(true);
    ui->label_12->setEnabled(true);
    ui->label_13->setEnabled(true);
    ui->label_14->setEnabled(true);
    ui->label_15->setEnabled(true);
    ui->lineEdit_20->setEnabled(true);
    ui->comboBox->setEnabled(true);
    ui->label_16->setVisible(false);
    ui->lineEdit_15->setVisible(false);
    ui->pushButton_10->setEnabled(false);
    connect(ui->checkBox,SIGNAL(clicked()),this,SLOT(Comprobar3()));
    ui->groupBox_6->setEnabled(false);
    ui->lineEdit_16->setVisible(false);
    ui->label_17->setVisible(false);
    ui->pushButton_17->setVisible(false);
    ui->comboBox_3->setEnabled(false);
    ui->label_20->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
    ui->lineEdit_4->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_19->setEnabled(false);
    ui->lineEdit_5->setEnabled(false);
    ui->lineEdit_6->setEnabled(false);
    ui->lineEdit_7->setEnabled(false);
    ui->comboBox_2->setEnabled(false);
    QSqlQuery Variable(db);
    Variable.exec("SELECT Genero FROM id3Genre");
    while(Variable.next())
    {
        ui->comboBox->addItem(Variable.value(0).toString());
        ui->comboBox_2->addItem(Variable.value(0).toString());
    }
    ui->comboBox->setCurrentIndex(ui->comboBox->findText("254 None"));
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText("254 None"));
    ui->comboBox_4->setCurrentIndex(ui->comboBox_4->findText("id3v2"));
    ControlNum = 0;
    ui->checkBox_3->setVisible(true);
    ui->checkBox_4->setVisible(true);
    ui->checkBox_5->setVisible(true);
    ui->checkBox_6->setVisible(true);
    ui->checkBox_7->setVisible(true);
    ui->checkBox_8->setVisible(true);
    connect(ui->checkBox_3,SIGNAL(clicked()),this,SLOT(Comprobar4()));
    connect(ui->checkBox_4,SIGNAL(clicked()),this,SLOT(Comprobar4()));
    connect(ui->checkBox_5,SIGNAL(clicked()),this,SLOT(Comprobar4()));
    connect(ui->checkBox_6,SIGNAL(clicked()),this,SLOT(Comprobar4()));
    connect(ui->checkBox_7,SIGNAL(clicked()),this,SLOT(Comprobar4()));
    connect(ui->checkBox_8,SIGNAL(clicked()),this,SLOT(Comprobar4()));
    ui->checkBox_2->setChecked(true);
    connect(ui->checkBox_9,SIGNAL(clicked()),this,SLOT(Comprobar5()));
    connect(ui->checkBox_10,SIGNAL(clicked()),this,SLOT(Comprobar6()));
    ui->pushButton_20->setVisible(false);
    ui->pushButton_21->setVisible(false);
    ui->groupBox_8->setVisible(false);
    ui->radioButton_11->setChecked(true);
    this->Comprobar4();    
    Ordenar = 0;
    OtroDirectorio = "";
    this->installEventFilter(this);
}

id3mp3::~id3mp3()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void id3mp3::Valor(QString valor, QString Logs, Phonon::MediaObject *mediaObject, Phonon::AudioOutput *audioOutput, Phonon::Path path, Phonon::Effect *effect)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
    if (Logs == "S")
        Log = "S";
    else
        Log = "N";
    MediaObject = mediaObject;
    AudioOutput = audioOutput;
    Path = path;
    Effect = effect;
    connect(MediaObject, SIGNAL(finished()), this, SLOT(final()));
}

void id3mp3::closeEvent ( QCloseEvent * event )
{
    if (CierreTotal == 1)
    {
        MediaObject->stop();
        emit Cerrar();
        event->accept();
    }
    else
    {
        MediaObject->stop();
        close();
        event->accept();
    }
}

bool id3mp3::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("Etiquetador"));
                return true;
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Escape)
            {
                if (CierreTotal == 0)
                    close();
                else if (CierreTotal == 1)
                    return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void id3mp3::Comprobar()
{
    if (ui->radioButton->isChecked())
    {
        ui->groupBox_2->hide();
        ui->groupBox->show();
        ui->pushButton_20->setVisible(false);
        ui->pushButton_21->setVisible(false);
    }
    if (ui->radioButton_2->isChecked())
    {
        ui->groupBox->hide();
        ui->groupBox_2->show();
        ui->pushButton_20->setVisible(true);
        ui->pushButton_21->setVisible(true);
    }
}

void id3mp3::Comprobar5()
{
    if (ui->checkBox_9->isChecked())
        ui->lineEdit_13->setEnabled(false);
    else
        ui->lineEdit_13->setEnabled(true);
}

void id3mp3::Comprobar6()
{
    if (ui->checkBox_10->isChecked())
        ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(tr("Sin estructura")));
    else
        ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(tr("Por defecto")));
}

void id3mp3::Comprobar4()
{
    if (ui->checkBox_3->isChecked())
    {
        ui->checkBox_3->setStyleSheet("color: rgb(0, 0, 255)");
        ui->lineEdit_10->setEnabled(true);
    }
    else
    {
        ui->checkBox_3->setStyleSheet("color: rgb(255, 0, 0)");
        ui->lineEdit_10->setEnabled(false);
    }
    if (ui->checkBox_4->isChecked())
    {
        ui->checkBox_4->setStyleSheet("color: rgb(0, 0, 255)");
        ui->lineEdit_11->setEnabled(true);
    }
    else
    {
        ui->checkBox_4->setStyleSheet("color: rgb(255, 0, 0)");
        ui->lineEdit_11->setEnabled(false);
    }
    if (ui->checkBox_5->isChecked())
    {
        ui->checkBox_5->setStyleSheet("color: rgb(0, 0, 255)");
        ui->lineEdit_20->setEnabled(true);
    }
    else
    {
        ui->checkBox_5->setStyleSheet("color: rgb(255, 0, 0)");
        ui->lineEdit_20->setEnabled(false);
    }
    if (ui->checkBox_6->isChecked())
    {
        ui->checkBox_6->setStyleSheet("color: rgb(0, 0, 255)");
        ui->comboBox->setEnabled(true);
    }
    else
    {
        ui->checkBox_6->setStyleSheet("color: rgb(255, 0, 0)");
        ui->comboBox->setEnabled(false);
    }
    if (ui->checkBox_7->isChecked())
    {
        ui->checkBox_7->setStyleSheet("color: rgb(0, 0, 255)");
        ui->lineEdit_14->setEnabled(true);
    }
    else
    {
        ui->checkBox_7->setStyleSheet("color: rgb(255, 0, 0)");
        ui->lineEdit_14->setEnabled(false);
    }
    if (ui->checkBox_8->isChecked())
    {
        ui->checkBox_8->setStyleSheet("color: rgb(0, 0, 255)");
        ui->lineEdit_12->setEnabled(true);
        ui->checkBox_9->setEnabled(true);
        if (ui->checkBox_9->isChecked())
            ui->lineEdit_13->setEnabled(false);
        else
            ui->lineEdit_13->setEnabled(true);
    }
    else
    {
        ui->checkBox_8->setStyleSheet("color: rgb(255, 0, 0)");
        ui->lineEdit_12->setEnabled(false);
        ui->lineEdit_13->setEnabled(false);
        ui->checkBox_9->setEnabled(false);
    }
}

void id3mp3::Comprobar1()
{
    if (ui->radioButton_7->isChecked())
    {
        ui->lineEdit->setEnabled(true);
        ui->pushButton_11->setEnabled(true);
        ui->pushButton_4->setText(tr("Seleccionar directorio"));
        ui->checkBox_2->setEnabled(true);
    }
    if (ui->radioButton_4->isChecked())
    {
        ui->lineEdit->setEnabled(false);
        ui->pushButton_11->setEnabled(false);
        ui->pushButton_4->setText(tr("Seleccionar archivos"));
        ui->checkBox_2->setEnabled(false);
    }
}

void id3mp3::Comprobar2()
{
    if (ui->radioButton_5->isChecked())
    {
        ui->checkBox->setEnabled(true);
        ui->label->setEnabled(false);
        ui->lineEdit_9->setEnabled(false);
        ui->comboBox_3->setEnabled(false);
        ui->label_20->setEnabled(false);
        ui->label_17->setVisible(false);
        ui->pushButton_17->setVisible(false);
        ui->pushButton_8->setVisible(true);
        ui->pushButton_18->setVisible(true);
        ui->lineEdit_16->setVisible(false);        
        ui->lineEdit_16->setText("");
        ui->lineEdit_10->setText("");
        ui->lineEdit_11->setText("");
        ui->lineEdit_14->setText("");
        ui->lineEdit_12->setText("");
        ui->lineEdit_13->setText("");
        ui->lineEdit_20->setText("");
        ui->comboBox->setCurrentIndex(ui->comboBox->findText("254 None"));
        if (ui->checkBox->isChecked())
        {
            ui->lineEdit_10->setVisible(true);
            ui->lineEdit_11->setVisible(true);
            ui->lineEdit_12->setVisible(true);
            ui->lineEdit_13->setVisible(true);
            ui->lineEdit_14->setVisible(true);
            ui->label_10->setVisible(true);
            ui->label_11->setVisible(true);
            ui->label_12->setVisible(true);
            ui->label_13->setVisible(true);
            ui->label_14->setVisible(true);
            ui->label_15->setVisible(true);
            ui->label_19->setVisible(true);
            ui->lineEdit_20->setVisible(true);
            ui->comboBox->setVisible(true);
            ui->checkBox_3->setVisible(true);
            ui->checkBox_4->setVisible(true);
            ui->checkBox_5->setVisible(true);
            ui->checkBox_6->setVisible(true);
            ui->checkBox_7->setVisible(true);
            ui->checkBox_8->setVisible(true);
            ui->checkBox_9->setVisible(true);
            ui->lineEdit_13->setText(ui->lineEdit_15->text());
            this->Comprobar4();
        }
        else
        {
            ui->lineEdit_10->setVisible(false);
            ui->lineEdit_11->setVisible(false);
            ui->lineEdit_12->setVisible(false);
            ui->lineEdit_13->setVisible(false);
            ui->lineEdit_14->setVisible(false);
            ui->label_10->setVisible(false);
            ui->label_11->setVisible(false);
            ui->label_12->setVisible(false);
            ui->label_13->setVisible(false);
            ui->label_14->setVisible(false);
            ui->label_15->setVisible(false);
            ui->label_19->setVisible(false);
            ui->lineEdit_20->setVisible(false);
            ui->comboBox->setVisible(false);
            ui->checkBox_3->setVisible(false);
            ui->checkBox_4->setVisible(false);
            ui->checkBox_5->setVisible(false);
            ui->checkBox_6->setVisible(false);
            ui->checkBox_7->setVisible(false);
            ui->checkBox_8->setVisible(false);
            ui->checkBox_9->setVisible(false);
            ui->lineEdit_13->setText(ui->lineEdit_15->text());
        }       
    }
    if (ui->radioButton_6->isChecked())
    {
        ui->label->setEnabled(true);
        ui->lineEdit_9->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        ui->label_20->setEnabled(true);
        ui->label_17->setVisible(false);
        ui->pushButton_17->setVisible(false);
        ui->pushButton_8->setVisible(true);
        ui->pushButton_18->setVisible(true);
        ui->lineEdit_16->setVisible(false);
        ui->lineEdit_10->setVisible(false);
        ui->lineEdit_11->setVisible(false);
        ui->lineEdit_12->setVisible(false);
        ui->lineEdit_13->setVisible(false);
        ui->lineEdit_14->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
        ui->label_13->setVisible(false);
        ui->label_14->setVisible(false);
        ui->label_15->setVisible(false);
        ui->label_19->setVisible(false);
        ui->lineEdit_20->setVisible(false);
        ui->comboBox->setVisible(false);
        ui->checkBox->setEnabled(false);
        ui->checkBox_3->setVisible(false);
        ui->checkBox_4->setVisible(false);
        ui->checkBox_5->setVisible(false);
        ui->checkBox_6->setVisible(false);
        ui->checkBox_7->setVisible(false);
        ui->checkBox_8->setVisible(false);
        ui->checkBox_9->setVisible(false);
        ui->lineEdit_13->setText("");
    }
    if (ui->radioButton_3->isChecked())
    {
        ui->label->setEnabled(false);
        ui->lineEdit_9->setEnabled(false);
        ui->comboBox_3->setEnabled(false);
        ui->label_20->setEnabled(false);
        ui->label_17->setVisible(true);
        ui->pushButton_17->setVisible(true);
        ui->pushButton_8->setVisible(false);
        ui->pushButton_18->setVisible(false);
        ui->lineEdit_16->setVisible(true);
        ui->lineEdit_10->setVisible(true);
        ui->lineEdit_11->setVisible(true);
        ui->lineEdit_12->setVisible(true);
        ui->lineEdit_13->setVisible(true);
        ui->lineEdit_14->setVisible(true);
        ui->label_10->setVisible(true);
        ui->label_11->setVisible(true);
        ui->label_12->setVisible(true);
        ui->label_13->setVisible(true);
        ui->label_14->setVisible(true);
        ui->label_15->setVisible(true);
        ui->label_19->setVisible(true);
        ui->lineEdit_20->setVisible(true);
        ui->comboBox->setVisible(true);
        ui->checkBox->setEnabled(false);
        ui->checkBox_3->setVisible(false);
        ui->checkBox_4->setVisible(false);
        ui->checkBox_5->setVisible(false);
        ui->checkBox_6->setVisible(false);
        ui->checkBox_7->setVisible(false);
        ui->checkBox_8->setVisible(false);
        ui->checkBox_9->setVisible(false);
        ui->lineEdit_10->setEnabled(true);
        ui->lineEdit_11->setEnabled(true);
        ui->lineEdit_20->setEnabled(true);
        ui->comboBox->setEnabled(true);
        ui->lineEdit_14->setEnabled(true);
        ui->lineEdit_12->setEnabled(true);
        ui->lineEdit_13->setEnabled(true);
        ui->lineEdit_13->setText("");
        QString valor, Titulo, Album, Artista, Comentarios, Anual, Tracks, Genero;
        int row=ui->tableWidget->currentRow();
        if (row >= 0)
        {
            QTableWidgetItem *item1,*item2,*item3,*item4,*item5,*item6,*item7,*item8;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            item5=new QTableWidgetItem;
            item6=new QTableWidgetItem;
            item7=new QTableWidgetItem;
            item8=new QTableWidgetItem;
            item1=ui->tableWidget->item(row,1);
            item2=ui->tableWidget->item(row,2);
            item3=ui->tableWidget->item(row,3);
            item4=ui->tableWidget->item(row,4);
            item5=ui->tableWidget->item(row,5);
            item6=ui->tableWidget->item(row,6);
            item7=ui->tableWidget->item(row,7);
            item8=ui->tableWidget->item(row,8);
            valor=item1->text();
            Titulo=item2->text();
            Album=item3->text();
            Artista=item4->text();
            Comentarios=item5->text();
            Anual=item6->text();
            Tracks=item7->text();
            Genero=item8->text();
            QStringList Track;
            Track = Tracks.split("/");
            QString PTrack = Track.value(0);
            QString TTrack = Track.value(1);
            ui->lineEdit_16->setText(Titulo);
            ui->lineEdit_10->setText(Album);
            ui->lineEdit_11->setText(Artista);
            ui->lineEdit_14->setText(Anual);
            ui->lineEdit_12->setText(PTrack);
            ui->lineEdit_13->setText(TTrack);
            ui->comboBox->setCurrentIndex(ui->comboBox->findText(Genero));
            ui->lineEdit_20->setText(Comentarios);
            MediaObject->stop();
            QTest::qWait(500);
            Phonon::MediaSource source(valor);
            MediaObject->setCurrentSource(source);
            MediaObject->pause();
            ui->pushButton_12->setEnabled(true);
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
        }
    }    
}

void id3mp3::Comprobar3()
{
    if (!ui->radioButton_3->isChecked())
    {
        if (ui->checkBox->isChecked() && ui->radioButton_6->isChecked() == false)
        {
            ui->label_17->setVisible(false);
            ui->pushButton_17->setVisible(false);
            ui->lineEdit_16->setVisible(false);
            ui->lineEdit_10->setVisible(true);
            ui->lineEdit_11->setVisible(true);
            ui->lineEdit_12->setVisible(true);
            ui->lineEdit_13->setVisible(true);
            ui->lineEdit_14->setVisible(true);
            ui->label_10->setVisible(true);
            ui->label_11->setVisible(true);
            ui->label_12->setVisible(true);
            ui->label_13->setVisible(true);
            ui->label_14->setVisible(true);
            ui->label_15->setVisible(true);
            ui->label_19->setVisible(true);
            ui->lineEdit_20->setVisible(true);
            ui->comboBox->setVisible(true);
            ui->checkBox_3->setVisible(true);
            ui->checkBox_4->setVisible(true);
            ui->checkBox_5->setVisible(true);
            ui->checkBox_6->setVisible(true);
            ui->checkBox_7->setVisible(true);
            ui->checkBox_8->setVisible(true);
        }
        else
        {
            ui->label_17->setVisible(false);
            ui->pushButton_17->setVisible(false);
            ui->lineEdit_16->setVisible(false);
            ui->lineEdit_10->setVisible(false);
            ui->lineEdit_11->setVisible(false);
            ui->lineEdit_12->setVisible(false);
            ui->lineEdit_13->setVisible(false);
            ui->lineEdit_14->setVisible(false);
            ui->label_10->setVisible(false);
            ui->label_11->setVisible(false);
            ui->label_12->setVisible(false);
            ui->label_13->setVisible(false);
            ui->label_14->setVisible(false);
            ui->label_15->setVisible(false);
            ui->label_19->setVisible(false);
            ui->lineEdit_20->setVisible(false);
            ui->comboBox->setVisible(false);
            ui->checkBox_3->setVisible(false);
            ui->checkBox_4->setVisible(false);
            ui->checkBox_5->setVisible(false);
            ui->checkBox_6->setVisible(false);
            ui->checkBox_7->setVisible(false);
            ui->checkBox_8->setVisible(false);
        }
    }
}

void id3mp3::on_pushButton_clicked()
{
    ui->lineEdit_4->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_5->setText("");
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText("254 None"));
    ui->lineEdit_19->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->groupBox_6->setEnabled(true);
    ui->lineEdit_4->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_19->setEnabled(false);
    ui->lineEdit_5->setEnabled(false);
    ui->lineEdit_6->setEnabled(false);
    ui->lineEdit_7->setEnabled(false);
    ui->comboBox_2->setEnabled(false);
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    fileName1 = QFileDialog::getOpenFileName(this,tr(QString::fromUtf8("Abrir archivo de audio")),
                        path,trUtf8(tr("Archivo audio compatible (*.mp3 *.ogg)")));
    if (fileName1.isEmpty())
    {
        ui->groupBox_6->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_19->setEnabled(false);
        ui->lineEdit_5->setEnabled(false);
        ui->lineEdit_6->setEnabled(false);
        ui->lineEdit_7->setEnabled(false);
        ui->comboBox_2->setEnabled(false);
        return;
    }
    drakeSistema drake;
    mp3Title = drake.getMp3Title(fileName1);
    mp3Artist = drake.getMp3Artist(fileName1);
    mp3Album = drake.getMp3Album(fileName1);
    mp3Year =  drake.getMp3Year(fileName1);
    mp3Comment = drake.getMp3Comment(fileName1);
    mp3Track = drake.getMp3Track(fileName1);
    mp3Genre = drake.getMp3Genre(fileName1);
    QStringList Title = mp3Title.split(":");
    mp3Title = Title.value(1);
    if (mp3Title.left(1) == " ")
        mp3Title = mp3Title.remove(0,1);
    QStringList Artist = mp3Artist.split(":");
    mp3Artist = Artist.value(1);
    if (mp3Artist.left(1) == " ")
        mp3Artist = mp3Artist.remove(0,1);
    QStringList Album = mp3Album.split(":");
    mp3Album = Album.value(1);
    if (mp3Album.left(1) == " ")
        mp3Album = mp3Album.remove(0,1);
    QStringList Year = mp3Year.split(":");
    mp3Year = Year.value(1);
    if (mp3Year.left(1) == " ")
        mp3Year = mp3Year.remove(0,1);
    QStringList Comment0 = mp3Comment.split("\n");
    QString Comentario = Comment0.value(0);
    QStringList Comment1 = Comentario.split(":");
    mp3Comment = Comment1.value(2);
    if (mp3Comment.left(1) == " ")
        mp3Comment = mp3Comment.remove(0,1);
    QStringList Tracks = mp3Track.split(":");
    mp3Track = Tracks.value(1);
    if (mp3Track.left(1) == " ")
        mp3Track = mp3Track.remove(0,1);
    QStringList Genero = mp3Genre.split(":");
    mp3Genre = Genero.value(1);
    if (mp3Genre.left(1) == " ")
        mp3Genre = mp3Genre.remove(0,1);
    mp3Genre.remove("(");
    mp3Genre.remove(")");
    ui->lineEdit_8->setText(fileName1);
    ui->lineEdit_4->setText(QString::fromUtf8(mp3Title));
    ui->lineEdit_2->setText(QString::fromUtf8(mp3Artist));
    ui->lineEdit_3->setText(QString::fromUtf8(mp3Album));
    ui->lineEdit_19->setText(QString::fromUtf8(mp3Comment));
    ui->lineEdit_5->setText(QString::fromUtf8(mp3Year));
    int Totale = mp3Genre.size();
    if (Totale == 1)
        mp3Genre = "00"+mp3Genre+"";
    else if (Totale == 2)
        mp3Genre = "0"+mp3Genre+"";
    QSqlQuery Variable(db);
    Variable.exec("SELECT Genero FROM id3Genre");
    while(Variable.next())
    {
        QString valor;
        valor = Variable.value(0).toString();
        if (valor.contains(mp3Genre))
        {
            mp3Genre = valor;
            break;
        }
    }
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(mp3Genre));
    QStringList Track;
    Track = mp3Track.split("/");
    QString PTrack = Track.value(0);
    QString TTrack = Track.value(1);
    ui->lineEdit_6->setText(QString::fromUtf8(PTrack));
    ui->lineEdit_7->setText(QString::fromUtf8(TTrack));
    ui->pushButton_12->setEnabled(true);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
    ui->lineEdit_4->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_19->setEnabled(true);
    ui->lineEdit_5->setEnabled(true);
    ui->lineEdit_6->setEnabled(true);
    ui->lineEdit_7->setEnabled(true);
    ui->comboBox_2->setEnabled(true);
}

void id3mp3::on_pushButton_3_clicked()
{
    if (CierreTotal == 1)
    {
        if (Log == "S")
        {
            system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
        }
        MediaObject->stop();
        emit Cerrar();
    }
    else
    {
        if (Log == "S")
        {
            system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
        }
        MediaObject->stop();
        close();
    }
}

void id3mp3::on_pushButton_2_clicked()
{
    QStringList comandos;
    QString Title= ui->lineEdit_4->text();
    if (Title == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay datos para realizar el cambio de etiqueta."));
        m.exec();
        return;
    }
    Totalizar = 0;
    TotalProceso = 0;
    QString Artist= ui->lineEdit_2->text();
    QString Album=  ui->lineEdit_3->text();
    QString Year= ui->lineEdit_5->text();
    QString Comment= ui->lineEdit_19->text();
    QString Track= ui->lineEdit_6->text();
    QString Total= ui->lineEdit_7->text();
    QString Genero = ui->comboBox_2->currentText();
    int Valor = Genero.size();
    int Value = Valor-3;
    Genero.chop(Value);
    QString cmd, cmd1;
    if (ui->comboBox_4->currentText() == "id3v1")
    {
        cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=\"%4\" --comment=\"%5\" --track=%6/%7 --genre=\"%8\" -1 \"%9\"";
        cmd1=cmd1.arg(Artist).arg(Title).arg(Album).arg(Year).arg(Comment).arg(Track).arg(Total).arg(Genero).arg(fileName1);
        QString cmd2 = "chown %1:%1 \"%2\"";
        cmd2 = cmd2.arg(user).arg(fileName1);
        comandos<< cmd1 << cmd2;
    }
    if (ui->comboBox_4->currentText() == "id3v2")
    {
        cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=\"%4\" --comment=\"%5\" --track=%6/%7 --genre=\"%8\" -2 \"%9\"";
        cmd1=cmd1.arg(Artist).arg(Title).arg(Album).arg(Year).arg(Comment).arg(Track).arg(Total).arg(Genero).arg(fileName1);
        QString cmd2 = "chown %1:%1 \"%2\"";
        cmd2 = cmd2.arg(user).arg(fileName1);
        comandos<< cmd1 << cmd2;
    }
    if (ui->comboBox_4->currentText() == tr("Todas"))
    {
        cmd = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=\"%4\" --comment=\"%5\" --track=%6/%7 --genre=\"%8\" -1 \"%9\"";
        cmd=cmd.arg(Artist).arg(Title).arg(Album).arg(Year).arg(Comment).arg(Track).arg(Total).arg(Genero).arg(fileName1);
        cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=\"%4\" --comment=\"%5\" --track=%6/%7 --genre=\"%8\" -2 \"%9\"";
        cmd1=cmd1.arg(Artist).arg(Title).arg(Album).arg(Year).arg(Comment).arg(Track).arg(Total).arg(Genero).arg(fileName1);
        QString cmd2 = "chown %1:%1 \"%2\"";
        cmd2 = cmd2.arg(user).arg(fileName1);
        comandos<< cmd << cmd1 << cmd2;
    }
    if (mib != 0)
        delete mib;
    ui->progressBar->show();
    mib = new DrakeProcesos1(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count();
    mib->Valor(valor,3);
    mib->iniciarProceso();
    Totalizar = comandos.count();
    ui->progressBar->setRange(0,Totalizar);
}

void id3mp3::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
}

void id3mp3::ProcesarValor(QString ValorComand)
{
    if (ControlNum == 1 || ControlNum == 2)
    {
        int iFilas, a;
        QString Ruta, Titulo, Album, Artista, Comentarios, Anual, Track, Total, Genero;
        QTableWidgetItem *item1,*item2,*item3,*item4,*item5,*item6,*item7,*item8;
        iFilas=ui->tableWidget->rowCount();
        for(a=0;a<iFilas;a++)
        {
            item1=ui->tableWidget->item(a,1);
            item2=ui->tableWidget->item(a,2);
            item3=ui->tableWidget->item(a,3);
            item4=ui->tableWidget->item(a,4);
            item5=ui->tableWidget->item(a,5);
            item6=ui->tableWidget->item(a,6);
            item7=ui->tableWidget->item(a,7);
            item8=ui->tableWidget->item(a,8);
            Ruta=item1->text();
            Titulo=item2->text();
            Album=item3->text();
            Artista=item4->text();
            Comentarios=item5->text();
            Anual=item6->text();
            Track=item7->text();
            Genero=item8->text();
            if (ValorComand.contains(Ruta))
            {
                if (ControlNum == 1)
                {
                    ui->tableWidget->selectRow(a);
                    drakeSistema drake;
                    mp3Title = drake.getMp3Title(Ruta);
                    QStringList Title = mp3Title.split(":");
                    mp3Title = Title.value(1);
                    if (mp3Title.left(1) == " ")
                        mp3Title = mp3Title.remove(0,1);
                    item2->setText(mp3Title);
                    ui->tableWidget->setItem(a,2,item2);
                    ui->tableWidget->resizeColumnToContents(2);
                    ui->tableWidget->resizeRowToContents(2);
                }
                else if (ControlNum == 2)
                {
                    ui->tableWidget->selectRow(a);
                    drakeSistema drake;
                    mp3Title = drake.getMp3Title(Ruta);
                    mp3Artist = drake.getMp3Artist(Ruta);
                    mp3Album = drake.getMp3Album(Ruta);
                    mp3Year =  drake.getMp3Year(Ruta);
                    mp3Comment = drake.getMp3Comment(Ruta);
                    mp3Track = drake.getMp3Track(Ruta);
                    mp3Genre = drake.getMp3Genre(Ruta);
                    QStringList Title = mp3Title.split(":");
                    mp3Title = Title.value(1);
                    if (mp3Title.left(1) == " ")
                        mp3Title = mp3Title.remove(0,1);
                    QStringList Artist = mp3Artist.split(":");
                    mp3Artist = Artist.value(1);
                    if (mp3Artist.left(1) == " ")
                        mp3Artist = mp3Artist.remove(0,1);
                    QStringList Album = mp3Album.split(":");
                    mp3Album = Album.value(1);
                    if (mp3Album.left(1) == " ")
                        mp3Album = mp3Album.remove(0,1);
                    QStringList Year = mp3Year.split(":");
                    mp3Year = Year.value(1);
                    if (mp3Year.left(1) == " ")
                        mp3Year = mp3Year.remove(0,1);
                    QStringList Comment0 = mp3Comment.split("\n");
                    QString Comentario = Comment0.value(0);
                    QStringList Comment1 = Comentario.split(":");
                    mp3Comment = Comment1.value(2);
                    if (mp3Comment.left(1) == " ")
                        mp3Comment = mp3Comment.remove(0,1);
                    QStringList Tracks = mp3Track.split(":");
                    mp3Track = Tracks.value(1);
                    if (mp3Track.left(1) == " ")
                        mp3Track = mp3Track.remove(0,1);
                    QStringList Genero = mp3Genre.split(":");
                    mp3Genre = Genero.value(1);
                    if (mp3Genre.left(1) == " ")
                        mp3Genre = mp3Genre.remove(0,1);
                    mp3Genre.remove("(");
                    mp3Genre.remove(")");
                    int Totale = mp3Genre.size();
                    if (Totale == 1)
                        mp3Genre = "00"+mp3Genre+"";
                    else if (Totale == 2)
                        mp3Genre = "0"+mp3Genre+"";
                    QSqlQuery Variable(db);
                    Variable.exec("SELECT Genero FROM id3Genre");
                    while(Variable.next())
                    {
                        QString valor;
                        valor = Variable.value(0).toString();
                        if (valor.contains(mp3Genre))
                        {
                            mp3Genre = valor;
                            break;
                        }
                    }
                    item2->setText(mp3Title);
                    item3->setText(mp3Album);
                    item4->setText(mp3Artist);
                    item5->setText(mp3Comment);
                    item6->setText(mp3Year);
                    item7->setText(mp3Track);
                    item8->setText(mp3Genre);
                    ui->tableWidget->setItem(a,2,item2);
                    ui->tableWidget->setItem(a,3,item3);
                    ui->tableWidget->setItem(a,4,item4);
                    ui->tableWidget->setItem(a,5,item5);
                    ui->tableWidget->setItem(a,6,item6);
                    ui->tableWidget->setItem(a,7,item7);
                    ui->tableWidget->setItem(a,8,item8);
                    ui->tableWidget->resizeColumnToContents(2);
                    ui->tableWidget->resizeColumnToContents(3);
                    ui->tableWidget->resizeColumnToContents(4);
                    ui->tableWidget->resizeColumnToContents(5);
                    ui->tableWidget->resizeColumnToContents(6);
                    ui->tableWidget->resizeColumnToContents(7);
                    ui->tableWidget->resizeColumnToContents(8);
                    ui->tableWidget->resizeColumnToContents(9);
                    ui->tableWidget->resizeRowToContents(2);
                    ui->tableWidget->resizeRowToContents(3);
                    ui->tableWidget->resizeRowToContents(4);
                    ui->tableWidget->resizeRowToContents(5);
                    ui->tableWidget->resizeRowToContents(6);
                    ui->tableWidget->resizeRowToContents(7);
                    ui->tableWidget->resizeRowToContents(8);
                }
            }
        }
    }
    if (ControlNum == 3)
    {
        int iFilas, a;
        QString Nombre, Ruta, Titulo, Album, Artista, Comentarios, Anual, Track, Total, Genero;
        QTableWidgetItem *item,*item1,*item2,*item3,*item4,*item5,*item6,*item7,*item8;
        iFilas=ui->tableWidget->rowCount();
        for(a=0;a<iFilas;a++)
        {
            item=ui->tableWidget->item(a,0);
            item1=ui->tableWidget->item(a,1);
            item2=ui->tableWidget->item(a,2);
            item3=ui->tableWidget->item(a,3);
            item4=ui->tableWidget->item(a,4);
            item5=ui->tableWidget->item(a,5);
            item6=ui->tableWidget->item(a,6);
            item7=ui->tableWidget->item(a,7);
            item8=ui->tableWidget->item(a,8);
            Nombre = item->text();
            Ruta=item1->text();
            Titulo=item2->text();
            Album=item3->text();
            Artista=item4->text();
            Comentarios=item5->text();
            Anual=item6->text();
            Track=item7->text();
            Genero=item8->text();
            QString NewRute = Ruta;
            NewRute = NewRute.remove(Nombre);
            QString NewTitle = Nombre;
            while (NewTitle.startsWith('0'))
            {
                NewTitle.remove(0,1);
            }
            QString NewRuta = ""+NewRute+""+NewTitle+"";
            if (ValorComand.contains(NewRuta))
            {
                ui->tableWidget->selectRow(a);
                drakeSistema drake;
                if (NewRuta != Ruta)
                {
                    mp3Title = drake.getMp3Title(NewRuta);
                    mp3Artist = drake.getMp3Artist(NewRuta);
                    mp3Album = drake.getMp3Album(NewRuta);
                    mp3Year =  drake.getMp3Year(NewRuta);
                    mp3Comment = drake.getMp3Comment(NewRuta);
                    mp3Track = drake.getMp3Track(NewRuta);
                    mp3Genre = drake.getMp3Genre(NewRuta);
                }
                else
                {
                    mp3Title = drake.getMp3Title(Ruta);
                    mp3Artist = drake.getMp3Artist(Ruta);
                    mp3Album = drake.getMp3Album(Ruta);
                    mp3Year =  drake.getMp3Year(Ruta);
                    mp3Comment = drake.getMp3Comment(Ruta);
                    mp3Track = drake.getMp3Track(Ruta);
                    mp3Genre = drake.getMp3Genre(Ruta);
                }
                QStringList Title = mp3Title.split(":");
                mp3Title = Title.value(1);
                if (mp3Title.left(1) == " ")
                    mp3Title = mp3Title.remove(0,1);
                QStringList Artist = mp3Artist.split(":");
                mp3Artist = Artist.value(1);
                if (mp3Artist.left(1) == " ")
                    mp3Artist = mp3Artist.remove(0,1);
                QStringList Album = mp3Album.split(":");
                mp3Album = Album.value(1);
                if (mp3Album.left(1) == " ")
                    mp3Album = mp3Album.remove(0,1);
                QStringList Year = mp3Year.split(":");
                mp3Year = Year.value(1);
                if (mp3Year.left(1) == " ")
                    mp3Year = mp3Year.remove(0,1);
                QStringList Comment0 = mp3Comment.split("\n");
                QString Comentario = Comment0.value(0);
                QStringList Comment1 = Comentario.split(":");
                mp3Comment = Comment1.value(2);
                if (mp3Comment.left(1) == " ")
                    mp3Comment = mp3Comment.remove(0,1);
                QStringList Tracks = mp3Track.split(":");
                mp3Track = Tracks.value(1);
                if (mp3Track.left(1) == " ")
                    mp3Track = mp3Track.remove(0,1);
                QStringList Genero = mp3Genre.split(":");
                mp3Genre = Genero.value(1);
                if (mp3Genre.left(1) == " ")
                    mp3Genre = mp3Genre.remove(0,1);
                mp3Genre.remove("(");
                mp3Genre.remove(")");
                int Totale = mp3Genre.size();
                if (Totale == 1)
                    mp3Genre = "00"+mp3Genre+"";
                else if (Totale == 2)
                    mp3Genre = "0"+mp3Genre+"";
                QSqlQuery Variable(db);
                Variable.exec("SELECT Genero FROM id3Genre");
                while(Variable.next())
                {
                    QString valor;
                    valor = Variable.value(0).toString();
                    if (valor.contains(mp3Genre))
                    {
                        mp3Genre = valor;
                        break;
                    }
                }
                if (NewRuta != Ruta)
                {
                    item->setText(NewTitle);
                    item1->setText(NewRuta);
                }
                item2->setText(mp3Title);
                item3->setText(mp3Album);
                item4->setText(mp3Artist);
                item5->setText(mp3Comment);
                item6->setText(mp3Year);
                item7->setText(mp3Track);
                item8->setText(mp3Genre);
                if (NewRuta != Ruta)
                {
                    ui->tableWidget->setItem(a,0,item);
                    ui->tableWidget->setItem(a,1,item1);
                }
                ui->tableWidget->setItem(a,2,item2);
                ui->tableWidget->setItem(a,3,item3);
                ui->tableWidget->setItem(a,4,item4);
                ui->tableWidget->setItem(a,5,item5);
                ui->tableWidget->setItem(a,6,item6);
                ui->tableWidget->setItem(a,7,item7);
                ui->tableWidget->setItem(a,8,item8);
                ui->tableWidget->resizeColumnToContents(2);
                ui->tableWidget->resizeColumnToContents(3);
                ui->tableWidget->resizeColumnToContents(4);
                ui->tableWidget->resizeColumnToContents(5);
                ui->tableWidget->resizeColumnToContents(6);
                ui->tableWidget->resizeColumnToContents(7);
                ui->tableWidget->resizeColumnToContents(8);
                ui->tableWidget->resizeColumnToContents(9);
                ui->tableWidget->resizeRowToContents(2);
                ui->tableWidget->resizeRowToContents(3);
                ui->tableWidget->resizeRowToContents(4);
                ui->tableWidget->resizeRowToContents(5);
                ui->tableWidget->resizeRowToContents(6);
                ui->tableWidget->resizeRowToContents(7);
                ui->tableWidget->resizeRowToContents(8);
            }
        }
    }
    TotalProceso = TotalProceso+1;
    ui->progressBar->setValue(TotalProceso);
}

void id3mp3::mibFin()
{
    if (Ordenar == 2 || Ordenar == 3)
    {
        disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    }
    else
    {
        disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
        disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    }    
    if (TotalProceso == Totalizar)
    {
        ui->progressBar->setRange(0,100);
        ui->progressBar->setValue(0);
        ui->progressBar->setFormat("%p%");
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_6->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_8->setEnabled(true);
        ui->pushButton_10->setEnabled(false);
        ui->progressBar->hide();
        Evento = 0;
        ControlNum = 0;
    }
    if (Ordenar == 2)
        ui->textEdit->append(tr("Realizada primera fase"));
    else if (Ordenar == 3)
        ui->textEdit->append(tr("Trabajo terminado"));
    if (ui->groupBox_8->isVisible())
    {
        ui->groupBox_8->setVisible(false);
        ui->pushButton_18->setVisible(true);
    }
}

void id3mp3::on_pushButton_12_clicked()
{
    if (ui->radioButton->isChecked())
    {
        if (ui->lineEdit_8->text() == "")
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No hay ninguna cancion cargada en el modo individual."));
            m.exec();
            return;
        }
        else
        {
            Phonon::MediaSource source(ui->lineEdit_8->text());
            MediaObject->setCurrentSource(source);
            MediaObject->play();
            ui->pushButton_12->setEnabled(false);
            ui->pushButton_13->setEnabled(true);
            ui->pushButton_14->setEnabled(true);
            ui->seekSlider_2->setMediaObject(MediaObject);
            //ui->seekSlider_2->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
            ui->volumeSlider_4->setAudioOutput(AudioOutput);
            //ui->volumeSlider_4->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
            timer->start(1000);
        }
    }
    else if (ui->radioButton_2->isChecked())
    {
        QString valor;
        int row=ui->tableWidget->currentRow();
        if (row < 0)
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No hay ninguna cancion cargada en el modo grupo."));
            m.exec();
            return;
        }
        QTableWidgetItem *item;
        item=new QTableWidgetItem;
        item=ui->tableWidget->item(row,1);
        valor=item->text();
        Phonon::MediaSource source(valor);
        MediaObject->setCurrentSource(source);
        MediaObject->play();
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_13->setEnabled(true);
        ui->pushButton_14->setEnabled(true);
        ui->seekSlider_2->setMediaObject(MediaObject);
        //ui->seekSlider_2->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        ui->volumeSlider_4->setAudioOutput(AudioOutput);
        //ui->volumeSlider_4->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        timer->start(1000);
    }
}

void id3mp3::update()
{
    quint64 time = MediaObject->currentTime();
    QTime displayTime((time / 3600000) % 60, (time / 60000) % 60, (time / 1000) % 60);
    ui->lcdNumber_2->display(displayTime.toString("hh:mm:ss"));
}

void id3mp3::on_pushButton_13_clicked()
{
    bool wasPlaying = MediaObject->state() == Phonon::PausedState;
    if (wasPlaying)
    {
        MediaObject->play();
        ui->pushButton_13->setText(tr("Pausa"));
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_13->setEnabled(true);
        ui->pushButton_14->setEnabled(true);
    }
    else
    {
        MediaObject->pause();
        ui->pushButton_13->setText(tr("Continuar"));
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_13->setEnabled(true);
        ui->pushButton_14->setEnabled(false);
    }
}

void id3mp3::on_pushButton_14_clicked()
{
    MediaObject->stop();
    MediaObject->pause();
    ui->pushButton_12->setEnabled(true);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
    timer->stop();
    ui->lcdNumber_2->display("00:00:00");
}

void id3mp3::on_pushButton_5_clicked()
{
    Sonido *Ecualizador=new Sonido(this);
    if (Stilo == "A")
        Ecualizador->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    connect(Ecualizador, SIGNAL(Sound(QString, int, int, int, int, int, int, int, int, int, int)),
            this, SLOT(Ecualizar(QString, int, int, int, int, int, int, int, int, int, int)));
    Ecualizador->exec();
    QString Recibido = Ecualizador->Resultado;
    if (Recibido == "Negativo")
    {
        QString activo;
        int banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10;
        QSqlQuery Efectos(db);
        Efectos.exec("SELECT activo,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10 FROM Ecualizador WHERE id=2");
        Efectos.first();
        if (Efectos.isValid())
        {
            activo=Efectos.value(0).toString();
            banda1=Efectos.value(1).toInt();
            banda2=Efectos.value(2).toInt();
            banda3=Efectos.value(3).toInt();
            banda4=Efectos.value(4).toInt();
            banda5=Efectos.value(5).toInt();
            banda6=Efectos.value(6).toInt();
            banda7=Efectos.value(7).toInt();
            banda8=Efectos.value(8).toInt();
            banda9=Efectos.value(9).toInt();
            banda10=Efectos.value(10).toInt();
        }
        if (activo == "Si")
        {
            QList<Phonon::EffectParameter> parameters = Effect->parameters();
            foreach(Phonon::EffectParameter parameter, parameters)
            {
                if (parameter.name() == "band0")
                    Effect->setParameterValue(parameter,banda1);
                else if (parameter.name() == "band1")
                    Effect->setParameterValue(parameter,banda2);
                else if (parameter.name() == "band2")
                    Effect->setParameterValue(parameter,banda3);
                else if (parameter.name() == "band3")
                    Effect->setParameterValue(parameter,banda4);
                else if (parameter.name() == "band4")
                    Effect->setParameterValue(parameter,banda5);
                else if (parameter.name() == "band5")
                    Effect->setParameterValue(parameter,banda6);
                else if (parameter.name() == "band6")
                    Effect->setParameterValue(parameter,banda7);
                else if (parameter.name() == "band7")
                    Effect->setParameterValue(parameter,banda8);
                else if (parameter.name() == "band8")
                    Effect->setParameterValue(parameter,banda9);
                else if (parameter.name() == "band9")
                    Effect->setParameterValue(parameter,banda10);
            }
        }
        else
        {
            QList<Phonon::EffectParameter> parameters = Effect->parameters();
            foreach(Phonon::EffectParameter parameter, parameters)
            {
                if (parameter.name() == "band0")
                    Effect->setParameterValue(parameter,0);
                else if (parameter.name() == "band1")
                    Effect->setParameterValue(parameter,0);
                else if (parameter.name() == "band2")
                    Effect->setParameterValue(parameter,0);
                else if (parameter.name() == "band3")
                    Effect->setParameterValue(parameter,0);
                else if (parameter.name() == "band4")
                    Effect->setParameterValue(parameter,0);
                else if (parameter.name() == "band5")
                    Effect->setParameterValue(parameter,0);
                else if (parameter.name() == "band6")
                    Effect->setParameterValue(parameter,0);
                else if (parameter.name() == "band7")
                    Effect->setParameterValue(parameter,0);
                else if (parameter.name() == "band8")
                    Effect->setParameterValue(parameter,0);
                else if (parameter.name() == "band9")
                    Effect->setParameterValue(parameter,0);
            }
        }
    }
}

void id3mp3::Ecualizar(QString Valor, int band1, int band2, int band3, int band4, int band5, int band6, int band7, int band8, int band9, int band10)
{
    if (Valor == "Si")
    {
        QList<Phonon::EffectParameter> parameters = Effect->parameters();
        foreach(Phonon::EffectParameter parameter, parameters)
        {
            if (parameter.name() == "band0")
                Effect->setParameterValue(parameter,band1);
            else if (parameter.name() == "band1")
                Effect->setParameterValue(parameter,band2);
            else if (parameter.name() == "band2")
                Effect->setParameterValue(parameter,band3);
            else if (parameter.name() == "band3")
                Effect->setParameterValue(parameter,band4);
            else if (parameter.name() == "band4")
                Effect->setParameterValue(parameter,band5);
            else if (parameter.name() == "band5")
                Effect->setParameterValue(parameter,band6);
            else if (parameter.name() == "band6")
                Effect->setParameterValue(parameter,band7);
            else if (parameter.name() == "band7")
                Effect->setParameterValue(parameter,band8);
            else if (parameter.name() == "band8")
                Effect->setParameterValue(parameter,band9);
            else if (parameter.name() == "band9")
                Effect->setParameterValue(parameter,band10);
        }        
    }
    else
    {
        QList<Phonon::EffectParameter> parameters = Effect->parameters();
        foreach(Phonon::EffectParameter parameter, parameters)
        {
            if (parameter.name() == "band0")
                Effect->setParameterValue(parameter,0);
            else if (parameter.name() == "band1")
                Effect->setParameterValue(parameter,0);
            else if (parameter.name() == "band2")
                Effect->setParameterValue(parameter,0);
            else if (parameter.name() == "band3")
                Effect->setParameterValue(parameter,0);
            else if (parameter.name() == "band4")
                Effect->setParameterValue(parameter,0);
            else if (parameter.name() == "band5")
                Effect->setParameterValue(parameter,0);
            else if (parameter.name() == "band6")
                Effect->setParameterValue(parameter,0);
            else if (parameter.name() == "band7")
                Effect->setParameterValue(parameter,0);
            else if (parameter.name() == "band8")
                Effect->setParameterValue(parameter,0);
            else if (parameter.name() == "band9")
                Effect->setParameterValue(parameter,0);
        }
    }    
}

void id3mp3::on_pushButton_4_clicked()
{
    if (ui->radioButton_7->isChecked())
    {
        ui->label_16->setVisible(true);
        ui->lineEdit_15->setVisible(true);
        QString path=tr("/home/%1/Documentos/");
        path=path.arg(user);
        QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio a buscar?"),path,QFileDialog::ShowDirsOnly);
        if (fileNameDirectori.isEmpty())
        {
            ui->label_16->setVisible(false);
            ui->lineEdit_15->setVisible(false);
            return;
        }
        ui->lineEdit->setText(fileNameDirectori);
        this->Analizar();
    }
    if (ui->radioButton_4->isChecked())
    {
        listaArchivos.clear();
        ui->label_16->setVisible(true);
        ui->lineEdit_15->setVisible(true);
        QString path=tr("/home/%1/Documentos/");
        path=path.arg(user);
        listaArchivos=QFileDialog::getOpenFileNames(this,tr("Abrir Archivos"),path,"Todos los archivos (*.mp3 *.ogg)");
        if (listaArchivos.isEmpty())
        {
            ui->label_16->setVisible(false);
            ui->lineEdit_15->setVisible(false);
            return;
        }
        this->Analizar();
    }
}

void id3mp3::Analizar()
{
    if (ui->radioButton_7->isChecked())
    {
        int Borrado, x;
        Borrado = ui->tableWidget->rowCount();
        for(x=0;x<Borrado;x++)
        {
             ui->tableWidget->removeRow(x);
             x=x-1;
             Borrado=Borrado-1;
        }
        ui->lineEdit_15->setText(QString::number(Borrado));
        drakeSistema drake;
        QString Objetivo;
        if (ui->checkBox_2->isChecked())
            Objetivo = drake.getDu(ui->lineEdit->text());
        else
        {
            QString Valorar = "find \""+ui->lineEdit->text()+"\" -maxdepth 1";
            Objetivo = drake.getStart(Valorar);
        }
        if (Objetivo == "")
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("El directorio seleccionado no tiene archivos mp3/ogg para seleccionar."));
            m.exec();
            ui->label_16->setVisible(false);
            ui->lineEdit_15->setVisible(false);
            return;
        }
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_15->setEnabled(false);
        ui->pushButton_16->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_18->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->groupBox_3->setEnabled(false);
        ui->groupBox_4->setEnabled(false);
        ui->groupBox_5->setEnabled(false);
        ui->groupBox_6->setEnabled(false);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_6->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_8->setEnabled(true);
        ui->pushButton_10->setEnabled(true);
        int iFilas;
        QStringList listaArchivos1 = Objetivo.split("\n");
        listaArchivos1.sort();
        ui->progressBar->show();
        ui->progressBar->setRange(0,listaArchivos1.count());
        ui->progressBar->setTextVisible(true);
        ui->progressBar->setFormat(tr("Analizando archivos... %p%"));
        ui->textEdit->append(tr("Iniciando analisis de archivos"));
        QTest::qWait(20);
        for(int i=0;i<listaArchivos1.count();i++)
        {
            qApp->processEvents();
            if (Evento == 1)
            {
                ui->progressBar->setRange(0,100);
                ui->progressBar->setValue(0);
                ui->progressBar->setFormat("%p%");
                int Borrado, x;
                Borrado = ui->tableWidget->rowCount();
                for(x=0;x<Borrado;x++)
                {
                     ui->tableWidget->removeRow(x);
                     x=x-1;
                     Borrado=Borrado-1;
                }
                ui->lineEdit_15->setText("0");
                ui->label_16->setVisible(false);
                ui->lineEdit_15->setVisible(false);
                ui->pushButton_6->setEnabled(true);
                ui->pushButton_15->setEnabled(true);
                ui->pushButton_16->setEnabled(true);
                ui->pushButton_7->setEnabled(true);
                ui->pushButton_8->setEnabled(true);
                ui->pushButton_18->setEnabled(true);
                ui->pushButton_9->setEnabled(true);
                ui->groupBox_3->setEnabled(true);
                ui->groupBox_4->setEnabled(true);
                ui->groupBox_5->setEnabled(true);
                ui->checkBox_3->setEnabled(true);
                ui->checkBox_4->setEnabled(true);
                ui->checkBox_5->setEnabled(true);
                ui->checkBox_6->setEnabled(true);
                ui->checkBox_7->setEnabled(true);
                ui->checkBox_8->setEnabled(true);
                ui->pushButton_10->setEnabled(false);
                ui->progressBar->hide();
                ui->textEdit->append(tr("Trabajo cancelado"));
                Evento = 0;
                return;
            }
            QString ruta;
            QTableWidgetItem *item1,*item2,*item3,*item4,*item5,*item6,*item7,*item8,*item9,*item10,*item11;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            item5=new QTableWidgetItem;
            item6=new QTableWidgetItem;
            item7=new QTableWidgetItem;
            item8=new QTableWidgetItem;
            item9=new QTableWidgetItem;
            item10=new QTableWidgetItem;
            item11=new QTableWidgetItem;
            ruta=listaArchivos1.value(i);
            QFile file(ruta);
            int Peso = QFileInfo(file).size();
            if (ruta.contains(".mp3",Qt::CaseInsensitive) || ruta.contains(".ogg",Qt::CaseInsensitive))
            {
                ui->textEdit->append(tr("Analizando... ")+ruta+"");
                QStringList Nombre = ruta.split("/");
                QString Final = Nombre.value(Nombre.count()-1);
                drakeSistema drake;
                mp3Title = drake.getMp3Title(ruta);
                mp3Artist = drake.getMp3Artist(ruta);
                mp3Album = drake.getMp3Album(ruta);
                mp3Year =  drake.getMp3Year(ruta);
                mp3Comment = drake.getMp3Comment(ruta);
                mp3Track = drake.getMp3Track(ruta);
                mp3Genre = drake.getMp3Genre(ruta);
                QStringList Title = mp3Title.split(":");
                mp3Title = Title.value(1);
                if (mp3Title.left(1) == " ")
                    mp3Title = mp3Title.remove(0,1);
                QStringList Artist = mp3Artist.split(":");
                mp3Artist = Artist.value(1);
                if (mp3Artist.left(1) == " ")
                    mp3Artist = mp3Artist.remove(0,1);
                QStringList Album = mp3Album.split(":");
                mp3Album = Album.value(1);
                if (mp3Album.left(1) == " ")
                    mp3Album = mp3Album.remove(0,1);
                QStringList Year = mp3Year.split(":");
                mp3Year = Year.value(1);
                if (mp3Year.left(1) == " ")
                    mp3Year = mp3Year.remove(0,1);
                QStringList Comment0 = mp3Comment.split("\n");
                QString Comentario = Comment0.value(0);
                QStringList Comment1 = Comentario.split(":");
                mp3Comment = Comment1.value(2);
                if (mp3Comment.left(1) == " ")
                    mp3Comment = mp3Comment.remove(0,1);
                QStringList Tracks = mp3Track.split(":");
                mp3Track = Tracks.value(1);
                if (mp3Track.left(1) == " ")
                    mp3Track = mp3Track.remove(0,1);
                QStringList Genero = mp3Genre.split(":");
                mp3Genre = Genero.value(1);
                if (mp3Genre.left(1) == " ")
                    mp3Genre = mp3Genre.remove(0,1);
                mp3Genre.remove("(");
                mp3Genre.remove(")");
                int Totale = mp3Genre.size();
                if (Totale == 1)
                    mp3Genre = "00"+mp3Genre+"";
                else if (Totale == 2)
                    mp3Genre = "0"+mp3Genre+"";
                QSqlQuery Variable(db);
                Variable.exec("SELECT Genero FROM id3Genre");
                while(Variable.next())
                {
                    QString valor;
                    valor = Variable.value(0).toString();
                    if (valor.contains(mp3Genre))
                    {
                        mp3Genre = valor;
                        break;
                    }
                }
                item1->setText(Final);
                item2->setText(ruta);
                item3->setText(mp3Title);
                item4->setText(mp3Album);
                item5->setText(mp3Artist);
                item6->setText(mp3Comment);
                item7->setText(mp3Year);
                item8->setText(mp3Track);
                item9->setText(mp3Genre);
                item10->setText(tr("Si"));
                item11->setText(QString::number(Peso));
                iFilas=ui->tableWidget->rowCount();
                ui->lineEdit_15->setText(QString::number(iFilas+1));
                ui->tableWidget->insertRow(iFilas);
                ui->tableWidget->setItem(iFilas,0,item1);
                ui->tableWidget->setItem(iFilas,1,item2);
                ui->tableWidget->setItem(iFilas,2,item3);
                ui->tableWidget->setItem(iFilas,3,item4);
                ui->tableWidget->setItem(iFilas,4,item5);
                ui->tableWidget->setItem(iFilas,5,item6);
                ui->tableWidget->setItem(iFilas,6,item7);
                ui->tableWidget->setItem(iFilas,7,item8);
                ui->tableWidget->setItem(iFilas,8,item9);
                ui->tableWidget->setItem(iFilas,9,item10);
                ui->tableWidget->setItem(iFilas,10,item11);
                ui->tableWidget->item(iFilas,9)->setIcon(QIcon(":/Imagenes/good.png"));
                ui->progressBar->setValue(i);
                ui->tableWidget->resizeColumnToContents(0);
                ui->tableWidget->resizeColumnToContents(1);
                ui->tableWidget->resizeColumnToContents(2);
                ui->tableWidget->resizeColumnToContents(3);
                ui->tableWidget->resizeColumnToContents(4);
                ui->tableWidget->resizeColumnToContents(5);
                ui->tableWidget->resizeColumnToContents(6);
                ui->tableWidget->resizeColumnToContents(7);
                ui->tableWidget->resizeColumnToContents(8);
                ui->tableWidget->resizeColumnToContents(9);
                ui->tableWidget->resizeRowToContents(0);
                ui->tableWidget->resizeRowToContents(1);
                ui->tableWidget->resizeRowToContents(2);
                ui->tableWidget->resizeRowToContents(3);
                ui->tableWidget->resizeRowToContents(4);
                ui->tableWidget->resizeRowToContents(5);
                ui->tableWidget->resizeRowToContents(6);
                ui->tableWidget->resizeRowToContents(7);
                ui->tableWidget->resizeRowToContents(8);
            }
        }
        ui->progressBar->setValue(listaArchivos1.count());
        ui->progressBar->setValue(0);
        ui->progressBar->hide();
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_6->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_8->setEnabled(true);
        ui->pushButton_10->setEnabled(false);
        if (ui->tableWidget->rowCount() > 0)
        {
            ui->groupBox_6->setEnabled(true);
        }
        if (ui->radioButton_5->isChecked())
        {
            if (ui->checkBox->isChecked())
            {
                ui->lineEdit_13->setText(ui->lineEdit_15->text());
            }
        }
    }
    if (ui->radioButton_4->isChecked())
    {
        int Borrado, x;
        Borrado = ui->tableWidget->rowCount();
        for(x=0;x<Borrado;x++)
        {
             ui->tableWidget->removeRow(x);
             x=x-1;
             Borrado=Borrado-1;
        }
        ui->lineEdit_15->setText(QString::number(Borrado));
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_15->setEnabled(false);
        ui->pushButton_16->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_18->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->groupBox_3->setEnabled(false);
        ui->groupBox_4->setEnabled(false);
        ui->groupBox_5->setEnabled(false);
        ui->groupBox_6->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
        ui->checkBox_4->setEnabled(false);
        ui->checkBox_5->setEnabled(false);
        ui->checkBox_6->setEnabled(false);
        ui->checkBox_7->setEnabled(false);
        ui->checkBox_8->setEnabled(false);
        ui->pushButton_10->setEnabled(true);
        int iFilas;
        listaArchivos.sort();
        ui->progressBar->show();
        ui->progressBar->setRange(0,listaArchivos.count());
        ui->progressBar->setTextVisible(true);
        ui->progressBar->setFormat(tr("Analizando archivos... %p%"));
        ui->textEdit->append(tr("Iniciando analisis de archivos"));
        QTest::qWait(20);
        for(int i=0;i<listaArchivos.count();i++)
        {
            qApp->processEvents();
            if (Evento == 1)
            {
                ui->progressBar->setRange(0,100);
                ui->progressBar->setValue(0);
                ui->progressBar->setFormat("%p%");
                int Borrado, x;
                Borrado = ui->tableWidget->rowCount();
                for(x=0;x<Borrado;x++)
                {
                     ui->tableWidget->removeRow(x);
                     x=x-1;
                     Borrado=Borrado-1;
                }
                ui->lineEdit_15->setText("0");
                ui->label_16->setVisible(false);
                ui->lineEdit_15->setVisible(false);
                ui->pushButton_6->setEnabled(true);
                ui->pushButton_15->setEnabled(true);
                ui->pushButton_16->setEnabled(true);
                ui->pushButton_7->setEnabled(true);
                ui->pushButton_8->setEnabled(true);
                ui->pushButton_18->setEnabled(true);
                ui->pushButton_9->setEnabled(true);
                ui->groupBox_3->setEnabled(true);
                ui->groupBox_4->setEnabled(true);
                ui->groupBox_5->setEnabled(true);
                ui->checkBox_3->setEnabled(true);
                ui->checkBox_4->setEnabled(true);
                ui->checkBox_5->setEnabled(true);
                ui->checkBox_6->setEnabled(true);
                ui->checkBox_7->setEnabled(true);
                ui->checkBox_8->setEnabled(true);
                ui->pushButton_10->setEnabled(false);
                ui->progressBar->hide();
                ui->textEdit->append(tr("Trabajo cancelado"));
                Evento = 0;
                return;
            }
            QString ruta;
            QTableWidgetItem *item1,*item2,*item3,*item4,*item5,*item6,*item7,*item8,*item9,*item10,*item11;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            item5=new QTableWidgetItem;
            item6=new QTableWidgetItem;
            item7=new QTableWidgetItem;
            item8=new QTableWidgetItem;
            item9=new QTableWidgetItem;
            item10=new QTableWidgetItem;
            item11=new QTableWidgetItem;
            ruta=listaArchivos.value(i);
            QFile file(ruta);
            int Peso = QFileInfo(file).size();
            if (ruta.contains(".mp3",Qt::CaseInsensitive) || ruta.contains(".ogg",Qt::CaseInsensitive))
            {
                ui->textEdit->append(tr("Analizando... ")+ruta+"");
                QStringList Nombre = ruta.split("/");
                QString Final = Nombre.value(Nombre.count()-1);
                drakeSistema drake;
                mp3Title = drake.getMp3Title(ruta);
                mp3Artist = drake.getMp3Artist(ruta);
                mp3Album = drake.getMp3Album(ruta);
                mp3Year =  drake.getMp3Year(ruta);
                mp3Comment = drake.getMp3Comment(ruta);
                mp3Track = drake.getMp3Track(ruta);
                mp3Genre = drake.getMp3Genre(ruta);
                QStringList Title = mp3Title.split(":");
                mp3Title = Title.value(1);
                if (mp3Title.left(1) == " ")
                    mp3Title = mp3Title.remove(0,1);
                QStringList Artist = mp3Artist.split(":");
                mp3Artist = Artist.value(1);
                if (mp3Artist.left(1) == " ")
                    mp3Artist = mp3Artist.remove(0,1);
                QStringList Album = mp3Album.split(":");
                mp3Album = Album.value(1);
                if (mp3Album.left(1) == " ")
                    mp3Album = mp3Album.remove(0,1);
                QStringList Year = mp3Year.split(":");
                mp3Year = Year.value(1);
                if (mp3Year.left(1) == " ")
                    mp3Year = mp3Year.remove(0,1);
                QStringList Comment0 = mp3Comment.split("\n");
                QString Comentario = Comment0.value(0);
                QStringList Comment1 = Comentario.split(":");
                mp3Comment = Comment1.value(2);
                if (mp3Comment.left(1) == " ")
                    mp3Comment = mp3Comment.remove(0,1);
                QStringList Tracks = mp3Track.split(":");
                mp3Track = Tracks.value(1);
                if (mp3Track.left(1) == " ")
                    mp3Track = mp3Track.remove(0,1);
                QStringList Genero = mp3Genre.split(":");
                mp3Genre = Genero.value(1);
                if (mp3Genre.left(1) == " ")
                    mp3Genre = mp3Genre.remove(0,1);
                mp3Genre.remove("(");
                mp3Genre.remove(")");
                int Totale = mp3Genre.size();
                if (Totale == 1)
                    mp3Genre = "00"+mp3Genre+"";
                else if (Totale == 2)
                    mp3Genre = "0"+mp3Genre+"";
                QSqlQuery Variable(db);
                Variable.exec("SELECT Genero FROM id3Genre");
                while(Variable.next())
                {
                    QString valor;
                    valor = Variable.value(0).toString();
                    if (valor.contains(mp3Genre))
                    {
                        mp3Genre = valor;
                        break;
                    }
                }
                item1->setText(Final);
                item2->setText(ruta);
                item3->setText(mp3Title);
                item4->setText(mp3Album);
                item5->setText(mp3Artist);
                item6->setText(mp3Comment);
                item7->setText(mp3Year);
                item8->setText(mp3Track);
                item9->setText(mp3Genre);
                item10->setText(tr("Si"));
                item11->setText(QString::number(Peso));
                iFilas=ui->tableWidget->rowCount();
                ui->lineEdit_15->setText(QString::number(iFilas+1));
                ui->tableWidget->insertRow(iFilas);
                ui->tableWidget->setItem(iFilas,0,item1);
                ui->tableWidget->setItem(iFilas,1,item2);
                ui->tableWidget->setItem(iFilas,2,item3);
                ui->tableWidget->setItem(iFilas,3,item4);
                ui->tableWidget->setItem(iFilas,4,item5);
                ui->tableWidget->setItem(iFilas,5,item6);
                ui->tableWidget->setItem(iFilas,6,item7);
                ui->tableWidget->setItem(iFilas,7,item8);
                ui->tableWidget->setItem(iFilas,8,item9);
                ui->tableWidget->setItem(iFilas,9,item10);
                ui->tableWidget->setItem(iFilas,10,item11);
                ui->tableWidget->item(iFilas,9)->setIcon(QIcon(":/Imagenes/good.png"));
                ui->progressBar->setValue(i);
                ui->tableWidget->resizeColumnToContents(0);
                ui->tableWidget->resizeColumnToContents(1);
                ui->tableWidget->resizeColumnToContents(2);
                ui->tableWidget->resizeColumnToContents(3);
                ui->tableWidget->resizeColumnToContents(4);
                ui->tableWidget->resizeColumnToContents(5);
                ui->tableWidget->resizeColumnToContents(6);
                ui->tableWidget->resizeColumnToContents(7);
                ui->tableWidget->resizeColumnToContents(8);
                ui->tableWidget->resizeColumnToContents(9);
                ui->tableWidget->resizeRowToContents(0);
                ui->tableWidget->resizeRowToContents(1);
                ui->tableWidget->resizeRowToContents(2);
                ui->tableWidget->resizeRowToContents(3);
                ui->tableWidget->resizeRowToContents(4);
                ui->tableWidget->resizeRowToContents(5);
                ui->tableWidget->resizeRowToContents(6);
                ui->tableWidget->resizeRowToContents(7);
                ui->tableWidget->resizeRowToContents(8);
            }
        }
        ui->progressBar->setValue(listaArchivos.count());
        ui->progressBar->setValue(0);
        ui->progressBar->hide();
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_6->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_8->setEnabled(true);
        ui->pushButton_10->setEnabled(false);
        if (ui->tableWidget->rowCount() > 0)
        {
            ui->groupBox_6->setEnabled(true);
        }
    }
}

void id3mp3::on_pushButton_10_clicked()
{
    Evento = 1;
    if (mib != 0)
    {
        mib->killProceso();
        disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
        disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib = 0;
        ui->progressBar->setRange(0,100);
        ui->progressBar->setValue(0);
        ui->progressBar->setFormat("%p%");
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_6->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_8->setEnabled(true);
        ui->pushButton_10->setEnabled(false);
        ui->progressBar->hide();
        ui->textEdit->append(tr("Trabajo cancelado"));
        Evento = 0;
    }
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    ui->progressBar->setFormat("%p%");
    ui->progressBar->hide();    
}

void id3mp3::on_pushButton_11_clicked()
{
    ui->label_16->setVisible(true);
    ui->lineEdit_15->setVisible(true);
    this->Analizar();
}

void id3mp3::on_tableWidget_clicked()
{   
    QString valor, Titulo, Album, Artista, Comentarios, Anual, Track, Total, Genero;
    int row=ui->tableWidget->currentRow();    
    QTableWidgetItem *item1,*item2,*item3,*item4,*item5,*item6,*item7,*item8;
    item1=new QTableWidgetItem;
    item2=new QTableWidgetItem;
    item3=new QTableWidgetItem;
    item4=new QTableWidgetItem;
    item5=new QTableWidgetItem;
    item6=new QTableWidgetItem;
    item7=new QTableWidgetItem;
    item8=new QTableWidgetItem;
    item1=ui->tableWidget->item(row,1);
    item2=ui->tableWidget->item(row,2);
    item3=ui->tableWidget->item(row,3);
    item4=ui->tableWidget->item(row,4);
    item5=ui->tableWidget->item(row,5);
    item6=ui->tableWidget->item(row,6);
    item7=ui->tableWidget->item(row,7);
    item8=ui->tableWidget->item(row,8);
    valor=item1->text();
    Titulo=item2->text();
    Album=item3->text();
    Artista=item4->text();
    Comentarios=item5->text();
    Anual=item6->text();
    Track=item7->text();
    Genero=item8->text();
    if (ui->radioButton_3->isChecked())
    {
        ui->lineEdit_16->setText(Titulo);
        ui->lineEdit_10->setText(Album);
        ui->lineEdit_11->setText(Artista);
        ui->lineEdit_14->setText(Anual);
        if (Track.contains("/"))
        {
            QStringList PTrack = Track.split("/");
            Track = PTrack.value(0);
            Total = PTrack.value(1);
        }
        else
        {
            Total = "";
        }
        ui->lineEdit_12->setText(Track);
        ui->lineEdit_13->setText(Total);
        ui->lineEdit_20->setText(Comentarios);
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(Genero));
    }
    ui->groupBox_6->setEnabled(true);
    bool wasPlaying = MediaObject->state() == Phonon::PlayingState;
    if (wasPlaying)
    {
        MediaObject->stop();
        QTest::qWait(500);
        Phonon::MediaSource source(valor);
        MediaObject->setCurrentSource(source);
        ui->pushButton_12->setEnabled(true);
        ui->pushButton_13->setEnabled(false);
        ui->pushButton_14->setEnabled(false);
        this->on_pushButton_12_clicked();
    }
    else
    {
        MediaObject->stop();
        QTest::qWait(500);
        Phonon::MediaSource source(valor);
        MediaObject->setCurrentSource(source);
        MediaObject->pause();
        ui->pushButton_12->setEnabled(true);
        ui->pushButton_13->setEnabled(false);
        ui->pushButton_14->setEnabled(false);
    }
}

void id3mp3::on_pushButton_15_clicked()
{
    int iFilas, a;
    iFilas=ui->tableWidget->rowCount();
    if (iFilas > 0)
    {
        for(a=0;a<iFilas;a++)
        {
            QTableWidgetItem *item;
            item=new QTableWidgetItem;
            qApp->processEvents();
            item->setText(tr("Si"));
            ui->tableWidget->setItem(a,9,item);
            ui->tableWidget->item(a,9)->setIcon(QIcon(":/Imagenes/good.png"));

        }
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
    }
}

void id3mp3::on_pushButton_16_clicked()
{
    int iFilas, a;
    iFilas=ui->tableWidget->rowCount();
    if (iFilas > 0)
    {
        for(a=0;a<iFilas;a++)
        {
            QTableWidgetItem *item;
            item=new QTableWidgetItem;
            qApp->processEvents();
            item->setText(tr("No"));
            ui->tableWidget->setItem(a,9,item);
            ui->tableWidget->item(a,9)->setIcon(QIcon(":/Imagenes/bad.png"));
        }
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
    }
}

void id3mp3::on_pushButton_17_clicked()
{
    int iFilas;
    iFilas=ui->tableWidget->currentRow();
    QTableWidgetItem *item,*item1,*item2,*item3,*item4,*item5,*item6,*item7,*item8;
    if (iFilas == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        Totalizar = 0;
        TotalProceso = 0;
        item=new QTableWidgetItem;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        item4=new QTableWidgetItem;
        item5=new QTableWidgetItem;
        item6=new QTableWidgetItem;
        item7=new QTableWidgetItem;
        item8=new QTableWidgetItem;
        item = ui->tableWidget->item(ui->tableWidget->currentRow(),1);
        item1->setText(ui->lineEdit_16->text());
        item2->setText(ui->lineEdit_10->text());
        item3->setText(ui->lineEdit_11->text());
        item4->setText(ui->lineEdit_20->text());
        item5->setText(ui->lineEdit_14->text());
        item6->setText(""+ui->lineEdit_12->text()+"/"+ui->lineEdit_13->text()+"");
        item7->setText(ui->comboBox->currentText());
        item8->setText(tr("Si"));
        ui->tableWidget->setItem(iFilas,2,item1);
        ui->tableWidget->setItem(iFilas,3,item2);
        ui->tableWidget->setItem(iFilas,4,item3);
        ui->tableWidget->setItem(iFilas,5,item4);
        ui->tableWidget->setItem(iFilas,6,item5);
        ui->tableWidget->setItem(iFilas,7,item6);
        ui->tableWidget->setItem(iFilas,8,item7);
        ui->tableWidget->setItem(iFilas,9,item8);
        ui->tableWidget->item(iFilas,9)->setIcon(QIcon(":/Imagenes/good.png"));
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();
    }
    QStringList comandos;
    QString Title= ui->lineEdit_16->text();
    QString Artist= ui->lineEdit_11->text();
    QString Album=  ui->lineEdit_10->text();
    QString Year= ui->lineEdit_14->text();
    QString Comment= ui->lineEdit_20->text();
    QString Track= ui->lineEdit_12->text();
    QString Total= ui->lineEdit_13->text();
    QString Genero = ui->comboBox->currentText();
    int Valor = Genero.size();
    int Value = Valor-3;
    Genero.chop(Value);
    QString ruta = item->text();
    QString cmd, cmd1;
    if (ui->comboBox_4->currentText() == "id3v1")
    {
        cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=\"%4\" --comment=\"%5\" --track=%6/%7 --genre=\"%8\" -1 \"%9\"";
        cmd1=cmd1.arg(Artist).arg(Title).arg(Album).arg(Year).arg(Comment).arg(Track).arg(Total).arg(Genero).arg(ruta);
        QString cmd2 = "chown %1:%1 \"%2\"";
        cmd2 = cmd2.arg(user).arg(ruta);
        comandos<< cmd1 << cmd2;
    }
    if (ui->comboBox_4->currentText() == "id3v2")
    {
        cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=\"%4\" --comment=\"%5\" --track=%6/%7 --genre=\"%8\" -2 \"%9\"";
        cmd1=cmd1.arg(Artist).arg(Title).arg(Album).arg(Year).arg(Comment).arg(Track).arg(Total).arg(Genero).arg(ruta);
        QString cmd2 = "chown %1:%1 \"%2\"";
        cmd2 = cmd2.arg(user).arg(ruta);
        comandos<< cmd1 << cmd2;
    }
    if (ui->comboBox_4->currentText() == tr("Todas"))
    {
        cmd = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=\"%4\" --comment=\"%5\" --track=%6/%7 --genre=\"%8\" -1 \"%9\"";
        cmd=cmd.arg(Artist).arg(Title).arg(Album).arg(Year).arg(Comment).arg(Track).arg(Total).arg(Genero).arg(ruta);
        cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=\"%4\" --comment=\"%5\" --track=%6/%7 --genre=\"%8\" -2 \"%9\"";
        cmd1=cmd1.arg(Artist).arg(Title).arg(Album).arg(Year).arg(Comment).arg(Track).arg(Total).arg(Genero).arg(ruta);
        QString cmd2 = "chown %1:%1 \"%2\"";
        cmd2 = cmd2.arg(user).arg(ruta);
        comandos<< cmd << cmd1 << cmd2;
    }
    if (mib != 0)
        delete mib;
    ui->progressBar->show();
    mib = new DrakeProcesos1(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count();
    mib->Valor(valor,3);
    mib->iniciarProceso();
    Totalizar = comandos.count();
    ui->progressBar->setRange(0,Totalizar);
}

void id3mp3::on_pushButton_6_clicked()
{
    int iFilas;
    iFilas=ui->tableWidget->currentRow();
    if (iFilas == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QTableWidgetItem *item;
        item=new QTableWidgetItem;
        item->setText(tr("Si"));
        ui->tableWidget->setItem(iFilas,9,item);
        ui->tableWidget->item(iFilas,9)->setIcon(QIcon(":/Imagenes/good.png"));
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
    }
}

void id3mp3::on_pushButton_9_clicked()
{
    int iFilas;
    iFilas=ui->tableWidget->currentRow();
    if (iFilas == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QTableWidgetItem *item;
        item=new QTableWidgetItem;
        item->setText(tr("No"));
        ui->tableWidget->setItem(iFilas,9,item);
        ui->tableWidget->item(iFilas,9)->setIcon(QIcon(":/Imagenes/bad.png"));
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
    }
}

void id3mp3::on_pushButton_7_clicked()
{
    int Campo = ui->tableWidget->currentRow();
    if (Campo == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro para borrar."));
        m.exec();
        return;
    }
    ui->tableWidget->removeRow(Campo);
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    int Valor = ui->tableWidget->rowCount();
    ui->lineEdit_15->setText(QString::number(Valor));
}

void id3mp3::on_pushButton_8_clicked()
{
    int Val=ui->tableWidget->rowCount();
    if (Val > 0)
    {
        if (ui->radioButton_6->isChecked())
        {
            Totalizar = 0;
            TotalProceso = 0;
            ui->pushButton_6->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_7->setEnabled(false);
            ui->pushButton_8->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_9->setEnabled(false);
            ui->groupBox_3->setEnabled(false);
            ui->groupBox_4->setEnabled(false);
            ui->groupBox_5->setEnabled(false);
            ui->groupBox_6->setEnabled(false);
            ui->checkBox_3->setEnabled(false);
            ui->checkBox_4->setEnabled(false);
            ui->checkBox_5->setEnabled(false);
            ui->checkBox_6->setEnabled(false);
            ui->checkBox_7->setEnabled(false);
            ui->checkBox_8->setEnabled(false);
            ui->pushButton_10->setEnabled(true);
            ui->label_16->setVisible(true);
            ui->lineEdit_15->setVisible(true);
            ControlNum = 1;
            ui->progressBar->show();
            int iFilas, a, Valor, Residuo, Total;
            QString Value, Relleno;
            Valor = ui->lineEdit_9->text().toInt();
            Residuo = ui->lineEdit_15->text().toInt() + (Valor-1);
            Total = QString::number(Residuo).size();
            QStringList comandos;
            iFilas=ui->tableWidget->rowCount();
            if (iFilas > 0)
            {
                QString Ruta, Titulo, Marca;
                QTableWidgetItem *item,*item1,*item2;
                for(a=0;a<iFilas;a++)
                {
                    qApp->processEvents();
                    if (Evento == 1)
                    {
                        ui->progressBar->setRange(0,100);
                        ui->progressBar->setValue(0);
                        ui->progressBar->setFormat("%p%");
                        ui->pushButton_6->setEnabled(true);
                        ui->pushButton_15->setEnabled(true);
                        ui->pushButton_16->setEnabled(true);
                        ui->pushButton_7->setEnabled(true);
                        ui->pushButton_8->setEnabled(true);
                        ui->pushButton_18->setEnabled(true);
                        ui->pushButton_9->setEnabled(true);
                        ui->groupBox_3->setEnabled(true);
                        ui->groupBox_4->setEnabled(true);
                        ui->groupBox_5->setEnabled(true);
                        ui->checkBox_3->setEnabled(true);
                        ui->checkBox_4->setEnabled(true);
                        ui->checkBox_5->setEnabled(true);
                        ui->checkBox_6->setEnabled(true);
                        ui->checkBox_7->setEnabled(true);
                        ui->checkBox_8->setEnabled(true);
                        ui->pushButton_10->setEnabled(false);
                        ui->progressBar->hide();
                        ui->textEdit->append(tr("Trabajo cancelado"));
                        Evento = 0;
                        return;
                    }
                    item=new QTableWidgetItem;
                    item1=new QTableWidgetItem;
                    item2=new QTableWidgetItem;
                    item = ui->tableWidget->item(a,1);
                    item1 = ui->tableWidget->item(a,2);
                    item2 = ui->tableWidget->item(a,9);
                    Marca = item2->text();
                    if (Marca == tr("Si"))
                    {
                        Ruta = item->text();
                        Value = QString::number(Valor);
                        QString cmd, cmd1;
                        if (ui->checkBox_10->isChecked())
                        {
                            Relleno = Total;
                        }
                        else
                        {
                            if (ui->comboBox_3->currentText() == tr("Por defecto"))
                            {
                                Relleno = Value.rightJustified(Total,'0');
                            }
                            else if (ui->comboBox_3->currentText() != tr("Por defecto"))
                            {
                                int Tamano = ui->comboBox_3->currentText().toInt();
                                Relleno = Value.rightJustified(Tamano,'0');
                            }
                        }
                        Titulo = ""+Relleno+" "+item1->text()+"";
                        if (ui->comboBox_4->currentText() == "id3v1")
                        {
                            cmd1 = "id3v2 --song=\"%1\" -1 \"%2\"";
                            cmd1=cmd1.arg(Titulo).arg(Ruta);
                            QString cmd2 = "chown %1:%1 \"%2\"";
                            cmd2 = cmd2.arg(user).arg(Ruta);
                            comandos<< cmd1 << cmd2;
                        }
                        if (ui->comboBox_4->currentText() == "id3v2")
                        {
                            cmd1 = "id3v2 --song=\"%1\" -2 \"%2\"";
                            cmd1=cmd1.arg(Titulo).arg(Ruta);
                            QString cmd2 = "chown %1:%1 \"%2\"";
                            cmd2 = cmd2.arg(user).arg(Ruta);
                            comandos<< cmd1 << cmd2;
                        }
                        if (ui->comboBox_4->currentText() == tr("Todas"))
                        {
                            cmd = "id3v2 --song=\"%1\" -1 \"%2\"";
                            cmd=cmd.arg(Titulo).arg(Ruta);
                            cmd1 = "id3v2 --song=\"%1\" -2 \"%2\"";
                            cmd1=cmd1.arg(Titulo).arg(Ruta);
                            QString cmd2 = "chown %1:%1 \"%2\"";
                            cmd2 = cmd2.arg(user).arg(Ruta);
                            comandos<< cmd << cmd1 << cmd2;
                        }
                        Valor++;
                    }
                }
                mib = new DrakeProcesos1(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                int valor= comandos.count();
                mib->Valor(valor,3);
                mib->iniciarProceso();
                Totalizar = comandos.count();
                ui->progressBar->setRange(0,Totalizar);
            }
        }
        if (ui->radioButton_5->isChecked())
        {
            if (ui->checkBox->isChecked())
            {
                Totalizar = 0;
                TotalProceso = 0;
                ControlNum = 2;
                ui->progressBar->show();
                ui->progressBar->setFormat(tr("Cambiando etiqueta a archivos... %p%"));
                ui->pushButton_6->setEnabled(false);
                ui->pushButton_15->setEnabled(false);
                ui->pushButton_16->setEnabled(false);
                ui->pushButton_7->setEnabled(false);
                ui->pushButton_8->setEnabled(false);
                ui->pushButton_18->setEnabled(false);
                ui->pushButton_9->setEnabled(false);
                ui->groupBox_3->setEnabled(false);
                ui->groupBox_4->setEnabled(false);
                ui->groupBox_5->setEnabled(false);
                ui->groupBox_6->setEnabled(false);
                ui->checkBox_3->setEnabled(false);
                ui->checkBox_4->setEnabled(false);
                ui->checkBox_5->setEnabled(false);
                ui->checkBox_6->setEnabled(false);
                ui->checkBox_7->setEnabled(false);
                ui->checkBox_8->setEnabled(false);
                ui->pushButton_10->setEnabled(true);
                int iFilas, a, Valor, Residuo, Total;
                QString Value, Relleno;
                Valor = ui->lineEdit_12->text().toInt();
                Residuo = ui->lineEdit_13->text().toInt() + (Valor-1);
                Total = QString::number(Residuo).size();
                QStringList comandos;
                iFilas=ui->tableWidget->rowCount();
                if (iFilas > 0)
                {
                    QString Ruta, Titulo, Album, Artista, Comentarios, Anual, Track, Genero, Marca;
                    QString Album1, Artista1, Comentarios1, Anual1, Track1, Total1, Genero1;
                    QTableWidgetItem *item,*item1,*item2,*item3,*item4,*item5,*item6,*item7,*item8;
                    for(a=0;a<iFilas;a++)
                    {
                        qApp->processEvents();
                        if (Evento == 1)
                        {
                            ui->progressBar->setRange(0,100);
                            ui->progressBar->setValue(0);
                            ui->progressBar->setFormat("%p%");
                            ui->pushButton_6->setEnabled(true);
                            ui->pushButton_15->setEnabled(true);
                            ui->pushButton_16->setEnabled(true);
                            ui->pushButton_7->setEnabled(true);
                            ui->pushButton_8->setEnabled(true);
                            ui->pushButton_18->setEnabled(true);
                            ui->pushButton_9->setEnabled(true);
                            ui->groupBox_3->setEnabled(true);
                            ui->groupBox_4->setEnabled(true);
                            ui->groupBox_5->setEnabled(true);
                            ui->checkBox_3->setEnabled(true);
                            ui->checkBox_4->setEnabled(true);
                            ui->checkBox_5->setEnabled(true);
                            ui->checkBox_6->setEnabled(true);
                            ui->checkBox_7->setEnabled(true);
                            ui->checkBox_8->setEnabled(true);
                            ui->pushButton_10->setEnabled(false);
                            ui->progressBar->hide();
                            ui->textEdit->append(tr("Trabajo cancelado"));
                            Evento = 0;
                            return;
                        }
                        item=new QTableWidgetItem;
                        item1=new QTableWidgetItem;
                        item2=new QTableWidgetItem;
                        item3=new QTableWidgetItem;
                        item4=new QTableWidgetItem;
                        item5=new QTableWidgetItem;
                        item6=new QTableWidgetItem;
                        item7=new QTableWidgetItem;
                        item8=new QTableWidgetItem;
                        item= ui->tableWidget->item(a,0);
                        item1= ui->tableWidget->item(a,1);
                        item2= ui->tableWidget->item(a,3);
                        item3= ui->tableWidget->item(a,4);
                        item4= ui->tableWidget->item(a,5);
                        item5= ui->tableWidget->item(a,6);
                        item6= ui->tableWidget->item(a,7);
                        item7= ui->tableWidget->item(a,8);
                        item8 = ui->tableWidget->item(a,9);
                        Marca = item8->text();
                        if (Marca == tr("Si"))
                        {
                            Ruta = item1->text();
                            Titulo = item->text();
                            Titulo = Titulo.remove(".mp3",Qt::CaseInsensitive).remove(".ogg",Qt::CaseInsensitive);
                            Album = item2->text();
                            Artista = item3->text();
                            Comentarios = item4->text();
                            Anual = item5->text();
                            Track = item6->text();
                            Genero = item7->text();
                            Value = QString::number(Valor);
                            if (ui->checkBox_10->isChecked())
                            {
                                Relleno = Total;
                            }
                            else
                            {
                                Relleno = Value.rightJustified(Total,'0');
                            }
                            if (ui->checkBox_3->isChecked())
                            {
                                Album1 = ui->lineEdit_10->text();
                            }
                            else
                            {
                                Album1 = Album;
                            }
                            if (ui->checkBox_4->isChecked())
                            {
                                Artista1 = ui->lineEdit_11->text();
                            }
                            else
                            {
                                Artista1 = Artista;
                            }
                            if (ui->checkBox_5->isChecked())
                            {
                                Comentarios1 = ui->lineEdit_20->text();
                            }
                            else
                            {
                                Comentarios1 = Comentarios;
                            }
                            if (ui->checkBox_6->isChecked())
                            {
                                Genero1 = ui->comboBox->currentText();
                            }
                            else
                            {
                                Genero1 = Genero;
                            }
                            int ValorGen = Genero1.size();
                            int ValueGen = ValorGen-3;
                            Genero1.chop(ValueGen);
                            if (ui->checkBox_7->isChecked())
                            {
                                Anual1 = ui->lineEdit_14->text();
                            }
                            else
                            {
                                Anual1 = Anual;
                            }
                            Value = QString::number(Valor);
                            if (ui->checkBox_10->isChecked())
                            {
                                Relleno = Value;
                            }
                            else
                            {
                                Relleno = Value.rightJustified(Total,'0');
                            }
                            if (ui->checkBox_8->isChecked())
                            {
                                Track1 = Relleno;
                                Total1 = ui->lineEdit_13->text();
                            }
                            else
                            {
                                QStringList Tracks;
                                Tracks = Track.split("/");
                                QString PTrack = Tracks.value(0);
                                QString TTrack = Tracks.value(1);
                                Track1 = PTrack;
                                Total1 = TTrack;
                            }
                            QString cmd, cmd1;
                            if (ui->checkBox_9->isChecked())
                            {
                                if (ui->comboBox_4->currentText() == "id3v1")
                                {
                                    cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=%4 --comment=\"%5\" --track=%6 --genre=%7 -1 \"%8\"";
                                    cmd1=cmd1.arg(Artista1).arg(Titulo).arg(Album1).arg(Anual1).arg(Comentarios1).arg(Track1).arg(Genero1).arg(Ruta);
                                    QString cmd2 = "chown %1:%1 \"%2\"";
                                    cmd2 = cmd2.arg(user).arg(Ruta);
                                    comandos<< cmd1 << cmd2;
                                }
                                if (ui->comboBox_4->currentText() == "id3v2")
                                {
                                    cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=%4 --comment=\"%5\" --track=%6 --genre=%7 -2 \"%8\"";
                                    cmd1=cmd1.arg(Artista1).arg(Titulo).arg(Album1).arg(Anual1).arg(Comentarios1).arg(Track1).arg(Genero1).arg(Ruta);
                                    QString cmd2 = "chown %1:%1 \"%2\"";
                                    cmd2 = cmd2.arg(user).arg(Ruta);
                                    comandos<< cmd1 << cmd2;
                                }
                                if (ui->comboBox_4->currentText() == tr("Todas"))
                                {
                                    cmd = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=%4 --comment=\"%5\" --track=%6 --genre=%7 -1 \"%8\"";
                                    cmd=cmd.arg(Artista1).arg(Titulo).arg(Album1).arg(Anual1).arg(Comentarios1).arg(Track1).arg(Genero1).arg(Ruta);
                                    cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=%4 --comment=\"%5\" --track=%6 --genre=%7 -2 \"%8\"";
                                    cmd1=cmd1.arg(Artista1).arg(Titulo).arg(Album1).arg(Anual1).arg(Comentarios1).arg(Track1).arg(Genero1).arg(Ruta);
                                    QString cmd2 = "chown %1:%1 \"%2\"";
                                    cmd2 = cmd2.arg(user).arg(Ruta);
                                    comandos<< cmd << cmd1 << cmd2;
                                }
                            }
                            else
                            {
                                if (ui->comboBox_4->currentText() == "id3v1")
                                {
                                    cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=%4 --comment=\"%5\" --track=%6/%7 --genre=%8 -1 \"%9\"";
                                    cmd1=cmd1.arg(Artista1).arg(Titulo).arg(Album1).arg(Anual1).arg(Comentarios1).arg(Track1).arg(Total1).arg(Genero1).arg(Ruta);
                                    QString cmd2 = "chown %1:%1 \"%2\"";
                                    cmd2 = cmd2.arg(user).arg(Ruta);
                                    comandos<< cmd1 << cmd2;
                                }
                                if (ui->comboBox_4->currentText() == "id3v2")
                                {
                                    cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=%4 --comment=\"%5\" --track=%6/%7 --genre=%8 -2 \"%9\"";
                                    cmd1=cmd1.arg(Artista1).arg(Titulo).arg(Album1).arg(Anual1).arg(Comentarios1).arg(Track1).arg(Total1).arg(Genero1).arg(Ruta);
                                    QString cmd2 = "chown %1:%1 \"%2\"";
                                    cmd2 = cmd2.arg(user).arg(Ruta);
                                    comandos<< cmd1 << cmd2;
                                }
                                if (ui->comboBox_4->currentText() == tr("Todas"))
                                {
                                    cmd = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=%4 --comment=\"%5\" --track=%6/%7 --genre=%8 -1 \"%9\"";
                                    cmd=cmd.arg(Artista1).arg(Titulo).arg(Album1).arg(Anual1).arg(Comentarios1).arg(Track1).arg(Total1).arg(Genero1).arg(Ruta);
                                    cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=%4 --comment=\"%5\" --track=%6/%7 --genre=%8 -2 \"%9\"";
                                    cmd1=cmd1.arg(Artista1).arg(Titulo).arg(Album1).arg(Anual1).arg(Comentarios1).arg(Track1).arg(Total1).arg(Genero1).arg(Ruta);
                                    QString cmd2 = "chown %1:%1 \"%2\"";
                                    cmd2 = cmd2.arg(user).arg(Ruta);
                                    comandos<< cmd << cmd1 << cmd2;
                                }
                            }
                            Valor++;
                        }
                    }
                    mib = new DrakeProcesos1(comandos, this);
                    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                    connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
                    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                    int valor= comandos.count();
                    mib->Valor(valor,3);
                    mib->iniciarProceso();
                    Totalizar = comandos.count();
                    ui->progressBar->setRange(0,Totalizar);
                }
            }
            else
            {
                Totalizar = 0;
                TotalProceso = 0;
                ControlNum = 2;
                ui->progressBar->show();
                ui->progressBar->setFormat(tr("Cambiando etiqueta a archivos... %p%"));
                ui->pushButton_6->setEnabled(false);
                ui->pushButton_15->setEnabled(false);
                ui->pushButton_16->setEnabled(false);
                ui->pushButton_7->setEnabled(false);
                ui->pushButton_8->setEnabled(false);
                ui->pushButton_18->setEnabled(false);
                ui->pushButton_9->setEnabled(false);
                ui->groupBox_3->setEnabled(false);
                ui->groupBox_4->setEnabled(false);
                ui->groupBox_5->setEnabled(false);
                ui->groupBox_6->setEnabled(false);
                ui->checkBox_3->setEnabled(false);
                ui->checkBox_4->setEnabled(false);
                ui->checkBox_5->setEnabled(false);
                ui->checkBox_6->setEnabled(false);
                ui->checkBox_7->setEnabled(false);
                ui->checkBox_8->setEnabled(false);
                ui->pushButton_10->setEnabled(true);
                int iFilas, a;
                QStringList comandos;
                iFilas=ui->tableWidget->rowCount();
                if (iFilas > 0)
                {
                    QString Ruta, Titulo, Marca;
                    QTableWidgetItem *item0,*item,*item2;
                    for(a=0;a<iFilas;a++)
                    {
                        qApp->processEvents();
                        if (Evento == 1)
                        {
                            ui->progressBar->setRange(0,100);
                            ui->progressBar->setValue(0);
                            ui->progressBar->setFormat("%p%");
                            ui->pushButton_6->setEnabled(true);
                            ui->pushButton_15->setEnabled(true);
                            ui->pushButton_16->setEnabled(true);
                            ui->pushButton_7->setEnabled(true);
                            ui->pushButton_8->setEnabled(true);
                            ui->pushButton_18->setEnabled(true);
                            ui->pushButton_9->setEnabled(true);
                            ui->groupBox_3->setEnabled(true);
                            ui->groupBox_4->setEnabled(true);
                            ui->groupBox_5->setEnabled(true);
                            ui->checkBox_3->setEnabled(true);
                            ui->checkBox_4->setEnabled(true);
                            ui->checkBox_5->setEnabled(true);
                            ui->checkBox_6->setEnabled(true);
                            ui->checkBox_7->setEnabled(true);
                            ui->checkBox_8->setEnabled(true);
                            ui->pushButton_10->setEnabled(false);
                            ui->progressBar->hide();
                            ui->textEdit->append(tr("Trabajo cancelado"));
                            Evento = 0;
                            return;
                        }
                        item0=new QTableWidgetItem;
                        item=new QTableWidgetItem;
                        item2=new QTableWidgetItem;
                        item0= ui->tableWidget->item(a,0);
                        item= ui->tableWidget->item(a,1);
                        item2 = ui->tableWidget->item(a,9);
                        Marca = item2->text();
                        if (Marca == tr("Si"))
                        {
                            Ruta = item->text();
                            Titulo = item0->text();
                            Titulo = Titulo.remove(".mp3",Qt::CaseInsensitive).remove(".ogg",Qt::CaseInsensitive);
                            QString cmd, cmd1;
                            if (ui->comboBox_4->currentText() == "id3v1")
                            {
                                cmd1 = "id3v2 --song=\"%1\" -1 \"%2\"";
                                cmd1=cmd1.arg(Titulo).arg(Ruta);
                                QString cmd2 = "chown %1:%1 \"%2\"";
                                cmd2 = cmd2.arg(user).arg(Ruta);
                                comandos<< cmd1 << cmd2;
                            }
                            if (ui->comboBox_4->currentText() == "id3v2")
                            {
                                cmd1 = "id3v2 --song=\"%1\" -2 \"%2\"";
                                cmd1=cmd1.arg(Titulo).arg(Ruta);
                                QString cmd2 = "chown %1:%1 \"%2\"";
                                cmd2 = cmd2.arg(user).arg(Ruta);
                                comandos<< cmd1 << cmd2;
                            }
                            if (ui->comboBox_4->currentText() == tr("Todas"))
                            {
                                cmd = "id3v2 --song=\"%1\" -1 \"%2\"";
                                cmd=cmd.arg(Titulo).arg(Ruta);
                                cmd1 = "id3v2 --song=\"%1\" -2 \"%2\"";
                                cmd1=cmd1.arg(Titulo).arg(Ruta);
                                QString cmd2 = "chown %1:%1 \"%2\"";
                                cmd2 = cmd2.arg(user).arg(Ruta);
                                comandos<< cmd << cmd1 << cmd2;
                            }
                        }
                    }
                    mib = new DrakeProcesos1(comandos, this);
                    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                    connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
                    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                    int valor= comandos.count();
                    mib->Valor(valor,3);
                    mib->iniciarProceso();
                    Totalizar = comandos.count();
                    ui->progressBar->setRange(0,Totalizar);
                }
            }
        }        
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay registros cargados para poder realizar los cambios."));
        m.exec();
        return;
    }
}

void id3mp3::final()
{
    MediaObject->stop();
    ui->pushButton_12->setEnabled(true);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
}

void id3mp3::on_pushButton_18_clicked()
{
    ui->groupBox_8->setVisible(true);
    ui->pushButton_18->setVisible(false);
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("ADVERTENCIA IMPORTANTE")),
                QString::fromUtf8(tr("<center><b>PRECAUCION</center><p>"
                           "Si aceptas esta opcion borraras todas las etiquetas de todos los archivos musicales "
                           "seleccionados.<p>"
                           "Debes seleccionar el tipo de borrado y pulsar el boton correspondiente para realizar "
                           "el borrado definitivo.<p>"
                           "Ten en cuenta el tipo de etiqueta que quieres borrar y seleccionarla en las nuevas opciones "
                           "que apareceran al continuar el proceso, ya que segun "
                           "la version seleccionada se borraran unas u otras, por lo que si quieres borrar masivo "
                           "tanto en version 1 como version 2 deberias poner la opcion de \"Borrar todas las etiquetas\" (Recomendada).<p>"
                           "<B>NOTA: Procede con mucha precaucion o no aceptes la opcion si no "
                           "sabes lo que estas haciendo.</B><p>"
                           "&iquest;Borrar todas las etiquetas?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::No)
    {
        ui->groupBox_8->setVisible(false);
        ui->pushButton_18->setVisible(true);
    }
}

void id3mp3::on_pushButton_19_clicked()
{
    int itemCount = ui->tableWidget->rowCount();
    if (itemCount > 0)
    {
        ui->progressBar->show();
        ui->progressBar->setFormat(tr("Eliminando todas las etiquetas... %p%"));
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_15->setEnabled(false);
        ui->pushButton_16->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_18->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->groupBox_3->setEnabled(false);
        ui->groupBox_4->setEnabled(false);
        ui->groupBox_5->setEnabled(false);
        ui->groupBox_6->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
        ui->checkBox_4->setEnabled(false);
        ui->checkBox_5->setEnabled(false);
        ui->checkBox_6->setEnabled(false);
        ui->checkBox_7->setEnabled(false);
        ui->checkBox_8->setEnabled(false);
        ui->pushButton_10->setEnabled(true);
        QString Nombre = "Lista";
        QString path=tr("/home/%1/Documentos/%2.m3u");
        path=path.arg(user).arg(Nombre);
        QString fileNameDestino = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar lista .m3u")),
                            path,trUtf8(tr("Archivo .m3u (*.m3u)")));
        if (fileNameDestino.isEmpty())
        {
            ui->progressBar->setRange(0,100);
            ui->progressBar->setValue(0);
            ui->progressBar->setFormat("%p%");
            ui->pushButton_6->setEnabled(true);
            ui->pushButton_15->setEnabled(true);
            ui->pushButton_16->setEnabled(true);
            ui->pushButton_7->setEnabled(true);
            ui->pushButton_8->setEnabled(true);
            ui->pushButton_18->setEnabled(true);
            ui->pushButton_9->setEnabled(true);
            ui->groupBox_3->setEnabled(true);
            ui->groupBox_4->setEnabled(true);
            ui->groupBox_5->setEnabled(true);
            ui->checkBox_3->setEnabled(true);
            ui->checkBox_4->setEnabled(true);
            ui->checkBox_5->setEnabled(true);
            ui->checkBox_6->setEnabled(true);
            ui->checkBox_7->setEnabled(true);
            ui->checkBox_8->setEnabled(true);
            ui->pushButton_10->setEnabled(false);
            ui->progressBar->hide();
            return;
        }
        if (fileNameDestino.contains(".m3u"))
            fileNameDestino.remove(".m3u");
        QFile file(""+fileNameDestino+".m3u");
        file.open(QIODevice::WriteOnly | QIODevice::Truncate);
        QTextStream in(&file);
        QString activo;
        ui->progressBar->setRange(0,itemCount);
        ui->textEdit->append(tr("Creando lista en ruta "+fileNameDestino+".m3u"));
        QTableWidgetItem *item;
        for(int i=0;i<itemCount;i++)
        {
            item=new QTableWidgetItem;
            item = ui->tableWidget->item(i,1);
            activo = item->text();
            in << activo + "\n";
            ui->progressBar->setValue(i);
        }
        ui->progressBar->setValue(itemCount);
        ui->textEdit->append(tr("Fichero creado correctamente."));
        file.close();
        ui->progressBar->setRange(0,100);
        ui->progressBar->setValue(0);
        ui->progressBar->setFormat("%p%");
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_6->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_8->setEnabled(true);
        ui->pushButton_10->setEnabled(false);
        ui->progressBar->hide();
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay registros cargados para poder crear la lista de reproduccion."));
        m.exec();
        ui->progressBar->setRange(0,100);
        ui->progressBar->setValue(0);
        ui->progressBar->setFormat("%p%");
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_6->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_8->setEnabled(true);
        ui->pushButton_10->setEnabled(false);
        ui->progressBar->hide();
        return;
    }
}

void id3mp3::on_pushButton_20_clicked()
{
    int iFilas, a;
    QStringList comandos;
    QString Ruta, Marca;
    QTableWidgetItem *item1,*item2;
    iFilas=ui->tableWidget->rowCount();
    if (iFilas > 0)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("ADVERTENCIA IMPORTANTE")),
                    QString::fromUtf8(tr("<center><b>PRECAUCION</center><p>"
                               "Vas a cambiar masivamente las etiquetas id3v2 por lo que perderas los datos que tuvieras guardados.<p>"
                               "<B>NOTA: Procede con mucha precaucion o no aceptes la opcion si no "
                               "sabes lo que estas haciendo.</B><p>"
                               "&iquest;Importar etiquetas id3v1 a ide3v2?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            Totalizar = 0;
            TotalProceso = 0;
            ControlNum = 2;
            ui->progressBar->show();
            ui->progressBar->setFormat(tr("Importando id3v2 a id3v1... %p%"));
            ui->pushButton_6->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_7->setEnabled(false);
            ui->pushButton_8->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_9->setEnabled(false);
            ui->groupBox_3->setEnabled(false);
            ui->groupBox_4->setEnabled(false);
            ui->groupBox_5->setEnabled(false);
            ui->groupBox_6->setEnabled(false);
            ui->checkBox_3->setEnabled(false);
            ui->checkBox_4->setEnabled(false);
            ui->checkBox_5->setEnabled(false);
            ui->checkBox_6->setEnabled(false);
            ui->checkBox_7->setEnabled(false);
            ui->checkBox_8->setEnabled(false);
            ui->pushButton_10->setEnabled(true);
            for(a=0;a<iFilas;a++)
            {
                qApp->processEvents();
                if (Evento == 1)
                {
                    ui->progressBar->setRange(0,100);
                    ui->progressBar->setValue(0);
                    ui->progressBar->setFormat("%p%");
                    ui->pushButton_6->setEnabled(true);
                    ui->pushButton_15->setEnabled(true);
                    ui->pushButton_16->setEnabled(true);
                    ui->pushButton_7->setEnabled(true);
                    ui->pushButton_8->setEnabled(true);
                    ui->pushButton_18->setEnabled(true);
                    ui->pushButton_9->setEnabled(true);
                    ui->groupBox_3->setEnabled(true);
                    ui->groupBox_4->setEnabled(true);
                    ui->groupBox_5->setEnabled(true);
                    ui->checkBox_3->setEnabled(true);
                    ui->checkBox_4->setEnabled(true);
                    ui->checkBox_5->setEnabled(true);
                    ui->checkBox_6->setEnabled(true);
                    ui->checkBox_7->setEnabled(true);
                    ui->checkBox_8->setEnabled(true);
                    ui->pushButton_10->setEnabled(false);
                    ui->progressBar->hide();
                    ui->textEdit->append(tr("Trabajo cancelado"));
                    Evento = 0;
                    return;
                }
                item1=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                item1= ui->tableWidget->item(a,1);
                item2 = ui->tableWidget->item(a,9);
                Marca = item2->text();
                if (Marca == tr("Si"))
                {
                    Ruta = item1->text();
                    QString cmd = "id3v2 -d \"%1\"";
                    cmd=cmd.arg(Ruta);
                    QString cmd1 = "id3v2 -C \"%1\"";
                    cmd1=cmd1.arg(Ruta);
                    QString cmd2 = "chown %1:%1 \"%2\"";
                    cmd2 = cmd2.arg(user).arg(Ruta);
                    comandos<< cmd << cmd1 << cmd2;
                }
            }
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count();
            mib->Valor(valor,3);
            mib->iniciarProceso();
            Totalizar = comandos.count();
            ui->progressBar->setRange(0,Totalizar);
        }
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay registros cargados para poder importar."));
        m.exec();
        ui->progressBar->setRange(0,100);
        ui->progressBar->setValue(0);
        ui->progressBar->setFormat("%p%");
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_6->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_8->setEnabled(true);
        ui->pushButton_10->setEnabled(false);
        ui->progressBar->hide();
        return;
    }
}

void id3mp3::on_pushButton_21_clicked()
{
    int iFilas, a;
    QStringList comandos;
    QString Ruta, Titulo, Album, Artista, Comentarios, Anual, Track, Genero, Marca;
    iFilas=ui->tableWidget->rowCount();
    if (iFilas > 0)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("ADVERTENCIA IMPORTANTE")),
                    QString::fromUtf8(tr("<center><b>PRECAUCION</center><p>"
                               "Vas a cambiar masivamente las etiquetas id3v1 por lo que perderas los datos que tuvieras guardados.<p>"
                               "<B>NOTA: Procede con mucha precaucion o no aceptes la opcion si no "
                               "sabes lo que estas haciendo.</B><p>"
                               "&iquest;Importar etiquetas id3v2 a ide3v1?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            Totalizar = 0;
            TotalProceso = 0;
            ControlNum = 2;
            ui->progressBar->show();
            ui->progressBar->setFormat(tr("Importando id3v1 a id3v2... %p%"));
            ui->pushButton_6->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->pushButton_16->setEnabled(false);
            ui->pushButton_7->setEnabled(false);
            ui->pushButton_8->setEnabled(false);
            ui->pushButton_18->setEnabled(false);
            ui->pushButton_9->setEnabled(false);
            ui->groupBox_3->setEnabled(false);
            ui->groupBox_4->setEnabled(false);
            ui->groupBox_5->setEnabled(false);
            ui->groupBox_6->setEnabled(false);
            ui->checkBox_3->setEnabled(false);
            ui->checkBox_4->setEnabled(false);
            ui->checkBox_5->setEnabled(false);
            ui->checkBox_6->setEnabled(false);
            ui->checkBox_7->setEnabled(false);
            ui->checkBox_8->setEnabled(false);
            ui->pushButton_10->setEnabled(true);
            QTableWidgetItem *item1,*item2,*item3,*item4,*item5,*item6,*item7,*item8,*item9;
            for(a=0;a<iFilas;a++)
            {
                qApp->processEvents();
                if (Evento == 1)
                {
                    ui->progressBar->setRange(0,100);
                    ui->progressBar->setValue(0);
                    ui->progressBar->setFormat("%p%");
                    ui->pushButton_6->setEnabled(true);
                    ui->pushButton_15->setEnabled(true);
                    ui->pushButton_16->setEnabled(true);
                    ui->pushButton_7->setEnabled(true);
                    ui->pushButton_8->setEnabled(true);
                    ui->pushButton_18->setEnabled(true);
                    ui->pushButton_9->setEnabled(true);
                    ui->groupBox_3->setEnabled(true);
                    ui->groupBox_4->setEnabled(true);
                    ui->groupBox_5->setEnabled(true);
                    ui->checkBox_3->setEnabled(true);
                    ui->checkBox_4->setEnabled(true);
                    ui->checkBox_5->setEnabled(true);
                    ui->checkBox_6->setEnabled(true);
                    ui->checkBox_7->setEnabled(true);
                    ui->checkBox_8->setEnabled(true);
                    ui->pushButton_10->setEnabled(false);
                    ui->progressBar->hide();
                    ui->textEdit->append(tr("Trabajo cancelado"));
                    Evento = 0;
                    return;
                }
                item1=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                item3=new QTableWidgetItem;
                item4=new QTableWidgetItem;
                item5=new QTableWidgetItem;
                item6=new QTableWidgetItem;
                item7=new QTableWidgetItem;
                item8=new QTableWidgetItem;
                item9=new QTableWidgetItem;
                item1= ui->tableWidget->item(a,1);
                item9= ui->tableWidget->item(a,2);
                item2= ui->tableWidget->item(a,3);
                item3= ui->tableWidget->item(a,4);
                item4= ui->tableWidget->item(a,5);
                item5= ui->tableWidget->item(a,6);
                item6= ui->tableWidget->item(a,7);
                item7= ui->tableWidget->item(a,8);
                item8 = ui->tableWidget->item(a,9);
                Marca = item8->text();
                if (Marca == tr("Si"))
                {
                    Ruta = item1->text();
                    Titulo = item9->text();
                    Album = item2->text();
                    Artista = item3->text();
                    Comentarios = item4->text();
                    Anual = item5->text();
                    Track = item6->text();
                    Genero = item7->text();
                    QStringList Tracks;
                    Tracks = Track.split("/");
                    Track = Tracks.value(0);
                    QString cmd1 = "id3v2 --artist=\"%1\" --song=\"%2\" --album=\"%3\" --year=%4 --comment=\"%5\" --track=%6 --genre=%7 -1 \"%8\"";
                    cmd1=cmd1.arg(Artista).arg(Titulo).arg(Album).arg(Anual).arg(Comentarios).arg(Track).arg(Genero).arg(Ruta);
                    QString cmd2 = "chown %1:%1 \"%2\"";
                    cmd2 = cmd2.arg(user).arg(Ruta);
                    comandos<< cmd1 << cmd2;
                }
            }
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count();
            mib->Valor(valor,3);
            mib->iniciarProceso();
            Totalizar = comandos.count();
            ui->progressBar->setRange(0,Totalizar);
        }
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay registros cargados para poder importar."));
        m.exec();
        ui->progressBar->setRange(0,100);
        ui->progressBar->setValue(0);
        ui->progressBar->setFormat("%p%");
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_6->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_8->setEnabled(true);
        ui->pushButton_10->setEnabled(false);
        ui->progressBar->hide();
        return;
    }
}

void id3mp3::on_pushButton_23_clicked()
{
    ui->groupBox_8->setVisible(false);
    ui->pushButton_18->setVisible(true);
}

void id3mp3::on_pushButton_22_clicked()
{
    Totalizar = 0;
    TotalProceso = 0;
    ControlNum = 2;
    ui->progressBar->show();
    ui->progressBar->setFormat(tr("Eliminando todas las etiquetas... %p%"));
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_15->setEnabled(false);
    ui->pushButton_16->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_18->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->groupBox_3->setEnabled(false);
    ui->groupBox_4->setEnabled(false);
    ui->groupBox_5->setEnabled(false);
    ui->groupBox_6->setEnabled(false);
    ui->checkBox_3->setEnabled(false);
    ui->checkBox_4->setEnabled(false);
    ui->checkBox_5->setEnabled(false);
    ui->checkBox_6->setEnabled(false);
    ui->checkBox_7->setEnabled(false);
    ui->checkBox_8->setEnabled(false);
    ui->pushButton_10->setEnabled(true);
    int iFilas, a;
    QStringList comandos;
    iFilas=ui->tableWidget->rowCount();
    if (iFilas > 0)
    {
        QString Ruta, Marca;
        QTableWidgetItem *item, *item1;
        for(a=0;a<iFilas;a++)
        {
            qApp->processEvents();
            if (Evento == 1)
            {
                ui->progressBar->setRange(0,100);
                ui->progressBar->setValue(0);
                ui->progressBar->setFormat("%p%");
                ui->pushButton_6->setEnabled(true);
                ui->pushButton_15->setEnabled(true);
                ui->pushButton_16->setEnabled(true);
                ui->pushButton_7->setEnabled(true);
                ui->pushButton_8->setEnabled(true);
                ui->pushButton_18->setEnabled(true);
                ui->pushButton_9->setEnabled(true);
                ui->groupBox_3->setEnabled(true);
                ui->groupBox_4->setEnabled(true);
                ui->groupBox_5->setEnabled(true);
                ui->checkBox_3->setEnabled(true);
                ui->checkBox_4->setEnabled(true);
                ui->checkBox_5->setEnabled(true);
                ui->checkBox_6->setEnabled(true);
                ui->checkBox_7->setEnabled(true);
                ui->checkBox_8->setEnabled(true);
                ui->pushButton_10->setEnabled(false);
                ui->progressBar->hide();
                ui->textEdit->append(tr("Trabajo cancelado"));
                Evento = 0;
                return;
            }
            item=new QTableWidgetItem;
            item1=new QTableWidgetItem;
            item= ui->tableWidget->item(a,1);
            item1= ui->tableWidget->item(a,9);
            Marca = item1->text();
            if (Marca == tr("Si"))
            {
                Ruta = item->text();
                if (ui->radioButton_10->isChecked())
                {
                    QString cmd1 = "id3v2 --delete-v1 \"%1\"";
                    cmd1=cmd1.arg(Ruta);
                    QString cmd2 = "chown %1:%1 \"%2\"";
                    cmd2 = cmd2.arg(user).arg(Ruta);
                    comandos<< cmd1 << cmd2;
                }
                if (ui->radioButton_9->isChecked())
                {
                    QString cmd1 = "id3v2 --delete-v2 \"%1\"";
                    cmd1=cmd1.arg(Ruta);
                    QString cmd2 = "chown %1:%1 \"%2\"";
                    cmd2 = cmd2.arg(user).arg(Ruta);
                    comandos<< cmd1 << cmd2;
                }
                if (ui->radioButton_11->isChecked())
                {
                    QString cmd1 = "id3v2 --delete-all \"%1\"";
                    cmd1=cmd1.arg(Ruta);
                    QString cmd2 = "echo chown %1:%1 \"%2\"";
                    cmd2 = cmd2.arg(user).arg(Ruta);
                    comandos << cmd1 << cmd2;
                }
            }
        }
        mib = new DrakeProcesos1(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count();
        mib->Valor(valor,3);
        mib->iniciarProceso();
        Totalizar = comandos.count();
        ui->progressBar->setRange(0,Totalizar);
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay registros cargados para eliminar."));
        m.exec();
        ui->progressBar->setRange(0,100);
        ui->progressBar->setValue(0);
        ui->progressBar->setFormat("%p%");
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_16->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        ui->checkBox_5->setEnabled(true);
        ui->checkBox_6->setEnabled(true);
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_8->setEnabled(true);
        ui->pushButton_10->setEnabled(false);
        ui->progressBar->hide();
        Evento = 0;
        return;
    }
}

void id3mp3::on_pushButton_24_clicked()
{
    QString Raiz = getDisc("/");
    QStringList Value=Raiz.split(" ");
    double raiz = Value.value(Value.count()-3).toInt();
    int iFilas, a;
    double Origen, Destino;
    Origen = 0;
    iFilas=ui->tableWidget->rowCount();    
    if (iFilas > 0)
    {
        for(a=0;a<iFilas;a++)
        {
            QString Marca;
            QTableWidgetItem *item, *item1;
            item=new QTableWidgetItem;
            item1=new QTableWidgetItem;
            item= ui->tableWidget->item(a,9);
            item1= ui->tableWidget->item(a,10);
            Marca = item->text();
            if (Marca == tr("Si"))
            {
                Origen = Origen + item1->text().toInt();
            }
        }
raiz = 50;
        if (raiz*1024 <= Origen)
        {
            Destino = raiz;
            if (Destino*1024 <= Origen)
            {
                int respuesta1 = 0;
                respuesta1 = QMessageBox::question(this, QString::fromUtf8(tr("ADVERTENCIA")),
                            QString::fromUtf8(tr("<center><b>Sin espacio en unidad destino</center><p>"
                                       "No se puede volcar la informacion necesaria a la unidad por defecto "
                                       "por no haber espacio suficiente por lo que debes elegir otra unidad o no continuar.<p>"
                                       "Se precisa de ")+QString::number((Origen/1024)/1024,'f',2)+tr("Mb de espacio minimo para poder continuar.<p>"
                                       "&iquest;Elegir otra unidad?")), QMessageBox::Ok, QMessageBox::No);
                if (respuesta1 == QMessageBox::Ok)
                {
                    QString path=tr("/home/%1/Documentos/");
                    path=path.arg(user);
                    QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio a buscar?"),path,QFileDialog::ShowDirsOnly);
                    if (fileNameDirectori.isEmpty())
                    {
                        return;
                    }
                    OtroDirectorio = fileNameDirectori;
                    QString destino = getDisc(OtroDirectorio);
                    QStringList Valor = destino.split(" ");
                    Destino = Valor.value(Valor.count()-3).toInt();
                }
                else
                {
                    return;
                }
            }
        }
        int respuesta = 0;
        if (OtroDirectorio == "")
        {
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("ADVERTENCIA MUY IMPORTANTE")),
                        QString::fromUtf8(tr("<center><b>PRECAUCION</center><p>"
                                   "Cuando se carga una lista de reproduccion en un reproductor es muy posible que no lleven el orden "
                                   "que teniamos asignado en nuestras etiquetas o nuestro nombre de archivo.<p>"
                                   "Esto es debido a que muchos reproductores o radios de coche, realizan un rastreo del disco fisico para "
                                   "ir insertando cada uno de los ficheros seleccionados y segun en el orden que esten en el disco "
                                   "fisico (sectores) ira insertando y esto hace que nuestra lista no este ordenada.<p>"
                                   "El proceso que se va a realizar consta de 2 pasos:<p>"
                                   "1.- Se hara una copia de todos los datos de tu soporte PENDRIVE/SD.<p>"
                                   "2.- Se volcara la copia realizada anteriormente de nuevo al soporte PENDRIVE/SD.<p>"
                                   "Espacio libre en raiz: ")+QString::number(raiz/1024,'f',2)+tr("Mb.<p>"
                                   "Espacio necesario    : ")+QString::number((Origen/1024)/1024,'f',2)+tr("Mb.<p>"
                                   "<B>Procede con mucha precaucion o no aceptes la opcion si no sabes lo que estas haciendo.</B><p>"
                                   "&iquest;Reordenar listas de reproduccion?")), QMessageBox::Ok, QMessageBox::No);
        }
        else
        {
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("ADVERTENCIA MUY IMPORTANTE")),
                        QString::fromUtf8(tr("<center><b>PRECAUCION</center><p>"
                                   "Cuando se carga una lista de reproduccion en un reproductor es muy posible que no lleven el orden "
                                   "que teniamos asignado en nuestras etiquetas o nuestro nombre de archivo.<p>"
                                   "Esto es debido a que muchos reproductores o radios de coche, realizan un rastreo del disco fisico para "
                                   "ir insertando cada uno de los ficheros seleccionados y segun en el orden que esten en el disco "
                                   "fisico (sectores) ira insertando y esto hace que nuestra lista no este ordenada.<p>"
                                   "El proceso que se va a realizar consta de 2 pasos:<p>"
                                   "1.- Se hara una copia de todos los datos de tu soporte PENDRIVE/SD.<p>"
                                   "2.- Se volcara la copia realizada anteriormente de nuevo al soporte PENDRIVE/SD.<p>"
                                   "Espacio libre en destino: ")+QString::number(Destino/1024,'f',2)+tr("Mb.<p>"
                                   "Espacio necesario       : ")+QString::number((Origen/1024)/1024,'f',2)+tr("Mb.<p>"
                                   "<B>Procede con mucha precaucion o no aceptes la opcion si no sabes lo que estas haciendo.</B><p>"
                                   "&iquest;Reordenar listas de reproduccion?")), QMessageBox::Ok, QMessageBox::No);
        }
        if (respuesta == QMessageBox::Ok)
        {
            Ordenar = 1;
            this->Ordenando();
        }
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay registros cargados para poder reordenar."));
        m.exec();
        return;
    }
}

void id3mp3::Ordenando()
{
    int iFilas,a;
    iFilas=ui->tableWidget->rowCount();
    Totalizar = 0;
    TotalProceso = 0;
    ControlNum = 2;
    ui->progressBar->show();
    ui->progressBar->setFormat(tr("Reordenando posicion archivos de audio... %p%"));
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_15->setEnabled(false);
    ui->pushButton_16->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_18->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->groupBox_3->setEnabled(false);
    ui->groupBox_4->setEnabled(false);
    ui->groupBox_5->setEnabled(false);
    ui->groupBox_6->setEnabled(false);
    ui->checkBox_3->setEnabled(false);
    ui->checkBox_4->setEnabled(false);
    ui->checkBox_5->setEnabled(false);
    ui->checkBox_6->setEnabled(false);
    ui->checkBox_7->setEnabled(false);
    ui->checkBox_8->setEnabled(false);
    ui->pushButton_10->setEnabled(true);
    QStringList comandos;
    comandos.clear();
    QString Ruta, Marca, Origen;
    QTableWidgetItem *item, *item1, *origen;
    QString Explora;
    if (OtroDirectorio == "")
    {
        Explora = "find /usr/share/RecoverDrake/BACKUPRD -type d";
    }
    else
    {
        Explora = "find %1/BACKUPRD -type d";
        Explora = Explora.arg(OtroDirectorio);
    }
    drakeSistema drake;
    QString valor = drake.getStart(Explora);
    if (valor == "")
    {
        QString cm;
        if (OtroDirectorio == "")
        {
            cm = "mkdir /usr/share/RecoverDrake/BACKUPRD/";
        }
        else
        {
            cm = "mkdir %1/BACKUPRD/";
            cm = cm.arg(OtroDirectorio);
        }
        comandos << cm;
    }
    if (Ordenar == 3)
    {
        QString cmd1;
        if (OtroDirectorio == "")
        {
            cmd1 = "rm -vf -r /usr/share/RecoverDrake/BACKUPRD/";
        }
        else
        {
            cmd1 = "rm -vf -r %1/BACKUPRD/";
            cmd1 = cmd1.arg(OtroDirectorio);
        }
        comandos << cmd1;
        Ordenar = 0;
        OtroDirectorio = "";
        mib = new DrakeProcesos1(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count();
        mib->Valor(valor,3);
        mib->iniciarProceso();
        Totalizar = comandos.count();
        ui->progressBar->setRange(0,Totalizar);
    }
    else
    {
        for(a=0;a<iFilas;a++)
        {
            qApp->processEvents();
            if (Evento == 1)
            {
                ui->progressBar->setRange(0,100);
                ui->progressBar->setValue(0);
                ui->progressBar->setFormat("%p%");
                ui->pushButton_6->setEnabled(true);
                ui->pushButton_15->setEnabled(true);
                ui->pushButton_16->setEnabled(true);
                ui->pushButton_7->setEnabled(true);
                ui->pushButton_8->setEnabled(true);
                ui->pushButton_18->setEnabled(true);
                ui->pushButton_9->setEnabled(true);
                ui->groupBox_3->setEnabled(true);
                ui->groupBox_4->setEnabled(true);
                ui->groupBox_5->setEnabled(true);
                ui->checkBox_3->setEnabled(true);
                ui->checkBox_4->setEnabled(true);
                ui->checkBox_5->setEnabled(true);
                ui->checkBox_6->setEnabled(true);
                ui->checkBox_7->setEnabled(true);
                ui->checkBox_8->setEnabled(true);
                ui->pushButton_10->setEnabled(false);
                ui->progressBar->hide();
                ui->textEdit->append(tr("Trabajo cancelado"));
                Evento = 0;
                return;
            }
            item=new QTableWidgetItem;
            item1=new QTableWidgetItem;
            origen=new QTableWidgetItem;
            item= ui->tableWidget->item(a,1);
            item1= ui->tableWidget->item(a,9);
            origen= ui->tableWidget->item(a,0);
            Marca = item1->text();
            if (Marca == tr("Si"))
            {
                Ruta = item->text();
                Origen = origen->text();
                if (Ordenar == 1)
                {
                    QString cmd1;
                    if (OtroDirectorio == "")
                    {
                        cmd1 = "mv -vf \"%1\" \"/usr/share/RecoverDrake/BACKUPRD/%2\"";
                        cmd1=cmd1.arg(Ruta).arg(Origen);
                    }
                    else
                    {
                        cmd1 = "mv -vf \"%1\" \"%2/BACKUPRD/%3\"";
                        cmd1=cmd1.arg(Ruta).arg(OtroDirectorio).arg(Origen);
                    }
                    comandos<< cmd1;
                }
                else if (Ordenar == 2)
                {
                    QString cmd1;
                    if (OtroDirectorio == "")
                    {
                        cmd1 = "mv -vf \"/usr/share/RecoverDrake/BACKUPRD/%1\" \"%2\"";
                        cmd1=cmd1.arg(Origen).arg(Ruta);
                    }
                    else
                    {
                        cmd1 = "mv -vf \"%1/BACKUPRD/%2\" \"%3\"";
                        cmd1=cmd1.arg(OtroDirectorio).arg(Origen).arg(Ruta);
                    }
                    QString cmd2 = "chown %1:%1 \"%2\"";
                    cmd2 = cmd2.arg(user).arg(Ruta);
                    comandos << cmd1 << cmd2;
                }
            }
        }
        if (Ordenar == 1)
        {
            Ordenar = 2;
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            connect(mib, SIGNAL(finProceso()), this, SLOT(Ordenando()));
            int valor= comandos.count();
            mib->Valor(valor,3);
            mib->iniciarProceso();
            Totalizar = comandos.count();
            ui->progressBar->setRange(0,Totalizar);
        }
        else if (Ordenar == 2)
        {
            Ordenar = 3;
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            connect(mib, SIGNAL(finProceso()), this, SLOT(Ordenando()));
            int valor= comandos.count();
            mib->Valor(valor,3);
            mib->iniciarProceso();
            Totalizar = comandos.count();
            ui->progressBar->setRange(0,Totalizar);
        }
    }
}

QString id3mp3::getDisc(QString Valor)
{
    QProcess *procesoFree, *procesoGrep;
    QStringList argumentosFree;
    QStringList argumentosGrep;
    QByteArray Raiz;
    procesoFree=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosFree << "--total" << ""+Valor+"";
    argumentosGrep << "total";
    procesoFree->setStandardOutputProcess(procesoGrep);
    procesoFree->start("df", argumentosFree);
    procesoGrep->start("grep",argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoFree->waitForFinished();
    procesoGrep->waitForFinished();
    Raiz = procesoGrep->readAllStandardOutput();
    delete procesoFree;
    delete procesoGrep;
    QString res = QString(Raiz);
    res.chop(0);
    return res;
}
