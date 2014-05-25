#include "makefile.h"
#include "ui_makefile.h"
#include "drakesistema.h"
#include <QFileDialog>
#include "drakeprocesos.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

makefile::makefile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::makefile)
{
    ui->setupUi(this);
    mib=0;
    drakeSistema drake;
    user = drake.getUser();
    ui->radioButton_3->setChecked(true);
    ui->radioButton->setChecked(true);
    ui->groupBox_3->setEnabled(true);
    ui->groupBox_4->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit->setEnabled(true);
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Instalar()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Desinstalar()));
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar()));
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
    CierreTotal = 0;
    this->installEventFilter(this);
}

makefile::~makefile()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void makefile::Valor(QString valor)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
}

void makefile::on_pushButton_2_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void makefile::closeEvent ( QCloseEvent * event )
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

void makefile::Instalar()
{
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->label_2->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
    ui->label->setEnabled(true);
    ui->checkBox_5->show();
    ui->checkBox_6->setText(tr("Contiene fichero de instalacion"));
    ui->label_2->setText(tr("Ruta de instalacion alternativa"));
    if (Valor1 != "")
    {
        ui->checkBox_6->setEnabled(true);
        ui->checkBox_6->setChecked(true);
    }
    else if (Valor1 != "")
    {
        ui->checkBox_6->setEnabled(false);
        ui->checkBox_6->setChecked(false);
    }
    ui->groupBox_3->setEnabled(true);
    ui->groupBox_4->setEnabled(false);
}

void makefile::Desinstalar()
{
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->label->setEnabled(false);
    ui->checkBox_5->hide();
    ui->checkBox_6->setText(tr("Contiene fichero de desinstalacion"));
    ui->label_2->setText(tr("Ruta de desinstalacion"));
    ui->checkBox_6->setEnabled(false);
    ui->checkBox_6->setChecked(false);
    ui->groupBox_3->setEnabled(false);
    ui->groupBox_4->setEnabled(true);
}

void makefile::on_pushButton_3_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de fuentes")),
                        path,trUtf8(tr("Todos los ficheros de fuentes soportados (*.tar.gz)")));
    if (fileNameOrigen.isEmpty())
        return;
    ui->lineEdit->setText(fileNameOrigen);
}

void makefile::Comprobar()
{
    if (ui->radioButton->isChecked() == true)
    {
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit->setEnabled(true);
    }
    if (ui->radioButton_2->isChecked() == true)
    {
        ui->lineEdit_2->setEnabled(true);
        ui->lineEdit->setEnabled(false);
    }
}

void makefile::on_pushButton_4_clicked()
{
    if (ui->lineEdit->text() == "" && ui->lineEdit_2->text() == "" && ui->lineEdit_3->text() == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay una ruta seleccionada para poder realizar el proceso."));
        m.exec();
        return;
    }
    QStringList Preparar;
    QStringList comandos;
    QString Localizar, Terminado, md, md1, md2, md3, md4, md5, cmd33, cmd34;
    if (ui->lineEdit_3->text() != "")
    {
        if (ui->radioButton_3->isChecked() == true)
        {
            md3 = tr("echo Comprobando ficheros de instalacion y configuracion...");
        }
        else if (ui->radioButton_3->isChecked() == false)
        {
            md3 = tr("echo Comprobando ficheros de desinstalacion...");
        }
        comandos <<md3;
        if (mib != 0)
            delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        if (ui->radioButton_3->isChecked() == true)
        {
            connect(mib, SIGNAL(finProceso()), this, SLOT(Instalacion()));
        }
        else if (ui->radioButton_3->isChecked() == false)
        {
            connect(mib, SIGNAL(finProceso()), this, SLOT(Desinstalacion()));
        }
        int valor= comandos.count(); mib->Valor(valor,3); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
    }
    else
    {
        if (ui->radioButton_3->isChecked() == true)
        {
            drakeSistema drake;
            QString Temporal = drake.getFind("/home/"+user+"/tmp/");
            if (Temporal != "home/"+user+"/tmp")
            {
                cmd33 = tr("echo Creando carpeta temporal...");
                cmd34 = "mkdir /home/%1/tmp/";
                cmd34 = cmd34.arg(user);
                comandos << cmd33 << cmd34;
            }
            if (ui->radioButton->isChecked() == true)
            {
                md1 = tr("echo Copiando ficheros al directorio temporal y extrayendo...");
                md2 = "tar xvzf \"%2\" --directory=/home/%1/tmp/";
                md2 = md2.arg(user).arg(fileNameOrigen);
                md3 = tr("echo Comprobando ficheros de instalacion y configuracion...");
                comandos << md1 << md2 << md3;
            }
            else if (ui->radioButton_2->isChecked() == true)
            {
                Localizar = ui->lineEdit_2->text();
                Preparar = Localizar.split("/");
                Terminado = Preparar.last();
                Terminado = Terminado.remove(".tar.gz");
                md = tr("echo Descargando del servidor...");
                md1 = "wget -c -P/home/%1/tmp/ %2";
                md1=md1.arg(user).arg(ui->lineEdit->text());
                md3 = tr("echo Copiando ficheros al directorio temporal y extrayendo...");
                md4 = "tar xvzf /home/%1/tmp/%2.tar.gz --directory=/home/%1/tmp/";
                md4 = md4.arg(user).arg(Terminado);
                md5 = tr("echo Comprobando ficheros de instalacion y configuracion...");
                comandos << md << md1 << md3 << md4 << md5;
            }
            if (mib != 0)
                delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            connect(mib, SIGNAL(finProceso()), this, SLOT(Instalacion()));
            int valor= comandos.count(); mib->Valor(valor,3); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
        }
        else if (ui->radioButton_3->isChecked() == false)
        {
            md5 = tr("echo Comprobando ficheros de desinstalacion...");
            comandos << md5;
            if (mib != 0)
                delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            connect(mib, SIGNAL(finProceso()), this, SLOT(Desinstalacion()));
            int valor= comandos.count(); mib->Valor(valor,3); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
        }
    }
}

void makefile::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));    
}

void makefile::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
}

QString makefile::getName(QString Validar)
{
    QProcess *procesoFree;
    QByteArray FreeTotal;
    procesoFree=new QProcess(this);
    procesoFree->start(Validar);
    if (! procesoFree->waitForStarted())
        return QString("");
    procesoFree->waitForFinished();
    FreeTotal = procesoFree->readAllStandardOutput();
    delete procesoFree;
    QString res = QString(FreeTotal);
    res.chop(0);
    return res;
}

void makefile::Instalacion()
{
    QStringList Preparar, Validar;
    QString Terminado, Servidor, Localizar, Resto, Comprobar, Valor, Rastreo;
    drakeSistema drake;
    if (ui->lineEdit_3->text() != "")
    {
        QString md1 = "find \"%1\" -name Makefile";
        md1 = md1.arg(ui->lineEdit_3->text());
        QString md2 = "find \"%1\" -name configure";
        md2 = md2.arg(ui->lineEdit_3->text());
        Valor1 = drake.getStart(md1);
        Valor2 = drake.getStart(md2);
    }
    else
    {
        if (ui->radioButton->isChecked() == true)
        {
            Localizar = ui->lineEdit->text();
        }
        else if (ui->radioButton_2->isChecked() == true)
        {
            Servidor = ui->lineEdit_2->text();
            Preparar = Servidor.split("/");
            Resto = Preparar.last();
            Localizar = "/home/%1/tmp/%2";
            Localizar =  Localizar.arg(user).arg(Resto);
        }
        Comprobar = "tar tf \"%1\"";
        Comprobar = Comprobar.arg(Localizar);
        Terminado = getName(Comprobar);
        Validar = Terminado.split("/");
        Valor = Validar.value(0);
        Rastreo = "/home/"+user+"/tmp/"+Valor+"";
        QString md1 = "find \"%1\" -name Makefile";
        md1 = md1.arg(Rastreo);
        QString md2 = "find \"%1\" -name configure";
        md2 = md2.arg(Rastreo);
        Valor1 = drake.getStart(md1);
        Valor2 = drake.getStart(md2);
    }
    if (Valor1 != "")
    {
        ui->checkBox_2->setChecked(true);
        ui->checkBox_3->setChecked(true);
        ui->checkBox_2->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
        ui->checkBox_6->setChecked(true);
        ui->checkBox_6->setEnabled(true);
        ui->textEdit->append(tr("Se encuentra fichero de instalacion."));
    }
    else if (Valor1 == "")
    {
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        ui->checkBox_2->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
        ui->checkBox_6->setChecked(false);
        ui->checkBox_6->setEnabled(false);
        ui->textEdit->append(tr("No se encuentra fichero de instalacion. Busca manualmente el fichero."));
    }
    if (Valor2 != "")
    {
        ui->checkBox->setChecked(true);
        ui->checkBox->setEnabled(true);
        ui->checkBox_5->setChecked(true);
        ui->checkBox_5->setEnabled(true);
        ui->textEdit->append(tr("Se encuentra fichero de configuracion."));
    }
    else if (Valor2 == "")
    {
        ui->checkBox->setChecked(false);
        ui->checkBox->setEnabled(false);
        ui->checkBox_5->setChecked(false);
        ui->checkBox_5->setEnabled(false);
        ui->textEdit->append(tr("No se encuentra fichero de configuracion."));
    }
}

void makefile::Desinstalacion()
{
    QString val;
    int pos, valor=0;
    QFile file(""+fileNameDirectori+"/Makefile");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString datoslst = in.readAll();
    file.close();
    QStringList lista = datoslst.split(" ");
    val = "uninstall";
    for(int i=0;i<lista.count();i++)
    {
        QString verlo=QString::fromUtf8(lista.value(i));        
        pos = verlo.indexOf(val, 0);
        if (pos != -1)
        {
            valor++;
        }
    }
    if (valor > 0)
    {
        ui->checkBox_7->setChecked(true);
        ui->checkBox_7->setEnabled(true);
        ui->checkBox_6->setChecked(true);
        ui->checkBox_6->setEnabled(true);
        ui->textEdit->append(tr("Se encuentra fichero de desinstalacion."));
    }
    else
    {
        ui->checkBox_7->setChecked(false);
        ui->checkBox_7->setEnabled(false);
        ui->checkBox_6->setChecked(false);
        ui->checkBox_6->setEnabled(false);
        ui->textEdit->append(tr("No se encuentra fichero de desinstalacion."));
    }
}

void makefile::on_pushButton_clicked()
{
    if (ui->lineEdit->text() == "" && ui->lineEdit_2->text() == "" && ui->lineEdit_3->text() == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay una ruta seleccionada para poder realizar el proceso."));
        m.exec();
        return;
    }
    QStringList Preparar, Validar, comandos;;
    QString Terminado, Servidor, Localizar, Resto, Comprobar, Valor, Rastreo, md1, md2, md4;
    if (ui->radioButton->isChecked() == true)
    {
        Localizar = ui->lineEdit->text();
    }
    else if (ui->radioButton_2->isChecked() == true)
    {
        Servidor = ui->lineEdit_2->text();
        Preparar = Servidor.split("/");
        Resto = Preparar.last();
        Localizar = "/home/%1/tmp/%2";
        Localizar =  Localizar.arg(user).arg(Resto);
    }
    Comprobar = "tar tf \"%1\"";
    Comprobar = Comprobar.arg(Localizar);
    Terminado = getName(Comprobar);
    Validar = Terminado.split("/");
    Valor = Validar.value(0);
    Rastreo = "/home/"+user+"/tmp/"+Valor+"";
    if (ui->checkBox->isChecked() == true)
    {        
        md1 = tr("echo Ejecutando configure...");
        if (ui->lineEdit_3->text() != "")
        {
            md2 = "\"%1\"/configure";
            md2=md2.arg(ui->lineEdit_3->text());
        }
        else
        {
            md2 = "/home/%1/tmp/%2/configure";
            md2 = md2.arg(user).arg(Rastreo);
        }
        comandos << md1 << md2;
    }
    if (ui->checkBox_2->isChecked() == true)
    {
        md1 = tr("echo Probando make...");
        if (ui->lineEdit_3->text() != "")
        {
            md2 = "make \"--directory=%1\"/";
            md2=md2.arg(ui->lineEdit_3->text());
        }
        else
        {
            md2 = "make --directory=/home/%1/tmp/%2/";
            md2 = md2.arg(user).arg(Rastreo);
        }
        comandos << md1 << md2;
    }
    if (ui->checkBox_3->isChecked() == true)
    {
        md1 = tr("echo Realizando instalacion...");
        if (ui->lineEdit_3->text() != "")
        {
            md2 = "make install \"--directory=%1/\"";
            md2=md2.arg(ui->lineEdit_3->text());
        }
        else
        {
            md2 = "make install --directory=/home/%1/tmp/%2/";
            md2 = md2.arg(user).arg(Rastreo);
        }
        comandos << md1 << md2;
    }
    if (ui->checkBox_4->isChecked() == true)
    {
        md1 = tr("echo Realizando limpieza...");
        if (ui->lineEdit_3->text() != "")
        {
            md2 = "make clean \"--directory=%1/\"";
            md2=md2.arg(ui->lineEdit_3->text());
        }
        else
        {
            md2 = "make clean --directory=/home/%1/tmp/%2/";
            md2 = md2.arg(user).arg(Rastreo);
        }
        md4 = "rm -vR -f /home/%1/tmp/%2/";
        md4=md4.arg(user).arg(Terminado);
        comandos << md1 << md2 << md4;
    }
    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count(); mib->Valor(valor,3); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
}

void makefile::on_pushButton_5_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    fileNameDirectori = QFileDialog::getExistingDirectory(this,QString::fromUtf8(tr("Que directorio utilizar?")),path,QFileDialog::ShowDirsOnly);
    if (fileNameDirectori.isEmpty())
        return;
    ui->lineEdit_3->setText(fileNameDirectori);
}

void makefile::on_pushButton_6_clicked()
{
    if (ui->lineEdit->text() == "" && ui->lineEdit_2->text() == "" && ui->lineEdit_3->text() == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay una ruta seleccionada para poder realizar el proceso."));
        m.exec();
        return;
    }
    QStringList comandos;
    QString md1, md2, md3, md4, md5, md6, md7;
    md1 = tr("echo Realizando desinstalacion...");
    md2 = "make uninstall \"--directory=%1\"/";
    md2=md2.arg(fileNameDirectori);
    md3 = tr("echo Desinstalacion realizada.");
    md4 = tr("echo Realizando limpieza...");
    md5 = "make clean \"--directory=%1\"/";
    md5=md5.arg(fileNameDirectori);
    md6 = "rm -vR -f \"%1\"";
    md6=md6.arg(fileNameDirectori);
    md7 = tr("echo Limpieza realizada.");
    comandos << md1 << md2 << md3 << md4 << md5 << md6 << md7;
    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count(); mib->Valor(valor,3); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
}

bool makefile::eventFilter(QObject* obj, QEvent *event)
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
