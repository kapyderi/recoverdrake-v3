#include "cierre.h"
#include "ui_cierre.h"
#include "QDebug"
#include "QDateTime"
#include "QMessageBox"
#include <QSqlQuery>

Cierre::Cierre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cierre)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(hora()));
    timer->start(1000);
    QDateTime time =QDateTime::currentDateTime();
    QString Dia = time.toString("dd");
    QString Mes = time.toString("MM");
    QString Anyo = time.toString("yyyy");
    QString Hora = time.toString("hh");
    QString Minuto = time.toString("mm");
    QString Segundo = time.toString("ss");
    ui->spinBox->setValue(Dia.toInt());
    ui->spinBox_2->setValue(Mes.toInt());
    ui->spinBox_3->setValue(Anyo.toInt());
    ui->spinBox_6->setValue(Hora.toInt());
    ui->spinBox_4->setValue(Minuto.toInt());
    ui->spinBox_5->setValue(Segundo.toInt());
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
    QString cantidad43, cantidad44;
    QSqlQuery query41(db);
    query41.exec("SELECT spanish FROM Idioma WHERE id=2");
    query41.first();
    if (query41.isValid())
        cantidad43=query41.value(0).toString();
    QSqlQuery query42(db);
    query42.exec("SELECT english FROM Idioma WHERE id=2");
    query42.first();
    if (query42.isValid())
        cantidad44=query42.value(0).toString();
    if ( cantidad43 == "2")
    {
        ui->label_8->setText(tr("Ano"));
    }
    else if ( cantidad44 == "2")
    {
        ui->label_8->setText(tr("Year"));
    }
}

Cierre::~Cierre()
{
    delete ui;
}

void Cierre::on_pushButton_2_clicked()
{
    this->DownDia=0;
    this->DownMes=0;
    this->DownAnyo=0;
    this->DownHora=0;
    this->DownMinuto=0;
    this->DownSegundo=0;
    this->close();
    return;
}

void Cierre::on_pushButton_clicked()
{
    int DiaD = ui->spinBox->value();
    int MesD = ui->spinBox_2->value();
    int AnyoD = ui->spinBox_3->value();
    int HoraD = ui->spinBox_6->value();
    int MinutoD = ui->spinBox_4->value();
    int SegundoD = ui->spinBox_5->value();
    QDateTime FechaInicio = QDateTime::currentDateTime();
    QDateTime FechaFinal(QDate(AnyoD,MesD,DiaD), QTime(HoraD,MinutoD,SegundoD));
    if (FechaInicio >= FechaFinal)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr(QString::fromUtf8("La fecha de apagado no puede ser inferior a la fecha del sistema.")));
        m.exec();
        return;
    }
    else
    {
        this->DownDia=DiaD;
        this->DownMes=MesD;
        this->DownAnyo=AnyoD;
        this->DownHora=HoraD;
        this->DownMinuto=MinutoD;
        this->DownSegundo=SegundoD;
        this->close();
        return;
    }
}

void Cierre::hora()
{
    QDateTime time =QDateTime::currentDateTime();
    QString hora = time.toString("dd/MM/yyyy hh:mm:ss");
    ui->label_15->setText(hora);
}

void Cierre::on_spinBox_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox->setPrefix("0");
    else
        ui->spinBox->setPrefix("");
}

void Cierre::on_spinBox_2_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_2->setPrefix("0");
    else
        ui->spinBox_2->setPrefix("");
}

void Cierre::on_spinBox_6_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_6->setPrefix("0");
    else
        ui->spinBox_6->setPrefix("");
}

void Cierre::on_spinBox_4_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_4->setPrefix("0");
    else
        ui->spinBox_4->setPrefix("");
}

void Cierre::on_spinBox_5_valueChanged(int arg1)
{
    if (arg1 < 10)
        ui->spinBox_5->setPrefix("0");
    else
        ui->spinBox_5->setPrefix("");
}
