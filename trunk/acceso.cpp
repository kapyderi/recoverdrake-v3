#include "acceso.h"
#include "ui_acceso.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include "stdio.h"
#include "recoverdrake.h"
#include "ui_recoverdrake.h"
#include "drakesistema.h"
#include <QDateTime>
#include <QMessageBox>
#include <QToolTip>
#include <QPoint>
#include <password.h>
#include "notas.h"
#include <QFile>
#include <QInputDialog>
#include <QShortcut>
#include <QDebug>
#include <QTest>
#include <QDesktopWidget>
#include <QTranslator>

extern QTranslator *qTranslator;

acceso::acceso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::acceso)
{
    ui->setupUi(this);    
    ui->checkBox->hide();
    connect(ui->checkBox,SIGNAL(clicked()),this,SLOT(Comprobar()));
    db=QSqlDatabase::database("PRINCIPAL");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(hora()));
    timer->start(1000);
    Stilo = "B";
    QString cantidad43, cantidad44;
    QSqlQuery query41(db);
    query41.exec("SELECT spanish FROM Idioma WHERE id=2");
    query41.first();
    if (query41.isValid())
        cantidad43=query41.value(0).toString();
    QSqlQuery query42(db);
    query42.exec("SELECT english FROM Idioma WHERE id=2");
    query42.first();
    if (query42.isValid())
        cantidad44=query42.value(0).toString();
    if ( cantidad43 == "2")
    {
        ui->radioButton->setChecked(true);
        ui->radioButton_2->setChecked(false);
        QLocale::setDefault(QLocale(QLocale::Spanish,QLocale::Spain));
    }
    else if ( cantidad44 == "2")
    {
        ui->radioButton->setChecked(false);
        ui->radioButton_2->setChecked(true);
        QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
    }
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Spanish()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(English()));
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
        setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    }
    Valor = 0;
    Serial=getSerial();
    ui->label_18->setText(tr("UUID: ")+Serial+"");
    QString UUID = calculo(Serial);
    QFile file1("/usr/share/RecoverDrake/.Registro.ini");
    file1.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in1(&file1);
    QString ValorReg = in1.readAll();
    file1.close();
    if (UUID != ValorReg)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No coincide el equipo con la copia registrada. Se continua con limitaciones o deberas registrar la copia."));
        m.exec();
        Limitacion = 0;
    }
    else
        Limitacion = 1;
    notas *acc=new notas();
    Ver=acc->Ultimo;
    qsrand(QTime::currentTime().msec());
    if (Limitacion == 0)
    {
        ramdomize();
        QSqlQuery dato(db);
        dato.first();
        dato.exec("UPDATE Registro SET serie='"+Clave+"'");
        ui->label_12->setText(tr("<FONT COLOR=\"RED\">Copia no registrada."));
        Registro = 0;
        ui->label_11->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
        ui->label_11->setScaledContents(true);
        ui->label_11->adjustSize();
        QString Serie;
        QSqlQuery serial(db);
        serial.exec("SELECT Serie FROM Registro");
        serial.first();
        if(serial.isSelect())
            Serie = serial.value(0).toString();
        ui->label_9->setText(Serie);
        ui->pushButton_4->setText(tr("Generar clave"));
        ContraClave = "0";
        Clav = "1";
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+""); m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Se ha generado un numero de serie y debes tener una clave valida para poder continuar sin limitaciones.<p>Solo tienes que generar una nueva y registrarla, con el boton correspondiente."));
        m.exec();
        ui->groupBox_3->show();
        QString Posicion;
        QString Dat;
        QSqlQuery datoReg(db);
        datoReg.exec("SELECT Dato FROM Registro");
        datoReg.first();
        if (datoReg.isSelect())
            Dat = datoReg.value(0).toString();
        if (Dat == "0")
            Posicion = "etc";
        else if (Dat == "1")
            Posicion = "bin";
        else if (Dat == "2")
            Posicion = "usr";
        else if (Dat == "3")
            Posicion = "lib";
        else if (Dat == "4")
            Posicion = "var";
        system("rm /"+Posicion+"/.RecReg.ini");
    }
    else
    {
        QString Serie;
        QSqlQuery serial(db);
        serial.exec("SELECT Serie FROM Registro");
        serial.first();
        if (serial.isValid())
            Serie = serial.value(0).toString();
        if (Serie == "")
        {
            ramdomize();
            QSqlQuery dato(db);
            dato.first();
            dato.exec("UPDATE Registro SET serie='"+Clave+"'");
            ui->label_12->setText(tr("<FONT COLOR=\"RED\">Copia no registrada."));
            Registro = 0;
            ui->label_11->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
            ui->label_11->setScaledContents(true);
            ui->label_11->adjustSize();
            QString Serie;
            QSqlQuery serial(db);
            serial.exec("SELECT Serie FROM Registro");
            serial.first();
            if(serial.isSelect())
                Serie = serial.value(0).toString();
            ui->label_9->setText(Serie);
            ui->pushButton_4->setText(tr("Generar clave"));
            ContraClave = "0";
            Clav = "1";
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+""); m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Se ha generado un numero de serie y debes tener una clave valida para poder continuar sin limitaciones.<p>Solo tienes que generar una nueva y registrarla, con el boton correspondiente."));
            m.exec();
            ui->groupBox_3->show();
            Limitacion = 0;
        }
        else if (Serie !="")
        {

            QString Dato = calculo(Serie);
            QString datoslst, Posicion;
            QString Dat;
            QSqlQuery dato(db);
            dato.exec("SELECT Dato FROM Registro");
            dato.first();
            if (dato.isSelect())
                Dat = dato.value(0).toString();
            if (Dat == "0")
                Posicion = "etc";
            else if (Dat == "1")
                Posicion = "bin";
            else if (Dat == "2")
                Posicion = "usr";
            else if (Dat == "3")
                Posicion = "lib";
            else if (Dat == "4")
                Posicion = "var";
            QFile file("/"+Posicion+"/.RecReg.ini");
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                ContraClave = "0";
                Clav = "1";
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("No hay clave de registro todavia y debes tener una clave valida para poder continuar sin limitaciones.<p>Solo tienes que generar una nueva y registrarla con el boton correspondiente."));
                m.exec();
                ui->label_12->setText(tr("<FONT COLOR=\"RED\">Copia no registrada."));
                Registro = 0;
                ui->pushButton_4->setText(tr("Generar clave"));
                ui->label_11->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
                ui->label_11->setScaledContents(true);
                ui->label_11->adjustSize();
                ui->groupBox_3->show();
            }
            else
            {
                file.open(QIODevice::ReadOnly | QIODevice::Text);
                QTextStream in(&file);
                datoslst = in.readAll();
                file.close();
                if (Dato == datoslst)
                {
                    ContraClave = calculo(datoslst);
                    QSqlQuery clave(db);
                    clave.exec("SELECT clave FROM Registro");
                    clave.first();
                    if (clave.isSelect())
                        Clav = clave.value(0).toString();
                    if (ContraClave == Clav)
                    {
                        ui->lineEdit->setText(ContraClave);
                        ui->label_12->setText(tr("<FONT COLOR=\"BLUE\">Copia registrada."));
                        Registro = 1;
                        ui->lineEdit->setEnabled(false);
                        ui->pushButton_4->hide();
                        ui->label_11->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/good.png")));
                        ui->label_11->setScaledContents(true);
                        ui->label_11->adjustSize();
                        ui->groupBox_3->hide();
                    }
                    else
                    {
                        QMessageBox m;
                        if (Stilo == "A")
                            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                        m.setText(tr("La clave de registro no coincide con la de tu ordenador.<p>Debes tener una clave valida para poder continuar sin limitaciones.<p>Solo tienes que generar una nueva y registrarla con el boton correspondiente para que todo vuelva a lo suyo."));
                        m.exec();
                        ui->label_12->setText(tr("<FONT COLOR=\"RED\">Copia no registrada."));
                        Registro = 0;
                        ui->pushButton_4->setText(tr("Generar clave"));
                        ui->label_11->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
                        ui->label_11->setScaledContents(true);
                        ui->label_11->adjustSize();
                        ui->groupBox_3->show();
                    }
                }
                else if (Dato != datoslst)
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("La clave de registro no coincide con la de tu ordenador.<p>Debes tener una clave valida para poder continuar sin limitaciones.<p>Solo tienes que generar una nueva y registrarla con el boton correspondiente para que todo vuelva a lo suyo."));
                    m.exec();
                    ui->label_12->setText(tr("<FONT COLOR=\"RED\">Copia no registrada."));
                    Registro = 0;
                    ui->pushButton_4->setText(tr("Generar clave"));
                    ui->label_11->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
                    ui->label_11->setScaledContents(true);
                    ui->label_11->adjustSize();
                    ui->groupBox_3->show();
                }
            }
            ui->label_9->setText(Serie);
        }
    }
    this->contador=0;
    this->tecla();
    this->User(); 
    this->setWindowFlags(Qt::Window|Qt::CustomizeWindowHint|Qt::WindowTitleHint);
    drakeSistema drake;
    Distro = drake.getDistrop();
    Nucleo = drake.getNucleo();
    ui->label_4->setText(tr(Distro));
    ui->label_6->setText(tr(Ver));
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+K+P"), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(Mostrar()));    
    connect(ui->checkBox_2, SIGNAL(clicked()), this, SLOT(Mostrar1()));
    this->adjustSize();
    this->installEventFilter(this);
    QDesktopWidget screen;
    QRect screenGeom = screen.screenGeometry(this);
    int screenCenterX = screenGeom.center().x();
    int screenCenterY = screenGeom.center().y();
    move(screenCenterX - width () / 2, screenCenterY - height() / 2);
}

acceso::~acceso()
{
    delete ui;
}

void acceso::changeEvent(QEvent *e)
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

void acceso::keyPressEvent( QKeyEvent* e )
{
  switch ( e->key() )
  {
     case Qt::Key_CapsLock:
      if (CapsLock == "on")
      {          
          CapsLock = "off";
          ui->label_16->setFrameShadow(QFrame::Sunken);
          ui->label_16->setText(tr("minusculas"));
          ui->label_16->setEnabled(false);
          CapsLock = "off";
      }
      else if (CapsLock == "off")
      {
           ui->label_16->setFrameShadow(QFrame::Raised);
           ui->label_16->setText(tr("MAYUSCULAS"));
           ui->label_16->setEnabled(true);
           CapsLock = "on";
      }
      break;
     default:
        QDialog::keyPressEvent( e );
        break;
  }
}

void acceso::User()
{
    QString Spain, English;
    QSqlQuery querySpain(db);
    querySpain.exec("SELECT spanish FROM Idioma WHERE id='2'");
    querySpain.first();
    if (querySpain.isSelect())
        Spain=querySpain.value(0).toString();
    QSqlQuery queryEnglish(db);
    queryEnglish.exec("SELECT english FROM Idioma WHERE id='2'");
    queryEnglish.first();
    if (queryEnglish.isSelect())
        English=queryEnglish.value(0).toString();
    QString idioma;
    if ( Spain == "2")
    {
        idioma = "es";
    }
    else if ( English == "2")
    {
        idioma = "en";
    }
    QSqlQuery clave(db);
    clave.exec("SELECT clave FROM Registro");
    clave.first();
    if (clave.isSelect())
        Clav = clave.value(0).toString();
    if (ContraClave == Clav && Limitacion == 1)
    {
        ui->comboBox->clear();
        if (ui->checkBox->isChecked() == false)
        {
            QSqlQuery Variable(db);
            Variable.exec("SELECT Usuario,Activo FROM Acceso WHERE Activo LIKE '2' AND Usuario != 'kapyderi'");
            while(Variable.next())
            {
                ui->comboBox->addItem(Variable.value(0).toString());
            }
            QSqlQuery Control(db);
            Control.exec("SELECT Usuario,Fecha_Ingreso FROM control WHERE Usuario != 'kapyderi'");
            Control.last();
            QString control=Control.value(0).toString();
            QString Acceso=Control.value(1).toString();
            if (control != "")
            {
                ui->comboBox->setCurrentIndex(ui->comboBox->findText(control));
                ui->label_14->setText(Acceso);
            }
        }
        else if (ui->checkBox->isChecked() == true)
        {
            QSqlQuery Variable(db);
            Variable.exec("SELECT Usuario,Activo FROM Acceso WHERE Activo LIKE '2'");
            while(Variable.next())
            {
                ui->comboBox->addItem(Variable.value(0).toString());
            }
            QSqlQuery Control(db);
            Control.exec("SELECT Usuario,Fecha_Ingreso FROM control");
            Control.last();
            QString control=Control.value(0).toString();
            QString Acceso=Control.value(1).toString();
            if (control != "")
            {
                ui->comboBox->setCurrentIndex(ui->comboBox->findText(control));
                ui->label_14->setText(Acceso);
            }
        }
    }
    else if (ContraClave != Clav || Limitacion == 0)
    {
        if (ui->checkBox->isChecked() == false)
        {
            ui->comboBox->clear();
            QSqlQuery Variable(db);
            Variable.exec("SELECT Usuario,Activo,Nivel FROM Acceso WHERE Activo LIKE '2' and Nivel LIKE '1' AND Usuario != 'kapyderi'");
            while(Variable.next())
            {
                ui->comboBox->addItem(Variable.value(0).toString());
            }
        }
        else if (ui->checkBox->isChecked() == true)
        {
            ui->comboBox->clear();
            QSqlQuery Variable(db);
            Variable.exec("SELECT Usuario,Activo,Nivel FROM Acceso WHERE Activo LIKE '2' and Nivel LIKE '1'");
            while(Variable.next())
            {
                ui->comboBox->addItem(Variable.value(0).toString());
            }
        }
    }
    QSqlQuery query1(db);
    query1.exec("SELECT Usuario FROM Acceso WHERE Usuario='admin' AND Activo='0'");
    query1.first();
    if (query1.isSelect())
        Nivel=query1.value(0).toString();
    if (Nivel == "admin")
    {
        ui->label_2->setVisible(false);
        if (idioma == "en")
        {
            ui->label_6->setText(tr(Ver));
            ui->groupBox_2->setTitle(QString::fromUtf8(tr("Password")));
            ui->pushButton_3->setText("Forgot your password?");
        }
        else
        {
            ui->groupBox_2->setTitle(QString::fromUtf8(tr("Contrasena")));
        }
    }
    else
    {
        if (idioma == "en")
        {
            ui->label_6->setText(tr(Ver));
            ui->groupBox_2->setTitle(QString::fromUtf8(tr("Password (**)")));
            ui->pushButton_3->setText("Forgot your password?");
        }
    }
}

void acceso::tecla()
{
    QString Caps = getCaps();
    QStringList Capslock = Caps.split("0");
    for (int a=0;a<Capslock.count();a++)
    {
        QString Value = Capslock.value(a);
        if (Value.contains("Caps Lock"))
        {
            if (Value.contains("off"))
                CapsLock = "off";
            else if (Value.contains("on"))
                CapsLock = "on";
        }
    }
    if (CapsLock == "on")
    {
        ui->label_16->setFrameShadow(QFrame::Raised);
        ui->label_16->setText(tr("MAYUSCULAS"));
        ui->label_16->setEnabled(true);
    }
    else
    {
        ui->label_16->setFrameShadow(QFrame::Sunken);
        ui->label_16->setText(tr("minusculas"));
        ui->label_16->setEnabled(false);
    }
}

QString acceso::getCaps()
{
    QProcess *procesoXset, *procesoGrep;
    QStringList argumentosXset;
    QStringList argumentosGrep;
    QByteArray TipCaps;
    procesoXset=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosXset << "q";
    argumentosGrep << "Caps Lock";
    procesoXset->setStandardOutputProcess(procesoGrep);
    procesoXset->start("xset",argumentosXset);
    procesoGrep->start("grep",argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoXset->waitForFinished();
    procesoGrep->waitForFinished();
    TipCaps = QString(procesoGrep->readAllStandardOutput());
    delete procesoXset;
    delete procesoGrep;
    QString res = QString(TipCaps);
    res.chop(1);
    return res;
}

void acceso::on_pushButton_clicked()
{   
    QString numero;
    int power=2;
    power=power-contador;
    numero=QString::number(power);
    QSqlQuery query(db);
    query.exec("select * from Acceso where Usuario='"+ui->comboBox->currentText()+"' and Clave='"+ui->lineEdit_2->text()+"'");
    if( query.first() )
    {
            if (ui->checkBox->isChecked() == true)
            {
                bool ok;
                QString Clave;
                Clave = QInputDialog::getText(this, QString::fromUtf8(tr("Clave de Administrador")),
                QString::fromUtf8(tr("Introduce la clave de administrador.<P> ")),
                QLineEdit::Password,
                "",&ok);
                if (Clave.isEmpty())
                    return;
                if (ok && !Clave.isEmpty())
                {
                    if (Clave != "4Rimas")
                    {
                        QMessageBox m;
                        if (Stilo == "A")
                            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                        m.setText(tr("La clave introducida no concuerda con la del Administrador. No se puede continuar..."));
                        m.exec();
                        return;
                    }
                }
                else
                {
                    return;
                }
            }
            this->correcto=true;
            QSqlQuery mod(db);
            mod.prepare("INSERT INTO Control (Usuario,Fecha_Ingreso,Version,Nucleo)"
                        "VALUES (:User, :Fecha, :Version, :Nucleo)");
            mod.bindValue(":User", ui->comboBox->currentText());
            mod.bindValue(":Fecha", QDateTime::currentDateTime());
            mod.bindValue(":Version", Ver);
            mod.bindValue(":Nucleo", Nucleo);
            mod.exec();
            this->Usuar=ui->comboBox->currentText();          
            this->close();
            return;
    }
    else
    {
        contador++;
        int respuesta = 0;
        respuesta = QMessageBox::question(this, tr("Acceso no valido"),
                   tr("Al usuario <b>%1</b> se le ha introducido una clave incorrecta.<p>"
                   "Comprueba que los datos introducidos sean correctos.<p>"
                   "Te quedan %2 intentos de 3 posibles.<p>"
                   "&iquest;Probar otra vez?").arg(ui->comboBox->currentText()).arg(numero), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok)
        {
            ui->lineEdit_2->setText(tr(""));
            if(contador==3)
            {
                exit(0);
            }
            else
            {
                return;
            }
        }
        exit(0);
    }
}

void acceso::on_pushButton_2_clicked()
{
   exit(0);
}

void acceso::on_pushButton_3_clicked()
{
    password *Pass=new password(this);
    if (Stilo == "A")
        Pass->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    QString Valor;
    Valor = ui->comboBox->currentText();
    Pass->Dato(Valor);
    Pass->exec();
    QString Loc=Pass->Local;
    if (Loc == "")
    {
        return;
    }
    else if (Loc != "")
    {
        ui->lineEdit_2->setText(Loc);
    }
}

void acceso::on_comboBox_currentIndexChanged()
{
    if (ui->comboBox->currentText() == "invitado")
        ui->lineEdit_2->setText("invitado");
    else
        ui->lineEdit_2->setText("");
}

QString acceso::getSerial()
{
    QProcess *procesoXset;
    QStringList argumentosXset;
    QByteArray TipCaps;
    procesoXset=new QProcess(this);
    argumentosXset << "-s" << "system-uuid";
    procesoXset->start("dmidecode",argumentosXset);
    if (! procesoXset->waitForStarted())
        return QString("");
    procesoXset->waitForFinished();
    TipCaps = QString(procesoXset->readAllStandardOutput());
    delete procesoXset;
    QString res = QString(TipCaps);
    res.chop(1);
    return res;
}

QString acceso::calculo(QString Serie)
{
    Comp.clear();
    int dat,dato;
    QString Valor;
    QStringList Cambio;
    QStringList Calculo = Serie.split("");
    for (int a=1;a<Calculo.count()-1;a++)
    {
        QString Value = Calculo.value(a);
        if (Value == "0")
        {
            dat = ((Value.toInt()+8)*a)+Calculo.count();
            Cambio=QString::number(dat).split("");
            dato= Cambio.value(1).toInt()+Cambio.value(2).toInt()+Cambio.value(3).toInt();
            Valor = sustituir(dato);
        }
        else if (Value == "1")
        {
            dat = ((Value.toInt()+8)*a)+Calculo.count();
            Cambio=QString::number(dat).split("");
            dato= Cambio.value(1).toInt()+Cambio.value(2).toInt()+Cambio.value(3).toInt();
            Valor = sustituir(dato);
        }
        else if (Value == "2")
        {
            dat = ((Value.toInt()+8)*a)+Calculo.count();
            Cambio=QString::number(dat).split("");
            dato= Cambio.value(1).toInt()+Cambio.value(2).toInt()+Cambio.value(3).toInt();
            Valor = sustituir(dato);
        }
        else if (Value == "3")
        {
            dat = ((Value.toInt()+8)*a)+Calculo.count();
            Cambio=QString::number(dat).split("");
            dato= Cambio.value(1).toInt()+Cambio.value(2).toInt()+Cambio.value(3).toInt();
            Valor = sustituir(dato);
        }
        else if (Value == "4")
        {
            dat = ((Value.toInt()+8)*a)+Calculo.count();
            Cambio=QString::number(dat).split("");
            dato= Cambio.value(1).toInt()+Cambio.value(2).toInt()+Cambio.value(3).toInt();
            Valor = sustituir(dato);
        }
        else if (Value == "5")
        {
            dat = ((Value.toInt()+8)*a)+Calculo.count();
            Cambio=QString::number(dat).split("");
            dato= Cambio.value(1).toInt()+Cambio.value(2).toInt()+Cambio.value(3).toInt();
            Valor = sustituir(dato);
        }
        else if (Value == "6")
        {
            dat = ((Value.toInt()+8)*a)+Calculo.count();
            Cambio=QString::number(dat).split("");
            dato= Cambio.value(1).toInt()+Cambio.value(2).toInt()+Cambio.value(3).toInt();
            Valor = sustituir(dato);
        }
        else if (Value == "7")
        {
            dat = ((Value.toInt()+8)*a)+Calculo.count();
            Cambio=QString::number(dat).split("");
            dato= Cambio.value(1).toInt()+Cambio.value(2).toInt()+Cambio.value(3).toInt();
            Valor = sustituir(dato);
        }
        else if (Value == "8")
        {
            dat = ((Value.toInt()+8)*a)+Calculo.count();
            Cambio=QString::number(dat).split("");
            dato= Cambio.value(1).toInt()+Cambio.value(2).toInt()+Cambio.value(3).toInt();
            Valor = sustituir(dato);
        }
        else if (Value == "9")
        {
            dat = ((Value.toInt()+8)*a)+Calculo.count();
            Cambio=QString::number(dat).split("");
            dato= Cambio.value(1).toInt()+Cambio.value(2).toInt()+Cambio.value(3).toInt();
            Valor = sustituir(dato);
        }
        else
        {
            QString Receptor = sustituir1(Value);
            dat = ((Receptor.toInt()+8)*a)+Calculo.count();
            Cambio=QString::number(dat).split("");
            dato= Cambio.value(1).toInt();
            Valor = QString::number(dato);
        }
        Comp.append(Valor);
    }
    return Comp;
}

void acceso::on_pushButton_4_clicked()
{
    if (ui->pushButton_4->text() == tr("Generar clave"))
    {
        QString Posicion, Serie, Clave, Dat;
        QSqlQuery serial(db);
        serial.exec("SELECT Serie FROM Registro");
        serial.first();
        if (serial.isSelect())
        {
            Serie = serial.value(0).toString();
            Clave = calculo(Serie);
        }
        QSqlQuery dato(db);
        dato.exec("SELECT Dato FROM Registro");
        dato.first();
        if (dato.isSelect())
            Dat = dato.value(0).toString();
        if (Dat == "0")
            Posicion = "etc";
        else if (Dat == "1")
            Posicion = "bin";
        else if (Dat == "2")
            Posicion = "usr";
        else if (Dat == "3")
            Posicion = "lib";
        else if (Dat == "4")
            Posicion = "var";
        system("rm -vf /'"+Posicion+"'/.RecReg.ini");
        system("touch /'"+Posicion+"'/.RecReg.ini");
        QFile file("/"+Posicion+"/.RecReg.ini");
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream in(&file);
        in << ""+Clave+"";
        file.close();
        QString UUID = calculo(Serial);
        system("rm -vf /usr/share/RecoverDrake/.Registro.ini");
        system("touch /usr/share/RecoverDrake/.Registro.ini");
        QFile file1("/usr/share/RecoverDrake/.Registro.ini");
        file1.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream in1(&file1);
        in1 << ""+UUID+"";
        file1.close();
        ContraClave = calculo(Clave);
        ui->pushButton_4->setText(tr("Registrar"));
        ui->lineEdit->setText(ContraClave);
        ui->label_11->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/good.png")));
        Limitacion = 1;
    }
    else if (ui->pushButton_4->text() == tr("Registrar"))
    {
        ui->label_12->setText(tr("<FONT COLOR=\"BLUE\">Copia registrada"));
        Registro = 1;
        ui->lineEdit->setEnabled(false);
        ui->pushButton_4->hide();
        QSqlQuery dato(db);
        dato.first();
        dato.exec("UPDATE Registro SET Clave='"+ContraClave+"'");
        this->Mostrar1();
        this->User();
    }
}

void acceso::ramdomize()
{
    int num,num1,total,dato;
    QString Valor;
    dato = randInt(0,4);
    QSqlQuery dat(db);
    dat.first();
    dat.exec("UPDATE Registro SET Dato='"+QString::number(dato)+"'");
    total = randInt(18,45);
    for (int i=1;i<total;i++)
    {
        num=randInt(0,1);
        if (num == 0)
        {
            num1=randInt(0,9);
            Valor = QString::number(num1);
        }
        else if (num == 1)
        {
            num1=randInt(1,26);
            Valor = sustituir(num1);
        }
        Clave.append(Valor);
    }
    return;
}

int acceso::randInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

QString acceso::sustituir(int num1)
{
    QString valor;
    if (num1 == 1)
        valor = "A";
    if (num1 == 2)
        valor = "B";
    if (num1 == 3)
        valor = "C";
    if (num1 == 4)
        valor = "D";
    if (num1 == 5)
        valor = "E";
    if (num1 == 6)
        valor = "F";
    if (num1 == 7)
        valor = "G";
    if (num1 == 8)
        valor = "H";
    if (num1 == 9)
        valor = "I";
    if (num1 == 10)
        valor = "J";
    if (num1 == 11)
        valor = "K";
    if (num1 == 12)
        valor = "L";
    if (num1 == 13)
        valor = "M";
    if (num1 == 14)
        valor = "N";
    if (num1 == 15)
        valor = "O";
    if (num1 == 16)
        valor = "P";
    if (num1 == 17)
        valor = "Q";
    if (num1 == 18)
        valor = "R";
    if (num1 == 19)
        valor = "S";
    if (num1 == 20)
        valor = "T";
    if (num1 == 21)
        valor = "U";
    if (num1 == 22)
        valor = "V";
    if (num1 == 23)
        valor = "W";
    if (num1 == 24)
        valor = "X";
    if (num1 == 25)
        valor = "Y";
    if (num1 == 26)
        valor = "Z";
    return valor;
}

QString acceso::sustituir1(QString dato)
{
    QString valor;
    if (dato == "A")
        valor = 1;
    if (dato == "B")
        valor = 2;
    if (dato == "C")
        valor = 3;
    if (dato == "D")
        valor = 4;
    if (dato == "E")
        valor = 5;
    if (dato == "F")
        valor = 6;
    if (dato == "G")
        valor = 7;
    if (dato == "H")
        valor = 8;
    if (dato == "I")
        valor = 9;
    if (dato == "J")
        valor = 10;
    if (dato == "K")
        valor = 11;
    if (dato == "L")
        valor = 12;
    if (dato == "M")
        valor = 13;
    if (dato == "N")
        valor = 14;
    if (dato == "O")
        valor = 15;
    if (dato == "P")
        valor = 16;
    if (dato == "Q")
        valor = 17;
    if (dato == "R")
        valor = 18;
    if (dato == "S")
        valor = 19;
    if (dato == "T")
        valor = 20;
    if (dato == "U")
        valor = 21;
    if (dato == "V")
        valor = 22;
    if (dato == "W")
        valor = 23;
    if (dato == "X")
        valor = 24;
    if (dato == "Y")
        valor = 25;
    if (dato == "Z")
        valor = 26;
    return valor;
}

void acceso::Comprobar()
{
    QSqlQuery clave(db);
    clave.exec("SELECT clave FROM Registro");
    clave.first();
    if (clave.isSelect())
        Clav = clave.value(0).toString();
    if (ContraClave == Clav && Limitacion == 1)
    {
        ui->comboBox->clear();
        if (ui->checkBox->isChecked() == false)
        {
            QSqlQuery Variable(db);
            Variable.exec("SELECT Usuario,Activo FROM Acceso WHERE Activo LIKE '2' AND Usuario != 'kapyderi'");
            while(Variable.next())
            {
                ui->comboBox->addItem(Variable.value(0).toString());
            }
            QSqlQuery Control(db);
            Control.exec("SELECT Usuario,Fecha_Ingreso FROM control WHERE Usuario != 'kapyderi'");
            Control.last();
            QString control=Control.value(0).toString();
            QString Acceso=Control.value(1).toString();
            if (control != "")
            {
                ui->comboBox->setCurrentIndex(ui->comboBox->findText(control));
                ui->label_14->setText(Acceso);
            }
        }
        else if (ui->checkBox->isChecked() == true)
        {            
            QSqlQuery Variable(db);
            Variable.exec("SELECT Usuario,Activo FROM Acceso WHERE Activo LIKE '2'");
            while(Variable.next())
            {
                ui->comboBox->addItem(Variable.value(0).toString());                
            }
            QSqlQuery Control(db);
            Control.exec("SELECT Usuario,Fecha_Ingreso FROM control");
            Control.last();
            QString control=Control.value(0).toString();
            QString Acceso=Control.value(1).toString();
            if (control != "")
            {
                ui->comboBox->setCurrentIndex(ui->comboBox->findText(control));
                ui->label_14->setText(Acceso);
            }
        }
    }
    else if (ContraClave != Clav || Limitacion == 0)
    {
        if (ui->checkBox->isChecked() == false)
        {
            ui->comboBox->clear();
            QSqlQuery Variable(db);
            Variable.exec("SELECT Usuario,Activo,Nivel FROM Acceso WHERE Activo LIKE '2' and Nivel LIKE '1' AND Usuario != 'kapyderi'");
            while(Variable.next())
            {
                ui->comboBox->addItem(Variable.value(0).toString());
            }
        }
        else if (ui->checkBox->isChecked() == true)
        {
            ui->comboBox->clear();
            QSqlQuery Variable(db);
            Variable.exec("SELECT Usuario,Activo,Nivel FROM Acceso WHERE Activo LIKE '2' and Nivel LIKE '1'");
            while(Variable.next())
            {
                ui->comboBox->addItem(Variable.value(0).toString());
            }
        }
    }
}

void acceso::Mostrar()
{
    if (ui->checkBox->isHidden())
    {
        ui->checkBox->show();
        ui->checkBox->setChecked(true);
        this->adjustSize();
        ui->lineEdit_2->setFocus();
        ui->label_14->setText("");
        this->Comprobar();
    }
    else if (ui->checkBox->isShown())
    {
        ui->checkBox->hide();
        ui->checkBox->setChecked(false);
        this->adjustSize();
        ui->label_14->setText("");
        this->Comprobar();
    }
}

bool acceso::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Escape)
            {
                return true;
            }
        }        
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor("Acceso");
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void acceso::Mostrar1()
{
    if (ui->checkBox_2->isChecked())
    {
        ui->checkBox_2->setText(tr("Ocultar datos de registro"));
        ui->groupBox_3->show();
        this->adjustSize();
        QDesktopWidget screen;
        QRect screenGeom = screen.screenGeometry(this);
        int screenCenterX = screenGeom.center().x();
        int screenCenterY = screenGeom.center().y();
        move(screenCenterX - width () / 2, screenCenterY - height() / 2);
    }
    else
    {
        ui->checkBox_2->setText(tr("Mostrar datos de registro"));
        ui->groupBox_3->hide();
        this->adjustSize();
        QDesktopWidget screen;
        QRect screenGeom = screen.screenGeometry(this);
        int screenCenterX = screenGeom.center().x();
        int screenCenterY = screenGeom.center().y();
        move(screenCenterX - width () / 2, screenCenterY - height() / 2);
    }
}

void acceso::on_lineEdit_2_textChanged(QString Value)
{
    if (Valor == 0)
    {
        if (Value != "")
        {
            QChar ascii;
            int numero;
            ascii=Value.at(0).toAscii();
            numero=ascii.toAscii() ;
            if (numero >= 65 && numero <=90)
            {
                QMessageBox m;
                m.setWindowTitle(tr("Advertencia!!!"));
                m.setText(tr("El bloque de mayusculas esta activado."));
                m.exec();
                Valor = 1;
            }
        }
    }
}

void acceso::Spanish()
{
    Valor1 = ui->label_9->text();
    Valor4 = ui->label_4->text();
    if (ui->radioButton->isChecked())
    {
        qTranslator->load("/usr/share/RecoverDrake/RecoverDrake_es.qm", ".");        
        QLocale::setDefault(QLocale(QLocale::Spanish,QLocale::Spain));
        this->Cambiar();
    }
    QTest::qWait(20);
    QString Spain, English;
    QSqlQuery querySpain(db);
    querySpain.exec("SELECT spanish FROM Idioma WHERE id='2'");
    querySpain.first();
    if (querySpain.isSelect())
        Spain=querySpain.value(0).toString();
    QSqlQuery queryEnglish(db);
    queryEnglish.exec("SELECT english FROM Idioma WHERE id='2'");
    queryEnglish.first();
    if (queryEnglish.isSelect())
        English=queryEnglish.value(0).toString();
    QString idioma;
    if ( Spain == "2")
    {
        idioma = "es";
    }
    else if ( English == "2")
    {
        idioma = "en";
    }
    if (Nivel == "admin")
    {
        ui->label_2->setVisible(false);
        if (idioma == "en")
        {
            ui->label_6->setText(tr(Ver));
            ui->groupBox_2->setTitle(QString::fromUtf8(tr("Password")));
            ui->pushButton_3->setText("Forgot your password?");
            if (Registro == 1)
            {
                ui->label_12->setText(tr("<FONT COLOR=\"BLUE\">Registered copy."));
            }
            else if (Registro == 0)
            {
                ui->label_12->setText(tr("<FONT COLOR=\"RED\">Copy no registered."));
            }
            if (CapsLock == "on")
            {
                ui->label_16->setText(tr("UPPERCASE"));
            }
            else if (CapsLock == "off")
            {
                ui->label_16->setText(tr("lowercase"));
            }
        }
        else
        {
            ui->label_6->setText(tr(Ver));
            ui->groupBox_2->setTitle(QString::fromUtf8(tr("Contrasena")));
            if (CapsLock == "on")
            {
                ui->label_16->setText(tr("MAYUSCULAS"));
            }
            else if (CapsLock == "off")
            {
                ui->label_16->setText(tr("minusculas"));
            }
        }
    }
    else
    {
        if (idioma == "en")
        {
            ui->label_6->setText(tr(Ver));
            ui->groupBox_2->setTitle(QString::fromUtf8(tr("Password (**)")));
            ui->pushButton_3->setText("Forgot your password?");
            if (Registro == 1)
            {
                ui->label_12->setText(tr("<FONT COLOR=\"BLUE\">Registered copy."));
            }
            else if (Registro == 0)
            {
                ui->label_12->setText(tr("<FONT COLOR=\"RED\">Copy no registered."));
            }
            if (CapsLock == "on")
            {
                ui->label_16->setText(tr("UPPERCASE"));
            }
            else if (CapsLock == "off")
            {
                ui->label_16->setText(tr("lowercase"));
            }
        }
    }
    ui->label_9->setText(Valor1);
    ui->label_4->setText(Valor4);
    ui->label_18->setText(tr("UUID: ")+Serial+"");
    ui->pushButton_4->setText(tr("Generar clave"));
    this->adjustSize();
}

void acceso::English()
{
    Valor1 = ui->label_9->text();
    Valor4 = ui->label_4->text();
    if (ui->radioButton_2->isChecked())
    {
        qTranslator->load("/usr/share/RecoverDrake/RecoverDrake_en.qm", ".");
        QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
        this->Cambiar();
    }    
    QTest::qWait(20);
    QString Spain, English;
    QSqlQuery querySpain(db);
    querySpain.exec("SELECT spanish FROM Idioma WHERE id='2'");
    querySpain.first();
    if (querySpain.isSelect())
        Spain=querySpain.value(0).toString();
    QSqlQuery queryEnglish(db);
    queryEnglish.exec("SELECT english FROM Idioma WHERE id='2'");
    queryEnglish.first();
    if (queryEnglish.isSelect())
        English=queryEnglish.value(0).toString();
    QString idioma;
    if ( Spain == "2")
    {
        idioma = "es";
    }
    else if ( English == "2")
    {
        idioma = "en";
    }
    if (Nivel == "admin")
    {
        ui->label_2->setVisible(false);
        if (idioma == "en")
        {
            ui->label_6->setText(tr(Ver));
            ui->groupBox_2->setTitle(QString::fromUtf8(tr("Password")));
            ui->pushButton_3->setText("Forgot your password?");
            if (Registro == 1)
            {
                ui->label_12->setText(tr("<FONT COLOR=\"BLUE\">Registered copy."));
            }
            else if (Registro == 0)
            {
                ui->label_12->setText(tr("<FONT COLOR=\"RED\">Copy no registered."));
            }
            if (CapsLock == "on")
            {
                ui->label_16->setText(tr("UPPERCASE"));
            }
            else if (CapsLock == "off")
            {
                ui->label_16->setText(tr("lowercase"));
            }
        }
        else
        {
            ui->label_6->setText(tr(Ver));
            ui->groupBox_2->setTitle(QString::fromUtf8(tr("Contrasena")));
            if (CapsLock == "on")
            {
                ui->label_16->setText(tr("MAYUSCULAS"));
            }
            else if (CapsLock == "off")
            {
                ui->label_16->setText(tr("minusculas"));
            }
        }
    }
    else
    {
        if (idioma == "en")
        {
            ui->label_6->setText(tr(Ver));
            ui->groupBox_2->setTitle(QString::fromUtf8(tr("Password (**)")));
            ui->pushButton_3->setText("Forgot your password?");
            if (Registro == 1)
            {
                ui->label_12->setText(tr("<FONT COLOR=\"BLUE\">Registered copy."));
            }
            else if (Registro == 0)
            {
                ui->label_12->setText(tr("<FONT COLOR=\"RED\">Copy no registered."));
            }
            if (CapsLock == "on")
            {
                ui->label_16->setText(tr("UPPERCASE"));
            }
            else if (CapsLock == "off")
            {
                ui->label_16->setText(tr("lowercase"));
            }
        }
    }
    ui->label_9->setText(Valor1);
    ui->label_4->setText(Valor4);
    ui->label_18->setText(tr("UUID: ")+Serial+"");
    ui->pushButton_4->setText(tr("Generar clave"));
    this->adjustSize();
}

void acceso::Cambiar()
{
    QString cantidad25, Spanish, England;
    QSqlQuery queryIdioma(db);
    queryIdioma.exec("SELECT id FROM Idioma WHERE id=2");
    queryIdioma.first();
    if (queryIdioma.isValid())
        cantidad25=queryIdioma.value(0).toString();
    if (cantidad25 == "2")
    {
        if(ui->radioButton->isChecked())
        {
            Spanish = "2";
            England = "0";
        }
        else if(ui->radioButton_2->isChecked())
        {
            Spanish = "0";
            England = "2";
        }
        QSqlQuery Idioma(db);
        Idioma.exec("UPDATE Idioma SET spanish='"+Spanish+"',english='"+England+"' WHERE id=2");
    }
}

void acceso::hora()
{
    if (ui->radioButton->isChecked())
    {
        QDateTime time =QDateTime::currentDateTime();
        QString hora = time.toString("dd/MM/yyyy hh:mm:ss");
        ui->label_19->setText(hora);
    }
    else if (ui->radioButton_2->isChecked())
    {
        QDateTime time =QDateTime::currentDateTime();
        QString hora = time.toString("MM/dd/yyyy hh:mm:ss");
        ui->label_19->setText(hora);
    }

}
