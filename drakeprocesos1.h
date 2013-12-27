#ifndef DrakeProcesos11_H
#define DrakeProcesos11_H

#include <QObject>
#include <QProcess>
#include <QStringList>

class DrakeProcesos1 : public QObject
{
    Q_OBJECT
public:
    DrakeProcesos1(QStringList com, QObject *parent = 0);
    ~DrakeProcesos1();
    void iniciarProceso();
    void killProceso();
    void Valor(int valor, int Control);
    int DatoTotal;
    int Dato;
    int Ultimo;
    int Ultima;
    int Reset;
    QString user;
    int SinMensaje;
    QString Value;

signals:
    void publicarDatos(QString valor);
    void finProceso();
    void progreso(QString Dato);
    void ValorDato(QString ValorComand);

private slots:
    void error (QProcess::ProcessError errores );
    void finalizado (int exitCode, QProcess::ExitStatus exitStatus );
    void leerError();
    void leerOutput();

private:
    void crearConectarProceso();
    void destruirProceso();
    QStringList comandos;
    QProcess *proceso;

};

#endif // DrakeProcesos11_H
