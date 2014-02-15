#include "conversorud.h"
#include "ui_conversorud.h"
#include <QSqlQuery>
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>
#include <QBuffer>
#include <QTest>
#include <QProgressDialog>
#include <QProcess>
#include <QFuture>
#include <QtConcurrentRun>




// http://www.convertworld.com/es/almacenamiento-de-datos/?c=a




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
    QString pais;
    QSqlQuery Pais(db);
    Pais.exec("SELECT Tipo FROM Pais WHERE id=1");
    Pais.first();
    if (Pais.isValid())
        pais=Pais.value(0).toString();
    qDebug() << pais;
    if (pais == "1")
    {
        ui->groupBox_6->setVisible(true);
        ui->groupBox_7->setVisible(true);
    }
    else if (pais == "2")
    {
        ui->groupBox_6->setVisible(false);
        ui->groupBox_7->setVisible(false);
    }
    ui->comboBox_11->setCurrentIndex(ui->comboBox_11->findText(tr("Ano")));
    ui->comboBox_12->setCurrentIndex(ui->comboBox_12->findText(tr("Ano")));
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("Metro (m)")));
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(tr("Centimetro (cm)")));
    ui->comboBox_26->setCurrentIndex(ui->comboBox_26->findText(tr("Gal")));
    ui->comboBox_27->setCurrentIndex(ui->comboBox_27->findText(tr("Fuerza G (g)")));
    ui->comboBox_19->setCurrentIndex(ui->comboBox_19->findText(tr("Byte (B)")));
    ui->comboBox_20->setCurrentIndex(ui->comboBox_20->findText(tr("Kilobyte (KB)")));
    ui->comboBox_24->setCurrentIndex(ui->comboBox_24->findText(tr("Gigabyte por segundo (GB/s)")));
    ui->comboBox_30->setCurrentIndex(ui->comboBox_30->findText(tr("Kilobyte por segundo (kB/s)")));
    ui->comboBox_21->setCurrentIndex(ui->comboBox_21->findText(tr("Circulo")));
    ui->comboBox_22->setCurrentIndex(ui->comboBox_22->findText(tr("Giro")));
    ui->comboBox_4->setCurrentIndex(ui->comboBox_4->findText(tr("Metro cuadrado (m²)")));
    ui->comboBox_6->setCurrentIndex(ui->comboBox_6->findText(tr("Metro cuadrado (m²)")));
    ui->comboBox_17->setCurrentIndex(ui->comboBox_17->findText(tr("Lumen hora (lm·h)")));
    ui->comboBox_31->setCurrentIndex(ui->comboBox_31->findText(tr("Lumen hora (lm·h)")));
    ui->comboBox_50->setCurrentIndex(ui->comboBox_50->findText(tr("Mol (mol)")));
    ui->comboBox_51->setCurrentIndex(ui->comboBox_51->findText(tr("Mol (mol)")));
    ui->comboBox_46->setCurrentIndex(ui->comboBox_46->findText(tr("Culombios (C)")));
    ui->comboBox_47->setCurrentIndex(ui->comboBox_47->findText(tr("Culombios (C)")));
    ui->comboBox_44->setCurrentIndex(ui->comboBox_44->findText(tr("Metros cubicos por segundo (m³/s)")));
    ui->comboBox_45->setCurrentIndex(ui->comboBox_45->findText(tr("Metros cubicos por segundo (m³/s)")));
    ui->comboBox_54->setCurrentIndex(ui->comboBox_54->findText(tr("Siemens (S)")));
    ui->comboBox_55->setCurrentIndex(ui->comboBox_55->findText(tr("Siemens (S)")));
    ui->comboBox_53->setCurrentIndex(ui->comboBox_53->findText(tr("Litros por 100 kilometros (l/100 km)")));
    ui->comboBox_56->setCurrentIndex(ui->comboBox_56->findText(tr("Litros por 100 kilometros (l/100 km)")));
    Decimales = 20;
    ui->comboBox->insertSeparator(11);
    ui->comboBox->insertSeparator(25);
    ui->comboBox->insertSeparator(28);
    ui->comboBox_2->insertSeparator(11);
    ui->comboBox_2->insertSeparator(25);
    ui->comboBox_2->insertSeparator(28);
    ui->comboBox_19->insertSeparator(8);
    ui->comboBox_20->insertSeparator(8);
    ui->comboBox_24->insertSeparator(18);
    ui->comboBox_24->insertSeparator(37);
    ui->comboBox_30->insertSeparator(18);
    ui->comboBox_30->insertSeparator(37);
    ui->comboBox_4->insertSeparator(9);
    ui->comboBox_6->insertSeparator(9);
    ui->comboBox_4->insertSeparator(20);
    ui->comboBox_6->insertSeparator(20);
    ui->comboBox_4->insertSeparator(25);
    ui->comboBox_6->insertSeparator(25);
    ui->comboBox_50->insertSeparator(3);
    ui->comboBox_51->insertSeparator(3);
    ui->comboBox_48->insertSeparator(11);
    ui->comboBox_49->insertSeparator(11);
    ui->comboBox_48->insertSeparator(22);
    ui->comboBox_49->insertSeparator(22);
    ui->comboBox_46->insertSeparator(6);
    ui->comboBox_47->insertSeparator(6);
    ui->comboBox_44->insertSeparator(14);
    ui->comboBox_45->insertSeparator(14);
    ui->comboBox_44->insertSeparator(28);
    ui->comboBox_45->insertSeparator(28);
    ui->comboBox_44->insertSeparator(43);
    ui->comboBox_45->insertSeparator(43);
    ui->comboBox_44->insertSeparator(58);
    ui->comboBox_45->insertSeparator(58);
    ui->comboBox_54->insertSeparator(7);
    ui->comboBox_55->insertSeparator(7);
    ui->comboBox_53->insertSeparator(4);
    ui->comboBox_56->insertSeparator(4);
    ui->comboBox_53->insertSeparator(7);
    ui->comboBox_56->insertSeparator(7);
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
    ui->tabWidget->setCurrentPage(0);
    this->Comprobar2();
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->lineEdit->setFocus();
    ui->radioButton_2->setChecked(true);
    ui->radioButton_3->setChecked(true);
    ui->label_37->setVisible(false);
    AmortizacionP = 0;
    ui->groupBox_12->setVisible(false);
    ui->comboBox_25->setCurrentText(tr("Distancia o Longitud"));
    ui->lineEdit_55->setText("28");
    ui->label_135->setText("");
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
    ui->lineEdit_47->installEventFilter(this);
    ui->lineEdit_40->installEventFilter(this);
    ui->lineEdit_45->installEventFilter(this);
    ui->lineEdit_42->installEventFilter(this);
    ui->lineEdit_50->installEventFilter(this);
    ui->lineEdit_4->installEventFilter(this);
    ui->lineEdit_39->installEventFilter(this);
    ui->lineEdit_55->installEventFilter(this);
    ui->lineEdit_37->installEventFilter(this);
    ui->lineEdit_156->installEventFilter(this);
    ui->lineEdit_154->installEventFilter(this);
    ui->lineEdit_152->installEventFilter(this);
    ui->lineEdit_150->installEventFilter(this);
    ui->lineEdit_160->installEventFilter(this);
    ui->lineEdit_159->installEventFilter(this);
    this->installEventFilter(this);
    QFuture<void> f1 = QtConcurrent::run(this, &ConversorUD::Divisa);
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
                ayuda->Valor(tr("Conversor"));
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
            if (keyEvent->key() == Qt::Key_Up)
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
            if (keyEvent->key() == Qt::Key_Up)
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
            if (keyEvent->key() == Qt::Key_Down)
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
            if (keyEvent->key() == Qt::Key_Up)
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
            if (keyEvent->key() == Qt::Key_Down)
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
            if (keyEvent->key() == Qt::Key_Up)
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
            if (keyEvent->key() == Qt::Key_Up)
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
            if (keyEvent->key() == Qt::Key_Up)
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
            if (keyEvent->key() == Qt::Key_Down)
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
            if (keyEvent->key() == Qt::Key_Up)
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
            if (keyEvent->key() == Qt::Key_Down)
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
            if (keyEvent->key() == Qt::Key_Down)
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
            if (keyEvent->key() == Qt::Key_Up)
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
            if (keyEvent->key() == Qt::Key_Down)
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
            if (keyEvent->key() == Qt::Key_Up)
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
            if (keyEvent->key() == Qt::Key_Down)
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
            if (keyEvent->key() == Qt::Key_Up)
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
            if (keyEvent->key() == Qt::Key_Down)
            {
                ui->lineEdit_15->setFocus();
                ui->lineEdit_15->selectAll();
                return true;
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Up)
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
            if (keyEvent->key() == Qt::Key_Down)
            {
                ui->lineEdit_18->setFocus();
                ui->lineEdit_18->selectAll();
                return true;
            }
        }
        return false;
    }
    if (obj == ui->lineEdit_47)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_47->setFocus();
            ui->lineEdit_47->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_40)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_40->setFocus();
            ui->lineEdit_40->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_45)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_45->setFocus();
            ui->lineEdit_45->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_42)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_42->setFocus();
            ui->lineEdit_42->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_50)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_50->setFocus();
            ui->lineEdit_50->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_4)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_4->setFocus();
            ui->lineEdit_4->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_39)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_39->setFocus();
            ui->lineEdit_39->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_55)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_55->setFocus();
            ui->lineEdit_55->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_37)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_37->setFocus();
            ui->lineEdit_37->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_156)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_156->setFocus();
            ui->lineEdit_156->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_154)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_154->setFocus();
            ui->lineEdit_154->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_152)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_152->setFocus();
            ui->lineEdit_152->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_150)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_150->setFocus();
            ui->lineEdit_150->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_160)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_160->setFocus();
            ui->lineEdit_160->selectAll();
            return true;
        }
        return false;
    }
    if (obj == ui->lineEdit_159)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            ui->lineEdit_159->setFocus();
            ui->lineEdit_159->selectAll();
            return true;
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
    ui->lineEdit_2->setText("");
    ui->lineEdit_2->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_pushButton_8_clicked()
{
    ui->lineEdit_8->setText("");
    ui->lineEdit_8->setFocus();
    ui->lineEdit_7->setText("");
    ui->lineEdit_7->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_pushButton_9_clicked()
{
    ui->lineEdit_12->setText("");
    ui->lineEdit_12->setFocus();
    ui->lineEdit_11->setText("");
    ui->lineEdit_11->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
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
    ui->lineEdit_3->setText("");
    ui->lineEdit_3->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_pushButton_11_clicked()
{
    ui->lineEdit_10->setText("");
    ui->lineEdit_10->setFocus();
    ui->lineEdit_9->setText("");
    ui->lineEdit_9->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_pushButton_6_clicked()
{
    ui->lineEdit_15->setText("");
    ui->lineEdit_16->setText("");
    ui->lineEdit_17->setText("");
    ui->lineEdit_18->setText("");
    ui->label_135->setText("");
    ui->lineEdit_125->setText("");
    ui->lineEdit_124->setText("");
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
    if (ui->lineEdit_27->text() != "" && ui->lineEdit_29->text() != "" && ui->lineEdit_31->text() != "")
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
        ui->tabWidget->setVisible(true);
        ui->textEdit->setVisible(true);
        ui->textEdit_2->setVisible(true);
        ui->groupBox_8->setVisible(false);
        ui->groupBox_9->setVisible(false);
        ui->groupBox_7->setVisible(false);
        ui->groupBox_6->setVisible(false);
        ui->groupBox_10->setVisible(false);
        ui->comboBox_25->setVisible(true);
        ui->groupBox_20->setVisible(true);
    }
    if (ui->radioButton_7->isChecked())
    {
        ui->tabWidget->setVisible(false);
        ui->textEdit->setVisible(false);
        ui->textEdit_2->setVisible(false);
        ui->groupBox_8->setVisible(true);
        ui->groupBox_9->setVisible(true);
        QString pais;
        QSqlQuery Pais(db);
        Pais.exec("SELECT Tipo FROM Pais WHERE id=1");
        Pais.first();
        if (Pais.isValid())
            pais=Pais.value(0).toString();
        qDebug() << pais;
        if (pais == "1")
        {
            ui->groupBox_6->setVisible(true);
            ui->groupBox_7->setVisible(true);
        }
        else if (pais == "2")
        {
            ui->groupBox_6->setVisible(false);
            ui->groupBox_7->setVisible(false);
        }
        ui->groupBox_10->setVisible(true);
        ui->comboBox_25->setVisible(false);
        ui->groupBox_20->setVisible(false);
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
        if (ui->lineEdit_28->text() != "")
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
        int Pose = 3;
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
        QStringList Resta1 = Resulta1.split(".");
        QString VResto1 = Resta1.value(0);
        int ValorResto1 = DigitX1-(VResto1.toInt()*11);
        int ValorDigito = 11-ValorResto1;
        if (ValorDigito == 10)
            ValorDigito = 1;
        if (ValorDigito == 11)
            ValorDigito = 0;
        QString Resulta2 = QString::number(Resultado2,'f',2);
        QStringList Resta2 = Resulta2.split(".");
        QString VResto2 = Resta2.value(0);
        int ValorResto2 = DigitX2-(VResto2.toInt()*11);
        int ValorDigito1 = 11-ValorResto2;
        if (ValorDigito1 == 10)
            ValorDigito1 = 1;
        if (ValorDigito1 == 11)
            ValorDigito1 = 0;
        ui->lineEdit_16->setText(""+QString::number(ValorDigito)+""+QString::number(ValorDigito1)+"");
        QString ValorIban = ui->lineEdit_15->text()+ui->lineEdit_18->text()+ui->lineEdit_16->text()+ui->lineEdit_17->text()+"142800";                
        QString Parte1 = ValorIban.mid(0,9);
        QString Parte2 = ValorIban.mid(9,7);
        QString Parte3 = ValorIban.mid(16,7);
        QString Parte4 = ValorIban.mid(23,4);
        double Resto1Iban = Parte1.toDouble()/97;
        QString Resto1 = QString::number(Resto1Iban,'f',10);
        QStringList Resto1Calc = Resto1.split(".");
        double RestoPar1 = Resto1Calc.value(0).toDouble();
        double Final1 = Parte1.toDouble()-(RestoPar1*97);
        QString Value1 = QString::number(Final1);
        QString Valor2 = Value1+Parte2;
        double Resto2Iban = Valor2.toDouble()/97;
        QString Resto2 = QString::number(Resto2Iban,'f',10);
        QStringList Resto2Calc = Resto2.split(".");
        double RestoPar2 = Resto2Calc.value(0).toDouble();
        double Final2 = Valor2.toDouble()-(RestoPar2*97);
        QString Value2 = QString::number(Final2);
        QString Valor3 = Value2+Parte3;
        double Resto3Iban = Valor3.toDouble()/97;
        QString Resto3 = QString::number(Resto3Iban,'f',10);
        QStringList Resto3Calc = Resto3.split(".");
        double RestoPar3 = Resto3Calc.value(0).toDouble();
        double Final3 = Valor3.toDouble()-(RestoPar3*97);
        QString Value3 = QString::number(Final3);
        QString Valor4 = Value3+Parte4;
        double Resto4Iban = Valor4.toDouble()/97;
        QString Resto4 = QString::number(Resto4Iban,'f',10);
        QStringList Resto4Calc = Resto4.split(".");
        double RestoPar4 = Resto4Calc.value(0).toDouble();
        double Final4 = Valor4.toDouble()-(RestoPar4*97);
        QString Value4 = QString::number(Final4);
        int Total = 98-Value4.toInt();
        QString ValorES;
        if (Total < 10)
            ValorES = "0"+QString::number(Total);
        else
            ValorES = QString::number(Total);
        QString Resultado = "ES"+ValorES;
        ui->lineEdit_124->setText(Resultado);
        QString Nombre, Bic;
        QSqlQuery query(db);
        query.exec("SELECT Nombre,Bic FROM Bic WHERE Codigo='"+ui->lineEdit_15->text()+"'");
        query.first();
        if (query.isValid())
        {
            Nombre=query.value(0).toString();
            Bic=query.value(1).toString();
        }
        ui->lineEdit_125->setText(Bic);
        ui->label_135->setText(Nombre);
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

void ConversorUD::on_comboBox_activated(const QString &arg1)
{
    if (ui->lineEdit->text() == "")
    {
        ui->lineEdit_2->setText("");
        ui->lineEdit_2->setToolTip("");
    }
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
            ui->lineEdit_2->setToolTip(Zero);
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
            ui->lineEdit_2->setToolTip(Zero);
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
            {
                ui->lineEdit_2->setText("");
                ui->lineEdit_2->setToolTip("");
            }
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
                    ui->lineEdit_2->setToolTip(Zero);
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
                    ui->lineEdit_2->setToolTip(Zero);
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
    {
        ui->lineEdit_2->setText("");
        ui->lineEdit_2->setToolTip("");
    }
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
            ui->lineEdit_2->setToolTip(Zero);
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
            ui->lineEdit_2->setToolTip(Zero);
        }
    }
    Reprobar("Longitud");
}

void ConversorUD::on_lineEdit_returnPressed()
{
    ui->lineEdit->setFocus();
    ui->lineEdit->selectAll();
}

void ConversorUD::on_pushButton_20_clicked()
{
    ui->lineEdit_46->setText("");
    ui->lineEdit_46->setFocus();
    ui->lineEdit_47->setText("");
    ui->lineEdit_47->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_lineEdit_47_returnPressed()
{
    ui->lineEdit_47->setFocus();
    ui->lineEdit_47->selectAll();
}

void ConversorUD::on_lineEdit_47_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_47->text() == "")
            {
                ui->lineEdit_46->setText("");
                ui->lineEdit_46->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_26->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Aceleracion");
                QString Valor1 = ui->comboBox_27->currentText();
                double Resto1 = Referencia(Valor1,"Aceleracion");
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
                    ui->lineEdit_46->setText(Zero);
                    ui->lineEdit_46->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_46->setText(Zero);
                    ui->lineEdit_46->setToolTip(Zero);
                }
            }
            Reprobar("Aceleracion");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_47->setFocus();
            QString Resto = ui->lineEdit_47->text();
            Resto.chop(1);
            ui->lineEdit_47->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_26_activated(const QString &arg1)
{
    if (ui->lineEdit_47->text() == "")
    {
        ui->lineEdit_46->setText("");
        ui->lineEdit_46->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_47->text().toFloat();
        double Resto = Referencia(Valor,"Aceleracion");
        QString Valor1 = ui->comboBox_27->currentText();
        double Resto1 = Referencia(Valor1,"Aceleracion");
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
            ui->lineEdit_46->setText(Zero);
            ui->lineEdit_46->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_46->setText(Zero);
            ui->lineEdit_46->setToolTip(Zero);
        }
    }
    Reprobar("Aceleracion");
}

void ConversorUD::on_comboBox_27_activated(const QString &arg1)
{
    if (ui->lineEdit_47->text() == "")
    {
        ui->lineEdit_46->setText("");
        ui->lineEdit_46->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_26->currentText();
        double Cantidad = ui->lineEdit_47->text().toFloat();
        double Resto = Referencia(Valor,"Aceleracion");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Aceleracion");
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
            ui->lineEdit_46->setText(Zero);
            ui->lineEdit_46->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_46->setText(Zero);
            ui->lineEdit_46->setToolTip(Zero);
        }
    }
    Reprobar("Aceleracion");
}

void ConversorUD::on_pushButton_17_clicked()
{
    ui->lineEdit_40->setText("");
    ui->lineEdit_40->setFocus();
    ui->lineEdit_41->setText("");
    ui->lineEdit_41->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_lineEdit_40_returnPressed()
{
    ui->lineEdit_40->setFocus();
    ui->lineEdit_40->selectAll();
}

void ConversorUD::on_lineEdit_40_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_40->text() == "")
            {
                ui->lineEdit_41->setText("");
                ui->lineEdit_41->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_19->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Almacenamiento");
                QString Valor1 = ui->comboBox_20->currentText();
                double Resto1 = Referencia(Valor1,"Almacenamiento");
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
                    ui->lineEdit_41->setText(Zero);
                    ui->lineEdit_41->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_41->setText(Zero);
                    ui->lineEdit_41->setToolTip(Zero);
                }
            }
            Reprobar("Almacenamiento");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_40->setFocus();
            QString Resto = ui->lineEdit_40->text();
            Resto.chop(1);
            ui->lineEdit_40->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_19_activated(const QString &arg1)
{
    if (ui->lineEdit_40->text() == "")
    {
        ui->lineEdit_41->setText("");
        ui->lineEdit_41->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_40->text().toFloat();
        double Resto = Referencia(Valor,"Almacenamiento");
        QString Valor1 = ui->comboBox_20->currentText();
        double Resto1 = Referencia(Valor1,"Almacenamiento");
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
            ui->lineEdit_41->setText(Zero);
            ui->lineEdit_41->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_41->setText(Zero);
            ui->lineEdit_41->setToolTip(Zero);
        }
    }
    Reprobar("Almacenamiento");
}

void ConversorUD::on_comboBox_20_activated(const QString &arg1)
{
    if (ui->lineEdit_40->text() == "")
    {
        ui->lineEdit_41->setText("");
        ui->lineEdit_41->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_19->currentText();
        double Cantidad = ui->lineEdit_40->text().toFloat();
        double Resto = Referencia(Valor,"Almacenamiento");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Almacenamiento");
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
            ui->lineEdit_41->setText(Zero);
            ui->lineEdit_41->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_41->setText(Zero);
            ui->lineEdit_41->setToolTip(Zero);
        }
    }
    Reprobar("Almacenamiento");
}

void ConversorUD::on_pushButton_19_clicked()
{
    ui->lineEdit_45->setText("");
    ui->lineEdit_45->setFocus();
    ui->lineEdit_44->setText("");
    ui->lineEdit_44->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_lineEdit_45_returnPressed()
{
    ui->lineEdit_45->setFocus();
    ui->lineEdit_45->selectAll();
}

void ConversorUD::on_lineEdit_45_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_45->text() == "")
            {
                ui->lineEdit_44->setText("");
                ui->lineEdit_44->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_24->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Ancho banda");
                QString Valor1 = ui->comboBox_30->currentText();
                double Resto1 = Referencia(Valor1,"Ancho banda");
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
                    ui->lineEdit_44->setText(Zero);
                    ui->lineEdit_44->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_44->setText(Zero);
                    ui->lineEdit_44->setToolTip(Zero);
                }
            }
            Reprobar("Ancho banda");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_45->setFocus();
            QString Resto = ui->lineEdit_45->text();
            Resto.chop(1);
            ui->lineEdit_45->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_24_activated(const QString &arg1)
{
    if (ui->lineEdit_45->text() == "")
    {
        ui->lineEdit_44->setText("");
        ui->lineEdit_44->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_45->text().toFloat();
        double Resto = Referencia(Valor,"Ancho banda");
        QString Valor1 = ui->comboBox_30->currentText();
        double Resto1 = Referencia(Valor1,"Ancho banda");
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
            ui->lineEdit_44->setText(Zero);
            ui->lineEdit_44->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_44->setText(Zero);
            ui->lineEdit_44->setToolTip(Zero);
        }
    }
    Reprobar("Ancho banda");
}

void ConversorUD::on_comboBox_30_activated(const QString &arg1)
{
    if (ui->lineEdit_45->text() == "")
    {
        ui->lineEdit_44->setText("");
        ui->lineEdit_44->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_24->currentText();
        double Cantidad = ui->lineEdit_45->text().toFloat();
        double Resto = Referencia(Valor,"Ancho banda");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Ancho banda");
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
            ui->lineEdit_44->setText(Zero);
            ui->lineEdit_44->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_44->setText(Zero);
            ui->lineEdit_44->setToolTip(Zero);
        }
    }
    Reprobar("Ancho banda");
}

void ConversorUD::on_lineEdit_12_textChanged(const QString &arg1)
{
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    ui->label_14->setText(tr("Sistema de numeracion: Convertir a...")+ui->comboBox_14->currentText()+"");
    int Value = 0;
    if (arg1 != "")
    {
        if (ui->comboBox_14->currentText() == tr("Binario"))
        {
            if (arg1 != "")
            {
                QString Valor = arg1.right(1);
                if (!Valor.contains("0") && !Valor.contains("1"))
                {
                    QMessageBox m;
                    m.setWindowTitle(tr("Advertencia!!!"));
                    m.setText(tr("Has introducido un caracter no valido.<p>Solo puedes utilizar numeros binarios (0 y 1) en el sistema binario."));
                    m.exec();
                    ui->lineEdit_12->setFocus();
                    QString Resto = ui->lineEdit_12->text();
                    Resto.chop(1);
                    ui->lineEdit_12->setText(Resto);
                    return;
                }
                else
                {
                    int Calculo;
                    QString aux;
                    for (int i = arg1.length()-1;i>-1;i--)
                    {
                        aux += arg1[i];
                    }
                    QStringList VBinary = aux.split("");
                    for(int a=1;a<VBinary.count()-1;a++)
                    {
                        Calculo = GetCalc(VBinary.value(a),a,tr("Binario"));
                        Value = Value+Calculo;
                    }
                }
            }
        }
        if (ui->comboBox_14->currentText() == tr("Octal"))
        {
            if (arg1 != "")
            {
                QString Valor = arg1.right(1);
                QChar ascii;
                int numero;
                ascii=Valor.at(0).toAscii();
                numero=ascii.toAscii() ;
                if (numero >= 48 && numero <=55)
                {
                    int Calculo;
                    QString aux;
                    for (int i = arg1.length()-1;i>-1;i--)
                    {
                        aux += arg1[i];
                    }
                    QStringList VBinary = aux.split("");
                    for(int a=1;a<VBinary.count()-1;a++)
                    {
                        Calculo = GetCalc(VBinary.value(a),a,tr("Octal"));
                        Value = Value+Calculo;
                    }
                }
                else
                {
                    QMessageBox m;
                    m.setWindowTitle(tr("Advertencia!!!"));
                    m.setText(tr("Has introducido un caracter no valido.<p>Solo puedes utilizar numeros octales (de 0 a 7) en el sistema octal."));
                    m.exec();
                    ui->lineEdit_12->setFocus();
                    QString Resto = ui->lineEdit_12->text();
                    Resto.chop(1);
                    ui->lineEdit_12->setText(Resto);
                    return;
                }
            }
        }
        if (ui->comboBox_14->currentText() == tr("Decimal"))
        {
            if (arg1 != "")
            {
                QString Valor = arg1.right(1);
                QChar ascii;
                int numero;
                ascii=Valor.at(0).toAscii();
                numero=ascii.toAscii() ;
                if (numero >= 48 && numero <=57)
                {
                    Value = arg1.toInt();
                }
                else
                {
                    QMessageBox m;
                    m.setWindowTitle(tr("Advertencia!!!"));
                    m.setText(tr("Has introducido un caracter no valido.<p>Solo puedes utilizar numeros decimales (de 0 a 9) en el sistema decimal."));
                    m.exec();
                    ui->lineEdit_12->setFocus();
                    QString Resto = ui->lineEdit_12->text();
                    Resto.chop(1);
                    ui->lineEdit_12->setText(Resto);
                    return;
                    Value = arg1.toInt();
                }
            }
        }
        if (ui->comboBox_14->currentText() == tr("Hexadecimal"))
        {
            if (arg1 != "")
            {
                QString Valor = arg1.right(1);
                QChar ascii;
                int numero;
                ascii=Valor.at(0).toAscii();
                numero=ascii.toAscii() ;
                if ( (numero >= 48 && numero <=57) || (numero >= 65 && numero <=70))
                {
                    int Calculo;
                    QString aux;
                    for (int i = arg1.length()-1;i>-1;i--)
                    {
                        aux += arg1[i];
                    }
                    QStringList VBinary = aux.split("");
                    for(int a=1;a<VBinary.count()-1;a++)
                    {
                        Calculo = GetCalc(VBinary.value(a),a,tr("Hexadecimal"));
                        Value = Value+Calculo;
                    }
                }
                else
                {
                    QMessageBox m;
                    m.setWindowTitle(tr("Advertencia!!!"));
                    m.setText(tr("Has introducido un caracter no valido.<p>Solo puedes utilizar numeros hexadecimal (de 0 a 9 y de A a F (MAYUSCULAS)) en el sistema hexadecimal."));
                    m.exec();
                    ui->lineEdit_12->setFocus();
                    QString Resto = ui->lineEdit_12->text();
                    Resto.chop(1);
                    ui->lineEdit_12->setText(Resto);
                    return;
                }
            }
        }
        for(int b=0;b<4;b++)
        {
            if (b == 0)
            {
                QString Valor, VBinario, Parte;
                double Resto, Fin;
                int Parcial, Final;
                QString Valorar = QString::number(Value,'f',1);
                Fin = Valorar.toDouble();
                Final = 1;
                while (Final != 0)
                {
                    Resto = Fin/2;
                    Valor = QString::number(Resto);
                    QStringList Valor1 = Valor.split(".");
                    Final = Valor1.value(0).toInt();
                    Fin = Valor1.value(0).toDouble();
                    Parte = "0."+Valor1.value(1);
                    Parcial = Parte.toDouble()*2;
                    if ( Parcial > 0 )
                        VBinario.append("1");
                    else
                        VBinario.append("0");
                }
                QString aux;
                for (int i = VBinario.length()-1;i>-1;i--)
                {
                    aux += VBinario[i];
                }
                ui->textEdit->append(""+arg1+" "+ui->comboBox_14->currentText()+tr(" es igual a ")+aux+tr(" en Binario"));
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            if (b == 1)
            {
                QString Valor, VBinario, Parte;
                double Resto, Fin;
                int Parcial, Final;
                QString Valorar = QString::number(Value,'f',1);
                Fin = Valorar.toDouble();
                Final = 1;
                while (Final != 0)
                {
                    Resto = Fin/8;
                    Valor = QString::number(Resto);
                    QStringList Valor1 = Valor.split(".");
                    Final = Valor1.value(0).toInt();
                    Fin = Valor1.value(0).toDouble();
                    Parte = "0."+Valor1.value(1);
                    Parcial = Parte.toDouble()*8;
                    VBinario.append(QString::number(Parcial));
                }
                QString aux;
                for (int i = VBinario.length()-1;i>-1;i--)
                {
                    aux += VBinario[i];
                }
                ui->textEdit->append(""+arg1+" "+ui->comboBox_14->currentText()+tr(" es igual a ")+aux+tr(" en Octal"));
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            if (b == 2)
            {
                ui->textEdit->append(""+arg1+" "+ui->comboBox_14->currentText()+tr(" es igual a ")+QString::number(Value)+tr(" en Decimal"));
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            if (b == 3)
            {
                QString Valor, VBinario, Parte, Resultado;
                double Resto, Fin;
                int Parcial, Final;
                QString Valorar = QString::number(Value,'f',1);
                Fin = Valorar.toDouble();
                Final = 1;
                while (Final != 0)
                {
                    Resto = Fin/16;
                    Valor = QString::number(Resto);
                    QStringList Valor1 = Valor.split(".");
                    Final = Valor1.value(0).toInt();
                    Fin = Valor1.value(0).toDouble();
                    Parte = "0."+Valor1.value(1);
                    Parcial = Parte.toDouble()*16;
                    Resultado = QString::number(Parcial);
                    if (Parcial == 10)
                        Resultado = "A";
                    if (Parcial == 11)
                        Resultado = "B";
                    if (Parcial == 12)
                        Resultado = "C";
                    if (Parcial == 13)
                        Resultado = "D";
                    if (Parcial == 14)
                        Resultado = "E";
                    VBinario.append(Resultado);
                }
                QString aux;
                for (int i = VBinario.length()-1;i>-1;i--)
                {
                    aux += VBinario[i];
                }
                ui->textEdit->append(""+arg1+" "+ui->comboBox_14->currentText()+tr(" es igual a ")+aux+tr(" en Hexadecimal"));
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
        if (ui->comboBox_15->currentText() == tr("Binario"))
        {
            QString Valor, VBinario, Parte;
            double Resto, Fin;
            int Parcial, Final;
            QString Valorar = QString::number(Value,'f',1);
            Fin = Valorar.toDouble();
            Final = 1;
            while (Final != 0)
            {
                Resto = Fin/2;
                Valor = QString::number(Resto);
                QStringList Valor1 = Valor.split(".");
                Final = Valor1.value(0).toInt();
                Fin = Valor1.value(0).toDouble();
                Parte = "0."+Valor1.value(1);
                Parcial = Parte.toDouble()*2;
                if ( Parcial > 0 )
                    VBinario.append("1");
                else
                    VBinario.append("0");
            }
            QString aux;
            for (int i = VBinario.length()-1;i>-1;i--)
            {
                aux += VBinario[i];
            }
            ui->lineEdit_11->setText(aux);
        }
        if (ui->comboBox_15->currentText() == tr("Octal"))
        {
            QString Valor, VBinario, Parte;
            double Resto, Fin;
            int Parcial, Final;
            QString Valorar = QString::number(Value,'f',1);
            Fin = Valorar.toDouble();
            Final = 1;
            while (Final != 0)
            {
                Resto = Fin/8;
                Valor = QString::number(Resto);
                QStringList Valor1 = Valor.split(".");
                Final = Valor1.value(0).toInt();
                Fin = Valor1.value(0).toDouble();
                Parte = "0."+Valor1.value(1);
                Parcial = Parte.toDouble()*8;
                VBinario.append(QString::number(Parcial));
            }
            QString aux;
            for (int i = VBinario.length()-1;i>-1;i--)
            {
                aux += VBinario[i];
            }
            ui->lineEdit_11->setText(aux);
        }
        if (ui->comboBox_15->currentText() == tr("Decimal"))
        {
            ui->lineEdit_11->setText(QString::number(Value));
        }
        if (ui->comboBox_15->currentText() == tr("Hexadecimal"))
        {
            QString Valor, VBinario, Parte, Resultado;
            double Resto, Fin;
            int Parcial, Final;
            QString Valorar = QString::number(Value,'f',1);
            Fin = Valorar.toDouble();
            Final = 1;
            while (Final != 0)
            {
                Resto = Fin/16;
                Valor = QString::number(Resto);
                QStringList Valor1 = Valor.split(".");
                Final = Valor1.value(0).toInt();
                Fin = Valor1.value(0).toDouble();
                Parte = "0."+Valor1.value(1);
                Parcial = Parte.toDouble()*16;
                Resultado = QString::number(Parcial);
                if (Parcial == 10)
                    Resultado = "A";
                if (Parcial == 11)
                    Resultado = "B";
                if (Parcial == 12)
                    Resultado = "C";
                if (Parcial == 13)
                    Resultado = "D";
                if (Parcial == 14)
                    Resultado = "E";
                VBinario.append(Resultado);
            }
            QString aux;
            for (int i = VBinario.length()-1;i>-1;i--)
            {
                aux += VBinario[i];
            }
            ui->lineEdit_11->setText(aux);
        }
    }
    else
        ui->lineEdit_11->setText("");
}

int ConversorUD::GetCalc(QString Valor, int Posicion, QString Tipo)
{
    int PreValor, Result, Multiplo, Resultado, Final, Posse;
    if (Tipo == tr("Binario"))
        Multiplo = 2;
    if (Tipo == tr("Octal"))
        Multiplo = 8;
    if (Tipo == tr("Hexadecimal"))
           Multiplo = 16;
    Posse = Posicion-1;
    Resultado = Multiplo;
    for(int a=1;a<Posse;a++)
    {
        Result = Resultado*Multiplo;
        Resultado = Result;
    }
    QChar ascii;
    int numero;
    ascii=Valor.at(0).toAscii();
    numero=ascii.toAscii() ;
    if (numero == 65)
        Valor = "10";
    if (numero == 66)
        Valor = "11";
    if (numero == 67)
        Valor = "12";
    if (numero == 68)
        Valor = "13";
    if (numero == 69)
        Valor = "14";
    if (numero == 70)
        Valor = "15";
    PreValor = Valor.toInt();
    if (Posse == 0)
        Final = PreValor;
    else
        Final = PreValor*Resultado;
    return Final;
}

void ConversorUD::on_lineEdit_12_returnPressed()
{
    ui->lineEdit_12->setFocus();
    ui->lineEdit_12->selectAll();
}

void ConversorUD::on_comboBox_14_activated(const QString &arg1)
{
    ui->lineEdit_12->setText("");
}

void ConversorUD::on_comboBox_15_activated(const QString &arg1)
{
    QString Provisional = ui->lineEdit_12->text();
    ui->lineEdit_12->setText("");
    ui->lineEdit_12->setText(Provisional);
}

void ConversorUD::on_lineEdit_50_textChanged(const QString &arg1)
{
    QString Resultado, Valor;
    QStringList Value = arg1.split("");
    for(int a=1;a<Value.count()-1;a++)
    {
        Resultado = tabla(Value.value(a));
        Valor.append(Resultado+" ");
    }
    ui->lineEdit_52->setText(Valor);
    ui->lineEdit_52->setToolTip(Valor);
}

QString ConversorUD::tabla(QString Valor)
{
    QString Value;
    if (Valor == "a")
        Value = "1100001";
    if (Valor == "b")
        Value = "1100010";
    if (Valor == "c")
        Value = "1100011";
    if (Valor == "d")
        Value = "1100100";
    if (Valor == "e")
        Value = "1100101";
    if (Valor == "f")
        Value = "1100110";
    if (Valor == "g")
        Value = "1100111";
    if (Valor == "h")
        Value = "1101000";
    if (Valor == "i")
        Value = "1101001";
    if (Valor == "j")
        Value = "1101010";
    if (Valor == "k")
        Value = "1101011";
    if (Valor == "l")
        Value = "1101100";
    if (Valor == "m")
        Value = "1101101";
    if (Valor == "n")
        Value = "1101110";
    if (Valor == "o")
        Value = "1101111";
    if (Valor == "p")
        Value = "1110000";
    if (Valor == "q")
        Value = "1110001";
    if (Valor == "r")
        Value = "1110010";
    if (Valor == "s")
        Value = "1110011";
    if (Valor == "t")
        Value = "1110100";
    if (Valor == "u")
        Value = "1110101";
    if (Valor == "v")
        Value = "1110110";
    if (Valor == "w")
        Value = "1110111";
    if (Valor == "x")
        Value = "1111000";
    if (Valor == "y")
        Value = "1111001";
    if (Valor == "z")
        Value = "1111010";
    if (Valor == "A")
        Value = "1000001";
    if (Valor == "B")
        Value = "1000010";
    if (Valor == "C")
        Value = "1000011";
    if (Valor == "D")
        Value = "1000100";
    if (Valor == "E")
        Value = "1000101";
    if (Valor == "F")
        Value = "1000110";
    if (Valor == "G")
        Value = "1000111";
    if (Valor == "H")
        Value = "1001000";
    if (Valor == "I")
        Value = "1001001";
    if (Valor == "J")
        Value = "1001010";
    if (Valor == "K")
        Value = "1001011";
    if (Valor == "L")
        Value = "1001100";
    if (Valor == "M")
        Value = "1001101";
    if (Valor == "N")
        Value = "1001110";
    if (Valor == "O")
        Value = "1001111";
    if (Valor == "P")
        Value = "1010000";
    if (Valor == "Q")
        Value = "1010001";
    if (Valor == "R")
        Value = "1010010";
    if (Valor == "S")
        Value = "1010011";
    if (Valor == "T")
        Value = "1010100";
    if (Valor == "U")
        Value = "1010101";
    if (Valor == "V")
        Value = "1010110";
    if (Valor == "W")
        Value = "1010111";
    if (Valor == "X")
        Value = "1011000";
    if (Valor == "Y")
        Value = "1011001";
    if (Valor == "Z")
        Value = "1011010";
    if (Valor == "ñ")
        Value = "11110001";
    if (Valor == "Ñ")
        Value = "11010001";
    if (Valor == "Ñ")
        Value = "0100000";
    return Value;
}

void ConversorUD::on_calendarWidget_clicked(const QDate &date)
{
    QString Fecha, Final;
    int Value;
    if (Idioma == "Es")
    {
        Fecha = date.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Fecha = date.toString("MM-dd-yyyy");
    }
    ui->lineEdit_56->setText(Fecha);
    int Diferencia;
    if (ui->lineEdit_55->text() == "28")
    {
        Value = 0;
        Diferencia = QDate::currentDate().toJulianDay() - date.toJulianDay()+Value;
    }
    else
    {
        Value = ui->lineEdit_55->text().toInt() - 28;
        Diferencia = QDate::currentDate().toJulianDay() - (date.toJulianDay()+Value);
    }
    if (Diferencia >=0)
        ui->lineEdit_54->setText(QString::number(Diferencia));
    else
        ui->calendarWidget->setSelectedDate(QDate::currentDate());
    int Resto = 280-Diferencia;
    ui->lineEdit_51->setText(QString::number(Resto));
    int Ratio = (Diferencia * 100) / 280;
    ui->lineEdit_53->setText(QString::number(Ratio));
    int ValorF = 280+Value;
    QDate FechaF = date.addDays(ValorF);
    if (Idioma == "Es")
    {
        Final = FechaF.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaF.toString("MM-dd-yyyy");
    }
    ui->lineEdit_57->setText(Final);
    this->Semanas();
}

void ConversorUD::on_lineEdit_55_returnPressed()
{
    if (ui->lineEdit_55->text() == "")
        ui->lineEdit_55->setText("28");
    else
    {
        int Valor = ui->lineEdit_55->text().toInt();
        if (Valor < 14)
            ui->lineEdit_55->setText("28");
        else
        {
            if (Valor > 60)
                ui->lineEdit_55->setText("28");
            else
            {
                int Diferencia, Value;
                QString Final;
                if (ui->lineEdit_55->text() == "28")
                {
                    Value = 0;
                    Diferencia = QDate::currentDate().toJulianDay() - ui->calendarWidget->selectedDate().toJulianDay()+Value;
                }
                else
                {
                    Value = ui->lineEdit_55->text().toInt() - 28;
                    Diferencia = QDate::currentDate().toJulianDay() - (ui->calendarWidget->selectedDate().toJulianDay()+Value);
                }
                ui->lineEdit_54->setText(QString::number(Diferencia));
                int Resto = 280-Diferencia;
                ui->lineEdit_51->setText(QString::number(Resto));
                int Ratio = (Diferencia * 100) / 280;
                ui->lineEdit_53->setText(QString::number(Ratio));
                int ValorF = 280+Value;
                QDate FechaF = ui->calendarWidget->selectedDate().addDays(ValorF);
                if (Idioma == "Es")
                {
                    Final = FechaF.toString("dd-MM-yyyy");
                }
                else if (Idioma == "En")
                {
                    Final = FechaF.toString("MM-dd-yyyy");
                }
                ui->lineEdit_57->setText(Final);
            }
        }
    }
    ui->lineEdit_55->setFocus();
    ui->lineEdit_55->selectAll();
    this->Semanas();
}

void ConversorUD::Semanas()
{
    int Value, Posicion;
    QString Final;
    QDate FechaS, FechaS1, FechaS2, FechaS3, FechaS4, FechaS5, FechaS6, FechaS7, FechaS8, FechaS9, FechaS10, FechaS11, FechaS12, FechaS13, FechaS14, FechaS15;
    QDate FechaS16, FechaS17, FechaS18, FechaS19, FechaS20, FechaS21, FechaS22, FechaS23, FechaS24, FechaS25, FechaS26, FechaS27, FechaS28, FechaS29, FechaS30;
    QDate FechaS31, FechaS32, FechaS33, FechaS34, FechaS35, FechaS36, FechaS37, FechaS38, FechaS39, FechaS40, FechaS41, FechaS42, FechaS43, FechaS44, FechaS45;
    QDate FechaS46, FechaS47, FechaS48, FechaS49, FechaS50, FechaS51, FechaS52, FechaS53, FechaS54, FechaS55, FechaS56, FechaS57, FechaS58, FechaS59, FechaS60;
    QDate FechaS61, FechaS62, FechaS63, FechaS64, FechaS65, FechaS66, FechaS67, FechaS68, FechaS69, FechaS70, FechaS71, FechaS72, FechaS73, FechaS74, FechaS75;
    QDate FechaS76, FechaS77, FechaS78, FechaS79;
    Value = ui->lineEdit_55->text().toInt() - 28;
    Posicion = 0;
    FechaS = ui->calendarWidget->selectedDate().addDays(Value);
    if (Idioma == "Es")
    {
        Final = FechaS.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS.toString("MM-dd-yyyy");
    }
    ui->lineEdit_58->setText(Final);
    FechaS1 = FechaS.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS1.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS1.toString("MM-dd-yyyy");
    }
    ui->lineEdit_59->setText(Final);
    if (FechaS1.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_2->setChecked(true);
        Posicion++;
    }    
    FechaS2 = FechaS1.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS2.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS2.toString("MM-dd-yyyy");
    }
    ui->lineEdit_61->setText(Final);
    FechaS3 = FechaS2.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS3.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS3.toString("MM-dd-yyyy");
    }
    ui->lineEdit_60->setText(Final);
    if (FechaS3.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_3->setChecked(true);
        Posicion++;
    }    
    FechaS4 = FechaS3.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS4.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS4.toString("MM-dd-yyyy");
    }
    ui->lineEdit_63->setText(Final);
    FechaS5 = FechaS4.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS5.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS5.toString("MM-dd-yyyy");
    }
    ui->lineEdit_62->setText(Final);
    if (FechaS5.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_4->setChecked(true);
        Posicion++;
    }   
    FechaS6 = FechaS5.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS6.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS6.toString("MM-dd-yyyy");
    }
    ui->lineEdit_65->setText(Final);
    FechaS7 = FechaS6.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS7.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS7.toString("MM-dd-yyyy");
    }
    ui->lineEdit_64->setText(Final);
    if (FechaS7.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_5->setChecked(true);
        Posicion++;
    }    
    FechaS8 = FechaS7.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS8.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS8.toString("MM-dd-yyyy");
    }
    ui->lineEdit_67->setText(Final);
    FechaS9 = FechaS8.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS9.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS9.toString("MM-dd-yyyy");
    }
    ui->lineEdit_66->setText(Final);
    if (FechaS9.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_6->setChecked(true);
        Posicion++;
    }    
    FechaS10 = FechaS9.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS10.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS10.toString("MM-dd-yyyy");
    }
    ui->lineEdit_69->setText(Final);
    FechaS11 = FechaS10.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS11.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS11.toString("MM-dd-yyyy");
    }
    ui->lineEdit_68->setText(Final);
    if (FechaS11.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_7->setChecked(true);
        Posicion++;
    }    
    FechaS12 = FechaS11.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS12.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS12.toString("MM-dd-yyyy");
    }
    ui->lineEdit_71->setText(Final);
    FechaS13 = FechaS12.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS13.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS13.toString("MM-dd-yyyy");
    }
    ui->lineEdit_70->setText(Final);
    if (FechaS13.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_8->setChecked(true);
        Posicion++;
    }    
    FechaS14 = FechaS13.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS14.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS14.toString("MM-dd-yyyy");
    }
    ui->lineEdit_73->setText(Final);
    FechaS15 = FechaS14.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS15.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS15.toString("MM-dd-yyyy");
    }
    ui->lineEdit_72->setText(Final);
    if (FechaS15.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_9->setChecked(true);
        Posicion++;
    }    
    FechaS16 = FechaS15.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS16.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS16.toString("MM-dd-yyyy");
    }
    ui->lineEdit_75->setText(Final);
    FechaS17 = FechaS16.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS17.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS17.toString("MM-dd-yyyy");
    }
    ui->lineEdit_74->setText(Final);
    if (FechaS17.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_10->setChecked(true);
        Posicion++;
    }    
    FechaS18 = FechaS17.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS18.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS18.toString("MM-dd-yyyy");
    }
    ui->lineEdit_77->setText(Final);
    FechaS19 = FechaS18.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS19.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS19.toString("MM-dd-yyyy");
    }
    ui->lineEdit_76->setText(Final);
    if (FechaS19.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_11->setChecked(true);
        Posicion++;
    }    
    FechaS20 = FechaS19.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS20.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS20.toString("MM-dd-yyyy");
    }
    ui->lineEdit_79->setText(Final);
    FechaS21 = FechaS20.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS21.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS21.toString("MM-dd-yyyy");
    }
    ui->lineEdit_78->setText(Final);
    if (FechaS21.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_12->setChecked(true);
        Posicion++;
    }    
    FechaS22 = FechaS21.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS22.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS22.toString("MM-dd-yyyy");
    }
    ui->lineEdit_81->setText(Final);
    FechaS23 = FechaS22.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS23.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS23.toString("MM-dd-yyyy");
    }
    ui->lineEdit_80->setText(Final);
    if (FechaS23.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_13->setChecked(true);
        Posicion++;
    }    
    FechaS24 = FechaS23.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS24.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS24.toString("MM-dd-yyyy");
    }
    ui->lineEdit_83->setText(Final);
    FechaS25 = FechaS24.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS25.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS25.toString("MM-dd-yyyy");
    }
    ui->lineEdit_82->setText(Final);
    if (FechaS25.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_14->setChecked(true);
        Posicion++;
    }    
    FechaS26 = FechaS25.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS26.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS26.toString("MM-dd-yyyy");
    }
    ui->lineEdit_85->setText(Final);
    FechaS27 = FechaS26.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS27.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS27.toString("MM-dd-yyyy");
    }
    ui->lineEdit_84->setText(Final);
    if (FechaS27.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_15->setChecked(true);
        Posicion++;
    }    
    FechaS28 = FechaS27.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS28.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS28.toString("MM-dd-yyyy");
    }
    ui->lineEdit_87->setText(Final);
    FechaS29 = FechaS28.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS29.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS29.toString("MM-dd-yyyy");
    }
    ui->lineEdit_86->setText(Final);
    if (FechaS29.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_16->setChecked(true);
        Posicion++;
    }    
    FechaS30 = FechaS29.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS30.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS30.toString("MM-dd-yyyy");
    }
    ui->lineEdit_89->setText(Final);
    FechaS31 = FechaS30.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS31.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS31.toString("MM-dd-yyyy");
    }
    ui->lineEdit_88->setText(Final);
    if (FechaS31.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_17->setChecked(true);
        Posicion++;
    }    
    FechaS32 = FechaS31.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS32.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS32.toString("MM-dd-yyyy");
    }
    ui->lineEdit_91->setText(Final);
    FechaS33 = FechaS32.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS33.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS33.toString("MM-dd-yyyy");
    }
    ui->lineEdit_90->setText(Final);
    if (FechaS33.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_18->setChecked(true);
        Posicion++;
    }    
    FechaS34 = FechaS33.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS34.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS34.toString("MM-dd-yyyy");
    }
    ui->lineEdit_93->setText(Final);
    FechaS35 = FechaS34.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS35.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS35.toString("MM-dd-yyyy");
    }
    ui->lineEdit_92->setText(Final);
    if (FechaS35.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_19->setChecked(true);
        Posicion++;
    }    
    FechaS36 = FechaS35.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS36.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS36.toString("MM-dd-yyyy");
    }
    ui->lineEdit_95->setText(Final);
    FechaS37 = FechaS36.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS37.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS37.toString("MM-dd-yyyy");
    }
    ui->lineEdit_94->setText(Final);
    if (FechaS37.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_20->setChecked(true);
        Posicion++;
    }   
    FechaS38 = FechaS37.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS38.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS38.toString("MM-dd-yyyy");
    }
    ui->lineEdit_97->setText(Final);
    FechaS39 = FechaS38.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS39.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS39.toString("MM-dd-yyyy");
    }
    ui->lineEdit_96->setText(Final);
    if (FechaS39.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_21->setChecked(true);
        Posicion++;
    }    
    FechaS40 = FechaS39.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS40.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS40.toString("MM-dd-yyyy");
    }
    ui->lineEdit_99->setText(Final);
    FechaS41 = FechaS40.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS41.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS41.toString("MM-dd-yyyy");
    }
    ui->lineEdit_98->setText(Final);
    if (FechaS41.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_22->setChecked(true);
        Posicion++;
    }    
    FechaS42 = FechaS41.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS42.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS42.toString("MM-dd-yyyy");
    }
    ui->lineEdit_101->setText(Final);
    FechaS43 = FechaS42.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS43.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS43.toString("MM-dd-yyyy");
    }
    ui->lineEdit_100->setText(Final);
    if (FechaS43.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_23->setChecked(true);
        Posicion++;
    }    
    FechaS44 = FechaS43.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS44.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS44.toString("MM-dd-yyyy");
    }
    ui->lineEdit_103->setText(Final);
    FechaS45 = FechaS44.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS45.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS45.toString("MM-dd-yyyy");
    }
    ui->lineEdit_102->setText(Final);
    if (FechaS45.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_24->setChecked(true);
        Posicion++;
    }    
    FechaS46 = FechaS45.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS46.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS46.toString("MM-dd-yyyy");
    }
    ui->lineEdit_105->setText(Final);
    FechaS47 = FechaS46.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS47.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS47.toString("MM-dd-yyyy");
    }
    ui->lineEdit_104->setText(Final);
    if (FechaS47.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_25->setChecked(true);
        Posicion++;
    }    
    FechaS48 = FechaS47.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS48.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS48.toString("MM-dd-yyyy");
    }
    ui->lineEdit_107->setText(Final);
    FechaS49 = FechaS48.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS49.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS49.toString("MM-dd-yyyy");
    }
    ui->lineEdit_106->setText(Final);
    if (FechaS49.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_26->setChecked(true);
        Posicion++;
    }    
    FechaS50 = FechaS49.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS50.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS50.toString("MM-dd-yyyy");
    }
    ui->lineEdit_109->setText(Final);
    FechaS51 = FechaS50.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS51.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS51.toString("MM-dd-yyyy");
    }
    ui->lineEdit_108->setText(Final);
    if (FechaS51.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_27->setChecked(true);
        Posicion++;
    }    
    FechaS52 = FechaS51.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS52.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS52.toString("MM-dd-yyyy");
    }
    ui->lineEdit_111->setText(Final);
    FechaS53 = FechaS52.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS53.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS53.toString("MM-dd-yyyy");
    }
    ui->lineEdit_110->setText(Final);
    if (FechaS53.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_29->setChecked(true);
        Posicion++;
    }    
    FechaS54 = FechaS53.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS54.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS54.toString("MM-dd-yyyy");
    }
    ui->lineEdit_113->setText(Final);
    FechaS55 = FechaS54.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS55.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS55.toString("MM-dd-yyyy");
    }
    ui->lineEdit_112->setText(Final);
    if (FechaS55.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_30->setChecked(true);
        Posicion++;
    }    
    FechaS56 = FechaS55.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS56.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS56.toString("MM-dd-yyyy");
    }
    ui->lineEdit_115->setText(Final);
    FechaS57 = FechaS56.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS57.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS57.toString("MM-dd-yyyy");
    }
    ui->lineEdit_114->setText(Final);
    if (FechaS57.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_31->setChecked(true);
        Posicion++;
    }    
    FechaS58 = FechaS57.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS58.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS58.toString("MM-dd-yyyy");
    }
    ui->lineEdit_117->setText(Final);
    FechaS59 = FechaS58.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS59.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS59.toString("MM-dd-yyyy");
    }
    ui->lineEdit_116->setText(Final);
    if (FechaS59.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_32->setChecked(true);
        Posicion++;
    }    
    FechaS60 = FechaS59.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS60.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS60.toString("MM-dd-yyyy");
    }
    ui->lineEdit_119->setText(Final);
    FechaS61 = FechaS60.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS61.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS61.toString("MM-dd-yyyy");
    }
    ui->lineEdit_118->setText(Final);
    if (FechaS61.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_33->setChecked(true);
        Posicion++;
    }    
    FechaS62 = FechaS61.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS62.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS62.toString("MM-dd-yyyy");
    }
    ui->lineEdit_121->setText(Final);
    FechaS63 = FechaS62.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS63.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS63.toString("MM-dd-yyyy");
    }
    ui->lineEdit_120->setText(Final);
    if (FechaS63.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_34->setChecked(true);
        Posicion++;
    }
    FechaS64 = FechaS63.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS64.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS64.toString("MM-dd-yyyy");
    }
    ui->lineEdit_123->setText(Final);
    FechaS65 = FechaS64.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS65.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS65.toString("MM-dd-yyyy");
    }
    ui->lineEdit_122->setText(Final);
    if (FechaS65.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_35->setChecked(true);
        Posicion++;
    }    
    FechaS66 = FechaS65.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS66.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS66.toString("MM-dd-yyyy");
    }
    ui->lineEdit_137->setText(Final);
    FechaS67 = FechaS66.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS67.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS67.toString("MM-dd-yyyy");
    }
    ui->lineEdit_136->setText(Final);
    if (FechaS67.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_42->setChecked(true);
        Posicion++;
    }    
    FechaS68 = FechaS67.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS68.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS68.toString("MM-dd-yyyy");
    }
    ui->lineEdit_139->setText(Final);
    FechaS69 = FechaS68.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS69.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS69.toString("MM-dd-yyyy");
    }
    ui->lineEdit_138->setText(Final);
    if (FechaS69.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_43->setChecked(true);
        Posicion++;
    }    
    FechaS70 = FechaS69.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS70.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS70.toString("MM-dd-yyyy");
    }
    ui->lineEdit_141->setText(Final);
    FechaS71 = FechaS70.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS71.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS71.toString("MM-dd-yyyy");
    }
    ui->lineEdit_140->setText(Final);
    if (FechaS71.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_44->setChecked(true);
        Posicion++;
    }    
    FechaS72 = FechaS71.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS72.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS72.toString("MM-dd-yyyy");
    }
    ui->lineEdit_143->setText(Final);
    FechaS73 = FechaS72.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS73.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS73.toString("MM-dd-yyyy");
    }
    ui->lineEdit_142->setText(Final);
    if (FechaS73.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_45->setChecked(true);
        Posicion++;
    }    
    FechaS74 = FechaS73.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS74.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS74.toString("MM-dd-yyyy");
    }
    ui->lineEdit_145->setText(Final);
    FechaS75 = FechaS74.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS75.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS75.toString("MM-dd-yyyy");
    }
    ui->lineEdit_144->setText(Final);
    if (FechaS75.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_46->setChecked(true);
        Posicion++;
    }   
    FechaS76 = FechaS75.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS76.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS76.toString("MM-dd-yyyy");
    }
    ui->lineEdit_147->setText(Final);
    FechaS77 = FechaS76.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS77.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS77.toString("MM-dd-yyyy");
    }
    ui->lineEdit_146->setText(Final);
    if (FechaS77.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_47->setChecked(true);
        Posicion++;
    }    
    FechaS78 = FechaS77.addDays(1);
    if (Idioma == "Es")
    {
        Final = FechaS78.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS78.toString("MM-dd-yyyy");
    }
    ui->lineEdit_149->setText(Final);
    FechaS79 = FechaS78.addDays(6);
    if (Idioma == "Es")
    {
        Final = FechaS79.toString("dd-MM-yyyy");
    }
    else if (Idioma == "En")
    {
        Final = FechaS79.toString("MM-dd-yyyy");
    }
    ui->lineEdit_148->setText(Final);
    if (FechaS79.toJulianDay() <= QDate::currentDate().toJulianDay())
    {
        ui->checkBox_48->setChecked(true);
        Posicion++;
    }
    if (Posicion == 1)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentPage(0);
    }
    if (Posicion == 2)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentPage(1);
    }
    if (Posicion == 3)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentPage(2);
    }
    if (Posicion == 4)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentPage(3);
    }
    if (Posicion == 5)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentPage(4);
    }
    if (Posicion == 6)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentPage(5);
    }
    if (Posicion == 7)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentPage(6);
    }
    if (Posicion == 8)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentPage(7);
    }
    if (Posicion == 9)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentPage(8);
    }
    if (Posicion == 10)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentPage(9);
    }
    if (Posicion == 11)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentPage(10);
    }
    if (Posicion == 12)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_2->setCurrentPage(11);
    }
    if (Posicion == 13)
    {
        ui->toolBox->setCurrentIndex(0);
        ui->tabWidget_3->setCurrentPage(12);
    }
    if (Posicion == 14)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(0);
    }
    if (Posicion == 15)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(1);
    }
    if (Posicion == 16)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(2);
    }
    if (Posicion == 17)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(3);
    }
    if (Posicion == 18)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(4);
    }
    if (Posicion == 19)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(5);
    }
    if (Posicion == 20)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(6);
    }
    if (Posicion == 21)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(7);
    }
    if (Posicion == 22)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(8);
    }
    if (Posicion == 23)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(9);
    }
    if (Posicion == 24)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(10);
    }
    if (Posicion == 25)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(11);
    }
    if (Posicion == 26)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(12);
    }
    if (Posicion == 27)
    {
        ui->toolBox->setCurrentIndex(1);
        ui->tabWidget_3->setCurrentPage(13);
    }
    if (Posicion == 28)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(0);
    }
    if (Posicion == 29)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(1);
    }
    if (Posicion == 30)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(2);
    }
    if (Posicion == 31)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(3);
    }
    if (Posicion == 32)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(4);
    }
    if (Posicion == 33)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(5);
    }
    if (Posicion == 34)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(6);
    }
    if (Posicion == 35)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(7);
    }
    if (Posicion == 36)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(8);
    }
    if (Posicion == 37)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(9);
    }
    if (Posicion == 38)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(10);
    }
    if (Posicion == 39)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(11);
    }
    if (Posicion == 40)
    {
        ui->toolBox->setCurrentIndex(2);
        ui->tabWidget_4->setCurrentPage(12);
    }
}

void ConversorUD::on_pushButton_22_clicked()
{
    ui->lineEdit_50->setText("");
    ui->lineEdit_52->setText("");
    ui->lineEdit_52->setToolTip("");
}

void ConversorUD::on_lineEdit_50_returnPressed()
{
    ui->lineEdit_50->setFocus();
    ui->lineEdit_50->selectAll();
}

void ConversorUD::on_pushButton_18_clicked()
{
    ui->lineEdit_42->setText("");
    ui->lineEdit_42->setFocus();
    ui->lineEdit_43->setText("");
    ui->lineEdit_43->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_lineEdit_42_returnPressed()
{
    ui->lineEdit_42->setFocus();
    ui->lineEdit_42->selectAll();
}

void ConversorUD::on_lineEdit_42_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_42->text() == "")
            {
                ui->lineEdit_43->setText("");
                ui->lineEdit_43->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_21->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Angulo");
                QString Valor1 = ui->comboBox_22->currentText();
                double Resto1 = Referencia(Valor1,"Angulo");
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
                    ui->lineEdit_43->setText(Zero);
                    ui->lineEdit_43->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_43->setText(Zero);
                    ui->lineEdit_43->setToolTip(Zero);
                }
            }
            Reprobar("Angulo");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_42->setFocus();
            QString Resto = ui->lineEdit_42->text();
            Resto.chop(1);
            ui->lineEdit_42->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_21_activated(const QString &arg1)
{
    if (ui->lineEdit_42->text() == "")
    {
        ui->lineEdit_43->setText("");
        ui->lineEdit_43->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_42->text().toFloat();
        double Resto = Referencia(Valor,"Angulo");
        QString Valor1 = ui->comboBox_22->currentText();
        double Resto1 = Referencia(Valor1,"Angulo");
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
            ui->lineEdit_43->setText(Zero);
            ui->lineEdit_43->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_43->setText(Zero);
            ui->lineEdit_43->setToolTip(Zero);
        }
    }
    Reprobar("Angulo");
}

void ConversorUD::on_comboBox_22_activated(const QString &arg1)
{
    if (ui->lineEdit_42->text() == "")
    {
        ui->lineEdit_43->setText("");
        ui->lineEdit_43->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_21->currentText();
        double Cantidad = ui->lineEdit_42->text().toFloat();
        double Resto = Referencia(Valor,"Angulo");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Angulo");
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
            ui->lineEdit_43->setText(Zero);
            ui->lineEdit_43->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_43->setText(Zero);
            ui->lineEdit_43->setToolTip(Zero);
        }
    }
    Reprobar("Angulo");
}

void ConversorUD::on_lineEdit_4_returnPressed()
{
    ui->lineEdit_4->setFocus();
    ui->lineEdit_4->selectAll();
}

void ConversorUD::on_lineEdit_4_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_4->text() == "")
            {
                ui->lineEdit_3->setText("");
                ui->lineEdit_3->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_4->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Area");
                QString Valor1 = ui->comboBox_6->currentText();
                double Resto1 = Referencia(Valor1,"Area");
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
                    ui->lineEdit_3->setText(Zero);
                    ui->lineEdit_3->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_3->setText(Zero);
                    ui->lineEdit_3->setToolTip(Zero);
                }
            }
            Reprobar("Area");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_4->setFocus();
            QString Resto = ui->lineEdit_4->text();
            Resto.chop(1);
            ui->lineEdit_4->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_4_activated(const QString &arg1)
{
    if (ui->lineEdit_4->text() == "")
    {
        ui->lineEdit_3->setText("");
        ui->lineEdit_3->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_4->text().toFloat();
        double Resto = Referencia(Valor,"Area");
        QString Valor1 = ui->comboBox_6->currentText();
        double Resto1 = Referencia(Valor1,"Area");
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
            ui->lineEdit_3->setText(Zero);
            ui->lineEdit_3->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_3->setText(Zero);
            ui->lineEdit_3->setToolTip(Zero);
        }
    }
    Reprobar("Area");
}

void ConversorUD::on_comboBox_6_activated(const QString &arg1)
{
    if (ui->lineEdit_4->text() == "")
    {
        ui->lineEdit_3->setText("");
        ui->lineEdit_3->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_4->currentText();
        double Cantidad = ui->lineEdit_4->text().toFloat();
        double Resto = Referencia(Valor,"Area");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Area");
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
            ui->lineEdit_3->setText(Zero);
            ui->lineEdit_3->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_3->setText(Zero);
            ui->lineEdit_3->setToolTip(Zero);
        }
    }
    Reprobar("Area");
}

void ConversorUD::on_pushButton_16_clicked()
{
    ui->lineEdit_39->setText("");
    ui->lineEdit_39->setFocus();
    ui->lineEdit_38->setText("");
    ui->lineEdit_38->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_lineEdit_39_returnPressed()
{
    ui->lineEdit_39->setFocus();
    ui->lineEdit_39->selectAll();
}

void ConversorUD::on_lineEdit_39_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_39->text() == "")
            {
                ui->lineEdit_38->setText("");
                ui->lineEdit_38->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_18->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Campo");
                QString Valor1 = ui->comboBox_23->currentText();
                double Resto1 = Referencia(Valor1,"Campo");
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
                    ui->lineEdit_38->setText(Zero);
                    ui->lineEdit_38->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_38->setText(Zero);
                    ui->lineEdit_38->setToolTip(Zero);
                }
            }
            Reprobar("Campo");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_39->setFocus();
            QString Resto = ui->lineEdit_39->text();
            Resto.chop(1);
            ui->lineEdit_39->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_18_activated(const QString &arg1)
{
    if (ui->lineEdit_39->text() == "")
    {
        ui->lineEdit_38->setText("");
        ui->lineEdit_38->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_39->text().toFloat();
        double Resto = Referencia(Valor,"Campo");
        QString Valor1 = ui->comboBox_23->currentText();
        double Resto1 = Referencia(Valor1,"Campo");
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
            ui->lineEdit_38->setText(Zero);
            ui->lineEdit_38->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_38->setText(Zero);
            ui->lineEdit_38->setToolTip(Zero);
        }
    }
    Reprobar("Campo");
}

void ConversorUD::on_comboBox_23_activated(const QString &arg1)
{
    if (ui->lineEdit_39->text() == "")
    {
        ui->lineEdit_38->setText("");
        ui->lineEdit_38->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_18->currentText();
        double Cantidad = ui->lineEdit_39->text().toFloat();
        double Resto = Referencia(Valor,"Campo");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Campo");
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
            ui->lineEdit_38->setText(Zero);
            ui->lineEdit_38->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_38->setText(Zero);
            ui->lineEdit_38->setToolTip(Zero);
        }
    }
    Reprobar("Campo");
}

void ConversorUD::on_pushButton_15_clicked()
{
    ui->lineEdit_37->setText("");
    ui->lineEdit_37->setFocus();
    ui->lineEdit_36->setText("");
    ui->lineEdit_36->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_lineEdit_37_returnPressed()
{
    ui->lineEdit_37->setFocus();
    ui->lineEdit_37->selectAll();
}

void ConversorUD::on_lineEdit_37_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_37->text() == "")
            {
                ui->lineEdit_36->setText("");
                ui->lineEdit_36->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_17->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Luz");
                QString Valor1 = ui->comboBox_31->currentText();
                double Resto1 = Referencia(Valor1,"Luz");
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
                    ui->lineEdit_36->setText(Zero);
                    ui->lineEdit_36->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_36->setText(Zero);
                    ui->lineEdit_36->setToolTip(Zero);
                }
            }
            Reprobar("Luz");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_37->setFocus();
            QString Resto = ui->lineEdit_37->text();
            Resto.chop(1);
            ui->lineEdit_37->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_17_activated(const QString &arg1)
{
    if (ui->lineEdit_37->text() == "")
    {
        ui->lineEdit_36->setText("");
        ui->lineEdit_36->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_37->text().toFloat();
        double Resto = Referencia(Valor,"Luz");
        QString Valor1 = ui->comboBox_31->currentText();
        double Resto1 = Referencia(Valor1,"Luz");
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
            ui->lineEdit_36->setText(Zero);
            ui->lineEdit_36->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_36->setText(Zero);
            ui->lineEdit_36->setToolTip(Zero);
        }
    }
    Reprobar("Luz");
}

void ConversorUD::on_comboBox_31_activated(const QString &arg1)
{
    if (ui->lineEdit_37->text() == "")
    {
        ui->lineEdit_36->setText("");
        ui->lineEdit_36->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_17->currentText();
        double Cantidad = ui->lineEdit_37->text().toFloat();
        double Resto = Referencia(Valor,"Luz");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Luz");
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
            ui->lineEdit_36->setText(Zero);
            ui->lineEdit_36->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_36->setText(Zero);
            ui->lineEdit_36->setToolTip(Zero);
        }
    }
    Reprobar("Luz");
}

void ConversorUD::on_pushButton_32_clicked()
{
    ui->lineEdit_156->setText("");
    ui->lineEdit_156->setFocus();
    ui->lineEdit_157->setText("");
    ui->lineEdit_157->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_lineEdit_156_returnPressed()
{
    ui->lineEdit_156->setFocus();
    ui->lineEdit_156->selectAll();
}

void ConversorUD::on_lineEdit_156_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_156->text() == "")
            {
                ui->lineEdit_157->setText("");
                ui->lineEdit_157->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_50->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Sustancia");
                QString Valor1 = ui->comboBox_51->currentText();
                double Resto1 = Referencia(Valor1,"Sustancia");
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
                    ui->lineEdit_157->setText(Zero);
                    ui->lineEdit_157->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_157->setText(Zero);
                    ui->lineEdit_157->setToolTip(Zero);
                }
            }
            Reprobar("Sustancia");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_156->setFocus();
            QString Resto = ui->lineEdit_156->text();
            Resto.chop(1);
            ui->lineEdit_156->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_50_activated(const QString &arg1)
{
    if (ui->lineEdit_156->text() == "")
    {
        ui->lineEdit_157->setText("");
        ui->lineEdit_157->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_156->text().toFloat();
        double Resto = Referencia(Valor,"Sustancia");
        QString Valor1 = ui->comboBox_51->currentText();
        double Resto1 = Referencia(Valor1,"Sustancia");
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
            ui->lineEdit_157->setText(Zero);
            ui->lineEdit_157->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_157->setText(Zero);
            ui->lineEdit_157->setToolTip(Zero);
        }
    }
    Reprobar("Sustancia");
}

void ConversorUD::on_comboBox_51_activated(const QString &arg1)
{
    if (ui->lineEdit_156->text() == "")
    {
        ui->lineEdit_157->setText("");
        ui->lineEdit_157->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_50->currentText();
        double Cantidad = ui->lineEdit_156->text().toFloat();
        double Resto = Referencia(Valor,"Sustancia");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Sustancia");
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
            ui->lineEdit_157->setText(Zero);
            ui->lineEdit_157->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_157->setText(Zero);
            ui->lineEdit_157->setToolTip(Zero);
        }
    }
    Reprobar("Sustancia");
}

void ConversorUD::on_pushButton_31_clicked()
{
    ui->lineEdit_154->setText("");
    ui->lineEdit_154->setFocus();
    ui->lineEdit_155->setText("");
    ui->lineEdit_155->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_lineEdit_154_returnPressed()
{
    ui->lineEdit_154->setFocus();
    ui->lineEdit_154->selectAll();
}

void ConversorUD::on_lineEdit_154_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_154->text() == "")
            {
                ui->lineEdit_155->setText("");
                ui->lineEdit_155->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_48->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Electrica");
                QString Valor1 = ui->comboBox_49->currentText();
                double Resto1 = Referencia(Valor1,"Electrica");
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
                    ui->lineEdit_155->setText(Zero);
                    ui->lineEdit_155->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_155->setText(Zero);
                    ui->lineEdit_155->setToolTip(Zero);
                }
            }
            Reprobar("Electrica");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_154->setFocus();
            QString Resto = ui->lineEdit_154->text();
            Resto.chop(1);
            ui->lineEdit_154->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_48_activated(const QString &arg1)
{
    if (ui->lineEdit_154->text() == "")
    {
        ui->lineEdit_155->setText("");
        ui->lineEdit_155->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_154->text().toFloat();
        double Resto = Referencia(Valor,"Electrica");
        QString Valor1 = ui->comboBox_49->currentText();
        double Resto1 = Referencia(Valor1,"Electrica");
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
            ui->lineEdit_155->setText(Zero);
            ui->lineEdit_155->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_155->setText(Zero);
            ui->lineEdit_155->setToolTip(Zero);
        }
    }
    Reprobar("Electrica");
}

void ConversorUD::on_comboBox_49_activated(const QString &arg1)
{
    if (ui->lineEdit_154->text() == "")
    {
        ui->lineEdit_155->setText("");
        ui->lineEdit_155->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_48->currentText();
        double Cantidad = ui->lineEdit_154->text().toFloat();
        double Resto = Referencia(Valor,"Electrica");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Electrica");
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
            ui->lineEdit_155->setText(Zero);
            ui->lineEdit_155->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_155->setText(Zero);
            ui->lineEdit_155->setToolTip(Zero);
        }
    }
    Reprobar("Electrica");
}

void ConversorUD::on_pushButton_30_clicked()
{
    ui->lineEdit_152->setText("");
    ui->lineEdit_152->setFocus();
    ui->lineEdit_153->setText("");
    ui->lineEdit_153->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_lineEdit_152_returnPressed()
{
    ui->lineEdit_152->setFocus();
    ui->lineEdit_152->selectAll();
}

void ConversorUD::on_lineEdit_152_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_152->text() == "")
            {
                ui->lineEdit_153->setText("");
                ui->lineEdit_153->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_46->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Carga");
                QString Valor1 = ui->comboBox_47->currentText();
                double Resto1 = Referencia(Valor1,"Carga");
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
                    ui->lineEdit_153->setText(Zero);
                    ui->lineEdit_153->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_153->setText(Zero);
                    ui->lineEdit_153->setToolTip(Zero);
                }
            }
            Reprobar("Carga");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_152->setFocus();
            QString Resto = ui->lineEdit_152->text();
            Resto.chop(1);
            ui->lineEdit_152->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_46_activated(const QString &arg1)
{
    if (ui->lineEdit_152->text() == "")
    {
        ui->lineEdit_153->setText("");
        ui->lineEdit_153->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_152->text().toFloat();
        double Resto = Referencia(Valor,"Carga");
        QString Valor1 = ui->comboBox_47->currentText();
        double Resto1 = Referencia(Valor1,"Carga");
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
            ui->lineEdit_153->setText(Zero);
            ui->lineEdit_153->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_153->setText(Zero);
            ui->lineEdit_153->setToolTip(Zero);
        }
    }
    Reprobar("Carga");
}

void ConversorUD::on_comboBox_47_activated(const QString &arg1)
{
    if (ui->lineEdit_152->text() == "")
    {
        ui->lineEdit_153->setText("");
        ui->lineEdit_153->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_46->currentText();
        double Cantidad = ui->lineEdit_152->text().toFloat();
        double Resto = Referencia(Valor,"Carga");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Carga");
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
            ui->lineEdit_153->setText(Zero);
            ui->lineEdit_153->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_153->setText(Zero);
            ui->lineEdit_153->setToolTip(Zero);
        }
    }
    Reprobar("Carga");
}

void ConversorUD::on_pushButton_29_clicked()
{
    ui->lineEdit_150->setText("");
    ui->lineEdit_150->setFocus();
    ui->lineEdit_151->setText("");
    ui->lineEdit_151->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_lineEdit_150_returnPressed()
{
    ui->lineEdit_150->setFocus();
    ui->lineEdit_150->selectAll();
}

void ConversorUD::on_lineEdit_150_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_150->text() == "")
            {
                ui->lineEdit_151->setText("");
                ui->lineEdit_151->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_44->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Caudal");
                QString Valor1 = ui->comboBox_45->currentText();
                double Resto1 = Referencia(Valor1,"Caudal");
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
                    ui->lineEdit_151->setText(Zero);
                    ui->lineEdit_151->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_151->setText(Zero);
                    ui->lineEdit_151->setToolTip(Zero);
                }
            }
            Reprobar("Caudal");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_150->setFocus();
            QString Resto = ui->lineEdit_150->text();
            Resto.chop(1);
            ui->lineEdit_150->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_44_activated(const QString &arg1)
{
    if (ui->lineEdit_150->text() == "")
    {
        ui->lineEdit_151->setText("");
        ui->lineEdit_151->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_150->text().toFloat();
        double Resto = Referencia(Valor,"Caudal");
        QString Valor1 = ui->comboBox_45->currentText();
        double Resto1 = Referencia(Valor1,"Caudal");
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
            ui->lineEdit_151->setText(Zero);
            ui->lineEdit_151->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_151->setText(Zero);
            ui->lineEdit_151->setToolTip(Zero);
        }
    }
    Reprobar("Caudal");
}

void ConversorUD::on_comboBox_45_activated(const QString &arg1)
{
    if (ui->lineEdit_150->text() == "")
    {
        ui->lineEdit_151->setText("");
        ui->lineEdit_151->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_44->currentText();
        double Cantidad = ui->lineEdit_150->text().toFloat();
        double Resto = Referencia(Valor,"Caudal");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Caudal");
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
            ui->lineEdit_151->setText(Zero);
            ui->lineEdit_151->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_151->setText(Zero);
            ui->lineEdit_151->setToolTip(Zero);
        }
    }
    Reprobar("Caudal");
}

void ConversorUD::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_46->setToolTip("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_4->setToolTip("");
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
    ui->lineEdit_46->setText("");
    ui->lineEdit_46->setToolTip("");
    ui->lineEdit_47->setText("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    ui->lineEdit_40->setText("");
    ui->lineEdit_41->setText("");
    ui->lineEdit_41->setToolTip("");
    ui->lineEdit_45->setText("");
    ui->lineEdit_44->setText("");
    ui->lineEdit_45->setToolTip("");
    ui->lineEdit_42->setText("");
    ui->lineEdit_43->setText("");
    ui->lineEdit_43->setToolTip("");
    ui->lineEdit_50->setText("");
    ui->lineEdit_52->setText("");
    ui->lineEdit_52->setToolTip("");
    ui->lineEdit_39->setText("");
    ui->lineEdit_38->setText("");
    ui->lineEdit_38->setToolTip("");
    ui->lineEdit_56->setText("");
    ui->lineEdit_57->setText("");
    ui->lineEdit_54->setText("");
    ui->lineEdit_53->setText("");
    ui->lineEdit_51->setText("");
    ui->lineEdit_55->setText("28");
    ui->lineEdit_58->setText("");
    ui->lineEdit_59->setText("");
    ui->lineEdit_60->setText("");
    ui->lineEdit_61->setText("");
    ui->lineEdit_62->setText("");
    ui->lineEdit_63->setText("");
    ui->lineEdit_64->setText("");
    ui->lineEdit_65->setText("");
    ui->lineEdit_66->setText("");
    ui->lineEdit_67->setText("");
    ui->lineEdit_68->setText("");
    ui->lineEdit_69->setText("");
    ui->lineEdit_70->setText("");
    ui->lineEdit_71->setText("");
    ui->lineEdit_72->setText("");
    ui->lineEdit_73->setText("");
    ui->lineEdit_74->setText("");
    ui->lineEdit_75->setText("");
    ui->lineEdit_76->setText("");
    ui->lineEdit_77->setText("");
    ui->lineEdit_78->setText("");
    ui->lineEdit_79->setText("");
    ui->lineEdit_80->setText("");
    ui->lineEdit_81->setText("");
    ui->lineEdit_82->setText("");
    ui->lineEdit_83->setText("");
    ui->lineEdit_84->setText("");
    ui->lineEdit_85->setText("");
    ui->lineEdit_86->setText("");
    ui->lineEdit_87->setText("");
    ui->lineEdit_88->setText("");
    ui->lineEdit_89->setText("");
    ui->lineEdit_90->setText("");
    ui->lineEdit_91->setText("");
    ui->lineEdit_92->setText("");
    ui->lineEdit_93->setText("");
    ui->lineEdit_94->setText("");
    ui->lineEdit_95->setText("");
    ui->lineEdit_96->setText("");
    ui->lineEdit_97->setText("");
    ui->lineEdit_98->setText("");
    ui->lineEdit_99->setText("");
    ui->lineEdit_100->setText("");
    ui->lineEdit_101->setText("");
    ui->lineEdit_102->setText("");
    ui->lineEdit_103->setText("");
    ui->lineEdit_104->setText("");
    ui->lineEdit_105->setText("");
    ui->lineEdit_106->setText("");
    ui->lineEdit_107->setText("");
    ui->lineEdit_108->setText("");
    ui->lineEdit_109->setText("");
    ui->lineEdit_110->setText("");
    ui->lineEdit_111->setText("");
    ui->lineEdit_112->setText("");
    ui->lineEdit_113->setText("");
    ui->lineEdit_114->setText("");
    ui->lineEdit_115->setText("");
    ui->lineEdit_116->setText("");
    ui->lineEdit_117->setText("");
    ui->lineEdit_118->setText("");
    ui->lineEdit_119->setText("");
    ui->lineEdit_120->setText("");
    ui->lineEdit_121->setText("");
    ui->lineEdit_122->setText("");
    ui->lineEdit_123->setText("");
    ui->lineEdit_136->setText("");
    ui->lineEdit_137->setText("");
    ui->lineEdit_138->setText("");
    ui->lineEdit_139->setText("");
    ui->lineEdit_140->setText("");
    ui->lineEdit_141->setText("");
    ui->lineEdit_142->setText("");
    ui->lineEdit_143->setText("");
    ui->lineEdit_144->setText("");
    ui->lineEdit_145->setText("");
    ui->lineEdit_146->setText("");
    ui->lineEdit_147->setText("");
    ui->lineEdit_148->setText("");
    ui->lineEdit_149->setText("");
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    ui->calendarWidget_2->setSelectedDate(QDate::currentDate());
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    ui->checkBox_11->setChecked(false);
    ui->checkBox_12->setChecked(false);
    ui->checkBox_13->setChecked(false);
    ui->checkBox_14->setChecked(false);
    ui->checkBox_15->setChecked(false);
    ui->checkBox_16->setChecked(false);
    ui->checkBox_17->setChecked(false);
    ui->checkBox_18->setChecked(false);
    ui->checkBox_19->setChecked(false);
    ui->checkBox_20->setChecked(false);
    ui->checkBox_21->setChecked(false);
    ui->checkBox_22->setChecked(false);
    ui->checkBox_23->setChecked(false);
    ui->checkBox_24->setChecked(false);
    ui->checkBox_25->setChecked(false);
    ui->checkBox_26->setChecked(false);
    ui->checkBox_27->setChecked(false);
    ui->checkBox_29->setChecked(false);
    ui->checkBox_30->setChecked(false);
    ui->checkBox_31->setChecked(false);
    ui->checkBox_32->setChecked(false);
    ui->checkBox_33->setChecked(false);
    ui->checkBox_34->setChecked(false);
    ui->checkBox_35->setChecked(false);
    ui->checkBox_42->setChecked(false);
    ui->checkBox_43->setChecked(false);
    ui->checkBox_44->setChecked(false);
    ui->checkBox_45->setChecked(false);
    ui->checkBox_46->setChecked(false);
    ui->checkBox_47->setChecked(false);
    ui->checkBox_48->setChecked(false);
    ui->toolBox->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentPage(0);
    ui->lineEdit_125->setText("");
    ui->lineEdit_124->setText("");
    ui->label_135->setText("");
    ui->lineEdit_37->setText("");
    ui->lineEdit_36->setText("");
    ui->lineEdit_36->setToolTip("");
    ui->lineEdit_156->setText("");
    ui->lineEdit_157->setText("");
    ui->lineEdit_157->setToolTip("");
    ui->lineEdit_154->setText("");
    ui->lineEdit_155->setText("");
    ui->lineEdit_155->setToolTip("");
    ui->lineEdit_152->setText("");
    ui->lineEdit_153->setText("");
    ui->lineEdit_153->setToolTip("");
    ui->lineEdit_150->setText("");
    ui->lineEdit_151->setText("");
    ui->lineEdit_151->setToolTip("");
    ui->lineEdit_160->setText("");
    ui->lineEdit_161->setText("");
    ui->lineEdit_161->setToolTip("");
    ui->lineEdit_159->setText("");
    ui->lineEdit_158->setText("");
    ui->lineEdit_158->setToolTip("");
    int Borrado, x;
    Borrado = ui->tableWidget->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    ui->comboBox_11->setCurrentIndex(ui->comboBox_11->findText(tr("Ano")));
    ui->comboBox_12->setCurrentIndex(ui->comboBox_12->findText(tr("Ano")));
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("Metro (m)")));
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(tr("Centimetro (cm)")));
    ui->comboBox_26->setCurrentIndex(ui->comboBox_26->findText(tr("Gal")));
    ui->comboBox_27->setCurrentIndex(ui->comboBox_27->findText(tr("Fuerza G (g)")));
    ui->comboBox_19->setCurrentIndex(ui->comboBox_19->findText(tr("Byte (B)")));
    ui->comboBox_20->setCurrentIndex(ui->comboBox_20->findText(tr("Kilobyte (KB)")));
    ui->comboBox_24->setCurrentIndex(ui->comboBox_24->findText(tr("Gigabyte por segundo (GB/s)")));
    ui->comboBox_30->setCurrentIndex(ui->comboBox_30->findText(tr("Kilobyte por segundo (kB/s)")));
    ui->comboBox_21->setCurrentIndex(ui->comboBox_21->findText(tr("Circulo")));
    ui->comboBox_22->setCurrentIndex(ui->comboBox_22->findText(tr("Giro")));
    ui->comboBox_4->setCurrentIndex(ui->comboBox_4->findText(tr("Metro cuadrado (m²)")));
    ui->comboBox_6->setCurrentIndex(ui->comboBox_6->findText(tr("Metro cuadrado (m²)")));
    ui->comboBox_17->setCurrentIndex(ui->comboBox_17->findText(tr("Lumen hora (lm·h)")));
    ui->comboBox_31->setCurrentIndex(ui->comboBox_31->findText(tr("Lumen hora (lm·h)")));
    ui->comboBox_50->setCurrentIndex(ui->comboBox_50->findText(tr("Mol (mol)")));
    ui->comboBox_51->setCurrentIndex(ui->comboBox_51->findText(tr("Mol (mol)")));
    ui->comboBox_46->setCurrentIndex(ui->comboBox_46->findText(tr("Culombios (C)")));
    ui->comboBox_47->setCurrentIndex(ui->comboBox_47->findText(tr("Culombios (C)")));
    ui->comboBox_44->setCurrentIndex(ui->comboBox_44->findText(tr("Metros cubicos por segundo (m³/s)")));
    ui->comboBox_45->setCurrentIndex(ui->comboBox_45->findText(tr("Metros cubicos por segundo (m³/s)")));
    ui->comboBox_54->setCurrentIndex(ui->comboBox_54->findText(tr("Siemens (S)")));
    ui->comboBox_55->setCurrentIndex(ui->comboBox_55->findText(tr("Siemens (S)")));
    ui->comboBox_53->setCurrentIndex(ui->comboBox_53->findText(tr("Litros por 100 kilometros (l/100 km)")));
    ui->comboBox_56->setCurrentIndex(ui->comboBox_56->findText(tr("Litros por 100 kilometros (l/100 km)")));
}

void ConversorUD::on_comboBox_3_activated(const QString &arg1)
{
    Decimales = arg1.toInt();
    if (ui->lineEdit->text() == "")
    {
        ui->lineEdit_2->setText("");
        ui->lineEdit_2->setToolTip("");
    }
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
            ui->lineEdit_2->setToolTip(Zero);
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
            ui->lineEdit_2->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_47->text() == "")
    {
        ui->lineEdit_46->setText("");
        ui->lineEdit_46->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_26->currentText();
        double Cantidad = ui->lineEdit_47->text().toFloat();
        double Resto = Referencia(Valor,"Aceleracion");
        QString Valor1 = ui->comboBox_27->currentText();
        double Resto1 = Referencia(Valor1,"Aceleracion");
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
            ui->lineEdit_46->setText(Zero);
            ui->lineEdit_46->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_46->setText(Zero);
            ui->lineEdit_46->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_40->text() == "")
    {
        ui->lineEdit_41->setText("");
        ui->lineEdit_41->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_19->currentText();
        double Cantidad = ui->lineEdit_40->text().toFloat();
        double Resto = Referencia(Valor,"Almacenamiento");
        QString Valor1 = ui->comboBox_20->currentText();
        double Resto1 = Referencia(Valor1,"Almacenamiento");
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
            ui->lineEdit_41->setText(Zero);
            ui->lineEdit_41->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_41->setText(Zero);
            ui->lineEdit_41->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_45->text() == "")
    {
        ui->lineEdit_44->setText("");
        ui->lineEdit_44->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_24->currentText();
        double Cantidad = ui->lineEdit_45->text().toFloat();
        double Resto = Referencia(Valor,"Ancho banda");
        QString Valor1 = ui->comboBox_30->currentText();
        double Resto1 = Referencia(Valor1,"Ancho banda");
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
            ui->lineEdit_44->setText(Zero);
            ui->lineEdit_44->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_44->setText(Zero);
            ui->lineEdit_44->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_42->text() == "")
    {
        ui->lineEdit_43->setText("");
        ui->lineEdit_43->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_21->currentText();
        double Cantidad = ui->lineEdit_42->text().toFloat();
        double Resto = Referencia(Valor,"Angulo");
        QString Valor1 = ui->comboBox_22->currentText();
        double Resto1 = Referencia(Valor1,"Angulo");
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
            ui->lineEdit_43->setText(Zero);
            ui->lineEdit_43->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_43->setText(Zero);
            ui->lineEdit_43->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_4->text() == "")
    {
        ui->lineEdit_3->setText("");
        ui->lineEdit_3->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_4->currentText();
        double Cantidad = ui->lineEdit_4->text().toFloat();
        double Resto = Referencia(Valor,"Area");
        QString Valor1 = ui->comboBox_6->currentText();
        double Resto1 = Referencia(Valor1,"Area");
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
            ui->lineEdit_3->setText(Zero);
            ui->lineEdit_3->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_3->setText(Zero);
            ui->lineEdit_3->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_39->text() == "")
    {
        ui->lineEdit_38->setText("");
        ui->lineEdit_38->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_18->currentText();
        double Cantidad = ui->lineEdit_39->text().toFloat();
        double Resto = Referencia(Valor,"Campo");
        QString Valor1 = ui->comboBox_23->currentText();
        double Resto1 = Referencia(Valor1,"Campo");
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
            ui->lineEdit_38->setText(Zero);
            ui->lineEdit_38->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_38->setText(Zero);
            ui->lineEdit_38->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_37->text() == "")
    {
        ui->lineEdit_36->setText("");
        ui->lineEdit_36->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_17->currentText();
        double Cantidad = ui->lineEdit_37->text().toFloat();
        double Resto = Referencia(Valor,"Luz");
        QString Valor1 = ui->comboBox_31->currentText();
        double Resto1 = Referencia(Valor1,"Luz");
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
            ui->lineEdit_36->setText(Zero);
            ui->lineEdit_36->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_36->setText(Zero);
            ui->lineEdit_36->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_156->text() == "")
    {
        ui->lineEdit_157->setText("");
        ui->lineEdit_157->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_50->currentText();
        double Cantidad = ui->lineEdit_156->text().toFloat();
        double Resto = Referencia(Valor,"Sustancia");
        QString Valor1 = ui->comboBox_51->currentText();
        double Resto1 = Referencia(Valor1,"Sustancia");
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
            ui->lineEdit_157->setText(Zero);
            ui->lineEdit_157->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_157->setText(Zero);
            ui->lineEdit_157->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_154->text() == "")
    {
        ui->lineEdit_155->setText("");
        ui->lineEdit_155->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_48->currentText();
        double Cantidad = ui->lineEdit_154->text().toFloat();
        double Resto = Referencia(Valor,"Electrica");
        QString Valor1 = ui->comboBox_49->currentText();
        double Resto1 = Referencia(Valor1,"Electrica");
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
            ui->lineEdit_155->setText(Zero);
            ui->lineEdit_155->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_155->setText(Zero);
            ui->lineEdit_155->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_152->text() == "")
    {
        ui->lineEdit_153->setText("");
        ui->lineEdit_153->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_46->currentText();
        double Cantidad = ui->lineEdit_152->text().toFloat();
        double Resto = Referencia(Valor,"Carga");
        QString Valor1 = ui->comboBox_47->currentText();
        double Resto1 = Referencia(Valor1,"Carga");
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
            ui->lineEdit_153->setText(Zero);
            ui->lineEdit_153->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_153->setText(Zero);
            ui->lineEdit_153->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_150->text() == "")
    {
        ui->lineEdit_151->setText("");
        ui->lineEdit_151->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_44->currentText();
        double Cantidad = ui->lineEdit_150->text().toFloat();
        double Resto = Referencia(Valor,"Caudal");
        QString Valor1 = ui->comboBox_45->currentText();
        double Resto1 = Referencia(Valor1,"Caudal");
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
            ui->lineEdit_151->setText(Zero);
            ui->lineEdit_151->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_151->setText(Zero);
            ui->lineEdit_151->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_160->text() == "")
    {
        ui->lineEdit_161->setText("");
        ui->lineEdit_161->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_54->currentText();
        double Cantidad = ui->lineEdit_160->text().toFloat();
        double Resto = Referencia(Valor,"Conductancia");
        QString Valor1 = ui->comboBox_55->currentText();
        double Resto1 = Referencia(Valor1,"Conductancia");
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
            ui->lineEdit_161->setText(Zero);
            ui->lineEdit_161->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_161->setText(Zero);
            ui->lineEdit_161->setToolTip(Zero);
        }
    }
    if (ui->lineEdit_159->text() == "")
    {
        ui->lineEdit_158->setText("");
        ui->lineEdit_158->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_53->currentText();
        double Cantidad = ui->lineEdit_159->text().toFloat();
        double Resto = Referencia(Valor,"Combustible");
        QString Valor1 = ui->comboBox_56->currentText();
        double Resto1 = Referencia(Valor1,"Combustible");
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
            ui->lineEdit_158->setText(Zero);
            ui->lineEdit_158->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_158->setText(Zero);
            ui->lineEdit_158->setToolTip(Zero);
        }
    }
    if (ui->label_14->text().contains(tr("Distancia o Longitud")))
        Reprobar("Longitud");
    if (ui->label_14->text().contains(tr("Aceleracion")))
        Reprobar("Aceleracion");
    if (ui->label_14->text().contains(tr("Almacenamiento")))
        Reprobar("Almacenamiento");
    if (ui->label_14->text().contains(tr("Ancho de banda")))
        Reprobar("Ancho banda");
    if (ui->label_14->text().contains(tr("Angulo")))
        Reprobar("Angulo");
    if (ui->label_14->text().contains(tr("Superficie o Area")))
        Reprobar("Area");
    if (ui->label_14->text().contains(tr("Campo magnetico")))
        Reprobar("Campo");
    if (ui->label_14->text().contains(tr("Cantidad de luz")))
        Reprobar("Luz");
    if (ui->label_14->text().contains(tr("Cantidad de sustancia")))
        Reprobar("Sustancia");
    if (ui->label_14->text().contains(tr("Capacidad electrica")))
        Reprobar("Electrica");
    if (ui->label_14->text().contains(tr("Carga electrica")))
        Reprobar("Carga");
    if (ui->label_14->text().contains(tr("Caudal volumetrico")))
        Reprobar("Caudal");
    if (ui->label_14->text().contains(tr("Conductancia electrica")))
        Reprobar("Conductancia");
    if (ui->label_14->text().contains(tr("Consumo de combustible")))
        Reprobar("Combustible");
}

void ConversorUD::on_comboBox_25_activated(const QString &arg1)
{
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    if (arg1 == tr("Aceleracion"))
    {
        ui->tabWidget->setCurrentPage(0);
        ui->lineEdit_47->setFocus();
    }
    if (arg1 == tr("Distancia o Longitud"))
    {
        ui->tabWidget->setCurrentPage(0);
        ui->lineEdit->setFocus();
    }
    if (arg1 == tr("Almacenamiento de datos"))
    {
        ui->tabWidget->setCurrentPage(1);
        ui->lineEdit_40->setFocus();
    }
    if (arg1 == tr("Ancho de banda"))
    {
        ui->tabWidget->setCurrentPage(1);
        ui->lineEdit_45->setFocus();
    }
    if (arg1 == tr("Angulo"))
    {
        ui->tabWidget->setCurrentPage(1);
        ui->lineEdit_42->setFocus();
    }
    if (arg1 == tr("Sistema de numeracion"))
    {
        ui->tabWidget->setCurrentPage(0);
        ui->lineEdit_12->setFocus();
    }
    if (arg1 == tr("Superficie o Area"))
    {
        ui->tabWidget->setCurrentPage(0);
        ui->lineEdit_4->setFocus();
    }
    if (arg1 == tr("Campo magnetico"))
    {
        ui->tabWidget->setCurrentPage(1);
        ui->lineEdit_39->setFocus();
    }
    if (arg1 == tr("Calendario de embarazo"))
    {
        ui->tabWidget->setCurrentPage(2);
    }
    if (arg1 == tr("Cantidad de luz"))
    {
        ui->tabWidget->setCurrentPage(1);
        ui->lineEdit_37->setFocus();
    }
    if (arg1 == tr("Cantidad de sustancia"))
    {
        ui->tabWidget->setCurrentPage(3);
        ui->lineEdit_156->setFocus();
    }
    if (arg1 == tr("Capacidad electrica"))
    {
        ui->tabWidget->setCurrentPage(3);
        ui->lineEdit_154->setFocus();
    }
    if (arg1 == tr("Carga electrica"))
    {
        ui->tabWidget->setCurrentPage(3);
        ui->lineEdit_152->setFocus();
    }
    if (arg1 == tr("Caudal volumetrico"))
    {
        ui->tabWidget->setCurrentPage(3);
        ui->lineEdit_150->setFocus();
    }
    if (arg1 == tr("Conductancia electrica"))
    {
        ui->tabWidget->setCurrentPage(3);
        ui->lineEdit_160->setFocus();
    }
    if (arg1 == tr("Consumo de combustible"))
    {
        ui->tabWidget->setCurrentPage(3);
        ui->lineEdit_159->setFocus();
    }
}

void ConversorUD::Reprobar(QString Tipo)
{
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    if (Tipo == "Longitud")
    {
        QString Value = ui->comboBox->currentText();
        QString Valor = ui->lineEdit->text();
        double Cantidad = ui->lineEdit->text().toDouble();
        double Resto = Referencia(Value,"Longitud");
        Unidad(Resto,0.0000000001,Cantidad,tr("Angstrom (Å)"),"Longitud",Valor);
        Unidad1(Resto,0.0000000001,Cantidad,tr("Angstrom (Å)"),"Longitud",Valor);
        Unidad(Resto,0.000000001,Cantidad,tr("Nanometro (nm)"),"Longitud",Valor);
        Unidad1(Resto,0.000000001,Cantidad,tr("Nanometro (nm)"),"Longitud",Valor);
        Unidad(Resto,0.000001,Cantidad,tr("Micrometro (µm)"),"Longitud",Valor);
        Unidad1(Resto,0.00001,Cantidad,tr("Micrometro (µm)"),"Longitud",Valor);
        Unidad(Resto,0.001,Cantidad,tr("Milimetro (mm)"),"Longitud",Valor);
        Unidad1(Resto,0.001,Cantidad,tr("Milimetro (mm)"),"Longitud",Valor);
        Unidad(Resto,0.01,Cantidad,tr("Centimetro (cm)"),"Longitud",Valor);
        Unidad1(Resto,0.01,Cantidad,tr("Centimetro (cm)"),"Longitud",Valor);
        Unidad(Resto,0.1,Cantidad,tr("Decimetro (dm)"),"Longitud",Valor);
        Unidad1(Resto,0.1,Cantidad,tr("Decimetro (dm)"),"Longitud",Valor);
        Unidad(Resto,1,Cantidad,tr("Metro (m)"),"Longitud",Valor);
        Unidad1(Resto,1,Cantidad,tr("Metro (m)"),"Longitud",Valor);
        Unidad(Resto,10,Cantidad,tr("Decametro (dam)"),"Longitud",Valor);
        Unidad1(Resto,10,Cantidad,tr("Decametro (dam)"),"Longitud",Valor);
        Unidad(Resto,100,Cantidad,tr("Hectometro (hm)"),"Longitud",Valor);
        Unidad1(Resto,100,Cantidad,tr("Hectometro (hm)"),"Longitud",Valor);
        Unidad(Resto,1000,Cantidad,tr("Kilometro (km)"),"Longitud",Valor);
        Unidad1(Resto,1000,Cantidad,tr("Kilometro (km)"),"Longitud",Valor);
        Unidad(Resto,10000,Cantidad,tr("Miriametro (mam)"),"Longitud",Valor);
        Unidad1(Resto,10000,Cantidad,tr("Miriametro (mam)"),"Longitud",Valor);
        Unidad(Resto,4828.0320,Cantidad,tr("Legua"),"Longitud",Valor);
        Unidad1(Resto,0.001,Cantidad,tr("Legua"),"Longitud",Valor);
        Unidad(Resto,1609.344,Cantidad,tr("Milla (mi)"),"Longitud",Valor);
        Unidad1(Resto,1609.344,Cantidad,tr("Milla (mi)"),"Longitud",Valor);
        Unidad(Resto,201.168,Cantidad,tr("Estadio"),"Longitud",Valor);
        Unidad1(Resto,201.168,Cantidad,tr("Estadio"),"Longitud",Valor);
        Unidad(Resto,20.1168,Cantidad,tr("Cadena"),"Longitud",Valor);
        Unidad1(Resto,20.1168,Cantidad,tr("Cadena"),"Longitud",Valor);
        Unidad(Resto,5.0292,Cantidad,tr("Barra (rd)"),"Longitud",Valor);
        Unidad1(Resto,5.0292,Cantidad,tr("Barra (rd)"),"Longitud",Valor);
        Unidad(Resto,0.9144,Cantidad,tr("Yarda (yd)"),"Longitud",Valor);
        Unidad1(Resto,0.9144,Cantidad,tr("Yarda (yd)"),"Longitud",Valor);
        Unidad(Resto,0.3048,Cantidad,tr("Pie (ft)"),"Longitud",Valor);
        Unidad1(Resto,0.3048,Cantidad,tr("Pie (ft)"),"Longitud",Valor);
        Unidad(Resto,0.201168,Cantidad,tr("Link"),"Longitud",Valor);
        Unidad1(Resto,0.201168,Cantidad,tr("Link"),"Longitud",Valor);
        Unidad(Resto,0.1016,Cantidad,tr("Mano"),"Longitud",Valor);
        Unidad1(Resto,0.1016,Cantidad,tr("Mano"),"Longitud",Valor);
        Unidad(Resto,0.0254,Cantidad,tr("Pulgada (in)"),"Longitud",Valor);
        Unidad1(Resto,0.0254,Cantidad,tr("Pulgada (in)"),"Longitud",Valor);
        Unidad(Resto,0.00254,Cantidad,tr("Linea"),"Longitud",Valor);
        Unidad1(Resto,0.00254,Cantidad,tr("Linea"),"Longitud",Valor);
        Unidad(Resto,0.0000254,Cantidad,tr("Mil (mil)"),"Longitud",Valor);
        Unidad1(Resto,0.0000254,Cantidad,tr("Mil (mil)"),"Longitud",Valor);
        Unidad(Resto,0.0000254,Cantidad,tr("Thou (thou)"),"Longitud",Valor);
        Unidad1(Resto,0.0000254,Cantidad,tr("Thou (thou)"),"Longitud",Valor);
        Unidad(Resto,1852,Cantidad,tr("Milla nautica"),"Longitud",Valor);
        Unidad1(Resto,1852,Cantidad,tr("Milla nautica"),"Longitud",Valor);
        Unidad(Resto,1.8288,Cantidad,tr("Braza"),"Longitud",Valor);
        Unidad1(Resto,1.8288,Cantidad,tr("Braza"),"Longitud",Valor);
        Unidad(Resto,30857000000000000,Cantidad,tr("Parsec (pc)"),"Longitud",Valor);
        Unidad1(Resto,30857000000000000,Cantidad,tr("Parsec (pc)"),"Longitud",Valor);
        Unidad(Resto,9454254955488000,Cantidad,tr("Ano luz"),"Longitud",Valor);
        Unidad1(Resto,9454254955488000,Cantidad,tr("Ano luz"),"Longitud",Valor);
        Unidad(Resto,147597870610,Cantidad,tr("Unidad astronomica (AE)"),"Longitud",Valor);
        Unidad1(Resto,147597870610,Cantidad,tr("Unidad astronomica (AE)"),"Longitud",Valor);
        Unidad(Resto,17987547480,Cantidad,tr("Minuto luz"),"Longitud",Valor);
        Unidad1(Resto,17987547480,Cantidad,tr("Minuto luz"),"Longitud",Valor);
        Unidad(Resto,299792458,Cantidad,tr("Segundo luz"),"Longitud",Valor);
        Unidad1(Resto,299792458,Cantidad,tr("Segundo luz"),"Longitud",Valor);
        ui->label_14->setText(tr("Distancia o Longitud: Convertir a...")+ui->comboBox->currentText()+"");
        ui->label_15->setText(tr("Distancia o Longitud: Convertir de...")+ui->comboBox->currentText()+"");
    }
    if (Tipo == "Aceleracion")
    {
        QString Value = ui->comboBox_26->currentText();
        QString Valor = ui->lineEdit_47->text();
        double Cantidad = ui->lineEdit_47->text().toDouble();
        double Resto = Referencia(Value,"Aceleracion");
        Unidad(Resto,0.01,Cantidad,tr("Metros por segundo cuadrado (m/s²)"),"Aceleracion",Valor);
        Unidad1(Resto,0.01,Cantidad,tr("Metros por segundo cuadrado (m/s²)"),"Aceleracion",Valor);
        Unidad(Resto,0.0328083333,Cantidad,tr("Pies por segundo cuadrado (ft/s²)"),"Aceleracion",Valor);
        Unidad1(Resto,0.0328083333,Cantidad,tr("Pies por segundo cuadrado (ft/s²)"),"Aceleracion",Valor);
        Unidad(Resto,1,Cantidad,tr("Gal"),"Aceleracion",Valor);
        Unidad1(Resto,1,Cantidad,tr("Gal"),"Aceleracion",Valor);
        Unidad(Resto,1000,Cantidad,tr("Miligal"),"Aceleracion",Valor);
        Unidad1(Resto,1000,Cantidad,tr("Miligal"),"Aceleracion",Valor);
        Unidad(Resto,0.0010197162,Cantidad,tr("Gravedad estandar"),"Aceleracion",Valor);
        Unidad1(Resto,0.0010197162,Cantidad,tr("Gravedad estandar"),"Aceleracion",Valor);
        Unidad(Resto,0.0010197162,Cantidad,tr("Almacenamiento (g)"),"Aceleracion",Valor);
        Unidad1(Resto,0.0010197162,Cantidad,tr("Fuerza G (g)"),"Aceleracion",Valor);
        ui->label_14->setText(tr("Aceleracion: Convertir a...")+ui->comboBox_26->currentText()+"");
        ui->label_15->setText(tr("Aceleracion: Convertir de...")+ui->comboBox_26->currentText()+"");
    }
    if (Tipo == "Almacenamiento")
    {
        QString Value = ui->comboBox_19->currentText();
        QString Valor = ui->lineEdit_40->text();
        double Cantidad = ui->lineEdit_40->text().toDouble();
        double Resto = Referencia(Value,"Almacenamiento");
        Unidad(Resto,8,Cantidad,tr("Bit"),"Almacenamiento",Valor);
        Unidad1(Resto,8,Cantidad,tr("Bit"),"Almacenamiento",Valor);
        Unidad(Resto,2,Cantidad,tr("Nibble"),"Almacenamiento",Valor);
        Unidad1(Resto,2,Cantidad,tr("Nibble"),"Almacenamiento",Valor);
        Unidad(Resto,0.0078125,Cantidad,tr("Kilobit"),"Almacenamiento",Valor);
        Unidad1(Resto,0.0078125,Cantidad,tr("Kilobit"),"Almacenamiento",Valor);
        Unidad(Resto,0.0000076294,Cantidad,tr("Megabit"),"Almacenamiento",Valor);
        Unidad1(Resto,0.0000076294,Cantidad,tr("Megabit"),"Almacenamiento",Valor);
        Unidad(Resto,0.00000000074505805969,Cantidad,tr("Gigabit"),"Almacenamiento",Valor);
        Unidad1(Resto,0.00000000074505805969,Cantidad,tr("Gigabit"),"Almacenamiento",Valor);
        Unidad(Resto,0.00000000000072759580612,Cantidad,tr("Terabit"),"Almacenamiento",Valor);
        Unidad1(Resto,0.00000000000072759580612,Cantidad,tr("Terabit"),"Almacenamiento",Valor);
        Unidad(Resto,0.0000000000000007105427742,Cantidad,tr("Petabit"),"Almacenamiento",Valor);
        Unidad1(Resto,0.0000000000000007105427742,Cantidad,tr("Petabit"),"Almacenamiento",Valor);
        Unidad(Resto,0.000000000000000000769388942719,Cantidad,tr("Exabit"),"Almacenamiento",Valor);
        Unidad1(Resto,0.000000000000000000769388942719,Cantidad,tr("Exabit"),"Almacenamiento",Valor);
        Unidad(Resto,1,Cantidad,tr("Byte (B)"),"Almacenamiento",Valor);
        Unidad1(Resto,1,Cantidad,tr("Byte (B)"),"Almacenamiento",Valor);
        Unidad(Resto,0.0009765625,Cantidad,tr("Kilobyte (KB)"),"Almacenamiento",Valor);
        Unidad1(Resto,0.0009765625,Cantidad,tr("Kilobyte (KB)"),"Almacenamiento",Valor);
        Unidad(Resto,0.000000095367431641,Cantidad,tr("Megabyte (MB)"),"Almacenamiento",Valor);
        Unidad1(Resto,0.000000095367431641,Cantidad,tr("Megabyte (MB)"),"Almacenamiento",Valor);
        Unidad(Resto,0.000000000093132257462,Cantidad,tr("Gigabyte (GB)"),"Almacenamiento",Valor);
        Unidad1(Resto,0.000000000093132257462,Cantidad,tr("Gigabyte (GB)"),"Almacenamiento",Valor);
        Unidad(Resto,0.000000000000090949478149,Cantidad,tr("Terabyte (TB)"),"Almacenamiento",Valor);
        Unidad1(Resto,0.000000000000090949478149,Cantidad,tr("Terabyte (TB)"),"Almacenamiento",Valor);
        Unidad(Resto,0.000000000000000088817853928,Cantidad,tr("Petabyte (PB)"),"Almacenamiento",Valor);
        Unidad1(Resto,0.000000000000000088817853928,Cantidad,tr("Petabyte (PB)"),"Almacenamiento",Valor);
        Unidad(Resto,0.000000000000000000086736183167,Cantidad,tr("Exabyte (EB)"),"Almacenamiento",Valor);
        Unidad1(Resto,0.000000000000000000086736183167,Cantidad,tr("Exabyte (EB)"),"Almacenamiento",Valor);
        ui->label_14->setText(tr("Almacenamiento: Convertir a...")+ui->comboBox_19->currentText()+"");
        ui->label_15->setText(tr("Almacenamiento: Convertir de...")+ui->comboBox_19->currentText()+"");
    }
    if (Tipo == "Ancho banda")
    {
        QString Value = ui->comboBox_24->currentText();
        QString Valor = ui->lineEdit_45->text();
        double Cantidad = ui->lineEdit_45->text().toDouble();
        double Resto = Referencia(Value,"Ancho banda");
        Unidad(Resto,8000000000,Cantidad,tr("Bit por segundo (bit/s)"),"Ancho banda",Valor);
        Unidad1(Resto,8000000000,Cantidad,tr("Bit por segundo (bit/s)"),"Ancho banda",Valor);
        Unidad(Resto,8000000,Cantidad,tr("Kilobit por segundo (kbit/s)"),"Ancho banda",Valor);
        Unidad1(Resto,8000000,Cantidad,tr("Kilobit por segundo (kbit/s)"),"Ancho banda",Valor);
        Unidad(Resto,8000,Cantidad,tr("Megabit por segundo (Mbit/s)"),"Ancho banda",Valor);
        Unidad1(Resto,8000,Cantidad,tr("Megabit por segundo (Mbit/s)"),"Ancho banda",Valor);
        Unidad(Resto,8,Cantidad,tr("Gigabit por segundo (Gbit/s)"),"Ancho banda",Valor);
        Unidad1(Resto,8,Cantidad,tr("Gigabit por segundo (Gbit/s)"),"Ancho banda",Valor);
        Unidad(Resto,0.008,Cantidad,tr("Terabit por segundo (Tbit/s)"),"Ancho banda",Valor);
        Unidad1(Resto,0.008,Cantidad,tr("Terabit por segundo (Tbit/s)"),"Ancho banda",Valor);
        Unidad(Resto,7812500,Cantidad,tr("Kibibit por segundo (Kibit/s)"),"Ancho banda",Valor);
        Unidad1(Resto,7812500,Cantidad,tr("Kibibit por segundo (Kibit/s)"),"Ancho banda",Valor);
        Unidad(Resto,0.0000078125,Cantidad,tr("Mebibit por segundo (Mibit/s)"),"Ancho banda",Valor);
        Unidad1(Resto,0.0000078125,Cantidad,tr("Mebibit por segundo (Mibit/s)"),"Ancho banda",Valor);
        Unidad(Resto,7.4505806,Cantidad,tr("Gibibit por segundo (Gibit/s)"),"Ancho banda",Valor);
        Unidad1(Resto,7.4505806,Cantidad,tr("Gibibit por segundo (Gibit/s)"),"Ancho banda",Valor);
        Unidad(Resto,0.00727596,Cantidad,tr("Tebibit por segundo (Tibit/s)"),"Ancho banda",Valor);
        Unidad1(Resto,0.00727596,Cantidad,tr("Tebibit por segundo (Tibit/s)"),"Ancho banda",Valor);
        Unidad(Resto,1000000000,Cantidad,tr("Byte por segundo (B/s)"),"Ancho banda",Valor);
        Unidad1(Resto,1000000000,Cantidad,tr("Byte por segundo (B/s)"),"Ancho banda",Valor);
        Unidad(Resto,1000000,Cantidad,tr("Kilobyte por segundo (kB/s)"),"Ancho banda",Valor);
        Unidad1(Resto,1000000,Cantidad,tr("Kilobyte por segundo (kB/s)"),"Ancho banda",Valor);
        Unidad(Resto,1000,Cantidad,tr("Megabyte por segundo (MB/s)"),"Ancho banda",Valor);
        Unidad1(Resto,1000,Cantidad,tr("Megabyte por segundo (MB/s)"),"Ancho banda",Valor);
        Unidad(Resto,1,Cantidad,tr("Gigabyte por segundo (GB/s)"),"Ancho banda",Valor);
        Unidad1(Resto,1,Cantidad,tr("Gigabyte por segundo (GB/s)"),"Ancho banda",Valor);
        Unidad(Resto,0.001,Cantidad,tr("Terabyte por segundo (TB/s)"),"Ancho banda",Valor);
        Unidad1(Resto,0.001,Cantidad,tr("Terabyte por segundo (TB/s)"),"Ancho banda",Valor);
        Unidad(Resto,976562.5,Cantidad,tr("Kibibyte por segundo (KiB/s)"),"Ancho banda",Valor);
        Unidad1(Resto,976562.5,Cantidad,tr("Kibibyte por segundo (KiB/s)"),"Ancho banda",Valor);
        Unidad(Resto,953.67431641,Cantidad,tr("Mebibyte por segundo (MiB/s)"),"Ancho banda",Valor);
        Unidad1(Resto,953.67431641,Cantidad,tr("Mebibyte por segundo (MiB/s)"),"Ancho banda",Valor);
        Unidad(Resto,0.93132257,Cantidad,tr("Gibibyte por segundo (GiB/s)"),"Ancho banda",Valor);
        Unidad1(Resto,0.93132257,Cantidad,tr("Gibibyte por segundo (GiB/s)"),"Ancho banda",Valor);
        Unidad(Resto,0.00090949,Cantidad,tr("Tebibyte por segundo (TiB/s)"),"Ancho banda",Valor);
        Unidad1(Resto,0.00090949,Cantidad,tr("Tebibyte por segundo (TiB/s)"),"Ancho banda",Valor);
        Unidad(Resto,2880000000000,Cantidad,tr("Bit por hora"),"Ancho banda",Valor);
        Unidad1(Resto,2880000000000,Cantidad,tr("Bit por hora"),"Ancho banda",Valor);
        Unidad(Resto,28800000000,Cantidad,tr("Kilobit por hora"),"Ancho banda",Valor);
        Unidad1(Resto,28800000000,Cantidad,tr("Kilobit por hora"),"Ancho banda",Valor);
        Unidad(Resto,2880000,Cantidad,tr("Megabit por hora"),"Ancho banda",Valor);
        Unidad1(Resto,2880000,Cantidad,tr("Megabit por hora"),"Ancho banda",Valor);
        Unidad(Resto,28800,Cantidad,tr("Gigabit por hora"),"Ancho banda",Valor);
        Unidad1(Resto,28800,Cantidad,tr("Gigabit por hora"),"Ancho banda",Valor);
        Unidad(Resto,28.8,Cantidad,tr("Terabit por hora"),"Ancho banda",Valor);
        Unidad1(Resto,28.8,Cantidad,tr("Terabit por hora"),"Ancho banda",Valor);
        Unidad(Resto,28125000000,Cantidad,tr("Kibibit por hora"),"Ancho banda",Valor);
        Unidad1(Resto,28125000000,Cantidad,tr("Kibibit por hora"),"Ancho banda",Valor);
        Unidad(Resto,27465820.3,Cantidad,tr("Mebibit por hora"),"Ancho banda",Valor);
        Unidad1(Resto,27465820.3,Cantidad,tr("Mebibit por hora"),"Ancho banda",Valor);
        Unidad(Resto,26822.0901,Cantidad,tr("Gibibit por hora"),"Ancho banda",Valor);
        Unidad1(Resto,26822.0901,Cantidad,tr("Gibibit por hora"),"Ancho banda",Valor);
        Unidad(Resto,26.19344741,Cantidad,tr("Tebibit por hora"),"Ancho banda",Valor);
        Unidad1(Resto,26.19344741,Cantidad,tr("Tebibit por hora"),"Ancho banda",Valor);
        Unidad(Resto,3600000000000,Cantidad,tr("Byte por hora"),"Ancho banda",Valor);
        Unidad1(Resto,3600000000000,Cantidad,tr("Byte por hora"),"Ancho banda",Valor);
        Unidad(Resto,3600000000.00,Cantidad,tr("Kilobyte por hora"),"Ancho banda",Valor);
        Unidad1(Resto,3600000000.00,Cantidad,tr("Kilobyte por hora"),"Ancho banda",Valor);
        Unidad(Resto,3600000,Cantidad,tr("Megabyte por hora"),"Ancho banda",Valor);
        Unidad1(Resto,3600000,Cantidad,tr("Megabyte por hora"),"Ancho banda",Valor);
        Unidad(Resto,3600,Cantidad,tr("Gigabyte por hora"),"Ancho banda",Valor);
        Unidad1(Resto,3600,Cantidad,tr("Gigabyte por hora"),"Ancho banda",Valor);
        Unidad(Resto,3.6,Cantidad,tr("Terabyte por hora"),"Ancho banda",Valor);
        Unidad1(Resto,3.6,Cantidad,tr("Terabyte por hora"),"Ancho banda",Valor);
        Unidad(Resto,3515625000.00,Cantidad,tr("Kibibyte por hora"),"Ancho banda",Valor);
        Unidad1(Resto,3516625000.00,Cantidad,tr("Kibibyte por hora"),"Ancho banda",Valor);
        Unidad(Resto,3433227.54,Cantidad,tr("Mebibyte por hora"),"Ancho banda",Valor);
        Unidad1(Resto,3433227.54,Cantidad,tr("Mebibyte por hora"),"Ancho banda",Valor);
        Unidad(Resto,3352.76127,Cantidad,tr("Gibibyte por hora"),"Ancho banda",Valor);
        Unidad1(Resto,3352.76127,Cantidad,tr("Gibibyte por hora"),"Ancho banda",Valor);
        Unidad(Resto,3.27418093,Cantidad,tr("Tebibyte por hora"),"Ancho banda",Valor);
        Unidad1(Resto,3.27418093,Cantidad,tr("Tebibyte por hora"),"Ancho banda",Valor);
        Unidad(Resto,69120000000000,Cantidad,tr("Bit por dia"),"Ancho banda",Valor);
        Unidad1(Resto,69120000000000,Cantidad,tr("Bit por dia"),"Ancho banda",Valor);
        Unidad(Resto,691200000000,Cantidad,tr("Kilobit por dia"),"Ancho banda",Valor);
        Unidad1(Resto,691200000000,Cantidad,tr("Kilobit por dia"),"Ancho banda",Valor);
        Unidad(Resto,691200000,Cantidad,tr("Megabit por dia"),"Ancho banda",Valor);
        Unidad1(Resto,691200000,Cantidad,tr("Megabit por dia"),"Ancho banda",Valor);
        Unidad(Resto,691200,Cantidad,tr("Gigabit por dia"),"Ancho banda",Valor);
        Unidad1(Resto,691200,Cantidad,tr("Gigabit por dia"),"Ancho banda",Valor);
        Unidad(Resto,691.2,Cantidad,tr("Terabit por dia"),"Ancho banda",Valor);
        Unidad1(Resto,691.2,Cantidad,tr("Terabit por dia"),"Ancho banda",Valor);
        Unidad(Resto,675000000000,Cantidad,tr("Kibibit por dia"),"Ancho banda",Valor);
        Unidad1(Resto,675000000000,Cantidad,tr("Kibibit por dia"),"Ancho banda",Valor);
        Unidad(Resto,659179687.5,Cantidad,tr("Mebibit por dia"),"Ancho banda",Valor);
        Unidad1(Resto,659179687.5,Cantidad,tr("Mebibit por dia"),"Ancho banda",Valor);
        Unidad(Resto,643730.164,Cantidad,tr("Gibibit por dia"),"Ancho banda",Valor);
        Unidad1(Resto,643730.164,Cantidad,tr("Gibibit por dia"),"Ancho banda",Valor);
        Unidad(Resto,628.64273787,Cantidad,tr("Tebibit por dia"),"Ancho banda",Valor);
        Unidad1(Resto,628.64273787,Cantidad,tr("Tebibit por dia"),"Ancho banda",Valor);
        Unidad(Resto,8640000000000,Cantidad,tr("Byte por dia"),"Ancho banda",Valor);
        Unidad1(Resto,8640000000000,Cantidad,tr("Byte por dia"),"Ancho banda",Valor);
        Unidad(Resto,86400000000,Cantidad,tr("Kilobyte por dia"),"Ancho banda",Valor);
        Unidad1(Resto,86400000000,Cantidad,tr("Kilobyte por dia"),"Ancho banda",Valor);
        Unidad(Resto,86400000,Cantidad,tr("Megabyte por dia"),"Ancho banda",Valor);
        Unidad1(Resto,86400000,Cantidad,tr("Megabyte por dia"),"Ancho banda",Valor);
        Unidad(Resto,86400,Cantidad,tr("Gigabyte por dia"),"Ancho banda",Valor);
        Unidad1(Resto,86400,Cantidad,tr("Gigabyte por dia"),"Ancho banda",Valor);
        Unidad(Resto,86.4,Cantidad,tr("Terabyte por dia"),"Ancho banda",Valor);
        Unidad1(Resto,86.4,Cantidad,tr("Terabyte por dia"),"Ancho banda",Valor);
        Unidad(Resto,84375000000,Cantidad,tr("Kibibyte por dia"),"Ancho banda",Valor);
        Unidad1(Resto,84375000000,Cantidad,tr("Kibibyte por dia"),"Ancho banda",Valor);
        Unidad(Resto,82397460.9,Cantidad,tr("Mebibyte por dia"),"Ancho banda",Valor);
        Unidad1(Resto,82397460.9,Cantidad,tr("Mebibyte por dia"),"Ancho banda",Valor);
        Unidad(Resto,80466.2704,Cantidad,tr("Gibibyte por dia"),"Ancho banda",Valor);
        Unidad1(Resto,80466.2704,Cantidad,tr("Gibibyte por dia"),"Ancho banda",Valor);
        Unidad(Resto,78.58034223,Cantidad,tr("Tebibyte por dia"),"Ancho banda",Valor);
        Unidad1(Resto,78.58034223,Cantidad,tr("Tebibyte por dia"),"Ancho banda",Valor);
        ui->label_14->setText(tr("Ancho de banda: Convertir a...")+ui->comboBox_24->currentText()+"");
        ui->label_15->setText(tr("Ancho de banda: Convertir de...")+ui->comboBox_24->currentText()+"");
    }
    if (Tipo == "Angulo")
    {
        QString Value = ui->comboBox_21->currentText();
        QString Valor = ui->lineEdit_42->text();
        double Cantidad = ui->lineEdit_42->text().toDouble();
        double Resto = Referencia(Value,"Angulo");
        Unidad(Resto,360,Cantidad,tr("Grado sexagesimal"),"Angulo",Valor);
        Unidad1(Resto,360,Cantidad,tr("Grado sexagesimal"),"Angulo",Valor);
        Unidad(Resto,6.2831853072,Cantidad,tr("Radian"),"Angulo",Valor);
        Unidad1(Resto,6.2831853072,Cantidad,tr("Radian)"),"Angulo",Valor);
        Unidad(Resto,1,Cantidad,tr("Circulo"),"Angulo",Valor);
        Unidad1(Resto,1,Cantidad,tr("Circulo"),"Angulo",Valor);
        Unidad(Resto,1,Cantidad,tr("Giro"),"Angulo",Valor);
        Unidad1(Resto,1,Cantidad,tr("Giro"),"Angulo",Valor);
        Unidad(Resto,1,Cantidad,tr("Ciclo"),"Angulo",Valor);
        Unidad1(Resto,1,Cantidad,tr("Ciclo"),"Angulo",Valor);
        Unidad(Resto,1,Cantidad,tr("Rotacion"),"Angulo",Valor);
        Unidad1(Resto,1,Cantidad,tr("Rotacion"),"Angulo",Valor);
        Unidad(Resto,1,Cantidad,tr("Revolucion"),"Angulo",Valor);
        Unidad1(Resto,1,Cantidad,tr("Revolucion"),"Angulo",Valor);
        Unidad(Resto,4,Cantidad,tr("Angulo recto"),"Angulo",Valor);
        Unidad1(Resto,4,Cantidad,tr("Angulo recto"),"Angulo",Valor);
        Unidad(Resto,6400,Cantidad,tr("Milesimal (OTAN)"),"Angulo",Valor);
        Unidad1(Resto,6400,Cantidad,tr("Milesimal (OTAN)"),"Angulo",Valor);
        Unidad(Resto,6000,Cantidad,tr("Milesimal (Union Sovietica)"),"Angulo",Valor);
        Unidad1(Resto,6000,Cantidad,tr("Milesimal (Union Sovietica)"),"Angulo",Valor);
        Unidad(Resto,6300,Cantidad,tr("Milesimal (Suecia)"),"Angulo",Valor);
        Unidad1(Resto,6300,Cantidad,tr("Milesimal (Suecia)"),"Angulo",Valor);
        Unidad(Resto,400,Cantidad,tr("Grado centesimal"),"Angulo",Valor);
        Unidad1(Resto,400,Cantidad,tr("Grado centesimal"),"Angulo",Valor);
        Unidad(Resto,400,Cantidad,tr("Gon"),"Angulo",Valor);
        Unidad1(Resto,400,Cantidad,tr("Gon"),"Angulo",Valor);
        Unidad(Resto,32,Cantidad,tr("Punto"),"Angulo",Valor);
        Unidad1(Resto,32,Cantidad,tr("Punto"),"Angulo",Valor);
        Unidad(Resto,24,Cantidad,tr("Angulo horario"),"Angulo",Valor);
        Unidad1(Resto,24,Cantidad,tr("Angulo horario"),"Angulo",Valor);
        ui->label_14->setText(tr("Angulo: Convertir a...")+ui->comboBox_21->currentText()+"");
        ui->label_15->setText(tr("Angulo: Convertir de...")+ui->comboBox_21->currentText()+"");
    }
    if (Tipo == "Area")
    {
        QString Value = ui->comboBox_4->currentText();
        QString Valor = ui->lineEdit_4->text();
        double Cantidad = ui->lineEdit_4->text().toDouble();
        double Resto = Referencia(Value,"Area");
        Unidad(Resto,100000000000000000000.00,Cantidad,tr("Nanometro cuadrado (nm²)"),"Area",Valor);
        Unidad1(Resto,100000000000000000000.00,Cantidad,tr("Nanometro cuadrado (nm²)"),"Area",Valor);
        Unidad(Resto,100000000000000,Cantidad,tr("Micrometro cuadrado (µm²)"),"Area",Valor);
        Unidad1(Resto,100000000000000,Cantidad,tr("Micrometro cuadrado (µm²)"),"Area",Valor);
        Unidad(Resto,100000000,Cantidad,tr("Milimetro cuadrado (mm²)"),"Area",Valor);
        Unidad1(Resto,100000000,Cantidad,tr("Milimetro cuadrado (mm²)"),"Area",Valor);
        Unidad(Resto,1000000,Cantidad,tr("Centimetro cuadrado (cm²)"),"Area",Valor);
        Unidad1(Resto,1000000,Cantidad,tr("Centimetro cuadrado (cm²)"),"Area",Valor);
        Unidad(Resto,10000,Cantidad,tr("Decimetro cuadrado (dm²)"),"Area",Valor);
        Unidad1(Resto,10000,Cantidad,tr("Decimetro cuadrado (dm²)"),"Area",Valor);
        Unidad(Resto,100,Cantidad,tr("Metro cuadrado (m²)"),"Area",Valor);
        Unidad1(Resto,100,Cantidad,tr("Metro cuadrado (m²)"),"Area",Valor);
        Unidad(Resto,1,Cantidad,tr("Area (a)"),"Area",Valor);
        Unidad1(Resto,1,Cantidad,tr("Area (a)"),"Area",Valor);
        Unidad(Resto,0.01,Cantidad,tr("Hectarea (ha)"),"Area",Valor);
        Unidad1(Resto,0.01,Cantidad,tr("Hectarea (ha)"),"Area",Valor);
        Unidad(Resto,0.0001,Cantidad,tr("Kilometro cuadrado (km²)"),"Area",Valor);
        Unidad1(Resto,0.0001,Cantidad,tr("Kilometro cuadrado (km²)"),"Area",Valor);
        Unidad(Resto,0.0000010725,Cantidad,tr("Municipio"),"Area",Valor);
        Unidad1(Resto,0.0000010725,Cantidad,tr("Municipio"),"Area",Valor);
        Unidad(Resto,0.0000386102,Cantidad,tr("Milla cuadrada"),"Area",Valor);
        Unidad1(Resto,0.0000386102,Cantidad,tr("Milla cuadrada"),"Area",Valor);
        Unidad(Resto,0.0001544409,Cantidad,tr("Patrimonio familiar"),"Area",Valor);
        Unidad1(Resto,0.0001544409,Cantidad,tr("Patrimonio familiar"),"Area",Valor);
        Unidad(Resto,0.02471055,Cantidad,tr("Acre"),"Area",Valor);
        Unidad1(Resto,0.02471055,Cantidad,tr("Acre"),"Area",Valor);
        Unidad(Resto,0.0988422,Cantidad,tr("Rood"),"Area",Valor);
        Unidad1(Resto,0.0988422,Cantidad,tr("Rood"),"Area",Valor);
        Unidad(Resto,3.953687,Cantidad,tr("Rod cuadrada"),"Area",Valor);
        Unidad1(Resto,3.953687,Cantidad,tr("Rod cuadrada"),"Area",Valor);
        Unidad(Resto,10.76391,Cantidad,tr("Cuadrado"),"Area",Valor);
        Unidad1(Resto,10.76391,Cantidad,tr("Cuadrado"),"Area",Valor);
        Unidad(Resto,119.599,Cantidad,tr("Yarda cuadrada (yd²)"),"Area",Valor);
        Unidad1(Resto,119.599,Cantidad,tr("Yarda cuadrada (yd²)"),"Area",Valor);
        Unidad(Resto,1076.391,Cantidad,tr("Pie cuadrado (ft²)"),"Area",Valor);
        Unidad1(Resto,1076.391,Cantidad,tr("Pie cuadrado (ft²)"),"Area",Valor);
        Unidad(Resto,155000.3,Cantidad,tr("Pulgada cuadrada (in²)"),"Area",Valor);
        Unidad1(Resto,155000.3,Cantidad,tr("Pulgada cuadrada (in²)"),"Area",Valor);
        Unidad(Resto,30.24999,Cantidad,tr("Tsubo"),"Area",Valor);
        Unidad1(Resto,30.24999,Cantidad,tr("Tsubo"),"Area",Valor);
        Unidad(Resto,10083.33,Cantidad,tr("Cho"),"Area",Valor);
        Unidad1(Resto,10083.33,Cantidad,tr("Cho"),"Area",Valor);
        Unidad(Resto,100833.3,Cantidad,tr("Tann"),"Area",Valor);
        Unidad1(Resto,100833.3,Cantidad,tr("Tann"),"Area",Valor);
        Unidad(Resto,1008333,Cantidad,tr("Se"),"Area",Valor);
        Unidad1(Resto,1008333,Cantidad,tr("Se"),"Area",Valor);
        Unidad(Resto,0.1,Cantidad,tr("Donum metrico"),"Area",Valor);
        Unidad1(Resto,0.1,Cantidad,tr("Donum metrico"),"Area",Valor);
        Unidad(Resto,0.074749375,Cantidad,tr("Donum de Chipre"),"Area",Valor);
        Unidad1(Resto,0.074749375,Cantidad,tr("Donum de Chipre"),"Area",Valor);
        Unidad(Resto,0.04,Cantidad,tr("Donum iraqui"),"Area",Valor);
        Unidad1(Resto,0.04,Cantidad,tr("Donum iraqui"),"Area",Valor);
        Unidad(Resto,0.01,Cantidad,tr("Estrema griego"),"Area",Valor);
        Unidad1(Resto,0.01,Cantidad,tr("Estrema griego"),"Area",Valor);
        Unidad(Resto,0.0140056,Cantidad,tr("Campo de futbol"),"Area",Valor);
        Unidad1(Resto,0.0140056,Cantidad,tr("Campo de futbol"),"Area",Valor);
        ui->label_14->setText(tr("Superficie o Area: Convertir a...")+ui->comboBox_4->currentText()+"");
        ui->label_15->setText(tr("Superficie o Area: Convertir de...")+ui->comboBox_4->currentText()+"");
    }
    if (Tipo == "Campo")
    {
        QString Value = ui->comboBox_18->currentText();
        QString Valor = ui->lineEdit_39->text();
        double Cantidad = ui->lineEdit_39->text().toDouble();
        double Resto = Referencia(Value,"Campo");
        Unidad(Resto,0.7957747155,Cantidad,tr("Amperio por metro (A/m)"),"Campo",Valor);
        Unidad1(Resto,0.7957747155,Cantidad,tr("Amperio por metro (A/m)"),"Campo",Valor);
        Unidad(Resto,0.7957747155,Cantidad,tr("Amperio-vuelta por metro (AT/m)"),"Campo",Valor);
        Unidad1(Resto,0.7957747155,Cantidad,tr("Amperio-vuelta por metro (AT/m)"),"Campo",Valor);
        Unidad(Resto,0.01,Cantidad,tr("Oersted (Oe)"),"Campo",Valor);
        Unidad1(Resto,0.01,Cantidad,tr("Oersted (Oe)"),"Campo",Valor);
        Unidad(Resto,1,Cantidad,tr("Gilbert por metro (Gi/m)"),"Campo",Valor);
        Unidad1(Resto,1,Cantidad,tr("Gilbert por metro (Gi/m)"),"Campo",Valor);
        ui->label_14->setText(tr("Campo magnetico: Convertir a...")+ui->comboBox_18->currentText()+"");
        ui->label_15->setText(tr("Campo magnetico: Convertir de...")+ui->comboBox_18->currentText()+"");
    }
    if (Tipo == "Luz")
    {
        QString Value = ui->comboBox_17->currentText();
        QString Valor = ui->lineEdit_37->text();
        double Cantidad = ui->lineEdit_37->text().toDouble();
        double Resto = Referencia(Value,"Luz");
        Unidad(Resto,3600,Cantidad,tr("Talbot (T)"),"Luz",Valor);
        Unidad1(Resto,3600,Cantidad,tr("Talbot (T)"),"Luz",Valor);
        Unidad(Resto,3600,Cantidad,tr("Lumen segundo (lm·s)"),"Luz",Valor);
        Unidad1(Resto,3600,Cantidad,tr("Lumen segundo (lm·s)"),"Luz",Valor);
        Unidad(Resto,60,Cantidad,tr("Lumen minuto (lm·min)"),"Luz",Valor);
        Unidad1(Resto,60,Cantidad,tr("Lumen minuto (lm·min)"),"Luz",Valor);
        Unidad(Resto,1,Cantidad,tr("Lumen hora (lm·h)"),"Luz",Valor);
        Unidad1(Resto,1,Cantidad,tr("Lumen hora (lm·h)"),"Luz",Valor);
        ui->label_14->setText(tr("Cantidad de luz: Convertir a...")+ui->comboBox_17->currentText()+"");
        ui->label_15->setText(tr("Cantidad de luz: Convertir de...")+ui->comboBox_17->currentText()+"");
    }
    if (Tipo == "Sustancia")
    {
        QString Value = ui->comboBox_50->currentText();
        QString Valor = ui->lineEdit_156->text();
        double Cantidad = ui->lineEdit_156->text().toDouble();
        double Resto = Referencia(Value,"Sustancia");
        Unidad(Resto,1000,Cantidad,tr("Milimol (mmol)"),"Sustancia",Valor);
        Unidad1(Resto,1000,Cantidad,tr("Milimol (mmol)"),"Sustancia",Valor);
        Unidad(Resto,1,Cantidad,tr("Mol (mol)"),"Sustancia",Valor);
        Unidad1(Resto,1,Cantidad,tr("Mol (mol)"),"Sustancia",Valor);
        Unidad(Resto,0.001,Cantidad,tr("Kilomol (kmol)"),"Sustancia",Valor);
        Unidad1(Resto,0.001,Cantidad,tr("Kilomol (kmol)"),"Sustancia",Valor);
        Unidad(Resto,0.0022046226,Cantidad,tr("Libra mol (lb-mol)"),"Sustancia",Valor);
        Unidad1(Resto,0.0022046226,Cantidad,tr("Libra mol (lb-mol)"),"Sustancia",Valor);
        ui->label_14->setText(tr("Cantidad de sustancia: Convertir a...")+ui->comboBox_50->currentText()+"");
        ui->label_15->setText(tr("Cantidad de sustancia: Convertir de...")+ui->comboBox_50->currentText()+"");
    }
    if (Tipo == "Electrica")
    {
        QString Value = ui->comboBox_48->currentText();
        QString Valor = ui->lineEdit_154->text();
        double Cantidad = ui->lineEdit_154->text().toDouble();
        double Resto = Referencia(Value,"Electrica");
        Unidad(Resto,1,Cantidad,tr("Faradio (F)"),"Electrica",Valor);
        Unidad1(Resto,1,Cantidad,tr("Faradio (F)"),"Electrica",Valor);
        Unidad(Resto,0.1,Cantidad,tr("Decafaradio (daF)"),"Electrica",Valor);
        Unidad1(Resto,0.1,Cantidad,tr("Decafaradio (daF)"),"Electrica",Valor);
        Unidad(Resto,0.01,Cantidad,tr("Hectofaradio (hF)"),"Electrica",Valor);
        Unidad1(Resto,0.01,Cantidad,tr("Hectofaradio (hF)"),"Electrica",Valor);
        Unidad(Resto,0.001,Cantidad,tr("Kilofaradio (kF)"),"Electrica",Valor);
        Unidad1(Resto,0.001,Cantidad,tr("Kilofaradio (kF)"),"Electrica",Valor);
        Unidad(Resto,0.000001,Cantidad,tr("Megafaradio (MF)"),"Electrica",Valor);
        Unidad1(Resto,0.000001,Cantidad,tr("Megafaradio (MF)"),"Electrica",Valor);
        Unidad(Resto,0.000000001,Cantidad,tr("Gigafaradio (GF)"),"Electrica",Valor);
        Unidad1(Resto,0.000000001,Cantidad,tr("Gigafaradio (GF)"),"Electrica",Valor);
        Unidad(Resto,0.000000000001,Cantidad,tr("Terafaradio (TF)"),"Electrica",Valor);
        Unidad1(Resto,0.000000000001,Cantidad,tr("Terafaradio (TF)"),"Electrica",Valor);
        Unidad(Resto,0.000000000000001,Cantidad,tr("Petafaradio (PF)"),"Electrica",Valor);
        Unidad1(Resto,0.000000000000001,Cantidad,tr("Petafaradio (PF)"),"Electrica",Valor);
        Unidad(Resto,0.000000000000000001,Cantidad,tr("Exafaradio (EF)"),"Electrica",Valor);
        Unidad1(Resto,0.000000000000000001,Cantidad,tr("Exafaradio (EF)"),"Electrica",Valor);
        Unidad(Resto,0.000000000000000000001,Cantidad,tr("Zettafaradio (ZF)"),"Electrica",Valor);
        Unidad1(Resto,0.000000000000000000001,Cantidad,tr("Zettafaradio (ZF)"),"Electrica",Valor);
        Unidad(Resto,0.000000000000000000000001,Cantidad,tr("Yottafaradio (YF)"),"Electrica",Valor);
        Unidad1(Resto,0.000000000000000000000001,Cantidad,tr("Yottafaradio (YF)"),"Electrica",Valor);
        Unidad(Resto,10,Cantidad,tr("Decifaradio (dF)"),"Electrica",Valor);
        Unidad1(Resto,10,Cantidad,tr("Decifaradio (dF)"),"Electrica",Valor);
        Unidad(Resto,100,Cantidad,tr("Centifaradio (cF)"),"Electrica",Valor);
        Unidad1(Resto,100,Cantidad,tr("Centifaradio (cF)"),"Electrica",Valor);
        Unidad(Resto,1000,Cantidad,tr("Milifaradio (mF)"),"Electrica",Valor);
        Unidad1(Resto,1000,Cantidad,tr("Milifaradio (mF)"),"Electrica",Valor);
        Unidad(Resto,1000000,Cantidad,tr("Microfaradio (µF)"),"Electrica",Valor);
        Unidad1(Resto,1000000,Cantidad,tr("Microfaradio (µF)"),"Electrica",Valor);
        Unidad(Resto,1000000000,Cantidad,tr("Nanofaradio (nF)"),"Electrica",Valor);
        Unidad1(Resto,1000000000,Cantidad,tr("Nanofaradio (nF)"),"Electrica",Valor);
        Unidad(Resto,1000000000000,Cantidad,tr("Picofaradio (pF)"),"Electrica",Valor);
        Unidad1(Resto,1000000000000,Cantidad,tr("Picofaradio (pF)"),"Electrica",Valor);
        Unidad(Resto,1000000000000000,Cantidad,tr("Femtofaradio (fF)"),"Electrica",Valor);
        Unidad1(Resto,1000000000000000,Cantidad,tr("Femtofaradio (fF)"),"Electrica",Valor);
        Unidad(Resto,1000000000000000000,Cantidad,tr("Attofaradio (aF)"),"Electrica",Valor);
        Unidad1(Resto,1000000000000000000,Cantidad,tr("Attofaradio (aF)"),"Electrica",Valor);
        Unidad(Resto,1000000000000000000000.00,Cantidad,tr("Zeptofaradio (zF)"),"Electrica",Valor);
        Unidad1(Resto,1000000000000000000000.00,Cantidad,tr("Zeptofaradio (zF)"),"Electrica",Valor);
        Unidad(Resto,1000000000000000000000000.00,Cantidad,tr("Yoctofaradio (yF)"),"Electrica",Valor);
        Unidad1(Resto,1000000000000000000000000.00,Cantidad,tr("Yoctofaradio (yF)"),"Electrica",Valor);
        Unidad(Resto,1,Cantidad,tr("Culombio por voltio"),"Electrica",Valor);
        Unidad1(Resto,1,Cantidad,tr("Culombio por voltio"),"Electrica",Valor);
        Unidad(Resto,0.000000001,Cantidad,tr("Abfaradio (abF)"),"Electrica",Valor);
        Unidad1(Resto,0.000000001,Cantidad,tr("Abfaradio (abF)"),"Electrica",Valor);
        Unidad(Resto,898755178736.5,Cantidad,tr("Statfaradio (statF)"),"Electrica",Valor);
        Unidad1(Resto,898755178736.5,Cantidad,tr("Statfaradio (statF)"),"Electrica",Valor);
        ui->label_14->setText(tr("Capacidad electrica: Convertir a...")+ui->comboBox_48->currentText()+"");
        ui->label_15->setText(tr("Capacidad electrica: Convertir de...")+ui->comboBox_48->currentText()+"");
    }
    if (Tipo == "Carga")
    {
        QString Value = ui->comboBox_46->currentText();
        QString Valor = ui->lineEdit_152->text();
        double Cantidad = ui->lineEdit_152->text().toDouble();
        double Resto = Referencia(Value,"Carga");
        Unidad(Resto,1000000000,Cantidad,tr("Nanoculombios (nC)"),"Carga",Valor);
        Unidad1(Resto,1000000000,Cantidad,tr("Nanoculombios (nC)"),"Carga",Valor);
        Unidad(Resto,1000000,Cantidad,tr("Microculombios (µC)"),"Carga",Valor);
        Unidad1(Resto,1000000,Cantidad,tr("Microculombios (µC)"),"Carga",Valor);
        Unidad(Resto,1000,Cantidad,tr("Miliculombios (mC)"),"Carga",Valor);
        Unidad1(Resto,1000,Cantidad,tr("Miliculombios (mC)"),"Carga",Valor);
        Unidad(Resto,1,Cantidad,tr("Culombios (C)"),"Carga",Valor);
        Unidad1(Resto,1,Cantidad,tr("Culombios (C)"),"Carga",Valor);
        Unidad(Resto,0.001,Cantidad,tr("Kiloculombios (kC)"),"Carga",Valor);
        Unidad1(Resto,0.001,Cantidad,tr("Kiloculombios (kC)"),"Carga",Valor);
        Unidad(Resto,0.000001,Cantidad,tr("Megaculombios (MC)"),"Carga",Valor);
        Unidad1(Resto,0.000001,Cantidad,tr("Megaculombios (MC)"),"Carga",Valor);
        Unidad(Resto,0.1,Cantidad,tr("Abculombios (abC)"),"Carga",Valor);
        Unidad1(Resto,0.1,Cantidad,tr("Abculombios (abC)"),"Carga",Valor);
        Unidad(Resto,0.277777777778,Cantidad,tr("Miliamperios-hora (mAh)"),"Carga",Valor);
        Unidad1(Resto,0.277777777778,Cantidad,tr("Miliamperios-hora (mAh)"),"Carga",Valor);
        Unidad(Resto,0.000277777777778,Cantidad,tr("Amperios-hora (Ah)"),"Carga",Valor);
        Unidad1(Resto,0.000277777777778,Cantidad,tr("Amperios-hora (Ah)"),"Carga",Valor);
        Unidad(Resto,0.00001036426864904,Cantidad,tr("Faraday (F)"),"Carga",Valor);
        Unidad1(Resto,0.00001036426864904,Cantidad,tr("Faraday (F)"),"Carga",Valor);
        Unidad(Resto,2997924580.00,Cantidad,tr("Statculombios (statC)"),"Carga",Valor);
        Unidad1(Resto,2997924580.00,Cantidad,tr("Statculombios (statC)"),"Carga",Valor);
        Unidad(Resto,6241509474153816705,Cantidad,tr("Carga Elemental (e)"),"Carga",Valor);
        Unidad1(Resto,6241509474153816705,Cantidad,tr("Carga Elemental (e)"),"Carga",Valor);
        ui->label_14->setText(tr("Carga electrica: Convertir a...")+ui->comboBox_46->currentText()+"");
        ui->label_15->setText(tr("Carga electrica: Convertir de...")+ui->comboBox_46->currentText()+"");
    }
    if (Tipo == "Caudal")
    {
        QString Value = ui->comboBox_44->currentText();
        QString Valor = ui->lineEdit_150->text();
        double Cantidad = ui->lineEdit_150->text().toDouble();
        double Resto = Referencia(Value,"Caudal");
        Unidad(Resto,0.000000001,Cantidad,tr("Kilometros cubicos por segundo (km³/s)"),"Caudal",Valor);
        Unidad1(Resto,0.000000001,Cantidad,tr("Kilometros cubicos por segundo (km³/s)"),"Caudal",Valor);
        Unidad(Resto,1,Cantidad,tr("Metros cubicos por segundo (m³/s)"),"Caudal",Valor);
        Unidad1(Resto,1,Cantidad,tr("Metros cubicos por segundo (m³/s)"),"Caudal",Valor);
        Unidad(Resto,1000,Cantidad,tr("Decimetros cubicos por segundo (dm³/s)"),"Caudal",Valor);
        Unidad1(Resto,1000,Cantidad,tr("Decimetros cubicos por segundo (dm³/s)"),"Caudal",Valor);
        Unidad(Resto,1000000,Cantidad,tr("Centimetros cubicos por segundo (cm³/s)"),"Caudal",Valor);
        Unidad1(Resto,1000000,Cantidad,tr("Centimetros cubicos por segundo (cm³/s)"),"Caudal",Valor);
        Unidad(Resto,1000000000,Cantidad,tr("Milimetros cubicos por segundo (mm³/s)"),"Caudal",Valor);
        Unidad1(Resto,1000000000,Cantidad,tr("Milimetros cubicos por segundo (mm³/s)"),"Caudal",Valor);
        Unidad(Resto,61023.7440947319,Cantidad,tr("Pulgadas cubicas por segundo (in³/s)"),"Caudal",Valor);
        Unidad1(Resto,61023.7440947319,Cantidad,tr("Pulgadas cubicas por segundo (in³/s)"),"Caudal",Valor);
        Unidad(Resto,35.3146667214884,Cantidad,tr("Pies cubicos por segundo (ft³/s)"),"Caudal",Valor);
        Unidad1(Resto,35.3146667214884,Cantidad,tr("Pies cubicos por segundo (ft³/s)"),"Caudal",Valor);
        Unidad(Resto,264.172052358147,Cantidad,tr("Galones por el segundo (Liquido EE.UU.)"),"Caudal",Valor);
        Unidad1(Resto,264.172052358147,Cantidad,tr("Galones por el segundo (Liquido EE.UU.)"),"Caudal",Valor);
        Unidad(Resto,219.969248299088,Cantidad,tr("Galones por segundo (Imperial)"),"Caudal",Valor);
        Unidad1(Resto,219.969248299088,Cantidad,tr("Galones por segundo (Imperial)"),"Caudal",Valor);
        Unidad(Resto,1000,Cantidad,tr("Litros por segundo (l/s)"),"Caudal",Valor);
        Unidad1(Resto,1000,Cantidad,tr("Litros por segundo (l/s)"),"Caudal",Valor);
        Unidad(Resto,0.000000000239912758578926,Cantidad,tr("Millas cubicas por segundo"),"Caudal",Valor);
        Unidad1(Resto,0.000000000239912758578926,Cantidad,tr("Millas cubicas por segundo"),"Caudal",Valor);
        Unidad(Resto,0.000810713193789908,Cantidad,tr("Acre-pies por segundo"),"Caudal",Valor);
        Unidad1(Resto,0.000810713193789908,Cantidad,tr("Acre-pies por segundo"),"Caudal",Valor);
        Unidad(Resto,28.3775932584017,Cantidad,tr("Bushels por segundo (EE.UU,)"),"Caudal",Valor);
        Unidad1(Resto,28.3775932584017,Cantidad,tr("Bushels por segundo (EE.UU,)"),"Caudal",Valor);
        Unidad(Resto,27.496156037386,Cantidad,tr("Bushels por segundo (Imperial)"),"Caudal",Valor);
        Unidad1(Resto,27.496156037386,Cantidad,tr("Bushels por segundo (Imperial)"),"Caudal",Valor);
        Unidad(Resto,0.000000006,Cantidad,tr("Kilometros cubicos por minuto (km³/min)"),"Caudal",Valor);
        Unidad1(Resto,0.000000006,Cantidad,tr("Kilometros cubicos por minuto (km³/min)"),"Caudal",Valor);
        Unidad(Resto,60,Cantidad,tr("Metros cubicos por minuto (m³/min)"),"Caudal",Valor);
        Unidad1(Resto,60,Cantidad,tr("Metros cubicos por minuto (m³/min)"),"Caudal",Valor);
        Unidad(Resto,60000,Cantidad,tr("Decimetros cubicos por minuto (dm³/min)"),"Caudal",Valor);
        Unidad1(Resto,60000,Cantidad,tr("Decimetros cubicos por minuto (dm³/min)"),"Caudal",Valor);
        Unidad(Resto,60000000,Cantidad,tr("Centimetros cubicos por minuto (cm³/min)"),"Caudal",Valor);
        Unidad1(Resto,60000000,Cantidad,tr("Centimetros cubicos por minuto (cm³/min)"),"Caudal",Valor);
        Unidad(Resto,60000000000,Cantidad,tr("Milimetros cubicos por minuto (mm³/min)"),"Caudal",Valor);
        Unidad1(Resto,60000000000,Cantidad,tr("Milimetros cubicos por minuto (mm³/min)"),"Caudal",Valor);
        Unidad(Resto,3661424.64568392,Cantidad,tr("Pulgadas cubicas por minuto (in³/min)"),"Caudal",Valor);
        Unidad1(Resto,3661424.64568392,Cantidad,tr("Pulgadas cubicas por minuto (in³/min)"),"Caudal",Valor);
        Unidad(Resto,2118.8800032893,Cantidad,tr("Pies cubicos por minuto (ft³/min)"),"Caudal",Valor);
        Unidad1(Resto,2118.8800032893,Cantidad,tr("Pies cubicos por minuto (ft³/min)"),"Caudal",Valor);
        Unidad(Resto,15850.3231414888,Cantidad,tr("Galones por el minuto (Liquido EE.UU.)"),"Caudal",Valor);
        Unidad1(Resto,15850.3231414888,Cantidad,tr("Galones por el minuto (Liquido EE.UU.)"),"Caudal",Valor);
        Unidad(Resto,13198.1548979453,Cantidad,tr("Galones por minuto (Imperial)"),"Caudal",Valor);
        Unidad1(Resto,13198.1548979453,Cantidad,tr("Galones por minuto (Imperial)"),"Caudal",Valor);
        Unidad(Resto,60000,Cantidad,tr("Litros por minuto (l/min)"),"Caudal",Valor);
        Unidad1(Resto,60000,Cantidad,tr("Litros por minuto (l/min)"),"Caudal",Valor);
        Unidad(Resto,0.0000000143947655147356,Cantidad,tr("Millas cubicas por minuto"),"Caudal",Valor);
        Unidad1(Resto,0.0000000143947655147356,Cantidad,tr("Millas cubicas por minuto"),"Caudal",Valor);
        Unidad(Resto,0.0486427916273945,Cantidad,tr("Acre-pies por minuto"),"Caudal",Valor);
        Unidad1(Resto,0.0486427916273945,Cantidad,tr("Acre-pies por minuto"),"Caudal",Valor);
        Unidad(Resto,1702.6555955041,Cantidad,tr("Bushels por minuto (EE.UU,)"),"Caudal",Valor);
        Unidad1(Resto,1702.6555955041,Cantidad,tr("Bushels por minuto (EE.UU,)"),"Caudal",Valor);
        Unidad(Resto,1649.76936224316,Cantidad,tr("Bushels por minuto (Imperial)"),"Caudal",Valor);
        Unidad1(Resto,1649.76936224316,Cantidad,tr("Bushels por minuto (Imperial)"),"Caudal",Valor);
        Unidad(Resto,0.0000036,Cantidad,tr("Kilometros cubicos por hora (km³/h)"),"Caudal",Valor);
        Unidad1(Resto,0.0000036,Cantidad,tr("Kilometros cubicos por hora (km³/h)"),"Caudal",Valor);
        Unidad(Resto,3600,Cantidad,tr("Metros cubicos por hora (m³/h)"),"Caudal",Valor);
        Unidad1(Resto,3600,Cantidad,tr("Metros cubicos por hora (m³/h)"),"Caudal",Valor);
        Unidad(Resto,3600000,Cantidad,tr("Decimetros cubicos por hora (dm³/h)"),"Caudal",Valor);
        Unidad1(Resto,3600000,Cantidad,tr("Decimetros cubicos por hora (dm³/h)"),"Caudal",Valor);
        Unidad(Resto,3600000000.00,Cantidad,tr("Centimetros cubicos por hora (cm³/h)"),"Caudal",Valor);
        Unidad1(Resto,3600000000.00,Cantidad,tr("Centimetros cubicos por hora (cm³/h)"),"Caudal",Valor);
        Unidad(Resto,3600000000000,Cantidad,tr("Milimetros cubicos por hora (mm³/h)"),"Caudal",Valor);
        Unidad1(Resto,3600000000000,Cantidad,tr("Milimetros cubicos por hora (mm³/h)"),"Caudal",Valor);
        Unidad(Resto,219685478.741035,Cantidad,tr("Pulgadas cubicas por hora (in³/h)"),"Caudal",Valor);
        Unidad1(Resto,219685478.741035,Cantidad,tr("Pulgadas cubicas por hora (in³/h)"),"Caudal",Valor);
        Unidad(Resto,127132.800197358,Cantidad,tr("Pies cubicos por hora (ft³/h)"),"Caudal",Valor);
        Unidad1(Resto,127132.800197358,Cantidad,tr("Pies cubicos por hora (ft³/h)"),"Caudal",Valor);
        Unidad(Resto,951019.388489329,Cantidad,tr("Galones por el hora (Liquido EE.UU.)"),"Caudal",Valor);
        Unidad1(Resto,951019.388489329,Cantidad,tr("Galones por el hora (Liquido EE.UU.)"),"Caudal",Valor);
        Unidad(Resto,791889.293876716,Cantidad,tr("Galones por hora (Imperial)"),"Caudal",Valor);
        Unidad1(Resto,791889.293876716,Cantidad,tr("Galones por hora (Imperial)"),"Caudal",Valor);
        Unidad(Resto,3600000,Cantidad,tr("Litros por hora (l/h)"),"Caudal",Valor);
        Unidad1(Resto,3600000,Cantidad,tr("Litros por hora (l/h)"),"Caudal",Valor);
        Unidad(Resto,0.000000863685930884134,Cantidad,tr("Millas cubicas por hora"),"Caudal",Valor);
        Unidad1(Resto,0.000000863685930884134,Cantidad,tr("Millas cubicas por hora"),"Caudal",Valor);
        Unidad(Resto,2.91856749764367,Cantidad,tr("Acre-pies por hora"),"Caudal",Valor);
        Unidad1(Resto,2.91856749764367,Cantidad,tr("Acre-pies por hora"),"Caudal",Valor);
        Unidad(Resto,102159.335730246,Cantidad,tr("Bushels por hora (EE.UU,)"),"Caudal",Valor);
        Unidad1(Resto,102159.335730246,Cantidad,tr("Bushels por hora (EE.UU,)"),"Caudal",Valor);
        Unidad(Resto,98986.1617345895,Cantidad,tr("Bushels por hora (Imperial)"),"Caudal",Valor);
        Unidad1(Resto,98986.1617345895,Cantidad,tr("Bushels por hora (Imperial)"),"Caudal",Valor);
        Unidad(Resto,0.0000864,Cantidad,tr("Kilometros cubicos por dia"),"Caudal",Valor);
        Unidad1(Resto,0.0000864,Cantidad,tr("Kilometros cubicos por dia"),"Caudal",Valor);
        Unidad(Resto,86400,Cantidad,tr("Metros cubicos por dia"),"Caudal",Valor);
        Unidad1(Resto,86400,Cantidad,tr("Metros cubicos por dia"),"Caudal",Valor);
        Unidad(Resto,86400000,Cantidad,tr("Decimetros cubicos por dia"),"Caudal",Valor);
        Unidad1(Resto,86400000,Cantidad,tr("Decimetros cubicos por dia"),"Caudal",Valor);
        Unidad(Resto,86400000000,Cantidad,tr("Centimetros cubicos por dia"),"Caudal",Valor);
        Unidad1(Resto,86400000000,Cantidad,tr("Centimetros cubicos por dia"),"Caudal",Valor);
        Unidad(Resto,86400000000000,Cantidad,tr("Milimetros cubicos por dia"),"Caudal",Valor);
        Unidad1(Resto,86400000000000,Cantidad,tr("Milimetros cubicos por dia"),"Caudal",Valor);
        Unidad(Resto,5272451489.78484,Cantidad,tr("Pulgadas cubicas por dia"),"Caudal",Valor);
        Unidad1(Resto,5272451489.78484,Cantidad,tr("Pulgadas cubicas por dia"),"Caudal",Valor);
        Unidad(Resto,3051187.2047366,Cantidad,tr("Pies cubicos por dia"),"Caudal",Valor);
        Unidad1(Resto,3051187.2047366,Cantidad,tr("Pies cubicos por dia"),"Caudal",Valor);
        Unidad(Resto,22824465.3237439,Cantidad,tr("Galones por el dia (Liquido EE.UU.)"),"Caudal",Valor);
        Unidad1(Resto,22824465.3237439,Cantidad,tr("Galones por el dia (Liquido EE.UU.)"),"Caudal",Valor);
        Unidad(Resto,19005343.0530412,Cantidad,tr("Galones por dia (Imperial)"),"Caudal",Valor);
        Unidad1(Resto,19005343.0530412,Cantidad,tr("Galones por dia (Imperial)"),"Caudal",Valor);
        Unidad(Resto,86400000,Cantidad,tr("Litros por dia"),"Caudal",Valor);
        Unidad1(Resto,86400000,Cantidad,tr("Litros por dia"),"Caudal",Valor);
        Unidad(Resto,0.0000207284623412192,Cantidad,tr("Millas cubicas por dia"),"Caudal",Valor);
        Unidad1(Resto,0.0000207284623412192,Cantidad,tr("Millas cubicas por dia"),"Caudal",Valor);
        Unidad(Resto,70.045619943448,Cantidad,tr("Acre-pies por dia"),"Caudal",Valor);
        Unidad1(Resto,70.045619943448,Cantidad,tr("Acre-pies por dia"),"Caudal",Valor);
        Unidad(Resto,2451824.05752591,Cantidad,tr("Bushels por dia (EE.UU,)"),"Caudal",Valor);
        Unidad1(Resto,2451824.05752591,Cantidad,tr("Bushels por dia (EE.UU,)"),"Caudal",Valor);
        Unidad(Resto,2375667.88163015,Cantidad,tr("Bushels por dia (Imperial)"),"Caudal",Valor);
        Unidad1(Resto,2375667.88163015,Cantidad,tr("Bushels por dia (Imperial)"),"Caudal",Valor);
        Unidad(Resto,0.031536,Cantidad,tr("Kilometros cubicos por ano"),"Caudal",Valor);
        Unidad1(Resto,0.031536,Cantidad,tr("Kilometros cubicos por ano"),"Caudal",Valor);
        Unidad(Resto,31536000,Cantidad,tr("Metros cubicos por ano"),"Caudal",Valor);
        Unidad1(Resto,31536000,Cantidad,tr("Metros cubicos por ano"),"Caudal",Valor);
        Unidad(Resto,31536000000,Cantidad,tr("Decimetros cubicos por ano"),"Caudal",Valor);
        Unidad1(Resto,31536000000,Cantidad,tr("Decimetros cubicos por ano"),"Caudal",Valor);
        Unidad(Resto,31536000000000,Cantidad,tr("Centimetros cubicos por ano"),"Caudal",Valor);
        Unidad1(Resto,31536000000000,Cantidad,tr("Centimetros cubicos por ano"),"Caudal",Valor);
        Unidad(Resto,31536000000000000,Cantidad,tr("Milimetros cubicos por ano"),"Caudal",Valor);
        Unidad1(Resto,31536000000000000,Cantidad,tr("Milimetros cubicos por ano"),"Caudal",Valor);
        Unidad(Resto,1924444793771.47,Cantidad,tr("Pulgadas cubicas por ano"),"Caudal",Valor);
        Unidad1(Resto,1924444793771.47,Cantidad,tr("Pulgadas cubicas por ano"),"Caudal",Valor);
        Unidad(Resto,1113683329.72886,Cantidad,tr("Pies cubicos por ano"),"Caudal",Valor);
        Unidad1(Resto,1113683329.72886,Cantidad,tr("Pies cubicos por ano"),"Caudal",Valor);
        Unidad(Resto,8330929843.16652,Cantidad,tr("Galones por el ano (Liquido EE.UU.)"),"Caudal",Valor);
        Unidad1(Resto,8330929843.16652,Cantidad,tr("Galones por el ano (Liquido EE.UU.)"),"Caudal",Valor);
        Unidad(Resto,6936950214.36003,Cantidad,tr("Galones por ano (Imperial)"),"Caudal",Valor);
        Unidad1(Resto,6936950214.36003,Cantidad,tr("Galones por ano (Imperial)"),"Caudal",Valor);
        Unidad(Resto,31536000000,Cantidad,tr("Litros por ano"),"Caudal",Valor);
        Unidad1(Resto,31536000000,Cantidad,tr("Litros por ano"),"Caudal",Valor);
        Unidad(Resto,0.00756588875454502,Cantidad,tr("Millas cubicas por ano"),"Caudal",Valor);
        Unidad1(Resto,0.00756588875454502,Cantidad,tr("Millas cubicas por ano"),"Caudal",Valor);
        Unidad(Resto,25566.6512793585,Cantidad,tr("Acre-pies por ano"),"Caudal",Valor);
        Unidad1(Resto,25566.6512793585,Cantidad,tr("Acre-pies por ano"),"Caudal",Valor);
        Unidad(Resto,894915780.996958,Cantidad,tr("Bushels por ano (EE.UU,)"),"Caudal",Valor);
        Unidad1(Resto,894915780.996958,Cantidad,tr("Bushels por ano (EE.UU,)"),"Caudal",Valor);
        Unidad(Resto,867118776.795004,Cantidad,tr("Bushels por ano (Imperial)"),"Caudal",Valor);
        Unidad1(Resto,867118776.795004,Cantidad,tr("Bushels por ano (Imperial)"),"Caudal",Valor);
        ui->label_14->setText(tr("Caudal volumetrico: Convertir a...")+ui->comboBox_44->currentText()+"");
        ui->label_15->setText(tr("Caudal volumetrico: Convertir de...")+ui->comboBox_44->currentText()+"");
    }
    if (Tipo == "Conductancia")
    {
        QString Value = ui->comboBox_54->currentText();
        QString Valor = ui->lineEdit_160->text();
        double Cantidad = ui->lineEdit_160->text().toDouble();
        double Resto = Referencia(Value,"Conductancia");
        Unidad(Resto,1000000000,Cantidad,tr("Nanosiemens (nS)"),"Conductancia",Valor);
        Unidad1(Resto,1000000000,Cantidad,tr("Nanosiemens (nS)"),"Conductancia",Valor);
        Unidad(Resto,1000000,Cantidad,tr("Microsiemens (µS)"),"Conductancia",Valor);
        Unidad1(Resto,1000000,Cantidad,tr("Microsiemens (µS)"),"Conductancia",Valor);
        Unidad(Resto,1000,Cantidad,tr("Milisiemens (mS)"),"Conductancia",Valor);
        Unidad1(Resto,1000,Cantidad,tr("Milisiemens (mS)"),"Conductancia",Valor);
        Unidad(Resto,1,Cantidad,tr("Siemens (S)"),"Conductancia",Valor);
        Unidad1(Resto,1,Cantidad,tr("Siemens (S)"),"Conductancia",Valor);
        Unidad(Resto,0.001,Cantidad,tr("Kilosiemens (kS)"),"Conductancia",Valor);
        Unidad1(Resto,0.001,Cantidad,tr("Kilosiemens (kS)"),"Conductancia",Valor);
        Unidad(Resto,0.000001,Cantidad,tr("Megasiemens (MS)"),"Conductancia",Valor);
        Unidad1(Resto,0.000001,Cantidad,tr("Megasiemens (MS)"),"Conductancia",Valor);
        Unidad(Resto,0.000000001,Cantidad,tr("Gigasiemens (GS)"),"Conductancia",Valor);
        Unidad1(Resto,0.000000001,Cantidad,tr("Gigasiemens (GS)"),"Conductancia",Valor);
        Unidad(Resto,1,Cantidad,tr("Mho (℧)"),"Conductancia",Valor);
        Unidad1(Resto,1,Cantidad,tr("Mho (℧)"),"Conductancia",Valor);
        Unidad(Resto,1,Cantidad,tr("Amperios por voltios (A/V)"),"Conductancia",Valor);
        Unidad1(Resto,1,Cantidad,tr("Amperios por voltios (A/V)"),"Conductancia",Valor);
        ui->label_14->setText(tr("Conductancia electrica: Convertir a...")+ui->comboBox_54->currentText()+"");
        ui->label_15->setText(tr("Conductancia electrica: Convertir de...")+ui->comboBox_54->currentText()+"");
    }
    if (Tipo == "Combustible")
    {
        QString Value = ui->comboBox_53->currentText();
        QString Valor = ui->lineEdit_159->text();
        double Cantidad = ui->lineEdit_159->text().toDouble();
        double Resto = Referencia(Value,"Combustible");
        Unidad(Resto,0.01,Cantidad,tr("Litros por kilometro (l/km)"),"Combustible",Valor);
        Unidad1(Resto,0.01,Cantidad,tr("Litros por kilometro (l/km)"),"Combustible",Valor);
        Unidad(Resto,0.1,Cantidad,tr("Litros por 10 kilometros (l/10 km)"),"Combustible",Valor);
        Unidad1(Resto,0.1,Cantidad,tr("Litros por 10 kilometros (l/10 km)"),"Combustible",Valor);
        Unidad(Resto,1,Cantidad,tr("Litros por 100 kilometros (l/100 km"),"Combustible",Valor);
        Unidad1(Resto,1,Cantidad,tr("Litros por 100 kilometros (l/100 km"),"Combustible",Valor);
        Unidad(Resto,100,Cantidad,tr("Kilometros por litro (km/l)"),"Combustible",Valor);
        Unidad1(Resto,100,Cantidad,tr("Kilometros por litro (km/l)"),"Combustible",Valor);
        Unidad(Resto,235.2145,Cantidad,tr("Millas por galon Americano (mpg)"),"Combustible",Valor);
        Unidad1(Resto,235.2145,Cantidad,tr("Millas por galon Americano (mpg)"),"Combustible",Valor);
        Unidad(Resto,0.4251438,Cantidad,tr("Galones por 100 millas"),"Combustible",Valor);
        Unidad1(Resto,0.4251438,Cantidad,tr("Galones por 100 millas"),"Combustible",Valor);
        Unidad(Resto,282.4815,Cantidad,tr("Millas por galon Britanico (mpg:1)"),"Combustible",Valor);
        Unidad1(Resto,282.4815,Cantidad,tr("Millas por galon Britanico (mpg:1)"),"Combustible",Valor);
        Unidad(Resto,62.1371192237334,Cantidad,tr("Millas por litro (mpl)"),"Combustible",Valor);
        Unidad1(Resto,62.1371192237334,Cantidad,tr("Millas por litro (mpl)"),"Combustible",Valor);
        Unidad(Resto,0.3540055,Cantidad,tr("Galones por 100 millas"),"Combustible",Valor);
        Unidad1(Resto,0.3540055,Cantidad,tr("Galones por 100 millas"),"Combustible",Valor);
        ui->label_14->setText(tr("Consumo de combustible: Convertir a...")+ui->comboBox_53->currentText()+"");
        ui->label_15->setText(tr("Consumo de combustible: Convertir de...")+ui->comboBox_53->currentText()+"");
    }
}

double ConversorUD::Referencia(QString Value,QString Tipo)
{
    double Valor;
    if (Tipo == "Longitud")
    {
        if (Value == tr("Angstrom (Å)"))
            Valor = 0.0000000001;
        if (Value == tr("Nanometro (nm)"))
            Valor = 0.000000001;
        if (Value == tr("Micrometro (µm)"))
            Valor = 0.000001;
        if (Value == tr("Milimetro (mm)"))
            Valor = 0.001;
        if (Value == tr("Centimetro (cm)"))
            Valor = 0.01;
        if (Value == tr("Decimetro (dm)"))
            Valor = 0.1;
        if (Value == tr("Metro (m)"))
            Valor = 1;
        if (Value == tr("Decametro (dam)"))
            Valor = 10;
        if (Value == tr("Hectometro (hm)"))
            Valor = 100;
        if (Value == tr("Kilometro (km)"))
            Valor = 1000;
        if (Value == tr("Miriametro (mam)"))
            Valor = 10000;
        if (Value == tr("Legua"))
            Valor = 4828.032;
        if (Value == tr("Milla (mi)"))
            Valor = 1609.344;
        if (Value == tr("Estadio"))
            Valor = 201.168;
        if (Value == tr("Cadena"))
            Valor = 20.1168;
        if (Value == tr("Barra (rd)"))
            Valor = 5.0292;
        if (Value == tr("Yarda (yd)"))
            Valor = 0.9144;
        if (Value == tr("Pie (ft)"))
            Valor = 0.3048;
        if (Value == tr("Link"))
            Valor = 0.201168;
        if (Value == tr("Mano"))
            Valor = 0.1016;
        if (Value == tr("Pulgada (in)"))
            Valor = 0.0254;
        if (Value == tr("Linea"))
            Valor = 0.00254;
        if (Value == tr("Mil (mil)"))
            Valor = 0.0000254;
        if (Value == tr("Thou (thou)"))
            Valor = 0.0000254;
        if (Value == tr("Milla nautica"))
            Valor = 1852;
        if (Value == tr("Braza"))
            Valor = 1.8288;
        if (Value == tr("Parsec (pc)"))
            Valor = 30857000000000000;
        if (Value == tr("Ano luz"))
            Valor = 9454254955488000;
        if (Value == tr("Unidad astronomica (AE)"))
            Valor = 147597870610;
        if (Value == tr("Minuto luz"))
            Valor = 17987547480;
        if (Value == tr("Segundo luz"))
            Valor = 299792458;
    }
    if (Tipo == "Aceleracion")
    {
        if (Value == tr("Metros por segundo cuadrado (m/s²)"))
            Valor = 0.01;
        if (Value == tr("Pies por segundo cuadrado (ft/s²)"))
            Valor = 0.0328083333;
        if (Value == tr("Gal"))
            Valor = 1;
        if (Value == tr("Miligal"))
            Valor = 1000;
        if (Value == tr("Gravedad estandar"))
            Valor = 0.0010197162;
        if (Value == tr("Fuerza G (g)"))
            Valor = 0.0010197162;
    }
    if (Tipo == "Almacenamiento")
    {
        if (Value == tr("Bit"))
            Valor = 8;
        if (Value == tr("Nibble"))
            Valor = 2;
        if (Value == tr("Kilobit"))
            Valor = 0.0078125;
        if (Value == tr("Megabit"))
            Valor = 0.0000076294;
        if (Value == tr("Gigabit"))
            Valor = 0.00000000074505805969;
        if (Value == tr("Terabit"))
            Valor = 0.00000000000072759580612;
        if (Value == tr("Petabit"))
            Valor = 0.0000000000000007105427742;
        if (Value == tr("Exabit"))
            Valor = 0.000000000000000000769388942719;
        if (Value == tr("Byte (B)"))
            Valor = 1;
        if (Value == tr("Kilobyte (KB)"))
            Valor = 0.0009765625;
        if (Value == tr("Megabyte (MB)"))
            Valor = 0.000000095367431641;
        if (Value == tr("Gigabyte (GB)"))
            Valor = 0.000000000093132257462;
        if (Value == tr("Terabyte (TB)"))
            Valor = 0.000000000000090949478149;
        if (Value == tr("Petabyte (PB)"))
            Valor = 0.000000000000000088817853928;
        if (Value == tr("Exabyte (EB)"))
            Valor = 0.000000000000000000086736183167;
    }
    if (Tipo == "Ancho banda")
    {
        if (Value == tr("Bit por segundo (bit/s)"))
            Valor = 8000000000;
        if (Value == tr("Kilobit por segundo (kbit/s)"))
            Valor = 8000000;
        if (Value == tr("Megabit por segundo (Mbit/s)"))
            Valor = 8000;
        if (Value == tr("Gigabit por segundo (Gbit/s)"))
            Valor = 8;
        if (Value == tr("Terabit por segundo (Tbit/s)"))
            Valor = 0.008;
        if (Value == tr("Kibibit por segundo (Kibit/s)"))
            Valor = 7812500;
        if (Value == tr("Mebibit por segundo (Mibit/s)"))
            Valor = 0.0000078125;
        if (Value == tr("Gibibit por segundo (Gibit/s"))
            Valor = 7.4505806;
        if (Value == tr("Tebibit por segundo (Tibit/s)"))
            Valor = 0.00727596;
        if (Value == tr("Byte por segundo (B/s)"))
            Valor = 1000000000;
        if (Value == tr("Kilobyte por segundo (kB/s)"))
            Valor = 1000000;
        if (Value == tr("Megabyte por segundo (MB/s)"))
            Valor = 1000;
        if (Value == tr("Gigabyte por segundo (GB/s)"))
            Valor = 1;
        if (Value == tr("Terabyte por segundo (TB/s)"))
            Valor = 0.001;
        if (Value == tr("Kibibyte por segundo (KiB/s)"))
            Valor = 976562.5;
        if (Value == tr("Mebibyte por segundo (MiB/s)"))
            Valor = 953.67431641;
        if (Value == tr("Gibibyte por segundo (GiB/s)"))
            Valor = 0.93132257;
        if (Value == tr("Tebibyte por segundo (TiB/s)"))
            Valor = 0.00090949;
        if (Value == tr("Bit por hora"))
            Valor = 2880000000000;
        if (Value == tr("Kilobit por hora"))
            Valor = 28800000000;
        if (Value == tr("Megabit por hora"))
            Valor = 2880000;
        if (Value == tr("Gigabit por hora"))
            Valor = 28800;
        if (Value == tr("Terabit por hora"))
            Valor = 28.8;
        if (Value == tr("Kibibit por hora"))
            Valor = 28125000000;
        if (Value == tr("Mebibit por hora"))
            Valor = 27465820.3;
        if (Value == tr("Gibibit por hora"))
            Valor = 26822.0901;
        if (Value == tr("Tebibit por hora"))
            Valor = 26.19344741;
        if (Value == tr("Byte por hora"))
            Valor = 3600000000000;
        if (Value == tr("Kilobyte por hora"))
            Valor = 3600000000.00;
        if (Value == tr("Megabyte por hora"))
            Valor = 3600000;
        if (Value == tr("Gigabyte por hora"))
            Valor = 3600;
        if (Value == tr("Terabyte por hora"))
            Valor = 3.6;
        if (Value == tr("Kibibyte por hora"))
            Valor = 3516625000.00;
        if (Value == tr("Mebibyte por hora"))
            Valor = 3433227.54;
        if (Value == tr("Gibibyte por hora"))
            Valor = 3352.76127;
        if (Value == tr("Tebibyte por hora"))
            Valor = 3.27418093;
        if (Value == tr("Bit por dia"))
            Valor = 69120000000000;
        if (Value == tr("Kilobit por dia"))
            Valor = 691200000000;
        if (Value == tr("Megabit por dia"))
            Valor = 691200000;
        if (Value == tr("Gigabit por dia"))
            Valor = 691200;
        if (Value == tr("Terabit por dia"))
            Valor = 691.2;
        if (Value == tr("Kibibit por dia"))
            Valor = 675000000000;
        if (Value == tr("Mebibit por dia"))
            Valor = 659179687.5;
        if (Value == tr("Gibibit por dia"))
            Valor = 643730.164;
        if (Value == tr("Tebibit por dia"))
            Valor = 628.64273787;
        if (Value == tr("Byte por dia"))
            Valor = 8640000000000;
        if (Value == tr("Kilobyte por dia"))
            Valor = 86400000000;
        if (Value == tr("Megabyte por dia"))
            Valor = 86400000;
        if (Value == tr("Gigabyte por dia"))
            Valor = 86400;
        if (Value == tr("Terabyte por dia"))
            Valor = 86.4;
        if (Value == tr("Kibibyte por dia"))
            Valor = 84375000000;
        if (Value == tr("Mebibyte por dia"))
            Valor = 82397460.9;
        if (Value == tr("Gibibyte por dia"))
            Valor = 80466.2704;
        if (Value == tr("Tebibyte por dia"))
            Valor = 78.58034223;
    }
    if (Tipo == "Angulo")
    {
        if (Value == tr("Grado sexagesimal"))
            Valor = 360;
        if (Value == tr("Radian"))
            Valor = 6.2831853072;
        if (Value == tr("Circulo"))
            Valor = 1;
        if (Value == tr("Giro"))
            Valor = 1;
        if (Value == tr("Ciclo"))
            Valor = 1;
        if (Value == tr("Rotacion"))
            Valor = 1;
        if (Value == tr("Revolucion"))
            Valor = 1;
        if (Value == tr("Angulo recto"))
            Valor = 4;
        if (Value == tr("Milesimal (OTAN)"))
            Valor = 6400;
        if (Value == tr("Milesimal (Union Sovietica)"))
            Valor = 6000;
        if (Value == tr("Milesimal (Suecia)"))
            Valor = 6300;
        if (Value == tr("Grado centesimal"))
            Valor = 400;
        if (Value == tr("Gon"))
            Valor = 400;
        if (Value == tr("Punto"))
            Valor = 32;
        if (Value == tr("Angulo horario"))
            Valor = 24;
    }
    if (Tipo == "Area")
    {
        if (Value == tr("Nanometro cuadrado (nm²)"))
            Valor = 100000000000000000000.00;
        if (Value == tr("Micrometro cuadrado (µm²)"))
            Valor = 100000000000000;
        if (Value == tr("Milimetro cuadrado (mm²)"))
            Valor = 100000000;
        if (Value == tr("Centimetro cuadrado (cm²)"))
            Valor = 1000000;
        if (Value == tr("Decimetro cuadrado (dm²)"))
            Valor = 10000;
        if (Value == tr("Metro cuadrado (m²)"))
            Valor = 100;
        if (Value == tr("Area (a)"))
            Valor = 1;
        if (Value == tr("Hectarea (ha)"))
            Valor = 0.01;
        if (Value == tr("Kilometro cuadrado (km²)"))
            Valor = 0.0001;
        if (Value == tr("Municipio"))
            Valor = 0.0000010725;
        if (Value == tr("Milla cuadrada"))
            Valor = 0.0000386102;
        if (Value == tr("Patrimonio familiar"))
            Valor = 0.0001544409;
        if (Value == tr("Acre"))
            Valor = 0.02471055;
        if (Value == tr("Rood"))
            Valor = 0.0988422;
        if (Value == tr("Rod cuadrada"))
            Valor = 3.953687;
        if (Value == tr("Cuadrado"))
            Valor = 10.76391;
        if (Value == tr("Yarda cuadrada (yd²)"))
            Valor = 119.599;
        if (Value == tr("Pie cuadrado (ft²)"))
            Valor = 1076.391;
        if (Value == tr("Pulgada cuadrada (in²)"))
            Valor = 155000.3;
        if (Value == tr("Tsubo"))
            Valor = 30.24999;
        if (Value == tr("Cho"))
            Valor = 10083.33;
        if (Value == tr("Tann"))
            Valor = 100833.3;
        if (Value == tr("Se"))
            Valor = 1008333;
        if (Value == tr("Donum metrico"))
            Valor = 0.1;
        if (Value == tr("Donum de Chipre"))
            Valor = 0.074749375;
        if (Value == tr("Donum iraqui"))
            Valor = 0.04;
        if (Value == tr("Estrema griego"))
            Valor = 0.01;
        if (Value == tr("Campo de futbol"))
            Valor = 0.0140056;
    }
    if (Tipo == "Campo")
    {
        if (Value == tr("Amperio por metro (A/m)"))
            Valor = 0.7957747155;
        if (Value == tr("Amperio-vuelta por metro (AT/m)"))
            Valor = 0.7957747155;
        if (Value == tr("Oersted (Oe)"))
            Valor = 0.01;
        if (Value == tr("Gilbert por metro (Gi/m)"))
            Valor = 1;
    }
    if (Tipo == "Luz")
    {
        if (Value == tr("Talbot (T)"))
            Valor = 3600;
        if (Value == tr("Lumen segundo (lm·s)"))
            Valor = 3600;
        if (Value == tr("Lumen minuto (lm·min)"))
            Valor = 60;
        if (Value == tr("Lumen hora (lm·h)"))
            Valor = 1;
    }
    if (Tipo == "Sustancia")
    {
        if (Value == tr("Milimol (mmol)"))
            Valor = 1000;
        if (Value == tr("Mol (mol)"))
            Valor = 1;
        if (Value == tr("Kilomol (kmol)"))
            Valor = 0.001;
        if (Value == tr("Libra mol (lb-mol)"))
            Valor = 0.0022046226;
    }
    if (Tipo == "Electrica")
    {
        if (Value == tr("Faradio (F)"))
            Valor = 1;
        if (Value == tr("Decafaradio (daF)"))
            Valor = 0.1;
        if (Value == tr("Hectofaradio (hF)"))
            Valor = 0.01;
        if (Value == tr("Kilofaradio (kF)"))
            Valor = 0.001;
        if (Value == tr("Megafaradio (MF)"))
            Valor = 0.000001;
        if (Value == tr("Gigafaradio (GF)"))
            Valor = 0.000000001;
        if (Value == tr("Terafaradio (TF)"))
            Valor = 0.000000000001;
        if (Value == tr("Petafaradio (PF)"))
            Valor = 0.000000000000001;
        if (Value == tr("Exafaradio (EF)"))
            Valor = 0.000000000000000001;
        if (Value == tr("Zettafaradio (ZF)"))
            Valor = 0.000000000000000000001;
        if (Value == tr("Yottafaradio (YF)"))
            Valor = 0.000000000000000000000001;
        if (Value == tr("Decifaradio (dF)"))
            Valor = 10;
        if (Value == tr("Centifaradio (cF)"))
            Valor = 100;
        if (Value == tr("Milifaradio (mF)"))
            Valor = 1000;
        if (Value == tr("Microfaradio (µF)"))
            Valor = 1000000;
        if (Value == tr("Nanofaradio (nF)"))
            Valor = 1000000000;
        if (Value == tr("Picofaradio (pF)"))
            Valor = 1000000000000;
        if (Value == tr("Femtofaradio (fF)"))
            Valor = 1000000000000000;
        if (Value == tr("Attofaradio (aF)"))
            Valor = 1000000000000000000;
        if (Value == tr("Zeptofaradio (zF)"))
            Valor = 1000000000000000000000.00;
        if (Value == tr("Yoctofaradio (yF)"))
            Valor = 1000000000000000000000000.00;
        if (Value == tr("Culombio por voltio"))
            Valor = 1;
        if (Value == tr("Abfaradio (abF)"))
            Valor = 0.000000001;
        if (Value == tr("Statfaradio (statF)"))
            Valor = 898755178736.5;
    }
    if (Tipo == "Carga")
    {
        if (Value == tr("Nanoculombios (nC)"))
            Valor = 1000000000;
        if (Value == tr("Microculombios (µC)"))
            Valor = 1000000;
        if (Value == tr("Miliculombios (mC)"))
            Valor = 1000;
        if (Value == tr("Culombios (C)"))
            Valor = 1;
        if (Value == tr("Kiloculombios (kC)"))
            Valor = 0.001;
        if (Value == tr("Megaculombios (MC)"))
            Valor = 0.000001;
        if (Value == tr("Abculombios (abC)"))
            Valor = 0.1;
        if (Value == tr("Miliamperios-hora (mAh)"))
            Valor = 0.277777777778;
        if (Value == tr("Amperios-hora (Ah)"))
            Valor = 0.000277777777778;
        if (Value == tr("Faraday (F)"))
            Valor = 0.00001036426864904;
        if (Value == tr("Statculombios (statC)"))
            Valor = 2997924580.00;
        if (Value == tr("Carga Elemental (e)"))
            Valor = 6241509474153816705;
    }
    if (Tipo == "Caudal")
    {
        if (Value == tr("Kilometros cubicos por segundo (km³/s)"))
            Valor = 0.000000001;
        if (Value == tr("Metros cubicos por segundo (m³/s)"))
            Valor = 1;
        if (Value == tr("Decimetros cubicos por segundo (dm³/s)"))
            Valor = 1000;
        if (Value == tr("Centimetros cubicos por segundo (cm³/s)"))
            Valor = 1000000;
        if (Value == tr("Milimetros cubicos por segundo (mm³/s)"))
            Valor = 1000000000;
        if (Value == tr("Pulgadas cubicas por segundo (in³/s)"))
            Valor = 61023.7440947319;
        if (Value == tr("Pies cubicos por segundo (ft³/s)"))
            Valor = 35.3146667214884;
        if (Value == tr("Galones por el segundo (Liquido EE.UU.)"))
            Valor = 264.172052358147;
        if (Value == tr("Galones por segundo (Imperial)"))
            Valor = 219.969248299088;
        if (Value == tr("Litros por segundo (l/s)"))
            Valor = 1000;
        if (Value == tr("Millas cubicas por segundo"))
            Valor = 0.000000000239912758578926;
        if (Value == tr("Acre-pies por segundo"))
            Valor = 0.000810713193789908;
        if (Value == tr("Bushels por segundo (EE.UU,)"))
            Valor = 28.3775932584017;
        if (Value == tr("Bushels por segundo (Imperial)"))
            Valor = 27.496156037386;
        if (Value == tr("Kilometros cubicos por minuto (km³/min)"))
            Valor = 0.000000006;
        if (Value == tr("Metros cubicos por minuto (m³/min)"))
            Valor = 60;
        if (Value == tr("Decimetros cubicos por minuto (dm³/min)"))
            Valor = 60000;
        if (Value == tr("Centimetros cubicos por minuto (cm³/min)"))
            Valor = 60000000;
        if (Value == tr("Milimetros cubicos por minuto (mm³/min)"))
            Valor = 60000000000;
        if (Value == tr("Pulgadas cubicas por minuto (in³/min)"))
            Valor = 3661424.64568392;
        if (Value == tr("Pies cubicos por minuto (ft³/min)"))
            Valor = 2118.8800032893;
        if (Value == tr("Galones por el minuto (Liquido EE.UU.)"))
            Valor = 15850.3231414888;
        if (Value == tr("Galones por minuto (Imperial)"))
            Valor = 13198.1548979453;
        if (Value == tr("Litros por minuto (l/min)"))
            Valor = 60000;
        if (Value == tr("Millas cubicas por minuto"))
            Valor = 0.0000000143947655147356;
        if (Value == tr("Acre-pies por minuto"))
            Valor = 0.0486427916273945;
        if (Value == tr("Bushels por minuto (EE.UU,)"))
            Valor = 1702.6555955041;
        if (Value == tr("Bushels por minuto (Imperial)"))
            Valor = 1649.76936224316;
        if (Value == tr("Kilometros cubicos por hora (km³/h)"))
            Valor = 0.0000036;
        if (Value == tr("Metros cubicos por hora (m³/h)"))
            Valor = 3600;
        if (Value == tr("Decimetros cubicos por hora (dm³/h)"))
            Valor = 3600000;
        if (Value == tr("Centimetros cubicos por hora (cm³/h)"))
            Valor = 3600000000.00;
        if (Value == tr("Milimetros cubicos por hora (mm³/h)"))
            Valor = 3600000000000;
        if (Value == tr("Pulgadas cubicas por hora (in³/h)"))
            Valor = 219685478.741035;
        if (Value == tr("Pies cubicos por hora (ft³/h)"))
            Valor = 127132.800197358;
        if (Value == tr("Galones por el hora (Liquido EE.UU.)"))
            Valor = 951019.388489329;
        if (Value == tr("Galones por hora (Imperial)"))
            Valor = 791889.293876716;
        if (Value == tr("Litros por hora (l/h)"))
            Valor = 3600000;
        if (Value == tr("Millas cubicas por hora"))
            Valor = 0.000000863685930884134;
        if (Value == tr("Acre-pies por hora"))
            Valor = 2.91856749764367;
        if (Value == tr("Bushels por hora (EE.UU,)"))
            Valor = 102159.335730246;
        if (Value == tr("Bushels por hora (Imperial)"))
            Valor = 98986.1617345895;
        if (Value == tr("Kilometros cubicos por dia"))
            Valor = 0.0000864;
        if (Value == tr("Metros cubicos por dia"))
            Valor = 86400;
        if (Value == tr("Decimetros cubicos por dia"))
            Valor = 86400000;
        if (Value == tr("Centimetros cubicos por dia"))
            Valor = 86400000000;
        if (Value == tr("Milimetros cubicos por dia"))
            Valor = 86400000000000;
        if (Value == tr("Pulgadas cubicas por dia"))
            Valor = 5272451489.78484;
        if (Value == tr("Pies cubicos por dia"))
            Valor = 3051187.2047366;
        if (Value == tr("Galones por el dia (Liquido EE.UU.)"))
            Valor = 22824465.3237439;
        if (Value == tr("Galones por dia (Imperial)"))
            Valor = 19005343.0530412;
        if (Value == tr("Litros por dia"))
            Valor = 86400000;
        if (Value == tr("Millas cubicas por dia"))
            Valor = 0.0000207284623412192;
        if (Value == tr("Acre-pies por dia"))
            Valor = 70.045619943448;
        if (Value == tr("Bushels por dia (EE.UU,)"))
            Valor = 2451824.05752591;
        if (Value == tr("Bushels por dia (Imperial)"))
            Valor = 2375667.88163015;
        if (Value == tr("Kilometros cubicos por ano"))
            Valor = 0.031536;
        if (Value == tr("Metros cubicos por ano"))
            Valor = 31536000;
        if (Value == tr("Decimetros cubicos por ano"))
            Valor = 31536000000;
        if (Value == tr("Centimetros cubicos por ano"))
            Valor = 31536000000000;
        if (Value == tr("Milimetros cubicos por ano"))
            Valor = 31536000000000000;
        if (Value == tr("Pulgadas cubicas por ano"))
            Valor = 1924444793771.47;
        if (Value == tr("Pies cubicos por ano"))
            Valor = 1113683329.72886;
        if (Value == tr("Galones por el ano (Liquido EE.UU.)"))
            Valor = 8330929843.16652;
        if (Value == tr("Galones por ano (Imperial)"))
            Valor = 6936950214.36003;
        if (Value == tr("Litros por ano"))
            Valor = 31536000000;
        if (Value == tr("Millas cubicas por ano"))
            Valor = 0.00756588875454502;
        if (Value == tr("Acre-pies por ano"))
            Valor = 25566.6512793585;
        if (Value == tr("Bushels por ano (EE.UU,)"))
            Valor = 894915780.996958;
        if (Value == tr("Bushels por ano (Imperial)"))
            Valor = 867118776.795004;
    }
    if (Tipo == "Conductancia")
    {
        if (Value == tr("Nanosiemens (nS)"))
            Valor = 1000000000;
        if (Value == tr("Microsiemens (µS)"))
            Valor = 1000000;
        if (Value == tr("Milisiemens (mS)"))
            Valor = 1000;
        if (Value == tr("Siemens (S)"))
            Valor = 1;
        if (Value == tr("Kilosiemens (kS)"))
            Valor = 0.001;
        if (Value == tr("Megasiemens (MS)"))
            Valor = 0.000001;
        if (Value == tr("Gigasiemens (GS)"))
            Valor = 0.000000001;
        if (Value == tr("Mho (℧)"))
            Valor = 1;
        if (Value == tr("Amperios por voltios (A/V)"))
            Valor = 1;
    }
    if (Tipo == "Combustible")
    {
        if (Value == tr("Litros por kilometro (l/km)"))
            Valor = 0.01;
        if (Value == tr("Litros por 10 kilometros (l/10 km)"))
            Valor = 0.1;
        if (Value == tr("Litros por 100 kilometros (l/100 km)"))
            Valor = 1;
        if (Value == tr("Kilometros por litro (km/l)"))
            Valor = 100;
        if (Value == tr("Millas por galon Americano (mpg)"))
            Valor = 235.2145;
        if (Value == tr("Galones por 100 millas"))
            Valor = 0.4251438;
        if (Value == tr("Millas por galon Britanico (mpg:1)"))
            Valor = 282.4815;
        if (Value == tr("Millas por litro (mpl)"))
            Valor = 62.1371192237334;
        if (Value == tr("Galones por 100 millas"))
            Valor = 0.3540055;
    }
    return Valor;
}

void ConversorUD::Unidad(double Value, double Value1, double Cantidad, QString Nombre, QString Base, QString Compara)
{
    QStringList decimal = Compara.split(".");
    QString CantDecPos = decimal.value(1);
    int CantDec = CantDecPos.count();
    if (CantDec == 0)
        CantDec = 2;
    if (Base == "Longitud")
    {
        if (ui->lineEdit->text() != "")
        {
            QString Zero;
            if (ui->comboBox->currentText() == Nombre)
            {
                double ValorF = Cantidad;
                Zero = QString("%L1").arg(ValorF,0,'f',Decimales);
//                if (Zero.right(1) == "0")
//                    Zero = Zero.remove(QRegExp("0+$"));
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
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
//                if (Zero.right(1) == "0")
//                    Zero = Zero.remove(QRegExp("0+$"));
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
    if (Base == "Aceleracion")
    {
        if (ui->lineEdit_47->text() != "")
        {
            QString Zero;
            if (ui->comboBox_26->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_26->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_26->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Almacenamiento")
    {
        if (ui->lineEdit_40->text() != "")
        {
            QString Zero;
            if (ui->comboBox_19->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_19->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_19->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Ancho banda")
    {
        if (ui->lineEdit_45->text() != "")
        {
            QString Zero;
            if (ui->comboBox_24->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_24->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_24->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Angulo")
    {
        if (ui->lineEdit_42->text() != "")
        {
            QString Zero;
            if (ui->comboBox_21->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_21->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_21->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Area")
    {
        if (ui->lineEdit_4->text() != "")
        {
            QString Zero;
            if (ui->comboBox_4->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_4->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_4->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Campo")
    {
        if (ui->lineEdit_39->text() != "")
        {
            QString Zero;
            if (ui->comboBox_18->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_18->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_18->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Luz")
    {
        if (ui->lineEdit_37->text() != "")
        {
            QString Zero;
            if (ui->comboBox_17->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_17->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_17->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Sustancia")
    {
        if (ui->lineEdit_156->text() != "")
        {
            QString Zero;
            if (ui->comboBox_50->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_50->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_50->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Electrica")
    {
        if (ui->lineEdit_154->text() != "")
        {
            QString Zero;
            if (ui->comboBox_48->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_48->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_48->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Carga")
    {
        if (ui->lineEdit_152->text() != "")
        {
            QString Zero;
            if (ui->comboBox_46->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_46->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_46->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Caudal")
    {
        if (ui->lineEdit_150->text() != "")
        {
            QString Zero;
            if (ui->comboBox_44->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_44->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_44->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Conductancia")
    {
        if (ui->lineEdit_160->text() != "")
        {
            QString Zero;
            if (ui->comboBox_54->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_54->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_54->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Combustible")
    {
        if (ui->lineEdit_159->text() != "")
        {
            QString Zero;
            if (ui->comboBox_53->currentText() == Nombre)
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
                ui->textEdit->append(""+Zero+" "+ui->comboBox_53->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit->append(""+Valor+" "+ui->comboBox_53->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
}
void ConversorUD::Unidad1(double Value, double Value1, double Cantidad, QString Nombre, QString Base, QString Compara)
{
    QStringList decimal = Compara.split(".");
    QString CantDecPos = decimal.value(1);
    int CantDec = CantDecPos.count();
    if (Base == "Longitud")
    {
        //ver porque falla esta parte

        if (ui->lineEdit->text() != "")
        {
            QString Zero;
            if (ui->comboBox->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value1/Value)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
    if (Base == "Aceleracion")
    {
        if (ui->lineEdit_47->text() != "")
        {
            QString Zero;
            if (ui->comboBox_26->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_26->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_26->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Almacenamiento")
    {
        if (ui->lineEdit_40->text() != "")
        {
            QString Zero;
            if (ui->comboBox_19->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_19->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_19->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Ancho banda")
    {
        if (ui->lineEdit_45->text() != "")
        {
            QString Zero;
            if (ui->comboBox_24->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_24->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_24->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Angulo")
    {
        if (ui->lineEdit_42->text() != "")
        {
            QString Zero;
            if (ui->comboBox_21->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_21->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_21->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Area")
    {
        if (ui->lineEdit_4->text() != "")
        {
            QString Zero;
            if (ui->comboBox_4->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_4->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_4->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Campo")
    {
        if (ui->lineEdit_39->text() != "")
        {
            QString Zero;
            if (ui->comboBox_18->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_18->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_18->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Luz")
    {
        if (ui->lineEdit_37->text() != "")
        {
            QString Zero;
            if (ui->comboBox_17->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_17->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_17->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Sustancia")
    {
        if (ui->lineEdit_156->text() != "")
        {
            QString Zero;
            if (ui->comboBox_50->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_50->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_50->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Electrica")
    {
        if (ui->lineEdit_154->text() != "")
        {
            QString Zero;
            if (ui->comboBox_48->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_48->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_48->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Carga")
    {
        if (ui->lineEdit_152->text() != "")
        {
            QString Zero;
            if (ui->comboBox_46->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_46->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_46->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Caudal")
    {
        if (ui->lineEdit_150->text() != "")
        {
            QString Zero;
            if (ui->comboBox_44->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_44->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_44->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Conductancia")
    {
        if (ui->lineEdit_160->text() != "")
        {
            QString Zero;
            if (ui->comboBox_54->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_54->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_54->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
    if (Base == "Combustible")
    {
        if (ui->lineEdit_159->text() != "")
        {
            QString Zero;
            if (ui->comboBox_53->currentText() == Nombre)
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_53->currentText()+tr(" son ")+Zero+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
            else
            {
                double ValorF = (Value/Value1)*Cantidad;
                QString Valor = QString("%L1").arg(Cantidad,0,'f',CantDec);
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
                ui->textEdit_2->append(""+Zero+" "+ui->comboBox_53->currentText()+tr(" son ")+Valor+" "+Nombre+"");
                if (Log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit_2->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
            }
        }
    }
}

void ConversorUD::on_pushButton_34_clicked()
{
    ui->lineEdit_160->setText("");
    ui->lineEdit_160->setFocus();
    ui->lineEdit_161->setText("");
    ui->lineEdit_161->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_lineEdit_160_returnPressed()
{
    ui->lineEdit_160->setFocus();
    ui->lineEdit_160->selectAll();
}

void ConversorUD::on_lineEdit_160_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_160->text() == "")
            {
                ui->lineEdit_161->setText("");
                ui->lineEdit_161->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_54->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Conductancia");
                QString Valor1 = ui->comboBox_55->currentText();
                double Resto1 = Referencia(Valor1,"Conductancia");
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
                    ui->lineEdit_161->setText(Zero);
                    ui->lineEdit_161->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_161->setText(Zero);
                    ui->lineEdit_161->setToolTip(Zero);
                }
            }
            Reprobar("Conductancia");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_160->setFocus();
            QString Resto = ui->lineEdit_160->text();
            Resto.chop(1);
            ui->lineEdit_160->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_54_activated(const QString &arg1)
{
    if (ui->lineEdit_160->text() == "")
    {
        ui->lineEdit_161->setText("");
        ui->lineEdit_161->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_160->text().toFloat();
        double Resto = Referencia(Valor,"Conductancia");
        QString Valor1 = ui->comboBox_55->currentText();
        double Resto1 = Referencia(Valor1,"Conductancia");
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
            ui->lineEdit_161->setText(Zero);
            ui->lineEdit_161->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_161->setText(Zero);
            ui->lineEdit_161->setToolTip(Zero);
        }
    }
    Reprobar("Conductancia");
}

void ConversorUD::on_comboBox_55_activated(const QString &arg1)
{
    if (ui->lineEdit_160->text() == "")
    {
        ui->lineEdit_161->setText("");
        ui->lineEdit_161->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_54->currentText();
        double Cantidad = ui->lineEdit_160->text().toFloat();
        double Resto = Referencia(Valor,"Conductancia");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Conductancia");
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
            ui->lineEdit_161->setText(Zero);
            ui->lineEdit_161->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_161->setText(Zero);
            ui->lineEdit_161->setToolTip(Zero);
        }
    }
    Reprobar("Conductancia");
}

void ConversorUD::on_pushButton_33_clicked()
{
    ui->lineEdit_159->setText("");
    ui->lineEdit_159->setFocus();
    ui->lineEdit_158->setText("");
    ui->lineEdit_158->setToolTip("");
    ui->label_14->setText("");
    ui->label_15->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
}

void ConversorUD::on_lineEdit_159_returnPressed()
{
    ui->lineEdit_159->setFocus();
    ui->lineEdit_159->selectAll();
}

void ConversorUD::on_lineEdit_159_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = VerNum(arg1,1);
        if (Valor == "No")
            {
            if (ui->lineEdit_159->text() == "")
            {
                ui->lineEdit_158->setText("");
                ui->lineEdit_158->setToolTip("");
            }
            else
            {
                QString Valor = ui->comboBox_53->currentText();
                double Cantidad = arg1.toDouble();
                double Resto = Referencia(Valor,"Combustible");
                QString Valor1 = ui->comboBox_56->currentText();
                double Resto1 = Referencia(Valor1,"Combustible");
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
                    ui->lineEdit_158->setText(Zero);
                    ui->lineEdit_158->setToolTip(Zero);
                }
                else
                {
                    double ValorF = (Resto1/Resto)*Cantidad;
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
                    ui->lineEdit_158->setText(Zero);
                    ui->lineEdit_158->setToolTip(Zero);
                }
            }
            Reprobar("Combustible");
        }
        else
        {
            QMessageBox m;
            m.setWindowTitle(tr("Advertencia!!!"));
            m.setText(tr("Has introducido un caracter no valido."));
            m.exec();
            ui->lineEdit_159->setFocus();
            QString Resto = ui->lineEdit_159->text();
            Resto.chop(1);
            ui->lineEdit_159->setText(Resto);
            return;
        }
    }
}

void ConversorUD::on_comboBox_53_activated(const QString &arg1)
{
    if (ui->lineEdit_159->text() == "")
    {
        ui->lineEdit_158->setText("");
        ui->lineEdit_158->setToolTip("");
    }
    else
    {
        QString Valor = arg1;
        double Cantidad = ui->lineEdit_159->text().toFloat();
        double Resto = Referencia(Valor,"Combustible");
        QString Valor1 = ui->comboBox_56->currentText();
        double Resto1 = Referencia(Valor1,"Combustible");
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
            ui->lineEdit_158->setText(Zero);
            ui->lineEdit_158->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_158->setText(Zero);
            ui->lineEdit_158->setToolTip(Zero);
        }
    }
    Reprobar("Combustible");
}

void ConversorUD::on_comboBox_56_activated(const QString &arg1)
{
    if (ui->lineEdit_159->text() == "")
    {
        ui->lineEdit_158->setText("");
        ui->lineEdit_158->setToolTip("");
    }
    else
    {
        QString Valor = ui->comboBox_53->currentText();
        double Cantidad = ui->lineEdit_159->text().toFloat();
        double Resto = Referencia(Valor,"Combustible");
        QString Valor1 = arg1;
        double Resto1 = Referencia(Valor1,"Combustible");
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
            ui->lineEdit_158->setText(Zero);
            ui->lineEdit_158->setToolTip(Zero);
        }
        else
        {
            double ValorF = (Resto1/Resto)*Cantidad;
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
            ui->lineEdit_158->setText(Zero);
            ui->lineEdit_158->setToolTip(Zero);
        }
    }
    Reprobar("Combustible");
}

QString ConversorUD::getDivisa()
{
    QProcess *procesoFree;
    QStringList argumentosFree;
    QByteArray ip;
    procesoFree=new QProcess(this);
    argumentosFree << "http://www.convertworld.com/es/moneda/";
    procesoFree->start("curl", argumentosFree);
    if (! procesoFree->waitForStarted())
        return QString("");
    procesoFree->waitForFinished();
    ip = procesoFree->readAllStandardOutput();
    delete procesoFree;
    QString res = QString(ip);
    res.chop(0);
    return res;
}

void ConversorUD::Divisa()
{
    QString Comprobar;
    QStringList Resto;
    QString Valor = getDivisa();
    QStringList Depurar = Valor.split("\n");
    for (int a=0;a<Depurar.count();a++)
    {
        Comprobar = Depurar.value(a);
        if (Comprobar.contains("<option value="))
        {
            Resto << Comprobar;
        }
    }
    qDebug() << Resto;

    // falta esta parte para las monedas
}
