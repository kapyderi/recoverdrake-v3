#include <QMessageBox>
#include <stdlib.h>
#include <QtGui>
#include <QToolButton>
#include <QWidget>

#include "recoverdrake.h"
#include "ui_recoverdrake.h"
#include "drakesistema.h"
#include "drakeprocesos.h"
#include "acceso.h"
#include "claves.h"
#include "help.h"
#include "notas.h"
#include "burn.h"

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlTableModel>

recoverdrake::recoverdrake(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::recoverdrake)
{
    ui->setupUi(this);

    drakeSistema drake;

    actionSalir();
    actionConsola_como_root();
    actionEditar_y_configurar_repositorios();
    actionAcerca_de();
    actionAcerca_de_Qt();

    dist = drake.getDistribucion();
    arqt = drake.getArquitectura();
    user = drake.getUser();
    Tip = drake.getTipKernel();
    Ver = drake.getVerKernel();
    Rev = drake.getRevKernel();
    Dir = drake.getDirActual();
    Vir = drake.getVirtual();

    mib = 0;
    otros = 0;
    clave = 0;

    acceso *acc=new acceso(this);
    acc->exec();

    this->Arranque();

}

recoverdrake::~recoverdrake()
{
    delete ui;
    if (mib != 0)
        delete mib;
    if (otros != 0 )
        delete otros;
    if (clave != 0)
        delete clave;
}

void recoverdrake::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void recoverdrake::Arranque()
{
    QString cmd="echo Comprobando dependencias necesarias...";
    QString comando="/bin/sh urpmi -a --auto zenity sudo bash kwrite libstdc++5 ndiswrapper photorec testdisk ntfs-config kde-rootactions-servicemenu cdparanoia lame ffmpeg dvdauthor";

    QStringList comandos;
    comandos<< cmd << comando;

    if (mib != 0)
        delete otros;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    mib->iniciarProceso();
}

void recoverdrake::actionSalir()
{
    connect(ui->actionSalir,SIGNAL(triggered()),this,SLOT(close()));
}

void recoverdrake::on_actionUsuarios_triggered()
{
    claves *clave=new claves();
    clave->exec();     
}

void recoverdrake::on_actionComprabar_depndencias_RecoverDrake_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Comprobar dependencias de uso"),
               tr("<center><b>Comprobar dependecias para RecoverDrake</b></center><p>"

                  "<b>IMPORTANTE:</b> Esta opcion se utiliza para saber y actualizar "
                  "todas las dependencias necesarias para un buen uso de RecoverDrake, "
                  "ya que necesita de varios paquetes externos que deben estar "
                  "debidamente configurados e instalados para tener al 100% nuestra "
                  "utilidad.<p>"

                  "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                  "el cual le sera notificado cuando finalice.</B><p>"

                  "&iquest;Comprobar dependencias para el buen uso de RecoverDrake?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

    QString cmd="echo Buscando dependencias necesarias e instalando...";
    QString comando="/bin/sh urpmi -a --auto zenity sudo bash kwrite libstdc++5 ndiswrapper photorec testdisk ntfs-config kde-rootactions-servicemenu cdparanoia lame ffmpeg dvdauthor";

    QStringList comandos;
    comandos<< cmd << comando;

    if (mib != 0)
        delete otros;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    mib->iniciarProceso();}
    return;
}

void recoverdrake::on_actionEliminar_Repositorios_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Eliminar repositorios"),
               tr("<center><b>Eliminar repositorios configurados</b></center><p>"

                  "<b>IMPORTANTE:</b> Esta opcion solo es valida, si los repositorios "
                  "suelen fallar, ya que los elimina y los vuelve a crear con "
                  "una nueva configuracion.<p>"

                  "Proceda con cuidado!!!<p>"

                  "Como su nombre indica, tras una instalacion limpia, se "
                  "quedan instalados como repositorios los soportes del "
                  "DVD/CD de instalacion, pues con esta opcion se pueden "
                  "eliminar y dejar limpios todos los soportes.<p>"

                  "Tambien sirve cuando tienes algun grupo de repositorios "
                  "\"problematicos\" y quieres cambiarlos o cualquier otro tipo "
                  "de problemas de configuracion de los mismos.<p>"

                  "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                  "el cual le sera notificado cuando finalice.</B><p>"

                  "&iquest;Eliminar repositorios instalados?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

    QString comando="/bin/sh urpmi.removemedia -a";

    QStringList comandos;
    comandos<< comando;

    if (mib != 0)
        delete otros;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    mib->iniciarProceso();}
    return;
}

void recoverdrake::on_actionOficiales_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Instalar repositorios oficiales"),
               tr("<center><b>Oficiales</b></center><p>"

                  "Configuracion de los repositorios Oficiales.<p>"

                  "Estos repositorios como su nombre indica son los garantizados "
                  "por Mandriva y son necesarios para tenerlo todo actualizado "
                  "y poder disponer de los paquetes que Mandriva nos deja a nuestro "
                  "alcance.<p>"

                  "Representan el conjunto de repositoriosa Main, Contrib, non-free "
                  "y sus respectivos \"updates\" y \"backports\"<p>"

                  "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                  "el cual le sera notificado cuando finalice.</B><p>"

                  "&iquest;Instalar repositorios Oficiales (Recomendado)?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

    QString comando="/bin/sh urpmi.addmedia --wget --distrib --mirrorlist \"http://api.mandriva.com/mirrors/basic.%1.%2.list\"";
    comando = comando.arg(dist).arg(arqt);

    QStringList comandos;
    comandos<< comando;

    if (mib != 0)
        delete otros;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    mib->iniciarProceso();}
    return;
}

void recoverdrake::on_actionPLF_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Instalar repositorios PLF"),
               tr("<center><b>PLF</b></center><p>"

                  "Configuracion de los repositorios PLF.<p>"

                  "Corresponden al grupo \"Penguin Liberation Front\" mas "
                  "conocidos como PLF y es un grupo de paquetes altamente "
                  "recomendado.<P>"

                  "Representan el conjunto de repositorios non-free y free "
                  "y sus respectivos \"updates\" y \"backports\"<p>"

                  "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                  "el cual le sera notificado cuando finalice.</B><p>"

                  "&iquest;Instalar repositorios PLF (Recomendado)?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

    QString cmd1 = "urpmi.addmedia --wget --distrib --mirrorlist \"http://plf.zarb.org/mirrors/%1.%2.list\"";
    cmd1 = cmd1.arg(dist).arg(arqt);

    QStringList comandos;
    comandos<< cmd1;

    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    mib->iniciarProceso();}
    return;
}

void recoverdrake::on_actionMIB_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Instalar repositorios MIB"),
               tr("<center><b>MIB</b></center><p>"

                  "Configuracion de los repositorios MIB.<p>"

                  "Corresponden al grupo \"Mandriva International Backports\" mas "
                  "conocidos como MIB o \"Mandriva Italian Backports\" de origen "
                  "italiano y es un grupo de paquetes mas moderno e incluso no "
                  "distribuidos en otros repositorios, pero suelen causar problemas "
                  "con los repositorios oficiales, por lo que recomiendo que esten "
                  "inhabilitados desde inicio y solo habilitar cuando se necesite "
                  "un paquete en particular.<p>"

                  "Representan el conjunto de repositorios Basic_32 y Experto_32.<p>"

                  "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                  "el cual le sera notificado cuando finalice.</B><p>"

                  "&iquest;Instalar repositorios MIB?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

    QString cmd1 = "/bin/sh urpmi.addmedia --wget --update MIB-basic_32 http://mib.pianetalinux.org/MIB/%1/32/basic/ with media_info/synthesis.hdlist.cz" ;
    cmd1 = cmd1.arg(dist);
    QString cmd2 = "/bin/sh urpmi.addmedia --wget MIB-experts_32 http://mib.pianetalinux.org/MIB/%1/32/experts/ with media_info/synthesis.hdlist.cz";
    cmd2 =  cmd2.arg(dist);

    QStringList comandos;
    comandos<< cmd1 << cmd2 ;

    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    mib->iniciarProceso();}
    return;
}

void recoverdrake::on_actionBDK_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Instalar repositorios BDK"),
               tr("<center><b>BDK</b></center><p>"

                  "Configuracion de los repositorios BDK.<p>"

                  "Somos, ya que me incluyo, el grupo \"blogdrake\", el foro "
                  "oficial de Mandriva en lengua espa&ntilde;ola y en nuestro "
                  "repositorio puedes encontrar versiones recientes de "
                  "paquetes actualizados y paquetes que no encontraras en "
                  "otros repositorios<p>"

                  "Al igual que MIB, debería estar deshabilitado de comienzo "
                  "y habilitar en el momento de su uso, para evitar cualquier "
                  "incompatibilidad de software<p>"

                  "Representan el conjunto de repositorios free, noarch-free y "
                  "non-free y noarch-free.<p>"

                  "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                  "el cual le sera notificado cuando finalice.</B><p>"

                  "&iquest;Instalar repositorios BDK?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

    QString cmd1 = "/bin/sh urpmi.addmedia --update --wget Bdk-%2-free ftp://ftp.blogdrake.net/mandriva/%1/free/%2 with media_info/synthesis.hdlist.cz" ;
    cmd1 = cmd1.arg(dist).arg(arqt);
    QString cmd2 = "/bin/sh urpmi.addmedia --update --wget Bdk-noarch-free ftp://ftp.blogdrake.net/mandriva/%1/free/noarch with media_info/synthesis.hdlist.cz";
    cmd2 =  cmd2.arg(dist);
    QString cmd3 = "/bin/sh urpmi.addmedia --update --wget Bdk-noarch-nonfree ftp://ftp.blogdrake.net/mandriva/%1/non-free/noarch with media_info/synthesis.hdlist.cz";
    cmd3 =  cmd3.arg(dist);
    QString cmd4 = "/bin/sh urpmi.addmedia --update --wget Bdk-%2-nonfree ftp://ftp.blogdrake.net/mandriva/%1/non-free/%2 with media_info/synthesis.hdlist.cz";
    cmd4 = cmd4.arg(dist).arg(arqt);

    QStringList comandos;
    comandos<< cmd1 << cmd2 << cmd3 << cmd4;

    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    mib->iniciarProceso();}
    return;
}

void recoverdrake::on_actionMUD_triggered()
{
    int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar repositorios MUD"),
               tr("<center><b>MUD</b></center><p>"

                  "Configuracion de los repositorios MUD.<p>"

                  "Corresponden al grupo \"Mandriva User Deutschland\" mas "
                  "conocido como MUD de origen Aleman y como MIB o BDK es un "
                  "desarrollo totalmente independiente, por lo que debe estar "
                  "deshabilitado desde inicio, por la similitud con el grupo "
                  "MIB o BDK.<P>"

                  "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                  "el cual le sera notificado cuando finalice.</B><p>"

                  "&iquest;Instalar repositorios MUD?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

    QString cmd1 = "/bin/sh urpmi.addmedia --wget MUD-%2 ftp://ftp.mandrivauser.de/rpm/GPL/%1/%2/release/ with media_info/synthesis.hdlist.cz";
    cmd1 = cmd1.arg(dist).arg(arqt);

    QStringList comandos;
    comandos<< cmd1;

    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    mib->iniciarProceso();}
    return;
}

void recoverdrake::on_actionOtros_Manualmente_triggered()
{
    int respuesta = 0;
    bool ok;
    respuesta = QMessageBox::question(this, tr("Instalacion manual de repositorios"),
                tr("<center><b>Instalar repositorio manualmente</b></center><p>"

                   "Este apartado solo sirve para poder introducir un "
                   "repositorio a mano, ya que hay muchos mas que no voy "
                   "a relacionar aqui que pueden ser de tu interes.<p>"

                   "Introduzca <b>SOLO</b> el nombre con el que quieras que "
                   "sea identificado y la direccion de la web.<P> "

                   "<FONT COLOR=\"RED\">Ejemplo:<p>"

                   "<FONT COLOR=\"RED\">KDE_452<p>"

                   "<FONT COLOR=\"RED\">ftp://ftp.kde.org/pub/kde/stable/4.5.0/Mandriva/2010.1/i586/<p>"

                   "<b><FONT COLOR=\"RED\">NUNCA</b> incluir la parte inicial que pone "
                   "<b>urpmi.addmedia</b> ni la parte final <b>with media_info/synthesis.hdlist.cz</b> "
                   "ya que esta parte, RecoverDrake, lo hace automaticamente.<p>"

                   "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                   "el cual le sera notificado cuando finalice.</B><p>"

                   "&iquest;Comenzar instalacion manual de repositorios?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){
               QString texto = QInputDialog::getText(this, tr("Instalacion manual de repositorios"),
               tr("Introduzca el nombre para identificar el repositorio.<P> "

                   "<FONT COLOR=\"RED\">Ejemplo:<p>"

                   "<FONT COLOR=\"RED\">KDE45_i586"),
                   QLineEdit::Normal,
                   "",
                   &ok);
                   if (ok && !texto.isEmpty()){
                         QString texto1 = QInputDialog::getText(this, tr("Instalacion manual de repositorios"),
                               tr("Introduzca la direccion web<p>"

                                  "<FONT COLOR=\"RED\">Ejemplo:<p>"

                                  "<FONT COLOR=\"RED\">ftp://ftp.kde.org/pub/kde/stable/4.5.0/Mandriva/2010.1/i586/<p>"),
                                  QLineEdit::Normal,
                                  "",
                                  &ok);
                        if (ok && !texto1.isEmpty()){
                        QString cmd = "/bin/sh urpmi.addmedia %1 %2 with media_info/synthesis.hdlist.cz";
                        cmd = cmd.arg(texto).arg(texto1);
                        QStringList comandos;
                        comandos<< cmd;

                        if (mib != 0)
                            delete mib;
                        mib = new DrakeProcesos(comandos, this);
                        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                        mib->iniciarProceso();}
                }
        }
        return;
}
void recoverdrake::on_actionA_adir_todos_triggered()
{
    int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar todos los repositorios"),
               tr("<center><b>Instalar todos los repositorios</b></center><p>"

                  "Este apartado realiza la instalacion masiva de todos "
                  "los repositorios incluidos por defectos, como pueden "
                  "ser OFICIALES, PLF, MIB, BDK y MUD.<P> "

                  "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                  "el cual le sera notificado cuando finalice.</B><p>"

                  "&iquest;Configurar todos los repositorios?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){
        QString cmd1 = "/bin/sh urpmi.addmedia --wget --distrib --mirrorlist \"http://api.mandriva.com/mirrors/basic.%1.%2.list\"";
        cmd1 = cmd1.arg(dist).arg(arqt);
        QString cmd2 = "urpmi.addmedia --wget --distrib --mirrorlist \"http://plf.zarb.org/mirrors/%1.%2.list\"";
        cmd2 = cmd2.arg(dist).arg(arqt);
        QString cmd3 = "/bin/sh urpmi.addmedia --wget --update MIB-basic_32 http://mib.pianetalinux.org/MIB/%1/32/basic/ with media_info/synthesis.hdlist.cz" ;
        cmd3 = cmd3.arg(dist);
        QString cmd4 = "/bin/sh urpmi.addmedia --wget MIB-experts_32 http://mib.pianetalinux.org/MIB/%1/32/experts/ with media_info/synthesis.hdlist.cz";
        cmd4 =  cmd4.arg(dist);
        QString cmd5 = "/bin/sh urpmi.addmedia --update --wget Bdk-%2-free ftp://ftp.blogdrake.net/mandriva/%1/free/%2 with media_info/synthesis.hdlist.cz" ;
        cmd5 = cmd5.arg(dist).arg(arqt);
        QString cmd6 = "/bin/sh urpmi.addmedia --update --wget Bdk-noarch-free ftp://ftp.blogdrake.net/mandriva/%1/free/noarch with media_info/synthesis.hdlist.cz";
        cmd6 =  cmd6.arg(dist);
        QString cmd7 = "/bin/sh urpmi.addmedia --update --wget Bdk-noarch-nonfree ftp://ftp.blogdrake.net/mandriva/%1/non-free/noarch with media_info/synthesis.hdlist.cz";
        cmd7 =  cmd7.arg(dist);
        QString cmd8 = "/bin/sh urpmi.addmedia --update --wget Bdk-%2-nonfree ftp://ftp.blogdrake.net/mandriva/%1/non-free/%2 with media_info/synthesis.hdlist.cz";
        cmd8 = cmd8.arg(dist).arg(arqt);
        QString cmd9 = "/bin/sh urpmi.addmedia --wget MUD-%2 ftp://ftp.mandrivauser.de/rpm/GPL/%1/%2/release/ with media_info/synthesis.hdlist.cz";
        cmd9 = cmd9.arg(dist).arg(arqt);

        QStringList comandos;
        comandos<< cmd1 << cmd2 << cmd3 << cmd4 << cmd5 << cmd6 << cmd7 << cmd8 << cmd9;

        if (mib != 0)
            delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
}

void recoverdrake::actionEditar_y_configurar_repositorios()
{
    connect(ui->actionEditar_y_configurar_repositorios,SIGNAL(triggered()),this,SLOT(Config_Repos()));
}

void recoverdrake::Config_Repos()       
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Configurar repositorios"),
                           tr("<center><b>Editar/Borrar/Incluir Repositorios</b></center><p>"

                           "Con esta opcion Vd.puede EDITAR, HABILITAR, DESHABILITAR "
                           "e incluso BORRAR cualquier repositorio que haya en su "
                           "sistema.<p>"

                           "Muy util cuando un repositorio le da problemas.<p>"

                           "Proceda con cuidado!!! Habilitar repositorios debugs "
                           "o Testing,puede desestabilizar su sistema.<p>"

                           "Es interesante para su sistema que los repositorios "
                           "MIB, BDK y MUD esten deshabilitados.<p>"

                           "&iquest;Configurar repositorios?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "drakrpm-edit-media";

        QStringList comandos;
        comandos<< cmd;

        if (mib != 0)
            delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
}

void recoverdrake::on_actionActualizar_sistema_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Actualizar sistema"),
                           tr("<center><b>Actualizar sistema<b></center><p>"

                           "Como su nombre indica, una vez configurados los "
                           "repositorios es importante hacer una actualizacion "
                           "para solucionar cualquier bugs, problema, etc.<p>"

                           "Dicha actualizacion se realiza de manera automatica, "
                           "para no tener que interactuar con la terminal.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Actualizar sistema (Recomendado)?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){
        QString cmd = "/bin/sh urpmi --wget --auto --force --auto-update -v";

        QStringList comandos;
        comandos<< cmd;

        if (mib != 0)
            delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
}

void recoverdrake::on_actionEliminar_paquetes_huerfanos_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Eliminar paquetes huerfanos"),
                           tr("<center><b>Eliminar paquetes huerfanos<b></center><p>"

                           "Su finalidad es el desinstalar del sistema todos los "
                           "paquetes que se quedan huerfanos por desinstalacion de "
                           "otros paquetes.<p>"

                           "Esta opcion se incluye como una opcion mas, pero no se "
                           "recomienda utilizarla, ya que se puede inutilizar el "
                           "sistema.<p>"

                           "<FONT COLOR=\"RED\">PROCEDA CON PRECAUCION!!!!<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Desinstalar paquetes huerfanos (NO recomendado)?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "RecoverOrphans";

        QStringList comandos;
        comandos<< cmd;

        if (mib != 0)
        delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
}

void recoverdrake::on_actionRecuperar_paquetes_huerfanos_Eliminados_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Recuperar paquetes huerfanos"),
                           tr("<center><b>Recuperar paquetes huerfanos<b></center><p>"

                           "Mediante esta opcion podemos recupera los paquetes "
                           "huerfanos eliminados, ya que los volvera a instalar.<p>"

                           "Es importante en el caso de inestabilidad del sistema.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Recuperar paquetes huerfanos eliminados?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "RecoverResOrphans";

        QStringList comandos;
        comandos<< cmd;

        if (mib != 0)
        delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
}

void recoverdrake::on_actionSalvaguardar_rpm_s_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Salvaguarda de Rpm's"),
                           tr("<center><b>Salvaguarda de Rpm's<b></center><p>"

                           "Crea un fichero .lst con la informacion de rpm's de "
                           "su sistema, para ser utilizado en caso de necesidad.<p>"

                           "Es la opcion mas importante de RecoverDrake y para lo "
                           "que fue construido, ya que puedes exportar la lista a "
                           "otro equipo y hacer un mirror del original o por otro "
                           "lado, tras una instalacion de nueva version, se ejecuta "
                           "y vuelve a su estado original.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Realizar salvaguarda (Recomendado)?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "RecoverRpm";

        QStringList comandos;
        comandos<< cmd;

        if (mib != 0)
        delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
}

void recoverdrake::on_actionRecuperar_rpm_s_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Recuperar salvaguarda de Rpm's"),
                           tr("<center><b>Recuperar salvaguarda de Rpm's<b></center><p>"

                           "IMPORTANTE: Esta opcion sirve para recuperar los "
                           "paquetes despues de la instalacion/actualizacion.<p>"

                           "Utilizelo solo para este proposito.<p>"

                           "NOTA: Si su /home esta en una particion aparte, "
                           "continue sin problemas, sino es asi, copie el fichero "
                           "denominado PackAntxxxxxx.lst en la ubicacion:<p>"

                           "/home/TU_USUARIO/Documentos<p>"

                           "sino expecifica otra ruta, antes de realizar este paso, "
                           "ya que sino es asi, no podra realizarlo.<p>"

                           "Instalara todos los paquetes guardados, desechando los "
                           "ya instalados.<p>"

                           "Para poder llevar un seguimiento se creara un fichero "
                           "denominado RegRecoverxxxxxx.lst con los procesos "
                           "realizados durante el volcado en la ubicacion:<p>"

                           "/home/TU_USUARIO/Documentos<p>"

                           "sino expecifica otra ruta.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Recuperar salvaguarda (Recomendado)?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "RecoverResRpm";

        QStringList comandos;
        comandos<< cmd;

        if (mib != 0)
        delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
}

void recoverdrake::on_actionSalvaguardar_copia_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Copia de seguridad"),
                           tr("<center><b>Copia de seguridad</b></center><p>"

                           "Como su nombre indica, podemos hacer una copia de "
                           "seguridad de nuestros datos y de cualquier "
                           "directorio..<p>"

                           "Generara la copia del respado en la ubicacion en su "
                           "/home/TU_USUARIO/Documentos/ llamada RespaldoDrakexxxxxx.tar.bz2, "
                           "sino se expecifica lo contrario.<p>"

                           "En el caso de existir un fichero anterior con el mismo "
                           "nombre sera actualizado.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Realizar Backup?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "RecoverBackup";

        QStringList comandos;
        comandos<< cmd;

        if (mib != 0)
        delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
}

void recoverdrake::on_actionRecuperar_copia_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Restaurar copia de seguridad"),
                           tr("<center><b>Restaurar copia de seguridad<b></center><p>"

                           "Como su nombre indica, podemos restaurar los datos "
                           "anteriormente salvados a su ubicacion original. "
                           "salvo que se le de otra ruta.<p>"

                           "Instalara todos los datos guardados, sobreescribiendo "
                           "los ya instalados, en el que caso de que existan.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Restaurar backup?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/Documentos/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir copia de seguridad"),
                                path,trUtf8("Fichero comprimido .taz.bz2 (*.tar.bz2)"));
            if (fileNameOrigen.isEmpty())
                return;

            QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Donde descomprimir?"),path,QFileDialog::ShowDirsOnly);
            if (fileNameDirectori.isEmpty())
                return;

            QString cmd = "tar -xjvf %2 --directory=%3";
            cmd = cmd.arg(fileNameOrigen).arg(fileNameDirectori);

            QStringList comandos;
            comandos<< cmd;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionPreparar_kernel_para_autocompilaci_n_DKMS_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Preparar kernel para autocompilacion"),
                           tr("<center><b>Preparar kernel para autocompilacion<b></center><p>"

                           "A quien no le ha pasado, que al intentar compilar los DKMS, le han "
                           "dado error, por la necesidad de fuentes y codigo source sobre el "
                           "kernel activo, a la vez de no tener instaladas la librerias de "
                           "compilacion gcc<p>"

                           "Para poder solucionarlo, solo hay que ejecutar esta utilidad y "
                           "quedara resuelto.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Preparar autocompilacion?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi -a --auto kernel-%1-devel-%2-%3 kernel-%1-devel-latest kernel-%1-latest kernel-source-latest kernel-source-%2-%3 dkms dkms-minimal gcc gcc-c++ gcc-cpp";
        cmd = cmd.arg(Tip).arg(Ver).arg(Rev);

        QStringList comandos;
        comandos<< cmd;

        if (mib != 0)
            delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
}

void recoverdrake::on_actionCrear_imanen_ISO_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Crear imagen ISO"),
                               tr("<center><b>Crear imagen ISO<b></center><p>"

                               "Podemos crear una imagen iso con el simple echo de ejecutar esta "
                               "utilidad.<p>"

                               "<b>Introduzca el DVD/CD Origen en la unidad"

                               "Observaciones: Puede que lance un error del tipo entrada/salida "
                               "pero el proceso se realiza correctamente, prueba con la opcion de "
                               "Montar Imagen ISO, para verificar que ha sido correcta<p>"

                               "<B>NOTA Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Crear imagen ISO?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString path="/home/%1/Documentos/imagen.iso";
                path=path.arg(user);

                QString fileNameDestino = QFileDialog::getSaveFileName(this,tr("Salvar imagen ISO"),
                                    path,tr("Imagen ISO (*.iso)"));
                if (fileNameDestino.isEmpty())
                    return;

                QString cmd = "dd if=/dev/cdrom of=%2";
                cmd = cmd.arg(fileNameDestino);

                QStringList comandos;
                comandos<< cmd;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionMontar_imagen_ISO_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Montar imagen ISO"),
                               tr("<center><b>Montar imagen ISO<b></center><p>"

                               "Puede que nos interese montar una imagen .iso para poder "
                               "trabajar sobre ella, sin tener que grabarla en un CD/DVD.<P>"

                               "Con esta utilidad, hacemos un montaje en nuestro disco "
                               "duro sin tener que grabarla.<P>"

                               "<B>NOTA Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Montar imagen ISO?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString path="/home/%1/Documentos/";
                path=path.arg(user);

                QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir imagen ISO"),
                                    path,trUtf8("Imagen ISO (*.iso)"));
                if (fileNameOrigen.isEmpty())
                    return;

                QString fileNameDestino = QFileDialog::getExistingDirectory(this,tr("Destino de montaje"),path,QFileDialog::ShowDirsOnly);
                if (fileNameDestino.isEmpty())
                    return;

                QString cmd = "mount -o loop %2 %3";
                cmd = cmd.arg(fileNameOrigen).arg(fileNameDestino);

                QStringList comandos;
                comandos<< cmd;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionDesmontar_imagen_ISO_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Desmontar imagen ISO"),
                               tr("<center><b>Montar imagen ISO<b></center><p>"

                               "Una vez hemos acabado con la manipulacion de la imagen ISO "
                               "debemos desmontarla para poder dejar libre la memoria a la "
                               "vez que podemos manipular el fichero original ISO.<P>"

                               "<B>NOTA Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Desmontar imagen ISO?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString path="/home/%1/Documentos/";
                path=path.arg(user);
                QString fileNameOrigen = QFileDialog::getExistingDirectory(this,tr("Origen de imagen montada"),path,QFileDialog::ShowDirsOnly);
                if (fileNameOrigen.isEmpty())
                    return;

                QString cmd = "umount %2";
                QString cmd1 = "rmdir %2";
                cmd = cmd.arg(fileNameOrigen);
                cmd1 = cmd1.arg(fileNameOrigen);

                QStringList comandos;
                comandos<< cmd << cmd1;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionDuplicar_disco_triggered()
{
    int respuesta = 0;
    bool ok;
    respuesta = QMessageBox::question(this, tr("Duplicar Disco Duro"),
                tr("<center><b>Duplicar Disco Duro</b></center><p>"

                   "Puede que quieras duplicar un disco, al haber instalado "
                   "uno mas grande y no quieras perder toda la configuracion "
                   "o sistema personalizado.<p>"

                   "Mediante este proceso, hacemos un duplicado exacto de "
                   "disco completo.<p>"

                   "<b>IMPORTANTE: Comprueba con sumo cuidadado que la unidad origen "
                   "y la unidad destino sean correctas.</b><p>"

                   "Para ello antes de realizar el proceso se accedera a los "
                   "discos para que no haya ningun tipo de duda. "
                   "Es importante que tomes nota del nombre de cada unidad.<p>"

                   "Hay que tener en cuenta tambien que el disco destino debe "
                   "ser igual en capacidad (o en todo caso mayor) que el disco "
                   "origen.<p>"

                   "<FONT COLOR=\"RED\">Por ejemplo:<p>"
                   "<FONT COLOR=\"RED\">sda (disco origen)<p>"
                   "<FONT COLOR=\"RED\">sdb (disco destino)<p>"

                   "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                   "el cual le sera notificado cuando finalice.</B><p>"

                   "&iquest;Duplicar disco duro completo?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){
        system("diskdrake");
               QString texto = QInputDialog::getText(this, tr("Disco Origen"),
               tr("Introduzca el nombre de disco <b>ORIGEN</b>.<P> "

                   "<FONT COLOR=\"RED\">Ejemplo:<p>"

                   "<FONT COLOR=\"RED\">sda<p>"),
                   QLineEdit::Normal,
                   "",
                   &ok);
                   if (ok && !texto.isEmpty()){
                         QString texto1 = QInputDialog::getText(this, tr("Disco Destino"),
                               tr("Introduzca el nombre de disco <b>DESTINO</B><p>"

                                  "<FONT COLOR=\"RED\">Ejemplo:<p>"

                                  "<FONT COLOR=\"RED\">sdb<p>"),
                                  QLineEdit::Normal,
                                  "",
                                  &ok);
                        if (ok && !texto1.isEmpty()){
                        QString cmd = "dd if=/dev/%1 of=/dev/%2 bs=1M";
                        cmd = cmd.arg(texto).arg(texto1);
                        QStringList comandos;
                        comandos<< cmd;

                        if (mib != 0)
                            delete mib;
                        mib = new DrakeProcesos(comandos, this);
                        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                        mib->iniciarProceso();}
                }
        }
        return;
}

void recoverdrake::on_actionDuplicar_partici_n_triggered()
{
    int respuesta = 0;
    bool ok;
    respuesta = QMessageBox::question(this, tr("Duplicar Particion"),
                tr("<center><b>Duplicar Particion</b></center><p>"

                   "Puede que quieras duplicar una particion ya que la "
                   "capacidad se ha quedado peque&ntilde;a y quieras volcarla "
                   "a una mas grande.<p>"

                   "Mediante este proceso, hacemos un duplicado exacto de "
                   "una particion.<p>"

                   "<b>IMPORTANTE: Comprueba con sumo cuidadado que la particion "
                   "origen y la particion destino sean correctas.</b><p>"

                   "Para ello antes de realizar el proceso se accedera a las "
                   "particiones para que no haya ningun tipo de duda. "
                   "Es importante que tomes nota del nombre de cada particion.<p>"

                   "Hay que tener en cuenta tambien que la particion destino debe "
                   "ser igual en capacidad (o en todo caso mayor) que la particion "
                   "origen.<p>"

                   "<FONT COLOR=\"RED\">Por ejemplo:<p>"
                   "<FONT COLOR=\"RED\">sda1 (particion origen)<p>"
                   "<FONT COLOR=\"RED\">sda2 (particion destino)<p>"

                   "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                   "el cual le sera notificado cuando finalice.</B><p>"

                   "&iquest;Duplicar particion?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){
        system("diskdrake");
               QString texto = QInputDialog::getText(this, tr("Particion Origen"),
               tr("Introduzca el nombre de la particion <b>ORIGEN</b>.<P> "

                   "<FONT COLOR=\"RED\">Ejemplo:<p>"

                   "<FONT COLOR=\"RED\">sda1<p>"),
                   QLineEdit::Normal,
                   "",
                   &ok);
                   if (ok && !texto.isEmpty()){
                         QString texto1 = QInputDialog::getText(this, tr("Particion Destino"),
                               tr("Introduzca el nombre de la particion <b>DESTINO</B><p>"

                                  "<FONT COLOR=\"RED\">Ejemplo:<p>"

                                  "<FONT COLOR=\"RED\">sdb<p>"),
                                  QLineEdit::Normal,
                                  "",
                                  &ok);
                        if (ok && !texto1.isEmpty()){
                        QString cmd = "dd if=/dev/%1 of=/dev/%2 bs=1M";
                        cmd = cmd.arg(texto).arg(texto1);
                        QStringList comandos;
                        comandos<< cmd;

                        if (mib != 0)
                            delete mib;
                        mib = new DrakeProcesos(comandos, this);
                        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                        mib->iniciarProceso();}
                }
        }
        return;
}

void recoverdrake::on_actionCrear_Usb_bootable_triggered()
{
    int respuesta = 0;
    bool ok;
    respuesta = QMessageBox::question(this, tr("Crear USB-Live"),
                tr("<center><b>Crear USB-Live</b></center><p>"

                   "Se puede crear un USB-Live para poder iniciar desde un USB "
                   "si no se dispone una unidad de CD/DVD como los peque&ntilde;os "
                   "portatiles que solo tienen puertos USB.<p>"

                   "Hay que tener disponible una imagen .iso del sistema operativo "
                   "a instalar en el USB, y claro esta hay que disponer de un USB.<p>"

                   "<b>IMPORTANTE: Comprueba con sumo cuidadado que la unidad USB sea "
                   "la correcta.</b><p>"

                   "Para ello antes de realizar el proceso se accedera a los "
                   "discos para que no haya ningun tipo de duda y suele estar en la "
                   "ultima pesta&ntilde;a del diskdrake (fijate en el peso de la unidad).<p>"
                   "Es importante que tomes nota del nombre de cada unidad y compruebes "
                   "la capacidad para evitar sobresaltos.<p>"

                   "Este proceso puede tardar varios minutos.<p>"

                   "<FONT COLOR=\"RED\">Por ejemplo:<p>"
                   "<FONT COLOR=\"RED\">sdg (disco USB)<p>"

                   "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                   "el cual le sera notificado cuando finalice.</B><p>"

                   "&iquest;Crear USB-Live?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){
        system("diskdrake");
        QString path="/home/%1/Escritorio/";
        path=path.arg(user);

        QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Imagen .iso"),
                            path,trUtf8("Imagen iso (*.iso)"));
        if (fileNameOrigen.isEmpty())
            return;
        QString texto = QInputDialog::getText(this, tr("Disco Usb"),
            tr("Introduzca el nombre de disco <b>USB</B><p>"

            "<FONT COLOR=\"RED\">Ejemplo:<p>"

            "<FONT COLOR=\"RED\">sdg<p>"),
        QLineEdit::Normal,
        "",
        &ok);
        if (ok && !texto.isEmpty()){
        QString cmd = "dd if=%1 of=/dev/%2 bs=2M";
        cmd = cmd.arg(fileNameOrigen).arg(texto);
        QStringList comandos;
        comandos<< cmd;

        if (mib != 0)
            delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
    }
    return;
}

void recoverdrake::on_actionSalvaguardar_ficheros_de_recuperaci_n_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Backup ficheros de configuracion"),
                           tr("<center><b>Backup de ficheros de configuracion</b></center><p>"

                           "En el directorio /etc que cuelga de la raiz, tenemos todas "
                           "las configuraciones de nuestro equipo, tanto de usuarios, "
                           "como de discos duros y un largo etc. de procesos que no nos "
                           "gustaria perder, por lo que con esta utilidad, podemos "
                           "guardarlos para mas tarde poder disponer de ellos.<p>"

                           "Se guardan automaticamente los ficheros del directorio "
                           "/etc y todos sus subdirectorios sino se expecifica lo "
                           "contrario, ya que se puede elegir ficheros de configuracion "
                           "independientes.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Realizar Backup de configuracion?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "RecoverConf";

        QStringList comandos;
        comandos<< cmd;

        if (mib != 0)
        delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
}

void recoverdrake::on_actionRecuperar_ficheros_de_instalaci_n_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Restaurar ficheros de configuracion"),
                           tr("<center><b>Restaurar ficheros de configuracion<b></center><p>"

                           "Como su nombre indica, podemos restaurar los datos "
                           "anteriormente salvados a su ubicacion original "
                           "o destino marcado.<p>"

                           "<FONT COLOR=\"RED\">IMPORTANTE: Si el destino esta en la raiz "
                           "(/), se restaurara en la ubicacion original.<p>"

                           "Instalara todos los datos guardados, sobreescribiendo "
                           "los ya instalados, en el caso de existir.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Restaurar configuración?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/Documentos/";
            path=path.arg(user);
            QString path1="/";
            path1=path1.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir copia de seguridad"),
                                path,trUtf8("Fichero comprimido .taz.bz2 (*.tar.bz2)"));
            if (fileNameOrigen.isEmpty())
                return;

            QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Donde descomprimir?"),path1,QFileDialog::ShowDirsOnly);
            if (fileNameDirectori.isEmpty())
                return;

            QString cmd = "tar -xjvf %2 --directory=%3";
            cmd = cmd.arg(fileNameOrigen).arg(fileNameDirectori);

            QStringList comandos;
            comandos<< cmd;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionA_adir_KDE_inestable_triggered()
{
    int respuesta = 0;
    bool ok;
    respuesta = QMessageBox::question(this, tr("Probar KDE inestable"),
                           tr("<center><b>Probar KDE inestable<b></center><p>"

                              "Cuantas veces has querido instalar una version de kde "
                              "superior y no soportada por Mandriva y te ha dado miedo de "
                              "que no respondiera el equipo tras el reinicio.<p>"

                              "Pues para los que tenemos \"versionitis\" llega esta "
                              "aplicacion, donde se pueden probar versiones inestables, "
                              "sin morir en el intento.<P>"

                              "Tal como nos dice su descripcion, de esta manera incluimos "
                              "el mirror del repositorio donde estan los paquetes a "
                              "actualizar del nuevo KDE que haya en el momento.<p>"

                              "En la primera parte de este proceso, pondremos el nombre "
                              "con el que se identificara internamente el repositorio "
                              "en nuestro sistema.<p>"

                              "En la segunda parte del proceso, se introduce la direccion "
                              "ftp/html donde estan colgados los ficheros a actualizar.<p>"

                              "Introduzca <b>SOLO</b> el nombre con el que quieras que "
                              "sea identificado y la direccion de la web.<P>"

                              "<FONT COLOR=\"RED\">Ejemplo:<p>"

                              "<FONT COLOR=\"RED\">KDE_INESTABLE<p>"

                              "<FONT COLOR=\"RED\">ftp://ftp.kde.org/pub/kde/stable/4.5.0/Mandriva/2010.1/i586/<p>"

                              "<b><FONT COLOR=\"RED\">NUNCA</b> incluir la parte inicial que pone "
                              "<b>urpmi.addmedia</b> ni la parte final <b>with media_info/synthesis.hdlist.cz</b> "
                              "ya que esta parte, RecoverDrake, lo hace automaticamente.<p>"

                              "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                              "el cual le sera notificado cuando finalice.</B><p>"

                              "&iquest;Probar KDE inestable?"), QMessageBox::Ok, QMessageBox::No);

               if (respuesta == QMessageBox::Ok){
                          QString texto = QInputDialog::getText(this, tr("Nombre identificativo de KDE inestable"),
                          tr("Introduzca el nombre para identificar el repositorio.<P> "

                              "<FONT COLOR=\"RED\">Ejemplo:<p>"

                              "<FONT COLOR=\"RED\">KDE_INESTABLE"),
                              QLineEdit::Normal,
                              "",
                              &ok);
                              if (ok && !texto.isEmpty()){
                                    QString texto1 = QInputDialog::getText(this, tr("Instalacion manual de repositorios"),
                                          tr("Introduzca la direccion web<p>"

                                             "<FONT COLOR=\"RED\">Ejemplo:<p>"

                                             "<FONT COLOR=\"RED\">ftp://ftp.kde.org/pub/kde/stable/4.5.0/Mandriva/2010.1/i586/<p>"),
                                             QLineEdit::Normal,
                                             "",
                                             &ok);
                                   if (ok && !texto1.isEmpty()){
                                   QString cmd = "/bin/sh urpmi.addmedia %1 %2 with media_info/synthesis.hdlist.cz";
                                   cmd = cmd.arg(texto).arg(texto1);
                                   QStringList comandos;
                                   comandos<< cmd;

                                   if (mib != 0)
                                       delete mib;
                                   mib = new DrakeProcesos(comandos, this);
                                   connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                                   connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                                   mib->iniciarProceso();}
                           }
                   }
                   return;
}

void recoverdrake::on_actionActualizar_KDE_inestable_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;
    bool ok;
    respuesta = QMessageBox::question(this, tr("Actualizar KDE inestable"),
                           tr("<center><b>Actualizar KDE inestable<b></center><p>"

                              "Mediante esta opcion se hace una simulacion para "
                              "saber si habra problemas de compatibilidad o "
                              "errores apreciados.<p>"

                              "Tras la simulacion, comienza la instalacion si se "
                              "marca la casilla de \"si\"<p>"

                              "Introduzca el nombre con el que identifico el soporte<p>"

                              "<FONT COLOR=\"RED\">Ejemplo:<p>"

                              "<FONT COLOR=\"RED\">KDE_INESTABLE<p>"

                              "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                              "el cual le sera notificado cuando finalice.</B><p>"

                              "&iquest;Actualizar KDE inestable?"), QMessageBox::Ok, QMessageBox::No);

               if (respuesta == QMessageBox::Ok){
                          QString texto = QInputDialog::getText(this, tr("Nombre identificativo de KDE inestable"),
                          tr("Introduzca el nombre para identificar el repositorio.<P> "

                              "<FONT COLOR=\"RED\">Ejemplo:<p>"

                              "<FONT COLOR=\"RED\">KDE_INESTABLE"),
                              QLineEdit::Normal,
                              "",
                              &ok);
                              if (ok && !texto.isEmpty()){
                                   QString cmd = "/bin/sh urpmi --auto --auto-update --test --media %1";
                                   cmd = cmd.arg(texto);
                                   QStringList comandos;
                                   comandos<< cmd;

                                   if (mib != 0)
                                       delete mib;
                                   mib = new DrakeProcesos(comandos, this);
                                   connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                                   connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                                   mib->iniciarProceso();}
                                   respuesta1 = QMessageBox::question(this, tr("Actualizar KDE inestable"),
                                                tr("<center><b>Actualizar KDE inestable<b></center><p>"

                                                   "<FONT COLOR=\"BLUE\">ESPERAR A QUE TERMINE LA SIMULACION...<P>"

                                                   "<FONT COLOR=\"BLUE\">Por favor sea paciente...<p>"

                                                   "Si la simulacion ha resultado positiva, puede realizar "
                                                   "la instalacion de kde inestable.<p>"

                                                   "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                                                   "el cual le sera notificado cuando finalice.</B><p>"

                                                   "...proceder con la instalacion?"), QMessageBox::Ok, QMessageBox::No);

                                    if (respuesta1 == QMessageBox::Ok){
                                        QString cmd1 = "/bin/sh urpmi --auto --auto-select";
                                        QStringList comandos;
                                        comandos<< cmd1;
                                        if (mib != 0)
                                           delete mib;
                                        mib = new DrakeProcesos(comandos, this);
                                        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                                        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                                        mib->iniciarProceso();
                                    }
                                    return;
                   }
                   return;
}

void recoverdrake::on_actionDesinstalar_KDE_inestable_triggered()
{
    int respuesta = 0;
    bool ok;
    respuesta = QMessageBox::question(this, tr("Desinstalar KDE inestable"),
                           tr("<center><b>Desinstalar KDE inestable<b></center><p>"

                              "Si no nos convence la instalacion de la nueva version "
                              "de KDE, solo nos queda eliminar los paquetes nuevos que "
                              "se han instalado, eliminar el repositorio KDE4 que se ha "
                              "creado nuevamente y volver a instalar los paquetes que se "
                              "habian actualizado.<p>"

                              "DEBE eliminar el nombre del repositorio inestable para que "
                              "al eliminar y volver a actualizar no vuelva a coger los "
                              "paquetes actualizados.<p>"

                              "Con esta parte de la aplicacion, realizamos este proceso.<p>"

                              "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                              "el cual le sera notificado cuando finalice.</B><p>"

                              "&iquest;Desinstalar KDE inestable?"), QMessageBox::Ok, QMessageBox::No);

               if (respuesta == QMessageBox::Ok){
                          QString texto = QInputDialog::getText(this, tr("Nombre identificativo de KDE inestable"),
                          tr("Introduzca el nombre para identificar el repositorio.<P> "

                              "<FONT COLOR=\"RED\">Ejemplo:<p>"

                              "<FONT COLOR=\"RED\">KDE_INESTABLE"),
                              QLineEdit::Normal,
                              "",
                              &ok);
                              if (ok && !texto.isEmpty()){
                                   QString cmd = "echo Removiendo repositorio %1";
                                   QString cmd1 = "/bin/sh urpmi.removemedia %1";
                                   QString cmd2 = "echo Realizando desinstalacion de KDE...";
                                   QString cmd3 = "/bin/sh urpme -v --auto --force -a kde";
                                   QString cmd4 = "echo Continuando con la restauración de KDE...";
                                   QString cmd5 = "/bin/sh urpmi -a --auto --force task-kde4 task-kde4-minimal";
                                   QString cmd6 = "echo Revisando paquetes KDE sin instalar...";
                                   QString cmd7 = "/bin/sh urpmi -a --auto --force kde";
                                   cmd = cmd.arg(texto);
                                   cmd1 = cmd1.arg(texto);
                                   QStringList comandos;
                                   comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5 << cmd6 << cmd7;

                                   if (mib != 0)
                                       delete mib;
                                   mib = new DrakeProcesos(comandos, this);
                                   connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                                   connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                                   mib->iniciarProceso();}
                                   return;
                }
                return;
}

void recoverdrake::on_actionInstalar_paquete_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar paquetes"),
                               tr("<center><b>Instalar paquetes</b></center><p>"

                               "Accedemos a la instalacion de paquetes de forma "
                               "grafica, donde podemos elegir cualquier paquete "
                               "que este en los repositorios configurados.<p>"

                               "&iquest;Instalar paquetes?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString cmd = "rpmdrake";

                QStringList comandos;
                comandos<< cmd;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionKDE_2_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar Kde"),
                               tr("<center><b>Instalar Kde</b></center><p>"

                               "Uno de los escritorios mas potentes y el que "
                               "utiliza por defecto Mandriva.<p>"

                               "Debido a su calidad y robusted, se necesita de un "
                               "gran equipo para poder sacarle todo el rendimiento "
                               "de lo que es capaz.<p>"

                               "Tiene una gran comunidad muy activa, detras de este"
                               "maravillo escritorio, el cual ha sido copia en su "
                               "estilo por el inombrable 7.<p>"

                               "Altamente recomendable.<p>"

                               "<B>NOTA: Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Instalar KDE (Recomendado)?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString cmd = "/bin/sh urpmi -a --auto --force task-kde4 task-kde4-minimal";

                QStringList comandos;
                comandos<< cmd;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionGNOME_2_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar Gnome"),
                               tr("<center><b>Instalar Gnome</b></center><p>"

                               "Otros de los escritorios mas potentes y versatiles "
                               "que hay para Linux.<p>"

                               "Tambien es recomendable tenerlo instalado, ya que "
                               "nos puede sacar de algun apuro.<p>"

                               "<B>NOTA: Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Instalar Gnome (Recomendado)?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString cmd = "/bin/sh urpmi -a --auto --force task-gnome task-gnome-minimal";

                QStringList comandos;
                comandos<< cmd;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionE17_2_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar E17"),
                               tr("<center><b>Instalar E17</b></center><p>"

                               "Tambien conocido como Enlightenment, es un escritorio "
                               "que utiliza pocos recursos a la vez que muy atractivo "
                               "y versatil<p>"

                               "<B>NOTA: Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Instalar E17?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString cmd = "/bin/sh urpmi -a --auto --force task-e17 task-e17-minimal";

                QStringList comandos;
                comandos<< cmd;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionXFCE_2_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar Xfce"),
                               tr("<center><b>Instalar Xfce</b></center><p>"

                               "Personalmente este escritorio me gusta esteticamente, "
                               "pero he de reconocer que no es mi principal.<p>"

                               "Tiene un buen estilo, segun mi criterio, me recuerda "
                               "bastante al sistema Mac.<p>"

                               "<B>NOTA Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Instalar Xfce?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString cmd = "/bin/sh urpmi -a --auto --force task-xfce task-xfce-minimal task-xfce-plugins";

                QStringList comandos;
                comandos<< cmd;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionEDE_2_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar Ede"),
                               tr("<center><b>Instalar Ede</b></center><p>"

                               "Personalmente nunca lo he utilizado, pero como esta, lo "
                               "pongo.<p>"

                               "<B>NOTA: Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Instalar Ede?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString cmd = "/bin/sh urpmi -a --auto --force task-ede";

                QStringList comandos;
                comandos<< cmd;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionLXDE_2_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar Lxde"),
                               tr("<center><b>Instalar Lxde</b></center><p>"

                               "Basado en Kde, pero mucho mas sencillo y ocupa muchos "
                               "menos recursos.<p>"

                               "<B>NOTA: Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Instalar Lxde?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString cmd = "/bin/sh urpmi -a --auto --force task-lxde";

                QStringList comandos;
                comandos<< cmd;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionMOBLIN_2_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar Moblin"),
                               tr("<center><b>Instalar Moblin</b></center><p>"

                               "Es un escritorio orientado a notebook, por su sencillez, "
                               "ya que tienes todo lo que quieres a un simple click de "
                               "raton.<p>"

                               "<B>NOTA Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Instalar Moblin?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString cmd = "/bin/sh urpmi -a --auto --force task-moblin";

                QStringList comandos;
                comandos<< cmd;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionSUGAR_2_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar Sugar"),
                               tr("<center><b>Instalar Sugar</b></center><p>"

                               "Un escritorio basado en gtk, pero que tampoco lo he "
                               "utilizado, por lo que no puedo decir como es, pero "
                               "estar...esta.<p>"

                               "<B>NOTA: Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Instalar Sugar?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString cmd = "/bin/sh urpmi -a --auto --force task-sugar";

                QStringList comandos;
                comandos<< cmd;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionTodos_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar todos"),
                               tr("<center><b>Instalar todos los Escritorios</b></center><p>"

                               "Mediante esta opcion puedes instalar todos los escritorios "
                               "de forma masiva e incluye Kde, Gnome, E17, Xfce, Ede, Lxde, "
                               "Moblin y Sugar.<p>"

                               "Este proceso puede tardar bastante tiempo, por lo que debe ser "
                               "paciente.<p>"

                               "<B>NOTA: Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Instalar todos los escritorios?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString cmd = "/bin/sh urpmi -a --auto --force task-kde4 task-kde4-minimal";
                QString cmd1 = "/bin/sh urpmi -a --auto --force task-gnome task-gnome-minimal";
                QString cmd2 = "/bin/sh urpmi -a --auto --force task-e17 task-e17-minimal";
                QString cmd3 = "/bin/sh urpmi -a --auto --force task-xfce task-xfce-minimal task-xfce-plugins";
                QString cmd4 = "/bin/sh urpmi -a --auto --force task-ede";
                QString cmd5 = "/bin/sh urpmi -a --auto --force task-lxde";
                QString cmd6 = "/bin/sh urpmi -a --auto --force task-moblin";
                QString cmd7 = "/bin/sh urpmi -a --auto --force task-sugar";

                QStringList comandos;
                comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5 << cmd6 << cmd7;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionInstalar_drivers_de_impresoras_cups_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar drivers para impresoras (CUPS)"),
                               tr("<center><b>Instalar drivers para impresoras</b></center><p>"

                               "Para evitar cualquier conflicto de compatibilidad, instalaremos "
                               "todo lo necesario para poder disponer satisfactoriamente del "
                               "driver de nuestra impresora.<p>"

                               "<B>NOTA: Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString cmd = "/bin/sh urpmi --wget --auto task-printing";

                QStringList comandos;
                comandos<< cmd;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionCodecs_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar codecs audio/video"),
                               tr("<center><b>Instalar codecs audio/video</b></center><p>"

                               "Paquete de codecs para el sistema multimedia, incluidos "
                               "los de win32, por lo que se podra ver y oir videos, musica, "
                               "etc.<p>"

                               "<B>NOTA: Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Instalar codecs?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){


                QString cmd = "/bin/sh urpmi --wget -a --auto --force urpmi --wget --auto real-codecs win32-codecs xanim-codecs libquicktime libquicktime-x264 libquicktime-lame libquicktime-faad libquicktime-faac faad2 xine-faad faac libamrnb3 libamrwb3 amrnb amrwb";
                QString cmd1 = "/bin/sh urpmi --wget -a --force --auto lame gstreamer0.10-a52dec gstreamer0.10-amrnb gstreamer0.10-amrwb gstreamer0.10-faad gstreamer0.10-faac gstreamer0.10-ffmpeg mencoder gstreamer0.10-lame";
                QString cmd2 = "/bin/sh urpmi --wget -a --force --auto gstreamer0.10-flac gstreamer0.10-cdio gstreamer0.10-cdparanoia ffmpeg mencoder transcode gstreamer0.10-mms";

                QStringList comandos;
                comandos<< cmd << cmd1 << cmd2;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionInstalar_sopctas_qsopcast_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;

    respuesta = QMessageBox::question(this, tr("Instalar y configurar sopcast y qsopcast"),
                           tr("<center><b>Instalar y configurar sopcast y qsopcast<b></center><p>"

                           "Esta utilidad sirve para ver todo tipo de eventos, aunque se suele "
                           "utilizar para ver eventos deportivos, los cuales pueden ser de pago "
                           "en algunos paises y en otros son emitidos libremente y por canales "
                           "abiertos via internet y que por lo general son de origen Chino o "
                           "japones.<p>"

                           "<FONT COLOR=\"RED\">IMPORTANTE: En algunos paises, utilizar este tipo de software puede ser ilegal, "
                           "<FONT COLOR=\"RED\">consulte la legislacion vigente de su pais para saber si puede utilizar "
                           "<FONT COLOR=\"RED\">dicho software.<p>"

                           "Se instala sopcast y su \"gui\" qsopcast para modo grafico.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Instalar y configurar qsopcast?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                    respuesta1 = QMessageBox::question(this, tr("Licencia de uso"),
                                           tr("<center><b>Licencia (Idioma original)<b></center><p>"

                                           "<FONT COLOR=\"BLUE\">Terms of Service<p>"

                                           "<FONT COLOR=\"BLUE\">Nowadays, all the services on SopCast (sopcast.com) are totally free and only for test purpose. "
                                           "<FONT COLOR=\"BLUE\">Our client (P2P TV Player) and channel list can be copied and distributed freely for anyone. "
                                           "<FONT COLOR=\"BLUE\">Any portion of these may not be sold, resold, or otherwise exploited for any commercial purpose "
                                           "<FONT COLOR=\"BLUE\">that is not expressly permitted by SopCast. Some websites have been found selling the services "
                                           "<FONT COLOR=\"BLUE\">based on SopCast. Please immediately cease all such infringements.<p>"), QMessageBox::Ok, QMessageBox::No);
                    if (respuesta1 == QMessageBox::Ok){

                                QString cmd = "echo descomprimiendo ficheros...";
                                QString cmd1 = "tar xvzf /root/qsopcast.tar.gz --directory=/home/%1";
                                cmd1 = cmd1.arg(user);
                                QString cmd2 = "tar xvzf /root/sp-sc-auth.tar.gz --directory=/home/%1";
                                cmd2 = cmd2.arg(user);
                                QString cmd3 = "echo creando directorio...";
                                QString cmd4 = "cp /home/%1/sp-sc-auth /home/%1/.sopcast/";
                                cmd4 = cmd4.arg(user);
                                QString cmd5 = "echo Instalando paquete local...";
                                QString cmd6 = "urpmi /home/%1/qsopcast-0.3.1.rpm";
                                cmd6=cmd6.arg(user);
                                QString cmd7 = "ln -s /home/%1/.sopcast/sp-sc-auth /usr/local/bin/sopcast";
                                cmd7 = cmd7.arg(user);
                                QString cmd8 = "echo Borrando temporales...";
                                QString cmd9 = "rm -f /home/%1/sp-sc-auth";
                                cmd9 = cmd9.arg(user);
                                QString cmd10 = "rm -f /home/%1/qsopcast-0.3.1.rpm";
                                cmd10 = cmd10.arg(user);
                                QStringList comandos;
                                comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5 << cmd6 << cmd7 << cmd8 << cmd9 << cmd10;

                                if (mib != 0)
                                delete mib;
                                mib = new DrakeProcesos(comandos, this);
                                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                                mib->iniciarProceso();}
                                return;
                    }
                    return;
}

void recoverdrake::on_actionInstalar_drivers_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Instalar drivers con ndiswrapper"),
                           tr("<center><b>Instalar drivers con ndiswrapper<b></center><p>"

                           "Puede que nuestra red necesite de los drivers nativos de guindows,"
                           "por cualquier motivo, ya sea que no es reconocido el driver/modulo "
                           "de Linux o por errores en el mismo.<p>"

                           "La solucion pasa por instalar el fichero .ini y .sys de nuestro "
                           "sistema operativo del lado oscuro.<p>"

                           "<FONT COLOR=\"BLUE\">OBSERVACION: Comprueba que la ruta de origen no tenga signos raros "
                           "<FONT COLOR=\"BLUE\">o espacios entre nombres, porque generara un error de modulo.<p>"

                           "Ejemplo: ],[,},{,),(, /es una prueba/de error en/ruta/, etc.<p>"

                           "<FONT COLOR=\"BLUE\">Lo mas correcto es guardar el fichero .inf y .sys en el escritorio de "
                           "<FONT COLOR=\"BLUE\">Linux y asi no habra problemas de incompatibilidad.<p>"

                           "<FONT COLOR=\"RED\">AVISO: Va a utilizar un driver privativo en su sistema.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString path="/media/";

        QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir fichero .inf"),
                            path,trUtf8("Fichero información (*.inf);;Fichero sistema (*.sys)"));
        if (fileNameOrigen.isEmpty())
            return;
            QString fileName = fileNameOrigen.replace(" ", "\\ ");
            QString cmd = "echo Instalando modulo en el sistema...";
            QString cmd2= "ndiswrapper -i %1";
            cmd2= cmd2.arg(fileName);
            QString cmd1= "echo Probando modulo wifi...";
            QString cmd3= "ndiswrapper -l";
            QStringList comandos;
            comandos<< cmd <<cmd2 <<cmd1 <<cmd3;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionVer_modulo_instalado_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Comprobar modulo instalado"),
                           tr("<center><b>Comprobar modulo instalador<b></center><p>"

                           "Esta opcion solo sirve para saber el modulo instalado actual de "
                           "ndiswrapper en el caso de que exista.<p>"

                           "&iquest;Comprobar modulo?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Comprobando modulos instalados...";
            QString cmd1= "ndiswrapper -l";
            QStringList comandos;
            comandos<< cmd <<cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionBorrar_drivers_triggered()
{
    int respuesta = 0;
    bool ok;

    respuesta = QMessageBox::question(this, tr("Desinstalar drivers con ndiswrapper"),
                           tr("<center><b>Desinstalar drivers con ndiswrapper<b></center><p>"

                           "Por alguna razon tendremos la necesidad de eliminar un modulo "
                           "cargado anteriormente con ndiswrapper.<p>"

                           "Ejecutando esta opcion se desinstalara dicho modulo.<p>"

                           "Antes de realizar el proceso, en la consola le informara de los drivers "
                           "ndiswrapper que hay instalado en su sistema, por lo que solo tendra "
                           "que poner el nombre (Alias), para poder desinstalarlo.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Desinstalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Comprobando modulos instalados...";
            QString cmd1= "ndiswrapper -l";
            QStringList comandos;
            comandos<< cmd <<cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
                QString texto = QInputDialog::getText(this, tr("Nombre de modulo ndiswrapper"),
                tr("Introduzca el nombre del modulo que aparece en la consola.<P> "

                    "<FONT COLOR=\"RED\">Ejemplo:<p>"

                    "<FONT COLOR=\"RED\">rt61"),
                    QLineEdit::Normal,
                    "",
                    &ok);
                    if (ok && !texto.isEmpty()){
                        QString cmd2 = "echo Desinstalando modulo instalado...";
                        QString cmd3= "ndiswrapper -r %1";
                        cmd3=cmd3.arg(texto);
                        QStringList comandos;
                        comandos<< cmd2 <<cmd3;

                        if (mib != 0)
                        delete mib;
                        mib = new DrakeProcesos(comandos, this);
                        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                        mib->iniciarProceso();}
                        return;
}

void recoverdrake::on_actionMadwifi_2_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;

    respuesta = QMessageBox::question(this, tr("Instalar drivers Madwifi"),
                           tr("<center><b>Instalar drivers Madwifi<b></center><p>"

                           "Drivers Madwifi para redes inalambricas de los modelos "
                           "Atheros©.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                respuesta1 = QMessageBox::question(this, tr("Licencia de uso"),
                                       tr("<center><b>Licencia GPL<b></center><p>"

                                       "<FONT COLOR=\"BLUE\">La Licencia Publica General de GNU o "
                                       "<FONT COLOR=\"BLUE\">mas conocida por su nombre en ingles GNU General Public "
                                       "<FONT COLOR=\"BLUE\">License o simplemente sus siglas del ingles GNU GPL, es una "
                                       "<FONT COLOR=\"BLUE\">licencia creada por la Free Software Foundation en 1989 "
                                       "<FONT COLOR=\"BLUE\">(la primera version), y esta orientada principalmente a "
                                       "<FONT COLOR=\"BLUE\">proteger la libre distribucion, modificacion y uso de software.<p>"
                                       "<FONT COLOR=\"BLUE\">Su proposito es declarar que el software cubierto por esta "
                                       "<FONT COLOR=\"BLUE\">licencia es software libre y protegerlo de intentos de "
                                       "<FONT COLOR=\"BLUE\">apropiacion que restrinjan esas libertades a los usuarios.<p>"), QMessageBox::Ok, QMessageBox::No);

                if (respuesta1 == QMessageBox::Ok){

                            QString cmd = "echo descomprimiendo ficheros...";
                            QString cmd1 = "tar xvzf /root/wifi-firmware.tar.gz --directory=/home/%1 madwifi.rpm";
                            cmd1 = cmd1.arg(user);
                            QString cmd2 = "echo Instalando paquete local...";
                            QString cmd3 = "urpmi /home/%1/madwifi.rpm";
                            cmd3=cmd3.arg(user);
                            QString cmd4 = "echo Borrando temporales...";
                            QString cmd5 = "rm -f /home/%1/madwifi.rpm";
                            cmd5 = cmd5.arg(user);
                            QStringList comandos;
                            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5;

                            if (mib != 0)
                            delete mib;
                            mib = new DrakeProcesos(comandos, this);
                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                            mib->iniciarProceso();}
                            return;
                }
                return;
}

void recoverdrake::on_actionRT2860_2_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;

    respuesta = QMessageBox::question(this, tr("Instalar drivers RT2860"),
                           tr("<center><b>Instalar drivers RT2860<b></center><p>"

                           "Drivers RT2860 para redes inalambricas de los modelos "
                           "Railink©.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                respuesta1 = QMessageBox::question(this, tr("Licencia de uso"),
                                       tr("<center><b>Licencia (Version original)<b></center><p>"

                                       "<FONT COLOR=\"BLUE\">Copyright (c) 2007, Ralink Technology Corporation<p>"
                                       "<FONT COLOR=\"BLUE\">All rights reserved.<p>"

                                       "<FONT COLOR=\"BLUE\">Redistribution.  Redistribution and use in binary form, without modification, are permitted provided that the following conditions are "
                                       "<FONT COLOR=\"BLUE\">met:<p>"

                                       "<FONT COLOR=\"BLUE\">* Redistributions must reproduce the above copyright notice and the following disclaimer in the documentation and/or other materials "
                                       "<FONT COLOR=\"BLUE\">provided with the distribution.<p>"
                                       "<FONT COLOR=\"BLUE\">* Neither the name of Ralink Technology Corporation nor the names of its suppliers may be used to endorse or promote products derived from this "
                                       "<FONT COLOR=\"BLUE\">software without specific prior written permission.<p>"
                                       "<FONT COLOR=\"BLUE\">* No reverse engineering, decompilation, or disassembly of this software is permitted.<p>"

                                       "<FONT COLOR=\"BLUE\">Limited patent license. Ralink Technology Corporation grants a world-wide, royalty-free, non-exclusive license under patents it now or hereafter "
                                       "<FONT COLOR=\"BLUE\">owns or controls to make, have made, use, import, offer to sell and sell (\"Utilize\") this software, but solely to the extent that any "
                                       "<FONT COLOR=\"BLUE\">such patent is necessary to Utilize the software alone, or in combination with an operating system licensed under an approved Open "
                                       "<FONT COLOR=\"BLUE\">Source license as listed by the Open Source Initiative at http://opensource.org/licenses.  The patent license shall not apply to "
                                       "<FONT COLOR=\"BLUE\">any other combinations which include this software.  No hardware per se is licensed hereunder.<p>"

                                       "<FONT COLOR=\"BLUE\">DISCLAIMER.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, "
                                       "<FONT COLOR=\"BLUE\">BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE "
                                       "<FONT COLOR=\"BLUE\">COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, "
                                       "<FONT COLOR=\"BLUE\">BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND "
                                       "<FONT COLOR=\"BLUE\">ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE "
                                       "<FONT COLOR=\"BLUE\">USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.<p>"), QMessageBox::Ok, QMessageBox::No);

                if (respuesta1 == QMessageBox::Ok){

                            QString cmd = "echo descomprimiendo ficheros...";
                            QString cmd1 = "tar xvzf /root/wifi-firmware.tar.gz --directory=/home/%1 rt2860-firmware.rpm";
                            cmd1 = cmd1.arg(user);
                            QString cmd2 = "echo Instalando paquete local...";
                            QString cmd3 = "urpmi /home/%1/rt2860-firmware.rpm";
                            cmd3=cmd3.arg(user);
                            QString cmd4 = "echo Borrando temporales...";
                            QString cmd5 = "rm -f /home/%1/rt2860-firmware.rpm";
                            cmd5 = cmd5.arg(user);
                            QStringList comandos;
                            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5;

                            if (mib != 0)
                            delete mib;
                            mib = new DrakeProcesos(comandos, this);
                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                            mib->iniciarProceso();}
                            return;
                }
                return;
}

void recoverdrake::on_actionRT2870_2_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;

    respuesta = QMessageBox::question(this, tr("Instalar drivers RT2870"),
                           tr("<center><b>Instalar drivers RT2870<b></center><p>"

                           "Drivers RT2870 para redes inalambricas de los modelos "
                           "Railink©.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                respuesta1 = QMessageBox::question(this, tr("Licencia de uso"),
                                       tr("<center><b>Licencia (Version original)<b></center><p>"

                                       "<FONT COLOR=\"BLUE\">Copyright (c) 2007, Ralink Technology Corporation<p>"
                                       "<FONT COLOR=\"BLUE\">All rights reserved.<p>"

                                       "<FONT COLOR=\"BLUE\">Redistribution.  Redistribution and use in binary form, without modification, are permitted provided that the following conditions are "
                                       "<FONT COLOR=\"BLUE\">met:<p>"

                                       "<FONT COLOR=\"BLUE\">* Redistributions must reproduce the above copyright notice and the following disclaimer in the documentation and/or other materials "
                                       "<FONT COLOR=\"BLUE\">provided with the distribution.<p>"
                                       "<FONT COLOR=\"BLUE\">* Neither the name of Ralink Technology Corporation nor the names of its suppliers may be used to endorse or promote products derived from this "
                                       "<FONT COLOR=\"BLUE\">software without specific prior written permission.<p>"
                                       "<FONT COLOR=\"BLUE\">* No reverse engineering, decompilation, or disassembly of this software is permitted.<p>"

                                       "<FONT COLOR=\"BLUE\">Limited patent license. Ralink Technology Corporation grants a world-wide, royalty-free, non-exclusive license under patents it now or hereafter "
                                       "<FONT COLOR=\"BLUE\">owns or controls to make, have made, use, import, offer to sell and sell (\"Utilize\") this software, but solely to the extent that any "
                                       "<FONT COLOR=\"BLUE\">such patent is necessary to Utilize the software alone, or in combination with an operating system licensed under an approved Open "
                                       "<FONT COLOR=\"BLUE\">Source license as listed by the Open Source Initiative at http://opensource.org/licenses.  The patent license shall not apply to "
                                       "<FONT COLOR=\"BLUE\">any other combinations which include this software.  No hardware per se is licensed hereunder.<p>"

                                       "<FONT COLOR=\"BLUE\">DISCLAIMER.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, "
                                       "<FONT COLOR=\"BLUE\">BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE "
                                       "<FONT COLOR=\"BLUE\">COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, "
                                       "<FONT COLOR=\"BLUE\">BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND "
                                       "<FONT COLOR=\"BLUE\">ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE "
                                       "<FONT COLOR=\"BLUE\">USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.<p>"), QMessageBox::Ok, QMessageBox::No);

                if (respuesta1 == QMessageBox::Ok){

                            QString cmd = "echo descomprimiendo ficheros...";
                            QString cmd1 = "tar xvzf /root/wifi-firmware.tar.gz --directory=/home/%1 rt2870-firmware.rpm";
                            cmd1 = cmd1.arg(user);
                            QString cmd2 = "echo Instalando paquete local...";
                            QString cmd3 = "urpmi /home/%1/rt2870-firmware.rpm";
                            cmd3=cmd3.arg(user);
                            QString cmd4 = "echo Borrando temporales...";
                            QString cmd5 = "rm -f /home/%1/rt2870-firmware.rpm";
                            cmd5 = cmd5.arg(user);
                            QStringList comandos;
                            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5;

                            if (mib != 0)
                            delete mib;
                            mib = new DrakeProcesos(comandos, this);
                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                            mib->iniciarProceso();}
                            return;
                }
                return;
}

void recoverdrake::on_actionRT3090_2_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;

    respuesta = QMessageBox::question(this, tr("Instalar drivers RT3090"),
                           tr("<center><b>Instalar drivers RT3090<b></center><p>"

                           "Drivers RT3090 para redes inalambricas de los modelos "
                           "Railink©.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                respuesta1 = QMessageBox::question(this, tr("Licencia de uso"),
                                       tr("<center><b>Licencia (Version original)<b></center><p>"

                                       "<FONT COLOR=\"BLUE\">Copyright (c) 2007, Ralink Technology Corporation<p>"
                                       "<FONT COLOR=\"BLUE\">All rights reserved.<p>"

                                       "<FONT COLOR=\"BLUE\">Redistribution.  Redistribution and use in binary form, without modification, are permitted provided that the following conditions are "
                                       "<FONT COLOR=\"BLUE\">met:<p>"

                                       "<FONT COLOR=\"BLUE\">* Redistributions must reproduce the above copyright notice and the following disclaimer in the documentation and/or other materials "
                                       "<FONT COLOR=\"BLUE\">provided with the distribution.<p>"
                                       "<FONT COLOR=\"BLUE\">* Neither the name of Ralink Technology Corporation nor the names of its suppliers may be used to endorse or promote products derived from this "
                                       "<FONT COLOR=\"BLUE\">software without specific prior written permission.<p>"
                                       "<FONT COLOR=\"BLUE\">* No reverse engineering, decompilation, or disassembly of this software is permitted.<p>"

                                       "<FONT COLOR=\"BLUE\">Limited patent license. Ralink Technology Corporation grants a world-wide, royalty-free, non-exclusive license under patents it now or hereafter "
                                       "<FONT COLOR=\"BLUE\">owns or controls to make, have made, use, import, offer to sell and sell (\"Utilize\") this software, but solely to the extent that any "
                                       "<FONT COLOR=\"BLUE\">such patent is necessary to Utilize the software alone, or in combination with an operating system licensed under an approved Open "
                                       "<FONT COLOR=\"BLUE\">Source license as listed by the Open Source Initiative at http://opensource.org/licenses.  The patent license shall not apply to "
                                       "<FONT COLOR=\"BLUE\">any other combinations which include this software.  No hardware per se is licensed hereunder.<p>"

                                       "<FONT COLOR=\"BLUE\">DISCLAIMER.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, "
                                       "<FONT COLOR=\"BLUE\">BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE "
                                       "<FONT COLOR=\"BLUE\">COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, "
                                       "<FONT COLOR=\"BLUE\">BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND "
                                       "<FONT COLOR=\"BLUE\">ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE "
                                       "<FONT COLOR=\"BLUE\">USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.<p>"), QMessageBox::Ok, QMessageBox::No);

                if (respuesta1 == QMessageBox::Ok){

                            QString cmd = "echo descomprimiendo ficheros...";
                            QString cmd1 = "tar xvzf /root/wifi-firmware.tar.gz --directory=/home/%1 rt3090-firmware.rpm";
                            cmd1 = cmd1.arg(user);
                            QString cmd2 = "echo Instalando paquete local...";
                            QString cmd3 = "urpmi /home/%1/rt3090-firmware.rpm";
                            cmd3=cmd3.arg(user);
                            QString cmd4 = "echo Borrando temporales...";
                            QString cmd5 = "rm -f /home/%1/rt3090-firmware.rpm";
                            cmd5 = cmd5.arg(user);
                            QStringList comandos;
                            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5;

                            if (mib != 0)
                            delete mib;
                            mib = new DrakeProcesos(comandos, this);
                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                            mib->iniciarProceso();}
                            return;
                }
                return;
}

void recoverdrake::on_action61_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;

    respuesta = QMessageBox::question(this, tr("Instalar drivers RT61"),
                           tr("<center><b>Instalar drivers RT61<b></center><p>"

                           "Drivers RT61 para redes inalambricas de los modelos "
                           "Railink©.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                respuesta1 = QMessageBox::question(this, tr("Licencia de uso"),
                                       tr("<center><b>Licencia (Version original)<b></center><p>"

                                       "<FONT COLOR=\"BLUE\">Copyright (c) 2007, Ralink Technology Corporation<p>"
                                       "<FONT COLOR=\"BLUE\">All rights reserved.<p>"

                                       "<FONT COLOR=\"BLUE\">Redistribution.  Redistribution and use in binary form, without modification, are permitted provided that the following conditions are "
                                       "<FONT COLOR=\"BLUE\">met:<p>"

                                       "<FONT COLOR=\"BLUE\">* Redistributions must reproduce the above copyright notice and the following disclaimer in the documentation and/or other materials "
                                       "<FONT COLOR=\"BLUE\">provided with the distribution.<p>"
                                       "<FONT COLOR=\"BLUE\">* Neither the name of Ralink Technology Corporation nor the names of its suppliers may be used to endorse or promote products derived from this "
                                       "<FONT COLOR=\"BLUE\">software without specific prior written permission.<p>"
                                       "<FONT COLOR=\"BLUE\">* No reverse engineering, decompilation, or disassembly of this software is permitted.<p>"

                                       "<FONT COLOR=\"BLUE\">Limited patent license. Ralink Technology Corporation grants a world-wide, royalty-free, non-exclusive license under patents it now or hereafter "
                                       "<FONT COLOR=\"BLUE\">owns or controls to make, have made, use, import, offer to sell and sell (\"Utilize\") this software, but solely to the extent that any "
                                       "<FONT COLOR=\"BLUE\">such patent is necessary to Utilize the software alone, or in combination with an operating system licensed under an approved Open "
                                       "<FONT COLOR=\"BLUE\">Source license as listed by the Open Source Initiative at http://opensource.org/licenses.  The patent license shall not apply to "
                                       "<FONT COLOR=\"BLUE\">any other combinations which include this software.  No hardware per se is licensed hereunder.<p>"

                                       "<FONT COLOR=\"BLUE\">DISCLAIMER.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, "
                                       "<FONT COLOR=\"BLUE\">BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE "
                                       "<FONT COLOR=\"BLUE\">COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, "
                                       "<FONT COLOR=\"BLUE\">BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND "
                                       "<FONT COLOR=\"BLUE\">ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE "
                                       "<FONT COLOR=\"BLUE\">USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.<p>"), QMessageBox::Ok, QMessageBox::No);

                if (respuesta1 == QMessageBox::Ok){

                            QString cmd = "echo descomprimiendo ficheros...";
                            QString cmd1 = "tar xvzf /root/wifi-firmware.tar.gz --directory=/home/%1 rt61-firmware.rpm";
                            cmd1 = cmd1.arg(user);
                            QString cmd2 = "echo Instalando paquete local...";
                            QString cmd3 = "urpmi /home/%1/rt61-firmware.rpm";
                            cmd3=cmd3.arg(user);
                            QString cmd4 = "echo Borrando temporales...";
                            QString cmd5 = "rm -f /home/%1/rt61-firmware.rpm";
                            cmd5 = cmd5.arg(user);
                            QStringList comandos;
                            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5;

                            if (mib != 0)
                            delete mib;
                            mib = new DrakeProcesos(comandos, this);
                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                            mib->iniciarProceso();}
                            return;
                }
                return;
}

void recoverdrake::on_actionRT73_2_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;

    respuesta = QMessageBox::question(this, tr("Instalar drivers RT73"),
                           tr("<center><b>Instalar drivers RT73<b></center><p>"

                           "Drivers RT73 para redes inalambricas de los modelos "
                           "Railink©.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                respuesta1 = QMessageBox::question(this, tr("Licencia de uso"),
                                       tr("<center><b>Licencia (Version original)<b></center><p>"

                                       "<FONT COLOR=\"BLUE\">Copyright (c) 2007, Ralink Technology Corporation<p>"
                                       "<FONT COLOR=\"BLUE\">All rights reserved.<p>"

                                       "<FONT COLOR=\"BLUE\">Redistribution.  Redistribution and use in binary form, without modification, are permitted provided that the following conditions are "
                                       "<FONT COLOR=\"BLUE\">met:<p>"

                                       "<FONT COLOR=\"BLUE\">* Redistributions must reproduce the above copyright notice and the following disclaimer in the documentation and/or other materials "
                                       "<FONT COLOR=\"BLUE\">provided with the distribution.<p>"
                                       "<FONT COLOR=\"BLUE\">* Neither the name of Ralink Technology Corporation nor the names of its suppliers may be used to endorse or promote products derived from this "
                                       "<FONT COLOR=\"BLUE\">software without specific prior written permission.<p>"
                                       "<FONT COLOR=\"BLUE\">* No reverse engineering, decompilation, or disassembly of this software is permitted.<p>"

                                       "<FONT COLOR=\"BLUE\">Limited patent license. Ralink Technology Corporation grants a world-wide, royalty-free, non-exclusive license under patents it now or hereafter "
                                       "<FONT COLOR=\"BLUE\">owns or controls to make, have made, use, import, offer to sell and sell (\"Utilize\") this software, but solely to the extent that any "
                                       "<FONT COLOR=\"BLUE\">such patent is necessary to Utilize the software alone, or in combination with an operating system licensed under an approved Open "
                                       "<FONT COLOR=\"BLUE\">Source license as listed by the Open Source Initiative at http://opensource.org/licenses.  The patent license shall not apply to "
                                       "<FONT COLOR=\"BLUE\">any other combinations which include this software.  No hardware per se is licensed hereunder.<p>"

                                       "<FONT COLOR=\"BLUE\">DISCLAIMER.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, "
                                       "<FONT COLOR=\"BLUE\">BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE "
                                       "<FONT COLOR=\"BLUE\">COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, "
                                       "<FONT COLOR=\"BLUE\">BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND "
                                       "<FONT COLOR=\"BLUE\">ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE "
                                       "<FONT COLOR=\"BLUE\">USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.<p>"), QMessageBox::Ok, QMessageBox::No);

                if (respuesta1 == QMessageBox::Ok){

                            QString cmd = "echo descomprimiendo ficheros...";
                            QString cmd1 = "tar xvzf /root/wifi-firmware.tar.gz --directory=/home/%1 rt73-firmware.rpm";
                            cmd1 = cmd1.arg(user);
                            QString cmd2 = "echo Instalando paquete local...";
                            QString cmd3 = "urpmi /home/%1/rt73-firmware.rpm";
                            cmd3=cmd3.arg(user);
                            QString cmd4 = "echo Borrando temporales...";
                            QString cmd5 = "rm -f /home/%1/rt73-firmware.rpm";
                            cmd5 = cmd5.arg(user);
                            QStringList comandos;
                            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5;

                            if (mib != 0)
                            delete mib;
                            mib = new DrakeProcesos(comandos, this);
                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                            mib->iniciarProceso();}
                            return;
                }
                return;
}

void recoverdrake::on_actionAtmel_2_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;

    respuesta = QMessageBox::question(this, tr("Instalar drivers Atmel"),
                           tr("<center><b>Instalar drivers Atmel<b></center><p>"

                           "Drivers Atmel para redes inalambricas de los modelos "
                           "Atmel©.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                respuesta1 = QMessageBox::question(this, tr("Licencia de uso"),
                                       tr("<center><b>Licencia (Version original)<b></center><p>"

                                       "<FONT COLOR=\"BLUE\">Copyright (c) 2004 Atmel Corporation. All Rights Reserved.<p>"
                                       "<FONT COLOR=\"BLUE\">Redistribution and use of the microcode software ( Firmware ) is "
                                       "<FONT COLOR=\"BLUE\">permitted provided that the following conditions are met:<p>"

                                       "<FONT COLOR=\"BLUE\">1. Firmware is redistributed in object code only;<p>"
                                       "<FONT COLOR=\"BLUE\">2. Any reproduction of Firmware must contain the above "
                                       "<FONT COLOR=\"BLUE\">copyright notice, this list of conditions and the below "
                                       "<FONT COLOR=\"BLUE\">disclaimer in the documentation and/or other materials "
                                       "<FONT COLOR=\"BLUE\">provided with the distribution; and<p>"
                                       "<FONT COLOR=\"BLUE\">3. The name of Atmel Corporation may not be used to endorse "
                                       "<FONT COLOR=\"BLUE\">or promote products derived from this Firmware without specific "
                                       "<FONT COLOR=\"BLUE\">prior written consent.<p>"

                                       "<FONT COLOR=\"BLUE\">DISCLAIMER: ATMEL PROVIDES THIS FIRMWARE  \"AS IS\" WITH NO WARRANTIES OR "
                                       "<FONT COLOR=\"BLUE\">INDEMNITIES WHATSOEVER. ATMEL EXPRESSLY DISCLAIMS ANY EXPRESS, STATUTORY "
                                       "<FONT COLOR=\"BLUE\">OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED "
                                       "<FONT COLOR=\"BLUE\">WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND "
                                       "<FONT COLOR=\"BLUE\">NON-INFRINGEMENT. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, "
                                       "<FONT COLOR=\"BLUE\">INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES "
                                       "<FONT COLOR=\"BLUE\">(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR "
                                       "<FONT COLOR=\"BLUE\">SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) "
                                       "<FONT COLOR=\"BLUE\">HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, "
                                       "<FONT COLOR=\"BLUE\">STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN "
                                       "<FONT COLOR=\"BLUE\">ANY WAY OUT OF THE USE OF THIS FIRMWARE, EVEN IF ADVISED OF THE "
                                       "<FONT COLOR=\"BLUE\">POSSIBILITY OF SUCH DAMAGE. USER ACKNOWLEDGES AND AGREES THAT THE "
                                       "<FONT COLOR=\"BLUE\">PURCHASE OR USE OF THE FIRMWARE WILL NOT CREATE OR GIVE GROUNDS FOR A "
                                       "<FONT COLOR=\"BLUE\">LICENSE BY IMPLICATION, ESTOPPEL, OR OTHERWISE IN ANY INTELLECTUAL "
                                       "<FONT COLOR=\"BLUE\">PROPERTY RIGHTS (PATENT, COPYRIGHT, TRADE SECRET, MASK WORK, OR OTHER "
                                       "<FONT COLOR=\"BLUE\">PROPRIETARY RIGHT) EMBODIED IN ANY OTHER ATMEL HARDWARE OR FIRMWARE.<p>"), QMessageBox::Ok, QMessageBox::No);

                if (respuesta1 == QMessageBox::Ok){

                            QString cmd = "echo descomprimiendo ficheros...";
                            QString cmd1 = "tar xvzf /root/wifi-firmware.tar.gz --directory=/home/%1 atmel-firmware.rpm";
                            cmd1 = cmd1.arg(user);
                            QString cmd2 = "echo Instalando paquete local...";
                            QString cmd3 = "urpmi /home/%1/atmel-firmware.rpm";
                            cmd3=cmd3.arg(user);
                            QString cmd4 = "echo Borrando temporales...";
                            QString cmd5 = "rm -f /home/%1/atmel-firmware.rpm";
                            cmd5 = cmd5.arg(user);
                            QStringList comandos;
                            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5;

                            if (mib != 0)
                            delete mib;
                            mib = new DrakeProcesos(comandos, this);
                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                            mib->iniciarProceso();}
                            return;
                }
                return;
}

void recoverdrake::on_actionBcm43xx_fwcutter_2_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;

    respuesta = QMessageBox::question(this, tr("Instalar drivers Bcm43xx_fwcutter"),
                           tr("<center><b>Instalar drivers Bcm43xx_fwcutter<b></center><p>"

                           "Drivers Bcm43xx para redes inalambricas de los modelos "
                           "Broadcom©.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                respuesta1 = QMessageBox::question(this, tr("Licencia de uso"),
                                       tr("<center><b>Licencia (Version original)<b></center><p>"

                                       "<FONT COLOR=\"BLUE\">This program is free software; you can redistribute it and/or modify "
                                       "<FONT COLOR=\"BLUE\">it under the terms of the GNU General Public License as published by "
                                       "<FONT COLOR=\"BLUE\">the Free Software Foundation; either version 2 of the License, or (at "
                                       "<FONT COLOR=\"BLUE\">your option) any later version.<p>"), QMessageBox::Ok, QMessageBox::No);

                if (respuesta1 == QMessageBox::Ok){

                            QString cmd = "echo descomprimiendo ficheros...";
                            QString cmd1 = "tar xvzf /root/wifi-firmware.tar.gz --directory=/home/%1 bcm43xx-fwcutter.rpm";
                            cmd1 = cmd1.arg(user);
                            QString cmd2 = "echo Instalando paquete local...";
                            QString cmd3 = "urpmi /home/%1/bcm43xx-fwcutter.rpm";
                            cmd3=cmd3.arg(user);
                            QString cmd4 = "echo Borrando temporales...";
                            QString cmd5 = "rm -f /home/%1/bcm43xx-fwcutter.rpm";
                            cmd5 = cmd5.arg(user);
                            QStringList comandos;
                            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5;

                            if (mib != 0)
                            delete mib;
                            mib = new DrakeProcesos(comandos, this);
                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                            mib->iniciarProceso();}
                            return;
                }
                return;
}

void recoverdrake::on_actionB43_fwcutter_2_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;

    respuesta = QMessageBox::question(this, tr("Instalar drivers b43_fwcutter"),
                           tr("<center><b>Instalar drivers b43xx_fwcutter<b></center><p>"

                           "Drivers b43xx para redes inalambricas de los modelos "
                           "Broadcom©. Puede ser la solucion para cuando falla el "
                           "driver bcm43xx.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                respuesta1 = QMessageBox::question(this, tr("Licencia de uso"),
                                       tr("<center><b>Licencia (Version original)<b></center><p>"

                                       "<FONT COLOR=\"BLUE\">This program is free software; you can redistribute it and/or modify "
                                       "<FONT COLOR=\"BLUE\">it under the terms of the GNU General Public License as published by "
                                       "<FONT COLOR=\"BLUE\">the Free Software Foundation; either version 2 of the License, or (at "
                                       "<FONT COLOR=\"BLUE\">your option) any later version.<p>"), QMessageBox::Ok, QMessageBox::No);

                if (respuesta1 == QMessageBox::Ok){

                            QString cmd = "echo descomprimiendo ficheros...";
                            QString cmd1 = "tar xvzf /root/wifi-firmware.tar.gz --directory=/home/%1 b43-fwcutter.rpm";
                            cmd1 = cmd1.arg(user);
                            QString cmd2 = "echo Instalando paquete local...";
                            QString cmd3 = "urpmi /home/%1/b43-fwcutter.rpm";
                            cmd3=cmd3.arg(user);
                            QString cmd4 = "echo Borrando temporales...";
                            QString cmd5 = "rm -f /home/%1/b43-fwcutter.rpm";
                            cmd5 = cmd5.arg(user);
                            QStringList comandos;
                            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5;

                            if (mib != 0)
                            delete mib;
                            mib = new DrakeProcesos(comandos, this);
                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                            mib->iniciarProceso();}
                            return;
                }
                return;
}

void recoverdrake::on_actionIpw2100_2_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;

    respuesta = QMessageBox::question(this, tr("Instalar drivers ipw3945d"),
                           tr("<center><b>Instalar drivers ipw3945d<b></center><p>"

                           "Drivers ipw3945 para redes inalambricas de los modelos "
                           "Intel©<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                respuesta1 = QMessageBox::question(this, tr("Licencia de uso"),
                                       tr("<center><b>Licencia (Version original)<b></center><p>"

                                       "<FONT COLOR=\"BLUE\">Copyright (c) 2006, Intel Corporation.<p>"
                                       "<FONT COLOR=\"BLUE\">All rights reserved.<p>"

                                       "<FONT COLOR=\"BLUE\">Redistribution.  Redistribution and use in binary form, without "
                                       "<FONT COLOR=\"BLUE\">modification, are permitted provided that the following conditions are "
                                       "<FONT COLOR=\"BLUE\">met:<p>"

                                       "<FONT COLOR=\"BLUE\">* Redistributions must reproduce the above copyright notice and the "
                                       "<FONT COLOR=\"BLUE\">following disclaimer in the documentation and/or other materials "
                                       "<FONT COLOR=\"BLUE\">provided with the distribution.<p>"
                                       "<FONT COLOR=\"BLUE\">* Neither the name of Intel Corporation nor the names of its suppliers "
                                       "<FONT COLOR=\"BLUE\">may be used to endorse or promote products derived from this software "
                                       "<FONT COLOR=\"BLUE\">without specific prior written permission.<p>"
                                       "<FONT COLOR=\"BLUE\">* No reverse engineering, decompilation, or disassembly of this software "
                                       "<FONT COLOR=\"BLUE\">is permitted.<p>"

                                       "<FONT COLOR=\"BLUE\">Limited patent license.  Intel Corporation grants a world-wide, "
                                       "<FONT COLOR=\"BLUE\">royalty-free, non-exclusive license under patents it now or hereafter "
                                       "<FONT COLOR=\"BLUE\">owns or controls to make, have made, use, import, offer to sell and "
                                       "<FONT COLOR=\"BLUE\">sell (\"Utilize\") this software, but solely to the extent that any "
                                       "<FONT COLOR=\"BLUE\">such patent is necessary to Utilize the software alone, or in "
                                       "<FONT COLOR=\"BLUE\">combination with an operating system licensed under an approved Open "
                                       "Source license as listed by the Open Source Initiative at "
                                       "<FONT COLOR=\"BLUE\">http://opensource.org/licenses.  The patent license shall not apply to "
                                       "<FONT COLOR=\"BLUE\">any other combinations which include this software.  No hardware per "
                                       "<FONT COLOR=\"BLUE\">se is licensed hereunder.<p>"

                                       "<FONT COLOR=\"BLUE\">DISCLAIMER.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND "
                                       "<FONT COLOR=\"BLUE\">CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, "
                                       "<FONT COLOR=\"BLUE\">BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND "
                                       "<FONT COLOR=\"BLUE\">FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE "
                                       "<FONT COLOR=\"BLUE\">COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, "
                                       "<FONT COLOR=\"BLUE\">INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, "
                                       "<FONT COLOR=\"BLUE\">BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS "
                                       "<FONT COLOR=\"BLUE\">OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND "
                                       "<FONT COLOR=\"BLUE\">ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR "
                                       "<FONT COLOR=\"BLUE\">TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE "
                                       "<FONT COLOR=\"BLUE\">USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH "
                                       "<FONT COLOR=\"BLUE\">DAMAGE.<p>"), QMessageBox::Ok, QMessageBox::No);

                if (respuesta1 == QMessageBox::Ok){

                            QString cmd = "echo descomprimiendo ficheros...";
                            QString cmd1 = "tar xvzf /root/wifi-firmware.tar.gz --directory=/home/%1 ipw3945d.rpm";
                            cmd1 = cmd1.arg(user);
                            QString cmd2 = "echo Instalando paquete local...";
                            QString cmd3 = "urpmi /home/%1/ipw3945d.rpm";
                            cmd3=cmd3.arg(user);
                            QString cmd4 = "echo Borrando temporales...";
                            QString cmd5 = "rm -f /home/%1/ipw3945d.rpm";
                            cmd5 = cmd5.arg(user);
                            QStringList comandos;
                            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5;

                            if (mib != 0)
                            delete mib;
                            mib = new DrakeProcesos(comandos, this);
                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                            mib->iniciarProceso();}
                            return;
                }
                return;
}

void recoverdrake::on_actionConvertir_caracteres_especiales_a_UTF8_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir caracteres especiales a UTF8"),
                           tr("<center><b>Convertir caracteres especiales a UTF8<b></center><p>"

                           "En algunas ocasiones intentamos renombrar o borrar algun "
                           "fichero y nos es imposible hacerlo, debido a su codificacion, "
                           "ya que aparecen caracteres raros en dicho nombre.<p>"

                           "La solucion pasa por ejecutar esta funcion y se queda solucionado "
                           "y a partir de hay, podras hacer lo que quieras con dicho fichero.<p>"

                           "El problema parece ser que es debido a algunos archivos generados "
                           "en el sistema operativo \"guindows\".<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir caracteres a UTF8?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString path="/home/%1/Documentos/";
        path=path.arg(user);

        QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio a corregir UTF8?"),path,QFileDialog::ShowDirsOnly);
        if (fileNameDirectori.isEmpty())
            return;

            QString cmd = "/bin/sh RecoverConvert %2";
            cmd = cmd.arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionSustituir_espacios_en_blanco_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Sustituir espacios en blanco"),
                           tr("<center><b>Sustituir espacios en blanco<b></center><p>"

                           "Mediante esta utilidad, conseguimo las sustitucion "
                           "de los espacios en blanco de los nombres de archivos "
                           "que nos pueden dar errores al ejecutarlos o modificarlos.<p>"

                           "SOLO se realizara la conversion de ficheros sobre el directorio "
                           "que se ha marcado, no sobre los subdirectorios para no realizar "
                           "operaciones que puedan dañar directorios.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Sustituir espacios en blanco?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "RecoverRename";
            QStringList comandos;
            comandos<< cmd;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionRpm_database_bloqued_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Desbloquear base de datos de uprmi"),
                           tr("<center><b>Desbloquear base de datos de urpmi<b></center><p>"

                           "El mensaje es conocido como \"RPM database bloqued\".<p>"

                           "En alguna ocasion puede pasar, que por alguna razon "
                           "la base de datos de urmpi se quede trabada o bloqueada, "
                           "por lo que es necesario desbloquearla o no se podra utilizar.<p>"

                           "Mediante esta utilidad se soluciona dicho problema.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Desbloquear base de datos urpmi?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Eliminando ficheros bloqueados...";
            QString cmd1 = "killall urpmi urpmi.update urpme rpm urpmi.addmedia";
            QString cmd2 ="rm -f /var/lib/urpmi/.LOCK /var/lib/rpm/RPMLOCK";
            QString cmd3 ="echo Base de dastos de uprmi desbloqueada.";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd2 << cmd3;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionIdioma_espa_ol_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Cambiar idioma a espa&ntilde;ol"),
                           tr("<center><b>Cambiar idioma a espa&ntilde;ol<b></center><p>"

                           "A veces puede pasar que al reinstalar KDE, perdamos la "
                           "configuracion en espa&ntilde;ol y todos los menus nos salgan "
                           "en ingles.<p>"

                           "Mediante esta utilidad se soluciona dicho problema.<p>"

                           "<FONT COLOR=\"BLUE\">ImPORTANTE: Para que el proceso tenga efecto, debe cerrar "
                           "<FONT COLOR=\"BLUE\">la sesion actual, tras la instalacion del "
                           "paquete instalado.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Cambiar idioma a espa&ntilde;ol?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "/bin/sh urpmi -a --auto kde-l10n-es";
            QStringList comandos;
            comandos<< cmd;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionSolucionar_kdeinit4_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Solucionar fallo kdeinit4"),
                           tr("<center><b>Solucionar fallo kdeinit4<b></center><p>"

                           "Al intentar entrar en KDE, puede que nos de este error y no "
                           "podamos acceder a nuestro escritorio favorito.<p>"

                           "Este error es debido a la configuracion de algun plasma de "
                           "escritorio, por lo que la solucion pasa por volver a configurar "
                           "el estilo visual de kde.<p>"

                           "<b>IMPORTANTE: Realizando este proceso, el escritorio volvera a su "
                           "estado inicial, para evitar el error.<p>"

                           "<b>Es importante que comprenda que su configuracion personal "
                           "desaparecera y tendra que volver a configurar de nuevo su escritorio.<p>"

                           "Se realiza una copia del directorio oculto para poder recuperar, si es "
                           "necesario, denominado \".kde4Backup\".<p>"

                           "Si quiere recuperar su configuracion solo tendra que utilizar (Recuperar "
                           "configuracion) de este mismo submenu.<p>"

                           "<b>No olvide reiniciar sesion para que los cambios tengan efecto.<p></b>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Solucionar kdeinit4?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Realizando backup del fichero responsable del error...";
            QString cmd1 = "mkdir /home/%1/.kde4Backup/";
            cmd1=cmd1.arg(user);
            QString cmd2 = "cp -R /home/%1/.kde4/ /home/%1/.kde4Backup/";
            cmd2=cmd2.arg(user);
            QString cmd3 = "echo Borrando fichero responsable del error...";
            QString cmd4 = "rm -rf /home/%1/.kde4/share/config/";
            cmd4=cmd4.arg(user);
            QString cmd5 = "chown -R %1 /home/%1/.kde4Backup/";
            cmd5=cmd5.arg(user);
            QString cmd6 = "chgrp -R %1 /home/%1/.kde4Backup/";
            cmd6=cmd6.arg(user);
            QString cmd7 = "echo Proceso de reconstruccion realizado.";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5 << cmd6 << cmd7;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionRecuperar_configuraci_n_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Recuperar configuracion"),
                           tr("<center><b>Recuperar configuracion<b></center><p>"

                           "Mediante este proceso, vuelve a recuperar al estado anterior la configuracion "
                           "de su kde.<p>"

                           "<b>IMPORTANTE</b>: Si realiza este proceso, puede que su kde, vuelva al estado "
                           "anterior a su problema, por lo que no habra hecho nada.<p>"

                           "No olvide reiniciar sesion para que los cambios tengan efecto.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Recuperar configuracion?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Realizando la recuperacion de configuracion...";
            QString cmd1 = "cp -r /home/%1/.kde4Backup/.kde4/ /home/%1/";
            cmd1=cmd1.arg(user);
            QString cmd3 = "chown -R %1 /home/%1/.kde4/";
            cmd3=cmd3.arg(user);
            QString cmd4 = "chgrp -R %1 /home/%1/.kde4/";
            cmd4=cmd4.arg(user);
            QString cmd5 = "echo Proceso de reconfiguracion realizado.";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd3 << cmd4 << cmd5;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionRecuperar_KDE_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Recuperar KDE"),
                           tr("<center><b>Recuperar KDE<b></center><p>"

                           "Por diversos motivos KDE puede desestabilizarse o simplemente no "
                           "ejecutarse por diversos motivos.<p>"

                           "<b>IMPORTANTE: Realizando este proceso, el escritorio volvera a su "
                           "estado inicial, para evitar loss errores.<p>"

                           "<b>Es importante que comprenda que su configuracion personal "
                           "desaparecera y tendra que volver a configurar de nuevo su escritorio.<p>"

                           "Se realiza una copia del directorio oculto para poder recuperar, si es "
                           "necesario, denominado \".kde4Backup\".<p>"

                           "Si quiere recuperar su configuracion solo tendra que utilizar (Recuperar "
                           "configuracion) de este mismo submenu.<p>"

                           "<b>No olvide reiniciar sesion para que los cambios tengan efecto.<p></b>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Recuperar KDE?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Realizando backup del fichero responsable del error...";
            QString cmd1 = "mkdir /home/%1/.kde4Backup/";
            cmd1=cmd1.arg(user);
            QString cmd2 = "cp -R /home/%1/.kde4/ /home/%1/.kde4Backup/";
            cmd2=cmd2.arg(user);
            QString cmd3 = "echo Borrando fichero responsable del error...";
            QString cmd4 = "rm -rf /home/%1/.kde4/";
            cmd4=cmd4.arg(user);
            QString cmd5 = "chown -R %1 /home/%1/.kde4Backup/";
            cmd5=cmd5.arg(user);
            QString cmd6 = "chgrp -R %1 /home/%1/.kde4Backup/";
            cmd6=cmd6.arg(user);
            QString cmd7 = "echo Proceso de reconstruccion realizado.";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 << cmd5 << cmd6 << cmd7;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionRecuperar_configuraci_n_anterior_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Recuperar configuracion anterior"),
                           tr("<center><b>Recuperar configuracion anterior<b></center><p>"

                           "Mediante este proceso, vuelve a recuperar al estado anterior la configuracion "
                           "de su kde.<p>"

                           "<b>IMPORTANTE</b>: Si realiza este proceso, puede que su kde, vuelva al estado "
                           "anterior a su problema, por lo que no habra hecho nada.<p>"

                           "No olvide reiniciar sesion para que los cambios tengan efecto.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Recuperar configuracion anterior?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Realizando la recuperacion de configuracion...";
            QString cmd1 = "cp -r /home/%1/.kde4Backup/.kde4/ /home/%1/";
            cmd1=cmd1.arg(user);
            QString cmd3 = "chown -R %1 /home/%1/.kde4/";
            cmd3=cmd3.arg(user);
            QString cmd4 = "chgrp -R %1 /home/%1/.kde4/";
            cmd4=cmd4.arg(user);
            QString cmd5 = "echo Proceso de reconfiguracion realizado.";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd3 << cmd4 << cmd5;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionAdobe_reader_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Adobe Reader"),
                           tr("<center><b>Adober Reader<b></center><p>"

                           "Al navegar con firefox y quere abrir un fichero de tipo "
                           ".pdf, podemos tener el problema de que no lo lea por no "
                           "tener instaldo el Reader, con esta opcion se soluciona "
                           "el problema.<p>"

                           "<b>IMPORTANTE</b>: Va a instalar un paquete privativo en "
                           "su sistema.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Solucionar Adobe Reader?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/Documentos/AdobeReader_esp-8.1.7-1.i486.rpm";
            path=path.arg(user);

            QString fileNameDestino = QFileDialog::getSaveFileName(this,tr("Salvar fichero AdobeReader"),
                                path,tr("Fichero RPM (*.rpm)"));
            if (fileNameDestino.isEmpty())
                return;

                QString cmd = "echo Descargando desde el servidor en modo consola...";
                QString cmd1 = "wget http://ardownload.adobe.com/pub/adobe/reader/unix/8.x/8.1.7/esp/AdobeReader_esp-8.1.7-1.i486.rpm -O /%2";
                cmd1=cmd1.arg(fileNameDestino);
                QString cmd3 = "urpmi %2";
                cmd3=cmd3.arg(fileNameDestino);
                QString cmd4 = "rm -f %2";
                cmd4=cmd4.arg(fileNameDestino);
                QString cmd5 = "echo Proceso de instalacion realizado.";
                QStringList comandos;
                comandos<< cmd << cmd1 << cmd3 << cmd4 << cmd5;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
}

void recoverdrake::on_actionDolphin_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Error de Dolphin con vista previa"),
                           tr("<center><b>Error de Dolphin con vista previa<b></center><p>"

                           "Por algun motivo, al abrir Dolphin y tener videos en "
                           "la carpeta contenedora, puede generar que se ralentize "
                           "el equipo, cuando ejecuta la vista previa.<p>"

                           "La solucion es instalar este script que ira matando los "
                           "procesos relacionados con kio_thumbnail.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Solucionar Dolphin?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "RecoverDolphin";

        QStringList comandos;
        comandos<< cmd;

        if (mib != 0)
        delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
}

void recoverdrake::on_actionRecuperar_contrase_a_usuario_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Recuperar contrase&ntilde;a de usuario"),
                           tr("<center><b>Recuperar contrase&ntilde;a de usuario<b></center><p>"

                           "A veces puede ocurrir que, por algun motivo, olvidemos "
                           "alguna de las contrase&ntilde;as de nuestro sistema, por lo "
                           "que con esta opcion es facil de recuperar.<p>"

                           "La contrase&ntilde;a root no tiene sentido en este apartado, "
                           "ya que si has llegado hasta aqui, es por que la sabes, "
                           "aunque explico como hacerlo de manera informativa:<p>"

                           "<B>RECUPERAR CONTRASE&ntilde;A ROOT<P>"

                           "<B>Lo primero a hacer es reiniciar la maquina, ya en Grub "
                           "<B>hay que colocarse sobre la opcion de Linux y pulsar (e) "
                           "<B>luego colocarse sobre la opcion (kernel) y pulsar (e), "
                           "<B>separa con un espacio el texto subsecuente, escribimos "
                           "<B>(single) y presionamos enter.<p>"

                           "<B>Despues pulsa (b) para iniciar el sistema, al entrar en "
                           "<B>modo terminal tenemos la cuenta root, por lo que solo "
                           "<B>necesitamos cambiar la contrase&ntilde;a con el comando:<p> "

                           "<B>passwd root<p>"

                           "<B>y despues reinicia el sistema para que surtan efecto los "
                           "<B>cambios mediante el comando (reboot).<p>"

                           "<B>NOTA: Este proceso se realiza en la consola que se abre "
                           "<B>junto a RecoverDrake, al inicio de la ejecución, ya que "
                           "<b>es necesaria para poder ejecutarse correctamente.<p>"
                           "<b>EN DICHA CONSOLA SE DEBE INTRODUCIR EL NUEVO PASSWORD DOS VECES.<p>"

                           "&iquest;Recuperar contrase&ntilde;a?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok)
                {
                system("RecoverPswd");
                }
        return;
}

void recoverdrake::on_actionKTTSD_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("KTTSD no se esta ejecutando"),
                           tr("<center><b>KTTSD no se esta ejecutando<b></center><p>"

                           "Por algun motivo las nuevas versiones de kttsd y de "
                           "jovie hacen que no funcione el lector de voces festival, "
                           "lanzando un mensaje de que no se esta ejecutando KTTSD.<p>"
                     
                           "La solucion pasa por utilizar esta utilidad.<p>"
                           
                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Configurar KTTSD?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "RecoverKTTSD";

        QStringList comandos;
        comandos<< cmd;

        if (mib != 0)
        delete mib;
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib->iniciarProceso();}
        return;
}

void recoverdrake::on_actionVirtualBox_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Configurar VirtualBox"),
                           tr("<center><b>Configurar VirtualBox<b></center><p>"

                           "Cuando queremos ejecutar VirtualBox, es posible "
                           "que lance un mensaje de que no se puede ejecutar "
                           "y tengamos que configurarlo a la vez que prepararlo "
                           "para proximos kernel.<p>"

                           "Esta funcion hace esa labor, creando una nueva "
                           "configuracion para su funcionamiento y por otro "
                           "lado, haciendo que se pueda compilar con futuro "
                           "kernels (nucleos)<p>"

                           "Es tan valido para version OSE como para Oracle.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Configurar Virtualbox?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "echo Descargando paquetes necesarios e instalando...";
        QString cmd1 = "urpmi --auto -a dkms-virtualbox virtualbox-kernel-%1 virtualbox-kernel-%1-latest";
        cmd1 = cmd1.arg(Tip);
        QString cmd2 = "echo Configurando vboxdrv";
        if ( Vir == "vboxdrv")
            {
            QString cmd3 = "sudo /etc/init.d/vboxdrv setup";
            QString cmd4 = "echo VirtualBox configurado.";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4;
            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();
            }
        else
            {
            QString cmd3 = "echo Nada que configurar en vboxdrv";
            QString cmd4 = "echo VirtualBox configurado.";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4;
            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();
            }
        }
        return;
}

void recoverdrake::on_actionExcluir_paquete_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Excluir paquete a actualizar"),
                           tr("<center><b>Excluir paquete a actualizar<b></center><p>"

                           "A veces, hay paquetes que no se actualizan de forma "
                           "correcta o fallan las dependencias y siempre "
                           "aparecen para actualizar aunque no pueden ser "
                           "instalados, por lo que es preciso excluirlos de "
                           "las actualizaciones.<p>"

                           "Con esta utilidad, se puede hacer con el simple "
                           "hecho de introducir su nombre simple.<p>"

                           "<FONT COLOR=\"BLUE\">Ejemplo: rhythmbox<p>"

                           "Si por lo contrario quiere excluir un nombre y "
                           "todas sus variantes, debe introducirlo de la "
                           "siguiente manera...<p>"

                           "<FONT COLOR=\"BLUE\">Ejemplo: /^rhythmbox/<p>"

                           "<b>Tal cual se muestra con las barras / y el signo ^<p>"

                           "&iquest;Excluir paquete?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

             QString cmd= "RecoverExclu";
             QStringList comandos;
             comandos<< cmd;

             if (mib != 0)
             delete mib;
             mib = new DrakeProcesos(comandos, this);
             connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
             connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
             mib->iniciarProceso();}
             return;
}

void recoverdrake::on_actionRecuperar_paquete_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Recuperar paquete excluido"),
                           tr("<center><b>Recuperar paquete excluido<b></center><p>"

                           "Puede que quieras recuperar la actualizacion "
                           "de un paquete en particular, por lo que con "
                           "solo poner su nombre se volvera a activar.<p>"

                           "Con esta utilidad, se puede hacer con el simple "
                           "hecho de introducir su nombre simple.<p>"

                           "<FONT COLOR=\"BLUE\">Ejemplo: rhythmbox<p>"

                           "Si por lo contrario quiere recuperar un nombre y "
                           "todas sus variantes, debe introducirlo de la "
                           "siguiente manera...<p>"

                           "<FONT COLOR=\"BLUE\">Ejemplo: /^rhythmbox/<p>"

                           "<b>Tal cual se muestra con las barras / y el signo ^<p>"

                           "&iquest;Recuperar paquete excluido?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                         QString cmd = "RecoverInclu";
                         QStringList comandos;
                         comandos<< cmd;

                         if (mib != 0)
                             delete mib;
                         mib = new DrakeProcesos(comandos, this);
                         connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                         connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                         mib->iniciarProceso();}
                         return;                 
}

void recoverdrake::on_actionVaciar_fichero_de_exclusiones_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Vaciar fichero de exclusiones"),
                           tr("<center><b>Vaciar fichero de exclusiones<b></center><p>"

                           "Se procedera a la reconstruccion total del "
                           "fichero de exclusiones, si esta seguro de "
                           "que es lo que quiere hacer, marque ok, si "
                           "duda marque no.<p>"

                           "<b>NOTA: Todos los ficheros excluidos seran "
                           "<b>restaurados. PROCEDA CON PRECAUCION.<p>"

                           "&iquest;Reconstruir fichero de exclusiones?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                         QString cmd = "RecoverRest";
                         QStringList comandos;
                         comandos<< cmd;

                         if (mib != 0)
                             delete mib;
                         mib = new DrakeProcesos(comandos, this);
                         connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                         connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                         mib->iniciarProceso();}
                         return;
}

void recoverdrake::on_actionAplicar_permisos_masivos_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Aplicar permisos a unidades NTFS"),
                           tr("<center><b>Aplicar permisos a unidades NTFS<b></center><p>"

                           "Se ha apreciado un error en las unidades NTFS, en el que "
                           "despues de escribir en ellas, aparece el mensaje:<p>"

                           "No se pudieron cambiar los permisos...<p>"

                           "no siendo problematico es bastante molesto y mas si "
                           "estas pasando varios archivos a la vez, ya que en "
                           "cada una de los archivos aparecera dicho mensaje.<p>"

                           "Se generara un fichero denominado fstab.bak con la "
                           "configuracion anterior en la ruta /etc/fstab.bak, por lo "
                           "que en el caso de inestabilidad, solo tendria que ser "
                           "renombrado por /etc/fstab y volveria a su estado original, "
                           "dicho proceso se realiza automaticamente con la otra opcion "
                           "del menu NTFS<P>"

                           "&iquest;Aplicar permisos a NTFS?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                         QString cmd = "RecoverNTFS";
                         QStringList comandos;
                         comandos<< cmd;

                         if (mib != 0)
                             delete mib;
                         mib = new DrakeProcesos(comandos, this);
                         connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                         connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                         mib->iniciarProceso();}
                         return;
}

void recoverdrake::on_actionRecuperar_fstab_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Recuperar fichero fstab"),
                           tr("<center><b>Recuperar fichero fstab<b></center><p>"

                           "Si has notado cualquier inestabilidad al realizar el "
                           "proceso de configuracion de NTFS, debe utilizar esta "
                           "opcion ya que recuperara la configuracion anterior.<p>"

                           "Ten en cuenta que si lo haces, todos los permisos "
                           "otorgados, se habran perdido.<p>"

                           "&iquest;Recuperar configuracion fstab?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                         QString cmd = "echo Restaurando fichero fstab...";
                         QString cmd1 = "mv -f /etc/fstab.bak /etc/fstab";
                         QString cmd2 = "echo Restauracion realizada satisfactoriamente.";
                         QStringList comandos;
                         comandos<< cmd << cmd1 << cmd2;

                         if (mib != 0)
                             delete mib;
                         mib = new DrakeProcesos(comandos, this);
                         connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                         connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                         mib->iniciarProceso();}
                         return;
}

void recoverdrake::on_actionRecuperar_ficheros_directorios_borrados_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Recuperar ficheros de directorios borrados"),
                           tr("<center><b>Recuperar ficheros de directorios borrados<b></center><p>"

                           "Por error o responsablemente se pueden borrar archivos o directorios "
                           "que lamentablemente no queriamos borrar y queremos recuperarlos.<p>"

                           "Lo mas importante es no sobreescribir el disco por que los inodos del "
                           "borrado siguen estando activos.<p>"

                           "Esta es una utilidad para realizar eso y mas ya que se puede recuperar "
                           "incluso particiones corruptas.<p>"

                           "Este proceso puede ser efectivo o no, ya que depende de muchos factores, "
                           "ya que los datos unas veces se recuperan correctamente y otras no.<p>"

                           "Y no olvides de la importancia de hacer una copia de tu datos mas preciados.<p>"

                           "Siga los pasos que le iran dando para poder realizar de una forma optima "
                           "la recuperacion.<p>"

                           "&iquest;Intentar la recuperacion de ficheros borrados?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                         system ("echo Intentando la recuperacion...");
                         system("photorec");
                         QString cmd1 = "echo Recuperacion terminada.";
                         QStringList comandos;
                         comandos<< cmd1;

                         if (mib != 0)
                             delete mib;
                         mib = new DrakeProcesos(comandos, this);
                         connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                         connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                         mib->iniciarProceso();}
                         return;
}

void recoverdrake::on_actionWifi_intermitente_WEB_WPA_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Wifi intermitente encriptada WEB/WPA"),
                           tr("<center><b>Wifi intermitente encriptada WEB/WPA<b></center><p>"

                           "Este opcion pretende que la wifi, cuando esta fallida, "
                           "y no para de desactivarse, hace que fuerze, cada minuto, "
                           "su ejecucion de manera automatica, si esta activo.<p>"

                           "Este version solo funciona con encriptaciones tipo WEB/WPA.<p>"

                           "&iquest;Habilitar Wifi intermitente?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                         QString cmd1 = "RecoverWifiWep";
                         QStringList comandos;
                         comandos<< cmd1;

                         if (mib != 0)
                             delete mib;
                         mib = new DrakeProcesos(comandos, this);
                         connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                         connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                         mib->iniciarProceso();}
                         return;
}

void recoverdrake::on_actionWifi_intermitente_abierta_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Wifi intermitente abierta"),
                           tr("<center><b>Wifi intermitente abierta<b></center><p>"

                           "Este opcion pretende que la wifi, cuando esta fallida, "
                           "y no para de desactivarse, hace que fuerze, cada minuto, "
                           "su ejecucion de manera automatica, si esta activo.<p>"

                           "Este version solo funciona sin encriptaciones.<p>"

                           "&iquest;Habilitar Wifi intermitente?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                         QString cmd1 = "RecoverWifi";
                         QStringList comandos;
                         comandos<< cmd1;

                         if (mib != 0)
                             delete mib;
                         mib = new DrakeProcesos(comandos, this);
                         connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                         connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                         mib->iniciarProceso();}
                         return;
}

void recoverdrake::on_actionNo_se_pueden_ejecutar_opciones_de_Sudo_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("No se puede ejecutar sudo con el usuario activo"),
                           tr("<center><b>No se puede ejecutar sudo con el usuario activo<b></center><p>"

                           "Este opcion soluciona los problemas de permisos con el "
                           "comando \"sudo\", ya que introduce el usuario para no "
                           "tener problemas de permisos.<p>"

                           "&iquest;Introducir usuario en /etc/sudoers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

                         QString cmd1 = "RecoverSudo";
                         QStringList comandos;
                         comandos<< cmd1;

                         if (mib != 0)
                             delete mib;
                         mib = new DrakeProcesos(comandos, this);
                         connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                         connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                         mib->iniciarProceso();}
                         return;
}

void recoverdrake::on_actionConvertir_deb_a_rpm_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Convertir .deb a .rpm"),
                               tr("<center><b>Convertir .deb a .rpm<b></center><p>"

                               "Es posible que necesitemos convertir ficheros de tipo "
                               ".deb a .rpm, por que no se encuentra el paquete "
                               "correspondiente en nuestra distribucion favorita.<p>"

                               "Con esta utilidad es posible hacerlo.<P>"

                               "<B>NOTA Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice.</B><p>"

                               "&iquest;Convertir .deb a .rpm?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString path="/home/%1/";
                path=path.arg(user);

                QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .deb"),
                                    path,trUtf8("Archivo .deb (*.deb)"));
                if (fileNameOrigen.isEmpty())
                    return;

                QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Donde guardar el fichero .rpm?"),path,QFileDialog::ShowDirsOnly);
                if (fileNameDirectori.isEmpty())
                    return;

                QString cmd = "alien -r -c %2";
                cmd = cmd.arg(fileNameOrigen);
                system("mv /home/'"+user+"'/*.rpm '"+fileNameDirectori+"'");
                QString cmd1 ="echo Archivo ubicado correctamente.";
                QStringList comandos;
                comandos<< cmd << cmd1;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;

}

void recoverdrake::on_actionExtraer_audio_a_un_video_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Extraer audio de un video"),
                           tr("<center><b>Extraer audio de un video<b></center><p>"

                           "Con esta utilidad puedes extraer un audio de un video "
                           "y dejar el video resultante sin audio.<p>"

                           "Se creara un fichero con el audio en mp3.<p>"
                           "Se creara un fichero con el video.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.avi<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Extraer audio de video?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString fileNameOrigen1;
            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo de video"),
                                path,trUtf8("Archivos de video (*.avi *.mpg *.flv *.wmv)"));
            fileNameOrigen1 = fileNameOrigen;
            QString fileNameOrigenMod = fileNameOrigen.replace(".avi",".mp3");
            QString fileNameOrigenMod1 = fileNameOrigen.replace(".mpg",".mp3");
            QString fileNameOrigenMod2 = fileNameOrigen.replace(".flv",".mp3");
            QString fileNameOrigenMod3 = fileNameOrigen.replace(".wmv",".mp3");

            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero de video"),
                                path,trUtf8("Archivos de video (*.avi *.mpg *.flv *.wmv)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString info="ffmpeg -i %2";
            QString cmd ="ffmpeg -i %2 -y %3";
            cmd=cmd.arg(fileNameOrigen1).arg(fileNameOrigenMod3);
            QString cmd1 = "ffmpeg -i %2 -vcodec copy -an -y %3";
            cmd1=cmd1.arg(fileNameOrigen1).arg(fileNameDirectori);
            QStringList comandos;
            comandos<<info << cmd << cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionIncluir_audio_a_un_video_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("A&ntilde;adir audio a un video"),
                           tr("<center><b>A&ntilde;adir audio a un video<b></center><p>"

                           "Con esta utilidad puedes A&ntilde;adir audio a un video.<p>"

                           "Se creara un fichero final con el nuevo video.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.avi<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;A&ntilde;adir audio a video?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo de video"),
                                path,trUtf8("Archivos de video (*.avi *.mpg *.flv *.wmv)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameOrigen1 = QFileDialog::getOpenFileName(this,tr("Abrir archivo de audio"),
                                path,trUtf8("Archivos de audio (*.mp3 *.ac3 *.wma *.wav)"));
            if (fileNameOrigen1.isEmpty())
                 return;

            QString fileNameDestino = QFileDialog::getSaveFileName(this,tr("Guardar el fichero de video"),
                                path,trUtf8("Archivos de video (*.avi *.mpg *.flv *.wmv)"));
            if (fileNameDestino.isEmpty())
                 return;

            QString cmd ="ffmpeg -i %2 -i %3 -sameq -y %4";
            cmd=cmd.arg(fileNameOrigen1).arg(fileNameOrigen).arg(fileNameDestino);
            QStringList comandos;
            comandos<< cmd;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionMp3_wma_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mp3 a .wma"),
                           tr("<center><b>Convertir formato .mp3 a .wma<b></center><p>"

                           "Conversion de .mp3 a .wma<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.wma<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mp3"),
                                path,trUtf8("Archivo .mp3 (*.mp3)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wma?"),
                                path,trUtf8("Archivo .wma (*.wma)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -ab 192k -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionMp3_wav_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mp3 a .wav"),
                           tr("<center><b>Convertir formato .mp3 a .wav<b></center><p>"

                           "Conversion de .mp3 a .wav<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.wav<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mp3"),
                                path,trUtf8("Archivo .mp3 (*.mp3)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wav?"),
                                path,trUtf8("Archivo .wav (*.wav)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -ab 192k -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionMp3_ac3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mp3 a .ac3"),
                           tr("<center><b>Convertir formato .mp3 a .ac3<b></center><p>"

                           "Conversion de .mp3 a .ac3<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.ac3<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mp3"),
                                path,trUtf8("Archivo .mp3 (*.mp3)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .ac3?"),
                                path,trUtf8("Archivo .ac3 (*.ac3)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -ab 192k -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionWma_mp3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wma a .mp3"),
                           tr("<center><b>Convertir formato .wma a .mp3<b></center><p>"

                           "Conversion de .wma a .mp3<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.mp3<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wma"),
                                path,trUtf8("Archivo .wma (*.wma)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mp3?"),
                                path,trUtf8("Archivo .mp3 (*.mp3)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -ab 192k -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionWma_wav_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wma a .wav"),
                           tr("<center><b>Convertir formato .wma a .wav<b></center><p>"

                           "Conversion de .wma a .wav<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.wav<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wma"),
                                path,trUtf8("Archivo .wma (*.wma)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wav?"),
                                path,trUtf8("Archivo .wav (*.wav)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -ab 192k -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionWma_ac3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wma a .ac3"),
                           tr("<center><b>Convertir formato .wma a .ac3<b></center><p>"

                           "Conversion de .wma a .ac3<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.ac3<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wma"),
                                path,trUtf8("Archivo .wma (*.wma)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wav?"),
                                path,trUtf8("Archivo .ac3 (*.ac3)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -ab 192k -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionCda_mp3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .cda a .mp3"),
                           tr("<center><b>Convertir formato .cda a .mp3<b></center><p>"

                           "Esta utilidad sirve para poder ripear un CD original "
                           "y transformarlo para poder ser oido en tu equipo o en "
                           "cualquier soporte que reproduzca mp3.<p>"

                           "<B>AVISO:Debe introducir el CD original en la unidad para poder "
                           "<b>utilizar esta funcion antes de ejecutarla."

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Ripeando CD...";
            QString cmd1 = "cdparanoia -vsZB";
            QString cmd2 = "echo Moviendo y convirtiendo a destino selecionado...";
            QString cmd3 = "RecoverMovemp3";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd2 << cmd3;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionCda_wma_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .cda a .wma"),
                           tr("<center><b>Convertir formato .cda a .wma<b></center><p>"

                           "Esta utilidad sirve para poder ripear un CD original "
                           "y transformarlo para poder ser oido en tu equipo o en "
                           "cualquier soporte que reproduzca wma.<p>"

                           "<B>AVISO:Debe introducir el CD original en la unidad para poder "
                           "<b>utilizar esta funcion antes de ejecutarla."

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Ripeando CD...";
            QString cmd1 = "cdparanoia -vsZB";
            QString cmd2 = "echo Moviendo y convirtiendo a destino selecionado...";
            QString cmd3 = "RecoverMovewma";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd2 << cmd3;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionCda_wav_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .cda a .wav"),
                           tr("<center><b>Convertir formato .cda a .wav<b></center><p>"

                           "Esta utilidad sirve para poder ripear un CD original "
                           "y transformarlo para poder ser oido en tu equipo o en "
                           "cualquier soporte que reproduzca wav.<p>"

                           "<B>AVISO:Debe introducir el CD original en la unidad para poder "
                           "<b>utilizar esta funcion antes de ejecutarla."

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Ripeando CD...";
            QString cmd1 = "cdparanoia -vsZB";
            QString cmd2 = "echo Moviendo a destino selecionado...";
            QString cmd3 = "RecoverMove";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd2 << cmd3;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionCda_ac3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .cda a .ac3"),
                           tr("<center><b>Convertir formato .cda a .ac3<b></center><p>"

                           "Esta utilidad sirve para poder ripear un CD original "
                           "y transformarlo para poder ser oido en tu equipo o en "
                           "cualquier soporte que reproduzca ac3.<p>"

                           "<B>AVISO:Debe introducir el CD original en la unidad para poder "
                           "<b>utilizar esta funcion antes de ejecutarla."

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Ripeando CD...";
            QString cmd1 = "cdparanoia -vsZB";
            QString cmd2 = "echo Moviendo y convirtiendo a destino selecionado...";
            QString cmd3 = "RecoverMoveac3";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd2 << cmd3;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionWav_wma_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wav a .wma"),
                           tr("<center><b>Convertir formato .wav a .wma<b></center><p>"

                           "Conversion de .wav a .wma<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.wma<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wav"),
                                path,trUtf8("Archivo .wav (*.wav)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wma?"),
                                path,trUtf8("Archivo .wma (*.wma)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -ab 192k -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionWav_mp3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wav a .mp3"),
                           tr("<center><b>Convertir formato .wav a .mp3<b></center><p>"

                           "Conversion de .wav a .mp3<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.mp3<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wav"),
                                path,trUtf8("Archivo .wav (*.wav)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mp3?"),
                                path,trUtf8("Archivo .mp3 (*.mp3)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -ab 192k -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionWav_ac3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wav a .ac3"),
                           tr("<center><b>Convertir formato .wav a .ac3<b></center><p>"

                           "Conversion de .wav a .ac3<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.ac3<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wav"),
                                path,trUtf8("Archivo .wav (*.wav)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .ac3?"),
                                path,trUtf8("Archivo .ac3 (*.ac3)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -ab 192k -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionAc3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .ac3 a .wma"),
                           tr("<center><b>Convertir formato .ac3 a .wma<b></center><p>"

                           "Conversion de .ac3 a .wma<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.wma<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .ac3"),
                                path,trUtf8("Archivo .ac3 (*.ac3)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wma?"),
                                path,trUtf8("Archivo .wma (*.wma)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -ab 192k -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionAc3_mp3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .ac3 a .mp3"),
                           tr("<center><b>Convertir formato .ac3 a .mp3<b></center><p>"

                           "Conversion de .ac3 a .mp3<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.mp3<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .ac3"),
                                path,trUtf8("Archivo .ac3 (*.ac3)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mp3?"),
                                path,trUtf8("Archivo .mp3 (*.mp3)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -ab 192k -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionAc3_wav_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .ac3 a .wav"),
                           tr("<center><b>Convertir formato .ac3 a .wav<b></center><p>"

                           "Conversion de .ac3 a .wav<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.wav<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .ac3"),
                                path,trUtf8("Archivo .ac3 (*.ac3)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wav?"),
                                path,trUtf8("Archivo .wav (*.wav)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -ab 192k -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionAvi_HD_avi_Standar_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .avi HD a .avi Standard"),
                           tr("<center><b>Convertir formato .avi HD a .avi Standar<b></center><p>"

                           "Conversion de formatos avi HD (480p, 720p  y 1080p) a "
                           "formatos avi Standar antiguos.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.avi<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .avi"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .avi?"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -sameq -fs 734003200 -vcodec mpeg4 -vtag XVID -s 592x352 -acodec libmp3lame -ab 128kb -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionAvi_mpg_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .avi a .mpg"),
                           tr("<center><b>Convertir formato .avi a .mpg<b></center><p>"

                           "Conversion de formatos avi a formatos mpg.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.mpg<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .avi"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mpg?"),
                                path,trUtf8("Archivo .mpg (*.mpg)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -sameq -fs 734003200 -s 592x352 -acodec libmp3lame -ab 128kb -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionAvi_dvd_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .avi a .dvd"),
                           tr("<center><b>Convertir formato .avi a .dvd<b></center><p>"

                           "Conversion de formatos avi a formatos dvd.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco.<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .avi"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Donde guardar ficheros de dvd?"),path,QFileDialog::ShowDirsOnly);
            if (fileNameDirectori.isEmpty())
                return;

            QString cm = "mkdir %1/DVD_DATA";
            cm=cm.arg(path);
            QString cmd = "ffmpeg -i %1 -sameq -fs 734003200 -s 592x352 -target pal-dvd -y %2/dvd.mpg";
            cmd=cmd.arg(fileNameOrigen).arg(fileNameDirectori);
            QString cmd1 = "dvdauthor -o %1/DVD_DATA/ -t %2/dvd.mpg";
            cmd1=cmd1.arg(path).arg(path);
            QString cmd2 = "rm -f %1/dvd.mpg";
            cmd2=cmd2.arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cm << cmd << cmd1 << cmd2;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionAVI_WMV_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .avi a .wmv"),
                           tr("<center><b>Convertir formato .avi a .wmv<b></center><p>"

                           "Conversion de formatos avi a formatos wmv.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.wmv<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .avi"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wmv?"),
                                path,trUtf8("Archivo .wmv (*.wmv)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -sameq -fs 734003200 -s 592x352 -acodec libmp3lame -ab 128kb -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionMp4_avi_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mp4 a .avi"),
                           tr("<center><b>Convertir formato .mp4 a .avi<b></center><p>"

                           "Conversion de formatos mp4 a formatos avi.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "IMPORTANTE: Los nombres no pueden incluir espacios en "
                           "blanco y el nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.avi<p>"

                           "<B>UTILICE LA OPCION DE SUSTITUIR ESPACIOS EN BLANCO DEL MENU "
                           "<B>DE SOLUCION DE PROBLEMAS PARA RESOLVER LOS NOMBRES DE ARCHIVO "
                           "<B>DE FORMA MASIVA O TAMBIEN PUEDE RENOMBRAR, DENTRO DE LA VENTANA DE SELECCION, "
                           "<B>EL FICHERO DESEADO.<P>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mp4"),
                                path,trUtf8("Archivo .mp4 (*.mp4)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .avi?"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString cmd1 = "ffmpeg -i %2 -fs 734003200 -sameq -s 592x352 -acodec libmp3lame -ab 128kb -y %3";
            cmd1=cmd1.arg(fileNameOrigen).arg(fileNameDirectori);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionSaber_dependencias_de_librerias_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Saber librerias de binarios"),
                           tr("<center><b>Saber librerias de binarios<b></center><p>"

                           "Mediante esta utilidad, puedes saber todas las librerias "
                           "dependientes de un programa, a nivel informativo.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Comprobar dependencias de librerias?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/usr/sbin/";

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo binario"),
                                path);
            if (fileNameOrigen.isEmpty())
                 return;

            QString cmd1 = "ldd -v %1";
            cmd1=cmd1.arg(fileNameOrigen);
            QStringList comandos;
            comandos<< cmd1;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

void recoverdrake::on_actionSaber_paquetes_dependientes_triggered()
{
    int respuesta = 0;
    bool ok;

    respuesta = QMessageBox::question(this, tr("Saber dependencias de paquete"),
                           tr("<center><b>Saber dependencias de paquete<b></center><p>"

                           "Mediante esta utilidad, puedes saber todos los paquetes "
                           "necesarios para una buena instalación de un paquete "
                           "que queramos instalar, para que no haya problema de "
                           "dependencias.<p>"

                           "Muy util, cuando al instalar un paquete nos falla algo.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice.</B><p>"

                           "&iquest;Comprobar dependencias de paquete?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString texto = QInputDialog::getText(this, tr("Nombre del paquete a buscar"),
            tr("Introduzca el nombre del paquete a buscar.<P> "

            "<FONT COLOR=\"RED\">Ejemplo:<p>"

            "<FONT COLOR=\"RED\">RecoverDrake"),
            QLineEdit::Normal,
            "",
            &ok);
            if (ok && !texto.isEmpty()){

                QString cmd1 = "urpmq -d %1";
                cmd1=cmd1.arg(texto);
                QStringList comandos;
                comandos<< cmd1;

                if (mib != 0)
                delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                mib->iniciarProceso();}
                return;
            }
            return;
}

void recoverdrake::on_menuQuemado_de_discos_CD_DVD_triggered()
{
    burn *quemar=new burn(this);
    quemar->show();
}

void recoverdrake::on_actionAyuda_de_RecoverDrake_triggered()
{
    help *hp=new help(this);
    hp->show();
}

void recoverdrake::on_actionNota_de_la_versi_n_triggered()
{
    notas *note=new notas(this);
    note->show();
}

void recoverdrake::actionConsola_como_root()
{
    connect(ui->actionConsola_como_root,SIGNAL(triggered()),this,SLOT(Konsola_root()));
}

void recoverdrake::Konsola_root()
{
    system("konsole");
}

void recoverdrake::actionAcerca_de()
{
    connect(ui->actionAcerca_de,SIGNAL(triggered()),this,SLOT(Acerca_de()));
}

void recoverdrake::Acerca_de()
{
    QMessageBox::about(this, tr("Acerca de..."),
            tr("<center><b>kapyderi 2010 -- BOFH de Blogdrake.net</b></center><p>"
               "RecoverDrake es una utilidad que le puede sacar de muchos apuros.<p>"

               "En un principio fue creada para recuperar paquetes instalados "
               "en su ordenardor y poder volver a instalarlos sin tener que "
               "recordar que habia instalado anteriormente, a quien no le ha "
               "pasado alguna vez, verdad.<p>"

               "Con el paso del tiempo, se ha hecho mas extenso y en estos "
               "momentos cubre muchas aplicaciones en una, ya que tienes "
               "infinidad de soporte a problemas y configuraciones.<p>"
               "Gracias por usarlo.<p>"
               "<center><a href=\"http://www.kapyderi.blogspot.com\">www.kapyderi-blogspot.com</a></center>"));
}

void recoverdrake::on_actionAgradecimientos_triggered()
{
    QMessageBox::about(this, tr("Agradecimientos"),
            tr("<center><b>Agradecimientos</b></center><p>"

               "Agradecimientos:<p>"

               "No por ultimo menos importante, quiero agradecer a...<p>"

               "Katnatek, por parte de su codigo y por la ayuda desinteresada.<p>"
               "SinnerBOFH, por su experiencia.<p>"
               "Drakor, por su ayuda e interes.<p>"
               "Will, por servir de conejillo de indias.<p>"
               "Paky, mi mujer por soportarme en el teclado.<p>"
               "Athenea, mi hija mayor por su admiracion por mi hobbie.<p>"
               "Minerva, mi hija menor por los ratos sentada en mi regazo mientras programo.<p>"
               "Motitos, por sus reflesiones de como deberia ser RecoverDrake.<p>"
               "Annubis, por su desinteresada ayuda y sugerencias.<p>"
               "Er Bardo y Adrimag del foro zonaqt por sus explicaciones sobre el compilador y su "
               "gran aportacion a la construcion de este programa basado en C++/Qt.<p>"
               "Leo Vasquez de ZonaQt por las horas de ayuda y explicaciones.<p>"
               "Michael Jackson por la inspiracion mientras oigo su musica<p>"
               "Luigi por su interes y pruebas<p>"
               "vinxeno, porque si Internet fuera una persona, seguro sería el<p>"
               "Carlos \"Toro\", no te olvido, estes donde estes - R.I.P. 25-08-2000<p>"
               "Blogdrake y ZonaQt, porque sin ellas, no habria sido lo que es ahora RecoverDrake.<p>"

               "...si me dejo alguien que me perdone, pero es muuu tarde."));
}


void recoverdrake::actionAcerca_de_Qt()
{
    connect(ui->actionAcerca_de_Qt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
}

void recoverdrake::mibEscribir(QString valor)
{
    ui->textEdit->append(valor);
}

void recoverdrake::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
}
