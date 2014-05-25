#include "totalsincrono.h"
#include "ui_totalsincrono.h"
#include <QKeyEvent>
#include <QSqlQuery>
#include "drakesistema.h"
#include <QMessageBox>
#include <QDebug>
#include <QTableWidgetItem>

TotalSincrono::TotalSincrono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TotalSincrono)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Model= new QSqlTableModel(0,db);
    Model->setTable("Sincrono");
    Model->select();
    ui->tableView->setModel(Model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(7, true);
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(cambiaFila(QModelIndex)));
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    drakeSistema drake;
    user = drake.getUser();
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
    QString Spain, English;
    QSqlQuery querySpain(db);
    querySpain.exec("SELECT spanish FROM Idioma WHERE id='2'");
    querySpain.first();
    if (querySpain.isSelect())
        Spain=querySpain.value(0).toString();
    QSqlQuery queryEnglish(db);
    queryEnglish.exec("SELECT english FROM Idioma WHERE id='2'");
    queryEnglish.first();
    if (queryEnglish.isSelect())
        English=queryEnglish.value(0).toString();
    QString idioma;
    if ( Spain == "2")
    {
        Idioma = "es";
    }
    else if ( English == "2")
    {
        Idioma = "en";
    }
    if (Idioma == "en")
    {
        Model->setHeaderData(1,Qt::Horizontal,"Reference");
        Model->setHeaderData(2,Qt::Horizontal,"Target");
        Model->setHeaderData(3,Qt::Horizontal,"Destination");
        Model->setHeaderData(4,Qt::Horizontal,"Delete");
        Model->setHeaderData(5,Qt::Horizontal,"Check");
        Model->setHeaderData(6,Qt::Horizontal,"Hidden");
    }
    else if (Idioma == "en")
    {
        Model->setHeaderData(1,Qt::Horizontal,"Referencia");
        Model->setHeaderData(2,Qt::Horizontal,"Objetivo");
        Model->setHeaderData(3,Qt::Horizontal,"Destino");
        Model->setHeaderData(4,Qt::Horizontal,"Eliminar");
        Model->setHeaderData(5,Qt::Horizontal,"Comprobar");
        Model->setHeaderData(6,Qt::Horizontal,"Ocultos");
    }
    this->installEventFilter(this);
    CierreTotal = 0;
    cantidad = 1;    
}

TotalSincrono::~TotalSincrono()
{
    delete ui;
    delete Model;
}

void TotalSincrono::cambiaFila(QModelIndex actual)
{
    ActualRow=actual.row();
    QModelIndex index;
    index=ui->tableView->model()->index(ActualRow,0);
    index=ui->tableView->model()->index(ActualRow,1);
    Ref= index.data().toString();
    index=ui->tableView->model()->index(ActualRow,2);
    index=ui->tableView->model()->index(ActualRow,3);
    index=ui->tableView->model()->index(ActualRow,4);
    index=ui->tableView->model()->index(ActualRow,5);
    index=ui->tableView->model()->index(ActualRow,6);
    index=ui->tableView->model()->index(ActualRow,7);
}

bool TotalSincrono::eventFilter(QObject* obj, QEvent *event)
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
                ayuda->Valor(tr("Sincrono"));
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void TotalSincrono::Valor(QString valor, QString Log)
{    
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
    if (Log == "S")
        log = "S";
    else
        log = "N";
    inicio();
}

void TotalSincrono::on_pushButton_10_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void TotalSincrono::closeEvent ( QCloseEvent * event )
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

void TotalSincrono::inicio()
{
    QSqlQuery Cantidad(db);
    Cantidad.exec("SELECT COUNT(id) as Cantidad FROM Sincrono");
    int cuenta;
    Cantidad.first();
    cuenta = Cantidad.value(0).toInt();
    if (cuenta > 0)
    {
        QString Referencia, Objetivo, Destino, Eliminar, Comprobar, Ocultos, Codigo, Id;
        QSqlQuery Sincroniza(db);
        Sincroniza.exec("SELECT Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo,Id FROM Sincrono");
        while(Sincroniza.next())
        {
            Referencia = Sincroniza.value(0).toString();
            Objetivo = Sincroniza.value(1).toString();
            Destino = Sincroniza.value(2).toString();
            Eliminar = Sincroniza.value(3).toString();
            Comprobar = Sincroniza.value(4).toString();
            Ocultos = Sincroniza.value(5).toString();
            Codigo = Sincroniza.value(6).toString();
            Id = Sincroniza.value(7).toString();
            Sincro = new sincrono();
            connect(Sincro, SIGNAL(Terminado(int,QString)), this, SLOT(Refrescar(int,QString)));
            ui->tabWidget->addTab(Sincro,Referencia);
            ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
            Sincro->Valor(Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo,0,log,Id);
        }
    }
    else if (cuenta == 0)
    {
        Sincro = new sincrono();
        connect(Sincro, SIGNAL(Terminado(int,QString)), this, SLOT(Refrescar(int,QString)));
        ui->tabWidget->addTab(Sincro,"Manual: "+QString::number(cantidad)+"");
        ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
        cantidad++;
    }
}

void TotalSincrono::on_pushButton_4_clicked()
{
    Sincro = new sincrono();
    connect(Sincro, SIGNAL(Terminado(int,QString)), this, SLOT(Refrescar(int,QString)));
    ui->tabWidget->addTab(Sincro,"Manual: "+QString::number(cantidad)+"");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
    cantidad++;    
}

void TotalSincrono::on_pushButton_5_clicked()
{
    if (ui->tabWidget->count() > 1)
    {
        ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
        cantidad--;
    }
    else
    {
        ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
        Sincro = new sincrono();
        connect(Sincro, SIGNAL(Terminado(int,QString)), this, SLOT(Refrescar(int,QString)));
        ui->tabWidget->addTab(Sincro,"Manual: "+QString::number(cantidad)+"");
        ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
        cantidad++;
    }
}

void TotalSincrono::Refrescar(int Valor,QString Value)
{
    if (Valor == 1)
    {
        ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
    }
    if (Value != "")
    {
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),Value);
    }
    Model->select();
    ui->tableView->setModel(Model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

void TotalSincrono::on_pushButton_14_clicked()
{
    ui->tabWidget->clear();
    QSqlQuery Cantidad(db);
    Cantidad.exec("SELECT COUNT(id) as Cantidad FROM Sincrono");
    int cuenta;
    Cantidad.first();
    cuenta = Cantidad.value(0).toInt();
    if (cuenta > 0)
    {
        QString Referencia, Objetivo, Destino, Eliminar, Comprobar, Ocultos, Codigo, Id;
        QSqlQuery Sincroniza(db);
        Sincroniza.exec("SELECT Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo,Id FROM Sincrono");
        while(Sincroniza.next())
        {
            Referencia = Sincroniza.value(0).toString();
            Objetivo = Sincroniza.value(1).toString();
            Destino = Sincroniza.value(2).toString();
            Eliminar = Sincroniza.value(3).toString();
            Comprobar = Sincroniza.value(4).toString();
            Ocultos = Sincroniza.value(5).toString();
            Codigo = Sincroniza.value(6).toString();
            Id = Sincroniza.value(7).toString();
            Sincro = new sincrono();
            connect(Sincro, SIGNAL(Terminado(int,QString)), this, SLOT(Refrescar(int,QString)));
            ui->tabWidget->addTab(Sincro,Referencia);
            ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
            Sincro->Valor(Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo,1,log,Id);
            cantidad++;
        }
    }
    else if (cuenta == 0)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay objetivos guardados para poder analizar."));
        m.exec();
        return;
    }
}

void TotalSincrono::on_pushButton_12_clicked()
{
    ui->tabWidget->clear();
    QSqlQuery Cantidad(db);
    Cantidad.exec("SELECT COUNT(id) as Cantidad FROM Sincrono");
    int cuenta;
    Cantidad.first();
    cuenta = Cantidad.value(0).toInt();
    if (cuenta > 0)
    {
        QString Referencia, Objetivo, Destino, Eliminar, Comprobar, Ocultos, Codigo, Id;
        QSqlQuery Sincroniza(db);
        Sincroniza.exec("SELECT Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo,Id FROM Sincrono");
        while(Sincroniza.next())
        {
            Referencia = Sincroniza.value(0).toString();
            Objetivo = Sincroniza.value(1).toString();
            Destino = Sincroniza.value(2).toString();
            Eliminar = Sincroniza.value(3).toString();
            Comprobar = Sincroniza.value(4).toString();
            Ocultos = Sincroniza.value(5).toString();
            Codigo = Sincroniza.value(6).toString();
            Id = Sincroniza.value(7).toString();
            Sincro = new sincrono();
            connect(Sincro, SIGNAL(Terminado(int,QString)), this, SLOT(Refrescar(int,QString)));
            ui->tabWidget->addTab(Sincro,Referencia);
            ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
            Sincro->Valor(Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo,2,log,Id);
        }
    }
    else if (cuenta == 0)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay objetivos guardados para poder sincronizar."));
        m.exec();
        return;
    }
}

void TotalSincrono::on_tableView_doubleClicked(const QModelIndex &index)
{
    int iFilas, a, Valor;
    QString Refer;
    iFilas=index.row();
    QModelIndex indexar;
    indexar=ui->tableView->model()->index(iFilas,1);
    Refer= indexar.data().toString();
    Valor = ui->tabWidget->count();
    for(a=0;a<Valor;a++)
    {
        if (ui->tabWidget->tabText(a) == Refer)
        {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Ya hay un objetivo abierto con el mismo nombre."));
        m.exec();
        return;
        }
    }
    QString Referencia, Objetivo, Destino, Eliminar, Comprobar, Ocultos, Codigo, Id;
    QSqlQuery Sincroniza(db);
    Sincroniza.exec("SELECT Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo,Id FROM Sincrono WHERE Referencia='"+Refer+"'");
    Sincroniza.first();
    Referencia = Sincroniza.value(0).toString();
    Objetivo = Sincroniza.value(1).toString();
    Destino = Sincroniza.value(2).toString();
    Eliminar = Sincroniza.value(3).toString();
    Comprobar = Sincroniza.value(4).toString();
    Ocultos = Sincroniza.value(5).toString();
    Codigo = Sincroniza.value(6).toString();
    Id = Sincroniza.value(7).toString();
    Sincro = new sincrono();
    connect(Sincro, SIGNAL(Terminado(int,QString)), this, SLOT(Refrescar(int,QString)));
    ui->tabWidget->addTab(Sincro,Referencia);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
    Sincro->Valor(Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo,0,log,Id);
}
