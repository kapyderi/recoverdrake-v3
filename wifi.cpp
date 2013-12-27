#include "wifi.h"
#include "ui_wifi.h"
#include "drakesistema.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>
#include "drakeprocesos1.h"
#include "recoverdrake.h"
#include "ui_recoverdrake.h"
#include <QFile>
#include <QTableWidgetItem>
#include <QDebug>

wifi::wifi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wifi)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    mib = 0;
    Model= new QSqlTableModel(0,db);
    Model->setTable("wlistablanca");
    Model->select();
    ui->tableView->setModel(Model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila(QModelIndex)));
    Model1= new QSqlTableModel(0,db);
    Model1->setTable("wlistanegra");
    Model1->select();
    ui->tableView_2->setModel(Model1);
    ui->tableView_2->setColumnHidden(0, true);
    ui->tableView_2->resizeColumnsToContents();
    ui->tableView_2->resizeRowsToContents();
    connect(ui->tableView_2->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila1(QModelIndex)));
    drakeSistema drake;
    user = drake.getUser();
    ip = drake.getIPRouter();
    ip = ip.left(27).remove(0,16).remove(" ");
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
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

wifi::~wifi()
{
    delete ui;
    delete Model;
    delete Model1;
    if (mib != 0)
        delete mib;
}

void wifi::changeEvent(QEvent *e)
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

void wifi::on_pushButton_4_clicked()
{
    close();
}

void wifi::cambiaFila(QModelIndex actual)
{
        int i;
        i=actual.row();
        QModelIndex index;
        index=ui->tableView->model()->index(i,0);
        this->id= index.data().toInt();
        ui->lineEdit_3->setText(index.data().toString());
        index=ui->tableView->model()->index(i,1);
        ui->lineEdit_5->setText(index.data().toString());
        index=ui->tableView->model()->index(i,2);
        ui->lineEdit->setText(index.data().toString());
        this->fila=i;
}

void wifi::cambiaFila1(QModelIndex actual)
{
        int i1;
        i1=actual.row();
        QModelIndex index;
        index=ui->tableView_2->model()->index(i1,0);
        this->id1= index.data().toInt();
        ui->lineEdit_4->setText(index.data().toString());
        index=ui->tableView_2->model()->index(i1,1);
        ui->lineEdit_6->setText(index.data().toString());
        index=ui->tableView_2->model()->index(i1,2);
        ui->lineEdit_2->setText(index.data().toString());
        this->fila1=i1;
}

void wifi::on_pushButton_clicked()
{
    QString mac;
    mac=ui->lineEdit->text();
    if (mac=="Es la direccion MAC de tu equipo.")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("La direccion MAC de tu equipo no puede estar en ninguna lista para evitar cualquier problema de protocolos."));
        m.exec();
        return;
    }
    else
    {
        QSqlQuery query1(db);
        query1.exec("SELECT mac FROM wlistablanca WHERE mac='"+mac+"'");
        query1.first();
        if (query1.isValid())
            Cantidad=query1.value(0).toString();
        if (mac == Cantidad)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No se pueden duplicar MAC. Cambie los datos de la MAC para poder insertarla."));
            m.exec();
            return;
        }
        else
        {
            QSqlQuery query(db);
            query.prepare("INSERT INTO wlistablanca (ip,mac)"
                          "VALUES (:ip, :mac)");
            query.bindValue(":ip", ui->lineEdit_5->text());
            query.bindValue(":mac", ui->lineEdit->text());
            query.exec();
            Model->select();
            ui->tableView->setModel(Model);
        }
    }
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

void wifi::on_pushButton_2_clicked()
{
    QString mac1;
    mac1=ui->lineEdit_2->text();
    if (mac1=="Es la direccion MAC de tu equipo.")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("La direccion MAC de tu equipo no puede estar en ninguna lista para evitar cualquier problema de protocolos."));
        m.exec();
        return;
    }
    else
    {
        QSqlQuery query1(db);
        query1.exec("SELECT mac FROM wlistanegra WHERE mac='"+mac1+"'");
        query1.first();
        if (query1.isValid())
            Cantidad1=query1.value(0).toString();
        if (mac1 == Cantidad1)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No se pueden duplicar MAC. Cambie los datos de la MAC para poder insertarla."));
            m.exec();
            return;
        }
        else
        {
            int respuesta = 0;
            respuesta = QMessageBox::question(this, tr(QString::fromUtf8("Confirmación de bloqueo de MAC")),
                                   tr(QString::fromUtf8("<center><b>CONFIRMACIÓN<b></center><p>"

                                   "Procede con cuidado, ya que dejarás desconectada esa MAC hasta que la quites de la "
                                   "lista negra.<p>"

                                   "&iquest;Está seguro de querer bloquear la MAC "+mac1+"?")), QMessageBox::Ok, QMessageBox::No);
            if (respuesta == QMessageBox::Ok)
            {
                QSqlQuery query(db);
                query.prepare("INSERT INTO wlistanegra (ip,mac)"
                              "VALUES (:ip, :mac)");
                query.bindValue(":ip", ui->lineEdit_6->text());
                query.bindValue(":mac", ui->lineEdit_2->text());
                query.exec();
                Model1->select();
                ui->tableView_2->setModel(Model1);
                QString cm =QString::fromUtf8(tr("echo Bloqueando acceso a la MAC "+mac1+"..."));
                QString cm1= "iptables -A INPUT -p all -m mac --mac-source %1 -j DROP";
                cm1 = cm1.arg(mac1);
                QStringList comandos;
                comandos<< cm << cm1;

                if (mib != 0)
                    delete mib;
                mib = new DrakeProcesos1(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
            }
            ui->tableView_2->resizeColumnsToContents();
            ui->tableView_2->resizeRowsToContents();
            return;
        }
    }
    ui->tableView_2->resizeColumnsToContents();
    ui->tableView_2->resizeRowsToContents();
}

void wifi::on_pushButton_3_clicked()
{
    ui->tableView->model()->removeRow(fila);
}

void wifi::on_pushButton_5_clicked()
{
    QString mac1 =ui->lineEdit_2->text();
    int respuesta = 0;
    respuesta = QMessageBox::question(this, tr(QString::fromUtf8("Confirmación de desbloqueo de mac")),
                           tr(QString::fromUtf8("<center><b>CONFIRMACIÓN<b></center><p>"

                           "Procede con cuidado, ya que dejarás insegura esa mac hasta que la vuelvas a poner en "
                           "lista negra.<p>"

                           "&iquest;Está seguro de querer desbloquear la mac "+mac1+"?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {        
        ui->tableView_2->model()->removeRow(fila1);
        QString cm =QString::fromUtf8(tr("echo Desbloqueando acceso a la MAC "+mac1+"..."));
        QString cm1= "iptables -D INPUT -p all -m mac --mac-source %1 -j DROP";
        cm1 = cm1.arg(mac1);
        QStringList comandos;
        comandos<< cm << cm1;

        if (mib != 0)
            delete mib;
        mib = new DrakeProcesos1(comandos, this);
        connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
    }
    return;
}

void wifi::on_pushButton_11_clicked()
{
    this->ui->lineEdit->setText("");
    this->ui->lineEdit_5->setText("");
}

void wifi::on_pushButton_12_clicked()
{
    this->ui->lineEdit_2->setText("");
    this->ui->lineEdit_6->setText("");
}

void wifi::on_pushButton_7_clicked()
{
    Model->setFilter("mac like'"+ui->lineEdit->text()+"%'");
    ui->tableView->setModel(Model);
}

void wifi::on_pushButton_9_clicked()
{
    Model1->setFilter("mac like'"+ui->lineEdit_2->text()+"%'");
    ui->tableView_2->setModel(Model1);
}

void wifi::on_pushButton_10_clicked()
{
    QSqlRecord record= Model->record(this->fila);
    record.setValue(1,ui->lineEdit_5->text());
    record.setValue(2,ui->lineEdit->text());
    Model->setRecord(this->fila,record);
    Model->submitAll();
}

void wifi::on_pushButton_8_clicked()
{
    QSqlRecord record= Model1->record(this->fila1);
    record.setValue(1,ui->lineEdit_6->text());
    record.setValue(2,ui->lineEdit_2->text());
    Model1->setRecord(this->fila1,record);
    Model1->submitAll();
}

void wifi::on_pushButton_6_clicked()
{
    QString cm =QString::fromUtf8(tr("echo Escaneando Red Wifi y Router..."));
    QString cm1= "nmap -sS -PO -O %1-254";
    cm1 = cm1.arg(ip);
    QStringList comandos;
    comandos<< cm << cm1;

    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos1(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(lanzar()));
    int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
}

void wifi::lanzar()
{
    int iFilas;
    QFile file("/home/"+user+"/TempIP.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QString datosIp = in.readAll();
    file.close();
    lista = datosIp.split("\n");
    val = "Nmap scan report for ";
    for(int i=0;i<lista.count();i++)
    {
        QString verlo=QString::fromUtf8(lista.value(i));
        pos = verlo.indexOf(val, 0);
        if (pos != -1)
        {
            Value0 = lista.at(i);
            QString Valor = QString::fromUtf8(Value0.remove(val));
            QTableWidgetItem *item1, *item2;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item1->setText(""+Valor+"");
            drakeSistema drake;
            MacDic = drake.getMac(Valor);
            MacDic = MacDic.left(50).remove(0,33);
            if (MacDic == " entry")
            {
                MacDic = "Es la direccion MAC de tu equipo.";
            }
            item2->setText(""+MacDic+"");
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
        }
    }
    system("rm -vf /home/"+user+"/TempIP.txt");
    ui->progressBar->setValue(0);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
}

void wifi::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
    system(QString::fromUtf8("echo '"+valor+"' >> /home/'"+user+"'/TempIP.txt"));
}

void wifi::mibprogreso(QString Dat)
{
    ui->progressBar->setValue(Dat.toInt());
}

void wifi::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    ui->progressBar->setValue(0);
}

void wifi::on_pushButton_13_clicked()
{
    QString mac;
    QTableWidgetItem *item, *item1;
    item = ui->tableWidget->item(ui->tableWidget->currentRow(),0);
    item1 = ui->tableWidget->item(ui->tableWidget->currentRow(),1);
    mac = item1->text();
    if (mac=="Es la direccion MAC de tu equipo.")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("La direccion MAC de tu equipo no puede estar en ninguna lista para evitar cualquier problema de protocolos."));
        m.exec();
        return;
    }
    else
    {
        QSqlQuery query(db);
        query.exec("SELECT mac FROM wlistanegra WHERE mac='"+mac+"'");
        query.first();
        if (query.isValid())
            Cantidad=query.value(0).toString();
        if (mac == Cantidad)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No se puede ingresar en la lista blanca ya que esta incluida en la lista negra.<p>Por logica no puede estar en las dos listas."));
            m.exec();
            return;
        }
        else
        {
            QSqlQuery query1(db);
            query1.exec("SELECT mac FROM wlistablanca WHERE mac='"+mac+"'");
            query1.first();
            if (query1.isValid())
                Cantidad1=query1.value(0).toString();
            if (mac == Cantidad1)
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("No se pueden duplicar MAC. Cambie los datos de la MAC para poder insertarla."));
                m.exec();
                return;
            }
            else
            {
                QSqlQuery query(db);
                query.prepare("INSERT INTO wlistablanca (ip,mac)"
                              "VALUES (:ip, :mac)");
                query.bindValue(":ip", item->text());
                query.bindValue(":mac", item1->text());
                query.exec();
                Model->select();
                ui->tableView->setModel(Model);
            }
        }
    }
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

void wifi::on_pushButton_14_clicked()
{
    QString mac1;
    QTableWidgetItem *item, *item1;
    item = ui->tableWidget->item(ui->tableWidget->currentRow(),0);
    item1 = ui->tableWidget->item(ui->tableWidget->currentRow(),1);
    mac1 = item1->text();
    if (mac1=="Es la direccion MAC de tu equipo.")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("La direccion MAC de tu equipo no puede estar en ninguna lista para evitar cualquier problema de protocolos."));
        m.exec();
        return;
    }
    else
    {
        QSqlQuery query(db);
        query.exec("SELECT mac FROM wlistablanca WHERE mac='"+mac1+"'");
        query.first();
        if (query.isValid())
            Cantidad=query.value(0).toString();
        if (mac1 == Cantidad)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No se puede ingresar en la lista negra ya que esta incluida en la lista blanca.<p> Por logica no puede estar en las dos listas."));
            m.exec();
            return;
        }
        else
        {
            QSqlQuery query1(db);
            query1.exec("SELECT mac FROM wlistanegra WHERE mac='"+mac1+"'");
            query1.first();
            if (query1.isValid())
                Cantidad1=query1.value(0).toString();
            if (mac1 == Cantidad1)
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("No se pueden duplicar MAC. Cambie los datos de la MAC para poder insertarla."));
                m.exec();
                return;
            }
            else
            {
                int respuesta = 0;
                respuesta = QMessageBox::question(this, tr(QString::fromUtf8("Confirmación de bloqueo de MAC")),
                                       tr(QString::fromUtf8("<center><b>CONFIRMACIÓN<b></center><p>"

                                       "Procede con cuidado, ya que dejarás desconectada esa MAC hasta que la quites de la "
                                       "lista negra.<p>"

                                       "&iquest;Está seguro de querer bloquear la MAC "+mac1+"?")), QMessageBox::Ok, QMessageBox::No);
                if (respuesta == QMessageBox::Ok)
                {
                    QSqlQuery query2(db);
                    query2.prepare("INSERT INTO wlistanegra (ip,mac)"
                                  "VALUES (:ip, :mac)");
                    query2.bindValue(":ip", item->text());
                    query2.bindValue(":mac", item1->text());
                    query2.exec();
                    Model1->select();
                    ui->tableView_2->setModel(Model1);
                    QString cm =QString::fromUtf8(tr("echo Bloqueando acceso a la MAC "+mac1+"..."));
                    QString cm1= "iptables -A INPUT -p all -m mac --mac-source %1 -j DROP";
                    cm1 = cm1.arg(mac1);
                    QStringList comandos;
                    comandos<< cm << cm1;

                    if (mib != 0)
                        delete mib;
                    mib = new DrakeProcesos1(comandos, this);
                    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                    connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
                    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                    int valor= comandos.count(); mib->Valor(valor,0); mib->iniciarProceso();
                }
                ui->tableView_2->resizeColumnsToContents();
                ui->tableView_2->resizeRowsToContents();
                return;
            }
        }
    }
    ui->tableView_2->resizeColumnsToContents();
    ui->tableView_2->resizeRowsToContents();
}
