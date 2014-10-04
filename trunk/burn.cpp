#include "burn.h"
#include "ui_burn.h"
#include "localizador.h"
#include "drakeprocesos1.h"
#include "drakesistema.h"
#include "recoverdrake.h"
#include "ui_recoverdrake.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>
#include "QFileSystemModel"
#include "QProcess"
#include <QMutex>
#include <QKeyEvent>
#include <QMimeData>
#include <QTreeWidgetItem>
#include <QTest>
#include <QDebug>

burn::burn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::burn)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    ui->progressBar->hide();
    ui->label_5->hide();
    ui->groupBox_11->hide();
    mib = 0;
    drakeSistema drake;
    user = drake.getUser();
    path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    Distro = drake.getDistrop();
    dist = drake.getDistribucion();
    ui->lineEdit_2->setText(path);
    Directorio = ui->lineEdit_2->text();
    QString Veloz1, Veloz2, Veloz3, Veloz4, Veloz5;
    Stilo = "B";
    QSqlQuery queryVelocidad(db);
    queryVelocidad.exec("SELECT Velocidad2x,Velocidad4x,Velocidad8x,Velocidad16x,Velocidad32x FROM Opcion4 WHERE id=2");
    queryVelocidad.first();
    if (queryVelocidad.isSelect())
    {
        Veloz1=queryVelocidad.value(0).toString();
        Veloz2=queryVelocidad.value(1).toString();
        Veloz3=queryVelocidad.value(2).toString();
        Veloz4=queryVelocidad.value(3).toString();
        Veloz5=queryVelocidad.value(4).toString();
    }
    if (Veloz1 == "2")
    {
        velocidad="2";
    }
    else if (Veloz2 == "2")
    {
        velocidad="4";
    }
    else if (Veloz3 =="2")
    {
        velocidad="8";
    }
    else if (Veloz4 =="2")
    {
        velocidad="16";
    }
    else if (Veloz5 =="2")
    {
        velocidad="32";
    }
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(velocidad+"x"));
    QString Dev1, Dev2, Dev3;
    QSqlQuery queryDev(db);
    queryDev.exec("SELECT Numero1,Numero2,Numero3 FROM Opcion3 WHERE id=2");
    queryDev.first();
    if (queryDev.isSelect())
    {
        Dev1=queryDev.value(0).toString();
        Dev2=queryDev.value(1).toString();
        Dev3=queryDev.value(2).toString();
    }
    Dev=""+Dev1+","+Dev2+","+Dev3+"";
    QSqlQuery queryDefecto(db);
    queryDefecto.exec("SELECT Defecto FROM Miscelanea WHERE id=2");
    queryDefecto.first();
    if (queryDefecto.isSelect())
        cantidadDefecto=queryDefecto.value(0).toString();
    if (cantidadDefecto == "0")
    {
        QSqlQuery query47(db);
        query47.exec("SELECT Fuente FROM Font WHERE id=2");
        query47.first();
        if (query47.isSelect())
            cantidad47=query47.value(0).toString();
        QSqlQuery query48(db);
        query48.exec("SELECT Estilo FROM Font WHERE id=2");
        query48.first();
        if (query48.isSelect())
            cantidad48=query48.value(0).toString();
        QSqlQuery query49(db);
        query49.exec("SELECT Talla FROM Font WHERE id=2");
        query49.first();
        if (query49.isSelect())
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
        if (query50.isSelect())
            cantidad50=query50.value(0).toString();
        QSqlQuery query51(db);
        query51.exec("SELECT ColorFondo FROM Color WHERE id=2");
        query51.first();
        if (query51.isSelect())
            cantidad51=query51.value(0).toString();
        Stilo = "A";
    }
    this->installEventFilter(this);
    CierreTotal = 0;
    Opcion = 0;
    tamanio = 0.000;
    QFileDialog *fdlg = new QFileDialog(this, "Buscador");
    fdlg->setAcceptDrops(true);
    connect(fdlg, SIGNAL(finished(int)), fdlg, SLOT(open()));
    connect(fdlg, SIGNAL(fileSelected(QString)), this, SLOT(Cargar(QString)));
    connect(fdlg, SIGNAL(currentChanged(QString)), this, SLOT(Value(QString)));
    ui->gridLayout_28->addWidget(fdlg);
    fdlg->setWindowState(Qt::WindowMaximized);
    fdlg->setLabelText(QFileDialog::Reject, NULL);
    fdlg->setViewMode(QFileDialog::Detail);
    ui->tableWidget->setAcceptDrops(true);
    ui->tableWidget->setDropIndicatorShown(true);
    ui->textEdit->setAcceptDrops(false);
    ui->progressBar_2->setRange(0,0);
    ui->progressBar_2->setValue(0);
    ui->textEdit_2->clear();
    QString Dato = getInfo();
    ui->textEdit_2->setText(Dato);
    ui->textEdit_3->clear();
    QString Dato2 = getDir();
    ui->textEdit_3->setText(Dato2);
    ui->tabWidget->setCurrentPage(0);
    Estado = 0;
    Contador = new QTimer(this);
    connect(Contador, SIGNAL(timeout()), this, SLOT(Contar()));
    Contador->start(10000);
    connect(ui->pushButton_17,SIGNAL(clicked()),this,SLOT(Refresco()));
    connect(ui->checkBox_4,SIGNAL(clicked()),this,SLOT(Comprobar()));
    ui->pushButton_14->setVisible(false);
    ui->tabWidget->setTabText(1,"Opciones");
    Grabando = "";
    ui->textEdit->clear();
    this->setAcceptDrops(true);
    ui->checkBox_2->hide();
    ui->textEdit_4->setText(getCDRom());
    ui->tableWidget->installEventFilter(this);
    connect(ui->checkBox_3,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->checkBox_2,SIGNAL(clicked()),this,SLOT(Comprobar2()));
    connect(ui->checkBox_5,SIGNAL(clicked()),this,SLOT(Comprobar3()));
    connect(ui->checkBox,SIGNAL(clicked()),this,SLOT(Comprobar4()));
    connect(ui->checkBox_6,SIGNAL(clicked()),this,SLOT(Comprobar5()));
    ui->label_17->setShown(false);
    ui->label_22->setShown(false);
    ui->label_23->setShown(false);
    ui->label_24->setShown(false);
    ui->label_25->setShown(false);
    ui->label_26->setShown(false);
    ui->label_27->setShown(false);
    ui->label_28->setShown(false);
    ui->label_29->setShown(false);
    ui->label_30->setShown(false);
    ui->label_31->setShown(false);
    ui->pushButton_15->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
    compara = "";
    Copia = ui->comboBox_2->currentText().toInt();
    ui->label_33->setVisible(false);
    Counter = 0;
    Localizar = getPack();
}

burn::~burn()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void burn::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void burn::Valor(QString valor)
{
    if (valor == "Quitar")
    {        
        CierreTotal = 1;
    }
}

void burn::Value(QString Valor)
{
    Localizado = Valor;
}

void burn::Contar()
{
    QFile file("/etc/mtab");
    QDateTime Fecha = QFileInfo(file).lastModified();
    QString ComFecha = Fecha.toString();
    if (compara != ComFecha)
    {
        compara = ComFecha;
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString datoslst = in.readAll();
        file.close();
        QStringList lista = datoslst.split("\n");
        int Valor = lista.count();
        QString Valorando = lista.value(Valor-2);
        if (Valorando.contains("/dev/sr0"))
        {
            QString Dato, Dato2, Captura, ValorCapturado, Final, Rw;
            ui->label_17->setShown(false);
            ui->label_22->setShown(false);
            ui->label_23->setShown(false);
            ui->label_24->setShown(false);
            ui->label_25->setShown(false);
            ui->label_26->setShown(false);
            ui->label_27->setShown(false);
            ui->label_28->setShown(false);
            ui->label_29->setShown(false);
            ui->label_30->setShown(false);
            ui->label_31->setShown(false);
            int Value, Capacidad, Total;
            QStringList DatoInfo, DatoInfo1;
            Dato = getInfo();
            Dato2 = getDir();
            DatoInfo = Dato.split("\n");
            for (int a=0;a<DatoInfo.count();a++)
            {
                Captura = DatoInfo.value(a);
                if (Captura.contains("Track Size:"))
                {
                    ValorCapturado = Captura.remove("Track Size:");
                    ValorCapturado = ValorCapturado.remove(" ");
                    ValorCapturado = ValorCapturado.remove("*2KB");
                    Capacidad = (ValorCapturado.toInt()*2)/1024;
                    TipoMedio = "DVD";
                    Value = 0;
                    break;
                }
                else
                {
                    Value = 1;
                }
            }
            if (Value == 1)
            {
                system("umount /dev/cdrom");
                Dato = getInfo1();
                DatoInfo1 = Dato.split("\n");
                for (int a=0;a<DatoInfo1.count();a++)
                {
                    Captura = DatoInfo1.value(a);
                    if (Captura.contains("CD-RW"))
                    {
                        if (Captura.contains("yes"))
                            Rw = "Si";
                        else
                            Rw = "No";
                    }
                    if (Captura.contains("CD-R empty"))
                    {
                        if (Captura.contains("yes"))
                        {
                            Multi = "Si";
                            Final = "Si";
                        }
                        else
                            Multi = "No";
                    }
                    if (Captura.contains("Appendable"))
                    {
                        Multi = "Si";
                    }
                    if (Captura.contains("Total Capacity"))
                    {
                        if (Captura.contains("n/a"))
                            Capacidad = 702;
                        else
                        {
                            QStringList Buscar = Captura.split(",");
                            QString Valor = Buscar.value(1);
                            QStringList Buscar1 = Valor.split("/");
                            QString Valor2 = Buscar1.value(0);
                            Total = Valor2.toInt();
                        }
                    }
                    if (Captura.contains("Sessions"))
                    {
                        QStringList Buscar = Captura.split(":");
                        QString Valor = Buscar.value(1);
                        Sesion = Valor.remove(" ");
                    }
                    if (Captura.contains("Start of last session"))
                    {
                        QStringList Buscar = Captura.split(":");
                        QString Valor = Buscar.value(1);
                        QStringList Buscar1 = Valor.split(" ");
                        QString Valor2 = Buscar1.value(1);
                        Inicio = Valor2.toInt();
                    }
                    if (Captura.contains("Start of new session"))
                    {
                        QStringList Buscar = Captura.split(":");
                        QString Valor = Buscar.value(1);
                        QStringList Buscar1 = Valor.split(" ");
                        QString Valor2 = Buscar1.value(1);
                        Capacidad = (Valor2.toInt()*2)/1024;
                    }
                    if (Captura.contains("Remaining Capacity"))
                    {
                        QStringList Buscar = Captura.split(":");
                        QString Valor = Buscar.value(3);
                        QStringList Buscar1 = Valor.split(",");
                        QString Valor2 = Buscar1.value(1);
                        QStringList Buscar2 = Valor2.split("/");
                        QString Valor3 = Buscar2.value(0);
                        Valor3 = Valor3.remove(" ");
                        Libre = Valor3.toInt();
                    }
                }
                TipoMedio = "CD";
                system("mount /dev/cdrom");
            }
            else if (Value == 0)
            {
                for (int a=0;a<DatoInfo.count();a++)
                {
                    Captura = DatoInfo.value(a);
                    if (Captura.contains("Mounted Media:"))
                    {
                        if (Captura.contains("RW"))
                        {
                            Rw = "Si";
                            ui->pushButton_15->setEnabled(true);
                            ui->pushButton_13->setEnabled(true);
                        }
                        else
                        {
                            Rw = "No";
                            ui->pushButton_15->setEnabled(false);
                            ui->pushButton_13->setEnabled(false);
                        }
                    }
                    if (Captura.contains("Mounted Media:"))
                    {
                        QStringList Valor = Captura.split(",");
                        TipCD = Valor.value(1);
                    }                    
                    if (Captura.contains("Disc status:"))
                    {
                        if (Captura.contains("complete"))
                            Multi = "No";
                        if (Captura.contains("appendable"))
                            Multi = "Si";
                        if (Captura.contains("blank"))
                        {
                            Multi = "Si";
                            Final = "Si";
                        }
                    }
                    if (Captura.contains("Number of Sessions: "))
                    {
                        QString Valor = Captura.remove("Number of Sessions: ");
                        Sesion = Valor;
                    }
                    if (Captura.contains("Free Blocks:"))
                    {
                        QString Valor = Captura.remove("Free Blocks:");
                        Valor = Valor.remove(" ");
                        Valor = Valor.remove("*2KB");
                        Libre = (Valor.toInt()*2)/1024;
                    }
                    if (Captura.contains(("W@")))
                    {
                        QStringList Buscar = Captura.split(" ");
                        for (int b=0;b<Buscar.count();b++)
                        {
                            QString Valor = Buscar.value(b);
                            if (Valor.contains("W@"))
                            {
                                QString Velocidad = Valor.remove("W@");
                                QStringList Segregar = Velocidad.split("x");
                                QString Velo2 = Segregar.value(0);
                                if (Velo2 == "2.0")
                                    ui->label_22->setShown(true);
                                if (Velo2 == "4.0")
                                    ui->label_23->setShown(true);
                                if (Velo2 == "6.0")
                                    ui->label_17->setShown(true);
                                if (Velo2 == "8.0")
                                    ui->label_24->setShown(true);
                                if (Velo2 == "10.0")
                                    ui->label_25->setShown(true);
                                if (Velo2 == "12.0")
                                    ui->label_26->setShown(true);
                                if (Velo2 == "16.0")
                                    ui->label_27->setShown(true);
                                if (Velo2 == "18.0")
                                    ui->label_28->setShown(true);
                                if (Velo2 == "20.0")
                                    ui->label_29->setShown(true);
                                if (Velo2 == "22.0")
                                    ui->label_30->setShown(true);
                                if (Velo2 == "24.0")
                                    ui->label_31->setShown(true);
                            }
                        }
                    }
                }
            }
            if (Dato2 != ui->textEdit_3->toPlainText() || Dato != ui->textEdit_2->toPlainText())
            {
                ui->textEdit_2->setText("");
                ui->textEdit_3->setText("");
                ui->textEdit_3->setText(Dato2);
                ui->textEdit_2->setText(Dato);
            }
            ui->label_13->setText(QString::number(Capacidad)+" Mb");
            ui->label_11->setText(TipCD);
            ui->label_15->setText(Multi);
            ui->label_19->setText(Sesion);
            ui->label_32->setText(Rw);
            ui->label_21->setText(QString::number(Libre)+" Mb");
            if (Value == 0)
            {
                ui->label_9->setText(QString::number(Total)+ " Mb");
            }
            else
            {
                if (Final == "Si")
                    ui->label_9->setText(QString::number(Capacidad)+ " Mb");
                else
                    ui->label_9->setText(QString::number(Capacidad+Libre)+ " Mb");
            }
            if (Multi == "Si")
            {
                ui->checkBox_2->setHidden(false);
                ui->checkBox_3->setHidden(true);
            }
            else if (Multi == "No")
            {
                ui->checkBox_2->setHidden(true);
                ui->checkBox_3->setHidden(false);
            }
        }
    }
}

QString burn::getInfo1()
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "disk-info"; //dev=/dev/cdrom" << "-atip";
    procesoRPM->start("cdrdao",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res =  QString(Paquete);
    res.chop(1);
    return res;
}

void burn::Refrescar()
{            
    cdrdao= "cdrdao";
    if (Localizar.contains(cdrdao) == false)
            cdrdao= "0";
    else
            cdrdao= "1";
    cdrkit= "cdrkit";
    if (Localizar.contains(cdrkit) == false)
            cdrkit= "0";
    else
            cdrkit= "1";
    ffmpeg= "ffmpeg";
    if (Localizar.contains(ffmpeg) == false)
            ffmpeg= "0";
    else
            ffmpeg= "1";
    dvdauthor= "dvdauthor";
    if (Localizar.contains(dvdauthor) == false)
            dvdauthor= "0";
    else
            dvdauthor= "1";
    dvdrwtools= "dvd+rw-tools";
    if (Localizar.contains(dvdrwtools) == false)
            dvdrwtools= "0";
    else
            dvdrwtools= "1";
    vcdimager= "vcdimager";
    if (Localizar.contains(vcdimager) == false)
            vcdimager= "0";
    else
            vcdimager= "1";
    cdparanoia= "cdparanoia";
    if (Localizar.contains(cdparanoia) == false)
            cdparanoia= "0";
    else
            cdparanoia= "1";
    dvdbackup= "dvdbackup";
    if (Localizar.contains(dvdbackup) == false)
            dvdbackup= "0";
    else
            dvdbackup= "1";
}

QString burn::getPack()
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "-qa" << "--queryformat='%{N} '";
    procesoRPM->start("rpm",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res =  QString(Paquete);
    res.chop(1);
    return res;
}

void burn::on_pushButton_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    this->Refrescar();
    int i;
    int iFilas;
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    listaArchivos=QFileDialog::getOpenFileNames
     (this,tr("Abrir Archivos"),path,
        "Todos los archivos (*.*)");
    if (listaArchivos.isEmpty())
    {
        Opcion = 0;
        return;
    }
    for(i=0;i<listaArchivos.count();i++ )
    {
        int Valor;
        QString rutaAbs;
        rutaAbs=listaArchivos.value(i);
        int a,cantidad;
        QString cadena;
        cantidad=ui->tableWidget->rowCount();
        for(a=0;a<cantidad;a++)
        {
            QTableWidgetItem *itemC;
            itemC=ui->tableWidget->item(a,1);
            cadena= itemC->text();
            if (cadena == rutaAbs)
            {
                Valor = 0;
                break;
            }
            else
                Valor= 1;
        }
        if (Valor != 0)
        {
            QTableWidgetItem *item1,*item2,*item3;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            QFile file(rutaAbs);
            float size = QFileInfo(file).size();
            item1->setText(tr(QFileInfo(file).fileName()));
            item2->setText(tr(rutaAbs));
            float f;
            f = size;
            if (f > 0)
            {
                if (f <= 999)
                    item3->setText(""+QString::number(f)+" B");
                if (f > 999 && f <= 999999)
                {
                    f = (size + 1023) / 1024;
                    item3->setText(""+QString::number(f,'f',1)+" kB");
                }
                if (f > 999999 && f <= 999999999)
                {
                    f = (size + 1023) / 1024;
                    f = f / 1024;
                    item3->setText(""+QString::number(f,'f',1)+" MB");
                    Tipo = "MB";
                }
                if (f > 999999999)
                {
                    f = (size + 1023) / 1024;
                    f = f / 1024;
                    f = f / 1024;
                    item3->setText(""+QString::number(f,'f',1)+" GB");
                    Peso = "GB";
                    Tipo = "GB";
                }
                iFilas=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(iFilas);
                ui->tableWidget->setItem(iFilas,0,item1);
                ui->tableWidget->setItem(iFilas,1,item2);
                ui->tableWidget->setItem(iFilas,2,item3);
                ui->tableWidget->resizeRowsToContents();
                ui->tableWidget->resizeColumnsToContents();
            }
        }
    }
    this->Recuento();
    int Ratio = tamanio;
    if (tamanio <= 700.00)
    {
        if (Peso != "GB")
            ui->label_2->setText("MB");
    }
    else if (tamanio > 700.00)
    {
        tamanio = tamanio / 1024;
        ui->label_2->setText("GB");
    }
    ui->label_4->setText(QString::number(tamanio,'f',2));
    if (Peso != "GB")
    {
        if (tamanio <= 700.00)
        {
            ui->label_3->setText(tr("Introducir DVD o CD"));
            ui->progressBar_2->setRange(0,700);ui->progressBar_3->setRange(0,700);
            ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
        }
        else if (tamanio >= 700.00)
        {
            if (tamanio <= 4482.00)
            {
                ui->label_3->setText(tr("Introducir DVD o DVD Doble Capa"));
                ui->progressBar_2->setRange(0,4482);ui->progressBar_3->setRange(0,4482);
                ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
            }
            else if (tamanio >= 4482.00)
            {
                if (tamanio <= 8110.00)
                {
                    ui->label_3->setText(tr("Introducir DVD Doble Capa"));
                    ui->progressBar_2->setRange(0,8110);ui->progressBar_3->setRange(0,8110);
                    ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
                }
                else if (tamanio >= 8110.00)
                {
                    ui->label_3->setText(tr("Tamano excedido"));
                }
            }
        }
    }
    else
    {
        if (tamanio <= 0.683)
        {
            ui->label_3->setText(tr("Introducir DVD o CD"));
            ui->progressBar_2->setRange(0,700);ui->progressBar_3->setRange(0,700);
            ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
        }
        else if (tamanio >= 0.683)
        {
            if (tamanio <= 4.380)
            {
                ui->label_3->setText(tr("Introducir DVD o DVD Doble Capa"));
                ui->progressBar_2->setRange(0,4482);ui->progressBar_3->setRange(0,4482);
                ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
            }
            else if (tamanio >= 4.380)
            {
                if (tamanio <= 7.920)
                {
                    ui->label_3->setText(tr("Introducir DVD Doble Capa"));
                    ui->progressBar_2->setRange(0,8110);ui->progressBar_3->setRange(0,8110);ui->progressBar_3->setRange(0,8110);
                    ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
                }
                else if (tamanio >= 7.920)
                {
                    ui->label_3->setText(tr("Tamano excedido"));
                    ui->progressBar_2->setValue(0);
                }
            }
        }
    }
    Opcion = 0;
}

void burn::Recuento()
{
    tamanio = 0.000;
    int Total = ui->tableWidget->rowCount();
    for (int a=0;a<Total;a++)
    {
        QTableWidgetItem *item;
        item=ui->tableWidget->item(a,2);
        QString Valorar = item->text();
        int pos1 = Valorar.indexOf(" MB", 0);
        if (pos1 != -1)
        {
            Valorar = Valorar.remove(" MB");
            tamanio = tamanio + Valorar.toFloat();
        }
        else
        {
            int pos2 = Valorar.indexOf(" B", 0);
            if (pos2 != -1)
            {
                Valorar = Valorar.remove(" B");
                tamanio = tamanio + ((Valorar.toFloat()/1024)/1024);
            }
            else
            {
                int pos3 = Valorar.indexOf(" kB", 0);
                if (pos3 != -1)
                {
                    Valorar = Valorar.remove(" kB");
                    tamanio = tamanio + ((Valorar.toFloat()/1024));
                }
                else
                {
                    Valorar = Valorar.remove(" GB");
                    tamanio = tamanio + (Valorar.toFloat()*1024);
                }
            }
        }
    }    
}

void burn::on_pushButton_5_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void burn::closeEvent ( QCloseEvent * event )
{
    if (CierreTotal == 1)
    {
        emit Cerrar();
        event->accept();
    }
    else
    {
        close();
        event->accept();
    }
}

void burn::on_pushButton_2_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    this->Refrescar();
    int iFilas;
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio a buscar?"),path,QFileDialog::ShowDirsOnly);
    if (fileNameDirectori.isEmpty())
    {
        Opcion = 0;
        return;
    }
    QString size= getSize(fileNameDirectori);
    QString ruta;
    ruta=fileNameDirectori+"/";
    int Valor;
    int a,cantidad;
    QString cadena;
    cantidad=ui->tableWidget->rowCount();
    if (cantidad == 0)
        Valor = 1;
    else
    {
        for(a=0;a<cantidad;a++)
        {
            QTableWidgetItem *itemC;
            itemC=ui->tableWidget->item(a,1);
            cadena= itemC->text();
            if (cadena == ruta)
            {
                Valor = 0;
                break;
            }
            else
                Valor = 1;
        }
    }
    if (Valor != 0)
    {
        QTableWidgetItem *item1,*item2,*item3;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;        
        item1->setText(tr("DIRECTORIO"));
        item2->setText(tr(ruta));
        float f;
        f = size.toFloat()*1024;
        if (f > 0)
        {
            if (f <= 999)
                item3->setText(""+QString::number(f)+" B");
            if (f > 999 && f <= 999999)
            {
                f = (f + 1023) / 1024;
                item3->setText(""+QString::number(f,'f',1)+" kB");
            }
            if (f > 999999 && f <= 999999999)
            {
                f = (f + 1023) / 1024;
                f = f / 1024;
                item3->setText(""+QString::number(f,'f',1)+" MB");
                Tipo = "MB";
            }
            if (f > 999999999)
            {
                f = (f + 1023) / 1024;
                f = f / 1024;
                f = f / 1024;
                item3->setText(""+QString::number(f,'f',1)+" GB");
                Peso = "GB";
                Tipo = "GB";
            }
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->setItem(iFilas,2,item3);
            ui->tableWidget->resizeRowsToContents();
            ui->tableWidget->resizeColumnsToContents();
        }
    }
    this->Recuento();
    int Ratio = tamanio;
    if (tamanio <= 700)
    {
        if (Peso != "GB")
            ui->label_2->setText("MB");
    }
    else if (tamanio > 700)
    {
        tamanio = tamanio / 1024;
        ui->label_2->setText("GB");
    }
    ui->label_4->setText(tr(QString::number(tamanio,'f',3)));
    if (Peso != "GB")
    {
        if (tamanio <= 700.00)
        {
            ui->label_3->setText(tr("Introducir DVD o CD"));
            ui->progressBar_2->setRange(0,700);ui->progressBar_3->setRange(0,700);
            ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
        }
        else if (tamanio >= 700.00)
        {
            if (tamanio <= 4482.00)
            {
                ui->label_3->setText(tr("Introducir DVD o DVD Doble Capa"));
                ui->progressBar_2->setRange(0,4482);ui->progressBar_3->setRange(0,4482);
                ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
            }
            else if (tamanio >= 4482.00)
            {
                if (tamanio <= 8110.00)
                {
                    ui->label_3->setText(tr("Introducir DVD Doble Capa"));
                    ui->progressBar_2->setRange(0,8110);ui->progressBar_3->setRange(0,8110);
                    ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
                }
                else if (tamanio >= 8110.00)
                {
                    ui->label_3->setText(tr("Tamano excedido"));
                }
            }
        }
    }
    else
    {
        if (tamanio <= 0.683)
        {
            ui->label_3->setText(tr("Introducir DVD o CD"));
            ui->progressBar_2->setRange(0,700);ui->progressBar_3->setRange(0,700);
            ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
        }
        else if (tamanio >= 0.683)
        {
            if (tamanio <= 4.380)
            {
                ui->label_3->setText(tr("Introducir DVD o DVD Doble Capa"));
                ui->progressBar_2->setRange(0,4482);ui->progressBar_3->setRange(0,4482);
                ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
            }
            else if (tamanio >= 4.380)
            {
                if (tamanio <= 7.920)
                {
                    ui->label_3->setText(tr("Introducir DVD Doble Capa"));
                    ui->progressBar_2->setRange(0,8110);ui->progressBar_3->setRange(0,8110);ui->progressBar_3->setRange(0,8110);
                    ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
                }
                else if (tamanio >= 7.920)
                {
                    ui->label_3->setText(tr("Tamano excedido"));
                    ui->progressBar_2->setValue(0);
                }
            }
        }
    }
    Opcion = 0;
}

void burn::on_pushButton_3_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    this->Refrescar();
    int Campo = ui->tableWidget->currentRow();
    if (Campo == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro para borrar."));
        m.exec();
        Opcion = 0;
        return;
    }
    ui->tableWidget->removeRow(Campo);
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    int Ratio;
    if (ui->tableWidget->rowCount()==0)
    {
         ui->label_4->setText(tr(""));
         ui->label_2->setText("");
         this->Recuento();
         Ratio = tamanio;
    }
    else
    {        
        this->Recuento();
        Ratio = tamanio;
        if (tamanio <= 700)
        {
            if (Peso != "GB")
                ui->label_2->setText("MB");
        }
        else if (tamanio > 700)
        {
            tamanio = tamanio / 1024;
            ui->label_2->setText("GB");
        }        
        ui->label_4->setText(tr(QString::number(tamanio,'f',3)));
    }  
    if (Peso != "GB")
    {
        if (tamanio <= 700.00)
        {
            ui->label_3->setText(tr("Introducir DVD o CD"));
            ui->progressBar_2->setRange(0,700);ui->progressBar_3->setRange(0,700);
            ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
        }
        else if (tamanio >= 700.00)
        {
            if (tamanio <= 4482.00)
            {
                ui->label_3->setText(tr("Introducir DVD o DVD Doble Capa"));
                ui->progressBar_2->setRange(0,4482);ui->progressBar_3->setRange(0,4482);
                ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
            }
            else if (tamanio >= 4482.00)
            {
                if (tamanio <= 8110.00)
                {
                    ui->label_3->setText(tr("Introducir DVD Doble Capa"));
                    ui->progressBar_2->setRange(0,8110);ui->progressBar_3->setRange(0,8110);
                    ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
                }
                else if (tamanio >= 8110.00)
                {
                    ui->label_3->setText(tr("Tamano excedido"));
                }
            }
        }
    }
    else
    {
        if (tamanio <= 0.683)
        {
            ui->label_3->setText(tr("Introducir DVD o CD"));
            ui->progressBar_2->setRange(0,700);ui->progressBar_3->setRange(0,700);
            ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
        }
        else if (tamanio >= 0.683)
        {
            if (tamanio <= 4.380)
            {
                ui->label_3->setText(tr("Introducir DVD o DVD Doble Capa"));
                ui->progressBar_2->setRange(0,4482);ui->progressBar_3->setRange(0,4482);
                ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
            }
            else if (tamanio >= 4.380)
            {
                if (tamanio <= 7.920)
                {
                    ui->label_3->setText(tr("Introducir DVD Doble Capa"));
                    ui->progressBar_2->setRange(0,8110);ui->progressBar_3->setRange(0,8110);ui->progressBar_3->setRange(0,8110);
                    ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
                }
                else if (tamanio >= 7.920)
                {
                    ui->label_3->setText(tr("Tamano excedido"));
                    ui->progressBar_2->setValue(0);
                }
            }
        }
    }
    Opcion = 0;
}

QString burn::getSize(QString Dir)
{
    QProcess *procesoDu, *procesoCut;
    QStringList argumentosDu;
    QStringList argumentosCut;
    QByteArray Size;
    procesoDu=new QProcess(this);
    procesoCut=new QProcess(this);
    argumentosDu << "-s" << "--block-size=K" << ""+Dir+"";
    argumentosCut << "-d" << "K" << "-f1";
    procesoDu->setStandardOutputProcess(procesoCut);
    procesoDu->start("du",argumentosDu);
    procesoCut->start("cut",argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoDu->waitForFinished();
    procesoCut->waitForFinished();
    Size = QString(procesoCut->readAllStandardOutput());
    procesoCut->waitForFinished();
    delete procesoDu;
    delete procesoCut;
    QString res =  QString(Size);
    res.chop(1);
    return res;
}

QString burn::getMulti()
{
    QProcess *procesoMulti;
    QStringList argumentosMulti;
    QByteArray Multi;
    procesoMulti=new QProcess(this);
    argumentosMulti << "-msinfo" << "dev="+Dev+"";
    procesoMulti->start("cdrecord",argumentosMulti);
    if (! procesoMulti->waitForStarted())
        return QString("");
    procesoMulti->waitForFinished();
    Multi = QString(procesoMulti->readAllStandardOutput());
    procesoMulti->waitForFinished();
    delete procesoMulti;
    QString res =  QString(Multi);
    res.chop(1);
    return res;
}

void burn::on_pushButton_4_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    ui->progressBar->show();
    ui->label_5->show();
    this->Refrescar();
    if (ffmpeg == "0")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(QString::fromUtf8(tr("No se puede utilizar esta función sin instalar la dependencia \"ffmpeg\" necesaria.<p>Realize la instalación para poder utilizarla.")));
        m.exec();
    }
    else
    {
        if (dvdauthor == "0")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(QString::fromUtf8(tr("No se puede utilizar esta función sin instalar la dependencia \"dvdauthor\" necesaria.<p>Realize la instalación para poder utilizarla.")));
            m.exec();
        }
        else
        {
            if (cdrkit == "0")
            {
                    QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(QString::fromUtf8(tr("No se puede utilizar esta función sin instalar la dependencia \"cdrkit\" necesaria.<p>Realize la instalación para poder utilizarla.")));
                    m.exec();
            }
            else
            {
                        int i,cantidad;
                        cantidad=ui->tableWidget->rowCount();
                        QStringList comandos;
                        QString path="/home/%1/";
                        path=path.arg(user);
                        QString cadena;
                        for(i=0;i<cantidad;i++)
                        {
                            system("eject");
                            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                            m.setText(tr("Introduce el medio a quemar expecificado en la ventana anterior.<p>" "Pulsa Ok para continuar..."));
                            m.exec();
                            system("eject -t");
                            QMessageBox mA; if (Stilo == "A") mA.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                            mA.setText(tr("Espera a que el notificador de dispositivos te avise de que esta cargado el disco y pulse Ok para comenzar el proceso."));
                            mA.exec();
                            QTableWidgetItem *item;
                            item=ui->tableWidget->item(i,1);
                            cadena=item->text();
                            cadena=cadena.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
                            QString c1 = QString::fromUtf8(tr("echo Creando directorio temporal..."));
                            QString cm = "su - %1 -c \"mkdir %2DVD_DATA\"";
                            cm=cm.arg(user).arg(path);
                            QString c2 = QString::fromUtf8(tr("echo Codificando fichero de video..."));
                            QString cmd = "su - %1 -c \"ffmpeg -i %2 -sameq -s %4 -target pal-dvd -y %3dvd.mpg\"";
                            cmd=cmd.arg(user).arg(cadena).arg(path).arg(resolucion);
                            QString c3 = QString::fromUtf8(tr("echo Creando ficheros de DVD..."));
                            QString cmd1 = "dvdauthor -o %2DVD_DATA/ -t %2dvd.mpg";
                            cmd1=cmd1.arg(path);
                            QString cmd11 = "dvdauthor -o %2DVD_DATA/ -T";
                            cmd11=cmd11.arg(path);
                            QString c4 = QString::fromUtf8(tr("echo Borrando fichero de video temporal..."));
                            QString cmd2 = "su - %1 -c \"rm -vf %2dvd.mpg\"";
                            cmd2=cmd2.arg(user).arg(path);
                            QString c5 = QString::fromUtf8(tr("echo Creando imagen compatible con DVD de video..."));
                            QString cmd3 = "su - %1 -c \"mkisofs -dvd-video -v -o %2temp_dvd.iso %2DVD_DATA\"";
                            cmd3=cmd3.arg(user).arg(path);
                            QString c51 = QString::fromUtf8(tr("echo Grabando DVD de video..."));
                            QString cmd4 = "su - %1 -c \"cdrecord -v -dao speed=%2 dev=%3 -overburn %4temp_dvd.iso\"";
                            cmd4=cmd4.arg(user).arg(velocidad).arg(Dev).arg(path);
                            QString c6 = QString::fromUtf8(tr("echo Borrando imagen temporal..."));
                            QString cmd5 = "su - %1 -c \"rm -vf %2temp_dvd.iso\"";
                            cmd5=cmd5.arg(user).arg(path);
                            QString c7 = QString::fromUtf8(tr("echo Borrando directorio temporal..."));
                            QString cmd6 = "rm -vr -f %2DVD_DATA";
                            cmd6=cmd6.arg(path);
                            QString c8 = QString::fromUtf8(tr("echo Expulsando disco grabado..."));
                            QString cmd7= "eject";
                            comandos<< c1 << cm << c2 << cmd << c3 << cmd1 << cmd11 << c4 << cmd2 << c5 << cmd3 << c51 << cmd4 << c6 << cmd5 << c7 << cmd6 << c8 << cmd7;
                        }
                        if (mib != 0)
                        delete mib;
                        mib = new DrakeProcesos1(comandos, this);
                        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                        connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                        int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
             }
        }
    }
    Opcion = 0;
}

void burn::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
}

void burn::mibprogreso(QString Dat)
{
    ui->progressBar->setValue(Dat.toInt());
}

void burn::mibFin()
{    
    Copia = Copia-1;
    if (Copia < 1)
    {
        if (ui->comboBox_2->currentText().toInt() > 1)
        {            
            if (Copia == 0)
            {
                if (Grabando == "Datos")
                {
                    QTest::qWait(1000);
                    QStringList comandos;
                    QString c3 = QString::fromUtf8(tr("echo Borrando imagen temporal..."));
                    QString cmd3 = "su - %1 -c \"rm -vf %2RCV_DATA.iso\"";
                    cmd3=cmd3.arg(user).arg(ui->lineEdit_2->text());
                    comandos << c3 << cmd3;
                    mib = new DrakeProcesos1(comandos, this);
                    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                    connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                    int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
                }
                else if (Grabando == "DVDVideoCopy")
                {
                    QTest::qWait(1000);
                    QStringList comandos;
                    QString c3 = QString::fromUtf8(tr("echo Borrando ficheros temporales..."));
                    QString cmd3 = "su - %1 -c \"rm -vf -r %2%3tmp/BckDVD/\"";
                    cmd3=cmd3.arg(user).arg(path);
                    comandos << c3 << cmd3;
                    mib = new DrakeProcesos1(comandos, this);
                    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                    connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                    int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
                }
            }
            else if (Copia == -1)
            {
                QTest::qWait(1000);
                disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                ui->progressBar->setValue(0);
                ui->progressBar->hide();
                ui->label_5->hide();
                ui->pushButton_14->setEnabled(true);
                Opcion = 0;
                Counter = 0;
                Contador->start(10000);
                ui->label_33->setVisible(false);
            }
        }
        else
        {
            if (Copia == 0)
            {
                if (Grabando == "Datos")
                {
                    QTest::qWait(1000);
                    QStringList comandos;
                    QString c3 = QString::fromUtf8(tr("echo Borrando imagen temporal..."));
                    QString cmd3 = "su - %1 -c \"rm -vf %2RCV_DATA.iso\"";
                    cmd3=cmd3.arg(user).arg(ui->lineEdit_2->text());
                    comandos << c3 << cmd3;
                    mib = new DrakeProcesos1(comandos, this);
                    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                    connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                    int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
                }
                else if (Grabando == "DVDVideoCopy")
                {
                    QTest::qWait(1000);
                    QStringList comandos;
                    QString c3 = QString::fromUtf8(tr("echo Borrando ficheros temporales..."));
                    QString cmd3 = "su - %1 -c \"rm -vf %2%3tmp/BckDVD/\"";
                    cmd3=cmd3.arg(user).arg(path);
                    comandos << c3 << cmd3;
                    mib = new DrakeProcesos1(comandos, this);
                    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                    connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                    int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
                }
            }
            else if (Copia == -1)
            {
                QTest::qWait(1000);
                disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                ui->progressBar->setValue(0);
                ui->progressBar->hide();
                ui->label_5->hide();
                ui->pushButton_14->setEnabled(true);
                Opcion = 0;
                Counter = 0;
                Contador->start(10000);
                ui->label_33->setVisible(false);
            }
        }
    }
    else if (Copia >= 1)
    {
        QTest::qWait(1000);
        Opcion = 0;
        on_pushButton_14_clicked();
    }
}

void burn::on_pushButton_7_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    ui->progressBar->show();
    ui->label_5->show();
    this->Refrescar();
    if (ffmpeg == "0")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"ffmpeg\" necesaria.<p>Realize la instalación para poder utilizarla.")));
        m.exec();
    }
    else
    {
        if (cdrkit == "0")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"cdrkit\" necesaria.<p>Realize la instalación para poder utilizarla.")));
            m.exec();
        }
        else
        {
            system("eject");
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Introduce el CD a quemar.<p>" "Pulsa Ok para continuar..."));
            m.exec();
            system("eject -t");
            QMessageBox mA; if (Stilo == "A") mA.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            mA.setText(tr("Espera a que el notificador de dispositivos te avise de que esta cargado el disco y pulse Ok para comenzar el proceso."));
            mA.exec();

            QString path="/home/%1/";
            path=path.arg(user);
            QString cadena;
            QStringList comandos;
            int i,cantidad;
            cantidad=ui->tableWidget->rowCount();
            QString c1 = QString::fromUtf8(tr("echo Creando directorio temporal..."));
            QString cm = "su - %1 -c \"mkdir %2CD_AUDIO\"";
            cm=cm.arg(user).arg(path);
            comandos<< c1 << cm;
            for(i=0;i<cantidad;i++)
            {
                QTableWidgetItem *item;
                item=ui->tableWidget->item(i,1);
                cadena=item->text();
                cadena=cadena.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
                QString c2 = QString::fromUtf8(tr("echo Codificando audio en...Track%1.wav."));
                c2=c2.arg(QString::number(i));
                QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -ar 44100 -ab %3 -y %4CD_AUDIO/Track%5.wav\"";
                cmd1=cmd1.arg(user).arg(cadena).arg(Audio).arg(path).arg(QString::number(i));
                comandos<< c2 << cmd1;
            }
            QString c3 = QString::fromUtf8(tr("echo Grabando CD de audio..."));
            QString cmd4 = "su - %1 -c \"cdrecord dev=%3 speed=%2 -pad -audio %4CD_AUDIO/*.wav\"";
            cmd4=cmd4.arg(user).arg(velocidad).arg(Dev).arg(path);
            QString c4 = QString::fromUtf8(tr("echo Borrando directorio temporal..."));
            QString cmd6 = "su - %1 -c \"rm -vr -f %2CD_AUDIO\"";
            cmd6=cmd6.arg(user).arg(path);
            QString c5 = QString::fromUtf8(tr("echo Expulsando disco grabado..."));
            QString cmd5= "eject";
            comandos<< c3 << cmd4 << c4 << cmd6 << c5 << cmd5;
            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
        }
    }
    Opcion = 0;
}

void burn::on_pushButton_6_clicked()
{
    int Valor = ui->tableWidget->rowCount();
    if (Valor <= 0)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay datos para grabar."));
        m.exec();
        return;
    }
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setTabText(1,"Grabar");
    ui->pushButton_14->setVisible(true);
    ui->groupBox_11->show();
    ui->tabWidget->setTabIcon(1,QIcon(":/Imagenes/cd_burning_section.png"));
    Grabando = "Datos";    
}

void burn::on_pushButton_10_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    ui->progressBar->show();
    ui->label_5->show();
    this->Refrescar();
    if (cdrkit == "0")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"cdrkit\" necesaria.<p>Realize la instalación para poder utilizarla.")));
        m.exec();
    }
    else
    {
        if (vcdimager == "0")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"vcdimager\" necesaria.<p>Realize la instalación para poder utilizarla.")));
            m.exec();
        }
        else
        {
            system("eject");
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Introduce el CD a quemar.<p>" "Pulsa Ok para continuar..."));
            m.exec();
            system("eject -t");
            QMessageBox mA; if (Stilo == "A") mA.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            mA.setText(tr("Espera a que el notificador de dispositivos te avise de que esta cargado el disco y pulse Ok para comenzar el proceso."));
            mA.exec();
            QString path="/home/%1/";
            path=path.arg(user);
            QString cadena;
            QStringList comandos;
            int i,cantidad;
            cantidad=ui->tableWidget->rowCount();
            QString c1 = QString::fromUtf8(tr("echo Creando directorio temporal..."));
            QString cm = "su - %1 -c \"mkdir %2CD_VIDEO\"";
            cm=cm.arg(user).arg(path);
            comandos<< c1 << cm;
            for(i=0;i<cantidad;i++)
            {
                QTableWidgetItem *item;
                item=ui->tableWidget->item(i,1);
                cadena=item->text();
                cadena=cadena.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
                QString c2 = QString::fromUtf8(tr("echo Codificando archivo de video estandar mpg..."));
                QString cmd1 = "su - %1 -c \"ffmpeg -i %2 -target pal-vcd %3CD_VIDEO/videoCD%4.mpg\"";
                cmd1=cmd1.arg(user).arg(cadena).arg(path).arg(QString::number(i));
                comandos<< c2 << cmd1;
            }
            QString c3 = QString::fromUtf8(tr("echo Creando imagen compatible con VCD..."));
            QString cmd4 = "su - %1 -c \"vcdimager %4CD_VIDEO/*.mpg\"";
            cmd4=cmd4.arg(user).arg(path);
            QString c4 = QString::fromUtf8(tr("echo Grabando CD de Video..."));
            QString cmd2="su - %1 -c \"cdrdao write videocd.cue\"";
            cmd2=cmd2.arg(user);
            QString c5 = QString::fromUtf8(tr("echo Borrando imagen y directorio temporal..."));
            QString cmd6 = "su - %1 -c \"rm -vr -f %2CD_VIDEO videocd.cue\"";
            cmd6=cmd6.arg(user).arg(path);
            QString c6 = QString::fromUtf8(tr("echo Expulsando disco grabado..."));
            QString cmd= "eject";
            comandos<< c3 << cmd4 << c4 << cmd2 << c5 << cmd6 << c6 <<cmd;
            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
        }
    }
    Opcion = 0;
}

bool burn::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Escape)
            {
                if (CierreTotal == 0)
                    close();
                else if (CierreTotal == 1)
                    return true;
            }
        }
        return false;
    }
    if (obj == ui->tableWidget)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Delete)
            {
                on_pushButton_3_clicked();
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void burn::dragEnterEvent(QDragEnterEvent *event)
{
        event->acceptProposedAction();
}

void burn::dropEvent(QDropEvent *event)
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    this->Refrescar();
    float f;
    int iFilas;
    QTableWidgetItem *item1,*item2,*item3;
    item1=new QTableWidgetItem;
    item2=new QTableWidgetItem;
    item3=new QTableWidgetItem;
    QString rutaAbs = Localizado;
    drakeSistema drake;
    QString tipo = drake.getTipo(rutaAbs);
    QStringList Tipillo = tipo.split(":");
    QString tipe = Tipillo.value(1);
    int Valor;
    int a,cantidad;
    QString cadena;
    cantidad=ui->tableWidget->rowCount();
    if (cantidad == 0)
        Valor = 1;
    else
    {
        for(a=0;a<cantidad;a++)
        {
            QTableWidgetItem *itemC;
            itemC=ui->tableWidget->item(a,1);
            cadena= itemC->text();
            if (cadena == rutaAbs+"/")
            {
                Valor = 0;
                break;
            }
            else
                Valor = 1;
        }
    }
    if (Valor != 0)
    {
        if (tipe == " directory")
        {
            QString size= getSize(rutaAbs);
            QString ruta= rutaAbs+"/";
            item1->setText(tr("DIRECTORIO"));
            item2->setText(tr(ruta));
            f=size.toFloat()*1024;
        }
        else
        {
            QFile file(rutaAbs);
            float size = QFileInfo(file).size();
            item1->setText(tr(QFileInfo(file).fileName()));
            item2->setText(tr(rutaAbs));
            f = size;
        }
        if (f > 0)
        {
            if (f <= 999)
                item3->setText(""+QString::number(f)+" B");
            if (f > 999 && f <= 999999)
            {
                f = (f + 1023) / 1024;
                item3->setText(""+QString::number(f,'f',1)+" kB");
            }
            if (f > 999999 && f <= 999999999)
            {
                f = (f + 1023) / 1024;
                f = f / 1024;
                item3->setText(""+QString::number(f,'f',1)+" MB");
                Tipo = "MB";
            }
            if (f > 999999999)
            {
                f = (f + 1023) / 1024;
                f = f / 1024;
                f = f / 1024;
                item3->setText(""+QString::number(f,'f',1)+" GB");
                Peso = "GB";
                Tipo = "GB";
            }
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->setItem(iFilas,2,item3);
            ui->tableWidget->resizeRowsToContents();
            ui->tableWidget->resizeColumnsToContents();
        }
    }
    this->Recuento();
    int Ratio = tamanio;
    if (tamanio <= 700)
    {
        if (Peso != "GB")
            ui->label_2->setText("MB");
    }
    else if (tamanio > 700)
    {
        tamanio = tamanio / 1024;
        ui->label_2->setText("GB");
    }
    ui->label_4->setText(QString::number(tamanio,'f',3));
    if (Peso != "GB")
    {
        if (tamanio <= 700.00)
        {
            ui->label_3->setText(tr("Introducir DVD o CD"));
            ui->progressBar_2->setRange(0,700);ui->progressBar_3->setRange(0,700);
            ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
        }
        else if (tamanio >= 700.00)
        {
            if (tamanio <= 4482.00)
            {
                ui->label_3->setText(tr("Introducir DVD o DVD Doble Capa"));
                ui->progressBar_2->setRange(0,4482);ui->progressBar_3->setRange(0,4482);
                ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
            }
            else if (tamanio >= 4482.00)
            {
                if (tamanio <= 8110.00)
                {
                    ui->label_3->setText(tr("Introducir DVD Doble Capa"));
                    ui->progressBar_2->setRange(0,8110);ui->progressBar_3->setRange(0,8110);
                    ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
                }
                else if (tamanio >= 8110.00)
                {
                    ui->label_3->setText(tr("Tamano excedido"));
                }
            }
        }
    }
    else
    {
        if (tamanio <= 0.683)
        {
            ui->label_3->setText(tr("Introducir DVD o CD"));
            ui->progressBar_2->setRange(0,700);ui->progressBar_3->setRange(0,700);
            ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
        }
        else if (tamanio >= 0.683)
        {
            if (tamanio <= 4.380)
            {
                ui->label_3->setText(tr("Introducir DVD o DVD Doble Capa"));
                ui->progressBar_2->setRange(0,4482);ui->progressBar_3->setRange(0,4482);
                ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
            }
            else if (tamanio >= 4.380)
            {
                if (tamanio <= 7.920)
                {
                    ui->label_3->setText(tr("Introducir DVD Doble Capa"));
                    ui->progressBar_2->setRange(0,8110);ui->progressBar_3->setRange(0,8110);ui->progressBar_3->setRange(0,8110);
                    ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
                }
                else if (tamanio >= 7.920)
                {
                    ui->label_3->setText(tr("Tamano excedido"));
                    ui->progressBar_2->setValue(0);
                }
            }
        }
    }
    Opcion = 0;
    event->acceptProposedAction();
}

void burn::Cargar(QString Valor)
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();        
        return;
    }
    this->Refrescar();
    int iFilas;
    float f;
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString rutaAbs;
    QTableWidgetItem *item1,*item2,*item3;
    item1=new QTableWidgetItem;
    item2=new QTableWidgetItem;
    item3=new QTableWidgetItem;
    rutaAbs = Valor;
    drakeSistema drake;
    QString tipo = drake.getTipo(rutaAbs);
    QStringList Tipillo = tipo.split(":");
    QString tipe = Tipillo.value(1);
    if (tipe == " directory")
    {
        Opcion = 0;
        return;
    }
    else
    {
        int Valor;
        int a,cantidad;
        QString cadena;
        cantidad=ui->tableWidget->rowCount();
        for(a=0;a<cantidad;a++)
        {
            QTableWidgetItem *itemC;
            itemC=ui->tableWidget->item(a,1);
            cadena= itemC->text();
            if (cadena == rutaAbs)
            {
                Valor = 0;
                break;
            }
            else
                Valor = 1;
        }
        if (Valor != 0)
        {
            QFile file(rutaAbs);
            float size = QFileInfo(file).size();
            item1->setText(tr(QFileInfo(file).fileName()));
            item2->setText(tr(rutaAbs));
            f = size;
            if (f > 0)
            {
                if (f <= 999)
                    item3->setText(""+QString::number(f)+" B");
                if (f > 999 && f <= 999999)
                {
                    f = (f + 1023) / 1024;
                    item3->setText(""+QString::number(f,'f',1)+" kB");
                }
                if (f > 999999 && f <= 999999999)
                {
                    f = (f + 1023) / 1024;
                    f = f / 1024;
                    item3->setText(""+QString::number(f,'f',1)+" MB");
                    Tipo = "MB";
                }
                if (f > 999999999)
                {
                    f = (f + 1023) / 1024;
                    f = f / 1024;
                    f = f / 1024;
                    item3->setText(""+QString::number(f,'f',1)+" GB");
                    Peso = "GB";
                    Tipo = "GB";
                }
                iFilas=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(iFilas);
                ui->tableWidget->setItem(iFilas,0,item1);
                ui->tableWidget->setItem(iFilas,1,item2);
                ui->tableWidget->setItem(iFilas,2,item3);
                ui->tableWidget->resizeRowsToContents();
                ui->tableWidget->resizeColumnsToContents();
            }
        }
    }
    this->Recuento();
    int Ratio = tamanio;
    if (tamanio <= 700)
    {
        if (Peso != "GB")
            ui->label_2->setText("MB");
    }
    else if (tamanio > 700)
    {
        tamanio = tamanio / 1024;
        ui->label_2->setText("GB");
    }
    ui->label_4->setText(QString::number(tamanio,'f',3));    
    if (Peso != "GB")
    {
        if (tamanio <= 700.00)
        {
            ui->label_3->setText(tr("Introducir DVD o CD"));
            ui->progressBar_2->setRange(0,700);ui->progressBar_3->setRange(0,700);
            ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
        }
        else if (tamanio >= 700.00)
        {
            if (tamanio <= 4482.00)
            {
                ui->label_3->setText(tr("Introducir DVD o DVD Doble Capa"));
                ui->progressBar_2->setRange(0,4482);ui->progressBar_3->setRange(0,4482);
                ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
            }
            else if (tamanio >= 4482.00)
            {
                if (tamanio <= 8110.00)
                {
                    ui->label_3->setText(tr("Introducir DVD Doble Capa"));
                    ui->progressBar_2->setRange(0,8110);ui->progressBar_3->setRange(0,8110);
                    ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
                }
                else if (tamanio >= 8110.00)
                {
                    ui->label_3->setText(tr("Tamano excedido"));
                }
            }
        }
    }
    else
    {
        if (tamanio <= 0.683)
        {
            ui->label_3->setText(tr("Introducir DVD o CD"));
            ui->progressBar_2->setRange(0,700);ui->progressBar_3->setRange(0,700);
            ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
        }
        else if (tamanio >= 0.683)
        {
            if (tamanio <= 4.380)
            {
                ui->label_3->setText(tr("Introducir DVD o DVD Doble Capa"));
                ui->progressBar_2->setRange(0,4482);ui->progressBar_3->setRange(0,4482);
                ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
            }
            else if (tamanio >= 4.380)
            {
                if (tamanio <= 7.920)
                {
                    ui->label_3->setText(tr("Introducir DVD Doble Capa"));
                    ui->progressBar_2->setRange(0,8110);ui->progressBar_3->setRange(0,8110);ui->progressBar_3->setRange(0,8110);
                    ui->progressBar_2->setValue(Ratio);ui->progressBar_3->setValue(ui->progressBar_2->value());
                }
                else if (tamanio >= 7.920)
                {
                    ui->label_3->setText(tr("Tamano excedido"));
                    ui->progressBar_2->setValue(0);
                }
            }
        }
    }
    Opcion = 0;
}

void burn::on_pushButton_11_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    ui->progressBar->show();
    ui->label_5->show();
    this->Refrescar();
    if (cdrkit == "0")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"cdrkit\" necesaria.<p>Realize la instalación para poder utilizarla.")));
        m.exec();
    }
    else
    {
        QString cm= QString::fromUtf8(tr("echo Creando imagen temporal..."));
        QString cmd = "su - %1 -c \"dd if=/dev/cdrom of=imagenburn.iso bs=2048 count=140564\"";
        cmd=cmd.arg(user);
        QString cm1= QString::fromUtf8(tr("echo Grabando disco..."));
        QString cmd1 = "su - %1 -c \"cdrecord -v dev=%2 speed=%3 -overburn -data imagenburn.iso\"";
        cmd1=cmd1.arg(user).arg(Dev).arg(velocidad);
        QString cm2= QString::fromUtf8(tr("echo Expulsando medio..."));
        QString cmd2 = "eject /cdrw/";
        QString cm3= QString::fromUtf8(tr("echo Borrando imagen temporal..."));
        QString cmd3 = "su - %1 -c \"rm -vf imagenburn.iso\"";
        cmd3=cmd3.arg(user);
        QStringList comandos;
        comandos<< cm << cmd << cm1 << cmd1 << cm2 << cmd2 << cm3 << cmd3;
        if (mib != 0)
        delete mib;
        mib = new DrakeProcesos1(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
    }
    Opcion= 0;
}

void burn::Info()
{    
    QString Dato, Dato2;     
    Dato2 = getDir();
    if (Dato2 != "")
    {
        ui->textEdit_2->setText("");
        ui->textEdit_3->setText("");
        ui->textEdit_3->setText(Dato2);
        Dato = getInfo();
        ui->textEdit_2->setText(Dato);
    }
    else
        this->Info();
}

void burn::Refresco()
{
    QString Dato, Dato2, Captura, ValorCapturado, Final, Rw;
    ui->label_17->setShown(false);
    ui->label_22->setShown(false);
    ui->label_23->setShown(false);
    ui->label_24->setShown(false);
    ui->label_25->setShown(false);
    ui->label_26->setShown(false);
    ui->label_27->setShown(false);
    ui->label_28->setShown(false);
    ui->label_29->setShown(false);
    ui->label_30->setShown(false);
    ui->label_31->setShown(false);
    int Value, Capacidad, Total;
    QStringList DatoInfo, DatoInfo1;
    Dato = getInfo();
    Dato2 = getDir();
    DatoInfo = Dato.split("\n");
    for (int a=0;a<DatoInfo.count();a++)
    {
        Captura = DatoInfo.value(a);
        if (Captura.contains("Track Size:"))
        {
            ValorCapturado = Captura.remove("Track Size:");
            ValorCapturado = ValorCapturado.remove(" ");
            ValorCapturado = ValorCapturado.remove("*2KB");
            Capacidad = (ValorCapturado.toInt()*2)/1024;
            TipoMedio = "DVD";
            Value = 0;
            break;
        }
        else
            Value = 1;
    }
    if (Value == 1)
    {
        system("umount /dev/cdrom");
        Dato = getInfo1();
        DatoInfo1 = Dato.split("\n");
        for (int a=0;a<DatoInfo1.count();a++)
        {
            Captura = DatoInfo1.value(a);
            if (Captura.contains("CD-RW"))
            {
                if (Captura.contains("yes"))
                    Rw = "Si";
                else
                    Rw = "No";
            }
            if (Captura.contains("CD-R empty"))
            {
                if (Captura.contains("yes"))
                {
                    Multi = "Si";
                    Final = "Si";
                }
                else
                    Multi = "No";
            }
            if (Captura.contains("Appendable"))
            {
                Multi = "Si";
            }
            if (Captura.contains("Total Capacity"))
            {
                if (Captura.contains("n/a"))
                    Capacidad = 702;
                else
                {
                    QStringList Buscar = Captura.split(",");
                    QString Valor = Buscar.value(1);
                    QStringList Buscar1 = Valor.split("/");
                    QString Valor2 = Buscar1.value(0);
                    Total = Valor2.toInt();
                }
            }
            if (Captura.contains("Sessions"))
            {
                QStringList Buscar = Captura.split(":");
                QString Valor = Buscar.value(1);
                Sesion = Valor.remove(" ");
            }
            if (Captura.contains("Start of last session"))
            {
                QStringList Buscar = Captura.split(":");
                QString Valor = Buscar.value(1);
                QStringList Buscar1 = Valor.split(" ");
                QString Valor2 = Buscar1.value(1);
                Inicio = Valor2.toInt();
            }
            if (Captura.contains("Start of new session"))
            {
                QStringList Buscar = Captura.split(":");
                QString Valor = Buscar.value(1);
                QStringList Buscar1 = Valor.split(" ");
                QString Valor2 = Buscar1.value(1);
                Capacidad = (Valor2.toInt()*2)/1024;
            }
            if (Captura.contains("Remaining Capacity"))
            {
                QStringList Buscar = Captura.split(":");
                QString Valor = Buscar.value(3);
                QStringList Buscar1 = Valor.split(",");
                QString Valor2 = Buscar1.value(1);
                QStringList Buscar2 = Valor2.split("/");
                QString Valor3 = Buscar2.value(0);
                Valor3 = Valor3.remove(" ");
                Libre = Valor3.toInt();
            }
        }
        TipoMedio = "CD";
        system("mount /dev/cdrom");
    }
    else if (Value == 0)
    {
        for (int a=0;a<DatoInfo.count();a++)
        {
            Captura = DatoInfo.value(a);            
            if (Captura.contains("Mounted Media:"))
            {
                if (Captura.contains("RW"))
                {
                    Rw = "Si";
                    ui->pushButton_15->setEnabled(true);
                    ui->pushButton_13->setEnabled(true);
                }
                else
                {
                    Rw = "No";
                    ui->pushButton_15->setEnabled(false);
                    ui->pushButton_13->setEnabled(false);
                }
            }
            if (Captura.contains("Mounted Media:"))
            {
                QStringList Valor = Captura.split(",");
                TipCD = Valor.value(1);
            }
            if (Captura.contains("Disc status:"))
            {
                if (Captura.contains("complete"))
                    Multi = "No";
                if (Captura.contains("appendable"))
                    Multi = "Si";
                if (Captura.contains("blank"))
                {
                    Multi = "Si";
                    Final = "Si";
                }
            }
            if (Captura.contains("Number of Sessions: "))
            {
                QString Valor = Captura.remove("Number of Sessions: ");
                Sesion = Valor;
            }
            if (Captura.contains("Free Blocks:"))
            {
                QString Valor = Captura.remove("Free Blocks:");
                Valor = Valor.remove(" ");
                Valor = Valor.remove("*2KB");
                Libre = (Valor.toInt()*2)/1024;
            }
            if (Captura.contains(("W@")))
            {
                QStringList Buscar = Captura.split(" ");
                for (int b=0;b<Buscar.count();b++)
                {
                    QString Valor = Buscar.value(b);
                    if (Valor.contains("W@"))
                    {
                        QString Velocidad = Valor.remove("W@");
                        QStringList Segregar = Velocidad.split("x");
                        QString Velo2 = Segregar.value(0);
                        if (Velo2 == "2.0")
                            ui->label_22->setShown(true);
                        if (Velo2 == "4.0")
                            ui->label_23->setShown(true);
                        if (Velo2 == "6.0")
                            ui->label_17->setShown(true);
                        if (Velo2 == "8.0")
                            ui->label_24->setShown(true);
                        if (Velo2 == "10.0")
                            ui->label_25->setShown(true);
                        if (Velo2 == "12.0")
                            ui->label_26->setShown(true);
                        if (Velo2 == "16.0")
                            ui->label_27->setShown(true);
                        if (Velo2 == "18.0")
                            ui->label_28->setShown(true);
                        if (Velo2 == "20.0")
                            ui->label_29->setShown(true);
                        if (Velo2 == "22.0")
                            ui->label_30->setShown(true);
                        if (Velo2 == "24.0")
                            ui->label_31->setShown(true);
                    }
                }
            }
        }
    }
    if (Dato2 != ui->textEdit_3->toPlainText() || Dato != ui->textEdit_2->toPlainText())
    {
        ui->textEdit_2->setText("");
        ui->textEdit_3->setText("");
        ui->textEdit_3->setText(Dato2);
        ui->textEdit_2->setText(Dato);
    }
    ui->label_13->setText(QString::number(Capacidad)+" Mb");
    ui->label_11->setText(TipCD);
    ui->label_15->setText(Multi);
    ui->label_19->setText(Sesion);
    ui->label_32->setText(Rw);
    ui->label_21->setText(QString::number(Libre)+" Mb");
    if (Final == "Si")
        ui->label_9->setText(QString::number(Capacidad)+ " Mb");
    else
        ui->label_9->setText(QString::number(Capacidad+Libre)+ " Mb");
    if (Multi == "Si")
    {
        ui->checkBox_2->setHidden(false);
        ui->checkBox_3->setHidden(true);
    }
    else if (Multi == "No")
    {
        ui->checkBox_2->setHidden(true);
        ui->checkBox_3->setHidden(false);
    }
}

QString burn::getInfo()
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "/dev/cdrom";
    procesoRPM->start("dvd+rw-mediainfo",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res =  QString(Paquete);
    res.chop(1);
    return res;
}

QString burn::getCDRom()
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "/proc/sys/dev/cdrom/info";
    procesoRPM->start("cat",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res =  QString(Paquete);
    res.chop(1);
    return res;
}

void burn::on_pushButton_16_clicked()
{
    if (Estado == 0)
    {
        Contador->stop();
        ui->textEdit_2->setText("");
        ui->textEdit_3->setText("");
        ui->label_17->setShown(false);
        ui->label_22->setShown(false);
        ui->label_23->setShown(false);
        ui->label_24->setShown(false);
        ui->label_25->setShown(false);
        ui->label_26->setShown(false);
        ui->label_27->setShown(false);
        ui->label_28->setShown(false);
        ui->label_29->setShown(false);
        ui->label_30->setShown(false);
        ui->label_31->setShown(false);
        ui->label_13->setText("");
        ui->label_11->setText("");
        ui->label_15->setText("");
        ui->label_19->setText("");
        ui->label_21->setText("");
        ui->label_9->setText("");
        system("eject");
        Estado = 1;
    }
    else if (Estado == 1)
    {
        Contador->start(10000);
        ui->textEdit_2->setText("");
        ui->textEdit_3->setText("");
        system("eject -t");
        Estado = 0;
        this->Info();
    }
}

QString burn::getDir()
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    if (Distro=="Mageia")
    {
        if (dist.toInt() >= 3)
            argumentosRPM << "-1" << "/run/media/"+user+"/Disc";
        else
            argumentosRPM << "-1" << "/media/cdrom";
    }
    else
        argumentosRPM << "-1" << "/media/cdrom";
    procesoRPM->start("dir",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res =  QString(Paquete);
    res.chop(1);
    return res;
}

void burn::on_comboBox_currentIndexChanged(QString )
{
    QString ValorTotal = ui->comboBox->currentText();
    velocidad = ValorTotal.remove("x");
}

void burn::on_pushButton_13_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    this->Refrescar();
    if (cdrkit == "0")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr(QString::fromUtf8("No se puede utilizar esta funcion sin instalar la dependencia \"cdrkit\" necesaria.<p>Realize la instalacion para poder utilizarla, activando las dependencias en el menu principal.")));
        m.exec();
    }
    else
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Borrar disco CD/DVD regrabable")),
                               QString::fromUtf8(tr("<center><b>Borrar disco CD/DVD regrabable</center><p>"
                               "Utilidad para forzar el borrado del disco CD/DVD regrabable.<p>"
                               "IMPORTANTE: Utilizar solo en el caso de que el "
                               "disco no se autoformatee.<p>"
                               "&iquest;Borrar disco CD/DVD?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            QString cm= QString::fromUtf8(tr("echo Borrado de disco en proceso..."));
            QString cmd1;
            if (TipoMedio == "DVD")
            {
                cmd1 = "su - %1 -c \"dvd+rw-format -force /dev/dvd\"";
                cmd1=cmd1.arg(user);
            }
            else if (TipoMedio == "CD")
            {
                cmd1 = "su - %1 -c \"cdrecord -v gracetime=2 dev=/dev/cdrw -eject blank=fast -force\"";
                cmd1=cmd1.arg(user);
            }
            QStringList comandos;
            comandos<< cm << cmd1;
            if (mib != 0)
               delete mib;
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
         }
    }
    Opcion = 0;
}

void burn::on_pushButton_15_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    this->Refrescar();
    if (cdrkit == "0")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr(QString::fromUtf8("No se puede utilizar esta funcion sin instalar la dependencia \"cdrkit\" necesaria.<p>Realize la instalacion para poder utilizarla, activando las dependencias en el menu principal.")));
        m.exec();
    }
    else
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Formatear disco CD/DVD regrabable")),
                               QString::fromUtf8(tr("<center><b>Formatear disco CD/DVD regrabable<center><p>"
                               "Utilidad para forzar el formateo del disco CD/DVD regrabable.<p>"
                               "IMPORTANTE: Utilizar solo en el caso de que el "
                               "disco no se autoformatee y no utilices mucho esta opcion o dejaras inservible el medio.<p>"
                               "&iquest;Formatear disco CD/DVD?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            QString cm= QString::fromUtf8(tr("echo Formateo de disco en proceso..."));
            QString cmd1;
            if (TipoMedio == "DVD")
            {
                cmd1 = "su - %1 -c \"dvd+rw-format -force=all /dev/dvd\"";
                cmd1=cmd1.arg(user);
            }
            else if (TipoMedio == "CD")
            {
                cmd1 = "su - %1 -c \"cdrecord -v gracetime=2 dev=/dev/cdrw -eject blank=all -force\"";
                cmd1=cmd1.arg(user);
            }
            QStringList comandos;
            comandos<< cm << cmd1;
            if (mib != 0)
                delete mib;
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
         }
    }
    Opcion = 0;
}

void burn::on_pushButton_12_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameDirectori;
    if (ui->checkBox_4->isChecked())
    {
        fileNameDirectori = QFileDialog::getSaveFileName(this, tr("Nombre de la iso"),path,tr("iso (*.iso)"));
        if (fileNameDirectori.contains(".iso", Qt::CaseInsensitive) == false)
        {
            fileNameDirectori = fileNameDirectori+".iso";            
        }
        else
        {
            QString Temporal = fileNameDirectori;
            QStringList Depurado = Temporal.split("/");
            int Valor = Depurado.count();
            QString Value = Depurado.value(Valor-1);
            if (Value.contains(".iso"))
                Directorio = Temporal.remove(Value);
        }
    }
    else
    {
        fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio a guardar iso?"),path,QFileDialog::ShowDirsOnly);
        Directorio = fileNameDirectori;
    }
    if (fileNameDirectori.isEmpty())
    {
        Opcion = 0;
        return;
    }
    ui->lineEdit_2->setText(fileNameDirectori);
    Opcion = 0;
}

void burn::Comprobar()
{
    if (ui->checkBox_4->isChecked())
    {
        ui->lineEdit_2->setText(Directorio+"/RCV_DATA.iso");
        ui->groupBox_13->setEnabled(false);
        ui->groupBox_8->setEnabled(false);
    }
    else
    {
        ui->lineEdit_2->setText(Directorio);
        ui->groupBox_13->setEnabled(true);
        ui->groupBox_8->setEnabled(true);
    }
}

void burn::Comprobar1()
{
    if (ui->checkBox_3->isChecked())
    {
        ui->checkBox_2->setChecked(false);
        ui->checkBox_5->setHidden(true);
    }
    else
    {
        ui->checkBox_5->setHidden(false);
    }
}

void burn::Comprobar2()
{
    if (ui->checkBox_2->isChecked())
    {
        ui->checkBox_3->setChecked(false);
        ui->checkBox_5->setHidden(true);
        ui->groupBox_13->setEnabled(false);
    }
    else
    {
        ui->checkBox_5->setHidden(false);
        ui->groupBox_13->setEnabled(true);
    }
}

void burn::Comprobar3()
{
    if (ui->checkBox_5->isChecked())
    {
        ui->checkBox_2->setHidden(true);
        ui->checkBox_3->setHidden(true);
    }
    else
    {        
        if (ui->label_15->text() == "Si")
        {
            ui->checkBox_2->setHidden(false);
        }
        else if (ui->label_15->text() == "No")
        {
            ui->checkBox_3->setHidden(false);
        }
    }
}

void burn::Comprobar4()
{
    if (ui->checkBox->isChecked())
    {
        ui->groupBox_13->setEnabled(false);
    }
    else
    {
        ui->groupBox_13->setEnabled(true);
    }
}

void burn::Comprobar5()
{
    if (ui->checkBox_6->isChecked())
    {
        ui->groupBox_13->setEnabled(false);
    }
    else
    {
        ui->groupBox_13->setEnabled(true);
    }
}

void burn::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked())
    {
        ui->groupBox_7->setChecked(false);
    }
    else
    {
        ui->groupBox_7->setChecked(true);
    }
}

void burn::on_groupBox_7_clicked()
{
    if (ui->groupBox_7->isChecked())
        ui->checkBox->setChecked(false);
    else
        ui->checkBox->setChecked(true);
}

void burn::on_pushButton_14_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    this->Refrescar();
    if (dvdrwtools == "0")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"dvd+rw-tools\" necesaria.<p>Realize la instalación para poder utilizarla.")));
        m.exec();
    }
    else
    {
        if (dvdauthor == "0")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(QString::fromUtf8(tr("No se puede utilizar esta función sin instalar la dependencia \"dvdauthor\" necesaria.<p>Realize la instalación para poder utilizarla.")));
            m.exec();
        }
        else
        {
            if (cdrkit == "0")
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"cdrkit\" necesaria.<p>Realize la instalación para poder utilizarla.")));
                m.exec();
            }
            else
            {
                if (cdrdao == "0")
                {
                    QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"cdrdao\" necesaria.<p>Realize la instalación para poder utilizarla.")));
                    m.exec();
                }
                else
                {
                    if (ffmpeg == "0")
                    {
                        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                        m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"ffmpeg\" necesaria.<p>Realize la instalación para poder utilizarla.")));
                        m.exec();
                    }
                    else
                    {
                        if (vcdimager == "0")
                        {
                            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                            m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"vcdimager\" necesaria.<p>Realize la instalación para poder utilizarla.")));
                            m.exec();
                        }
                        else
                        {
                            if (cdparanoia == "0")
                            {
                                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                                m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"cdparanoia\" necesaria.<p>Realize la instalación para poder utilizarla.")));
                                m.exec();
                            }
                            else
                            {
                                if (dvdbackup == "0")
                                {
                                    QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                                    m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"dvdbackup\" necesaria.<p>Realize la instalación para poder utilizarla.")));
                                    m.exec();
                                }
                                else
                                {
                                    Contador->stop();
                                    ui->label_33->setVisible(true);
                                    ui->pushButton_14->setEnabled(false);
                                    ui->label_33->setText(tr("Realizando copia ")+QString::number((ui->comboBox_2->currentText().toInt()+1)-Copia)+tr(" de ")+ui->comboBox_2->currentText()+"");
                                    if (Grabando == "Datos")
                                    {
                                        ui->progressBar->show();
                                        ui->label_5->show();
                                        if (!ui->checkBox_4->isChecked())
                                        {
                                            if (Copia == ui->comboBox_2->currentText().toInt())
                                            {
                                                system("eject");
                                                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                                                m.setText(tr("Introduce el medio a quemar.<p>" "Pulsa Ok para continuar..."));
                                                m.exec();
                                                system("eject -t");
                                            }
                                            else
                                            {
                                                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                                                m.setText(tr("Introduce el siguiente medio a quemar.<p>" "Pulsa Ok para continuar..."));
                                                m.exec();
                                                system("eject -t");
                                            }
                                        }
                                        int C = 0;
                                        while (C < 15)
                                        {
                                            if (TipoMedio != "")
                                            {
                                                QTest::qWait(1000);
                                                C++;
                                            }
                                            else
                                                C=0;
                                        }
                                        QString path="/home/%1/";
                                        path=path.arg(user);
                                        QString cadena, cadena1, cmd;
                                        QStringList comandos;
                                        int i,cantidad;
                                        cantidad=ui->tableWidget->rowCount();
                                        for(i=0;i<cantidad;i++)
                                        {
                                            QTableWidgetItem *item;
                                            item=ui->tableWidget->item(i,1);
                                            cadena1= item->text();
                                            cadena1=cadena1.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
                                            cadena=cadena + cadena1 +" ";
                                        }
                                        if (ui->checkBox->isChecked())
                                        {
                                            if (ui->checkBox_3->isChecked())
                                            {
                                                if (TipoMedio == "CD")
                                                {
                                                    cmd = "su - %1 -c \"mkisofs -RJ %2 | cdrecord -v -multi fs=4m speed=%3 dev=%4 -data -\"";
                                                    cmd = cmd.arg(user).arg(cadena).arg(velocidad).arg(Dev);
                                                    comandos << cmd;
                                                }
                                                else if (TipoMedio == "DVD")
                                                {
                                                    cmd = "su - %1 -c \"growisofs -speed=%4 -Z /dev/dvd -RJ -v -V \"%3\" %2\"";
                                                    cmd = cmd.arg(user).arg(cadena).arg(ui->lineEdit->text()).arg(velocidad);
                                                    comandos << cmd;
                                                }
                                            }
                                            else
                                            {
                                                if (TipoMedio == "CD")
                                                {
                                                    cmd = "su - %1 -c \"mkisofs -RJ %2 | cdrecord -v fs=4m speed=%3 dev=%4 -data -\"";
                                                    cmd = cmd.arg(user).arg(cadena).arg(velocidad).arg(Dev);
                                                    comandos << cmd;
                                                }
                                                else if (TipoMedio == "DVD")
                                                {
                                                    cmd = "su - %1 -c \"growisofs -dvd-compat -speed=%4 -Z /dev/dvd -RJ -v -V \"%3\" %2\"";
                                                    cmd = cmd.arg(user).arg(cadena).arg(ui->lineEdit->text()).arg(velocidad);
                                                    comandos << cmd;
                                                }
                                            }
                                            QString c4 = QString::fromUtf8(tr("echo Expulsando disco grabado..."));
                                            QString cmd4= "eject";
                                            comandos << c4 << cmd4;
                                            if (mib != 0)
                                            delete mib;
                                            mib = new DrakeProcesos1(comandos, this);
                                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                                            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                                            int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
                                        }
                                        else
                                        {
                                            if (ui->comboBox_2->currentText().toInt() > 1 && Copia < ui->comboBox_2->currentText().toInt())
                                            {}
                                            else
                                            {
                                                QString c1 = QString::fromUtf8(tr("echo Creando imagen de datos..."));
                                                comandos << c1;
                                            }
                                            QString cmd, c2, cmd1, c3, cmd3, c4, cmd4;
                                            if (ui->groupBox_7->isChecked())
                                            {
                                                if (ui->checkBox_4->isChecked())
                                                {
                                                    QString str = ui->lineEdit_2->text();
                                                    if (str.contains(".iso", Qt::CaseInsensitive) == true)
                                                    {
                                                        cmd = "su - %1 -c \"mkisofs -RJ -v -V \"%4\" -o %3 %2\"";
                                                        cmd = cmd.arg(user).arg(cadena).arg(ui->lineEdit_2->text()).arg(ui->lineEdit->text());
                                                        comandos << cmd;
                                                    }
                                                    else
                                                    {
                                                        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                                                        m.setText(tr(QString::fromUtf8("Introduce un nombre en la ruta para poder crear la iso.")));
                                                        m.exec();
                                                        Opcion = 0;
                                                        Contador->start(10000);
                                                        ui->progressBar->show();
                                                        ui->label_5->show();
                                                        return;
                                                    }
                                                }
                                                else
                                                {
                                                    if (ui->comboBox_2->currentText().toInt() > 1 && Copia < ui->comboBox_2->currentText().toInt())
                                                    {}
                                                    else
                                                    {
                                                        cmd = "su - %1 -c \"mkisofs -RJ -v -V \"%4\" -o %3RCV_DATA.iso %2\"";
                                                        cmd = cmd.arg(user).arg(cadena).arg(ui->lineEdit_2->text()).arg(ui->lineEdit->text());
                                                        c2 = QString::fromUtf8(tr("echo Grabando imagen de datos..."));
                                                        comandos << cmd << c2;
                                                    }
                                                    if (TipoMedio == "CD")
                                                    {
                                                       if (ui->checkBox_3->isChecked())
                                                       {
                                                           cmd1 = "su - %1 -c \"cdrecord -v -multi dev=%2 speed=%3 -overburn -data %4RCV_DATA.iso\"";
                                                           cmd1=cmd1.arg(user).arg(Dev).arg(velocidad).arg(ui->lineEdit_2->text());
                                                       }
                                                       else
                                                       {
                                                           cmd1 = "su - %1 -c \"cdrecord -v dev=%2 speed=%3 -overburn -data %4RCV_DATA.iso\"";
                                                           cmd1=cmd1.arg(user).arg(Dev).arg(velocidad).arg(ui->lineEdit_2->text());
                                                       }
                                                  }
                                                  else if (TipoMedio == "DVD")
                                                  {
                                                      if (ui->checkBox_3->isChecked())
                                                      {
                                                          cmd1 = "su - %1 -c \"growisofs -dvd-compat -speed=%2 -Z /dev/dvd=%3RCV_DATA.iso\"";
                                                          cmd1=cmd1.arg(user).arg(velocidad).arg(ui->lineEdit_2->text());
                                                       }
                                                       else
                                                       {
                                                          cmd1 = "su - %1 -c \"growisofs -speed=%2 -Z /dev/dvd=%3RCV_DATA.iso\"";
                                                          cmd1=cmd1.arg(user).arg(velocidad).arg(ui->lineEdit_2->text());
                                                       }
                                                   }
                                                   c4 = QString::fromUtf8(tr("echo Expulsando disco grabado..."));
                                                   cmd4= "eject";
                                                   comandos << cmd1 << c4 << cmd4;
                                                   mib = new DrakeProcesos1(comandos, this);
                                                   connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                                                   connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                                                   connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                                                   int valor= comandos.count(); mib->Valor(valor,1); mib->iniciarProceso();
                                                }
                                            }
                                            else
                                            {
                                                cmd = "su - %1 -c \"mkisofs -RJ -v -V \"%4\" -o %3RCV_DATA.iso %2\"";
                                                cmd = cmd.arg(user).arg(cadena).arg(path).arg(ui->lineEdit->text());
                                                c2 = QString::fromUtf8(tr("echo Grabando imagen de datos..."));
                                                if (TipoMedio == "CD")
                                                {
                                                    if (ui->checkBox_3->isChecked())
                                                    {
                                                        cmd1 = "su - %1 -c \"cdrecord -v -multi dev=%2 speed=%3 -overburn -data %4RCV_DATA.iso\"";
                                                        cmd1=cmd1.arg(user).arg(Dev).arg(velocidad).arg(ui->lineEdit_2->text());
                                                    }
                                                    else
                                                    {
                                                        cmd1 = "su - %1 -c \"cdrecord -v dev=%2 speed=%3 -overburn -data %4RCV_DATA.iso\"";
                                                        cmd1=cmd1.arg(user).arg(Dev).arg(velocidad).arg(ui->lineEdit_2->text());
                                                    }
                                                }
                                                else if (TipoMedio == "DVD")
                                                {
                                                    if (ui->checkBox_3->isChecked())
                                                    {
                                                        cmd1 = "su - %1 -c \"growisofs -speed=%2 -dvd-compat -Z /dev/dvd=%3RCV_DATA.iso2\"";
                                                        cmd1=cmd1.arg(user).arg(velocidad).arg(ui->lineEdit_2->text());
                                                    }
                                                    else
                                                    {
                                                        cmd1 = "su - %1 -c \"growisofs -speed=%2 -Z /dev/dvd=%3RCV_DATA.iso\"";
                                                        cmd1=cmd1.arg(user).arg(velocidad).arg(ui->lineEdit_2->text());
                                                    }
                                                }
                                                c3 = QString::fromUtf8(tr("echo Borrando imagen temporal..."));
                                                cmd3 = "su - %1 -c \"rm -vf %2RCV_DATA.iso\"";
                                                cmd3=cmd3.arg(user).arg(path);
                                                c4 = QString::fromUtf8(tr("echo Expulsando disco grabado..."));
                                                cmd4= "eject";
                                                comandos << cmd << c2 << cmd1 << c3 << cmd3 << c4 << cmd4;
                                                if (mib != 0)
                                                delete mib;
                                                mib = new DrakeProcesos1(comandos, this);
                                                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                                                connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                                                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                                                int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
                                            }
                                        }
                                    }
                                    if (Grabando == "DVDVideoCopy")
                                    {                                        
                                        ui->progressBar->show();
                                        ui->label_5->show();                                       
                                        if (Counter == 0)
                                        {
                                            if (Copia == ui->comboBox_2->currentText().toInt())
                                            {
                                                Copia = Copia + 1;
                                                Counter = 1;
                                                system("eject");
                                                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                                                m.setText(tr("Introduce el DVD a copiar.<p>" "Pulsa Ok para continuar..."));
                                                m.exec();
                                                system("eject -t");
                                                int C = 0;
                                                while (C < 15)
                                                {
                                                    if (TipoMedio != "")
                                                    {
                                                        QTest::qWait(1000);
                                                        C++;
                                                    }
                                                    else
                                                        C=0;
                                                }
                                                QString path="/home/%1/";
                                                path=path.arg(user);
                                                QString cmd, c4, cmd1;
                                                QStringList comandos;



                                                //Me he quedado por aqui. Falta terminar esta parte o por lo menos por probar.


                                                cmd = "su - %1 -c \"dvdbackup -M -v -n BckDVD -i /dev/dvd -o %2tmp/\"";
                                                cmd = cmd.arg(user).arg(path);
                                                c4 = QString::fromUtf8(tr("echo Expulsando disco leido..."));
                                                cmd1 = "eject";
                                                comandos << cmd << c4 << cmd1;
                                                if (mib != 0)
                                                delete mib;
                                                mib = new DrakeProcesos1(comandos, this);
                                                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                                                connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                                                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                                                int valor= comandos.count(); mib->Valor(valor,1); mib->iniciarProceso();
                                            }
                                        }
                                        else if (Counter == 1)
                                        {
                                            QString c2, cmd1, c4, cmd4;
                                            QStringList comandos;
                                            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                                            m.setText(tr("Introduce el medio a copiar.<p>" "Pulsa Ok para continuar..."));
                                            m.exec();
                                            system("eject -t");
                                            int C = 0;
                                            while (C < 15)
                                            {
                                                if (TipoMedio != "")
                                                {
                                                    QTest::qWait(1000);
                                                    C++;
                                                }
                                                else
                                                    C=0;
                                            }
                                            c2 = QString::fromUtf8(tr("echo Grabando imagen de datos..."));
                                            cmd1 = "su - %1 -c \"growisofs -dvd-video -speed=%2 -Z /dev/dvd=%3tmp/BckDVD/\"";
                                            cmd1=cmd1.arg(user).arg(velocidad).arg(path);
                                            c4 = QString::fromUtf8(tr("echo Expulsando disco grabado..."));
                                            cmd4= "eject";
                                            comandos << c2 << cmd1 << c4 << cmd4;
                                            mib = new DrakeProcesos1(comandos, this);
                                            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                                            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                                            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                                            int valor= comandos.count(); mib->Valor(valor,1); mib->iniciarProceso();
                                        }
                                    }
                                    if (Grabando == "")
                                    {
                                        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                                        m.setText(tr("No se ha dado ninguna orden de grabacion."));
                                        m.exec();
                                        Opcion = 0;
                                        Contador->start(10000);
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }    
}

void burn::on_pushButton_18_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setTabText(1,"Opciones");
    ui->tabWidget->setTabIcon(1,QIcon(":/Imagenes/local-administration-mdk.png"));
}

void burn::on_tabWidget_currentChanged(int index)
{
    Q_UNUSED(index);
    if (ui->tabWidget->currentIndex() == 0)
    {
        ui->groupBox_11->hide();
        ui->tabWidget->setTabIcon(1,QIcon(":/Imagenes/local-administration-mdk.png"));
        ui->pushButton_14->setHidden(true);
        ui->groupBox_7->setEnabled(true);
        ui->pushButton_19->setEnabled(true);
        ui->groupBox_8->setEnabled(true);
        ui->groupBox_11->setEnabled(true);
        ui->groupBox_5->setEnabled(true);
        ui->tabWidget->setTabText(1,"Opciones");
    }
    else
    {
        if (ui->pushButton_14->isHidden())
        {
            ui->tabWidget->setTabIcon(1,QIcon(":/Imagenes/local-administration-mdk.png"));
            ui->tabWidget->setTabText(1,"Opciones");
        }
    }
}

void burn::on_pushButton_19_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    Contador->stop();
    if (cdrkit == "0")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr(QString::fromUtf8("No se puede utilizar esta función sin instalar la dependencia \"cdrkit\" necesaria.<p>Realize la instalación para poder utilizarla.")));
        m.exec();
    }
    else
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Cerrar disco")),
                               QString::fromUtf8(tr("<center><b>Cerrar disco<center><p>"
                               "IMPORTANTE: Si cierras el disco, ya no podras hacer multisesion "
                               "y por lo tanto no se podra grabar mas en el, salvo que sea regrabable.<p>"
                               "&iquest;Cerrar disco CD/DVD?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            QStringList comandos;
            QString c3 = QString::fromUtf8(tr("echo Cerrando disco..."));
            QString cmd3 = "su - %1 -c \"growisofs -M /dev/dvd=/dev/zero\"";
            cmd3=cmd3.arg(user);
            QString c4 = QString::fromUtf8(tr("echo Expulsando disco grabado..."));
            QString cmd4= "eject";
            comandos << c3 << cmd3 << c4 << cmd4;;
            if (mib != 0)
            delete mib;
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
        }
    }
    Opcion = 0;
}

void burn::on_comboBox_2_currentIndexChanged(QString )
{
    Copia = ui->comboBox_2->currentText().toInt();
}

void burn::on_pushButton_20_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setTabText(1,"Grabar");
    ui->pushButton_14->setVisible(true);
    ui->groupBox_11->show();
    ui->tabWidget->setTabIcon(1,QIcon(":/Imagenes/cd_burning_section.png"));
    ui->groupBox_7->setEnabled(false);
    ui->pushButton_19->setEnabled(false);
    ui->groupBox_8->setEnabled(false);
    ui->groupBox_11->setEnabled(false);
    ui->groupBox_5->setEnabled(false);
    Grabando = "DVDVideoCopy";
}

//falta por terminar
