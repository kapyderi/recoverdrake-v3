#include "update.h"
#include "ui_update.h"
#include <QDebug>
#include <QProcess>
#include "drakesistema.h"
#include "drakeprocesos.h"
#include <QFile>
#include <QTest>
#include <QMessageBox>
#include <QSqlQuery>

Update::Update(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Update)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    drakeSistema drake;
    user = drake.getUser();
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(true);
    ui->checkBox_4->setChecked(false);
    mib=0;
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

Update::~Update()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void Update::Valor(QString valor)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
}

void Update::on_pushButton_2_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void Update::closeEvent ( QCloseEvent * event )
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

QString Update::getRpm()
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;

    procesoRPM=new QProcess(this);

    argumentosRPM << "--auto-select";

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

QString Update::getRpm2(QString Value)
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;

    procesoRPM=new QProcess(this);

    argumentosRPM << "-u" <<"-i" << ""+Value+"";

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

void Update::on_pushButton_14_clicked()
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
    int iFilas;
    ui->textEdit->append(tr("Se paciente y espera a que termine la comprobacion de paquetes a actualizar..."));
    QTest::qWait(20);
    QString Local = getRpm();
    lista = Local.split("\n");
    if (lista.count() == 1)
    {
        if (lista.value(0) == "")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Nada que actualizar.<p>Todos los paquetes estan al dia."));
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
            ui->textEdit->append(tr("Procesando... ")+Value+tr("(Registro: ")+QString::number(i)+")");
            QString Local1 = getRpm2(Value);
            if (Local1 != "")
            {
                QStringList Datos = Local1.split("\n");
                QString Val1 = "Version     : ";
                QString Val2 = "Release     : ";
                QString Val3 = "Architecture: ";
                QString Val4 = "Size        : ";
                for(int a=0;a<Datos.count();a++)
                {
                    QString verlo=QString::fromUtf8(Datos.value(a));
                    int pos1 = verlo.indexOf(Val1, 0);
                    int pos2 = verlo.indexOf(Val2, 0);
                    int pos3 = verlo.indexOf(Val3, 0);
                    int pos4 = verlo.indexOf(Val4, 0);
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
                    if (pos4 != -1)
                    {
                        Value3 = Datos.at(a);
                    }
                    Value0 = QString::fromUtf8(Value0.remove(Val1));
                    Value1 = QString::fromUtf8(Value1.remove(Val2));
                    Value2 = QString::fromUtf8(Value2.remove(Val3).remove(Val4).right(10).remove(" "));
                    Value3 = QString::fromUtf8(Value3.left(43).remove(Val4).remove(" "));
                }
                QTableWidgetItem *item1, *item2, *item3, *item4, *item5, *item6;
                item1=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                item3=new QTableWidgetItem;
                item4=new QTableWidgetItem;
                item5=new QTableWidgetItem;
                item6=new QTableWidgetItem;
                item1->setText("Ok");
                item2->setText(""+Value+"");
                item3->setText(""+Value0+"");
                item4->setText(""+Value1+"");
                item5->setText(""+Value2+"");
                float ValInt;
                ValInt = (Value3.toInt() + 1023)/1024;
                ValInt = ValInt / 1024;
                Value3 = QString::number(ValInt,'f',2);
                item6->setText(""+Value3+" Mb");
                iFilas=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(iFilas);
                ui->tableWidget->setItem(iFilas,0,item1);
                ui->tableWidget->setItem(iFilas,1,item2);
                ui->tableWidget->setItem(iFilas,2,item3);
                ui->tableWidget->setItem(iFilas,3,item4);
                ui->tableWidget->setItem(iFilas,4,item5);
                ui->tableWidget->setItem(iFilas,5,item6);
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

void Update::on_pushButton_6_clicked()
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

void Update::on_pushButton_7_clicked()
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

void Update::on_pushButton_3_clicked()
{
    QString Opcion="";
    QString Opcion1="";
    QString Opcion2="";
    QString Opcion3="";
    if (ui->checkBox->isChecked())
    {
        Opcion = "--a";
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
    QString cmd = QString::fromUtf8(tr("echo Realizando procesos..."));
    comandos<< cmd;
    for(int i=0;i<itemCount;i++)
    {
        item = ui->tableWidget->item(i,0);
        item1 = ui->tableWidget->item(i,1);
        activo = item->text();
        activo1 = item1->text();
        if (activo == "Ok")
        {
            QString cmd1 = "urpmi %1 %2 %3 %4 %5";
            cmd1=cmd1.arg(Opcion).arg(Opcion1).arg(Opcion2).arg(Opcion3).arg(activo1);
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

void Update::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
}

void Update::ProcesarValor(QString ValorComand)
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

void Update::mibprogreso(QString Dat)
{
    ui->progressBar->setValue(Dat.toInt());
}

void Update::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    ui->progressBar->setValue(0);
    this->on_pushButton_14_clicked();
}

void Update::on_pushButton_10_clicked()
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
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void Update::on_pushButton_12_clicked()
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
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void Update::on_pushButton_8_clicked()
{
    QString Opcion="";
    QString Opcion1="";
    QString Opcion2="";
    QString Opcion3="";
    if (ui->checkBox->isChecked())
    {
        Opcion = "--a";
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
    if (itemCount == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QString cmd = QString::fromUtf8(tr("echo Realizando procesos..."));
        comandos<< cmd;
        for(int i=0;i<itemCount;i++)
        {
            item = ui->tableWidget->item(i,0);
            item1 = ui->tableWidget->item(i,1);
            activo = item->text();
            activo1 = item1->text();
            if (activo == "Ok")
            {
                QString cmd1 = "urpmi %1 %2 %3 %4 %5";
                cmd1=cmd1.arg(Opcion).arg(Opcion1).arg(Opcion2).arg(Opcion3).arg(activo1);
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

void Update::on_pushButton_11_clicked()
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
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void Update::on_pushButton_13_clicked()
{
    QTableWidgetItem *item, *item1;
    QString activo, activo1;
    QStringList comandos;
    int respuesta = 0;
    int itemCount = ui->tableWidget->currentRow();
    if (itemCount == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Excluir paquete a actualizar")),
                    QString::fromUtf8(tr("<center><b>Excluir paquete a actualizar<b></center><p>"

                    "Si realiza esta operacion dicho paquete no volvera a aparecer en la "
                    "lista de actualizacion, excepto que se vuelva a incluir en ella, con "
                    "la opcion correspondiente del menu de \"Solucion a problemas\".<p>"

                    "&iquest;Esta seguro de excluir el paquete seleccionado?")), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok)
        {

            QString cmd = QString::fromUtf8(tr("echo Realizando procesos..."));
            comandos<< cmd;
            item = ui->tableWidget->item(itemCount,0);
            item1 = ui->tableWidget->item(itemCount,1);
            activo = item->text();
            activo1 = item1->text();
            if (activo == "Ok")
            {
                 QString cm = QString::fromUtf8(tr("echo Excluyendo paquete..."));
                 system("echo '"+activo1+"' >> /etc/urpmi/skip.list");
                 QString cmd1 = QString::fromUtf8(tr("echo Paquete excluido satisfactoriamente."));
                 comandos<< cm << cmd1;
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
}
