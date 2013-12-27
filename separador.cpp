#include "separador.h"
#include "ui_separador.h"

Separador::Separador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Separador)
{
    ui->setupUi(this);
    ui->radioButton_4->setChecked(true);
    ui->checkBox->setChecked(false);
}

Separador::~Separador()
{
    delete ui;
}

void Separador::Valor(QString datos)
{
     ui->lineEdit_3->setText(""+datos+"");
}

void Separador::on_pushButton_clicked()
{
    if (ui->radioButton->isChecked() == true)
    {
        this->SaltoDato=",";
    }
    else if (ui->radioButton_2->isChecked() == true)
    {
        this->SaltoDato=".";
    }
    else if (ui->radioButton_3->isChecked() == true)
    {
        this->SaltoDato="Tab";
    }
    else if (ui->radioButton_5->isChecked() == true)
    {
        this->SaltoDato=""+ui->lineEdit_5->text()+"";
    }   
    else if (ui->radioButton_4->isChecked() == true)
    {
        this->SaltoDato=";";
    }
    else if (ui->radioButton_6->isChecked() == true)
    {
        this->SaltoDato=":";
    }
    if (ui->checkBox->isChecked() == true)
    {
        this->Separa="Si";
    }
    else if (ui->checkBox->isChecked() == false)
    {
        this->Separa="No";
    }
    close();
}
