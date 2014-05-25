#include "dblibros.h"
#include "ui_dblibros.h"

dblibros::dblibros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dblibros)
{
    ui->setupUi(this);
}

dblibros::~dblibros()
{
    delete ui;
}

void dblibros::changeEvent(QEvent *e)
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
