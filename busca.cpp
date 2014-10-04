#include "busca.h"
#include "ui_busca.h"
#include <QFileDialog>
#include "drakesistema.h"
#include <QProcess>
#include <QMessageBox>
#include <QDebug>
#include <QProgressDialog>
#include <QTest>
#include <drakeprocesos.h>
#include <QTimer>
#include <QSqlQuery>
#include <QKeyEvent>
#include <QtConcurrentRun>
#include <QFuture>
#include <QDesktopServices>
#include <QDirIterator>

Busca::Busca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Busca)
{
    ui->setupUi(this);
    drakeSistema drake;
    db=QSqlDatabase::database("PRINCIPAL");
    user = drake.getUser();
    Control=0;
    mib = 0;
    ui->lineEdit_2->setText("/");
    ui->radioButton_2->setChecked(true);
    ui->radioButton_6->setChecked(true);
    ui->checkBox_4->setChecked(false);
    ui->groupBox_4->setEnabled(false);
    ui->groupBox_5->setEnabled(false);
    connect(ui->checkBox_4,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_6,SIGNAL(clicked()),this,SLOT(Verificar()));
    connect(ui->radioButton_7,SIGNAL(clicked()),this,SLOT(Verificar()));
    connect(ui->radioButton_8,SIGNAL(clicked()),this,SLOT(Verificar()));
    Contador = new QTimer(this);
    connect(Contador, SIGNAL(timeout()), this, SLOT(Contar()));
    Contador->stop();
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
    connect(ui->radioButton_9,SIGNAL(clicked()),this,SLOT(Menu()));
    connect(ui->radioButton_10,SIGNAL(clicked()),this,SLOT(Menu()));
    ui->radioButton_9->setChecked(true);
    ui->pushButton_7->setVisible(false);
    this->installEventFilter(this);
    CierreTotal = 0;
    Opcion = 0;
    ui->pushButton_5->hide();
    ui->pushButton_2->hide();
    ui->pushButton_6->hide();
    connect(ui->radioButton_13,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_14,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    ui->radioButton_13->setChecked(true);
    connect(ui->tableWidget_2, SIGNAL(cellActivated(int,int)),this, SLOT(openFileOfItem(int,int)));
    ui->comboBox_3->addItem(QDir::currentPath());
}

Busca::~Busca()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void Busca::changeEvent(QEvent *e)
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

void Busca::Value(int value)
{
    if (value == 1)
        CierreTotal = 1;
}

void Busca::on_pushButton_3_clicked()
{    
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void Busca::closeEvent ( QCloseEvent * event )
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

void Busca::Comprobar1()
{
    if (ui->radioButton_13->isChecked())
        ui->stackedWidget->setCurrentIndex(1);
    else if (ui->radioButton_14->isChecked())
        ui->stackedWidget->setCurrentIndex(0);
}

void Busca::on_pushButton_clicked()
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
    QString fileNameDirectori = QFileDialog::getExistingDirectory(this,QString::fromUtf8(tr("Directorio desde donde buscar...")),path,QFileDialog::ShowDirsOnly);
    if (fileNameDirectori.isEmpty())
    {
        Opcion = 0;
        return;
    }
    ui->lineEdit_2->setText(fileNameDirectori);
    Opcion=0;
}

void Busca::on_pushButton_4_clicked()
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
    QString Name, Signo;
    int Borrado, x;
    Borrado = ui->tableWidget->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    if (ui->lineEdit->text() == "" && ui->checkBox_4->isChecked() == false)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has ingresado ningun dato para buscar. Es necesario este dato ya que intentas buscar algo."));
        m.exec();
        Contador->stop();
        ui->label_4->setText("");
        Opcion = 0;
        return;
    }
    if (ui->lineEdit_2->text() == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has ingresado ningun ruta de busqueda. Es necesario saber donde buscar."));
        m.exec();
        Contador->stop();
        ui->label_4->setText("");
        Opcion = 0;
        return;
    }
    Contador->start(200);
    ui->label_4->setText(tr("Espera por favor. Buscando"));
    ui->pushButton_5->show();
    ui->pushButton_4->hide();
    ui->pushButton_2->hide();
    ui->pushButton_6->hide();
    QString cm1;
    if (ui->checkBox_4->isChecked() == false)
    {
        if (ui->radioButton->isChecked() == true)
            Name="-iname";
        else if (ui->radioButton_2->isChecked() == true)
            Name="-name";
        cm1="find \"%1\" -type f %3 \"%2\"";
        cm1=cm1.arg(ui->lineEdit_2->text()).arg(ui->lineEdit->text()).arg(Name);
    }
    else if (ui->checkBox_4->isChecked() == true)
    {
        if (ui->radioButton_3->isChecked() == true)
            Signo="+";
        else if (ui->radioButton_4->isChecked() == true)
            Signo="-";
        else if (ui->radioButton_5->isChecked() == true)
            Signo="";
        if (ui->radioButton_6->isChecked() == true)
            Tipo="k";
        else if (ui->radioButton_7->isChecked() == true)
            Tipo="M";
        else if (ui->radioButton_8->isChecked() == true)
            Tipo="G";
        cm1="find \"%2\" -size %3\"%4\"%5";
        cm1=cm1.arg(ui->lineEdit_2->text()).arg(Signo).arg(ui->lineEdit_3->text()).arg(Tipo);
    }
    QStringList comandos;
    comandos << cm1;
    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count();
    mib->Valor(valor,3);
    mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
    mib->iniciarProceso();
}

void Busca::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    if (Control == 0)
   {
        float f;
        qint64 size;
        int iFilas;
        lista = valor.split("\n");
        for(int i=0;i<lista.count();i++)
        {
            QString Value0 = lista.value(i);
            QString Valor1 = Value0.left(4);
            QString Valor2 = Value0.left(1);
            if (Value0 != "")
            {
                if (Valor1 != "find")
                {
                    if (Valor2 != ":")
                    {
                        QFile file(Value0);
                        size = QFileInfo(file).size();
                        f=(size + 1023) / 1024;
                        if (Tipo == "M")
                            f=f/1024;
                        else if (Tipo == "G")
                        {
                            f=f/1024;
                            f=f/1024;
                        }
                        else
                        {
                            if (f < 1024)
                                Tipo="k";
                            else if (f >= 1024 || f < 1048576)
                            {
                                f=f/1024;
                                Tipo="M";
                            }
                            else if (f >= 1048576)
                            {
                                f=f/1024;
                                f=f/1024;
                                Tipo="G";
                            }
                        }
                        QTableWidgetItem *item1, *item2;
                        item1=new QTableWidgetItem;
                        item2=new QTableWidgetItem;
                        item1->setText(""+Value0+"");
                        item2->setText(""+QString::number(f,'f',2)+""+Tipo+"");
                        iFilas=ui->tableWidget->rowCount();
                        ui->tableWidget->insertRow(iFilas);
                        ui->tableWidget->setItem(iFilas,0,item1);
                        ui->tableWidget->setItem(iFilas,1,item2);
                    }
                }
            }
            Tipo.clear();
        }
        ui->tableWidget->resizeColumnsToContents();
    }
}

void Busca::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int cantidad = ui->tableWidget->rowCount();
    ui->label_4->setText(tr("Encontradas ")+QString::number(cantidad)+tr(" coincidencias."));
    Control=0;
    Opcion = 0;
    ui->pushButton_5->hide();
    ui->pushButton_4->show();
    ui->pushButton_2->show();
    ui->pushButton_6->show();
}

void Busca::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    Q_UNUSED(index);
    Control=1;
    ui->label_4->setText(tr("Ejecutando enlace..."));
    int acceso = ui->tableWidget->currentRow();
    QTableWidgetItem *item1;
    item1=new QTableWidgetItem;
    item1=ui->tableWidget->item(acceso,0);
    QString valorItem=item1->text();
    QString QvalorItem = valorItem.replace(" ","\\ ").replace("(","\\(").replace(")","\\)").replace("[","\\[").replace("]","\\]");
    QString cm1="su - %1 -c \"xdg-open %2\"";
    cm1=cm1.arg(user).arg(QvalorItem);
    QStringList comandos;
    comandos << cm1;
    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count();
    mib->Valor(valor,3);
    mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
    mib->iniciarProceso();
}

void Busca::Comprobar()
{
    if (ui->checkBox_4->isChecked() == true)
    {
       ui->groupBox_4->setEnabled(true);
       ui->radioButton_5->setChecked(true);
       ui->radioButton_6->setChecked(true);
       ui->radioButton_7->setChecked(false);
       ui->radioButton_8->setChecked(false);
       ui->lineEdit->setEnabled(false);
       ui->radioButton->setEnabled(false);
       ui->radioButton_2->setEnabled(false);
       ui->groupBox_5->setEnabled(true);
    }
    else if (ui->checkBox_4->isChecked() == false)
    {
        ui->groupBox_4->setEnabled(false);
        ui->lineEdit->setEnabled(true);
        ui->radioButton->setEnabled(true);
        ui->radioButton_2->setEnabled(true);
        ui->groupBox_5->setEnabled(false);
    }
}

void Busca::Verificar()
{
    if (ui->radioButton_6->isChecked() == true)
    {
        ui->radioButton_7->setChecked(false);
        ui->radioButton_8->setChecked(false);
    }
    if (ui->radioButton_7->isChecked() == true)
    {
        ui->radioButton_6->setChecked(false);
        ui->radioButton_8->setChecked(false);
    }
    if (ui->radioButton_8->isChecked() == true)
    {
        ui->radioButton_6->setChecked(false);
        ui->radioButton_7->setChecked(false);
    }
}

void Busca::Menu()
{
    if (ui->radioButton_9->isChecked())
    {
       ui->groupBox->setEnabled(true);
       ui->groupBox_6->setEnabled(true);
       ui->groupBox_7->setEnabled(true);
       ui->pushButton_6->setVisible(true);
       ui->pushButton_7->setVisible(false);
    }
    else if (ui->radioButton_10->isChecked())
    {
        ui->groupBox->setEnabled(false);
        ui->groupBox_6->setEnabled(false);
        ui->groupBox_7->setEnabled(false);
        ui->pushButton_6->setVisible(false);
        ui->pushButton_7->setVisible(true);
    }
}

void Busca::on_pushButton_2_clicked()
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
    Control=1;
    ui->label_4->setText(tr("Ejecutando enlace..."));
    int acceso = ui->tableWidget->currentRow();
    if (acceso == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        Opcion = 0;
        return;
    }
    QTableWidgetItem *item1;
    item1=new QTableWidgetItem;
    item1=ui->tableWidget->item(acceso,0);
    QString valorItem=item1->text();
    QString QvalorItem = valorItem.replace(" ","\\ ").replace("(","\\(").replace(")","\\)").replace("[","\\[").replace("]","\\]");
    QString cm1="su - %1 -c \"xdg-open %2\"";
    cm1=cm1.arg(user).arg(QvalorItem);
    QStringList comandos;
    comandos << cm1;
    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count();
    mib->Valor(valor,3);
    mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
    mib->iniciarProceso();
}

void Busca::Contar()
{
    if (ui->label_4->text() == tr("Espera por favor. Buscando"))
         ui->label_4->setText(tr("Espera por favor. Buscando."));
    else if (ui->label_4->text() == tr("Espera por favor. Buscando."))
         ui->label_4->setText(tr("Espera por favor. Buscando.."));
    else if (ui->label_4->text() == tr("Espera por favor. Buscando.."))
         ui->label_4->setText(tr("Espera por favor. Buscando..."));
    else if (ui->label_4->text() == tr("Espera por favor. Buscando..."))
         ui->label_4->setText(tr("Espera por favor. Buscando...."));
    else if (ui->label_4->text() == tr("Espera por favor. Buscando...."))
         ui->label_4->setText(tr("Espera por favor. Buscando....."));
    else if (ui->label_4->text() == tr("Espera por favor. Buscando....."))
         ui->label_4->setText(tr("Espera por favor. Buscando......"));
    else if (ui->label_4->text() == tr("Espera por favor. Buscando......"))
         ui->label_4->setText(tr("Espera por favor. Buscando......."));
    else if (ui->label_4->text() == tr("Espera por favor. Buscando......."))
         ui->label_4->setText(tr("Espera por favor. Buscando........"));
    else if (ui->label_4->text() == tr("Espera por favor. Buscando........"))
         ui->label_4->setText(tr("Espera por favor. Buscando........."));
    else if (ui->label_4->text() == tr("Espera por favor. Buscando........."))
         ui->label_4->setText(tr("Espera por favor. Buscando.........."));
    else if (ui->label_4->text() == tr("Espera por favor. Buscando.........."))
         ui->label_4->setText(tr("Espera por favor. Buscando"));
}

void Busca::on_pushButton_5_clicked()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    ui->label_4->setText(tr("Busqueda cancelada por el usuario."));
    Control=0;
    Opcion = 0;
    ui->pushButton_4->show();
    ui->pushButton_5->hide();
    ui->pushButton_2->hide();
    ui->pushButton_6->hide();
}

bool Busca::eventFilter(QObject* obj, QEvent *event)
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
        if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("Buscador"));
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void Busca::on_pushButton_7_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    if (ui->lineEdit_2->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has ingresado ningun ruta de busqueda. Es necesario saber donde buscar."));
        m.exec();
        Contador->stop();
        ui->label_4->setText("");
        Opcion = 0;
        return;
    }
    int Borrado, x;
    Borrado = ui->tableWidget->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    Contador->start(200);
    ui->label_4->setText(tr("Espera por favor. Buscando"));    
    dato = ui->lineEdit_2->text();
    QFuture<void> valor = QtConcurrent::run(this,&Busca::Peso,dato);
    Q_UNUSED(valor);
}

void Busca::Peso(QString dat)
{
    QString Valor;
    QProcess *procesoCut, *procesoCut2, *procesoCut3;
    QStringList argumentosCut, argumentosCut2;
    QByteArray release;
    procesoCut=new QProcess(this);
    procesoCut2=new QProcess(this);
    procesoCut3=new QProcess(this);
    procesoCut->setStandardOutputProcess(procesoCut2);
    procesoCut2->setStandardOutputProcess(procesoCut3);
    argumentosCut << "-Sm" << ""+dat+"";
    argumentosCut2 << "-n";
    procesoCut->start("du", argumentosCut);
    procesoCut2->start("sort", argumentosCut2);
    procesoCut3->start("tail");
    if (! procesoCut3->waitForStarted())
        return;
    procesoCut->waitForFinished();
    procesoCut2->waitForFinished();
    procesoCut3->waitForFinished();
    release = procesoCut3->readAllStandardOutput();
    delete procesoCut;
    delete procesoCut2;
    delete procesoCut3;
    QString res = QString(release);
    res.chop(1);
    Valor = res;
    int iFilas;
    Contador->stop();
    QStringList list = Valor.split("\n");
    for(int i=0;i<list.count();i++)
    {
        QString Value0 = list.value(i);
        QTableWidgetItem *item1, *item2;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item1->setText(""+Value0+"");
        item2->setText("");
        iFilas=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(iFilas);
        ui->tableWidget->setItem(iFilas,0,item1);
        ui->tableWidget->setItem(iFilas,1,item2);
    }
    int cantidad = ui->tableWidget->rowCount();
    ui->label_4->setText(tr("Encontradas ")+QString::number(cantidad)+tr(" coincidencias."));
    Opcion = 0;
}

void Busca::on_pushButton_8_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    QString directory = QFileDialog::getExistingDirectory(this,
                               tr("Encontrar archivos"), QDir::currentPath());
    if (!directory.isEmpty())
    {
        if (ui->comboBox_3->findText(directory) == -1)
            ui->comboBox_3->addItem(directory);
        ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(directory));
    }
    Opcion=0;
}

void Busca::on_pushButton_9_clicked()
{
    if (Opcion == 0)
        Opcion = 1;
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes esperar a que termine el proceso que se esta realizando."));
        m.exec();
        return;
    }
    int Borrado, x;
    Borrado = ui->tableWidget->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    Contador->start(200);
    ui->label_4->setText(tr("Espera por favor. Buscando"));
    QString path = ui->comboBox_3->currentText();
    QFuture<void> valor = QtConcurrent::run(this,&Busca::Exaustivo,path);
    Q_UNUSED(valor);
}

void Busca::Exaustivo(QString valor)
{
    currentDir = QDir(valor);
    QStringList Directorios;
    Directorios << valor;
    if (ui->checkBox_3->isChecked())
    {
        if (ui->checkBox->isChecked())
        {
            QDirIterator iterator(currentDir.absolutePath(), QDir::Dirs|QDir::NoDotAndDotDot|QDir::Hidden, QDirIterator::Subdirectories|QDirIterator::FollowSymlinks);
            while (iterator.hasNext())
            {
                iterator.next();
                if (iterator.fileInfo().isDir())
                   Directorios << iterator.filePath();
            }
        }
        else
        {
            QDirIterator iterator(currentDir.absolutePath(), QDir::Dirs|QDir::NoDotAndDotDot, QDirIterator::Subdirectories|QDirIterator::FollowSymlinks);
            while (iterator.hasNext())
            {
                iterator.next();
                if (iterator.fileInfo().isDir())
                    Directorios << iterator.filePath();
            }
        }
        QString fileName = ui->comboBox->currentText();
        QString text = ui->comboBox_2->currentText();
        updateComboBox(ui->comboBox);
        updateComboBox(ui->comboBox_2);
        updateComboBox(ui->comboBox_3);
        ui->tableWidget_2->setRowCount(0);
        for(int a=0;a<Directorios.count();a++)
        {
            Directory = QDir(Directorios.value(a));
            QStringList files;
            if (fileName.isEmpty())
                fileName = "*";
            if (ui->checkBox->isChecked())
                files = Directory.entryList(QStringList(fileName), QDir::Files | QDir::NoSymLinks | QDir::Hidden);
            else
                files = Directory.entryList(QStringList(fileName), QDir::Files | QDir::NoSymLinks);
            if (!text.isEmpty())
                files = findFiles(files, text);
            showFiles(files);
        }
    }
    else
    {
        Directory = currentDir;
        QString fileName = ui->comboBox->currentText();
        QString text = ui->comboBox_2->currentText();
        updateComboBox(ui->comboBox);
        updateComboBox(ui->comboBox_2);
        updateComboBox(ui->comboBox_3);
        ui->tableWidget_2->setRowCount(0);
        QStringList files;
        if (fileName.isEmpty())
            fileName = "*";
        if (ui->checkBox->isChecked())
            files = currentDir.entryList(QStringList(fileName),
                               QDir::Files|QDir::NoSymLinks|QDir::NoDotAndDotDot|QDir::Hidden);
        else
            files = currentDir.entryList(QStringList(fileName),
                               QDir::Files|QDir::NoSymLinks|QDir::NoDotAndDotDot);
        if (!text.isEmpty())
            files = findFiles(files, text);
        showFiles(files);
    }
    ui->tableWidget_2->resizeRowsToContents();
    ui->tableWidget_2->resizeColumnsToContents();
    Opcion = 0;
}

QStringList Busca::findFiles(const QStringList &files, const QString &text)
{
    QProgressDialog progressDialog(this);
    progressDialog.setCancelButtonText(tr("&Cancelar"));
    progressDialog.setRange(0, files.size());
    progressDialog.setWindowTitle(tr("Encontrar archivos"));
    progressDialog.show();
    QStringList foundFiles;
    for (int i = 0; i < files.size(); ++i)
    {
        progressDialog.setValue(i);
        progressDialog.setLabelText(tr("Buscando archivos %1 de %2...").arg(i).arg(files.size()));
        qApp->processEvents();
        if (progressDialog.wasCanceled())
            break;
        QFile file(Directory.absoluteFilePath(files[i]));
        if (file.open(QIODevice::ReadOnly))
        {
            QString line;
            QTextStream in(&file);
            while (!in.atEnd())
            {
                if (progressDialog.wasCanceled())
                    break;
                line = in.readLine();
                if (ui->checkBox_2->isChecked())
                {
                    if (line.contains(text, Qt::CaseInsensitive))
                    {
                        foundFiles << files[i];
                        break;
                    }
                }
                else
                {
                    if (line.contains(text))
                    {
                        foundFiles << files[i];
                        break;
                    }
                }
            }
        }
    }
    return foundFiles;
}

void Busca::showFiles(const QStringList &files)
{
    int row;
    for (int i = 0; i < files.size(); ++i)
    {
        QFile file(Directory.absoluteFilePath(files[i]));
        qint64 size = QFileInfo(file).size();
        QString Path = QFileInfo(file).absoluteFilePath();
        QTableWidgetItem *fileNameItem = new QTableWidgetItem(files[i]);
        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *sizeItem = new QTableWidgetItem(tr("%1 KB").arg(int((size + 1023) / 1024)));
        sizeItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        sizeItem->setFlags(sizeItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *fileNamePath = new QTableWidgetItem(Path);
        fileNamePath->setFlags(fileNamePath->flags() ^ Qt::ItemIsEditable);
        row = ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(row);
        ui->tableWidget_2->setItem(row, 0, fileNameItem);
        ui->tableWidget_2->setItem(row, 1, sizeItem);
        ui->tableWidget_2->setItem(row, 2, fileNamePath);
    }    
    row = ui->tableWidget_2->rowCount();
    ui->label_4->setText(tr("%1 archivo(s) encontrado(s)").arg(row) + tr(" (Doble click para abrir un archivo)"));
}

void Busca::updateComboBox(QComboBox *comboBox)
{
    if (comboBox->findText(comboBox->currentText()) == -1)
        comboBox->addItem(comboBox->currentText());
}

void Busca::openFileOfItem(int row, int /* column */)
{
    QTableWidgetItem *item = ui->tableWidget_2->item(row, 2);
    QDesktopServices::openUrl(QUrl::fromLocalFile(item->text()));
}

void Busca::on_pushButton_6_clicked()
{
    //falta esta parte para abrir la ruta de los programas
}
