#include "pregunta.h"
#include "ui_pregunta.h"

Pregunta::Pregunta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pregunta)
{
    ui->setupUi(this);
}

Pregunta::~Pregunta()
{
    delete ui;
}
