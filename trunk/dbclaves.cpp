#include "dbclaves.h"
#include "ui_dbclaves.h"
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCloseEvent>
#include <QMessageBox>
#include <QDebug>
#include <drakesistema.h>

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
    Model->setHeaderData(1,Qt::Horizontal,"Descripcion");
    Model->setHeaderData(3,Qt::Horizontal,"Clave");    
    ui->tableView->setModel(Model);
    ui->tableView->setColumnHidden(8, true);
    ui->tableView->setColumnHidden(4, true);
    ui->tableView->setColumnHidden(5, true);
    ui->tableView->setColumnHidden(6, true);
    Stilo = "B";
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila(QModelIndex)));
    ui->tableView->selectRow(0);
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
    ui->lineEdit->setFocus();
    this->installEventFilter(this);
    CierreTotal = 0;
    Bloqueo = 0;
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
    index=ui->tableView->model()->index(i,3);
    ui->lineEdit_10->setText(tr(index.data().toString()));
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
                }
            }
        }
        else
        {
            ui->lineEdit_9->setText(ui->lineEdit->text());
            ui->lineEdit_10->setText(ui->lineEdit_2->text());
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
                     "<b>"+ui->lineEdit->text()+" -  "+ui->lineEdit_2->text()+"</b><p>"
                     "&iquest;Borrar clave?")), QMessageBox::Ok, QMessageBox::No);
         if (respuesta == QMessageBox::Ok)
         {
             ui->tableView->model()->removeRow(fila);
         }
         else if (respuesta == QMessageBox::No)
         {
             return;
         }
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
                               "de usuario para realizar este paso.<p>"
                               "&iquest;Estas seguro de borrar la base de datos de claves?")), QMessageBox::Ok, QMessageBox::No);
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
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Sin una clave valida no vas a poder borrar la base de datos."));
                m.exec();
                return;
            }
        }
        return;
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Nada que procesar."));
        m.exec();
        return;
    }
}

void dbclaves::on_pushButton_10_clicked()
{
    if (ui->lineEdit_6->text().contains("www"))
    {
         system("su - "+user+" -c \"firefox "+ui->lineEdit_6->text()+"\"");
    }
}
