#include "subtitulos.h"
#include "ui_subtitulos.h"
#include "drakesistema.h"
#include <QFileDialog>
#include <QSqlQuery>

Subtitulos::Subtitulos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Subtitulos)
{
    ui->setupUi(this);
    drakeSistema drake;
    user = drake.getUser();
    mib=0;
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

Subtitulos::~Subtitulos()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void Subtitulos::changeEvent(QEvent *e)
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

void Subtitulos::on_pushButton_5_clicked()
{
    close();
}

void Subtitulos::on_pushButton_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    PeliOrigen=QFileDialog::getOpenFileName
     (this,tr("Abrir Archivo"),path,
        tr("Todos los archivos (*.*)"));
    if(PeliOrigen.isEmpty() )
    {
        return;
    }
    QFile file(PeliOrigen);
    Peli = QFileInfo(file).fileName();
    ui->lineEdit->setText(""+Peli+"");
}

void Subtitulos::on_pushButton_2_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    SubOrigen=QFileDialog::getOpenFileName
     (this,tr("Abrir Archivo"),path,
        tr("Archivo .srt (*.srt)"));
    if(SubOrigen.isEmpty() )
    {
        return;
    }
    QFile file(SubOrigen);
    Sub = QFileInfo(file).fileName();
    ui->lineEdit_2->setText(""+Sub+"");
}

void Subtitulos::on_pushButton_3_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    PeliDestino=QFileDialog::getOpenFileName
     (this,tr("Abrir Archivo"),path,
        tr("Todos los archivos (*.*)"));
    if(PeliDestino.isEmpty() )
    {
        return;
    }
    QFile file(PeliDestino);
    Final = QFileInfo(file).fileName();
    ui->lineEdit_3->setText(""+Final+"");
}

void Subtitulos::on_pushButton_4_clicked()
{
    QStringList comandos;
    QString cmd = QString::fromUtf8(tr("echo Realizando proceso de subtitulado..."));
    PeliOrigen = PeliOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    SubOrigen = SubOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    PeliDestino = PeliDestino.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    QString cmd1 = "su - %1 -c \"mencoder -ovc lavc -lavcopts vcodec=mpeg4 -oac copy %2 -o %4 -sub %3 -font /usr/share/fonts/TTF/DejaVuSans.ttf -subfont-autoscale 1\"";
    cmd1=cmd1.arg(user).arg(PeliOrigen).arg(SubOrigen).arg(PeliDestino);
    QString cmd2 = QString::fromUtf8(tr("echo Subtitulos insertados."));
    comandos << cmd << cmd1 << cmd2;
    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count(); mib->Valor(valor,2); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
}

void Subtitulos::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
}

void Subtitulos::mibFin()
{
disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
}
