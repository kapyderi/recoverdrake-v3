#include "traductor.h"
#include "ui_traductor.h"
#include <QSqlQuery>
#include <QKeyEvent>
#include "drakesistema.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QProcess>
#include <QProgressDialog>

Traductor::Traductor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Traductor)
{
    ui->setupUi(this);
    Posicion = 0;
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
    if ( Spain == "2")
        idioma = "es";
    else if ( English == "2")
        idioma = "en";
    ui->comboBox->addItem("auto");
    if (idioma == "es")
    {        
        QSqlQuery Variable(db);
        Variable.exec("SELECT Idioma FROM IdiomaES ORDER BY Idioma");
        while(Variable.next())
        {
            if (ui->comboBox->findText(Variable.value(0).toString()) == -1)
            {
                ui->comboBox->addItem(Variable.value(0).toString());
                ui->comboBox_2->addItem(Variable.value(0).toString());

            }
        }
        ui->comboBox->setCurrentIndex(ui->comboBox->findText("auto)"));
        ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText("inglés"));
        QString Entrada, Salida;
        Entrada = ui->comboBox->currentText();
        Salida = ui->comboBox_2->currentText();
        QSqlQuery Clave(db);
        Clave.exec("SELECT Clave FROM IdiomaES WHERE Idioma='"+Entrada+"'");
        Clave.first();
        if (ui->comboBox->currentText() != "auto")
            Origen = Clave.value(0).toString();
        else
            Origen = "auto";
        QSqlQuery Clave1(db);
        Clave1.exec("SELECT Clave FROM IdiomaES WHERE Idioma='"+Salida+"'");
        Clave1.first();
        Destino = Clave1.value(0).toString();
    }
    else
    {
        QSqlQuery Variable(db);
        Variable.exec("SELECT Idioma FROM IdiomaEN ORDER BY Idioma");
        while(Variable.next())
        {
            if (ui->comboBox->findText(Variable.value(0).toString()) == -1)
            {
                ui->comboBox->addItem(Variable.value(0).toString());
                ui->comboBox_2->addItem(Variable.value(0).toString());
            }
        }
        ui->comboBox->setCurrentIndex(ui->comboBox->findText("auto"));
        ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText("English"));
        QString Entrada, Salida;
        Entrada = ui->comboBox->currentText();
        Salida = ui->comboBox_2->currentText();
        QSqlQuery Clave(db);
        Clave.exec("SELECT Clave FROM IdiomaEN WHERE Idioma='"+Entrada+"'");
        Clave.first();
        if (ui->comboBox->currentText() != "auto")
            Origen = Clave.value(0).toString();
        else
            Origen = "auto";
        QSqlQuery Clave1(db);
        Clave1.exec("SELECT Clave FROM IdiomaEN WHERE Idioma='"+Salida+"'");
        Clave1.first();
        Destino = Clave1.value(0).toString();
    }
    ui->textEdit->installEventFilter(this);
    ui->textEdit->acceptDrops();
    Posicion = 1;
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

void Traductor::on_comboBox_currentIndexChanged(const QString &arg1)
{    
    QString Entrada, Salida;
    Entrada = ui->comboBox->currentText();
    Salida = ui->comboBox_2->currentText();
    if (arg1 == ui->comboBox_2->currentText())
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Si pones el mismo idioma la traduccion no se realizara."));
        m.exec();
        return;
    }
    else
    {
        if (idioma == "es")
        {
            QSqlQuery Clave(db);
            Clave.exec("SELECT Clave FROM IdiomaES WHERE Idioma='"+Entrada+"'");
            Clave.first();
            if (ui->comboBox->currentText() != "auto")
                Origen = Clave.value(0).toString();
            else
                Origen = "auto";
            QSqlQuery Clave1(db);
            Clave1.exec("SELECT Clave FROM IdiomaES WHERE Idioma='"+Salida+"'");
            Clave1.first();
            Destino = Clave1.value(0).toString();
        }
        else
        {
            QSqlQuery Clave(db);
            Clave.exec("SELECT Clave FROM IdiomaEN WHERE Idioma='"+Entrada+"'");
            Clave.first();
            if (ui->comboBox->currentText() != "auto")
                Origen = Clave.value(0).toString();
            else
                Origen = "auto";
            QSqlQuery Clave1(db);
            Clave1.exec("SELECT Clave FROM IdiomaEN WHERE Idioma='"+Salida+"'");
            Clave1.first();
            Destino = Clave1.value(0).toString();
        }
    }
    if (Posicion == 1)
        on_pushButton_clicked();
}

void Traductor::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString Entrada, Salida;
    Entrada = ui->comboBox->currentText();
    Salida = ui->comboBox_2->currentText();
    if (arg1 == ui->comboBox->currentText())
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Si pones el mismo idioma la traduccion no se realizara."));
        m.exec();
        return;
    }
    else
    {
        if (idioma == "es")
        {
            QSqlQuery Clave(db);
            Clave.exec("SELECT Clave FROM IdiomaES WHERE Idioma='"+Entrada+"'");
            Clave.first();
            if (ui->comboBox->currentText() != "auto")
                Origen = Clave.value(0).toString();
            else
                Origen = "auto";
            QSqlQuery Clave1(db);
            Clave1.exec("SELECT Clave FROM IdiomaES WHERE Idioma='"+Salida+"'");
            Clave1.first();
            Destino = Clave1.value(0).toString();
        }
        else
        {
            QSqlQuery Clave(db);
            Clave.exec("SELECT Clave FROM IdiomaEN WHERE Idioma='"+Entrada+"'");
            Clave.first();
            if (ui->comboBox->currentText() != "auto")
                Origen = Clave.value(0).toString();
            else
                Origen = "auto";
            QSqlQuery Clave1(db);
            Clave1.exec("SELECT Clave FROM IdiomaEN WHERE Idioma='"+Salida+"'");
            Clave1.first();
            Destino = Clave1.value(0).toString();
        }
    }
    if (Posicion == 1)
        on_pushButton_clicked();
}

void Traductor::on_pushButton_clicked()
{
    ui->textEdit_2->clear();
    QString ListTrad = ui->textEdit->text();
    QStringList Lista =ListTrad.split("\n");
    QString ValorLinea;
    QProgressDialog progress(tr("Realizando traduccion... Espera por favor"), tr("Cancelar"), 0, Lista.count(),this);
    progress.show();
    for (int a=0;a<Lista.count();a++)
    {
        qApp->processEvents();
        progress.setValue(a);
        if (progress.wasCanceled())
            break;
        QString Dato = Lista.value(a);
        Dato.replace(" ","%20");
        ValorLinea = "wget v -U \"Firefox\" -q -O - \"http://translate.google.com/translate_a/t?client=t&text=\"%1\"&sl=%2&tl=%3";
        ValorLinea = ValorLinea.arg(Dato).arg(Origen).arg(Destino);
        QString Datos = tramitarDatos(ValorLinea);
        ui->textEdit_2->append(Datos);
    }
    progress.setValue(Lista.count());
}

void Traductor::on_pushButton_3_clicked()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
}

QString Traductor::tramitarDatos(QString Datos)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosGrep;
    QByteArray IpRouter;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosGrep << "-d" << "\"" << "-f2";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start(Datos);
    procesoGrep->start("cut", argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    procesoGrep->waitForFinished();
    IpRouter = procesoGrep->readAllStandardOutput();
    delete procesoCat;
    delete procesoGrep;
    QString res = QString(IpRouter);
    res.chop(1);
    return res;
}

//#!/bin/bash

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
