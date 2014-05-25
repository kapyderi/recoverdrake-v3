#include "calculadora.h"
#include "ui_calculadora.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

Calculadora::Calculadora(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Calculadora)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    QSqlQuery queryDefecto(db);
    queryDefecto.exec("SELECT Defecto FROM Miscelanea WHERE id=2");
    queryDefecto.first();
    if (queryDefecto.isValid())
        cantidadDefecto=queryDefecto.value(0).toString();
    if (cantidadDefecto == "0")
    {
        QSqlQuery query47(db);
        query47.exec("SELECT Fuente FROM Font WHERE id=2");
        query47.first();
        if (query47.isValid())
            cantidad47=query47.value(0).toString();
        QSqlQuery query48(db);
        query48.exec("SELECT Estilo FROM Font WHERE id=2");
        query48.first();
        if (query48.isValid())
            cantidad48=query48.value(0).toString();
        QSqlQuery query49(db);
        query49.exec("SELECT Talla FROM Font WHERE id=2");
        query49.first();
        if (query49.isValid())
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
        if (query50.isValid())
            cantidad50=query50.value(0).toString();
        QSqlQuery query51(db);
        query51.exec("SELECT ColorFondo FROM Color WHERE id=2");
        query51.first();
        if (query51.isValid())
            cantidad51=query51.value(0).toString();
        Stilo = "A";
    }
    QSqlQuery query25(db);
    query25.exec("SELECT Digitos,Decimales FROM Calculadora WHERE id=2");
    query25.first();
    if (query25.isValid())
    {
        Enteros=query25.value(0).toInt();
        Decimales=query25.value(1).toInt();
    }
    ui->horizontalSlider->setValue(Enteros);
    ui->horizontalSlider_2->setValue(Decimales);
    ui->label->setText(tr("Numero total de digitos: ")+QString::number(Enteros));
    ui->label_2->setText(tr("Numero total de decimales: ")+QString::number(Decimales));
    Conversion = 0;
    ValueCambio = 0;
    Aritmetica = 0;
}

Calculadora::~Calculadora()
{
    delete ui;
}

void Calculadora::on_pushButton_28_clicked()
{
    this->Terminado = "Si";
    close();
}

void Calculadora::on_pushButton_4_clicked()
{
    int Cantidad = Valor.size();
    if (Cantidad < Enteros)
    {
        Valor.append("7");
        ui->lineEdit->setText(Valor);
        this->Cambio();
    }
}

void Calculadora::on_pushButton_5_clicked()
{
    int Cantidad = Valor.size();
    if (Cantidad < Enteros)
    {
        Valor.append("8");
        ui->lineEdit->setText(Valor);
        this->Cambio();
    }
}

void Calculadora::on_pushButton_6_clicked()
{
    int Cantidad = Valor.size();
    if (Cantidad < Enteros)
    {
        Valor.append("9");
        ui->lineEdit->setText(Valor);
        this->Cambio();
    }
}

void Calculadora::on_pushButton_8_clicked()
{
    int Cantidad = Valor.size();
    if (Cantidad < Enteros)
    {
        Valor.append("4");
        ui->lineEdit->setText(Valor);
        this->Cambio();
    }
}

void Calculadora::on_pushButton_9_clicked()
{
    int Cantidad = Valor.size();
    if (Cantidad < Enteros)
    {
        Valor.append("5");
        ui->lineEdit->setText(Valor);
        this->Cambio();
    }
}

void Calculadora::on_pushButton_10_clicked()
{
    int Cantidad = Valor.size();
    if (Cantidad < Enteros)
    {
        Valor.append("6");
        ui->lineEdit->setText(Valor);
        this->Cambio();
    }
}

void Calculadora::on_pushButton_14_clicked()
{
    int Cantidad = Valor.size();
    if (Cantidad < Enteros)
    {
        Valor.append("1");
        ui->lineEdit->setText(Valor);
        this->Cambio();
    }
}

void Calculadora::on_pushButton_15_clicked()
{
    int Cantidad = Valor.size();
    if (Cantidad < Enteros)
    {
        Valor.append("2");
        ui->lineEdit->setText(Valor);
        this->Cambio();
    }
}

void Calculadora::on_pushButton_16_clicked()
{
    int Cantidad = Valor.size();
    if (Cantidad < Enteros)
    {
        Valor.append("3");
        ui->lineEdit->setText(Valor);
        this->Cambio();
    }
}

void Calculadora::on_pushButton_20_clicked()
{
    int Cantidad = Valor.size();
    if (Cantidad < Enteros)
    {
        if (ui->lineEdit->text().size() >= 1)
        {
            Valor.append("0");
            ui->lineEdit->setText(Valor);
            this->Cambio();
        }
    }
}

void Calculadora::on_pushButton_27_clicked()
{
    int Cantidad = Valor.size();
    if (Cantidad < Enteros)
    {
        if (ui->lineEdit->text().size() >= 1)
        {
            Valor.append("00");
            ui->lineEdit->setText(Valor);
            this->Cambio();
        }
    }
}

void Calculadora::on_pushButton_21_clicked()
{
    if (!Valor.contains("."))
    {
        int Cantidad = Valor.size();
        if (Cantidad < Enteros)
        {
            if (ui->lineEdit->text().size() < 1)
            {
                Valor.clear();
                Valor.append("0.0");
                ui->lineEdit->setText(Valor);
                this->Cambio();
            }
            else
            {
                Valor.append(".");
                ui->lineEdit->setText(Valor);
                this->Cambio();
            }
        }
    }
}

void Calculadora::on_horizontalSlider_valueChanged(int value)
{
    Enteros = value;
    ui->label->setText(tr("Numero total de digitos: ")+QString::number(Enteros));
    QString Digito = QString::number(Enteros);
    QSqlQuery Miscelanea(db);
    Miscelanea.exec("UPDATE Calculadora SET Digitos='"+Digito+"' WHERE id=2");
}

void Calculadora::Cambio()
{
    if (ValueCambio == 1)
    {
        double Value = ui->lineEdit->text().toFloat();
        if (Valor != "")
        {
            if (Conversion == 0)
            {
                QString Zero;
                double Pesetas = Value*166.386;
                Zero = QString("%L1").arg(Pesetas,0,'f',0);
                ui->lineEdit_2->setText(Zero);
            }
            else if (Conversion == 1)
            {
                QString Zero;
                double Pesetas = Value/166.386;
                Zero = QString("%L1").arg(Pesetas,0,'f',2);
                ui->lineEdit_2->setText(Zero);
            }
        }
        else
            ui->lineEdit_2->setText("");
    }
    else
       ui->lineEdit_2->setText("");
}

void Calculadora::on_horizontalSlider_2_valueChanged(int value)
{
    Decimales = value;
    ui->label_2->setText(tr("Numero total de digitos: ")+QString::number(Decimales));
    QString Decimal = QString::number(Decimales);
    QSqlQuery Miscelanea(db);
    Miscelanea.exec("UPDATE Calculadora SET Decimales='"+Decimal+"' WHERE id=2");
}

void Calculadora::on_pushButton_2_clicked()
{
    Valor.clear();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}

void Calculadora::on_pushButton_30_clicked()
{
    Valor.clear();
    Aritmetica=0;
    //Resultado.clear();
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->textEdit->setText("");
}

void Calculadora::on_pushButton_32_clicked()
{
    if (ui->pushButton_32->isChecked())
    {
        ui->pushButton_33->setChecked(false);
        ValueCambio = 1;
        Conversion = 0;
        this->Cambio();
    }
    if (!ui->pushButton_32->isChecked())
    {
        if (!ui->pushButton_33->isChecked())
            ui->lineEdit_2->setText("");
    }
}

void Calculadora::on_pushButton_33_clicked()
{
    if (ui->pushButton_33->isChecked())
    {
        ui->pushButton_32->setChecked(false);
        ValueCambio = 1;
        Conversion = 1;
        this->Cambio();
    }
    if (!ui->pushButton_33->isChecked())
    {
        if (!ui->pushButton_32->isChecked())
            ui->lineEdit_2->setText("");
    }
}

void Calculadora::on_pushButton_clicked()
{
    QString valor = Valor;
    valor.chop(1);
    Valor.clear();
    Valor = valor;
    ui->lineEdit->setText(valor);
}

void Calculadora::on_pushButton_11_clicked()
{
    if (ui->lineEdit->text() != "")
    {
        if (Aritmetica == 0)
        {
            QString Zero;
            double Pesetas = ui->lineEdit->text().toDouble();
            Zero = QString("%L1").arg(Pesetas,0,'f',Decimales);
            ui->textEdit->append(Zero);
            ui->textEdit->append("÷");
            Aritmetica = ui->lineEdit->text().toDouble();
            Signo = "÷";
            ui->lineEdit->setText("");
            Valor.clear();
        }
        else
        {
            QString Zero, Zero1;
            double anterior = Aritmetica;
            double posterior = ui->lineEdit->text().toDouble();
            Zero = QString("%L1").arg(posterior,0,'f',Decimales);
            ui->textEdit->append(Zero);
            ui->textEdit->append("=");
            double subtotal = anterior/posterior;
            Zero1 = QString("%L1").arg(subtotal,0,'f',Decimales);
            ui->textEdit->append(Zero1);
            ui->textEdit->append("÷");
            Aritmetica = subtotal;
            Signo = "÷";
            ui->lineEdit->setText("");
            Valor.clear();
        }
    }
}

void Calculadora::on_pushButton_34_clicked()
{
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                QString::fromUtf8(tr("<center><b>Reiniciar valores por defecto<b></center><p>"
                "Vas a proceder a reiniciar los valores por defecto de numero de digitos y "
                "decimales.<p>"
                "&iquest;Realizar reinicio de valores?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        QString Digito,Decimal;
        QSqlQuery query(db);
        query.exec("SELECT Digitos,Decimales FROM Calculadora WHERE id=1");
        query.first();
        if (query.isValid())
        {
            Digito=query.value(0).toString();
            Decimal=query.value(1).toString();
        }
        QSqlQuery Miscelanea(db);
        Miscelanea.exec("UPDATE Calculadora SET Digitos='"+Digito+"',Decimales='"+Decimal+"' WHERE id=2");
        Enteros=Digito.toInt();
        Decimales=Decimal.toInt();
        ui->horizontalSlider->setValue(Enteros);
        ui->horizontalSlider_2->setValue(Decimales);
        ui->label->setText(tr("Numero total de digitos: ")+QString::number(Enteros));
        ui->label_2->setText(tr("Numero total de decimales: ")+QString::number(Decimales));
    }
}
