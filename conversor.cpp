#include "conversor.h"
#include "ui_conversor.h"
#include "drakesistema.h"
#include "drakeprocesos.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <phonon/videoplayer.h>
#include <phonon/mediaobject.h>
#include <phonon/videowidget.h>
#include <phonon/audiooutput.h>
#include <QtMultimedia>
#include <QTimer>
#include <QTime>
#include <QTest>
#include <QSqlQuery>
#include <QKeyEvent>
#include <phonon/BackendCapabilities>
#include <phonon/EffectDescription>
#include <phonon/EffectWidget>
#include <phonon/EffectParameter>

Conversor::Conversor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Conversor)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    ui->progressBar->hide();
    drakeSistema drake;
    user = drake.getUser();
    connect(ui->tableWidget, SIGNAL(cellPressed(int,int)), this, SLOT(tableClicked(int,int)));
    mib=0;
    ui->lcdNumber->display("00:00:00");
    ui->pushButton->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
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
    this->installEventFilter(this);
    CierreTotal = 0;
}

Conversor::~Conversor()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void Conversor::changeEvent(QEvent *e)
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

void Conversor::on_pushButton_2_clicked()
{
    if (ui->videoPlayer->isPlaying())
        ui->videoPlayer->stop();
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void Conversor::closeEvent ( QCloseEvent * event )
{
    if (CierreTotal == 1)
    {
        emit Cerrar();
        event->accept();
    }
    else
    {
        close();
        event->accept();
    }
}

void Conversor::Valor(QString valor, Phonon::MediaObject *mediaObject, Phonon::AudioOutput *audioOutput, Phonon::Path path, Phonon::Effect *effect)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
    MediaObject = mediaObject;
    AudioOutput = audioOutput;
    Path = path;
    Effect = effect;
}

void Conversor::on_pushButton_19_clicked()
{
    int i;
    int iFilas;
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    listaArchivos=QFileDialog::getOpenFileNames
     (this,tr("Abrir Archivo"),path,
        "Todos los archivos (*.*)");
    if(listaArchivos.isEmpty() )
    {
        return;
    }
    for(i=0;i<listaArchivos.count();i++ )
    {
        QString rutaAbs;
        QTableWidgetItem *item1, *item2, *item3;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        rutaAbs=listaArchivos.value(i);
        QFile file(rutaAbs);
        item1->setText(tr(QFileInfo(file).fileName()));
        item2->setText(tr(rutaAbs));
        item3->setText("Ok");
        iFilas=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(iFilas);
        ui->tableWidget->setItem(iFilas,0,item3);
        ui->tableWidget->setItem(iFilas,1,item1);
        ui->tableWidget->setItem(iFilas,2,item2);
        ui->tableWidget->item(iFilas,0)->setIcon(QIcon(":/Imagenes/good.png"));
        int Contador = ui->tableWidget->rowCount();
        ui->lineEdit_2->setText(QString::number(Contador+1));
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

void Conversor::on_pushButton_20_clicked()
{
    int iFilas, a;
    QString valor;
    iFilas=ui->tableWidget->rowCount();
    QTableWidgetItem *item;
    for(a=0;a<iFilas;a++)
    {
        item=ui->tableWidget->item(a,0);
        valor=item->text();
        if(valor != "Ok")
        {
            ui->tableWidget->item(a,0)->setIcon(QIcon(":/Imagenes/good.png"));
            item->setText("Ok");
            ui->tableWidget->setItem(iFilas,0,item);
        }
     }
}

void Conversor::on_pushButton_21_clicked()
{
    int iFilas, a;
    QString valor;
    iFilas=ui->tableWidget->rowCount();
    QTableWidgetItem *item;
    for(a=0;a<iFilas;a++)
    {
        item=ui->tableWidget->item(a,0);
        valor=item->text();
        if(valor == "Ok")
        {
            ui->tableWidget->item(a,0)->setIcon(QIcon(":/Imagenes/bad.png"));
            item->setText("");
            ui->tableWidget->setItem(iFilas,0,item);
        }
     }
}

void Conversor::on_pushButton_15_clicked()
{
    int iFilas;
    QString valor;
    iFilas=ui->tableWidget->currentRow();
    if (iFilas == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QTableWidgetItem *item;
        item=new QTableWidgetItem;
        item=ui->tableWidget->item(iFilas,0);
        valor=item->text();
        if(valor != "Ok")
        {
            ui->tableWidget->item(iFilas,0)->setIcon(QIcon(":/Imagenes/good.png"));
            item->setText("Ok");
            ui->tableWidget->setItem(iFilas,0,item);
        }
    }
}

void Conversor::on_pushButton_16_clicked()
{
    int iFilas;
    QString valor;
    iFilas=ui->tableWidget->currentRow();
    if (iFilas == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QTableWidgetItem *item;
        item=new QTableWidgetItem;
        item=ui->tableWidget->item(iFilas,0);
        valor=item->text();
        if(valor == "Ok")
        {
            ui->tableWidget->item(iFilas,0)->setIcon(QIcon(":/Imagenes/bad.png"));
            item->setText("");
            ui->tableWidget->setItem(iFilas,0,item);
        }
    }
}

void Conversor::on_pushButton_17_clicked()
{
    int j;
    j=ui->tableWidget->currentRow();
    if (j == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes realizar lo que has solicitado."));
        m.exec();
        return;
    }
    else
    {
        ui->tableWidget->removeRow(j);
        int Contador = ui->tableWidget->rowCount();
        ui->lineEdit_2->setText(QString::number(Contador));
    }
}

void Conversor::on_pushButton_5_clicked()
{
    int iFilas;
    iFilas=ui->tableWidget->currentRow();
    if (iFilas == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QTableWidgetItem *item;
        item=new QTableWidgetItem;
        Video = ui->comboBox->currentText();
        Audio = ui->comboBox_2->currentText();
        Formato = ui->comboBox_3->currentText();
        Resolucion = ui->comboBox_4->currentText();
        Peso = ui->comboBox_5->currentText();
        QString Ruta = ui->lineEdit->text();
        if (Ruta == "")
            item->setText(""+Video+"*"+Audio+"*"+Formato+"*"+Resolucion+"*"+Peso+"");
        else
            item->setText(""+Video+"*"+Audio+"*"+Formato+"*"+Resolucion+"*"+Peso+"*"+Ruta+"");
        ui->tableWidget->setItem(iFilas,3,item);
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
    }
}

void Conversor::on_pushButton_4_clicked()
{
    ui->progressBar->show();
    QTableWidgetItem *item, *item1, *item2, *item3;
    QString activo, activo1, activo2, activo3, Enrrutar, RutaAbs, Desecho, Ruta;
    QStringList comandos;
    int itemCount = ui->tableWidget->rowCount();
    if (itemCount == 0)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay nada para procesar."));
        m.exec();
        return;
    }
    QString cmd = QString::fromUtf8("echo Realizando procesos de conversion...");
    comandos<< cmd;
    for(int i=0;i<itemCount;i++)
    {
        item = ui->tableWidget->item(i,0);
        item1 = ui->tableWidget->item(i,1);
        item2 = ui->tableWidget->item(i,2);
        item3 = ui->tableWidget->item(i,3);
        activo = item->text();
        activo1 = item1->text();
        if (ui->lineEdit->text() == "")
        {
            activo2 = item2->text();
            RutaAbs = activo2;
            Desecho = activo2.right(4);
            Ruta = activo2.remove(Desecho);
        }
        else
        {
            activo2 = item2->text();
            RutaAbs = activo2;
            Enrrutar = ui->lineEdit->text();
            Desecho = activo2.right(4);
            if (Desecho.contains("."))
                Ruta = Enrrutar.remove(Desecho);
            else
                Ruta = Enrrutar;
        }
        if (Desecho.contains("avi") || Desecho.contains("mpg") || Desecho.contains("wmv") || Desecho.contains("avi") || Desecho.contains("mpeg") || Desecho.contains("flv") || Desecho.contains("mp4") || Desecho.contains("avi"))
        {
            activo3 = item3->text();
            if (activo == "Ok")
            {
                QStringList parts = activo3.split("*");
                for(int a=0;a<parts.count();a++)
                {
                    Value = parts.value(a);
                    if (a == 0)
                    {
                        Desecho = Desecho.right(3);
                        if (Desecho == Value)
                        {
                           Video = "backup."+Value+"";
                           DatoVideo = Value;
                        }
                        else
                        {
                           Video = Value;
                           DatoVideo = Value;
                        }
                    }
                    else if (a == 1)
                    {
                        if (Value == "mp3")
                        {
                            Value = "libmp3lame";
                        }
                        if (Value == "pcm")
                        {
                            Value = "pcm_alaw";
                        }
                        if (Value == "Copiar" || Value == "Copy")
                        {
                            Value = "copy";
                        }
                        Audio = "-acodec "+Value+"";
                    }
                    else if (a == 2)
                    {
                        if (Value == "Copiar" || Value == "Copy")
                        {
                            Formato = "";
                        }
                        else
                        {
                            Formato = "-aspect "+Value+"";
                        }
                    }
                    else if (a == 3)
                    {
                        if (Value == "Copiar" || Value == "Copy")
                        {
                            Resolucion = "";
                        }
                        else
                        {
                            Resolucion = "-s "+Value+"";
                        }
                    }
                    else if (a == 4)
                    {
                        if (Value == "Sin especificar" || Value == "Unspecified")
                        {
                            Peso = "";
                        }
                        if (Value == "700 Mg")
                        {
                            Value = "700000000";
                            Peso = "-ps "+Value+" -b 700k";
                        }
                        else if (Value == "900 Mg")
                        {
                            Value = "900000000";
                            Peso = "-ps "+Value+" -b 900k";
                        }
                        else if (Value == "1400 Mg")
                        {
                            Value = "1400000000";
                            Peso = "-ps "+Value+" -b 1400k";
                        }
                    }
                }
                RutaAbs = RutaAbs.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
                Ruta = Ruta.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
                QString cmd0 = "echo convirtiendo "+activo1+"...";
                comandos << cmd0;
                Calidad = "-qscale 0";
                if (Peso != "")
                {
                    Calidad = "";
                }
                QString cmd1;
                if (DatoVideo == "avi" || DatoVideo == "mpg")
                {
                    cmd1 = "su - %1 -c \"ffmpeg -i %2 %9 %3 %4 %5 %8 -y %6.%7\"";
                    cmd1=cmd1.arg(user).arg(RutaAbs).arg(Audio).arg(Formato).arg(Resolucion).arg(Ruta).arg(Video).arg(Peso).arg(Calidad);
                }
                if (DatoVideo == "DVD")
                {
                    Video = "mpeg";
                    cmd1 = "su - %1 -c \"ffmpeg -i %2 %9 -target pal-dvd %3 %4 %5 %8 -y %6.%7\"";
                    cmd1=cmd1.arg(user).arg(RutaAbs).arg(Audio).arg(Formato).arg(Resolucion).arg(Ruta).arg(Video).arg(Peso).arg(Calidad);
                }
                if (DatoVideo == "wmv")
                {
                    cmd1 = "su - %1 -c \"ffmpeg -i %2 -b 1000k -vcodec wmv2 -ar 44100 -ab 56000 -ac 2 -y %3.%4\"";
                    cmd1=cmd1.arg(user).arg(RutaAbs).arg(Ruta).arg(Video);
                }
                if (DatoVideo == "flv")
                {
                    cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 56 -ar 44100 -b 200 -r 15 -s 320×240 -f flv %3.%4\"";
                    cmd1=cmd1.arg(user).arg(RutaAbs).arg(Ruta).arg(Video);
                }
                if (DatoVideo == "3gp")
                {
                    cmd1 = "su - %1 -c \"ffmpeg -i %2 -s qcif -r 15 -ac 1 -ar 8000 -b 256000 -ab 15 %3.%4\"";
                    cmd1=cmd1.arg(user).arg(RutaAbs).arg(Ruta).arg(Video);
                }
                if (DatoVideo == "mp4")
                {
                    cmd1 = "su - %1 -c \"ffmpeg -i %2 -b 300 -s 320×240 -vcodec xvid -ab 32 -ar 24000 -acodec aac %3.%4\"";
                    cmd1=cmd1.arg(user).arg(RutaAbs).arg(Ruta).arg(Video);
                }
                if (DatoVideo == "DV")
                {
                    Video = "dv";
                    cmd1 = "su - %1 -c \"ffmpeg -i %2 %9 %3 %4 %5 %8 -target pal-dv %6.%7\"";
                    cmd1=cmd1.arg(user).arg(RutaAbs).arg(Audio).arg(Formato).arg(Resolucion).arg(Ruta).arg(Video).arg(Peso).arg(Calidad);
                }
                if (DatoVideo == "H.264")
                {
                    Video = "mp4";
                    cmd1 = "su - %1 -c \"ffmpeg -y -i %2 -acodec aac -ab 72k -s 320×176 -aspect 16:9 -vcodec h264 -b 300k -qcomp 0.6 -qmin 16 -qmax 51 -qdiff 4 -flags +loop -cmp +chroma -subq 7 -refs 6 -g 250 -keyint_min 25 -rc_eq ‘blurCplx^(1-qComp)’ -sc_threshold 40 -me_range 12 -i_qfactor 0.71 -directpred 3 %3.%4\"";
                    cmd1=cmd1.arg(user).arg(RutaAbs).arg(Ruta).arg(Video);
                }
                comandos<< cmd1;
            }
        }
        else
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No hay nada para procesar o el archivo de origen no es un archivo valido de video de los formatos compatibles."));
            m.exec();
            return;
        }
        if (mib != 0)
            delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count(); mib->Valor(valor,2); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
    }
}

void Conversor::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
}

void Conversor::ProcesarValor(QString ValorComand)
{
    int iFilas, a;
    QString valor;
    int valor1;
    iFilas=ui->tableWidget->rowCount();
    QTableWidgetItem *item;
    for(a=0;a<iFilas;a++)
    {
        item=ui->tableWidget->item(a,0);
        valor=item->text();
        valor1=item->row();
        if(valor== "Ok")
        {
            if ( valor1 == ValorComand.toInt() )
            {
                item->setText(tr("Hecho"));
                ui->tableWidget->setItem(iFilas,0,item);
            }
        }
    }
}

void Conversor::mibprogreso(QString Dat)
{
    ui->progressBar->setValue(Dat.toInt());
}

void Conversor::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    ui->progressBar->setValue(0);
    ui->progressBar->hide();
}

void Conversor::on_pushButton_clicked()
{
    int iFilas;
    QString valor, valor1;
    iFilas=ui->tableWidget->currentRow();
    if (iFilas == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QTableWidgetItem *item, *item1;
        item=new QTableWidgetItem;
        item1=new QTableWidgetItem;
        item=ui->tableWidget->item(iFilas,0);
        valor=item->text();
        item1=ui->tableWidget->item(iFilas,2);
        valor1=item1->text();
        if(valor == "Ok")
        {
            ui->videoPlayer->load(Phonon::MediaSource(valor1));
            ui->videoPlayer->play();
            ui->pushButton->setEnabled(false);
            ui->pushButton_6->setEnabled(true);
            ui->pushButton_3->setEnabled(true);            
            ui->seekSlider->setMediaObject(ui->videoPlayer->mediaObject());
            //ui->seekSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
            ui->volumeSlider_2->setAudioOutput(AudioOutput);
            //ui->volumeSlider_2->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
            timer->start(1000);
        }
    }
}

void Conversor::on_pushButton_3_clicked()
{
    ui->videoPlayer->stop();
    ui->videoPlayer->pause();
    ui->pushButton->setEnabled(true);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    timer->stop();
    ui->lcdNumber->display("00:00:00");
}

void Conversor::on_pushButton_6_clicked()
{
    if (ui->videoPlayer->isPaused())
    {
        ui->videoPlayer->play();
        ui->pushButton_6->setText(tr("Pausa"));
        ui->pushButton->setEnabled(false);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
    }
    else
    {
        ui->videoPlayer->pause();
        ui->pushButton_6->setText(tr("Continuar"));
        ui->pushButton->setEnabled(false);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_3->setEnabled(false);
    }
}

void Conversor::tableClicked(int row, int /*column*/)
{
    QString valor, valor1;
    row=ui->tableWidget->currentRow();
    QTableWidgetItem *item, *item1;
    item=new QTableWidgetItem;
    item1=new QTableWidgetItem;
    item=ui->tableWidget->item(row,0);
    valor=item->text();
    item1=ui->tableWidget->item(row,2);
    valor1=item1->text();
    if(valor == "Ok")
    {
       ui->videoPlayer->stop();
       QTest::qWait(500);
       ui->videoPlayer->load(Phonon::MediaSource(valor1));
       ui->videoPlayer->pause();
       ui->pushButton->setEnabled(true);
       ui->pushButton_6->setEnabled(false);
       ui->pushButton_3->setEnabled(false);
    }
}

void Conversor::update()
{
    quint64 time = ui->videoPlayer->currentTime();
    QTime displayTime((time / 3600000) % 60, (time / 60000) % 60, (time / 1000) % 60);
    ui->lcdNumber->display(displayTime.toString("hh:mm:ss"));
}

void Conversor::on_comboBox_currentIndexChanged(QString seleccion)
{
    if ( seleccion == "avi" )
    {
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        ui->comboBox_4->setEnabled(true);
        ui->comboBox_5->setEnabled(true);
    }
    else if (seleccion == "mpg")
    {
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        ui->comboBox_4->setEnabled(true);
        ui->comboBox_5->setEnabled(true);
    }
    else if (seleccion == "DVD")
    {
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        ui->comboBox_4->setEnabled(true);
        ui->comboBox_5->setEnabled(true);
    }
    else if (seleccion == "DV")
    {
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        ui->comboBox_4->setEnabled(true);
        ui->comboBox_5->setEnabled(true);
    }
    else
    {
        ui->comboBox_2->setEnabled(false);
        ui->comboBox_3->setEnabled(false);
        ui->comboBox_4->setEnabled(false);
        ui->comboBox_5->setEnabled(false);
    }
}

bool Conversor::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
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

void Conversor::on_pushButton_7_clicked()
{
    if (mib != 0)
    {
        mib->killProceso();
        disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
        disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        ui->progressBar->setValue(0);
        ui->progressBar->hide();
    }
}

void Conversor::on_pushButton_8_clicked()
{
    QString path;
    path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Salvar archivo de video")),
                            path,trUtf8(tr("Todos los archivos (*)")));
    if (fileNameOrigen.isEmpty())
    {
       return;
    }
    QString fileName = fileNameOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    ui->lineEdit->setText(fileName);
}
