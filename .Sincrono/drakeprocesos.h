#ifndef DRAKEPROCESOS_H
#define DRAKEPROCESOS_H

#include <QObject>
#include <QProcess>
#include <QStringList>
#include <QSqlDatabase>

class DrakeProcesos : public QObject
{
    Q_OBJECT
public:
    DrakeProcesos(QStringList com, QObject *parent = 0);
    ~DrakeProcesos();
    void iniciarProceso();
    void killProceso();
    void Valor(int valor, int valor1);
    void Mascara(QString cantidad51, QString cantidad50, QString cantidad49, QString DatoTalla,QString cantidad47, QString DatoNegro);
    int Dato;
    int DatoTotal;
    int DatoRef;
    QString user;
    QString FcantidadDefecto;
    QString Fcantidad47;
    QString Fcantidad48;
    QString Fcantidad49;
    QString FDatoTalla;
    QString FDatoNegro;
    QString Fcantidad50;
    QString Fcantidad51;
    QString Stilo;
    QSqlDatabase db;

signals:
    void publicarDatos(QString valor);
    void finProceso();
    void DatoComand(QString comando);
    void progreso(QString Dato);
    void ValorDato(QString ValorComand);

private slots:
    void error (QProcess::ProcessError errores );
    void finalizado (int exitCode, QProcess::ExitStatus exitStatus );
    void leerError ();
    void leerOutput ();

private:
    void crearConectarProceso();
    void destruirProceso();
    QStringList comandos;
    QProcess *proceso;
    QString ValorComand;

};

#endif // DRAKEPROCESOS_H
