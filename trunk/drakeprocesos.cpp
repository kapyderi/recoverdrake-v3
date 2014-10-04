#include "drakeprocesos.h"
#include <QStringList>
#include <QMessageBox>
#include <QDebug>
#include "drakesistema.h"
#include <QCoreApplication>
#include <QSqlQuery>

DrakeProcesos::DrakeProcesos(QStringList com, QObject *parent) : QObject(parent)
{
    this->comandos = com;
    proceso = 0;
    drakeSistema drake;
    user = drake.getUser();        
}

DrakeProcesos::~DrakeProcesos()
{
    this->destruirProceso();
}

void DrakeProcesos::Mascara(QString cantidad51, QString cantidad50, QString cantidad49, QString DatoTalla, QString cantidad47, QString DatoNegro)
{
    db=QSqlDatabase::database("PRINCIPAL");
    Stilo = "B";
    QString cantidadDefecto;
    QSqlQuery queryDefecto(db);
    queryDefecto.exec("SELECT Defecto FROM Miscelanea WHERE id=2");
    queryDefecto.first();
    if (queryDefecto.isSelect())
        cantidadDefecto=queryDefecto.value(0).toString();
    if (cantidadDefecto == "0")
    {
        Fcantidad47=cantidad47;
        Fcantidad49=cantidad49;
        FDatoTalla=DatoTalla;
        FDatoNegro=DatoNegro;
        Fcantidad50=cantidad50;
        Fcantidad51=cantidad51;
        Stilo = "A";
    }
}

void DrakeProcesos::Valor(int valor, int valor1)
{
    DatoTotal = valor;
    DatoRef = valor1;
}

void DrakeProcesos::iniciarProceso()
{
    if (comandos.count() == 0)
    {
        emit finProceso();
        return;
    }
    QString comando = this->comandos.at(0);
    emit DatoComand(comando);
    QString comand;
    if (DatoRef == 0)
    {
        comand = this->comandos.at(0);
        ValorComand = comand;
    }
    if (DatoRef == 1)
    {
        comand = this->comandos.at(0);
        ValorComand = comand.remove("urpmi").remove("--auto").remove("--a").remove("--force").remove("--fuzzy").remove(" ");
    }
    if (DatoRef == 2)
    {
        comand = this->comandos.at(0);
        ValorComand = QString::number(DatoTotal-comandos.count());
    }
    if (DatoRef == 3)
    {
        comand = this->comandos.at(0);
        ValorComand = comand;
    }
    this->crearConectarProceso();
    proceso->start(comando);
    comandos.removeAt(0);
}

void DrakeProcesos::crearConectarProceso()
{
    this->destruirProceso();
    proceso = new QProcess(this);
    connect(proceso, SIGNAL(error(QProcess::ProcessError)), this, SLOT(error(QProcess::ProcessError)));
    connect(proceso, SIGNAL(finished ( int, QProcess::ExitStatus)), this, SLOT(finalizado(int,QProcess::ExitStatus)));
    connect(proceso, SIGNAL(readyReadStandardError ()), this, SLOT(leerError()));
    connect(proceso, SIGNAL(readyReadStandardOutput ()), this, SLOT(leerOutput()));
}

void DrakeProcesos::destruirProceso()
{
    if (proceso != 0)
    {
        disconnect(proceso, SIGNAL(error(QProcess::ProcessError)), this, SLOT(error(QProcess::ProcessError)));
        disconnect(proceso, SIGNAL(finished ( int, QProcess::ExitStatus)), this, SLOT(finalizado(int,QProcess::ExitStatus)));
        disconnect(proceso, SIGNAL(readyReadStandardError ()), this, SLOT(leerError()));
        disconnect(proceso, SIGNAL(readyReadStandardOutput ()), this, SLOT(leerOutput()));
        delete proceso;
        proceso = 0;
    }
}

void DrakeProcesos::killProceso()
{
    disconnect(proceso, SIGNAL(error(QProcess::ProcessError)), this, SLOT(error(QProcess::ProcessError)));
    disconnect(proceso, SIGNAL(finished ( int, QProcess::ExitStatus)), this, SLOT(finalizado(int,QProcess::ExitStatus)));
    disconnect(proceso, SIGNAL(readyReadStandardError ()), this, SLOT(leerError()));
    disconnect(proceso, SIGNAL(readyReadStandardOutput ()), this, SLOT(leerOutput()));
    proceso->kill();
    delete proceso;
    proceso = 0;
}

void DrakeProcesos::finalizado (int exitCode, QProcess::ExitStatus exitStatus )
{   
    int Ultimo = comandos.size();
    Dato = 100-(100*(Ultimo)/(DatoTotal));
    emit progreso(QString::number(Dato));
    emit ValorDato(ValorComand);
    if (Ultimo == 0)
    {
        if (DatoRef != 3)
        {
            if (DatoRef == 5)
            {}
            else
            {
                if (DatoRef == 4)
                {
                    if (exitStatus == QProcess::CrashExit)
                    {
                        system("su - "+user+" -c \"/usr/bin/notify-send -i /usr/share/icons/gnome/32x32/status/important.png \'(RecoverDrake)...\' \'ERROR: El proceso termino inesperadamente.\'\"");
                        emit publicarDatos(tr("El proceso termino inesperadamente."));
                    }
                    else if (exitCode != 0)
                    {
                        system("su - "+user+" -c \"/usr/bin/notify-send -i /usr/share/icons/gnome/32x32/status/important.png \'(RecoverDrake)...\' \'PROBLEMA: El proceso no se ha realizado satisfactoriamente.\'\"");
                        emit publicarDatos(tr("El proceso no se ha realizado satisfactoriamente."));
                    }
                    else
                    {
                        system("su - "+user+" -c \"/usr/bin/notify-send -i /usr/share/icons/gnome/32x32/status/important.png \'(RecoverDrake)...\' \'OK: Proceso realizado correctamente.\'\"");
                        emit publicarDatos(tr("Proceso realizado correctamente."));
                    }
                }
                else
                {
                    if (exitStatus == QProcess::CrashExit)
                    {
                        system("su - "+user+" -c \"/usr/bin/notify-send -i /usr/share/icons/gnome/32x32/status/important.png \'(RecoverDrake)...\' \'ERROR: El proceso termino inesperadamente.\'\"");
                        if (DatoTotal == 999)
                            emit publicarDatos(tr("El proceso termino inesperadamente."));
                        else
                        {
                            QMessageBox m;
                            if (Stilo == "A")
                                m.setStyleSheet("background-color: "+Fcantidad51+"; color: "+Fcantidad50+"; font-size: "+Fcantidad49+"pt; font-style: "+FDatoTalla+"; font-family: "+Fcantidad47+"; font-weight: "+FDatoNegro+"");
                            m.setText(tr(QString::fromUtf8("<b>El proceso termino inesperadamente.<p>Se actualizaran procesos internos.<p>Se paciente...")));
                            m.exec();
                        }
                    }
                    else if (exitCode != 0)
                    {
                        system("su - "+user+" -c \"/usr/bin/notify-send -i /usr/share/icons/gnome/32x32/status/important.png \'(RecoverDrake)...\' \'PROBLEMA: El proceso no se ha realizado satisfactoriamente.\'\"");
                        if (DatoTotal == 999)
                            emit publicarDatos(tr("El proceso no se ha realizado satisfactoriamente."));
                        else
                        {
                            QMessageBox m;
                            if (Stilo == "A")
                                m.setStyleSheet("background-color: "+Fcantidad51+"; color: "+Fcantidad50+"; font-size: "+Fcantidad49+"pt; font-style: "+FDatoTalla+"; font-family: "+Fcantidad47+"; font-weight: "+FDatoNegro+"");
                            m.setText(tr(QString::fromUtf8("<b>El proceso no se ha realizado satisfactoriamente.<p>Se actualizaran procesos internos.<p>Se paciente...")));
                            m.exec();
                        }
                    }
                    else
                    {
                        system("su - "+user+" -c \"/usr/bin/notify-send -i /usr/share/icons/gnome/32x32/status/important.png \'(RecoverDrake)...\' \'OK: Proceso realizado correctamente.\'\"");
                        if (DatoTotal == 999)
                            emit publicarDatos(tr("Proceso realizado correctamente."));
                        else
                        {
                            QMessageBox m;
                            if (Stilo == "A")
                                m.setStyleSheet("background-color: "+Fcantidad51+"; color: "+Fcantidad50+"; font-size: "+Fcantidad49+"pt; font-style: "+FDatoTalla+"; font-family: "+Fcantidad47+"; font-weight: "+FDatoNegro+"");
                            m.setText(tr(QString::fromUtf8("<b>Proceso realizado correctamente.<p>Se actualizarán procesos internos.<p>Se paciente...")));
                            m.exec();
                        }
                    }
                }
            }
        }
        else
        {
            if (exitStatus == QProcess::CrashExit)
                system("su - "+user+" -c \"/usr/bin/notify-send -i /usr/share/icons/gnome/32x32/status/important.png \'(RecoverDrake)...\' \'ERROR: El proceso termino inesperadamente.\'\"");
            else if (exitCode != 0)
                system("su - "+user+" -c \"/usr/bin/notify-send -i /usr/share/icons/gnome/32x32/status/important.png \'(RecoverDrake)...\' \'PROBLEMA: El proceso no se ha realizado satisfactoriamente.\'\"");
            else
                system("su - "+user+" -c \"/usr/bin/notify-send -i /usr/share/icons/gnome/32x32/status/important.png \'(RecoverDrake)...\' \'OK: Proceso realizado correctamente.\'\"");
        }
    }
    this->iniciarProceso();
}

void DrakeProcesos::error(QProcess::ProcessError errores)
{
    Q_UNUSED(errores);
    system("su - "+user+" -c \"/usr/bin/notify-send -i /usr/share/icons/gnome/32x32/status/important.png \'(RecoverDrake)...\' \'ERROR: El proceso ha generado un error.\'\"");
    if (DatoRef != 3)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+Fcantidad51+"; color: "+Fcantidad50+"; font-size: "+Fcantidad49+"pt; font-style: "+FDatoTalla+"; font-family: "+Fcantidad47+"; font-weight: "+FDatoNegro+"");
        m.setText(tr(QString::fromUtf8("<b>El proceso ha generado un error.<p>Se actualizarán procesos internos.<p>Se paciente...")));
        m.exec();
    }
    emit finProceso();
    return;
}

void DrakeProcesos::leerError()
{
    QByteArray datos = proceso->readAllStandardError();
    emit publicarDatos(QString::fromLocal8Bit(datos));
}

void DrakeProcesos::leerOutput()
{    
    QByteArray datos = proceso->readAllStandardOutput();
    emit publicarDatos(QString::fromLocal8Bit(datos));
}
