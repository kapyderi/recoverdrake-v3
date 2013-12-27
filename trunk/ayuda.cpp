#include "ayuda.h"
#include "ui_ayuda.h"
#include <QDebug>







//ir poniendo conforme se vayan terminando partes del programa para saber que esta hecho.
//ir poniendo las ayudas en ingles cuando se termine la ayuda, se deben de poner las pestanas en ingles con el (tr).
//OJO HAY QUE VER TODOS LOS CIERRES CUANDO HAY UN TEXTEDIT
//comprobar en Recoverdrake.cpp si los que son con gui (ventana aparte) llevan la linea de comprobar()
//comprobar segun nivel que todo lo de root este deshabilitado (RecoverDrake.ui)
// falta terminar los append para ponerle el "tr(" para traduccion.









Ayuda::Ayuda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ayuda)
{
    ui->setupUi(this);
    Pestana = 0;    
    int Valor = ui->tabWidget->count();
    for (int a=0;a<Valor;a++)
    {
        QString Nombre;
        Nombre = ui->tabWidget->tabText(a);
        indice << Nombre;
    }
    ui->lineEdit->selectAll();
    ui->listWidget_2->sortItems(Qt::AscendingOrder);
    ui->tabWidget_2->setCurrentPage(0);
    connect(ui->tabWidget_2,SIGNAL(currentChanged(int)),this,SLOT(Comprobar()));
}

Ayuda::~Ayuda()
{
    delete ui;
}

void Ayuda::on_pushButton_clicked()
{
    close();
}

void Ayuda::Valor(QString valor)
{
    ui->tabWidget->clear();
    ui->listWidget_2->setCurrentRow(0);
    if (valor == "Sincrono")
    {
        ui->tabWidget->insertTab(0,ui->tab_1,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == "Sincrono::Copias sincronizadas")
    {
        ui->tabWidget->insertTab(0,ui->tab_2,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == "Sincrono::Omitir palabras sincronizadas")
    {
        ui->tabWidget->insertTab(0,ui->tab_31,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == "Salvaguarda")
    {
        ui->tabWidget->insertTab(0,ui->tab_41,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == "Comparador")
    {
        ui->tabWidget->insertTab(0,ui->tab_5,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == "TeleDrake")
    {
        ui->tabWidget->insertTab(0,ui->tab_6,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == "VideoDrake")
    {
        ui->tabWidget->insertTab(0,ui->tab_7,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == "Acceso")
    {
        ui->tabWidget->insertTab(0,ui->tab_8,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == "Etiquetador")
    {
        ui->tabWidget->insertTab(0,ui->tab,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == "Backup")
    {
        ui->tabWidget->insertTab(0,ui->tab_9,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == "RecoverDrake")
    {
        ui->tabWidget_2->setCurrentPage(1);
        ui->listWidget_2->setCurrentRow(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(ui->listWidget->currentItem()->text());
    }
}

void Ayuda::on_listWidget_currentTextChanged(const QString &currentText)
{
    ui->tabWidget->removeTab(Pestana);
    if (currentText == "Sincrono")
    {
        ui->tabWidget->insertTab(0,ui->tab_1,"Sincrono");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Sincrono::Copias sincronizadas")
    {
        ui->tabWidget->insertTab(0,ui->tab_2,"Sincrono::Copias sincronizadas");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Sincrono::Omitir palabras sincronizadas")
    {
        ui->tabWidget->insertTab(0,ui->tab_31,"Sincrono::Omitir palabras sincronizadas");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Salvaguarda")
    {
        ui->tabWidget->insertTab(0,ui->tab_41,"Salvaguarda");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Comparador")
    {
        ui->tabWidget->insertTab(0,ui->tab_5,"Comparador");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "TeleDrake")
    {
        ui->tabWidget->insertTab(0,ui->tab_6,"TeleDrake");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "VideoDrake")
    {        this->Comprobar();
        //        QString Valor;
        //        Valor = ui->listWidget_2->currentItem()->text();
        ui->tabWidget->insertTab(0,ui->tab_7,"VideoDrake");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Acceso")
    {
        ui->tabWidget->insertTab(0,ui->tab_8,"Acceso");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Etiquetador")
    {
        ui->tabWidget->insertTab(0,ui->tab,"Etiquetador");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Backup")
    {
        ui->tabWidget->insertTab(0,ui->tab_9,"Backup");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Menu principal::Activar control errores de sesion")
    {
        ui->tabWidget->insertTab(0,ui->tab_10,"Menu principal::Activar control errores de sesion");
        ui->tabWidget->setCurrentPage(0);
    }
}

void Ayuda::on_lineEdit_textChanged(const QString &arg1)
{
    QRegExp regExp(arg1 , Qt::CaseInsensitive , Qt::MatchContains);
    ui->listWidget->clear();
    ui->listWidget->addItems(indice.filter(regExp));
    ui->listWidget->setCurrentRow(0);
}

void Ayuda::on_listWidget_2_currentTextChanged(const QString &currentText)
{
    ui->tabWidget->removeTab(Pestana);
    if (currentText == "Sincrono")
    {
        ui->tabWidget->insertTab(0,ui->tab_1,"Sincrono");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Sincrono::Copias sincronizadas")
    {
        ui->tabWidget->insertTab(0,ui->tab_2,"Sincrono::Copias sincronizadas");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Sincrono::Omitir palabras sincronizadas")
    {
        ui->tabWidget->insertTab(0,ui->tab_31,"Sincrono::Omitir palabras sincronizadas");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Salvaguarda")
    {
        ui->tabWidget->insertTab(0,ui->tab_41,"Salvaguarda");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Comparador")
    {
        ui->tabWidget->insertTab(0,ui->tab_5,"Comparador");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "TeleDrake")
    {
        ui->tabWidget->insertTab(0,ui->tab_6,"TeleDrake");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "VideoDrake")
    {
        ui->tabWidget->insertTab(0,ui->tab_7,"VideoDrake");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Acceso")
    {
        ui->tabWidget->insertTab(0,ui->tab_8,"Acceso");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Etiquetador")
    {
        ui->tabWidget->insertTab(0,ui->tab,"Etiquetador");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Backup")
    {
        ui->tabWidget->insertTab(0,ui->tab_9,"Backup");
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == "Menu principal::Activar control errores de sesion")
    {
        ui->tabWidget->insertTab(0,ui->tab_10,"Menu principal::Activar control errores de sesion");
        ui->tabWidget->setCurrentPage(0);
    }
}

void Ayuda::Comprobar()
{
    QString Valor;
    if (ui->tabWidget_2->currentIndex() == 0)
    {
        Valor = ui->listWidget->currentItem()->text();
    }
    else if (ui->tabWidget_2->currentIndex() == 1)
    {
        Valor = ui->listWidget_2->currentItem()->text();
    }
    ui->tabWidget->removeTab(Pestana);
    if (Valor == "Sincrono")
    {
        ui->tabWidget->insertTab(0,ui->tab_1,"Sincrono");
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == "Sincrono::Copias sincronizadas")
    {
        ui->tabWidget->insertTab(0,ui->tab_2,"Sincrono::Copias sincronizadas");
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == "Sincrono::Omitir palabras sincronizadas")
    {
        ui->tabWidget->insertTab(0,ui->tab_31,"Sincrono::Omitir palabras sincronizadas");
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == "Salvaguarda")
    {
        ui->tabWidget->insertTab(0,ui->tab_41,"Salvaguarda");
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == "Comparador")
    {
        ui->tabWidget->insertTab(0,ui->tab_5,"Comparador");
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == "TeleDrake")
    {
        ui->tabWidget->insertTab(0,ui->tab_6,"TeleDrake");
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == "VideoDrake")
    {
        ui->tabWidget->insertTab(0,ui->tab_7,"VideoDrake");
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == "Acceso")
    {
        ui->tabWidget->insertTab(0,ui->tab_8,"Acceso");
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == "Etiquetador")
    {
        ui->tabWidget->insertTab(0,ui->tab,"Etiquetador");
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == "Backup")
    {
        ui->tabWidget->insertTab(0,ui->tab_9,"Backup");
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == "Menu principal::Activar control errores de sesion")
    {
        ui->tabWidget->insertTab(0,ui->tab_10,"Menu principal::Activar control errores de sesion");
        ui->tabWidget->setCurrentPage(0);
    }
}
