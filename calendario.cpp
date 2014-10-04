#include "calendario.h"
#include "ui_calendario.h"
#include "drakesistema.h"
#include <QSqlQuery>
#include <QFileInfo>
#include <QDebug>
#include <QStyleFactory>
#include <QMessageBox>

Calendario::Calendario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calendario)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Stilo = "B";
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
    QString Estilo;
    QSqlQuery queryEstilo(db);
    queryEstilo.exec("SELECT Style FROM Estilo WHERE id=2");
    queryEstilo.first();
    Estilo=queryEstilo.value(0).toString();
    QApplication::setStyle(QStyleFactory::create(Estilo));
    ui->progressBar->setVisible(false);
    ui->textEdit->setVisible(false);
    data = QDate::currentDate();
    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),this, SLOT(Calendar(QDate)));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(Consola()));
    Posicion = 0;
    mib=0;
    Segmento = 0;
    drakeSistema drake;
    user = drake.getUser();
    ui->pushButton_9->setEnabled(false);
    this->installEventFilter(this);
}

Calendario::~Calendario()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void Calendario::Valor(QString valor, QString Log)
{
    if (Log == "S")
        log = "S";
    else
        log = "N";
    QBrush brush;
    QFont font("SansSerif", 15, QFont::Bold);
    brush.setColor(Qt::blue);
    ui->label_2->setText(valor);
    drakeSistema drake;
    QString Explora;
    Explora = "find \"%1/.Sincrono\" -type f";
    Explora = Explora.arg(ui->label_2->text());
    valor = drake.getStart(Explora);
    Value = valor.split("\n");
    for(int i=1;i<Value.count();i++)
    {
        qApp->processEvents();
        int iFilas;
        QString ruta;
        QTableWidgetItem *item1,*item2,*item3,*item4;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        item4=new QTableWidgetItem;
        ruta=Value.value(i);
        QFile file(ruta);
        QDateTime Fecha = QFileInfo(file).lastModified();
        QDate Resto = Fecha.date();
        QTextCharFormat cf = ui->calendarWidget->dateTextFormat(Resto);
        cf.setBackground(brush);
        cf.setFont(font);
        ui->calendarWidget->setDateTextFormat(Resto,cf);
        if (Resto >= data)
        {
            item1->setText(QFileInfo(file).fileName());
            item2->setText(Resto.toString());
            item3->setText(QFileInfo(file).filePath());
            item4->setText(tr("No"));
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->setItem(iFilas,2,item3);
            ui->tableWidget->setItem(iFilas,3,item4);
            ui->tableWidget->item(iFilas,3)->setIcon(QIcon(":/Imagenes/bad.png"));
        }
    }
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    this->on_pushButton_5_clicked();
}

void Calendario::Calendar(QDate date)
{
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    int Borrado, x;
    Borrado = ui->tableWidget->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    for(int i=1;i<Value.count();i++)
    {
        qApp->processEvents();
        int iFilas;
        QString ruta;
        QTableWidgetItem *item1,*item2, *item3, *item4;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        item4=new QTableWidgetItem;
        ruta=Value.value(i);
        QFile file(ruta);
        QDateTime Fecha = QFileInfo(file).lastModified();
        QDate Resto = Fecha.date();
        if (Resto >= date)
        {
            item1->setText(QFileInfo(file).fileName());
            item2->setText(Resto.toString());
            item3->setText(QFileInfo(file).filePath());
            item4->setText(tr("No"));
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->setItem(iFilas,2,item3);
            ui->tableWidget->setItem(iFilas,3,item4);
        }
    }
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    this->on_pushButton_5_clicked();
    Posicion = 0;
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    ui->pushButton_11->setEnabled(true);
    ui->pushButton_12->setEnabled(true);
}

void Calendario::on_pushButton_clicked()
{
    if (log == "S")
    {
        system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
    }
    close();
}

void Calendario::on_pushButton_2_clicked()
{
    int Contador = ui->tableWidget->rowCount();
    if (Contador == 0)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay nada seleccionado para recuperar."));
        m.exec();
        return;
    }
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Recuperar copias de sincronizacion")),
                           QString::fromUtf8(tr("<center><b>Recuperar copias de sincronizacion guardadas<b></center><p>"
                           "Si recuperas las copias seleccionadas sobreescribiran las originales que tengas "
                           "desaciendo los ultimos cambios realizados en ellas.<p>"
                           "&iquest;Estas seguro de que quieres recuperar las copias sincronizadas?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        ui->progressBar->setVisible(true);
        ui->textEdit->setVisible(true);
        QString Root = ui->label_2->text();       
        ui->textEdit->append("");
        ui->textEdit->append(tr("Iniciando recuperacion de copia seleccionada"));
        QStringList comandos;
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_10->setEnabled(false);
        ui->pushButton_11->setEnabled(false);
        ui->pushButton_12->setEnabled(false);
        Evento=0;
        ui->pushButton_9->setEnabled(true);
        QString Valor1 = "ls -l -d \"%1\"";
        Valor1 = Valor1.arg(ui->label_2->text());
        QString PermisosO = getPropietario(Valor1);
        QStringList RestoO = PermisosO.split(" ");
        QString PermiO = RestoO.value(2);
        QTableWidgetItem *item1,*item2;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        QString RutaObj, RutaDest, Marca;
        int Update = ui->tableWidget->rowCount();
        for(int x=0;x<Update;x++)
        {
            qApp->processEvents();
            if (Evento == 1)
            {
                ui->textEdit->append(tr("Trabajo cancelado"));
                ui->pushButton_9->setEnabled(false);
                ui->progressBar->setVisible(false);
                ui->textEdit->setVisible(false);
                return;
            }
            item1 = ui->tableWidget->item(x,2);
            item2 = ui->tableWidget->item(x,3);
            RutaObj=item1->text();
            Marca = item2->text();
            RutaDest =item1->text();
            RutaObj = RutaObj.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
            RutaDest = RutaDest.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)").remove("/.Sincrono");
            QString cm;
            if (Marca == tr("Si"))
            {
                if (Root.contains("root") || PermiO.contains("root"))
                {
                    cm = "su -c \"cp -p -v %1 %2\"";
                    cm = cm.arg(RutaObj).arg(RutaDest);
                }
                else
                {
                    cm = "su - "+user+" -c \"cp -p -v %1 %2\"";
                    cm = cm.arg(RutaObj).arg(RutaDest);
                }
                comandos << cm;
            }
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

void Calendario::on_pushButton_3_clicked()
{
    int iFilas;
    QString activo;
    iFilas=ui->tableWidget->currentRow();
    if (iFilas == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QTableWidgetItem *item;
        item=new QTableWidgetItem;
        item=ui->tableWidget->item(iFilas,3);
        activo = item->text();
        if (activo == tr("Si"))
        {            
            item->setText(tr("No"));
            ui->tableWidget->setItem(iFilas,3,item);
            ui->tableWidget->item(iFilas,3)->setIcon(QIcon(":/Imagenes/bad.png"));
        }
        else if (activo == tr("No"))
        {            
            item->setText(tr("Si"));
            ui->tableWidget->setItem(iFilas,3,item);
            ui->tableWidget->item(iFilas,3)->setIcon(QIcon(":/Imagenes/good.png"));
        }
    }
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void Calendario::on_pushButton_4_clicked()
{
    int iFilas, a;
    iFilas=ui->tableWidget->rowCount();    
    for(a=0;a<iFilas;a++)
    {
        QTableWidgetItem *item;
        item=new QTableWidgetItem;
        qApp->processEvents();        
        item->setText(tr("Si"));
        ui->tableWidget->setItem(a,3,item);
        ui->tableWidget->item(a,3)->setIcon(QIcon(":/Imagenes/good.png"));
    }
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void Calendario::on_pushButton_5_clicked()
{
    int iFilas, a;
    iFilas=ui->tableWidget->rowCount();
    for(a=0;a<iFilas;a++)
    {
        QTableWidgetItem *item;
        item=new QTableWidgetItem;
        qApp->processEvents();        
        item->setText(tr("No"));
        ui->tableWidget->setItem(a,3,item);
        ui->tableWidget->item(a,3)->setIcon(QIcon(":/Imagenes/bad.png"));
    }
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
}

void Calendario::Comprobar()
{
    if (Posicion == 0)
    {
        int Borrado, x;
        Borrado = ui->tableWidget->rowCount();
        for(x=0;x<Borrado;x++)
        {
             ui->tableWidget->removeRow(x);
             x=x-1;
             Borrado=Borrado-1;
        }
        for(int i=1;i<Value.count();i++)
        {
            qApp->processEvents();
            int iFilas;
            QString ruta;
            QTableWidgetItem *item1,*item2, *item3, *item4;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            ruta=Value.value(i);
            QFile file(ruta);
            QDateTime Fecha = QFileInfo(file).lastModified();
            QDate Resto = Fecha.date();
            if (Resto == ui->calendarWidget->selectedDate())
            {
                item1->setText(QFileInfo(file).fileName());
                item2->setText(Resto.toString());
                item3->setText(QFileInfo(file).filePath());
                item4->setText(tr("No"));
                iFilas=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(iFilas);
                ui->tableWidget->setItem(iFilas,0,item1);
                ui->tableWidget->setItem(iFilas,1,item2);
                ui->tableWidget->setItem(iFilas,2,item3);
                ui->tableWidget->setItem(iFilas,3,item4);
            }
        }
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
        this->on_pushButton_5_clicked();
        Posicion = 1;
        ui->pushButton_6->setText(tr("Filtrar desde fecha"));
    }
    else if (Posicion == 1)
    {
        int Borrado, x;
        Borrado = ui->tableWidget->rowCount();
        for(x=0;x<Borrado;x++)
        {
             ui->tableWidget->removeRow(x);
             x=x-1;
             Borrado=Borrado-1;
        }
        for(int i=1;i<Value.count();i++)
        {
            int iFilas;
            QString ruta;
            QTableWidgetItem *item1,*item2, *item3, *item4;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            ruta=Value.value(i);
            QFile file(ruta);
            QDateTime Fecha = QFileInfo(file).lastModified();
            QDate Resto = Fecha.date();
            if (Resto >= ui->calendarWidget->selectedDate())
            {
                item1->setText(QFileInfo(file).fileName());
                item2->setText(Resto.toString());
                item3->setText(QFileInfo(file).filePath());
                item4->setText("No");
                iFilas=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(iFilas);
                ui->tableWidget->setItem(iFilas,0,item1);
                ui->tableWidget->setItem(iFilas,1,item2);
                ui->tableWidget->setItem(iFilas,2,item3);
                ui->tableWidget->setItem(iFilas,3,item4);
            }
        }
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
        this->on_pushButton_5_clicked();
        Posicion = 0;
        ui->pushButton_6->setText(tr("Filtrar por fecha"));
    }
}

void Calendario::Comprobar1()
{
    int Borrado, x;
    QDate Valor;
    QString Resto;
    Borrado = ui->tableWidget->rowCount();
    for(x=0;x<Borrado;x++)
    {
        ui->tableWidget->removeRow(x);
        x=x-1;
        Borrado=Borrado-1;
    }
    for(int i=1;i<Value.count();i++)
    {
        int iFilas;
        QString ruta;
        QTableWidgetItem *item1,*item2, *item3, *item4;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        item4=new QTableWidgetItem;
        ruta=Value.value(i);
        QFile file(ruta);
        QDateTime Fecha = QFileInfo(file).lastModified();
        QDate Resto = Fecha.date();
        if (ruta.contains(".bak"))
        {
            item1->setText(QFileInfo(file).fileName());
            item2->setText(Resto.toString());
            item3->setText(QFileInfo(file).filePath());
            item4->setText(tr("Si"));
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->setItem(iFilas,2,item3);
            ui->tableWidget->setItem(iFilas,3,item4);
        }
    }
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->resizeColumnsToContents();
    this->on_pushButton_5_clicked();
}

void Calendario::on_pushButton_7_clicked()
{
    QStringList comandos;
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Borrar copias de sincronizacion")),
                           QString::fromUtf8(tr("<center><b>Borrado de copias de sincronizacion guardadas<b></center><p>"
                           "Si borras las copias, en el caso de sincronizar y haber cometido algun error "
                           "ya no podras recuperar la copia anterior perdiendo definitivamente los datos "
                           "guardados con el consiguiente problema.<p>"
                           "Si has realizado backups tambien se borraran.<p>"
                           "NO RECOMIENDO REALIZAR ESTE PROCESO.<p>"
                           "&iquest;Estas completamente seguro de que quieres borrar las copias sincronizadas?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        ui->progressBar->setVisible(true);
        ui->textEdit->setVisible(true);
        QString cm1, Value;
        Value = ""+ui->label_2->text()+"/.Sincrono";
        Value = Value.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
        cm1 = "su -c \"rm -vrf %1\"";
        cm1 = cm1.arg(Value);
        comandos << cm1;
        if (mib != 0)
            delete mib;
        mib = new DrakeProcesos1(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count();
        mib->Valor(valor,0);
        mib->iniciarProceso();
    }
}

void Calendario::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
}

void Calendario::mibprogreso(QString Dat)
{
    ui->progressBar->setValue(Dat.toInt());
}

void Calendario::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    ui->pushButton_11->setEnabled(true);
    ui->pushButton_12->setEnabled(true);
    if (Segmento == 1)
    {
        drakeSistema drake;
        QString Explora;
        Explora = "find \"%1/.Sincrono\" -type f";
        Explora = Explora.arg(ui->label_2->text());
        valor = drake.getStart(Explora);
        Value = valor.split("\n");
        Segmento = 0;
    }
}

void Calendario::Consola()
{
    if (ui->textEdit->isVisible())
    {
        ui->textEdit->setVisible(false);
        ui->pushButton_8->setText(tr("Mostrar consola"));
    }
    else
    {
        ui->textEdit->setVisible(true);
        ui->pushButton_8->setText(tr("Ocultar consola"));
    }
}

QString Calendario::getPropietario(QString Valor)
{
    QProcess *procesoCut;
    QByteArray du;
    procesoCut=new QProcess(this);
    procesoCut->start(Valor);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    du = procesoCut->readAllStandardOutput();
    delete procesoCut;
    QString res = QString(du);
    res.chop(1);
    return res;
}

bool Calendario::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("Sincrono::Copias sincronizadas"));
                return true;
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Escape)
            {
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void Calendario::on_pushButton_9_clicked()
{
    Evento = 1;
    if (mib != 0)
    {
        mib->killProceso();
        disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    }
    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    ui->pushButton_11->setEnabled(true);
    ui->pushButton_12->setEnabled(true);
}

void Calendario::on_pushButton_10_clicked()
{
    int Contador = ui->tableWidget->currentRow();
    if (Contador == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay nada seleccionado para realizar backup."));
        m.exec();
        return;
    }
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Crear backup de archivo")),
                           QString::fromUtf8(tr("<center><b>Creacion de backup de archivo<b></center><p>"
                           "Si realizas este proceso, se realizara una backup exclusiva que no podra ser "
                           "sobreescrita.<p>"
                           "&iquest;Realizar backup?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        ui->progressBar->setVisible(true);
        ui->textEdit->setVisible(true);
        QString Root = ui->label_2->text();
        ui->textEdit->append("");
        ui->textEdit->append(tr("Iniciando copia de seguridad copia seleccionada"));
        QStringList comandos;
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_10->setEnabled(false);
        ui->pushButton_11->setEnabled(false);
        ui->pushButton_12->setEnabled(false);
        Evento=0;
        ui->pushButton_9->setEnabled(true);
        QString Valor1 = "ls -l -d \"%1\"";
        Valor1 = Valor1.arg(ui->label_2->text());
        QString PermisosO = getPropietario(Valor1);
        QStringList RestoO = PermisosO.split(" ");
        QString PermiO = RestoO.value(2);
        QTableWidgetItem *item1,*item2;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        QString RutaObj, RutaDest, Marca;
        int Update = ui->tableWidget->rowCount();
        int Total = 0;
        for(int x=0;x<Update;x++)
        {
            qApp->processEvents();
            if (Evento == 1)
            {
                ui->textEdit->append(tr("Trabajo cancelado"));
                ui->pushButton_9->setEnabled(false);
                ui->progressBar->setVisible(false);
                ui->textEdit->setVisible(false);
                return;
            }
            item1 = ui->tableWidget->item(x,2);
            item2 = ui->tableWidget->item(x,3);
            RutaObj=item1->text();
            Marca=item2->text();
            RutaObj = RutaObj.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
            QString cm;
            if (Marca == tr("Si"))
            {
                if (Root.contains("root") || PermiO.contains("root"))
                {
                    cm = "su -c \"cp -p -v %1 %1.bak\"";
                    cm = cm.arg(RutaObj);
                }
                else
                {
                    cm = "su - "+user+" -c \"cp -p -v %1 %1.bak\"";
                    cm = cm.arg(RutaObj);
                }
                comandos << cm;
                Total++;
            }
        }
        if (Total > 0)
        {
            if (mib != 0)
                delete mib;
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count();
            mib->Valor(valor,0);
            mib->iniciarProceso();
            Segmento = 1;
        }
        else
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No hay nada seleccionado para realizar backup."));
            m.exec();
            ui->progressBar->setValue(0);
            ui->progressBar->setVisible(false);
            ui->textEdit->setVisible(false);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            ui->pushButton_4->setEnabled(true);
            ui->pushButton_5->setEnabled(true);
            ui->pushButton_6->setEnabled(true);
            ui->pushButton_7->setEnabled(true);
            ui->pushButton_8->setEnabled(true);
            ui->pushButton_10->setEnabled(true);
            ui->pushButton_11->setEnabled(true);
            ui->pushButton_12->setEnabled(true);
            return;
        }
    }
}

void Calendario::on_pushButton_12_clicked()
{
    int Contador = ui->tableWidget->currentRow();
    if (Contador == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay nada seleccionado para borrar."));
        m.exec();
        return;
    }
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Borrar archivo seleccionado")),
                           QString::fromUtf8(tr("<center><b>Borrado del archivo seleccionado<b></center><p>"
                           "Se procede a borrar el archivo seleccionado.<p>"
                           "Si has realizado backups tambien se borraran.<p>"
                           "NO DEBERIAS BORRAR ARCHIVOS QUE PUEDES NECESITAR POSTERIORMENTE.<p>"
                           "&iquest;Estas completamente seguro de que quieres borrar el archivo seleccionado?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        QStringList comandos;
        QString valor, ruta;
        QTableWidgetItem *item, *item1;
        item=new QTableWidgetItem;
        item1=new QTableWidgetItem;
        item=ui->tableWidget->item(ui->tableWidget->currentRow(),2);
        item1=ui->tableWidget->item(ui->tableWidget->currentRow(),3);
        ruta = item->text();
        valor = item1->text();
        if (valor == tr("Si"))
        {
            ui->tableWidget->removeRow(ui->tableWidget->currentRow());
            ui->progressBar->setVisible(true);
            ui->textEdit->setVisible(true);
            QString cm1;
            ruta = ruta.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
            cm1 = "su -c \"rm -vrf %1\"";
            cm1 = cm1.arg(ruta);
            comandos << cm1;
            if (mib != 0)
                delete mib;
            mib = new DrakeProcesos1(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count();
            mib->Valor(valor,0);
            mib->iniciarProceso();
            Segmento = 1;
        }
        else
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Para poder borrar tiene que estar el archivo marcado."));
            m.exec();
            return;
        }
    }
}
