#include "convaudio.h"
#include "ui_convaudio.h"
#include <QKeyEvent>
#include "drakesistema.h"
#include "drakeprocesos.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <phonon/mediaobject.h>
#include <phonon/audiooutput.h>
#include <QtMultimedia>
#include <QTimer>
#include <QTime>
#include <QTest>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <phonon/BackendCapabilities>
#include <phonon/EffectDescription>
#include <phonon/EffectWidget>
#include <phonon/EffectParameter>

ConvAudio::ConvAudio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConvAudio)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    ui->progressBar_2->hide();
    drakeSistema drake;
    user = drake.getUser();
    connect(ui->tableWidget_2, SIGNAL(cellPressed(int,int)), this, SLOT(tableClicked(int,int)));
    mib=0;
    ui->lcdNumber_2->display("00:00:00");
    ui->pushButton_12->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
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

ConvAudio::~ConvAudio()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void ConvAudio::on_pushButton_9_clicked()
{
    bool wasPlaying = MediaObject->state() == Phonon::PlayingState;
    if (wasPlaying)
    {
        MediaObject->stop();
    }
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void ConvAudio::closeEvent ( QCloseEvent * event )
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

void ConvAudio::Valor(QString valor, Phonon::MediaObject *mediaObject, Phonon::AudioOutput *audioOutput, Phonon::Path path, Phonon::Effect *effect)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
    MediaObject = mediaObject;
    AudioOutput = audioOutput;
    Path = path;
    Effect = effect;
    connect(MediaObject, SIGNAL(finished()), this, SLOT(final()));
}

bool ConvAudio::eventFilter(QObject *obj, QEvent *event)
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

void ConvAudio::on_pushButton_27_clicked()
{
    mib->killProceso();
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    ui->progressBar_2->setValue(0);
    ui->progressBar_2->hide();
}

void ConvAudio::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit_2->append(valor);
}

void ConvAudio::ProcesarValor(QString ValorComand)
{
    int iFilas, a;
    QString valor;
    int valor1;
    iFilas=ui->tableWidget_2->rowCount();
    QTableWidgetItem *item;
    for(a=0;a<iFilas;a++)
    {
        item=ui->tableWidget_2->item(a,0);
        valor=item->text();
        valor1=item->row();
        if(valor== "Ok")
        {
            if ( valor1 == ValorComand.toInt() )
            {
                item->setText(tr("Hecho"));
                ui->tableWidget_2->setItem(iFilas,0,item);
            }
        }
    }
}

void ConvAudio::mibprogreso(QString Dat)
{
    ui->progressBar_2->setValue(Dat.toInt());
}

void ConvAudio::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    ui->progressBar_2->setValue(0);
    ui->progressBar_2->hide();
}

void ConvAudio::on_pushButton_12_clicked()
{
    int iFilas;
    QString valor, valor1;
    iFilas=ui->tableWidget_2->currentRow();
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
        item=ui->tableWidget_2->item(iFilas,0);
        valor=item->text();
        item1=ui->tableWidget_2->item(iFilas,2);
        valor1=item1->text();
        if(valor == "Ok")
        {
            Phonon::MediaSource source(valor1);
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
}

void ConvAudio::update()
{
    quint64 time = MediaObject->currentTime();
    QTime displayTime((time / 3600000) % 60, (time / 60000) % 60, (time / 1000) % 60);
    ui->lcdNumber_2->display(displayTime.toString("hh:mm:ss"));
}

void ConvAudio::on_pushButton_14_clicked()
{
    MediaObject->stop();
    MediaObject->pause();
    ui->pushButton_12->setEnabled(true);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
    timer->stop();
    ui->lcdNumber_2->display("00:00:00");
}

void ConvAudio::on_pushButton_13_clicked()
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

void ConvAudio::on_pushButton_24_clicked()
{
    QStringList listaArchivos;
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
        iFilas=ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(iFilas);
        ui->tableWidget_2->setItem(iFilas,0,item3);
        ui->tableWidget_2->setItem(iFilas,1,item1);
        ui->tableWidget_2->setItem(iFilas,2,item2);
        ui->tableWidget_2->item(iFilas,0)->setIcon(QIcon(":/Imagenes/good.png"));
        int Contador = ui->tableWidget_2->rowCount();
        ui->lineEdit_3->setText(QString::number(Contador));
    }
    ui->tableWidget_2->resizeColumnsToContents();
    ui->tableWidget_2->resizeRowsToContents();
}

void ConvAudio::tableClicked(int row, int /*column*/)
{
    QString valor, valor1;
    row=ui->tableWidget_2->currentRow();
    QTableWidgetItem *item, *item1;
    item=new QTableWidgetItem;
    item1=new QTableWidgetItem;
    item=ui->tableWidget_2->item(row,0);
    valor=item->text();
    item1=ui->tableWidget_2->item(row,2);
    valor1=item1->text();
    if(valor == "Ok")
    {
       MediaObject->stop();
       QTest::qWait(500);
       Phonon::MediaSource source(valor1);
       MediaObject->setCurrentSource(source);
       MediaObject->pause();
       ui->pushButton_12->setEnabled(true);
       ui->pushButton_13->setEnabled(false);
       ui->pushButton_14->setEnabled(false);
    }
}

void ConvAudio::on_pushButton_10_clicked()
{
    int iFilas;
    iFilas=ui->tableWidget_2->currentRow();
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
        Audio = ui->comboBox_6->currentText();
        Calidad = ui->comboBox_7->currentText();
        QString Ruta = ui->lineEdit->text();
        if (Ruta == "")
            item->setText(""+Audio+"*"+Calidad+"");
        else
            item->setText(""+Audio+"*"+Calidad+"*"+Ruta+"");
        ui->tableWidget_2->setItem(iFilas,3,item);
        ui->tableWidget_2->resizeRowsToContents();
        ui->tableWidget_2->resizeColumnsToContents();
    }
}

void ConvAudio::on_pushButton_8_clicked()
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

void ConvAudio::on_pushButton_22_clicked()
{
    int iFilas, a;
    QString valor;
    iFilas=ui->tableWidget_2->rowCount();
    QTableWidgetItem *item;
    for(a=0;a<iFilas;a++)
    {
        item=ui->tableWidget_2->item(a,0);
        valor=item->text();
        if(valor != "Ok")
        {
            ui->tableWidget_2->item(a,0)->setIcon(QIcon(":/Imagenes/good.png"));
            item->setText("Ok");
            ui->tableWidget_2->setItem(iFilas,0,item);
        }
     }
}

void ConvAudio::on_pushButton_23_clicked()
{
    int iFilas, a;
    QString valor;
    iFilas=ui->tableWidget_2->rowCount();
    QTableWidgetItem *item;
    for(a=0;a<iFilas;a++)
    {
        item=ui->tableWidget_2->item(a,0);
        valor=item->text();
        if(valor == "Ok")
        {
            ui->tableWidget_2->item(a,0)->setIcon(QIcon(":/Imagenes/bad.png"));
            item->setText("");
            ui->tableWidget_2->setItem(iFilas,0,item);
        }
     }
}

void ConvAudio::on_pushButton_18_clicked()
{
    int iFilas;
    QString valor;
    iFilas=ui->tableWidget_2->currentRow();
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
        item=ui->tableWidget_2->item(iFilas,0);
        valor=item->text();
        if(valor != "Ok")
        {
            ui->tableWidget_2->item(iFilas,0)->setIcon(QIcon(":/Imagenes/good.png"));
            item->setText("Ok");
            ui->tableWidget_2->setItem(iFilas,0,item);
        }
    }
}

void ConvAudio::on_pushButton_25_clicked()
{
    int iFilas;
    QString valor;
    iFilas=ui->tableWidget_2->currentRow();
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
        item=ui->tableWidget_2->item(iFilas,0);
        valor=item->text();
        if(valor == "Ok")
        {
            ui->tableWidget_2->item(iFilas,0)->setIcon(QIcon(":/Imagenes/bad.png"));
            item->setText("");
            ui->tableWidget_2->setItem(iFilas,0,item);
        }
    }
}

void ConvAudio::on_pushButton_26_clicked()
{
    int j;
    j=ui->tableWidget_2->currentRow();
    if (j == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes realizar lo que has solicitado."));
        m.exec();
        return;
    }
    else
    {
        ui->tableWidget_2->removeRow(j);
        int Contador = ui->tableWidget_2->rowCount();
        ui->lineEdit_3->setText(QString::number(Contador));
    }
}

void ConvAudio::on_pushButton_11_clicked()
{
    ui->progressBar_2->show();
    QTableWidgetItem *item, *item1, *item2, *item3;
    QString activo, activo1, activo2, activo3, Enrrutar, RutaAbs, Desecho, Ruta, TipAudio, Value, Calidad;
    QStringList comandos;
    int itemCount = ui->tableWidget_2->rowCount();
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
        item = ui->tableWidget_2->item(i,0);
        item1 = ui->tableWidget_2->item(i,1);
        item2 = ui->tableWidget_2->item(i,2);
        item3 = ui->tableWidget_2->item(i,3);
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
        if (Desecho.contains("mp3") || Desecho.contains("mp2") || Desecho.contains("wma") || Desecho.contains("wav") || Desecho.contains("aac") || Desecho.contains("pcm") || Desecho.contains("ac3"))
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
                           TipAudio = "backup."+Value+"";
                        }
                        else
                        {
                           TipAudio = Value;
                        }
                    }
                    else if (a == 1)
                    {
                        Calidad = Value.remove("kbs");
                    }
                }
                RutaAbs = RutaAbs.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
                Ruta = Ruta.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
                QString cmd0 = "echo convirtiendo "+activo1+"...";
                comandos << cmd0;
                QString cmd1;
                cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab %3 -y %4.%5\"";
                cmd1=cmd1.arg(user).arg(RutaAbs).arg(Calidad).arg(Ruta).arg(TipAudio);
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

void ConvAudio::on_pushButton_clicked()
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

void ConvAudio::Ecualizar(QString Valor, int band1, int band2, int band3, int band4, int band5, int band6, int band7, int band8, int band9, int band10)
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

void ConvAudio::final()
{
    MediaObject->stop();
    ui->pushButton_12->setEnabled(true);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
}
