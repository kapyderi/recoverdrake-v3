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
    if (valor == tr("Sincrono"))
    {
        ui->tabWidget->insertTab(0,ui->tab_1,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Sincrono::Copias sincronizadas"))
    {
        ui->tabWidget->insertTab(0,ui->tab_2,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Sincrono::Omitir palabras sincronizadas"))
    {
        ui->tabWidget->insertTab(0,ui->tab_31,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Salvaguarda"))
    {        
        ui->tabWidget->insertTab(0,ui->tab_41,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Comparador"))
    {
        ui->tabWidget->insertTab(0,ui->tab_5,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("TeleDrake"))
    {
        ui->tabWidget->insertTab(0,ui->tab_6,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("VideoDrake"))
    {
        ui->tabWidget->insertTab(0,ui->tab_7,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Acceso"))
    {
        ui->tabWidget->insertTab(0,ui->tab_8,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Etiquetador"))
    {
        ui->tabWidget->insertTab(0,ui->tab,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Backup"))
    {
        ui->tabWidget->insertTab(0,ui->tab_9,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Grabador"))
    {
        ui->tabWidget->insertTab(0,ui->tab_12,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("RecoverDrake"))
    {
        ui->tabWidget_2->setCurrentPage(1);
        ui->listWidget_2->setCurrentRow(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(ui->listWidget->currentItem()->text());
    }
    if (valor == tr("QRDrake"))
    {
        ui->tabWidget->insertTab(0,ui->tab_14,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Compresor"))
    {
        ui->tabWidget->insertTab(0,ui->tab_15,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("DB de claves"))
    {
        ui->tabWidget->insertTab(0,ui->tab_16,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Encriptador de texto"))
    {
        ui->tabWidget->insertTab(0,ui->tab_17,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Buscador"))
    {
        ui->tabWidget->insertTab(0,ui->tab_18,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Permisos"))
    {
        ui->tabWidget->insertTab(0,ui->tab_19,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (valor == tr("Test de Linux"))
    {
        ui->tabWidget->insertTab(0,ui->tab_20,valor);
        ui->tabWidget->setCurrentPage(0);
        ui->listWidget->setCurrentRow(0);
        ui->lineEdit->setText(valor);
    }
    if (ui->lineEdit->text() == "")
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
    if (currentText == tr("Sincrono"))
    {
        ui->tabWidget->insertTab(0,ui->tab_1,tr("Sincrono"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Sincrono::Copias sincronizadas"))
    {
        ui->tabWidget->insertTab(0,ui->tab_2,tr("Sincrono::Copias sincronizadas"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Sincrono::Omitir palabras sincronizadas"))
    {
        ui->tabWidget->insertTab(0,ui->tab_31,tr("Sincrono::Omitir palabras sincronizadas"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Salvaguarda"))
    {
        ui->tabWidget->insertTab(0,ui->tab_41,tr("Salvaguarda"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Comparador"))
    {
        ui->tabWidget->insertTab(0,ui->tab_5,tr("Comparador"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("TeleDrake"))
    {
        ui->tabWidget->insertTab(0,ui->tab_6,tr("TeleDrake"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("VideoDrake"))
    {
        ui->tabWidget->insertTab(0,ui->tab_7,tr("VideoDrake"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Acceso"))
    {
        ui->tabWidget->insertTab(0,ui->tab_8,tr("Acceso"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Etiquetador"))
    {
        ui->tabWidget->insertTab(0,ui->tab,tr("Etiquetador"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Backup"))
    {
        ui->tabWidget->insertTab(0,ui->tab_9,tr("Backup"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Menu principal::Activar control errores de sesion"))
    {
        ui->tabWidget->insertTab(0,ui->tab_10,tr("Menu principal::Activar control errores de sesion"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Solucion a problemas::Amule"))
    {
        ui->tabWidget->insertTab(0,ui->tab_11,tr("Solucion a problemas::Amule"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Grabador"))
    {
        ui->tabWidget->insertTab(0,ui->tab_12,tr("Grabador"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Solucion a problemas::Phonon"))
    {
        ui->tabWidget->insertTab(0,ui->tab_13,tr("Solucion a problemas::Phonon"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("QRDrake"))
    {
        ui->tabWidget->insertTab(0,ui->tab_14,tr("QRDrake"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Compresor"))
    {
        ui->tabWidget->insertTab(0,ui->tab_15,tr("Compresor"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("DB de claves"))
    {
        ui->tabWidget->insertTab(0,ui->tab_16,tr("DB de claves"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Encriptador de texto"))
    {
        ui->tabWidget->insertTab(0,ui->tab_17,tr("Encriptador de texto"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Buscador"))
    {
        ui->tabWidget->insertTab(0,ui->tab_18,tr("Buscador"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Permisos"))
    {
        ui->tabWidget->insertTab(0,ui->tab_19,tr("Permisos"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Test de Linux"))
    {
        ui->tabWidget->insertTab(0,ui->tab_20,tr("Test de Linux"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Menu utilidades::Probar USB por emulacion"))
    {
        ui->tabWidget->insertTab(0,ui->tab_21,tr("Menu utilidades::Probar USB por emulacion"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Solucion a problemas::Grub con Grub-efi"))
    {
        ui->tabWidget->insertTab(0,ui->tab_22,tr("Solucion a problemas::Grub con Grub-efi"));
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
    if (currentText == tr("Sincrono"))
    {
        ui->tabWidget->insertTab(0,ui->tab_1,tr("Sincrono"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Sincrono::Copias sincronizadas"))
    {
        ui->tabWidget->insertTab(0,ui->tab_2,tr("Sincrono::Copias sincronizadas"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Sincrono::Omitir palabras sincronizadas"))
    {
        ui->tabWidget->insertTab(0,ui->tab_31,tr("Sincrono::Omitir palabras sincronizadas"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Salvaguarda"))
    {
        ui->tabWidget->insertTab(0,ui->tab_41,tr("Salvaguarda"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Comparador"))
    {
        ui->tabWidget->insertTab(0,ui->tab_5,tr("Comparador"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("TeleDrake"))
    {
        ui->tabWidget->insertTab(0,ui->tab_6,tr("TeleDrake"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("VideoDrake"))
    {
        ui->tabWidget->insertTab(0,ui->tab_7,tr("VideoDrake"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Acceso"))
    {
        ui->tabWidget->insertTab(0,ui->tab_8,tr("Acceso"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Etiquetador"))
    {
        ui->tabWidget->insertTab(0,ui->tab,tr("Etiquetador"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Backup"))
    {
        ui->tabWidget->insertTab(0,ui->tab_9,tr("Backup"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Menu principal::Activar control errores de sesion"))
    {
        ui->tabWidget->insertTab(0,ui->tab_10,tr("Menu principal::Activar control errores de sesion"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Solucion a problemas::Amule"))
    {
        ui->tabWidget->insertTab(0,ui->tab_11,tr("Solucion a problemas::Amule"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Grabador"))
    {
        ui->tabWidget->insertTab(0,ui->tab_12,tr("Grabador"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Solucion a problemas::Phonon"))
    {
        ui->tabWidget->insertTab(0,ui->tab_13,tr("Solucion a problemas::Phonon"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("QRDrake"))
    {
        ui->tabWidget->insertTab(0,ui->tab_14,tr("QRDrake"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Compresor"))
    {
        ui->tabWidget->insertTab(0,ui->tab_15,tr("Compresor"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("DB de claves"))
    {
        ui->tabWidget->insertTab(0,ui->tab_16,tr("DB de claves"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Encriptador de texto"))
    {
        ui->tabWidget->insertTab(0,ui->tab_17,tr("Encriptador de texto"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Buscador"))
    {
        ui->tabWidget->insertTab(0,ui->tab_18,tr("Buscador"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Permisos"))
    {
        ui->tabWidget->insertTab(0,ui->tab_19,tr("Permisos"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Test de Linux"))
    {
        ui->tabWidget->insertTab(0,ui->tab_20,tr("Test de Linux"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Menu utilidades::Probar USB por emulacion"))
    {
        ui->tabWidget->insertTab(0,ui->tab_21,tr("Menu utilidades::Probar USB por emulacion"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (currentText == tr("Solucion a problemas::Grub con Grub-efi"))
    {
        ui->tabWidget->insertTab(0,ui->tab_22,tr("Solucion a problemas::Grub con Grub-efi"));
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
    if (Valor == tr("Sincrono"))
    {
        ui->tabWidget->insertTab(0,ui->tab_1,tr("Sincrono"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Sincrono::Copias sincronizadas"))
    {
        ui->tabWidget->insertTab(0,ui->tab_2,tr("Sincrono::Copias sincronizadas"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Sincrono::Omitir palabras sincronizadas"))
    {
        ui->tabWidget->insertTab(0,ui->tab_31,tr("Sincrono::Omitir palabras sincronizadas"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Salvaguarda"))
    {
        ui->tabWidget->insertTab(0,ui->tab_41,tr("Salvaguarda"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Comparador"))
    {
        ui->tabWidget->insertTab(0,ui->tab_5,tr("Comparador"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("TeleDrake"))
    {
        ui->tabWidget->insertTab(0,ui->tab_6,tr("TeleDrake"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("VideoDrake"))
    {
        ui->tabWidget->insertTab(0,ui->tab_7,tr("VideoDrake"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Acceso"))
    {
        ui->tabWidget->insertTab(0,ui->tab_8,tr("Acceso"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Etiquetador"))
    {
        ui->tabWidget->insertTab(0,ui->tab,tr("Etiquetador"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Backup"))
    {
        ui->tabWidget->insertTab(0,ui->tab_9,tr("Backup"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Menu principal::Activar control errores de sesion"))
    {
        ui->tabWidget->insertTab(0,ui->tab_10,tr("Menu principal::Activar control errores de sesion"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Solucion a problemas::Amule"))
    {
        ui->tabWidget->insertTab(0,ui->tab_11,tr("Solucion a problemas::Amule"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Grabador"))
    {
        ui->tabWidget->insertTab(0,ui->tab_12,tr("Grabador"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Solucion a problemas::Phonon"))
    {
        ui->tabWidget->insertTab(0,ui->tab_13,tr("Solucion a problemas::Phonon"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("QRDrake"))
    {
        ui->tabWidget->insertTab(0,ui->tab_14,tr("QRDrake"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Compresor"))
    {
        ui->tabWidget->insertTab(0,ui->tab_15,tr("Compresor"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("DB de claves"))
    {
        ui->tabWidget->insertTab(0,ui->tab_16,tr("DB de claves"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Encriptador de texto"))
    {
        ui->tabWidget->insertTab(0,ui->tab_17,tr("Encriptador de texto"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Buscador"))
    {
        ui->tabWidget->insertTab(0,ui->tab_18,tr("Buscador"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Permisos"))
    {
        ui->tabWidget->insertTab(0,ui->tab_19,tr("Permisos"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Test de Linux"))
    {
        ui->tabWidget->insertTab(0,ui->tab_20,tr("Test de Linux"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Menu utilidades::Probar USB por emulacion"))
    {
        ui->tabWidget->insertTab(0,ui->tab_21,tr("Menu utilidades::Probar USB por emulacion"));
        ui->tabWidget->setCurrentPage(0);
    }
    if (Valor == tr("Solucion a problemas::Grub con Grub-efi"))
    {
        ui->tabWidget->insertTab(0,ui->tab_22,tr("Solucion a problemas::Grub con Grub-efi"));
        ui->tabWidget->setCurrentPage(0);
    }
}
