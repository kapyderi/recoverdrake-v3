#include "rpminst.h"
#include "ui_rpminst.h"
#include "drakesistema.h"
#include <QMessageBox>
#include <QTest>
#include <QProgressDialog>
#include <QDebug>
#include <QInputDialog>
#include <recoverdrake.h>
#include <QTableWidgetItem>
#include <QSqlQuery>

rpminst::rpminst(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rpminst)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnHidden(3,true);
    ui->tableWidget->setColumnHidden(4,true);
    ui->tableWidget->setColumnHidden(5,true);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    mib=0;
    Activo=0;
    Cantidad=0;
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

rpminst::~rpminst()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void rpminst::Valor(int valor, QString Value)
{
    if (valor == 1)
    {
        ui->tableWidget->horizontalHeaderItem(2)->setText(tr("Nucleos"));
        ui->pushButton_15->close();
        ui->pushButton_14->close();
        ui->pushButton_10->setText(tr("Marcar kernel"));
        ui->pushButton_12->setText(tr("Desmarcar kernel"));
        ui->pushButton_13->setText(tr("Desinstalar kernel"));
        ui->tableWidget->setColumnHidden(3,false);
        ui->tableWidget->setColumnHidden(4,false);
        ui->tableWidget->setColumnHidden(5,false);
        Activo=1;
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Se va a proceder a rastrear los nucleos, devels, latest y sources de tu equipo.<p>Este proceso se puede demorar un poco, se paciente."));
        m.exec();
        on_pushButton_15_clicked();
    }
    if (Value == "Quitar")
    {
        CierreTotal = 1;
    }
}

void rpminst::on_pushButton_14_clicked()
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
    drakeSistema drake;
    rpm = drake.getRpms();
    lista = rpm.split("\n");
    if (lista.count() == 1)
    {
        if (lista.value(0) == "")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Nada que procesar."));
            m.exec();
            return;
        }
    }
    setUpdatesEnabled(false);
    QProgressDialog progress(tr("Comprobando rpms instalados... Espera por favor"), tr("Cancelar"), 0, lista.count(), this);
    progress.show();
    for(int i=0;i<lista.count();i++)
    {
        qApp->processEvents();
        progress.setValue(i);
        if (progress.wasCanceled())
            break;
        Value0 = lista.value(i);
        if (Value0 != "")
        {
            Value1 = Value0.right(29);
            Value2 = Value0.remove(""+Value1+"").remove(" ");
            QTableWidgetItem *item1, *item2, *item3;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item1->setText("");
            item2->setText(""+Value1+"");
            item3->setText(""+Value2+"");
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->setItem(iFilas,2,item3);
            ui->tableWidget->item(iFilas,0)->setIcon(QIcon(":/Imagenes/bad.png"));
            int Contador = ui->tableWidget->rowCount();
            ui->lineEdit_2->setText(QString::number(Contador+1));
        }
    }
    progress.setValue(lista.count());
    setUpdatesEnabled(true);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

void rpminst::on_pushButton_2_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void rpminst::closeEvent ( QCloseEvent * event )
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

void rpminst::on_pushButton_12_clicked()
{
    int iFilas;
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
        item=ui->tableWidget->item(iFilas,0);
        item1=new QTableWidgetItem;
        item1=ui->tableWidget->item(iFilas,2);
        valor=item->text();
        valor1=item1->text();
        if(valor == "Ok")
        {
            ui->tableWidget->item(iFilas,0)->setIcon(QIcon(":/Imagenes/bad.png"));
            item->setText("");
            ui->tableWidget->setItem(iFilas,0,item);
            if (Activo == 1)
            {
                if (valor1 == "")
                {
                    return;
                }
                QStringList Version = valor1.split("-");
                QString Valor0 = Version.value(1);
                QString Valor = Version.value(2);
                int iFilas1 = ui->tableWidget->rowCount();
                QTableWidgetItem *itm, *item2;
                itm=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                for(int i=0;i<iFilas1;i++)
                {
                    itm=ui->tableWidget->item(i,0);
                    item2=ui->tableWidget->item(i,3);
                    QString valor=item2->text();
                    if( valor.contains(Valor) == true && valor.contains("source") == true)
                    {
                        ui->tableWidget->item(i,0)->setIcon(QIcon(":/Imagenes/bad.png"));
                        itm->setText("");
                        ui->tableWidget->setItem(i,0,item);
                    }
                }
                QTableWidgetItem *itm1, *item3;
                itm1=new QTableWidgetItem;
                item3=new QTableWidgetItem;
                for(int i=0;i<iFilas1;i++)
                {
                    itm1=ui->tableWidget->item(i,0);
                    item3=ui->tableWidget->item(i,4);
                    QString valor=item3->text();
                    if( valor.contains(Valor) == true && valor.contains(Valor0) == true)
                    {
                        ui->tableWidget->item(i,0)->setIcon(QIcon(":/Imagenes/bad.png"));
                        itm1->setText("");
                        ui->tableWidget->setItem(i,0,item);
                    }
                }
                QTableWidgetItem *itm2, *item4;
                itm2=new QTableWidgetItem;
                item4=new QTableWidgetItem;
                for(int i=0;i<iFilas1;i++)
                {
                    itm2=ui->tableWidget->item(i,0);
                    item4=ui->tableWidget->item(i,5);
                    QString valor=item4->text();
                    if( valor.contains(Valor) == true && valor.contains(Valor0) == true)
                    {
                        ui->tableWidget->item(i,0)->setIcon(QIcon(":/Imagenes/bad.png"));
                        itm2->setText("");
                        ui->tableWidget->setItem(i,0,item);
                    }
                }
            }
        }
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

void rpminst::on_pushButton_10_clicked()
{
    int iFilas;
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
        item1=ui->tableWidget->item(iFilas,2);
        valor=item->text();
        valor1=item1->text();
        if (valor1 == "")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("El registro que quieres marcar no es un nucleo, sino un derivado como un source, devel o latest."));
            m.exec();
            return;
        }
        if(valor != "Ok")
        {            
            ui->tableWidget->item(iFilas,0)->setIcon(QIcon(":/Imagenes/good.png"));
            item->setText("Ok");
            ui->tableWidget->setItem(iFilas,0,item);
            if (Activo == 1)
            {
                QStringList Version = valor1.split("-");
                QString Valor0 = Version.value(1);
                QString Valor = Version.value(2);
                int iFilas1 = ui->tableWidget->rowCount();
                QTableWidgetItem *itm, *item2;
                itm=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                for(int i=0;i<iFilas1;i++)
                {
                    itm=ui->tableWidget->item(i,0);
                    item2=ui->tableWidget->item(i,3);
                    QString valor=item2->text();
                    if( valor.contains(Valor) == true && valor.contains("source") == true)
                    {
                        ui->tableWidget->item(i,0)->setIcon(QIcon(":/Imagenes/good.png"));
                        itm->setText("Ok");
                        ui->tableWidget->setItem(i,0,item);
                    }
                }
                QTableWidgetItem *itm1, *item3;
                itm1=new QTableWidgetItem;
                item3=new QTableWidgetItem;
                for(int i=0;i<iFilas1;i++)
                {
                    itm1=ui->tableWidget->item(i,0);
                    item3=ui->tableWidget->item(i,4);
                    QString valor=item3->text();
                    if( valor.contains(Valor) == true && valor.contains(Valor0) == true)
                    {
                        ui->tableWidget->item(i,0)->setIcon(QIcon(":/Imagenes/good.png"));
                        itm1->setText("Ok");
                        ui->tableWidget->setItem(i,0,item);
                    }
                }
                QTableWidgetItem *itm2, *item4;
                itm2=new QTableWidgetItem;
                item4=new QTableWidgetItem;
                for(int i=0;i<iFilas1;i++)
                {
                    itm2=ui->tableWidget->item(i,0);
                    item4=ui->tableWidget->item(i,5);
                    QString valor=item4->text();
                    if( valor.contains(Valor) == true && valor.contains(Valor0) == true)
                    {
                        ui->tableWidget->item(i,0)->setIcon(QIcon(":/Imagenes/good.png"));
                        itm2->setText("Ok");
                        ui->tableWidget->setItem(i,0,item);
                    }
                }
            }
        }
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

void rpminst::on_pushButton_13_clicked()
{
    if (Activo == 1)
    {
        Recuento();
    }
    if (Cantidad < 2)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Tienes que dejar como minimo dos kernels para poder recuperar el sistema si fuera necesario y estas dejando en el sistema solo "+QString::number(Cantidad)+" kernel."));
        m.exec();
        return;
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
        item1 = ui->tableWidget->item(i,2);
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

void rpminst::Recuento()
{
    QTableWidgetItem *itemA, *itemB;
    QString activoA, activoB;
    int itemCount = ui->tableWidget->rowCount();
    for(int i=0;i<itemCount;i++)
    {
        itemA = ui->tableWidget->item(i,0);
        itemB = ui->tableWidget->item(i,2);
        activoA = itemA->text();
        activoB = itemB->text();
        if (activoA == "" && activoB !="")
        {
            Cantidad++;
        }
    }
}

void rpminst::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
}

void rpminst::ProcesarValor(QString ValorComand)
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

void rpminst::mibprogreso(QString Dat)
{
    ui->progressBar->setValue(Dat.toInt());
}

void rpminst::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    ui->progressBar->setValue(0);
    lista.clear();
    if (Activo == 1)
    {
        this->on_pushButton_15_clicked();
    }
    else
    {
        this->on_pushButton_14_clicked();
    }
}

void rpminst::on_pushButton_15_clicked()
{
    if (Activo != 1)
    {
        bool ok;
        QString Nombre = QInputDialog::getText(this, QString::fromUtf8(tr("Nombre clave para delimitar busqueda")),
        QString::fromUtf8(tr("Introduce el nombre clave a filtrar.<P> "
        "<FONT COLOR=\"RED\">Ejemplo:<p>"
        "<FONT COLOR=\"RED\">kernel<p>")),
        QLineEdit::Normal,
        "",
        &ok);
        if (ok && !Nombre.isEmpty())
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
            drakeSistema drake;
            rpm = drake.getRpmsN(Nombre);
            lista = rpm.split("\n");
            if (lista.count() == 1)
            {
                if (lista.value(0) == "")
                {
                    QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("Nada que procesar."));
                    m.exec();
                    return;
                }
            }
            setUpdatesEnabled(false);
            QProgressDialog progress(tr("Comprobando rpms instalados... Espera por favor"), tr("Cancelar"), 0, lista.count(), this);
            progress.show();
            for(int i=0;i<lista.count();i++)
            {
                qApp->processEvents();
                progress.setValue(i);
                if (progress.wasCanceled())
                    break;
                Value0 = lista.value(i);
                if (Value0 != "")
                {
                    Value1 = Value0.right(29);
                    Value2 = Value0.remove(""+Value1+"").remove(" ");
                    QTableWidgetItem *item1, *item2, *item3;
                    item1=new QTableWidgetItem;
                    item2=new QTableWidgetItem;
                    item3=new QTableWidgetItem;
                    item1->setText("");
                    item2->setText(""+Value1+"");
                    item3->setText(""+Value2+"");
                    iFilas=ui->tableWidget->rowCount();
                    ui->tableWidget->insertRow(iFilas);
                    ui->tableWidget->setItem(iFilas,0,item1);
                    ui->tableWidget->setItem(iFilas,1,item2);
                    ui->tableWidget->setItem(iFilas,2,item3);
                    ui->tableWidget->item(iFilas,0)->setIcon(QIcon(":/Imagenes/bad.png"));
                    int Contador = ui->tableWidget->rowCount();
                    ui->lineEdit_2->setText(QString::number(Contador+1));
                }
            }
            progress.setValue(lista.count());
            setUpdatesEnabled(true);
        }
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
             int Contador = ui->tableWidget->rowCount();
             ui->lineEdit_2->setText(QString::number(Contador));
        }
        int iFilas;
        drakeSistema drake;
        rpm = drake.getRpmsN("kernel-desktop");
        lista << rpm.split("\n");
        rpm1 = drake.getRpmsN("kernel-linus");
        lista << rpm1.split("\n");
        rpm2 = drake.getRpmsN("kernel-netbook");
        lista << rpm2.split("\n");
        rpm3 = drake.getRpmsN("kernel-rt");
        lista << rpm3.split("\n");
        rpm4 = drake.getRpmsN("kernel-server");
        lista << rpm4.split("\n");
        rpm5 = drake.getRpmsN("kernel-source");
        lista << rpm5.split("\n");
        rpm6 = drake.getRpmsN("kernel-tmb");
        lista << rpm6.split("\n");
        rpm7 = drake.getRpmsN("kernel-vserver");
        lista << rpm7.split("\n");
        if (lista.count() == 1)
        {
            if (lista.value(0) == "")
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Nada que procesar."));
                m.exec();
                return;
            }
        }
        setUpdatesEnabled(false);
        QProgressDialog progress(tr("Comprobando nucleos instalados... Espera por favor"), tr("Cancelar"), 0, lista.count(), this);
        progress.show();
        QString Val1 = "source";
        QString Val2 = "devel";
        QString Val3 = "latest";
        for(int i=0;i<lista.count();i++)
        {
            qApp->processEvents();
            progress.setValue(i);
            if (progress.wasCanceled())
                break;
            Value0 = lista.value(i);
            if (Value0 != "")
            {
                Value1 = Value0.right(29);
                Value2 = Value0.remove(""+Value1+"").remove(" ");
                QString verlo=Value2;
                if (Value2.left(6) == "kernel")
                {
                    int pos1 = verlo.indexOf(Val1, 0);
                    int pos2 = verlo.indexOf(Val2, 0);
                    int pos3 = verlo.indexOf(Val3, 0);
                    if (pos1 != -1)
                    {
                        Value3 = verlo;
                        Value2 = "";
                    }
                    else if (pos1 == -1)
                    {
                        Value3="";
                    }
                    if (pos2 != -1)
                    {
                        Value4 = verlo;
                        Value2 = "";
                    }
                    else if (pos2 == -1)
                    {
                        Value4="";
                    }
                    if (pos3 != -1)
                    {
                        if (pos2 != -1)
                        {
                            Value5 = "";
                            Value2 = "";
                        }
                        if (pos1 != -1)
                        {
                            Value4 = "";
                            Value2 = "";
                        }
                        else
                        {
                            Value5 = verlo;
                            Value2 = "";
                        }
                    }
                    else if (pos3 == -1)
                    {
                        Value5="";
                    }
                    QTableWidgetItem *item1, *item2, *item3, *item4, *item5, *item6;
                    item1=new QTableWidgetItem;
                    item2=new QTableWidgetItem;
                    item3=new QTableWidgetItem;
                    item4=new QTableWidgetItem;
                    item5=new QTableWidgetItem;
                    item6=new QTableWidgetItem;
                    item1->setText("");
                    item2->setText(""+Value1+"");
                    item3->setText(""+Value2+"");
                    item4->setText(""+Value3+"");
                    item5->setText(""+Value4+"");
                    item6->setText(""+Value5+"");
                    iFilas=ui->tableWidget->rowCount();
                    ui->tableWidget->insertRow(iFilas);
                    ui->tableWidget->setItem(iFilas,0,item1);
                    ui->tableWidget->setItem(iFilas,1,item2);
                    ui->tableWidget->setItem(iFilas,2,item3);
                    ui->tableWidget->setItem(iFilas,3,item4);
                    ui->tableWidget->setItem(iFilas,4,item5);
                    ui->tableWidget->setItem(iFilas,5,item6);
                    ui->tableWidget->item(iFilas,0)->setIcon(QIcon(":/Imagenes/bad.png"));
                    int Contador = ui->tableWidget->rowCount();
                    ui->lineEdit_2->setText(QString::number(Contador+1));
                }
            }
        }
        progress.setValue(lista.count());
        setUpdatesEnabled(true);
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}
