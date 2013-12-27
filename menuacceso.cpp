#include "menuacceso.h"
#include "ui_menuacceso.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDebug>
#include <QMessageBox>
#include "drakesistema.h"

MenuAcceso::MenuAcceso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuAcceso)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Model= new QSqlTableModel(0,db);
    Model->setTable("Menu");
    Model->select();
    Model->setHeaderData(1,Qt::Horizontal,"Nombre");
    Model->setHeaderData(2,Qt::Horizontal,"Nombre en Espanol");
    Model->setHeaderData(3,Qt::Horizontal,"Comentario en Espanol");
    Model->setHeaderData(4,Qt::Horizontal,"Comentario");
    Model->setHeaderData(5,Qt::Horizontal,"Categoria");
    Model->setHeaderData(6,Qt::Horizontal,"Icono");
    Model->setHeaderData(7,Qt::Horizontal,"Ejecutable");
    ui->tableView->setModel(Model);
    ui->tableView->setColumnHidden(0, true);
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila(QModelIndex)));
    drakeSistema drake;
    user = drake.getUser();
    mib = 0;
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
}

MenuAcceso::~MenuAcceso()
{
    delete ui;
    delete Model;
    if (mib != 0)
        delete mib;
}

void MenuAcceso::on_pushButton_4_clicked()
{
    close();
}

void MenuAcceso::cambiaFila(QModelIndex actual)
{
        int i;
        i=actual.row();
        QModelIndex index;
        index=ui->tableView->model()->index(i,0);
        this->id= index.data().toInt();
        ui->lineEdit_3->setText(index.data().toString());
        index=ui->tableView->model()->index(i,1);
        ui->lineEdit->setText(index.data().toString());
        index=ui->tableView->model()->index(i,2);
        ui->lineEdit_6->setText(index.data().toString());
        index=ui->tableView->model()->index(i,3);
        ui->textEdit_4->setText(index.data().toString());
        index=ui->tableView->model()->index(i,4);
        ui->textEdit->setText(index.data().toString());
        index=ui->tableView->model()->index(i,5);
        ui->textEdit_3->setText(index.data().toString());
        index=ui->tableView->model()->index(i,6);
        QImage image("/usr/share/icons/"+index.data().toString()+"");
        ui->label_6->setPixmap(QPixmap::fromImage(image));
        ui->label_6->setScaledContents(true);
        ui->label_6->adjustSize();
        index=ui->tableView->model()->index(i,7);
        ui->lineEdit_4->setText(index.data().toString());
        this->fila=i;
}

void MenuAcceso::on_pushButton_clicked()
{
    Value0 = ui->lineEdit_4->text();
    Value1 = ui->lineEdit->text();
    Value2 = ui->lineEdit_6->text();
    Value5 = ui->textEdit->toPlainText();
    Value6 = ui->textEdit_4->toPlainText();
    Value7 = ui->textEdit_3->toPlainText();
    QSqlQuery queryVal(db);
    queryVal.exec("SELECT Name FROM Menu WHERE Name='"+Value1+"'");
    queryVal.first();
    if (queryVal.isValid())
        Valor=queryVal.value(0).toString();
    if (Value1 == Valor)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El nombre "+Value1+" ya existe. Utiliza la opción de modificar para cambiar los datos del mismo"));
        m.exec();
    }
    else
    {
        QSqlQuery queryValor(db);
        queryValor.prepare("INSERT INTO Menu (Name,Name_es,Comment_es,Comment,Categories,Exec)"
                           "VALUES (:Name, :NameEs, :CommentEs, :Comment, :Categories, :Exec)");
        queryValor.bindValue(":Name", Value1);
        queryValor.bindValue(":NameEs", Value2);
        queryValor.bindValue(":CommentEs", Value6);
        queryValor.bindValue(":Comment", Value5);
        queryValor.bindValue(":Categories", Value7);
        queryValor.bindValue(":Exec", Value0);
        queryValor.exec();
        Model->select();
        ui->tableView->setModel(Model);
    }
}

void MenuAcceso::on_pushButton_7_clicked()
{
    this->ui->lineEdit_4->setText("");
    this->ui->lineEdit->setText("");
    this->ui->lineEdit_6->setText("");
    this->ui->textEdit->setText("");
    this->ui->textEdit_4->setText("");
    this->ui->textEdit_3->setText("");
    return;
}

void MenuAcceso::on_pushButton_3_clicked()
{
     ui->tableView->model()->removeRow(fila);
}

void MenuAcceso::on_pushButton_6_clicked()
{
    QString cm1= "su - %1 -c \""+ui->lineEdit_4->text()+"\"";
    cm1 = cm1.arg(user);
    QStringList comandos;
    comandos<< cm1;

    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
    return;
}


void MenuAcceso::on_pushButton_5_clicked()
{
    Model->setFilter("Name like'"+ui->lineEdit->text()+"%'");
    ui->tableView->setModel(Model);
}

void MenuAcceso::on_pushButton_2_clicked()
{
    QString Compara = ui->lineEdit->text();
    QSqlQuery queryVal(db);
    queryVal.exec("SELECT Name FROM Menu WHERE Name='"+Compara+"'");
    queryVal.first();
    if (queryVal.isValid())
        Valor=queryVal.value(0).toString();
    if (Compara == Valor)
    {
        QSqlRecord record= Model->record(this->fila);
        record.setValue(1, ""+Compara+"");
        record.setValue(2, ui->lineEdit_6->text());
        record.setValue(3, ui->textEdit_4->toPlainText());
        record.setValue(4, ui->textEdit->toPlainText());
        record.setValue(5, ui->textEdit_3->toPlainText());
        record.setValue(7, ui->lineEdit_4->text());
        Model->setRecord(this->fila,record);
        Model->submitAll();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El nombre <b>"+ui->lineEdit->text()+"</b> no se puede modificar, ya que no se puede localizar en la base de datos del menu si es modifciado."));
        m.exec();
    }
}
