#include "Mrpm.h"
#include "ui_Mrpm.h"
#include <QFile>
#include "drakesistema.h"
#include "drakeprocesos.h"
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>
#include <QStringList>
#include <QSqlQuery>
#include <QTest>
#include <QDate>
#include <QProgressDialog>
#include <QKeyEvent>
#include <QThread>
#include <QtConcurrentRun>
#include <QFuture>
#include <QDebug>

Mrpm::Mrpm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mrpm)
{
    ui->setupUi(this);
    QFuture<void> f1 = QtConcurrent::run(this, &Mrpm::Recibir);
    db=QSqlDatabase::database("PRINCIPAL");
    drakeSistema drake;
    user = drake.getUser();
    Distro = drake.getDistrop();
    mib = 0;
    Comprobado = 0;
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(true);
    ui->checkBox_4->setChecked(false);
    ui->progressBar->hide();
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
    connect(ui->checkBox_5,SIGNAL(clicked()),this,SLOT(Comprobar()));
    ui->textEdit->clear();
    CierreTotal = 0;
    Opcion = 0;
    Comprueba = "No";
    Evento = 0;
    ui->pushButton_16->setEnabled(false);
    ui->pushButton_17->setEnabled(false);
    ui->pushButton_18->setEnabled(false);    
    this->installEventFilter(this);
    ui->lineEdit->setFocus();
}

Mrpm::~Mrpm()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void Mrpm::Recibir()
{
    QString RecDat = getDatos();
    RecDat = RecDat.remove("'");
    Listado = RecDat.split(" ");
}

void Mrpm::Comprobar()
{
    if (ui->checkBox_5->isChecked())
    {
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        Comprobado = 1;
    }
    else
    {
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
        Comprobado = 0;
    }
}

void Mrpm::Valor(QString valor, QString Logs)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
    if (Logs == "S")
        Log = "S";
    else
        Log = "N";
}

void Mrpm::on_pushButton_2_clicked()
{
    if (CierreTotal == 1)
    {
        if (Log == "S")
        {
            system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
        }
        emit Cerrar();
    }
    else
    {
        if (Log == "S")
        {
            system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
        }
        close();
    }
}

void Mrpm::closeEvent ( QCloseEvent * event )
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

void Mrpm::on_pushButton_4_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }   
    int j=ui->tableWidget->rowCount();
    if (j > 0)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                    QString::fromUtf8(tr("<center><b>Nueva lista de datos<b></center><p>"
                    "Hay registros ya cargados anteriormente, si cargas una nueva lista "
                    "se borraran los datos anteriormente cargados.<p>"
                    "&iquest;Continuar con una nueva lista?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::No)
        {
            Opcion = 0;
            return;
        }
        else
        {
            int Borrado, x;
            Borrado = ui->tableWidget->rowCount();
            for(x=0;x<Borrado;x++)
            {
                 ui->tableWidget->removeRow(x);
                 x=x-1;
                 Borrado=Borrado-1;
            }
        }
    }
    int iFilas;
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo .lst")),
                        path,trUtf8(tr("Archivo .lst (*.lst)")));
    if (fileNameOrigen.isEmpty())
    {
        Opcion = 0;
        return;
    }
    QFile file(fileNameOrigen);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString datoslst = in.readAll();
    file.close();
    lista = datoslst.split(" ");
    if (lista.count() == 1)
    {
        if (lista.value(0) == "")
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Nada que procesar.<p>Todos los paquetes estan correctamente cargados o no hay paquetes en la lista cargada."));
            m.exec();
            Opcion = 0;
            return;
        }
    }
    int Contador;
    setUpdatesEnabled(false);
    QProgressDialog progress(tr("Cargando lista de rpms... Espera por favor"), tr("Cancelar"), 0, lista.count(),this);
    progress.show();
    QTableWidgetItem *item1, *item2, *item3, *item4, *item5, *item6;
    for(int i=0;i<lista.count();i++)
    {       
        qApp->processEvents();
        progress.setValue(i);
        if (progress.wasCanceled())
        {
            Opcion = 0;
            break;
        }
        Value0 = lista.value(i);
        if (Value0 != "")
        {
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            item5=new QTableWidgetItem;
            item6=new QTableWidgetItem;
            item1->setText(""+Value0+"");
            item2->setText(" ");
            item3->setText(" ");
            item4->setText(" ");
            item5->setText(" ");
            item6->setText(" ");
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->setItem(iFilas,2,item3);
            ui->tableWidget->setItem(iFilas,3,item4);
            ui->tableWidget->setItem(iFilas,4,item5);
            ui->tableWidget->setItem(iFilas,5,item6);
            Contador = ui->tableWidget->rowCount();
            ui->lineEdit_2->setText(QString::number(Contador+1));
        }
    }
    progress.setValue(lista.count());    
    setUpdatesEnabled(true);
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    if (ui->lineEdit->text() != "")
    {
        Opcion = 0;
        on_pushButton_13_clicked();
    }
    Opcion = 0;
}

void Mrpm::on_pushButton_5_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    int iFilas, a;
    QString activo, Local, Local1, Local2, Local3;
    iFilas=ui->tableWidget->currentRow();
    if (iFilas == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        Opcion = 0;
        return;
    }
    else
    {
        QTableWidgetItem *item, *item2, *item3, *item4, *item5;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        item4=new QTableWidgetItem;
        item5=new QTableWidgetItem;
        item = ui->tableWidget->item(ui->tableWidget->currentRow(),0);
        activo = item->text();
        Local = getPack(activo);
        if (Local.contains("Name") == false)
        {
            Local="...";
            Local1 = getRpm2(activo);
            if (Local1 == "")
            {
                Local1="...";
                Local2="...";
                Local3="...";
            }
            else
            {
                QStringList Datos = Local1.split("\n");
                QString Val1 = "Name        : ";
                QString Val2 = "Summary     : ";
                QString Val3 = "Group       : ";
                for(a=0;a<Datos.count();a++)
                {
                    QString verlo=QString::fromUtf8(Datos.value(a));
                    int pos1 = verlo.indexOf(Val1, 0);
                    int pos2 = verlo.indexOf(Val2, 0);
                    int pos3 = verlo.indexOf(Val3, 0);
                    if (pos1 != -1)
                    {
                        Value0 = Datos.at(a);
                    }
                    if (pos2 != -1)
                    {
                        Value1 = Datos.at(a);
                    }
                    if (pos3 != -1)
                    {
                        Value2 = Datos.at(a);
                    }
                    Value0 = QString::fromUtf8(Value0.remove(Val1));
                    Value1 = QString::fromUtf8(Value1.remove(Val2));
                    Value2 = QString::fromUtf8(Value2.remove(Val3));
                    Local1=""+Value0+"";
                    Local2=""+Value1+"";
                    Local3=""+Value2+"";
                }
            }
        }
        else
        {
            QStringList Dat = Local.split("\n");
            QString Val = "Name        : ";
            Local = Dat.value(0);
            Local = Local.remove(Val);
            QString Val2 = "Summary     : ";
            QString Val3 = "Group       : ";
            for(a=0;a<Dat.count();a++)
            {
                QString verlo=QString::fromUtf8(Dat.value(a));
                int pos2 = verlo.indexOf(Val2, 0);
                int pos3 = verlo.indexOf(Val3, 0);
                if (pos2 != -1)
                {
                    Value1 = Dat.at(a);
                }
                if (pos3 != -1)
                {
                    Value2 = Dat.at(a);
                }
                Value1 = QString::fromUtf8(Value1.remove(Val2));
                Value2 = QString::fromUtf8(Value2.remove(Val3));
                Local1=Local;
                Local2=""+Value1+"";
                Local3=""+Value2+"";
            }
        }
        item2->setText(""+Local+"");
        item3->setText(""+Local1+"");
        item4->setText(""+Local2+"");
        item5->setText(""+Local3+"");
        ui->tableWidget->setItem(iFilas,1,item2);
        ui->tableWidget->setItem(iFilas,2,item3);
        ui->tableWidget->setItem(iFilas,3,item4);
        ui->tableWidget->setItem(iFilas,4,item5);
        int Contador = ui->tableWidget->rowCount();        
        ui->lineEdit_2->setText(QString::number(Contador));        
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    Opcion = 0;
}

QString Mrpm::getPack(QString activo)
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "-q" << "--info" << ""+activo+"";
    procesoRPM->start("rpm",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res = QString(Paquete);
    res.chop(1);
    return res;
}

QString Mrpm::getRpm2(QString activo)
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "-i" << ""+activo+"";
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

void Mrpm::on_pushButton_6_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    int j;
    j=ui->tableWidget->rowCount();
    if (j == 0)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay registros para procesar."));
        m.exec();
        Opcion = 0;
        return;
    }
    else
    {
        ui->progressBar->show();
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Comprobar paquetes de la lista")),
                    QString::fromUtf8(tr("<center><b>Comprobar paquetes de la lista<b></center><p>"
                    "Mediante este proceso realizamos la comprobacion uno por uno de la disponibilidad "
                    "de los paquetes en sus repositorios, incluyendo informacion interesante de si esta "
                    "instalado, si se puede instalar, observaciones (en Ingles) y categoria (en Ingles).<p>"
                    "Este proceso puede ser muy prolongado, dependiendo de los paquetes que haya en la lista, "
                    "por lo que recomiendo que anteriormente se haya realizado la opcion de "
                    "\"Evitar palabras clave\" o \"Evitar instalados\" ya que lo que pudiera ser conflictivo "
                    "o instalado ya se habra desestimado disminuyendo el tiempo de espera para que termine el proceso.<p>"
                    "&iquest;Comprobar paquetes de la lista?")), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok)
        {
            Evento = 0;
            ui->pushButton_16->setEnabled(true);
            QString activo, Local, Local1, Local2, Local3;
            int itemCount = ui->tableWidget->rowCount();
            ui->progressBar->setRange(0,itemCount);
            ui->textEdit->append(tr("Este proceso puede ser muy prolongado segun paquetes a comprobar."));
            ui->textEdit->append(tr("Se paciente y espera a que termine la comprobacion..."));
            QTableWidgetItem *item,*item2,*item3,*item4,*item5;
            for(int i=0;i<itemCount;i++)
            {
                qApp->processEvents();
                if (Evento == 1)
                {
                    ui->textEdit->append(tr("Trabajo cancelado"));
                    ui->pushButton_16->setEnabled(false);
                    return;
                }
                item=0;item2=0;item3=0;item4=0;item5=0;
                item=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                item3=new QTableWidgetItem;
                item4=new QTableWidgetItem;
                item5=new QTableWidgetItem;
                item = ui->tableWidget->item(i,0);
                activo = item->text();
                ui->textEdit->append(tr("Comprobando... ")+activo+tr("(Registro: ")+QString::number(i)+")");
                Local = getPack(activo);
                if (Local.contains("Name") == false)
                {
                    Local="...";
                    Local1 = getRpm2(activo);
                    if (Local1 == "")
                    {
                        Local1="...";
                        Local2="...";
                        Local3="...";
                    }
                    else
                    {
                        QStringList Datos = Local1.split("\n");
                        QString Val1 = "Name        : ";
                        QString Val2 = "Summary     : ";
                        QString Val3 = "Group       : ";
                        for(int a=0;a<Datos.count();a++)
                        {
                            QString verlo=QString::fromUtf8(Datos.value(a));
                            int pos1 = verlo.indexOf(Val1, 0);
                            int pos2 = verlo.indexOf(Val2, 0);
                            int pos3 = verlo.indexOf(Val3, 0);
                            if (pos1 != -1)
                            {
                                Value0 = Datos.at(a);
                            }
                            if (pos2 != -1)
                            {
                                Value1 = Datos.at(a);
                            }
                            if (pos3 != -1)
                            {
                                Value2 = Datos.at(a);
                            }
                            Value0 = QString::fromUtf8(Value0.remove(Val1));
                            Value1 = QString::fromUtf8(Value1.remove(Val2));
                            Value2 = QString::fromUtf8(Value2.remove(Val3));
                            Local1=""+Value0+"";
                            Local2=""+Value1+"";
                            Local3=""+Value2+"";
                        }
                    }
                }
                else
                {
                    QStringList Dat = Local.split("\n");
                    QString Val = "Name        : ";
                    Local = Dat.value(0);
                    Local = Local.remove(Val);
                    QString Val2 = "Summary     : ";
                    QString Val3 = "Group       : ";
                    for(int a=0;a<Dat.count();a++)
                    {
                        QString verlo=QString::fromUtf8(Dat.value(a));
                        int pos2 = verlo.indexOf(Val2, 0);
                        int pos3 = verlo.indexOf(Val3, 0);
                        if (pos2 != -1)
                        {
                            Value1 = Dat.at(a);
                        }
                        if (pos3 != -1)
                        {
                            Value2 = Dat.at(a);
                        }
                        Value1 = QString::fromUtf8(Value1.remove(Val2));
                        Value2 = QString::fromUtf8(Value2.remove(Val3));
                        Local1=Local;
                        Local2=""+Value1+"";
                        Local3=""+Value2+"";
                    }
                }
                item2->setText(""+Local+"");
                item3->setText(""+Local1+"");
                item4->setText(""+Local2+"");
                item5->setText(""+Local3+"");
                ui->tableWidget->setItem(i,1,item2);
                ui->tableWidget->setItem(i,2,item3);
                ui->tableWidget->setItem(i,3,item4);
                ui->tableWidget->setItem(i,4,item5);
                ui->tableWidget->selectRow(i);
                ui->progressBar->setValue(i);
            }            
            ui->progressBar->setValue(itemCount);
            int Contador = ui->tableWidget->rowCount();
            ui->lineEdit_2->setText(QString::number(Contador));
            Comprobado=1;
            ui->progressBar->setRange(0,100);
            ui->progressBar->setValue(0);
            ui->progressBar->hide();
            ui->tableWidget->resizeColumnsToContents();
            ui->tableWidget->resizeRowsToContents();
        }
    }
    Opcion = 0;
}

void Mrpm::on_pushButton_7_clicked()
{  
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
        int i,j;
        i=0;
        j=ui->tableWidget->rowCount();
        if (j == 0)
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No hay registros para procesar."));
            m.exec();
            Opcion = 0;
            return;
        }
        else
        {
            if (Comprobado == 0)
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Los registros cargados no han sido comprobados. Tienes que comprobar la disponibilidad de todos para poder realizar este proceso."));
                m.exec();
                Opcion = 0;
                return;
            }
            else if (Comprobado == 1)
            {
                ui->progressBar->show();
                Evento = 0;
                ui->pushButton_16->setEnabled(true);
                QString valor, valor1;
                QTableWidgetItem *item, *item1;
                for(i=0;i<j;i++)
                {
                    ui->progressBar->setRange(0,j);
                    qApp->processEvents();
                    if (Evento == 1)
                    {
                        ui->textEdit->append(tr("Trabajo cancelado"));
                        ui->pushButton_16->setEnabled(false);
                        return;
                    }
                    item=0;
                    item1=0;
                    item=ui->tableWidget->item(i,2);
                    item1=ui->tableWidget->item(i,1);
                    valor=item->text();
                    valor1=item1->text();
                    if(valor=="...")
                    {
                        ui->tableWidget->removeRow(i);
                        i=i-1;
                        j=j-1;
                    }
                    else if(valor1 != "...")
                    {
                        ui->tableWidget->removeRow(i);
                        i=i-1;
                        j=j-1;
                    }
                    ui->progressBar->setValue(i);
                    int Contador = ui->tableWidget->rowCount();
                    ui->lineEdit_2->setText(QString::number(Contador));
                }
                ui->progressBar->setValue(j);
                ui->progressBar->setRange(0,100);
                ui->progressBar->setValue(0);
                ui->progressBar->hide();
            }
        }
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();
        Opcion = 0;
}

void Mrpm::on_pushButton_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    QString opcion="";
    QString Opcion1="";
    QString Opcion2="";
    QString Opcion3="";
    if (ui->checkBox->isChecked())
    {
        opcion = "--a";
    }
    if (ui->checkBox_2->isChecked())
    {
        Opcion1 = "--force";
    }
    if (ui->checkBox_3->isChecked())
    {
        Opcion2 = "--auto";
    }
    if (ui->checkBox_4->isChecked())
    {
        Opcion3 = "--fuzzy";
    }
    QTableWidgetItem *item, *item1;
    QString activo, activo1;
    QStringList comandos;
    int itemCount = ui->tableWidget->rowCount();
    if (itemCount == 0)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ninguna lista cargada para procesar."));
        m.exec();
        Opcion = 0;
        return;
    }
    else
    {
        if (Comprobado == 0)
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Los registros cargados no han sido comprobados.<p>Tienes que comprobar la disponibilidad de todos para poder realizar este proceso o desmarcar la casilla de \"No realizar comprobacion\""));
            m.exec();
            Opcion = 0;
            return;
        }
        else if (Comprobado == 1)
        {
            ui->progressBar->show();
            TotalProceso = 0;
            Comprueba = "Si";
            Evento = 0;
            ui->pushButton_16->setEnabled(true);
            QString cmd = QString::fromUtf8(tr("echo Realizando procesos..."));
            comandos<< cmd;
            for(int i=0;i<itemCount;i++)
            {
                qApp->processEvents();
                if (Evento == 1)
                {
                    ui->textEdit->append(tr("Trabajo cancelado"));
                    ui->pushButton_16->setEnabled(false);
                    ui->progressBar->setValue(0);
                    ui->progressBar->hide();
                    return;
                }
                item = ui->tableWidget->item(i,2);
                item1 = ui->tableWidget->item(i,0);
                activo = item->text();
                activo1 = item1->text();
                if (activo != "..." && activo != " ")
                {
                    QString cmd1 = "urpmi %1 %2 %3 %4 %5";
                    cmd1=cmd1.arg(opcion).arg(Opcion1).arg(Opcion2).arg(Opcion3).arg(activo);
                    comandos<< cmd1;
                }
                else
                {
                    QString cmd1 = "urpmi %1 %2 %3 %4 %5";
                    cmd1=cmd1.arg(opcion).arg(Opcion1).arg(Opcion2).arg(Opcion3).arg(activo1);
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
            int valor= comandos.count();
            mib->Valor(valor,0);
            mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
            mib->iniciarProceso();
            Totalizar = comandos.count();
            ui->progressBar->setRange(0,Totalizar);

        }
    }
}

void Mrpm::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
    if (Log == "S")
    {
        system(QString::fromUtf8("echo '"+valor+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
    }
}

void Mrpm::ProcesarValor(QString ValorComand)
{
    int iFilas, a;
    QString valor, valor1;
    iFilas=ui->tableWidget->rowCount();
    QTableWidgetItem *item, *item1, *item2;
    for(a=0;a<iFilas;a++)
    {
        item=ui->tableWidget->item(a,2);
        item1=ui->tableWidget->item(a,5);
        item2=ui->tableWidget->item(a,0);
        valor=item->text();
        valor1=item2->text();        
        if (valor == " ")
            valor=valor1;
        if(ValorComand.contains(valor))
        {
            ui->tableWidget->item(a,5)->setIcon(QIcon(":/Imagenes/good.png"));
            item1->setText(tr("Hecho"));
            ui->tableWidget->setItem(iFilas,5,item1);
            ui->tableWidget->selectRow(a);
        }
     }
     TotalProceso = TotalProceso+1;
     ui->progressBar->setValue(TotalProceso);
}

void Mrpm::mibprogreso(QString Dat)
{
    if (Comprueba == "No")
        ui->progressBar->setValue(Dat.toInt());
}

void Mrpm::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    if (TotalProceso == Totalizar)
    {
        Comprueba = "No";
        ui->pushButton_16->setEnabled(false);
        ui->progressBar->setValue(0);
        ui->progressBar->hide();
        Opcion = 0;
    }
}

void Mrpm::on_pushButton_8_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    QString opcion="";
    QString Opcion1="";
    QString Opcion2="";
    QString Opcion3="";
    if (ui->checkBox->isChecked())
    {
        opcion = "--a";
    }
    if (ui->checkBox_2->isChecked())
    {
        Opcion1 = "--force";
    }

    if (ui->checkBox_3->isChecked())
    {
        Opcion2 = "--auto";
    }
    if (ui->checkBox_4->isChecked())
    {
        Opcion3 = "--fuzzy";
    }
    int iFilas;
    QString activo;
    QStringList comandos;
    iFilas=ui->tableWidget->currentRow();
    if (iFilas == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        Opcion = 0;
        return;
    }
    else
    {
        QTableWidgetItem *item;
        QString cmd = QString::fromUtf8(tr("echo Realizando procesos..."));
        comandos<< cmd;
        item = ui->tableWidget->item(iFilas,2);
        activo = item->text();
        if (activo == " ")
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No has verificado la integridad del paquete, por lo que no puedes procesar la solicitud."));
            m.exec();
            Opcion = 0;
            return;
        }
        else
        {
            if (activo != "...")
            {
                QString cmd1 = "urpmi %1 %2 %3 %4 %5";
                cmd1=cmd1.arg(opcion).arg(Opcion1).arg(Opcion2).arg(Opcion3).arg(activo);
                comandos<< cmd1;
            }
            if (mib != 0)
                delete mib;
            ui->progressBar->show();
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count();
            mib->Valor(valor,0);
            mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
            mib->iniciarProceso();            
            Totalizar = comandos.count();
            ui->progressBar->setRange(0,Totalizar);
        }
    }
}

void Mrpm::on_pushButton_10_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    int iFilas;
    QString activo, Local1, Local2, Local3, activo2;
    iFilas=ui->tableWidget->currentRow();
    if (iFilas == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        Opcion = 0;
        return;
    }
    else
    {
        QTableWidgetItem *item, *item2,*item3, *item4, *item5, *item6;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        item4=new QTableWidgetItem;
        item5=new QTableWidgetItem;
        item6=new QTableWidgetItem;
        item = ui->tableWidget->item(ui->tableWidget->currentRow(),0);
        item2 = ui->tableWidget->item(ui->tableWidget->currentRow(),1);
        activo = item->text();
        activo2 = item2->text();
        if (activo2 == " ")
        {
            QString Local = getPack(activo);
            if (Local.contains("Name") == false)
            {
                Local="...";
                Local1 = getRpm2(activo);
                if (Local1 == "")
                {
                    Local1="...";
                    Local2="...";
                    Local3="...";
                }
                else
                {
                    QStringList Datos = Local1.split("\n");
                    QString Val1 = "Name        : ";
                    QString Val2 = "Summary     : ";
                    QString Val3 = "Group       : ";
                    for(int a=0;a<Datos.count();a++)
                    {
                        QString verlo=QString::fromUtf8(Datos.value(a));
                        int pos1 = verlo.indexOf(Val1, 0);
                        int pos2 = verlo.indexOf(Val2, 0);
                        int pos3 = verlo.indexOf(Val3, 0);
                        if (pos1 != -1)
                        {
                            Value0 = Datos.at(a);
                        }
                        if (pos2 != -1)
                        {
                            Value1 = Datos.at(a);
                        }
                        if (pos3 != -1)
                        {
                            Value2 = Datos.at(a);
                        }
                        Value0 = QString::fromUtf8(Value0.remove(Val1));
                        Value1 = QString::fromUtf8(Value1.remove(Val2));
                        Value2 = QString::fromUtf8(Value2.remove(Val3));
                        Local1=""+Value0+"";
                        Local2=""+Value1+"";
                        Local3=""+Value2+"";
                    }
                }
            }
            else
            {
                QStringList Dat = Local.split("\n");
                QString Val = "Name        : ";
                Local = Dat.value(0);
                Local = Local.remove(Val);
                QString Val2 = "Summary     : ";
                QString Val3 = "Group       : ";
                for(int a=0;a<Dat.count();a++)
                {
                    QString verlo=QString::fromUtf8(Dat.value(a));
                    int pos2 = verlo.indexOf(Val2, 0);
                    int pos3 = verlo.indexOf(Val3, 0);
                    if (pos2 != -1)
                    {
                        Value1 = Dat.at(a);
                    }
                    if (pos3 != -1)
                    {
                        Value2 = Dat.at(a);
                    }
                    Value1 = QString::fromUtf8(Value1.remove(Val2));
                    Value2 = QString::fromUtf8(Value2.remove(Val3));
                    Local1=Local;
                    Local2=""+Value1+"";
                    Local3=""+Value2+"";
                }
            }
            item2->setText(""+Local+"");
            item3->setText(""+Local1+"");
            item4->setText(""+Local2+"");
            item5->setText(""+Local3+"");
            item6->setText("Ok");
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->setItem(iFilas,2,item3);
            ui->tableWidget->setItem(iFilas,3,item4);
            ui->tableWidget->setItem(iFilas,4,item5);
            ui->tableWidget->setItem(iFilas,5,item6);
        }
        else
        {
            item6->setText("Ok");
            ui->tableWidget->setItem(iFilas,5,item6);
        }
        int Contador = ui->tableWidget->rowCount();
        ui->lineEdit_2->setText(QString::number(Contador));
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();
    }
    Opcion = 0;
}

void Mrpm::on_pushButton_12_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    QString opcion="";
    QString Opcion1="";
    QString Opcion2="";
    QString Opcion3="";
    if (ui->checkBox->isChecked())
    {
        opcion = "--a";
    }
    if (ui->checkBox_2->isChecked())
    {
        Opcion1 = "--force";
    }
    if (ui->checkBox_3->isChecked())
    {
        Opcion2 = "--auto";
    }
    if (ui->checkBox_4->isChecked())
    {
        Opcion3 = "--fuzzy";
    }
    QTableWidgetItem *item, *item1;
    QString activo, activo1;
    QStringList comandos;
    int itemCount = ui->tableWidget->rowCount();
    if (itemCount == 0)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        Opcion = 0;
        return;
    }
    else
    {
        TotalProceso=0;
        QString cmd = QString::fromUtf8(tr("echo Realizando procesos..."));
        comandos<< cmd;
        Evento = 0;
        ui->pushButton_16->setEnabled(true);
        for(int i=0;i<itemCount;i++)
        {
            if (Evento == 1)
            {
                ui->textEdit->append(tr("Trabajo cancelado"));
                ui->progressBar->setValue(0);
                ui->progressBar->hide();
                ui->pushButton_16->setEnabled(false);
                return;
            }
            item = ui->tableWidget->item(i,5);
            item1 = ui->tableWidget->item(i,0);
            activo = item->text();
            activo1 = item1->text();
            if (activo == "Ok")
            {
                QString cmd1 = "urpmi %1 %2 %3 %4 %5";
                cmd1=cmd1.arg(opcion).arg(Opcion1).arg(Opcion2).arg(Opcion3).arg(activo1);
                comandos<< cmd1;
            }
        }
        if (mib != 0)
            delete mib;
        ui->progressBar->show();
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count();
        mib->Valor(valor,0);
        mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
        mib->iniciarProceso();        
        Totalizar = comandos.count();
        ui->progressBar->setRange(0,Totalizar);
    }
}

void Mrpm::on_pushButton_3_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    ui->progressBar->show();
    QString Fecha = QDate::currentDate().toString("ddMMyyyy");
    QString Nombre = "PackAnt";
    QString path=tr("/home/%1/Documentos/%2%3%4.lst");
    path=path.arg(user).arg(Nombre).arg(Distro).arg(Fecha);
    QString fileNameDestino = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar archivo .lst")),
                        path,trUtf8(tr("Archivo .lst (*.lst)")));
    if (fileNameDestino.isEmpty())
    {
        Opcion = 0;
        return;
    }
    if (fileNameDestino.contains(".lst"))
        fileNameDestino.remove(".lst");
    QFile file(""+fileNameDestino+".lst");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream in(&file);
    QString activo;
    int itemCount = ui->tableWidget->rowCount();
    ui->progressBar->setRange(0,itemCount);
    ui->textEdit->append(tr("Creando fichero en ruta "+fileNameDestino+".lst"));
    QTableWidgetItem *item;
    for(int i=0;i<itemCount;i++)
    {
        item=new QTableWidgetItem;
        item = ui->tableWidget->item(i,0);
        activo = item->text();
        in << activo + " ";
        ui->progressBar->setValue(i);
    }    
    ui->progressBar->setValue(itemCount);
    ui->textEdit->append(tr("Fichero creado correctamente."));
    file.close();
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    ui->progressBar->hide();
    Opcion = 0;
}

void Mrpm::on_pushButton_11_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();        
        return;
    }
    int j;
    j=ui->tableWidget->currentRow();
    if (j == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes realizar lo que has solicitado."));
        m.exec();
        Opcion = 0;
        return;
    }
    else
    {
        ui->tableWidget->removeRow(j);
        int Contador = ui->tableWidget->rowCount();
        ui->lineEdit_2->setText(QString::number(Contador));
    }
    if (ui->lineEdit->text() != "")
    {
        Opcion = 0;
        on_pushButton_13_clicked();
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    Opcion = 0;
}

void Mrpm::on_pushButton_9_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    int i,j,a;
    i=0;
    j=ui->tableWidget->rowCount();
    ui->progressBar->show();
    int respuesta = 0;
    int respuesta1 = 0;
    if (j == 0)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay registros para procesar."));
        m.exec();
        Opcion = 0;
        return;
    }
    else
    {
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Evitar palabras clave")),
                        QString::fromUtf8(tr("<center><b>Evitar palabras clave<b></center><p>"
                        "Mediante este proceso realizamos una purga de las palabras clave que se "
                        "hayan introducido en las preferencias, evitando la instalacion por ejemplo "
                        "de librerias (lib) que pudieran entrar en conflicto con lo ya instalado.<p>"
                        "Tambien se procedera, si es necesario, a la purga de paquetes instalados.<p>"
                        "&iquest;Evitar palabras clave?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            ui->textEdit->append(tr("Este proceso puede ser muy prolongado segun paquetes a purgar."));
            ui->textEdit->append(tr("Sea paciente y espere a que termine la comprobacion."));
            ui->textEdit->append(tr("<FONT COLOR=\"BLUE\"><B>Realizando primera fase de rastreo (Evitar palabras clave)...</b>"));
            ui->progressBar->setRange(0,j);
            QStringList Datos;
            QString verlo, valor;
            QSqlQuery query(db);
            QTableWidgetItem *item;
            Evento = 0;
            ui->pushButton_16->setEnabled(true);
            query.exec("SELECT Palabra FROM Palabra");
            while(query.next())
            {
                Datos << query.value(0).toString();
            }
            for(i=0;i<j;i++)
            {
                ui->progressBar->setRange(0,j);
                qApp->processEvents();
                if (Evento == 1)
                {
                    ui->textEdit->append(tr("Trabajo cancelado"));
                    ui->pushButton_16->setEnabled(false);
                    return;
                }
                item=ui->tableWidget->item(i,0);
                valor=item->text();
                ui->textEdit->append(tr("Procesando... "+valor+"(Registro: "+QString::number(i)+")"));
                for(a=0;a<Datos.count();a++)
                {
                    verlo=QString::fromUtf8(Datos.value(a));
                    if(valor.contains(verlo) == true)
                    {
                       ui->tableWidget->removeRow(i);
                       i=i-1;
                       j=j-1;
                       int Contador = ui->tableWidget->rowCount();
                       ui->lineEdit_2->setText(QString::number(Contador));
                    }
                }
                ui->progressBar->setValue(i);
            }
            ui->progressBar->setValue(j);
            ui->progressBar->setRange(0,100);
            ui->progressBar->setValue(0);
            ui->progressBar->hide();
        }
        respuesta1 = QMessageBox::question(this, QString::fromUtf8(tr("Purgar paquetes instalados")),
                     QString::fromUtf8(tr("<center><b>Purgar paquetes instalados<b></center><p>"
                     "Mediante este proceso realizamos una purga de los paquetes instalados en "
                     "el sistema, para realizar el proceso con mayor rendimiento.<p>"
                     "&iquest;Purgar paquetes instalados?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta1 == QMessageBox::Ok)
        {
            Opcion = 0;
            this->on_pushButton_15_clicked();
        }
    }
    Opcion = 0;
}

void Mrpm::on_pushButton_14_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    int j=ui->tableWidget->rowCount();
    if (j > 0)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                    QString::fromUtf8(tr("<center><b>Nueva lista de datos<b></center><p>"
                    "Hay registros ya cargados anteriormente, si cargas una nueva lista "
                    "se borraran los datos anteriormente cargados.<p>"
                    "&iquest;Continuar con una nueva lista?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::No)
        {
            Opcion = 0;
            return;
        }
        else
        {
            int Borrado, x;
            Borrado = ui->tableWidget->rowCount();
            for(x=0;x<Borrado;x++)
            {
                 ui->tableWidget->removeRow(x);
                 x=x-1;
                 Borrado=Borrado-1;
            }
        }
    }    
    int respuesta1=0;
    int iFilas;
    setUpdatesEnabled(false);
    QProgressDialog progress(tr("Generar listado de rpms instalados...Espera por favor"), tr("Cancelar"), 0, Listado.count(), this);
    progress.show();
    QTest::qWait(20);
    QTableWidgetItem *item1, *item2, *item3, *item4, *item5, *item6;
    for(int i=0;i<Listado.count();i++)
    {
        qApp->processEvents();
        progress.setValue(i);
        if (progress.wasCanceled())
            break;
        Value0 = Listado.value(i);
        if (Value0 != "")
        {
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            item5=new QTableWidgetItem;
            item6=new QTableWidgetItem;
            item1->setText(""+Value0+"");
            item2->setText(" ");
            item3->setText(" ");
            item4->setText(" ");
            item5->setText(" ");
            item6->setText(" ");
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->setItem(iFilas,2,item3);
            ui->tableWidget->setItem(iFilas,3,item4);
            ui->tableWidget->setItem(iFilas,4,item5);
            ui->tableWidget->setItem(iFilas,5,item6);
            int Contador = ui->tableWidget->rowCount();
            ui->lineEdit_2->setText(QString::number(Contador+1));
        }
    }
    progress.setValue(Listado.count());
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    setUpdatesEnabled(true);
    if (ui->lineEdit->text() != "")
    {
        Opcion=0;
        on_pushButton_13_clicked();
    }
    respuesta1 = QMessageBox::question(this, QString::fromUtf8(tr("Guardar a fichero")),
                QString::fromUtf8(tr("<center><b>Guardar a fichero<b></center><p>"
                "Si no quieres procesar los paquetes con las distintas opciones que tienes "
                "puedes grabar directamente el fichero con tus paquetes instalados.<p>"
                "Siempre puedes volcar el listado despues con la opcion correspondiente.<p>"
                "&iquest;Guardar a fichero?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta1 == QMessageBox::Ok)
    {
        Opcion = 0;
        this->on_pushButton_3_clicked();
    }
    Opcion = 0;
}

QString Mrpm::getDatos()
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquetes;
    procesoRPM=new QProcess(this);
    argumentosRPM << "-qa" << "--queryformat='%{N} '";
    procesoRPM->start("rpm",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquetes = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res = QString(Paquetes);
    res.chop(1);
    return res;
}

void Mrpm::on_pushButton_15_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }    
    int j,a,i;
    j=ui->tableWidget->rowCount();
    if (j == 0)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay registros para procesar."));
        m.exec();
        Opcion = 0;
        return;
    }
    else
    {
        ui->progressBar->show();
        ui->textEdit->append(tr("<FONT COLOR=\"BLUE\"><B>Realizando segunda fase de rastreo (Paquetes instalados)...</b>"));
        QString value, verlo;
        ui->progressBar->setRange(0,j);
        Evento = 0;
        ui->pushButton_16->setEnabled(true);
        QTableWidgetItem *item;
        for(i=0;i<j;i++)
        {
            ui->progressBar->setRange(0,j);
            qApp->processEvents();
            if (Evento == 1)
            {
                ui->textEdit->append(tr("Trabajo cancelado"));
                ui->pushButton_16->setEnabled(false);
                return;
            }
            item=0;
            item=new QTableWidgetItem;
            item=ui->tableWidget->item(i,0);
            value=item->text();
            ui->textEdit->append(tr("Comprobando... ")+value+"");
            for(a=0;a<Listado.count();a++)
            {
                verlo=QString::fromUtf8(Listado.value(a));
                if(value == verlo)
                {
                   ui->tableWidget->removeRow(i);
                   i=i-1;
                   j=j-1;
                   int Contador = ui->tableWidget->rowCount();
                   ui->lineEdit_2->setText(QString::number(Contador));
                }
                ui->progressBar->setValue(i);
            }
        }
        ui->progressBar->setValue(j);
     }
     ui->progressBar->setRange(0,100);
     ui->progressBar->setValue(0);
     ui->progressBar->hide();
     ui->tableWidget->resizeColumnsToContents();
     ui->tableWidget->resizeRowsToContents();
     Opcion = 0;
}

void Mrpm::on_pushButton_16_clicked()
{
    Evento = 1;
    if (mib != 0)
    {
        mib->killProceso();
        disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
        disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    }
    Comprueba = "No";
    ui->progressBar->setValue(0);
    ui->progressBar->hide();
    Opcion = 0;
}

bool Mrpm::eventFilter(QObject* obj, QEvent *event)
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
                ayuda->Valor("Salvaguarda");
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

void Mrpm::on_lineEdit_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        int valor = ui->lineEdit_2->text().toInt();
        if (valor <= 0)
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No hay registros para poder filtrar."));
            m.exec();
            ui->lineEdit->setText("");
            return;
        }
    }
}

void Mrpm::on_pushButton_13_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    int i,j;
    j=ui->tableWidget->rowCount();
    if (j == 0)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay registros para procesar."));
        m.exec();
        Opcion = 0;
        return;
    }
    else
    {
        Posicion.clear();
        QString verlo = ui->lineEdit->text();
        if (verlo != "")
        {
            QString valor;
            QTableWidgetItem *item;
            item=new QTableWidgetItem;
            for(i=0;i<j;i++)
            {
                item=ui->tableWidget->item(i,0);
                valor=item->text();
                if(valor.contains(verlo))
                {
                    Posicion << QString::number(i);
                }
            }
            ui->tableWidget->resizeColumnsToContents();
            ui->tableWidget->resizeRowsToContents();
        }
    }   
    if (Posicion.count() > 0)
    {
        ui->tableWidget->selectRow(Posicion.value(0).toInt());
        Situacion=0;
        ui->label_2->setText(tr(""+QString::number(Posicion.count())+" Registros"));
    }
    else
        ui->label_2->setText("");
    if (Posicion.count() > 1)
    {
        ui->pushButton_17->setEnabled(true);
        ui->pushButton_18->setEnabled(true);
    }
    else
    {
        ui->pushButton_17->setEnabled(false);
        ui->pushButton_18->setEnabled(false);
    }
    Opcion = 0;
}

void Mrpm::on_pushButton_17_clicked()
{
    if (Situacion != 0)
    {
        ui->tableWidget->selectRow(Posicion.value(Situacion-1).toInt());
        Situacion=Situacion-1;
    }
}

void Mrpm::on_pushButton_18_clicked()
{
    if (Situacion != Posicion.count()-1)
    {
        ui->tableWidget->selectRow(Posicion.value(Situacion+1).toInt());
        Situacion=Situacion+1;
    }
}

void Mrpm::on_pushButton_19_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    int j=ui->tableWidget->rowCount();
    if (j > 0)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                    QString::fromUtf8(tr("<center><b>Borrar datos cargados<b></center><p>"
                    "Si utilizas esta opcion borraras todos los datos que hayas cargado "
                    "con la consiguiente perdida de tiempo. Hazlo solo si lo tienes claro.<p>"
                    "&iquest;Continuar con el borrado?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::No)
        {
            Opcion = 0;
            return;
        }
        else
        {
            int Borrado, x;
            Borrado = ui->tableWidget->rowCount();
            for(x=0;x<Borrado;x++)
            {
                 ui->tableWidget->removeRow(x);
                 x=x-1;
                 Borrado=Borrado-1;
            }
        }
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay datos cargados para borrar."));
        m.exec();
    }
    Opcion = 0;
}
