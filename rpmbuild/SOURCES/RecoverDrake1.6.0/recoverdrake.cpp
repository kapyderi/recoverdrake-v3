#include <QMessageBox>
#include <stdlib.h>
#include <QtGui>
#include <QToolButton>
#include <QWidget>
#include <QIcon>

#include "recoverdrake.h"
#include "ui_recoverdrake.h"
#include "drakesistema.h"
#include "drakeprocesos.h"
#include "acceso.h"
#include "claves.h"
#include "help.h"
#include "notas.h"
#include "burn.h"
#include "dialog.h"
#include "visualizar.h"

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlTableModel>

recoverdrake::recoverdrake(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::recoverdrake)
{
    ui->setupUi(this);

    QSettings seting("myorg","Aplica");
    QVariant opcion;
    QVariant opcion1;
    QVariant opcion2;
    QVariant opcion3;
    QVariant opcion4;
    opcion=seting.value("opcion",false);
    opcion1=seting.value("opcion1",false);
    opcion2=seting.value("opcion2",false);
    opcion3=seting.value("opcion3",false);
    opcion4=seting.value("opcion4",false);
    ui->actionActivar_Desactivar_inicio_con_Linux->setChecked(opcion.toBool());
    ui->actionComprabar_depndencias_RecoverDrake->setChecked(opcion1.toBool());
    ui->actionSugerencias_y_avisos->setChecked(opcion2.toBool());
    ui->actionMinimizar_al_Salir->setChecked(opcion3.toBool());
    ui->actionActivar_Logs_de_sucesos->setChecked(opcion4.toBool());

    drakeSistema drake;

    dist = drake.getDistribucion();
    arqt = drake.getArquitectura();
    user = drake.getUser();
    Tip = drake.getTipKernel();
    Ver = drake.getVerKernel();
    Rev = drake.getRevKernel();
    Dir = drake.getDirActual();
    Vir = drake.getVirtual();
    Linux = drake.getLinux();
    Pci = drake.getPci();
    Mod = drake.getModulo();
    du = drake.getEspacio();
    repo = drake.getRepositorio();
    red = drake.getRedes();
    rpm = drake.getRpms();
    Distro = drake.getDistrop();

    this->ui->textEdit_9->setText(rpm);
    this->ui->textEdit_6->setText(du);
    this->ui->lineEdit->setText(user);
    this->ui->lineEdit_2->setText(arqt);
    this->ui->lineEdit_3->setText(dist);
    this->ui->lineEdit_4->setText(Ver);
    this->ui->lineEdit_5->setText(Tip);
    this->ui->lineEdit_6->setText(Rev);
    this->ui->textEdit_3->setText(Linux);
    this->ui->textEdit_10->setText(Pci);
    this->ui->textEdit_5->setText(Mod);   
    this->ui->textEdit_7->setText(repo);
    this->ui->textEdit_8->setText(red);

    actionConsola_como_root();
    actionEditar_y_configurar_repositorios();
    actionAcerca_de();
    actionAcerca_de_Qt();

    mib = 0;
    otros = 0;
    clave = 0;

    acceso *acc=new acceso(this);
    acc->exec();
    QString Usu=acc->Usuar;    
    this->ui->label_7->setText(Usu);

    this->Arranque();

    crearAcciones();
    this->crearIcono();
    trayIcon->show();
    this->setIcono();

    QSqlQuery query;
    query.exec("select Usuario from Control");
    query.last();
    Dato=query.value(0).toString();
    QSqlQuery query1;
    query1.exec("SELECT Usuario,Nivel FROM Acceso WHERE Usuario LIKE '"+Dato+"'");
    query1.first();
    Nivel=query1.value(1).toString();
    if (Nivel == "1")
    {
        ui->actionUsuarios->setEnabled(false);
        ui->menuInstaladores->setEnabled(false);
        ui->menuMantenimiento->setEnabled(false);
        ui->menuSoluci_n_a_problemas->setEnabled(false);
        ui->menuUtilidades->setEnabled(false);
        ui->actionConsola_como_root->setEnabled(false);
        ui->actionSystemSetting_como_root->setEnabled(false);
        ui->actionMenu_contextual_de_root_en_usuario->setEnabled(false);
        ui->menuAntivirus->setEnabled(false);
    }
    else if (Nivel == "2")
    {
        ui->actionUsuarios->setEnabled(false);
        ui->menuUtilidades->setEnabled(false);
        ui->menuInstalar_drivers_wifi_con_ndiswrapper->setEnabled(false);
        ui->menuInstalar_drivers_wifi_propietarios_2->setEnabled(false);
        ui->menuSoluci_n_a_problemas->setEnabled(false);
        ui->actionConsola_como_root->setEnabled(false);
        ui->actionSystemSetting_como_root->setEnabled(false);
        ui->actionMenu_contextual_de_root_en_usuario->setEnabled(false);
        ui->menuAntivirus->setEnabled(false);
        ui->menuMantenimiento->setEnabled(false);
    }
    if (Distro == "Mageia")
    {
        ui->actionPLF->setEnabled(false);
        ui->actionBDK->setEnabled(false);
        ui->actionMIB->setEnabled(false);
        ui->actionMUD->setEnabled(false);
        ui->actionA_adir_todos->setEnabled(false);
        ui->actionPLF->setText("PLF (Solo Mandriva)");
        ui->actionBDK->setText("BDK (Solo Mandriva)");
        ui->actionMIB->setText("MIB (Solo Mandriva)");
        ui->actionMUD->setText("MUD (Solo Mandriva)");
        ui->actionA_adir_todos->setText(QString::fromUtf8("Añadir todos (Solo Mandriva)"));
    }
    this->ui->label_9->setText(Nivel);
    QSqlQuery query2;
    query2.exec("SELECT COUNT(Usuario) AS Cantidad FROM Control");
    query2.first();
    Cantidad=query2.value(0).toString();
    if (Cantidad == "1")
    {
        QSqlQuery query3;
        query3.exec("UPDATE Acceso SET Activo = 0 WHERE Usuario = 'admin'");
        this->CrearUser();
    }
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::CrearUser()
{    
    QMessageBox m;
    m.setText("Es la primera vez que se ejecuta RecoverDrake por lo que tiene que crear un usuario nuevo con <b>Nivel 3</b>, ya que admin se ha deshabilitado para la proxima vez que acceda a RecoverDrake.<p>Si quiere habilitar de nuevo <b>admin</b> debera acceder a usuarios y volver a habilitarlo.");
    m.exec();
    claves *clave=new claves();
    clave->exec();
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::Arranque()
{   
   bool opcion1;
   bool opcion4;
   opcion4=ui->actionActivar_Logs_de_sucesos->isChecked();
   opcion1=ui->actionComprabar_depndencias_RecoverDrake->isChecked();
   QSettings seting("myorg","Aplica");
   seting.setValue("opcion1",opcion1);   
   seting.setValue("opcion4",opcion4);
   if (opcion4==true)
    {
       system("echo Fecha de ingreso... >> /home/'"+user+"'/RecoverDrake.log");
       system("date >> /home/'"+user+"'/RecoverDrake.log");
    }
   if (opcion1==true)
    {

       ui->lineEdit_7->setText("COMPROBACION DE DEPENDENCIAS ACTIVADA.");
       QString cmd="echo Comprobando dependencias necesarias...";
       QString comando="/bin/sh urpmi -a --auto --force zenity sudo bash kwrite libstdc++ ndiswrapper photorec testdisk ntfs-config cdparanoia lame ffmpeg dvdauthor parole cdrecord tar alien urpmi fakeroot rpmdrake mkvtoolnix clamav dolphin libqtgui4 unrar mencoder gnome-utils";
       QString cmd1 = "/bin/sh urpmi --wget -a --auto --force real-codecs win32-codecs xanim-codecs libquicktime libquicktime-x264 libquicktime-lame libquicktime-faad libquicktime-faac faad2 xine-faad faac libamrnb3 libamrwb3 amrnb amrwb";
       QString cmd2 = "/bin/sh urpmi --wget -a --force --auto lame gstreamer0.10-a52dec gstreamer0.10-amrnb gstreamer0.10-amrwb gstreamer0.10-faad gstreamer0.10-faac gstreamer0.10-ffmpeg mencoder gstreamer0.10-lame";
       QString cmd3 = "/bin/sh urpmi --wget -a --force --auto gstreamer0.10-flac gstreamer0.10-cdio gstreamer0.10-cdparanoia ffmpeg mencoder transcode gstreamer0.10-mms";

       QStringList comandos;
       comandos<< cmd << comando << cmd1 << cmd2 << cmd3;

       if (mib != 0)
           delete otros;
       mib = new DrakeProcesos(comandos, this);
       connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
       connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
       mib->iniciarProceso();
    }
   else
    {       
       ui->lineEdit_7->setText("ATENCION: LA COMPROBACION DE DEPENDENCIAS NO ESTA ACTIVADA, PUEDE NO FUNCIONAR CORRECTAMENTE.");
       int respuesta = 0;

       respuesta = QMessageBox::question(this, tr("Comprobar dependencias de uso"),
                  tr("<center><b>Comprobar dependencias para RecoverDrake</b></center><p>"

                     "<b>IMPORTANTE:</b> He observado que tienes la comprobacion de dependencias "
                     "deshabilitada...no es un buen consejo, ya que para realizar todos los "
                     "procesos de RecoverDrake, son necesarios paquetes externos que deberian "
                     "estar totalmente configurados y funcionando al 100%.<p>"

                     "&iquest;Comprobar dependencias para el buen uso de RecoverDrake?"), QMessageBox::Ok, QMessageBox::No);

       if (respuesta == QMessageBox::Ok){

       QString cmd="echo Buscando dependencias necesarias e instalando...";
       QString comando="/bin/sh urpmi -a --auto --force zenity sudo bash kwrite libstdc++ ndiswrapper photorec testdisk ntfs-config cdparanoia lame ffmpeg dvdauthor parole cdrecord tar alien urpmi fakeroot rpmdrake mkvtoolnix clamav dolphin libqtgui4 unrar mencoder gnome-utils";
       QString cmd1= "/bin/sh urpmi --wget -a --auto --force real-codecs win32-codecs xanim-codecs libquicktime libquicktime-x264 libquicktime-lame libquicktime-faad libquicktime-faac faad2 xine-faad faac libamrnb3 libamrwb3 amrnb amrwb";
       QString cmd2 = "/bin/sh urpmi --wget -a --force --auto lame gstreamer0.10-a52dec gstreamer0.10-amrnb gstreamer0.10-amrwb gstreamer0.10-faad gstreamer0.10-faac gstreamer0.10-ffmpeg mencoder gstreamer0.10-lame";
       QString cmd3 = "/bin/sh urpmi --wget -a --force --auto gstreamer0.10-flac gstreamer0.10-cdio gstreamer0.10-cdparanoia ffmpeg mencoder transcode gstreamer0.10-mms";

       QStringList comandos;
       comandos<< cmd << comando << cmd1 << cmd2 << cmd3;

       if (mib != 0)
           delete otros;
       mib = new DrakeProcesos(comandos, this);
       connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
       connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
       mib->iniciarProceso();}
       return;
    }
   return;
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionComprobar_dependencias_triggered()
{
       int respuesta = 0;

       respuesta = QMessageBox::question(this, tr("Comprobar dependencias de uso"),
                  tr("<center><b>Comprobar dependencias para RecoverDrake</b></center><p>"

                     "<b>IMPORTANTE:</b> Se procede a comprobar la integridad de funcionamiento "
                     "de RecoverDrake, realizando la busqueda de paquetes externos necesarios y "
                     "que deberian estar totalmente configurados y funcionando al 100%.<p>"

                     "&iquest;Comprobar dependencias para el buen uso de RecoverDrake?"), QMessageBox::Ok, QMessageBox::No);

       if (respuesta == QMessageBox::Ok){

       QString cmd="echo Buscando dependencias necesarias e instalando...";
       QString comando="/bin/sh urpmi -a --auto --force zenity sudo bash kwrite libstdc++ ndiswrapper photorec testdisk ntfs-config cdparanoia lame ffmpeg dvdauthor parole cdrecord tar alien urpmi fakeroot rpmdrake mkvtoolnix clamav dolphin libqtgui4 unrar mencoder gnome-utils";
       QString cmd1= "/bin/sh urpmi --wget -a --auto --force real-codecs win32-codecs xanim-codecs libquicktime libquicktime-x264 libquicktime-lame libquicktime-faad libquicktime-faac faad2 xine-faad faac libamrnb3 libamrwb3 amrnb amrwb";
       QString cmd2 = "/bin/sh urpmi --wget -a --force --auto lame gstreamer0.10-a52dec gstreamer0.10-amrnb gstreamer0.10-amrwb gstreamer0.10-faad gstreamer0.10-faac gstreamer0.10-ffmpeg mencoder gstreamer0.10-lame";
       QString cmd3 = "/bin/sh urpmi --wget -a --force --auto gstreamer0.10-flac gstreamer0.10-cdio gstreamer0.10-cdparanoia ffmpeg mencoder transcode gstreamer0.10-mms";

       QStringList comandos;
       comandos<< cmd << comando << cmd1 << cmd2 << cmd3;

       if (mib != 0)
           delete otros;
       mib = new DrakeProcesos(comandos, this);
       connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
       connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
       mib->iniciarProceso();}
       return;
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionSugerencias_y_avisos_triggered(bool a)
{
    QMessageBox m;
    bool opcion2;
    opcion2=ui->actionSugerencias_y_avisos->isChecked();
    QSettings seting("myorg","Aplica");
    seting.setValue("opcion2",opcion2);
    if (a==true)
     {
        m.setText("Se ha activado las sugerencias al inicio de RecoverDrake");
     }
    else
    {
        m.setText("Se ha desactivado las sugerencias al inicio de RecoverDrake.<p>""Utilice esta opcion para volver a activarla.");
    }
    m.exec();
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionSalir_triggered()
{
    bool opcion3;
    opcion3=ui->actionMinimizar_al_Salir->isChecked();
    QSettings seting("myorg","Aplica");
    seting.setValue("opcion3",opcion3);
    if (opcion3==true)
     {
        if (trayIcon->isVisible()) {

        QMessageBox::information(this, tr("Systray"),
        tr("El programa seguira corriendo en la bandeja del sistema.\n"));
        hide();}
     }
    else
     {
        close();
     }
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionUsuarios_triggered()
{
    claves *clave=new claves();
    clave->exec();     
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionComprabar_depndencias_RecoverDrake_triggered(bool c)
{
   QMessageBox m;
   bool opcion1;
   opcion1=ui->actionComprabar_depndencias_RecoverDrake->isChecked();
   QSettings seting("myorg","Aplica");
   seting.setValue("opcion1",opcion1);
   if (c==true)
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
                     "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

                     "&iquest;Comprobar dependencias para el buen uso de RecoverDrake?"), QMessageBox::Ok, QMessageBox::No);

       if (respuesta == QMessageBox::Ok){

       this->ui->lineEdit_7->setText("COMPROBACION DE DEPENDENCIAS ACTIVADA.");
       m.setText("Se ha activado la comprobacion de dependencias de RecoverDrake");
       QString cmd="echo Buscando dependencias necesarias e instalando...";
       QString comando="/bin/sh urpmi -a --auto --force zenity sudo bash kwrite libstdc++ ndiswrapper photorec testdisk ntfs-config cdparanoia lame ffmpeg dvdauthor parole cdrecord tar alien urpmi fakeroot rpmdrake mkvtoolnix clamav dolphin libqtgui4 unrar mencoder gnome-utils";
       QString cmd1= "/bin/sh urpmi --wget -a --auto --force real-codecs win32-codecs xanim-codecs libquicktime libquicktime-x264 libquicktime-lame libquicktime-faad libquicktime-faac faad2 xine-faad faac libamrnb3 libamrwb3 amrnb amrwb";
       QString cmd2 = "/bin/sh urpmi --wget -a --force --auto lame gstreamer0.10-a52dec gstreamer0.10-amrnb gstreamer0.10-amrwb gstreamer0.10-faad gstreamer0.10-faac gstreamer0.10-ffmpeg mencoder gstreamer0.10-lame";
       QString cmd3 = "/bin/sh urpmi --wget -a --force --auto gstreamer0.10-flac gstreamer0.10-cdio gstreamer0.10-cdparanoia ffmpeg mencoder transcode gstreamer0.10-mms";

       QStringList comandos;
       comandos<< cmd << comando << cmd1 << cmd2 << cmd3;

       if (mib != 0)
           delete otros;
       mib = new DrakeProcesos(comandos, this);
       connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
       connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
       mib->iniciarProceso();}
       return;
    }
   else
   {
       this->ui->lineEdit_7->setText("ATENCION: LA COMPROBACION DE DEPENDENCIAS NO ESTA ACTIVADA, PUEDE NO FUNCIONAR CORRECTAMENTE.");
       m.setText("Se ha desactivado la comprobacion de dependencias de RecoverDrake.<p>""Utilice esta opcion para volver a activarla.");
   }
      m.exec();
}

//***OPCION REVISADA Y TERMINADA***//
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
                  "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionOficiales_triggered()
{
    int respuesta = 0;

    if(Distro=="Mandriva"){

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
                      "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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
        }
        else if(Distro == "Mageia")
        {
            respuesta = QMessageBox::question(this, tr("Instalar repositorios oficiales"),
                       tr("<center><b>Oficiales</b></center><p>"

                          "Configuracion de los repositorios Oficiales.<p>"

                          "Estos repositorios como su nombre indica son los garantizados "
                          "por Mageia y son necesarios para tenerlo todo actualizado "
                          "y poder disponer de los paquetes que Mageia nos deja a nuestro "
                          "alcance.<p>"

                          "Representan el conjunto de repositorios core, nonfree, tainted "
                          "y sus respectivos \"updates\" y \"backports\"<p>"

                          "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                          "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

                          "&iquest;Instalar repositorios Oficiales (Recomendado)?"), QMessageBox::Ok, QMessageBox::No);

            if (respuesta == QMessageBox::Ok){

            QString comando="/bin/sh urpmi.addmedia --wget --distrib --mirrorlist";
            comando = comando.arg(dist).arg(arqt);

            QStringList comandos;
            comandos<< comando;

            if (mib != 0)
                delete otros;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
        }
        return;
}

//***OPCION REVISADA Y TERMINADA***//
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
                  "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                  "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                  "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

                  "&iquest;Instalar repositorios BDK?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

    QString cmd1 ="urpmi.addmedia --wget --distrib ftp://ftp.blogdrake.net/mandriva/%1/%2";    
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

//***OPCION REVISADA Y TERMINADA***//
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
                  "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                   "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionA_adir_todos_triggered()
{
    int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar todos los repositorios"),
               tr("<center><b>Instalar todos los repositorios</b></center><p>"

                  "Este apartado realiza la instalacion masiva de todos "
                  "los repositorios incluidos por defectos, como pueden "
                  "ser OFICIALES, PLF, MIB, BDK y MUD.<P> "

                  "<B>NOTA: Debe esperar a que termine completamente el proceso seleccionado, "
                  "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::actionEditar_y_configurar_repositorios()
{
    connect(ui->actionEditar_y_configurar_repositorios,SIGNAL(triggered()),this,SLOT(Config_Repos()));
}

//***OPCION REVISADA Y TERMINADA***//
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
                           "o Testing, pueden desestabilizar su sistema.<p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

                               "&iquest;Crear imagen ISO?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString path="/home/%1/Documentos/imagen.iso";
                path=path.arg(user);

                QString fileNameDestino = QFileDialog::getSaveFileName(this,tr("Salvar imagen ISO"),
                                    path,tr("Imagen ISO (*.iso)"));
                if (fileNameDestino.isEmpty())
                    return;

                QString cmd = "su - %1 -c \"dd if=/dev/cdrom of=%2\"";
                cmd = cmd.arg(user).arg(fileNameDestino);

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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

                               "&iquest;Montar imagen ISO?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString path="/home/%1/Documentos/";
                QString path2="/mnt/";
                path=path.arg(user);

                QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir imagen ISO"),
                                    path,trUtf8("Imagen ISO (*.iso)"));
                if (fileNameOrigen.isEmpty())
                    return;

                QString fileNameDestino = QFileDialog::getExistingDirectory(this,tr("Destino de montaje"),path2,QFileDialog::ShowDirsOnly);
                if (fileNameDestino.isEmpty())
                    return;

                QString cmd = "su - %1 -c \"mount -o loop %2 %3\"";
                cmd = cmd.arg(user).arg(fileNameOrigen).arg(fileNameDestino);

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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

                               "&iquest;Desmontar imagen ISO?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString path="/mnt/";
                QString fileNameOrigen = QFileDialog::getExistingDirectory(this,tr("Ubicacion de origen de imagen montada"),path,QFileDialog::ShowDirsOnly);
                if (fileNameOrigen.isEmpty())
                    return;

                int respuesta2 = 0;
                respuesta2 = QMessageBox::question(this, tr("Borrar directorio montado"),
                                       tr("<center><b>Borrar directorio montado<b></center><p>"

                                       "IMPORTANTE: Si marcas la opcion OK, tienes que tener muy en "
                                       "cuenta que el directorio donde has montado la imagen "
                                       "no es un directorio que tenia anteriormente datos, "
                                       "porque seran eliminados y puede causar graves daños.<p>"

                                       "Marque OK solo en el caso de haber creado a conciencia el "
                                       "directorio para montar la imagen.<p>"

                                       "PROCEDA CON MUCHA PRECAUCION.<P>"

                                       "<B>NOTA Debe esperar a que termine completamente el "
                                       "proceso seleccionado, el cual le sera notificado "
                                       "cuando finalice, en la consola de procesos.</B><p>"

                                       "&iquest;Borrar directorio tras el desmontado?"), QMessageBox::Ok, QMessageBox::No);

                if (respuesta2 == QMessageBox::Ok){

                            QString cmd2 ="su - %1 -c \"fuser -k %2\"";
                            QString cmd = "su - %1 -c \"umount %2\"";
                            QString cmd1 = "su - %1 -c \"rm -R -f %2\"";
                            cmd = cmd.arg(user).arg(fileNameOrigen);
                            cmd1 = cmd1.arg(user).arg(fileNameOrigen);
                            cmd2 = cmd2.arg(user).arg(fileNameOrigen);

                            QStringList comandos;
                            comandos<< cmd2 << cmd << cmd1;

                            if (mib != 0)
                            delete mib;
                            mib = new DrakeProcesos(comandos, this);
                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                            mib->iniciarProceso(); }

                else {

                    QString cmd2 ="su - %1 -c \"fuser -k %2\"";
                    QString cmd = "su - %1 -c \"umount %2\"";
                    cmd2 = cmd2.arg(user).arg(fileNameOrigen);
                    cmd = cmd.arg(user).arg(fileNameOrigen);

                    QStringList comandos;
                    comandos<< cmd2 << cmd;

                    if (mib != 0)
                    delete mib;
                    mib = new DrakeProcesos(comandos, this);
                    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                    mib->iniciarProceso();}
            }
            return;
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionBorrar_imagen_ISO_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Borrar imagen ISO"),
                               tr("<center><b>Borrar imagen ISO<b></center><p>"

                               "Con esta utilidad, hacemos un borrado de una imagen de nuestro disco "
                               "duro.<P>"

                               "<B>NOTA Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice, en la consola de procesos.</B><p>"

                               "&iquest;Borrar imagen ISO?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString path="/home/%1/Documentos/";
                QString path2="/mnt/";
                path=path.arg(user);

                QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir imagen ISO"),
                                    path,trUtf8("Imagen ISO (*.iso)"));
                if (fileNameOrigen.isEmpty())
                    return;

                QString cmd = "su - %1 -c \"rm -f %2\"";
                cmd = cmd.arg(user).arg(fileNameOrigen);

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

//***OPCION REVISADA Y TERMINADA***//
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
                   "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                   "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                   "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                              "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                              "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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
                                                   "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                              "el cual le sera notificado cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionEDE_2_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar Ede"),
                               tr("<center><b>Instalar Ede</b></center><p>"

                               "Personalmente nunca lo he utilizado, pero como esta, lo "
                               "pongo.<p>"

                               "<B>NOTA: Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionLXDE_2_triggered()
{
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Instalar Lxde"),
                               tr("<center><b>Instalar Lxde</b></center><p>"

                               "Basado en Kde, pero mucho mas sencillo y ocupa muchos "
                               "menos recursos.<p>"

                               "<B>NOTA: Debe esperar a que termine completamente el "
                               "proceso seleccionado, el cual le sera notificado "
                               "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

                               "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString cmd = "/bin/sh urpmi --wget --auto task-printing task-printing-misc task-printing-server system-config-printer";

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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

                               "&iquest;Instalar codecs?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){


                QString cmd = "/bin/sh urpmi --wget -a --auto --force real-codecs win32-codecs xanim-codecs libquicktime libquicktime-x264 libquicktime-lame libquicktime-faad libquicktime-faac faad2 xine-faad faac libamrnb3 libamrwb3 amrnb amrwb";
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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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

                           "<FONT COLOR=\"BLUE\">Lo mas correcto es guardar el fichero .inf y .sys en el escritorio de "
                           "<FONT COLOR=\"BLUE\">Linux y asi no habra problemas de incompatibilidad.<p>"

                           "<FONT COLOR=\"RED\">AVISO: Va a utilizar un driver privativo en su sistema.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar drivers?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString path="/media/";

        QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir fichero .inf"),
                            path,trUtf8("Fichero información (*.inf);;Fichero sistema (*.sys)"));
        system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
        if (fileNameOrigen.isEmpty())
            return;
            QString fileName = fileNameOrigen.replace(" ", "_");
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

//***OPCION REVISADA Y TERMINADA***//
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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "operaciones que puedan perjudicar directorios.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Desbloquear base de datos urpmi?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Eliminando ficheros bloqueados...";
            QString cmd1 = "killall urpmi urpmi.update urpme rpm urpmi.addmedia userhelper";
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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionVisionar_flash_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Visionar Flash"),
                           tr("<center><b>Visionar Flash<b></center><p>"

                           "Para poder ver videos de tipo flash, como por ejemplo "
                           "de la pagina de youtube, necesitas tener instalado "
                           "el plugin flash o irremediablemente no podras verlos.<p>"

                           "La solucion pasa por utilizar esta utilidad.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar plugin flash?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi -a --auto flash-player-plugin";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionVirtualBox_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Configurar VirtualBox"),
                           tr("<center><b>Configurar Virtualbox<b></center><p>"

                           "Cuando queremos ejecutar Virtualbox, es posible "
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
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Configurar Virtualbox?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "echo Descargando paquetes necesarios e instalando...";
        QString cmd1 = "urpmi --auto -a dkms-Virtualbox Virtualbox-kernel-%1 Virtualbox-kernel-%1-latest";
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

//***OPCION REVISADA Y TERMINADA***//
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

//***OPCION REVISADA Y TERMINADA***//
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

//***OPCION REVISADA Y TERMINADA***//
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

//***OPCION REVISADA Y TERMINADA***//
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

//***OPCION REVISADA Y TERMINADA***//
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

//***OPCION REVISADA Y TERMINADA***//
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

//***OPCION REVISADA Y TERMINADA***//
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

//***OPCION REVISADA Y TERMINADA***//
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

//***OPCION REVISADA Y TERMINADA***//
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionCargar_direcci_n_sop_triggered()
{
    int respuesta = 0;
    int respuesta1 = 0;
    bool ok;

    respuesta = QMessageBox::question(this, tr("Ejecutar sopcast"),
                           tr("<center><b>Ejecutar sopcast<b></center><p>"

                           "Esta utilidad sirve para ver todo tipo de eventos, aunque se suele "
                           "utilizar para ver eventos deportivos, los cuales pueden ser de pago "
                           "en algunos paises y en otros son emitidos libremente y por canales "
                           "abiertos via internet y que por lo general son de origen Chino o "
                           "japones.<p>"

                           "<FONT COLOR=\"RED\">IMPORTANTE: En algunos paises, utilizar este tipo de software puede ser ilegal, "
                           "<FONT COLOR=\"RED\">consulte la legislacion vigente de su pais para saber si puede utilizar "
                           "<FONT COLOR=\"RED\">dicho software.<p>"

                           "Solo tiene que meter lar direccion sop del evento para poder visualizarlo, pero "
                           "anteriormente tiene que tener instalado en el sistema los paquetes sopcast y "
                           "vlc o parole, para poder visionarlo correctamente.<p>"

                           "<B>NOTA: Durante la ejecucion de este apartado no es recomendable utilizar ninguna opcion del "
                           "menu salvo la de visionar el evento en este mismo submenu, ya que se cortara la comunicacion. Y "
                           "por supuesto no cierre RecoverDrake, mientras este visualizando el evento.</B><p>"

                           "&iquest;Ejecutar sopcast?"), QMessageBox::Ok, QMessageBox::No);

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

                                QString direccion = QInputDialog::getText(this, tr("Direccion sop"),
                                tr("Introduzca la direccion completa \"sop\" del evento.<P>"

                                    "<FONT COLOR=\"RED\">Ejemplo:<p>"

                                    "<FONT COLOR=\"RED\">sop://sop.prueba.com:3912/60713<p>"),
                                    QLineEdit::Normal,
                                    "",
                                    &ok);
                                    if (ok && !direccion.isEmpty()){

                                        system("su - "+user+" -c \"sp-sc '"+direccion+"' 3908 8908 > /dev/null &\"");
                                            }
                                }
                    else {
                                return;
                         }
                    }
                    return;
}

void recoverdrake::on_actionVisionar_evento_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Visionar evento"),
                           tr("<center><b>Visionar sop montada<b></center><p>"

                           "Una vez montada la direccion sop a visionar, solo nos resta "
                           "lanzarla en un programa de video.<p>"

                           "&iquest;Visionar evento?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok)
    {
        system("su - "+user+" -c \"parole http://localhost:8908/tv.asf\"");
    }
    return;
}

void recoverdrake::on_actionMatar_direccion_sop_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Matar direccion sop activa"),
                           tr("<center><b>Matar direccion sop activa<b></center><p>"

                           "Por algun motivo, puede que al haber activado un nuevo sop, el anterior se "
                           "quede enganchado. La solucion pasa por ejecutar esta utilidad para que sea liberado.<p>"

                           "Como norma general, suele pasar en algunas ocasiones, aunque no es normal.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Matar sop activo?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

        QString cmd = "RecoverSop";

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

//***OPCION REVISADA Y TERMINADA***//
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
                               "cuando finalice, en la consola de procesos.</B><p>"

                               "&iquest;Convertir .deb a .rpm?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

                QString path="/home/%1/";
                path=path.arg(user);

                QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .deb"),
                                    path,trUtf8("Archivo .deb (*.deb)"));
                system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
                if (fileNameOrigen.isEmpty())
                    return;

                QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Donde guardar el fichero .rpm?"),path,QFileDialog::ShowDirsOnly);
                if (fileNameDirectori.isEmpty())
                    return;

                QString fileName = fileNameOrigen.replace(" ","_");
                QString cmd = "fakeroot alien -r -c %2";
                cmd = cmd.arg(fileName);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionReconstruir_DB_de_los_rpm_s_triggered()
{
    int respuesta = 0;
    QString fileNameOrigen;

    respuesta = QMessageBox::question(this, tr("Reconstruir DB de los rpm's"),
                           tr("<center><b>Reconstruir DB de los rpm's<b></center><p>"

                           "Con esta opcion reconstruimos toda la base de datos de "
                           "rpmś instalados en el sistema. Muy util cuando hay problemas "
                           "de localizacion de paquetes aun teniendolos instalados.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Reconstruir DB?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "rpm --rebuilddb";
            QStringList comandos;
            comandos<<cmd;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionConvertir_cbr_a_pdf_triggered()
{
    int respuesta = 0;
    QString fileNameOrigen;

    respuesta = QMessageBox::question(this, tr("Convertir formato .cbr a .pdf"),
                           tr("<center><b>Convertir formato .cbr a .pdf<b></center><p>"

                           "Conversion de .cbr a .pdf<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "El formato .cbr, es en realidad un fichero comprimido de imagenes, por "
                           "lo que para poder convertirlo a .pdf, es necesario descomprimir y volcarlo "
                           "a la salida de .pdf<p>"

                           "NOTA: El fichero resultante tendra el mismo nombre que el .cbr, pero "
                           "con la extension y compatibilidad de un .pdf<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .cbr"),
                                path,trUtf8("Archivo .cbr (*.cbr)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString cmd = "su - %1 -c \"mkdir %2tmpcbr/\"";
            cmd=cmd.arg(user).arg(path);
            QString cmd1= "su - %1 -c \"cp %2 %3tmpcbr/\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(path);
            QString cmd2 = "su - %1 -c \"unrar e -y %2tmpcbr/*.cbr %2tmpcbr/\"";
            cmd2=cmd2.arg(user).arg(path);
            QString cmd3= "su - %1 -c \"convert %2tmpcbr/*.jpg %3.pdf\"";
            cmd3=cmd3.arg(user).arg(path).arg(fileName);
            QString cmd4="su - %1 -c \"rm -rf %2tmpcbr/\"";
            cmd4=cmd4.arg(user).arg(path);
            QStringList comandos;
            comandos<<cmd << cmd1 <<cmd2 <<cmd3 <<cmd4;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}    
            return;
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionExtraer_audio_a_un_video_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Extraer audio de un video"),
                           tr("<center><b>Extraer audio de un video<b></center><p>"

                           "Con esta utilidad puedes extraer un audio de un video "
                           "y dejar el video resultante sin audio.<p>"

                           "Se creara un fichero con el audio en mp3 en la misma ruta "
                           "que el fichero de video original.<p>"
                           "Se creara un fichero con el video sin audio.<p>"

                           "IMPORTANTE: El nombre del fichero a grabar debe expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.avi<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Extraer audio de video?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo de video"),
                                path,trUtf8("Archivos de video (*.avi *.mpg *.flv *.wmv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");

            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero de video"),
                                path,trUtf8("Archivos de video (*.avi *.mpg *.flv *.wmv)"));

            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString info="su - %1 -c \"fmpeg -i %2\"";
            info=info.arg(user).arg(fileName);
            QString cmd ="su - %1 -c \"ffmpeg -i %2 -y %2.mp3\"";
            cmd=cmd.arg(user).arg(fileName);
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -vcodec copy -an -y %3\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionIncluir_audio_a_un_video_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("A&ntilde;adir audio a un video"),
                           tr("<center><b>A&ntilde;adir audio a un video<b></center><p>"

                           "Con esta utilidad puedes A&ntilde;adir audio a un video.<p>"

                           "Se creara un fichero final con el nuevo video y audio.<p>"

                           "IMPORTANTE: El nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.avi<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;A&ntilde;adir audio a video?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo de video"),
                                path,trUtf8("Archivos de video (*.avi *.mpg *.flv *.wmv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameOrigen1 = QFileDialog::getOpenFileName(this,tr("Abrir archivo de audio"),
                                path,trUtf8("Archivos de audio (*.mp3 *.ac3 *.wma *.wav)"));
            system("mv -v '"+fileNameOrigen1+"' `echo '"+fileNameOrigen1+"' | tr ' ' '_'`");
            if (fileNameOrigen1.isEmpty())
                 return;

            QString fileNameDestino = QFileDialog::getSaveFileName(this,tr("Guardar el fichero de video"),
                                path,trUtf8("Archivos de video (*.avi *.mpg *.flv *.wmv)"));
            if (fileNameDestino.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameOrigen1.replace(" ","_");
            QString fileName2 = fileNameDestino.replace(" ","_");
            QString cmd ="su - %1 -c \"ffmpeg -i %2 -i %3 -sameq -y %4\"";
            cmd=cmd.arg(user).arg(fileName1).arg(fileName).arg(fileName2);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionUnir_varios_video_en_uno_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Unir varios videos en uno"),
                           tr("<center><b>Unir varios videos en uno<b></center><p>"

                           "Con esta utilidad puedes unir varios videos en un video final, los"
                           "cuales tienen que tener la misma extension. EJEMPLO: Video1.avi Video2.avi<p>"

                           "IMPORTANTE: El nombre del fichero a grabar debe de expecificar "
                           "el tipo de extension. EJEMPLO: Nuevo_nombre<FONT COLOR=\"BLUE\"><b>.avi<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Unir varios videos en uno?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            int i;
            QStringList fileNameSort;
            QString fileName;           
            QString path="/home/%1/";
            path=path.arg(user);

            QStringList fileNameOrigen = QFileDialog::getOpenFileNames(this,tr("Abrir archivos de video"),
                                path,trUtf8("Archivos de video (*.avi *.mpg *.flv *.wmv)"));

            if (fileNameOrigen.isEmpty())
                 return;

            for(i=0;i<fileNameOrigen.count();i++ )
            {
                QString valor;
                valor=fileNameOrigen.value(i);
                system("mv -v '"+valor+"' `echo '"+valor+"' | tr ' ' '_'`");                
            }

            fileNameSort=fileNameOrigen.replaceInStrings(" ","_");
            fileName=fileNameOrigen.join(" ");

            QString fileNameDestino = QFileDialog::getSaveFileName(this,tr("Guardar el fichero de video"),
                                path,trUtf8("Archivos de video (*.avi *.mpg *.flv *.wmv)"));
            if (fileNameDestino.isEmpty())
                 return;

            QString fileName2 = fileNameDestino.replace(" ","_");
            QString cmd ="su - %1 -c \"mencoder -forceidx -oac copy -ovc copy -o %3 %2\"";
            cmd=cmd.arg(user).arg(fileName).arg(fileName2);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMp3_wma_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mp3 a .wma"),
                           tr("<center><b>Convertir formato .mp3 a .wma<b></center><p>"

                           "Conversion de .mp3 a .wma<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mp3"),
                                path,trUtf8("Archivo .mp3 (*.mp3)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wma?"),
                                path,trUtf8("Archivo .wma (*.wma)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 192k -y %3.wma\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMp3_wav_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mp3 a .wav"),
                           tr("<center><b>Convertir formato .mp3 a .wav<b></center><p>"

                           "Conversion de .mp3 a .wav<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mp3"),
                                path,trUtf8("Archivo .mp3 (*.mp3)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wav?"),
                                path,trUtf8("Archivo .wav (*.wav)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 192k -y %3.wav\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMp3_ac3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mp3 a .ac3"),
                           tr("<center><b>Convertir formato .mp3 a .ac3<b></center><p>"

                           "Conversion de .mp3 a .ac3<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mp3"),
                                path,trUtf8("Archivo .mp3 (*.mp3)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .ac3?"),
                                path,trUtf8("Archivo .ac3 (*.ac3)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 192k -y %3.ac3\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWma_mp3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wma a .mp3"),
                           tr("<center><b>Convertir formato .wma a .mp3<b></center><p>"

                           "Conversion de .wma a .mp3<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wma"),
                                path,trUtf8("Archivo .wma (*.wma)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mp3?"),
                                path,trUtf8("Archivo .mp3 (*.mp3)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 192k -y %3.mp3\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWma_wav_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wma a .wav"),
                           tr("<center><b>Convertir formato .wma a .wav<b></center><p>"

                           "Conversion de .wma a .wav<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wma"),
                                path,trUtf8("Archivo .wma (*.wma)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wav?"),
                                path,trUtf8("Archivo .wav (*.wav)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 192k -y %3.wav\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWma_ac3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wma a .ac3"),
                           tr("<center><b>Convertir formato .wma a .ac3<b></center><p>"

                           "Conversion de .wma a .ac3<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wma"),
                                path,trUtf8("Archivo .wma (*.wma)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wav?"),
                                path,trUtf8("Archivo .ac3 (*.ac3)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 192k -y %3.ac3\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Ripeando CD...";
            QString cmd1 = "su - %1 -c \"cdparanoia -vsZB\"";
            cmd1=cmd1.arg(user);
            QString cmd2 = "echo Moviendo y convirtiendo a destino selecionado...";
            QString cmd3 = "su - %1 -c \"RecoverMovemp3\"";
            cmd3=cmd3.arg(user);
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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Ripeando CD...";
            QString cmd1 = "su - %1 -c \"cdparanoia -vsZB\"";
            cmd1=cmd1.arg(user);
            QString cmd2 = "echo Moviendo y convirtiendo a destino selecionado...";
            QString cmd3 = "su - %1 -c \"RecoverMovewma\"";
            cmd3=cmd3.arg(user);
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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Ripeando CD...";
            QString cmd1 = "su - %1 -c \"cdparanoia -vsZB\"";
            cmd1=cmd1.arg(user);
            QString cmd2 = "echo Moviendo a destino selecionado...";
            QString cmd3 = "su - %1 -c \"RecoverMove\"";
            cmd3=cmd3.arg(user);
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

//***OPCION REVISADA Y TERMINADA***//
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
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "echo Ripeando CD...";
            QString cmd1 = "su - %1 -c \"cdparanoia -vsZB\"";
            QString cmd2 = "echo Moviendo y convirtiendo a destino selecionado...";
            QString cmd3 = "su - %1 -c \"RecoverMoveac3\"";
            cmd3=cmd3.arg(user);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWav_wma_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wav a .wma"),
                           tr("<center><b>Convertir formato .wav a .wma<b></center><p>"

                           "Conversion de .wav a .wma<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wav"),
                                path,trUtf8("Archivo .wav (*.wav)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wma?"),
                                path,trUtf8("Archivo .wma (*.wma)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 192k -y %3.wma\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWav_mp3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wav a .mp3"),
                           tr("<center><b>Convertir formato .wav a .mp3<b></center><p>"

                           "Conversion de .wav a .mp3<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wav"),
                                path,trUtf8("Archivo .wav (*.wav)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mp3?"),
                                path,trUtf8("Archivo .mp3 (*.mp3)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 192k -y %3.mp3\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWav_ac3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wav a .ac3"),
                           tr("<center><b>Convertir formato .wav a .ac3<b></center><p>"

                           "Conversion de .wav a .ac3<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wav"),
                                path,trUtf8("Archivo .wav (*.wav)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .ac3?"),
                                path,trUtf8("Archivo .ac3 (*.ac3)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 192k -y %3.ac3\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAc3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .ac3 a .wma"),
                           tr("<center><b>Convertir formato .ac3 a .wma<b></center><p>"

                           "Conversion de .ac3 a .wma<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .ac3"),
                                path,trUtf8("Archivo .ac3 (*.ac3)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wma?"),
                                path,trUtf8("Archivo .wma (*.wma)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 192k -y %3.wma\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAc3_mp3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .ac3 a .mp3"),
                           tr("<center><b>Convertir formato .ac3 a .mp3<b></center><p>"

                           "Conversion de .ac3 a .mp3<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .ac3"),
                                path,trUtf8("Archivo .ac3 (*.ac3)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mp3?"),
                                path,trUtf8("Archivo .mp3 (*.mp3)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 192k -y %3.mp3\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAc3_wav_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .ac3 a .wav"),
                           tr("<center><b>Convertir formato .ac3 a .wav<b></center><p>"

                           "Conversion de .ac3 a .wav<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .ac3"),
                                path,trUtf8("Archivo .ac3 (*.ac3)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wav?"),
                                path,trUtf8("Archivo .wav (*.wav)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ab 192k -y %3.wav\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAvi_HD_avi_Standar_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .avi HD a .avi Standard"),
                           tr("<center><b>Convertir formato .avi HD a .avi Standar<b></center><p>"

                           "Conversion de formatos avi HD (480p, 720p  y 1080p) a "
                           "formatos avi Standar antiguos.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .avi"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .avi?"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -vcodec mpeg4 -vtag XVID -s 592x352 -acodec libmp3lame -ab 128kb -y %3\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionDesempaquetar_matroska_y_convertir_a_avi_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Desempaquetar Matroska y convertir a avi"),
                           tr("<center><b>Desempaquetar Matroska y convertir a avi<b></center><p>"

                           "Desempaquetado de contenedor Matroska y conversion a formato avi.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Desempaquetar y convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mkv"),
                                path,trUtf8("Archivo .mkv (*.mkv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .avi?"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString ct ="echo Creando temporal. Por favor espere...";
            QString cm = "su - %1 -c \"cp %2 temp_mkv.mkv\"";
            cm=cm.arg(user).arg(fileName);
            QString cmd = "su - %1 -c \"mkvextract tracks temp_mkv.mkv 1:temp_video.avi 2:temp_audio.ac3 3:temp_sub.srt\"";
            cmd=cmd.arg(user);
            QString cmd1 = "su - %1 -c \"ffmpeg -i temp_video.avi -i temp_audio.ac3 -sameq -vcodec copy -s 592x352 -y %3\"";
            cmd1=cmd1.arg(user).arg(fileName1);
            QString cmd2 ="su - %1 -c \"rm -f temp_mkv.mkv temp_video.avi temp_sub.srt temp_audio.ac3\"";
            cmd2=cmd2.arg(user);
            QStringList comandos;
            comandos<<ct <<cm << cmd << cmd1 << cmd2;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAvi_mpg_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .avi a .mpg"),
                           tr("<center><b>Convertir formato .avi a .mpg<b></center><p>"

                           "Conversion de formatos avi a formatos mpg.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .avi"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mpg?"),
                                path,trUtf8("Archivo .mpg (*.mpg)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s 592x352 -acodec libmp3lame -ab 128kb -y %3.mpg\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAvi_dvd_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .avi a .dvd"),
                           tr("<center><b>Convertir formato .avi a .dvd<b></center><p>"

                           "Conversion de formatos avi a formatos dvd.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .avi"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Donde guardar ficheros de dvd?"),path,QFileDialog::ShowDirsOnly);
            if (fileNameDirectori.isEmpty())
                return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString cm = "su - %1 -c \"mkdir %2/DVD_DATA\"";
            cm=cm.arg(user).arg(path);
            QString cmd = "su - %1 -c \"ffmpeg -i %2 -sameq -s 592x352 -target pal-dvd -y %3/dvd.mpg";
            cmd=cmd.arg(user).arg(fileName).arg(fileNameDirectori);
            QString cmd1 = "su - %1 -c \"dvdauthor -o %2DVD_DATA/ -t %3/dvd.mpg";
            cmd1=cmd1.arg(user).arg(path).arg(fileNameDirectori);
            QString cmd2 = "su - %1 -c \"rm -f %2/dvd.mpg\"";
            cmd2=cmd2.arg(user).arg(fileNameDirectori);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAVI_WMV_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .avi a .wmv"),
                           tr("<center><b>Convertir formato .avi a .wmv<b></center><p>"

                           "Conversion de formatos avi a formatos wmv.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .avi"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wmv?"),
                                path,trUtf8("Archivo .wmv (*.wmv)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -vcodec wmv2 -acodec wmav2 -s 592x352 -ab 448kb -y %3.wmv\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAvi_flv_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .avi a .flv"),
                           tr("<center><b>Convertir formato .avi a .flv<b></center><p>"

                           "Conversion de formatos avi a formatos flv.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .avi"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .flv?"),
                                path,trUtf8("Archivo .flv (*.flv)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -threads 2 -r 30.00 -threads 1 -pix_fmt yuv420p -g 300 -qmin 3 -b 512k -async 50 -ar 11025 -ac 1 -s 592x352 -acodec libmp3lame -ab 128kb -y %3.flv\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAvi_3gp_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .avi a .3gp"),
                           tr("<center><b>Convertir formato .avi a .3gp<b></center><p>"

                           "Conversion de formatos avi a formatos 3gp.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .avi"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .3gp?"),
                                path,trUtf8("Archivo .3gp (*.3gp)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s qcif -r 12 -ac 1 -ar 8000 -b 30 -ab 12.2K -s 592x352 -y %3.3gp\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAvi_mp4_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .avi a .mp4"),
                           tr("<center><b>Convertir formato .avi a .mp4<b></center><p>"

                           "Conversion de formatos avi a formatos mp4.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .avi"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mp4?"),
                                path,trUtf8("Archivo .mp4 (*.mp4)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s qcif -r 12 -ac 1 -ar 8000 -b 30 -ab 12.2K -s 592x352 -y %3.mp4\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMpg_avi_2_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mpg a .avi"),
                           tr("<center><b>Convertir formato .mpg a .avi<b></center><p>"

                           "Conversion de formatos mpg a formatos avi.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mpg"),
                                path,trUtf8("Archivo .mpg (*.mpg)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .avi?"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s 592x352 -acodec libmp3lame -ab 128kb -y %3.avi\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMpg_dvd_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mpg a .dvd"),
                           tr("<center><b>Convertir formato .mpg a .dvd<b></center><p>"

                           "Conversion de formatos mpg a formatos DVD.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mpg"),
                                path,trUtf8("Archivo .mpg (*.mpg)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Donde guardar ficheros de dvd?"),path,QFileDialog::ShowDirsOnly);
            if (fileNameDirectori.isEmpty())
                return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString cm = "su - %1 -c \"mkdir %2/DVD_DATA\"";
            cm=cm.arg(user).arg(path);
            QString cmd = "su - %1 -c \"ffmpeg -i %2 -sameq -s 592x352 -target pal-dvd -y %3/dvd.mpg";
            cmd=cmd.arg(user).arg(fileName).arg(fileNameDirectori);
            QString cmd1 = "su - %1 -c \"dvdauthor -o %2DVD_DATA/ -t %3/dvd.mpg\"";
            cmd1=cmd1.arg(user).arg(path).arg(fileNameDirectori);
            QString cmd2 = "su - %1 -c \"rm -f %2/dvd.mpg\"";
            cmd2=cmd2.arg(user).arg(fileNameDirectori);
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

void recoverdrake::on_actionMPG_WMV_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mpg a .wmv"),
                           tr("<center><b>Convertir formato .mpg a .wmv<b></center><p>"

                           "Conversion de formatos mpg a formatos wmv.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mpg"),
                                path,trUtf8("Archivo .mpg (*.mpg)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wmv?"),
                                path,trUtf8("Archivo .wmv (*.wmv)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -vcodec wmv2 -acodec wmav2 -s 592x352 -ab 448kb -y %3.wmv\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMpg_flv_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mpg a .flv"),
                           tr("<center><b>Convertir formato .mpg a .flv<b></center><p>"

                           "Conversion de formatos mpg a formatos flv.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mpg"),
                                path,trUtf8("Archivo .mpg (*.mpg)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .flv?"),
                                path,trUtf8("Archivo .flv (*.flv)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -threads 2 -r 30.00 -threads 1 -pix_fmt yuv420p -g 300 -qmin 3 -b 512k -async 50 -ar 11025 -ac 1 -s 592x352 -acodec libmp3lame -ab 128kb -y %3.flv\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMpg_3gp_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mpg a .3gp"),
                           tr("<center><b>Convertir formato .mpg a .3gp<b></center><p>"

                           "Conversion de formatos mpg a formatos 3gp.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mpg"),
                                path,trUtf8("Archivo .mpg (*.mpg)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .3gp?"),
                                path,trUtf8("Archivo .3gp (*.3gp)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s qcif -r 12 -ac 1 -ar 8000 -b 30 -ab 12.2K -s 592x352 -y %3.3gp\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMpg_mp4_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mpg a .mp4"),
                           tr("<center><b>Convertir formato .mpg a .mp4<b></center><p>"

                           "Conversion de formatos mpg a formatos mp4.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mpg"),
                                path,trUtf8("Archivo .mpg (*.mpg)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mp4?"),
                                path,trUtf8("Archivo .mp4 (*.mp4)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s qcif -r 12 -ac 1 -ar 8000 -b 30 -ab 12.2K -s 592x352 -y %3.mp4\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

void recoverdrake::on_actionWmv_avi_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wmv a .avi"),
                           tr("<center><b>Convertir formato .wmv a .avi<b></center><p>"

                           "Conversion de formatos wmv a formatos avi.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wmv"),
                                path,trUtf8("Archivo .wmv (*.wmv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .avi?"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s 592x352 -acodec libmp3lame -ab 128kb -y %3.avi\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWmv_mpg_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wmv a .mpg"),
                           tr("<center><b>Convertir formato .wmv a .mpg<b></center><p>"

                           "Conversion de formatos wmv a formatos mpg.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wmv"),
                                path,trUtf8("Archivo .wmv (*.wmv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mpg?"),
                                path,trUtf8("Archivo .mpg (*.mpg)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s 592x352 -acodec libmp3lame -ab 128kb -y %3.mpg\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWmv_dvd_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wmv a .dvd"),
                           tr("<center><b>Convertir formato .wmv a .dvd<b></center><p>"

                           "Conversion de formatos wmv a formatos DVD.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wmv"),
                                path,trUtf8("Archivo .wmv (*.wmv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Donde guardar ficheros de dvd?"),path,QFileDialog::ShowDirsOnly);
            if (fileNameDirectori.isEmpty())
                return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString cm = "su - %1 -c \"mkdir %2/DVD_DATA\"";
            cm=cm.arg(user).arg(path);
            QString cmd = "su - %1 -c \"ffmpeg -i %2 -sameq -s 592x352 -target pal-dvd -y %3/dvd.mpg\"";
            cmd=cmd.arg(user).arg(fileName).arg(fileNameDirectori);
            QString cmd1 = "su - %1 -c \"dvdauthor -o %2/DVD_DATA/ -t %3/dvd.mpg\"";
            cmd1=cmd1.arg(user).arg(path).arg(fileNameDirectori);
            QString cmd2 = "su - %1 -c \"rm -f %2/dvd.mpg\"";
            cmd2=cmd2.arg(user).arg(fileNameDirectori);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWmv_flv_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wmv a .flv"),
                           tr("<center><b>Convertir formato .wmv a .flv<b></center><p>"

                           "Conversion de formatos wmv a formatos flv.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wmv"),
                                path,trUtf8("Archivo .wmv (*.wmv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .flv?"),
                                path,trUtf8("Archivo .flv (*.flv)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -threads 2 -r 30.00 -threads 1 -pix_fmt yuv420p -g 300 -qmin 3 -b 512k -async 50 -ar 11025 -ac 1 -s 592x352 -acodec libmp3lame -ab 128kb -y %3.flv\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWmv_3gp_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wmv a .3gp"),
                           tr("<center><b>Convertir formato .wmv a .3gp<b></center><p>"

                           "Conversion de formatos wmv a formatos 3gp.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wmv"),
                                path,trUtf8("Archivo .wmv (*.wmv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .3gp?"),
                                path,trUtf8("Archivo .3gp (*.3gp)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s qcif -r 12 -ac 1 -ar 8000 -b 30 -ab 12.2K -s 592x352 -y %3.3gp\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWmv_mp4_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .wmv a .mp4"),
                           tr("<center><b>Convertir formato .wmv a .mp4<b></center><p>"

                           "Conversion de formatos wmv a formatos mp4.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .wmv"),
                                path,trUtf8("Archivo .wmv (*.wmv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mp4?"),
                                path,trUtf8("Archivo .mp4 (*.mp4)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s qcif -r 12 -ac 1 -ar 8000 -b 30 -ab 12.2K -s 592x352 -y %3.mp4\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

void recoverdrake::on_actionFlv_avi_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .flv a .avi"),
                           tr("<center><b>Convertir formato .flv a .avi<b></center><p>"

                           "Conversion de formatos flv a formatos avi.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .flv"),
                                path,trUtf8("Archivo .flv (*.flv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .avi?"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s 592x352 -acodec libmp3lame -ab 128kb -y %3.avi\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionFlv_dvd_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .flv a .dvd"),
                           tr("<center><b>Convertir formato .flv a .dvd<b></center><p>"

                           "Conversion de formatos flv a formatos DVD.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .flv"),
                                path,trUtf8("Archivo .flv (*.flv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Donde guardar ficheros de dvd?"),path,QFileDialog::ShowDirsOnly);
            if (fileNameDirectori.isEmpty())
                return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString cm = "su - %1 -c \"mkdir %2/DVD_DATA\"";
            cm=cm.arg(user).arg(path);
            QString cmd = "su - %1 -c \"ffmpeg -i %2 -sameq -s 592x352 -target pal-dvd -y %3/dvd.mpg";
            cmd=cmd.arg(user).arg(fileName).arg(fileNameDirectori);
            QString cmd1 = "su - %1 -c \"dvdauthor -o %2DVD_DATA/ -t %3/dvd.mpg\"";
            cmd1=cmd1.arg(user).arg(path).arg(fileNameDirectori);
            QString cmd2 = "su - %1 -c \"rm -f %2/dvd.mpg\"";
            cmd2=cmd2.arg(user).arg(fileNameDirectori);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionFlv_wmv_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .flv a wvm"),
                           tr("<center><b>Convertir formato .flv a .wmv<b></center><p>"

                           "Conversion de formatos flv a formatos wmv.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .flv"),
                                path,trUtf8("Archivo .flv (*.flv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .wmv?"),
                                path,trUtf8("Archivo .wmv (*.wmv)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s qcif -r 12 -ac 1 -ar 8000 -b 30 -ab 12.2K -s 592x352 -y %3.wmv\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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
//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionFlv_mpg_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .flv a .mpg"),
                           tr("<center><b>Convertir formato .flv a .mpg<b></center><p>"

                           "Conversion de formatos flv a formatos mpg.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .flv"),
                                path,trUtf8("Archivo .flv (*.flv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .mpg?"),
                                path,trUtf8("Archivo .mpg (*.mpg)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s 592x352 -acodec libmp3lame -ab 128kb -y %3.mpg\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionFlv_3gp_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .flv a .3gp"),
                           tr("<center><b>Convertir formato .flv a .3gp<b></center><p>"

                           "Conversion de formatos flv a formatos 3gp.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .flv"),
                                path,trUtf8("Archivo .flv (*.flv)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .3gp?"),
                                path,trUtf8("Archivo .3gp (*.3gp)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s qcif -r 12 -ac 1 -ar 8000 -b 30 -ab 12.2K -s 592x352 -y %3.3gp\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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







//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMp4_avi_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Convertir formato .mp4 a .avi"),
                           tr("<center><b>Convertir formato .mp4 a .avi<b></center><p>"

                           "Conversion de formatos mp4 a formatos avi.<p>"

                           "Solo se puede convertir un fichero por vez.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Convertir formato?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .mp4"),
                                path,trUtf8("Archivo .mp4 (*.mp4)"));
            system("mv -v '"+fileNameOrigen+"' `echo '"+fileNameOrigen+"' | tr ' ' '_'`");
            if (fileNameOrigen.isEmpty())
                 return;

            QString fileNameDirectori = QFileDialog::getSaveFileName(this,tr("Guardar el fichero .avi?"),
                                path,trUtf8("Archivo .avi (*.avi)"));
            if (fileNameDirectori.isEmpty())
                 return;

            QString fileName = fileNameOrigen.replace(" ","_");
            QString fileName1 = fileNameDirectori.replace(" ","_");
            QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -sameq -s 592x352 -acodec libmp3lame -ab 128kb -y %3.avi\"";
            cmd1=cmd1.arg(user).arg(fileName).arg(fileName1);
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








//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionSaber_dependencias_de_librerias_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Saber librerias de binarios"),
                           tr("<center><b>Saber librerias de binarios<b></center><p>"

                           "Mediante esta utilidad, puedes saber todas las librerias "
                           "dependientes de un programa, a nivel informativo.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionActualizar_refrescar_soportes_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Actualizar soportes"),
                           tr("<center><b>Actualizar soportes<b></center><p>"

                           "Mediante esta utilidad, se actualizaran todos los "
                           "soportes para tener todas las sintesis al dia.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Actualizar soportes?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd1 = "urpmi.update -a";            
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionSaber_paquetes_dependientes_triggered()
{
    int respuesta = 0;
    bool ok;

    respuesta = QMessageBox::question(this, tr("Saber dependencias de paquete"),
                           tr("<center><b>Saber dependencias de paquete<b></center><p>"

                           "Mediante esta utilidad, puedes saber todos los paquetes "
                           "necesarios para una buena instalacion de un paquete "
                           "que queramos instalar, para que no haya problema de "
                           "dependencias.<p>"

                           "Muy util, cuando al instalar un paquete nos falla algo.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionSaber_el_repositorio_de_un_paquete_triggered()
{
    int respuesta = 0;
    bool ok;

    respuesta = QMessageBox::question(this, tr("Saber repositorio de un paquete"),
                           tr("<center><b>Saber repositorio de un paquete<b></center><p>"

                           "Mediante esta utilidad, puedes saber a que repositorio "
                           "pertenece un paquete en cuestion.<p>"

                           "Se lo mas expecifico posible para la busqueda, ya que si pones el "
                           "nombre lo mas completo posible, te limitara a menos posibilidades.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Saber repositorio de un paquete?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString texto = QInputDialog::getText(this, tr("Nombre del paquete a buscar"),
            tr("Introduzca el nombre del paquete a buscar.<P> "

            "<FONT COLOR=\"RED\">Ejemplo:<p>"

            "<FONT COLOR=\"RED\">RecoverDrake"),
            QLineEdit::Normal,
            "",
            &ok);
            if (ok && !texto.isEmpty()){

                QString cmd1 = "urpmf --filename --size --summary --license --vendor -m %1";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionLocalizador_de_archivos_en_repositorios_triggered()
{
    int respuesta = 0;
    bool ok;

    respuesta = QMessageBox::question(this, tr("Localizador de archivos en repositorios"),
                           tr("<center><b>Localizador de archivos en repositorios<b></center><p>"

                           "Mediante esta utilidad, puedes saber a que repositorio y paquete "
                           "pertenece un archivo en cuestion.<p>"

                           "Se lo mas expecifico posible para la busqueda, ya que si pones el "
                           "nombre lo mas completo posible, te limitara a menos posibilidades.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Localizar archivo en repositorios?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString texto = QInputDialog::getText(this, tr("Nombre del paquete a buscar"),
            tr("Introduzca el nombre del paquete a buscar.<P> "

            "<FONT COLOR=\"RED\">Ejemplo:<p>"

            "<FONT COLOR=\"RED\">libc.so.6"),
            QLineEdit::Normal,
            "",
            &ok);
            if (ok && !texto.isEmpty()){

                QString cmd1 = "urpmf %1";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionBorrar_regrabable_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Borrar disco regrabable"),
                           tr("<center><b>Borrar disco regrabable</center><p>"

                           "Utilidad para forzar el borrado/formateo del disco regrabable.<p>"

                           "IMPORTANTE: Utilizar solo en el caso de que el "
                           "disco no se autoformatee.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Borrar/Formatear disco?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd1 = "su - %1 -c \"dvd+rw-format -force /dev/dvd\"";
            cmd1=cmd1.arg(user);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionCopiar_iso_a_CD_DVD_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Copiar iso a soporte DVD/CD"),
                           tr("<center><b>Copiar iso a soporte DVD/CD</center><p>"

                           "Quemado de disco DVD/CD sobre una imagen ISO.<p>"

                           "Para un buen funcionamiento del lector/grabador, es "
                           "importante que se deje el disco introducido en la bandeja "
                           "abierta, ya que el proceso la cerrara automaticamente.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "Tambien se procedera a la expulsion del disco grabado "
                           "una vez haya finalizado.<p>"

                           "PRECAUCION: Cualquier disco que se introduzca SOBREESCRIBIRA "
                           "el contenido que hubiera por lo que se perderia su contenido original "
                           "y si fuera un regrabable, este sera formateado automaticamente, sin "
                           "previo aviso.<p>"

                           "&iquest;Copiar ISO a destino DVD/CD?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameOrigen = QFileDialog::getOpenFileName(this,tr("Abrir archivo .iso"),
                                path,trUtf8("Archivo .iso (*.iso)"));
            if (fileNameOrigen.isEmpty())
                 return;

            QString cmd1 = "su - %1 -c \"cdrecord -v dev=0,0,0 -data %2\"";
            cmd1=cmd1.arg(user).arg(fileNameOrigen);
            QString cmd2 = "eject /cdrw/";
            QStringList comandos;
            comandos<< cmd1 << cmd2;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionCopiar_CD_DVD_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Copiar DVD/CD"),
                           tr("<center><b>Copiar DVD/CD</center><p>"

                           "Duplicado de disco DVD/CD.<p>"

                           "Para un buen funcionamiento del lector/grabador, es "
                           "importante que se deje el disco introducido en la bandeja "
                           "abierta, ya que el proceso la cerrara automaticamente.<p>"

                           "Este proceso, puede tardar un tiempo, sea paciente, "
                           "la espera lo merece.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "Tambien se procedera a la expulsion del disco grabado "
                           "una vez haya finalizado.<p>"

                           "PRECAUCION: Cualquier disco que se introduzca SOBREESCRIBIRA "
                           "el contenido que hubiera por lo que se perderia su contenido original "
                           "y si fuera un regrabable, este sera formateado automaticamente, sin "
                           "previo aviso.<p>"

                           "&iquest;Copiar DVD/CD?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "su - %1 -c \"dd if=/dev/cdrom of=imagenburn.iso bs=2048 count=140564\"";
            cmd=cmd.arg(user);
            QString cmd1 = "su - %1 -c \"cdrecord -v dev=0,0,0 -data imagenburn.iso\"";
            cmd1=cmd1.arg(user);
            QString cmd2 = "eject /cdrw/";
            QString cmd3 = "su - %1 -c \"rm -f imagenburn.iso\"";
            cmd3=cmd3.arg(user);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionVaciar_papeleras_del_sistema_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Vaciar papelera de root"),
                           tr("<center><b>Vaciar papelera de root</center><p>"

                           "Con esta opcion vamos a ganar espacio en nuestro disco duro.<p>"

                           "Puede que por algun motivo hayas utilizado root para alguna "
                           "tarea y hayas borrado archivos y se este utilizando un espacio en "
                           "el disco duro que se esta desperdiciando tontamente, por lo que con esta tarea "
                           "de mantenimiento se borrara definitivamente el contenido de la papelera de root, "
                           "ubicada en una carpeta oculta dentro de /home, llamada .Trash-0 y "
                           "que al no estar visible, por defecto, puede estar perjudicando al espacio de tu "
                           "disco duro.<p>"

                           "PRECAUCION: Tenga en cuenta lo que esta haciendo, ya que dichos "
                           "ficheros y carpetas no se podran recuperar despues de vaciar las papeleras.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Comenzar tarea de mantenimiento?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            system("rm -r -f /home/.Trash-0/files/*");
            system("rm -r -f /home/.Trash-0/info/*");
            QString cmd3 = "echo Espacio ocupado despues del mantenimiento...";
            QString cmd4 = "du /home/.Trash-0/";
            QStringList comandos;
            comandos<< cmd3 << cmd4;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionLimpiar_temporales_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Vaciar temporales"),
                           tr("<center><b>Vaciar temporales</center><p>"

                           "Con esta opcion vamos a ganar espacio en nuestro disco duro.<p>"

                           "En las carpetas /tmp se van quedando residuos que no son necesarios "
                           "y se esta utilizando un espacio en el disco duro que se esta desperdiciando "
                           "tontamente, por lo que con esta tarea de mantenimiento se borrara definitivamente "
                           "el contenido de dichos temporales.<p>"

                           "PRECAUCION: Tenga en cuenta lo que esta haciendo, ya que dichos "
                           "ficheros y carpetas no se podran recuperar despues del mantenimiento, ademas "
                           "de que se debería reiniciar el sistema ya que algunos temporales pueden ser "
                           "requeridos por el sistema y deben ser reconstruidos.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Comenzar tarea de mantenimiento?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            system("rm -r -f /home/'"+user+"'/tmp/*");
            system("rm -r -f /tmp/*");
            system ("rm -r -f /root/tmp/*");
            QString cmd = "echo Procesos de limpieza realizados";
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

void recoverdrake::on_actionVaciar_logs_de_RecoverDrake_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Vaciar logs de RecoverDrake"),
                           tr("<center><b>Vaciar logs</center><p>"

                           "Se borrara el registro de sucesos de RecoverDrake.<p>"

                           "PROCEDA CON PRECAUCION. Perdera todos los registros de "
                           "uso de RecoverDrake.<p>"

                           "&iquest;Borrar Logs activo?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            system("rm -f /home/'"+user+"'/RecoverDrake.log");
            QString cmd = "date";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMenu_contextual_de_root_en_usuario_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Menu contextual con operaciones de root"),
                           tr("<center><b>Privilegios de root en usuario normal</center><p>"

                           "Con esta opcion podemos acceder a realizar mantenimientos y opciones de root "
                           "desde un usuario normal sin privilegios avanzados con solo "
                           "introducir la clave de root, cuando sea requerida.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar menu contextual de root?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString comando="/bin/sh urpmi -a --auto kde-rootactions-servicemenu";

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

void recoverdrake::on_actionHacer_CD_DVD_de_datos_triggered()
{
    burn *quemar=new burn(this);
    quemar->show();
}

void recoverdrake::on_actionHacer_DVD_de_video_triggered()
{
    burn *quemar=new burn(this);
    quemar->show();
}

void recoverdrake::on_actionHacer_CD_DVD_de_audio_triggered()
{
    burn *quemar=new burn(this);
    quemar->show();
}

void recoverdrake::on_actionHacer_CD_de_video_triggered()
{
    burn *quemar=new burn(this);
    quemar->show();
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAyuda_de_RecoverDrake_triggered()
{
    help *hp=new help(this);
    hp->show();
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionNota_de_la_versi_n_triggered()
{
    notas *note=new notas(this);
    note->show();
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::actionConsola_como_root()
{
    connect(ui->actionConsola_como_root,SIGNAL(triggered()),this,SLOT(Konsola_root()));
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::Konsola_root()
{
    system("konsole");
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::actionAcerca_de()
{
    connect(ui->actionAcerca_de,SIGNAL(triggered()),this,SLOT(Acerca_de()));
}

//***OPCION REVISADA Y TERMINADA***//
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
               "infinidad de soporte a problemas y configuraciones y extras.<p>"
               "Gracias por usarlo.<p>"
               "<center><a href=\"http://www.kapyderi.blogspot.com\">www.kapyderi-blogspot.com</a></center>"));
}

//***OPCION REVISADA Y TERMINADA***//
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
               "Leo Vasquez de ZonaQt por las horas de ayuda y explicaciones. Colaborador activo del proyecto RecoverDrake y creador de codigo.<p>"
               "Michael Jackson por la inspiracion mientras oigo su musica.<p>"
               "Luigi por su interes y pruebas.<p>"
               "vinxenso, porque si Internet fuera una persona, seguro seria el.<p>"
               "Carlos \"Toro\", no te olvido, estes donde estes - R.I.P. 25-08-2000.<p>"
               "Blogdrake y ZonaQt, porque sin ellas, no habria sido lo que es ahora RecoverDrake.<p>"

               "...si me dejo alguien que me perdone, pero es muuu tarde."));
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::actionAcerca_de_Qt()
{
    connect(ui->actionAcerca_de_Qt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::mibEscribir(QString valor)
{    
    bool opcion4;
    opcion4=ui->actionActivar_Logs_de_sucesos->isChecked();
    QSettings seting("myorg","Aplica");
    seting.setValue("opcion4",opcion4);
    ui->textEdit->append(valor);
    ui->lineEdit_8->setText(valor);    
    if (opcion4==true)
     {        
        system("echo '"+valor+"' >> /home/'"+user+"'/RecoverDrake.log");
     }
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::closeEvent(QCloseEvent *event)
{
    bool opcion3;
    opcion3=ui->actionMinimizar_al_Salir->isChecked();
    QSettings seting("myorg","Aplica");
    seting.setValue("opcion3",opcion3);
    if (opcion3==true)
     {
        if (trayIcon->isVisible()) {
        QMessageBox::information(this, tr("Systray"),
        tr("El programa seguira corriendo en la bandeja del sistema.\n"));
        hide();
        event->ignore();}
      }
      close();
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMinimizar_al_Salir_triggered(bool d)
{
    QMessageBox m;
    bool opcion3;
    opcion3=ui->actionMinimizar_al_Salir->isChecked();
    QSettings seting("myorg","Aplica");
    seting.setValue("opcion3",opcion3);
    if (d==true)
     {
        int respuesta = 0;

        respuesta = QMessageBox::question(this, tr("Minimizar a la bandeja del sistema"),
                               tr("Puede mandar el programa a la bandeja del sistema "
                               "en vez de cerrar directamente.<p>"

                               "Para terminar completamente el uso del programa seleccione "
                               "<b>Quit</b> del menu contextual del icono o desactive de "
                               "nuevo esta opcion.<p>"

                               "&iquest;Activar el minimizar a la bandeja?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){

            m.setText("Se ha activado el icono de la bandeja del sistema");
            }
     }
    else
    {
        m.setText("Se ha desactivado el icono de la bandeja del sistema.<p>""Utilice esta opcion para volver a activarla.");
    }
    m.exec();
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::crearIcono()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::setIcono()
{
    trayIcon->setIcon(QIcon("/usr/share/icons/RecoverDrake.png"));
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::crearAcciones()
{
         minimizeAction = new QAction(tr("Mi&nimize"), this);
         connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

         maximizeAction = new QAction(tr("Ma&ximize"), this);
         connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

         restoreAction = new QAction(tr("&Restore"), this);
         connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

         quitAction = new QAction(tr("&Quit"), this);
         connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionActivar_Desactivar_inicio_con_Linux_triggered(bool b)
{
    QMessageBox m;
    bool opcion;
    opcion=ui->actionActivar_Desactivar_inicio_con_Linux->isChecked();
    QSettings seting("myorg","Aplica");
    seting.setValue("opcion",opcion);
   if (b==true)
    {
       QString cmd = "cp /usr/share/applications/RecoverDrake.desktop /home/%1/.config/autostart/RecoverDrake.desktop";
       cmd = cmd.arg(user);
       QStringList comandos;
       comandos<< cmd;

       if (mib != 0)
       delete mib;
       mib = new DrakeProcesos(comandos, this);
       connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
       connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
       mib->iniciarProceso();
       m.setText("Se ha activado el inicio automatico con Linux");
    }
   else
   {
       QString cmd = "rm -f /home/%1/.config/autostart/RecoverDrake.desktop";
       cmd = cmd.arg(user);
       QStringList comandos;
       comandos<< cmd;

       if (mib != 0)
       delete mib;
       mib = new DrakeProcesos(comandos, this);
       connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
       connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
       mib->iniciarProceso();
       m.setText("Se ha desactivado el inicio automatico con Linux");
   }
   m.exec();
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::chekar(bool b)
{
    QSettings seting("myorg","Aplica");
    seting.setValue("opcion",b);
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::chekar1(bool c)
{
    if (ui->actionComprabar_depndencias_RecoverDrake->isChecked()==true)
    {
        ui->lineEdit_7->setText("COMPROBACION DE DEPENDENCIAS ACTIVADA.");
    }
    else
    {
        ui->lineEdit_7->setText("ATENCION: LA COMPROBACION DE DEPENDENCIAS NO ESTA ACTIVADA. PUEDE QUE RECOVERDRAKE NO FUNCIONE CORRECTAMENTE.");
    }
    QSettings seting("myorg","Aplica");
    seting.setValue("opcion1",c);
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::chekar2(bool a)
{
    if (ui->actionSugerencias_y_avisos->isChecked()==true)
    {
        Dialog *sugerencias=new Dialog(this);
        sugerencias->exec();
    }
    QSettings seting("myorg","Aplica");
    seting.setValue("opcion2",a);
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::chekar3(bool d)
{
    QSettings seting("myorg","Aplica");
    seting.setValue("opcion3",d);
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::chekar4(bool e)
{
    QSettings seting("myorg","Aplica");
    seting.setValue("opcion4",e);
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionActivar_Logs_de_sucesos_triggered(bool e)
{    
    int respuesta = 0;
    QMessageBox m;
    bool opcion4;
    opcion4=ui->actionActivar_Logs_de_sucesos->isChecked();
    QSettings seting("myorg","Aplica");
    seting.setValue("opcion4",opcion4);
    if (e==true)
     {
        m.setText("Se ha activado los logs del sistema.");
     }
    else
    {
        m.setText("Se ha desactivado las logs del sistema.<p>""Utilice esta opcion para volver a activarla.");
        respuesta = QMessageBox::question(this, tr("Borrar Logs actual"),
                               tr("<center><b>Borrar Logs actual</center><p>"

                               "&iquest;Borrar Logs activo?"), QMessageBox::Ok, QMessageBox::No);

        if (respuesta == QMessageBox::Ok){
            system("rm -f /home/'"+user+"'/RecoverDrake.log");
        }
    }
    m.exec();
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionActualizar_DB_Virus_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Actualizacion de la DB de firmas de Virus"),
                           tr("<center><b>Actualizacion de DB de firmas</center><p>"

                           "Se accedera a internet y se actualizara la base de datos "
                           "de firmas de virus, para estar completamente al dia.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Actualizar Antivirus?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "freshclam";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionScanear_Virus_2_triggered()
{
    int respuesta = 0;
   
    respuesta = QMessageBox::question(this, tr("Escanear en busca de virus"),
                           tr("<center><b>Escanear en busca de virus</center><p>"

                           "Partimos de la base de que no se necesita un antivirus "
                           "para linux, pero si que puedes tener en perfecta sintonia "
                           "una particion con Guindows, por lo que seria necesario "
                           "tener un antivirus activo para que no sea infectada "
                           "dicha unidad.<p>"

                           "PROCEDA CON PRECAUCION: Si encuentra cualquier virus, eliminara el "
                           "fichero contenedor del mismo, por lo que se borrara del "
                           "sistema.<p>"

                           "Con esta opcion se busca y elimina cualquier tipo de virus "
                           "que haya en tu sistema.<p>"

                           "<b>IMPORTANTE: El directorio raiz de escaneado, no puede tener espacios "
                           "en el nombre.<p></b>"

                           "Se generara un fichero con los ficheros infectados.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos. Este proceso puede ser muy prolongado.</B><p>"

                           "&iquest;Escanear virus?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){
                                         
            QString path="/home/%1/";
            path=path.arg(user);

            QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Que directorio escanear?"),path,QFileDialog::ShowDirsOnly);
            if (fileNameDirectori.isEmpty())
                return;
                        
            QString cmd = "su - %1 -c \"clamscan -r --move=/home/%1/tmp --heuristic-scan-precedence --detect-broken --block-encrypted --algorithmic-detection %2\"";
            cmd=cmd.arg(user).arg(fileNameDirectori);
            QString cmd1 ="su - %1 -c \"RecoverAntivirus\"";
            cmd1=cmd1.arg(user);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionBorrar_ficheros_de_Cuarentena_triggered()
{
    int respuesta = 0;

    system("dolphin /home/'"+user+"'/tmp");
    respuesta = QMessageBox::question(this, tr("Borrar ficheros de cuarentena"),
                           tr("<center><b>Borrar ficheros de cuarentena</center><p>"

                           "Con esta utilidad borraremos los ficheros que tengamos en "
                           "cuarentena, que estan alojados en la carpeta /tmp de tu "
                           "usuario.<p>"

                           "Es interesante que revise los ficheros a borrar, ya que puede "
                           "haber algo importante. En el caso de tener algo que no se quiera "
                           "borrar, cambielo de ubicacion en el navegador de ficheros que "
                           "se ha abierto junto con esta funcion.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos. Este proceso puede ser muy prolongado.</B><p>"

                           "&iquest;Vaciar Cuarentena?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString path="/home/%1/";
            path=path.arg(user);

            system("dolphin "+path+"/tmp");
            QString cmd = "su - %1 -c \"clamscan -r --remove --heuristic-scan-precedence --detect-broken --block-encrypted --algorithmic-detection /home/%1/tmp\"";
            cmd=cmd.arg(user);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionListar_logs_de_accesos_triggered()
{
    Visualizar *Visual=new Visualizar(this);
    Visual->show();
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAmarok_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Amarok"),
                           tr("<center><b>Instalar Amarok</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Amarok.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Amarok?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto amarok";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionExaile_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Exaile"),
                           tr("<center><b>Instalar Exaile</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Exaile.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Exaile?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto exaile streamripper";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAudacius_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Audacious"),
                           tr("<center><b>Instalar Audacious</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Audacious.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Audacious?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto audacious";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionBanshee_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Banshee"),
                           tr("<center><b>Instalar Banshee</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Banshee.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Banshee?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto banshee";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionRhythmbox_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Rhythmbox"),
                           tr("<center><b>Instalar Rhythmbox</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Rhythmbox.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Rhythmbox?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto rhythmbox";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionXmms_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Xmms"),
                           tr("<center><b>Instalar Xmms</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Xmms.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Xmms?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto xmms";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionTodos_3_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Todos"),
                           tr("<center><b>Instalar Todos</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar todos los reproductores de audio?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto amarok exaile streamripper audacious banshee rhythmbox xmms";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionInstalar_Pack_de_Juegos_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Juegos): Pack"),
                           tr("<center><b>Instalar Pack de juegos</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "Este proceso es prolongado, ya que se descargaran unas "
                           "4 Gb de juegos aproximadamente.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Pack de Juegos?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto task-games";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionCairo_Dock_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Docks): Cairo"),
                           tr("<center><b>Instalar Cairo</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Cairo.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Cairo?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto cairo-dock";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionDragonPlayer_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Dragon Player"),
                           tr("<center><b>Instalar Dragon Player</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Dragon Player.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Dragon Player?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto dragonplayer";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionKaffeine_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Kaffeine"),
                           tr("<center><b>Instalar Kaffeine</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Kaffeine.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Kaffeine?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto kaffeine4";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionTotem_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Totem"),
                           tr("<center><b>Instalar Totem</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Totem.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Totem?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto totem-gstreamer";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionVlc_2_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): VLC"),
                           tr("<center><b>Instalar VLC</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: VLC.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar VLC?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto vlc-plugin-a52 vlc-plugin-aa vlc-plugin-dv vlc-plugin-dvdnav vlc-plugin-flac vlc-plugin-fluidsynth vlc-plugin-ggi vlc-plugin-mod vlc-plugin-ogg vlc-plugin-opengl vlc-plugin-pulse vlc-plugin-schroedinger vlc-plugin-sdl vlc-plugin-speex vlc-plugin-theora vlc-plugin-twolame vlc-plugin-xosd svlc";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionSmplay7er_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Smplayer"),
                           tr("<center><b>Instalar Smplayer</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Smplayer.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Smplayer?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto smplayer";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionKmplayer_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Kmplayer"),
                           tr("<center><b>Instalar Kmplayer</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Kmplayer.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Kmplayer?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto kmplayer mplayerplugin";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionParole_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Parole"),
                           tr("<center><b>Instalar Parole</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Parole.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Parole?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto parole parole-browser-plugin";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionXine_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Xine"),
                           tr("<center><b>Instalar Xine</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Xine.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Xine?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto xine-ui";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionTodos_2_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Reproductores de audio): Todos"),
                           tr("<center><b>Instalar Todos</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Todos los reproductores de audio?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto dragonplayer kaffeine4 totem-gstreamer "
                          "vlc-plugin-a52 vlc-plugin-aa vlc-plugin-dv vlc-plugin-dvdnav "
                          "vlc-plugin-flac vlc-plugin-fluidsynth vlc-plugin-ggi vlc-plugin-mod "
                          "vlc-plugin-ogg vlc-plugin-opengl vlc-plugin-pulse vlc-plugin-schroedinger "
                          "vlc-plugin-sdl vlc-plugin-speex vlc-plugin-theora vlc-plugin-twolame "
                          "vlc-plugin-xosd svlc smplayer kmplayer mplayerplugin parole "
                          "parole-browser-plugin xine-ui";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAmsn_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Clientes de Mensajeria): Amsn"),
                           tr("<center><b>Instalar Amsn</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Amsn.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Amsn?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto amsn";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionPidgin_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Clientes de Mensajeria): Pidgin"),
                           tr("<center><b>Instalar Pidgin</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Pidgin.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Pidgin?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto pidgin-plugins pidgin-musictracker "
                          "pidgin-guifications pidgin-plugin-pack";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionKopete_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Clientes de Mensajeria): Kopete"),
                           tr("<center><b>Instalar Kopete</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Kopete.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Kopete?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto kopete";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionEmesene_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Clientes de Mensajeria): Emesene"),
                           tr("<center><b>Instalar Emesene</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Emesene.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Emesene?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto emesene";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionKmess_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Clientes de Mensajeria): Kmess"),
                           tr("<center><b>Instalar Kmess</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Kmess.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Kmess?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto kmess";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionSkype_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Clientes de Mensajeria): Skype"),
                           tr("<center><b>Instalar Skype</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Skype.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Skype?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto skype";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionTodos_4_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Clientes de Mensajeria): Todos"),
                           tr("<center><b>Instalar Todos</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Todos los Clientes de Mensajeria?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto amsn pidgin-plugins pidgin-musictracker "
                          "pidgin-guifications pidgin-plugin-pack kopete emesene kmess skype";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionEkiga_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Videoconferencia): Ekiga"),
                           tr("<center><b>Instalar Ekiga</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Ekiga.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Ekiga?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto ekiga";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionGnokii_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Videoconferencia): Gnokii"),
                           tr("<center><b>Instalar Gnokii</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Gnokii.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Gnokii?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto gnokii-xgnokii";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionPhone_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Videoconferencia): Phone"),
                           tr("<center><b>Instalar Phone</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Phone.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Phone?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto gnome-phone-manager";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionTodos_5_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Videoconferencia): Todos"),
                           tr("<center><b>Instalar Todos</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Todos los de Videoconferencia?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto ekiga gnokii-xgnokii gnome-phone-manager";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionVuze_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): Vuze"),
                           tr("<center><b>Instalar Vuze</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Vuze.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Vuze?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto vuze";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAmule_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): Amule"),
                           tr("<center><b>Instalar Amule</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Amule.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Amule?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto amule";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionApollon_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): Apollon"),
                           tr("<center><b>Instalar Apollon</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Apollon.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Apollon?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto apollon gift gift-gnutella gift-openft";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionKtorrent_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): Ktorrent"),
                           tr("<center><b>Instalar Ktorrent</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Ktorrent.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Ktorrent?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto ktorrent";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionDeluge_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): Deluge"),
                           tr("<center><b>Instalar Deluge</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Deluge.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Deluge?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto deluge";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionTransmission_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): Transmission"),
                           tr("<center><b>Instalar Transmission</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Transmission.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Transmission?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto transmission transmission-gtk transmission-qt4";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionNicotine_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): Nicotine"),
                           tr("<center><b>Instalar Nicotine</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Nicotine.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Nicotine?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto nicotine";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionFrostwire_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): Frostwire"),
                           tr("<center><b>Instalar Frostwire</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Frostwire.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Frostwire?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto frostwire";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMegaupload_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): Megaupload"),
                           tr("<center><b>Instalar Megaupload</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Megaupload.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Megaupload?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto megaupload-dl";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionJdownloader_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): Jdownloader"),
                           tr("<center><b>Instalar Jdownloader</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Jdownloader.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Jdownloader?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto JDownloader";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMegaJc_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): MegaJc"),
                           tr("<center><b>Instalar MegaJc</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: MegaJc.<p>"

                           "<b>IMPORTANTE: MegaJc no esta en los repositorios, ni se le espera "
                           "por lo que accedes a Internet y descargamos el paquete en formato .deb, "
                           "luego lo transformamos automaticamente y despues son instaladas las "
                           "dependencias necesarias para que todo funcione correctamente.</b><p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar MegaJc?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "wget http://nexxuz.com/repositorios/ubuntu/megajc/stable.deb";
            QString cmd1 ="fakeroot alien -r -c stable.deb";
            QString cmd2 ="urpmi megajc-reloaded-1.0.12-2.noarch.rpm";            
            QString cmd3 ="rm -f stable.deb megajc-reloaded-1.0.12-2.noarch.rpm";
            QString cmd4 ="urpmi -a --auto python-gdata curl wput ffmpeg libnotify wondershaper gambas2";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionEd2k_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): Ed2k"),
                       tr("<center><b>Instalar Ed2k</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Ed2k.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Ed2k?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto ed2k-gtk-gui";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionTodos_6_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (P2P): Todos"),
                           tr("<center><b>Instalar Todos</center><p>"

                           "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                           "para un completo uso de tu sistema operativo.<p>"

                           "En este caso: Todos.<p>"

                           "<B>NOTA: Debe esperar a que termine completamente el "
                           "proceso seleccionado, el cual le sera notificado "
                           "cuando finalice, en la consola de procesos.</B><p>"

                           "&iquest;Instalar Todos los clientes de p2p?"), QMessageBox::Ok, QMessageBox::No);

    if (respuesta == QMessageBox::Ok){

            QString cmd = "urpmi --wget --auto vuze amule apollon gift gift-gnutella gift-openft "
                          "ktorrent deluge transmission transmission-gtk transmission-qt4 nicotine "
                          "frostwire megaupload-dl JDownloader ed2k-gtk-gui";
            QString cmd1 = "wget http://nexxuz.com/repositorios/ubuntu/megajc/stable.deb";
            QString cmd2 ="fakeroot alien -r -c stable.deb";
            QString cmd3 ="urpmi megajc-reloaded-1.0.12-2.noarch.rpm";
            QString cmd4 ="rm -f stable.deb megajc-reloaded-1.0.12-2.noarch.rpm";
            QString cmd5 ="urpmi -a --auto python-gdata curl wput ffmpeg libnotify wondershaper gambas2";
            QStringList comandos;
            comandos<< cmd << cmd1 << cmd2 << cmd3 << cmd4 <<cmd5;

            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            mib->iniciarProceso();}
            return;
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionK3b_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Quemadores CD/DVD): K3b"),
                       tr("<center><b>Instalar K3b</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: K3b.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar K3b?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto k3b";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionBrasero_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Quemadores CD/DVD): Brasero"),
                       tr("<center><b>Instalar Brasero</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Brasero.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Brasero?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto brasero";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionTodos_11_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Quemadores CD/DVD): Todos"),
                       tr("<center><b>Instalar Todos</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Todos.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Todos?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto k3b brasero";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAkr_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Compresores): Ark"),
                       tr("<center><b>Instalar Ark</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Ark.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Ark?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto ark";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionUnrar_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Compresores): Pack Unrar/Zip/Arj/7Zip"),
                       tr("<center><b>Instalar Pack Unrar/Zip/Arj/7Zip</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Pack Unrar/Zip/Arj/7Zip.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Pack Unrar/Zip/Arj/7Zip?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto gzip bzip2 tar zip unzip unrar lha p7zip arj unarj zoo unace cabextract";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionFile_Roller_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Compresores): File-Roller"),
                       tr("<center><b>Instalar File-Roller</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: File-Roller.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar File-Roller?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto file-roller";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionXarchiver_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Compresores): Xarchiver"),
                       tr("<center><b>Instalar Xarchiver</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Xarchiver.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Xarchiver?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto xarchiver";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionDalle_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Compresores): Dalle"),
                       tr("<center><b>Instalar Dalle</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Dalle.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Dalle?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto dalle";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionTodos_7_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Compresores): Todos"),
                       tr("<center><b>Instalar Todos</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Todos.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Todos los Compresores?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto ark gzip bzip2 tar zip unzip unrar lha p7zip arj unarj zoo unace cabextract file-roller xarchiver dalle";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionC_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Programacion): C"),
                       tr("<center><b>Instalar C</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: C.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar C?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto task-c-devel";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionC_2_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Programacion): C++"),
                       tr("<center><b>Instalar C++</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: C++ (RecoverDrake esta escrito en C++ y Qt).<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar C++?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto task-c++-devel";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionQt_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Programacion): Qt"),
                       tr("<center><b>Instalar Qt</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Qt (RecoverDrake esta escrito en C++ y Qt).<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Qt?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto --force libqt4-devel qt-creator qt4-designer";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionRpm_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Programacion): Rpm"),
                       tr("<center><b>Instalar Rpm</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Rpm.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Rpm?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto rpmlint rpm-build spec-helper libtool easyrpmbuilder";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionFortran_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Programacion): Fortran"),
                       tr("<center><b>Instalar Fortran</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Fortran.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Fortran?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto gcc-gfortran";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionGambas_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Programacion): Gambas"),
                       tr("<center><b>Instalar Gambas</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Gambas.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Gambas?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget --auto gambas2-ide gambas2-gb-gui";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionJava_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Programacion): Java"),
                       tr("<center><b>Instalar Java</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Java.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Java?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto java-1.6.0-sun eclipse netbeans";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionTodos_8_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Programacion): Todos"),
                       tr("<center><b>Instalar Todos</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Todos.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Todos los paquetes de programacion?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto task-c-devel task-c++-devel libqt4-devel qt-creator qt4-designer "
                      "rpmlint rpm-build spec-helper libtool easyrpmbuilder gcc-gfortran gambas2-ide gambas2-gb-gui "
                      "java-1.6.0-sun eclipse netbeans";
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

void recoverdrake::on_actionCerrar_sesion_activa_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Cerrar sesion activa"),
                       tr("<center><b>Cerrar sesion activa</center><p>"

                       "Con esta utilidad puedes cerrar la sesion activa y se "
                       "volvera al gestor de accesos.<p>"

                       "&iquest;Entrar en modo consola?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){
    system("killall X");}
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionReiniciar_equipo_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Reiniciar sistema"),
                       tr("<center><b>Reiniciar sistema</center><p>"

                       "Puede pasar que no podamos apagar o reiniciar el "
                       "equipo por que no aparecen los botones correspondientes "
                       "o en su defecto, fallan.<p>"

                       "Con esta utilidad puedes reiniciar el sistema sin peligro, "
                       "ya que antes de hacerlo, deja todos los procesos cerrados.<p>"

                       "&iquest;Reiniciar sistema?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){
    system("reboot");}
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionApagar_equipo_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Apagar sistema"),
                       tr("<center><b>Apagar sistema</center><p>"

                       "Puede pasar que no podamos apagar o reiniciar el "
                       "equipo por que no aparecen los botones correspondientes "
                       "o en su defecto, fallan.<p>"

                       "Con esta utilidad puedes apagar el sistema sin peligro, "
                       "ya que antes de hacerlo, deja todos los procesos cerrados.<p>"

                       "&iquest;Apagar sistema?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){
    system("halt");}
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionEntrar_en_modo_consola_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Entrar en modo consola"),
                       tr("<center><b>Entrar en modo consola</center><p>"

                       "Puede que tengamos que hacer algo en consola sin tener "
                       "abierto el servidor grafico (X), como por ejemplo instalar "
                       "los drivers privativos de nvidia.<p>"

                       "Con esta utilidad puedes cerrar el servidor grafico y "
                       "hacer los procesos necesarios desde la terminal sin peligro "
                       "de tener procesos graficos activados.<p>"

                       "IMPORTANTE: Para volver otra vez al servidor grafico tienes que "
                       "escribir como <b>root</b>, el siguiente comando: <p>"
                       "<b>init 5</b><p>"

                       "&iquest;Entrar en modo consola?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){
    system("init 3");}
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionProcesos_activos_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Control de procesos"),
                       tr("<center><b>Control de procesos</center><p>"

                       "Control de todos los procesos activos, tanto del usuario como "
                       "de root, incluso se pueden matar cualquiera de los procesos "
                       "que necesitemos hacerlo.<p>"

                       "&iquest;Abrir consola de procesos?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){
    system("konsole -e top");}
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWine_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Emulacion): Wine"),
                       tr("<center><b>Instalar Wine</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Wine.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Wine?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto wine";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionWine_doors_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Emulacion): Wine-doors"),
                       tr("<center><b>Instalar Wine-doors</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Wine-doors.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Wine-doors?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto wine-doors";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionPlayonlinux_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Emulacion): Playonlinux"),
                       tr("<center><b>Instalar Playonlinux</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Playonlinux.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Playonlinux?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto playonlinux";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionVirtualBox_2_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Emulacion): Virtualbox"),
                       tr("<center><b>Instalar Virtualbox</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Virtualbox.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Virtualbox?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto virtualbox virtualbox-guest-additions dkms-virtualbox";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionQuemu_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Emulacion): Qemu"),
                       tr("<center><b>Instalar Qemu</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Qemu.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Qemu?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto qemu-launcher qemu qemu-img";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionM_A_M_E_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Emulacion): M.A.M.E."),
                       tr("<center><b>Instalar M.A.M.E.</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: M.A.M.E.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar M.A.M.E.?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto sdlmame sdlmame-extra-data";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionRock_Diamonds_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Emulacion): Rocks'n'Diamonds"),
                       tr("<center><b>Instalar Rocks'n'Diamonds</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Rocks'n'Diamonds<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Rocks'n'Diamonds?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto rocksndiamonds";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionPack_Emuladores_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Emulacion): Pack emuladores"),
                       tr("<center><b>Instalar Pack emuladores</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Pack emuladores<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Pack emuladores?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto desmume arnold atari800-sdl boycotadvance dosbox dosemu e-uae epsxe fceux frodo"
                      "fuse-emulator fuse-emulator-utils fuse-utils gcube gens-gs gngeo gngb goosnes hatari lxdream mednafen "
                      "openmsx osmose snes9x vice zsnes";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionTodos_9_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Emulacion): Todos"),
                       tr("<center><b>Instalar Todos</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Todos.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar todos los paquetes de emulacion?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto wine wine-doors playonlinux virtualbox virtualbox-guest-additions dkms-virtualbox "
                      "qemu-launcher qemu qemu-img sdlmame sdlmame-extra-data rocksndiamonds desmume arnold atari800-sdl "
                      "boycotadvance dosbox dosemu e-uae epsxe fceux frodo fuse-emulator fuse-emulator-utils fuse-utils "
                      "gcube gens-gs gngeo gngb goosnes hatari lxdream mednafen openmsx osmose snes9x vice zsnes";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionSoundStudio_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Conversores): SoundStudio"),
                       tr("<center><b>Instalar SoundStudio</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: SoundStudio<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar SoundStudio?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto task-sound-studio";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionSoundConverter_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Conversores): SoundConverter"),
                       tr("<center><b>Instalar SoundConverter</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: SoundConverter<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar SoundConverter?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto soundconverter";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAudioKonverter_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Conversores): AudioKonverter"),
                       tr("<center><b>Instalar AudioKonverter</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: AudioKonverter<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar AudioKonverter?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto audiokonverter";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionMixxx_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Conversores): Mixxx"),
                       tr("<center><b>Instalar Mixxx</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Mixxx<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Mixxx?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto mixxx";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionAvidemux_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Conversores): Avidemux"),
                       tr("<center><b>Instalar Avidemux</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Avidemux<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar Avidemux?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto avidemux";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionDvDRip_triggered()
{
    int respuesta = 0;

    respuesta = QMessageBox::question(this, tr("Imprescindibles (Conversores): dvd::rip"),
                       tr("<center><b>Instalar dvd::rip</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: dvd::rip<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar dvd::rip?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto dvdrip";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionTodos_10_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Conversores): Todos"),
                       tr("<center><b>Instalar Todos</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados imprescindibles "
                       "para un completo uso de tu sistema operativo.<p>"

                       "En este caso: Todos.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar todos los paquetes de conversion?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto task-sound-studio soundconverter audiokonverter mixxx avidemux dvdrip";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionInstalar_Recomendables_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Imprescindibles (Recomendables)"),
                       tr("<center><b>Instalar Recomendables</center><p>"

                       "Con esta opcion vamos a instalar paquetes considerados recomendables "
                       "para un completo uso de tu sistema operativo y siempre siguiendo mi "
                       "criterio personal.<p>"

                       "En este caso: festival, amor, koffice, matrix, openoffice, kshisen (mahjongg), gimp, etc.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Instalar recomendables?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto festival amor koffice-l10n-es koffice xscreensaver-matrix tmux "
                      "kate task-blackberry-gnome task-3ddesktop-kde openoffice.org openoffice.org-help-es "
                      "xsane-gimp gimp kttsd gaupol alsamixergui asunder compiz-fusion";
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionSystemSetting_como_root_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("SytemSetting como root"),
                       tr("<center><b>SystemSetting como root</center><p>"

                       "Con esta opcion sirve para configurar el escritorio, pero en este "
                       "caso como root, ya que por ejemplo para cambiar la ventana de "
                       "bienvenida por otra es necesario acceder a el como root.<p>"

                       "&iquest;Acceder a SystemSetting?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok)
        {
            system("systemsettings");
        }
        return;
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionError_en_ventanas_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Sin marco de ventana en compiz-fusion"),
                       tr("<center><b>Sin marco de ventana en compiz-fusion</center><p>"

                       "Con esta opcion arreglaremos el problema de las ventanas "
                       "al instalar emerald y paquetes complementarios de compiz-fusion, "
                       "por lo que se instala o comprueba si esta instalado y despues se "
                       "acceda a su configuracion.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Preparar para arreglar marco de ventana de compiz-fusion?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "urpmi --wget -a --auto emerald compiz compiz-fusion compiz-fusion-icon compiz-fusion-plugins-extra compiz-fusion-plugins-unsupported gset-compiz";
        QString cmd1 ="su - %1 -c \"emerald-theme-manager\"";
        cmd1=cmd1.arg(user);
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

//***OPCION REVISADA Y TERMINADA***//       
void recoverdrake::on_actionConfigurar_emerald_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Configurar emerald"),
                       tr("<center><b>Configurar emerald</center><p>"

                       "Con esta opcion sirve para configurar la decoracion de las "
                       "ventanas de compiz-fusion.<p>"

                       "&iquest;Acceder a emerald?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok)
            {
                system("su - "+user+" -c \"emerald-theme-manager\"");
            }
            return;
}

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionCompizfussion_icon_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Activar Fusion Icon"),
                       tr("<center><b>Activar Fusion Icon</center><p>"

                       "NOTA MUY IMPORTANTE: NO ACTIVE ESTA OPCION SI NO TIENE "
                       "COMPIZ-FUSION ACTIVADO EN EL SISTEMA, YA QUE SIN REMEDIO "
                       "IRA A UNA PANTALLA EN BLANCO. LA SOLUCION EN EL CASO DE QUE "
                       "LE OCURRA ESTO ES PULSAR \"CTRL+ALT+BACKSPACE\" DOS VECES O "
                       "NO PODRA SALIR DE LA PANTALLA BLANCA.<p>"

                       "Con esta opcion ponemos en la barra de tareas un icono "
                       "para poder, en caso necesario, restaurar los marcos de "
                       "las ventanas de compiz-fusion.<p>"

                       "&iquest;Activar Fusion Icon?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

            QString cmd = "su - %1 -c \"fusion-icon\"";
            cmd=cmd.arg(user);
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

//***OPCION REVISADA Y TERMINADA***//
        /*! probar esta opcion pero en el caso de invitado */
void recoverdrake::on_actionRecuperar_barra_de_tareas_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Recuperar barra de tareas"),
                       tr("<center><b>Recuperar barra de tareas</center><p>"

                       "Con esta opcion arreglaremos el problema de la barra de "
                       "tareas en el caso de que haya desaparecido.<p>"

                       "Tenga en cuenta que con esta opcion, cambiara el aspecto "
                       "de su escritorio, no asi las demas configuraciones que "
                       "seguiran tal cual las tenia.<p>"

                       "<B>NOTA: Debe esperar a que termine completamente el "
                       "proceso seleccionado, el cual le sera notificado "
                       "cuando finalice, en la consola de procesos.</B><p>"

                       "&iquest;Recuperar barra de tareas?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "su - %1 -c \"kquitapp plasma-desktop\"";
        cmd=cmd.arg(user);
        QString cmd1 = "su - %1 -c \"mv /home/%1/.kde4/share/config/plasma-desktop-appletsrc /home/%1/.kde4/share/config/plasma-desktop-appletsrc.bak\"";
        cmd1=cmd1.arg(user);
        QString cmd2 = "su - %1 -c \"plasma-desktop\"";
        cmd2=cmd2.arg(user);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionCaptura_de_pantalla_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Captura de pantalla interactiva"),
                       tr("<center><b>Captura de pantalla interactiva</center><p>"

                       "Con esta utilidad puedes hacer una captura de pantalla "
                       "pero eligiendo que capturar y cuando.<p>"

                       "&iquest;Captura de pantalla interactiva?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok){

        QString cmd = "su - %1 -c \"gnome-screenshot --interactive\"";
        cmd=cmd.arg(user);
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

//***OPCION REVISADA Y TERMINADA***//
void recoverdrake::on_actionListar_logs_de_comandos_de_shell_triggered()
{
    int respuesta = 0;

respuesta = QMessageBox::question(this, tr("Listar logs de uso de comandos de shell"),
                       tr("<center><b>Listar logs de uso de comandos de shell</center><p>"

                       "Con esta utilidad puedes saber los ultimos comandos que has "
                       "escrito en la consola.<p>"

                       "Para el publico en general esto tiene poco de efectivo, pero "
                       "para algunos, es bastante interesante saber que comandos hemos "
                       "ejecutado.<p>"

                       "&iquest;Listar logs de comandos shell?"), QMessageBox::Ok, QMessageBox::No);

if (respuesta == QMessageBox::Ok)
        {
        system("kwrite /home/"+user+"/.bash_history");
        }
        return;
}
