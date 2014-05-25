#include "password.h"
#include "ui_password.h"
#include <QSqlQuery>
#include <QMessageBox>

password::password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::password)
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
}

password::~password()
{
    delete ui;
}

void password::changeEvent(QEvent *e)
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

void password::on_pushButton_2_clicked()
{
    close();
}

void password::Dato(QString valor)
{
    DatoUser=valor;
    QSqlQuery queryPregunta(db);
    queryPregunta.exec("SELECT Pregunta FROM Acceso WHERE Usuario='"+valor+"'");
    queryPregunta.first();
    if (queryPregunta.isValid())
        DatoPregunta=queryPregunta.value(0).toString();
    ui->label_3->setText(DatoPregunta);
}

void password::on_pushButton_clicked()
{
    QString DatoRespuesta, DatoClave;
    QSqlQuery queryRespuesta(db);
    queryRespuesta.exec("SELECT Respuesta FROM Acceso WHERE Usuario='"+DatoUser+"'");
    queryRespuesta.first();
    if (queryRespuesta.isValid())
        DatoRespuesta=queryRespuesta.value(0).toString();
    if (DatoRespuesta == ui->lineEdit->text())
    {
        QSqlQuery queryPass(db);
        queryPass.exec("SELECT Clave FROM Acceso WHERE Usuario='"+DatoUser+"'");
        queryPass.first();
        if (queryPass.isValid())
            DatoClave=queryPass.value(0).toString();
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("La clave para el usuario "+DatoUser+" es...<p>"+DatoClave+""));
        m.exec();
        this->Local=DatoClave;
        this->close();
        return;
    }
    else if(DatoRespuesta != ui->lineEdit->text())
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has introducido la respuesta correcta.<p>Prueba otra vez."));
        m.exec();
        return;
    }
}
