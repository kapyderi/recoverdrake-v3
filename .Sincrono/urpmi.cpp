#include "urpmi.h"
#include "ui_urpmi.h"
#include "drakeprocesos.h"
#include "drakesistema.h"
#include <QTest>
#include <QMessageBox>
#include <QProgressDialog>
#include <QDebug>
#include <QSqlQuery>

urpmi::urpmi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::urpmi)
{
    ui->setupUi(this);
    mib=0;
    drakeSistema drake;
    Distro = drake.getDistrop();
    dist = drake.getDistribucion();
    arqt = drake.getArquitectura();
    if (Distro == "Mandriva")
    {
        ui->label_3->setEnabled(false);
        ui->checkBox_10->setEnabled(false);
        ui->checkBox_11->setEnabled(false);
        ui->checkBox_5->setChecked(true);
        ui->checkBox_6->setChecked(true);
        ui->checkBox_7->setChecked(true);
        ui->checkBox_8->setChecked(true);
        ui->checkBox_9->setChecked(true);
    }
    else if (Distro == "Mageia")
    {
        ui->label_2->setEnabled(false);
        ui->checkBox_5->setEnabled(false);
        ui->checkBox_6->setEnabled(false);
        ui->checkBox_7->setEnabled(false);
        ui->checkBox_8->setEnabled(false);
        ui->checkBox_9->setEnabled(false);
        ui->checkBox_10->setChecked(true);
        ui->checkBox_11->setChecked(true);
    }
    Cambio=0;
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
}

urpmi::~urpmi()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void urpmi::changeEvent(QEvent *e)
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

void urpmi::Valor(QString valor)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
}

void urpmi::on_pushButton_2_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void urpmi::closeEvent ( QCloseEvent * event )
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

void urpmi::on_pushButton_14_clicked()
{
    int Borrado, x;
    Borrado = ui->tableWidget->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
         int Contador = ui->tableWidget->rowCount();
         ui->lineEdit_2->setText(QString::number(Contador));
    }
    ui->textEdit->append(tr("Realizando proceso seleccionado y recopilando los datos solicitados... espera por favor, puede tardar unos segundos."));
    int iFilas;
    drakeSistema drake;
    repo = drake.getRepositorio();
    QString Local1 = getDatos();
    QStringList Datos = Local1.split("\n");
    lista = repo.split("\n");
    if (lista.count() == 1)
    {
        if (lista.value(0) == "")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No hay repositorios que procesar."));
            m.exec();
            return;
        }
    }
    setUpdatesEnabled(false);
    QProgressDialog progress(tr("Comprobando repositorios... Espera por favor"), tr("Cancelar"), 0, lista.count(), this);
    progress.show();
    QTest::qWait(20);
    QString Local2 = getDatos1();
    QStringList DatosUp = Local2.split("\n");
    for(int i=0;i<lista.count();i++)
    {
        qApp->processEvents();
        progress.setValue(i);
        if (progress.wasCanceled())
            break;
        Value0 = lista.value(i);
        if (Value0 != "")
        {
            Value1="";
            Value2="";
            Value3="";
            ui->textEdit->append(tr("Procesando... ")+Value0+tr("(Registro: ")+QString::number(i)+")");
            if (Local1 != "")
            {               
                for(int a=0;a<Datos.count();a++)
                {
                    QString verlo=QString::fromUtf8(Datos.value(a));
                    int pos1 = verlo.indexOf(Value0, 0);
                    if (pos1 != -1)
                    {
                        Value1 = tr("Si");
                    }                    
                }
            }
                for(int b=0;b<DatosUp.count();b++)
                {
                    QString verlo1=QString::fromUtf8(DatosUp.value(b));
                    int pos2 = verlo1.indexOf(Value0, 0);
                    if (pos2 != -1)
                    {
                        Value3 = tr("Si");
                    }
                }
                QTableWidgetItem *item1, *item2, *item3, *item4, *item5;
                item1=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                item3=new QTableWidgetItem;
                item4=new QTableWidgetItem;
                item5=new QTableWidgetItem;
                item1->setText("Ok");
                item2->setText(""+Value0+"");                
                item3->setText(""+Value1+"");
                if (Value1=="")
                {
                    Value2 = tr("Si");
                }
                item4->setText(""+Value2+"");
                item5->setText(""+Value3+"");
                iFilas=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(iFilas);
                ui->tableWidget->setItem(iFilas,0,item1);
                ui->tableWidget->setItem(iFilas,1,item2);
                ui->tableWidget->setItem(iFilas,2,item3);
                ui->tableWidget->setItem(iFilas,3,item4);
                ui->tableWidget->setItem(iFilas,4,item5);
                ui->tableWidget->item(iFilas,0)->setIcon(QIcon(":/Imagenes/good.png"));
                int Contador = ui->tableWidget->rowCount();
                ui->lineEdit_2->setText(QString::number(Contador+1));
        }
    }
    progress.setValue(lista.count());
    setUpdatesEnabled(true);
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

QString urpmi::getDatos()
{
    QProcess *procesoUrpmi;
    QStringList argumentosUrpmi;
    QByteArray Paquete;

    procesoUrpmi=new QProcess(this);

    argumentosUrpmi << "--list-media" << "active";

    procesoUrpmi->start("urpmq",argumentosUrpmi);

    if (! procesoUrpmi->waitForStarted())
        return QString("");

    procesoUrpmi->waitForFinished();

    Paquete = QString(procesoUrpmi->readAllStandardOutput());

    delete procesoUrpmi;
    QString res = QString(Paquete);
    res.chop(1);
    return res;
}

QString urpmi::getDatos1()
{
    QProcess *procesoUrpmi;
    QStringList argumentosUrpmi;
    QByteArray Paquete;

    procesoUrpmi=new QProcess(this);

    argumentosUrpmi << "--update";

    procesoUrpmi->start("urpmi.update",argumentosUrpmi);

    if (! procesoUrpmi->waitForStarted())
        return QString("");

    procesoUrpmi->waitForFinished();

    Paquete = QString(procesoUrpmi->readAllStandardOutput());

    delete procesoUrpmi;
    QString res = QString(Paquete);
    res.chop(1);
    return res;
}

void urpmi::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
}

void urpmi::ProcesarValor(QString ValorComand)
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
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void urpmi::mibprogreso(QString Dat)
{
    ui->progressBar->setValue(Dat.toInt());
}

void urpmi::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    ui->progressBar->setValue(0);
    if (Cambio == 0)
    {
        this->on_pushButton_14_clicked();
    }
    else
    {
        Cambio=0;
    }
}

void urpmi::on_pushButton_6_clicked()
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
            ui->tableWidget->setItem(a,0,item);
        }
     }
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void urpmi::on_pushButton_7_clicked()
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
            ui->tableWidget->setItem(a,0,item);
        }
     }
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void urpmi::on_pushButton_3_clicked()
{
    int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Eliminar repositorios")),
               QString::fromUtf8(tr("<center><b>Eliminar repositorios configurados</b></center><p>"

                  "<b>IMPORTANTE:</b> Esta opcion solo es valida, si los repositorios "
                  "estan fallando, ya que los elimina y los vuelve a crear con "
                  "una nueva configuracion.<p>"

                  "Proceda con cuidado!!!<p>"

                  "Como su nombre indica, tras una instalacion limpia, se "
                  "quedan instalados como repositorios los soportes del "
                  "DVD/CD de instalacion, pues con esta opcion se pueden "
                  "eliminar y dejar limpios todos los soportes.<p>"

                  "Tambien sirve cuando tienes algun grupo de repositorios "
                  "\"problematicos\" y quieres cambiarlos o cualquier otro tipo "
                  "de problemas de configuracion de los mismos.<p>"

                  "<B>NOTA: Debes esperar a que termine completamente el proceso seleccionado, "
                  "el cual le sera notificado cuando finalice en la consola de procesos.</B><p>"

                  "&iquest;Eliminar repositorios instalados?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok){

    QString cmd =QString::fromUtf8(tr("echo Eliminando repositorios..."));
    QString comando="urpmi.removemedia -a";

    QStringList comandos;
    comandos<< cmd << comando;

    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count(); mib->Valor(valor,0); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();}
    return;
}

void urpmi::on_pushButton_10_clicked()
{
    int iFilas;
    QString valor1, valor2, valor3;
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
        QTableWidgetItem *item1, *item2, *item3;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        item1=ui->tableWidget->item(iFilas,1);
        item2=ui->tableWidget->item(iFilas,2);
        item3=ui->tableWidget->item(iFilas,3);
        valor1=item1->text();
        valor2=item2->text();
        valor3=item3->text();
        if(valor3 == tr("Si"))
        {            
            item2->setText(tr("Si"));
            item3->setText("");
            ui->tableWidget->setItem(iFilas,2,item2);
            ui->tableWidget->setItem(iFilas,3,item3);
            Cambio=1;
            QString cmd =QString::fromUtf8(tr("echo Activando repositorio %1..."));
            cmd=cmd.arg(valor1);
            QString comando="urpmi.update --no-ignore \"%1\"";
            comando=comando.arg(valor1);
            QStringList comandos;
            comandos<< cmd << comando;
            if (mib != 0)
                delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count();
            mib->Valor(valor,0);
            mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
            mib->iniciarProceso();
        }
        else if (valor3 != tr("Si"))
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("El repositorio ya esta activo por lo que no puedes volver a activarlo."));
            m.exec();
            return;
        }
    }
}

void urpmi::on_pushButton_12_clicked()
{
    int iFilas;
    QString valor1, valor2, valor3;
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
        QTableWidgetItem *item1, *item2, *item3;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        item1=ui->tableWidget->item(iFilas,1);
        item2=ui->tableWidget->item(iFilas,2);
        item3=ui->tableWidget->item(iFilas,3);
        valor1=item1->text();
        valor2=item2->text();
        valor3=item3->text();
        if(valor2 == tr("Si"))
        {
            item2->setText("");
            item3->setText(tr("Si"));
            ui->tableWidget->setItem(iFilas,2,item2);
            ui->tableWidget->setItem(iFilas,3,item3);
            Cambio=1;
            QString cmd =QString::fromUtf8(tr("echo Desactivando repositorio %1..."));
            cmd=cmd.arg(valor1);
            QString comando="urpmi.update --ignore \"%1\"";
            comando=comando.arg(valor1);
            QStringList comandos;
            comandos<< cmd << comando;
            if (mib != 0)
                delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count();
            mib->Valor(valor,0);
            mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
            mib->iniciarProceso();
        }
        else if (valor2 != tr("Si"))
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("El repositorio ya esta activo por lo que no puedes volver a activarlo."));
            m.exec();
            return;
        }
    }
}

void urpmi::on_pushButton_11_clicked()
{
    int iFilas;
    QStringList comandos;
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
        item1=ui->tableWidget->item(iFilas,1);
        valor=item->text();
        valor1= item1->text();
        QString cmd =QString::fromUtf8(tr("echo Eliminando repositorio seleccionado..."));
        comandos<< cmd;
        if(valor == "Ok")
        {
            QString comando="urpmi.removemedia \"%1\"";
            comando=comando.arg(valor1);
            comandos<< comando;
        }
        if (mib != 0)
            delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count(); mib->Valor(valor,0); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
    }
}

void urpmi::on_pushButton_5_clicked()
{
    QStringList comandos;
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Instalar todos los repositorios")),
               QString::fromUtf8(tr("<center><b>Instalar todos los repositorios</b></center><p>"

                  "Este apartado realiza la instalacion masiva de todos "
                  "los repositorios incluidos por defectos, como pueden "
                  "ser OFICIALES, PLF, MIB, BDK y MUD.<P> "

                  "<B>NOTA: Debes esperar a que termine completamente el proceso seleccionado, "
                  "el cual le sera notificado cuando finalice en la consola de procesos.</B><p>"

                  "&iquest;Configurar todos los repositorios?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        QString cmd=QString::fromUtf8(tr("echo Instalando repositorios seleccionados..."));
        comandos << cmd;
        if (ui->checkBox_5->isChecked() || ui->checkBox_10->isChecked())
        {
            QString cmd1 = "urpmi.addmedia --wget --distrib --mirrorlist";
            comandos << cmd1;
        }
        if(Distro=="Mandriva")
        {
            if (ui->checkBox_6->isChecked())
            {
                QString cmd2 = "urpmi.addmedia --wget --distrib --mirrorlist \"http://plf.zarb.org/mirrors/%1.%2.list\"";
                cmd2 = cmd2.arg(dist).arg(arqt);
                comandos << cmd2;
            }
            if (ui->checkBox_7->isChecked())
            {
                QString cmd3 = "urpmi.addmedia --wget --update MIB-basic_32 http://mib.pianetalinux.org/MIB/%1/32/basic/ with media_info/synthesis.hdlist.cz" ;
                cmd3 = cmd3.arg(dist);
                QString cmd4 = "urpmi.addmedia --wget MIB-experts_32 http://mib.pianetalinux.org/MIB/%1/32/experts/ with media_info/synthesis.hdlist.cz";
                cmd4 =  cmd4.arg(dist);
                comandos << cmd3 << cmd4;
            }
        }
        if (ui->checkBox_8->isChecked() || ui->checkBox_11->isChecked())
        {
            QString cmd5;
            if(Distro=="Mandriva")
            {
                if (dist == "2010.2")
                {
                    dist = "2010.1";
                }
                if (dist == "2011.0")
                {
                    cmd5 ="urpmi.addmedia --wget --distrib --nopubkey ftp://ftp.blogdrake.net/mandriva/%1/%2";
                    cmd5 = cmd5.arg(dist).arg(arqt);
                }
                else
                {
                    cmd5 ="urpmi.addmedia --wget --distrib ftp://ftp.blogdrake.net/mandriva/%1/%2";
                    cmd5 = cmd5.arg(dist).arg(arqt);
                }
            }
            else if (Distro=="Mageia")
            {
                cmd5 ="urpmi.addmedia --wget --distrib ftp://ftp.blogdrake.net/mageia/mageia%1/%2";
                cmd5 = cmd5.arg(dist).arg(arqt);
            }
            comandos << cmd5;
        }
        if(Distro=="Mandriva")
        {
            if (ui->checkBox_9->isChecked())
            {
                QString cmd6;
                if (dist == "2011.0")
                {
                    cmd6 = "echo No es posible configurar este repositorio en este momento.";
                }
                else
                {
                    cmd6 = "urpmi.addmedia --wget MUD-%2 ftp://ftp.mandrivauser.de/rpm/GPL/%1/%2/release/ with media_info/synthesis.hdlist.cz";
                    cmd6 = cmd6.arg(dist).arg(arqt);
                    comandos << cmd6;
                }
            }
        }
        if (mib != 0)
            delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count(); mib->Valor(valor,0); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
    }
    return;
}
