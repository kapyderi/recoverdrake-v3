#include "notas.h"
#include "ui_notas.h"
#include "drakesistema.h"

notas::notas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notas)
{
    ui->setupUi(this);
    drakeSistema drake;
    user = drake.getUser();
    this->Ultimo=ui->label_2->text();
}

notas::~notas()
{
    delete ui;
}

void notas::changeEvent(QEvent *e)
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

void notas::on_pushButton_clicked()
{
    close();
}

void notas::on_pushButton_4_clicked()
{
    system("su - "+user+" -c \"firefox http://www.codigoqt.com\"");
    return;
}

void notas::on_pushButton_3_clicked()
{
    system("su - "+user+" -c \firefox http://www.blogdrake.net\"");
    return;
}

void notas::on_pushButton_2_clicked()
{
    system("su - "+user+" -c \"firefox http://www.kapyderi.blogspot.com\"");
    return;
}
