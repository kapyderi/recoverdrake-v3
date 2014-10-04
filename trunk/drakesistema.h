#ifndef DRAKESISTEMA_H
#define DRAKESISTEMA_H

#include <QObject>
#include <QString>

class drakeSistema : public QObject
{
Q_OBJECT
public:
    explicit drakeSistema(QObject *parent = 0);
    QString getArquitectura();
    QString getDistribucion();
    QString getUser();
    QString getTipKernel();
    QString getVerKernel();
    QString getRevKernel();
    QString getDirActual();
    QString getVirtual();
    QString getLinux();
    QString getPci();
    QString getModulo();
    QString getEspacio();
    QString getRepositorio();
    QString getRedes();
    QString getRpms();
    QString getRpmsN(QString Nombre);
    QString getDistrop();
    QString Distro;
    QString getlsdvd();
    QString getCdrom();
    QString getFree();
    QString getDisco();
    QString getDiscR();
    QString getDiscH();
    QString getFreeTotal();
    QString getIP();
    QString getDB();
    QString getRelease();
    QString getIPRouter();
    QString getInternet();
    QString getInfoPro();
    QString getMedia();
    QString getCat(QString Valor);
    QString getMac(QString Valor);
    QString getLs();
    QString getMp3Title(QString filename);
    QString getMp3Artist(QString filename);
    QString getMp3Album(QString filename);
    QString getMp3Year(QString filename);
    QString getMp3Comment(QString filename);
    QString getMp3Track(QString filename);
    QString getMp3Genre(QString filename);
    QString getKill();
    QString getKillAll();
    QString getLabel();
    QString getLabelOld(QString Unidad);
    QString getNucleo();
    QString getResolution();
    QString getResolucion();
    QString getHostname();
    QString getBios();
    QString getEssid(QString ip);
    QString getStart(QString ruta);
    QString getEthernet();
    QString getTorrentP(QString Name);
    QString getTorrentN(QString Name);
    QString getFind(QString Valor);
    QString getBackup();
    QString getDu(QString Valor);
    QString getTipo(QString Valor);
    QString getLslh(QString Valor);
    QString getLslhd(QString Valor);
    QString getUsuarios();
    QString user;
    QString dist;
    QString getMAC(QString Tipo);
    QString getWhoami();

};

#endif // DRAKESISTEMA_H
