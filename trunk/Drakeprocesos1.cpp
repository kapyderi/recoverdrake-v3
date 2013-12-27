#include "drakeprocesos1.h"
#include <QStringList>
#include <QMessageBox>
#include "drakesistema.h"
#include <QCoreApplication>
#include <QDebug>

DrakeProcesos1::DrakeProcesos1(QStringList com, QObject *parent) : QObject(parent)
{
    this->comandos = com;
    proceso = 0;
    drakeSistema drake;
    user = drake.getUser();
}

DrakeProcesos1::~DrakeProcesos1()
{
    this->destruirProceso();
}

void DrakeProcesos1::Valor(int valor, int Control)
{
    DatoTotal = valor;
    SinMensaje = Control;
}

void DrakeProcesos1::iniciarProceso()
{   
    if (comandos.count() == 0)
    {
        emit finProceso();
        return;
    }
    QString comando = this->comandos.at(0);
    Value = comando;
    this->crearConectarProceso();
    proceso->start(comando);    
    comandos.removeAt(0);
}

void DrakeProcesos1::crearConectarProceso()
{
    this->destruirProceso();
    proceso = new QProcess(this);
    connect(proceso, SIGNAL(error(QProcess::ProcessError)), this, SLOT(error(QProcess::ProcessError)));
    connect(proceso, SIGNAL(finished ( int, QProcess::ExitStatus)), this, SLOT(finalizado(int,QProcess::ExitStatus)));
    connect(proceso, SIGNAL(readyReadStandardError ()), this, SLOT(leerError()));
    connect(proceso, SIGNAL(readyReadStandardOutput ()), this, SLOT(leerOutput()));
}

void DrakeProcesos1::destruirProceso()
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

void DrakeProcesos1::killProceso()
{
    disconnect(proceso, SIGNAL(error(QProcess::ProcessError)), this, SLOT(error(QProcess::ProcessError)));
    disconnect(proceso, SIGNAL(finished ( int, QProcess::ExitStatus)), this, SLOT(finalizado(int,QProcess::ExitStatus)));
    disconnect(proceso, SIGNAL(readyReadStandardError ()), this, SLOT(leerError()));
    disconnect(proceso, SIGNAL(readyReadStandardOutput ()), this, SLOT(leerOutput()));
    proceso->kill();
    delete proceso;
    proceso = 0;
}

void DrakeProcesos1::finalizado (int exitCode, QProcess::ExitStatus exitStatus )
{
    Ultimo = comandos.size();
    Dato = 100-(100*(Ultimo)/(DatoTotal));
    emit progreso(QString::number(Dato));
    emit ValorDato(Value);
    if (Ultimo == 0)
    {
        if (SinMensaje == 0)
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
    }
    this->iniciarProceso();
}

void DrakeProcesos1::error(QProcess::ProcessError errores)
{
    system("su - "+user+" -c \"/usr/bin/notify-send -i /usr/share/icons/gnome/32x32/status/important.png \'(RecoverDrake)...\' \'ERROR: El proceso ha generado un error.\'\"");
    emit publicarDatos(tr("El proceso ha generado un error."));
    this->iniciarProceso();
}

void DrakeProcesos1::leerError()
{
    QByteArray datos = proceso->readAllStandardError();
    emit publicarDatos(QString::fromLocal8Bit(datos));

}

void DrakeProcesos1::leerOutput()
{
    QByteArray datos = proceso->readAllStandardOutput();
    emit publicarDatos(QString::fromLocal8Bit(datos));
}
