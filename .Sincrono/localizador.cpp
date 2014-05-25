#include "localizador.h"
#include "ui_localizador.h"
#include <QMessageBox>
#include <stdlib.h>
#include <QtGui>
#include <QToolButton>
#include <QWidget>
#include <QIcon>
#include <QProcess>

Localizador::Localizador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Localizador)
{
    ui->setupUi(this);
}

Localizador::~Localizador()
{
    delete ui;
}

void Localizador::on_pbAgregar_clicked()
{
    int i;
    int iFilas;
    listaArchivos=QFileDialog::getOpenFileNames
     (this,tr("Abrir Archivo"),QDir::currentPath(),
        tr("Todos los archivos (*.*)"));
    if(listaArchivos.isEmpty())
    {
        return;
    }
    for(i=0;i<listaArchivos.count();i++ )
    {
        QString ruta;
        QTableWidgetItem *item1,*item2,*item3;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        ruta=listaArchivos.value(i);
        QFile file(ruta);
        qint64 size = QFileInfo(file).size();
        item1->setText(QFileInfo(file).fileName() );
        item2->setText(ruta);
        float f;
        f=(size + 1023) / 1024;
        f=f/1024;
        tamanio=tamanio + f;
        item3->setText(QString::number(f,'f',2));
        iFilas=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(iFilas);
        ui->tableWidget->setItem(iFilas,0,item1);
        ui->tableWidget->setItem(iFilas,1,item2);
        ui->tableWidget->setItem(iFilas,2,item3);
    }
    ui->lblTamanio->setText(QString::number(tamanio,'f',2));
}

void Localizador::on_pushButton_2_clicked()
{
    int iFilas;
    QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio a buscar?"),QDir::currentPath(),QFileDialog::ShowDirsOnly);
    if (fileNameDirectori.isEmpty())
       return;    
    QString size= getSize(fileNameDirectori);
    QString ruta;
    QTableWidgetItem *item1,*item2,*item3;
    item1=new QTableWidgetItem;
    item2=new QTableWidgetItem;
    item3=new QTableWidgetItem;
    ruta=fileNameDirectori+"/";
    item1->setText(tr("DIRECTORIO"));
    item2->setText(ruta);
    float f;
    f=size.toFloat()/1024;
    tamanio=tamanio + f;
    item3->setText(QString::number(f,'f',2));
    iFilas=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(iFilas);
    ui->tableWidget->setItem(iFilas,0,item1);
    ui->tableWidget->setItem(iFilas,1,item2);
    ui->tableWidget->setItem(iFilas,2,item3);
    ui->lblTamanio->setText(QString::number(tamanio,'f',2));
}

void Localizador::on_pbEliminar_clicked()
{
    if (ui->tableWidget->rowCount()==1 )
    {
         ui->lblTamanio->setText("0");
    }
    else
    {
        QTableWidgetItem *item;
        item=ui->tableWidget->item(ui->tableWidget->currentRow(),2);
        tamanio=tamanio - item->text().toFloat();
        ui->lblTamanio->setText(QString::number(tamanio));
    }
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void Localizador::on_pushButton_clicked()
{
    QString cadena, peso;
    int i,cantidad;
    cantidad=ui->tableWidget->rowCount();
    for(i=0;i<cantidad;i++)
    {
         QTableWidgetItem *item;         
         item=ui->tableWidget->item(i,1);        
         cadena=cadena + item->text()+" ";         
    }
    this->Local=cadena;
    peso=QString::number(tamanio,'f',2);
    this->Local1=peso;
    this->close();
    return;
}

QString Localizador::getSize(QString Dir)
{
    QProcess *procesoDu, *procesoCut;
    QStringList argumentosDu;
    QStringList argumentosCut;
    QByteArray Size;
    procesoDu=new QProcess(this);
    procesoCut=new QProcess(this);
    argumentosDu << "-s" << "--block-size=K" << ""+Dir+"";
    argumentosCut << "-d" << "K" << "-f1";
    procesoDu->setStandardOutputProcess(procesoCut);
    procesoDu->start("du",argumentosDu);
    procesoCut->start("cut",argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoDu->waitForFinished();
    procesoCut->waitForFinished();
    Size = QString(procesoCut->readAllStandardOutput());
    procesoCut->waitForFinished();
    delete procesoDu;
    delete procesoCut;
    QString res =  QString(Size);
    res.chop(1);
    return res;
}

void Localizador::on_pushButton_3_clicked()
{
    close();
}
