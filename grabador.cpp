#include "grabador.h"
#include "ui_grabador.h"
#include "drakesistema.h"
#include "QSqlQuery"
#include <phonon/BackendCapabilities>
#include <phonon/EffectDescription>
#include <phonon/EffectWidget>
#include <phonon/EffectParameter>
#include <QFileDialog>
#include <QMessageBox>
#include <QTime>
#include <QFile>

Grabador::Grabador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grabador)
{
    ui->setupUi(this);
    drakeSistema drake;
    user = drake.getUser();
    db=QSqlDatabase::database("PRINCIPAL");
    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(hora()));
    timer1->start(1000);
    mib = 0;
    Stilo = "B";
    iTcrs = 1;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
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
    QSqlQuery Variable(db);
    Variable.exec("SELECT Genero FROM id3Genre");
    while(Variable.next())
        ui->comboBox_2->addItem(Variable.value(0).toString());
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText("254 None"));
    CierreTotal = 0;
    ui->pushButton_12->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->groupBox_26->setEnabled(false);
    QString SinkM = LocSinkM();
    QString SinkD = LocSinkD();
    QStringList SinkMonitor = SinkM.split("\n");
    QStringList SinkDescrip = SinkD.split("\n");
    for(int a=0;a<SinkMonitor.count();a++)
    {
        QString Valor1 = SinkMonitor.value(a);
        QString Valor2 = SinkDescrip.value(a);
        Valor1 = Valor1.simplified();
        Valor2 = Valor2.simplified();
        Valor1 = Valor1.remove("Monitor Source:");
        Valor2 = Valor2.remove("Description:");
        Valor1 = Valor1.simplified();
        Valor2 = Valor2.simplified();
        QString Valor = ""+tr("Audio interno: ")+Valor1+" - "+Valor2+"";
        QString Valor0 = ""+tr("Microfono: ")+Valor1.remove(".monitor")+" - "+Valor2+"";
        ui->comboBox->addItem(Valor);
        ui->comboBox->addItem(Valor0);
    }
    this->Explorar();
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar()));
    ui->label->setText("");
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_5,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_8,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    ui->radioButton_5->setChecked(true);
    ui->pushButton_7->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->groupBox_4->setEnabled(false);
    ui->groupBox_5->setVisible(false);
    connect(ui->radioButton_6,SIGNAL(clicked()),this,SLOT(Comprobar2()));
    connect(ui->radioButton_7,SIGNAL(clicked()),this,SLOT(Comprobar2()));
    ui->radioButton_6->setChecked(true);
    ui->pushButton_11->setEnabled(false);
    time =QDateTime::currentDateTime();
    Dia = time.toString("dd");
    Mes = time.toString("MM");
    Anyo = time.toString("yyyy");
    Hora = time.toString("hh");
    Minuto = time.toString("mm");
    Segundo = time.toString("ss");
    ui->spinBox->setValue(Dia.toInt());
    ui->spinBox_2->setValue(Mes.toInt());
    ui->spinBox_3->setValue(Anyo.toInt());
    ui->spinBox_6->setValue(Hora.toInt());
    ui->spinBox_4->setValue(Minuto.toInt());
    ui->spinBox_5->setValue(Segundo.toInt());
    Dia1 = time.toString("dd");
    Mes1 = time.toString("MM");
    Anyo1 = time.toString("yyyy");
    Hora1 = time.toString("hh");
    Minuto1 = time.toString("mm");
    Segundo1 = time.toString("ss");
    ui->spinBox_7->setValue(Dia1.toInt());
    ui->spinBox_8->setValue(Mes1.toInt());
    ui->spinBox_9->setValue(Anyo1.toInt());
    ui->spinBox_10->setValue(Hora1.toInt());
    ui->spinBox_11->setValue(Minuto1.toInt());
    ui->spinBox_12->setValue(Segundo1.toInt());
    QString cantidad44;
    QSqlQuery query42(db);
    query42.exec("SELECT english FROM Idioma WHERE id=2");
    query42.first();
    if (query42.isValid())
        cantidad44=query42.value(0).toString();
    if ( cantidad44 == "2")
    {
        ui->label_8->setText("Year");
        ui->label_22->setText("Year");
        ui->label_168->setText("Year");
    }
    Desbloqueo = 0;
    Desbloqueo = 1;
    Graba = 0;
    Control = 0;
    ui->pushButton_13->setEnabled(false);
    this->installEventFilter(this);
}

Grabador::~Grabador()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void Grabador::Valor(QString valor, QString Logs, Phonon::MediaObject *mediaObject, Phonon::AudioOutput *audioOutput, Phonon::Path path, Phonon::Effect *effect)
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

void Grabador::final()
{
    MediaObject->stop();
    ui->pushButton_12->setEnabled(true);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
}

void Grabador::Comprobar()
{
    ui->comboBox->clear();
    if (ui->radioButton->isChecked())
    {
        QString SinkM = LocSinkM();
        QString SinkD = LocSinkD();
        QStringList SinkMonitor = SinkM.split("\n");
        QStringList SinkDescrip = SinkD.split("\n");
        for(int a=0;a<SinkMonitor.count();a++)
        {
            QString Valor1 = SinkMonitor.value(a);
            QString Valor2 = SinkDescrip.value(a);
            Valor1 = Valor1.simplified();
            Valor2 = Valor2.simplified();
            Valor1 = Valor1.remove("Monitor Source:");
            Valor2 = Valor2.remove("Description:");
            Valor1 = Valor1.simplified();
            Valor2 = Valor2.simplified();
            QString Valor = ""+tr("Audio interno: ")+Valor1+" - "+Valor2+"";
            ui->comboBox->addItem(Valor);
        }
    }
    if (ui->radioButton_2->isChecked())
    {
        QString SinkM = LocSinkM();
        QString SinkD = LocSinkD();
        QStringList SinkMonitor = SinkM.split("\n");
        QStringList SinkDescrip = SinkD.split("\n");
        for(int a=0;a<SinkMonitor.count();a++)
        {
            QString Valor1 = SinkMonitor.value(a);
            QString Valor2 = SinkDescrip.value(a);
            Valor1 = Valor1.simplified();
            Valor2 = Valor2.simplified();
            Valor1 = Valor1.remove("Monitor Source:");
            Valor2 = Valor2.remove("Description:");
            Valor1 = Valor1.simplified();
            Valor2 = Valor2.simplified();
            QString Valor0 = ""+tr("Microfono: ")+Valor1.remove(".monitor")+" - "+Valor2+"";
            ui->comboBox->addItem(Valor0);
        }
    }        
}

void Grabador::Comprobar1()
{
    if (ui->radioButton_3->isChecked())
    {
        ui->radioButton_3->setChecked(true);
        ui->radioButton_4->setChecked(false);
        ui->radioButton_5->setChecked(false);
        ui->radioButton_8->setChecked(false);
        ui->pushButton_7->setVisible(true);
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_2->setText("");
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_12->setEnabled(false);
        ui->groupBox_4->setEnabled(false);
        ui->groupBox_5->setVisible(false);
        ui->groupBox_6->setVisible(true);
    }
    if (ui->radioButton_4->isChecked())
    {
        ui->radioButton_3->setChecked(false);
        ui->radioButton_4->setChecked(true);
        ui->radioButton_5->setChecked(false);
        ui->radioButton_8->setChecked(false);
        ui->pushButton_7->setVisible(false);
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_2->setText("");
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_12->setEnabled(false);
        ui->groupBox_4->setEnabled(false);
        ui->groupBox_5->setVisible(false);
        ui->groupBox_6->setVisible(true);
    }
    if (ui->radioButton_5->isChecked())
    {
        ui->radioButton_3->setChecked(false);
        ui->radioButton_4->setChecked(false);
        ui->radioButton_5->setChecked(true);
        ui->radioButton_8->setChecked(false);
        ui->pushButton_7->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_2->setText("");
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_12->setEnabled(true);
        ui->groupBox_4->setEnabled(false);
        ui->groupBox_5->setVisible(false);
        ui->groupBox_6->setVisible(true);
    }
    if (ui->radioButton_8->isChecked())
    {
        ui->radioButton_3->setChecked(false);
        ui->radioButton_4->setChecked(false);
        ui->radioButton_5->setChecked(false);
        ui->radioButton_8->setChecked(true);
        ui->pushButton_7->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_2->setText("");
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_5->setVisible(true);
        ui->groupBox_6->setVisible(false);
        time =QDateTime::currentDateTime().addSecs(300);
        Hora = time.toString("hh");
        Minuto = time.toString("mm");
        Segundo = time.toString("ss");
        ui->spinBox_6->setValue(Hora.toInt());
        ui->spinBox_4->setValue(Minuto.toInt());
        ui->spinBox_5->setValue(Segundo.toInt());
        Hora1 = time.toString("hh");
        Minuto1 = time.toString("mm");
        Segundo1 = time.toString("ss");
        ui->spinBox_10->setValue(Hora1.toInt());
        ui->spinBox_11->setValue(Minuto1.toInt());
        ui->spinBox_12->setValue(Segundo1.toInt());
        Desbloqueo = 0;
        Desbloqueo1 =0;
    }
}

void Grabador::Comprobar2()
{
    if (ui->radioButton_6->isChecked())
    {
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
        ui->groupBox_26->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_11->setEnabled(false);
    }
    if (ui->radioButton_7->isChecked())
    {
        ui->groupBox_3->setEnabled(false);
        ui->groupBox_4->setEnabled(false);
        ui->groupBox_5->setEnabled(false);
        ui->groupBox_26->setEnabled(false);
        ui->pushButton_15->setEnabled(false);
        ui->pushButton_11->setEnabled(true);
    }
}

void Grabador::Explorar()
{
    QStringList lista;
    QString Explora;
    Explora = "find /etc/asound.conf";
    drakeSistema drake;
    QString value = drake.getStart(Explora);
    if (value == "")
    {
        ui->radioButton_2->setChecked(true);
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("Microfono"),Qt::MatchContains));
    }
    else
    {
        QFile file("/etc/asound.conf");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString datoslst = in.readAll();
        file.close();
        lista = datoslst.split("\n");
        for(int b=0;b<lista.count();b++)
        {
            QString Valor = lista.value(b);
            if (Valor.contains("pcm.pulse"))
            {
                QString posicion = lista.value(b+3);
                if (posicion.contains("#"))
                {
                    ui->radioButton_2->setChecked(true);
                    ui->radioButton->setChecked(false);
                    posicion = posicion.remove("device");
                    posicion = posicion.remove(".monitor");
                    posicion = posicion.remove("#");
                    posicion = posicion.trimmed();
                    posicion = ""+tr("Microfono: ")+posicion+"";
                    if (ui->comboBox->findText(posicion,Qt::MatchContains) >= 0)
                        ui->comboBox->setCurrentIndex(ui->comboBox->findText(posicion,Qt::MatchContains));
                }
                else
                {
                    ui->radioButton->setChecked(true);
                    ui->radioButton_2->setChecked(false);
                    posicion = posicion.remove("device");
                    posicion = posicion.trimmed();
                    posicion = ""+tr("Audio interno: ")+posicion+"";
                    if (ui->comboBox->findText(posicion,Qt::MatchContains) >= 0)
                        ui->comboBox->setCurrentIndex(ui->comboBox->findText(posicion,Qt::MatchContains));
                }
            }
        }
    }
}

void Grabador::closeEvent ( QCloseEvent * event )
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

bool Grabador::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("Grabador"));
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

void Grabador::on_pushButton_clicked()
{
    if (CierreTotal == 1)
    {
        if (Log == "S")
            system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
        MediaObject->stop();
        emit Cerrar();
    }
    else
    {
        if (Log == "S")
            system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
        MediaObject->stop();
        close();
    }
}

void Grabador::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
}

void Grabador::mibFin()
{
     disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
     disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
}

void Grabador::KillProceso()
{
    if (mib != 0)
    {
        mib->killProceso();
        disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        ui->textEdit->append(tr("Grabacion terminada!!"));
    }
}

void Grabador::on_pushButton_4_clicked()
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

void Grabador::Ecualizar(QString Valor, int band1, int band2, int band3, int band4, int band5, int band6, int band7, int band8, int band9, int band10)
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

void Grabador::on_pushButton_5_clicked()
{
    if (ui->radioButton_6->isChecked())
    {
        QString path=tr("/home/%1/Documentos/");
        path=path.arg(user);
        fileName = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar archivo de audio")),
                            path,trUtf8(tr("Archivo de audio (*.mp3)")));
        if (fileName.isEmpty())
            return;
        if (fileName.contains(".mp3"))
            ui->lineEdit->setText(fileName);
        else
            ui->lineEdit->setText(""+fileName+".mp3");
    }
    else if (ui->radioButton_7->isChecked())
    {
        QString path=tr("/home/%1/Documentos/");
        path=path.arg(user);
        fileName = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar archivo de video")),
                            path,trUtf8(tr("Archivo de video (*.mkv)")));
        if (fileName.isEmpty())
            return;
        if (fileName.contains(".mkv"))
            ui->lineEdit->setText(fileName);
        else
            ui->lineEdit->setText(""+fileName+".mkv");
    }
}

void Grabador::on_lineEdit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    if (ui->radioButton_6->isChecked())
    {
        if (ui->lineEdit->text() != "")
            ui->pushButton_15->setEnabled(true);
    }
    else if (ui->radioButton_7->isChecked())
    {
        if (ui->lineEdit->text() != "")
            ui->pushButton_11->setEnabled(true);
    }
}

void Grabador::on_pushButton_3_clicked()
{
    ui->groupBox_26->setEnabled(true);
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileName1 = QFileDialog::getOpenFileName(this,tr(QString::fromUtf8("Abrir archivo de audio")),
                        path,trUtf8(tr("Archivo audio compatible (*.mp3 *.ogg)")));
    if (fileName1.isEmpty())
    {
        ui->groupBox_26->setEnabled(false);
        return;
    }
    drakeSistema drake;
    QString mp3Title = drake.getMp3Title(fileName1);
    QString mp3Artist = drake.getMp3Artist(fileName1);
    QString mp3Album = drake.getMp3Album(fileName1);
    QString mp3Year =  drake.getMp3Year(fileName1);
    QString mp3Comment = drake.getMp3Comment(fileName1);
    QString mp3Track = drake.getMp3Track(fileName1);
    QString mp3Genre = drake.getMp3Genre(fileName1);
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
    ui->lineEdit_33->setText(fileName1);
    ui->lineEdit_32->setText(QString::fromUtf8(mp3Title));
    ui->lineEdit_31->setText(QString::fromUtf8(mp3Artist));
    ui->lineEdit_30->setText(QString::fromUtf8(mp3Album));
    ui->lineEdit_34->setText(QString::fromUtf8(mp3Comment));
    ui->lineEdit_28->setText(QString::fromUtf8(mp3Year));
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
    ui->lineEdit_29->setText(QString::fromUtf8(PTrack));
    ui->lineEdit_27->setText(QString::fromUtf8(TTrack));
    ui->pushButton_12->setEnabled(true);
    ui->pushButton_14->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->label->setText(tr("Archivo cargado: ")+fileName1+"");
}

void Grabador::on_pushButton_12_clicked()
{
    if (ui->lineEdit_33->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ninguna cancion cargada."));
        m.exec();
        return;
    }
    else
    {
        Phonon::MediaSource source(ui->lineEdit_33->text());
        MediaObject->setCurrentSource(source);
        MediaObject->play();
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_14->setEnabled(true);
        ui->seekSlider_2->setMediaObject(MediaObject);
        ui->volumeSlider_4->setAudioOutput(AudioOutput);
        timer->start(1000);
    }
}

void Grabador::update()
{
    if (ui->pushButton_15->text() == tr("Grabando"))
    {
        QTime x(00,00,00);
        x=x.addSecs(+(iTcrs));
        ui->lcdNumber_2->display(x.toString("hh:mm:ss"));
        iTcrs++;
    }
    else
    {
        quint64 time = MediaObject->currentTime();
        QTime displayTime((time / 3600000) % 60, (time / 60000) % 60, (time / 1000) % 60);
        ui->lcdNumber_2->display(displayTime.toString("hh:mm:ss"));
    }
}

void Grabador::on_pushButton_14_clicked()
{
    MediaObject->stop();
    MediaObject->pause();
    if (ui->radioButton_6->isChecked())
    {
        if (ui->pushButton_15->text() == tr("Grabando"))
        {
            ui->pushButton_12->setEnabled(true);
            ui->pushButton_6->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            ui->radioButton_5->setChecked(true);
            this->Comprobar1();
            ui->pushButton_15->setText(tr("Grabar"));
            ui->pushButton_15->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/grabaout.png")));
            ui->pushButton_15->setIconSize(QSize(25,25));
            timer->stop();
            iTcrs=0;
            ui->lcdNumber_2->display("00:00:00");
            this->KillProceso();
        }
        else
        {
            ui->pushButton_12->setEnabled(true);
            ui->pushButton_6->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            timer->stop();
            ui->lcdNumber_2->display("00:00:00");

        }
    }
    else if (ui->radioButton_7->isChecked())
    {
        if (ui->pushButton_11->text() == tr("Capturando escritorio"))
        {
            ui->pushButton_12->setEnabled(true);
            ui->pushButton_6->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            ui->radioButton_5->setChecked(true);
            this->Comprobar1();
            ui->pushButton_11->setText(tr("Capturar escritorio"));
            ui->pushButton_11->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/EscritorioOut.png")));
            ui->pushButton_11->setIconSize(QSize(25,25));
            iTcrs=0;
            this->KillProceso();
        }
        else
        {
            ui->pushButton_12->setEnabled(true);
            ui->pushButton_6->setEnabled(false);
            ui->pushButton_14->setEnabled(false);
            timer->stop();
            ui->lcdNumber_2->display("00:00:00");

        }
    }
}

void Grabador::on_pushButton_6_clicked()
{
    bool wasPlaying = MediaObject->state() == Phonon::PausedState;
    if (wasPlaying)
    {
        MediaObject->play();
        ui->pushButton_6->setText(tr("Pausa"));
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_14->setEnabled(true);
    }
    else
    {
        MediaObject->pause();
        ui->pushButton_6->setText(tr("Continuar"));
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_14->setEnabled(false);
    }
}

void Grabador::on_pushButton_15_clicked()
{
    if (ui->lineEdit->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ningun archivo de salida para poder grabar."));
        m.exec();
        return;
    }
    if (ui->pushButton_15->text() == tr("Grabar"))
    {
        if (!ui->lineEdit->text().contains(".mp3"))
        {
            int respuesta = 0;
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                           QString::fromUtf8(tr("<center><b>Fichero de salida erroneo</center><p>"
                           "No se puede realizar la grabacion porque el fichero introducido como destino "
                           "no tiene la extension .mp3 correcta.<p>"
                           "&iquest;Insertar extension .mp3 para continuar?")), QMessageBox::Ok, QMessageBox::No);
            if (respuesta == QMessageBox::Ok)
                ui->lineEdit->setText(""+fileName+".mp3");
            else
                return;
        }
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_14->setEnabled(true);
        ui->pushButton_15->setText(tr("Grabando"));
        ui->pushButton_15->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/grabain.png")));
        ui->pushButton_15->setIconSize(QSize(25,25));
        ui->lcdNumber_2->display("00:00:00");
        timer->start(1000);
        QStringList comandos;
        QString cmd1 = "su - "+user+" -c \"ffmpeg -f alsa -i pulse -ac 2 -ab 128k -y %1\"";
        cmd1=cmd1.arg(ui->lineEdit->text());
        comandos<< cmd1;
        mib = new DrakeProcesos1(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count();
        mib->Valor(valor,4);
        mib->iniciarProceso();
        Phonon::MediaSource source(ui->lineEdit_33->text());
        MediaObject->setCurrentSource(source);
        MediaObject->play();
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_14->setEnabled(true);
        ui->seekSlider_2->setMediaObject(MediaObject);
        ui->volumeSlider_4->setAudioOutput(AudioOutput);
        timer->start(1000);
    }
}

QString Grabador::LocSinkM()
{
    QProcess *procesoFind, *procesoCut;
    QStringList argumentosFind;
    QStringList argumentosCut;
    QByteArray TipVirtual;
    procesoFind=new QProcess(this);
    procesoCut=new QProcess(this);
    argumentosFind << "list" << "sinks";
    argumentosCut << "Monitor Source";
    procesoFind->setStandardOutputProcess(procesoCut);
    procesoFind->start("pactl",argumentosFind);
    procesoCut->start("grep",argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoFind->waitForFinished();
    procesoCut->waitForFinished();
    TipVirtual = QString(procesoCut->readAllStandardOutput());
    delete procesoFind;
    delete procesoCut;
    QString res =  QString(TipVirtual);
    res.chop(1);
    return res;
}

QString Grabador::LocSinkD()
{
    QProcess *procesoFind, *procesoCut;
    QStringList argumentosFind;
    QStringList argumentosCut;
    QByteArray TipVirtual;
    procesoFind=new QProcess(this);
    procesoCut=new QProcess(this);
    argumentosFind << "list" << "sinks";
    argumentosCut << "Description";
    procesoFind->setStandardOutputProcess(procesoCut);
    procesoFind->start("pactl",argumentosFind);
    procesoCut->start("grep",argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoFind->waitForFinished();
    procesoCut->waitForFinished();
    TipVirtual = QString(procesoCut->readAllStandardOutput());
    delete procesoFind;
    delete procesoCut;
    QString res =  QString(TipVirtual);
    res.chop(1);
    return res;
}

void Grabador::on_pushButton_2_clicked()
{
    QString source, sourcefinal, archivo, posicion1, posicion2, posicion3, posicion4;
    source = ui->comboBox->currentText();
    QStringList Source = source.split(" ");
    if (source.contains(tr("Audio interno")))
        sourcefinal = Source.value(2);
    else
        sourcefinal = Source.value(1);
    QStringList lista;
    QString Explora;
    Explora = "find /etc/asound.conf";
    drakeSistema drake;
    QString valor = drake.getStart(Explora);
    if (valor == "")
        archivo = "No";
    else
        archivo = "Si";
    if (ui->radioButton->isChecked())
    {
        if (archivo == "Si")
        {
            QFile file("/etc/asound.conf");
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in1(&file);
            QString datoslst = in1.readAll();
            lista = datoslst.split("\n");
            file.close();
            file.open(QIODevice::ReadWrite | QIODevice::Truncate);
            QTextStream in(&file);
            for(int b=0;b<lista.count();b++)
            {
                QString valor = lista.value(b);
                if (valor.contains("pcm.pulse"))
                {
                    in << valor + "\n";
                    posicion1 = lista.value(b+1);
                    in << posicion1 + "\n";
                    posicion2 = lista.value(b+2);
                    in << posicion2 + "\n";
                    posicion3 = lista.value(b+3);
                    posicion3 = posicion3.remove("#");
                    in << posicion3 + "\n";
                    posicion4 = lista.value(b+4);
                    in << posicion4 + "\n";
                    b = b+4;
                }
                else if (valor.contains("ctl.pulse"))
                {
                    valor = valor.remove("#");
                    in << valor + "\n";
                    posicion1 = lista.value(b+1);
                    in << posicion1 + "\n";
                    posicion2 = lista.value(b+2);
                    in << posicion2 + "\n";
                    posicion3 = lista.value(b+3);
                    posicion3 = posicion3.remove("#");
                    in << posicion3 + "\n";
                    posicion4 = lista.value(b+4);
                    in << posicion4 + "\n";
                    b = b+4;
                }
                else
                    in << valor + "\n";
            }
            file.close();
            ui->textEdit->append(tr("Configurado a entrada de grabacion: Audio interno. Modificado el fichero necesario."));
        }
        else if (archivo == "No")
        {
            QFile file("/etc/asound.conf");
            file.open(QIODevice::ReadWrite | QIODevice::Text);
            QTextStream in2(&file);
            in2 << "#Configuracion automatica de RecoverDrake" << "\n";
            in2 << "" << "\n";
            in2 << "pcm.pulse" << "\n";
            in2 << "{" << "\n";
            in2 << "   type pulse" << "\n";
            in2 << "   device " << sourcefinal << "\n";
            in2 << "}" << "\n";
            in2 << "" << "\n";
            in2 << "ctl.pulse" << "\n";
            in2 << "{" << "\n";
            in2 << "   type pulse" << "\n";
            in2 << "   device " << sourcefinal << "\n";
            in2 << "}" << "\n";
            file.close();
            ui->textEdit->append(tr("Configurado a entrada de grabacion: Audio interno. Generado el fichero necesario."));
        }
    }
    else if (ui->radioButton_2->isChecked())
    {
        if (archivo == "Si")
        {
            QFile file("/etc/asound.conf");
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in1(&file);
            QString datoslst = in1.readAll();
            lista = datoslst.split("\n");
            file.close();
            file.open(QIODevice::ReadWrite | QIODevice::Truncate);
            QTextStream in(&file);
            for(int b=0;b<lista.count();b++)
            {
                QString valor = lista.value(b);
                if (valor.contains("pcm.pulse"))
                {
                    in << valor + "\n";
                    posicion1 = lista.value(b+1);
                    in << posicion1 + "\n";
                    posicion2 = lista.value(b+2);
                    in << posicion2 + "\n";
                    posicion3 = lista.value(b+3);
                    in << "#" << posicion3 + "\n";
                    posicion4 = lista.value(b+4);
                    in << posicion4 + "\n";
                    b = b+4;
                }
                else if (valor.contains("ctl.pulse"))
                {
                    in << valor + "\n";
                    posicion1 = lista.value(b+1);
                    in << posicion1 + "\n";
                    posicion2 = lista.value(b+2);
                    in << posicion2 + "\n";
                    posicion3 = lista.value(b+3);
                    in << "#" << posicion3 + "\n";
                    posicion4 = lista.value(b+4);
                    in << posicion4 + "\n";
                    b = b+4;
                }
                else
                    in << valor + "\n";
            }
            file.close();
            ui->textEdit->append(tr("Configurado a entrada de grabacion: Microfono. Modificado el fichero necesario."));
        }
        else if (archivo == "No")
            ui->textEdit->append(tr("No es necesario configurar el archivo a microfono, No se genera el archivo de configuracion."));
    }
    this->Explorar();
}

void Grabador::on_pushButton_7_clicked()
{
    ui->groupBox_26->setEnabled(true);
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileName1 = QFileDialog::getOpenFileName(this,tr(QString::fromUtf8("Abrir archivo de audio")),
                        path,trUtf8(tr("Archivo audio compatible (*.mp3 *.ogg)")));
    if (fileName1.isEmpty())
    {
        ui->groupBox_26->setEnabled(false);
        return;
    }
    drakeSistema drake;
    QString mp3Title = drake.getMp3Title(fileName1);
    QString mp3Artist = drake.getMp3Artist(fileName1);
    QString mp3Album = drake.getMp3Album(fileName1);
    QString mp3Year =  drake.getMp3Year(fileName1);
    QString mp3Comment = drake.getMp3Comment(fileName1);
    QString mp3Track = drake.getMp3Track(fileName1);
    QString mp3Genre = drake.getMp3Genre(fileName1);
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
    ui->lineEdit_33->setText(fileName1);
    ui->lineEdit_32->setText(QString::fromUtf8(mp3Title));
    ui->lineEdit_31->setText(QString::fromUtf8(mp3Artist));
    ui->lineEdit_30->setText(QString::fromUtf8(mp3Album));
    ui->lineEdit_34->setText(QString::fromUtf8(mp3Comment));
    ui->lineEdit_28->setText(QString::fromUtf8(mp3Year));
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
    ui->lineEdit_29->setText(QString::fromUtf8(PTrack));
    ui->lineEdit_27->setText(QString::fromUtf8(TTrack));
    ui->label->setText(tr("Archivo cargado: ")+fileName1+"");
    ui->lineEdit_2->setText(fileName1);
}

void Grabador::on_pushButton_11_clicked()
{
    if (ui->lineEdit->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ningun archivo de salida para poder grabar."));
        m.exec();
        return;
    }
    if (ui->pushButton_11->text() == tr("Capturar escritorio"))
    {
        if (!ui->lineEdit->text().contains(".mkv"))
        {
            int respuesta = 0;
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                           QString::fromUtf8(tr("<center><b>Fichero de salida erroneo</center><p>"
                           "No se puede realizar la grabacion porque el fichero introducido como destino "
                           "no tiene la extension .mkv correcta.<p>"
                           "&iquest;Insertar extension .mkv para continuar?")), QMessageBox::Ok, QMessageBox::No);
            if (respuesta == QMessageBox::Ok)
                ui->lineEdit->setText(""+fileName+".mkv");
            else
                return;
        }
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_14->setEnabled(true);
        ui->pushButton_11->setText(tr("Capturando escritorio"));
        ui->pushButton_11->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/EscritorioIn.png")));
        ui->pushButton_11->setIconSize(QSize(25,25));
        drakeSistema drake;
        QString X = drake.getResolution();
        QString Y = drake.getResolucion();
        QStringList LasY = Y.split(",");
        QString Y2 = LasY.value(2);
        Y2=Y2.remove(" ").remove("maximum");
        QStringList LasX = X.split(" ");
        QString X2 = LasX.value(3);
        QStringList Parcial2 = X2.split("x");
        int Dato1 = Parcial2.value(0).toInt();
        int Dato2 = Parcial2.value(1).toInt();
        QString Resolucion = ""+QString::number(Dato1)+"x"+QString::number(Dato2)+"";
        QStringList comandos;
        QString cmd1 = "su - "+user+" -c \"ffmpeg -async 1 -f alsa -ac 2 -i pulse -f x11grab -crf 1 -qscale 1 -s %1 -r 25 -i :0.0 -y %2\"";
        cmd1=cmd1.arg(Resolucion).arg(ui->lineEdit->text());
        comandos<< cmd1;
        mib = new DrakeProcesos1(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count();
        mib->Valor(valor,4);
        mib->iniciarProceso();
    }
}

void Grabador::on_pushButton_8_clicked()
{
    ui->tableWidget->setSortingEnabled(false);
    QString Ruta, Fuente;
    QMessageBox m;
    QTableWidgetItem *item, *item1, *item2, *item3;
    item=new QTableWidgetItem;
    item1=new QTableWidgetItem;
    item2=new QTableWidgetItem;
    item3=new QTableWidgetItem;
    Ruta = ui->lineEdit_3->text();
    if (Ruta == "")
    {
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No tienes definida la ruta donde grabar."));
        m.exec();
        return;
    }
    else
    {
        if (Ruta.contains(".mp3"))
            item->setText(Ruta);
        else
        {
            int respuesta = 0;
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                           QString::fromUtf8(tr("<center><b>Fichero de salida erroneo</center><p>"
                           "No se puede realizar la grabacion porque el fichero introducido como destino "
                           "no tiene la extension .mp3 correcta.<p>"
                           "&iquest;Insertar extension .mp3 para continuar?")), QMessageBox::Ok, QMessageBox::No);
            if (respuesta == QMessageBox::Ok)
            {
                ui->lineEdit_3->setText(""+Ruta+".mp3");
                item->setText(ui->lineEdit_3->text());
            }
            else
                return;
        }
    }
    Fuente = ui->lineEdit_4->text();
    if (Fuente == "")
    {
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No tienes definida la fuente desde donde grabar."));
        m.exec();
        return;
    }
    else
    {
        if (Fuente.contains("://"))
            item1->setText(Fuente);
        else
        {
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("La fuente no es una direccion valida."));
            m.exec();
            return;
        }
    }
    QString DiaD = QString::number(ui->spinBox->value());
    QString MesD = QString::number(ui->spinBox_2->value());
    QString AnyoD = QString::number(ui->spinBox_3->value());
    QString HoraD = QString::number(ui->spinBox_6->value());
    QString MinutoD = QString::number(ui->spinBox_4->value());
    QString SegundoD = QString::number(ui->spinBox_5->value());
    QString DiaF = QString::number(ui->spinBox_7->value());
    QString MesF = QString::number(ui->spinBox_8->value());
    QString AnyoF = QString::number(ui->spinBox_9->value());
    QString HoraF = QString::number(ui->spinBox_10->value());
    QString MinutoF = QString::number(ui->spinBox_11->value());
    QString SegundoF = QString::number(ui->spinBox_12->value());
    QDateTime FechaInicio(QDate(AnyoD.toInt(),MesD.toInt(),DiaD.toInt()), QTime(HoraD.toInt(),MinutoD.toInt(),SegundoD.toInt()));
    QDateTime FechaFinal(QDate(AnyoF.toInt(),MesF.toInt(),DiaF.toInt()), QTime(HoraF.toInt(),MinutoF.toInt(),SegundoF.toInt()));
    time =QDateTime::currentDateTime().addSecs(60);
    if (FechaInicio <= time)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                       QString::fromUtf8(tr("<center><b>Fecha de inicio incorrecta</center><p>"
                       "La fecha de inicio tiene que ser como minimo 1 minuto superior a la fecha actual del sistema.<p>"
                       "&iquest;Ajustar fecha de inicio a la del sistema?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            FechaInicio = QDateTime::currentDateTime().addSecs(60);
            time =QDateTime::currentDateTime().addSecs(60);
            Dia = time.toString("dd");
            Mes = time.toString("MM");
            Anyo = time.toString("yyyy");
            Hora = time.toString("hh");
            Minuto = time.toString("mm");
            Segundo = time.toString("ss");
            ui->spinBox->setValue(Dia.toInt());
            ui->spinBox_2->setValue(Mes.toInt());
            ui->spinBox_3->setValue(Anyo.toInt());
            ui->spinBox_6->setValue(Hora.toInt());
            ui->spinBox_4->setValue(Minuto.toInt());
            ui->spinBox_5->setValue(Segundo.toInt());
        }
        else
            return;
    }
    DiaD = FechaInicio.toString("dd");
    MesD = FechaInicio.toString("MM");
    AnyoD = FechaInicio.toString("yyyy");
    HoraD = FechaInicio.toString("hh");
    MinutoD = FechaInicio.toString("mm");
    SegundoD = FechaInicio.toString("ss");
    DiaF = FechaFinal.toString("dd");
    MesF = FechaFinal.toString("MM");
    AnyoF = FechaFinal.toString("yyyy");
    HoraF = FechaFinal.toString("hh");
    MinutoF = FechaFinal.toString("mm");
    SegundoF = FechaFinal.toString("ss");
    if (FechaInicio >= FechaFinal)
    {
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr(QString::fromUtf8("La fecha final no puede ser inferior o igual a la fecha de inicio.")));
        m.exec();
        return;
    }
    else
    {
        item2->setText(""+DiaD+"/"+MesD+"/"+AnyoD+" "+HoraD+":"+MinutoD+":"+SegundoD+"");
        item3->setText(""+DiaF+"/"+MesF+"/"+AnyoF+" "+HoraF+":"+MinutoF+":"+SegundoF+"");
    }
    QString valor = Revisar(FechaInicio,0,0);
    if (valor == "Si")
    {
        int iFilas=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(iFilas);
        ui->tableWidget->setItem(iFilas,0,item);
        ui->tableWidget->setItem(iFilas,1,item1);
        ui->tableWidget->setItem(iFilas,2,item2);
        ui->tableWidget->setItem(iFilas,3,item3);
        ui->tableWidget->setSortingEnabled(true);
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
    }
    else
    {
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr(QString::fromUtf8("La fecha de inicio tiene que ser superior a la fecha final anterior.")));
        m.exec();
        return;
    }
    int Total = ui->tableWidget->rowCount();
    if (Total > 0)
        ui->pushButton_13->setEnabled(true);
    else
        ui->pushButton_13->setEnabled(false);
}

void Grabador::on_pushButton_16_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    fileName = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar archivo de audio")),
                        path,trUtf8(tr("Archivo de audio (*.mp3)")));
    if (fileName.isEmpty())
        return;
    if (fileName.contains(".mp3"))
        ui->lineEdit_3->setText(fileName);
    else
        ui->lineEdit_3->setText(""+fileName+".mp3");
}

void Grabador::on_tableWidget_itemSelectionChanged()
{
    QString Ruta, Fuente, HorarioI, HorarioF;
    int iFilas;
    iFilas=ui->tableWidget->currentRow();
    if (iFilas == -1)
        return;
    else
    {
        QTableWidgetItem *item, *item1, *item2, *item3;
        item=new QTableWidgetItem;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        item=ui->tableWidget->item(iFilas,0);
        item1=ui->tableWidget->item(iFilas,1);
        item2=ui->tableWidget->item(iFilas,2);
        item3=ui->tableWidget->item(iFilas,3);
        Ruta = item->text();
        Fuente = item1->text();
        HorarioI = item2->text();
        HorarioF = item3->text();
        QStringList HorI = HorarioI.split(" ");
        QString Fecha1 = HorI.value(0);
        QString Hora1 = HorI.value(1);
        QStringList Fecha1I, Hora1I;
        Fecha1I = Fecha1.split("/");
        Hora1I = Hora1.split(":");
        ui->spinBox->setValue(Fecha1I.value(0).toInt());
        ui->spinBox_2->setValue(Fecha1I.value(1).toInt());
        ui->spinBox_3->setValue(Fecha1I.value(2).toInt());
        ui->spinBox_6->setValue(Hora1I.value(0).toInt());
        ui->spinBox_4->setValue(Hora1I.value(1).toInt());
        ui->spinBox_5->setValue(Hora1I.value(2).toInt());
        QStringList HorF = HorarioF.split(" ");
        QString Fecha2 = HorF.value(0);
        QString Hora2 = HorF.value(1);
        QStringList Fecha2F, Hora2F;
        Fecha2F = Fecha2.split("/");
        Hora2F = Hora2.split(":");
        ui->spinBox_7->setValue(Fecha2F.value(0).toInt());
        ui->spinBox_8->setValue(Fecha2F.value(1).toInt());
        ui->spinBox_9->setValue(Fecha2F.value(2).toInt());
        ui->spinBox_10->setValue(Hora2F.value(0).toInt());
        ui->spinBox_11->setValue(Hora2F.value(1).toInt());
        ui->spinBox_12->setValue(Hora2F.value(2).toInt());
        ui->lineEdit_3->setText(Ruta);
        ui->lineEdit_4->setText(Fuente);
    }
}

void Grabador::on_pushButton_9_clicked()
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
        QTableWidgetItem *item, *item1, *item2, *item3;
        item=new QTableWidgetItem;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        QString Ruta, Fuente;
        QMessageBox m;
        Ruta = ui->lineEdit_3->text();
        if (Ruta == "")
        {
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No tienes definida la ruta donde grabar."));
            m.exec();
            return;
        }
        else
        {
            if (Ruta.contains(".mp3"))
                item->setText(Ruta);
            else
            {
                int respuesta = 0;
                respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                               QString::fromUtf8(tr("<center><b>Fichero de salida erroneo</center><p>"
                               "No se puede realizar la grabacion porque el fichero introducido como destino "
                               "no tiene la extension .mp3 correcta.<p>"
                               "&iquest;Insertar extension .mp3 para continuar?")), QMessageBox::Ok, QMessageBox::No);
                if (respuesta == QMessageBox::Ok)
                    ui->lineEdit_3->setText(""+Ruta+".mp3");
                else
                    return;
            }
        }
        Fuente = ui->lineEdit_4->text();
        if (Fuente == "")
        {
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No tienes definida la fuente desde donde grabar."));
            m.exec();
            return;
        }
        else
        {
            if (Fuente.contains("://"))
                item1->setText(Fuente);
            else
            {
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("La fuente no es una direccion valida."));
                m.exec();
                return;
            }
        }
        QString DiaD = QString::number(ui->spinBox->value());
        QString MesD = QString::number(ui->spinBox_2->value());
        QString AnyoD = QString::number(ui->spinBox_3->value());
        QString HoraD = QString::number(ui->spinBox_6->value());
        QString MinutoD = QString::number(ui->spinBox_4->value());
        QString SegundoD = QString::number(ui->spinBox_5->value());
        QString DiaF = QString::number(ui->spinBox_7->value());
        QString MesF = QString::number(ui->spinBox_8->value());
        QString AnyoF = QString::number(ui->spinBox_9->value());
        QString HoraF = QString::number(ui->spinBox_10->value());
        QString MinutoF = QString::number(ui->spinBox_11->value());
        QString SegundoF = QString::number(ui->spinBox_12->value());
        QDateTime FechaInicio(QDate(AnyoD.toInt(),MesD.toInt(),DiaD.toInt()), QTime(HoraD.toInt(),MinutoD.toInt(),SegundoD.toInt()));
        QDateTime FechaFinal(QDate(AnyoF.toInt(),MesF.toInt(),DiaF.toInt()), QTime(HoraF.toInt(),MinutoF.toInt(),SegundoF.toInt()));
        time =QDateTime::currentDateTime().addSecs(60);
        if (FechaInicio <= time)
        {
            int respuesta = 0;
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                           QString::fromUtf8(tr("<center><b>Fecha de inicio incorrecta</center><p>"
                           "La fecha de inicio tiene que ser como minimo 1 minuto superior a la fecha actual del sistema.<p>"
                           "&iquest;Ajustar fecha de inicio a la del sistema?")), QMessageBox::Ok, QMessageBox::No);
            if (respuesta == QMessageBox::Ok)
            {
                FechaInicio = QDateTime::currentDateTime().addSecs(60);
                time =QDateTime::currentDateTime().addSecs(60);
                Dia = time.toString("dd");
                Mes = time.toString("MM");
                Anyo = time.toString("yyyy");
                Hora = time.toString("hh");
                Minuto = time.toString("mm");
                Segundo = time.toString("ss");
                ui->spinBox->setValue(Dia.toInt());
                ui->spinBox_2->setValue(Mes.toInt());
                ui->spinBox_3->setValue(Anyo.toInt());
                ui->spinBox_6->setValue(Hora.toInt());
                ui->spinBox_4->setValue(Minuto.toInt());
                ui->spinBox_5->setValue(Segundo.toInt());
            }
            else
                return;
        }
        DiaD = FechaInicio.toString("dd");
        MesD = FechaInicio.toString("MM");
        AnyoD = FechaInicio.toString("yyyy");
        HoraD = FechaInicio.toString("hh");
        MinutoD = FechaInicio.toString("mm");
        SegundoD = FechaInicio.toString("ss");
        DiaF = FechaFinal.toString("dd");
        MesF = FechaFinal.toString("MM");
        AnyoF = FechaFinal.toString("yyyy");
        HoraF = FechaFinal.toString("hh");
        MinutoF = FechaFinal.toString("mm");
        SegundoF = FechaFinal.toString("ss");
        if (FechaInicio >= FechaFinal)
        {
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr(QString::fromUtf8("La fecha final no puede ser inferior o igual a la fecha de inicio.")));
            m.exec();
            return;
        }
        else
        {
            item2->setText(""+DiaD+"/"+MesD+"/"+AnyoD+" "+HoraD+":"+MinutoD+":"+SegundoD+"");
            item3->setText(""+DiaF+"/"+MesF+"/"+AnyoF+" "+HoraF+":"+MinutoF+":"+SegundoF+"");
        }
        QString valor = Revisar(FechaInicio,1,iFilas);
        if (valor == "Si")
        {
            ui->tableWidget->setItem(iFilas,0,item);
            ui->tableWidget->setItem(iFilas,1,item1);
            ui->tableWidget->setItem(iFilas,2,item2);
            ui->tableWidget->setItem(iFilas,3,item3);
            ui->tableWidget->resizeRowsToContents();
            ui->tableWidget->resizeColumnsToContents();
        }
        else
        {
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr(QString::fromUtf8("La fecha de inicio tiene que ser superior a la fecha final anterior.")));
            m.exec();
            return;
        }
    }
    int Total = ui->tableWidget->rowCount();
    if (Total > 0)
        ui->pushButton_13->setEnabled(true);
    else
        ui->pushButton_13->setEnabled(false);
}

void Grabador::on_pushButton_10_clicked()
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
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
    }
    int Total = ui->tableWidget->rowCount();
    if (Total > 0)
        ui->pushButton_13->setEnabled(true);
    else
        ui->pushButton_13->setEnabled(false);
}

QString Grabador::Revisar(QDateTime HoraI, int ValorI, int Posicion)
{
    int iFilas, ValueI;
    QString HorarioF, valor;
    iFilas=ui->tableWidget->rowCount();
    if (ValorI == 0)
        ValueI = iFilas-1;
    else if (ValorI == 1)
    {
        iFilas = Posicion;
        ValueI = iFilas-1;
    }
    if (iFilas > 0)
    {
        QTableWidgetItem *item1;
        item1=new QTableWidgetItem;
        for(int i=ValueI;i<iFilas;i++)
        {
            item1=ui->tableWidget->item(i,3);
            HorarioF = item1->text();
            QStringList HorF = HorarioF.split(" ");
            QString Fecha2 = HorF.value(0);
            QString Hora2 = HorF.value(1);
            QStringList Fecha2F, Hora2F;
            Fecha2F = Fecha2.split("/");
            Hora2F = Hora2.split(":");
            int DiaF = Fecha2F.value(0).toInt();
            int MesF = Fecha2F.value(1).toInt();
            int AnyoF = Fecha2F.value(2).toInt();
            int HoraF = Hora2F.value(0).toInt();
            int MinutoF = Hora2F.value(1).toInt();
            int SegundoF = Hora2F.value(2).toInt();
            QDateTime FechaFinal(QDate(AnyoF,MesF,DiaF), QTime(HoraF,MinutoF,SegundoF));
            if (FechaFinal < HoraI)
                valor = "Si";
            else
                valor = "No";
        }
    }
    else
        valor = "Si";
    return valor;
}

void Grabador::on_spinBox_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox->setPrefix("0");
    else
        ui->spinBox->setPrefix("");
}

void Grabador::on_spinBox_2_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_2->setPrefix("0");
    else
        ui->spinBox_2->setPrefix("");
}

void Grabador::on_spinBox_6_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_6->setPrefix("0");
    else
        ui->spinBox_6->setPrefix("");
    time =QDateTime::currentDateTime();
    int Valor = time.toString("hh").toInt();
    if (Valor != arg1)
        Desbloqueo = 1;
}

void Grabador::on_spinBox_4_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_4->setPrefix("0");
    else
        ui->spinBox_4->setPrefix("");
    time =QDateTime::currentDateTime();
    int Valor = time.toString("mm").toInt();
    if (Valor != arg1)
        Desbloqueo = 1;
}

void Grabador::on_spinBox_5_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_5->setPrefix("0");
    else
        ui->spinBox_5->setPrefix("");
    time =QDateTime::currentDateTime();
    int Valor = time.toString("ss").toInt();
    if (Valor != arg1)
        Desbloqueo = 1;
}

void Grabador::on_spinBox_7_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_7->setPrefix("0");
    else
        ui->spinBox_7->setPrefix("");
}

void Grabador::on_spinBox_8_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_8->setPrefix("0");
    else
        ui->spinBox_8->setPrefix("");
}

void Grabador::on_spinBox_10_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_10->setPrefix("0");
    else
        ui->spinBox_10->setPrefix("");
    time =QDateTime::currentDateTime();
    int Valor = time.toString("hh").toInt();
    if (Valor != arg1)
        Desbloqueo1 = 1;
}

void Grabador::on_spinBox_11_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_11->setPrefix("0");
    else
        ui->spinBox_11->setPrefix("");
    time =QDateTime::currentDateTime();
    int Valor = time.toString("mm").toInt();
    if (Valor != arg1)
        Desbloqueo1 = 1;
}

void Grabador::on_spinBox_12_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_12->setPrefix("0");
    else
        ui->spinBox_12->setPrefix("");
    time =QDateTime::currentDateTime();
    int Valor = time.toString("ss").toInt();
    if (Valor != arg1)
        Desbloqueo1 = 1;
}

void Grabador::hora()
{
    time =QDateTime::currentDateTime();
    QString hora = time.toString("dd/MM/yyyy hh:mm:ss");
    ui->label_29->setText(hora);
    if (Desbloqueo == 0)
    {
        Hora = time.toString("hh");
        Minuto = time.toString("mm");
        Segundo = time.toString("ss");
        ui->spinBox_6->setValue(Hora.toInt());
        ui->spinBox_4->setValue(Minuto.toInt());
        ui->spinBox_5->setValue(Segundo.toInt());
    }
    if (Desbloqueo1 == 0)
    {
        Hora1 = time.toString("hh");
        Minuto1 = time.toString("mm");
        Segundo1 = time.toString("ss");
        ui->spinBox_10->setValue(Hora1.toInt());
        ui->spinBox_11->setValue(Minuto1.toInt());
        ui->spinBox_12->setValue(Segundo1.toInt());
    }
}

void Grabador::on_pushButton_13_clicked()
{
    if (Graba == 0)
        Graba = 1;
    else if (Graba == 1)
        Graba = 0;
    if (Graba == 0)
    {
        ui->pushButton_13->setText(tr("Iniciar temporizador"));
        if (ControlRec->isActive())
            ControlRec->stop();
        if (Control == 1)
        {
            ControlFin->stop();
            this->KillProceso();
            system("killall firefox");
        }
    }
    else if (Graba == 1)
    {
        ui->pushButton_13->setText(tr("Parar temporizador"));
        this->EjecutarTempo();
    }
}

void Grabador::EjecutarTempo()
{
    QTableWidgetItem *item, *item1, *item2, *item3;
    item=new QTableWidgetItem;
    item1=new QTableWidgetItem;
    item2=new QTableWidgetItem;
    item3=new QTableWidgetItem;
    item=ui->tableWidget->item(0,2);
    item1=ui->tableWidget->item(0,3);
    item2=ui->tableWidget->item(0,0);
    item3=ui->tableWidget->item(0,1);
    PathI = item2->text();
    Source = item3->text();
    QString Horario = item->text();
    QStringList Hor = Horario.split(" ");
    QString Fecha = Hor.value(0);
    QString HoraI = Hor.value(1);
    QStringList Fecha1, Hora1;
    Fecha1 = Fecha.split("/");
    Hora1 = HoraI.split(":");
    int Dia = Fecha1.value(0).toInt();
    int Mes = Fecha1.value(1).toInt();
    int Anyo = Fecha1.value(2).toInt();
    int Hora = Hora1.value(0).toInt();
    int Minuto = Hora1.value(1).toInt();
    int Segundo = Hora1.value(2).toInt();
    QDateTime FechaInicio(QDate(Anyo,Mes,Dia), QTime(Hora,Minuto,Segundo));
    Inicio = FechaInicio;
    QString HorarioF = item1->text();
    QStringList HorF = HorarioF.split(" ");
    QString Fecha2 = HorF.value(0);
    QString Hora2 = HorF.value(1);
    QStringList Fecha2F, Hora2F;
    Fecha2F = Fecha2.split("/");
    Hora2F = Hora2.split(":");
    int DiaF = Fecha2F.value(0).toInt();
    int MesF = Fecha2F.value(1).toInt();
    int AnyoF = Fecha2F.value(2).toInt();
    int HoraF = Hora2F.value(0).toInt();
    int MinutoF = Hora2F.value(1).toInt();
    int SegundoF = Hora2F.value(2).toInt();
    QDateTime FechaFinal(QDate(AnyoF,MesF,DiaF), QTime(HoraF,MinutoF,SegundoF));
    Final = FechaFinal;
    ControlRec = new QTimer(this);
    connect(ControlRec, SIGNAL(timeout()), this, SLOT(CtrlRec()));
    ControlRec->start(1000);
}

void Grabador::CtrlRec()
{    
    QDateTime FechaInicio = QDateTime::currentDateTime();
    if (FechaInicio >= Inicio)
    {
        system("su - "+user+" -c \"firefox "+Source+"\"");
        QStringList comandos;
        QString cmd1 = "su - "+user+" -c \"ffmpeg -f alsa -i pulse -ac 2 -ab 128k -y %1\"";
        cmd1=cmd1.arg(PathI);
        comandos<< cmd1;
        mib = new DrakeProcesos1(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count();
        mib->Valor(valor,4);
        mib->iniciarProceso();
        ControlRec->stop();
        ControlFin = new QTimer(this);
        connect(ControlFin, SIGNAL(timeout()), this, SLOT(CtrlFin()));
        ControlFin->start(1000);
        Control = 1;
    }
}

void Grabador::CtrlFin()
{
    QDateTime FechaInicio = QDateTime::currentDateTime();
    if (Final <= FechaInicio)
    {
        this->KillProceso();
        system("killall firefox");
        ControlFin->stop();
        Control = 0;
        ui->tableWidget->removeRow(0);
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
        int Total = ui->tableWidget->rowCount();
        if (Total > 0)
        {
            ui->pushButton_13->setEnabled(true);
            this->EjecutarTempo();
        }
        else
        {
            ui->pushButton_13->setText(tr("Iniciar temporizador"));
            ui->pushButton_13->setEnabled(false);
        }
    }
}
