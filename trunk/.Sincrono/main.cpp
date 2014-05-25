#include <QtGui/QApplication>
#include <QCoreApplication>
#include "recoverdrake.h"
#include "drakesistema.h"
#include "bdconecttion.h"
#include "dialog.h"
#include <QLocale>
#include <QTranslator>
#include <QSqlQuery>
#include <QTextCodec>
#include <QFont>
#include <QDebug>
#include "opciones.h"
#include <QSqlDatabase>
#include <QStyleFactory>

QTranslator *qTranslator;
QSqlDatabase db;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("RecoverDrake");
    QStyleFactory::keys();
    QSettings seting("myorg","Aplica");
    QVariant opcion2;
    QString cantidad47, cantidad48, cantidad49, cantidad50, cantidad51;
    QString DatoTalla;
    QString DatoNegro;
    opcion2=seting.value("opcion2",false);
    if (!createConnection())
    {
       return 1;
    }
    db=QSqlDatabase::database("PRINCIPAL");
    QTextCodec *linuxCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(linuxCodec);
    QTextCodec::setCodecForCStrings(linuxCodec);
    QTextCodec::setCodecForLocale(linuxCodec);
    QString Spain, English;
    QSqlQuery querySpain(db);
    querySpain.exec("SELECT spanish FROM Idioma WHERE id=2");
    querySpain.first();
    if (querySpain.isValid())
        Spain=querySpain.value(0).toString();
    QSqlQuery queryEnglish(db);
    queryEnglish.exec("SELECT english FROM Idioma WHERE id=2");
    queryEnglish.first();
    if (queryEnglish.isValid())
        English=queryEnglish.value(0).toString();
    QString idioma;
    if ( Spain == "2")
    {
        idioma = "es";
        QLocale::setDefault(QLocale(QLocale::Spanish,QLocale::Spain));
    }
    else if ( English == "2")
    {
        idioma = "en";
        QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
    }
    QString Estilo;
    QSqlQuery queryEstilo(db);
    queryEstilo.exec("SELECT Style FROM Estilo WHERE id=2");
    queryEstilo.first();
    if (queryEstilo.isValid())
        Estilo=queryEstilo.value(0).toString();
    qTranslator = new QTranslator();
    qTranslator->load("/usr/share/RecoverDrake/RecoverDrake_"+idioma+".qm", ".");
    app.installTranslator(qTranslator);
    recoverdrake w;    
    QString cantidadDefecto;
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
        if (query48.isValid())
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
        w.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    }
    w.setStyle(QStyleFactory::create(Estilo));
    QApplication::setStyle(QStyleFactory::create(Estilo));
    w.showMaximized();
    if (opcion2==true)
    {        
        Dialog *sugerencias=new Dialog();
        if (cantidadDefecto == "0")
        {
            sugerencias->setStyle(QStyleFactory::create(Estilo));
            sugerencias->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        }
        sugerencias->exec();
    }
    return app.exec();
}
