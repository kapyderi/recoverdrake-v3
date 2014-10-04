#include "traductor.h"
#include "ui_traductor.h"
#include <QSqlQuery>
#include <QKeyEvent>
#include "drakesistema.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>


Traductor::Traductor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Traductor)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Stilo = "B";
    drakeSistema drake;
    user = drake.getUser();
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
    this->installEventFilter(this);
    QString Spain, English;
    QSqlQuery querySpain(db);
    querySpain.exec("SELECT spanish FROM Idioma WHERE id='2'");
    querySpain.first();
    if (querySpain.isSelect())
        Spain=querySpain.value(0).toString();
    QSqlQuery queryEnglish(db);
    queryEnglish.exec("SELECT english FROM Idioma WHERE id='2'");
    queryEnglish.first();
    if (queryEnglish.isSelect())
        English=queryEnglish.value(0).toString();
    QString idioma;
    if ( Spain == "2")
        idioma = "es";
    else if ( English == "2")
        idioma = "en";
    if (idioma == "es")
    {
        QSqlQuery Variable(db);
        Variable.exec("SELECT Idioma FROM IdiomaES");
        while(Variable.next())
        {
            ui->comboBox->addItem(Variable.value(0).toString());
            ui->comboBox_2->addItem(Variable.value(0).toString());
            ui->comboBox->findText("Español");
            ui->comboBox_2->findText("Ingles");
        }
    }
    else
    {
        QSqlQuery Variable(db);
        Variable.exec("SELECT Idioma FROM IdiomaEN");
        while(Variable.next())
        {
            ui->comboBox->addItem(Variable.value(0).toString());
            ui->comboBox_2->addItem(Variable.value(0).toString());
            ui->comboBox->findText("Spanish");
            ui->comboBox_2->findText("English");
        }
    }
}

Traductor::~Traductor()
{
    delete ui;
}

void Traductor::Valor(QString valor)
{
    if (valor == "Quitar")
        CierreTotal = 1;
}

void Traductor::closeEvent ( QCloseEvent * event )
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

void Traductor::changeEvent(QEvent *e)
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

bool Traductor::eventFilter(QObject* obj, QEvent *event)
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
        if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("Traductor"));
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void Traductor::on_pushButton_2_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}






//#!/bin/bash

//################################################################################
//## Script para llamar a Google Translate.
//## Álvaro Martín. Junio 2012.
//##
//##basado en http://crunchbanglinux.org/forums/topic/17034/access-google-translate-from-a-terminal/
//##
//################################################################################

//#lista códigos idiomas:
//    #http://en.wikipedia.org/wiki/List_of_ISO_639-1_codes

//#google se encarga de identificar el lenguaje origen al estar en auto
//DEFAULT_SOURCE_LANG=auto
//DEFAULT_TARGET_LANG=es

//help='Usage: trans <text> [[<source language>] <target language>]
//If no source language is specified autodetection will be used
//If no target language is specified spanish will be used
//Examples:
//    trans love
//        amor
//    trans love fr
//        amour
//    trans lieben de en
//        love'

//if [ $# = 0 ]
//then
//    echo "trans: missing text"
//    echo 'Usage: trans <text> [[<source language>] <target language>]'
//    echo
//    echo "Try 'trans -h' or trans --help' for options"
//    exit
//fi

//if [ "$1" = -h ] || [ "$1" = --help ]
//then
//    echo "$help"
//    exit
//fi

//if [ $3 ]; then
//    source="$2"
//    target="$3"
//elif [ $2 ]; then
//    source="$DEFAULT_SOURCE_LANG"
//    target="$2"
//else
//    source="$DEFAULT_SOURCE_LANG"
//    target="$DEFAULT_TARGET_LANG"
//fi

//echo -n "($source) $1 -> ($target)"
//result=$(wget  -U "Opera/7.50" -q -O - "http://translate.google.com/translate_a/t?client=t&text=$1&sl=$source&tl=$target" | cut -d \" -f2;)
//echo " $result"

//exit

//Lo guardamos, le damos permisos con chmod para hacerlo ejecutable y ya podemos traducir desde el terminal.Si queremos traducir una frase tendremos que entrecomillarla, por ejemplo, si hemos llamado translate al script:

//translate "el script funciona" es de

//Nos dará como resultado:

//(es) el script funciona -> (de) das Skript funktioniert

//Siguiendo los mismos pasos que hemos seguido en este ejemplo se puede crear también por ejemplo un script que nos dé definiciones de palabras según el diccionario de la RAE; sólo tenemos que averiguar la URL y estudiar la respuesta.

//https://translate.google.es/translate_a/single?client=t&sl=es&tl=en&q=hola%20que%20hay%20para%20traducir
//https://translate.google.es/translate_a/single?client=t&sl=es&tl=en&q=hola%20que%20hay%20para%20traducir%0A%0Aa%20ver%20que%20pasa%20con%20varias%20lineas
//HAY QUE HACERLO POR FRASES COMO EN ESTE EJEMPLO, HASTA RECIBIR EL SALTO DE LINEA...
//wget v -U "Firefox" -q -O - "http://translate.google.com/translate_a/t?client=t&text="pedido%20que%20hace%20los%20humanos"&sl=es&tl=en"

void Traductor::on_pushButton_3_clicked()
{
    termino = new Terminal(this);
    termino->exec();
}
