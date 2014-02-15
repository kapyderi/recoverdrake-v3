#include "backup.h"
#include "ui_backup.h"
#include "drakesistema.h"
#include <QDate>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QProgressDialog>
#include <QSqlQuery>
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTest>

Backup::Backup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Backup)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    DB=QSqlDatabase::database("COMPARA");
    drakeSistema drake;
    user = drake.getUser();
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_5,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_6,SIGNAL(clicked()),this,SLOT(Comprobar()));
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
    ui->lineEdit->setVisible(false);
    ui->pushButton_4->setVisible(false);
    connect(ui->radioButton_7,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_8,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    ui->tabWidget->setCurrentIndex(0);
    ui->comboBox->setVisible(true);
    ui->lineEdit->setVisible(false);
    ui->pushButton_4->setVisible(false);
    this->installEventFilter(this);
    CierreTotal = 0;
}

Backup::~Backup()
{
    delete ui;
}

void Backup::Valor(QString valor)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
}

void Backup::on_pushButton_clicked()
{    
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void Backup::closeEvent ( QCloseEvent * event )
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

void Backup::Comprobar()
{
    if (ui->radioButton->isChecked() == true)
    {
        ui->groupBox_2->setEnabled(true);
        ui->groupBox_3->setEnabled(false);
    }
    if (ui->radioButton_2->isChecked() == true)
    {
        ui->groupBox_2->setEnabled(false);
        ui->groupBox_3->setEnabled(true);
    }
    if (ui->radioButton_3->isChecked() == true)
    {
        ui->groupBox_2->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
    }
    if (ui->radioButton_4->isChecked() == true)
    {
        ui->groupBox_6->setEnabled(true);
        ui->groupBox_5->setEnabled(false);
    }
    if (ui->radioButton_5->isChecked() == true)
    {
        ui->groupBox_6->setEnabled(false);
        ui->groupBox_5->setEnabled(true);
    }
    if (ui->radioButton_6->isChecked() == true)
    {
        ui->groupBox_6->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
    }
}

void Backup::Comprobar1()
{
    if (ui->radioButton_7->isChecked())
    {
        ui->comboBox->setVisible(true);
        ui->lineEdit->setVisible(false);
        ui->pushButton_4->setVisible(false);
        ui->comboBox->clear();
        QString Valor= "~";
        QString Value;
        drakeSistema drake;
        Backp = drake.getBackup();
        QStringList Bkp = Backp.split("\n");
        for(int i=0;i<Bkp.count();i++)
        {
            Value = Bkp.value(i);
            Value = Value.remove("/usr/share/RecoverDrake/backup/");
            int Desestima = Value.indexOf(Valor,0);
            if (Desestima == -1)
                ui->comboBox->addItem(Value);
        }
        if (Backp == "")
        {
            ui->pushButton_3->setEnabled(false);
            ui->pushButton_5->setEnabled(false);
        }
    }
    if (ui->radioButton_8->isChecked())
    {
        ui->comboBox->setVisible(false);
        ui->lineEdit->setVisible(true);
        ui->pushButton_4->setVisible(true);
    }
}

void Backup::on_pushButton_2_clicked()
{    
    QString Fecha = QDateTime::currentDateTime().toString("dd-MM-yyyy_hh.mm.ss");
    QString Nombre = "BackupRD";
    QString path=tr("/home/%1/Documentos/%2%3.sqlite");
    path=path.arg(user).arg(Nombre).arg(Fecha);
    QString fileNameDestino = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar archivo .sqlite")),
                        path,trUtf8(tr("Archivo .sqlite (*.sqlite)")));
    if (fileNameDestino.isEmpty())
         return;
    QString fileName = fileNameDestino.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)").replace(".sqlite","");
    system("mkdir -pv /usr/share/RecoverDrake/backup/");
    QProgressDialog progress("Creando copia... Espera por favor", "Cancelar", 0, 47);
    if (Stilo == "A")
        progress.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    progress.setWindowModality(Qt::WindowModal);
    progress.show();
    QTest::qWait(20);
    for(int i=0;i<47;i++ )
    {
        progress.setValue(i);
        if (progress.wasCanceled())
            break;
        if ( i == 0)
        {
            QFile file("/usr/share/RecoverDrake/backup/BackupRD"+Fecha+".cfg");
            file.open(QIODevice::WriteOnly | QIODevice::Truncate);
            QTextStream in(&file);
            in << "Ruta: "+fileName+".sqlite" << "\n";
            if (ui->radioButton_2->isChecked() == true)
            {
                in << "Copia: Datos" << "\n";
                in << "Corte: No" << "\n";
                in << "Eth: No" << "\n";
                in << "Idioma: No" << "\n";
                in << "Video: No" << "\n";
                in << "Fuente: No" << "\n";
                in << "Red: No" << "\n";
                in << "Miscelanea: No" << "\n";
                in << "Color: No" << "\n";
                in << "ConvAudio: No" << "\n";
                in << "Cancion: No" << "\n";
                in << "Canal: No" << "\n";
                in << "Radio: No" << "\n";
                in << "Registro: No" << "\n";
                in << "TamCorte: No" << "\n";
                in << "Correo: No" << "\n";
                in << "Skin: No" << "\n";
                in << "Velocidad: No" << "\n";
                in << "Vnc: No" << "\n";
                in << "Resolucion: No" << "\n";
                in << "Grabacion: No" << "\n";
                in << "Wifi: No" << "\n";
                in << "Control: No" << "\n";
                in << "Menu: No" << "\n";
                in << "Chat: No" << "\n";
                in << "Vista: No" << "\n";
                in << "SVideo: No" << "\n";
                in << "Formato: No" << "\n";
                in << "Estilo: No" << "\n";
                in << "Ecualizador: No" << "\n";
                in << "Calculadora: No" << "\n";
                in << "Pais: No" << "\n";
                if (ui->checkBox_7->isChecked() == true)
                    LClave="Si";
                else if (ui->checkBox_7->isChecked() == false)
                    LClave="No";
                in << "LClave: "+LClave+"" << "\n";
                if (ui->checkBox_5->isChecked() == true)
                    LNwifi="Si";
                else if (ui->checkBox_5->isChecked() == false)
                    LNwifi="No";
                in << "LNwifi: "+LNwifi+"" << "\n";
                if (ui->checkBox_24->isChecked() == true)
                    LMusica="Si";
                else if (ui->checkBox_24->isChecked() == false)
                    LMusica="No";
                in << "LMusica: "+LMusica+"" << "\n";
                if (ui->checkBox_6->isChecked() == true)
                    LBwifi="Si";
                else if (ui->checkBox_6->isChecked() == false)
                    LBwifi="No";
                in << "LBwifi: "+LBwifi+"" << "\n";
                if (ui->checkBox_26->isChecked() == true)
                    LRadio="Si";
                else if (ui->checkBox_26->isChecked() == false)
                    LRadio="No";
                in << "LRadio: "+LRadio+"" << "\n";
                if (ui->checkBox_27->isChecked() == true)
                    LTelevision="Si";
                else if (ui->checkBox_27->isChecked() == false)
                    LTelevision="No";
                in << "LTelevision: "+LTelevision+"" << "\n";
                if (ui->checkBox_29->isChecked() == true)
                    LUser="Si";
                else if (ui->checkBox_29->isChecked() == false)
                    LUser="No";
                in << "LUser: "+LUser+"" << "\n";
                if (ui->checkBox_30->isChecked() == true)
                    LAccesos="Si";
                else if (ui->checkBox_30->isChecked() == false)
                    LAccesos="No";
                in << "LAccesos: "+LAccesos+"" << "\n";
                if (ui->checkBox_36->isChecked() == true)
                    LVnc="Si";
                else if (ui->checkBox_36->isChecked() == false)
                    LVnc="No";
                in << "LVnc: "+LVnc+"" << "\n";
                if (ui->checkBox_34->isChecked() == true)
                    LPelis="Si";
                else if (ui->checkBox_34->isChecked() == false)
                    LPelis="No";
                in << "LPelis: "+LPelis+"" << "\n";
                if (ui->checkBox_42->isChecked() == true)
                    LMenu="Si";
                else if (ui->checkBox_42->isChecked() == false)
                    LMenu="No";
                in << "LMenu: "+LMenu+"" << "\n";
                if (ui->checkBox_79->isChecked() == true)
                    LSincro="Si";
                else if (ui->checkBox_79->isChecked() == false)
                    LSincro="No";
                in << "LSincro: "+LSincro+"" << "\n";
                if (ui->checkBox_83->isChecked() == true)
                    Lid3="Si";
                else if (ui->checkBox_83->isChecked() == false)
                    Lid3="No";
                in << "Lid3: "+Lid3+"" << "\n";
                if (ui->checkBox_88->isChecked() == false)
                    LClaves="Si";
                else if (ui->checkBox_88->isChecked() == false)
                    LClaves="No";
                in << "LClaves: "+LClaves+"" << "\n";
                if (ui->checkBox_89->isChecked() == false)
                    LAscii="Si";
                else if (ui->checkBox_89->isChecked() == false)
                    LAscii="No";
                in << "LAscii: "+LAscii+"" << "\n";
                if (ui->checkBox_93->isChecked() == false)
                    LBic="Si";
                else if (ui->checkBox_93->isChecked() == false)
                    LBic="No";
                in << "LBic: "+LBic+"" << "\n";
            }
            else if (ui->radioButton->isChecked() == true)
            {
                in << "Copia: Configuraciones" << "\n";
                if (ui->checkBox->isChecked() == true)
                    Corte="Si";
                else if (ui->checkBox->isChecked() == false)
                    Corte="No";
                in << "Corte: "+Corte+"" << "\n";
                if (ui->checkBox_2->isChecked() == true)
                    Eth="Si";
                else if (ui->checkBox_2->isChecked() == false)
                    Eth="No";
                in << "Eth: "+Eth+"" << "\n";
                if (ui->checkBox_4->isChecked() == true)
                    Idioma="Si";
                else if (ui->checkBox_4->isChecked() == false)
                    Idioma="No";
                in << "Idioma: "+Idioma+"" << "\n";
                if (ui->checkBox_8->isChecked() == true)
                    Video="Si";
                else if (ui->checkBox_8->isChecked() == false)
                    Video="No";
                in << "Video: "+Video+"" << "\n";
                if (ui->checkBox_17->isChecked() == true)
                    Fuente="Si";
                else if (ui->checkBox_17->isChecked() == false)
                    Fuente="No";
                in << "Fuente: "+Fuente+"" << "\n";
                if (ui->checkBox_3->isChecked() == true)
                    Red="Si";
                else if (ui->checkBox_3->isChecked() == false)
                    Red="No";
                in << "Red: "+Red+"" << "\n";
                if (ui->checkBox_21->isChecked() == true)
                    Miscelanea="Si";
                else if (ui->checkBox_21->isChecked() == false)
                    Miscelanea="No";
                in << "Miscelanea: "+Miscelanea+"" << "\n";
                if (ui->checkBox_20->isChecked() == true)
                    Color="Si";
                else if (ui->checkBox_20->isChecked() == false)
                    Color="No";
                in << "Color: "+Color+"" << "\n";
                if (ui->checkBox_22->isChecked() == true)
                    ConvAudio="Si";
                else if (ui->checkBox_22->isChecked() == false)
                    ConvAudio="No";
                in << "ConvAudio: "+ConvAudio+"" << "\n";
                if (ui->checkBox_23->isChecked() == true)
                    Cancion="Si";
                else if (ui->checkBox_23->isChecked() == false)
                    Cancion="No";
                in << "Cancion: "+Cancion+"" << "\n";
                if (ui->checkBox_28->isChecked() == true)
                    Canal="Si";
                else if (ui->checkBox_28->isChecked() == false)
                    Canal="No";
                in << "Canal: "+Canal+"" << "\n";
                if (ui->checkBox_25->isChecked() == true)
                    Radio="Si";
                else if (ui->checkBox_25->isChecked() == false)
                    Radio="No";
                in << "Radio: "+Radio+"" << "\n";
                if (ui->checkBox_35->isChecked() == true)
                    Registro="Si";
                else if (ui->checkBox_35->isChecked() == false)
                    Registro="No";
                in << "Registro: "+Registro+"" << "\n";
                if (ui->checkBox_32->isChecked() == true)
                    TamCorte="Si";
                else if (ui->checkBox_32->isChecked() == false)
                    TamCorte="No";
                in << "TamCorte: "+TamCorte+"" << "\n";
                if (ui->checkBox_38->isChecked() == true)
                    Correo="Si";
                else if (ui->checkBox_38->isChecked() == false)
                    Correo="No";
                in << "Correo: "+Correo+"" << "\n";
                if (ui->checkBox_33->isChecked() == true)
                    Skin="Si";
                else if (ui->checkBox_33->isChecked() == false)
                    Skin="No";
                in << "Skin: "+Skin+"" << "\n";
                if (ui->checkBox_40->isChecked() == true)
                    Velocidad="Si";
                else if (ui->checkBox_40->isChecked() == false)
                    Velocidad="No";
                in << "Velocidad: "+Velocidad+"" << "\n";
                if (ui->checkBox_37->isChecked() == true)
                    Vnc="Si";
                else if (ui->checkBox_37->isChecked() == false)
                    Vnc="No";
                in << "Vnc: "+Vnc+"" << "\n";
                if (ui->checkBox_41->isChecked() == true)
                    Resolucion="Si";
                else if (ui->checkBox_41->isChecked() == false)
                    Resolucion="No";
                in << "Resolucion: "+Resolucion+"" << "\n";
                if (ui->checkBox_39->isChecked() == true)
                    Grabacion="Si";
                else if (ui->checkBox_39->isChecked() == false)
                    Grabacion="No";
                in << "Grabacion: "+Grabacion+"" << "\n";
                if (ui->checkBox_44->isChecked() == true)
                    Wifi="Si";
                else if (ui->checkBox_44->isChecked() == false)
                    Wifi="No";
                in << "Wifi: "+Wifi+"" << "\n";
                if (ui->checkBox_43->isChecked() == true)
                    Control="Si";
                else if (ui->checkBox_43->isChecked() == false)
                    Control="No";
                in << "Control: "+Control+"" << "\n";
                if (ui->checkBox_45->isChecked() == true)
                    Menu="Si";
                else if (ui->checkBox_45->isChecked() == false)
                    Menu="No";
                in << "Menu: "+Menu+"" << "\n";
                if (ui->checkBox_19->isChecked() == true)
                    Chat="Si";
                else if (ui->checkBox_19->isChecked() == false)
                    Chat="No";
                in << "Chat: "+Chat+"" << "\n";
                if (ui->checkBox_71->isChecked() == true)
                    Vista="Si";
                else if (ui->checkBox_71->isChecked() == false)
                    Vista="No";
                in << "Vista: "+Vista+"" << "\n";
                if (ui->checkBox_73->isChecked() == true)
                    SVideo="Si";
                else if (ui->checkBox_73->isChecked() == false)
                    SVideo="No";
                in << "SVideo: "+SVideo+"" << "\n";
                if (ui->checkBox_75->isChecked() == true)
                    Formato="Si";
                else if (ui->checkBox_75->isChecked() == false)
                    Formato="No";
                in << "Formato: "+Formato+"" << "\n";
                if (ui->checkBox_77->isChecked() == true)
                    Estilo="Si";
                else if (ui->checkBox_77->isChecked() == false)
                    Estilo="No";
                in << "Estilo: "+Estilo+"" << "\n";
                if (ui->checkBox_81->isChecked() == true)
                    Ecualizador="Si";
                else if (ui->checkBox_81->isChecked() == false)
                    Ecualizador="No";
                in << "Ecualizador: "+Ecualizador+"" << "\n";
                if (ui->checkBox_86->isChecked() == true)
                    Calculadora="Si";
                else if (ui->checkBox_86->isChecked() == false)
                    Calculadora="No";
                in << "Calculadora: "+Calculadora+"" << "\n";
                if (ui->checkBox_91->isChecked() == true)
                    Pais="Si";
                else if (ui->checkBox_91->isChecked() == false)
                    Pais="No";
                in << "Pais: "+Pais+"" << "\n";
                in << "LClave: No" << "\n";
                in << "LNwifi: No" << "\n";
                in << "LMusica: No" << "\n";
                in << "LBwifi: No" << "\n";
                in << "LRadio: No" << "\n";
                in << "LTelevision: No" << "\n";
                in << "LUser: No" << "\n";
                in << "LAccesos: No" << "\n";
                in << "LVnc: No" << "\n";
                in << "LPelis: No" << "\n";
                in << "LMenu: No" << "\n";
                in << "LSincro: No" << "\n";
                in << "Lid3: No" << "\n";
                in << "LClaves: No" << "\n";
                in << "LAscii: No" << "\n";
                in << "LBic: No" << "\n";
            }
            else if (ui->radioButton_3->isChecked() == true)
            {
                in << "Copia: Todo" << "\n";
                if (ui->checkBox->isChecked() == true)
                    Corte="Si";
                else if (ui->checkBox->isChecked() == false)
                    Corte="No";
                in << "Corte: "+Corte+"" << "\n";
                if (ui->checkBox_2->isChecked() == true)
                    Eth="Si";
                else if (ui->checkBox_2->isChecked() == false)
                    Eth="No";
                in << "Eth: "+Eth+"" << "\n";
                if (ui->checkBox_4->isChecked() == true)
                    Idioma="Si";
                else if (ui->checkBox_4->isChecked() == false)
                    Idioma="No";
                in << "Idioma: "+Idioma+"" << "\n";
                if (ui->checkBox_8->isChecked() == true)
                    Video="Si";
                else if (ui->checkBox_8->isChecked() == false)
                    Video="No";
                in << "Video: "+Video+"" << "\n";
                if (ui->checkBox_17->isChecked() == true)
                    Fuente="Si";
                else if (ui->checkBox_17->isChecked() == false)
                    Fuente="No";
                in << "Fuente: "+Fuente+"" << "\n";
                if (ui->checkBox_3->isChecked() == true)
                    Red="Si";
                else if (ui->checkBox_3->isChecked() == false)
                    Red="No";
                in << "Red: "+Red+"" << "\n";
                if (ui->checkBox_21->isChecked() == true)
                    Miscelanea="Si";
                else if (ui->checkBox_21->isChecked() == false)
                    Miscelanea="No";
                in << "Miscelanea: "+Miscelanea+"" << "\n";
                if (ui->checkBox_20->isChecked() == true)
                    Color="Si";
                else if (ui->checkBox_20->isChecked() == false)
                    Color="No";
                in << "Color: "+Color+"" << "\n";
                if (ui->checkBox_22->isChecked() == true)
                    ConvAudio="Si";
                else if (ui->checkBox_22->isChecked() == false)
                    ConvAudio="No";
                in << "ConvAudio: "+ConvAudio+"" << "\n";
                if (ui->checkBox_23->isChecked() == true)
                    Cancion="Si";
                else if (ui->checkBox_23->isChecked() == false)
                    Cancion="No";
                in << "Cancion: "+Cancion+"" << "\n";
                if (ui->checkBox_28->isChecked() == true)
                    Canal="Si";
                else if (ui->checkBox_28->isChecked() == false)
                    Canal="No";
                in << "Canal: "+Canal+"" << "\n";
                if (ui->checkBox_25->isChecked() == true)
                    Radio="Si";
                else if (ui->checkBox_25->isChecked() == false)
                    Radio="No";
                in << "Radio: "+Radio+"" << "\n";
                if (ui->checkBox_35->isChecked() == true)
                    Registro="Si";
                else if (ui->checkBox_35->isChecked() == false)
                    Registro="No";
                in << "Registro: "+Registro+"" << "\n";
                if (ui->checkBox_32->isChecked() == true)
                    TamCorte="Si";
                else if (ui->checkBox_32->isChecked() == false)
                    TamCorte="No";
                in << "TamCorte: "+TamCorte+"" << "\n";
                if (ui->checkBox_38->isChecked() == true)
                    Correo="Si";
                else if (ui->checkBox_38->isChecked() == false)
                    Correo="No";
                in << "Correo: "+Correo+"" << "\n";
                if (ui->checkBox_33->isChecked() == true)
                    Skin="Si";
                else if (ui->checkBox_33->isChecked() == false)
                    Skin="No";
                in << "Skin: "+Skin+"" << "\n";
                if (ui->checkBox_40->isChecked() == true)
                    Velocidad="Si";
                else if (ui->checkBox_40->isChecked() == false)
                    Velocidad="No";
                in << "Velocidad: "+Velocidad+"" << "\n";
                if (ui->checkBox_37->isChecked() == true)
                    Vnc="Si";
                else if (ui->checkBox_37->isChecked() == false)
                    Vnc="No";
                in << "Vnc: "+Vnc+"" << "\n";
                if (ui->checkBox_41->isChecked() == true)
                    Resolucion="Si";
                else if (ui->checkBox_41->isChecked() == false)
                    Resolucion="No";
                in << "Resolucion: "+Resolucion+"" << "\n";
                if (ui->checkBox_39->isChecked() == true)
                    Grabacion="Si";
                else if (ui->checkBox_39->isChecked() == false)
                    Grabacion="No";
                in << "Grabacion: "+Grabacion+"" << "\n";
                if (ui->checkBox_44->isChecked() == true)
                    Wifi="Si";
                else if (ui->checkBox_44->isChecked() == false)
                    Wifi="No";
                in << "Wifi: "+Wifi+"" << "\n";
                if (ui->checkBox_43->isChecked() == true)
                    Control="Si";
                else if (ui->checkBox_43->isChecked() == false)
                    Control="No";
                in << "Control: "+Control+"" << "\n";
                if (ui->checkBox_45->isChecked() == true)
                    Menu="Si";
                else if (ui->checkBox_45->isChecked() == false)
                    Menu="No";
                in << "Menu: "+Menu+"" << "\n";
                if (ui->checkBox_19->isChecked() == true)
                    Chat="Si";
                else if (ui->checkBox_19->isChecked() == false)
                    Chat="No";
                in << "Chat: "+Chat+"" << "\n";
                if (ui->checkBox_71->isChecked() == true)
                    Vista="Si";
                else if (ui->checkBox_71->isChecked() == false)
                    Vista="No";
                in << "Vista: "+Vista+"" << "\n";
                if (ui->checkBox_73->isChecked() == true)
                    SVideo="Si";
                else if (ui->checkBox_73->isChecked() == false)
                    SVideo="No";
                in << "SVideo: "+SVideo+"" << "\n";
                if (ui->checkBox_75->isChecked() == true)
                    Formato="Si";
                else if (ui->checkBox_75->isChecked() == false)
                    Formato="No";
                in << "Formato: "+Formato+"" << "\n";
                if (ui->checkBox_77->isChecked() == true)
                    Estilo="Si";
                else if (ui->checkBox_77->isChecked() == false)
                    Estilo="No";
                in << "Estilo: "+Estilo+"" << "\n";
                if (ui->checkBox_81->isChecked() == true)
                    Ecualizador="Si";
                else if (ui->checkBox_81->isChecked() == false)
                    Ecualizador="No";
                in << "Ecualizador: "+Ecualizador+"" << "\n";
                if (ui->checkBox_86->isChecked() == true)
                    Calculadora="Si";
                else if (ui->checkBox_86->isChecked() == false)
                    Calculadora="No";
                in << "Calculadora: "+Calculadora+"" << "\n";
                if (ui->checkBox_91->isChecked() == true)
                    Pais="Si";
                else if (ui->checkBox_91->isChecked() == false)
                    Pais="No";
                in << "Pais: "+Pais+"" << "\n";
                if (ui->checkBox_7->isChecked() == true)
                    LClave="Si";
                else if (ui->checkBox_7->isChecked() == false)
                    LClave="No";
                in << "LClave: "+LClave+"" << "\n";
                if (ui->checkBox_5->isChecked() == true)
                    LNwifi="Si";
                else if (ui->checkBox_5->isChecked() == false)
                    LNwifi="No";
                in << "LNwifi: "+LNwifi+"" << "\n";
                if (ui->checkBox_24->isChecked() == true)
                    LMusica="Si";
                else if (ui->checkBox_24->isChecked() == false)
                    LMusica="No";
                in << "LMusica: "+LMusica+"" << "\n";
                if (ui->checkBox_6->isChecked() == true)
                    LBwifi="Si";
                else if (ui->checkBox_6->isChecked() == false)
                    LBwifi="No";
                in << "LBwifi: "+LBwifi+"" << "\n";
                if (ui->checkBox_26->isChecked() == true)
                    LRadio="Si";
                else if (ui->checkBox_26->isChecked() == false)
                    LRadio="No";
                in << "LRadio: "+LRadio+"" << "\n";
                if (ui->checkBox_27->isChecked() == true)
                    LTelevision="Si";
                else if (ui->checkBox_27->isChecked() == false)
                    LTelevision="No";
                in << "LTelevision: "+LTelevision+"" << "\n";
                if (ui->checkBox_29->isChecked() == true)
                    LUser="Si";
                else if (ui->checkBox_29->isChecked() == false)
                    LUser="No";
                in << "LUser: "+LUser+"" << "\n";
                if (ui->checkBox_30->isChecked() == true)
                    LAccesos="Si";
                else if (ui->checkBox_30->isChecked() == false)
                    LAccesos="No";
                in << "LAccesos: "+LAccesos+"" << "\n";
                if (ui->checkBox_36->isChecked() == true)
                    LVnc="Si";
                else if (ui->checkBox_36->isChecked() == false)
                    LVnc="No";
                in << "LVnc: "+LVnc+"" << "\n";
                if (ui->checkBox_34->isChecked() == true)
                    LPelis="Si";
                else if (ui->checkBox_34->isChecked() == false)
                    LPelis="No";
                in << "LPelis: "+LPelis+"" << "\n";
                if (ui->checkBox_42->isChecked() == true)
                    LMenu="Si";
                else if (ui->checkBox_42->isChecked() == false)
                    LMenu="No";
                in << "LMenu: "+LMenu+"" << "\n";
                if (ui->checkBox_79->isChecked() == true)
                    LSincro="Si";
                else if (ui->checkBox_79->isChecked() == false)
                    LSincro="No";
                in << "LSincro: "+LSincro+"" << "\n";
                if (ui->checkBox_83->isChecked() == true)
                    Lid3="Si";
                else if (ui->checkBox_83->isChecked() == false)
                    Lid3="No";
                in << "Lid3: "+Lid3+"" << "\n";
                if (ui->checkBox_88->isChecked() == false)
                    LClaves="Si";
                else if (ui->checkBox_88->isChecked() == false)
                    LClaves="No";
                in << "LClaves: "+LClaves+"" << "\n";
                if (ui->checkBox_89->isChecked() == false)
                    LAscii="Si";
                else if (ui->checkBox_89->isChecked() == false)
                    LAscii="No";
                in << "LAscii: "+LAscii+"" << "\n";
                if (ui->checkBox_93->isChecked() == false)
                    LBic="Si";
                else if (ui->checkBox_93->isChecked() == false)
                    LBic="No";
                in << "LBic: "+LBic+"" << "\n";
            }
            file.close();
        }
        system("cp /root/Miscelanea.RecoverDrake.db.sqlite "+fileName+".sqlite");
        DBackup = QSqlDatabase::addDatabase("QSQLITE","BACKUP");
        DBackup.setDatabaseName(fileName+".sqlite");
        if (!DBackup.open())
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("<b>Error grave</b>:<p>No se ha podido abrir la base de datos espejo necesaria.<p>Comprueba que existe en la ruta."));
            m.exec();
            return;
        }
        else
        {
            if (i == 1)
            {
                if (Eth == "Si")
                {
                    QString cantidad40;
                    QSqlQuery query38(db);
                    query38.exec("SELECT conexion FROM ethernet WHERE id=2");
                    query38.first();
                    if (query38.isValid())
                         cantidad40=query38.value(0).toString();
                    QSqlQuery ethernet(DBackup);
                    ethernet.exec("UPDATE ethernet SET conexion='"+cantidad40+"' WHERE id=2");
                }
            }
            if (i == 2)
            {
                if (Idioma=="Si")
                {
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
                    QSqlQuery Idioma(DBackup);
                    Idioma.exec("UPDATE Idioma SET spanish='"+cantidad43+"',english='"+cantidad44+"' WHERE id=2");
                }
            }
            if (i == 3)
            {
                if (Fuente=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45;
                    QSqlQuery query41(db);
                    query41.exec("SELECT Fuente FROM Font WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(db);
                    query42.exec("SELECT Estilo FROM Font WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(db);
                    query43.exec("SELECT Talla FROM Font WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery Font(DBackup);
                    Font.exec("UPDATE Font SET Fuente='"+cantidad43+"',Estilo='"+cantidad44+"',Talla='"+cantidad45+"' WHERE id=2");
                }
            }
            if (i == 4)
            {
                if (Red=="Si")
                {
                    QString cantidad41, cantidad42;
                    QSqlQuery query39(db);
                    query39.exec("SELECT ethernet FROM red WHERE id=2");
                    query39.first();
                    if (query39.isValid())
                         cantidad41=query39.value(0).toString();
                    QSqlQuery query40(db);
                    query40.exec("SELECT wifi FROM red WHERE id=2");
                    query40.first();
                    if (query40.isValid())
                         cantidad42=query40.value(0).toString();
                    QSqlQuery red(DBackup);
                    red.exec("UPDATE red SET ethernet='"+cantidad41+"',wifi='"+cantidad42+"' WHERE id=2");
                }
            }
            if (i == 5)
            {
                if (Miscelanea=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45;
                    QSqlQuery query41(db);
                    query41.exec("SELECT Defecto FROM Miscelanea WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(db);
                    query42.exec("SELECT inicio FROM Miscelanea WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(db);
                    query43.exec("SELECT Dependencias FROM Miscelanea WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE Miscelanea SET Defecto='"+cantidad43+"',inicio='"+cantidad44+"',Dependencias='"+cantidad45+"' WHERE id=2");
                }
            }
            if (i == 6)
            {
                if (Color=="Si")
                {
                    QString cantidad43, cantidad44;
                    QSqlQuery query41(db);
                    query41.exec("SELECT ColorTexto FROM Color WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(db);
                    query42.exec("SELECT ColorFondo FROM Color WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery Color(DBackup);
                    Color.exec("UPDATE Color SET ColorTexto='"+cantidad43+"',ColorFondo='"+cantidad44+"' WHERE id=2");
                }
            }
            if (i == 7)
            {
                if (ConvAudio=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45;
                    QSqlQuery query41(db);
                    query41.exec("SELECT Audio128 FROM Opcion WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(db);
                    query42.exec("SELECT Audio192 FROM Opcion WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(db);
                    query43.exec("SELECT Audio320 FROM Opcion WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery Opcion(DBackup);
                    Opcion.exec("UPDATE Opcion SET Audio128='"+cantidad43+"',Audio192='"+cantidad44+"',Audio320='"+cantidad45+"' WHERE id=2");
                }
            }
            if (i == 8)
            {
                if (Cancion=="Si")
                {
                    QString cantidad43;
                    QSqlQuery query41(db);
                    query41.exec("SELECT Posicion FROM Cancion WHERE id=1");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery Cancion(DBackup);
                    Cancion.exec("UPDATE Cancion SET Posicion='"+cantidad43+"' WHERE id=1");
                }
            }
            if (i == 9)
            {
                if (Canal=="Si")
                {
                    QString cantidad43;
                    QSqlQuery query41(db);
                    query41.exec("SELECT Posicion FROM PosTele WHERE id=1");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery Cancion(DBackup);
                    Cancion.exec("UPDATE PosTele SET Posicion='"+cantidad43+"' WHERE id=1");
                }
            }
            if (i == 10)
            {
                if (Radio=="Si")
                {
                    QString cantidad43;
                    QSqlQuery query41(db);
                    query41.exec("SELECT Posicion FROM PosRadio WHERE id=1");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery Cancion(DBackup);
                    Cancion.exec("UPDATE PosRadio SET Posicion='"+cantidad43+"' WHERE id=1");
                }
            }
            if (i == 11)
            {
                if (Registro=="Si")
                {
                    QString dat, clv, seri;
                    QSqlQuery dato(db);
                    dato.exec("SELECT dato FROM Registro WHERE id=1");
                    dato.first();
                    if (dato.isValid())
                         dat=dato.value(0).toString();
                    QSqlQuery clav(db);
                    clav.exec("SELECT clave FROM Registro WHERE id=1");
                    clav.first();
                    if (clav.isValid())
                         clv=clav.value(0).toString();
                    QSqlQuery Serie(db);
                    Serie.exec("SELECT serie FROM Registro WHERE id=1");
                    Serie.first();
                    if (Serie.isValid())
                         seri=Serie.value(0).toString();
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE Registro SET dato='"+dat+"',clave='"+clv+"',serie='"+seri+"' WHERE id=1");
                }
            }
            if (i == 12)
            {
                if (TamCorte=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45, cantidad46, cantidad47;
                    QSqlQuery query41(db);
                    query41.exec("SELECT tamano1 FROM opcion1 WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(db);
                    query42.exec("SELECT tamano2 FROM opcion1 WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(db);
                    query43.exec("SELECT tamano3 FROM opcion1 WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery query44(db);
                    query44.exec("SELECT tamano4 FROM opcion1 WHERE id=2");
                    query44.first();
                    if (query44.isValid())
                         cantidad46=query44.value(0).toString();
                    QSqlQuery query45(db);
                    query45.exec("SELECT tamano5 FROM opcion1 WHERE id=2");
                    query45.first();
                    if (query45.isValid())
                         cantidad47=query45.value(0).toString();
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE opcion1 SET tamano1='"+cantidad43+"',tamano2='"+cantidad44+"',tamano3='"+cantidad45+"',tamano4='"+cantidad46+"',tamano5='"+cantidad47+"' WHERE id=2");
                }
            }
            if (i == 13)
            {
                if (Correo=="Si")
                {
                    QString Cantidad,Cantidad1,Cantidad2,Cantidad3;
                    QSqlQuery query(db);
                    query.exec("SELECT Correo,smtp,pass,destino FROM Correo WHERE id=1");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                        Cantidad1=query.value(1).toString();
                        Cantidad2=query.value(2).toString();
                        Cantidad3=query.value(3).toString();
                     }
                     QSqlQuery Miscelanea(DBackup);
                     Miscelanea.exec("UPDATE Correo SET Correo='"+Cantidad+"',smtp='"+Cantidad1+"',pass='"+Cantidad2+"',destino='"+Cantidad3+"' WHERE id=1");
                }
            }
            if (i == 14)
            {
                if (Skin=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(db);
                    query.exec("SELECT Fondo FROM consola WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE consola SET Fondo='"+Cantidad+"' WHERE id=2");
                }
            }
            if (i == 15)
            {
                if (Velocidad=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45, cantidad46, cantidad47;
                    QSqlQuery query41(db);
                    query41.exec("SELECT Velocidad2x FROM opcion4 WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(db);
                    query42.exec("SELECT Velocidad4x FROM opcion4 WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(db);
                    query43.exec("SELECT Velocidad8x FROM opcion4 WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery query44(db);
                    query44.exec("SELECT Velocidad16x FROM opcion4 WHERE id=2");
                    query44.first();
                    if (query44.isValid())
                         cantidad46=query44.value(0).toString();
                    QSqlQuery query45(db);
                    query45.exec("SELECT Velocidad32x FROM opcion4 WHERE id=2");
                    query45.first();
                    if (query45.isValid())
                         cantidad47=query45.value(0).toString();
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE opcion4 SET Velocidad2x='"+cantidad43+"',Velocidad4x='"+cantidad44+"',Velocidad8x='"+cantidad45+"',Velocidad16x='"+cantidad46+"',Velocidad32x='"+cantidad47+"' WHERE id=2");
                }
            }
            if (i == 16)
            {
                if (Vnc=="Si")
                {
                    QString Cantidad,Cantidad1,Cantidad2,Cantidad3,Cantidad4,Cantidad5,Cantidad6,Cantidad7;
                    QSqlQuery query(db);
                    query.exec("SELECT tipoIp,clave,contraclave,segundoplano,menuGrafico,escuchar,soloVisual,LimitarIp FROM DatosVnc WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                        Cantidad1=query.value(1).toString();
                        Cantidad2=query.value(2).toString();
                        Cantidad3=query.value(3).toString();
                        Cantidad4=query.value(4).toString();
                        Cantidad5=query.value(5).toString();
                        Cantidad6=query.value(6).toString();
                        Cantidad7=query.value(7).toString();
                     }
                     QSqlQuery Miscelanea(DBackup);
                     Miscelanea.exec("UPDATE DatosVnc SET tipoIp='"+Cantidad+"',clave='"+Cantidad1+"',contraclave='"+Cantidad2+"',segundoplano='"+Cantidad3+"',menuGrafico='"+Cantidad4+"',escuchar='"+Cantidad5+"',soloVisual='"+Cantidad6+"',LimitarIp='"+Cantidad7+"' WHERE id=2");
                }
            }
            if (i == 17)
            {
                if (Resolucion=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45, cantidad46, cantidad47, cantidad48;
                    QSqlQuery query41(db);
                    query41.exec("SELECT i480 FROM opcion5 WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(db);
                    query42.exec("SELECT i576 FROM opcion5 WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(db);
                    query43.exec("SELECT i2_576 FROM opcion5 WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery query44(db);
                    query44.exec("SELECT p720 FROM opcion5 WHERE id=2");
                    query44.first();
                    if (query44.isValid())
                         cantidad46=query44.value(0).toString();
                    QSqlQuery query45(db);
                    query45.exec("SELECT p1080 FROM opcion5 WHERE id=2");
                    query45.first();
                    if (query45.isValid())
                         cantidad47=query45.value(0).toString();
                    QSqlQuery query46(db);
                    query46.exec("SELECT kapy FROM opcion5 WHERE id=2");
                    query46.first();
                    if (query46.isValid())
                         cantidad48=query46.value(0).toString();
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE opcion5 SET i480='"+cantidad43+"',i576='"+cantidad44+"',i2_576='"+cantidad45+"',p720='"+cantidad46+"',p1080='"+cantidad47+"',kapy='"+cantidad48+"' WHERE id=2");
                }
            }
            if (i == 18)
            {
                if (Grabacion=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45;
                    QSqlQuery query41(db);
                    query41.exec("SELECT Numero1 FROM opcion3 WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(db);
                    query42.exec("SELECT Numero2 FROM opcion3 WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(db);
                    query43.exec("SELECT Numero3 FROM opcion3 WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE opcion3 SET Numero1='"+cantidad43+"',Numero2='"+cantidad44+"',Numero3='"+cantidad45+"' WHERE id=2");
                }
            }
            if (i == 19)
            {
                if (Wifi=="Si")
                {
                    QString cantidad43, cantidad44;
                    QSqlQuery query41(db);
                    query41.exec("SELECT conexion FROM Wifi WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(db);
                    query42.exec("SELECT essid FROM Wifi WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE Wifi SET conexion='"+cantidad43+"',essid='"+cantidad44+"' WHERE id=2");
                }
            }
            if (i == 20)
            {
                if (Control=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45, cantidad46;
                    QSqlQuery query41(db);
                    query41.exec("SELECT tiempo120 FROM Parental WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(db);
                    query42.exec("SELECT tiempo90 FROM Parental WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(db);
                    query43.exec("SELECT tiempo60 FROM Parental WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery query44(db);
                    query44.exec("SELECT tiempo30 FROM Parental WHERE id=2");
                    query44.first();
                    if (query44.isValid())
                         cantidad46=query44.value(0).toString();
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE Parental SET tiempo120='"+cantidad43+"',tiempo90='"+cantidad44+"',tiempo60='"+cantidad45+"',tiempo30='"+cantidad46+"' WHERE id=2");
                }
            }
            if (i == 21)
            {
                if (Menu=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(db);
                    query.exec("SELECT Tipo_Menu FROM Menus WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE Menus SET Tipo_Menu='"+Cantidad+"' WHERE id=2");
                }
            }
            if (i == 22)
            {
                if (Chat=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(db);
                    query.exec("SELECT visionado FROM chat WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE chat SET visionado='"+Cantidad+"' WHERE id=2");
                }
            }
            if (i == 23)
            {
                if (Vista=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(db);
                    query.exec("SELECT Aspecto FROM Formato WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE Formato SET Aspecto='"+Cantidad+"' WHERE id=2");
                }
            }
            if (i == 24)
            {
                if (SVideo=="Si")
                {
                    QString cantidad43, cantidad44;
                    QSqlQuery query41(db);
                    query41.exec("SELECT vlc FROM Video WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(db);
                    query42.exec("SELECT parole FROM Video WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery Video(DBackup);
                    Video.exec("UPDATE Video SET vlc='"+cantidad43+"',parole='"+cantidad44+"' WHERE id=2");
                }
            }
            if (i == 25)
            {
                if (Formato=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(db);
                    query.exec("SELECT Aplicacion FROM Aplicacion WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE Aplicacion SET Aplicacion='"+Cantidad+"' WHERE id=2");
                }
            }
            if (i == 26)
            {
                if (Estilo=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(db);
                    query.exec("SELECT Style FROM Estilo WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE Estilo SET Style='"+Cantidad+"' WHERE id=2");
                }
            }
            if (i == 27)
            {
                if (Ecualizador=="Si")
                {
                    QString Cantidad,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10,Volumen;
                    QSqlQuery query(db);
                    query.exec("SELECT activo,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10,Volume FROM Ecualizador WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                        banda1=query.value(1).toString();
                        banda2=query.value(2).toString();
                        banda3=query.value(3).toString();
                        banda4=query.value(4).toString();
                        banda5=query.value(5).toString();
                        banda6=query.value(6).toString();
                        banda7=query.value(7).toString();
                        banda8=query.value(8).toString();
                        banda9=query.value(9).toString();
                        banda10=query.value(10).toString();
                        Volumen=query.value(11).toString();
                    }
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE Ecualizador SET activo='"+Cantidad+"',banda1='"+banda1+"',banda2='"+banda2+"',banda3='"+banda3+"',banda4='"+banda4+"',banda5='"+banda5+"',banda6='"+banda6+"',banda7='"+banda7+"',banda8='"+banda8+"',banda9='"+banda9+"',banda10='"+banda10+"',Volume='"+Volumen+"' WHERE id=2");
                }
            }
            if (i == 28)
            {
                if (Calculadora=="Si")
                {
                    QString Digitos,Decimales;
                    QSqlQuery query(db);
                    query.exec("SELECT Digitos,Decimales FROM Calculadora WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Digitos=query.value(0).toString();
                        Decimales=query.value(1).toString();
                    }
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE Calculadora SET Digitos='"+Digitos+"',Decimales='"+Decimales+"' WHERE id=2");
                }
            }
            if (i == 29)
            {
                if (Pais=="Si")
                {
                    QString Tipo;
                    QSqlQuery query(db);
                    query.exec("SELECT Tipo FROM Pais WHERE id=1");
                    query.first();
                    if (query.isValid())
                    {
                        Tipo=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DBackup);
                    Miscelanea.exec("UPDATE Pais SET Tipo='"+Tipo+"' WHERE id=1");
                }
            }
            if (i == 30)
            {
                if (LClave=="Si")
                {
                    QSqlQuery Palabr(db);
                    Palabr.exec("SELECT COUNT(id) as Cantidad FROM Palabra");
                    int cuenta, comienzo;
                    Palabr.first();
                    cuenta = Palabr.value(0).toInt();
                    QSqlQuery Palabra(db);
                    Palabra.exec("SELECT palabra FROM Palabra");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Exportando lista de palabras clave... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Palabra.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatPalabra = Palabra.value(0).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT palabra FROM Palabra WHERE palabra='"+DatPalabra+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QString ValPalabra = RecDat.value(0).toString();
                             if (DatPalabra != ValPalabra)
                             {
                                 QSqlQuery Wwhite(DBackup);
                                 Wwhite.prepare("INSERT INTO Palabra (palabra)"
                                               "VALUES (:palabra)");
                                 Wwhite.bindValue(":palabra", DatPalabra);
                                 Wwhite.exec();
                             }
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 31)
            {
                if (LNwifi=="Si")
                {
                    QSqlQuery wlistanegr(db);
                    wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM wlistanegra");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(db);
                    wlistanegra.exec("SELECT ip,mac FROM wlistanegra");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Exportando lista negra de ip's... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatIp = wlistanegra.value(0).toString();
                         QString DatMac = wlistanegra.value(1).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT ip,mac FROM wlistanegra WHERE ip='"+DatIp+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DBackup);
                             Wdark.prepare("INSERT INTO wlistanegra (ip,mac)"
                                           "VALUES (:ip,:mac)");
                             Wdark.bindValue(":ip", DatIp);
                             Wdark.bindValue(":mac", DatMac);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 32)
            {
                if (LMusica=="Si")
                {
                    QSqlQuery Music(db);
                    Music.exec("SELECT COUNT(id) as Cantidad FROM Musica");
                    int cuenta, comienzo;
                    Music.first();
                    cuenta = Music.value(0).toInt();
                    QSqlQuery Musica(db);
                    Musica.exec("SELECT Nombre,Ruta FROM Musica");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Exportando lista de canciones... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Musica.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatIp = Musica.value(0).toString();
                         QString DatMac = Musica.value(1).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT Nombre,Ruta FROM Musica WHERE Nombre='"+DatIp+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wwhite(DBackup);
                             Wwhite.prepare("INSERT INTO Musica (Nombre,Ruta)"
                                            "VALUES (:Nombre,:Ruta)");
                             Wwhite.bindValue(":Nombre", DatIp);
                             Wwhite.bindValue(":Ruta", DatMac);
                             Wwhite.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 33)
            {
                if (LBwifi=="Si")
                {
                    QSqlQuery wlistablanc(db);
                    wlistablanc.exec("SELECT COUNT(id) as Cantidad FROM wlistablanca");
                    int cuenta, comienzo;
                    wlistablanc.first();
                    cuenta = wlistablanc.value(0).toInt();
                    QSqlQuery wlistablanca(db);
                    wlistablanca.exec("SELECT ip,mac FROM wlistablanca");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Exportando lista blanca de ip's... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistablanca.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatIp = wlistablanca.value(0).toString();
                         QString DatMac = wlistablanca.value(1).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT ip,mac FROM wlistablanca WHERE ip='"+DatIp+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wwhite(DBackup);
                             Wwhite.prepare("INSERT INTO wlistablanca (ip,mac)"
                                            "VALUES (:ip,:mac)");
                             Wwhite.bindValue(":ip", DatIp);
                             Wwhite.bindValue(":mac", DatMac);
                             Wwhite.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 34)
            {
                if (LRadio=="Si")
                {
                    QSqlQuery Radi(db);
                    Radi.exec("SELECT COUNT(id) as Cantidad FROM Radio");
                    int cuenta, comienzo;
                    Radi.first();
                    cuenta = Radi.value(0).toInt();
                    QSqlQuery Radio(db);
                    Radio.exec("SELECT Estilo,Nombre,Url FROM Radio");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Exportando lista de canales de radio... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Radio.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatEst = Radio.value(0).toString();
                         QString DatNom = Radio.value(1).toString();
                         QString DatUrl = Radio.value(2).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT Estilo,Nombre,Url FROM Radio WHERE Nombre='"+DatNom+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QString ValIp = RecDat.value(1).toString();
                             if (DatNom != ValIp)
                             {
                                 QSqlQuery Wwhite(DBackup);
                                 Wwhite.prepare("INSERT INTO Radio (Estilo,Nombre,Url)"
                                               "VALUES (:Estilo,:Nombre,:Url)");
                                 Wwhite.bindValue(":Estilo", DatEst);
                                 Wwhite.bindValue(":Nombre", DatNom);
                                 Wwhite.bindValue(":Url", DatUrl);
                                 Wwhite.exec();
                             }
                             else
                             {
                                 QSqlQuery Wwhite(DBackup);
                                 Wwhite.exec("UPDATE Radio SET Estilo='"+DatEst+"',Url='"+DatUrl+"' WHERE Nombre='"+DatNom+"'");
                             }
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 35)
            {
                if (LTelevision=="Si")
                {
                    QSqlQuery Televisio(db);
                    Televisio.exec("SELECT COUNT(id) as Cantidad FROM Television");
                    int cuenta, comienzo;
                    Televisio.first();
                    cuenta = Televisio.value(0).toInt();
                    QSqlQuery Television(db);
                    Television.exec("SELECT Categoria,Nombre,Direccion FROM Television");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Exportando lista de canales de television... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Television.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatEst = Television.value(0).toString();
                         QString DatNom = Television.value(1).toString();
                         QString DatUrl = Television.value(2).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT Categoria,Nombre,Direccion FROM Television WHERE Nombre='"+DatNom+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QString ValIp = RecDat.value(1).toString();
                             if (DatNom != ValIp)
                             {
                                 QSqlQuery Wwhite(DBackup);
                                 Wwhite.prepare("INSERT INTO Television (Categoria,Nombre,Direccion)"
                                               "VALUES (:Categoria,:Nombre,:Direccion)");
                                 Wwhite.bindValue(":Categoria", DatEst);
                                 Wwhite.bindValue(":Nombre", DatNom);
                                 Wwhite.bindValue(":Direccion", DatUrl);
                                 Wwhite.exec();
                             }
                             else
                             {
                                 QSqlQuery Wwhite(DBackup);
                                 Wwhite.exec("UPDATE Television SET Categoria='"+DatEst+"',Direccion='"+DatUrl+"' WHERE Nombre='"+DatNom+"'");
                             }
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 36)
            {
                if (LUser=="Si")
                {
                    QSqlQuery Acces(db);
                    Acces.exec("SELECT COUNT(id) as Cantidad FROM Acceso");
                    int cuenta, comienzo;
                    Acces.first();
                    cuenta = Acces.value(0).toInt();
                    QSqlQuery Acceso(db);
                    Acceso.exec("SELECT Usuario,Clave,Nivel,Activo,Pregunta,Respuesta FROM Acceso");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Usuarios... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Acceso.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatUsu = Acceso.value(0).toString();
                         QString DatClv = Acceso.value(1).toString();
                         QString DatNiv = Acceso.value(2).toString();
                         QString DatAct = Acceso.value(3).toString();
                         QString DatPre = Acceso.value(4).toString();
                         QString DatRes = Acceso.value(5).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT Usuario,Clave,Nivel,Activo,Pregunta,Respuesta FROM Acceso WHERE Usuario='"+DatUsu+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QString ValIp = RecDat.value(0).toString();
                             if (DatUsu != ValIp)
                             {
                                 QSqlQuery Wwhite(DBackup);
                                 Wwhite.prepare("INSERT INTO Acceso (Usuario,Clave,Nivel,Activo,Pregunta,Respuesta)"
                                               "VALUES (:Usuario,:Clave,:Nivel,:Activo,:Pregunta,:Respuesta)");
                                 Wwhite.bindValue(":Usuario", DatUsu);
                                 Wwhite.bindValue(":Clave", DatClv);
                                 Wwhite.bindValue(":Nivel", DatNiv);
                                 Wwhite.bindValue(":Activo", DatAct);
                                 Wwhite.bindValue(":Pregunta", DatPre);
                                 Wwhite.bindValue(":Respuesta", DatRes);
                                 Wwhite.exec();
                             }
                             else
                             {
                                 QSqlQuery Wwhite(DBackup);
                                 Wwhite.exec("UPDATE Acceso SET Usuario='"+DatUsu+"',Clave='"+DatClv+"',Nivel='"+DatNiv+"',Activo='"+DatAct+"',Pregunta='"+DatPre+"',Respuesta='"+DatRes+"' WHERE Usuario='"+DatUsu+"'");
                             }
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 37)
            {
                if (LAccesos=="Si")
                {
                    QSqlQuery Acces(db);
                    Acces.exec("SELECT COUNT(id) as Cantidad FROM Control");
                    int cuenta, comienzo;
                    Acces.first();
                    cuenta = Acces.value(0).toInt();
                    QSqlQuery Acceso(db);
                    Acceso.exec("SELECT Nucleo,Version,Usuario,Fecha_ingreso FROM Control");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Control de accesos... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Acceso.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                            break;
                         QString Datgru = Acceso.value(0).toString();
                         QString Datiso = Acceso.value(1).toString();
                         QString Datgr2 = Acceso.value(2).toString();
                         QString DatNls = Acceso.value(3).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT Nucleo,Version,Usuario,Fecha_ingreso FROM Control WHERE Fecha_ingreso='"+DatNls+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wwhite(DBackup);
                             Wwhite.prepare("INSERT INTO Control (Nucleo,Version,Usuario,Fecha_ingreso)"
                                            "VALUES (:Nucleo,:Version,:Usuario,:Fecha_ingreso)");
                             Wwhite.bindValue(":Nucleo", Datgru);
                             Wwhite.bindValue(":Version", Datiso);
                             Wwhite.bindValue(":Usuario", Datgr2);
                             Wwhite.bindValue(":Fecha_ingreso", DatNls);
                             Wwhite.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 38)
            {
                if (LVnc=="Si")
                {
                    QSqlQuery wlistanegr(db);
                    wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM ipvnc");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(db);
                    wlistanegra.exec("SELECT ip FROM ipvnc");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando ip's permitidas para vnc... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatIp = wlistanegra.value(0).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT ip FROM ipvnc WHERE ip='"+DatIp+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DBackup);
                             Wdark.prepare("INSERT INTO ipvnc (ip)"
                                           "VALUES (:ip)");
                             Wdark.bindValue(":ip", DatIp);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 39)
            {
                if (LPelis=="Si")
                {
                    QSqlQuery Acces(db);
                    Acces.exec("SELECT COUNT(id) as Cantidad FROM pelis");
                    int cuenta, comienzo;
                    Acces.first();
                    cuenta = Acces.value(0).toInt();
                    QSqlQuery Acceso(db);
                    Acceso.exec("SELECT titulo,titulo_original,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico,policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis,soporte,posicion,visionada,duracion,color,vose,formato,fecha FROM pelis");
                    setUpdatesEnabled(false);
                    QProgressDialog progressPelis("Actualizando Catalogo de Peliculas... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressPelis.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressPelis.show();
                    QTest::qWait(20);
                    comienzo=0;
                    DBackup.transaction();
                    while(Acceso.next())
                    {
                         progressPelis.setValue(comienzo++);
                         if (progressPelis.wasCanceled())
                             break;
                         QString titulo = Acceso.value(0).toString();
                         titulo = titulo.replace("'", " ");
                         QString titulo1 = Acceso.value(1).toString();
                         titulo1 = titulo.replace("'", " ");
                         QString edad = Acceso.value(2).toString();
                         QString drama = Acceso.value(3).toString();
                         QString comedia = Acceso.value(4).toString();
                         QString accion = Acceso.value(5).toString();
                         QString aventura = Acceso.value(6).toString();
                         QString scifi = Acceso.value(7).toString();
                         QString romantica = Acceso.value(8).toString();
                         QString musical = Acceso.value(9).toString();
                         QString catastrofes = Acceso.value(10).toString();
                         QString suspense = Acceso.value(11).toString();
                         QString fantasia = Acceso.value(12).toString();
                         QString erotico = Acceso.value(13).toString();
                         QString porno = Acceso.value(14).toString();
                         QString historico = Acceso.value(15).toString();
                         QString policiaco = Acceso.value(16).toString();
                         QString terror = Acceso.value(17).toString();
                         QString western = Acceso.value(18).toString();
                         QString belico = Acceso.value(19).toString();
                         QString deportes = Acceso.value(20).toString();
                         QString animacion = Acceso.value(21).toString();
                         QString documental = Acceso.value(22).toString();
                         QString gore_zombies = Acceso.value(23).toString();
                         QString caratula = Acceso.value(24).toString();
                         QString actor = Acceso.value(25).toString();
                         QString secundario = Acceso.value(26).toString();
                         QString calificacion = Acceso.value(27).toString();
                         QString sinopsis = Acceso.value(28).toString();
                         QString soporte = Acceso.value(29).toString();
                         QString posicion = Acceso.value(30).toString();
                         QString visionada = Acceso.value(31).toString();
                         QString duracion = Acceso.value(32).toString();
                         QString color = Acceso.value(33).toString();
                         QString vose = Acceso.value(34).toString();
                         QString formato = Acceso.value(35).toString();
                         QString director = Acceso.value(36).toString();
                         QString fecha = Acceso.value(37).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT titulo,titulo_original,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico,policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis,soporte,posicion,visionada,duracion,color,vose,formato,fecha FROM pelis WHERE titulo='"+titulo+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery query(DBackup);
                             query.prepare("INSERT INTO pelis (titulo,titulo_original,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico,policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis,soporte,posicion,visionada,duracion,color,vose,formato,director,fecha)"
                                           "VALUES (:titulo,:titulo1,:edad,:drama,:comedia,:accion,:aventura,:scifi,:romantica,:musical,:catastrofes,:suspense,:fantasia,:erotico,:porno,:historico,:policiaco,:terror,:western,:belico,:deportes,:animacion,:documental,:gore_zombies,:caratula,:actor,:secundario,:calificacion,:sinopsis,:soporte,:posicion,:visionada,:duracion,:color,:vose,:formato,:director,:fecha)");
                             query.bindValue(":titulo", titulo);
                             query.bindValue(":titulo1", titulo1);
                             query.bindValue(":edad", edad);
                             query.bindValue(":drama", drama);
                             query.bindValue(":comedia", comedia);
                             query.bindValue(":accion", accion);
                             query.bindValue(":aventura", aventura);
                             query.bindValue(":scifi", scifi);
                             query.bindValue(":romantica", romantica);
                             query.bindValue(":musical", musical);
                             query.bindValue(":catastrofes", catastrofes);
                             query.bindValue(":suspense", suspense);
                             query.bindValue(":fantasia", fantasia);
                             query.bindValue(":erotico", erotico);
                             query.bindValue(":porno", porno);
                             query.bindValue(":historico", historico);
                             query.bindValue(":policiaco", policiaco);
                             query.bindValue(":terror", terror);
                             query.bindValue(":western", western);
                             query.bindValue(":belico", belico);
                             query.bindValue(":deportes", deportes);
                             query.bindValue(":animacion", animacion);
                             query.bindValue(":documental", documental);
                             query.bindValue(":gore_zombies", gore_zombies);
                             query.bindValue(":caratula", caratula);
                             query.bindValue(":actor", actor);
                             query.bindValue(":secundario", secundario);
                             query.bindValue(":calificacion", calificacion);
                             query.bindValue(":sinopsis", sinopsis);
                             query.bindValue(":soporte", soporte);
                             query.bindValue(":posicion", posicion);
                             query.bindValue(":visionada", visionada);
                             query.bindValue(":duracion", duracion);
                             query.bindValue(":color", color);
                             query.bindValue(":vose", vose);
                             query.bindValue(":formato", formato);
                             query.bindValue(":director", director);
                             query.bindValue(":fecha", fecha);
                             query.exec();
                         }
                    }
                    DBackup.commit();
                    progressPelis.setValue(cuenta);
                    setUpdatesEnabled(true);
                }
            }
            if (i == 40)
            {
                if (LMenu=="Si")
                {
                    QSqlQuery Acces(db);
                    Acces.exec("SELECT COUNT(id) as Cantidad FROM Menu");
                    int cuenta, comienzo;
                    Acces.first();
                    cuenta = Acces.value(0).toInt();
                    QSqlQuery Acceso(db);
                    Acceso.exec("SELECT Name,Name_es,Comment_es,Comment,Categories,Icon,Exec FROM Menu");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Menu... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Acceso.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                            break;
                         QString Datgru = Acceso.value(0).toString();
                         QString Datiso = Acceso.value(1).toString();
                         QString Datgr2 = Acceso.value(2).toString();
                         QString DatNom = Acceso.value(3).toString();
                         QString DatVer = Acceso.value(4).toString();
                         QString DatArq = Acceso.value(5).toString();
                         QString DatDir = Acceso.value(6).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT Name,Name_es,Comment_es,Comment,Categories,Icon,Exec FROM Menu WHERE Name='"+Datgru+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wwhite(DBackup);
                             Wwhite.prepare("INSERT INTO Menu (Name,Name_es,Comment_es,Comment,Categories,Icon,Exec)"
                                            "VALUES (:Name,:Name_es,:Comment_es,:Comment,:Categories,:Icon,:Exec)");
                             Wwhite.bindValue(":Name", Datgru);
                             Wwhite.bindValue(":Name_es", Datiso);
                             Wwhite.bindValue(":Comment_es", Datgr2);
                             Wwhite.bindValue(":Comment", DatNom);
                             Wwhite.bindValue(":Categories", DatVer);
                             Wwhite.bindValue(":Icon", DatArq);
                             Wwhite.bindValue(":Exec", DatDir);
                             Wwhite.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 41)
            {
                if (LSincro=="Si")
                {
                    QSqlQuery wlistanegr(db);
                    wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM Sincrono");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(db);
                    wlistanegra.exec("SELECT Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo FROM Sincrono");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Control de sincronizaciones... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatReferencia = wlistanegra.value(0).toString();
                         QString DatObjetivo = wlistanegra.value(1).toString();
                         QString DatDestino = wlistanegra.value(2).toString();
                         QString DatEliminar = wlistanegra.value(3).toString();
                         QString DatComprobar = wlistanegra.value(4).toString();
                         QString Ocultos = wlistanegra.value(5).toString();
                         QString Codigo = wlistanegra.value(6).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo FROM Sincrono WHERE Referencia='"+DatReferencia+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DBackup);
                             Wdark.prepare("INSERT INTO Sincrono (Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo)"
                                           "VALUES (:Referencia,:Objetivo,:Destino,:Eliminar,:Comprobar,:Ocultos,:Codigo)");
                             Wdark.bindValue(":Referencia", DatReferencia);
                             Wdark.bindValue(":Objetivo", DatObjetivo);
                             Wdark.bindValue(":Destino", DatDestino);
                             Wdark.bindValue(":Eliminar", DatEliminar);
                             Wdark.bindValue(":Comprobar", DatComprobar);
                             Wdark.bindValue(":Ocultos", Ocultos);
                             Wdark.bindValue(":Codigo", Codigo);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 42)
            {
                if (Lid3=="Si")
                {
                    QSqlQuery wlistanegr(db);
                    wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM id3Genre");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(db);
                    wlistanegra.exec("SELECT Genero FROM id3Genre");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando ID de generos de mp3... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.setWindowModality(Qt::WindowModal);
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatObjetivo = wlistanegra.value(0).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT Genero FROM id3Genre WHERE Genero='"+DatObjetivo+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DBackup);
                             Wdark.prepare("INSERT INTO id3Genre (Genero)"
                                           "VALUES (:Genero)");
                             Wdark.bindValue(":Genero", DatObjetivo);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 43)
            {
                if (Corte == "Si")
                {
                    QString cantidad3, cantidad4, cantidad5, cantidad6, cantidad7, cantidad8, cantidad9, cantidad10, cantidad11, cantidad12, cantidad13;
                    QSqlQuery query3(db);
                    query3.exec("SELECT camouflage_pa FROM Opcion2 WHERE id=2");
                    query3.first();
                    if (query3.isValid())
                         cantidad3=query3.value(0).toString();
                    QSqlQuery query4(db);
                    query4.exec("SELECT efsplitter_pa FROM Opcion2 WHERE id=2");
                    query4.first();
                    if (query4.isValid())
                         cantidad4=query4.value(0).toString();
                    QSqlQuery query5(db);
                    query5.exec("SELECT generico_pa FROM Opcion2 WHERE id=2");
                    query5.first();
                    if (query5.isValid())
                         cantidad5=query5.value(0).toString();
                    QSqlQuery query6(db);
                    query6.exec("SELECT hacha1_pa FROM Opcion2 WHERE id=2");
                    query6.first();
                    if (query6.isValid())
                         cantidad6=query6.value(0).toString();
                    QSqlQuery query7(db);
                    query7.exec("SELECT hacha2_pa FROM Opcion2 WHERE id=2");
                    query7.first();
                    if (query7.isValid())
                         cantidad7=query7.value(0).toString();
                    QSqlQuery query8(db);
                    query8.exec("SELECT hachapro_pa FROM Opcion2 WHERE id=2");
                    query8.first();
                    if (query8.isValid())
                         cantidad8=query8.value(0).toString();
                    QSqlQuery query9(db);
                    query9.exec("SELECT mxs_pa FROM Opcion2 WHERE id=2");
                    query9.first();
                    if (query9.isValid())
                         cantidad9=query9.value(0).toString();
                    QSqlQuery query10(db);
                    query10.exec("SELECT sf_pa FROM Opcion2 WHERE id=2");
                    query10.first();
                    if (query10.isValid())
                         cantidad10=query10.value(0).toString();
                    QSqlQuery query11(db);
                    query11.exec("SELECT zip_pa FROM Opcion2 WHERE id=2");
                    query11.first();
                    if (query11.isValid())
                         cantidad11=query11.value(0).toString();
                    QSqlQuery query12(db);
                    query12.exec("SELECT camaleon1_pa FROM Opcion2 WHERE id=2");
                    query12.first();
                    if (query12.isValid())
                         cantidad12=query12.value(0).toString();
                    QSqlQuery query13(db);
                    query13.exec("SELECT camaleon2_pa FROM Opcion2 WHERE id=2");
                    query13.first();
                    if (query13.isValid())
                         cantidad13=query13.value(0).toString();
                    QSqlQuery Opcion2(DBackup);
                    Opcion2.exec("UPDATE Opcion2 SET camouflage_pa='"+cantidad3+"',efsplitter_pa='"+cantidad4+"',generico_pa='"+cantidad5+"',hacha1_pa='"+cantidad6+"',hacha2_pa='"+cantidad7+"',hachapro_pa='"+cantidad8+"',mxs_pa='"+cantidad9+"',sf_pa='"+cantidad10+"',zip_pa='"+cantidad11+"',camaleon1_pa='"+cantidad12+"',camaleon2_pa='"+cantidad13+"' WHERE id=2");
                }
            }
            if (i == 44)
            {
                if (LClaves=="Si")
                {
                    QSqlQuery wlistanegr(db);
                    wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM Clave");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(db);
                    wlistanegra.exec("SELECT Usuario,Password,Enc1,Enc2,Enc3,Tipo,Dir FROM Clave");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Listado de claves... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatUsuario = wlistanegra.value(0).toString();
                         QString DatPassword = wlistanegra.value(1).toString();
                         QString DatEnc1 = wlistanegra.value(2).toString();
                         QString DatEnc2 = wlistanegra.value(3).toString();
                         QString DatEnc3 = wlistanegra.value(4).toString();
                         QString Tipo = wlistanegra.value(5).toString();
                         QString Ubicacion = wlistanegra.value(6).toString();
                         QString UserRD = wlistanegra.value(7).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT Usuario,Password,Enc1,Enc2,Enc3,Tipo,Dir,UserRD FROM Clave WHERE Dir='"+Ubicacion+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DBackup);
                             Wdark.prepare("INSERT INTO Clave (Usuario,Password,Enc1,Enc2,Enc3,Tipo,Dir,UserRD)"
                                           "VALUES (:Usuario,:Password,:Enc1,:Enc2,:Enc3,:Tipo,:Dir,:UserRD)");
                             Wdark.bindValue(":Usuario", DatUsuario);
                             Wdark.bindValue(":Password", DatPassword);
                             Wdark.bindValue(":Enc1", DatEnc1);
                             Wdark.bindValue(":Enc2", DatEnc2);
                             Wdark.bindValue(":Enc3", DatEnc3);
                             Wdark.bindValue(":Tipo", Tipo);
                             Wdark.bindValue(":Dir", Ubicacion);
                             Wdark.bindValue(":UserRD", UserRD);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 45)
            {
                if (LAscii=="Si")
                {
                    QSqlQuery wlistanegr(db);
                    wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM Ascii");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(db);
                    wlistanegra.exec("SELECT Decimal,Unicode FROM Ascii");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Listado de codigos Ascii... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatDecimal = wlistanegra.value(0).toString();
                         QString DatUnicode = wlistanegra.value(1).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT Decimal,Unicode FROM Ascii WHERE Decimal='"+DatDecimal+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DBackup);
                             Wdark.prepare("INSERT INTO Ascii (Decimal,Unicode)"
                                           "VALUES (:Decimal,:Unicode)");
                             Wdark.bindValue(":Decimal", DatDecimal);
                             Wdark.bindValue(":Unicode", DatUnicode);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 46)
            {
                if (LBic=="Si")
                {
                    QSqlQuery wlistanegr(db);
                    wlistanegr.exec("SELECT COUNT(Cantidad) as Cantidad FROM Bic");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(db);
                    wlistanegra.exec("SELECT Codigo,Nombre,Bic FROM Bic");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Listado de codigos BIC... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DBackup.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatCodigo = wlistanegra.value(0).toString();
                         QString DatNombre = wlistanegra.value(1).toString();
                         QString DatBic = wlistanegra.value(2).toString();
                         QSqlQuery RecDat(DBackup);
                         RecDat.exec("SELECT Codigo,Nombre,Bic FROM Bic WHERE Codigo='"+DatCodigo+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DBackup);
                             Wdark.prepare("INSERT INTO Bic (Codigo,Nombre,Bic)"
                                           "VALUES (:Codigo,:Nombre,:Bic)");
                             Wdark.bindValue(":Codigo", DatCodigo);
                             Wdark.bindValue(":Nombre", DatNombre);
                             Wdark.bindValue(":Bic", DatBic);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DBackup.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DBackup.commit();
                    setUpdatesEnabled(true);
                }
            }
        }
    }
    progress.setValue(47);
    DBackup.close();
    QMessageBox m;
    if (Stilo == "A")
        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    m.setText(QString::fromUtf8(tr("Copia de seguridad "+fileName+" realizada con exito.")));
    m.exec();
}

void Backup::on_tabWidget_currentChanged(int /*index*/)
{
    if (ui->tabWidget->currentIndex() == 1)
    {        
        this->Comprobar1();
    }
}

void Backup::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString Valor = ui->comboBox->currentText();
    QString Value;
    QFile file("/usr/share/RecoverDrake/backup/"+Valor+"");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString datoslst = in.readAll();
    file.close();
    QStringList lista = datoslst.split("\n");
    for(int i=0;i<lista.count();i++)
    {
        Value = lista.value(i);
        if (i == 0)
        {
            QString Parcial, Explora;
            Parcial = Value;
            Parcial.remove("Ruta: ");
            Explora = "find \"%1\"";
            Explora = Explora.arg(Parcial);
            drakeSistema drake;
            QString value = drake.getStart(Explora);
            if (value == "")
            {
                QMessageBox m;
                m.setWindowTitle(tr("Advertencia!!!"));
                m.setText(tr("No se encuentra la copia en la ruta...<p>")+Parcial+tr("<p>Comprueba que este el archivo en su destino."));
                m.exec();
                ui->pushButton_3->setEnabled(false);
                ui->pushButton_5->setEnabled(true);
                return;
            }
            else
            {
                ui->label_2->setText(Value);
                ui->pushButton_3->setEnabled(true);
                ui->pushButton_5->setEnabled(true);
            }
        }
        if (i == 1)
        {
            Value = Value.remove("Copia: ");
            if (Value == "Configuraciones")
            {
                ui->radioButton_4->setChecked(true);
            }
            else if (Value == "Datos")
            {
                ui->radioButton_5->setChecked(true);
            }
            else if (Value == "Todo")
            {
                ui->radioButton_6->setChecked(true);
            }
            Comprobar();
        }
        if (i == 2)
        {
            Value = Value.remove("Corte: ");
            if (Value == "Si")
                ui->checkBox_12->setChecked(true);
            else if (Value == "No")
                ui->checkBox_12->setChecked(false);
        }
        if (i == 3)
        {
            Value = Value.remove("Eth: ");
            if (Value == "Si")
                ui->checkBox_14->setChecked(true);
            else if (Value == "No")
                ui->checkBox_14->setChecked(false);
        }
        if (i == 4)
        {
            Value = Value.remove("Idioma: ");
            if (Value == "Si")
                ui->checkBox_13->setChecked(true);
            else if (Value == "No")
                ui->checkBox_13->setChecked(false);
        }
        if (i == 5)
        {
            Value = Value.remove("Video: ");
            if (Value == "Si")
                ui->checkBox_15->setChecked(true);
            else if (Value == "No")
                ui->checkBox_15->setChecked(false);
        }
        if (i == 6)
        {
            Value = Value.remove("Fuente: ");
            if (Value == "Si")
                ui->checkBox_18->setChecked(true);
            else if (Value == "No")
                ui->checkBox_18->setChecked(false);
        }
        if (i == 7)
        {
            Value = Value.remove("Red: ");
            if (Value == "Si")
                ui->checkBox_16->setChecked(true);
            else if (Value == "No")
                ui->checkBox_16->setChecked(false);
        }
        if (i == 8)
        {
            Value = Value.remove("Miscelanea: ");
            if (Value == "Si")
                ui->checkBox_54->setChecked(true);
            else if (Value == "No")
                ui->checkBox_54->setChecked(false);
        }
        if (i == 9)
        {
            Value = Value.remove("Color: ");
            if (Value == "Si")
                ui->checkBox_53->setChecked(true);
            else if (Value == "No")
                ui->checkBox_53->setChecked(false);
        }
        if (i == 10)
        {
            Value = Value.remove("ConvAudio: ");
            if (Value == "Si")
                ui->checkBox_55->setChecked(true);
            else if (Value == "No")
                ui->checkBox_55->setChecked(false);
        }
        if (i == 11)
        {
            Value = Value.remove("Cancion: ");
            if (Value == "Si")
                ui->checkBox_56->setChecked(true);
            else if (Value == "No")
                ui->checkBox_56->setChecked(false);
        }
        if (i == 12)
        {
            Value = Value.remove("Canal: ");
            if (Value == "Si")
                ui->checkBox_58->setChecked(true);
            else if (Value == "No")
                ui->checkBox_58->setChecked(false);
        }
        if (i == 13)
        {
            Value = Value.remove("Radio: ");
            if (Value == "Si")
                ui->checkBox_57->setChecked(true);
            else if (Value == "No")
                ui->checkBox_57->setChecked(false);
        }
        if (i == 14)
        {
            Value = Value.remove("Registro: ");
            if (Value == "Si")
                ui->checkBox_61->setChecked(true);
            else if (Value == "No")
                ui->checkBox_61->setChecked(false);
        }
        if (i == 15)
        {
            Value = Value.remove("TamCorte: ");
            if (Value == "Si")
                ui->checkBox_59->setChecked(true);
            else if (Value == "No")
                ui->checkBox_59->setChecked(false);
        }
        if (i == 16)
        {
            Value = Value.remove("Correo: ");
            if (Value == "Si")
                ui->checkBox_63->setChecked(true);
            else if (Value == "No")
                ui->checkBox_63->setChecked(false);
        }
        if (i == 17)
        {
            Value = Value.remove("Skin: ");
            if (Value == "Si")
                ui->checkBox_60->setChecked(true);
            else if (Value == "No")
                ui->checkBox_60->setChecked(false);
        }
        if (i == 18)
        {
            Value = Value.remove("Velocidad: ");
            if (Value == "Si")
                ui->checkBox_65->setChecked(true);
            else if (Value == "No")
                ui->checkBox_65->setChecked(false);
        }
        if (i == 19)
        {
            Value = Value.remove("Vnc: ");
            if (Value == "Si")
                ui->checkBox_62->setChecked(true);
            else if (Value == "No")
                ui->checkBox_62->setChecked(false);
        }
        if (i == 20)
        {
            Value = Value.remove("Resolucion: ");
            if (Value == "Si")
                ui->checkBox_66->setChecked(true);
            else if (Value == "No")
                ui->checkBox_66->setChecked(false);
        }
        if (i == 21)
        {
            Value = Value.remove("Grabacion: ");
            if (Value == "Si")
                ui->checkBox_64->setChecked(true);
            else if (Value == "No")
                ui->checkBox_64->setChecked(false);
        }
        if (i == 22)
        {
            Value = Value.remove("Wifi: ");
            if (Value == "Si")
                ui->checkBox_68->setChecked(true);
            else if (Value == "No")
                ui->checkBox_68->setChecked(false);
        }
        if (i == 23)
        {
            Value = Value.remove("Control: ");
            if (Value == "Si")
                ui->checkBox_67->setChecked(true);
            else if (Value == "No")
                ui->checkBox_67->setChecked(false);
        }
        if (i == 24)
        {
            Value = Value.remove("Menu: ");
            if (Value == "Si")
                ui->checkBox_69->setChecked(true);
            else if (Value == "No")
                ui->checkBox_69->setChecked(false);
        }
        if (i == 25)
        {
            Value = Value.remove("Chat: ");
            if (Value == "Si")
                ui->checkBox_70->setChecked(true);
            else if (Value == "No")
                ui->checkBox_70->setChecked(false);
        }
        if (i == 26)
        {
            Value = Value.remove("Vista: ");
            if (Value == "Si")
                ui->checkBox_72->setChecked(true);
            else if (Value == "No")
                ui->checkBox_72->setChecked(false);
        }
        if (i == 27)
        {
            Value = Value.remove("SVideo: ");
            if (Value == "Si")
                ui->checkBox_74->setChecked(true);
            else if (Value == "No")
                ui->checkBox_74->setChecked(false);
        }
        if (i == 28)
        {
            Value = Value.remove("Formato: ");
            if (Value == "Si")
                ui->checkBox_76->setChecked(true);
            else if (Value == "No")
                ui->checkBox_76->setChecked(false);
        }
        if (i == 29)
        {
            Value = Value.remove("Estilo: ");
            if (Value == "Si")
                ui->checkBox_78->setChecked(true);
            else if (Value == "No")
                ui->checkBox_78->setChecked(false);
        }
        if (i == 30)
        {
            Value = Value.remove("Ecualizador: ");
            if (Value == "Si")
                ui->checkBox_82->setChecked(true);
            else if (Value == "No")
                ui->checkBox_82->setChecked(false);
        }
        if (i == 31)
        {
            Value = Value.remove("Calculadora: ");
            if (Value == "Si")
                ui->checkBox_85->setChecked(true);
            else if (Value == "No")
                ui->checkBox_85->setChecked(false);
        }
        if (i == 32)
        {
            Value = Value.remove("Pais: ");
            if (Value == "Si")
                ui->checkBox_92->setChecked(true);
            else if (Value == "No")
                ui->checkBox_92->setChecked(false);
        }
        if (i == 33)
        {
            Value = Value.remove("LClave: ");
            if (Value == "Si")
                ui->checkBox_9->setChecked(true);
            else if (Value == "No")
                ui->checkBox_9->setChecked(false);
        }
        if (i == 34)
        {
            Value = Value.remove("LNwifi: ");
            if (Value == "Si")
                ui->checkBox_10->setChecked(true);
            else if (Value == "No")
                ui->checkBox_10->setChecked(false);
        }
        if (i == 35)
        {
            Value = Value.remove("LMusica: ");
            if (Value == "Si")
                ui->checkBox_31->setChecked(true);
            else if (Value == "No")
                ui->checkBox_31->setChecked(false);
        }
        if (i == 36)
        {
            Value = Value.remove("LBwifi: ");
            if (Value == "Si")
                ui->checkBox_11->setChecked(true);
            else if (Value == "No")
                ui->checkBox_11->setChecked(false);
        }
        if (i == 37)
        {
            Value = Value.remove("LRadio: ");
            if (Value == "Si")
                ui->checkBox_46->setChecked(true);
            else if (Value == "No")
                ui->checkBox_46->setChecked(false);
        }
        if (i == 38)
        {
            Value = Value.remove("LTelevision: ");
            if (Value == "Si")
                ui->checkBox_47->setChecked(true);
            else if (Value == "No")
                ui->checkBox_47->setChecked(false);
        }
        if (i == 39)
        {
            Value = Value.remove("LUser: ");
            if (Value == "Si")
                ui->checkBox_48->setChecked(true);
            else if (Value == "No")
                ui->checkBox_48->setChecked(false);
        }
        if (i == 40)
        {
            Value = Value.remove("LAccesos: ");
            if (Value == "Si")
                ui->checkBox_49->setChecked(true);
            else if (Value == "No")
                ui->checkBox_49->setChecked(false);
        }
        if (i == 41)
        {
            Value = Value.remove("LVnc: ");
            if (Value == "Si")
                ui->checkBox_51->setChecked(true);
            else if (Value == "No")
                ui->checkBox_51->setChecked(false);
        }
        if (i == 42)
        {
            Value = Value.remove("LPelis: ");
            if (Value == "Si")
                ui->checkBox_50->setChecked(true);
            else if (Value == "No")
                ui->checkBox_50->setChecked(false);
        }
        if (i == 43)
        {
            Value = Value.remove("LMenu: ");
            if (Value == "Si")
                ui->checkBox_52->setChecked(true);
            else if (Value == "No")
                ui->checkBox_52->setChecked(false);
        }
        if (i == 44)
        {
            Value = Value.remove("LSincro: ");
            if (Value == "Si")
                ui->checkBox_80->setChecked(true);
            else if (Value == "No")
                ui->checkBox_80->setChecked(false);
        }
        if (i == 45)
        {
            Value = Value.remove("Lid3: ");
            if (Value == "Si")
                ui->checkBox_84->setChecked(true);
            else if (Value == "No")
                ui->checkBox_84->setChecked(false);
        }
        if (i == 46)
        {
            Value = Value.remove("LClaves: ");
            if (Value == "Si")
                ui->checkBox_87->setChecked(true);
            else if (Value == "No")
                ui->checkBox_87->setChecked(false);
        }
        if (i == 47)
        {
            Value = Value.remove("LAscii: ");
            if (Value == "Si")
                ui->checkBox_90->setChecked(true);
            else if (Value == "No")
                ui->checkBox_90->setChecked(false);
        }
        if (i == 48)
        {
            Value = Value.remove("LBic: ");
            if (Value == "Si")
                ui->checkBox_94->setChecked(true);
            else if (Value == "No")
                ui->checkBox_94->setChecked(false);
        }
    }
}

void Backup::on_pushButton_3_clicked()
{
    if (ui->radioButton_5->isChecked() == true)
    {
        if (ui->checkBox_9->isChecked() == true)
            LClave="Si";
        if (ui->checkBox_10->isChecked() == true)
            LNwifi="Si";
        if (ui->checkBox_31->isChecked() == true)
            LMusica="Si";
        if (ui->checkBox_11->isChecked() == true)
            LBwifi="Si";
        if (ui->checkBox_46->isChecked() == true)
            LRadio="Si";
        if (ui->checkBox_47->isChecked() == true)
            LTelevision="Si";
        if (ui->checkBox_48->isChecked() == true)
            LUser="Si";
        if (ui->checkBox_49->isChecked() == true)
            LAccesos="Si";
        if (ui->checkBox_51->isChecked() == true)
            LVnc="Si";
        if (ui->checkBox_50->isChecked() == true)
            LPelis="Si";
        if (ui->checkBox_52->isChecked() == true)
            LMenu="Si";
        if (ui->checkBox_80->isChecked() == true)
            LSincro="Si";
        if (ui->checkBox_84->isChecked() == true)
            Lid3="Si";
        if (ui->checkBox_87->isChecked() == true)
            LClaves="Si";
        if (ui->checkBox_90->isChecked() == true)
            LAscii="Si";
        if (ui->checkBox_94->isChecked() == true)
            LBic="Si";
    }
    else if (ui->radioButton_4->isChecked() == true)
    {
        if (ui->checkBox_12->isChecked() == true)
            Corte="Si";
        if (ui->checkBox_14->isChecked() == true)
            Eth="Si";
        if (ui->checkBox_13->isChecked() == true)
            Idioma="Si";
        if (ui->checkBox_15->isChecked() == true)
            Video="Si";
        if (ui->checkBox_18->isChecked() == true)
            Fuente="Si";
        if (ui->checkBox_16->isChecked() == true)
            Red="Si";
        if (ui->checkBox_54->isChecked() == true)
            Miscelanea="Si";
        if (ui->checkBox_53->isChecked() == true)
            Color="Si";
        if (ui->checkBox_55->isChecked() == true)
            ConvAudio="Si";
        if (ui->checkBox_56->isChecked() == true)
            Cancion="Si";
        if (ui->checkBox_58->isChecked() == true)
            Canal="Si";
        if (ui->checkBox_57->isChecked() == true)
            Radio="Si";
        if (ui->checkBox_61->isChecked() == true)
            Registro="Si";
        if (ui->checkBox_59->isChecked() == true)
            TamCorte="Si";
        if (ui->checkBox_63->isChecked() == true)
            Correo="Si";
        if (ui->checkBox_60->isChecked() == true)
            Skin="Si";
        if (ui->checkBox_65->isChecked() == true)
            Velocidad="Si";
        if (ui->checkBox_62->isChecked() == true)
            Vnc="Si";
        if (ui->checkBox_66->isChecked() == true)
            Resolucion="Si";
        if (ui->checkBox_64->isChecked() == true)
            Grabacion="Si";
        if (ui->checkBox_68->isChecked() == true)
            Wifi="Si";
        if (ui->checkBox_67->isChecked() == true)
            Control="Si";
        if (ui->checkBox_69->isChecked() == true)
            Menu="Si";
        if (ui->checkBox_70->isChecked() == true)
            Chat="Si";
        if (ui->checkBox_72->isChecked() == true)
            Vista="Si";
        if (ui->checkBox_74->isChecked() == true)
            SVideo="Si";
        if (ui->checkBox_76->isChecked() == true)
            Formato="Si";
        if (ui->checkBox_78->isChecked() == true)
            Estilo="Si";
        if (ui->checkBox_82->isChecked() == true)
            Ecualizador="Si";
        if (ui->checkBox_85->isChecked() == true)
            Calculadora="Si";
        if (ui->checkBox_92->isChecked() == true)
            Pais="Si";
    }
    else if (ui->radioButton_6->isChecked() == true)
    {
        if (ui->checkBox_12->isChecked() == true)
            Corte="Si";
        if (ui->checkBox_14->isChecked() == true)
            Eth="Si";
        if (ui->checkBox_13->isChecked() == true)
            Idioma="Si";
        if (ui->checkBox_15->isChecked() == true)
            Video="Si";
        if (ui->checkBox_18->isChecked() == true)
            Fuente="Si";
        if (ui->checkBox_16->isChecked() == true)
            Red="Si";
        if (ui->checkBox_54->isChecked() == true)
            Miscelanea="Si";
        if (ui->checkBox_53->isChecked() == true)
            Color="Si";
        if (ui->checkBox_55->isChecked() == true)
            ConvAudio="Si";
        if (ui->checkBox_56->isChecked() == true)
            Cancion="Si";
        if (ui->checkBox_58->isChecked() == true)
            Canal="Si";
        if (ui->checkBox_57->isChecked() == true)
            Radio="Si";
        if (ui->checkBox_61->isChecked() == true)
            Registro="Si";
        if (ui->checkBox_59->isChecked() == true)
            TamCorte="Si";
        if (ui->checkBox_63->isChecked() == true)
            Correo="Si";
        if (ui->checkBox_60->isChecked() == true)
            Skin="Si";
        if (ui->checkBox_65->isChecked() == true)
            Velocidad="Si";
        if (ui->checkBox_62->isChecked() == true)
            Vnc="Si";
        if (ui->checkBox_66->isChecked() == true)
            Resolucion="Si";
        if (ui->checkBox_64->isChecked() == true)
            Grabacion="Si";
        if (ui->checkBox_68->isChecked() == true)
            Wifi="Si";
        if (ui->checkBox_67->isChecked() == true)
            Control="Si";
        if (ui->checkBox_69->isChecked() == true)
            Menu="Si";
        if (ui->checkBox_70->isChecked() == true)
            Chat="Si";
        if (ui->checkBox_72->isChecked() == true)
            Vista="Si";
        if (ui->checkBox_74->isChecked() == true)
            SVideo="Si";
        if (ui->checkBox_76->isChecked() == true)
            Formato="Si";
        if (ui->checkBox_78->isChecked() == true)
            Estilo="Si";
        if (ui->checkBox_82->isChecked() == true)
            Ecualizador="Si";
        if (ui->checkBox_85->isChecked() == true)
            Calculadora="Si";
        if (ui->checkBox_92->isChecked() == true)
            Pais="Si";
        if (ui->checkBox_9->isChecked() == true)
            LClave="Si";
        if (ui->checkBox_10->isChecked() == true)
            LNwifi="Si";
        if (ui->checkBox_31->isChecked() == true)
            LMusica="Si";
        if (ui->checkBox_11->isChecked() == true)
            LBwifi="Si";
        if (ui->checkBox_46->isChecked() == true)
            LRadio="Si";
        if (ui->checkBox_47->isChecked() == true)
            LTelevision="Si";
        if (ui->checkBox_48->isChecked() == true)
            LUser="Si";
        if (ui->checkBox_49->isChecked() == true)
            LAccesos="Si";
        if (ui->checkBox_51->isChecked() == true)
            LVnc="Si";
        if (ui->checkBox_50->isChecked() == true)
            LPelis="Si";
        if (ui->checkBox_52->isChecked() == true)
            LMenu="Si";
        if (ui->checkBox_80->isChecked() == true)
            LSincro="Si";
        if (ui->checkBox_84->isChecked() == true)
            Lid3="Si";
        if (ui->checkBox_87->isChecked() == true)
            LClaves="Si";
        if (ui->checkBox_90->isChecked() == true)
            LAscii="Si";
        if (ui->checkBox_94->isChecked() == true)
            LBic="Si";
    }
    DBackup = QSqlDatabase::addDatabase("QSQLITE","BACKUP");
    QString Ruta = ui->label_2->text().remove("Ruta: ");
    DBackup.setDatabaseName(Ruta);
    if (!DBackup.open())
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("<b>Error grave</b>:<p>No se ha podido abrir la base de datos espejo necesaria.<p>Comprueba que existe en la ruta ")+Ruta+".");
        m.exec();
        return;
    }
    else
    {
        QProgressDialog progress("Recuperando copia... Espera por favor", "Cancelar", 0, 46);
        if (Stilo == "A")
            progress.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        progress.setWindowModality(Qt::WindowModal);
        progress.show();
        QTest::qWait(20);
        for(int i=0;i<46;i++ )
        {
            progress.setValue(i);
            if (progress.wasCanceled())
                break;
            if ( i == 0)
            {
                if (Corte == "Si")
                {
                    QString cantidad3, cantidad4, cantidad5, cantidad6, cantidad7, cantidad8, cantidad9, cantidad10, cantidad11, cantidad12, cantidad13;
                    QSqlQuery query3(DBackup);
                    query3.exec("SELECT camouflage_pa FROM Opcion2 WHERE id=2");
                    query3.first();
                    if (query3.isValid())
                         cantidad3=query3.value(0).toString();
                    QSqlQuery query4(DBackup);
                    query4.exec("SELECT efsplitter_pa FROM Opcion2 WHERE id=2");
                    query4.first();
                    if (query4.isValid())
                         cantidad4=query4.value(0).toString();
                    QSqlQuery query5(DBackup);
                    query5.exec("SELECT generico_pa FROM Opcion2 WHERE id=2");
                    query5.first();
                    if (query5.isValid())
                         cantidad5=query5.value(0).toString();
                    QSqlQuery query6(DBackup);
                    query6.exec("SELECT hacha1_pa FROM Opcion2 WHERE id=2");
                    query6.first();
                    if (query6.isValid())
                         cantidad6=query6.value(0).toString();
                    QSqlQuery query7(DBackup);
                    query7.exec("SELECT hacha2_pa FROM Opcion2 WHERE id=2");
                    query7.first();
                    if (query7.isValid())
                         cantidad7=query7.value(0).toString();
                    QSqlQuery query8(DBackup);
                    query8.exec("SELECT hachapro_pa FROM Opcion2 WHERE id=2");
                    query8.first();
                    if (query8.isValid())
                         cantidad8=query8.value(0).toString();
                    QSqlQuery query9(DBackup);
                    query9.exec("SELECT mxs_pa FROM Opcion2 WHERE id=2");
                    query9.first();
                    if (query9.isValid())
                         cantidad9=query9.value(0).toString();
                    QSqlQuery query10(DBackup);
                    query10.exec("SELECT sf_pa FROM Opcion2 WHERE id=2");
                    query10.first();
                    if (query10.isValid())
                         cantidad10=query10.value(0).toString();
                    QSqlQuery query11(DBackup);
                    query11.exec("SELECT zip_pa FROM Opcion2 WHERE id=2");
                    query11.first();
                    if (query11.isValid())
                         cantidad11=query11.value(0).toString();
                    QSqlQuery query12(DBackup);
                    query12.exec("SELECT camaleon1_pa FROM Opcion2 WHERE id=2");
                    query12.first();
                    if (query12.isValid())
                         cantidad12=query12.value(0).toString();
                    QSqlQuery query13(DBackup);
                    query13.exec("SELECT camaleon2_pa FROM Opcion2 WHERE id=2");
                    query13.first();
                    if (query13.isValid())
                         cantidad13=query13.value(0).toString();
                    QSqlQuery Opcion2(DB);
                    Opcion2.exec("UPDATE Opcion2 SET camouflage_pa='"+cantidad3+"',efsplitter_pa='"+cantidad4+"',generico_pa='"+cantidad5+"',hacha1_pa='"+cantidad6+"',hacha2_pa='"+cantidad7+"',hachapro_pa='"+cantidad8+"',mxs_pa='"+cantidad9+"',sf_pa='"+cantidad10+"',zip_pa='"+cantidad11+"',camaleon1_pa='"+cantidad12+"',camaleon2_pa='"+cantidad13+"' WHERE id=2");
                }
            }
            if (i == 1)
            {
                if (Eth == "Si")
                {
                    QString cantidad40;
                    QSqlQuery query38(DBackup);
                    query38.exec("SELECT conexion FROM ethernet WHERE id=2");
                    query38.first();
                    if (query38.isValid())
                         cantidad40=query38.value(0).toString();
                    QSqlQuery ethernet(DB);
                    ethernet.exec("UPDATE ethernet SET conexion='"+cantidad40+"' WHERE id=2");
                }
            }
            if (i == 2)
            {
                if (Idioma=="Si")
                {
                    QString cantidad43, cantidad44;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT spanish FROM Idioma WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(DBackup);
                    query42.exec("SELECT english FROM Idioma WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery Idioma(DB);
                    Idioma.exec("UPDATE Idioma SET spanish='"+cantidad43+"',english='"+cantidad44+"' WHERE id=2");
                }
            }
            if (i == 3)
            {
                if (Fuente=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT Fuente FROM Font WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(DBackup);
                    query42.exec("SELECT Estilo FROM Font WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(DBackup);
                    query43.exec("SELECT Talla FROM Font WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery Font(DB);
                    Font.exec("UPDATE Font SET Fuente='"+cantidad43+"',Estilo='"+cantidad44+"',Talla='"+cantidad45+"' WHERE id=2");
                }
            }
            if (i == 4)
            {
                if (Red=="Si")
                {
                    QString cantidad41, cantidad42;
                    QSqlQuery query39(DBackup);
                    query39.exec("SELECT ethernet FROM red WHERE id=2");
                    query39.first();
                    if (query39.isValid())
                         cantidad41=query39.value(0).toString();
                    QSqlQuery query40(DBackup);
                    query40.exec("SELECT wifi FROM red WHERE id=2");
                    query40.first();
                    if (query40.isValid())
                         cantidad42=query40.value(0).toString();
                    QSqlQuery red(DB);
                    red.exec("UPDATE red SET ethernet='"+cantidad41+"',wifi='"+cantidad42+"' WHERE id=2");
                }
            }
            if (i == 5)
            {
                if (Miscelanea=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT Defecto FROM Miscelanea WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(DBackup);
                    query42.exec("SELECT inicio FROM Miscelanea WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(DBackup);
                    query43.exec("SELECT Dependencias FROM Miscelanea WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE Miscelanea SET Defecto='"+cantidad43+"',inicio='"+cantidad44+"',Dependencias='"+cantidad45+"' WHERE id=2");
                }
            }
            if (i == 6)
            {
                if (Color=="Si")
                {
                    QString cantidad43, cantidad44;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT ColorTexto FROM Color WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(DBackup);
                    query42.exec("SELECT ColorFondo FROM Color WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery Color(DB);
                    Color.exec("UPDATE Color SET ColorTexto='"+cantidad43+"',ColorFondo='"+cantidad44+"' WHERE id=2");
                }
            }
            if (i == 7)
            {
                if (ConvAudio=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT Audio128 FROM Opcion WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(DBackup);
                    query42.exec("SELECT Audio192 FROM Opcion WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(DBackup);
                    query43.exec("SELECT Audio320 FROM Opcion WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery Opcion(DB);
                    Opcion.exec("UPDATE Opcion SET Audio128='"+cantidad43+"',Audio192='"+cantidad44+"',Audio320='"+cantidad45+"' WHERE id=2");
                }
            }
            if (i == 8)
            {
                if (Cancion=="Si")
                {
                    QString cantidad43;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT Posicion FROM Cancion WHERE id=1");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery Cancion(DB);
                    Cancion.exec("UPDATE Cancion SET Posicion='"+cantidad43+"' WHERE id=1");
                }
            }
            if (i == 9)
            {
                if (Canal=="Si")
                {
                    QString cantidad43;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT Posicion FROM PosTele WHERE id=1");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery Cancion(DB);
                    Cancion.exec("UPDATE PosTele SET Posicion='"+cantidad43+"' WHERE id=1");
                }
            }
            if (i == 10)
            {
                if (Radio=="Si")
                {
                    QString cantidad43;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT Posicion FROM PosRadio WHERE id=1");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery Cancion(DB);
                    Cancion.exec("UPDATE PosRadio SET Posicion='"+cantidad43+"' WHERE id=1");
                }
            }
            if (i == 11)
            {
                if (Registro=="Si")
                {
                    QString dat, clv, seri;
                    QSqlQuery dato(DBackup);
                    dato.exec("SELECT dato FROM Registro WHERE id=1");
                    dato.first();
                    if (dato.isValid())
                         dat=dato.value(0).toString();
                    QSqlQuery clav(DBackup);
                    clav.exec("SELECT clave FROM Registro WHERE id=1");
                    clav.first();
                    if (clav.isValid())
                         clv=clav.value(0).toString();
                    QSqlQuery Serie(DBackup);
                    Serie.exec("SELECT serie FROM Registro WHERE id=1");
                    Serie.first();
                    if (Serie.isValid())
                         seri=Serie.value(0).toString();
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE Registro SET dato='"+dat+"',clave='"+clv+"',serie='"+seri+"' WHERE id=1");
                }
            }
            if (i == 12)
            {
                if (TamCorte=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45, cantidad46, cantidad47;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT tamano1 FROM opcion1 WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(DBackup);
                    query42.exec("SELECT tamano2 FROM opcion1 WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(DBackup);
                    query43.exec("SELECT tamano3 FROM opcion1 WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery query44(DBackup);
                    query44.exec("SELECT tamano4 FROM opcion1 WHERE id=2");
                    query44.first();
                    if (query44.isValid())
                         cantidad46=query44.value(0).toString();
                    QSqlQuery query45(DBackup);
                    query45.exec("SELECT tamano5 FROM opcion1 WHERE id=2");
                    query45.first();
                    if (query45.isValid())
                         cantidad47=query45.value(0).toString();
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE opcion1 SET tamano1='"+cantidad43+"',tamano2='"+cantidad44+"',tamano3='"+cantidad45+"',tamano4='"+cantidad46+"',tamano5='"+cantidad47+"' WHERE id=2");
                }
            }
            if (i == 13)
            {
                if (Correo=="Si")
                {
                    QString Cantidad,Cantidad1,Cantidad2,Cantidad3;
                    QSqlQuery query(DBackup);
                    query.exec("SELECT Correo,smtp,pass,destino FROM Correo WHERE id=1");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                        Cantidad1=query.value(1).toString();
                        Cantidad2=query.value(2).toString();
                        Cantidad3=query.value(3).toString();
                     }
                     QSqlQuery Miscelanea(DB);
                     Miscelanea.exec("UPDATE Correo SET Correo='"+Cantidad+"',smtp='"+Cantidad1+"',pass='"+Cantidad2+"',destino='"+Cantidad3+"' WHERE id=1");
                }
            }
            if (i == 14)
            {
                if (Skin=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(DBackup);
                    query.exec("SELECT Fondo FROM consola WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE consola SET Fondo='"+Cantidad+"' WHERE id=2");
                }
            }
            if (i == 15)
            {
                if (Velocidad=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45, cantidad46, cantidad47;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT Velocidad2x FROM opcion4 WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(DBackup);
                    query42.exec("SELECT Velocidad4x FROM opcion4 WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(DBackup);
                    query43.exec("SELECT Velocidad8x FROM opcion4 WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery query44(DBackup);
                    query44.exec("SELECT Velocidad16x FROM opcion4 WHERE id=2");
                    query44.first();
                    if (query44.isValid())
                         cantidad46=query44.value(0).toString();
                    QSqlQuery query45(DBackup);
                    query45.exec("SELECT Velocidad32x FROM opcion4 WHERE id=2");
                    query45.first();
                    if (query45.isValid())
                         cantidad47=query45.value(0).toString();
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE opcion4 SET Velocidad2x='"+cantidad43+"',Velocidad4x='"+cantidad44+"',Velocidad8x='"+cantidad45+"',Velocidad16x='"+cantidad46+"',Velocidad32x='"+cantidad47+"' WHERE id=2");
                }
            }
            if (i == 16)
            {
                if (Vnc=="Si")
                {
                    QString Cantidad,Cantidad1,Cantidad2,Cantidad3,Cantidad4,Cantidad5,Cantidad6,Cantidad7;
                    QSqlQuery query(DBackup);
                    query.exec("SELECT tipoIp,clave,contraclave,segundoplano,menuGrafico,escuchar,soloVisual,LimitarIp FROM DatosVnc WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                        Cantidad1=query.value(1).toString();
                        Cantidad2=query.value(2).toString();
                        Cantidad3=query.value(3).toString();
                        Cantidad4=query.value(4).toString();
                        Cantidad5=query.value(5).toString();
                        Cantidad6=query.value(6).toString();
                        Cantidad7=query.value(7).toString();
                     }
                     QSqlQuery Miscelanea(DB);
                     Miscelanea.exec("UPDATE DatosVnc SET tipoIp='"+Cantidad+"',clave='"+Cantidad1+"',contraclave='"+Cantidad2+"',segundoplano='"+Cantidad3+"',menuGrafico='"+Cantidad4+"',escuchar='"+Cantidad5+"',soloVisual='"+Cantidad6+"',LimitarIp='"+Cantidad7+"' WHERE id=2");
                }
            }
            if (i == 17)
            {
                if (Resolucion=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45, cantidad46, cantidad47, cantidad48;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT i480 FROM opcion5 WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(DBackup);
                    query42.exec("SELECT i576 FROM opcion5 WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(DBackup);
                    query43.exec("SELECT i2_576 FROM opcion5 WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery query44(DBackup);
                    query44.exec("SELECT p720 FROM opcion5 WHERE id=2");
                    query44.first();
                    if (query44.isValid())
                         cantidad46=query44.value(0).toString();
                    QSqlQuery query45(DBackup);
                    query45.exec("SELECT p1080 FROM opcion5 WHERE id=2");
                    query45.first();
                    if (query45.isValid())
                         cantidad47=query45.value(0).toString();
                    QSqlQuery query46(DBackup);
                    query46.exec("SELECT kapy FROM opcion5 WHERE id=2");
                    query46.first();
                    if (query46.isValid())
                         cantidad48=query46.value(0).toString();
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE opcion5 SET i480='"+cantidad43+"',i576='"+cantidad44+"',i2_576='"+cantidad45+"',p720='"+cantidad46+"',p1080='"+cantidad47+"',kapy='"+cantidad48+"' WHERE id=2");
                }
            }
            if (i == 18)
            {
                if (Grabacion=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT Numero1 FROM opcion3 WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(DBackup);
                    query42.exec("SELECT Numero2 FROM opcion3 WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(DBackup);
                    query43.exec("SELECT Numero3 FROM opcion3 WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE opcion3 SET Numero1='"+cantidad43+"',Numero2='"+cantidad44+"',Numero3='"+cantidad45+"' WHERE id=2");
                }
            }
            if (i == 19)
            {
                if (Wifi=="Si")
                {
                    QString cantidad43, cantidad44;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT conexion FROM Wifi WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(DBackup);
                    query42.exec("SELECT essid FROM Wifi WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE Wifi SET conexion='"+cantidad43+"',essid='"+cantidad44+"' WHERE id=2");
                }
            }
            if (i == 20)
            {
                if (Control=="Si")
                {
                    QString cantidad43, cantidad44, cantidad45, cantidad46;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT tiempo120 FROM Parental WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(DBackup);
                    query42.exec("SELECT tiempo90 FROM Parental WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery query43(DBackup);
                    query43.exec("SELECT tiempo60 FROM Parental WHERE id=2");
                    query43.first();
                    if (query43.isValid())
                         cantidad45=query43.value(0).toString();
                    QSqlQuery query44(DBackup);
                    query44.exec("SELECT tiempo30 FROM Parental WHERE id=2");
                    query44.first();
                    if (query44.isValid())
                         cantidad46=query44.value(0).toString();
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE Parental SET tiempo120='"+cantidad43+"',tiempo90='"+cantidad44+"',tiempo60='"+cantidad45+"',tiempo30='"+cantidad46+"' WHERE id=2");
                }
            }
            if (i == 21)
            {
                if (Menu=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(DBackup);
                    query.exec("SELECT Tipo_Menu FROM Menus WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE Menus SET Tipo_Menu='"+Cantidad+"' WHERE id=2");
                }
            }
            if (i == 22)
            {
                if (Chat=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(DBackup);
                    query.exec("SELECT visionado FROM chat WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE chat SET visionado='"+Cantidad+"' WHERE id=2");
                }
            }
            if (i == 23)
            {
                if (Vista=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(DBackup);
                    query.exec("SELECT Aspecto FROM Formato WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE Formato SET Aspecto='"+Cantidad+"' WHERE id=2");
                }
            }
            if (i == 24)
            {
                if (SVideo=="Si")
                {
                    QString cantidad43, cantidad44;
                    QSqlQuery query41(DBackup);
                    query41.exec("SELECT vlc FROM Video WHERE id=2");
                    query41.first();
                    if (query41.isValid())
                         cantidad43=query41.value(0).toString();
                    QSqlQuery query42(DBackup);
                    query42.exec("SELECT parole FROM Video WHERE id=2");
                    query42.first();
                    if (query42.isValid())
                         cantidad44=query42.value(0).toString();
                    QSqlQuery Video(DB);
                    Video.exec("UPDATE Video SET vlc='"+cantidad43+"',parole='"+cantidad44+"' WHERE id=2");
                }
            }
            if (i == 25)
            {
                if (Formato=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(DBackup);
                    query.exec("SELECT Aplicacion FROM Aplicacion WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE Aplicacion SET Aplicacion='"+Cantidad+"' WHERE id=2");
                }
            }
            if (i == 26)
            {
                if (Estilo=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(DBackup);
                    query.exec("SELECT Style FROM Estilo WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE Estilo SET Style='"+Cantidad+"' WHERE id=2");
                }
            }
            if (i == 27)
            {
                if (Ecualizador=="Si")
                {
                    QString Cantidad,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10,Volumen;
                    QSqlQuery query(DBackup);
                    query.exec("SELECT activo,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10,Volume FROM Ecualizador WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                        banda1=query.value(1).toString();
                        banda2=query.value(2).toString();
                        banda3=query.value(3).toString();
                        banda4=query.value(4).toString();
                        banda5=query.value(5).toString();
                        banda6=query.value(6).toString();
                        banda7=query.value(7).toString();
                        banda8=query.value(8).toString();
                        banda9=query.value(9).toString();
                        banda10=query.value(10).toString();
                        Volumen=query.value(11).toString();
                    }
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE Ecualizador SET activo='"+Cantidad+"',banda1='"+banda1+"',banda2='"+banda2+"',banda3='"+banda3+"',banda4='"+banda4+"',banda5='"+banda5+"',banda6='"+banda6+"',banda7='"+banda7+"',banda8='"+banda8+"',banda9='"+banda9+"',banda10='"+banda10+"',Volume='"+Volumen+"' WHERE id=2");
                }
            }
            if (i == 28)
            {
                if (Calculadora=="Si")
                {
                    QString Digitos,Decimales;
                    QSqlQuery query(DBackup);
                    query.exec("SELECT Digitos,Decimales FROM Calculadora WHERE id=2");
                    query.first();
                    if (query.isValid())
                    {
                        Digitos=query.value(0).toString();
                        Decimales=query.value(1).toString();
                    }
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE Calculadora SET Digitos='"+Digitos+"',Decimales='"+Decimales+"' WHERE id=2");
                }
            }
            if (i == 29)
            {
                if (LClave=="Si")
                {
                    QSqlQuery Palabr(DBackup);
                    Palabr.exec("SELECT COUNT(id) as Cantidad FROM Palabra");
                    int cuenta, comienzo;
                    Palabr.first();
                    cuenta = Palabr.value(0).toInt();
                    QSqlQuery Palabra(DBackup);
                    Palabra.exec("SELECT palabra FROM Palabra");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Exportando lista de palabras clave... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A") progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Palabra.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatPalabra = Palabra.value(0).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT palabra FROM Palabra WHERE palabra='"+DatPalabra+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QString ValPalabra = RecDat.value(0).toString();
                             if (DatPalabra != ValPalabra)
                             {
                                 QSqlQuery Wwhite(DB);
                                 Wwhite.prepare("INSERT INTO Palabra (palabra)"
                                               "VALUES (:palabra)");
                                 Wwhite.bindValue(":palabra", DatPalabra);
                                 Wwhite.exec();
                             }
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 30)
            {
                if (LNwifi=="Si")
                {
                    QSqlQuery wlistanegr(DBackup);
                    wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM wlistanegra");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(DBackup);
                    wlistanegra.exec("SELECT ip,mac FROM wlistanegra");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Exportando lista negra de ip's... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatIp = wlistanegra.value(0).toString();
                         QString DatMac = wlistanegra.value(1).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT ip,mac FROM wlistanegra WHERE ip='"+DatIp+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DB);
                             Wdark.prepare("INSERT INTO wlistanegra (ip,mac)"
                                           "VALUES (:ip,:mac)");
                             Wdark.bindValue(":ip", DatIp);
                             Wdark.bindValue(":mac", DatMac);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 31)
            {
                if (LMusica=="Si")
                {
                    QSqlQuery Music(DBackup);
                    Music.exec("SELECT COUNT(id) as Cantidad FROM Musica");
                    int cuenta, comienzo;
                    Music.first();
                    cuenta = Music.value(0).toInt();
                    QSqlQuery Musica(DBackup);
                    Musica.exec("SELECT Nombre,Ruta FROM Musica");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Exportando lista de canciones... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Musica.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatIp = Musica.value(0).toString();
                         QString DatMac = Musica.value(1).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT Nombre,Ruta FROM Musica WHERE Nombre='"+DatIp+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wwhite(DB);
                             Wwhite.prepare("INSERT INTO Musica (Nombre,Ruta)"
                                            "VALUES (:Nombre,:Ruta)");
                             Wwhite.bindValue(":Nombre", DatIp);
                             Wwhite.bindValue(":Ruta", DatMac);
                             Wwhite.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 32)
            {
                if (LBwifi=="Si")
                {
                    QSqlQuery wlistablanc(DBackup);
                    wlistablanc.exec("SELECT COUNT(id) as Cantidad FROM wlistablanca");
                    int cuenta, comienzo;
                    wlistablanc.first();
                    cuenta = wlistablanc.value(0).toInt();
                    QSqlQuery wlistablanca(DBackup);
                    wlistablanca.exec("SELECT ip,mac FROM wlistablanca");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Exportando lista blanca de ip's... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistablanca.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatIp = wlistablanca.value(0).toString();
                         QString DatMac = wlistablanca.value(1).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT ip,mac FROM wlistablanca WHERE ip='"+DatIp+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wwhite(DB);
                             Wwhite.prepare("INSERT INTO wlistablanca (ip,mac)"
                                            "VALUES (:ip,:mac)");
                             Wwhite.bindValue(":ip", DatIp);
                             Wwhite.bindValue(":mac", DatMac);
                             Wwhite.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 33)
            {
                if (LRadio=="Si")
                {
                    QSqlQuery Radi(DBackup);
                    Radi.exec("SELECT COUNT(id) as Cantidad FROM Radio");
                    int cuenta, comienzo;
                    Radi.first();
                    cuenta = Radi.value(0).toInt();
                    QSqlQuery Radio(DBackup);
                    Radio.exec("SELECT Estilo,Nombre,Url FROM Radio");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Exportando lista de canales de radio... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Radio.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatEst = Radio.value(0).toString();
                         QString DatNom = Radio.value(1).toString();
                         QString DatUrl = Radio.value(2).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT Estilo,Nombre,Url FROM Radio WHERE Nombre='"+DatNom+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QString ValIp = RecDat.value(1).toString();
                             if (DatNom != ValIp)
                             {
                                 QSqlQuery Wwhite(DB);
                                 Wwhite.prepare("INSERT INTO Radio (Estilo,Nombre,Url)"
                                               "VALUES (:Estilo,:Nombre,:Url)");
                                 Wwhite.bindValue(":Estilo", DatEst);
                                 Wwhite.bindValue(":Nombre", DatNom);
                                 Wwhite.bindValue(":Url", DatUrl);
                                 Wwhite.exec();
                             }
                             else
                             {
                                 QSqlQuery Wwhite(DB);
                                 Wwhite.exec("UPDATE Radio SET Estilo='"+DatEst+"',Url='"+DatUrl+"' WHERE Nombre='"+DatNom+"'");
                             }
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 34)
            {
                if (LTelevision=="Si")
                {
                    QSqlQuery Televisio(DBackup);
                    Televisio.exec("SELECT COUNT(id) as Cantidad FROM Television");
                    int cuenta, comienzo;
                    Televisio.first();
                    cuenta = Televisio.value(0).toInt();
                    QSqlQuery Television(DBackup);
                    Television.exec("SELECT Categoria,Nombre,Direccion FROM Television");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Exportando lista de canales de television... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Television.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatEst = Television.value(0).toString();
                         QString DatNom = Television.value(1).toString();
                         QString DatUrl = Television.value(2).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT Categoria,Nombre,Direccion FROM Television WHERE Nombre='"+DatNom+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QString ValIp = RecDat.value(1).toString();
                             if (DatNom != ValIp)
                             {
                                 QSqlQuery Wwhite(DB);
                                 Wwhite.prepare("INSERT INTO Television (Categoria,Nombre,Direccion)"
                                               "VALUES (:Categoria,:Nombre,:Direccion)");
                                 Wwhite.bindValue(":Categoria", DatEst);
                                 Wwhite.bindValue(":Nombre", DatNom);
                                 Wwhite.bindValue(":Direccion", DatUrl);
                                 Wwhite.exec();
                             }
                             else
                             {
                                 QSqlQuery Wwhite(DB);
                                 Wwhite.exec("UPDATE Television SET Categoria='"+DatEst+"',Direccion='"+DatUrl+"' WHERE Nombre='"+DatNom+"'");
                             }
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 35)
            {
                if (LUser=="Si")
                {
                    QSqlQuery Acces(DBackup);
                    Acces.exec("SELECT COUNT(id) as Cantidad FROM Acceso");
                    int cuenta, comienzo;
                    Acces.first();
                    cuenta = Acces.value(0).toInt();
                    QSqlQuery Acceso(DBackup);
                    Acceso.exec("SELECT Usuario,Clave,Nivel,Activo,Pregunta,Respuesta FROM Acceso");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Usuarios... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Acceso.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatUsu = Acceso.value(0).toString();
                         QString DatClv = Acceso.value(1).toString();
                         QString DatNiv = Acceso.value(2).toString();
                         QString DatAct = Acceso.value(3).toString();
                         QString DatPre = Acceso.value(4).toString();
                         QString DatRes = Acceso.value(5).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT Usuario,Clave,Nivel,Activo,Pregunta,Respuesta FROM Acceso WHERE Usuario='"+DatUsu+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QString ValIp = RecDat.value(0).toString();
                             if (DatUsu != ValIp)
                             {
                                 QSqlQuery Wwhite(DB);
                                 Wwhite.prepare("INSERT INTO Acceso (Usuario,Clave,Nivel,Activo,Pregunta,Respuesta)"
                                               "VALUES (:Usuario,:Clave,:Nivel,:Activo,:Pregunta,:Respuesta)");
                                 Wwhite.bindValue(":Usuario", DatUsu);
                                 Wwhite.bindValue(":Clave", DatClv);
                                 Wwhite.bindValue(":Nivel", DatNiv);
                                 Wwhite.bindValue(":Activo", DatAct);
                                 Wwhite.bindValue(":Pregunta", DatPre);
                                 Wwhite.bindValue(":Respuesta", DatRes);
                                 Wwhite.exec();
                             }
                             else
                             {
                                 QSqlQuery Wwhite(DB);
                                 Wwhite.exec("UPDATE Acceso SET Usuario='"+DatUsu+"',Clave='"+DatClv+"',Nivel='"+DatNiv+"',Activo='"+DatAct+"',Pregunta='"+DatPre+"',Respuesta='"+DatRes+"' WHERE Usuario='"+DatUsu+"'");
                             }
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 36)
            {
                if (LAccesos=="Si")
                {
                    QSqlQuery Acces(DBackup);
                    Acces.exec("SELECT COUNT(id) as Cantidad FROM Control");
                    int cuenta, comienzo;
                    Acces.first();
                    cuenta = Acces.value(0).toInt();
                    QSqlQuery Acceso(DBackup);
                    Acceso.exec("SELECT Nucleo,Version,Usuario,Fecha_ingreso FROM Control");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Control de accesos... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(Acceso.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                            break;
                         QString Datgru = Acceso.value(0).toString();
                         QString Datiso = Acceso.value(1).toString();
                         QString Datgr2 = Acceso.value(2).toString();
                         QString DatNls = Acceso.value(3).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT Nucleo,Version,Usuario,Fecha_ingreso FROM Control WHERE Fecha_ingreso='"+DatNls+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wwhite(DB);
                             Wwhite.prepare("INSERT INTO Control (Nucleo,Version,Usuario,Fecha_ingreso)"
                                            "VALUES (:Nucleo,:Version,:Usuario,:Fecha_ingreso)");
                             Wwhite.bindValue(":Nucleo", Datgru);
                             Wwhite.bindValue(":Version", Datiso);
                             Wwhite.bindValue(":Usuario", Datgr2);
                             Wwhite.bindValue(":Fecha_ingreso", DatNls);
                             Wwhite.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 37)
            {
                if (LVnc=="Si")
                {
                    QSqlQuery wlistanegr(DBackup);
                    wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM ipvnc");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(DBackup);
                    wlistanegra.exec("SELECT ip FROM ipvnc");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando ip's permitidas para vnc... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatIp = wlistanegra.value(0).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT ip FROM ipvnc WHERE ip='"+DatIp+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DB);
                             Wdark.prepare("INSERT INTO ipvnc (ip)"
                                           "VALUES (:ip)");
                             Wdark.bindValue(":ip", DatIp);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 38)
            {
                if (LPelis=="Si")
                {
                    QSqlQuery Acces(DBackup);
                    Acces.exec("SELECT COUNT(id) as Cantidad FROM pelis");
                    int cuenta, comienzo;
                    Acces.first();
                    cuenta = Acces.value(0).toInt();
                    QSqlQuery Acceso(DBackup);
                    Acceso.exec("SELECT titulo,titulo_original,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico,policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis,soporte,posicion,visionada,duracion,color,vose,formato,fecha FROM pelis");
                    setUpdatesEnabled(false);
                    QProgressDialog progressPelis("Actualizando Catalogo de Peliculas... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressPelis.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressPelis.show();
                    QTest::qWait(20);
                    comienzo=0;
                    DB.transaction();
                    while(Acceso.next())
                    {
                         progressPelis.setValue(comienzo++);
                         if (progressPelis.wasCanceled())
                             break;
                         QString titulo = Acceso.value(0).toString();
                         titulo = titulo.replace("'", " ");
                         QString titulo1 = Acceso.value(1).toString();
                         titulo1 = titulo.replace("'", " ");
                         QString edad = Acceso.value(2).toString();
                         QString drama = Acceso.value(3).toString();
                         QString comedia = Acceso.value(4).toString();
                         QString accion = Acceso.value(5).toString();
                         QString aventura = Acceso.value(6).toString();
                         QString scifi = Acceso.value(7).toString();
                         QString romantica = Acceso.value(8).toString();
                         QString musical = Acceso.value(9).toString();
                         QString catastrofes = Acceso.value(10).toString();
                         QString suspense = Acceso.value(11).toString();
                         QString fantasia = Acceso.value(12).toString();
                         QString erotico = Acceso.value(13).toString();
                         QString porno = Acceso.value(14).toString();
                         QString historico = Acceso.value(15).toString();
                         QString policiaco = Acceso.value(16).toString();
                         QString terror = Acceso.value(17).toString();
                         QString western = Acceso.value(18).toString();
                         QString belico = Acceso.value(19).toString();
                         QString deportes = Acceso.value(20).toString();
                         QString animacion = Acceso.value(21).toString();
                         QString documental = Acceso.value(22).toString();
                         QString gore_zombies = Acceso.value(23).toString();
                         QString caratula = Acceso.value(24).toString();
                         QString actor = Acceso.value(25).toString();
                         QString secundario = Acceso.value(26).toString();
                         QString calificacion = Acceso.value(27).toString();
                         QString sinopsis = Acceso.value(28).toString();
                         QString soporte = Acceso.value(29).toString();
                         QString posicion = Acceso.value(30).toString();
                         QString visionada = Acceso.value(31).toString();
                         QString duracion = Acceso.value(32).toString();
                         QString color = Acceso.value(33).toString();
                         QString vose = Acceso.value(34).toString();
                         QString formato = Acceso.value(35).toString();
                         QString director = Acceso.value(36).toString();
                         QString fecha = Acceso.value(37).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT titulo,titulo_original,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico,policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis,soporte,posicion,visionada,duracion,color,vose,formato,fecha FROM pelis WHERE titulo='"+titulo+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery query(DB);
                             query.prepare("INSERT INTO pelis (titulo,titulo_original,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico,policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis,soporte,posicion,visionada,duracion,color,vose,formato,director,fecha)"
                                           "VALUES (:titulo,:titulo1,:edad,:drama,:comedia,:accion,:aventura,:scifi,:romantica,:musical,:catastrofes,:suspense,:fantasia,:erotico,:porno,:historico,:policiaco,:terror,:western,:belico,:deportes,:animacion,:documental,:gore_zombies,:caratula,:actor,:secundario,:calificacion,:sinopsis,:soporte,:posicion,:visionada,:duracion,:color,:vose,:formato,:director,:fecha)");
                             query.bindValue(":titulo", titulo);
                             query.bindValue(":titulo1", titulo1);
                             query.bindValue(":edad", edad);
                             query.bindValue(":drama", drama);
                             query.bindValue(":comedia", comedia);
                             query.bindValue(":accion", accion);
                             query.bindValue(":aventura", aventura);
                             query.bindValue(":scifi", scifi);
                             query.bindValue(":romantica", romantica);
                             query.bindValue(":musical", musical);
                             query.bindValue(":catastrofes", catastrofes);
                             query.bindValue(":suspense", suspense);
                             query.bindValue(":fantasia", fantasia);
                             query.bindValue(":erotico", erotico);
                             query.bindValue(":porno", porno);
                             query.bindValue(":historico", historico);
                             query.bindValue(":policiaco", policiaco);
                             query.bindValue(":terror", terror);
                             query.bindValue(":western", western);
                             query.bindValue(":belico", belico);
                             query.bindValue(":deportes", deportes);
                             query.bindValue(":animacion", animacion);
                             query.bindValue(":documental", documental);
                             query.bindValue(":gore_zombies", gore_zombies);
                             query.bindValue(":caratula", caratula);
                             query.bindValue(":actor", actor);
                             query.bindValue(":secundario", secundario);
                             query.bindValue(":calificacion", calificacion);
                             query.bindValue(":sinopsis", sinopsis);
                             query.bindValue(":soporte", soporte);
                             query.bindValue(":posicion", posicion);
                             query.bindValue(":visionada", visionada);
                             query.bindValue(":duracion", duracion);
                             query.bindValue(":color", color);
                             query.bindValue(":vose", vose);
                             query.bindValue(":formato", formato);
                             query.bindValue(":director", director);
                             query.bindValue(":fecha", fecha);
                             query.exec();
                         }
                    }
                    DB.commit();
                    progressPelis.setValue(cuenta);
                    setUpdatesEnabled(true);
                }
            }
            if (i == 39)
            {
            if (LMenu=="Si")
            {
                QSqlQuery Acces(DBackup);
                Acces.exec("SELECT COUNT(id) as Cantidad FROM Menu");
                int cuenta, comienzo;
                Acces.first();
                cuenta = Acces.value(0).toInt();
                QSqlQuery Acceso(DBackup);
                Acceso.exec("SELECT Name,Name_es,Comment_es,Comment,Categories,Icon,Exec FROM Menu");
                setUpdatesEnabled(false);
                QProgressDialog progressMenu("Actualizando Menu... Espera por favor", "Cancelar", 0, cuenta);
                if (Stilo == "A")
                    progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                progressMenu.show();
                QTest::qWait(20);
                comienzo=0;
                int cantidad=1;
                while(Acceso.next())
                {
                     if (cantidad == 1)
                     {
                         DB.transaction();
                     }
                     progressMenu.setValue(comienzo++);
                     if (progressMenu.wasCanceled())
                        break;
                     QString Datgru = Acceso.value(0).toString();
                     QString Datiso = Acceso.value(1).toString();
                     QString Datgr2 = Acceso.value(2).toString();
                     QString DatNom = Acceso.value(3).toString();
                     QString DatVer = Acceso.value(4).toString();
                     QString DatArq = Acceso.value(5).toString();
                     QString DatDir = Acceso.value(6).toString();
                     QSqlQuery RecDat(DB);
                     RecDat.exec("SELECT Name,Name_es,Comment_es,Comment,Categories,Icon,Exec FROM Menu WHERE Name='"+Datgru+"'");
                     RecDat.first();
                     if (RecDat.isSelect())
                     {
                         QSqlQuery Wwhite(DB);
                         Wwhite.prepare("INSERT INTO Menu (Name,Name_es,Comment_es,Comment,Categories,Icon,Exec)"
                                        "VALUES (:Name,:Name_es,:Comment_es,:Comment,:Categories,:Icon,:Exec)");
                         Wwhite.bindValue(":Name", Datgru);
                         Wwhite.bindValue(":Name_es", Datiso);
                         Wwhite.bindValue(":Comment_es", Datgr2);
                         Wwhite.bindValue(":Comment", DatNom);
                         Wwhite.bindValue(":Categories", DatVer);
                         Wwhite.bindValue(":Icon", DatArq);
                         Wwhite.bindValue(":Exec", DatDir);
                         Wwhite.exec();
                     }
                     cantidad++;
                     if (cantidad == 50)
                     {
                         cantidad=1;
                         DB.commit();
                     }
                }
                progressMenu.setValue(cuenta);
                DB.commit();
                setUpdatesEnabled(true);
            }
            }
            if (i == 40)
            {
                if (LSincro=="Si")
                {
                    QSqlQuery wlistanegr(DBackup);
                    wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM Sincrono");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(DBackup);
                    wlistanegra.exec("SELECT Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo FROM Sincrono");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Control de sincronizaciones... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatReferencia = wlistanegra.value(0).toString();
                         QString DatObjetivo = wlistanegra.value(1).toString();
                         QString DatDestino = wlistanegra.value(2).toString();
                         QString DatEliminar = wlistanegra.value(3).toString();
                         QString DatComprobar = wlistanegra.value(4).toString();
                         QString Ocultos = wlistanegra.value(5).toString();
                         QString Codigo = wlistanegra.value(6).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo FROM Sincrono WHERE Referencia='"+DatReferencia+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DB);
                             Wdark.prepare("INSERT INTO Sincrono (Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo)"
                                           "VALUES (:Referencia,:Objetivo,:Destino,:Eliminar,:Comprobar,:Ocultos,:Codigo)");
                             Wdark.bindValue(":Referencia", DatReferencia);
                             Wdark.bindValue(":Objetivo", DatObjetivo);
                             Wdark.bindValue(":Destino", DatDestino);
                             Wdark.bindValue(":Eliminar", DatEliminar);
                             Wdark.bindValue(":Comprobar", DatComprobar);
                             Wdark.bindValue(":Ocultos", Ocultos);
                             Wdark.bindValue(":Codigo",Codigo);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 41)
            {
                if (Lid3=="Si")
                {
                    QSqlQuery wlistanegr(DBackup);
                    wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM id3Genre");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(DBackup);
                    wlistanegra.exec("SELECT Genero FROM id3Genre");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando ID de generos de mp3... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.setWindowModality(Qt::WindowModal);
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatObjetivo = wlistanegra.value(0).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT Genero FROM id3Genre WHERE Genero='"+DatObjetivo+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DB);
                             Wdark.prepare("INSERT INTO id3Genre (Genero)"
                                           "VALUES (:Genero)");
                             Wdark.bindValue(":Genero", DatObjetivo);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 42)
            {
                if (LClaves=="Si")
                {
                    QSqlQuery wlistanegr(DBackup);
                    wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM Clave");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(DBackup);
                    wlistanegra.exec("SELECT Usuario,Password,Enc1,Enc2,Enc3,Tipo,Dir,UserRD FROM Clave");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Listado de claves... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatUsuario = wlistanegra.value(0).toString();
                         QString DatPassword = wlistanegra.value(1).toString();
                         QString DatEnc1 = wlistanegra.value(2).toString();
                         QString DatEnc2 = wlistanegra.value(3).toString();
                         QString DatEnc3 = wlistanegra.value(4).toString();
                         QString Tipo = wlistanegra.value(5).toString();
                         QString Ubicacion = wlistanegra.value(6).toString();
                         QString UserRD = wlistanegra.value(7).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT Usuario,Password,Enc1,Enc2,Enc3,Tipo,Dir,UserRD FROM Clave WHERE Dir='"+Ubicacion+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DB);
                             Wdark.prepare("INSERT INTO Clave (Usuario,Password,Enc1,Enc2,Enc3,Tipo,Dir,UserRD)"
                                           "VALUES (:Usuario,:Password,:Enc1,:Enc2,:Enc3,:Tipo,:Dir,:UserRD)");
                             Wdark.bindValue(":Usuario", DatUsuario);
                             Wdark.bindValue(":Password", DatPassword);
                             Wdark.bindValue(":Enc1", DatEnc1);
                             Wdark.bindValue(":Enc2", DatEnc2);
                             Wdark.bindValue(":Enc3", DatEnc3);
                             Wdark.bindValue(":Tipo", Tipo);
                             Wdark.bindValue(":Dir", Ubicacion);
                             Wdark.bindValue(":UserRD", UserRD);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 43)
            {
                if (LAscii=="Si")
                {
                    QSqlQuery wlistanegr(DBackup);
                    wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM Ascii");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(DBackup);
                    wlistanegra.exec("SELECT Decimal,Unicode FROM Ascii");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Listado de codigos Ascii... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatDecimal = wlistanegra.value(0).toString();
                         QString DatUnicode = wlistanegra.value(1).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT Decimal,Unicode FROM Ascii WHERE Decimal='"+DatDecimal+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DB);
                             Wdark.prepare("INSERT INTO Ascii (Decimal,Unicode)"
                                           "VALUES (:Decimal,:Unicode)");
                             Wdark.bindValue(":Decimal", DatDecimal);
                             Wdark.bindValue(":Unicode", DatUnicode);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
            if (i == 44)
            {
                if (Pais=="Si")
                {
                    QString Cantidad;
                    QSqlQuery query(DBackup);
                    query.exec("SELECT Tipo FROM Pais WHERE id=1");
                    query.first();
                    if (query.isValid())
                    {
                        Cantidad=query.value(0).toString();
                    }
                    QSqlQuery Miscelanea(DB);
                    Miscelanea.exec("UPDATE Pais SET Tipo='"+Cantidad+"' WHERE id=1");
                }
            }
            if (i == 45)
            {
                if (LBic=="Si")
                {
                    QSqlQuery wlistanegr(DBackup);
                    wlistanegr.exec("SELECT COUNT(Codigo) as Cantidad FROM Bic");
                    int cuenta, comienzo;
                    wlistanegr.first();
                    cuenta = wlistanegr.value(0).toInt();
                    QSqlQuery wlistanegra(DBackup);
                    wlistanegra.exec("SELECT Codigo,Nombre,Bic FROM Bic");
                    setUpdatesEnabled(false);
                    QProgressDialog progressMenu("Actualizando Listado de codigos BIC... Espera por favor", "Cancelar", 0, cuenta);
                    if (Stilo == "A")
                        progressMenu.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    progressMenu.show();
                    QTest::qWait(20);
                    comienzo=0;
                    int cantidad=1;
                    while(wlistanegra.next())
                    {
                         if (cantidad == 1)
                         {
                             DB.transaction();
                         }
                         progressMenu.setValue(comienzo++);
                         if (progressMenu.wasCanceled())
                             break;
                         QString DatCodigo = wlistanegra.value(0).toString();
                         QString DatNombre = wlistanegra.value(1).toString();
                         QString DatBic = wlistanegra.value(2).toString();
                         QSqlQuery RecDat(DB);
                         RecDat.exec("SELECT Codigo,Nombre,Bic FROM Bic WHERE Codigo='"+DatCodigo+"'");
                         RecDat.first();
                         if (RecDat.isSelect())
                         {
                             QSqlQuery Wdark(DB);
                             Wdark.prepare("INSERT INTO Bic (Codigo,Nombre,Bic)"
                                           "VALUES (:Codigo,:Nombre,:Bic)");
                             Wdark.bindValue(":Codigo", DatCodigo);
                             Wdark.bindValue(":Nombre", DatNombre);
                             Wdark.bindValue(":Bic", DatBic);
                             Wdark.exec();
                         }
                         cantidad++;
                         if (cantidad == 50)
                         {
                             cantidad=1;
                             DB.commit();
                         }
                    }
                    progressMenu.setValue(cuenta);
                    DB.commit();
                    setUpdatesEnabled(true);
                }
            }
        }
        progress.setValue(46);
        DBackup.close();
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(QString::fromUtf8(tr("Copia de seguridad "+ui->label_2->text()+" recuperada con exito.<p>Reinicia RecoverDrake para que todos los cambios sean efectivos.")));
        m.exec();
    }
}

bool Backup::eventFilter(QObject* obj, QEvent *event)
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
                ayuda->Valor(tr("Backup"));
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

void Backup::on_pushButton_4_clicked()
{
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                QString::fromUtf8(tr("<center><b>Eleccion manual de copia<b></center><p>"
                "Al realizar este paso no esta teniendo en cuenta el fichero de configuracion que "
                "se genera cuando se realiza la copia, por lo que al hacer la recuperacion sobre una copia directa "
                "se van a actualizar todas las bases de datos y no de forma personalizada.<p>"
                "&iquest;Buscar copia manualmente?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        QString path=tr("/home/%1/Documentos/");
        path=path.arg(user);
        QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo .sqlite")),
                            path,trUtf8(tr("Archivo .sqlite (*.sqlite)")));
        if (fileNameOrigen.isEmpty())
            return;
        ui->lineEdit->setText(fileNameOrigen);
    }
}

void Backup::on_pushButton_5_clicked()
{
    QString Valor = ui->comboBox->currentText();
    QString Value, Explora;
    QFile file("/usr/share/RecoverDrake/backup/"+Valor+"");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString datoslst = in.readAll();
    file.close();
    QStringList lista = datoslst.split("\n");
    for(int i=0;i<lista.count();i++)
    {
        Value = lista.value(i);
        if (i == 0)
        {
            Explora = Value;
            Explora.remove("Ruta: ");
            break;
        }
    }
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                QString::fromUtf8(tr("<center><b>Borrado de copia<b></center><p>"
                "Vas a proceder a borrar la copia seleccionada y es "
                "un proceso irreversible.<p>"
                "&iquest;Borrar copia seleccionada?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        system("rm -f /usr/share/RecoverDrake/backup/"+Valor+"");
        system("rm -f "+Explora+"");
        QMessageBox m;
        m.setWindowTitle(tr("Advertencia!!!"));
        m.setText(tr("Copia borrada... ")+Explora);
        m.exec();
        ui->radioButton_6->setChecked(true);
        ui->checkBox_12->setChecked(true);
        ui->checkBox_13->setChecked(true);
        ui->checkBox_14->setChecked(true);
        ui->checkBox_15->setChecked(true);
        ui->checkBox_18->setChecked(true);
        ui->checkBox_16->setChecked(true);
        ui->checkBox_54->setChecked(true);
        ui->checkBox_53->setChecked(true);
        ui->checkBox_55->setChecked(true);
        ui->checkBox_56->setChecked(true);
        ui->checkBox_58->setChecked(true);
        ui->checkBox_57->setChecked(true);
        ui->checkBox_61->setChecked(true);
        ui->checkBox_59->setChecked(true);
        ui->checkBox_63->setChecked(true);
        ui->checkBox_60->setChecked(true);
        ui->checkBox_65->setChecked(true);
        ui->checkBox_62->setChecked(true);
        ui->checkBox_66->setChecked(true);
        ui->checkBox_64->setChecked(true);
        ui->checkBox_68->setChecked(true);
        ui->checkBox_67->setChecked(true);
        ui->checkBox_69->setChecked(true);
        ui->checkBox_70->setChecked(true);
        ui->checkBox_72->setChecked(true);
        ui->checkBox_74->setChecked(true);
        ui->checkBox_76->setChecked(true);
        ui->checkBox_78->setChecked(true);
        ui->checkBox_82->setChecked(true);
        ui->checkBox_85->setChecked(true);
        ui->checkBox_9->setChecked(true);
        ui->checkBox_10->setChecked(true);
        ui->checkBox_31->setChecked(true);
        ui->checkBox_11->setChecked(true);
        ui->checkBox_46->setChecked(true);
        ui->checkBox_47->setChecked(true);
        ui->checkBox_48->setChecked(true);
        ui->checkBox_49->setChecked(true);
        ui->checkBox_51->setChecked(true);
        ui->checkBox_50->setChecked(true);
        ui->checkBox_52->setChecked(true);
        ui->checkBox_80->setChecked(true);
        ui->checkBox_84->setChecked(true);
        ui->checkBox_87->setChecked(true);
        ui->checkBox_90->setChecked(true);
        ui->checkBox_92->setChecked(true);
        ui->checkBox_94->setChecked(true);
        this->Comprobar();
        this->Comprobar1();
    }
}
