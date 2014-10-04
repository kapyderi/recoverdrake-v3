#include "visualreport.h"
#include "ui_visualreport.h"

VisualReport::VisualReport(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VisualReport)
{
    ui->setupUi(this);
}

VisualReport::~VisualReport()
{
    delete ui;
}

