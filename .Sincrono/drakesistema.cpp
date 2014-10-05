#include "drakesistema.h"
#include <QObject>
#include <QString>
#include <QProcess>
#include <stdlib.h>
#include <QMessageBox>
#include <QDir>
#include <QDebug>

drakeSistema::drakeSistema(QObject *parent) : QObject(parent)
{
}

QString drakeSistema::getVirtual()
{    
    QProcess *procesoFind, *procesoCut;
    QStringList argumentosFind;
    QStringList argumentosCut;
    QByteArray TipVirtual;
    procesoFind=new QProcess(this);
    procesoCut=new QProcess(this);
    argumentosFind << "/etc/init.d/vboxdrv";
    argumentosCut << "-d" << "/" << "-f4";
    procesoFind->setStandardOutputProcess(procesoCut);
    procesoFind->start("find",argumentosFind);
    procesoCut->start("cut",argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoFind->waitForFinished();
    procesoCut->waitForFinished();
    TipVirtual = QString(procesoCut->readAllStandardOutput());
    delete procesoFind;
    delete procesoCut;
    QString res =  QString(TipVirtual);    
    res.chop(1);
    return res;
}

QString drakeSistema::getDirActual()
{
    QProcess *procesoDir;
    QByteArray DirActual;
    procesoDir=new QProcess(this);
    procesoDir->start("pwd");
    if (! procesoDir->waitForStarted())
        return QString("");
    procesoDir->waitForFinished();
    DirActual = QString(procesoDir->readAllStandardOutput());
    delete procesoDir;
    QString res =  QString(DirActual);
    res.chop(1);
    return res;
 }

QString drakeSistema::getRedes()
{
    QProcess *procesoDir;
    QByteArray red;
    procesoDir=new QProcess(this);
    procesoDir->start("ifconfig");
    if (! procesoDir->waitForStarted())
        return QString("");
    procesoDir->waitForFinished();
    red = QString(procesoDir->readAllStandardOutput());
    delete procesoDir;
    QString res =  QString(red);
    res.chop(1);
    return res;
}

QString drakeSistema::getRpms()
{
    QProcess *procesoDir;
    QStringList argumentosFind;
    QByteArray rpm;
    procesoDir=new QProcess(this);
    argumentosFind << "-qa" << "--last";
    procesoDir->start("rpm",argumentosFind);
    if (! procesoDir->waitForStarted())
        return QString("");
    procesoDir->waitForFinished();
    rpm = QString(procesoDir->readAllStandardOutput());
    delete procesoDir;
    QString res =  QString(rpm);
    res.chop(1);
    return res;
}

QString drakeSistema::getRpmsN(QString Nombre)
{
    QProcess *procesoDir, *procesoCut;
    QStringList argumentosFind, argumentosCut;
    QByteArray rpm;

    procesoDir=new QProcess(this);
    procesoCut=new QProcess(this);

    argumentosFind << "-qa" << "--last";
    argumentosCut << ""+Nombre+"";

    procesoDir->setStandardOutputProcess(procesoCut);

    procesoDir->start("rpm",argumentosFind);
    procesoCut->start("grep", argumentosCut);

    if (! procesoCut->waitForStarted())
    {
        return QString("");
    }

    procesoCut->waitForFinished();

    rpm = QString(procesoCut->readAllStandardOutput());

    delete procesoDir;
    delete procesoCut;
    QString res =  QString(rpm);
    res.chop(1);
    return res;
}

QString drakeSistema::getTipKernel()
{
    QProcess *procesoUname, *procesoCut;
    QStringList argumentosUname;
    QStringList argumentosCut;
    QByteArray TipKernel;
    procesoUname=new QProcess(this);
    procesoCut=new QProcess(this);
    argumentosUname << "-r";
    argumentosCut << "-d" << "-" << "-f2";
    procesoUname->setStandardOutputProcess(procesoCut);
    procesoUname->start("uname",argumentosUname);
    procesoCut->start("cut",argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoUname->waitForFinished();
    procesoCut->waitForFinished();
    TipKernel = QString(procesoCut->readAllStandardOutput());
    delete procesoUname;
    delete procesoCut;
    QString res =  QString(TipKernel);
    res.chop(1);
    return res;
}

QString drakeSistema::getVerKernel()
{
    QProcess *procesoUname, *procesoCut;
    QStringList argumentosUname;
    QStringList argumentosCut;
    QByteArray VerKernel;
    procesoUname=new QProcess(this);
    procesoCut=new QProcess(this);
    argumentosUname << "-r";
    argumentosCut << "-d" << "-" << "-f1";
    procesoUname->setStandardOutputProcess(procesoCut);
    procesoUname->start("uname",argumentosUname);
    procesoCut->start("cut",argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoUname->waitForFinished();
    procesoCut->waitForFinished();
    VerKernel = QString(procesoCut->readAllStandardOutput());
    delete procesoUname;
    delete procesoCut;
    QString res = QString(VerKernel);
    res.chop(1);
    return res;
}

QString drakeSistema::getNucleo()
{
    QProcess *procesoUname;
    QStringList argumentosUname;
    QByteArray VerNucleo;

    procesoUname=new QProcess(this);

    argumentosUname << "-r";

    procesoUname->start("uname",argumentosUname);

    if (! procesoUname->waitForStarted())
        return QString("");

    procesoUname->waitForFinished();

    VerNucleo = QString(procesoUname->readAllStandardOutput());

    delete procesoUname;
    QString res = QString(VerNucleo);
    res.chop(1);
    return res;
}

QString drakeSistema::getRevKernel()
{
    QProcess *procesoUname, *procesoCut;
    QStringList argumentosUname;
    QStringList argumentosCut;
    QByteArray RevKernel;
    procesoUname=new QProcess(this);
    procesoCut=new QProcess(this);
    argumentosUname << "-r";
    argumentosCut << "-d" << "-" << "-f3";
    procesoUname->setStandardOutputProcess(procesoCut);
    procesoUname->start("uname",argumentosUname);
    procesoCut->start("cut",argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoUname->waitForFinished();
    procesoCut->waitForFinished();
    RevKernel = QString(procesoCut->readAllStandardOutput());
    delete procesoUname;
    delete procesoCut;
    QString res =  QString(RevKernel);
    res.chop(1);
    return res;
}

QString drakeSistema::getUser()
{
    QProcess *procesowho, *procesoCut, *procesoawk;
    QStringList argumentosawk;
    QStringList argumentosCut;
    QByteArray usuario;
    procesoawk=new QProcess(this);
    procesowho=new QProcess(this);
    procesoCut=new QProcess(this);
    argumentosawk << "NR<(NF-NR) {print $1}";
    argumentosCut << "-d" << " " << "-f1";
    procesowho->setStandardOutputProcess(procesoawk);
    procesoawk->setStandardOutputProcess(procesoCut);
    procesowho->start("who");
    procesoawk->start("awk",argumentosawk);
    procesoCut->start("cut",argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesowho->waitForFinished();
    procesoawk->waitForFinished();
    procesoCut->waitForFinished();
    usuario = QString(procesoCut->readAllStandardOutput());
    delete procesowho;
    delete procesoawk;
    delete procesoCut;
    QString res =  QString(usuario);
    res.chop(1);
    if (res == "")
        res = getWhoami();
    return res;
}

QString drakeSistema::getWhoami()
{
    QProcess *procesowho, *procesoCut, *procesoawk;
    QStringList argumentoscat;
    QStringList argumentosawk;
    QByteArray usuario;
    procesoawk=new QProcess(this);
    procesowho=new QProcess(this);
    procesoCut=new QProcess(this);
    argumentoscat << "/etc/passwd";
    argumentosawk << "-F" << ":" << "$3 >= 500 && $3 < 1024 {printf $1}";
    procesowho->setStandardOutputProcess(procesoawk);
    procesoawk->setStandardOutputProcess(procesoCut);
    procesowho->start("cat",argumentoscat);
    procesoawk->start("sort");
    procesoCut->start("awk",argumentosawk);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesowho->waitForFinished();
    procesoawk->waitForFinished();
    procesoCut->waitForFinished();
    usuario = QString(procesoCut->readAllStandardOutput());
    delete procesowho;
    delete procesoawk;
    delete procesoCut;
    QString res =  QString(usuario);
    return res;
}

QString drakeSistema::getArquitectura()
{
    QProcess *procesoCut;
    QStringList argumentosCut;
    QByteArray arquitectura;
    procesoCut=new QProcess(this);
    drakeSistema drake;
    Distro = drake.getDistrop();
    if (Distro=="Mandriva" || Distro=="OpenMandriva")
        argumentosCut << "-c" << "cut -d ' ' -f7 /etc/release";
    else if (Distro=="Mageia")
        argumentosCut << "-c" << "cut -d ' ' -f6 /etc/release";
    procesoCut->start("/bin/sh", argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    arquitectura = procesoCut->readAllStandardOutput();
    delete procesoCut;
    QString res =  QString(arquitectura);
    res.chop(1);
    return res;
}

QString drakeSistema::getLinux()
{
    QProcess *procesoCut;
    QStringList argumentosCut;
    QByteArray Linux;
    procesoCut=new QProcess(this);
    argumentosCut << "/etc/issue";
    procesoCut->start("cat", argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    Linux = procesoCut->readAllStandardOutput();
    delete procesoCut;
    QString res =  QString(Linux);
    res.chop(5);
    return res;
}

QString drakeSistema::getDistrop()
{
    QProcess *procesoCut;
    QStringList argumentosCut;
    QByteArray Distros;
    QString Distro;
    procesoCut=new QProcess(this);
    argumentosCut << "/etc/issue";
    procesoCut->start("cat", argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    Distros = procesoCut->readAllStandardOutput();
    delete procesoCut;
    Distro = QString(Distros);
    Distro=Distro.split(" ").value(0);
    QString res = QString(Distro);
    res.chop(0);
    return res;
}

QString drakeSistema::getRepositorio()
{
    QProcess *procesoCut;
    QStringList argumentosCut;
    QByteArray repo;
    procesoCut=new QProcess(this);
    argumentosCut << "--list-media";
    procesoCut->start("urpmq", argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    repo = procesoCut->readAllStandardOutput();
    delete procesoCut;
    QString res =  QString(repo);
    res.chop(1);
    return res;
}

QString drakeSistema::getPci()
{
    QProcess *procesoCut;
    QByteArray Pci;
    procesoCut=new QProcess(this);
    procesoCut->start("lspci");
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    Pci = procesoCut->readAllStandardOutput();
    delete procesoCut;
    QString res =  QString(Pci);
    res.chop(1);
    return res;
}

QString drakeSistema::getEspacio()
{
    QProcess *procesoCut;
    QStringList argumentosCut;
    QByteArray du;
    procesoCut=new QProcess(this);
    argumentosCut << "/home";
    procesoCut->start("du", argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    du = procesoCut->readAllStandardOutput();
    delete procesoCut;
    QString res =  QString(du);
    res.chop(1);
    return res;
}

QString drakeSistema::getModulo()
{
    QProcess *procesoCut;
    QByteArray Mod;
    procesoCut=new QProcess(this);
    procesoCut->start("lsmod");
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    Mod = procesoCut->readAllStandardOutput();
    delete procesoCut;
    QString res =  QString(Mod);
    res.chop(1);
    return res;
}

QString drakeSistema::getDistribucion()
{
    QProcess *procesoCut;
    QStringList argumentosCut;
    QByteArray distribucion;
    procesoCut=new QProcess(this);
    drakeSistema drake;
    Distro = drake.getDistrop();
    if (Distro=="Mandriva" || Distro=="OpenMandriva")
        argumentosCut << "-c" << "cut -d ' ' -f4 /etc/release";
    else if (Distro=="Mageia")
        argumentosCut << "-c" << "cut -d ' ' -f3 /etc/release";
    procesoCut->start("/bin/sh", argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    distribucion = procesoCut->readAllStandardOutput();
    delete procesoCut;
    QString res =  QString(distribucion);
    res.chop(1);
    return res;
}

QString drakeSistema::getlsdvd()
{
    QProcess *procesoLs;
    QByteArray lsdvd;

    procesoLs=new QProcess(this);

    procesoLs->start("lsdvd");

    if (! procesoLs->waitForStarted())
        return QString("");

    procesoLs->waitForFinished();

    lsdvd = procesoLs->readAllStandardOutput();
    procesoLs->waitForFinished();

    delete procesoLs;
    QString res =  QString(lsdvd);
    res.chop(1);
    return res;
}

QString drakeSistema::getCdrom()
{
    QProcess *procesoCD;
    QByteArray Cdrom;
    procesoCD=new QProcess(this);
    procesoCD->start("wodim -scanbus dev=/dev/sr0 -checkdrive");
    if (! procesoCD->waitForStarted())
        return QString("");
    procesoCD->waitForFinished();
    Cdrom = QString(procesoCD->readAllStandardOutput());
    delete procesoCD;
    QString res =  QString(Cdrom);
    res.chop(1);
    return res;
 }

QString drakeSistema::getFree()
{
    QProcess *procesoFree;
    QStringList argumentosFree;
    QByteArray Frees;
    QString Free;
    procesoFree=new QProcess(this);
    argumentosFree << "-o";
    procesoFree->start("free", argumentosFree);
    if (! procesoFree->waitForStarted())
        return QString("");
    procesoFree->waitForFinished();
    Frees = procesoFree->readAllStandardOutput();
    delete procesoFree;
    Free = QString(Frees);
    QString res =  QString("        "+Free+"");
    res.chop(0);
    return res;
}

QString drakeSistema::getDisco()
{
    QProcess *procesoFree;
    QStringList argumentosFree;
    QByteArray Total;
    procesoFree=new QProcess(this);
    argumentosFree << "-h";
    procesoFree->start("df", argumentosFree);
    if (! procesoFree->waitForStarted())
        return QString("");
    procesoFree->waitForFinished();
    Total = procesoFree->readAllStandardOutput();
    delete procesoFree;
    QString res = QString(Total);
    res.chop(0);
    return res;
}

QString drakeSistema::getDiscR()
{
    QProcess *procesoFree;
    QStringList argumentosFree;
    QByteArray Raiz;
    procesoFree=new QProcess(this);
    argumentosFree << "-H" << "/";
    procesoFree->start("df", argumentosFree);
    if (! procesoFree->waitForStarted())
        return QString("");
    procesoFree->waitForFinished();
    Raiz = procesoFree->readAllStandardOutput();
    delete procesoFree;
    QString res = QString(Raiz);
    res.chop(0);
    return res;
}

QString drakeSistema::getDiscH()
{
    QProcess *procesoFree;
    QStringList argumentosFree;
    QByteArray Home;

    procesoFree=new QProcess(this);

    argumentosFree << "-H" << "/home";

    procesoFree->start("df", argumentosFree);

    if (! procesoFree->waitForStarted())
        return QString("");

    procesoFree->waitForFinished();

    Home = procesoFree->readAllStandardOutput();

    delete procesoFree;
    QString res = QString(Home);
    res.chop(0);
    return res;
}

QString drakeSistema::getFreeTotal()
{
    QProcess *procesoFree;
    QStringList argumentosFree;
    QByteArray FreeTotal;

    procesoFree=new QProcess(this);

    argumentosFree << "-to";

    procesoFree->start("free", argumentosFree);

    if (! procesoFree->waitForStarted())
        return QString("");

    procesoFree->waitForFinished();

    FreeTotal = procesoFree->readAllStandardOutput();

    delete procesoFree;
    QString res = QString(FreeTotal);
    res.chop(0);
    return res;
}

QString drakeSistema::getIP()
{
    QProcess *procesoFree;
    QStringList argumentosFree;
    QByteArray ip;
    procesoFree=new QProcess(this);
    argumentosFree << "http://cualesmiip.e-mision.net:999/";
    procesoFree->start("curl", argumentosFree);
    if (! procesoFree->waitForStarted())
        return QString("");
    procesoFree->waitForFinished();
    ip = procesoFree->readAllStandardOutput();
    delete procesoFree;
    QString res = QString(ip);
    res.chop(0);
    return res;
}

QString drakeSistema::getDB()
{
    QProcess *procesoFind, *procesoGrep;
    QStringList argumentosFind;
    QStringList argumentosGrep;
    QByteArray db;

    procesoFind=new QProcess(this);
    procesoGrep=new QProcess(this);

    argumentosFind << "/usr/share/applications/";
    argumentosGrep << ".desktop";

    procesoFind->setStandardOutputProcess(procesoGrep);

    procesoFind->start("find",argumentosFind);
    procesoGrep->start("grep",argumentosGrep);

    if (! procesoGrep->waitForStarted())
        return QString("");

    procesoFind->waitForFinished();
    procesoGrep->waitForFinished();

    db = QString(procesoGrep->readAllStandardOutput());

    delete procesoFind;
    delete procesoGrep;
    QString res =  QString(db);
    res.chop(1);
    return res;
}

QString drakeSistema::getCat(QString Valor)
{
    QProcess *procesoCat;
    QStringList argumentosCat;
    QByteArray Cat;

    procesoCat=new QProcess(this);

    argumentosCat << ""+Valor+"";

    procesoCat->start("cat", argumentosCat);

    if (! procesoCat->waitForStarted())
        return QString("");

    procesoCat->waitForFinished();

    Cat = procesoCat->readAllStandardOutput();

    delete procesoCat;
    QString res = QString(Cat);
    res.chop(1);
    return res;
}

QString drakeSistema::getMp3Title(QString filename)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosCat;
    QStringList argumentosGrep;
    QByteArray Cat;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosCat << ""+filename+"";
    argumentosGrep << "TIT2";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("id3info", argumentosCat);
    procesoGrep->start("grep", argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    procesoGrep->waitForFinished();
    Cat = procesoGrep->readAllStandardOutput();
    delete procesoCat;
    delete procesoGrep;
    QString res = QString(Cat);
    res.chop(1);
    return res;
}

QString drakeSistema::getMp3Artist(QString filename)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosCat;
    QStringList argumentosGrep;
    QByteArray Cat;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosCat << ""+filename+"";
    argumentosGrep << "TPE1";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("id3info", argumentosCat);
    procesoGrep->start("grep", argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    procesoGrep->waitForFinished();
    Cat = procesoGrep->readAllStandardOutput();
    delete procesoCat;
    delete procesoGrep;
    QString res = QString(Cat);
    res.chop(1);
    return res;
}

QString drakeSistema::getMp3Album(QString filename)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosCat;
    QStringList argumentosGrep;
    QByteArray Cat;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosCat << ""+filename+"";
    argumentosGrep << "TALB";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("id3info", argumentosCat);
    procesoGrep->start("grep", argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    procesoGrep->waitForFinished();
    Cat = procesoGrep->readAllStandardOutput();
    delete procesoCat;
    delete procesoGrep;
    QString res = QString(Cat);
    res.chop(1);
    return res;
}

QString drakeSistema::getMp3Year(QString filename)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosCat;
    QStringList argumentosGrep;
    QByteArray Cat;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosCat << ""+filename+"";
    argumentosGrep << "TYER";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("id3info", argumentosCat);
    procesoGrep->start("grep", argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    procesoGrep->waitForFinished();
    Cat = procesoGrep->readAllStandardOutput();
    delete procesoCat;
    delete procesoGrep;
    QString res = QString(Cat);
    res.chop(1);
    return res;
}

QString drakeSistema::getMp3Comment(QString filename)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosCat;
    QStringList argumentosGrep;
    QByteArray Cat;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosCat << ""+filename+"";
    argumentosGrep << "COMM";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("id3info", argumentosCat);
    procesoGrep->start("grep", argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    procesoGrep->waitForFinished();
    Cat = procesoGrep->readAllStandardOutput();
    delete procesoCat;
    delete procesoGrep;
    QString res = QString(Cat);
    res.chop(1);
    return res;
}

QString drakeSistema::getMp3Track(QString filename)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosCat;
    QStringList argumentosGrep;
    QByteArray Cat;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosCat << ""+filename+"";
    argumentosGrep << "TRCK";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("id3info", argumentosCat);
    procesoGrep->start("grep", argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    procesoGrep->waitForFinished();
    Cat = procesoGrep->readAllStandardOutput();
    delete procesoCat;
    delete procesoGrep;
    QString res = QString(Cat);
    res.chop(1);
    return res;
}

QString drakeSistema::getMp3Genre(QString filename)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosCat;
    QStringList argumentosGrep;
    QByteArray Cat;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosCat << ""+filename+"";
    argumentosGrep << "TCON";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("id3info", argumentosCat);
    procesoGrep->start("grep", argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    procesoGrep->waitForFinished();
    Cat = procesoGrep->readAllStandardOutput();
    delete procesoCat;
    delete procesoGrep;
    QString res = QString(Cat);
    res.chop(1);
    return res;
}

QString drakeSistema::getRelease()
{
    QProcess *procesoCut, *procesoCut2, *procesoCut3, *procesoCut4;
    QStringList argumentosCut, argumentosCut2, argumentosCut3, argumentosCut4;
    QByteArray release;
    procesoCut=new QProcess(this);
    procesoCut2=new QProcess(this);
    procesoCut3=new QProcess(this);
    procesoCut4=new QProcess(this);
    procesoCut->setStandardOutputProcess(procesoCut2);
    procesoCut2->setStandardOutputProcess(procesoCut3);
    procesoCut3->setStandardOutputProcess(procesoCut4);
    drakeSistema drake;
    Distro = drake.getDistrop();
    argumentosCut << "-qa";
    if (Distro=="Mandriva") // || Distro=="OpenMandriva")
        argumentosCut2 << "-i" << "mandriva-release";
    else if (Distro=="Mageia")
        argumentosCut2 << "-i" << "mageia-release";
    argumentosCut3 << "-v" << "common";
    argumentosCut4 << "-f3" << "-d" << "-";
    procesoCut->start("rpm", argumentosCut);
    procesoCut2->start("grep", argumentosCut2);
    procesoCut3->start("grep", argumentosCut3);
    procesoCut4->start("cut", argumentosCut4);
    if (! procesoCut4->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    procesoCut2->waitForFinished();
    procesoCut3->waitForFinished();
    procesoCut4->waitForFinished();
    release = procesoCut4->readAllStandardOutput();
    delete procesoCut;
    delete procesoCut2;
    delete procesoCut3;
    delete procesoCut4;
    QString res =  QString(release);
    res.chop(1);
    return res;
}

QString drakeSistema::getIPRouter()
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosRoute;
    QStringList argumentosGrep;
    QByteArray IpRouter;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosRoute << "-n";
    argumentosGrep << "UG";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("route", argumentosRoute);
    procesoGrep->start("grep", argumentosGrep);
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

QString drakeSistema::getInternet()
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosRoute;
    QStringList argumentosGrep;
    QByteArray IpRouter;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosRoute << "-n";
    argumentosGrep << "UG";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("route", argumentosRoute);
    procesoGrep->start("grep", argumentosGrep);
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

QString drakeSistema::getInfoPro()
{
    QProcess *procesoCat;
    QStringList argumentosCat;
    QByteArray Cat;
    procesoCat=new QProcess(this);
    argumentosCat << "/proc/cpuinfo";
    procesoCat->start("cat", argumentosCat);
    if (! procesoCat->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    Cat = procesoCat->readAllStandardOutput();
    delete procesoCat;
    QString res = QString(Cat);
    res.chop(1);
    return res;
}

QString drakeSistema::getMac(QString Valor)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosRoute;
    QStringList argumentosGrep;
    QByteArray IpRouter;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosRoute << "-n" << "-e" << ""+Valor+"";
    argumentosGrep << ""+Valor+"";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("arp", argumentosRoute);
    procesoGrep->start("grep", argumentosGrep);
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

QString drakeSistema::getLs()
{
    QProcess *procesoCat;
    QStringList argumentosCat;
    QByteArray Cat;
    procesoCat=new QProcess(this);
    argumentosCat << "/usr/share/RecoverDrake/RecoverDrake.log";
    procesoCat->start("ls", argumentosCat);
    if (! procesoCat->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    Cat = procesoCat->readAllStandardOutput();
    delete procesoCat;
    QString res = QString(Cat);
    res.chop(1);
    return res;
}

QString drakeSistema::getMedia()
{
    QProcess *procesoMount, *procesoGrep;
    QStringList argumentosGrep;
    QByteArray IMedia;
    procesoMount=new QProcess(this);
    procesoGrep=new QProcess(this);
    user = getUser();
    QString Valor20 = "find /run/media -maxdepth 1";
    QString valor = getStart(Valor20);
    QStringList Comparar = valor.split("\n");
    QString value = Comparar.value(0);
    if (value == "")
        argumentosGrep << "/media/";
    else
        argumentosGrep << "/run/media/"+user+"/";
    procesoMount->setStandardOutputProcess(procesoGrep);
    procesoMount->start("mount");
    procesoGrep->start("grep", argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoMount->waitForFinished();
    procesoGrep->waitForFinished();
    IMedia = procesoGrep->readAllStandardOutput();
    delete procesoMount;
    delete procesoGrep;
    QString res = QString(IMedia);
    res.chop(1);
    return res;
}

QString drakeSistema::getKill()
{
    QProcess *procesoCut, *procesoCut2, *procesoCut3, *procesoCut4;
    QStringList argumentosCut, argumentosCut2, argumentosCut3, argumentosCut4;
    QByteArray release;

    procesoCut=new QProcess(this);
    procesoCut2=new QProcess(this);
    procesoCut3=new QProcess(this);
    procesoCut4=new QProcess(this);

    procesoCut->setStandardOutputProcess(procesoCut2);
    procesoCut2->setStandardOutputProcess(procesoCut3);
    procesoCut3->setStandardOutputProcess(procesoCut4);

    argumentosCut << "-e";
    argumentosCut2 << "kio_thumbnail";
    argumentosCut3 << "{'print $4'}";
    argumentosCut4 << "-l";

    procesoCut->start("ps", argumentosCut);
    procesoCut2->start("grep", argumentosCut2);
    procesoCut3->start("awk", argumentosCut3);
    procesoCut4->start("wc", argumentosCut4);

    if (! procesoCut4->waitForStarted())
        return QString("");

    procesoCut->waitForFinished();
    procesoCut2->waitForFinished();
    procesoCut3->waitForFinished();
    procesoCut4->waitForFinished();

    release = procesoCut4->readAllStandardOutput();

    delete procesoCut;
    delete procesoCut2;
    delete procesoCut3;
    delete procesoCut4;
    QString res =  QString(release);
    res.chop(1);
    return res;
}

QString drakeSistema::getKillAll()
{
    QProcess *procesoCut, *procesoCut2, *procesoCut3, *procesoCut4;
    QStringList argumentosCut, argumentosCut2, argumentosCut3, argumentosCut4;
    QByteArray release;

    procesoCut=new QProcess(this);
    procesoCut2=new QProcess(this);
    procesoCut3=new QProcess(this);
    procesoCut4=new QProcess(this);

    procesoCut->setStandardOutputProcess(procesoCut2);
    procesoCut2->setStandardOutputProcess(procesoCut3);
    procesoCut3->setStandardOutputProcess(procesoCut4);

    argumentosCut << "-ef";
    argumentosCut2 << "-v" << "grep";
    argumentosCut3 << "kio_thumbnail";
    argumentosCut4 << "{'print $2'}";

    procesoCut->start("ps", argumentosCut);
    procesoCut2->start("grep", argumentosCut2);
    procesoCut3->start("awk", argumentosCut3);
    procesoCut4->start("wc", argumentosCut4);

    if (! procesoCut4->waitForStarted())
        return QString("");

    procesoCut->waitForFinished();
    procesoCut2->waitForFinished();
    procesoCut3->waitForFinished();
    procesoCut4->waitForFinished();

    release = procesoCut4->readAllStandardOutput();

    delete procesoCut;
    delete procesoCut2;
    delete procesoCut3;
    delete procesoCut4;
    QString res =  QString(release);
    res.chop(1);
    return res;
}

QString drakeSistema::getLabel()
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosCat, argumentosGrep;
    QByteArray Label;

    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);

    argumentosCat << "/etc/mtools.conf";
    argumentosGrep << "mtools_skip_check=1";

    procesoCat->setStandardOutputProcess(procesoGrep);

    procesoCat->start("cat", argumentosCat);
    procesoGrep->start("grep", argumentosGrep);

    if (! procesoGrep->waitForStarted())
        return QString("");

    procesoCat->waitForFinished();
    procesoGrep->waitForFinished();

    Label = procesoGrep->readAllStandardOutput();

    delete procesoCat;
    delete procesoGrep;
    QString res = QString(Label);
    res.chop(1);
    return res;
}

QString drakeSistema::getLabelOld(QString Unidad)
{
    QProcess *procesoFree;
    QStringList argumentosFree;
    QByteArray FreeTotal;

    procesoFree=new QProcess(this);

    argumentosFree << "-i" << ""+Unidad+"" << "-s" << "::";

    procesoFree->start("mlabel", argumentosFree);

    if (! procesoFree->waitForStarted())
        return QString("");

    procesoFree->waitForFinished();

    FreeTotal = procesoFree->readAllStandardOutput();

    delete procesoFree;
    QString res = QString(FreeTotal);
    res.chop(0);
    return res;
}

QString drakeSistema::getResolution()
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosGrep;
    QByteArray Label;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosGrep << "*";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("xrandr");
    procesoGrep->start("grep", argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    procesoGrep->waitForFinished();
    Label = procesoGrep->readAllStandardOutput();
    delete procesoCat;
    delete procesoGrep;
    QString res = QString(Label);
    res.chop(1);
    return res;
}

QString drakeSistema::getResolucion()
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosCat, argumentosGrep;
    QByteArray Label;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosCat << "-q";
    argumentosGrep << "Screen";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("xrandr", argumentosCat);
    procesoGrep->start("grep", argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    procesoGrep->waitForFinished();
    Label = procesoGrep->readAllStandardOutput();
    delete procesoCat;
    delete procesoGrep;
    QString res = QString(Label);
    res.chop(1);
    return res;
}

QString drakeSistema::getHostname()
{
    QProcess *procesoCat;
    QByteArray Label;
    procesoCat=new QProcess(this);
    procesoCat->start("hostname");
    if (! procesoCat->waitForStarted())
        return QString("");
    procesoCat->waitForFinished();
    Label = procesoCat->readAllStandardOutput();
    delete procesoCat;
    QString res = QString(Label);
    res.chop(1);
    return res;
}

QString drakeSistema::getBios()
{
    QProcess *procesoXset;
    QByteArray TipCaps;
    procesoXset=new QProcess(this);
    procesoXset->start("dmidecode");
    if (! procesoXset->waitForStarted())
        return QString("");
    procesoXset->waitForFinished();
    TipCaps = QString(procesoXset->readAllStandardOutput());
    delete procesoXset;
    QString res = QString(TipCaps);
    res.chop(1);
    return res;
}

QString drakeSistema::getEssid(QString ip)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosRoute;
    QStringList argumentosGrep;
    QByteArray IpRouter;
    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosRoute << ip << "scan";
    argumentosGrep << "ESSID";
    procesoCat->setStandardOutputProcess(procesoGrep);
    procesoCat->start("iwlist", argumentosRoute);
    procesoGrep->start("grep", argumentosGrep);
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

QString drakeSistema::getEthernet()
{
    QProcess *procesoFind, *procesoCut;
    QStringList argumentosFind;
    QStringList argumentosCut;
    QByteArray TipVirtual;
    procesoFind=new QProcess(this);
    procesoCut=new QProcess(this);
    argumentosFind << "eth0";
    argumentosCut << "RX bytes";
    procesoFind->setStandardOutputProcess(procesoCut);
    procesoFind->start("ifconfig",argumentosFind);
    procesoCut->start("grep",argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoFind->waitForFinished();
    procesoCut->waitForFinished();
    TipVirtual = QString(procesoCut->readAllStandardOutput());
    delete procesoFind;
    delete procesoCut;
    QString res =  QString(TipVirtual);
    res.chop(1);
    return res;
}

QString drakeSistema::getTorrentP(QString Name)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosRoute;
    QStringList argumentosGrep;
    QByteArray IpRouter;

    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);

    argumentosRoute << Name;
    argumentosGrep << "  Total Size: ";

    procesoCat->setStandardOutputProcess(procesoGrep);

    procesoCat->start("transmission-show", argumentosRoute);
    procesoGrep->start("grep", argumentosGrep);

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

QString drakeSistema::getTorrentN(QString Name)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosRoute;
    QStringList argumentosGrep;
    QByteArray IpRouter;

    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);

    argumentosRoute << Name;
    argumentosGrep << "  Name: ";

    procesoCat->setStandardOutputProcess(procesoGrep);

    procesoCat->start("transmission-show", argumentosRoute);
    procesoGrep->start("grep", argumentosGrep);

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

QString drakeSistema::getFind(QString valor)
{
    QProcess *procesoFree;
    QStringList argumentosFree;
    QByteArray FreeTotal;
    procesoFree=new QProcess(this);
    argumentosFree << valor;
    procesoFree->start("find", argumentosFree);
    if (! procesoFree->waitForStarted())
        return QString("");
    procesoFree->waitForFinished();
    FreeTotal = procesoFree->readAllStandardOutput();
    delete procesoFree;
    QString res = QString(FreeTotal);
    res.chop(0);
    return res;
}

QString drakeSistema::getBackup()
{
    QProcess *procesoFind, *procesoGrep;
    QStringList argumentosFind;
    QStringList argumentosGrep;
    QByteArray db;
    procesoFind=new QProcess(this);
    procesoGrep=new QProcess(this);
    argumentosFind << "/usr/share/RecoverDrake/backup/";
    argumentosGrep << ".cfg";
    procesoFind->setStandardOutputProcess(procesoGrep);
    procesoFind->start("find",argumentosFind);
    procesoGrep->start("grep",argumentosGrep);
    if (! procesoGrep->waitForStarted())
        return QString("");
    procesoFind->waitForFinished();
    procesoGrep->waitForFinished();
    db = QString(procesoGrep->readAllStandardOutput());
    delete procesoFind;
    delete procesoGrep;
    QString res =  QString(db);
    res.chop(1);
    return res;
}

QString drakeSistema::getDu(QString Valor)
{
    QProcess *procesoCut;
    QStringList argumentosCut;
    QByteArray du;
    procesoCut=new QProcess(this);
    argumentosCut << ""+Valor+"";
    procesoCut->start("find", argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    du = procesoCut->readAllStandardOutput();
    delete procesoCut;
    QString res =  QString(du);
    res.chop(1);
    return res;
}

QString drakeSistema::getTipo(QString Valor)
{
    QProcess *procesoCut;
    QStringList argumentosCut;
    QByteArray du;
    procesoCut=new QProcess(this);
    argumentosCut << ""+Valor+"";
    procesoCut->start("file", argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    du = procesoCut->readAllStandardOutput();
    delete procesoCut;
    QString res =  QString(du);
    res.chop(1);
    return res;
}

QString drakeSistema::getLslh(QString Valor)
{
    QProcess *procesoCut;
    QStringList argumentosCut;
    QByteArray du;

    procesoCut=new QProcess(this);

    argumentosCut << "-lh" << ""+Valor+"";

    procesoCut->start("ls", argumentosCut);

    if (! procesoCut->waitForStarted())
        return QString("");

    procesoCut->waitForFinished();

    du = procesoCut->readAllStandardOutput();

    delete procesoCut;
    QString res =  QString(du);
    res.chop(1);
    return res;
}

QString drakeSistema::getLslhd(QString Valor)
{
    QProcess *procesoCut;
    QStringList argumentosCut;
    QByteArray du;

    procesoCut=new QProcess(this);

    argumentosCut << "-lhd" << ""+Valor+"";

    procesoCut->start("ls", argumentosCut);

    if (! procesoCut->waitForStarted())
        return QString("");

    procesoCut->waitForFinished();

    du = procesoCut->readAllStandardOutput();

    delete procesoCut;
    QString res =  QString(du);
    res.chop(1);
    return res;
}

QString drakeSistema::getUsuarios()
{
    QProcess *procesoFind, *procesoGrep;
    QStringList argumentosFind;
    QStringList argumentosGrep;
    QByteArray db;

    procesoFind=new QProcess(this);
    procesoGrep=new QProcess(this);

    argumentosFind << "/etc/passwd";
    argumentosGrep << "-d" << ":" << "-f1";

    procesoFind->setStandardOutputProcess(procesoGrep);

    procesoFind->start("cat",argumentosFind);
    procesoGrep->start("cut",argumentosGrep);

    if (! procesoGrep->waitForStarted())
        return QString("");

    procesoFind->waitForFinished();
    procesoGrep->waitForFinished();

    db = QString(procesoGrep->readAllStandardOutput());

    delete procesoFind;
    delete procesoGrep;
    QString res =  QString(db);
    res.chop(1);
    return res;
}

QString drakeSistema::getMAC(QString Tipo)
{
    QProcess *procesoDir, *procesoCut;
    QStringList argumentosFind, argumentosCut;
    QByteArray rpm;

    procesoDir=new QProcess(this);
    procesoCut=new QProcess(this);

    argumentosFind << ""+Tipo+"";
    argumentosCut << "/HW/ {print $5}";

    procesoDir->setStandardOutputProcess(procesoCut);

    procesoDir->start("ifconfig",argumentosFind);
    procesoCut->start("awk", argumentosCut);

    if (! procesoCut->waitForStarted())
    {
        return QString("");
    }

    procesoCut->waitForFinished();

    rpm = QString(procesoCut->readAllStandardOutput());

    delete procesoDir;
    delete procesoCut;
    QString res =  QString(rpm);
    res.chop(1);
    return res;
}

QString drakeSistema::getStart(QString ruta)
{
    QProcess *procesoFree;
    QByteArray FreeTotal;
    procesoFree=new QProcess(this);
    procesoFree->start(ruta);
    if (! procesoFree->waitForStarted())
        return QString("");
    procesoFree->waitForFinished();
    FreeTotal = procesoFree->readAllStandardOutput();
    delete procesoFree;
    QString res = QString(FreeTotal);
    res.chop(0);
    return res;
}
