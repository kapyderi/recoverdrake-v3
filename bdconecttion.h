#ifndef BDCONECTTION_H
#define BDCONECTTION_H

#include <QSqlDatabase>
#include <QtGui/QApplication>
#include <stdlib.h>
#include <QMessageBox>
#include "drakesistema.h"
#include "recoverdrake.h"
#include <QSqlQuery>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <QDebug>
#include "notas.h"
#include <QSqlError>
#include <QTest>
#include <QProgressDialog>
#include <QStringList>
#include <QFileDialog>
#include <QStyleFactory>

static bool createConnection()
{    
    QString cantidadDefecto, Estilo;
    QMessageBox m;
    int Dato1, Dato2;
    if (QSqlDatabase::isDriverAvailable("QSQLITE"))
    {
        QFile file("/usr/share/RecoverDrake/Miscelanea.RecoverDrake.db.sqlite");
        if (file.exists() == false)
        {
            m.setText("Es la primera vez que utilizas RecoverDrake por lo que se creara una base de datos con las configuraciones por defecto.");
            m.exec();
            system("cp -v /root/Miscelanea.RecoverDrake.db.sqlite /usr/share/RecoverDrake/Miscelanea.RecoverDrake.db.sqlite");
        }
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","PRINCIPAL");
        QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE","COMPARA");
        QSqlDatabase SM = QSqlDatabase::addDatabase("QSQLITE","sqlite_master");
        db.setDatabaseName("/usr/share/RecoverDrake/Miscelanea.RecoverDrake.db.sqlite");
        DB.setDatabaseName("/root/Miscelanea.RecoverDrake.db.sqlite");
        SM.setDatabaseName("/usr/share/RecoverDrake/Miscelanea.RecoverDrake.db.sqlite");
        if (!db.open())
        {
            m.setText("<b>Error grave</b>:<p>No se ha podido abrir la base de datos necesaria de configuraciones.<p>Comprueba que existe Miscelanea.RecoverDrake.db.sqlite en la ruta /usr/share/RecoverDrake.");
            m.exec();
            return false;
        }
        else if (!DB.open())
        {
            m.setText("<b>Error grave</b>:<p>No se ha podido abrir la base de datos espejo necesaria de configuraciones.<p>Comprueba que existe Miscelanea.RecoverDrake.db.sqlite en la ruta /usr/share/RecoverDrake.");
            m.exec();
            return false;
        }
        else if (!SM.open())
        {
            m.setText("<b>Error grave</b>:<p>No se ha podido abrir la base de datos espejo necesaria de configuraciones.<p>Comprueba que existe Miscelanea.RecoverDrake.db.sqlite en la ruta /usr/share/RecoverDrake.");
            m.exec();
            return false;
        }
        else
        {
            QSqlQuery query52(db);
            query52.exec("SELECT Style FROM Estilo WHERE id=2");
            query52.first();
            if (query52.isValid())
                 Estilo=query52.value(0).toString();
            QApplication::setStyle(QStyleFactory::create(Estilo));
            drakeSistema drake;
            QString X = drake.getResolution();
            QString Y = drake.getResolucion();
            QStringList LasY = Y.split(",");
            QString Y2 = LasY.value(2);
            Y2=Y2.remove(" ").remove("maximum");
            QStringList LasX = X.split(" ");
            QString X2 = LasX.value(3);
            QStringList Parcial2 = X2.split("x");
            Dato1 = Parcial2.value(0).toInt();
            Dato2 = Parcial2.value(1).toInt();
            QSqlQuery Vers(db);
            Vers.exec("SELECT Version FROM Control");
            Vers.last();
            QString Usu = Vers.value(0).toString();
            notas *acc=new notas();
            QString Ver=acc->Ultimo;           
            if (Usu == Ver)
            {
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
                   QLocale::setDefault(QLocale(QLocale::Spanish, QLocale::Spain));
                }
                else if ( English == "2")
                {
                    idioma = "en";
                    QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
                }
                QString cantidad;
                QSqlQuery query(db);
                query.exec("SELECT inicio FROM Miscelanea WHERE id=2");
                query.first();
                if (query.isValid())
                    cantidad=query.value(0).toString();
                if ( cantidad == "0" )
                {
                    drakeSistema drake;
                    QString user;
                    QString Distro;
                    user = drake.getUser();
                    Distro = drake.getDistrop();
                    QString cantidad47;
                    QString cantidad48;
                    QString cantidad49;
                    QString cantidad50;
                    QString cantidad51;
                    QString DatoTalla;
                    QString DatoNegro;
                    QMessageBox m;
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
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");                                                
                        m.setStyle(QStyleFactory::create(Estilo));                        
                    }
                    if (Dato1 != 1280 || Dato2 != 1024)
                    {
                        if (Dato1 <= 1279 || Dato2 <= 1023)
                        {
                            if (idioma == "en")
                            {
                                m.setText("Welcome, <b>" + user + "</b>.<p>""<b>I hope that Linux <b> (" + Distro + ") as RecoverDrake ones you like. <p>" "The configuration database has been loaded successfully. <p> "" <B>NOTICE:</b> Access to the main program may take a few seconds while collecting all data necessary for its execution.<p>""Please be patient...<p>""<center><b>IMPORTANT NOTE</center>""<center><b>You have defined a resolution of "+X2+" pixels and we recommend a minimum resolution of 1280x1024 pixels (you can use up to a maximum resolution of "+Y2+"), although you can continue.</center><p>""Click <b> OK </b> to continue loading the program...");
                            }
                            else
                            {
                                m.setText("Bienvenido, <b>"+user+"</b>.<p>""<b>Espero que tanto Linux ("+Distro+") como RecoverDrake sean de tu agrado.<p>""La base de datos de configuraciones ha sido cargada con exito.<p>""<B>AVISO:</b> El acceso al programa principal puede demorarse unos segundos mientras se recopilan todos los datos necesarios para su ejecucion.<p>""Por favor se paciente...<p>""<center><b>NOTA IMPORTANTE</center>""<center><b>Tienes definida una resolucion de "+X2+" pixeles y se recomienda una resolucion minima de 1280x1024 pixeles (puedes utilizar hasta una resolucion maxima de "+Y2+"), aunque se puede continuar.</center><p>""Pulsa <b>OK</b> para seguir con la carga del programa...");
                            }
                        }
                    }
                    else
                    {
                        if (idioma == "en")
                        {
                            m.setText("Welcome, <b>" + user + "</b>.<p>""<b>I hope that Linux <b> (" + Distro + ") as RecoverDrake ones you like. <p>" "The configuration database has been loaded successfully. <p> "" <B>NOTICE:</b> Access to the main program may take a few seconds while collecting all data necessary for its execution.<p>""Please be patient...<p>""Click <b> OK </b> to continue loading the program...");
                        }
                        else
                        {
                            m.setText("Bienvenido, <b>"+user+"</b>.<p>""<b>Espero que tanto Linux ("+Distro+") como RecoverDrake sean de tu agrado.<p>""La base de datos de configuraciones ha sido cargada con exito.<p>""<B>AVISO:</b> El acceso al programa principal puede demorarse unos segundos mientras se recopilan todos los datos necesarios para su ejecucion.<p>""Por favor se paciente...<p>""Pulsa <b>OK</b> para seguir con la carga del programa...");
                        }
                    }
                    m.exec();
               }
               return true;
           }
           else if (Usu != Ver)
           {
                int respuesta = 0;
                {
                    respuesta = QMessageBox::question(0,QString::fromUtf8("Nueva version de RecoverDrake"),
                                       QString::fromUtf8("<center><b>Nueva version de RecoverDrake localizada en el equipo<b></center><p>"
                                       "He comprobado que tienes instalada recientemente una nueva version de "
                                       "RecoverDrake <b>("+Ver+")</b> y puedes actualizar tus datos de versiones anteriores o crear una base de datos con lo minimo.<p>"
                                       "<B>NOTA: Te recomiendo que actualices para no perder configuraciones y datos creados por ti.</B><p>"
                                       "&iquest;Actualizar base de datos a ultima version?"), QMessageBox::Ok, QMessageBox::No);
                }
                if (respuesta == QMessageBox::Ok)
                {
                       QString path="/usr/share/RecoverDrake/";
                       QString fileNameOrigen = QFileDialog::getOpenFileName(0,QString::fromUtf8("Base de datos antigua .sqlite"),
                                            path,"Archivo .sqlite (*.sqlite)");
                       if (fileNameOrigen.isEmpty())
                            return 0;
                       db.close();
                       system("cp -v '"+fileNameOrigen+"' /usr/share/RecoverDrake/Miscelanea.RecoverDrake.db.sqlite.backup");
                       system("cp -v '"+fileNameOrigen+"' /usr/share/RecoverDrake/Miscelanea.RecoverDrake.db.sqlite");
                       db.open();
                       DB.close();
                       system("cp -v /root/Miscelanea.RecoverDrake.db.sqlite /root/Miscelanea.RecoverDrake.db.sqlite.backup");
                       DB.open();
                       QProgressDialog progress("Encontrada nueva version "+Ver+", actualizando Base de datos de RecoverDrake... Espera por favor", "Cancelar", 0, 42);
                       progress.setWindowModality(Qt::WindowModal);
                       progress.show();
                       for(int i=0;i<42;i++ )
                       {
                           progress.setValue(i);
                           if (progress.wasCanceled())
                               break;
                           if (i==0)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Opcion2'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad3, cantidad4, cantidad5, cantidad6, cantidad7, cantidad8, cantidad9, cantidad10, cantidad11, cantidad12, cantidad13;
                                   QSqlQuery query3(db);
                                   query3.exec("SELECT camouflage_pa,efsplitter,generico_pa,hacha1_pa,hacha2_pa,hachapro_pa,mxs_pa,sf_pa,zip_pa,camaleon1_pa,camaleon2_pa FROM Opcion2 WHERE id=2");
                                   query3.first();
                                   if (query3.isValid())
                                   {
                                        cantidad3=query3.value(0).toString();
                                        cantidad4=query3.value(1).toString();
                                        cantidad5=query3.value(2).toString();
                                        cantidad6=query3.value(3).toString();
                                        cantidad7=query3.value(4).toString();
                                        cantidad8=query3.value(5).toString();
                                        cantidad9=query3.value(6).toString();
                                        cantidad10=query3.value(7).toString();
                                        cantidad11=query3.value(8).toString();
                                        cantidad12=query3.value(9).toString();
                                        cantidad13=query3.value(10).toString();
                                        QSqlQuery Opcion2(DB);
                                        Opcion2.exec("UPDATE Opcion2 SET camouflage_pa='"+cantidad3+"',efsplitter_pa='"+cantidad4+"',generico_pa='"+cantidad5+"',hacha1_pa='"+cantidad6+"',hacha2_pa='"+cantidad7+"',hachapro_pa='"+cantidad8+"',mxs_pa='"+cantidad9+"',sf_pa='"+cantidad10+"',zip_pa='"+cantidad11+"',camaleon1_pa='"+cantidad12+"',camaleon2_pa='"+cantidad13+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==1)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='ethernet'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad40;
                                   QSqlQuery query38(db);
                                   query38.exec("SELECT conexion FROM ethernet WHERE id=2");
                                   query38.first();
                                   if (query38.isValid())
                                   {
                                        cantidad40=query38.value(0).toString();
                                        QSqlQuery ethernet(DB);
                                        ethernet.exec("UPDATE ethernet SET conexion='"+cantidad40+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==2)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='red'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad41, cantidad42;
                                   QSqlQuery query39(db);
                                   query39.exec("SELECT ethernet,wifi FROM red WHERE id=2");
                                   query39.first();
                                   if (query39.isValid())
                                   {
                                        cantidad41=query39.value(0).toString();
                                        cantidad42=query39.value(1).toString();
                                        QSqlQuery red(DB);
                                        red.exec("UPDATE red SET ethernet='"+cantidad41+"',wifi='"+cantidad42+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==3)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Idioma'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43, cantidad44;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT spanish,english FROM Idioma WHERE id=2");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        cantidad44=query41.value(1).toString();
                                        QSqlQuery Idioma(DB);
                                        Idioma.exec("UPDATE Idioma SET spanish='"+cantidad43+"',english='"+cantidad44+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==4)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='wlistanegra'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery wlistanegr(db);
                                   wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM wlistanegra");
                                   int cuenta, comienzo;
                                   wlistanegr.first();
                                   cuenta = wlistanegr.value(0).toInt();
                                   QSqlQuery wlistanegra(db);
                                   wlistanegra.exec("SELECT ip,mac FROM wlistanegra");
                                   QProgressDialog progressMenu("Actualizando lista negra de ip's... Espera por favor", "Cancelar", 0, cuenta);
                                   progressMenu.setWindowModality(Qt::WindowModal);
                                   progressMenu.show();
                                   comienzo=0;
                                   int cantidad=1;
                                   while(wlistanegra.next())
                                   {
                                        if (cantidad == 1)
                                        {
                                            DB.transaction();
                                        }
                                        progressMenu.setValue(comienzo++);
                                        if (progressMenu.wasCanceled())
                                            break;
                                        QString DatIp = wlistanegra.value(0).toString();
                                        QString DatMac = wlistanegra.value(1).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT ip,mac FROM wlistanegra WHERE ip='"+DatIp+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QSqlQuery Wdark(DB);
                                            Wdark.prepare("INSERT INTO wlistanegra (ip,mac)"
                                                          "VALUES (:ip,:mac)");
                                            Wdark.bindValue(":ip", DatIp);
                                            Wdark.bindValue(":mac", DatMac);
                                            Wdark.exec();
                                        }
                                        cantidad++;
                                        if (cantidad == 50)
                                        {
                                            cantidad=1;
                                            DB.commit();
                                        }
                                   }
                                   progressMenu.setValue(cuenta);
                                   DB.commit();
                               }
                           }
                           if (i==5)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='wlistablanca'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery wlistablanc(db);
                                   wlistablanc.exec("SELECT COUNT(id) as Cantidad FROM wlistablanca");
                                   int cuenta, comienzo;
                                   wlistablanc.first();
                                   cuenta = wlistablanc.value(0).toInt();
                                   QSqlQuery wlistablanca(db);
                                   wlistablanca.exec("SELECT ip,mac FROM wlistablanca");
                                   QProgressDialog progressMenu("Actualizando lista blanca de ip's... Espera por favor", "Cancelar", 0, cuenta);
                                   progressMenu.setWindowModality(Qt::WindowModal);
                                   progressMenu.show();
                                   comienzo=0;
                                   int cantidad=1;
                                   while(wlistablanca.next())
                                   {
                                        if (cantidad == 1)
                                        {
                                            DB.transaction();
                                        }
                                        progressMenu.setValue(comienzo++);
                                        if (progressMenu.wasCanceled())
                                            break;
                                        QString DatIp = wlistablanca.value(0).toString();
                                        QString DatMac = wlistablanca.value(1).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT ip,mac FROM wlistablanca WHERE ip='"+DatIp+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QSqlQuery Wwhite(DB);
                                            Wwhite.prepare("INSERT INTO wlistablanca (ip,mac)"
                                                           "VALUES (:ip,:mac)");
                                            Wwhite.bindValue(":ip", DatIp);
                                            Wwhite.bindValue(":mac", DatMac);
                                            Wwhite.exec();
                                        }
                                        cantidad++;
                                        if (cantidad == 50)
                                        {
                                            cantidad=1;
                                            DB.commit();
                                        }
                                   }
                                   progressMenu.setValue(cuenta);
                                   DB.commit();
                               }
                           }
                           if (i==6)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Palabra'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery Palabr(db);
                                   Palabr.exec("SELECT COUNT(id) as Cantidad FROM Palabra");
                                   int cuenta, comienzo;
                                   Palabr.first();
                                   cuenta = Palabr.value(0).toInt();
                                   QSqlQuery Palabra(db);
                                   Palabra.exec("SELECT palabra FROM Palabra");
                                   QProgressDialog progressMenu("Actualizando lista de palabras clave... Espera por favor", "Cancelar", 0, cuenta);
                                   progressMenu.setWindowModality(Qt::WindowModal);
                                   progressMenu.show();
                                   comienzo=0;
                                   int cantidad=1;
                                   while(Palabra.next())
                                   {
                                        if (cantidad == 1)
                                        {
                                            DB.transaction();
                                        }
                                        progressMenu.setValue(comienzo++);
                                        if (progressMenu.wasCanceled())
                                            break;
                                        QString DatPalabra = Palabra.value(0).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT palabra FROM Palabra WHERE palabra='"+DatPalabra+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QString ValPalabra = RecDat.value(0).toString();
                                            if (DatPalabra != ValPalabra)
                                            {
                                                QSqlQuery Wwhite(DB);
                                                Wwhite.prepare("INSERT INTO Palabra (palabra)"
                                                              "VALUES (:palabra)");
                                                Wwhite.bindValue(":palabra", DatPalabra);
                                                Wwhite.exec();
                                            }
                                        }
                                        cantidad++;
                                        if (cantidad == 50)
                                        {
                                            cantidad=1;
                                            DB.commit();
                                        }
                                   }
                                   progressMenu.setValue(cuenta);
                                   DB.commit();
                               }
                           }
                           if (i==7)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Video'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43, cantidad44;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT vlc,parole FROM Video WHERE id=2");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        cantidad44=query41.value(1).toString();
                                        QSqlQuery Video(DB);
                                        Video.exec("UPDATE Video SET vlc='"+cantidad43+"',parole='"+cantidad44+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==8)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Font'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43, cantidad44, cantidad45;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT Fuente,Estilo,Talla FROM Font WHERE id=2");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        cantidad44=query41.value(1).toString();
                                        cantidad45=query41.value(2).toString();
                                        QSqlQuery Font(DB);
                                        Font.exec("UPDATE Font SET Fuente='"+cantidad43+"',Estilo='"+cantidad44+"',Talla='"+cantidad45+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==9)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Color'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43, cantidad44;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT ColorTexto,ColorFondo FROM Color WHERE id=2");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        cantidad44=query41.value(1).toString();
                                        QSqlQuery Color(DB);
                                        Color.exec("UPDATE Color SET ColorTexto='"+cantidad43+"',ColorFondo='"+cantidad44+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==10)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Miscelanea'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43, cantidad44, cantidad45;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT Defecto,inicio,Dependencias FROM Miscelanea WHERE id=2");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        cantidad44=query41.value(1).toString();
                                        cantidad45=query41.value(2).toString();
                                        QSqlQuery Miscelanea(DB);
                                        Miscelanea.exec("UPDATE Miscelanea SET Defecto='"+cantidad43+"',inicio='"+cantidad44+"',Dependencias='"+cantidad45+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==11)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Opcion'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43, cantidad44, cantidad45;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT Audio128,Audio192,Audio320 FROM Opcion WHERE id=2");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        cantidad44=query41.value(1).toString();
                                        cantidad45=query41.value(2).toString();
                                        QSqlQuery Opcion(DB);
                                        Opcion.exec("UPDATE Opcion SET Audio128='"+cantidad43+"',Audio192='"+cantidad44+"',Audio320='"+cantidad45+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==12)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Cancion'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT Posicion FROM Cancion WHERE id=1");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        QSqlQuery Cancion(DB);
                                        Cancion.exec("UPDATE Cancion SET Posicion='"+cantidad43+"' WHERE id=1");
                                   }
                               }
                           }
                           if (i==13)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Musica'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery Music(db);
                                   Music.exec("SELECT COUNT(id) as Cantidad FROM Musica");
                                   int cuenta, comienzo;
                                   Music.first();
                                   cuenta = Music.value(0).toInt();
                                   QSqlQuery Musica(db);
                                   Musica.exec("SELECT Nombre,Ruta FROM Musica");
                                   QProgressDialog progressMenu("Actualizando lista de canciones... Espera por favor", "Cancelar", 0, cuenta);
                                   progressMenu.setWindowModality(Qt::WindowModal);
                                   progressMenu.show();
                                   comienzo=0;
                                   int cantidad=1;
                                   while(Musica.next())
                                   {
                                        if (cantidad == 1)
                                        {
                                            DB.transaction();
                                        }
                                        progressMenu.setValue(comienzo++);
                                        if (progressMenu.wasCanceled())
                                            break;
                                        QString DatIp = Musica.value(0).toString();
                                        QString DatMac = Musica.value(1).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT Nombre,Ruta FROM Musica WHERE Nombre='"+DatIp+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QSqlQuery Wwhite(DB);
                                            Wwhite.prepare("INSERT INTO Musica (Nombre,Ruta)"
                                                           "VALUES (:Nombre,:Ruta)");
                                            Wwhite.bindValue(":Nombre", DatIp);
                                            Wwhite.bindValue(":Ruta", DatMac);
                                            Wwhite.exec();
                                        }
                                        cantidad++;
                                        if (cantidad == 50)
                                        {
                                            cantidad=1;
                                            DB.commit();
                                        }
                                   }
                                   progressMenu.setValue(cuenta);
                                   DB.commit();
                               }
                           }
                           if (i==14)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='PosRadio'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT Posicion FROM PosRadio WHERE id=1");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        QSqlQuery Cancion(DB);
                                        Cancion.exec("UPDATE PosRadio SET Posicion='"+cantidad43+"' WHERE id=1");
                                   }
                               }
                           }
                           if (i==15)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Radio'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery Radi(db);
                                   Radi.exec("SELECT COUNT(id) as Cantidad FROM Radio");
                                   int cuenta, comienzo;
                                   Radi.first();
                                   cuenta = Radi.value(0).toInt();
                                   QSqlQuery Radio(db);
                                   Radio.exec("SELECT Estilo,Nombre,Url FROM Radio");
                                   QProgressDialog progressMenu("Actualizando lista de canales de radio... Espera por favor", "Cancelar", 0, cuenta);
                                   progressMenu.setWindowModality(Qt::WindowModal);
                                   progressMenu.show();
                                   comienzo=0;
                                   int cantidad=1;
                                   while(Radio.next())
                                   {
                                        if (cantidad == 1)
                                        {
                                            DB.transaction();
                                        }
                                        progressMenu.setValue(comienzo++);
                                        if (progressMenu.wasCanceled())
                                            break;
                                        QString DatEst = Radio.value(0).toString();
                                        QString DatNom = Radio.value(1).toString();
                                        QString DatUrl = Radio.value(2).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT Estilo,Nombre,Url FROM Radio WHERE Nombre='"+DatNom+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QString ValIp = RecDat.value(1).toString();
                                            if (DatNom != ValIp)
                                            {
                                                QSqlQuery Wwhite(DB);
                                                Wwhite.prepare("INSERT INTO Radio (Estilo,Nombre,Url)"
                                                              "VALUES (:Estilo,:Nombre,:Url)");
                                                Wwhite.bindValue(":Estilo", DatEst);
                                                Wwhite.bindValue(":Nombre", DatNom);
                                                Wwhite.bindValue(":Url", DatUrl);
                                                Wwhite.exec();
                                            }
                                            else
                                            {
                                                QSqlQuery Wwhite(DB);
                                                Wwhite.exec("UPDATE Radio SET Estilo='"+DatEst+"',Url='"+DatUrl+"' WHERE Nombre='"+DatNom+"'");
                                            }
                                        }
                                        cantidad++;
                                        if (cantidad == 50)
                                        {
                                            cantidad=1;
                                            DB.commit();
                                        }
                                   }
                                   progressMenu.setValue(cuenta);
                                   DB.commit();
                               }
                           }
                           if (i==16)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Television'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery Televisio(db);
                                   Televisio.exec("SELECT COUNT(id) as Cantidad FROM Television");
                                   int cuenta, comienzo;
                                   Televisio.first();
                                   cuenta = Televisio.value(0).toInt();
                                   QSqlQuery Television(db);
                                   Television.exec("SELECT Categoria,Nombre,Direccion FROM Television");
                                   QProgressDialog progressMenu("Actualizando lista de canales de television... Espera por favor", "Cancelar", 0, cuenta);
                                   progressMenu.setWindowModality(Qt::WindowModal);
                                   progressMenu.show();
                                   comienzo=0;
                                   int cantidad=1;
                                   while(Television.next())
                                   {
                                        if (cantidad == 1)
                                        {
                                            DB.transaction();
                                        }
                                        progressMenu.setValue(comienzo++);
                                        if (progressMenu.wasCanceled())
                                            break;
                                        QString DatEst = Television.value(0).toString();
                                        QString DatNom = Television.value(1).toString();
                                        QString DatUrl = Television.value(2).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT Categoria,Nombre,Direccion FROM Television WHERE Nombre='"+DatNom+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QString ValIp = RecDat.value(1).toString();
                                            if (DatNom != ValIp)
                                            {
                                                QSqlQuery Wwhite(DB);
                                                Wwhite.prepare("INSERT INTO Television (Categoria,Nombre,Direccion)"
                                                              "VALUES (:Categoria,:Nombre,:Direccion)");
                                                Wwhite.bindValue(":Categoria", DatEst);
                                                Wwhite.bindValue(":Nombre", DatNom);
                                                Wwhite.bindValue(":Direccion", DatUrl);
                                                Wwhite.exec();
                                            }
                                            else
                                            {
                                                QSqlQuery Wwhite(DB);
                                                Wwhite.exec("UPDATE Television SET Categoria='"+DatEst+"',Direccion='"+DatUrl+"' WHERE Nombre='"+DatNom+"'");
                                            }
                                        }
                                        cantidad++;
                                        if (cantidad == 50)
                                        {
                                            cantidad=1;
                                            DB.commit();
                                        }
                                   }
                                   progressMenu.setValue(cuenta);
                                   DB.commit();
                               }
                           }
                           if (i==17)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='PosTele'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT Posicion FROM PosTele WHERE id=1");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        QSqlQuery Cancion(DB);
                                        Cancion.exec("UPDATE PosTele SET Posicion='"+cantidad43+"' WHERE id=1");
                                   }
                               }
                           }
                           if (i==18)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Acceso'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery Acces(db);
                                   Acces.exec("SELECT COUNT(id) as Cantidad FROM Acceso");
                                   int cuenta, comienzo;
                                   Acces.first();
                                   cuenta = Acces.value(0).toInt();
                                   QSqlQuery Acceso(db);
                                   Acceso.exec("SELECT Usuario,Clave,Nivel,Activo,Pregunta,Respuesta FROM Acceso");
                                   QProgressDialog progressMenu("Actualizando Usuarios... Espera por favor", "Cancelar", 0, cuenta);
                                   progressMenu.setWindowModality(Qt::WindowModal);
                                   progressMenu.show();
                                   comienzo=0;
                                   int cantidad=1;
                                   while(Acceso.next())
                                   {
                                        if (cantidad == 1)
                                        {
                                            DB.transaction();
                                        }
                                        progressMenu.setValue(comienzo++);
                                        if (progressMenu.wasCanceled())
                                            break;
                                        QString DatUsu = Acceso.value(0).toString();
                                        QString DatClv = Acceso.value(1).toString();
                                        QString DatNiv = Acceso.value(2).toString();
                                        QString DatAct = Acceso.value(3).toString();
                                        QString DatPre = Acceso.value(4).toString();
                                        QString DatRes = Acceso.value(5).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT Usuario,Clave,Nivel,Activo,Pregunta,Respuesta FROM Acceso WHERE Usuario='"+DatUsu+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QString ValIp = RecDat.value(0).toString();
                                            if (DatUsu != ValIp)
                                            {
                                                QSqlQuery Wwhite(DB);
                                                Wwhite.prepare("INSERT INTO Acceso (Usuario,Clave,Nivel,Activo,Pregunta,Respuesta)"
                                                              "VALUES (:Usuario,:Clave,:Nivel,:Activo,:Pregunta,:Respuesta)");
                                                Wwhite.bindValue(":Usuario", DatUsu);
                                                Wwhite.bindValue(":Clave", DatClv);
                                                Wwhite.bindValue(":Nivel", DatNiv);
                                                Wwhite.bindValue(":Activo", DatAct);
                                                Wwhite.bindValue(":Pregunta", DatPre);
                                                Wwhite.bindValue(":Respuesta", DatRes);
                                                Wwhite.exec();
                                            }
                                            else
                                            {
                                                QSqlQuery Wwhite(DB);
                                                Wwhite.exec("UPDATE Acceso SET Usuario='"+DatUsu+"',Clave='"+DatClv+"',Nivel='"+DatNiv+"',Activo='"+DatAct+"',Pregunta='"+DatPre+"',Respuesta='"+DatRes+"' WHERE Usuario='"+DatUsu+"'");
                                            }
                                        }
                                        cantidad++;
                                        if (cantidad == 50)
                                        {
                                            cantidad=1;
                                            DB.commit();
                                        }
                                   }
                                   progressMenu.setValue(cuenta);
                                   DB.commit();
                               }
                           }
                           if (i==19)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='consola'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString Cantidad;
                                   QSqlQuery query(db);
                                   query.exec("SELECT Fondo FROM consola WHERE id=2");
                                   query.first();
                                   if (query.isValid())
                                   {
                                       Cantidad=query.value(0).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE consola SET Fondo='"+Cantidad+"' WHERE id=2");
                                   }                                   
                               }
                           }
                           if (i==20)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Control'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery Acces(db);
                                   Acces.exec("SELECT COUNT(id) as Cantidad FROM Control");
                                   int cuenta, comienzo;
                                   Acces.first();
                                   cuenta = Acces.value(0).toInt();
                                   QSqlQuery Acceso(db);
                                   Acceso.exec("SELECT Nucleo,Version,Usuario,Fecha_ingreso FROM Control");
                                   QProgressDialog progressMenu("Actualizando Control de accesos... Espera por favor", "Cancelar", 0, cuenta);
                                   progressMenu.setWindowModality(Qt::WindowModal);
                                   progressMenu.show();
                                   comienzo=0;
                                   int cantidad=1;
                                   while(Acceso.next())
                                   {
                                        if (cantidad == 1)
                                        {
                                            DB.transaction();
                                        }
                                        progressMenu.setValue(comienzo++);
                                        if (progressMenu.wasCanceled())
                                           break;
                                        QString Datgru = Acceso.value(0).toString();
                                        QString Datiso = Acceso.value(1).toString();
                                        QString Datgr2 = Acceso.value(2).toString();
                                        QString DatNls = Acceso.value(3).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT Nucleo,Version,Usuario,Fecha_ingreso FROM Control WHERE Fecha_ingreso='"+DatNls+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QSqlQuery Wwhite(DB);
                                            Wwhite.prepare("INSERT INTO Control (Nucleo,Version,Usuario,Fecha_ingreso)"
                                                           "VALUES (:Nucleo,:Version,:Usuario,:Fecha_ingreso)");
                                            Wwhite.bindValue(":Nucleo", Datgru);
                                            Wwhite.bindValue(":Version", Datiso);
                                            Wwhite.bindValue(":Usuario", Datgr2);
                                            Wwhite.bindValue(":Fecha_ingreso", DatNls);
                                            Wwhite.exec();
                                        }
                                        cantidad++;
                                        if (cantidad == 50)
                                        {
                                            cantidad=1;
                                            DB.commit();
                                        }
                                   }
                                   progressMenu.setValue(cuenta);
                                   DB.commit();
                               }
                           }
                           if (i==21)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='opcion1'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43, cantidad44, cantidad45, cantidad46, cantidad47;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT tamano1,tamano2,tamano3,tamano4,tamano5 FROM opcion1 WHERE id=2");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        cantidad44=query41.value(1).toString();
                                        cantidad45=query41.value(2).toString();
                                        cantidad46=query41.value(3).toString();
                                        cantidad47=query41.value(4).toString();
                                        QSqlQuery Miscelanea(DB);
                                        Miscelanea.exec("UPDATE opcion1 SET tamano1='"+cantidad43+"',tamano2='"+cantidad44+"',tamano3='"+cantidad45+"',tamano4='"+cantidad46+"',tamano5='"+cantidad47+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==22)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='opcion3'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43, cantidad44, cantidad45;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT Numero1,Numero2,Numero3 FROM opcion3 WHERE id=2");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        cantidad44=query41.value(1).toString();
                                        cantidad45=query41.value(2).toString();
                                        QSqlQuery Miscelanea(DB);
                                        Miscelanea.exec("UPDATE opcion3 SET Numero1='"+cantidad43+"',Numero2='"+cantidad44+"',Numero3='"+cantidad45+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==23)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='opcion4'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43, cantidad44, cantidad45, cantidad46, cantidad47;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT Velocidad2x,Velocidad4x,Velocidad8x,Velocidad16x,Velocidad32x, FROM opcion4 WHERE id=2");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        cantidad44=query41.value(1).toString();
                                        cantidad45=query41.value(2).toString();
                                        cantidad46=query41.value(3).toString();
                                        cantidad47=query41.value(4).toString();
                                        QSqlQuery Miscelanea(DB);
                                        Miscelanea.exec("UPDATE opcion4 SET Velocidad2x='"+cantidad43+"',Velocidad4x='"+cantidad44+"',Velocidad8x='"+cantidad45+"',Velocidad16x='"+cantidad46+"',Velocidad32x='"+cantidad47+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==24)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='opcion5'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43, cantidad44, cantidad45, cantidad46, cantidad47, cantidad48;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT i480,i576.i2_576.p720,p1080,kapy FROM opcion5 WHERE id=2");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                        cantidad43=query41.value(0).toString();
                                        cantidad44=query41.value(1).toString();
                                        cantidad45=query41.value(2).toString();
                                        cantidad46=query41.value(3).toString();
                                        cantidad47=query41.value(4).toString();
                                        cantidad48=query41.value(5).toString();
                                        QSqlQuery Miscelanea(DB);
                                        Miscelanea.exec("UPDATE opcion5 SET i480='"+cantidad43+"',i576='"+cantidad44+"',i2_576='"+cantidad45+"',p720='"+cantidad46+"',p1080='"+cantidad47+"',kapy='"+cantidad48+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==25)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Menu'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery Acces(db);
                                   Acces.exec("SELECT COUNT(id) as Cantidad FROM Menu");
                                   int cuenta, comienzo;
                                   Acces.first();
                                   cuenta = Acces.value(0).toInt();
                                   QSqlQuery Acceso(db);
                                   Acceso.exec("SELECT Name,Name_es,Comment_es,Comment,Categories,Icon,Exec FROM Menu");
                                   QProgressDialog progressMenu("Actualizando Menu... Espera por favor", "Cancelar", 0, cuenta);
                                   progressMenu.setWindowModality(Qt::WindowModal);
                                   progressMenu.show();
                                   comienzo=0;
                                   int cantidad=1;
                                   while(Acceso.next())
                                   {
                                        if (cantidad == 1)
                                        {
                                            DB.transaction();
                                        }
                                        progressMenu.setValue(comienzo++);
                                        if (progressMenu.wasCanceled())
                                           break;
                                        QString Datgru = Acceso.value(0).toString();
                                        QString Datiso = Acceso.value(1).toString();
                                        QString Datgr2 = Acceso.value(2).toString();
                                        QString DatNom = Acceso.value(3).toString();
                                        QString DatVer = Acceso.value(4).toString();
                                        QString DatArq = Acceso.value(5).toString();
                                        QString DatDir = Acceso.value(6).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT Name,Name_es,Comment_es,Comment,Categories,Icon,Exec FROM Menu WHERE Name='"+Datgru+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QSqlQuery Wwhite(DB);
                                            Wwhite.prepare("INSERT INTO Menu (Name,Name_es,Comment_es,Comment,Categories,Icon,Exec)"
                                                           "VALUES (:Name,:Name_es,:Comment_es,:Comment,:Categories,:Icon,:Exec)");
                                            Wwhite.bindValue(":Name", Datgru);
                                            Wwhite.bindValue(":Name_es", Datiso);
                                            Wwhite.bindValue(":Comment_es", Datgr2);
                                            Wwhite.bindValue(":Comment", DatNom);
                                            Wwhite.bindValue(":Categories", DatVer);
                                            Wwhite.bindValue(":Icon", DatArq);
                                            Wwhite.bindValue(":Exec", DatDir);
                                            Wwhite.exec();
                                        }
                                        cantidad++;
                                        if (cantidad == 50)
                                        {
                                            cantidad=1;
                                            DB.commit();
                                        }
                                   }
                                   progressMenu.setValue(cuenta);
                                   DB.commit();
                               }
                           }
                           if (i==26)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Parental'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43, cantidad44, cantidad45, cantidad46;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT tiempo120,tiempo90,tiempo60,tiempo30 FROM Parental WHERE id=2");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                       cantidad43=query41.value(0).toString();
                                       cantidad44=query41.value(1).toString();
                                       cantidad45=query41.value(2).toString();
                                       cantidad46=query41.value(4).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE Parental SET tiempo120='"+cantidad43+"',tiempo90='"+cantidad44+"',tiempo60='"+cantidad45+"',tiempo30='"+cantidad46+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==27)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Wifi'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString cantidad43, cantidad44;
                                   QSqlQuery query41(db);
                                   query41.exec("SELECT conexion,essid FROM Wifi WHERE id=2");
                                   query41.first();
                                   if (query41.isValid())
                                   {
                                       cantidad43=query41.value(0).toString();
                                       cantidad44=query41.value(1).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE Wifi SET conexion='"+cantidad43+"',essid='"+cantidad44+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==28)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='pelis'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery Acces(db);
                                   Acces.exec("SELECT COUNT(id) as Cantidad FROM pelis");
                                   int cuenta, comienzo;
                                   Acces.first();
                                   cuenta = Acces.value(0).toInt();
                                   QSqlQuery Acceso(db);
                                   Acceso.exec("SELECT titulo,titulo_original,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico,policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis,soporte,posicion,visionada,duracion,color,vose,formato,fecha FROM pelis");
                                   QProgressDialog progressPelis("Actualizando Catalogo de Peliculas... Espera por favor", "Cancelar", 0, cuenta);
                                   progressPelis.setWindowModality(Qt::WindowModal);
                                   progressPelis.show();
                                   comienzo=0;
                                   DB.transaction();
                                   while(Acceso.next())
                                   {
                                        progressPelis.setValue(comienzo++);
                                        if (progressPelis.wasCanceled())
                                            break;
                                        QString titulo = Acceso.value(0).toString();
                                        titulo = titulo.replace("'", " ");
                                        QString titulo1 = Acceso.value(1).toString();
                                        titulo1 = titulo.replace("'", " ");
                                        QString edad = Acceso.value(2).toString();
                                        QString drama = Acceso.value(3).toString();
                                        QString comedia = Acceso.value(4).toString();
                                        QString accion = Acceso.value(5).toString();
                                        QString aventura = Acceso.value(6).toString();
                                        QString scifi = Acceso.value(7).toString();
                                        QString romantica = Acceso.value(8).toString();
                                        QString musical = Acceso.value(9).toString();
                                        QString catastrofes = Acceso.value(10).toString();
                                        QString suspense = Acceso.value(11).toString();
                                        QString fantasia = Acceso.value(12).toString();
                                        QString erotico = Acceso.value(13).toString();
                                        QString porno = Acceso.value(14).toString();
                                        QString historico = Acceso.value(15).toString();
                                        QString policiaco = Acceso.value(16).toString();
                                        QString terror = Acceso.value(17).toString();
                                        QString western = Acceso.value(18).toString();
                                        QString belico = Acceso.value(19).toString();
                                        QString deportes = Acceso.value(20).toString();
                                        QString animacion = Acceso.value(21).toString();
                                        QString documental = Acceso.value(22).toString();
                                        QString gore_zombies = Acceso.value(23).toString();
                                        QString caratula = Acceso.value(24).toString();
                                        QString actor = Acceso.value(25).toString();
                                        QString secundario = Acceso.value(26).toString();
                                        QString calificacion = Acceso.value(27).toString();
                                        QString sinopsis = Acceso.value(28).toString();
                                        QString soporte = Acceso.value(29).toString();
                                        QString posicion = Acceso.value(30).toString();
                                        QString visionada = Acceso.value(31).toString();
                                        QString duracion = Acceso.value(32).toString();
                                        QString color = Acceso.value(33).toString();
                                        QString vose = Acceso.value(34).toString();
                                        QString formato = Acceso.value(35).toString();
                                        QString director = Acceso.value(36).toString();
                                        QString fecha = Acceso.value(37).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT titulo,titulo_original,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico,policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis,soporte,posicion,visionada,duracion,color,vose,formato,fecha FROM pelis WHERE titulo='"+titulo+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QSqlQuery query(DB);
                                            query.prepare("INSERT INTO pelis (titulo,titulo_original,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico,policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis,soporte,posicion,visionada,duracion,color,vose,formato,director,fecha)"
                                                          "VALUES (:titulo,:titulo1,:edad,:drama,:comedia,:accion,:aventura,:scifi,:romantica,:musical,:catastrofes,:suspense,:fantasia,:erotico,:porno,:historico,:policiaco,:terror,:western,:belico,:deportes,:animacion,:documental,:gore_zombies,:caratula,:actor,:secundario,:calificacion,:sinopsis,:soporte,:posicion,:visionada,:duracion,:color,:vose,:formato,:director,:fecha)");
                                            query.bindValue(":titulo", titulo);
                                            query.bindValue(":titulo1", titulo1);
                                            query.bindValue(":edad", edad);
                                            query.bindValue(":drama", drama);
                                            query.bindValue(":comedia", comedia);
                                            query.bindValue(":accion", accion);
                                            query.bindValue(":aventura", aventura);
                                            query.bindValue(":scifi", scifi);
                                            query.bindValue(":romantica", romantica);
                                            query.bindValue(":musical", musical);
                                            query.bindValue(":catastrofes", catastrofes);
                                            query.bindValue(":suspense", suspense);
                                            query.bindValue(":fantasia", fantasia);
                                            query.bindValue(":erotico", erotico);
                                            query.bindValue(":porno", porno);
                                            query.bindValue(":historico", historico);
                                            query.bindValue(":policiaco", policiaco);
                                            query.bindValue(":terror", terror);
                                            query.bindValue(":western", western);
                                            query.bindValue(":belico", belico);
                                            query.bindValue(":deportes", deportes);
                                            query.bindValue(":animacion", animacion);
                                            query.bindValue(":documental", documental);
                                            query.bindValue(":gore_zombies", gore_zombies);
                                            query.bindValue(":caratula", caratula);
                                            query.bindValue(":actor", actor);
                                            query.bindValue(":secundario", secundario);
                                            query.bindValue(":calificacion", calificacion);
                                            query.bindValue(":sinopsis", sinopsis);
                                            query.bindValue(":soporte", soporte);
                                            query.bindValue(":posicion", posicion);
                                            query.bindValue(":visionada", visionada);
                                            query.bindValue(":duracion", duracion);
                                            query.bindValue(":color", color);
                                            query.bindValue(":vose", vose);
                                            query.bindValue(":formato", formato);
                                            query.bindValue(":director", director);
                                            query.bindValue(":fecha", fecha);
                                            query.exec();
                                        }
                                   }
                                   DB.commit();
                                   progressPelis.setValue(cuenta);
                                   DB.commit();
                               }
                           }
                           if (i==29)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Registro'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString dat, clv, seri;
                                   QSqlQuery dato(db);
                                   dato.exec("SELECT dato,clave,serie FROM Registro WHERE id=1");
                                   dato.first();
                                   if (dato.isValid())
                                   {
                                       dat=dato.value(0).toString();
                                       clv=dato.value(1).toString();
                                       seri=dato.value(2).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE Registro SET dato='"+dat+"',clave='"+clv+"',serie='"+seri+"' WHERE id=1");
                                   }
                               }
                           }
                           if (i==30)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='ipvnc'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery wlistanegr(db);
                                   wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM ipvnc");
                                   int cuenta, comienzo;
                                   wlistanegr.first();
                                   cuenta = wlistanegr.value(0).toInt();
                                   QSqlQuery wlistanegra(db);
                                   wlistanegra.exec("SELECT ip FROM ipvnc");
                                   QProgressDialog progressMenu("Actualizando ip's permitidas para vnc... Espera por favor", "Cancelar", 0, cuenta);
                                   progressMenu.setWindowModality(Qt::WindowModal);
                                   progressMenu.show();
                                   comienzo=0;
                                   int cantidad=1;
                                   while(wlistanegra.next())
                                   {
                                        if (cantidad == 1)
                                        {
                                            DB.transaction();
                                        }
                                        progressMenu.setValue(comienzo++);
                                        if (progressMenu.wasCanceled())
                                            break;
                                        QString DatIp = wlistanegra.value(0).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT ip FROM ipvnc WHERE ip='"+DatIp+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QSqlQuery Wdark(DB);
                                            Wdark.prepare("INSERT INTO ipvnc (ip)"
                                                          "VALUES (:ip)");
                                            Wdark.bindValue(":ip", DatIp);
                                            Wdark.exec();
                                        }
                                        cantidad++;
                                        if (cantidad == 50)
                                        {
                                            cantidad=1;
                                            DB.commit();
                                        }
                                        progressMenu.setValue(cuenta);
                                        DB.commit();
                                   }
                               }
                           }
                           if (i==31)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='DatosVnc'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString Cantidad,Cantidad1,Cantidad2,Cantidad3,Cantidad4,Cantidad5,Cantidad6,Cantidad7;
                                   QSqlQuery query(db);
                                   query.exec("SELECT tipoIp,clave,contraclave,segundoplano,menuGrafico,escuchar,soloVisual,LimitarIp FROM DatosVnc WHERE id=2");
                                   query.first();
                                   if (query.isValid())
                                   {
                                       Cantidad=query.value(0).toString();
                                       Cantidad1=query.value(1).toString();
                                       Cantidad2=query.value(2).toString();
                                       Cantidad3=query.value(3).toString();
                                       Cantidad4=query.value(4).toString();
                                       Cantidad5=query.value(5).toString();
                                       Cantidad6=query.value(6).toString();
                                       Cantidad7=query.value(7).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE DatosVnc SET tipoIp='"+Cantidad+"',clave='"+Cantidad1+"',contraclave='"+Cantidad2+"',segundoplano='"+Cantidad3+"',menuGrafico='"+Cantidad4+"',escuchar='"+Cantidad5+"',soloVisual='"+Cantidad6+"',LimitarIp='"+Cantidad7+"' WHERE id=2");
                                   }                                   
                               }
                           }
                           if (i==32)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Correo'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString Cantidad,Cantidad1,Cantidad2,Cantidad3;
                                   QSqlQuery query(db);
                                   query.exec("SELECT Correo,smtp,pass,destino FROM Correo WHERE id=1");
                                   query.first();
                                   if (query.isValid())
                                   {
                                       Cantidad=query.value(0).toString();
                                       Cantidad1=query.value(1).toString();
                                       Cantidad2=query.value(2).toString();
                                       Cantidad3=query.value(3).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE Correo SET Correo='"+Cantidad+"',smtp='"+Cantidad1+"',pass='"+Cantidad2+"',destino='"+Cantidad3+"' WHERE id=1");
                                   }                                   
                               }
                           }
                           if (i==33)
                           {
                               QString Cantidad;
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Menus'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery query(db);
                                   query.exec("SELECT Tipo_Menu FROM Menus WHERE id=2");
                                   query.first();
                                   if (query.isValid())
                                   {
                                       Cantidad=query.value(0).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE Menus SET Tipo_Menu='"+Cantidad+"' WHERE id=2");
                                   }                                   
                               }
                           }
                           if (i==34)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Aplicacion'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString Cantidad;
                                   QSqlQuery query(db);
                                   query.exec("SELECT Aplicacion FROM Aplicacion WHERE id=2");
                                   query.first();
                                   if (query.isValid())
                                   {
                                       Cantidad=query.value(0).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE Aplicacion SET Aplicacion='"+Cantidad+"' WHERE id=2");
                                   }                                   
                               }
                           }
                           if (i==35)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='chat'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString Cantidad;
                                   QSqlQuery query(db);
                                   query.exec("SELECT visionado FROM chat WHERE id=2");
                                   query.first();
                                   if (query.isValid())
                                   {
                                       Cantidad=query.value(0).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE chat SET visionado='"+Cantidad+"' WHERE id=2");
                                   }                                  
                               }
                           }
                           if (i==36)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Formato'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString Cantidad;
                                   QSqlQuery query(db);
                                   query.exec("SELECT Aspecto FROM Formato WHERE id=2");
                                   query.first();
                                   if (query.isValid())
                                   {
                                       Cantidad=query.value(0).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE Formato SET Aspecto='"+Cantidad+"' WHERE id=2");
                                   }
                               }
                           }
                           if (i==37)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Estilo'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString Cantidad;
                                   QSqlQuery query(db);
                                   query.exec("SELECT Style FROM Estilo WHERE id=2");
                                   query.first();
                                   if (query.isValid())
                                   {
                                       Cantidad=query.value(0).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE Estilo SET Style='"+Cantidad+"' WHERE id=2");
                                   }                                   
                               }
                           }
                           if (i==38)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Sincrono'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery wlistanegr(db);
                                   wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM Sincrono");
                                   int cuenta, comienzo;
                                   wlistanegr.first();
                                   cuenta = wlistanegr.value(0).toInt();
                                   QSqlQuery wlistanegra(db);
                                   wlistanegra.exec("SELECT Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo FROM Sincrono");
                                   QProgressDialog progressMenu("Actualizando Control de sincronizaciones... Espera por favor", "Cancelar", 0, cuenta);
                                   progressMenu.setWindowModality(Qt::WindowModal);
                                   progressMenu.show();
                                   comienzo=0;
                                   int cantidad=1;
                                   while(wlistanegra.next())
                                   {
                                        if (cantidad == 1)
                                        {
                                            DB.transaction();
                                        }
                                        progressMenu.setValue(comienzo++);
                                        if (progressMenu.wasCanceled())
                                            break;
                                        QString DatReferencia = wlistanegra.value(0).toString();
                                        QString DatObjetivo = wlistanegra.value(1).toString();
                                        QString DatDestino = wlistanegra.value(2).toString();
                                        QString DatEliminar = wlistanegra.value(3).toString();
                                        QString DatComprobar = wlistanegra.value(4).toString();
                                        QString DatOcultos = wlistanegra.value(5).toString();
                                        QString DatCodigo = wlistanegra.value(6).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo FROM Sincrono WHERE Referencia='"+DatReferencia+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QSqlQuery Wdark(DB);
                                            Wdark.prepare("INSERT INTO Sincrono (Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo)"
                                                          "VALUES (:Referencia,:Objetivo,:Destino,:Eliminar,:Comprobar,:Ocultos,:Codigo)");
                                            Wdark.bindValue(":Referencia", DatReferencia);
                                            Wdark.bindValue(":Objetivo", DatObjetivo);
                                            Wdark.bindValue(":Destino", DatDestino);
                                            Wdark.bindValue(":Eliminar", DatEliminar);
                                            Wdark.bindValue(":Comprobar", DatComprobar);
                                            Wdark.bindValue(":Ocultos", DatOcultos);
                                            Wdark.bindValue(":Codigo",DatCodigo);
                                            Wdark.exec();
                                        }
                                        cantidad++;
                                        if (cantidad == 50)
                                        {
                                            cantidad=1;
                                            DB.commit();
                                        }
                                   }
                                   progressMenu.setValue(cuenta);
                                   DB.commit();
                               }
                           }
                           if (i==39)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Ecualizador'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString Cantidad,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10,Volumen;
                                   QSqlQuery query(db);
                                   query.exec("SELECT activo,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10,Volume FROM Ecualizador WHERE id=2");
                                   query.first();
                                   if (query.isValid())
                                   {
                                       Cantidad=query.value(0).toString();
                                       banda1=query.value(1).toString();
                                       banda2=query.value(2).toString();
                                       banda3=query.value(3).toString();
                                       banda4=query.value(4).toString();
                                       banda5=query.value(5).toString();
                                       banda6=query.value(6).toString();
                                       banda7=query.value(7).toString();
                                       banda8=query.value(8).toString();
                                       banda9=query.value(9).toString();
                                       banda10=query.value(10).toString();
                                       Volumen=query.value(11).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE Ecualizador SET activo='"+Cantidad+"',banda1='"+banda1+"',banda2='"+banda2+"',banda3='"+banda3+"',banda4='"+banda4+"',banda5='"+banda5+"',banda6='"+banda6+"',banda7='"+banda7+"',banda8='"+banda8+"',banda9='"+banda9+"',banda10='"+banda10+"',Volume='"+Volumen+"' WHERE id=2");
                                   }                                   
                               }
                           }
                           if (i==40)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='id3Genre'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QSqlQuery wlistanegr(db);
                                   wlistanegr.exec("SELECT COUNT(id) as Cantidad FROM id3Genre");
                                   int cuenta, comienzo;
                                   wlistanegr.first();
                                   cuenta = wlistanegr.value(0).toInt();
                                   QSqlQuery wlistanegra(db);
                                   wlistanegra.exec("SELECT Genero FROM id3Genre");
                                   QProgressDialog progressMenu("Actualizando ID de generos de mp3... Espera por favor", "Cancelar", 0, cuenta);
                                   progressMenu.setWindowModality(Qt::WindowModal);
                                   progressMenu.show();
                                   comienzo=0;
                                   int cantidad=1;
                                   while(wlistanegra.next())
                                   {
                                        if (cantidad == 1)
                                        {
                                            DB.transaction();
                                        }
                                        progressMenu.setValue(comienzo++);
                                        if (progressMenu.wasCanceled())
                                            break;
                                        QString DatObjetivo = wlistanegra.value(0).toString();
                                        QSqlQuery RecDat(DB);
                                        RecDat.exec("SELECT Genero FROM id3Genre WHERE Genero='"+DatObjetivo+"'");
                                        RecDat.first();
                                        if (RecDat.isSelect())
                                        {
                                            QSqlQuery Wdark(DB);
                                            Wdark.prepare("INSERT INTO id3Genre (Genero)"
                                                          "VALUES (:Genero)");
                                            Wdark.bindValue(":Genero", DatObjetivo);
                                            Wdark.exec();
                                        }
                                        cantidad++;
                                        if (cantidad == 50)
                                        {
                                            cantidad=1;
                                            DB.commit();
                                        }
                                   }
                                   progressMenu.setValue(cuenta);
                                   DB.commit();
                               }
                           }
                           if (i==41)
                           {
                               QSqlQuery queryA(SM);
                               queryA.exec("SELECT count() FROM sqlite_master WHERE type='table' AND name='Calculadora'");
                               queryA.first();
                               if (queryA.isValid())
                               {
                                   QString Digitos,Decimales;
                                   QSqlQuery query(db);
                                   query.exec("SELECT Digitos,Decimales FROM Calculadora WHERE id=2");
                                   query.first();
                                   if (query.isValid())
                                   {
                                       Digitos=query.value(0).toString();
                                       Decimales=query.value(1).toString();
                                       QSqlQuery Miscelanea(DB);
                                       Miscelanea.exec("UPDATE Calculadora SET Digitos='"+Digitos+"',Decimales='"+Decimales+"' WHERE id=2");
                                   }                                   
                               }
                           }
                       }
                       progress.setValue(42);
                       DB.close();
                       db.close();
                       SM.close();
                       system("cp /root/Miscelanea.RecoverDrake.db.sqlite /usr/share/RecoverDrake/Miscelanea.RecoverDrake.db.sqlite");
                       system("mv /root/Miscelanea.RecoverDrake.db.sqlite.backup /root/Miscelanea.RecoverDrake.db.sqlite");
               }
               else if (respuesta == QMessageBox::No)
               {
                    DB.close();
                    db.close();
                    SM.close();
                    system("cp /root/Miscelanea.RecoverDrake.db.sqlite /usr/share/RecoverDrake/Miscelanea.RecoverDrake.db.sqlite");
               }
               QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","PRINCIPAL");
               db.setDatabaseName("/usr/share/RecoverDrake/Miscelanea.RecoverDrake.db.sqlite");
               if (!db.open())
               {
                   m.setText("<b>Error grave</b>:<p>No se ha podido abrir la base de datos necesaria de configuraciones.<p>Comprueba que existe Miscelanea.RecoverDrake.db.sqlite en la ruta /usr/share/RecoverDrake.");
                   m.exec();
                   return false;
               }
               QSqlQuery query52(db);
               query52.exec("SELECT Style FROM Estilo WHERE id=2");
               query52.first();
               if (query52.isValid())
                    Estilo=query52.value(0).toString();
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
                  QLocale::setDefault(QLocale(QLocale::Spanish, QLocale::Spain));
               }
               else if ( English == "2")
               {
                   idioma = "en";
                   QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
               }
               QString cantidad;
               QSqlQuery query(db);
               query.exec("SELECT inicio FROM Miscelanea WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               if ( cantidad == "0" )
               {
                   drakeSistema drake;
                   QString user;
                   QString Distro;
                   user = drake.getUser();
                   Distro = drake.getDistrop();
                   QString cantidad47;
                   QString cantidad48;
                   QString cantidad49;
                   QString cantidad50;
                   QString cantidad51;
                   QString DatoTalla;
                   QString DatoNegro;
                   QMessageBox m;
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
                       m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                       QApplication::setStyle(QStyleFactory::create(Estilo));
                       m.setStyle(Estilo);
                   }
                   if (Dato1 != 1280 || Dato2 != 1024)
                   {
                       if (Dato1 <= 1279 || Dato2 <= 1023)
                       {
                           if (idioma == "en")
                           {
                               m.setText("Welcome, <b>" + user + "</b>.<p>""<b>I hope that Linux <b> (" + Distro + ") as RecoverDrake ones you like. <p>" "The configuration database has been loaded successfully. <p> "" <B>NOTICE:</b> Access to the main program may take a few seconds while collecting all data necessary for its execution.<p>""Please be patient...<p>""<center><b>IMPORTANT NOTE</center>""<center><b>You have defined a resolution of "+X2+" pixels and we recommend a minimum resolution of 1280x1024 pixels (you can use up to a maximum resolution of "+Y2+"), although you can continue.</center><p>""Click <b> OK </b> to continue loading the program...");
                           }
                           else
                           {
                               m.setText("Bienvenido, <b>"+user+"</b>.<p>""<b>Espero que tanto Linux ("+Distro+") como RecoverDrake sean de tu agrado.<p>""La base de datos de configuraciones ha sido cargada con exito.<p>""<B>AVISO:</b> El acceso al programa principal puede demorarse unos segundos mientras se recopilan todos los datos necesarios para su ejecucion.<p>""Por favor se paciente...<p>""<center><b>NOTA IMPORTANTE</center>""<center><b>Tienes definida una resolucion de "+X2+" pixeles y se recomienda una resolucion minima de 1280x1024 pixeles (puedes utilizar hasta una resolucion maxima de "+Y2+"), aunque se puede continuar.</center><p>""Pulsa <b>OK</b> para seguir con la carga del programa...");
                           }
                       }
                   }
                   else
                   {
                       if (idioma == "en")
                       {
                           m.setText("Welcome, <b>" + user + "</b>.<p>""<b>I hope that Linux <b> (" + Distro + ") as RecoverDrake ones you like. <p>" "The configuration database has been loaded successfully. <p> "" <B>NOTICE:</b> Access to the main program may take a few seconds while collecting all data necessary for its execution.<p>""Please be patient...<p>""Click <b> OK </b> to continue loading the program...");
                       }
                       else
                       {
                           m.setText("Bienvenido, <b>"+user+"</b>.<p>""<b>Espero que tanto Linux ("+Distro+") como RecoverDrake sean de tu agrado.<p>""La base de datos de configuraciones ha sido cargada con exito.<p>""<B>AVISO:</b> El acceso al programa principal puede demorarse unos segundos mientras se recopilan todos los datos necesarios para su ejecucion.<p>""Por favor se paciente...<p>""Pulsa <b>OK</b> para seguir con la carga del programa...");
                       }
                   }
                   m.exec();
               }
               return true;
           }
        }
    }
    else
    {
        m.setText("No hay driver instalado. Comprueba la disponibilidad de la base de datos.");
        m.exec();
        return false;
    }
    return false;
}

#endif // BDCONECTTION_H
