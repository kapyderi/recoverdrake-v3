#include "ordenar.h"
#include "ui_ordenar.h"
#include <QFontDialog>
#include <QColorDialog>
#include <QDebug>

ordenar::ordenar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordenar)
{
    ui->setupUi(this);
}

ordenar::~ordenar()
{
    delete ui;
}

void ordenar::Dato(QString valor)
{
    if (valor == "pelis")
    {
        ui->label_2->setEnabled(true);
        ui->comboBox->setEnabled(true);
        ui->label_3->setEnabled(false);
        ui->label_4->setEnabled(false);
        ui->comboBox_2->setEnabled(false);
        ui->comboBox_3->setEnabled(false);
    }
}

void ordenar::on_pushButton_3_clicked()
{
    bool ok;
    TLetra = QFontDialog::getFont(&ok, QFont("Helvetica", 6, 50), this);
    ui->lineEdit->setFont(TLetra);
}

void ordenar::on_pushButton_4_clicked()
{
    TColor= QColorDialog::getColor(Qt::black, this);
    QString Color = TColor.name();
    ui->lineEdit_2->setStyleSheet("color: "+Color+"");
}

void ordenar::on_pushButton_clicked()
{
    NOrden="";
    close();
}

void ordenar::on_pushButton_2_clicked()
{
    NOrden=ui->comboBox->currentText();
    close();
}

void ordenar::on_pushButton_5_clicked()
{
    TColor1= QColorDialog::getColor(Qt::black, this);
    QString Color = TColor1.name();
    ui->lineEdit_3->setStyleSheet("color: "+Color+"");
}
