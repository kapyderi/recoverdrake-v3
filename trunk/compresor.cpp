#include "compresor.h"
#include "ui_compresor.h"
#include <QSqlQuery>
#include <QCloseEvent>
#include <QDebug>
#include "drakesistema.h"
#include <QProcess>
#include <QMessageBox>
#include <QMimeData>


//falta por ver la linea 306 de kernel.cpp para descomprimir en otro directorio.


compresor::compresor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compresor)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    drakeSistema drake;
    user = drake.getUser();
    Stilo = "B";
    mib = 0;
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
    fdlg = new QFileDialog(this, "Buscador");
    connect(fdlg, SIGNAL(finished(int)),fdlg, SLOT(open()));
    connect(fdlg, SIGNAL(filesSelected(QStringList)), this, SLOT(ValorRuta(QStringList)));
    fdlg->setLabelText(QFileDialog::Reject, NULL);
    fdlg->setLabelText(QFileDialog::Accept, tr("Insertar archivos"));
    ui->gridLayout_4->addWidget(fdlg);
    fdlg->setWindowState(Qt::WindowMaximized);
    fdlg->setDir("/home/"+user);
    fdlg->setNameFilter(tr("Todos los archivos (*.*)"));
    fdlg->setFileMode(QFileDialog::ExistingFiles);
    fdlg->setViewMode(QFileDialog::Detail);
    fdlg->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
    fdlg1 = new QFileDialog(this, "Buscador");
    connect(fdlg1, SIGNAL(finished(int)),fdlg1, SLOT(open()));
    connect(fdlg1, SIGNAL(fileSelected(QString)), this, SLOT(Listado(QString)));
    ui->gridLayout_7->addWidget(fdlg1);
    fdlg1->setWindowState(Qt::WindowMaximized);
    fdlg1->setDir("/home/"+user);
    fdlg1->setNameFilter(tr("Todos los archivos compatibles (*.tar *.gz *.bz2 *.tar.gz *.tar.bz2 *.zip *.zoo *.arj *.7z *.rar);;Archivos tar (*.tar);;Archivos gz (*.gz);;Archivos bz2 (*.bz2);;Archivos tar.gz (*.tar.gz);;Archivos tar.bz2 (*.tar.bz2)"
                             ";;Archivos zip (*.zip);;Archivos zoo (*.zoo);;Archivos arj (*.arj);;Archivos 7z (*.7z);;Archivos rar (*.rar)"));
    fdlg1->setLabelText(QFileDialog::Reject, NULL);
    fdlg1->setLabelText(QFileDialog::Accept, tr("Seleccionar"));
    fdlg1->setViewMode(QFileDialog::Detail);
    fdlg1->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_13,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_14,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Empaquet()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Empaquet()));
    connect(ui->radioButton_5,SIGNAL(clicked()),this,SLOT(Empaquet()));
    connect(ui->radioButton_6,SIGNAL(clicked()),this,SLOT(Empaquet()));
    connect(ui->radioButton_7,SIGNAL(clicked()),this,SLOT(Empaquet()));
    connect(ui->radioButton_8,SIGNAL(clicked()),this,SLOT(Empaquet()));
    connect(ui->radioButton_9,SIGNAL(clicked()),this,SLOT(Empaquet()));
    connect(ui->radioButton_10,SIGNAL(clicked()),this,SLOT(Empaquet()));
    connect(ui->radioButton_11,SIGNAL(clicked()),this,SLOT(Empaquet()));
    connect(ui->radioButton_12,SIGNAL(clicked()),this,SLOT(Empaquet()));
    ui->radioButton->setChecked(true);
    this->Comprobar();
    ui->radioButton_3->setChecked(true);
    ui->checkBox->setVisible(true);
    ui->radioButton_13->setChecked(true);
    ui->checkBox_2->setVisible(false);
    this->Comprobar1();
    this->installEventFilter(this);
    ui->tableWidget->installEventFilter(this);
    CierreTotal = 0;
    Posicion = 0;
    TipoCom = 0;
    connect(ui->checkBox_6,SIGNAL(clicked()),this,SLOT(Comprobar3()));
    connect(ui->checkBox_7,SIGNAL(clicked()),this,SLOT(Comprobar4()));
    connect(ui->checkBox_8,SIGNAL(clicked()),this,SLOT(Comprobar5()));
    connect(ui->checkBox_7,SIGNAL(clicked()),this,SLOT(Comprobar6()));
    this->Empaquet();
    Evento = 0;
    ui->progressBar->hide();
    NoMessage = 0;
    TipoClick = 1;
    this->Comprobar2();
    this->Comprobar5();
}

compresor::~compresor()
{
    delete ui;
}

void compresor::Valor(QString valor, QString Logs)
{
    if (valor == "Quitar")
        CierreTotal = 1;
    if (Logs == "S")
        Log = "S";
    else
        Log = "N";
}

void compresor::closeEvent ( QCloseEvent * event )
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

void compresor::changeEvent(QEvent *e)
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

bool compresor::eventFilter(QObject* obj, QEvent *event)
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
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("Kompresor"));
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
                on_pushButton_2_clicked();
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

QString compresor::getSize(QString Dir)
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

void compresor::on_pushButton_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void compresor::Comprobar()
{
    if (ui->radioButton->isChecked())
    {
        if (TipoCom == 1)
        {
            this->Empaquet();
            ui->checkBox->setVisible(true);
            ui->stackedWidget->setCurrentIndex(0);
            TipoCom = 0;
            int Borrado, x;
            Borrado = ui->tableWidget->rowCount();
            for(x=0;x<Borrado;x++)
            {
                 ui->tableWidget->removeRow(x);
                 x=x-1;
                 Borrado=Borrado-1;
            }
        }
        ui->groupBox_5->setVisible(false);
        ui->groupBox_4->setVisible(true);
        ui->groupBox_3->setEnabled(true);
        ui->tableWidget->show();
        ui->tableWidget_2->hide();
        ui->label_4->hide();
        ui->checkBox_8->hide();
    }
    else if (ui->radioButton_2->isChecked())
    {
        if (TipoCom == 0)
        {
            ui->checkBox->setVisible(false);
            ui->stackedWidget->setCurrentIndex(1);
            TipoCom = 1;
            int Borrado, x;
            Borrado = ui->tableWidget->rowCount();
            for(x=0;x<Borrado;x++)
            {
                 ui->tableWidget->removeRow(x);
                 x=x-1;
                 Borrado=Borrado-1;
            }
        }
        ui->groupBox_5->setVisible(true);
        ui->groupBox_4->setVisible(false);
        ui->groupBox_3->setEnabled(false);
        ui->tableWidget->hide();
        ui->tableWidget_2->show();
        ui->label_4->show();
        ui->checkBox_8->show();
    }
}

void compresor::Comprobar1()
{
    if (ui->radioButton_13->isChecked())
    {
        fdlg->setFileMode(QFileDialog::ExistingFiles);
        fdlg->setNameFilter(tr("Todos los archivos (*.*)"));
        fdlg->setLabelText(QFileDialog::Accept, tr("Insertar archivos"));
        ui->checkBox_2->setVisible(false);        
        Posicion = 0;
    }
    else if (ui->radioButton_14->isChecked())
    {
        fdlg->setFileMode(QFileDialog::Directory);
        fdlg->setOption(QFileDialog::ShowDirsOnly);
        fdlg->setNameFilterDetailsVisible(false);
        fdlg->setLabelText(QFileDialog::Accept, tr("Insertar directorio"));
        ui->checkBox_2->setVisible(true);       
        Posicion = 1;
    }
}

void compresor::ValorRuta(QStringList valor)
{
    drakeSistema drake;
    QTableWidgetItem *item1,*item2,*item3;
    QStringList Depurado;
    QString rutaAbs, Tipo, Peso;
    float f;
    int iFilas, cantidad;
    Lista.clear();
    if (ui->checkBox_2->isChecked())
    {
        QStringList Parcial;
        QString Directorio = valor.value(0);
        QString Desglose = getDir(Directorio);
        Desglose = Desglose.remove("\\");
        Parcial = Desglose.split("\n");
        for(int a=0;a<Parcial.count();a++)
        {
            QString Fichero = valor.value(0)+"/"+Parcial.value(a);
            QString tipo = drake.getTipo(Fichero);
            QStringList Tipillo = tipo.split(":");
            QString tipe = Tipillo.value(1);
            cantidad=ui->tableWidget->rowCount();
            if (cantidad != 0)
            {
                if (ui->checkBox_2->isChecked())
                {
                    if (tipe == " directory")
                    {
                        if (Fichero.endsWith("/") == false)
                            Fichero = Fichero+"/";
                    }
                    items = ui->tableWidget->findItems(Fichero, Qt::MatchExactly);
                    if (items.count() == 0)
                    {
                        QString tipo = drake.getTipo(Fichero);
                        QStringList Tipillo = tipo.split(":");
                        QString tipe = Tipillo.value(1);
                        if (tipe == " directory")
                        {
                            item1=new QTableWidgetItem;
                            item2=new QTableWidgetItem;
                            item3=new QTableWidgetItem;
                            rutaAbs = Fichero;
                            QString size= getSize(rutaAbs);
                            QString ruta;
                            if (rutaAbs.endsWith("/") == false)
                                ruta= rutaAbs+"/";
                            else
                                ruta= rutaAbs;
                            item1->setText(tr("DIRECTORIO"));
                            item2->setText(tr(ruta));
                            f=size.toFloat()/1024;
                            if (f <= 700)
                            {
                                item3->setText(""+QString::number(f,'f',3)+"Mb");
                                Tipo = "Mb";
                            }
                            if (f > 700)
                            {
                                float g = f / 1024;
                                item3->setText(""+QString::number(g,'f',3)+"Gb");
                                Peso = "Gb";
                                Tipo = "Gb";
                            }
                            iFilas=ui->tableWidget->rowCount();
                            ui->tableWidget->insertRow(iFilas);
                            ui->tableWidget->setItem(iFilas,0,item1);
                            ui->tableWidget->setItem(iFilas,1,item2);
                            ui->tableWidget->setItem(iFilas,2,item3);
                            ui->tableWidget->resizeRowsToContents();
                            ui->tableWidget->resizeColumnsToContents();
                        }
                        else
                            Lista << Fichero;
                    }
                }
            }
            else
            {
                if (tipe == " directory")
                {
                    item1=new QTableWidgetItem;
                    item2=new QTableWidgetItem;
                    item3=new QTableWidgetItem;
                    rutaAbs = Fichero;
                    QString size= getSize(rutaAbs);
                    QString ruta;
                    if (rutaAbs.endsWith("/") == false)
                        ruta= rutaAbs+"/";
                    else
                        ruta= rutaAbs;
                    item1->setText(tr("DIRECTORIO"));
                    item2->setText(tr(ruta));
                    f=size.toFloat()/1024;
                    if (f <= 700)
                    {
                        item3->setText(""+QString::number(f,'f',3)+"Mb");
                        Tipo = "Mb";
                    }
                    if (f > 700)
                    {
                        float g = f / 1024;
                        item3->setText(""+QString::number(g,'f',3)+"Gb");
                        Peso = "Gb";
                        Tipo = "Gb";
                    }
                    iFilas=ui->tableWidget->rowCount();
                    ui->tableWidget->insertRow(iFilas);
                    ui->tableWidget->setItem(iFilas,0,item1);
                    ui->tableWidget->setItem(iFilas,1,item2);
                    ui->tableWidget->setItem(iFilas,2,item3);
                    ui->tableWidget->resizeRowsToContents();
                    ui->tableWidget->resizeColumnsToContents();
                }
                else
                    Lista << Fichero;
            }
        }
    }
    else
        Lista << valor;
    cantidad=ui->tableWidget->rowCount();
    if (cantidad != 0)
    {
        if (ui->checkBox_2->isChecked())
        {
            for(int a=0;a<Lista.count();a++)
            {
                QString Value = Lista.value(a);
                items = ui->tableWidget->findItems(Value, Qt::MatchExactly);
                if (items.count() == 0)
                    Depurado << Value;
            }
        }
        else
        {
            for(int a=0;a<valor.count();a++)
            {
                QString Value = valor.value(a);
                QString tipo = drake.getTipo(Value);
                QStringList Tipillo = tipo.split(":");
                QString tipe = Tipillo.value(1);
                if (tipe == " directory")
                {
                    if (Value.endsWith("/") == false)
                        Value = Value+"/";
                }
                items = ui->tableWidget->findItems(Value, Qt::MatchExactly);
                if (items.count() == 0)
                    Depurado << Value;
            }
        }
    }
    else
        Depurado << Lista;
    if (!Depurado.isEmpty())
    {
        if (Posicion == 1)
        {
            if (ui->checkBox_2->isChecked())
            {
                for (int a=0;a<Depurado.count();a++)
                {
                    item1=new QTableWidgetItem;
                    item2=new QTableWidgetItem;
                    item3=new QTableWidgetItem;
                    rutaAbs = Depurado.value(a);
                    QFile file(rutaAbs);
                    float size = QFileInfo(file).size();
                    item1->setText(tr(QFileInfo(file).fileName()));
                    item2->setText(tr(rutaAbs));
                    f = (size + 1023) / 1024;
                    f = f / 1024;
                    if (f <= 700)
                    {
                        item3->setText(""+QString::number(f,'f',3)+"Mb");
                        Tipo = "Mb";
                    }
                    if (f > 700)
                    {
                        float g = f / 1024;
                        item3->setText(""+QString::number(g,'f',3)+"Gb");
                        Peso = "Gb";
                        Tipo = "Gb";
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
            else
            {
                item1=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                item3=new QTableWidgetItem;
                rutaAbs = Depurado.value(0);
                QString size= getSize(rutaAbs);
                QString ruta;
                if (rutaAbs.endsWith("/") == false)
                    ruta= rutaAbs+"/";
                else
                    ruta= rutaAbs;
                item1->setText(tr("DIRECTORIO"));
                item2->setText(tr(ruta));
                f=size.toFloat()/1024;
                if (f <= 700)
                {
                    item3->setText(""+QString::number(f,'f',3)+"Mb");
                    Tipo = "Mb";
                }
                if (f > 700)
                {
                    float g = f / 1024;
                    item3->setText(""+QString::number(g,'f',3)+"Gb");
                    Peso = "Gb";
                    Tipo = "Gb";
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
        else
        {
            for (int a=0;a<Depurado.count();a++)
            {
                item1=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                item3=new QTableWidgetItem;
                rutaAbs = Depurado.value(a);
                QFile file(rutaAbs);
                float size = QFileInfo(file).size();
                item1->setText(tr(QFileInfo(file).fileName()));
                item2->setText(tr(rutaAbs));
                f = (size + 1023) / 1024;
                f = f / 1024;
                if (f <= 700)
                {
                    item3->setText(""+QString::number(f,'f',3)+"Mb");
                    Tipo = "Mb";
                }
                if (f > 700)
                {
                    float g = f / 1024;
                    item3->setText(""+QString::number(g,'f',3)+"Gb");
                    Peso = "Gb";
                    Tipo = "Gb";
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
    this->Comprobar2();
}

void compresor::Value(QString Valor)
{
    Lista.clear();
    Lista << Valor;
}

void compresor::Listado(QString Valor)
{
    ui->label_4->setText(tr("Fichero: "));
    ui->label_4->setText(tr("Fichero: ")+Valor);
    int Borrado, x;
    Borrado = ui->tableWidget_2->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget_2->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    if (Valor.endsWith(".tar"))
        LPaquet = ".tar";
    if (Valor.endsWith(".gz"))
        LPaquet = ".gz";
    if (Valor.endsWith(".bz2"))
        LPaquet = ".bz2";
    if (Valor.endsWith(".tar.gz"))
        LPaquet = ".tar.gz";
    if (Valor.endsWith(".tar.bz2"))
        LPaquet = ".tar.bz2";
    if (Valor.endsWith(".zip"))
        LPaquet = ".zip";
    if (Valor.endsWith(".zoo"))
        LPaquet = ".zoo";
    if (Valor.endsWith(".arj"))
        LPaquet = ".arj";
    if (Valor.endsWith(".7z"))
        LPaquet = ".7z";
    if (Valor.endsWith(".rar"))
        LPaquet = ".rar";
    QString Lista, Value;
    float f;
    int iFilas;
    QTableWidgetItem *item1,*item2, *item3, *item4;
    if (LPaquet == ".tar")
    {
        ui->pushButton_8->show();
        ui->tableWidget_2->hideColumn(3);
        Value = "su - %2 -c \"tar -t --list -f '%1'\"";
        Value = Value.arg(Valor).arg(user);
        Lista = getListado(Value);
        QStringList Parcial = Lista.split("\n");
        for(int a=0;a<Parcial.count();a++)
        {
            QString FFinal = Parcial.value(a);
            FFinal.replace(QRegExp("\\s+"), " ");
            FFinal.trimmed();
            QStringList Final = FFinal.split(" ");
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            QString size= Final.value(2);
            QString Juntar;
            for (int h=5;h<Final.count();h++)
                Juntar.append(Final.value(h)+" ");
            item1->setText(Juntar);
            item3->setText(tr("SIN COMPRESION"));
            f=(size.toFloat()/1024)/1024;
            if (f <= 700)
                item2->setText(""+QString::number(f,'f',2)+"Mb");
            if (f > 700)
            {
                float g = f / 1024;
                item2->setText(""+QString::number(g,'f',2)+"Gb");
            }
            iFilas=ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(iFilas);
            ui->tableWidget_2->setItem(iFilas,0,item1);
            ui->tableWidget_2->setItem(iFilas,1,item2);
            ui->tableWidget_2->setItem(iFilas,2,item3);
            ui->tableWidget_2->resizeRowsToContents();
            ui->tableWidget_2->resizeColumnsToContents();
        }
    }
    if (LPaquet == ".gz")
    {
        ui->pushButton_8->hide();
        QString ValorT, ValorC;
        Value = "su - %2 -c \"gzip -l '%1'\"";
        Value = Value.arg(Valor).arg(user);
        Lista = getListado(Value);
        QStringList Parcial = Lista.split("\n");
        QString FFinal = Parcial.value(1);
        FFinal.replace(QRegExp("\\s+"), " ");
        FFinal.trimmed();
        QStringList Final = FFinal.split(" ");
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        item4=new QTableWidgetItem;
        QString Juntar;
        for (int a=1;a<Final.count();a++)
        {
            if (a == 1)
            {
                ValorC = Final.value(a);
                f=(ValorC.toFloat()/1024)/1024;
                if (f <= 700)
                    item4->setText(""+QString::number(f,'f',2)+"Mb");
                if (f > 700)
                {
                    float g = f / 1024;
                    item4->setText(""+QString::number(g,'f',2)+"Gb");
                }
            }
            if (a == 2)
            {
                ValorT = Final.value(a);
                f=(ValorT.toFloat()/1024)/1024;
                if (f <= 700)
                    item2->setText(""+QString::number(f,'f',2)+"Mb");
                if (f > 700)
                {
                    float g = f / 1024;
                    item2->setText(""+QString::number(g,'f',2)+"Gb");
                }
            }
            if (a == 3)
                item3->setText(Final.value(a));
            if (a >= 4)
                Juntar.append(Final.value(a)+" ");
        }
        item1->setText(Juntar);
        iFilas=ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(iFilas);
        ui->tableWidget_2->setItem(iFilas,0,item1);
        ui->tableWidget_2->setItem(iFilas,1,item2);
        ui->tableWidget_2->setItem(iFilas,2,item3);
        ui->tableWidget_2->setItem(iFilas,3,item4);
        ui->tableWidget_2->resizeRowsToContents();
        ui->tableWidget_2->resizeColumnsToContents();
    }
    if (LPaquet == ".bz2")
    {
        ui->pushButton_8->hide();
        ui->tableWidget_2->hideColumn(1);
        ui->tableWidget_2->hideColumn(2);
        ui->tableWidget_2->hideColumn(3);
        item1=new QTableWidgetItem;
        Valor.remove(".bz2");
        item1->setText(Valor);
        iFilas=ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(iFilas);
        ui->tableWidget_2->setItem(iFilas,0,item1);
        ui->tableWidget_2->resizeRowsToContents();
        ui->tableWidget_2->resizeColumnsToContents();
    }
    if (LPaquet == ".tar.gz")
    {
        ui->pushButton_8->show();
        ui->tableWidget_2->hideColumn(2);
        ui->tableWidget_2->hideColumn(3);
        Value = "su - %2 -c \"tar -tz --list -f '%1'\"";
        Value = Value.arg(Valor).arg(user);
        Lista = getListado(Value);
        QStringList Parcial = Lista.split("\n");
        for(int a=0;a<Parcial.count();a++)
        {
            QString FFinal = Parcial.value(a);
            FFinal.replace(QRegExp("\\s+"), " ");
            FFinal.trimmed();
            QStringList Final = FFinal.split(" ");
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            QString size= Final.value(2);
            QString Juntar;
            for (int h=5;h<Final.count();h++)
                Juntar.append(Final.value(h)+" ");
            item1->setText(Juntar);
            f=(size.toFloat()/1024)/1024;
            if (f <= 700)
                item2->setText(""+QString::number(f,'f',2)+"Mb");
            if (f > 700)
            {
                float g = f / 1024;
                item2->setText(""+QString::number(g,'f',2)+"Gb");
            }
            iFilas=ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(iFilas);
            ui->tableWidget_2->setItem(iFilas,0,item1);
            ui->tableWidget_2->setItem(iFilas,1,item2);
            ui->tableWidget_2->resizeRowsToContents();
            ui->tableWidget_2->resizeColumnsToContents();
        }
    }
    if (LPaquet == ".tar.bz2")
    {
        ui->pushButton_8->show();
        ui->tableWidget_2->hideColumn(2);
        ui->tableWidget_2->hideColumn(3);
        Value = "su - %2 -c \"tar -tj --list -f '%1'\"";
        Value = Value.arg(Valor).arg(user);
        Lista = getListado(Value);
        QStringList Parcial = Lista.split("\n");
        for(int a=0;a<Parcial.count();a++)
        {
            QString FFinal = Parcial.value(a);
            FFinal.replace(QRegExp("\\s+"), " ");
            FFinal.trimmed();
            QStringList Final = FFinal.split(" ");
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            QString size= Final.value(2);
            QString Juntar;
            for (int h=5;h<Final.count();h++)
                Juntar.append(Final.value(h)+" ");
            item1->setText(Juntar);
            f=(size.toFloat()/1024)/1024;
            if (f <= 700)
                item2->setText(""+QString::number(f,'f',2)+"Mb");
            if (f > 700)
            {
                float g = f / 1024;
                item2->setText(""+QString::number(g,'f',2)+"Gb");
            }
            iFilas=ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(iFilas);
            ui->tableWidget_2->setItem(iFilas,0,item1);
            ui->tableWidget_2->setItem(iFilas,1,item2);
            ui->tableWidget_2->resizeRowsToContents();
            ui->tableWidget_2->resizeColumnsToContents();
        }
    }
    if (LPaquet == ".zip")
    {
        ui->pushButton_8->show();
        QString ValorT, ValorC;
        Value = "su - %2 -c \"unzip -v '%1'\"";
        Value = Value.arg(Valor).arg(user);
        Lista = getListado(Value);
        QStringList Parcial = Lista.split("\n");
        for (int i=3;i<Parcial.count();i++)
        {
            QString Value = Parcial.value(i);
            if (Value.contains("--------"))
                break;
            QString FFinal = Parcial.value(i);
            FFinal.replace(QRegExp("\\s+"), " ");
            FFinal.trimmed();
            QStringList Final = FFinal.split(" ");
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            QString Juntar;
            for (int a=1;a<Final.count();a++)
            {
                if (a == 1)
                {
                    ValorC = Final.value(a);
                    f=(ValorC.toFloat()/1024)/1024;
                    if (f <= 700)
                        item2->setText(""+QString::number(f,'f',2)+"Mb");
                    if (f > 700)
                    {
                        float g = f / 1024;
                        item2->setText(""+QString::number(g,'f',2)+"Gb");
                    }
                }
                if (a == 3)
                {
                    ValorT = Final.value(a);
                    f=(ValorT.toFloat()/1024)/1024;
                    if (f <= 700)
                        item4->setText(""+QString::number(f,'f',2)+"Mb");
                    if (f > 700)
                    {
                        float g = f / 1024;
                        item4->setText(""+QString::number(g,'f',2)+"Gb");
                    }
                }
                if (a == 4)
                    item3->setText(Final.value(a));
                if (a >= 8)
                    Juntar.append(Final.value(a)+" ");
            }
            item1->setText(Juntar);
            iFilas=ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(iFilas);
            ui->tableWidget_2->setItem(iFilas,0,item1);
            ui->tableWidget_2->setItem(iFilas,1,item2);
            ui->tableWidget_2->setItem(iFilas,2,item3);
            ui->tableWidget_2->setItem(iFilas,3,item4);
            ui->tableWidget_2->resizeRowsToContents();
            ui->tableWidget_2->resizeColumnsToContents();
        }
    }
    if (LPaquet == ".zoo")
    {
        ui->pushButton_8->show();
        QString ValorT, ValorC;
        Value = "su - %2 -c \"zoo -L '%1'\"";
        Value = Value.arg(Valor).arg(user);
        Lista = getListado(Value);
        QStringList Parcial = Lista.split("\n");
        for (int i=4;i<Parcial.count();i++)
        {
            QString Value = Parcial.value(i);
            if (Value.contains("--------"))
                break;
            QString FFinal = Parcial.value(i);
            FFinal.replace(QRegExp("\\s+"), " ");
            FFinal.trimmed();
            QStringList Final = FFinal.split(" ");
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            QString Juntar;
            for (int a=1;a<Final.count();a++)
            {
                if (a == 1)
                {
                    ValorC = Final.value(a);
                    f=(ValorC.toFloat()/1024)/1024;
                    if (f <= 700)
                        item2->setText(""+QString::number(f,'f',2)+"Mb");
                    if (f > 700)
                    {
                        float g = f / 1024;
                        item2->setText(""+QString::number(g,'f',2)+"Gb");
                    }
                }
                if (a == 2)
                    item3->setText(Final.value(a));
                if (a == 3)
                {
                    ValorT = Final.value(a);
                    f=(ValorT.toFloat()/1024)/1024;
                    if (f <= 700)
                        item4->setText(""+QString::number(f,'f',2)+"Mb");
                    if (f > 700)
                    {
                        float g = f / 1024;
                        item4->setText(""+QString::number(g,'f',2)+"Gb");
                    }
                }
                if (a >= 9)
                    Juntar.append(Final.value(a)+" ");
            }
            item1->setText(Juntar);
            iFilas=ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(iFilas);
            ui->tableWidget_2->setItem(iFilas,0,item1);
            ui->tableWidget_2->setItem(iFilas,1,item2);
            ui->tableWidget_2->setItem(iFilas,2,item3);
            ui->tableWidget_2->setItem(iFilas,3,item4);
            ui->tableWidget_2->resizeRowsToContents();
            ui->tableWidget_2->resizeColumnsToContents();
        }
    }
    if (LPaquet == ".arj")
    {
        ui->pushButton_8->show();
        int Posicion;
        QString ValorT, ValorC;
        Value = "su - %2 -c \"arj v '%1'\"";
        Value = Value.arg(Valor).arg(user);
        Lista = getListado(Value);
        QStringList Parcial = Lista.split("\n");
        for (int i=7;i<Parcial.count();i++)
        {
            QString Value = Parcial.value(i);
            if (Value.contains("--------"))
                break;
            QString Juntar;
            if (Value.contains(")"))
            {
                QString FFinal = Parcial.value(i);
                FFinal.replace(QRegExp("\\s+"), " ");
                FFinal.trimmed();
                QStringList Nombre = FFinal.split(")");
                item1=new QTableWidgetItem;
                for (int h=1;h<Nombre.count();h++)
                    Juntar.append(Nombre.value(h)+" ");
                item1->setText(Juntar);
                Posicion = 0;
            }
            if (Value.contains(":") && !Value.contains("DTA") && !Value.contains("DTC"))
            {
                QString FFinal = Parcial.value(i);
                FFinal.replace(QRegExp("\\s+"), " ");
                FFinal.trimmed();
                QStringList Nombre = FFinal.split(" ");
                qDebug() << Nombre;
                item2=new QTableWidgetItem;
                item3=new QTableWidgetItem;
                item4=new QTableWidgetItem;
                for (int h=3;h<Nombre.count();h++)
                {
                    if (h == 3)
                    {
                        ValorC = Nombre.value(h);
                        f=(ValorC.toFloat()/1024)/1024;
                        if (f <= 700)
                            item2->setText(""+QString::number(f,'f',2)+"Mb");
                        if (f > 700)
                        {
                            float g = f / 1024;
                            item2->setText(""+QString::number(g,'f',2)+"Gb");
                        }
                    }
                    if (h == 4)
                    {
                        ValorT = Nombre.value(h);
                        f=(ValorT.toFloat()/1024)/1024;
                        if (f <= 700)
                            item4->setText(""+QString::number(f,'f',2)+"Mb");
                        if (f > 700)
                        {
                            float g = f / 1024;
                            item4->setText(""+QString::number(g,'f',2)+"Gb");
                        }
                    }
                    if (h == 5)
                    {
                        double  Numero, Resto;
                        Numero = Nombre.value(h).toDouble();
                        Resto = 100-(Numero*100);
                        item3->setText(QString::number(Resto)+"%");
                    }
                    Posicion = 1;
                }
            }
            if (Posicion == 0)
            {
                iFilas=ui->tableWidget_2->rowCount();
                ui->tableWidget_2->insertRow(iFilas);
                ui->tableWidget_2->setItem(iFilas,0,item1);
            }
            else if (Posicion == 1)
            {
                ui->tableWidget_2->setItem(iFilas,1,item2);
                ui->tableWidget_2->setItem(iFilas,2,item3);
                ui->tableWidget_2->setItem(iFilas,3,item4);
            }
            ui->tableWidget_2->resizeRowsToContents();
            ui->tableWidget_2->resizeColumnsToContents();
        }
    }
    if (LPaquet == ".7z")
    {
        ui->pushButton_8->show();
        int Igual = 0;
        QString ValorT, ValorC;
        Value = "su - %2 -c \"7z l '%1'\"";
        Value = Value.arg(Valor).arg(user);
        Lista = getListado(Value);
        QStringList Parcial = Lista.split("\n");
        for (int i=17;i<Parcial.count();i++)
        {
            QString Value = Parcial.value(i);
            if (Value.contains("--------"))
                break;
            QString FFinal = Parcial.value(i);
            FFinal.replace(QRegExp("\\s+"), " ");
            FFinal.trimmed();
            QStringList Final = FFinal.split(" ");
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            QString Juntar;
            for (int a=3;a<Final.count();a++)
            {
                if (a == 3)
                {
                    ValorC = Final.value(a);
                    f=(ValorC.toFloat()/1024)/1024;
                    if (f <= 700)
                        item4->setText(""+QString::number(f,'f',2)+"Mb");
                    if (f > 700)
                    {
                        float g = f / 1024;
                        item4->setText(""+QString::number(g,'f',2)+"Gb");
                    }
                }
                if (a == 4)
                {
                    QChar ascii;
                    int numero;
                    ValorT = Final.value(a);
                    ascii=ValorT.at(0).toAscii();
                    numero=ascii.toAscii() ;
                    if (numero >= 48 && numero <=57)
                    {
                        f=(ValorT.toFloat()/1024)/1024;
                        if (f <= 700)
                            item2->setText(""+QString::number(f,'f',2)+"Mb");
                        if (f > 700)
                        {
                            float g = f / 1024;
                            item2->setText(""+QString::number(g,'f',2)+"Gb");
                        }
                    }
                    else
                    {
                        Igual = 1;
                        Juntar.append(Final.value(a)+" ");
                    }
                }
                if (a >= 5)
                    Juntar.append(Final.value(a)+" ");
            }
            item1->setText(Juntar);
            if (Igual == 1)
                item2->setText(item4->text());
            QString ValorRatioF, ValorRatioI;
            ValorRatioF = item4->text();
            ValorRatioF.chop(2);
            ValorRatioI = item2->text();
            ValorRatioI.chop(2);
            float RatioF, RatioI, RatioFinal;
            RatioF = ValorRatioF.toFloat();
            RatioI = ValorRatioI.toFloat();
            RatioFinal = 100-((RatioF*100)/RatioI);
            item3->setText(QString::number(RatioFinal,'f',2)+"%");
            iFilas=ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(iFilas);
            ui->tableWidget_2->setItem(iFilas,0,item1);
            ui->tableWidget_2->setItem(iFilas,1,item2);
            ui->tableWidget_2->setItem(iFilas,2,item3);
            ui->tableWidget_2->setItem(iFilas,3,item4);
            ui->tableWidget_2->resizeRowsToContents();
            ui->tableWidget_2->resizeColumnsToContents();
        }
    }
    if (LPaquet == ".rar")
    {
        ui->pushButton_8->show();
        QString ValorT, ValorC;
        Value = "su - %2 -c \"rar v '%1'\"";
        Value = Value.arg(Valor).arg(user);
        Lista = getListado(Value);
        QStringList Parcial = Lista.split("\n");
        for (int i=9;i<Parcial.count();i++)
        {
            QString Value = Parcial.value(i);
            if (Value.contains("--------"))
                break;
            QString FFinal = Parcial.value(i);
            FFinal.replace(QRegExp("\\s+"), " ");
            FFinal.trimmed();
            QStringList Final = FFinal.split(" ");
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            QString Juntar;
            for (int a=2;a<Final.count();a++)
            {
                qDebug() << Final.value(a);
                if (a == 2)
                {
                    ValorC = Final.value(a);
                    f=(ValorC.toFloat()/1024)/1024;
                    if (f <= 700)
                        item2->setText(""+QString::number(f,'f',2)+"Mb");
                    if (f > 700)
                    {
                        float g = f / 1024;
                        item2->setText(""+QString::number(g,'f',2)+"Gb");
                    }
                }
                if (a == 3)
                {
                    ValorT = Final.value(a);
                    f=(ValorT.toFloat()/1024)/1024;
                    if (f <= 700)
                        item4->setText(""+QString::number(f,'f',2)+"Mb");
                    if (f > 700)
                    {
                        float g = f / 1024;
                        item4->setText(""+QString::number(g,'f',2)+"Gb");
                    }
                }
                if (a == 4)
                    item3->setText(Final.value(a));
                if (a >= 8)
                    Juntar.append(Final.value(a)+" ");
            }
            item1->setText(Juntar);
            iFilas=ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(iFilas);
            ui->tableWidget_2->setItem(iFilas,0,item1);
            ui->tableWidget_2->setItem(iFilas,1,item2);
            ui->tableWidget_2->setItem(iFilas,2,item3);
            ui->tableWidget_2->setItem(iFilas,3,item4);
            ui->tableWidget_2->resizeRowsToContents();
            ui->tableWidget_2->resizeColumnsToContents();
        }
    }
    ui->label_2->setText(tr("Extraer ")+LPaquet+tr(" en..."));
}

QString compresor::getListado(QString Comando)
{
    QProcess *procesoRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    procesoRPM->start(Comando);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    delete procesoRPM;
    QString res = QString(Paquete);
    res.chop(1);
    return res;
}

void compresor::on_pushButton_2_clicked()
{
    int j;
    if (ui->radioButton->isChecked())
    {
        j=ui->tableWidget->currentRow();
        if (j == -1)
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No has seleccionado ningun registro, por lo que no puedes realizar lo que has solicitado."));
            m.exec();
            return;
        }
        else
            ui->tableWidget->removeRow(j);
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();
    }
    if (ui->radioButton_2->isChecked())
    {
        j=ui->tableWidget_2->currentRow();
        if (j == -1)
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No has seleccionado ningun registro, por lo que no puedes realizar lo que has solicitado."));
            m.exec();
            return;
        }
        else
            ui->tableWidget_2->removeRow(j);
        ui->tableWidget_2->resizeColumnsToContents();
        ui->tableWidget_2->resizeRowsToContents();
    }
    ui->label_4->setText(tr("Fichero: "));
}

void compresor::on_pushButton_3_clicked()
{
    ui->label_4->setText(tr("Fichero: "));
    if (ui->radioButton->isChecked())
    {
        int Borrado, x;
        Borrado = ui->tableWidget->rowCount();
        for(x=0;x<Borrado;x++)
        {
             ui->tableWidget->removeRow(x);
             x=x-1;
             Borrado=Borrado-1;
        }
        ui->label->setText(tr("Comprimir/Empaquetar en..."));
    }
    if (ui->radioButton_2->isChecked())
    {
        int Borrado, x;
        Borrado = ui->tableWidget_2->rowCount();
        for(x=0;x<Borrado;x++)
        {
             ui->tableWidget_2->removeRow(x);
             x=x-1;
             Borrado=Borrado-1;
        }
        ui->label_2->setText(tr("Extraer en..."));
    }
    NoMessage = 1;
    this->Comprobar2();
}

void compresor::on_pushButton_5_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    if (ui->checkBox->isChecked())
    {
        QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio destino?"),path,QFileDialog::ShowDirsOnly);
        if (fileNameDirectori.isEmpty())
           return;
        ui->lineEdit->setText(fileNameDirectori);
        FullDirectori = ui->lineEdit->text();
        this->Comprobar2();
    }
    else
    {
        QString fileNameDestino = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar archivo "+Paquet)),
                            path,trUtf8(tr("Archivo "+Paquet+" (*"+Paquet+")")));
        if (fileNameDestino.isEmpty())
            return;
        if (!fileNameDestino.contains(Paquet))
            fileNameDestino.append(Paquet);
        ui->lineEdit->setText(fileNameDestino);
        FullRute = ui->lineEdit->text();
        this->Comprobar2();
    }
}

void compresor::Empaquet()
{
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    if (ui->radioButton_3->isChecked())
    {
        Paquet = ".tar";
        ui->comboBox->hide();
        ui->label_3->hide();
        ui->checkBox_5->hide();
        ui->comboBox_2->hide();
        ui->checkBox_6->hide();
        ui->lineEdit->setEnabled(true);
        ui->label->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
    }
    if (ui->radioButton_4->isChecked())
    {
        Paquet = ".gz";
        ui->comboBox->show();
        ui->label_3->show();
        ui->label_3->setText(tr("Nivel de compresion (1 Menor ~ 9 Mayor)"));
        ui->checkBox_5->show();
        QStringList Valores;
        Valores << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9";
        ui->comboBox->clear();
        ui->comboBox->addItems(Valores);
        ui->comboBox_2->hide();
        ui->checkBox_6->hide();
        ui->lineEdit->setEnabled(false);
        ui->label->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->checkBox_4->setEnabled(false);
    }
    if (ui->radioButton_5->isChecked())
    {
        Paquet = ".bz2";
        ui->comboBox->show();
        ui->label_3->show();
        ui->label_3->setText(tr("Nivel de compresion (1 Menor ~ 9 Mayor)"));
        ui->checkBox_5->show();
        QStringList Valores;
        Valores << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9";
        ui->comboBox->clear();
        ui->comboBox->addItems(Valores);
        ui->checkBox_5->hide();
        ui->comboBox_2->hide();
        ui->checkBox_6->hide();
        ui->lineEdit->setEnabled(false);
        ui->label->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->checkBox_4->setEnabled(false);
    }
    if (ui->radioButton_6->isChecked())
    {
        Paquet = ".tar.gz";
        ui->comboBox->hide();
        ui->label_3->hide();
        ui->checkBox_5->hide();
        ui->comboBox_2->hide();
        ui->checkBox_6->hide();
        ui->lineEdit->setEnabled(true);
        ui->label->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
    }
    if (ui->radioButton_7->isChecked())
    {
        Paquet = ".tar.bz2";
        ui->comboBox->hide();
        ui->label_3->hide();
        ui->checkBox_5->hide();
        ui->comboBox_2->hide();
        ui->checkBox_6->hide();
        ui->lineEdit->setEnabled(true);
        ui->label->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
    }
    if (ui->radioButton_8->isChecked())
    {
        Paquet = ".zip";
        ui->comboBox->show();
        ui->label_3->show();
        ui->label_3->setText(tr("Nivel de compresion (1 Menor ~ 9 Mayor)"));
        ui->checkBox_5->show();
        QStringList Valores;
        Valores << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9";
        ui->comboBox->clear();
        ui->comboBox->addItems(Valores);
        ui->checkBox_5->show();
        ui->comboBox_2->hide();
        ui->checkBox_6->hide();
        ui->lineEdit->setEnabled(true);
        ui->label->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
    }
    if (ui->radioButton_9->isChecked())
    {
        Paquet = ".zoo";
        ui->comboBox->hide();
        ui->label_3->hide();
        ui->checkBox_5->hide();
        ui->comboBox_2->hide();
        ui->checkBox_6->hide();
        ui->lineEdit->setEnabled(true);
        ui->label->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
    }
    if (ui->radioButton_10->isChecked())
    {
        Paquet = ".arj";
        ui->comboBox->hide();
        ui->label_3->hide();
        ui->checkBox_5->show();
        ui->comboBox_2->show();
        ui->checkBox_6->show();
        ui->lineEdit->setEnabled(true);
        ui->label->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        this->Comprobar3();
    }
    if (ui->radioButton_11->isChecked())
    {
        Paquet = ".7z";
        ui->comboBox->show();
        ui->label_3->show();
        ui->label_3->setText(tr("Nivel de compresion (1 Menor ~ 9 Mayor)"));
        ui->checkBox_5->show();
        QStringList Valores;
        Valores << "1" << "3" <<  "5" <<  "7" <<  "9";
        ui->comboBox->clear();
        ui->comboBox->addItems(Valores);
        ui->checkBox_5->show();
        ui->comboBox_2->show();
        ui->checkBox_6->show();
        ui->lineEdit->setEnabled(true);
        ui->label->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        this->Comprobar3();
    }
    if (ui->radioButton_12->isChecked())
    {
        Paquet = ".rar";
        ui->comboBox->show();
        ui->label_3->show();
        ui->label_3->setText(tr("Nivel de compresion (1 Menor ~ 5 Mayor)"));
        ui->checkBox_5->show();
        QStringList Valores;
        Valores << "1" << "2" << "3" << "4" << "5";
        ui->comboBox->clear();
        ui->comboBox->addItems(Valores);
        ui->checkBox_5->show();
        ui->comboBox_2->show();
        ui->checkBox_6->show();
        ui->lineEdit->setEnabled(true);
        ui->label->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->checkBox_4->setEnabled(true);
        this->Comprobar3();
    }
    if (ui->radioButton->isChecked())
        ui->label->setText(tr("Comprimir/Empaquetar ")+Paquet+tr(" en..."));
    if (ui->lineEdit->text() != "")
    {
        QString Valor = ui->lineEdit->text();
        QFileInfo fi(Valor);
        QString ext = fi.suffix();
        if (ext.contains("tar"))
            Valor.remove(".tar");
        if (ext.contains("gz"))
        {
            if (Valor.contains("tar.gz"))
                Valor.remove(".tar.gz");
            else
                Valor.remove(".gz");
        }
        if (ext.contains("bz2"))
        {
            if (Valor.contains("tar.bz2"))
                Valor.remove(".tar.bz2");
            else
                Valor.remove(".bz2");
        }
        if (ext.contains("zip"))
            Valor.remove(".zip");
        if (ext.contains("zoo"))
            Valor.remove(".zoo");
        if (ext.contains("arj"))
            Valor.remove(".arj");
        if (ext.contains("7z"))
            Valor.remove(".7z");
        if (ext.contains("rar"))
            Valor.remove(".rar");
        ui->lineEdit->setText(Valor+Paquet);
    }
    if (ui->checkBox_4->isChecked())
    {
        ui->lineEdit->setEnabled(false);
        ui->label->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
    }
    else
    {
        ui->lineEdit->setEnabled(true);
        ui->label->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
    }
}

void compresor::on_pushButton_4_clicked()
{
    int cantidad;
    cantidad=ui->tableWidget->rowCount();
    if (cantidad != 0)
    {
        QString nombre, nombreParcial, cadena, rutaParcial, nombreParcial1, ruta, Encadena;
        if (ui->checkBox_3->isChecked() && ui->checkBox_4->isChecked())
        {
            QTableWidgetItem *itemA;
            itemA=ui->tableWidget->item(0,1);
            rutaParcial= itemA->text();
            cadena.append(rutaParcial+Paquet);
        }
        else if (ui->checkBox_3->isChecked())
        {
            QTableWidgetItem *itemA;
            itemA=ui->tableWidget->item(0,0);
            nombre= itemA->text();
            nombreParcial = "/"+nombre+Paquet;
            if (ui->lineEdit->text() != "")
            {
                nombreParcial1=ui->lineEdit->text();
                QStringList Parcial = nombreParcial1.split("/");
                for(int a=1;a<Parcial.count()-1;a++)
                    Encadena.append("/"+Parcial.value(a));
                cadena = Encadena+nombreParcial;
                ui->lineEdit->setText(cadena);
            }
            else
            {
                if (ui->radioButton_4->isChecked() || ui->radioButton_5->isChecked())
                {}
                else
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("Debes introducir una ruta para poder comprimir/empaquetar."));
                    m.exec();
                    return;
                }
            }
        }
        else if (ui->checkBox_4->isChecked())
        {
            if (!ui->checkBox->isChecked())
            {
                if (ui->lineEdit->text() != "")
                {
                    nombreParcial=ui->lineEdit->text();
                    nombreParcial = nombreParcial.remove(Paquet);
                    QStringList Parcial = nombreParcial.split("/");
                    Encadena = Parcial.value(Parcial.count()-1);
                    QTableWidgetItem *itemA;
                    itemA=ui->tableWidget->item(0,1);
                    ruta= itemA->text();
                    QStringList Parcial1 = ruta.split("/");
                    for(int a=1;a<Parcial1.count()-1;a++)
                        cadena.append("/"+Parcial1.value(a));
                    cadena.append("/"+Encadena+Paquet);
                    ui->lineEdit->setText(cadena);
                }
                else
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("No hay ninguna nombre de destino para comprimir se coge por defecto el que hay en la primera ruta."));
                    m.exec();
                    QTableWidgetItem *itemA;
                    itemA=ui->tableWidget->item(0,1);
                    ruta= itemA->text();
                    cadena.append(ruta+Paquet);
                    ui->lineEdit->setText(cadena);
                }
            }
        }
        else
        {
            if (ui->lineEdit->text() != "")
                cadena = ui->lineEdit->text();
            else
            {
                if (ui->radioButton_4->isChecked() || ui->radioButton_5->isChecked())
                {}
                else
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("Debes introducir una ruta para poder comprimir/empaquetar."));
                    m.exec();
                    return;
                }
            }
        }
        QStringList comandos;
        if (ui->checkBox->isChecked())
        {
            ui->progressBar->show();
            QTableWidgetItem *item1;
            QString activo1;            
            int itemCount = ui->tableWidget->rowCount();
            if (itemCount == 0)
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("No hay ningun registro, por lo que no puedes procesar la solicitud."));
                m.exec();
                return;
            }
            else
            {
                TotalProceso=0;
                QString cmd = QString::fromUtf8(tr("echo Realizando compresion/empaquetado..."));
                comandos<< cmd;
                Evento = 0;
                for(int i=0;i<itemCount;i++)
                {
                    if (Evento == 1)
                    {
                        ui->textEdit->append(tr("Trabajo cancelado"));
                        ui->progressBar->setValue(0);
                        ui->progressBar->hide();
                        return;
                    }
                    item1 = ui->tableWidget->item(i,1);
                    activo1 = item1->text();
                    QString cmd1, cadena1;
                    cadena1 = ui->lineEdit->text();
                    if (Paquet == ".tar")
                    {
                        cmd1= "su - %3 -c \"tar -vcf '%1' '%2'\"";
                        cmd1=cmd1.arg(cadena1).arg(activo1).arg(user);
                    }
                    if (Paquet == ".gz")
                    {
                        if (ui->checkBox_5->isChecked())
                            cmd1= "su - %3 -c \"gzip -vfrk -%2 '%1'\"";
                        else
                            cmd1= "su - %3 -c \"gzip -vfk -%2 '%1'\"";
                        cmd1=cmd1.arg(activo1).arg(ui->comboBox->currentText()).arg(user);
                    }
                    if (Paquet == ".bz2")
                    {
                        cmd1= "su - %3 -c \"bzip2 -vfk -%2 '%1'\"";
                        cmd1=cmd1.arg(activo1).arg(ui->comboBox->currentText()).arg(user);
                    }
                    if (Paquet == ".tar.gz")
                    {
                        cmd1= "su - %3 -c \"tar -vczf '%1' '%2'\"";
                        cmd1=cmd1.arg(cadena1).arg(activo1).arg(user);
                    }
                    if (Paquet == ".tar.bz2")
                    {
                        cmd1= "su - %3 -c \"tar -vcjf '%1' '%2'\"";
                        cmd1=cmd1.arg(cadena1).arg(activo1).arg(user);
                    }
                    if (Paquet == ".zip")
                    {
                        if (ui->checkBox_5->isChecked())
                            cmd1= "su - %4 -c \"zip -vr -%3 '%1' '%2'\"";
                        else
                            cmd1= "su - %4 -c \"zip -v -%3 '%1' '%2'\"";
                        cmd1=cmd1.arg(cadena1).arg(activo1).arg(ui->comboBox->currentText()).arg(user);
                    }
                    if (Paquet == ".zoo")
                    {
                        cmd1= "su - %3 -c \"zoo a '%1' '%2'\"";
                        cmd1=cmd1.arg(cadena1).arg(activo1).arg(user);
                    }
                    if (Paquet == ".arj")
                    {
                        if (ui->checkBox_6->isChecked())
                        {
                            if (ui->checkBox_5->isChecked())
                                cmd1= "su - %4 -c \"arj a -y -r -v%3 '%1' '%2'\"";
                            else
                                cmd1= "su - %4 -c \"arj a -y -v%3 '%1' '%2'\"";
                            cmd1=cmd1.arg(cadena1).arg(activo1).arg(ui->comboBox_2->currentText()).arg(user);
                        }
                        else
                        {
                            if (ui->checkBox_5->isChecked())
                                cmd1= "su - %3 -c \"arj a -y -r '%1' '%2'\"";
                            else
                                cmd1= "su - %3 -c \"arj a -y '%1' '%2'\"";
                            cmd1=cmd1.arg(cadena1).arg(activo1).arg(user);
                        }
                    }
                    if (Paquet == ".7z")
                    {
                        if (ui->checkBox_6->isChecked())
                        {
                            if (ui->checkBox_5->isChecked())
                                cmd1= "su - %5 -c \"7z a -y -r -mx=%3 -v%4 '%1' '%2'\"";
                            else
                                cmd1= "su - %5 -c \"7z a -y -mx=%3 -v%4 '%1' '%2'\"";
                            cmd1=cmd1.arg(cadena1).arg(activo1).arg(ui->comboBox->currentText()).arg(ui->comboBox_2->currentText()).arg(user);
                        }
                        else
                        {
                            if (ui->checkBox_5->isChecked())
                                cmd1= "su - %4 -c \"7z a -y -r -mx=%3 '%1' '%2'\"";
                            else
                                cmd1= "su - %4 -c \"7z a -y -mx=%3 '%1' '%2'\"";
                            cmd1=cmd1.arg(cadena1).arg(activo1).arg(ui->comboBox->currentText()).arg(user);
                        }
                    }
                    if (Paquet == ".rar")
                    {
                        if (ui->checkBox_6->isChecked())
                        {
                            if (ui->checkBox_5->isChecked())
                                cmd1= "su - %5 -c \"rar a -ep2 -y -r -m%3 -v%4 '%1' '%2'\"";
                            else
                                cmd1= "su - %5 -c \"rar a -ep2 -y -m%3 -v%4 '%1' '%2'\"";
                            cmd1=cmd1.arg(cadena1).arg(activo1).arg(ui->comboBox->currentText()).arg(ui->comboBox_2->currentText()).arg(user);
                        }
                        else
                        {
                            if (ui->checkBox_5->isChecked())
                                cmd1= "su - %4 -c \"rar a -ep2 -y -r -m%3 '%1' '%2'\"";
                            else
                                cmd1= "su - %4 -c \"rar a -ep2 -y -m%3 '%1' '%2'\"";
                            cmd1=cmd1.arg(cadena1).arg(activo1).arg(ui->comboBox->currentText()).arg(user);
                        }
                    }
                    comandos<< cmd1;
                }                
            }
        }
        else
        {
            QTableWidgetItem *item1;
            QString activo1;
            int itemCount = ui->tableWidget->rowCount();
            if (itemCount == 0)
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("No hay ningun registro, por lo que no puedes procesar la solicitud."));
                m.exec();
                return;
            }
            else
            {
                QStringList Lista;
                QString cmd1, cadena1;
                TotalProceso=0;
                QString cmd = QString::fromUtf8(tr("echo Realizando compresion/empaquetado..."));
                comandos<< cmd;
                cadena1 = ui->lineEdit->text();
                for(int i=0;i<itemCount;i++)
                {
                    item1 = ui->tableWidget->item(i,1);
                    Lista << "'"+item1->text()+"' ";
                }
                activo1 = Lista.join("");
                if (Paquet == ".tar")
                {
                    cmd1= "su - %3 -c \"tar -vcf '%1' %2\"";
                    cmd1=cmd1.arg(cadena1).arg(activo1).arg(user);
                }               
                if (Paquet == ".tar.gz")
                {
                    cmd1= "su - %3 -c \"tar -vczf '%1' %2\"";
                    cmd1=cmd1.arg(cadena1).arg(activo1).arg(user);
                }
                if (Paquet == ".tar.bz2")
                {
                    cmd1= "su - %3 -c \"tar -vcjf '%1' %2\"";
                    cmd1=cmd1.arg(cadena1).arg(activo1).arg(user);
                }
                if (Paquet == ".zip")
                {
                    if (ui->checkBox_5->isChecked())
                        cmd1= "su - %4 -c \"zip -vr -%3 '%1' %2\"";
                    else
                        cmd1= "su - %4 -c \"zip -v -%3 '%1' %2\"";
                    cmd1=cmd1.arg(cadena1).arg(activo1).arg(ui->comboBox->currentText()).arg(user);
                }
                if (Paquet == ".zoo")
                {
                    cmd1= "su - %3 -c \"zoo a '%1' %2\"";
                    cmd1=cmd1.arg(cadena1).arg(activo1).arg(user);
                }
                if (Paquet == ".arj")
                {
                    if (ui->checkBox_6->isChecked())
                    {
                        if (ui->checkBox_5->isChecked())
                            cmd1= "su - %4 -c \"arj a -y -r -v%3 '%1' %2\"";
                        else
                            cmd1= "su - %4 -c \"arj a -y -v%3 '%1' %2\"";
                        cmd1=cmd1.arg(cadena1).arg(activo1).arg(ui->comboBox_2->currentText()).arg(user);
                    }
                    else
                    {
                        if (ui->checkBox_5->isChecked())
                            cmd1= "su - %3 -c \"arj a -y -r '%1' %2\"";
                        else
                            cmd1= "su - %3 -c \"arj a -y '%1' %2\"";
                        cmd1=cmd1.arg(cadena1).arg(activo1).arg(user);
                    }
                }
                if (Paquet == ".7z")
                {
                    if (ui->checkBox_6->isChecked())
                    {
                        if (ui->checkBox_5->isChecked())
                            cmd1= "su - %5 -c \"7z a -y -r -mx=%3 -v%4 '%1' %2\"";
                        else
                            cmd1= "su - %5 -c \"7z a -y -mx=%3 -v%4 '%1' %2\"";
                        cmd1=cmd1.arg(cadena1).arg(activo1).arg(ui->comboBox->currentText()).arg(ui->comboBox_2->currentText()).arg(user);
                    }
                    else
                    {
                        if (ui->checkBox_5->isChecked())
                            cmd1= "su - %4 -c \"7z a -y -r -mx=%3 '%1' %2\"";
                        else
                            cmd1= "su - %4 -c \"7z a -y -mx=%3 '%1' %2\"";
                        cmd1=cmd1.arg(cadena1).arg(activo1).arg(ui->comboBox->currentText()).arg(user);
                    }
                }
                if (Paquet == ".rar")
                {
                    if (ui->checkBox_6->isChecked())
                    {
                        if (ui->checkBox_5->isChecked())
                            cmd1= "su - %5 -c \"rar a -ep2 -y -r -m%3 -v%4 '%1' %2\"";
                        else
                            cmd1= "su - %5 -c \"rar a -ep2 -y -m%3 -v%4 '%1' %2\"";
                        cmd1=cmd1.arg(cadena1).arg(activo1).arg(ui->comboBox->currentText()).arg(ui->comboBox_2->currentText()).arg(user);
                    }
                    else
                    {
                        if (ui->checkBox_5->isChecked())
                            cmd1= "su - %4 -c \"rar a -ep2 -y -r -m%3 '%1' %2\"";
                        else
                            cmd1= "su - %4 -c \"rar a -ep2 -y -m%3 '%1' %2\"";
                        cmd1=cmd1.arg(cadena1).arg(activo1).arg(ui->comboBox->currentText()).arg(user);
                    }
                }
                comandos<< cmd1;
            }
        }
        if (mib != 0)
            delete mib;
        ui->progressBar->show();
        mib = new DrakeProcesos(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count();
        mib->Valor(valor,3);
        mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
        mib->iniciarProceso();
        Totalizar = comandos.count();
        ui->progressBar->setRange(0,Totalizar);
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay registros para comprimir/empaquetar."));
        m.exec();
        return;
    }
}

QString compresor::getDir(QString Ruta)
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
        argumentosRPM << "-1" << Ruta;
    procesoRPM->start("dir",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    delete procesoRPM;
    QString res = QString(Paquete);
    res.chop(1);
    return res;
}

void compresor::Comprobar2()
{
    int cantidad;
    QString nombre, nombreParcial, cadena, ruta, Encadena, nombreParcial1;
    if (TipoClick == 1)
    {
        if (ui->checkBox->isChecked())
        {
            ui->radioButton_4->show();
            ui->radioButton_5->show();
            ui->checkBox_4->setText(tr("Utilizar misma ruta"));
            ui->checkBox_3->setVisible(false);
            if (ui->lineEdit->text() != "")
            {
                if (FullDirectori != "")
                {
                    nombreParcial=FullDirectori;
                    nombreParcial = nombreParcial.remove(Paquet);
                    QStringList Parcial = nombreParcial.split("/");
                    Encadena = Parcial.value(Parcial.count()-1);
                    nombreParcial.remove(Encadena);
                    ui->lineEdit->setText(nombreParcial);
                }
                else
                {
                    QString nombreParcial, Encadena;
                    FullRute = ui->lineEdit->text();
                    nombreParcial=ui->lineEdit->text();
                    nombreParcial = nombreParcial.remove(Paquet);
                    QStringList Parcial = nombreParcial.split("/");
                    Encadena = Parcial.value(Parcial.count()-1);
                    nombreParcial.remove(Encadena);
                    ui->lineEdit->setText(nombreParcial);
                }
                if (ui->lineEdit->text().endsWith("/") == true)
                {
                    QString Valor = ui->lineEdit->text();
                    Valor.chop(1);
                    ui->lineEdit->setText(Valor);
                }
            }
        }
        else if(!ui->checkBox->isChecked())
        {
            ui->radioButton_4->hide();
            ui->radioButton_5->hide();
            ui->checkBox_4->setText(tr("Utilizar misma ruta (Primer registro)"));
            ui->checkBox_3->setVisible(true);
            if (ui->lineEdit->text() != "")
            {
                if (FullRute != "")
                    ui->lineEdit->setText(FullRute);
                else
                    ui->lineEdit->setText("");
            }
        }
    }
    if (TipoClick == 3)
    {
        if (ui->checkBox_4->isChecked())
        {            
            ui->lineEdit->setEnabled(false);
            ui->label->setEnabled(false);
            ui->pushButton_5->setEnabled(false);
            if (!ui->checkBox->isChecked())
            {
                cantidad=ui->tableWidget->rowCount();
                if (cantidad != 0)
                {
                    if (ui->lineEdit->text() != "")
                    {
                        nombreParcial=ui->lineEdit->text();
                        nombreParcial = nombreParcial.remove(Paquet);
                        QStringList Parcial = nombreParcial.split("/");
                        Encadena = Parcial.value(Parcial.count()-1);
                        QTableWidgetItem *itemA;
                        itemA=ui->tableWidget->item(0,1);
                        ruta= itemA->text();
                        QStringList Parcial1 = ruta.split("/");
                        for(int a=1;a<Parcial1.count()-1;a++)
                            cadena.append("/"+Parcial1.value(a));
                        cadena.append("/"+Encadena+Paquet);
                        ui->lineEdit->setText(cadena);
                    }
                    else
                    {
                        QMessageBox m;
                        if (Stilo == "A")
                            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                        m.setText(tr("No hay ninguna nombre de destino para comprimir/empaquetar se coge por defecto el que hay en la primera ruta."));
                        m.exec();
                        QTableWidgetItem *itemA;
                        itemA=ui->tableWidget->item(0,1);
                        ruta= itemA->text();
                        cadena = ruta+Paquet;
                        ui->lineEdit->setText(cadena);
                    }
                }
                else
                {
                    if (NoMessage == 0)
                    {
                        QMessageBox m;
                        if (Stilo == "A")
                            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                        m.setText(tr("No hay registros cargados. Carga archivos para utilizar esta opcion"));
                        m.exec();
                    }
                    ui->lineEdit->setEnabled(true);
                    ui->label->setEnabled(true);
                    ui->pushButton_5->setEnabled(true);
                    ui->checkBox_4->setChecked(false);
                }
            }
        }
        else
        {
            if (ui->checkBox_3->isChecked())
            {
                if (ui->lineEdit->text() != "")
                {
                    cantidad=ui->tableWidget->rowCount();
                    if (cantidad != 0)
                    {
                        QTableWidgetItem *itemA, *itemB;
                        itemA=ui->tableWidget->item(0,0);
                        nombre= itemA->text();
                        if (nombre == tr("DIRECTORIO"))
                        {
                            QString nombreParcial;
                            itemB=ui->tableWidget->item(0,1);
                            nombreParcial = itemB->text();
                            QStringList Parcial1 = nombreParcial.split("/");
                            nombre = Parcial1.value(Parcial1.count()-2);
                        }
                        nombreParcial = "/"+nombre+Paquet;
                        if (ui->lineEdit->text() != "")
                        {
                            nombreParcial1=FullRute;
                            QStringList Parcial = nombreParcial1.split("/");
                            for(int a=1;a<Parcial.count()-1;a++)
                                Encadena.append("/"+Parcial.value(a));
                            cadena = Encadena+nombreParcial;
                            ui->lineEdit->setText(cadena);
                        }
                    }
                }
            }
            else
                ui->lineEdit->setText(FullRute);
            ui->lineEdit->setEnabled(true);
            ui->label->setEnabled(true);
            ui->pushButton_5->setEnabled(true);
        }
    }
    if (TipoClick == 2)
    {
        if (ui->checkBox_3->isChecked())
        {
            if (ui->checkBox_4->isChecked())
            {
                ui->lineEdit->setEnabled(false);
                ui->label->setEnabled(false);
                ui->pushButton_5->setEnabled(false);
            }
            else
            {
                ui->lineEdit->setEnabled(true);
                ui->label->setEnabled(true);
                ui->pushButton_5->setEnabled(true);
            }
            cantidad=ui->tableWidget->rowCount();
            if (cantidad != 0)
            {
                QTableWidgetItem *itemA, *itemB;
                itemA=ui->tableWidget->item(0,0);
                nombre= itemA->text();
                if (nombre == tr("DIRECTORIO"))
                {
                    QString nombreParcial;
                    itemB=ui->tableWidget->item(0,1);
                    nombreParcial = itemB->text();
                    QStringList Parcial1 = nombreParcial.split("/");
                    nombre = Parcial1.value(Parcial1.count()-2);
                }
                nombreParcial = "/"+nombre+Paquet;
                if (ui->lineEdit->text() != "")
                {
                    nombreParcial1=ui->lineEdit->text();
                    QStringList Parcial = nombreParcial1.split("/");
                    for(int a=1;a<Parcial.count()-1;a++)
                        Encadena.append("/"+Parcial.value(a));
                    cadena = Encadena+nombreParcial;
                    ui->lineEdit->setText(cadena);
                }
            }
            else
            {
                if (NoMessage == 0)
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("No hay registros cargados. Carga archivos para utilizar esta opcion"));
                    m.exec();
                }
                ui->checkBox_3->setChecked(false);
            }
        }
        else
        {
            if (ui->checkBox_4->isChecked())
            {
                if (ui->lineEdit->text() != "")
                {
                    QString nombreParcial = FullRute;
                    QStringList Parcial1 = nombreParcial.split("/");
                    nombre = Parcial1.value(Parcial1.count()-1);
                    nombreParcial = "/"+nombre;
                    nombreParcial1=ui->lineEdit->text();
                    QStringList Parcial = nombreParcial1.split("/");
                    for(int a=1;a<Parcial.count()-1;a++)
                        Encadena.append("/"+Parcial.value(a));
                    cadena = Encadena+nombreParcial;
                    ui->lineEdit->setText(cadena);
                }
            }
            else
                ui->lineEdit->setText(FullRute);
        }
    }
}

void compresor::Comprobar3()
{
    if (ui->checkBox_6->isChecked())
        ui->comboBox_2->show();
    else
        ui->comboBox_2->hide();
}

void compresor::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
    if (Log == "S")
        system(QString::fromUtf8("echo '"+valor+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
}

void compresor::ProcesarValor(QString ValorComand)
{
    int iFilas, a;
    QString valor;
    iFilas=ui->tableWidget->rowCount();
    QTableWidgetItem *item;
    for(a=0;a<iFilas;a++)
    {
        item=ui->tableWidget->item(a,0);
        valor=item->text();
        if(ValorComand.contains(valor))
            ui->tableWidget->selectRow(a);
     }
     TotalProceso = TotalProceso+1;
     ui->progressBar->setValue(TotalProceso);
}

void compresor::mibprogreso(QString Dat)
{
     ui->progressBar->setValue(Dat.toInt());
}

void compresor::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    if (TotalProceso == Totalizar)
    {
        ui->progressBar->setValue(0);
        ui->progressBar->hide();
    }
}

void compresor::on_checkBox_clicked()
{
    TipoClick = 1;
    this->Comprobar2();
}

void compresor::on_checkBox_3_clicked()
{
    TipoClick = 2;
    this->Comprobar2();
}

void compresor::on_checkBox_4_clicked()
{
    TipoClick = 3;
    this->Comprobar2();
}

void compresor::Comprobar4()
{
    if (ui->checkBox_7->isChecked())
    {
        ui->label_2->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
    }
    else
    {
        ui->label_2->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
    }
}

void compresor::Comprobar5()
{
    int Borrado, x;
    Borrado = ui->tableWidget_2->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget_2->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    if (ui->checkBox_8->isChecked())
    {
        disconnect(fdlg1, SIGNAL(fileSelected(QString)), this, SLOT(Listado(QString)));
        connect(fdlg1, SIGNAL(filesSelected(QStringList)), this, SLOT(ValorRuta1(QStringList)));
        fdlg1->setLabelText(QFileDialog::Accept, tr("Seleccionar archivos"));
        ui->pushButton_8->hide();
        ui->label_4->hide();
        fdlg1->setFileMode(QFileDialog::ExistingFiles);
        ui->tableWidget_2->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Ruta origen")));
        ui->tableWidget_2->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Ruta destino")));
        ui->tableWidget_2->hideColumn(3);
        ui->pushButton_9->show();
        ui->pushButton_10->show();
        ui->pushButton_11->show();
    }
    else
    {
        connect(fdlg1, SIGNAL(fileSelected(QString)), this, SLOT(Listado(QString)));
        disconnect(fdlg1, SIGNAL(filesSelected(QStringList)), this, SLOT(ValorRuta1(QStringList)));
        fdlg1->setLabelText(QFileDialog::Accept, tr("Seleccionar"));
        ui->pushButton_8->show();
        ui->label_4->show();
        fdlg1->setFileMode(QFileDialog::ExistingFile);
        ui->tableWidget_2->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Peso")));
        ui->tableWidget_2->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Nivel compresion")));
        ui->tableWidget_2->showColumn(3);
        ui->pushButton_9->hide();
        ui->pushButton_10->hide();
        ui->pushButton_11->hide();
    }
}

void compresor::Comprobar6()
{
    if (ui->checkBox_7->isChecked())
    {
        ui->pushButton_9->hide();
        ui->pushButton_10->hide();
        ui->pushButton_11->hide();
    }
    else
    {
        ui->pushButton_9->show();
        ui->pushButton_10->show();
        ui->pushButton_11->show();
    }
}

void compresor::ValorRuta1(QStringList valor)
{
    QTableWidgetItem *item1,*item2,*item3;
    QStringList Depurado;
    QString rutaAbs;
    int iFilas, cantidad;
    ListaD.clear();
    ListaD << valor;
    cantidad=ui->tableWidget_2->rowCount();
    if (cantidad != 0)
    {
        for(int a=0;a<valor.count();a++)
        {
            QString Value = valor.value(a);
            itemsD = ui->tableWidget_2->findItems(Value, Qt::MatchExactly);
            if (itemsD.count() == 0)
                Depurado << Value;
        }
    }
    else
        Depurado << ListaD;
    if (!Depurado.isEmpty())
    {
        for (int a=0;a<Depurado.count();a++)
        {
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            rutaAbs = Depurado.value(a);
            QFile file(rutaAbs);
            item1->setText(tr(QFileInfo(file).fileName()));
            item2->setText(tr(rutaAbs));
            if (ui->checkBox_8->isChecked())
            {
                QString Nombre, Ruta;
                Nombre = item1->text();
                Ruta = rutaAbs;
                Ruta.remove(Nombre);
                item3->setText(Ruta);
            }
            else
                item3->setText("");
            iFilas=ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(iFilas);
            ui->tableWidget_2->setItem(iFilas,0,item1);
            ui->tableWidget_2->setItem(iFilas,1,item2);
            ui->tableWidget_2->setItem(iFilas,2,item3);
            ui->tableWidget_2->resizeRowsToContents();
            ui->tableWidget_2->resizeColumnsToContents();
        }
    }
}

void compresor::on_pushButton_6_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio destino?"),path,QFileDialog::ShowDirsOnly);
    if (fileNameDirectori.isEmpty())
       return;
    ui->lineEdit_2->setText(fileNameDirectori);
}

void compresor::on_pushButton_7_clicked()
{
    //falta esta parte.
}

// http://www.qt-coding.com/2013/11/28/tip-of-the-day-select-multiple-rows-in-qtableview-programatically/
