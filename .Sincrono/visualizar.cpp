#include "visualizar.h"
#include "ui_visualizar.h"
#include <QKeyEvent>
#include <QDebug>

Visualizar::Visualizar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Visualizar)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");    
    this->installEventFilter(this);
    CierreTotal = 0;
}

Visualizar::~Visualizar()
{
    delete ui;
    delete Model;
}

void Visualizar::changeEvent(QEvent *e)
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

void Visualizar::Valor(QString valor, QString Tipo, QString ValorReg)
{
    if (valor == "Quitar")
    {        
        CierreTotal = 1;
    }
    if (Tipo == "Logs")
    {
        ui->tableView->setVisible(true);
        ui->textEdit->setVisible(false);
        Model= new QSqlTableModel(0,db);
        Model->setTable("Control");
        Model->select();
        ui->tableView->setModel(Model);
        ui->tableView->setColumnHidden(0, true);
        ui->tableView->resizeRowsToContents();
        ui->tableView->resizeColumnsToContents();
        TipoS = 0;
    }
    if (Tipo == "Error")
    {
        ui->tableView->setVisible(false);
        ui->textEdit->setVisible(true);
        QStringList Leer = ValorReg.split("\n");
        for (int i=0;i<Leer.count();i++)
        {
            ui->textEdit->append(Leer.value(i));
        }
        TipoS = 1;
    }
}

void Visualizar::on_pushButton_clicked()
{
    if (CierreTotal == 1)
    {
        if (TipoS == 0)
            emit Cerrar();
        else if (TipoS == 1)
            emit Cerrando();
    }
    else
        close();
}

void Visualizar::closeEvent ( QCloseEvent * event )
{
    if (CierreTotal == 1)
    {
        if (TipoS == 0)
            emit Cerrar();
        else if (TipoS == 1)
            emit Cerrando();
        event->accept();
    }
    else
    {
        close();
        event->accept();
    }
}

bool Visualizar::eventFilter(QObject* obj, QEvent *event)
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
