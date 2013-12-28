#include "conversorud.h"
#include "ui_conversorud.h"
#include <QSqlQuery>
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>
#include <QBuffer>
#include <QTest>
#include <QProgressDialog>

ConversorUD::ConversorUD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConversorUD)
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
        Idioma = "Es";
    }
    else if ( cantidad44 == "2")
    {
        Idioma = "En";
    }
    ui->comboBox_11->setCurrentIndex(ui->comboBox_11->findText(tr("Ano")));
    ui->comboBox_12->setCurrentIndex(ui->comboBox_12->findText(tr("Ano")));
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("Ano luz")));
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(tr("Ano luz")));
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("Metro")));
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(tr("Metro")));
    Decimales = 20;
    ui->comboBox->insertSeparator(11);
    ui->comboBox->insertSeparator(25);
    ui->comboBox->insertSeparator(28);
    ui->comboBox_2->insertSeparator(11);
    ui->comboBox_2->insertSeparator(25);
    ui->comboBox_2->insertSeparator(28);
    ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(QString::number(Decimales)));
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_5,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_6,SIGNAL(clicked()),this,SLOT(Comprobar2()));
    connect(ui->radioButton_7,SIGNAL(clicked()),this,SLOT(Comprobar2()));
    connect(ui->radioButton_8,SIGNAL(clicked()),this,SLOT(Comprobar3()));
    connect(ui->radioButton_9,SIGNAL(clicked()),this,SLOT(Comprobar3()));
    ui->radioButton_9->setChecked(true);
    ui->radioButton_6->setChecked(true);
    this->Comprobar2();
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->lineEdit->setFocus();
    ui->radioButton_2->setChecked(true);
    ui->radioButton_3->setChecked(true);
    ui->label_37->setVisible(false);
    AmortizacionP = 0;
    ui->groupBox_12->setVisible(false);
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit_14->installEventFilter(this);
    ui->lineEdit_19->installEventFilter(this);
    ui->lineEdit_21->installEventFilter(this);
    ui->lineEdit_6->installEventFilter(this);
    ui->lineEdit_5->installEventFilter(this);
    ui->lineEdit_25->installEventFilter(this);
    ui->lineEdit_22->installEventFilter(this);
    ui->lineEdit_23->installEventFilter(this);
    ui->lineEdit_26->installEventFilter(this);
    ui->lineEdit_27->installEventFilter(this);
    ui->lineEdit_29->installEventFilter(this);
    ui->lineEdit_31->installEventFilter(this);
    ui->lineEdit_15->installEventFilter(this);
    ui->lineEdit_18->installEventFilter(this);
    ui->lineEdit_17->installEventFilter(this);
    this->installEventFilter(this);
}

ConversorUD::~ConversorUD()
{
    delete ui;
}

void ConversorUD::Valor(QString valor, QString Logs)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
    if (Logs == "S")
        Log = "S";
    else
        Log = "N";
}

void ConversorUD::closeEvent (QCloseEvent *event)
{
    if (CierreTotal == 1)
    {
        emit Cerrar();
        event->accept();
    }
    else
    {
        close();
        event->accept();
    }
}

bool ConversorUD::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor("Conversor");
                return true;
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Escape)
            {
                if (CierreTotal == 0)
                    close();
                else if (CierreTotal == 1)
                    return true;
            }
        }
        return false;
    }
    if (obj == ui->lineEdit)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit->setFocus();
            ui->lineEdit->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_14)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_14->setFocus();
            ui->lineEdit_14->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_19)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_19->setFocus();
            ui->lineEdit_19->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Right)
            {
                if (ui->lineEdit_19->text() != "")
                {
                    ui->lineEdit_21->setFocus();
                    ui->lineEdit_21->selectAll();
                    return true;
                }
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_21)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_21->setFocus();
            ui->lineEdit_21->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Right)
            {
                if (ui->lineEdit_21->text() != "")
                {
                    ui->lineEdit_6->setFocus();
                    ui->lineEdit_6->selectAll();
                    return true;
                }
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Left)
            {
                ui->lineEdit_19->setFocus();
                ui->lineEdit_19->selectAll();
                return true;
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_6)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_6->setFocus();
            ui->lineEdit_6->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Right)
            {
                if (ui->lineEdit_6->text() != "")
                {
                    ui->lineEdit_5->setFocus();
                    ui->lineEdit_5->selectAll();
                    return true;
                }
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Left)
            {
                ui->lineEdit_21->setFocus();
                ui->lineEdit_21->selectAll();
                return true;
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_5)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_5->setFocus();
            ui->lineEdit_5->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Left)
            {
                ui->lineEdit_6->setFocus();
                ui->lineEdit_6->selectAll();
                return true;
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_25)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_25->setFocus();
            ui->lineEdit_25->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Right)
            {
                if (ui->lineEdit_25->text() != "")
                {
                    ui->lineEdit_22->setFocus();
                    ui->lineEdit_22->selectAll();
                    return true;
                }
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_22)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_22->setFocus();
            ui->lineEdit_22->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Right)
            {
                if (ui->lineEdit_22->text() != "")
                {
                    ui->lineEdit_26->setFocus();
                    ui->lineEdit_26->selectAll();
                    return true;
                }
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Left)
            {
                ui->lineEdit_25->setFocus();
                ui->lineEdit_25->selectAll();
                return true;
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_26)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_26->setFocus();
            ui->lineEdit_26->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Right)
            {
                if (ui->lineEdit_26->text() != "")
                {
                    ui->lineEdit_23->setFocus();
                    ui->lineEdit_23->selectAll();
                    return true;
                }
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Left)
            {
                ui->lineEdit_22->setFocus();
                ui->lineEdit_22->selectAll();
                return true;
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_23)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_23->setFocus();
            ui->lineEdit_23->selectAll();
            return true;
        }        
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Left)
            {
                ui->lineEdit_26->setFocus();
                ui->lineEdit_26->selectAll();
                return true;
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_27)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            AmortizacionP = 0;
            QString Value = QuitarMil(ui->lineEdit_27->text());
            ui->lineEdit_27->setText(Value);
            ui->lineEdit_27->setFocus();
            ui->lineEdit_27->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Right)
            {
                if (ui->lineEdit_27->text() != "")
                {
                    AmortizacionP = 1;
                    QString Value = PonerMil(ui->lineEdit_27->text());
                    ui->lineEdit_27->setText(Value);
                    ui->lineEdit_29->setFocus();
                    ui->lineEdit_29->selectAll();
                    return true;
                }
            }
        }
        return false;
    }   
    if (obj == ui->lineEdit_29)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_29->setFocus();
            ui->lineEdit_29->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Left)
            {
                AmortizacionP = 0;
                QString Value = QuitarMil(ui->lineEdit_27->text());
                ui->lineEdit_27->setText(Value);
                ui->lineEdit_27->setFocus();
                ui->lineEdit_27->selectAll();
                return true;
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Right)
            {
                if (ui->lineEdit_29->text() != "")
                {
                    ui->lineEdit_31->setFocus();
                    ui->lineEdit_31->selectAll();
                    return true;
                }
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_31)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_31->setFocus();
            ui->lineEdit_31->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Left)
            {
                ui->lineEdit_29->setFocus();
                ui->lineEdit_29->selectAll();
                return true;
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_15)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_15->setFocus();
            ui->lineEdit_15->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Right)
            {
                if (ui->lineEdit_15->text() != "")
                {
                    ui->lineEdit_18->setFocus();
                    ui->lineEdit_18->selectAll();
                    return true;
                }
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_18)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_18->setFocus();
            ui->lineEdit_18->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Left)
            {
                ui->lineEdit_15->setFocus();
                ui->lineEdit_15->selectAll();
                return true;
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Right)
            {
                if (ui->lineEdit_18->text() != "")
                {
                    ui->lineEdit_17->setFocus();
                    ui->lineEdit_17->selectAll();
                    return true;
                }
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_17)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_17->setFocus();
            ui->lineEdit_17->selectAll();
            return true;
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Left)
            {
                ui->lineEdit_18->setFocus();
                ui->lineEdit_18->selectAll();
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void ConversorUD::on_pushButton_clicked()
{
    if (CierreTotal == 1)
    {
        emit Cerrar();
    }
    else
    {
        close();
    }
}

void ConversorUD::on_comboBox_activated(const QString &arg1)
{
    if (ui->lineEdit->text() == "")
        ui->lineEdit_2->setText("");
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit->text().toFloat();
        double Resto = Referencia(Valor,"Longitud");
        QString Valor1 = ui->comboBox_2->currentText();
        double Resto1 = Referencia(Valor1,"Longitud");
        if (Valor == Valor1)
        {
            double ValorF = Cantidad;
            QString Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
            if (Zero.right(1) == "0")
                Zero = Zero.remove(QRegExp("0+$"));
            if (Idioma == "Es")
            {
                if (Zero.right(1) == ",")
                    Zero = Zero.remove(",");
            }
            else if (Idioma == "En")
            {
                if (Zero.right(1) == ".")
                    Zero = Zero.remove(".");
            }
            ui->lineEdit_2->setText(Zero);
        }
        else
        {
            double ValorF = (Resto/Resto1)*Cantidad;
            QString Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
            if (Zero.right(1) == "0")
                Zero = Zero.remove(QRegExp("0+$"));
            if (Idioma == "Es")
            {
                if (Zero.right(1) == ",")
                    Zero = Zero.remove(",");
            }
            else if (Idioma == "En")
            {
                if (Zero.right(1) == ".")
                    Zero = Zero.remove(".");
            }
            ui->lineEdit_2->setText(Zero);
        }
    }
    Reprobar("Longitud");
}

void ConversorUD::on_lineEdit_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit->text() == "")
                ui->lineEdit_2->setText("");
            else
            {
                QString Valor = ui->comboBox->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Longitud");
                QString Valor1 = ui->comboBox_2->currentText();
                double Resto1 = Referencia(Valor1,"Longitud");
                if (Valor == Valor1)
                {
                    double ValorF = Cantidad;
                    QString Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
                    if (Zero.right(1) == "0")
                        Zero = Zero.remove(QRegExp("0+$"));
                    if (Idioma == "Es")
                    {
                        if (Zero.right(1) == ",")
                            Zero = Zero.remove(",");
                    }
                    else if (Idioma == "En")
                    {
                        if (Zero.right(1) == ".")
                            Zero = Zero.remove(".");
                    }
                    ui->lineEdit_2->setText(Zero);
                }
                else
                {
                    double ValorF = (Resto/Resto1)*Cantidad;
                    QString Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
                    if (Zero.right(1) == "0")
                        Zero = Zero.remove(QRegExp("0+$"));
                    if (Idioma == "Es")
                    {
                        if (Zero.right(1) == ",")
                            Zero = Zero.remove(",");
                    }
                    else if (Idioma == "En")
                    {
                        if (Zero.right(1) == ".")
                            Zero = Zero.remove(".");
                    }
                    ui->lineEdit_2->setText(Zero);
                }
            }
            Reprobar("Longitud");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit->setFocus();
            QString Resto = ui->lineEdit->text();
            Resto.chop(1);
            ui->lineEdit->setText(Resto);
            return;
        }
    }
}
void ConversorUD::on_comboBox_2_activated(const QString &arg1)
{
    if (ui->lineEdit->text() == "")
        ui->lineEdit_2->setText("");
    else
    {
        QString Valor = ui->comboBox->currentText();
        double Cantidad = ui->lineEdit->text().toFloat();
        double Resto = Referencia(Valor,"Longitud");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Longitud");
        if (Valor == Valor1)
        {
            double ValorF = Cantidad;
            QString Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
            if (Zero.right(1) == "0")
                Zero = Zero.remove(QRegExp("0+$"));
            if (Idioma == "Es")
            {
                if (Zero.right(1) == ",")
                    Zero = Zero.remove(",");
            }
            else if (Idioma == "En")
            {
                if (Zero.right(1) == ".")
                    Zero = Zero.remove(".");
            }
            ui->lineEdit_2->setText(Zero);
        }
        else
        {
            double ValorF = (Resto/Resto1)*Cantidad;
            QString Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
            if (Zero.right(1) == "0")
                Zero = Zero.remove(QRegExp("0+$"));
            if (Idioma == "Es")
            {
                if (Zero.right(1) == ",")
                    Zero = Zero.remove(",");
            }
            else if (Idioma == "En")
            {
                if (Zero.right(1) == ".")
                    Zero = Zero.remove(".");
            }
            ui->lineEdit_2->setText(Zero);
        }
    }
    Reprobar("Longitud");
}

double ConversorUD::Referencia(QString Value,QString Tipo)
{
    double Valor;
    if (Tipo == "Longitud")
    {
        if (Value == tr("Angstrom"))
            Valor = 0.0000000001;
        if (Value == tr("Nanometro"))
            Valor = 0.000000001;
        if (Value == tr("Micrometro"))
            Valor = 0.000001;
        if (Value == tr("Milimetro"))
            Valor = 0.001;
        if (Value == tr("Centimetro"))
            Valor = 0.01;
        if (Value == tr("Decimetro"))
            Valor = 0.1;
        if (Value == tr("Metro"))
            Valor = 1;
        if (Value == tr("Decametro"))
            Valor = 10;
        if (Value == tr("Hectometro"))
            Valor = 100;
        if (Value == tr("Kilometro"))
            Valor = 1000;
        if (Value == tr("Miriametro"))
            Valor = 10000;
        if (Value == tr("Legua"))
            Valor = 4828.032;
        if (Value == tr("Milla"))
            Valor = 1609.344;
        if (Value == tr("Estadio"))
            Valor = 201.168;
        if (Value == tr("Cadena"))
            Valor = 20.1168;
        if (Value == tr("Barra"))
            Valor = 5.0292;
        if (Value == tr("Yarda"))
            Valor = 0.9144;
        if (Value == tr("Pie"))
            Valor = 0.3048;
        if (Value == tr("Link"))
            Valor = 0.201168;
        if (Value == tr("Mano"))
            Valor = 0.1016;
        if (Value == tr("Pulgada"))
            Valor = 0.0254;
        if (Value == tr("Linea"))
            Valor = 0.00254;
        if (Value == tr("Mil"))
            Valor = 0.0000254;
        if (Value == tr("Thou"))
            Valor = 0.0000254;
        if (Value == tr("Milla nautica"))
            Valor = 1852;
        if (Value == tr("Braza"))
            Valor = 1.8288;
        if (Value == tr("Parsec"))
            Valor = 30857000000000000;
        if (Value == tr("Ano luz"))
            Valor = 9454254955488000;
        if (Value == tr("Unidad astronomica"))
            Valor = 147597870610;
        if (Value == tr("Minuto luz"))
            Valor = 17987547480;
        if (Value == tr("Segundo luz"))
            Valor = 299792458;
    }
    return Valor;

//    units["in2_ref"] = 0.00064516;
//    units["ref_in2"] = 1550;
//    names["in2"] = "Pulgada cuadrada";
//    units["ac_ref"] = 4046.86;
//    units["ref_ac"] = 0.000247;
//    names["ac"] = "Acre";
//    units["cm2_ref"] = 0.0001;
//    units["ref_cm2"] = 10000;
//    names["cm2"] = "Centímetro cuadrado";
//    units["ft2_ref"] = 0.092903;
//    units["ref_ft2"] = 10.7639;
//    names["ft2"] = "Pie cuadrado";
//    units["yd2_ref"] = 0.836127;
//    units["ref_yd2"] = 1.19599;
//    names["yd2"] = "Yarda cuadrada";
//    units["m2_ref"] = 1;
//    units["ref_m2"] = 1;
//    names["m2"] = "Metro cuadrado";
//    units["h2_ref"] = 10000;
//    units["ref_h2"] = 0.0001;
//    names["h2"] = "Hectárea";
//    units["km2_ref"] = 1000000;
//    units["ref_km2"] = 0.000001;
//    names["km2"] = "kilómetro cuadrado";
//    units["mi2_ref"] = 2590000;
//    units["ref_mi2"] = 0.0000003861;
//    names["mi2"] = "Milla cuadrada";
//    units["kg_ref"] = 1;
//    units["ref_kg"] = 1;
//    names["kg"] = "Kilogramo";
//    units["t_ref"] = 1000;
//    units["ref_t"] = 0.001;
//    names["t"] = "Tonelada Métrica";
//    units["g_ref"] = 0.001;
//    units["ref_g"] = 1000;
//    names["g"] = "Gramo";
//    units["mg_ref"] = 0.000001;
//    units["ref_mg"] = 1000000;
//    names["mg"] = "Miligramo";
//    units["mcg_ref"] = 0.000000001;
//    units["ref_mcg"] = 1000000000;
//    names["mcg"] = "Microgramo";
//    units["c_ref"] = 1;
//    units["ref_c"] = 1;
//    names["c"] = "Grado Celsius";
//    units["f_ref"] = 104;
//    units["ref_f"] = 0.0096154;
//    names["f"] = "Grado Fahrenheit";
//    units["k_ref"] = 1.27415;
//    units["ref_k"] = 0.785;
//    names["k"] = "Grado Kelvin";
//    units["tl_ref"] = 1016.05;
//    units["ref_tl"] = 0.000984207;
//    names["tl"] = "Tonelada Larga";
//    units["tc_ref"] = 907.185;
//    units["ref_tc"] = 0.00110231;
//    names["tc"] = "Tonelada Corta";
//    units["st_ref"] = 6.35029;
//    units["ref_st"] = 0.157473;
//    names["st"] = "Piedra";
//    units["lb_ref"] = 0.453592;
//    units["ref_lb"] = 2.20462;
//    names["lb"] = "Libra";
//    units["oz_ref"] = 0.0283495;
//    units["ref_oz"] = 35.274;
//    names["oz"] = "Onza";
//    units["ns_ref"] = 0.000000001;
//    units["ref_ns"] = 1000000000;
//    names["ns"] = "Nanosegundo";
//    units["micros_ref"] = 0.000001;
//    units["ref_micros"] = 1000000;
//    names["micros"] = "Microsegundo";
//    units["ms_ref"] = 0.001;
//    units["ref_ms"] = 1000;
//    names["ms"] = "Milisegundo";
//    units["s_ref"] = 1;
//    units["ref_s"] = 1;
//    names["s"] = "Segundo";
//    units["min_ref"] = 60;
//    units["ref_min"] = 0.0166667;
//    names["min"] = "Minuto";
//    units["hr_ref"] = 3600;
//    units["ref_hr"] = 0.000277778;
//    names["hr"] = "Hora";
//    units["d_ref"] = 86400;
//    units["ref_d"] = 0.0000115741;
//    names["d"] = "Día";
//    units["semana_ref"] = 604800;
//    units["ref_semana"] = 0.0000016534;
//    names["semana"] = "Semana";
//    units["mes_ref"] = 2629750;
//    units["ref_mes"] = 0.00000038027;
//    names["mes"] = "Mes";
//    units["ano_ref"] = 31556900;
//    units["ref_ano"] = 0.000000031689;
//    names["ano"] = "Ano";
}

void ConversorUD::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
    ui->lineEdit_10->setText("");
    ui->lineEdit_11->setText("");
    ui->lineEdit_12->setText("");
    ui->lineEdit_13->setText("");
    ui->lineEdit_14->setText("");
    ui->lineEdit_15->setText("");
    ui->lineEdit_16->setText("");
    ui->lineEdit_17->setText("");
    ui->lineEdit_18->setText("");
    ui->lineEdit_19->setText("");
    ui->lineEdit_20->setText("");
    ui->lineEdit_21->setText("");
    ui->lineEdit_22->setText("");
    ui->lineEdit_23->setText("");
    ui->lineEdit_24->setText("");
    ui->lineEdit_25->setText("");
    ui->lineEdit_26->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    AmortizacionP = 0;
    ui->lineEdit_27->setText("");
    ui->lineEdit_28->setText("");
    ui->lineEdit_29->setText("");
    ui->lineEdit_30->setText("");
    ui->lineEdit_31->setText("");
    ui->lineEdit_32->setText("");
    ui->lineEdit_33->setText("");
    ui->lineEdit_34->setText("");
    ui->lineEdit_35->setText("");
    int Borrado, x;
    Borrado = ui->tableWidget->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
}

void ConversorUD::on_lineEdit_returnPressed()
{
    ui->lineEdit->setFocus();
    ui->lineEdit->selectAll();
}

void ConversorUD::on_comboBox_3_activated(const QString &arg1)
{
    Decimales = arg1.toInt();
    if (ui->lineEdit->text() == "")
        ui->lineEdit_2->setText("");
    else
    {
        QString Valor = ui->comboBox->currentText();
        double Cantidad = ui->lineEdit->text().toFloat();
        double Resto = Referencia(Valor,"Longitud");
        QString Valor1 = ui->comboBox_2->currentText();
        double Resto1 = Referencia(Valor1,"Longitud");
        if (Valor == Valor1)
        {
            double ValorF = Cantidad;
            QString Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
            if (Zero.right(1) == "0")
                Zero = Zero.remove(QRegExp("0+$"));
            if (Idioma == "Es")
            {
                if (Zero.right(1) == ",")
                    Zero = Zero.remove(",");
            }
            else if (Idioma == "En")
            {
                if (Zero.right(1) == ".")
                    Zero = Zero.remove(".");
            }
            ui->lineEdit_2->setText(Zero);
        }
        else
        {
            double ValorF = (Resto/Resto1)*Cantidad;
            QString Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
            if (Zero.right(1) == "0")
                Zero = Zero.remove(QRegExp("0+$"));
            if (Idioma == "Es")
            {
                if (Zero.right(1) == ",")
                    Zero = Zero.remove(",");
            }
            else if (Idioma == "En")
            {
                if (Zero.right(1) == ".")
                    Zero = Zero.remove(".");
            }
            ui->lineEdit_2->setText(Zero);
        }
    }
    if (ui->label_14->text().contains(tr("Distancia o Longitud")))
        Reprobar("Longitud");
}

void ConversorUD::Reprobar(QString Tipo)
{
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    if (Tipo == "Longitud")
    {
        QString Value = ui->comboBox->currentText();
        double Cantidad = ui->lineEdit->text().toFloat();
        double Resto = Referencia(Value,"Longitud");
        Unidad(Resto,0.0000000001,Cantidad,tr("Angstrom"),"Longitud");
        Unidad1(Resto,0.0000000001,Cantidad,tr("Angstrom"),"Longitud");
        Unidad(Resto,0.000000001,Cantidad,tr("Nanometro"),"Longitud");
        Unidad1(Resto,0.000000001,Cantidad,tr("Nanometro"),"Longitud");
        Unidad(Resto,0.000001,Cantidad,tr("Micrometro"),"Longitud");
        Unidad1(Resto,0.00001,Cantidad,tr("Micrometro"),"Longitud");
        Unidad(Resto,0.001,Cantidad,tr("Milimetro"),"Longitud");
        Unidad1(Resto,0.001,Cantidad,tr("Milimetro"),"Longitud");
        Unidad(Resto,0.01,Cantidad,tr("Centimetro"),"Longitud");
        Unidad1(Resto,0.01,Cantidad,tr("Centimetro"),"Longitud");
        Unidad(Resto,0.1,Cantidad,tr("Decimetro"),"Longitud");
        Unidad1(Resto,0.1,Cantidad,tr("Decimetro"),"Longitud");
        Unidad(Resto,1,Cantidad,tr("Metro"),"Longitud");
        Unidad1(Resto,1,Cantidad,tr("Metro"),"Longitud");
        Unidad(Resto,10,Cantidad,tr("Decametro"),"Longitud");
        Unidad1(Resto,10,Cantidad,tr("Decametro"),"Longitud");
        Unidad(Resto,100,Cantidad,tr("Hectometro"),"Longitud");
        Unidad1(Resto,100,Cantidad,tr("Hectometro"),"Longitud");
        Unidad(Resto,1000,Cantidad,tr("Kilometro"),"Longitud");
        Unidad1(Resto,1000,Cantidad,tr("Kilometro"),"Longitud");
        Unidad(Resto,10000,Cantidad,tr("Miriametro"),"Longitud");
        Unidad1(Resto,10000,Cantidad,tr("Miriametro"),"Longitud");
        Unidad(Resto,4828.0320,Cantidad,tr("Legua"),"Longitud");
        Unidad1(Resto,0.001,Cantidad,tr("Legua"),"Longitud");
        Unidad(Resto,1609.344,Cantidad,tr("Milla"),"Longitud");
        Unidad1(Resto,1609.344,Cantidad,tr("Milla"),"Longitud");
        Unidad(Resto,201.168,Cantidad,tr("Estadio"),"Longitud");
        Unidad1(Resto,201.168,Cantidad,tr("Estadio"),"Longitud");
        Unidad(Resto,20.1168,Cantidad,tr("Cadena"),"Longitud");
        Unidad1(Resto,20.1168,Cantidad,tr("Cadena"),"Longitud");
        Unidad(Resto,5.0292,Cantidad,tr("Barra"),"Longitud");
        Unidad1(Resto,5.0292,Cantidad,tr("Barra"),"Longitud");
        Unidad(Resto,0.9144,Cantidad,tr("Yarda"),"Longitud");
        Unidad1(Resto,0.9144,Cantidad,tr("Yarda"),"Longitud");
        Unidad(Resto,0.3048,Cantidad,tr("Pie"),"Longitud");
        Unidad1(Resto,0.3048,Cantidad,tr("Pie"),"Longitud");
        Unidad(Resto,0.201168,Cantidad,tr("Link"),"Longitud");
        Unidad1(Resto,0.201168,Cantidad,tr("Link"),"Longitud");
        Unidad(Resto,0.1016,Cantidad,tr("Mano"),"Longitud");
        Unidad1(Resto,0.1016,Cantidad,tr("Mano"),"Longitud");
        Unidad(Resto,0.0254,Cantidad,tr("Pulgada"),"Longitud");
        Unidad1(Resto,0.0254,Cantidad,tr("Pulgada"),"Longitud");
        Unidad(Resto,0.00254,Cantidad,tr("Linea"),"Longitud");
        Unidad1(Resto,0.00254,Cantidad,tr("Linea"),"Longitud");
        Unidad(Resto,0.0000254,Cantidad,tr("Mil"),"Longitud");
        Unidad1(Resto,0.0000254,Cantidad,tr("Mil"),"Longitud");
        Unidad(Resto,0.0000254,Cantidad,tr("Thou"),"Longitud");
        Unidad1(Resto,0.0000254,Cantidad,tr("Thou"),"Longitud");
        Unidad(Resto,1852,Cantidad,tr("Milla nautica"),"Longitud");
        Unidad1(Resto,1852,Cantidad,tr("Milla nautica"),"Longitud");
        Unidad(Resto,1.8288,Cantidad,tr("Braza"),"Longitud");
        Unidad1(Resto,1.8288,Cantidad,tr("Braza"),"Longitud");
        Unidad(Resto,30857000000000000,Cantidad,tr("Parsec"),"Longitud");
        Unidad1(Resto,30857000000000000,Cantidad,tr("Parsec"),"Longitud");
        Unidad(Resto,9454254955488000,Cantidad,tr("Ano luz"),"Longitud");
        Unidad1(Resto,9454254955488000,Cantidad,tr("Ano luz"),"Longitud");
        Unidad(Resto,147597870610,Cantidad,tr("Unidad astronomica"),"Longitud");
        Unidad1(Resto,147597870610,Cantidad,tr("Unidad astronomica"),"Longitud");
        Unidad(Resto,17987547480,Cantidad,tr("Minuto luz"),"Longitud");
        Unidad1(Resto,17987547480,Cantidad,tr("Minuto luz"),"Longitud");
        Unidad(Resto,299792458,Cantidad,tr("Segundo luz"),"Longitud");
        Unidad1(Resto,299792458,Cantidad,tr("Segundo luz"),"Longitud");
        ui->label_14->setText(tr("Distancia o Longitud: Convertir a...")+ui->comboBox->currentText()+"");
        ui->label_15->setText(tr("Distancia o Longitud: Convertir de...")+ui->comboBox->currentText()+"");
    }
}

void ConversorUD::Unidad(double Value, double Value1, double Cantidad, QString Nombre, QString Base)
{
    if (Base == "Longitud")
    {
        if (ui->lineEdit->text() != "")
        {
            QString Zero;
            if (ui->comboBox->currentText() == Base)
            {
                double ValorF = Cantidad;
                Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
                if (Zero.right(1) == "0")
                    Zero = Zero.remove(QRegExp("0+$"));
                if (Idioma == "Es")
                {
                    if (Zero.right(1) == ",")
                        Zero = Zero.remove(",");
                }
                else if (Idioma == "En")
                {
                    if (Zero.right(1) == ".")
                        Zero = Zero.remove(".");
                }
                ui->textEdit->append(""+Zero+" "+ui->comboBox->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,Decimales,'f',Decimales);
                if (Valor.right(1) == "0")
                    Valor = Valor.remove(QRegExp("0+$"));
                if (Idioma == "Es")
                {
                    if (Valor.right(1) == ",")
                        Valor = Valor.remove(",");
                }
                else if (Idioma == "En")
                {
                    if (Valor.right(1) == ".")
                        Valor = Valor.remove(".");
                }
                Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
                if (Zero.right(1) == "0")
                    Zero = Zero.remove(QRegExp("0+$"));
                if (Idioma == "Es")
                {
                    if (Zero.right(1) == ",")
                        Zero = Zero.remove(",");
                }
                else if (Idioma == "En")
                {
                    if (Zero.right(1) == ".")
                        Zero = Zero.remove(".");
                }
                ui->textEdit->append(""+Valor+" "+ui->comboBox->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
}
void ConversorUD::Unidad1(double Value, double Value1, double Cantidad, QString Nombre, QString Base)
{
    if (Base == "Longitud")
    {
        if (ui->lineEdit->text() != "")
        {
            QString Zero;
            if (ui->comboBox->currentText() == Base)
            {
                double ValorF = Cantidad;
                Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
                if (Zero.right(1) == "0")
                    Zero = Zero.remove(QRegExp("0+$"));
                if (Idioma == "Es")
                {
                    if (Zero.right(1) == ",")
                        Zero = Zero.remove(",");
                }
                else if (Idioma == "En")
                {
                    if (Zero.right(1) == ".")
                        Zero = Zero.remove(".");
                }
                ui->textEdit->append(""+Zero+" "+ui->comboBox->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,Decimales,'f',Decimales);
                if (Valor.right(1) == "0")
                    Valor = Valor.remove(QRegExp("0+$"));
                if (Idioma == "Es")
                {
                    if (Valor.right(1) == ",")
                        Valor = Valor.remove(",");
                }
                else if (Idioma == "En")
                {
                    if (Valor.right(1) == ".")
                        Valor = Valor.remove(".");
                }
                Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
                if (Zero.right(1) == "0")
                    Zero = Zero.remove(QRegExp("0+$"));
                if (Idioma == "Es")
                {
                    if (Zero.right(1) == ",")
                        Zero = Zero.remove(",");
                }
                else if (Idioma == "En")
                {
                    if (Zero.right(1) == ".")
                        Zero = Zero.remove(".");
                }
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
}

void ConversorUD::on_lineEdit_14_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,0);
        if (Valor == "No")
        {
            if (ui->lineEdit_14->text() == "")
                ui->lineEdit_13->setText("");
            else
            {
                double Valor;
                Valor = arg1.toFloat()/23;
                int Resto = Valor;
                int Calculo = Resto*23;
                int Diferencia = arg1.toInt()-Calculo;
                QString Resultado = CalculoDNI(Diferencia);
                QString Letra = QString("%L1").arg(Resultado);
                ui->lineEdit_13->setText(Letra);
            }
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_14->setFocus();
            QString Resto = ui->lineEdit_14->text();
            Resto.chop(1);
            ui->lineEdit_14->setText(Resto);
            return;
        }
    }
}

QString ConversorUD::CalculoDNI(int Numero)
{
    QString Letra;
    if (Numero == 0)
        Letra = "T";
    if (Numero == 1)
        Letra = "R";
    if (Numero == 2)
        Letra = "W";
    if (Numero == 3)
        Letra = "A";
    if (Numero == 4)
        Letra = "G";
    if (Numero == 5)
        Letra = "M";
    if (Numero == 6)
        Letra = "Y";
    if (Numero == 7)
        Letra = "F";
    if (Numero == 8)
        Letra = "P";
    if (Numero == 9)
        Letra = "D";
    if (Numero == 10)
        Letra = "X";
    if (Numero == 11)
        Letra = "B";
    if (Numero == 12)
        Letra = "N";
    if (Numero == 13)
        Letra = "J";
    if (Numero == 14)
        Letra = "Z";
    if (Numero == 15)
        Letra = "S";
    if (Numero == 16)
        Letra = "Q";
    if (Numero == 17)
        Letra = "V";
    if (Numero == 18)
        Letra = "H";
    if (Numero == 19)
        Letra = "L";
    if (Numero == 20)
        Letra = "C";
    if (Numero == 21)
        Letra = "K";
    if (Numero == 22)
        Letra = "E";
    return Letra;
}

void ConversorUD::on_lineEdit_14_returnPressed()
{
    ui->lineEdit_14->setFocus();
    ui->lineEdit_14->selectAll();
}

void ConversorUD::on_lineEdit_5_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,0);
        if (Valor == "No")
        {
            if (ui->lineEdit_6->text() == "")
            {
                ui->lineEdit_5->setText("");
                ui->lineEdit_6->setFocus();
            }
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_5->setFocus();
            QString Resto = ui->lineEdit_5->text();
            Resto.chop(1);
            ui->lineEdit_5->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_lineEdit_19_returnPressed()
{
    if (ui->lineEdit_19->text() != "")
    {
        ui->lineEdit_21->setFocus();
        ui->lineEdit_21->selectAll();
    }
    else
    {
        ui->lineEdit_19->setFocus();
        ui->lineEdit_19->selectAll();
    }
}

void ConversorUD::on_lineEdit_21_returnPressed()
{
    if (ui->lineEdit_21->text() != "")
    {
        ui->lineEdit_6->setFocus();
        ui->lineEdit_6->selectAll();
    }
    else
    {
        ui->lineEdit_21->setFocus();
        ui->lineEdit_21->selectAll();
    }
}

void ConversorUD::on_lineEdit_6_returnPressed()
{
    if (ui->lineEdit_6->text() != "")
    {
        ui->lineEdit_5->setFocus();
        ui->lineEdit_5->selectAll();
    }
    else
    {
        ui->lineEdit_6->setFocus();
        ui->lineEdit_6->selectAll();
    }
}

void ConversorUD::on_lineEdit_5_returnPressed()
{
    if (ui->lineEdit_5->text() == "")
        ui->lineEdit_20->setText("");
    else
    {
        if (ui->lineEdit_6->text() == "")
        {
            ui->lineEdit_5->setText("");
            ui->lineEdit_6->setFocus();
        }
        else
        {
            QString Cantidad;
            if (ui->radioButton->isChecked())
            {
                Cantidad.append(ui->lineEdit_21->text());
                Cantidad.append(ui->lineEdit_6->text());
                Cantidad.append(ui->lineEdit_5->text());
                if (Cantidad.size() != 9)
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("Deben haber 9 digitos (sin contar el ultimo digito) para utilizar la opcion de ISBN10.<P>Comprueba los digitos."));
                    m.exec();
                    return;
                }
                else
                {
                    int Valor1,Valor2,Valor3,Valor4,Valor5,Valor6,Valor7,Valor8,Valor9,VTotal,VDivT,Digito;
                    QStringList Total = Cantidad.split("");
                    for(int i=1;i<Total.count();i++)
                    {
                        if (i == 1)
                        {
                           Valor1 = Total.value(i).toInt()*1;
                        }
                        if (i == 2)
                        {
                           Valor2 = Total.value(i).toInt()*2;
                        }
                        if (i == 3)
                        {
                           Valor3 = Total.value(i).toInt()*3;
                        }
                        if (i == 4)
                        {
                           Valor4 = Total.value(i).toInt()*4;
                        }
                        if (i == 5)
                        {
                           Valor5 = Total.value(i).toInt()*5;
                        }
                        if (i == 6)
                        {
                           Valor6 = Total.value(i).toInt()*6;
                        }
                        if (i == 7)
                        {
                           Valor7 = Total.value(i).toInt()*7;
                        }
                        if (i == 8)
                        {
                           Valor8 = Total.value(i).toInt()*8;
                        }
                        if (i == 9)
                        {
                           Valor9 = Total.value(i).toInt()*9;
                        }
                    }
                    VTotal = Valor1+Valor2+Valor3+Valor4+Valor5+Valor6+Valor7+Valor8+Valor9;
                    VDivT = VTotal/11;
                    Digito = VTotal - (VDivT*11);
                    if (Digito <= 9)
                    {
                        ui->lineEdit_20->setText(QString::number(Digito));
                    }
                    else if (Digito == 10)
                    {
                        ui->lineEdit_20->setText("X");
                    }
                }
            }
            else if (ui->radioButton_2->isChecked())
            {
                Cantidad.append(ui->lineEdit_19->text());
                Cantidad.append(ui->lineEdit_21->text());
                Cantidad.append(ui->lineEdit_6->text());
                Cantidad.append(ui->lineEdit_5->text());
                if (Cantidad.size() != 12)
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("Deben haber 12 digitos (sin contar el ultimo digito) para utilizar la opcion de ISBN13.<P>Comprueba los digitos."));
                    m.exec();
                    return;
                }
                else
                {
                    int Valor1,Valor2,Valor3,Valor4,Valor5,Valor6,Valor7,Valor8,Valor9,Valor10,Valor11,Valor12,VTotal,VDivT,Digit,Digito;
                    QStringList Total = Cantidad.split("");
                    for(int i=1;i<Total.count();i++)
                    {
                        if (i == 1)
                        {
                           Valor1 = Total.value(i).toInt()*1;
                        }
                        if (i == 2)
                        {
                           Valor2 = Total.value(i).toInt()*3;
                        }
                        if (i == 3)
                        {
                           Valor3 = Total.value(i).toInt()*1;
                        }
                        if (i == 4)
                        {
                           Valor4 = Total.value(i).toInt()*3;
                        }
                        if (i == 5)
                        {
                           Valor5 = Total.value(i).toInt()*1;
                        }
                        if (i == 6)
                        {
                           Valor6 = Total.value(i).toInt()*3;
                        }
                        if (i == 7)
                        {
                           Valor7 = Total.value(i).toInt()*1;
                        }
                        if (i == 8)
                        {
                           Valor8 = Total.value(i).toInt()*3;
                        }
                        if (i == 9)
                        {
                           Valor9 = Total.value(i).toInt()*1;
                        }
                        if (i == 10)
                        {
                           Valor10 = Total.value(i).toInt()*3;
                        }
                        if (i == 11)
                        {
                           Valor11 = Total.value(i).toInt()*1;
                        }
                        if (i == 12)
                        {
                           Valor12 = Total.value(i).toInt()*3;
                        }
                    }
                    VTotal = Valor1+Valor2+Valor3+Valor4+Valor5+Valor6+Valor7+Valor8+Valor9+Valor10+Valor11+Valor12;
                    VDivT = VTotal/10;
                    Digit = VTotal - (VDivT*10);
                    Digito = 10-Digit;
                    ui->lineEdit_20->setText(QString::number(Digito));
                }
            }
        }
    }
}

void ConversorUD::on_lineEdit_21_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,0);
        if (Valor == "No")
        {
            if (ui->lineEdit_19->isVisible())
            {
                if (ui->lineEdit_19->text() == "")
                {
                    ui->lineEdit_21->setText("");
                    ui->lineEdit_19->setFocus();
                }
            }
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_21->setFocus();
            QString Resto = ui->lineEdit_21->text();
            Resto.chop(1);
            ui->lineEdit_21->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_lineEdit_6_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,0);
        if (Valor == "No")
        {
            if (ui->lineEdit_21->text() == "")
            {
                ui->lineEdit_6->setText("");
                ui->lineEdit_21->setFocus();
            }
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_6->setFocus();
            QString Resto = ui->lineEdit_6->text();
            Resto.chop(1);
            ui->lineEdit_6->setText(Resto);
            return;
        }
    }
}

void ConversorUD::Comprobar()
{
    if (ui->radioButton->isChecked())
    {
        ui->lineEdit_19->setVisible(false);
        ui->label_22->setVisible(false);
        ui->lineEdit_19->setText("");
        ui->lineEdit_21->setText("");
        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_20->setText("");
    }
    if (ui->radioButton_2->isChecked())
    {
        ui->lineEdit_19->setVisible(true);
        ui->label_22->setVisible(true);
        ui->lineEdit_19->setText("");
        ui->lineEdit_21->setText("");
        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_20->setText("");
    }
}

void ConversorUD::Comprobar1()
{
    if (ui->radioButton_3->isChecked())
    {
        ui->lineEdit_24->setVisible(true);
        ui->label_27->setVisible(true);
        ui->lineEdit_23->setMaxLength(3);
        ui->label_37->setVisible(false);
    }
    if (ui->radioButton_4->isChecked())
    {
        ui->lineEdit_24->setVisible(false);
        ui->label_27->setVisible(false);
        ui->lineEdit_23->setMaxLength(4);
        ui->label_37->setVisible(false);
    }
    if (ui->radioButton_5->isChecked())
    {
        ui->lineEdit_24->setVisible(false);
        ui->label_27->setVisible(false);
        ui->lineEdit_23->setMaxLength(4);
        ui->label_37->setVisible(true);
    }
}

void ConversorUD::on_lineEdit_25_returnPressed()
{
    if (ui->lineEdit_25->text().size() < 4)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Deben haber 4 digitos en este campo."));
        m.exec();
        return;
    }
    if (ui->lineEdit_25->text() != "")
    {
        ui->lineEdit_22->setFocus();
        ui->lineEdit_22->selectAll();
    }
    else
    {
        ui->lineEdit_25->setFocus();
        ui->lineEdit_25->selectAll();
    }
}

void ConversorUD::on_lineEdit_22_returnPressed()
{
    if (ui->lineEdit_22->text().size() < 4)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Deben haber 4 digitos en este campo."));
        m.exec();
        return;
    }
    if (ui->lineEdit_22->text() != "")
    {
        ui->lineEdit_26->setFocus();
        ui->lineEdit_26->selectAll();
    }
    else
    {
        ui->lineEdit_22->setFocus();
        ui->lineEdit_22->selectAll();
    }
}

void ConversorUD::on_lineEdit_26_returnPressed()
{
    if (ui->lineEdit_26->text().size() < 4)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Deben haber 4 digitos en este campo."));
        m.exec();
        return;
    }
    if (ui->lineEdit_26->text() != "")
    {
        ui->lineEdit_23->setFocus();
        ui->lineEdit_23->selectAll();
    }
    else
    {
        ui->lineEdit_26->setFocus();
        ui->lineEdit_26->selectAll();
    }
}

void ConversorUD::on_lineEdit_23_returnPressed()
{
    if (ui->lineEdit_23->text() == "")
        ui->lineEdit_24->setText("");
    else
    {
        int digit, digit1;
        QString Cantidad;
        if (ui->lineEdit_24->isVisible())
        {
            digit = 3;
            digit1 = 15;
        }
        else
        {
            digit = 4;
            digit1 = 16;
        }
        if (ui->lineEdit_23->text().size() < digit)
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Deben haber 4 digitos en este campo."));
            m.exec();
            return;
        }
        Cantidad.append(ui->lineEdit_25->text());
        Cantidad.append(ui->lineEdit_22->text());
        Cantidad.append(ui->lineEdit_26->text());
        Cantidad.append(ui->lineEdit_23->text());
        if (Cantidad.size() != digit1)
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Deben haber 15 digitos (sin contar el ultimo digito) para poder continuar.<P>Comprueba los digitos introducidos."));
            m.exec();
            return;
        }
        else
        {
            if (ui->radioButton_3->isChecked())
            {
                int Valor1,Valor2,Valor3,Valor4,Valor5,Valor6,Valor7,Valor8,Valor9,Valor10,Valor11,Valor12,Valor13,Valor14,Valor15,VTotal,VDivT,Digito;
                QStringList Total = Cantidad.split("");
                for(int i=1;i<Total.count();i++)
                {
                    if (i == 1)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor1 = Total.value(i).toInt()*2;
                           if (Valor1 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor1).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor1 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_25->setFocus();
                           return;
                        }
                    }
                    if (i == 2)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor2 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_25->setFocus();
                           return;
                        }
                    }
                    if (i == 3)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor3 = Total.value(i).toInt()*2;
                           if (Valor3 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor3).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor3 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_25->setFocus();
                           return;
                        }
                    }
                    if (i == 4)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor4 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_25->setFocus();
                           return;
                        }
                    }
                    if (i == 5)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor5 = Total.value(i).toInt()*2;
                           if (Valor5 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor5).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor5 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_22->setFocus();
                           return;
                        }
                    }
                    if (i == 6)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor6 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_22->setFocus();
                           return;
                        }
                    }
                    if (i == 7)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor7 = Total.value(i).toInt()*2;
                           if (Valor7 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor7).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor7 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_22->setFocus();
                           return;
                        }
                    }
                    if (i == 8)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor8 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_22->setFocus();
                           return;
                        }
                    }
                    if (i == 9)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor9 = Total.value(i).toInt()*2;
                           if (Valor9 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor9).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor9 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_26->setFocus();
                           return;
                        }
                    }
                    if (i == 10)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor10 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_26->setFocus();
                           return;
                        }
                    }
                    if (i == 11)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor11 = Total.value(i).toInt()*2;
                           if (Valor11 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor11).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor11 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_26->setFocus();
                           return;
                        }
                    }
                    if (i == 12)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor12 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_26->setFocus();
                           return;
                        }
                    }
                    if (i == 13)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor13 = Total.value(i).toInt()*2;
                           if (Valor13 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor13).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor13 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_23->setFocus();
                           return;
                        }
                    }
                    if (i == 14)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor14 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_23->setFocus();
                           return;
                        }
                    }
                    if (i == 15)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor15 = Total.value(i).toInt()*2;
                           if (Valor15 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor15).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor15 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_23->setFocus();
                           return;
                        }
                    }
                }
                VTotal = Valor1+Valor2+Valor3+Valor4+Valor5+Valor6+Valor7+Valor8+Valor9+Valor10+Valor11+Valor12+Valor13+Valor14+Valor15;
                VDivT = VTotal;
                while (VDivT >= 10)
                {
                    VDivT = VDivT - 10;
                }
                Digito = 10-VDivT;
                ui->lineEdit_24->setText(QString::number(Digito));
            }
            if (ui->radioButton_4->isChecked())
            {
                int Valor1,Valor2,Valor3,Valor4,Valor5,Valor6,Valor7,Valor8,Valor9,Valor10,Valor11,Valor12,Valor13,Valor14,Valor15,Valor16,VTotal,VDivT,Digito;
                QStringList Total = Cantidad.split("");
                for(int i=1;i<Total.count();i++)
                {
                    if (i == 1)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor1 = Total.value(i).toInt()*2;
                           if (Valor1 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor1).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor1 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_25->setFocus();
                           return;
                        }
                    }
                    if (i == 2)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor2 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_25->setFocus();
                           return;
                        }
                    }
                    if (i == 3)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor3 = Total.value(i).toInt()*2;
                           if (Valor3 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor3).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor3 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_25->setFocus();
                           return;
                        }
                    }
                    if (i == 4)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor4 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_25->setFocus();
                           return;
                        }
                    }
                    if (i == 5)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor5 = Total.value(i).toInt()*2;
                           if (Valor5 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor5).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor5 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_22->setFocus();
                           return;
                        }
                    }
                    if (i == 6)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor6 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_22->setFocus();
                           return;
                        }
                    }
                    if (i == 7)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor7 = Total.value(i).toInt()*2;
                           if (Valor7 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor7).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor7 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_22->setFocus();
                           return;
                        }
                    }
                    if (i == 8)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor8 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_22->setFocus();
                           return;
                        }
                    }
                    if (i == 9)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor9 = Total.value(i).toInt()*2;
                           if (Valor9 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor9).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor9 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_26->setFocus();
                           return;
                        }
                    }
                    if (i == 10)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor10 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_26->setFocus();
                           return;
                        }
                    }
                    if (i == 11)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor11 = Total.value(i).toInt()*2;
                           if (Valor11 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor11).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor11 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_26->setFocus();
                           return;
                        }
                    }
                    if (i == 12)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor12 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_26->setFocus();
                           return;
                        }
                    }
                    if (i == 13)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor13 = Total.value(i).toInt()*2;
                           if (Valor13 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor13).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor13 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_23->setFocus();
                           return;
                        }
                    }
                    if (i == 14)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor14 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_23->setFocus();
                           return;
                        }
                    }
                    if (i == 15)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                           Valor15 = Total.value(i).toInt()*2;
                           if (Valor15 >= 10)
                           {
                               int Resto = 0;
                               QStringList Valor = QString::number(Valor15).split("");
                               for (int a = 0;a<Valor.count();a++)
                                   Resto = Resto + Valor.value(a).toInt();
                               Valor15 = Resto;
                           }
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_23->setFocus();
                           return;
                        }
                    }
                    if (i == 16)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor16 = Total.value(i).toInt();
                        }
                        else
                        {
                           QMessageBox m;
                           m.setWindowTitle(tr("Advertencia!!!"));
                           m.setText(tr("Has introducido un caracter no valido."));
                           m.exec();
                           ui->lineEdit_23->setFocus();
                           return;
                        }
                    }
                }
                VTotal = Valor1+Valor2+Valor3+Valor4+Valor5+Valor6+Valor7+Valor8+Valor9+Valor10+Valor11+Valor12+Valor13+Valor14+Valor15+Valor16;
                VDivT = VTotal/10;
                Digito = VTotal-(VDivT*10);
                if (Digito != 0)
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("<FONT COLOR=\"RED\">El digito de validacion es erroneo."));
                    m.exec();
                    return;
                }
                else
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("<FONT COLOR=\"BLUE\">El digito de validacion es correcto."));
                    m.exec();
                    return;
                }
            }
            if (ui->radioButton_5->isChecked())
            {
                int Valor1,Valor2,Valor3,Valor4,Valor5,Valor6,Valor7,Valor8,Valor9,Valor10,Valor11,Valor12,Valor13,Valor14,Valor15,Valor16,VTotal,VDivT,Digito,Resultado,Final,NumX;
                QString Comprobar;
                NumX = 0;
                QStringList Total = Cantidad.split("");
                for(int i=1;i<Total.count();i++)
                {
                    if (i == 1)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor1 = Total.value(i).toInt()*2;
                            if (Valor1 >= 10)
                            {
                                int Resto = 0;
                                QStringList Valor = QString::number(Valor1).split("");
                                for (int a = 0;a<Valor.count();a++)
                                    Resto = Resto + Valor.value(a).toInt();
                                Valor1 = Resto;
                            }
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor1 = 0;
                                Comprobar = "Si";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_25->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 2)
                    {                        
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor2 = Total.value(i).toInt();
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor2 = 0;
                                Comprobar = "No";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_25->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 3)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor3 = Total.value(i).toInt()*2;
                            if (Valor3 >= 10)
                            {
                                int Resto = 0;
                                QStringList Valor = QString::number(Valor3).split("");
                                for (int a = 0;a<Valor.count();a++)
                                    Resto = Resto + Valor.value(a).toInt();
                                Valor3 = Resto;
                            }
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor3 = 0;
                                Comprobar = "Si";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_25->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 4)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor4 = Total.value(i).toInt();
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor4 = 0;
                                Comprobar = "No";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_25->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 5)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor5 = Total.value(i).toInt()*2;
                            if (Valor5 >= 10)
                            {
                                int Resto = 0;
                                QStringList Valor = QString::number(Valor5).split("");
                                for (int a = 0;a<Valor.count();a++)
                                    Resto = Resto + Valor.value(a).toInt();
                                Valor5 = Resto;
                            }
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor5 = 0;
                                Comprobar = "Si";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_22->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 6)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor6 = Total.value(i).toInt();
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor6 = 0;
                                Comprobar = "No";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_22->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 7)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor7 = Total.value(i).toInt()*2;
                            if (Valor7 >= 10)
                            {
                                int Resto = 0;
                                QStringList Valor = QString::number(Valor7).split("");
                                for (int a = 0;a<Valor.count();a++)
                                    Resto = Resto + Valor.value(a).toInt();
                                Valor7 = Resto;
                            }
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor7 = 0;
                                Comprobar = "Si";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_22->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 8)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor8 = Total.value(i).toInt();
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor8 = 0;
                                Comprobar = "No";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_22->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 9)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor9 = Total.value(i).toInt()*2;
                            if (Valor9 >= 10)
                            {
                                int Resto = 0;
                                QStringList Valor = QString::number(Valor9).split("");
                                for (int a = 0;a<Valor.count();a++)
                                    Resto = Resto + Valor.value(a).toInt();
                                Valor9 = Resto;
                            }
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor9 = 0;
                                Comprobar = "Si";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_26->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 10)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor10 = Total.value(i).toInt();
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor10 = 0;
                                Comprobar = "No";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_26->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 11)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor11 = Total.value(i).toInt()*2;
                            if (Valor11 >= 10)
                            {
                                int Resto = 0;
                                QStringList Valor = QString::number(Valor11).split("");
                                for (int a = 0;a<Valor.count();a++)
                                    Resto = Resto + Valor.value(a).toInt();
                                Valor11 = Resto;
                            }
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor11 = 0;
                                Comprobar = "Si";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_26->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 12)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor12 = Total.value(i).toInt();
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor12 = 0;
                                Comprobar = "No";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_26->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 13)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor13 = Total.value(i).toInt()*2;
                            if (Valor13 >= 10)
                            {
                                int Resto = 0;
                                QStringList Valor = QString::number(Valor13).split("");
                                for (int a = 0;a<Valor.count();a++)
                                    Resto = Resto + Valor.value(a).toInt();
                                Valor13 = Resto;
                            }
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor13 = 0;
                                Comprobar = "Si";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_23->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 14)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor14 = Total.value(i).toInt();
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor14 = 0;
                                Comprobar = "No";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_23->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 15)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor15 = Total.value(i).toInt()*2;
                            if (Valor13 >= 10)
                            {
                                int Resto = 0;
                                QStringList Valor = QString::number(Valor15).split("");
                                for (int a = 0;a<Valor.count();a++)
                                    Resto = Resto + Valor.value(a).toInt();
                                Valor15 = Resto;
                            }
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor15 = 0;
                                Comprobar = "Si";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_23->setFocus();
                                return;
                            }
                        }
                    }
                    if (i == 16)
                    {
                        QChar ascii;
                        int numero;
                        QString Verif = Total.value(i);
                        ascii=Verif.at(0).toAscii();
                        numero=ascii.toAscii() ;
                        if (numero >= 48 && numero <=57)
                        {
                            Valor16 = Total.value(i).toInt();
                        }
                        else
                        {
                            if (Total.value(i) == "X" || Total.value(i) == "x")
                            {
                                Valor16 = 0;
                                Comprobar = "No";
                                NumX = NumX + 1;
                            }
                            else
                            {
                                QMessageBox m;
                                m.setWindowTitle(tr("Advertencia!!!"));
                                m.setText(tr("El caracter ")+Total.value(i)+tr(" introducido no es valido."));
                                m.exec();
                                ui->lineEdit_23->setFocus();
                                return;
                            }
                        }
                    }
                }
                if (NumX > 1)
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("No puedes poner mas de una \"X\", ya que solo se puede localizar un digito por vez."));
                    m.exec();
                    return;
                }
                VTotal = Valor1+Valor2+Valor3+Valor4+Valor5+Valor6+Valor7+Valor8+Valor9+Valor10+Valor11+Valor12+Valor13+Valor14+Valor15+Valor16;
                VDivT = VTotal/10;
                Digito = VTotal-(VDivT*10);
                if (Digito != 0)
                    Resultado = 10-Digito;
                else
                    Resultado = 0;
                if (Comprobar == "Si")
                {
                    if (Resultado == 0)
                        Final = 0;
                    if (Resultado == 1)
                        Final = 5;
                    if (Resultado == 2)
                        Final = 1;
                    if (Resultado == 3)
                        Final = 6;
                    if (Resultado == 4)
                        Final = 2;
                    if (Resultado == 5)
                        Final = 7;
                    if (Resultado == 6)
                        Final = 3;
                    if (Resultado == 7)
                        Final = 8;
                    if (Resultado == 8)
                        Final = 4;
                    if (Resultado == 9)
                        Final = 9;
                }
                else
                {
                    Final = Resultado;
                }
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("El digito de falta es ")+QString::number(Final)+"");
                m.exec();
                if (ui->lineEdit_25->text().contains("X",Qt::CaseInsensitive))
                {
                    QString Sustituir = ui->lineEdit_25->text();
                    Sustituir = Sustituir.replace("X",QString::number(Final),Qt::CaseInsensitive);
                    ui->lineEdit_25->setText(Sustituir);
                }
                if (ui->lineEdit_22->text().contains("X",Qt::CaseInsensitive))
                {
                    QString Sustituir = ui->lineEdit_22->text();
                    Sustituir = Sustituir.replace("X",QString::number(Final),Qt::CaseInsensitive);
                    ui->lineEdit_22->setText(Sustituir);
                }
                if (ui->lineEdit_26->text().contains("X",Qt::CaseInsensitive))
                {
                    QString Sustituir = ui->lineEdit_26->text();
                    Sustituir = Sustituir.replace("X",QString::number(Final),Qt::CaseInsensitive);
                    ui->lineEdit_26->setText(Sustituir);
                }
                if (ui->lineEdit_23->text().contains("X",Qt::CaseInsensitive))
                {
                    QString Sustituir = ui->lineEdit_23->text();
                    Sustituir = Sustituir.replace("X",QString::number(Final),Qt::CaseInsensitive);
                    ui->lineEdit_23->setText(Sustituir);
                }
            }
        }
    }
}

void ConversorUD::on_lineEdit_22_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor;
        if (ui->radioButton_5->isChecked())
            Valor = VerNum(arg1,2);
        else
            Valor = VerNum(arg1,0);
        if (Valor == "No")
        {
            if (ui->lineEdit_25->text() == "")
            {
                ui->lineEdit_22->setText("");
                ui->lineEdit_25->setFocus();
            }
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_22->setFocus();
            QString Resto = ui->lineEdit_22->text();
            Resto.chop(1);
            ui->lineEdit_22->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_lineEdit_26_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor;
        if (ui->radioButton_5->isChecked())
            Valor = VerNum(arg1,2);
        else
            Valor = VerNum(arg1,0);
        if (Valor == "No")
        {
            if (ui->lineEdit_22->text() == "")
            {
                ui->lineEdit_26->setText("");
                ui->lineEdit_22->setFocus();
            }
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_22->setFocus();
            QString Resto = ui->lineEdit_22->text();
            Resto.chop(1);
            ui->lineEdit_22->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_lineEdit_23_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor;
        if (ui->radioButton_5->isChecked())
            Valor = VerNum(arg1,2);
        else
            Valor = VerNum(arg1,0);
        if (Valor == "No")
        {
            if (ui->lineEdit_26->text() == "")
            {
                ui->lineEdit_23->setText("");
                ui->lineEdit_26->setFocus();
            }
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_23->setFocus();
            QString Resto = ui->lineEdit_23->text();
            Resto.chop(1);
            ui->lineEdit_23->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_pushButton_3_clicked()
{
    ui->lineEdit_19->setText("");
    ui->lineEdit_20->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_21->setText("");
    ui->lineEdit_19->setFocus();
}

void ConversorUD::on_pushButton_4_clicked()
{
    ui->lineEdit_25->setText("");
    ui->lineEdit_22->setText("");
    ui->lineEdit_26->setText("");
    ui->lineEdit_23->setText("");
    ui->lineEdit_24->setText("");
    ui->lineEdit_25->setFocus();
}

void ConversorUD::on_pushButton_7_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}

void ConversorUD::on_pushButton_8_clicked()
{
    ui->lineEdit_8->setText("");
    ui->lineEdit_8->setFocus();
}

void ConversorUD::on_pushButton_9_clicked()
{
    ui->lineEdit_12->setText("");
    ui->lineEdit_12->setFocus();
}

void ConversorUD::on_pushButton_5_clicked()
{
    ui->lineEdit_14->setText("");
    ui->lineEdit_14->setFocus();
}

void ConversorUD::on_pushButton_10_clicked()
{
    ui->lineEdit_4->setText("");
    ui->lineEdit_4->setFocus();
}

void ConversorUD::on_pushButton_11_clicked()
{
    ui->lineEdit_10->setText("");
    ui->lineEdit_10->setFocus();
}

void ConversorUD::on_pushButton_6_clicked()
{
    ui->lineEdit_15->setText("");
    ui->lineEdit_16->setText("");
    ui->lineEdit_17->setText("");
    ui->lineEdit_18->setText("");
    ui->lineEdit_15->setFocus();
}

void ConversorUD::on_pushButton_12_clicked()
{
    AmortizacionP = 0;
    ui->lineEdit_27->setText("");
    ui->lineEdit_28->setText("");
    ui->lineEdit_29->setText("");
    ui->lineEdit_30->setText("");
    ui->lineEdit_31->setText("");
    ui->lineEdit_32->setText("");
    ui->lineEdit_33->setText("");
    ui->lineEdit_34->setText("");
    ui->lineEdit_35->setText("");
    ui->lineEdit_27->setFocus();
    int Borrado, x;
    Borrado = ui->tableWidget->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
}

QString ConversorUD::VerNum(QString Valor, int Tipo)
{
    QString Value;
    if (Tipo == 0)
    {
        QStringList Total = Valor.split("");
        for(int i=1;i<Total.count()-1;i++)
        {
            if (Total.value(i) != "")
            {
                QChar ascii;
                int numero;
                QString Verif = Total.value(i);
                ascii=Verif.at(0).toAscii();
                numero=ascii.toAscii() ;
                if (numero >= 48 && numero <=57)
                {
                   Value = "No";
                }
                else
                {
                    Value = "Si";
                    break;
                }
            }
        }
    }
    if (Tipo == 1)
    {
        int Totalizar = 0;
        QStringList Total = Valor.split("");
        for(int i=1;i<Total.count()-1;i++)
        {
            if (Total.value(i) != "")
            {
                QChar ascii;
                int numero;
                QString Verif = Total.value(i);
                ascii=Verif.at(0).toAscii();
                numero=ascii.toAscii() ;
                if (numero >= 48 && numero <=57)
                {
                   Value = "No";
                }
                else
                {
                    if (numero == 46)
                    {
                        Value = "No";
                        Totalizar = Totalizar+1;
                    }
                    else
                    {
                        Value = "Si";
                        break;
                    }
                }
            }
        }
        if (Totalizar > 1)
            Value = "Si";
    }
    if (Tipo == 2)
    {
        QStringList Total = Valor.split("");
        for(int i=1;i<Total.count()-1;i++)
        {
            if (Total.value(i) != "")
            {
                QChar ascii;
                int numero;
                QString Verif = Total.value(i);
                ascii=Verif.at(0).toAscii();
                numero=ascii.toAscii() ;
                if (numero >= 48 && numero <=57)
                {
                   Value = "No";
                }
                else
                {
                    if (Total.value(i) == "X" || Total.value(i) == "x")
                    {
                        Value = "No";
                    }
                    else
                    {
                        Value = "Si";
                        break;
                    }
                }
            }
        }
    }
    return Value;
}

void ConversorUD::on_lineEdit_19_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,0);
        if (Valor == "Si")
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_19->setFocus();
            QString Resto = ui->lineEdit_19->text();
            Resto.chop(1);
            ui->lineEdit_19->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_lineEdit_25_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor;
        if (ui->radioButton_5->isChecked())
            Valor = VerNum(arg1,2);
        else
            Valor = VerNum(arg1,0);
        if (Valor == "Si")
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_25->setFocus();
            QString Resto = ui->lineEdit_25->text();
            Resto.chop(1);
            ui->lineEdit_25->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_pushButton_14_clicked()
{
    if (ui->comboBox_7->currentText() == tr("Metodo Frances"))
    {
        double Intereses, Parte1, Parte2, Parte31, Result, Resultado, Parte41, Total, Parte, Resto, TotCuotas, TotInteres;
        double Tipo, Anual, Cuota, Amort, tae, tae1, tae2, TAE, ValorTAE;
        int Unidad = 1;
        QString Valor, Value1, Value, Value2, Value3;
        Valor = ui->comboBox_5->currentText();
        Tipo = Periodo(Valor);
        Anual = ui->lineEdit_31->text().toInt();
        Cuota = Tipo*Anual;
        Parte = ui->lineEdit_29->text().toDouble();
        Resto = (Parte/Tipo)/100;
        ui->lineEdit_30->setText(QString::number(Resto));
        ui->lineEdit_32->setText(QString::number(Cuota));
        Value = QuitarMil(ui->lineEdit_27->text());
        Amort = Value.toDouble();
        Intereses = ui->lineEdit_30->text().toDouble();
        Parte1 = Amort*Intereses;
        Parte2 = Unidad+Intereses;
        Resultado = Parte2;
        QProgressDialog progress("Realizando los calculos de la cuota... Espera por favor", "Cancelar", 0, Cuota);
        if (Stilo == "A")
            progress.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        progress.setWindowModality(Qt::WindowModal);
        progress.show();
        QTest::qWait(20);
        for(int a=1;a<Cuota;a++)
        {
            progress.setValue(a);
            if (progress.wasCanceled())
            {
                AmortizacionP = 0;
                ui->lineEdit_27->setText("");
                ui->lineEdit_28->setText("");
                ui->lineEdit_29->setText("");
                ui->lineEdit_30->setText("");
                ui->lineEdit_31->setText("");
                ui->lineEdit_32->setText("");
                ui->lineEdit_33->setText("");
                ui->lineEdit_34->setText("");
                ui->lineEdit_35->setText("");
                ui->lineEdit_27->setFocus();
                int Borrado, x;
                Borrado = ui->tableWidget->rowCount();
                for(x=0;x<Borrado;x++)
                {
                     ui->tableWidget->removeRow(x);
                     x=x-1;
                     Borrado=Borrado-1;
                }
                break;
            }
            Result = Resultado*Parte2;
            QString Parcial = QString::number(Result,'f',9);
            double Valor = Parcial.toDouble();
            Resultado = Valor;
        }      
        progress.setValue(Cuota);
        Parte31 = Unidad/Resultado;
        double Parte3=static_cast<double>(static_cast<int>(Parte31*1000000000+0.5))/1000000000.0;
        Parte41 = Unidad-Parte3;
        double Parte4=static_cast<double>(static_cast<int>(Parte41*1000000000+0.5))/1000000000.0;
        Total = Parte1/Parte4;
        Value1 = PonerMil(QString::number(Total));
        if (ui->checkBox->isChecked())
        {
            if (ui->comboBox_10->currentText().toInt() != 0)
            {
                ui->lineEdit_28->setAlignment(Qt::AlignHCenter);
                ui->lineEdit_28->setText(tr("Ver tabla"));
                CuotaCarencia = Value1;
            }
            else
            {
                ui->lineEdit_28->setAlignment(Qt::AlignRight);
                ui->lineEdit_28->setText(Value1);
                CuotaCarencia = Value1;
            }
        }
        else
        {
            ui->lineEdit_28->setAlignment(Qt::AlignRight);
            ui->lineEdit_28->setText(Value1);
            CuotaCarencia = Value1;
        }
        this->Tabla();
        TotCuotas = Total*Cuota;
        Value2 = PonerMil(QString::number(TotCuotas,'f',2));
        ui->lineEdit_33->setText(Value2);
        TotInteres = TotCuotas-Amort;
        Value3 = PonerMil(QString::number(TotInteres,'f',2));
        ui->lineEdit_34->setText(Value3);
        tae1 = Unidad+Resto;
        tae2 = tae1;
        for(int a=1;a<12;a++)
        {
            tae = tae1*tae2;
            ValorTAE = tae;
            tae1 = ValorTAE;
        }
        TAE = (tae-Unidad)*100;
        ui->lineEdit_35->setText(QString::number(TAE,'f',2));
    }
    if (ui->comboBox_7->currentText() == tr("Metodo Americano"))
    {
        double Intereses, Parte1, Parte, Resto, TotCuotas, TotInteres, Total;
        double Tipo, Anual, Cuota, Cuotas, Amort, Interes, tae, tae1, tae2, TAE, ValorTAE;
        QString Valor, Value1, Value, Value2, Value3, Value4, Value5;
        int Unidad = 1;
        Valor = ui->comboBox_5->currentText();
        Tipo = Periodo(Valor);
        Anual = ui->lineEdit_31->text().toDouble();
        Cuota = Tipo*Anual;
        Parte = ui->lineEdit_29->text().toDouble();
        Resto = (Parte/Tipo)/100;
        ui->lineEdit_30->setText(QString::number(Resto));
        ui->lineEdit_32->setText(QString::number(Cuota));
        Value = QuitarMil(ui->lineEdit_27->text());
        Amort = Value.toDouble();
        Intereses = ui->lineEdit_30->text().toDouble();
        Parte1 = Amort*Intereses;
        Value1 = PonerMil(QString::number(Parte1,'f',2));
        ui->lineEdit_28->setAlignment(Qt::AlignRight);
        ui->lineEdit_28->setText(Value1);
        this->Tabla();
        Value4 = QuitarMil(ui->lineEdit_28->text());
        Cuotas = Value4.toDouble();
        TotCuotas = (Cuotas*Cuota)+Amort;
        TotInteres = TotCuotas-Amort;
        Value3 = PonerMil(QString::number(TotInteres,'f',2));
        ui->lineEdit_34->setText(Value3);
        Value5 = QuitarMil(ui->lineEdit_34->text());
        Interes = Value5.toDouble();
        Total = Interes+Amort;
        Value2 = PonerMil(QString::number(Total,'f',2));
        ui->lineEdit_33->setText(Value2);
        tae1 = Unidad+Resto;
        tae2 = tae1;
        for(int a=1;a<12;a++)
        {
            tae = tae1*tae2;
            ValorTAE = tae;
            tae1 = ValorTAE;
        }
        TAE = (tae-Unidad)*100;
        ui->lineEdit_35->setText(QString::number(TAE,'f',2));
    }
    if (ui->comboBox_7->currentText() == tr("Metodo Aleman"))
    {
        double Intereses, Parte, Resto, Total, ParcInt, ParcAmort;
        double Tipo, Anual, Cuota, Amort, tae, tae1, tae2, TAE, ValorTAE;
        QString Valor, Value, Value1, Value2, Value3, Value4, Value5;
        int Unidad = 1;
        Valor = ui->comboBox_5->currentText();
        Tipo = Periodo(Valor);
        Anual = ui->lineEdit_31->text().toDouble();
        Cuota = Tipo*Anual;
        Parte = ui->lineEdit_29->text().toDouble();
        Resto = (Parte/Tipo)/100;
        ui->lineEdit_30->setText(QString::number(Resto));
        ui->lineEdit_32->setText(QString::number(Cuota));
        ui->lineEdit_28->setAlignment(Qt::AlignHCenter);
        ui->lineEdit_28->setText(tr("Ver tabla"));
        this->Tabla();
        int itemCount = ui->tableWidget->rowCount();
        Intereses = 0;
        Amort = 0;
        QTableWidgetItem *item, *item1;
        for(int i=0;i<itemCount;i++)
        {
            item=new QTableWidgetItem;
            item1=new QTableWidgetItem;
            item = ui->tableWidget->item(i,2);
            item1 = ui->tableWidget->item(i,3);
            Value4 = QuitarMil(item->text());
            ParcInt = Value4.toDouble();
            Intereses = Intereses + ParcInt;
            Value5 = QuitarMil(item1->text());
            ParcAmort = Value5.toDouble();
            Amort = Amort + ParcAmort;
        }
        Value = QuitarMil(QString::number(Intereses,'f',2));
        Value3 = PonerMil(Value);
        ui->lineEdit_34->setText(Value3);
        Value1 = QuitarMil(QString::number(Amort,'f',2));
        Total = Value.toDouble() + Value1.toDouble();
        Value2 = PonerMil(QString::number(Total,'f',2));
        ui->lineEdit_33->setText(Value2);
        tae1 = Unidad+Resto;
        tae2 = tae1;
        for(int a=1;a<12;a++)
        {
            tae = tae1*tae2;
            ValorTAE = tae;
            tae1 = ValorTAE;
        }
        TAE = (tae-Unidad)*100;
        ui->lineEdit_35->setText(QString::number(TAE,'f',2));
    }
}

void ConversorUD::Tabla()
{
    if (ui->comboBox_7->currentText() == tr("Metodo Frances"))
    {
        if (!ui->checkBox->isChecked())
        {
            int Borrado, x;
            Borrado = ui->tableWidget->rowCount();
            for(x=0;x<Borrado;x++)
            {
                 ui->tableWidget->removeRow(x);
                 x=x-1;
                 Borrado=Borrado-1;
            }
            QString Periodo, Mensualidad, Interes, Amortizacion, Capital, CapiAmort, Value, Totalue, Cuetue;
            double Intereses, Total, Valor, Cuota, RestoCap, ParcialInt, ParcialAmort, ParcialCap, ParcialCapiAmort;
            Cuetue = QuitarMil(ui->lineEdit_32->text());
            Cuota = Cuetue.toDouble();
            Intereses = ui->lineEdit_30->text().toDouble();
            if (ui->checkBox->isChecked())
            {
                if (ui->comboBox_10->currentText().toInt() != 0)
                {
                    Totalue = QuitarMil(CuotaCarencia);
                }
                else
                {
                    Totalue = QuitarMil(ui->lineEdit_28->text());
                }
            }
            else
            {
                Totalue = QuitarMil(ui->lineEdit_28->text());
            }
            Total = Totalue.toDouble();
            Value = QuitarMil(ui->lineEdit_27->text());
            Valor = Value.toDouble();
            QTableWidgetItem *item, *item1, *item2, *item3, *item4, *item5;
            QProgressDialog progress("Calculando tabla de amortizacion... Espera por favor", "Cancelar", 0, Cuota);
            if (Stilo == "A")
                progress.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            progress.setWindowModality(Qt::WindowModal);
            progress.show();
            QTest::qWait(20);
            for (int a=0;a<Cuota+1;a++)
            {
                progress.setValue(a);
                if (progress.wasCanceled())
                {
                    AmortizacionP = 0;
                    ui->lineEdit_27->setText("");
                    ui->lineEdit_28->setText("");
                    ui->lineEdit_29->setText("");
                    ui->lineEdit_30->setText("");
                    ui->lineEdit_31->setText("");
                    ui->lineEdit_32->setText("");
                    ui->lineEdit_33->setText("");
                    ui->lineEdit_34->setText("");
                    ui->lineEdit_35->setText("");
                    ui->lineEdit_27->setFocus();
                    int Borrado, x;
                    Borrado = ui->tableWidget->rowCount();
                    for(x=0;x<Borrado;x++)
                    {
                         ui->tableWidget->removeRow(x);
                         x=x-1;
                         Borrado=Borrado-1;
                    }
                    break;
                }
                item=new QTableWidgetItem;
                item1=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                item3=new QTableWidgetItem;
                item4=new QTableWidgetItem;
                item5=new QTableWidgetItem;
                if (a==0)
                {
                    Periodo = QString::number(a);
                    Mensualidad = "";
                    Interes = "";
                    Amortizacion = "";
                    ParcialCap = Valor;
                    Capital = QString("%L1").arg(ParcialCap,0,'f',2);
                    CapiAmort = "";
                    RestoCap = Valor;
                }
                else if (a==Cuota)
                {
                    Periodo = QString::number(a);
                    Mensualidad = QString("%L1").arg(Total,0,'f',2);
                    ParcialAmort = RestoCap;
                    Amortizacion = QString("%L1").arg(ParcialAmort,0,'f',2);
                    ParcialInt = Total-ParcialAmort;
                    Interes = QString("%L1").arg(ParcialInt,0,'f',2);
                    ParcialCap = RestoCap-ParcialAmort;
                    Capital = QString("%L1").arg(ParcialCap,0,'f',2);
                    ParcialCapiAmort = Valor-ParcialCap;
                    CapiAmort = QString("%L1").arg(ParcialCapiAmort,0,'f',2);
                }
                else
                {
                    Periodo = QString::number(a);
                    Mensualidad = QString("%L1").arg(Total,0,'f',2);
                    ParcialInt = RestoCap*Intereses;
                    Interes = QString("%L1").arg(ParcialInt,0,'f',2);
                    ParcialAmort = Total-ParcialInt;
                    Amortizacion = QString("%L1").arg(ParcialAmort,0,'f',2);
                    ParcialCap = RestoCap-ParcialAmort;
                    Capital = QString("%L1").arg(ParcialCap,0,'f',2);
                    ParcialCapiAmort = Valor-ParcialCap;
                    CapiAmort = QString("%L1").arg(ParcialCapiAmort,0,'f',2);
                    RestoCap = ParcialCap;
                }
                item->setText(Periodo);
                item1->setText(Mensualidad);
                item2->setText(Interes);
                item3->setText(Amortizacion);
                item4->setText(Capital);
                item5->setText(CapiAmort);
                int iFilas=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(iFilas);
                ui->tableWidget->setItem(iFilas,0,item);
                ui->tableWidget->setItem(iFilas,1,item1);
                ui->tableWidget->setItem(iFilas,2,item2);
                ui->tableWidget->setItem(iFilas,3,item3);
                ui->tableWidget->setItem(iFilas,4,item4);
                ui->tableWidget->setItem(iFilas,5,item5);
                ui->tableWidget->item(iFilas,0)->setTextAlignment(Qt::AlignRight);
                ui->tableWidget->item(iFilas,1)->setTextAlignment(Qt::AlignRight);
                ui->tableWidget->item(iFilas,2)->setTextAlignment(Qt::AlignRight);
                ui->tableWidget->item(iFilas,3)->setTextAlignment(Qt::AlignRight);
                ui->tableWidget->item(iFilas,4)->setTextAlignment(Qt::AlignRight);
                ui->tableWidget->item(iFilas,5)->setTextAlignment(Qt::AlignRight);
            }
            progress.setValue(Cuota);
            ui->tableWidget->resizeRowsToContents();
            ui->tableWidget->resizeColumnsToContents();
        }
        else
        {
            int Borrado, x;
            Borrado = ui->tableWidget->rowCount();
            for(x=0;x<Borrado;x++)
            {
                 ui->tableWidget->removeRow(x);
                 x=x-1;
                 Borrado=Borrado-1;
            }
            QString Periodo, Mensualidad, Interes, Amortizacion, Capital, CapiAmort, Value, Totalue, Cuetue, IntParc1;
            double Intereses, Total, Valor, Cuota, RestoCap, ParcialInt, ParcialAmort, ParcialCap, ParcialCapiAmort, IntParc, IntCarencia;
            Cuetue = QuitarMil(ui->lineEdit_32->text());
            Cuota = Cuetue.toDouble();
            Intereses = ui->lineEdit_30->text().toDouble();
            if (ui->checkBox->isChecked())
            {
                if (ui->comboBox_10->currentText().toInt() != 0)
                {
                    Totalue = QuitarMil(CuotaCarencia);
                }
                else
                {
                    Totalue = QuitarMil(ui->lineEdit_28->text());
                }
            }
            else
            {
                Totalue = QuitarMil(ui->lineEdit_28->text());
            }
            Total = Totalue.toDouble();
            Value = QuitarMil(ui->lineEdit_27->text());
            Valor = Value.toDouble();
            IntParc = Valor*Intereses;
            IntParc1 = QString("%L1").arg(IntParc,0,'f',2);
            IntCarencia = IntParc1.toDouble();
            QTableWidgetItem *item, *item1, *item2, *item3, *item4, *item5;
            QProgressDialog progress("Calculando tabla de amortizacion... Espera por favor", "Cancelar", 0, Cuota);
            if (Stilo == "A")
                progress.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            progress.setWindowModality(Qt::WindowModal);
            progress.show();
            QTest::qWait(20);
            for (int a=0;a<Cuota+1;a++)
            {
                progress.setValue(a);
                if (progress.wasCanceled())
                {
                    AmortizacionP = 0;
                    ui->lineEdit_27->setText("");
                    ui->lineEdit_28->setText("");
                    ui->lineEdit_29->setText("");
                    ui->lineEdit_30->setText("");
                    ui->lineEdit_31->setText("");
                    ui->lineEdit_32->setText("");
                    ui->lineEdit_33->setText("");
                    ui->lineEdit_34->setText("");
                    ui->lineEdit_35->setText("");
                    ui->lineEdit_27->setFocus();
                    int Borrado, x;
                    Borrado = ui->tableWidget->rowCount();
                    for(x=0;x<Borrado;x++)
                    {
                         ui->tableWidget->removeRow(x);
                         x=x-1;
                         Borrado=Borrado-1;
                    }
                    break;
                }
                item=new QTableWidgetItem;
                item1=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                item3=new QTableWidgetItem;
                item4=new QTableWidgetItem;
                item5=new QTableWidgetItem;
                if (a==0)
                {
                    Periodo = QString::number(a);
                    Mensualidad = "";
                    Interes = "";
                    Amortizacion = "";
                    ParcialCap = Valor;
                    Capital = QString("%L1").arg(ParcialCap,0,'f',2);
                    CapiAmort = "";
                    RestoCap = Valor;
                }
                else if (a==Cuota)
                {
                    Periodo = QString::number(a);
                    Mensualidad = QString("%L1").arg(Total,0,'f',2);
                    ParcialAmort = RestoCap;
                    Amortizacion = QString("%L1").arg(ParcialAmort,0,'f',2);
                    ParcialInt = Total-ParcialAmort;
                    Interes = QString("%L1").arg(ParcialInt,0,'f',2);
                    ParcialCap = RestoCap-ParcialAmort;
                    Capital = QString("%L1").arg(ParcialCap,0,'f',2);
                    ParcialCapiAmort = Valor-ParcialCap;
                    CapiAmort = QString("%L1").arg(ParcialCapiAmort,0,'f',2);
                }
                else
                {
                    if (a > 0 && a <=ui->comboBox_10->currentText().toInt())
                    {
                        if (ui->radioButton_8->isChecked())
                        {
                            Periodo = QString::number(a);
                            Mensualidad = QString("%L1").arg(0.00,0,'f',2);
                            Interes = QString("%L1").arg(0.00,0,'f',2);
                            Amortizacion = QString("%L1").arg(0.00,0,'f',2);
                            IntParc = IntCarencia+RestoCap;
                            Capital = QString("%L1").arg(IntParc,0,'f',2);
                            CapiAmort = QString("%L1").arg(0.00,0,'f',2);
                            RestoCap = IntParc;
                            Valor = RestoCap;
                        }
                        if (ui->radioButton_9->isChecked())
                        {
                            Periodo = QString::number(a);
                            Mensualidad = QString("%L1").arg(IntParc,0,'f',2);
                            Interes = QString("%L1").arg(IntParc,0,'f',2);
                            Amortizacion = QString("%L1").arg(0.00,0,'f',2);
                            Capital = QString("%L1").arg(Valor,0,'f',2);
                            CapiAmort = QString("%L1").arg(0.00,0,'f',2);
                        }
                    }
                    if (a == ui->comboBox_10->currentText().toInt()+1)
                    {
                            double Intereses, Parte1, Parte2, Parte31, Result, Resultado, Parte41; //, Total;
                            double Tipo, Anual, Cuota, Amort;
                            int Unidad = 1;
                            QString Valorar;
                            Valorar = ui->comboBox_5->currentText();
                            if (Valorar == tr("Mensual"))
                                Tipo= 12;
                            if (Valorar == tr("Bimestral"))
                                Tipo= 6;
                            if (Valorar == tr("Trimestral"))
                                Tipo= 4;
                            if (Valorar == tr("Cuatrimestral"))
                                Tipo= 3;
                            if (Valorar == tr("Semestral"))
                                Tipo= 2;
                            if (Valorar == tr("Anual"))
                                Tipo= 1;
                            Anual = ui->lineEdit_31->text().toInt();
                            Cuota = (Tipo*Anual)-ui->comboBox_10->currentText().toInt();
                            Amort = RestoCap;
                            Intereses = ui->lineEdit_30->text().toDouble();
                            Parte1 = Amort*Intereses;
                            Parte2 = Unidad+Intereses;
                            Resultado = Parte2;
                            for(int a=1;a<Cuota;a++)
                            {
                                Result = Resultado*Parte2;
                                QString Parcial = QString::number(Result,'f',9);
                                double Value1 = Parcial.toDouble();
                                Resultado = Value1;
                            }
                            Parte31 = Unidad/Resultado;
                            double Parte3=static_cast<double>(static_cast<int>(Parte31*1000000000+0.5))/1000000000.0;
                            Parte41 = Unidad-Parte3;
                            double Parte4=static_cast<double>(static_cast<int>(Parte41*1000000000+0.5))/1000000000.0;
                            Total = Parte1/Parte4;
                            Periodo = QString::number(a);
                            Mensualidad = QString("%L1").arg(Total,0,'f',2);
                            ParcialInt = RestoCap*Intereses;
                            Interes = QString("%L1").arg(ParcialInt,0,'f',2);
                            ParcialAmort = Total-ParcialInt;
                            Amortizacion = QString("%L1").arg(ParcialAmort,0,'f',2);
                            ParcialCap = RestoCap-ParcialAmort;
                            Capital = QString("%L1").arg(ParcialCap,0,'f',2);
                            ParcialCapiAmort = RestoCap-ParcialCap;
                            CapiAmort = QString("%L1").arg(ParcialCapiAmort,0,'f',2);
                            RestoCap = ParcialCap;
                    }
                    else if (a > ui->comboBox_10->currentText().toInt()+1 && a < Cuota)
                    {
                        Periodo = QString::number(a);
                        Mensualidad = QString("%L1").arg(Total,0,'f',2);
                        ParcialInt = RestoCap*Intereses;
                        Interes = QString("%L1").arg(ParcialInt,0,'f',2);
                        ParcialAmort = Total-ParcialInt;
                        Amortizacion = QString("%L1").arg(ParcialAmort,0,'f',2);
                        ParcialCap = RestoCap-ParcialAmort;
                        Capital = QString("%L1").arg(ParcialCap,0,'f',2);
                        ParcialCapiAmort = Valor-ParcialCap;
                        CapiAmort = QString("%L1").arg(ParcialCapiAmort,0,'f',2);
                        RestoCap = ParcialCap;
                    }
                }
                item->setText(Periodo);
                item1->setText(Mensualidad);
                item2->setText(Interes);
                item3->setText(Amortizacion);
                item4->setText(Capital);
                item5->setText(CapiAmort);
                int iFilas=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(iFilas);
                ui->tableWidget->setItem(iFilas,0,item);
                ui->tableWidget->setItem(iFilas,1,item1);
                ui->tableWidget->setItem(iFilas,2,item2);
                ui->tableWidget->setItem(iFilas,3,item3);
                ui->tableWidget->setItem(iFilas,4,item4);
                ui->tableWidget->setItem(iFilas,5,item5);
                ui->tableWidget->item(iFilas,0)->setTextAlignment(Qt::AlignRight);
                ui->tableWidget->item(iFilas,1)->setTextAlignment(Qt::AlignRight);
                ui->tableWidget->item(iFilas,2)->setTextAlignment(Qt::AlignRight);
                ui->tableWidget->item(iFilas,3)->setTextAlignment(Qt::AlignRight);
                ui->tableWidget->item(iFilas,4)->setTextAlignment(Qt::AlignRight);
                ui->tableWidget->item(iFilas,5)->setTextAlignment(Qt::AlignRight);
            }
            progress.setValue(Cuota);
            ui->tableWidget->resizeRowsToContents();
            ui->tableWidget->resizeColumnsToContents();
        }
    }
    if (ui->comboBox_7->currentText() == tr("Metodo Americano"))
    {
        int Borrado, x;
        Borrado = ui->tableWidget->rowCount();
        for(x=0;x<Borrado;x++)
        {
             ui->tableWidget->removeRow(x);
             x=x-1;
             Borrado=Borrado-1;
        }
        QString Periodo, Mensualidad, Interes, Amortizacion, Capital, CapiAmort, Value, Totalue, Cuetue;
        double Total, Valor, Cuota, ParcialCap, ParcialMen;
        Cuetue = QuitarMil(ui->lineEdit_32->text());
        Cuota = Cuetue.toDouble();
        Totalue = QuitarMil(ui->lineEdit_28->text());
        Total = Totalue.toDouble();
        Value = QuitarMil(ui->lineEdit_27->text());
        Valor = Value.toDouble();
        QTableWidgetItem *item, *item1, *item2, *item3, *item4, *item5;
        QProgressDialog progress("Calculando tabla de amortizacion... Espera por favor", "Cancelar", 0, Cuota);
        if (Stilo == "A")
            progress.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        progress.setWindowModality(Qt::WindowModal);
        progress.show();
        QTest::qWait(20);
        for (int a=0;a<Cuota+1;a++)
        {
            progress.setValue(a);
            if (progress.wasCanceled())
            {
                AmortizacionP = 0;
                ui->lineEdit_27->setText("");
                ui->lineEdit_28->setText("");
                ui->lineEdit_29->setText("");
                ui->lineEdit_30->setText("");
                ui->lineEdit_31->setText("");
                ui->lineEdit_32->setText("");
                ui->lineEdit_33->setText("");
                ui->lineEdit_34->setText("");
                ui->lineEdit_35->setText("");
                ui->lineEdit_27->setFocus();
                int Borrado, x;
                Borrado = ui->tableWidget->rowCount();
                for(x=0;x<Borrado;x++)
                {
                     ui->tableWidget->removeRow(x);
                     x=x-1;
                     Borrado=Borrado-1;
                }
                break;
            }
            item=new QTableWidgetItem;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            item5=new QTableWidgetItem;
            if (a==0)
            {
                Periodo = QString::number(a);
                Mensualidad = "";
                Interes = "";
                Amortizacion = "";
                ParcialCap = Valor;
                Capital = QString("%L1").arg(ParcialCap,0,'f',2);
                CapiAmort = "";
            }
            else if (a==Cuota)
            {
                Periodo = QString::number(a);
                ParcialMen = Valor+Total;
                Mensualidad = QString("%L1").arg(ParcialMen,0,'f',2);
                Interes = QString("%L1").arg(Total,0,'f',2);
                Amortizacion = QString("%L1").arg(Valor,0,'f',2);
                Capital = QString("%L1").arg(0.00,0,'f',2);
                CapiAmort = QString("%L1").arg(Valor,0,'f',2);
            }
            else
            {
                Periodo = QString::number(a);
                Mensualidad = QString("%L1").arg(Total,0,'f',2);
                Interes = QString("%L1").arg(Total,0,'f',2);
                Amortizacion = QString("%L1").arg(0.00,0,'f',2);
                Capital = QString("%L1").arg(Valor,0,'f',2);
                CapiAmort = QString("%L1").arg(0.00,0,'f',2);
            }
            item->setText(Periodo);
            item1->setText(Mensualidad);
            item2->setText(Interes);
            item3->setText(Amortizacion);
            item4->setText(Capital);
            item5->setText(CapiAmort);
            int iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item);
            ui->tableWidget->setItem(iFilas,1,item1);
            ui->tableWidget->setItem(iFilas,2,item2);
            ui->tableWidget->setItem(iFilas,3,item3);
            ui->tableWidget->setItem(iFilas,4,item4);
            ui->tableWidget->setItem(iFilas,5,item5);
            ui->tableWidget->item(iFilas,0)->setTextAlignment(Qt::AlignRight);
            ui->tableWidget->item(iFilas,1)->setTextAlignment(Qt::AlignRight);
            ui->tableWidget->item(iFilas,2)->setTextAlignment(Qt::AlignRight);
            ui->tableWidget->item(iFilas,3)->setTextAlignment(Qt::AlignRight);
            ui->tableWidget->item(iFilas,4)->setTextAlignment(Qt::AlignRight);
            ui->tableWidget->item(iFilas,5)->setTextAlignment(Qt::AlignRight);            
        }
        progress.setValue(Cuota);
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
    }
    if (ui->comboBox_7->currentText() == tr("Metodo Aleman"))
    {
        int Borrado, x;
        Borrado = ui->tableWidget->rowCount();
        for(x=0;x<Borrado;x++)
        {
             ui->tableWidget->removeRow(x);
             x=x-1;
             Borrado=Borrado-1;
        }
        QString Periodo, Mensualidad, Interes, Amortizacion, Capital, CapiAmort, Value, Totalue, Cuetue;
        double Intereses, Valor, Cuota, ParcialCap, ParcialMen, Amor, RestoCap, ParcialInt, ParcialCapiAmort;
        Cuetue = QuitarMil(ui->lineEdit_32->text());
        Cuota = Cuetue.toDouble();
        Intereses = ui->lineEdit_30->text().toDouble();
        Value = QuitarMil(ui->lineEdit_27->text());
        Valor = Value.toDouble();
        Amor = Valor/Cuota;
        QTableWidgetItem *item, *item1, *item2, *item3, *item4, *item5;
        QProgressDialog progress("Calculando tabla de amortizacion... Espera por favor", "Cancelar", 0, Cuota);
        if (Stilo == "A")
            progress.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        progress.setWindowModality(Qt::WindowModal);
        progress.show();
        QTest::qWait(20);
        for (int a=0;a<Cuota+1;a++)
        {
            progress.setValue(a);
            if (progress.wasCanceled())
            {
                AmortizacionP = 0;
                ui->lineEdit_27->setText("");
                ui->lineEdit_28->setText("");
                ui->lineEdit_29->setText("");
                ui->lineEdit_30->setText("");
                ui->lineEdit_31->setText("");
                ui->lineEdit_32->setText("");
                ui->lineEdit_33->setText("");
                ui->lineEdit_34->setText("");
                ui->lineEdit_35->setText("");
                ui->lineEdit_27->setFocus();
                int Borrado, x;
                Borrado = ui->tableWidget->rowCount();
                for(x=0;x<Borrado;x++)
                {
                     ui->tableWidget->removeRow(x);
                     x=x-1;
                     Borrado=Borrado-1;
                }
                break;
            }
            item=new QTableWidgetItem;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            item5=new QTableWidgetItem;
            if (a==0)
            {
                Periodo = QString::number(a);
                Mensualidad = "";
                Interes = "";
                Amortizacion = "";
                ParcialCap = Valor;
                Capital = QString("%L1").arg(ParcialCap,0,'f',2);
                CapiAmort = "";
                RestoCap = Valor;
            }
            else
            {
                Periodo = QString::number(a);
                Amortizacion = QString("%L1").arg(Amor,0,'f',2);
                ParcialInt = RestoCap*Intereses;
                Interes = QString("%L1").arg(ParcialInt,0,'f',2);
                ParcialMen = Amor+ParcialInt;
                Mensualidad = QString("%L1").arg(ParcialMen,0,'f',2);
                ParcialCap = RestoCap-Amor;
                Capital = QString("%L1").arg(ParcialCap,0,'f',2);
                ParcialCapiAmort = Valor-ParcialCap;
                CapiAmort = QString("%L1").arg(ParcialCapiAmort,0,'f',2);
                RestoCap = ParcialCap;
            }
            item->setText(Periodo);
            item1->setText(Mensualidad);
            item2->setText(Interes);
            item3->setText(Amortizacion);
            item4->setText(Capital);
            item5->setText(CapiAmort);
            int iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item);
            ui->tableWidget->setItem(iFilas,1,item1);
            ui->tableWidget->setItem(iFilas,2,item2);
            ui->tableWidget->setItem(iFilas,3,item3);
            ui->tableWidget->setItem(iFilas,4,item4);
            ui->tableWidget->setItem(iFilas,5,item5);
            ui->tableWidget->item(iFilas,0)->setTextAlignment(Qt::AlignRight);
            ui->tableWidget->item(iFilas,1)->setTextAlignment(Qt::AlignRight);
            ui->tableWidget->item(iFilas,2)->setTextAlignment(Qt::AlignRight);
            ui->tableWidget->item(iFilas,3)->setTextAlignment(Qt::AlignRight);
            ui->tableWidget->item(iFilas,4)->setTextAlignment(Qt::AlignRight);
            ui->tableWidget->item(iFilas,5)->setTextAlignment(Qt::AlignRight);            
        }
        progress.setValue(Cuota);
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->resizeColumnsToContents();
    }
}

int ConversorUD::Periodo(QString Tipo)
{
    int Valor;
    if (Tipo == tr("Mensual"))
        Valor = 12;
    if (Tipo == tr("Bimestral"))
        Valor = 6;
    if (Tipo == tr("Trimestral"))
        Valor = 4;
    if (Tipo == tr("Cuatrimestral"))
        Valor = 3;
    if (Tipo == tr("Semestral"))
        Valor = 2;
    if (Tipo == tr("Anual"))
        Valor = 1;
    return Valor;
}

void ConversorUD::on_lineEdit_27_textChanged(const QString &arg1)
{
    if (AmortizacionP == 0)
    {
        if (arg1 != "")
        {
            QString Valor;
            Valor = VerNum(arg1,1);
            if (Valor == "Si")
            {
                QMessageBox m;
                m.setWindowTitle(tr("Advertencia!!!"));
                m.setText(tr("Has introducido un caracter no valido."));
                m.exec();
                ui->lineEdit_27->setFocus();
                QString Resto = ui->lineEdit_27->text();
                Resto.chop(1);
                ui->lineEdit_27->setText(Resto);
                return;
            }
        }
    }
}

void ConversorUD::on_lineEdit_27_returnPressed()
{
    QString Valor;
    AmortizacionP = 1;
    ui->lineEdit_29->setFocus();
    Valor = PonerMil(ui->lineEdit_27->text());
    ui->lineEdit_27->setText(Valor);
}

QString ConversorUD::PonerMil(QString Valor)
{
    double Value;
    QString Parcial;
    Value = Valor.toDouble();
    Parcial = QString("%L1").arg(Value,0,'f',2);
    return Parcial;
}

QString ConversorUD::QuitarMil(QString Valor)
{
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
        Idioma = "Es";
    }
    else if ( cantidad44 == "2")
    {
        Idioma = "En";
    }
    if (Idioma == "Es")
    {
        Valor.remove(".");
        Valor.replace(",",".");
    }
    if (Idioma == "En")
    {
        Valor.remove(",");
    }
    return Valor;
}

void ConversorUD::on_lineEdit_29_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor;
        Valor = VerNum(arg1,1);
        if (Valor == "Si")
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_29->setFocus();
            QString Resto = ui->lineEdit_29->text();
            Resto.chop(1);
            ui->lineEdit_29->setText(Resto);
            return;
        }
        else
        {
            QString Valor;
            int Tipo;
            double Parte, Resto;
            Valor = ui->comboBox_5->currentText();
            Tipo = Periodo(Valor);
            Parte = ui->lineEdit_29->text().toDouble();
            Resto = (Parte/Tipo)/100;
            ui->lineEdit_30->setText(QString::number(Resto));
        }
    }
}

void ConversorUD::on_lineEdit_29_returnPressed()
{
    ui->lineEdit_31->setFocus();
}

void ConversorUD::on_lineEdit_31_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor;
        Valor = VerNum(arg1,0);
        if (Valor == "Si")
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_31->setFocus();
            QString Resto = ui->lineEdit_31->text();
            Resto.chop(1);
            ui->lineEdit_31->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_lineEdit_31_returnPressed()
{
    if (ui->lineEdit_31->text() != "" && ui->lineEdit_31->text() != "0")
        this->on_pushButton_14_clicked();
    else
        ui->lineEdit_32->setText("");
}

void ConversorUD::on_comboBox_5_currentIndexChanged(int index)
{
    if (ui->lineEdit_27->text() != "" && ui->lineEdit_29->text() != "" && ui->lineEdit_31->text() != "")
    {
        this->on_pushButton_14_clicked();
    }
}


void ConversorUD::on_comboBox_7_currentIndexChanged(int index)
{
    if (ui->lineEdit_27->text() != "" && ui->lineEdit_29->text() != "" && ui->lineEdit_31->text() != "")
    {
        this->on_pushButton_14_clicked();
    }
}

void ConversorUD::on_pushButton_13_clicked()
{
    Calculadora *Calcula=new Calculadora(this);
    if (Stilo == "A")
        Calcula->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    Calcula->show();
}

void ConversorUD::Comprobar2()
{
    if (ui->radioButton_6->isChecked())
    {
        ui->groupBox->setVisible(true);
        ui->groupBox_2->setVisible(true);
        ui->groupBox_3->setVisible(true);
        ui->groupBox_4->setVisible(true);
        ui->groupBox_5->setVisible(true);
        ui->textEdit->setVisible(true);
        ui->textEdit_2->setVisible(true);
        ui->groupBox_8->setVisible(false);
        ui->groupBox_9->setVisible(false);
        ui->groupBox_7->setVisible(false);
        ui->groupBox_6->setVisible(false);
        ui->groupBox_10->setVisible(false);
    }
    if (ui->radioButton_7->isChecked())
    {
        ui->groupBox->setVisible(false);
        ui->groupBox_2->setVisible(false);
        ui->groupBox_3->setVisible(false);
        ui->groupBox_4->setVisible(false);
        ui->groupBox_5->setVisible(false);
        ui->textEdit->setVisible(false);
        ui->textEdit_2->setVisible(false);
        ui->groupBox_8->setVisible(true);
        ui->groupBox_9->setVisible(true);
        ui->groupBox_7->setVisible(true);
        ui->groupBox_6->setVisible(true);
        ui->groupBox_10->setVisible(true);
    }
}

void ConversorUD::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked())
    {
        int Cantidad = ui->lineEdit_32->text().toInt();
        for (int a=0;a<Cantidad;a++)
        {
            ui->comboBox_10->addItem(QString::number(a));
        }
        ui->groupBox_12->setVisible(true);
        if (ui->comboBox_10->currentText().toInt() != 0)
        {
            ui->lineEdit_28->setText("");
            ui->lineEdit_33->setText("");
            ui->lineEdit_34->setText("");
            int Borrado, x;
            Borrado = ui->tableWidget->rowCount();
            for(x=0;x<Borrado;x++)
            {
                 ui->tableWidget->removeRow(x);
                 x=x-1;
                 Borrado=Borrado-1;
            }
        }
    }
    else
    {
        ui->groupBox_12->setVisible(false);
        ui->comboBox_10->clear();
        this->on_pushButton_14_clicked();
    }
}

void ConversorUD::on_comboBox_10_currentIndexChanged(int index)
{    
    this->on_pushButton_14_clicked();
}

void ConversorUD::Comprobar3()
{
    if (ui->radioButton_8->isChecked())
    {
        if (ui->comboBox_10->currentText().toInt() != 0)
            this->on_pushButton_14_clicked();
    }
    if (ui->radioButton_9->isChecked())
    {
        if (ui->comboBox_10->currentText().toInt() != 0)
        this->on_pushButton_14_clicked();
    }
}

void ConversorUD::on_lineEdit_15_returnPressed()
{
    if (ui->lineEdit_15->text() != "")
    {
        ui->lineEdit_18->setFocus();
        ui->lineEdit_18->selectAll();
    }
    else
    {
        ui->lineEdit_15->setFocus();
        ui->lineEdit_15->selectAll();
    }
}

void ConversorUD::on_lineEdit_15_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,0);
        if (Valor == "Si")
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_15->setFocus();
            QString Resto = ui->lineEdit_15->text();
            Resto.chop(1);
            ui->lineEdit_15->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_lineEdit_18_returnPressed()
{
    if (ui->lineEdit_18->text() != "")
    {
        ui->lineEdit_17->setFocus();
        ui->lineEdit_17->selectAll();
    }
    else
    {
        ui->lineEdit_18->setFocus();
        ui->lineEdit_18->selectAll();
    }
}

void ConversorUD::on_lineEdit_17_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,0);
        if (Valor == "Si")
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_17->setFocus();
            QString Resto = ui->lineEdit_17->text();
            Resto.chop(1);
            ui->lineEdit_17->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_lineEdit_17_returnPressed()
{
    if (ui->lineEdit_17->text() == "")
        ui->lineEdit_16->setText("");
    else
    {
        QString Digito1, Digito2;
        double Posicion, Posicion1, DigitX1, DigitX2;
        double Resultado1, Resultado2;
        double Posicion11, Posicion12, Posicion13, Posicion14, Posicion15, Posicion16, Posicion17, Posicion18;
        double Posicion21, Posicion22, Posicion23, Posicion24, Posicion25, Posicion26, Posicion27, Posicion28, Posicion29, Posicion30;
        double Pose = 3;
        Digito1.append(ui->lineEdit_15->text());
        Digito1.append(ui->lineEdit_18->text());
        QStringList Digit1 = Digito1.split("");
        for (int a=1;a<Digit1.count()-1;a++)
        {
            Posicion = Digit1.value(a).toInt();
            Posicion1 = CalculoDC(Pose,Posicion);
            Pose++;
            if (a == 1)
                Posicion11 = Posicion1;
            if (a == 2)
                Posicion12 = Posicion1;
            if (a == 3)
                Posicion13 = Posicion1;
            if (a == 4)
                Posicion14 = Posicion1;
            if (a == 5)
                Posicion15 = Posicion1;
            if (a == 6)
                Posicion16 = Posicion1;
            if (a == 7)
                Posicion17 = Posicion1;
            if (a == 8)
                Posicion18 = Posicion1;
        }
        Digito2.append(ui->lineEdit_17->text());
        QStringList Digit2 = Digito2.split("");
        for (int a=1;a<Digit2.count()-1;a++)
        {
            Posicion = Digit2.value(a).toInt();
            Posicion1 = CalculoDC(a,Posicion);
            if (a == 1)
                Posicion21 = Posicion1;
            if (a == 2)
                Posicion22 = Posicion1;
            if (a == 3)
                Posicion23 = Posicion1;
            if (a == 4)
                Posicion24 = Posicion1;
            if (a == 5)
                Posicion25 = Posicion1;
            if (a == 6)
                Posicion26 = Posicion1;
            if (a == 7)
                Posicion27 = Posicion1;
            if (a == 8)
                Posicion28 = Posicion1;
            if (a == 9)
                Posicion29 = Posicion1;
            if (a == 10)
                Posicion30 = Posicion1;
        }
        DigitX1=Posicion11+Posicion12+Posicion13+Posicion14+Posicion15+Posicion16+Posicion17+Posicion18;
        DigitX2=Posicion21+Posicion22+Posicion23+Posicion24+Posicion25+Posicion26+Posicion27+Posicion28+Posicion29+Posicion30;
        Resultado1 = DigitX1/11;
        Resultado2 = DigitX2/11;
        QString Resulta1 = QString::number(Resultado1,'f',2);
        QStringList Resto1 = Resulta1.split(".");
        QString VResto1 = "0."+Resto1.value(1);
        int ValorResto1 = VResto1.toDouble()*11;
        int ValorDigito = 11-ValorResto1;
        if (ValorDigito == 10)
            ValorDigito = 1;
        if (ValorDigito == 11)
            ValorDigito = 0;
        QString Resulta2 = QString::number(Resultado2);
        QStringList Resto2 = Resulta2.split(".");
        QString VResto2 = "0."+Resto2.value(1);
        int ValorResto2 = VResto2.toFloat()*11;
        int ValorDigito1 = 11-ValorResto2;
        if (ValorDigito1 == 10)
            ValorDigito1 = 1;
        if (ValorDigito1 == 11)
            ValorDigito1 = 0;
        ui->lineEdit_16->setText(""+QString::number(ValorDigito)+""+QString::number(ValorDigito1)+"");
    }
}

int ConversorUD::CalculoDC(int Numero, int Digit)
{
    int Digito;
    if (Numero == 1)
        Digito = Digit*1;
    if (Numero == 2)
        Digito = Digit*2;
    if (Numero == 3)
        Digito = Digit*4;
    if (Numero == 4)
        Digito = Digit*8;
    if (Numero == 5)
        Digito = Digit*5;
    if (Numero == 6)
        Digito = Digit*10;
    if (Numero == 7)
        Digito = Digit*9;
    if (Numero == 8)
        Digito = Digit*7;
    if (Numero == 9)
        Digito = Digit*3;
    if (Numero == 10)
        Digito = Digit*6;
    return Digito;
}
