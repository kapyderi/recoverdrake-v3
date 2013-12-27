#include "locusb.h"
#include "ui_locusb.h"
#include "drakesistema.h"
#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include <QTableWidgetItem>
#include <QSqlQuery>

LocUsb::LocUsb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LocUsb)
{
    ui->setupUi(this);
    this->UsbInfo();
    db=QSqlDatabase::database("PRINCIPAL");
    Stilo ="B";
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
}

LocUsb::~LocUsb()
{
    delete ui;
}

void LocUsb::on_pushButton_7_clicked()
{
    this->MediaUsb="";
    close();
}

void LocUsb::UsbInfo()
{
    drakeSistema drake;
    Media = drake.getMedia();
    int iFilas;
    Lista = Media.split("\n");
    if (Lista.count() == 1)
    {
        if (Lista.value(0) == "")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Nada que procesar.<p>No hay nada en la ruta /media para procesar."));
            m.exec();
            return;
        }
    }
    for(int i=0;i<Lista.count();i++)
    {
        Value0 = Lista.value(i);
        if (Value0 != "")
        {
            Valor = Value0.split(" ");
            for(int a=0;a<Valor.count();a++)
            {
                if (a == 0)
                {
                    Parte1 = Valor.value(a);
                    Value1 = Parte1.left(8);
                    Peso = getTalla(Parte1);
                    Value4 = Parte1;
                    Value5 = Peso.left(33).right(8).remove(" ");
                    drakeSistema drake;
                    LabelOld = drake.getLabelOld(Value4);
                    LabelOld=LabelOld.remove("Volume label is ").remove(" ");
                    Value6 = LabelOld;
                }
                if (a == 2)
                {
                    Parte2 = Valor.value(a);
                    drakeSistema drake;
                    QString user = drake.getUser();
                    QString Distro = drake.getDistrop();
                    QString dist = drake.getDistribucion();
                    if (Distro=="Mageia")
                    {
                        if (dist == "3")
                            Value2 = Parte2.remove("/run/media/"+user+"/");
                        else
                            Value2 = Parte2.remove("/media/");
                    }
                    else
                        Value2 = Parte2.remove("/media/");
                }
                if (a == 4)
                {
                    Parte3 = Valor.value(a);
                    Value3 = Parte3;
                }
            }
        }
        if (Value3 == "vfat" && Value5 !="")
        {
            QTableWidgetItem *item1, *item2, *item3, *item4, *item5, *item6;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            item5=new QTableWidgetItem;
            item6=new QTableWidgetItem;
            item1->setText(""+Value1+"");
            item2->setText(""+Value2+"");
            item3->setText(""+Value3+"");
            item4->setText(""+Value4+"");
            item5->setText(""+Value5+"");
            item6->setText(""+Value6+"");
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->setItem(iFilas,2,item3);
            ui->tableWidget->setItem(iFilas,3,item4);
            ui->tableWidget->setItem(iFilas,4,item5);
            ui->tableWidget->setItem(iFilas,5,item6);
        }
    }
}

void LocUsb::on_pushButton_8_clicked()
{
    if (activo1 != "")
    {
        this->MediaUsb=activo1;
        close();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ningún USB seleccionado."));
        m.exec();
        return;
    }
}

QString LocUsb::getTalla(QString Peso)
{
    QProcess *procesoFree, *procesoGrep;
    QStringList argumentosFree;
    QStringList argumentosGrep;
    QByteArray Total;

    procesoFree=new QProcess(this);
    procesoGrep=new QProcess(this);

    argumentosFree << "--block-size=G" << ""+Peso+"";
    argumentosGrep << ""+Peso+"";

    procesoFree->setStandardOutputProcess(procesoGrep);

    procesoFree->start("df", argumentosFree);
    procesoGrep->start("grep", argumentosGrep);

    if (! procesoGrep->waitForStarted())
        return QString("");

    procesoFree->waitForFinished();
    procesoGrep->waitForFinished();

    Total = procesoGrep->readAllStandardOutput();

    delete procesoFree;
    delete procesoGrep;
    QString res = QString(Total);
    res.chop(0);
    return res;
}

void LocUsb::on_tableWidget_itemSelectionChanged()
{
    QTableWidgetItem *item1;
    int row = ui->tableWidget->currentRow();
    item1=new QTableWidgetItem;
    item1 = ui->tableWidget->item(row,0);
    activo1 = item1->text();
}
