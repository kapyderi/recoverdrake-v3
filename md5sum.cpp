#include "md5sum.h"
#include "ui_md5sum.h"
#include "drakesistema.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

md5sum::md5sum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::md5sum)
{
    ui->setupUi(this);
    drakeSistema drake;
    user = drake.getUser();
    Contador = new QTimer(this);
    connect(Contador, SIGNAL(timeout()), this, SLOT(Contar()));
    Contador->stop();
    mib=0;
    Comp1=0;
    Comp2=0;
    ui->label_13->setVisible(false);
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
}

md5sum::~md5sum()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void md5sum::changeEvent(QEvent *e)
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

void md5sum::on_pushButton_3_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de imagen iso")),
                        path,trUtf8(tr("Ficheros iso (*.iso)")));
    if (fileNameOrigen.isEmpty())
        return;
    ui->lineEdit->setText(fileNameOrigen);
}

void md5sum::on_pushButton_5_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    fileNameOrigen1 = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de comprobacion")),
                        path,trUtf8(tr("Ficheros de comprobacion (*.md5)")));
    if (fileNameOrigen1.isEmpty())
        return;
    ui->lineEdit_4->setText(fileNameOrigen1);
    drakeSistema drake;
    QString valor = drake.getCat(fileNameOrigen1);
    Valor2=valor.split(" ");
    Val2=Valor2.value(0);
    ui->label_6->setText(Val2);
}

void md5sum::on_pushButton_2_clicked()
{
    close();
}

void md5sum::on_pushButton_4_clicked()
{
    Contador->start(200);
    ui->label_4->setText(tr("Espera por favor. Comprobando md5"));
    if (ui->lineEdit->text() == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has ingresado ninguna imagen para validar. No se puede continuar."));
        m.exec();
        return;
    }
    if (ui->lineEdit_4->text() == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has ingresado ningun archivo de verificacion. Solo se mostrara el md5 del archivo original, pero no se verficara."));
        m.exec();
    }
    QString cm, cm1;
    if (ui->lineEdit->text() != "")
    {
        cm = "echo Comprobando md5sum de imagen iso...";
        cm1="md5sum \"%1\"";
        cm1=cm1.arg(ui->lineEdit->text());
        comandos << cm << cm1;
    }
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

void md5sum::Contar()
{
    if (ui->label_4->text() == tr("Espera por favor. Comprobando md5"))
         ui->label_4->setText(tr("Espera por favor. Comprobando md5."));
    else if (ui->label_4->text() == tr("Espera por favor. Comprobando md5."))
         ui->label_4->setText(tr("Espera por favor. Comprobando md5.."));
    else if (ui->label_4->text() == tr("Espera por favor. Comprobando md5.."))
         ui->label_4->setText(tr("Espera por favor. Comprobando md5..."));
    else if (ui->label_4->text() == tr("Espera por favor. Comprobando md5..."))
         ui->label_4->setText(tr("Espera por favor. Comprobando md5...."));
    else if (ui->label_4->text() == tr("Espera por favor. Comprobando md5...."))
         ui->label_4->setText(tr("Espera por favor. Comprobando md5....."));
    else if (ui->label_4->text() == tr("Espera por favor. Comprobando md5....."))
         ui->label_4->setText(tr("Espera por favor. Comprobando md5......"));
    else if (ui->label_4->text() == tr("Espera por favor. Comprobando md5......"))
         ui->label_4->setText(tr("Espera por favor. Comprobando md5......."));
    else if (ui->label_4->text() == tr("Espera por favor. Comprobando md5......."))
         ui->label_4->setText(tr("Espera por favor. Comprobando md5........"));
    else if (ui->label_4->text() == tr("Espera por favor. Comprobando md5........"))
         ui->label_4->setText(tr("Espera por favor. Comprobando md5........."));
    else if (ui->label_4->text() == tr("Espera por favor. Comprobando md5........."))
         ui->label_4->setText(tr("Espera por favor. Comprobando md5.........."));
    else if (ui->label_4->text() == tr("Espera por favor. Comprobando md5.........."))
         ui->label_4->setText(tr("Espera por favor. Comprobando md5"));
}

void md5sum::on_pushButton_6_clicked()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    ui->label_4->setText(tr("Busqueda cancelada por el usuario."));
    Contador->stop();
}

void md5sum::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    Contador->stop();
    ui->label_4->setText("");
    if (Val1 != "")
    {
        if (ui->lineEdit_4->text() == "")
            ui->lineEdit_3->setText(Val1);
        else if (ui->lineEdit_4->text() != "")
        {
            if (Val1 == Val2)
            {
                ui->lineEdit_3->setText(Val1);
                ui->label_13->setVisible(true);
            }
        }
    }
}

void md5sum::mibEscribir(QString valor)
{
    Valor1=valor.split(" ");
    Val1=Valor1.value(0);
}
