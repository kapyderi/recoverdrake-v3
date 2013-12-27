#include "help.h"
#include "ui_help.h"
#include <QKeyEvent>

help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    CierreTotal = 0;
}

help::~help()
{
    delete ui;
}

void help::changeEvent(QEvent *e)
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

void help::on_pushButton_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void help::closeEvent ( QCloseEvent * event )
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

void help::Valor(QString valor)
{
    if (valor == "Quitar")
    {     
        CierreTotal = 1;
    }
}

bool help::eventFilter(QObject* obj, QEvent *event)
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
