#include "remoto.h"
#include "ui_remoto.h"
#include "drakeprocesos.h"
#include "drakesistema.h"
#include <QSqlQuery>

remoto::remoto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remoto)
{
    ui->setupUi(this);
    mib = 0;
    drakeSistema drake;
    user=drake.getUser();
    db=QSqlDatabase::database("PRINCIPAL");
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
    }
}

remoto::~remoto()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void remoto::on_pushButton_2_clicked()
{
    close();
}

void remoto::on_pushButton_3_clicked()
{
    QStringList comandos;
    QString md1 = "su - %1 -c \"vncviewer %2\"";
    md1=md1.arg(user).arg(ui->lineEdit->text());
    comandos << md1;
    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count();
    mib->Valor(valor,3);
    mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
    mib->iniciarProceso();
    close();
}

void remoto::mibFin()
{
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
}
