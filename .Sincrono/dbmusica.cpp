#include "dbmusica.h"
#include "ui_dbmusica.h"

dbmusica::dbmusica(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbmusica)
{
    ui->setupUi(this);
}

dbmusica::~dbmusica()
{
    delete ui;
}

void dbmusica::changeEvent(QEvent *e)
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
