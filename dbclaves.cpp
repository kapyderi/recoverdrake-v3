#include "dbclaves.h"
#include "ui_dbclaves.h"
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCloseEvent>

dbclaves::dbclaves(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbclaves)
{
    ui->setupUi(this);
    import=0;
    db=QSqlDatabase::database("PRINCIPAL");
    Model= new QSqlTableModel(0,db);
    Model->setTable("Clave");
    Model->select();    
    Model->setHeaderData(2,Qt::Horizontal,"Clave");
    Model->setHeaderData(3,Qt::Horizontal,"Encriptacion: Simple");
    Model->setHeaderData(4,Qt::Horizontal,"Encriptacion: Doble");
    Model->setHeaderData(5,Qt::Horizontal,"Encriptacion: Tripe");
    Model->setHeaderData(8,Qt::Horizontal,"Usuario de RecoverDrake");
    ui->tableView->setModel(Model);
    ui->tableView->resizeColumnsToContents();
    Stilo = "B";
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila(QModelIndex)));
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
        if (ui->lineEdit_6->text() != "")
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

void dbclaves::Valor(QString valor)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
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
        ui->pushButton_13->setVisible(false);
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
        ui->pushButton_13->setVisible(true);
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
        ui->pushButton_13->setVisible(true);
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
        ui->pushButton_13->setVisible(true);
        this->ramdomize();
    }
}

void dbclaves::on_comboBox_2_activated(const QString &arg1)
{
    if (arg1 == tr("Web"))
    {
        if (ui->lineEdit_6->text() != "")
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
}

void dbclaves::on_lineEdit_2_textChanged(const QString &arg1)
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
}

void dbclaves::on_pushButton_6_clicked()
{
    //me he quedado por aqui
}
