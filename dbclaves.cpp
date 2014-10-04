#include "dbclaves.h"
#include "ui_dbclaves.h"
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCloseEvent>
#include <QMessageBox>
#include <QDebug>
#include <drakesistema.h>
#include <QFileDialog>
#include <QProgressDialog>
#include <QPainter>
#include <QDateTime>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPrintDialog>
#include <QtConcurrentRun>
#include "Report/savetobdfrm.h"

dbclaves::dbclaves(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbclaves)
{
    ui->setupUi(this);
    drakeSistema drake;
    user = drake.getUser();
    import=0;
    db=QSqlDatabase::database("PRINCIPAL");
    Model= new QSqlTableModel(0,db);
    Model->setTable("Clave");
    Model->select();    
    Model->setHeaderData(1,Qt::Horizontal,tr("Descripcion"));
    Model->setHeaderData(3,Qt::Horizontal,tr("Clave"));
    ui->tableView->setModel(Model);
    ui->tableView->setColumnHidden(8, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setColumnHidden(5, true);
    ui->tableView->setColumnHidden(6, true);
    Stilo = "B";
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila(QModelIndex)));
    connect(ui->checkBox_22,SIGNAL(clicked()),this,SLOT(orden()));
    connect(ui->lineEdit_8,SIGNAL(textChanged(QString)),this,SLOT(orden()));
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
    ui->radioButton_5->setChecked(true);
    connect(ui->radioButton_5,SIGNAL(clicked()),this,SLOT(Cambiar()));
    connect(ui->radioButton_6,SIGNAL(clicked()),this,SLOT(Cambiar()));
    this->Cambiar();
    ui->radioButton_2->setChecked(true);
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Comprobar()));
    this->Comprobar();
    if ( ui->comboBox_2->currentText() == tr("Web"))
    {
        if (ui->lineEdit_6->text().contains("www"))
            ui->pushButton_10->setVisible(true);
        else
            ui->pushButton_10->setVisible(false);
    }
    else
    {
        ui->pushButton_10->setVisible(false);
    }
    this->installEventFilter(this);
    CierreTotal = 0;
    Bloqueo = 0;
    this->on_pushButton_6_clicked();
}

dbclaves::~dbclaves()
{
    delete ui;
    delete Model;
    if (import != 0)
        delete import;
}

void dbclaves::on_pushButton_4_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void dbclaves::Valor(QString valor, QString Usuario)
{
    IDUser = Usuario;
    Model->setFilter("UserRD like'"+IDUser+"'");
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
}

void dbclaves::cambiaFila(QModelIndex actual)
{    
    Bloqueo = 1;
    ui->lineEdit_9->setText("");
    ui->lineEdit_10->setText("");
    ui->lineEdit_9->setToolTip("");
    ui->lineEdit_10->setToolTip("");
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    int i;
    i=actual.row();
    QModelIndex index;
    index=ui->tableView->model()->index(i,0);
    ui->lineEdit_7->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,1);
    ui->lineEdit_6->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,2);
    ui->lineEdit_9->setText(tr(index.data().toString()));
    ui->lineEdit_9->setToolTip(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,3);
    ui->lineEdit_10->setText(tr(index.data().toString()));
    ui->lineEdit_10->setToolTip(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,4);
    ui->lineEdit_3->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,5);
    ui->lineEdit_4->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,6);
    ui->lineEdit_5->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,7);
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(tr(index.data().toString())));
    if (ui->lineEdit_5->text() != "0")
        ui->radioButton_4->setChecked(true);
    else if (ui->lineEdit_4->text() != "0")
        ui->radioButton_3->setChecked(true);
    else if (ui->lineEdit_3->text() != "0")
        ui->radioButton_2->setChecked(true);
    else
        ui->radioButton->setEnabled(true);
    this->fila=i;
    this->Desencriptar();
    Bloqueo = 0;
}

void dbclaves::closeEvent ( QCloseEvent * event )
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

void dbclaves::changeEvent(QEvent *e)
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

bool dbclaves::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
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
        if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("DB de claves"));
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void dbclaves::Comprobar()
{
    if (ui->radioButton->isChecked())
    {
        ui->lineEdit_3->setText("0");
        ui->lineEdit_4->setText("0");
        ui->lineEdit_5->setText("0");
    }
    if (ui->radioButton_2->isChecked())
    {
        QString User;
        User = ui->lineEdit->text();
        if (User.count() > 0)
            ui->lineEdit_3->setText(QString::number(User.count()));
        else
            ui->lineEdit_3->setText("1");
        ui->lineEdit_4->setText("0");
        ui->lineEdit_5->setText("0");
    }
    if (ui->radioButton_3->isChecked())
    {
        QString User,Pass;
        User = ui->lineEdit->text();
        if (User.count() > 0)
            ui->lineEdit_3->setText(QString::number(User.count()));
        else
            ui->lineEdit_3->setText("1");
        Pass = ui->lineEdit_2->text();
        int Total = User.count() + Pass.count();
        if (Total > 0)
            ui->lineEdit_4->setText(QString::number(Total));
        else
            ui->lineEdit_4->setText("1");
        ui->lineEdit_5->setText("0");
    }
    if (ui->radioButton_4->isChecked())
    {
        QString User,Pass;
        User = ui->lineEdit->text();
        if (User.count() > 0)
            ui->lineEdit_3->setText(QString::number(User.count()));
        else
            ui->lineEdit_3->setText("1");
        Pass = ui->lineEdit_2->text();
        int Total = User.count() + Pass.count();
        if (Total > 0)
            ui->lineEdit_4->setText(QString::number(Total));
        else
            ui->lineEdit_4->setText("1");
        this->ramdomize();
    }
    this->Encriptar();
}

void dbclaves::on_comboBox_2_activated(const QString &arg1)
{
    if (arg1 == tr("Web"))
    {
        if (ui->lineEdit_6->text().contains("www"))
            ui->pushButton_10->setVisible(true);
    }
    else
        ui->pushButton_10->setVisible(false);
}

void dbclaves::ramdomize()
{
    int total;
    total = randInt(11,99);
    ui->lineEdit_5->setText(QString::number(total));
}

int dbclaves::randInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

void dbclaves::on_lineEdit_textChanged(const QString &arg1)
{
    if (Bloqueo == 0)
    {
        if (ui->radioButton_2->isChecked())
        {
          ui->lineEdit_3->setText(QString::number(arg1.count()));
        }
        if (ui->radioButton_3->isChecked())
        {
            ui->lineEdit_3->setText(QString::number(arg1.count()));
            QString Clave;
            Clave = ui->lineEdit_2->text();
            int Total = arg1.count() + Clave.count();
            if (Total > 0)
                ui->lineEdit_4->setText(QString::number(Total));
            else
                ui->lineEdit_4->setText("1");
        }
        if (ui->radioButton_4->isChecked())
        {
            ui->lineEdit_3->setText(QString::number(arg1.count()));
            QString Clave;
            Clave = ui->lineEdit_2->text();
            int Total = arg1.count() + Clave.count();
            if (Total > 0)
                ui->lineEdit_4->setText(QString::number(Total));
            else
                ui->lineEdit_4->setText("1");
        }
        this->Encriptar();
    }
}

void dbclaves::on_lineEdit_2_textChanged(const QString &arg1)
{
    if (Bloqueo == 0)
    {
        if (ui->radioButton_3->isChecked())
        {
            QString User;
            User = ui->lineEdit->text();
            if (User.count() > 0)
                ui->lineEdit_3->setText(QString::number(User.count()));
            else
                ui->lineEdit_3->setText("1");
            int Total = User.count() + arg1.count();
            if (Total > 0)
                ui->lineEdit_4->setText(QString::number(Total));
            else
                ui->lineEdit_4->setText("1");
        }
        if (ui->radioButton_4->isChecked())
        {
            QString User;
            User = ui->lineEdit->text();
            if (User.count() > 0)
                ui->lineEdit_3->setText(QString::number(User.count()));
            else
                ui->lineEdit_3->setText("1");
            int Total = User.count() + arg1.count();
            if (Total > 0)
                ui->lineEdit_4->setText(QString::number(Total));
            else
                ui->lineEdit_4->setText("1");
        }
        this->Encriptar();
    }
}

void dbclaves::on_lineEdit_6_textChanged(const QString &arg1)
{
    if (arg1.contains("www"))
    {
        if (ui->comboBox_2->currentText() == "Web")
        {
            ui->pushButton_10->setVisible(true);
        }
        else
            ui->pushButton_10->setVisible(false);
    }
    else
        ui->pushButton_10->setVisible(false);
}

void dbclaves::on_pushButton_6_clicked()
{    
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("0");
    ui->lineEdit_4->setText("0");
    ui->lineEdit_5->setText("0");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_9->setText("");
    ui->lineEdit_10->setText("");
    ui->lineEdit_9->setToolTip("");
    ui->lineEdit_10->setToolTip("");
    ui->comboBox_2->setCurrentText("Web");
    ui->radioButton_2->setEnabled(true);
    ui->lineEdit->setFocus();
    Bloqueo = 0;
}

void dbclaves::Encriptar()
{
    int PosseU, PosseP;
    PosseU = ui->lineEdit->text().count();
    PosseP = ui->lineEdit_2->text().count();
    if (PosseU > 0 || PosseP > 0)
    {
        ui->lineEdit_9->setText("");
        ui->lineEdit_10->setText("");
        ui->lineEdit_9->setToolTip("");
        ui->lineEdit_10->setToolTip("");
        QString ValorAppendUser = "";
        QString ValorAppendPass = "";
        if (!ui->radioButton->isChecked())
        {
            QString UserParc = ui->lineEdit->text();
            QStringList User = UserParc.split("");
            QString PassParc = ui->lineEdit_2->text();
            QStringList Pass = PassParc.split("");
            if (ui->radioButton_2->isChecked())
            {
                for (int a=1;a<User.count()-1;a++)
                {
                    QString Posicion;
                    int Final, Dato, DatUser;
                    Posicion = User.value(a);
                    QSqlQuery query(db);
                    query.exec("SELECT Decimal FROM Ascii WHERE Unicode='"+Posicion+"'");
                    query.first();
                    Final = query.value(0).toInt();
                    Dato = ui->lineEdit_3->text().toInt()+a+1;
                    DatUser = Final * Dato;
                    if (a != User.count()-2)
                        ValorAppendUser = ValorAppendUser.append(QString::number(DatUser)+"-");
                    else
                        ValorAppendUser = ValorAppendUser.append(QString::number(DatUser));
                    ui->lineEdit_9->setText(ValorAppendUser);
                    ui->lineEdit_9->setToolTip(ValorAppendUser);
                }
                for (int a=1;a<Pass.count()-1;a++)
                {
                    QString Posicion;
                    int Final, Dato, DatUser;
                    Posicion = Pass.value(a);
                    QSqlQuery query(db);
                    query.exec("SELECT Decimal FROM Ascii WHERE Unicode='"+Posicion+"'");
                    query.first();
                    Final = query.value(0).toInt();
                    Dato = ui->lineEdit_3->text().toInt()+a+2;
                    DatUser = Final * Dato;
                    if (a != Pass.count()-2)
                        ValorAppendPass = ValorAppendPass.append(QString::number(DatUser)+"-");
                    else
                        ValorAppendPass = ValorAppendPass.append(QString::number(DatUser));
                    ui->lineEdit_10->setText(ValorAppendPass);
                    ui->lineEdit_10->setToolTip(ValorAppendUser);
                }
            }
            if (ui->radioButton_3->isChecked())
            {
                for (int a=1;a<User.count()-1;a++)
                {
                    QString Posicion;
                    int Final, Dato, DatUser;
                    Posicion = User.value(a);
                    QSqlQuery query(db);
                    query.exec("SELECT Decimal FROM Ascii WHERE Unicode='"+Posicion+"'");
                    query.first();
                    Final = query.value(0).toInt();
                    Dato = ui->lineEdit_3->text().toInt()+ui->lineEdit_4->text().toInt()+a+1;
                    DatUser = Final * Dato;
                    if (a != User.count()-2)
                        ValorAppendUser = ValorAppendUser.append(QString::number(DatUser)+"-");
                    else
                        ValorAppendUser = ValorAppendUser.append(QString::number(DatUser));
                    ui->lineEdit_9->setText(ValorAppendUser);
                    ui->lineEdit_9->setToolTip(ValorAppendUser);
                }
                for (int a=1;a<Pass.count()-1;a++)
                {
                    QString Posicion;
                    int Final, Dato, DatUser;
                    Posicion = Pass.value(a);
                    QSqlQuery query(db);
                    query.exec("SELECT Decimal FROM Ascii WHERE Unicode='"+Posicion+"'");
                    query.first();
                    Final = query.value(0).toInt();
                    Dato = ui->lineEdit_3->text().toInt()+ui->lineEdit_4->text().toInt()+a+2;
                    DatUser = Final * Dato;
                    if (a != Pass.count()-2)
                        ValorAppendPass = ValorAppendPass.append(QString::number(DatUser)+"-");
                    else
                        ValorAppendPass = ValorAppendPass.append(QString::number(DatUser));
                    ui->lineEdit_10->setText(ValorAppendPass);
                    ui->lineEdit_10->setToolTip(ValorAppendUser);
                }
            }
            if (ui->radioButton_4->isChecked())
            {
                for (int a=1;a<User.count()-1;a++)
                {
                    QString Posicion;
                    int Final, Dato, DatUser;
                    Posicion = User.value(a);
                    QSqlQuery query(db);
                    query.exec("SELECT Decimal FROM Ascii WHERE Unicode='"+Posicion+"'");
                    query.first();
                    Final = query.value(0).toInt();
                    Dato = ui->lineEdit_3->text().toInt()+ui->lineEdit_4->text().toInt()+ui->lineEdit_5->text().toInt()+a+1;
                    DatUser = Final * Dato;
                    if (a != User.count()-2)
                        ValorAppendUser = ValorAppendUser.append(QString::number(DatUser)+"-");
                    else
                        ValorAppendUser = ValorAppendUser.append(QString::number(DatUser));
                    ui->lineEdit_9->setText(ValorAppendUser);
                    ui->lineEdit_9->setToolTip(ValorAppendUser);
                }
                for (int a=1;a<Pass.count()-1;a++)
                {
                    QString Posicion;
                    int Final, Dato, DatUser;
                    Posicion = Pass.value(a);
                    QSqlQuery query(db);
                    query.exec("SELECT Decimal FROM Ascii WHERE Unicode='"+Posicion+"'");
                    query.first();
                    Final = query.value(0).toInt();
                    Dato = ui->lineEdit_3->text().toInt()+ui->lineEdit_4->text().toInt()+ui->lineEdit_5->text().toInt()+a+2;
                    DatUser = Final * Dato;
                    if (a != Pass.count()-2)
                        ValorAppendPass = ValorAppendPass.append(QString::number(DatUser)+"-");
                    else
                        ValorAppendPass = ValorAppendPass.append(QString::number(DatUser));
                    ui->lineEdit_10->setText(ValorAppendPass);
                    ui->lineEdit_10->setToolTip(ValorAppendUser);
                }
            }
        }
        else
        {
            ui->lineEdit_9->setText(ui->lineEdit->text());
            ui->lineEdit_10->setText(ui->lineEdit_2->text());
            ui->lineEdit_9->setToolTip(ui->lineEdit->text());
            ui->lineEdit_10->setToolTip(ui->lineEdit_2->text());
        }
    }
}

void dbclaves::Desencriptar()
{
    int PosseU, PosseP;
    PosseU = ui->lineEdit_9->text().count();
    PosseP = ui->lineEdit_10->text().count();
    if (PosseU > 0 || PosseP > 0)
    {
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        QString ValorAppendUser = "";
        QString ValorAppendPass = "";
        if (!ui->radioButton->isChecked())
        {
            QString UserParc = ui->lineEdit_9->text();
            QStringList User = UserParc.split("-");
            QString PassParc = ui->lineEdit_10->text();
            QStringList Pass = PassParc.split("-");
            if (ui->radioButton_2->isChecked())
            {
                for (int a=0;a<User.count();a++)
                {
                    int Posicion, Dato, DatUser;
                    QString Final;
                    Posicion = User.value(a).toInt();
                    Dato = ui->lineEdit_3->text().toInt()+(a+1)+1;
                    DatUser = Posicion / Dato;
                    QSqlQuery query(db);
                    query.exec("SELECT Unicode FROM Ascii WHERE Decimal='"+QString::number(DatUser)+"'");
                    query.first();
                    Final = query.value(0).toString();
                    ValorAppendUser = ValorAppendUser.append(Final);
                    ui->lineEdit->setText(ValorAppendUser);
                }
                for (int a=0;a<Pass.count();a++)
                {
                    int Posicion, Dato, DatUser;
                    QString Final;
                    Posicion = Pass.value(a).toInt();
                    Dato = ui->lineEdit_3->text().toInt()+(a+1)+2;
                    DatUser = Posicion / Dato;
                    QSqlQuery query(db);
                    query.exec("SELECT Unicode FROM Ascii WHERE Decimal='"+QString::number(DatUser)+"'");
                    query.first();
                    Final = query.value(0).toString();
                    ValorAppendPass = ValorAppendPass.append(Final);
                    ui->lineEdit_2->setText(ValorAppendPass);
                }
            }
            if (ui->radioButton_3->isChecked())
            {
                for (int a=0;a<User.count();a++)
                {
                    int Posicion, Dato, DatUser;
                    QString Final;
                    Posicion = User.value(a).toInt();
                    Dato = ui->lineEdit_3->text().toInt()+ui->lineEdit_4->text().toInt()+(a+1)+1;
                    DatUser = Posicion / Dato;
                    QSqlQuery query(db);
                    query.exec("SELECT Unicode FROM Ascii WHERE Decimal='"+QString::number(DatUser)+"'");
                    query.first();
                    Final = query.value(0).toString();
                    ValorAppendUser = ValorAppendUser.append(Final);
                    ui->lineEdit->setText(ValorAppendUser);
                }
                for (int a=0;a<Pass.count();a++)
                {
                    int Posicion, Dato, DatUser;
                    QString Final;
                    Posicion = Pass.value(a).toInt();
                    Dato = ui->lineEdit_3->text().toInt()+ui->lineEdit_4->text().toInt()+(a+1)+2;
                    DatUser = Posicion / Dato;
                    QSqlQuery query(db);
                    query.exec("SELECT Unicode FROM Ascii WHERE Decimal='"+QString::number(DatUser)+"'");
                    query.first();
                    Final = query.value(0).toString();
                    ValorAppendPass = ValorAppendPass.append(Final);
                    ui->lineEdit_2->setText(ValorAppendPass);
                }
            }
            if (ui->radioButton_4->isChecked())
            {
                for (int a=0;a<User.count();a++)
                {
                    int Posicion, Dato, DatUser;
                    QString Final;
                    Posicion = User.value(a).toInt();
                    Dato = ui->lineEdit_3->text().toInt()+ui->lineEdit_4->text().toInt()+ui->lineEdit_5->text().toInt()+(a+1)+1;
                    DatUser = Posicion / Dato;
                    QSqlQuery query(db);
                    query.exec("SELECT Unicode FROM Ascii WHERE Decimal='"+QString::number(DatUser)+"'");
                    query.first();
                    Final = query.value(0).toString();
                    ValorAppendUser = ValorAppendUser.append(Final);
                    ui->lineEdit->setText(ValorAppendUser);
                }
                for (int a=0;a<Pass.count();a++)
                {
                    int Posicion, Dato, DatUser;
                    QString Final;
                    Posicion = Pass.value(a).toInt();
                    Dato = ui->lineEdit_3->text().toInt()+ui->lineEdit_4->text().toInt()+ui->lineEdit_5->text().toInt()+(a+1)+2;
                    DatUser = Posicion / Dato;
                    QSqlQuery query(db);
                    query.exec("SELECT Unicode FROM Ascii WHERE Decimal='"+QString::number(DatUser)+"'");
                    query.first();
                    Final = query.value(0).toString();
                    ValorAppendPass = ValorAppendPass.append(Final);
                    ui->lineEdit_2->setText(ValorAppendPass);
                }
            }
        }
        else
        {
            ui->lineEdit->setText(ui->lineEdit_9->text());
            ui->lineEdit_2->setText(ui->lineEdit_10->text());
        }
    }
}

void dbclaves::on_pushButton_clicked()
{
    QString Dir, Usuario, Password, Enc1, Enc2, Enc3, Tipo, UserRD;
    Dir = ui->lineEdit_6->text();
    Usuario = ui->lineEdit_9->text();
    Password = ui->lineEdit_10->text();
    Enc1 = ui->lineEdit_3->text();
    Enc2 = ui->lineEdit_4->text();
    Enc3 = ui->lineEdit_5->text();
    Tipo = ui->comboBox_2->currentText();
    UserRD = IDUser;
    if (Usuario == "" || Password == "" || Dir == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se puede insertar si no se han introducido el usuario, clave y a que pertenece."));
        m.exec();
        return;
    }
    QSqlQuery query(db);
    query.prepare("INSERT INTO Clave (Dir,Usuario,Password,Enc1,Enc2,Enc3,Tipo,UserRD)"
                  "VALUES (:Dir,:Usuario,:Password,:Enc1,:Enc2,:Enc3,:Tipo,:UserRD)");
    query.bindValue(":Dir", Dir);
    query.bindValue(":Usuario", Usuario);
    query.bindValue(":Password", Password);
    query.bindValue(":Enc1", Enc1);
    query.bindValue(":Enc2", Enc2);
    query.bindValue(":Enc3", Enc3);
    query.bindValue(":Tipo", Tipo);
    query.bindValue(":UserRD", UserRD);
    query.exec();
    Model->select();
    ui->tableView->setModel(Model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    this->on_pushButton_6_clicked();
}

void dbclaves::on_pushButton_7_clicked()
{
    ui->tableView->selectRow(fila-1);
}

void dbclaves::on_pushButton_8_clicked()
{
    ui->tableView->selectRow(fila+1);
}

void dbclaves::on_pushButton_2_clicked()
{
    QString Dir, Usuario, Password, Enc1, Enc2, Enc3, Tipo, UserRD;
    Dir = ui->lineEdit_6->text();
    Usuario = ui->lineEdit_9->text();
    Password = ui->lineEdit_10->text();
    Enc1 = ui->lineEdit_3->text();
    Enc2 = ui->lineEdit_4->text();
    Enc3 = ui->lineEdit_5->text();
    Tipo = ui->comboBox_2->currentText();
    UserRD = IDUser;
    QString posicion = ui->lineEdit_7->text();
    if (posicion == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Nada que modificar."));
        m.exec();
        return;
    }
    QSqlRecord record= Model->record(this->fila);
    record.setValue(1,Dir);
    record.setValue(2,Usuario);
    record.setValue(3,Password);
    record.setValue(4,Enc1);
    record.setValue(5,Enc2);
    record.setValue(6,Enc3);
    record.setValue(7,Tipo);
    record.setValue(8,UserRD);
    Model->setRecord(this->fila,record);
    Model->submitAll();
}

void dbclaves::on_pushButton_3_clicked()
{
    QString posicion = ui->lineEdit_7->text();
    if (posicion != "")
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Borrar clave")),
                     QString::fromUtf8(tr("<center><b>Confirmar borrado de clave</center><p>"
                     "Vas a proceder al borrado del usuario y la clave...<p>"
                     "<b>"+ui->lineEdit->text()+" - "+ui->lineEdit_2->text()+"</b><p>"
                     "&iquest;Borrar clave?")), QMessageBox::Ok, QMessageBox::No);
         if (respuesta == QMessageBox::Ok)
             ui->tableView->model()->removeRow(fila);
         else if (respuesta == QMessageBox::No)
             return;
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Nada que borrar."));
        m.exec();
        return;
    }
}

void dbclaves::on_pushButton_11_clicked()
{
    if (ui->tableView->model()->rowCount() != 0)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Borrado de base de datos de claves del usuario activo")),
                               QString::fromUtf8(tr("<center><b>Borrado de base de datos de claves<b></center><p>"
                               "Se borrara toda la lista de claves del usuario activo, por lo que no se podra recuperar.</B><p>"
                               "Como es algo muy peligroso, ya que puedes perder datos muy importantes, tendras que introducir la clave "
                               "de tu usuario para realizar este paso.<p>"
                               "&iquest;Estas seguro de borrar tu base de datos de claves?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            Desbloquear *pass=new Desbloquear(this);
            if (Stilo == "A")
                pass->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            pass->exec();
            DatoRev=pass->Resultado;
            if (DatoRev == "1")
            {
                QSqlQuery query(db);
                query.exec("DELETE FROM Clave WHERE UserRD='"+IDUser+"'");
                Model->select();
                ui->tableView->setModel(Model);
            }
            else if(DatoRev == "0")
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Sin una clave valida no vas a poder borrar la base de datos."));
                m.exec();
                return;
            }
        }
        return;
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Nada que procesar."));
        m.exec();
        return;
    }
}

void dbclaves::on_pushButton_10_clicked()
{
    if (ui->lineEdit_6->text().contains("www"))
         system("su - "+user+" -c \"firefox "+ui->lineEdit_6->text()+"\"");
}

void dbclaves::on_pushButton_12_clicked()
{
    Separador *Separa=new Separador(this);
    if (Stilo == "A")
        Separa->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    Separa->Valor("Usuario;Clave;etc.");
    Separa->exec();
    QString SaltoDat=Separa->SaltoDato;
    if (SaltoDat == "Cancelar")
        return;
    if (SaltoDat == "Tab")
        SaltoDat = "\t";
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameDestino = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar archivo .csv")),
                      path,trUtf8(tr("Archivo .csv (*.csv)")));
    if (fileNameDestino.isEmpty())
        return;
    QString fileName = fileNameDestino.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)").replace(".lst","");
    QFile file(""+fileName+".csv");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream in(&file);
    in << tr("Usuario") << SaltoDat << tr("Clave") << SaltoDat << tr("Descripcion") << SaltoDat << tr("Encriptado Simple") << SaltoDat << tr("Encriptado Doble") << SaltoDat << tr("Encriptado Triple") << SaltoDat << tr("Tipo") << SaltoDat << tr("Usuario RecoverDrake") << "\n";
    QSqlQuery Acces(db);
    Acces.exec("SELECT COUNT(id) as Cantidad FROM Clave");
    int cuenta, comienzo;
    Acces.first();
    cuenta = Acces.value(0).toInt();
    QSqlQuery Acceso(db);
    Acceso.exec("SELECT Dir,Usuario,Password,Enc1,Enc2,Enc3,Tipo,UserRD FROM Clave WHERE UserRD='"+IDUser+"'");
    setUpdatesEnabled(false);
    QProgressDialog progressclaves(tr("Creando archivo... Espera por favor"), "Cancelar", 0, cuenta);
    progressclaves.show();
    comienzo=0;
    while(Acceso.next())
    {
         qApp->processEvents();
         progressclaves.setValue(comienzo++);
         if (progressclaves.wasCanceled())
             break;
         QString Dir = Acceso.value(0).toString();
         QString Usuario = Acceso.value(1).toString();
         QString Password = Acceso.value(2).toString();
         QString Enc1 = Acceso.value(3).toString();
         QString Enc2 = Acceso.value(4).toString();
         QString Enc3 = Acceso.value(5).toString();
         QString Tipo = Acceso.value(6).toString();
         QString UserRD = Acceso.value(7).toString();
         in << Usuario << SaltoDat << Password << SaltoDat << Dir << SaltoDat << Enc1 << SaltoDat << Enc2 << SaltoDat << Enc3 << SaltoDat << Tipo << SaltoDat << UserRD << "\n";
    }
    progressclaves.setValue(cuenta);
    file.close();
    setUpdatesEnabled(true);
    QMessageBox m;
    if (Stilo == "A")
        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    m.setText(tr("Exportacion a fichero realizada."));
    m.exec();
    return;
}

void dbclaves::on_pushButton_5_clicked()
{
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Importar fichero .cvs")),
                           QString::fromUtf8(tr("<b>Importar fichero .cvs</b><p>"
                           "Es importante que diferencies en el fichero .cvs que hayas generado, los "
                           "saltos de linea correctos, para que no interfieran en los datos a importar.<p>"
                           "Comprueba antes de importar cual has definido por defecto.</p>"
                           "Se insertaran los nuevos registros al final de la tabla.<p>"
                           "&iquest;Importar fichero .cvs?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        QString path=tr("/home/%1/Documentos/");
        path=path.arg(user);
        fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de texto en formato .csv")),
                            path,trUtf8(tr("Fichero .csv (*.csv)")));
        if (fileNameOrigen.isEmpty())
            return;
        QFile file(fileNameOrigen);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString datoslst = in.readAll();
        file.close();
        QStringList datos = datoslst.split("\n");
        if (import != 0)
            delete import;
        import=new importar(this);
        if (Stilo == "A")
            import->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        import->Valor(datos,1,IDUser);
        import->exec();
        QString Recibido=import->Resultado;
        if (Recibido == "Negativo")
            return;
        else if (Recibido == "Positivo")
        {
            Model->select();
            ui->tableView->setModel(Model);
        }
    }
    else if (respuesta == QMessageBox::No)
        return;
}

void dbclaves::orden()
{
    QString busca;
    busca = ui->comboBox->currentText();
    if (busca == tr("Sin filtro (todas las claves)"))
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
            Model->setFilter("dir like '%"+ui->lineEdit_8->text()+"%' and UserRD like'"+IDUser+"'");
        else
            Model->setFilter("dir != '""' and UserRD like'"+IDUser+"'");
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
            ui->tableView->sortByColumn(1,Qt::SortOrder(0));
        else
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Tipo: Web"))
    {
       Model->setFilter("tipo like 'Web' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Tipo: Banco"))
    {
       Model->setFilter("tipo like 'Banco' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Tipo: Movil"))
    {
       Model->setFilter("tipo like 'Movil' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Tipo: Ordenador"))
    {
       Model->setFilter("tipo like 'Ordenador' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Tipo: Caja fuerte"))
    {
       Model->setFilter("tipo like 'Caja fuerte' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Tipo: Otros"))
    {
       Model->setFilter("tipo like 'Otros' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Usuario"))
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
            Model->setFilter("usuario like '%"+ui->lineEdit_8->text()+"%' and UserRD like'"+IDUser+"'");
        else
            Model->setFilter("usuario != '""' and UserRD like'"+IDUser+"'");
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
            ui->tableView->sortByColumn(2,Qt::SortOrder(0));
        else
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Clave"))
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
            Model->setFilter("password like '%"+ui->lineEdit_8->text()+"%' and UserRD like'"+IDUser+"'");
        else
            Model->setFilter("password != '""' and UserRD like'"+IDUser+"'");
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
            ui->tableView->sortByColumn(3,Qt::SortOrder(0));
        else
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Encriptacion: Sin encriptar"))
    {
       Model->setFilter("enc1 like '0' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Encriptacion: Encriptacion simple"))
    {
       Model->setFilter("enc1 != '0' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca ==  tr("Encriptacion: Encriptacion doble"))
    {
       Model->setFilter("enc2 != '0' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca ==  tr("Encriptacion: Encriptacion triple"))
    {
       Model->setFilter("enc3 != '0' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Descripcion"))
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
            Model->setFilter("Dir like '%"+ui->lineEdit_8->text()+"%' and UserRD like'"+IDUser+"'");
        else
            Model->setFilter("dir != '""' and UserRD like'"+IDUser+"'");
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
            ui->tableView->sortByColumn(1,Qt::SortOrder(0));
        else
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
}

void dbclaves::on_comboBox_currentIndexChanged(QString busca)
{
    if (busca == tr("Sin filtro (todas las claves)"))
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
            Model->setFilter("dir like '%"+ui->lineEdit_8->text()+"%' and UserRD like'"+IDUser+"'");
        else
            Model->setFilter("dir != '""' and UserRD like'"+IDUser+"'");
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
            ui->tableView->sortByColumn(1,Qt::SortOrder(0));
        else
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Tipo: Web"))
    {
       Model->setFilter("tipo like 'Web' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Tipo: Banco"))
    {
       Model->setFilter("tipo like 'Banco' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Tipo: Movil"))
    {
       Model->setFilter("tipo like 'Movil' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Tipo: Ordenador"))
    {
       Model->setFilter("tipo like 'Ordenador' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Tipo: Caja fuerte"))
    {
       Model->setFilter("tipo like 'Caja fuerte' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Tipo: Otros"))
    {
       Model->setFilter("tipo like 'Otros' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Usuario"))
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
            Model->setFilter("usuario like '%"+ui->lineEdit_8->text()+"%' and UserRD like'"+IDUser+"'");
        else
            Model->setFilter("usuario != '""' and UserRD like'"+IDUser+"'");
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
            ui->tableView->sortByColumn(2,Qt::SortOrder(0));
        else
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Clave"))
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
            Model->setFilter("password like '%"+ui->lineEdit_8->text()+"%' and UserRD like'"+IDUser+"'");
        else
            Model->setFilter("password != '""' and UserRD like'"+IDUser+"'");
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
            ui->tableView->sortByColumn(3,Qt::SortOrder(0));
        else
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Encriptacion: Sin encriptar"))
    {
       Model->setFilter("enc1 like '0' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Encriptacion: Encriptacion simple"))
    {
       Model->setFilter("enc1 != '0' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca ==  tr("Encriptacion: Encriptacion doble"))
    {
       Model->setFilter("enc2 != '0' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca ==  tr("Encriptacion: Encriptacion triple"))
    {
       Model->setFilter("enc3 != '0' and UserRD like'"+IDUser+"'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       else
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
    if (busca == tr("Descripcion"))
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
            Model->setFilter("Dir like '%"+ui->lineEdit_8->text()+"%' and UserRD like'"+IDUser+"'");
        else
            Model->setFilter("dir != '""' and UserRD like'"+IDUser+"'");
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
            ui->tableView->sortByColumn(1,Qt::SortOrder(0));
        else
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
    }
}

void dbclaves::on_pushButton_9_clicked()
{
    SaveToBDFrm frm(this);
    frm.Valor("2","Clave",IDUser,"");
    frm.exec();
}

QString dbclaves::DesencriptarUser(QString Userid, QString Enc1, QString Enc2, QString Enc3, int Tipo)
{
    QString resultado;
    QString UserParc = Userid;
    QStringList User = UserParc.split("-");
    if (Enc1 == "0")
        resultado = Userid;
    else if (Enc2 == "0")
    {
        for (int a=0;a<User.count();a++)
        {
            int Posicion, Dato, DatUser;
            QString Final;
            Posicion = User.value(a).toInt();
            if (Tipo == 0)
                Dato =Enc1.toInt()+(a+1)+1;
            if (Tipo == 1)
                Dato =Enc1.toInt()+(a+1)+2;
            DatUser = Posicion / Dato;
            QSqlQuery query(db);
            query.exec("SELECT Unicode FROM Ascii WHERE Decimal='"+QString::number(DatUser)+"'");
            query.first();
            Final = query.value(0).toString();
            resultado = resultado.append(Final);
        }
    }
    else if (Enc3 == "0")
    {
        for (int a=0;a<User.count();a++)
        {
            int Posicion, Dato, DatUser;
            QString Final;
            Posicion = User.value(a).toInt();
            if (Tipo == 0)
                Dato = Enc1.toInt()+Enc2.toInt()+(a+1)+1;
            if (Tipo == 1)
                Dato = Enc1.toInt()+Enc2.toInt()+(a+1)+2;
            DatUser = Posicion / Dato;
            QSqlQuery query(db);
            query.exec("SELECT Unicode FROM Ascii WHERE Decimal='"+QString::number(DatUser)+"'");
            query.first();
            Final = query.value(0).toString();
            resultado = resultado.append(Final);
        }
    }
    else if (Enc3 != "0")
    {
        for (int a=0;a<User.count();a++)
        {
            int Posicion, Dato, DatUser;
            QString Final;
            Posicion = User.value(a).toInt();
            if (Tipo == 0)
                Dato = Enc1.toInt()+Enc2.toInt()+Enc3.toInt()+(a+1)+1;
            if (Tipo == 1)
                Dato = Enc1.toInt()+Enc2.toInt()+Enc3.toInt()+(a+1)+2;
            DatUser = Posicion / Dato;
            QSqlQuery query(db);
            query.exec("SELECT Unicode FROM Ascii WHERE Decimal='"+QString::number(DatUser)+"'");
            query.first();
            Final = query.value(0).toString();
            resultado = resultado.append(Final);
        }
    }
    return resultado;
}

void dbclaves::Cambiar()
{
    if (ui->radioButton_5->isChecked())
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->lineEdit->setFocus();
    }
    else if (ui->radioButton_6->isChecked())
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->lineEdit_11->setFocus();
    }
}

void dbclaves::on_lineEdit_11_textChanged(const QString &arg1)
{
    QString User,Pass,Enc1,Enc2,Enc3;
    User = arg1;
    Pass = ui->lineEdit_12->text();
    Enc1 = ui->lineEdit_13->text();
    Enc2 = ui->lineEdit_14->text();
    Enc3 = ui->lineEdit_15->text();
    if ( Enc1 != "" || Enc2 != "" || Enc3 !="")
    {
        QString Usuario = DesencriptarUser(User,Enc1,Enc2,Enc3,0);
        QString Password = DesencriptarUser(Pass,Enc1,Enc2,Enc3,1);
        ui->lineEdit_18->setText(Usuario);
        ui->lineEdit_19->setText(Password);
    }
}

void dbclaves::on_lineEdit_12_textChanged(const QString &arg1)
{
    QString User,Pass,Enc1,Enc2,Enc3;
    User = ui->lineEdit_11->text();
    Pass = arg1;
    Enc1 = ui->lineEdit_13->text();
    Enc2 = ui->lineEdit_14->text();
    Enc3 = ui->lineEdit_15->text();
    if ( Enc1 != "" || Enc2 != "" || Enc3 !="")
    {
        QString Usuario = DesencriptarUser(User,Enc1,Enc2,Enc3,0);
        QString Password = DesencriptarUser(Pass,Enc1,Enc2,Enc3,1);
        ui->lineEdit_18->setText(Usuario);
        ui->lineEdit_19->setText(Password);
    }
}

void dbclaves::on_lineEdit_13_textChanged(const QString &arg1)
{
    QString User,Pass,Enc1,Enc2,Enc3;
    User = ui->lineEdit_11->text();
    Pass = ui->lineEdit_12->text();
    Enc1 = arg1;
    Enc2 = ui->lineEdit_14->text();
    Enc3 = ui->lineEdit_15->text();
    if ( Enc1 != "" || Enc2 != "" || Enc3 != "")
    {
        QString Usuario = DesencriptarUser(User,Enc1,Enc2,Enc3,0);
        QString Password = DesencriptarUser(Pass,Enc1,Enc2,Enc3,1);
        ui->lineEdit_18->setText(Usuario);
        ui->lineEdit_19->setText(Password);
    }
}

void dbclaves::on_lineEdit_14_textChanged(const QString &arg1)
{
    QString User,Pass,Enc1,Enc2,Enc3;
    User = ui->lineEdit_11->text();
    Pass = ui->lineEdit_12->text();
    Enc1 = ui->lineEdit_13->text();
    Enc2 = arg1;
    Enc3 = ui->lineEdit_15->text();
    if ( Enc1 != "" || Enc2 != "" || Enc3 != "")
    {
        QString Usuario = DesencriptarUser(User,Enc1,Enc2,Enc3,0);
        QString Password = DesencriptarUser(Pass,Enc1,Enc2,Enc3,1);
        ui->lineEdit_18->setText(Usuario);
        ui->lineEdit_19->setText(Password);
    }
}

void dbclaves::on_lineEdit_15_textChanged(const QString &arg1)
{
    QString User,Pass,Enc1,Enc2,Enc3;
    User = ui->lineEdit_11->text();
    Pass = ui->lineEdit_12->text();
    Enc1 = ui->lineEdit_13->text();
    Enc2 = ui->lineEdit_14->text();
    Enc3 = arg1;
    if ( Enc1 != "" || Enc2 != "" || Enc3 != "")
    {
        QString Usuario = DesencriptarUser(User,Enc1,Enc2,Enc3,0);
        QString Password = DesencriptarUser(Pass,Enc1,Enc2,Enc3,1);
        ui->lineEdit_18->setText(Usuario);
        ui->lineEdit_19->setText(Password);
    }
}
