#include "sonido.h"
#include "ui_sonido.h"
#include <QSqlRecord>
#include <QSqlQuery>
#include <QMessageBox>

Sonido::Sonido(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sonido)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Model22= new QSqlTableModel(0,db);
    Model22->setTable("Ecualizador");
    Model22->select();
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
    QSqlQuery query25(db);
    query25.exec("SELECT activo,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10 FROM Ecualizador WHERE id=2");
    query25.first();
    if (query25.isValid())
    {
        activar=query25.value(0).toString();
        banda1=query25.value(1).toString();
        banda2=query25.value(2).toString();
        banda3=query25.value(3).toString();
        banda4=query25.value(4).toString();
        banda5=query25.value(5).toString();
        banda6=query25.value(6).toString();
        banda7=query25.value(7).toString();
        banda8=query25.value(8).toString();
        banda9=query25.value(9).toString();
        banda10=query25.value(10).toString();
    }
    if (activar == "Si")
        ui->checkBox_4->setChecked(true);
    else
        ui->checkBox_4->setChecked(false);
    ui->verticalSlider->setValue(banda1.toInt());
    ui->verticalSlider_2->setValue(banda2.toInt());
    ui->verticalSlider_3->setValue(banda3.toInt());
    ui->verticalSlider_4->setValue(banda4.toInt());
    ui->verticalSlider_5->setValue(banda5.toInt());
    ui->verticalSlider_6->setValue(banda6.toInt());
    ui->verticalSlider_7->setValue(banda7.toInt());
    ui->verticalSlider_8->setValue(banda8.toInt());
    ui->verticalSlider_9->setValue(banda9.toInt());
    ui->verticalSlider_10->setValue(banda10.toInt());
    Valor = 0;
    connect(ui->checkBox_4, SIGNAL(clicked()), this, SLOT(Comprobar()));
}

Sonido::~Sonido()
{
    delete ui;
    delete Model22;
}

void Sonido::on_pushButton_3_clicked()
{
    if (Valor == 1)
    {
        this->Resultado="Positivo";
    }
    else
    {
        this->Resultado="Negativo";
    }
    close();
}

void Sonido::on_pushButton_2_clicked()
{
    QString Activo,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10;
    QSqlQuery queryEcua(db);
    queryEcua.exec("SELECT activo,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10 FROM Ecualizador WHERE id=1");
    queryEcua.first();
    if (queryEcua.isValid())
    {
        Activo=queryEcua.value(0).toString();
        banda1=queryEcua.value(1).toString();
        banda2=queryEcua.value(2).toString();
        banda3=queryEcua.value(3).toString();
        banda4=queryEcua.value(4).toString();
        banda5=queryEcua.value(5).toString();
        banda6=queryEcua.value(6).toString();
        banda7=queryEcua.value(7).toString();
        banda8=queryEcua.value(8).toString();
        banda9=queryEcua.value(9).toString();
        banda10=queryEcua.value(10).toString();
    }
    if (Activo == "Si")
        ui->checkBox_4->setChecked(true);
    else
        ui->checkBox_4->setChecked(false);
    ui->verticalSlider->setValue(banda1.toInt());
    ui->verticalSlider_2->setValue(banda2.toInt());
    ui->verticalSlider_3->setValue(banda3.toInt());
    ui->verticalSlider_4->setValue(banda4.toInt());
    ui->verticalSlider_5->setValue(banda5.toInt());
    ui->verticalSlider_6->setValue(banda6.toInt());
    ui->verticalSlider_7->setValue(banda7.toInt());
    ui->verticalSlider_8->setValue(banda8.toInt());
    ui->verticalSlider_9->setValue(banda9.toInt());
    ui->verticalSlider_10->setValue(banda10.toInt());
    QString Ecualizador;
    QSqlQuery ecualizador(db);
    ecualizador.exec("SELECT id FROM Ecualizador WHERE id=2");
    ecualizador.first();
    if (ecualizador.isValid())
        Ecualizador=ecualizador.value(0).toString();
    int filaEcualizador=1;
    QSqlRecord record= Model22->record(filaEcualizador);
    record.setValue(0,Ecualizador.toInt());
    record.setValue(1,Activo);
    record.setValue(2,banda1);
    record.setValue(3,banda2);
    record.setValue(4,banda3);
    record.setValue(5,banda4);
    record.setValue(6,banda5);
    record.setValue(7,banda6);
    record.setValue(8,banda7);
    record.setValue(9,banda8);
    record.setValue(10,banda9);
    record.setValue(11,banda10);
    Model22->setRecord(filaEcualizador,record);
    Model22->submitAll();
    Valor = 1;
}

void Sonido::on_pushButton_clicked()
{
    QString Ecualizador;
    QSqlQuery ecualizador(db);
    ecualizador.exec("SELECT id FROM Ecualizador WHERE id=2");
    ecualizador.first();
    if (ecualizador.isValid())
        Ecualizador=ecualizador.value(0).toString();
    int filaEcualizador=1;
    QString Cantidad,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10;
    if (Ecualizador == "2")
    {
        if (ui->checkBox_4->isChecked())
            Cantidad = "Si";
        else
            Cantidad = "No";
        banda1=QString::number(ui->verticalSlider->value());
        banda2=QString::number(ui->verticalSlider_2->value());
        banda3=QString::number(ui->verticalSlider_3->value());
        banda4=QString::number(ui->verticalSlider_4->value());
        banda5=QString::number(ui->verticalSlider_5->value());
        banda6=QString::number(ui->verticalSlider_6->value());
        banda7=QString::number(ui->verticalSlider_7->value());
        banda8=QString::number(ui->verticalSlider_8->value());
        banda9=QString::number(ui->verticalSlider_9->value());
        banda10=QString::number(ui->verticalSlider_10->value());
        QSqlRecord record= Model22->record(filaEcualizador);
        record.setValue(0,Ecualizador.toInt());
        record.setValue(1,Cantidad);
        record.setValue(2,banda1);
        record.setValue(3,banda2);
        record.setValue(4,banda3);
        record.setValue(5,banda4);
        record.setValue(6,banda5);
        record.setValue(7,banda6);
        record.setValue(8,banda7);
        record.setValue(9,banda8);
        record.setValue(10,banda9);
        record.setValue(11,banda10);
        Model22->setRecord(filaEcualizador,record);
        Model22->submitAll();
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    this->Resultado="Positivo";
    close();
}

void Sonido::on_verticalSlider_valueChanged(int value)
{
    QString Cantidad;
    if (ui->checkBox_4->isChecked())
        Cantidad = "Si";
    else
        Cantidad = "No";
    emit Sound(Cantidad, ui->verticalSlider->value(), ui->verticalSlider_2->value(), ui->verticalSlider_3->value(),
               ui->verticalSlider_4->value(), ui->verticalSlider_5->value(), ui->verticalSlider_6->value(),
               ui->verticalSlider_7->value(), ui->verticalSlider_8->value(), ui->verticalSlider_9->value(),
               ui->verticalSlider_10->value());
}

void Sonido::on_verticalSlider_2_valueChanged(int value)
{
    QString Cantidad;
    if (ui->checkBox_4->isChecked())
        Cantidad = "Si";
    else
        Cantidad = "No";
    emit Sound(Cantidad, ui->verticalSlider->value(), ui->verticalSlider_2->value(), ui->verticalSlider_3->value(),
               ui->verticalSlider_4->value(), ui->verticalSlider_5->value(), ui->verticalSlider_6->value(),
               ui->verticalSlider_7->value(), ui->verticalSlider_8->value(), ui->verticalSlider_9->value(),
               ui->verticalSlider_10->value());
}

void Sonido::on_verticalSlider_3_valueChanged(int value)
{
    QString Cantidad;
    if (ui->checkBox_4->isChecked())
        Cantidad = "Si";
    else
        Cantidad = "No";
    emit Sound(Cantidad, ui->verticalSlider->value(), ui->verticalSlider_2->value(), ui->verticalSlider_3->value(),
               ui->verticalSlider_4->value(), ui->verticalSlider_5->value(), ui->verticalSlider_6->value(),
               ui->verticalSlider_7->value(), ui->verticalSlider_8->value(), ui->verticalSlider_9->value(),
               ui->verticalSlider_10->value());
}

void Sonido::on_verticalSlider_4_valueChanged(int value)
{
    QString Cantidad;
    if (ui->checkBox_4->isChecked())
        Cantidad = "Si";
    else
        Cantidad = "No";
    emit Sound(Cantidad, ui->verticalSlider->value(), ui->verticalSlider_2->value(), ui->verticalSlider_3->value(),
               ui->verticalSlider_4->value(), ui->verticalSlider_5->value(), ui->verticalSlider_6->value(),
               ui->verticalSlider_7->value(), ui->verticalSlider_8->value(), ui->verticalSlider_9->value(),
               ui->verticalSlider_10->value());
}

void Sonido::on_verticalSlider_5_valueChanged(int value)
{
    QString Cantidad;
    if (ui->checkBox_4->isChecked())
        Cantidad = "Si";
    else
        Cantidad = "No";
    emit Sound(Cantidad, ui->verticalSlider->value(), ui->verticalSlider_2->value(), ui->verticalSlider_3->value(),
               ui->verticalSlider_4->value(), ui->verticalSlider_5->value(), ui->verticalSlider_6->value(),
               ui->verticalSlider_7->value(), ui->verticalSlider_8->value(), ui->verticalSlider_9->value(),
               ui->verticalSlider_10->value());
}

void Sonido::on_verticalSlider_6_valueChanged(int value)
{
    QString Cantidad;
    if (ui->checkBox_4->isChecked())
        Cantidad = "Si";
    else
        Cantidad = "No";
    emit Sound(Cantidad, ui->verticalSlider->value(), ui->verticalSlider_2->value(), ui->verticalSlider_3->value(),
               ui->verticalSlider_4->value(), ui->verticalSlider_5->value(), ui->verticalSlider_6->value(),
               ui->verticalSlider_7->value(), ui->verticalSlider_8->value(), ui->verticalSlider_9->value(),
               ui->verticalSlider_10->value());
}

void Sonido::on_verticalSlider_7_valueChanged(int value)
{
    QString Cantidad;
    if (ui->checkBox_4->isChecked())
        Cantidad = "Si";
    else
        Cantidad = "No";
    emit Sound(Cantidad, ui->verticalSlider->value(), ui->verticalSlider_2->value(), ui->verticalSlider_3->value(),
               ui->verticalSlider_4->value(), ui->verticalSlider_5->value(), ui->verticalSlider_6->value(),
               ui->verticalSlider_7->value(), ui->verticalSlider_8->value(), ui->verticalSlider_9->value(),
               ui->verticalSlider_10->value());
}

void Sonido::on_verticalSlider_8_valueChanged(int value)
{
    QString Cantidad;
    if (ui->checkBox_4->isChecked())
        Cantidad = "Si";
    else
        Cantidad = "No";
    emit Sound(Cantidad, ui->verticalSlider->value(), ui->verticalSlider_2->value(), ui->verticalSlider_3->value(),
               ui->verticalSlider_4->value(), ui->verticalSlider_5->value(), ui->verticalSlider_6->value(),
               ui->verticalSlider_7->value(), ui->verticalSlider_8->value(), ui->verticalSlider_9->value(),
               ui->verticalSlider_10->value());
}

void Sonido::on_verticalSlider_9_valueChanged(int value)
{
    QString Cantidad;
    if (ui->checkBox_4->isChecked())
        Cantidad = "Si";
    else
        Cantidad = "No";
    emit Sound(Cantidad, ui->verticalSlider->value(), ui->verticalSlider_2->value(), ui->verticalSlider_3->value(),
               ui->verticalSlider_4->value(), ui->verticalSlider_5->value(), ui->verticalSlider_6->value(),
               ui->verticalSlider_7->value(), ui->verticalSlider_8->value(), ui->verticalSlider_9->value(),
               ui->verticalSlider_10->value());
}

void Sonido::on_verticalSlider_10_valueChanged(int value)
{
    QString Cantidad;
    if (ui->checkBox_4->isChecked())
        Cantidad = "Si";
    else
        Cantidad = "No";
    emit Sound(Cantidad, ui->verticalSlider->value(), ui->verticalSlider_2->value(), ui->verticalSlider_3->value(),
               ui->verticalSlider_4->value(), ui->verticalSlider_5->value(), ui->verticalSlider_6->value(),
               ui->verticalSlider_7->value(), ui->verticalSlider_8->value(), ui->verticalSlider_9->value(),
               ui->verticalSlider_10->value());
}

void Sonido::Comprobar()
{
    if (ui->checkBox_4->isChecked())
    {
        QString Cantidad;
        Cantidad = "Si";
        ui->groupBox_20->setEnabled(true);
        emit Sound(Cantidad, ui->verticalSlider->value(), ui->verticalSlider_2->value(), ui->verticalSlider_3->value(),
                   ui->verticalSlider_4->value(), ui->verticalSlider_5->value(), ui->verticalSlider_6->value(),
                   ui->verticalSlider_7->value(), ui->verticalSlider_8->value(), ui->verticalSlider_9->value(),
                   ui->verticalSlider_10->value());
    }
    else
    {
        QString Cantidad;
        Cantidad = "No";
        ui->groupBox_20->setEnabled(false);
        emit Sound(Cantidad, ui->verticalSlider->value(), ui->verticalSlider_2->value(), ui->verticalSlider_3->value(),
                   ui->verticalSlider_4->value(), ui->verticalSlider_5->value(), ui->verticalSlider_6->value(),
                   ui->verticalSlider_7->value(), ui->verticalSlider_8->value(), ui->verticalSlider_9->value(),
                   ui->verticalSlider_10->value());
    }
}
