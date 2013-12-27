#include "kernel.h"
#include "ui_kernel.h"
#include <QSqlQuery>
#include <QFileDialog>
#include "drakesistema.h"
#include <QDebug>
#include <QMessageBox>

Kernel::Kernel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kernel)
{
    ui->setupUi(this);
    QString Terminado = getLink();
    QStringList Resultado = Terminado.split("->");
    QString Link = Resultado.value(Resultado.count()-1);
    ui->label_9->setText(""+Link+"");
    mib = 0;
    drakeSistema drake;
    user = drake.getUser();
    db=QSqlDatabase::database("PRINCIPAL");
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
    CierreTotal = 0;
    ui->radioButton_2->setChecked(true);
    ui->pushButton_2->setVisible(false);
    ui->label->setVisible(false);
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar()));
    ui->groupBox_2->setVisible(false);
    ui->radioButton_3->setChecked(true);
    Opcion = 0;
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    ui->groupBox_5->setVisible(false);
    ui->radioButton_5->setChecked(true);
    ui->radioButton_8->setChecked(true);
    Config = "menuconfig";
    connect(ui->radioButton_8,SIGNAL(clicked()),this,SLOT(Comprobar2()));
    connect(ui->radioButton_9,SIGNAL(clicked()),this,SLOT(Comprobar2()));
    connect(ui->radioButton_10,SIGNAL(clicked()),this,SLOT(Comprobar2()));
    connect(ui->radioButton_11,SIGNAL(clicked()),this,SLOT(Comprobar2()));
    ui->radioButton_12->setChecked(true);
    ui->label_7->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    ui->pushButton_10->setVisible(false);
    connect(ui->radioButton_12,SIGNAL(clicked()),this,SLOT(Comprobar3()));
    connect(ui->radioButton_13,SIGNAL(clicked()),this,SLOT(Comprobar3()));
    ui->pushButton_11->setVisible(false);
}

Kernel::~Kernel()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void Kernel::Valor(QString valor)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
}

void Kernel::on_pushButton_3_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void Kernel::closeEvent ( QCloseEvent * event )
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

void Kernel::Comprobar3()
{
    if (ui->radioButton_12->isChecked())
    {
        ui->label_7->setVisible(false);
        ui->lineEdit_3->setVisible(false);
        ui->pushButton_10->setVisible(false);
        ui->pushButton_8->setText(tr("Compilar Kernel"));
    }
    if (ui->radioButton_13->isChecked())
    {
        ui->label_7->setVisible(true);
        ui->lineEdit_3->setVisible(true);
        ui->pushButton_10->setVisible(true);
        ui->pushButton_8->setText(tr("Compilar Modulo"));
    }
}

void Kernel::Comprobar2()
{
    if (ui->radioButton_8->isChecked())
    {
        ui->groupBox_6->setVisible(true);
        Config = "menuconfig";
    }
    if (ui->radioButton_9->isChecked())
    {
        ui->groupBox_6->setVisible(false);
        Config = "xconfig";
    }
    if (ui->radioButton_10->isChecked())
    {
        ui->groupBox_6->setVisible(false);
        Config = "gconfig";
    }
    if (ui->radioButton_11->isChecked())
    {
        ui->groupBox_6->setVisible(false);
        Config = "config";
    }
}

void Kernel::Comprobar1()
{
    if (ui->radioButton_3->isChecked())
    {
        ui->groupBox->setVisible(true);
        ui->groupBox_5->setVisible(false);
    }
    if (ui->radioButton_4->isChecked())
    {
        ui->groupBox->setVisible(false);
        ui->groupBox_5->setVisible(true);
    }
}

void Kernel::Comprobar()
{
    if (ui->radioButton->isChecked())
    {
        ui->pushButton_2->setVisible(true);
        ui->pushButton->setVisible(false);
        ui->label->setVisible(true);
    }
    if (ui->radioButton_2->isChecked())
    {
        ui->pushButton_2->setVisible(false);
        ui->pushButton->setVisible(true);
        ui->label->setVisible(false);
    }
}

void Kernel::on_pushButton_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    QString path;
    path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo fuente de nucleo")),
                            path,trUtf8(tr("Ficheros de fuentes (*.tar.gz *.tar.xz *.tar.bz2 *.gz *.xz *.bz2)")));
    if (fileNameOrigen.isEmpty())
    {
       Opcion = 0;
       return;
    }
    ui->lineEdit->setText(fileNameOrigen);
    Opcion = 0;
}

void Kernel::on_pushButton_2_clicked()
{
    system("su - "+user+" -c \"firefox http://www.kernel.org\"");
    return;
}

void Kernel::on_pushButton_4_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }    
    int Value;
    QString Enlace = getEnlace();
    if (Enlace != "")
    {
        Value = 0;
    }
    else
    {
        Value = 1;
    }
    QStringList comandos;
    QString Valor=ui->lineEdit->text();
    QString md, md1, md3, md4, md6, md7, md61;
    QStringList Preparar;
    QString Localizar, Terminado;
    Localizar = ui->lineEdit->text();
    Preparar = Localizar.split("/");
    Terminado = Preparar.last();
    QStringList Tipo = Valor.split(".");
    if (ui->lineEdit->text() == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has introducido ninguna ruta para buscar el nucleo."));
        m.exec();
        Opcion = 0;
        return;
    }
    if (Tipo.value(Tipo.count()-1) != "gz" && Tipo.value(Tipo.count()-1) != "xz" && Tipo.value(Tipo.count()-1) != "bz2")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has introducido ninguna ruta valida para buscar el nucleo."));
        m.exec();
        Opcion = 0;
        return;
    }
    ui->pushButton_11->setVisible(true);
    ui->groupBox_2->setVisible(true);
    if (ui->radioButton->isChecked())
    {
        if (Valor.contains("http") || Valor.contains("ftp"))
        {
            md = tr("echo Descargando del servidor...");
            md1 = "wget -c -P/home/%1/tmp/ %2";
            md1=md1.arg(user).arg(Valor);
            md3 = tr("echo Copiando ficheros al directorio temporal y extrayendo nucleo...");
            if (Tipo.value(Tipo.count()-1) == "gz")
            {
                if (Tipo.value(Tipo.count()-2) == "tar")
                {
                    Terminado = Terminado.remove(".tar.gz");
                    md4 = "tar zxf /home/%1/tmp/%2.tar.gz --directory=/usr/src/";
                    md4 = md4.arg(user).arg(Terminado);
                }
                else
                {
                    Terminado = Terminado.remove(".gz");
                    md4 = "gzip -d /home/%1/tmp/%2.gz --directory=/usr/src/";
                    md4 = md4.arg(user).arg(Terminado);
                }
            }
            else if (Tipo.value(Tipo.count()-1) == "xz")
            {
                if (Tipo.value(Tipo.count()-2) == "tar")
                {
                    Terminado = Terminado.remove(".tar.xz");
                    md4 = "tar Jxvf /home/%1/tmp/%2.tar.xz --directory=/usr/src/";
                    md4 = md4.arg(user).arg(Terminado);
                }
                else
                {
                    Terminado = Terminado.remove(".xz");
                    md4 = "xz -d /home/%1/tmp/%2.xz --directory=/usr/src/";
                    md4 = md4.arg(user).arg(Terminado);
                }
            }
            else if (Tipo.value(Tipo.count()-1) == "bz2")
            {
                if (Tipo.value(Tipo.count()-2) == "tar")
                {
                    Terminado = Terminado.remove(".tar.bz2");
                    md4 = "tar jxvf /home/%1/tmp/%2.tar.bz2 --directory=/usr/src/";
                    md4 = md4.arg(user).arg(Terminado);
                }
                else
                {
                    Terminado = Terminado.remove(".bz2");
                    md4 = "bzip2 -d /home/%1/tmp/%2.bz2 --directory=/usr/src/";
                    md4 = md4.arg(user).arg(Terminado);
                }
            }
            comandos << md << md1 << md3 << md4;
            if (Value == 0)
            {
                md61 = tr("echo Eliminando enlace anterior...");
                md6 = "rm -vf /usr/src/linux";
                comandos << md61 << md6;
            }
            md7 = "ln -s /usr/src/%1 /usr/src/linux";
            md7=md7.arg(Terminado);
            comandos << md7;
            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
        }
        else
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("La direccion introducida es local. Utiliza la opcion de \"Ordenador\" para poder continuar o cambia la direccion."));
            m.exec();
            ui->groupBox_2->setVisible(false);
            ui->pushButton_11->setVisible(false);
            Opcion = 0;
            return;
        }
    }
    else if (ui->radioButton_2->isChecked())
    {
        if (Valor.contains("http") || Valor.contains("ftp"))
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("La direccion introducida no es local. Utiliza la opcion de \"Internet\" para poder continuar o cambia la direccion."));
            m.exec();
            ui->pushButton_11->setVisible(false);
            ui->groupBox_2->setVisible(false);
            Opcion = 0;
            return;
        }
        else
        {
            md3 = tr("echo Extrayendo nucleo...");
            if (Tipo.value(Tipo.count()-1) == "gz")
            {
                if (Tipo.value(Tipo.count()-2) == "tar")
                {
                    Terminado = Terminado.remove(".tar.gz");
                    md4 = "tar zxf \"%2\" --directory=/usr/src/";
                    md4 = md4.arg(Valor);
                }
                else
                {
                    Terminado = Terminado.remove(".gz");
                    md4 = "gzip -d \"%2\" --directory=/usr/src/";
                    md4 = md4.arg(Valor);
                }
            }
            else if (Tipo.value(Tipo.count()-1) == "xz")
            {
                if (Tipo.value(Tipo.count()-2) == "tar")
                {
                    Terminado = Terminado.remove(".tar.xz");
                    md4 = "tar Jxvf \"%2\" --directory=/usr/src/";
                    md4 = md4.arg(Valor);
                }
                else
                {
                    Terminado = Terminado.remove(".xz");
                    md4 = "xz -d \"%2\" --directory=/usr/src/";
                    md4 = md4.arg(Valor);
                }
            }
            else if (Tipo.value(Tipo.count()-1) == "bz2")
            {
                if (Tipo.value(Tipo.count()-2) == "tar")
                {
                    Terminado = Terminado.remove(".tar.bz2");
                    md4 = "tar jxvf \"%2\" --directory=/usr/src/";
                    md4 = md4.arg(Valor);
                }
                else
                {
                    Terminado = Terminado.remove(".bz2");
                    md4 = "bzip2 -d \"%2\" --directory=/usr/src/";
                    md4 = md4.arg(Valor);
                }
            }
            comandos << md3 << md4;
            if (Value == 0)
            {
                md61 = tr("echo Eliminando enlace anterior...");
                md6 = "rm -vf /usr/src/linux";
                comandos << md61 << md6;
            }
            md7 = "ln -s /usr/src/%1 /usr/src/linux";
            md7=md7.arg(Terminado);
            comandos << md7;
            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
        }
    }
}

void Kernel::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
}

void Kernel::mibprogreso(QString Dat)
{
    ui->progressBar->setValue(Dat.toInt());
}

void Kernel::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    Opcion=0;
    ui->progressBar->setValue(0);
    ui->groupBox_2->setVisible(false);
    ui->pushButton_11->setVisible(false);
}

QString Kernel::getEnlace()
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "/usr/src/linux";
    procesoRPM->start("ls",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res =  QString(Paquete);
    res.chop(1);
    return res;
}

QString Kernel::getLink()
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "-l" << "/usr/src/linux";
    procesoRPM->start("ls",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res =  QString(Paquete);
    res.chop(1);
    return res;
}

void Kernel::on_pushButton_9_clicked()
{
    if (ui->groupBox_2->isVisible())
    {
        ui->pushButton_9->setText(tr("Mostrar consola"));
        ui->groupBox_2->setVisible(false);
    }
    else
    {
        ui->pushButton_9->setText(tr("Ocultar consola"));
        ui->groupBox_2->setVisible(true);
    }
}

void Kernel::on_pushButton_5_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    QString path;
    path="/usr/src/";
    QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio a buscar?"),path,QFileDialog::ShowDirsOnly);
    if (fileNameDirectori.isEmpty())
    {
        Opcion = 0;
        return;
    }
    QString fileName = fileNameDirectori.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    ui->lineEdit_2->setText(fileName);
    Opcion = 0;
}

void Kernel::on_pushButton_6_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    ui->groupBox_2->setVisible(true);
    ui->pushButton_11->setVisible(true);
    int Value;
    QString Valor = ui->lineEdit_2->text();
    QStringList comandos;
    QString md6, md7, md61;
    QString Enlace = getEnlace();
    if (Enlace != "")
    {
        Value = 0;
    }
    else
    {
        Value = 1;
    }
    if (ui->lineEdit_2->text() == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has introducido ninguna ruta para buscar el nucleo."));
        m.exec();
        ui->groupBox_2->setVisible(false);
        ui->pushButton_11->setVisible(false);
        Opcion = 0;
        return;
    }
    if (Value == 0)
    {
        md61 = tr("echo Eliminando enlace anterior...");
        md6 = "rm -vf /usr/src/linux";
        comandos << md61 << md6;
    }
    md7 = "ln -s %1 /usr/src/linux";
    md7=md7.arg(Valor);
    comandos << md7;
    if (mib != 0)
    delete mib;
    mib = new DrakeProcesos1(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
}

void Kernel::on_pushButton_7_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    int Value;
    QStringList comandos;
    QString md1, md2, md3, md4, md5;
    QString Enlace = getEnlace();
    if (Enlace != "")
    {
        Value = 0;
    }
    else
    {
        Value = 1;
    }
    if (Value == 1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No esta creado el enlace para compilar el nucleo. Realiza el enlace para poder continuar."));
        m.exec();
        Opcion = 0;
        return;
    }
    ui->groupBox_2->setVisible(true);
    ui->pushButton_11->setVisible(true);
    if (ui->radioButton_5->isChecked())
    {
        md1 = tr("echo Realizando limpieza...");
        md2 = "make -C /usr/src/linux/ clean";
        md3 = "make -C /usr/src/linux/ mrproper";
        md4 = tr("echo Accediendo a la configuracion del nucleo...");
        md5 = "konsole --nofork --workdir /usr/src/linux/ -e make %1";
        md5 = md5.arg(Config);
        comandos << md1 << md2 << md3 << md4 << md5;
        if (mib != 0)
        delete mib;
        mib = new DrakeProcesos1(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
    }
    else if (ui->radioButton_6->isChecked())
    {
        md1 = tr("echo Realizando limpieza...");
        md2 = "make -C /usr/src/linux/ clean";
        md3 = "make -C /usr/src/linux/ mrproper";
        md4 = tr("echo Accediendo a la configuracion del nucleo...");
        md5 = "konsole --nofork --workdir /usr/src/linux/ -e make oldconfig";
        comandos << md1 << md2 << md3 << md4 << md5;
        if (mib != 0)
        delete mib;
        mib = new DrakeProcesos1(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
    }
    else if (ui->radioButton_7->isChecked())
    {
        md1 = tr("echo Realizando limpieza...");
        md2 = "make -C /usr/src/linux/ clean";
        md3 = "make -C /usr/src/linux/ mrproper";
        md4 = tr("echo Accediendo a la configuracion del nucleo...");
        md5 = "konsole --nofork --workdir /usr/src/linux/ -e make localmodconfig";
        comandos << md1 << md2 << md3 << md4 << md5;
        if (mib != 0)
        delete mib;
        mib = new DrakeProcesos1(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
    }
}

void Kernel::on_pushButton_8_clicked()
{
    QString Terminado = getLink();
    QStringList Resultado = Terminado.split("-");
    QString Link = Resultado.value(Resultado.count()-1);
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    int Value;
    QStringList comandos;
    QString md1, md2, md3, md4, md5, md6;
    QString Enlace = getEnlace();
    if (Enlace != "")
    {
        Value = 0;
    }
    else
    {
        Value = 1;
    }
    if (Value == 1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No esta creado el enlace para compilar el nucleo. Realiza el enlace para poder continuar."));
        m.exec();
        Opcion = 0;
        return;
    }
    ui->groupBox_2->setVisible(true);
    ui->pushButton_11->setVisible(true);
    if (ui->radioButton_12->isChecked())
    {
        md1 = tr("echo Realizando compilacion...");
        md2 = "make -C /usr/src/linux";
        md3 = "make -C /usr/src/linux/ install";
        md4 = "make -C /usr/src/linux/ modules_install";
        md5 = "mkinitrd /boot/initrd-%1.img %1";
        md5 = md5.arg(Link);
        md6 = "update-grub";
        comandos << md1 << md2 << md3 << md4  << md5 << md6;
    }
    else if (ui->radioButton_13->isChecked())
    {
        if (ui->lineEdit_3->text() == "")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No has insertado ninguna ruta para poder compilar."));
            m.exec();
            Opcion = 0;
            ui->groupBox_2->setVisible(false);
            ui->pushButton_11->setVisible(false);
            return;
        }
        md1 = tr("echo Insertando modulo...");
        md2 = "make -C /usr/src/linux modules_prepare";
        md3 = "make -C /usr/src/linux/ M=%1 modules";
        md3 = md3.arg(ui->lineEdit_3->text());
        md4 = "make -C /usr/src/linux/ modules_install";
        comandos << md1 << md2 << md3 << md4;
    }
    if (mib != 0)
    delete mib;
    mib = new DrakeProcesos1(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
}

void Kernel::on_pushButton_10_clicked()
{
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Como saber la ruta del modulo")),
                QString::fromUtf8(tr("<center><b>Localizar ruta del modulo</center><p>"
                           "1º Localizar el modulo que nos falta desde menuconfig y ademas de "
                           "marcarlo, tambien copiamos su ruta.<p>"
                           "Ejemplo:<p>"
                           "Supongamos que se nos ha olvidado el soporte para USB 3.0: <p>"
                           "Abrimos el menuconfig y nos vamos hasta donde esta el modulo "
                           "y mostramos la ayuda pulsando \"shift + ?\".<p>"
                           "Nos fijamos en la parte que dice \"Defined at:\"<p>"
                           "En este caso la ruta seria: drivers/usb/host/<p>"
                           "2º Esa ruta es la que hay que utilizar para compilar el modulo.<p>")), QMessageBox::Ok);
    if (respuesta == QMessageBox::Ok)
    {
        return;
    }
}

void Kernel::on_pushButton_11_clicked()
{
    mib->killProceso();
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
}
