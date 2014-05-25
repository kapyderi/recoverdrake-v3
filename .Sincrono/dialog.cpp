#include "dialog.h"
#include "ui_dialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    QSqlQuery querySpain(db);
    querySpain.exec("SELECT spanish FROM Idioma WHERE id=2");
    querySpain.first();
    if (querySpain.isSelect())
        Spain=querySpain.value(0).toString();
    QSqlQuery queryEnglish(db);
    queryEnglish.exec("SELECT english FROM Idioma WHERE id=2");
    queryEnglish.first();
    if (queryEnglish.isSelect())
        English=queryEnglish.value(0).toString();
    QSqlQuery query(db);
    if ( Spain == "2")
       {
           query.exec("select Sugerencia from sugerencias order by random()");
           query.first();
           if (query.isSelect())
               query2=query.value(0).toString();
           ui->label_2->setText(query2);
       }
    else if ( English == "2")
       {
           query.exec("select Advice from Advice order by random()");
           query.first();
           if (query.isSelect())
               query2=query.value(0).toString();
           ui->label_2->setText(query2);
       }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::changeEvent(QEvent *e)
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

void Dialog::on_pushButton_clicked()
{
    close();
}

void Dialog::on_pushButton_3_clicked()
{
    Anterior=query2;
    QSqlQuery query(db);
    if ( Spain == "2")
    {
        query.exec("select Sugerencia from sugerencias order by random()");
        query.next();
        if (query.isValid())
        {
            query2=query.value(0).toString();
            ui->label_2->setText(query2);
        }
    }
    else if ( English == "2")
    {
        query.exec("select Advice from Advice order by random()");
        query.next();
        if (query.isValid())
        {
           query2=query.value(0).toString();
           ui->label_2->setText(query2);
       }
    }
}

void Dialog::on_pushButton_2_clicked()
{
    if (Anterior != "")
    {
        QSqlQuery query(db);
        if ( Spain == "2")
        {
            query.exec("select Sugerencia from sugerencias WHERE Sugerencia='"+Anterior+"'");
            query.first();
            if (query.isSelect())
                query2=query.value(0).toString();
            ui->label_2->setText(query2);
        }
        else if ( English == "2")
        {
            query.exec("select Advice from Advice WHERE Advice='"+Anterior+"'");
            query.first();
            if (query.isSelect())
                query2=query.value(0).toString();
            ui->label_2->setText(query2);
        }
    }
}
