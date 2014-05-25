#include "dbopciones.h"
#include "ui_dbopciones.h"

dbopciones::dbopciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbopciones)
{
    ui->setupUi(this);
}

dbopciones::~dbopciones()
{
    delete ui;
}

void dbopciones::changeEvent(QEvent *e)
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
