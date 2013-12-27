#include "desbloquear.h"
#include "ui_desbloquear.h"
#include <QMessageBox>
#include <QSqlQuery>

Desbloquear::Desbloquear(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Desbloquear)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    QSqlQuery query1(db);
    query1.exec("SELECT Usuario FROM Control");
    query1.last();
    Usuario=query1.value(0).toString();
    ui->lineEdit->setFocus();
}

Desbloquear::~Desbloquear()
{
    delete ui;
}

void Desbloquear::changeEvent(QEvent *e)
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

void Desbloquear::on_pushButton_clicked()
{
    QSqlQuery query(db);
    query.exec("select * from Acceso where Usuario='"+Usuario+"' and Clave='"+ui->lineEdit->text()+"'");
    if( query.first() )
        {
            this->correcto=true;
            this->Resultado="1";
            this->close();
            return;
        }
    else
        {
        QMessageBox::about(this, tr(QString::fromUtf8("Acceso no valido")),
                   tr("Al usuario activo se le ha introducido una clave incorrecta.<p>"
                   "Comprueba que los datos introducidos sean correctos.<p>"));
        this->correcto=false;
        this->Resultado="0";
        this->close();
        return;
    }
}

void Desbloquear::on_pushButton_2_clicked()
{
    this->correcto=false;
    this->Resultado="0";
    this->close();
    return;
}
