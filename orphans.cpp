#include "orphans.h"
#include "ui_orphans.h"
#include <QTest>
#include <QProcess>
#include <QMessageBox>
#include "drakesistema.h"
#include "drakeprocesos.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QSqlQuery>

orphans::orphans(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::orphans)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Stilo = "B";
    drakeSistema drake;
    user = drake.getUser();
    Distro = drake.getDistrop();
    mib=0;
    grabar=0;
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
    ui->pushButton->hide();
}

orphans::~orphans()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void orphans::on_pushButton_14_clicked()
{
    ui->pushButton->hide();
    grabar=0;
    this->on_pushButton_8_clicked();
    int iFilas;
    ui->textEdit->append(tr("Se paciente y espera a que termine la comprobacion de paquetes que han quedado huerfanos..."));
    QTest::qWait(20);
    QString Local = getRpm();
    lista = Local.split("\n");
    if (lista.count() == 1)
    {
        if (lista.value(0) == "")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Nada que eliminar.<p>Todos los paquetes huerfanos estan desinstalados."));
            m.exec();
            return;
        }
    }
    ui->progressBar->setRange(0,lista.count());
    for(int i=0;i<lista.count();i++)
    {
        Value = lista.value(i);
        if (Value != "")
        {
            QString Val1 = lista.value(i).right(7);
            if (Val1 != "writing")
            {
                ui->textEdit->append(tr("Procesando... ")+Value+tr("(Registro: ")+QString::number(i)+")");
                QTableWidgetItem *item1, *item2;
                item1=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                item1->setText("Ok");
                item2->setText(""+Value+"");
                iFilas=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(iFilas);
                ui->tableWidget->setItem(iFilas,0,item1);
                ui->tableWidget->setItem(iFilas,1,item2);
                ui->tableWidget->item(iFilas,0)->setIcon(QIcon(":/Imagenes/good.png"));
                ui->progressBar->setValue(i);
            }
        }        
    }
    ui->progressBar->setValue(lista.count());
    int Contador = ui->tableWidget->rowCount();
    ui->lineEdit_2->setText(QString::number(Contador));
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

QString orphans::getRpm()
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "--auto-orphans";
    procesoRPM->start("urpmq",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    delete procesoRPM;
    QString res = QString(Paquete);
    res.chop(1);
    return res;
}

void orphans::Valor(QString valor)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
}

void orphans::on_pushButton_2_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void orphans::closeEvent ( QCloseEvent * event )
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

void orphans::on_pushButton_6_clicked()
{
    grabar = 0;
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

void orphans::on_pushButton_7_clicked()
{
    grabar = 0;
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
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void orphans::on_pushButton_10_clicked()
{
    grabar = 0;
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
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void orphans::on_pushButton_12_clicked()
{
    grabar = 0;
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
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void orphans::on_pushButton_11_clicked()
{
    grabar = 0;
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
    this->on_pushButton_8_clicked();
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void orphans::on_pushButton_13_clicked()
{
    grabar = 1;
    QTableWidgetItem *item, *item1;
    QString activo, activo1;
    QStringList comandos;
    int itemCount = ui->tableWidget->rowCount();
    if (itemCount == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QString cmd = QString::fromUtf8("echo Realizando procesos...");
        comandos<< cmd;
        for(int i=0;i<itemCount;i++)
        {
            item = ui->tableWidget->item(i,0);
            item1 = ui->tableWidget->item(i,1);            
            activo = item->text();
            activo1 = item1->text();
            if (activo == "Ok")
            {
                QString cmd1 = "urpme --auto %1";
                cmd1=cmd1.arg(activo1);
                comandos<< cmd1;
            }
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

void orphans::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
}

void orphans::ProcesarValor(QString ValorComand)
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

void orphans::mibprogreso(QString Dat)
{
    ui->progressBar->setValue(Dat.toInt());
}

void orphans::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    ui->progressBar->setValue(0);
    if (grabar == 1)
    {
       this->on_pushButton_5_clicked();
    }
    this->on_pushButton_14_clicked();
}

void orphans::on_pushButton_3_clicked()
{
    grabar = 1;
    QTableWidgetItem *item, *item1;
    QString activo, activo1;
    QStringList comandos;
    int itemCount = ui->tableWidget->rowCount();
    QString cmd = QString::fromUtf8("echo Realizando procesos...");
    comandos<< cmd;
    for(int i=0;i<itemCount;i++)
    {
        item = ui->tableWidget->item(i,0);
        item1 = ui->tableWidget->item(i,1);
        activo = item->text();
        activo1 = item1->text();
        if (activo == "Ok")
        {
            QString cmd1 = "urpme --auto %1";
            cmd1=cmd1.arg(activo1);
            comandos<< cmd1;
        }
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

void orphans::on_pushButton_4_clicked()
{
    grabar = 0;
    int iFilas;
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo .lst")),
                        path,trUtf8(tr("Archivo .lst (*.lst)")));
    if (fileNameOrigen.isEmpty())
         return;
    QFile file(""+fileNameOrigen+"");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString datoslst = in.readAll();
    file.close();
    lista = datoslst.split(" ");
    for(int i=0;i<lista.count();i++)
    {
        Value0 = lista.value(i);
        if (Value0 != "")
        {
            QTableWidgetItem *item1, *item2;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item1->setText("Ok");
            item2->setText(""+Value0+"");
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->item(iFilas,0)->setIcon(QIcon(":/Imagenes/good.png"));
            int Contador = ui->tableWidget->rowCount();
            ui->lineEdit_2->setText(QString::number(Contador+1));
        }
    }
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    ui->pushButton->show();
}

void orphans::on_pushButton_5_clicked()
{
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Grabar listado de paquetes eliminados")),
                     QString::fromUtf8(tr("<center><b>Grabar listado de paquetes eliminados<b></center><p>"

                "Puedes grabar una copia de los paquetes que has eliminado para llevar un control en caso de "
                "inestabilidad del sistema.<p>"

                "&iquest;Grabar listado de paquetes huerfanos desinstalados?")), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok)
    {
        grabar = 0;
        QString Fecha = QDate::currentDate().toString("ddMMyyyy");
        QString Nombre = "PackOrphan";
        QString path="/home/%1/Documentos/%2%3%4.lst";
        path=path.arg(user).arg(Nombre).arg(Distro).arg(Fecha);
        QString fileNameDestino = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar archivo .lst")),
                            path,trUtf8(tr("Archivo .lst (*.lst)")));
        if (fileNameDestino.isEmpty())
             return;
        QFile file(""+fileNameDestino+".lst");
        file.open(QIODevice::WriteOnly | QIODevice::Truncate);
        QTextStream in(&file);
        QString activo, activo1;
        int itemCount = ui->tableWidget->rowCount();
        ui->progressBar->setRange(0,itemCount);
        ui->textEdit->append(tr("Creando fichero en ruta ")+fileNameDestino+".lst");
        for(int i=0;i<itemCount;i++)
        {
            QTableWidgetItem *item, *item1;
            item=new QTableWidgetItem;
            item1=new QTableWidgetItem;
            item = ui->tableWidget->item(i,0);
            item1 = ui->tableWidget->item(i,1);
            activo = item->text();
            activo1 = item1->text();
            if (activo == "Ok")
            {
                in << activo1 + " ";
            }
            ui->progressBar->setValue(i);
        }
        ui->progressBar->setValue(itemCount);
        ui->textEdit->append(tr("Fichero creado correctamente."));
        file.close();
        ui->progressBar->setRange(0,100);
        ui->progressBar->setValue(0);
    }
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    return;
}

void orphans::on_pushButton_8_clicked()
{
    grabar = 0;
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
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void orphans::on_pushButton_clicked()
{
    grabar = 0;
    QTableWidgetItem *item, *item1;
    QString activo, activo1;
    QStringList comandos;
    int itemCount = ui->tableWidget->rowCount();
    if (itemCount == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QString cmd = QString::fromUtf8("echo Realizando proceso de recuperacion...");
        comandos<< cmd;
        for(int i=0;i<itemCount;i++)
        {
            item = ui->tableWidget->item(i,0);
            item1 = ui->tableWidget->item(i,1);
            activo = item->text();
            activo1 = item1->text();
            if (activo == "Ok")
            {
                QString cmd1 = "urpmi --auto %1";
                cmd1=cmd1.arg(activo1);
                comandos<< cmd1;
            }
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
