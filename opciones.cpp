#include "opciones.h"
#include "ui_opciones.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include "drakesistema.h"
#include <QProcess>
#include <QDebug>
#include <QColorDialog>
#include <QTranslator>
#include <QProgressDialog>
#include <QTest>
#include <QSqlError>
#include <QGradient>
#include <QStyleFactory>
#include <QPalette>
#include <QStylePlugin>
#include <Smpt/SmtpMime>
#include "notas.h"

extern QTranslator *qTranslator;

opciones::opciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::opciones)
{
    ui->setupUi(this);
    drakeSistema drake;
    user = drake.getUser();
    arqt = drake.getArquitectura();
    notas *acc=new notas();
    Ver=acc->Ultimo;
    ui->label_216->setText(Ver);
    db=QSqlDatabase::database("PRINCIPAL");
    Stilo = "B";
    Model= new QSqlTableModel(0,db);
    Model->setTable("Opcion");
    Model->select();
    Model1= new QSqlTableModel(0,db);
    Model1->setTable("Opcion2");
    Model1->select();
    Model2= new QSqlTableModel(0,db);
    Model2->setTable("Opcion1");
    Model2->select();
    Model3= new QSqlTableModel(0,db);
    Model3->setTable("Opcion3");
    Model3->select();
    Model4= new QSqlTableModel(0,db);
    Model4->setTable("Opcion4");
    Model4->select();
    Model5= new QSqlTableModel(0,db);
    Model5->setTable("Opcion5");
    Model5->select();
    Model6= new QSqlTableModel(0,db);
    Model6->setTable("Miscelanea");
    Model6->select();
    Model7= new QSqlTableModel(0,db);
    Model7->setTable("Parental");
    Model7->select();
    Model8= new QSqlTableModel(0,db);
    Model8->setTable("wifi");
    Model8->select();
    Model9= new QSqlTableModel(0,db);
    Model9->setTable("ethernet");
    Model9->select();
    Model10= new QSqlTableModel(0,db);
    Model10->setTable("red");
    Model10->select();
    Model11= new QSqlTableModel(0,db);
    Model11->setTable("Idioma");
    Model11->select();
    Model12= new QSqlTableModel(0,db);
    Model12->setTable("Palabra");
    Model12->select();
    Model12->setHeaderData(1,Qt::Horizontal,tr("Palabra a evitar"));
    ui->tableView->setModel(Model12);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->resizeColumnsToContents();
    ui->tabWidget->setCurrentPage(0);
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(cambiaFila(QModelIndex)));
    Model13= new QSqlTableModel(0,db);
    Model13->setTable("Video");
    Model13->select();
    Model14= new QSqlTableModel(0,db);
    Model14->setTable("Font");
    Model14->select();
    Model15= new QSqlTableModel(0,db);
    Model15->setTable("Color");
    Model15->select();
    Model16= new QSqlTableModel(0,db);
    Model16->setTable("consola");
    Model16->select();
    Model17= new QSqlTableModel(0,db);
    Model17->setTable("Menus");
    Model17->select();
    Model18= new QSqlTableModel(0,db);
    Model18->setTable("Aplicacion");
    Model18->select();
    Model19= new QSqlTableModel(0,db);
    Model19->setTable("chat");
    Model19->select();
    Model20= new QSqlTableModel(0,db);
    Model20->setTable("Formato");
    Model20->select();
    Model21= new QSqlTableModel(0,db);
    Model21->setTable("Estilo");
    Model21->select();
    Model22= new QSqlTableModel(0,db);
    Model22->setTable("Ecualizador");
    Model22->select();
    Model23= new QSqlTableModel(0,db);
    Model23->setTable("Pais");
    Model23->select();
    Model24= new QSqlTableModel(0,db);
    Model24->setTable("Smtp");
    Model24->select();
    Model24->setHeaderData(2,Qt::Horizontal,tr("Servidor SMTP"));
    Model24->setHeaderData(6,Qt::Horizontal,tr("Usuario"));
    Model24->setHeaderData(7,Qt::Horizontal,tr("Puerto"));
    ui->tableView_2->setModel(Model24);
    ui->tableView_2->setColumnHidden(0, true);
    ui->tableView_2->setColumnHidden(3, true);
    ui->tableView_2->resizeColumnsToContents();
    connect(ui->tableView_2->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(cambiaFila1(QModelIndex)));
    Save = 0;
    Retro = 1;
    connect(ui->radioButton_15,SIGNAL(clicked()),this,SLOT(Wlan()));
    connect(ui->radioButton_14,SIGNAL(clicked()),this,SLOT(Eth()));
    connect(ui->radioButton_16,SIGNAL(clicked()),this,SLOT(Spanish()));
    connect(ui->radioButton_17,SIGNAL(clicked()),this,SLOT(English()));
    connect(ui->comboBox_3, SIGNAL(activated(QString)),this, SLOT(changeStyle(QString)));
    connect(ui->checkBox_4, SIGNAL(clicked()), this, SLOT(Comprobar()));
    ui->comboBox_3->addItems(QStyleFactory::keys());
    ui->radioButton_54->setChecked(true);
    connect(ui->radioButton_54,SIGNAL(clicked()),this,SLOT(Smtp()));
    connect(ui->radioButton_55,SIGNAL(clicked()),this,SLOT(Smtp()));
    this->Smtp();
    connect(ui->checkBox_7,SIGNAL(clicked()),this,SLOT(password()));
    this->iniciar();
}

opciones::~opciones()
{
    delete ui;
    delete Model;
    delete Model1;
    delete Model2;
    delete Model3;
    delete Model4;
    delete Model5;
    delete Model6;
    delete Model7;
    delete Model8;
    delete Model9;
    delete Model10;
    delete Model11;
    delete Model12;
    delete Model13;
    delete Model14;
    delete Model15;
    delete Model16;
    delete Model17;
    delete Model18;
    delete Model19;
    delete Model20;
    delete Model21;
    delete Model22;
    delete Model23;
    delete Model24;
}

void opciones::changeEvent(QEvent *e)
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

void opciones::Valor(QString Opcion)
{
    if (Opcion == "mail")
        ui->tabWidget->setCurrentIndex(4);
}

void opciones::Comprobar()
{
    if (ui->checkBox_4->isChecked())
        ui->groupBox_20->setEnabled(true);
    else
        ui->groupBox_20->setEnabled(false);
}

void opciones::iniciar()
{
    setUpdatesEnabled(false);
    QProgressDialog progress(tr("Recopilando datos de preferencias personales... Espera por favor"), tr("Cancelar"), 0, 101, this);
    progress.show();
    QTest::qWait(20);
    for(int i=0;i<101;i++)
    {
        qApp->processEvents();
        progress.setValue(i);
        if (progress.wasCanceled())
            break;
        if (i==0)
        {
            QSqlQuery query(db);
            query.exec("SELECT Audio128 FROM Opcion WHERE id=2");
            query.first();
            if (query.isValid())
                cantidad=query.value(0).toString();
            QSqlQuery query0(db);
            query0.exec("SELECT Audio192 FROM Opcion WHERE id=2");
            query0.first();
            if (query0.isValid())
                cantidad1=query0.value(0).toString();
            QSqlQuery query1(db);
            query1.exec("SELECT Audio320 FROM Opcion WHERE id=2");
            query1.first();
            if (query1.isValid())
                cantidad2=query1.value(0).toString();
            if ( cantidad == "2")
               {
                ui->radioButton->setChecked(true);
                ui->radioButton_2->setChecked(false);
                ui->radioButton_3->setChecked(false);
               }
            else if ( cantidad1 == "2")
               {
                ui->radioButton->setChecked(false);
                ui->radioButton_2->setChecked(true);
                ui->radioButton_3->setChecked(false);
               }
            else if ( cantidad2 == "2")
               {
                ui->radioButton->setChecked(false);
                ui->radioButton_2->setChecked(false);
                ui->radioButton_3->setChecked(true);
               }
        }
        if (i==1)
        {
            QSqlQuery query3(db);
            query3.exec("SELECT camouflage_pa FROM Opcion2 WHERE id=2");
            query3.first();
            if (query3.isValid())
                cantidad3=query3.value(0).toString();
            QSqlQuery query4(db);
            query4.exec("SELECT efsplitter_pa FROM Opcion2 WHERE id=2");
            query4.first();
            if (query4.isValid())
                cantidad4=query4.value(0).toString();
            QSqlQuery query5(db);
            query5.exec("SELECT generico_pa FROM Opcion2 WHERE id=2");
            query5.first();
            if (query5.isValid())
                cantidad5=query5.value(0).toString();
            QSqlQuery query6(db);
            query6.exec("SELECT hacha1_pa FROM Opcion2 WHERE id=2");
            query6.first();
            if (query6.isValid())
                cantidad6=query6.value(0).toString();
            QSqlQuery query7(db);
            query7.exec("SELECT hacha2_pa FROM Opcion2 WHERE id=2");
            query7.first();
            if (query7.isValid())
                cantidad7=query7.value(0).toString();
            QSqlQuery query8(db);
            query8.exec("SELECT hachapro_pa FROM Opcion2 WHERE id=2");
            query8.first();
            if (query8.isValid())
                cantidad8=query8.value(0).toString();
            QSqlQuery query9(db);
            query9.exec("SELECT mxs_pa FROM Opcion2 WHERE id=2");
            query9.first();
            if (query9.isValid())
                cantidad9=query9.value(0).toString();
            QSqlQuery query10(db);
            query10.exec("SELECT sf_pa FROM Opcion2 WHERE id=2");
            query10.first();
            if (query10.isValid())
                cantidad10=query10.value(0).toString();
            QSqlQuery query11(db);
            query11.exec("SELECT zip_pa FROM Opcion2 WHERE id=2");
            query11.first();
            if (query11.isValid())
                cantidad11=query11.value(0).toString();
            QSqlQuery query12(db);
            query12.exec("SELECT camaleon1_pa FROM Opcion2 WHERE id=2");
            query12.first();
            if (query12.isValid())
                cantidad12=query12.value(0).toString();
            QSqlQuery query13(db);
            query13.exec("SELECT camaleon2_pa FROM Opcion2 WHERE id=2");
            query13.first();
            if (query13.isValid())
                cantidad13=query13.value(0).toString();
            if ( cantidad3 == "2")
               {
                   ui->radioButton_20->setChecked(true);
                   ui->radioButton_21->setChecked(false);
                   ui->radioButton_23->setChecked(false);
                   ui->radioButton_24->setChecked(false);
                   ui->radioButton_25->setChecked(false);
                   ui->radioButton_26->setChecked(false);
                   ui->radioButton_27->setChecked(false);
                   ui->radioButton_28->setChecked(false);
                   ui->radioButton_29->setChecked(false);
                   ui->radioButton_30->setChecked(false);
                   ui->radioButton_31->setChecked(false);
               }
            else if ( cantidad4 == "2")
               {
                   ui->radioButton_20->setChecked(false);
                   ui->radioButton_21->setChecked(true);
                   ui->radioButton_23->setChecked(false);
                   ui->radioButton_24->setChecked(false);
                   ui->radioButton_25->setChecked(false);
                   ui->radioButton_26->setChecked(false);
                   ui->radioButton_27->setChecked(false);
                   ui->radioButton_28->setChecked(false);
                   ui->radioButton_29->setChecked(false);
                   ui->radioButton_30->setChecked(false);
                   ui->radioButton_31->setChecked(false);
               }
            else if ( cantidad5 == "2")
               {
                   ui->radioButton_20->setChecked(false);
                   ui->radioButton_21->setChecked(false);
                   ui->radioButton_23->setChecked(true);
                   ui->radioButton_24->setChecked(false);
                   ui->radioButton_25->setChecked(false);
                   ui->radioButton_26->setChecked(false);
                   ui->radioButton_27->setChecked(false);
                   ui->radioButton_28->setChecked(false);
                   ui->radioButton_29->setChecked(false);
                   ui->radioButton_30->setChecked(false);
                   ui->radioButton_31->setChecked(false);
               }
            else if ( cantidad6 == "2")
               {
                   ui->radioButton_20->setChecked(false);
                   ui->radioButton_21->setChecked(false);
                   ui->radioButton_23->setChecked(false);
                   ui->radioButton_24->setChecked(true);
                   ui->radioButton_25->setChecked(false);
                   ui->radioButton_26->setChecked(false);
                   ui->radioButton_27->setChecked(false);
                   ui->radioButton_28->setChecked(false);
                   ui->radioButton_29->setChecked(false);
                   ui->radioButton_30->setChecked(false);
                   ui->radioButton_31->setChecked(false);
               }
            else if ( cantidad7 == "2")
               {
                   ui->radioButton_20->setChecked(false);
                   ui->radioButton_21->setChecked(false);
                   ui->radioButton_23->setChecked(false);
                   ui->radioButton_24->setChecked(false);
                   ui->radioButton_25->setChecked(true);
                   ui->radioButton_26->setChecked(false);
                   ui->radioButton_27->setChecked(false);
                   ui->radioButton_28->setChecked(false);
                   ui->radioButton_29->setChecked(false);
                   ui->radioButton_30->setChecked(false);
                   ui->radioButton_31->setChecked(false);
               }
            else if ( cantidad8 == "2")
               {
                   ui->radioButton_20->setChecked(false);
                   ui->radioButton_21->setChecked(false);
                   ui->radioButton_23->setChecked(false);
                   ui->radioButton_24->setChecked(false);
                   ui->radioButton_25->setChecked(false);
                   ui->radioButton_26->setChecked(true);
                   ui->radioButton_27->setChecked(false);
                   ui->radioButton_28->setChecked(false);
                   ui->radioButton_29->setChecked(false);
                   ui->radioButton_30->setChecked(false);
                   ui->radioButton_31->setChecked(false);
               }
            else if ( cantidad9 == "2")
               {
                   ui->radioButton_20->setChecked(false);
                   ui->radioButton_21->setChecked(false);
                   ui->radioButton_23->setChecked(false);
                   ui->radioButton_24->setChecked(false);
                   ui->radioButton_25->setChecked(false);
                   ui->radioButton_26->setChecked(false);
                   ui->radioButton_27->setChecked(true);
                   ui->radioButton_28->setChecked(false);
                   ui->radioButton_29->setChecked(false);
                   ui->radioButton_30->setChecked(false);
                   ui->radioButton_31->setChecked(false);
               }
            else if ( cantidad10 == "2")
               {
                   ui->radioButton_20->setChecked(false);
                   ui->radioButton_21->setChecked(false);
                   ui->radioButton_23->setChecked(false);
                   ui->radioButton_24->setChecked(false);
                   ui->radioButton_25->setChecked(false);
                   ui->radioButton_26->setChecked(false);
                   ui->radioButton_27->setChecked(false);
                   ui->radioButton_28->setChecked(true);
                   ui->radioButton_29->setChecked(false);
                   ui->radioButton_30->setChecked(false);
                   ui->radioButton_31->setChecked(false);
               }
            else if ( cantidad11 == "2")
               {
                   ui->radioButton_20->setChecked(false);
                   ui->radioButton_21->setChecked(false);
                   ui->radioButton_23->setChecked(false);
                   ui->radioButton_24->setChecked(false);
                   ui->radioButton_25->setChecked(false);
                   ui->radioButton_26->setChecked(false);
                   ui->radioButton_27->setChecked(false);
                   ui->radioButton_28->setChecked(false);
                   ui->radioButton_29->setChecked(true);
                   ui->radioButton_30->setChecked(false);
                   ui->radioButton_31->setChecked(false);
               }
            else if ( cantidad12 == "2")
               {
                   ui->radioButton_20->setChecked(false);
                   ui->radioButton_21->setChecked(false);
                   ui->radioButton_23->setChecked(false);
                   ui->radioButton_24->setChecked(false);
                   ui->radioButton_25->setChecked(false);
                   ui->radioButton_26->setChecked(false);
                   ui->radioButton_27->setChecked(false);
                   ui->radioButton_28->setChecked(false);
                   ui->radioButton_29->setChecked(false);
                   ui->radioButton_30->setChecked(true);
                   ui->radioButton_31->setChecked(false);
               }
            else if ( cantidad13 == "2")
               {
                   ui->radioButton_20->setChecked(false);
                   ui->radioButton_21->setChecked(false);
                   ui->radioButton_23->setChecked(false);
                   ui->radioButton_24->setChecked(false);
                   ui->radioButton_25->setChecked(false);
                   ui->radioButton_26->setChecked(false);
                   ui->radioButton_27->setChecked(false);
                   ui->radioButton_28->setChecked(false);
                   ui->radioButton_29->setChecked(false);
                   ui->radioButton_30->setChecked(false);
                   ui->radioButton_31->setChecked(true);
               }
        }
        if (i==2)
        {
            QSqlQuery query14(db);
            query14.exec("SELECT tamano1 FROM Opcion1 WHERE id=2");
            query14.first();
            if (query14.isValid())
                cantidad14=query14.value(0).toString();
            QSqlQuery query15(db);
            query15.exec("SELECT tamano2 FROM Opcion1 WHERE id=2");
            query15.first();
            if (query15.isValid())
                cantidad15=query15.value(0).toString();
            QSqlQuery query16(db);
            query16.exec("SELECT tamano3 FROM Opcion1 WHERE id=2");
            query16.first();
            if (query16.isValid())
                cantidad16=query16.value(0).toString();
            QSqlQuery query17(db);
            query17.exec("SELECT tamano4 FROM Opcion1 WHERE id=2");
            query17.first();
            if (query17.isValid())
                cantidad17=query17.value(0).toString();
            QSqlQuery query18(db);
            query18.exec("SELECT tamano5 FROM Opcion1 WHERE id=2");
            query18.first();
            if (query18.isValid())
                cantidad18=query18.value(0).toString();
            if ( cantidad14 == "2")
               {
                   ui->radioButton_22->setChecked(true);
                   ui->radioButton_32->setChecked(false);
                   ui->radioButton_33->setChecked(false);
                   ui->radioButton_34->setChecked(false);
                   ui->radioButton_35->setChecked(false);
               }
            else if ( cantidad15 == "2")
               {
                   ui->radioButton_22->setChecked(false);
                   ui->radioButton_32->setChecked(true);
                   ui->radioButton_33->setChecked(false);
                   ui->radioButton_34->setChecked(false);
                   ui->radioButton_35->setChecked(false);
               }
            else if ( cantidad16 == "2")
               {
                   ui->radioButton_22->setChecked(false);
                   ui->radioButton_32->setChecked(false);
                   ui->radioButton_33->setChecked(true);
                   ui->radioButton_34->setChecked(false);
                   ui->radioButton_35->setChecked(false);
               }
            else if ( cantidad17 == "2")
               {
                   ui->radioButton_22->setChecked(false);
                   ui->radioButton_32->setChecked(false);
                   ui->radioButton_33->setChecked(false);
                   ui->radioButton_34->setChecked(true);
                   ui->radioButton_35->setChecked(false);
               }
            else if ( cantidad18 == "2")
               {
                   ui->radioButton_22->setChecked(false);
                   ui->radioButton_32->setChecked(false);
                   ui->radioButton_33->setChecked(false);
                   ui->radioButton_34->setChecked(false);
                   ui->radioButton_35->setChecked(true);
               }
        }
        if (i==3)
        {
            QSqlQuery query19(db);
            query19.exec("SELECT Velocidad2x FROM Opcion4 WHERE id=2");
            query19.first();
            if (query19.isValid())
                cantidad19=query19.value(0).toString();
            QSqlQuery query20(db);
            query20.exec("SELECT Velocidad4x FROM Opcion4 WHERE id=2");
            query20.first();
            if (query20.isValid())
                cantidad20=query20.value(0).toString();
            QSqlQuery query21(db);
            query21.exec("SELECT Velocidad8x FROM Opcion4 WHERE id=2");
            query21.first();
            if (query21.isValid())
                cantidad21=query21.value(0).toString();
            QSqlQuery query22(db);
            query22.exec("SELECT Velocidad16x FROM Opcion4 WHERE id=2");
            query22.first();
            if (query22.isValid())
                cantidad22=query22.value(0).toString();
            QSqlQuery query23(db);
            query23.exec("SELECT Velocidad32x FROM Opcion4 WHERE id=2");
            query23.first();
            if (query23.isValid())
                cantidad23=query23.value(0).toString();
            if ( cantidad19 == "2")
               {
                   ui->radioButton_36->setChecked(true);
                   ui->radioButton_37->setChecked(false);
                   ui->radioButton_38->setChecked(false);
                   ui->radioButton_39->setChecked(false);
                   ui->radioButton_40->setChecked(false);
               }
            else if ( cantidad20 == "2")
               {
                   ui->radioButton_36->setChecked(false);
                   ui->radioButton_37->setChecked(true);
                   ui->radioButton_38->setChecked(false);
                   ui->radioButton_39->setChecked(false);
                   ui->radioButton_40->setChecked(false);
               }
            else if ( cantidad21 == "2")
               {
                   ui->radioButton_36->setChecked(false);
                   ui->radioButton_37->setChecked(false);
                   ui->radioButton_38->setChecked(true);
                   ui->radioButton_39->setChecked(false);
                   ui->radioButton_40->setChecked(false);
               }
            else if ( cantidad22 == "2")
               {
                   ui->radioButton_36->setChecked(false);
                   ui->radioButton_37->setChecked(false);
                   ui->radioButton_38->setChecked(false);
                   ui->radioButton_39->setChecked(true);
                   ui->radioButton_40->setChecked(false);
               }
            else if ( cantidad23 == "2")
               {
                   ui->radioButton_36->setChecked(false);
                   ui->radioButton_37->setChecked(false);
                   ui->radioButton_38->setChecked(false);
                   ui->radioButton_39->setChecked(false);
                   ui->radioButton_40->setChecked(true);
               }
        }
        if (i==4)
        {
            QSqlQuery query24(db);
            query24.exec("SELECT Numero1,Numero2,Numero3 FROM Opcion3 WHERE id=2");
            query24.first();
            if (query24.isValid())
            {
                cantidad24=query24.value(0).toString();
                cantidad25=query24.value(1).toString();
                cantidad26=query24.value(2).toString();
            }
            ui->lineEdit->setText(cantidad24);
            ui->lineEdit_2->setText(cantidad25);
            ui->lineEdit_3->setText(cantidad26);
            drakeSistema drake;
            Cdrom = drake.getCdrom();
            ui->textEdit->append(Cdrom);
        }
        if (i==5)
        {            
            QSqlQuery query25(db);
            query25.exec("SELECT i480 FROM Opcion5 WHERE id=2");
            query25.first();
            if (query25.isValid())
                cantidad27=query25.value(0).toString();
            QSqlQuery query26(db);
            query26.exec("SELECT i576 FROM Opcion5 WHERE id=2");
            query26.first();
            if (query26.isValid())
                cantidad28=query26.value(0).toString();
            QSqlQuery query27(db);
            query27.exec("SELECT i2_576 FROM Opcion5 WHERE id=2");
            query27.first();
            if (query27.isValid())
                cantidad29=query27.value(0).toString();
            QSqlQuery query28(db);
            query28.exec("SELECT p720 FROM Opcion5 WHERE id=2");
            query28.first();
            if (query28.isValid())
                cantidad30=query28.value(0).toString();
            QSqlQuery query29(db);
            query29.exec("SELECT p1080 FROM Opcion5 WHERE id=2");
            query29.first();
            if (query29.isValid())
                cantidad31=query29.value(0).toString();
            QSqlQuery query30(db);
            query30.exec("SELECT kapy FROM Opcion5 WHERE id=2");
            query30.first();
            if (query30.isValid())
                cantidad32=query30.value(0).toString();
            if ( cantidad27 == "2")
               {
                   ui->radioButton_4->setChecked(true);
                   ui->radioButton_5->setChecked(false);
                   ui->radioButton_6->setChecked(false);
                   ui->radioButton_7->setChecked(false);
                   ui->radioButton_8->setChecked(false);
                   ui->radioButton_9->setChecked(false);
               }
            else if ( cantidad28 == "2")
               {
                   ui->radioButton_4->setChecked(false);
                   ui->radioButton_5->setChecked(true);
                   ui->radioButton_6->setChecked(false);
                   ui->radioButton_7->setChecked(false);
                   ui->radioButton_8->setChecked(false);
                   ui->radioButton_9->setChecked(false);
               }
            else if ( cantidad29 == "2")
               {
                   ui->radioButton_4->setChecked(false);
                   ui->radioButton_5->setChecked(false);
                   ui->radioButton_6->setChecked(true);
                   ui->radioButton_7->setChecked(false);
                   ui->radioButton_8->setChecked(false);
                   ui->radioButton_9->setChecked(false);
               }
            else if ( cantidad30 == "2")
               {
                   ui->radioButton_4->setChecked(false);
                   ui->radioButton_5->setChecked(false);
                   ui->radioButton_6->setChecked(false);
                   ui->radioButton_7->setChecked(true);
                   ui->radioButton_8->setChecked(false);
                   ui->radioButton_9->setChecked(false);
               }
            else if ( cantidad31 == "2")
               {
                   ui->radioButton_4->setChecked(false);
                   ui->radioButton_5->setChecked(false);
                   ui->radioButton_6->setChecked(false);
                   ui->radioButton_7->setChecked(false);
                   ui->radioButton_8->setChecked(true);
                   ui->radioButton_9->setChecked(false);
               }
            else if ( cantidad32 == "2")
               {
                   ui->radioButton_4->setChecked(false);
                   ui->radioButton_5->setChecked(false);
                   ui->radioButton_6->setChecked(false);
                   ui->radioButton_7->setChecked(false);
                   ui->radioButton_8->setChecked(false);
                   ui->radioButton_9->setChecked(true);
               }
        }
        if (i==6)
        {
            QSqlQuery query31(db);
            query31.exec("SELECT inicio FROM Miscelanea WHERE id=2");
            query31.first();
            if (query31.isValid())
                cantidad33=query31.value(0).toString();
            QSqlQuery query52(db);
            query52.exec("SELECT Defecto FROM Miscelanea WHERE id=2");
            query52.first();
            if (query52.isValid())
                cantidad52=query52.value(0).toString();
            QSqlQuery query53(db);
            query53.exec("SELECT Dependencias FROM Miscelanea WHERE id=2");
            query53.first();
            if (query53.isValid())
                cantidad54=query53.value(0).toString();
            if ( cantidad33 == "2")
                ui->checkBox->setChecked(true);
            else
                ui->checkBox->setChecked(false);
            if ( cantidad52 == "2")
                ui->checkBox_2->setChecked(true);
            else
                ui->checkBox_2->setChecked(false);
            if ( cantidad54 == "2")
                ui->checkBox_3->setChecked(true);
            else
                ui->checkBox_3->setChecked(false);
        }
        if (i==7)
        {
            QSqlQuery query32(db);
            query32.exec("SELECT tiempo120 FROM Parental WHERE id=2");
            query32.first();
            if (query32.isValid())
                cantidad34=query32.value(0).toString();
            QSqlQuery query33(db);
            query33.exec("SELECT tiempo90 FROM Parental WHERE id=2");
            query33.first();
            if (query33.isValid())
                cantidad35=query33.value(0).toString();
            QSqlQuery query34(db);
            query34.exec("SELECT tiempo60 FROM Parental WHERE id=2");
            query34.first();
            if (query34.isValid())
                cantidad36=query34.value(0).toString();
            QSqlQuery query35(db);
            query35.exec("SELECT tiempo30 FROM Parental WHERE id=2");
            query35.first();
            if (query35.isValid())
                cantidad37=query35.value(0).toString();
            if ( cantidad34 == "2")
               {
                ui->radioButton_10->setChecked(false);
                ui->radioButton_11->setChecked(false);
                ui->radioButton_12->setChecked(true);
                ui->radioButton_13->setChecked(false);
               }
            else if ( cantidad35 == "2")
               {
                ui->radioButton_10->setChecked(false);
                ui->radioButton_11->setChecked(false);
                ui->radioButton_12->setChecked(false);
                ui->radioButton_13->setChecked(true);
               }
            else if ( cantidad36 == "2")
               {
                ui->radioButton_10->setChecked(false);
                ui->radioButton_11->setChecked(true);
                ui->radioButton_12->setChecked(false);
                ui->radioButton_13->setChecked(false);
               }
            else if ( cantidad37 == "2")
               {
                ui->radioButton_10->setChecked(true);
                ui->radioButton_11->setChecked(false);
                ui->radioButton_12->setChecked(false);
                ui->radioButton_13->setChecked(false);
               }
        }
        if (i==8)
        {
            QSqlQuery query36(db);
            query36.exec("SELECT essid FROM wifi WHERE id=2");
            query36.first();
            if (query36.isValid())
                cantidad38=query36.value(0).toString();
            ui->lineEdit_4->setText(""+cantidad38+"");
        }
        if (i==9)
        {
            QSqlQuery query37(db);
            query37.exec("SELECT conexion FROM wifi WHERE id=2");
            query37.first();
            if (query37.isValid())
                cantidad39=query37.value(0).toString();
            ui->lineEdit_6->setText(""+cantidad39+"");
        }
        if (i==11)
        {
            QSqlQuery query38(db);
            query38.exec("SELECT conexion FROM ethernet WHERE id=2");
            query38.first();
            if (query38.isValid())
                cantidad40=query38.value(0).toString();
            ui->lineEdit_5->setText(""+cantidad40+"");
        }
        if (i==12)
        {
            QSqlQuery query39(db);
            query39.exec("SELECT ethernet FROM red WHERE id=2");
            query39.first();
            if (query39.isValid())
                cantidad41=query39.value(0).toString();
            QSqlQuery query40(db);
            query40.exec("SELECT wifi FROM red WHERE id=2");
            query40.first();
            if (query40.isValid())
            cantidad42=query40.value(0).toString();
            if ( cantidad41 == "2")
               {
                ui->radioButton_14->setChecked(true);
                ui->radioButton_15->setChecked(false);
               }
            else if ( cantidad42 == "2")
               {
                ui->radioButton_14->setChecked(false);
                ui->radioButton_15->setChecked(true);
               }
        }
        if (i==13)
        {
            QSqlQuery query41(db);
            query41.exec("SELECT spanish FROM Idioma WHERE id=2");
            query41.first();
            if (query41.isValid())
                cantidad43=query41.value(0).toString();
            QSqlQuery query42(db);
            query42.exec("SELECT english FROM Idioma WHERE id=2");
            query42.first();
            if (query42.isValid())
                cantidad44=query42.value(0).toString();
            if ( cantidad43 == "2")
               {
                ui->radioButton_16->setChecked(true);
                ui->radioButton_17->setChecked(false);
               }
            else if ( cantidad44 == "2")
               {
                ui->radioButton_16->setChecked(false);
                ui->radioButton_17->setChecked(true);
               }
        }
        if (i==14)
        {
            QSqlQuery query43(db);
            query43.exec("SELECT vlc FROM Video WHERE id=2");
            query43.first();
            if (query43.isValid())
                cantidad45=query43.value(0).toString();
            QSqlQuery query44(db);
            query44.exec("SELECT parole FROM Video WHERE id=2");
            query44.first();
            if (query44.isValid())
                cantidad46=query44.value(0).toString();
            if ( cantidad45 == "2")
               {
                ui->radioButton_18->setChecked(true);
                ui->radioButton_19->setChecked(false);
               }
            else if ( cantidad46 == "2")
               {
                ui->radioButton_18->setChecked(false);
                ui->radioButton_19->setChecked(true);
               }
        }
        if (i==15)
        {
            QSqlQuery query47(db);
            query47.exec("SELECT Fuente FROM Font WHERE id=2");
            query47.first();
            if (query47.isValid())
                cantidad47=query47.value(0).toString();
            QSqlQuery query48(db);
            query48.exec("SELECT Estilo FROM Font WHERE id=2");
            query48.first();
            if (query48.isValid())
                cantidad48=query48.value(0).toString();
            QSqlQuery query49(db);
            query49.exec("SELECT Talla FROM Font WHERE id=2");
            query49.first();
            if (query49.isValid())
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
        }
        if (i==16)
        {
            Localizar = getRpm("id3v2");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                    ui->label_184->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "id3v2";
                QString Value = getPack1(Valor);
                ui->label_184->setText(QString::fromUtf8(Value));
            }
        }
        if (i==17)
        {
            Localizar = getRpm("zenity");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_19->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "zenity";
                QString Value = getPack1(Valor);
                ui->label_19->setText(QString::fromUtf8(Value));
            }
        }
        if (i==18)
        {
            Localizar = getRpm("sudo");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_21->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "sudo";
                QString Value = getPack1(Valor);
                ui->label_21->setText(QString::fromUtf8(Value));
            }
        }
        if (i==19)
        {
            Localizar = getRpm("kwrite");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_23->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "kwrite";
                QString Value = getPack1(Valor);
                ui->label_23->setText(QString::fromUtf8(Value));
            }
        }
        if (i==20)
        {
            Localizar = getRpm("ndiswrapper");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_25->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "ndiswrapper";
                QString Value = getPack1(Valor);
                ui->label_25->setText(QString::fromUtf8(Value));
            }
        }
        if (i==21)
        {
            Localizar = getRpm("photorec");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_27->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "photorec";
                QString Value = getPack1(Valor);
                ui->label_27->setText(QString::fromUtf8(Value));
            }
        }
        if (i==22)
        {
            Localizar = getRpm("testdisk");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_29->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "testdisk";
                QString Value = getPack1(Valor);
                ui->label_29->setText(QString::fromUtf8(Value));
            }
        }
        if (i==23)
        {
            Localizar = getRpm("ntfsconfig");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_31->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "ntfsconfig";
                QString Value = getPack1(Valor);
                ui->label_31->setText(QString::fromUtf8(Value));
            }
        }
        if (i==24)
        {
            Localizar = getRpm("cdparanoia");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_33->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "cdparanoia";
                QString Value = getPack1(Valor);
                ui->label_33->setText(QString::fromUtf8(Value));
            }
        }
        if (i==25)
        {
            Localizar = getRpm("lame");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_35->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "lame";
                QString Value = getPack1(Valor);
                ui->label_35->setText(QString::fromUtf8(Value));
            }
        }
        if (i==26)
        {
            Localizar = getRpm("dvdauthor");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_37->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "dvdauthor";
                QString Value = getPack1(Valor);
                ui->label_37->setText(QString::fromUtf8(Value));
            }
        }
        if (i==27)
        {
            Localizar = getRpm("parole");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_39->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "parole";
                QString Value = getPack1(Valor);
                ui->label_39->setText(QString::fromUtf8(Value));
            }
        }
        if (i==28)
        {
            Localizar = getRpm("cdrkit");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_41->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "cdrkit";
                QString Value = getPack1(Valor);
                ui->label_41->setText(QString::fromUtf8(Value));
            }
        }
        if (i==29)
        {
            Localizar = getRpm("tar");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_43->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "tar";
                QString Value = getPack1(Valor);
                ui->label_43->setText(QString::fromUtf8(Value));
            }
        }
        if (i==30)
        {
            Localizar = getRpm("alien");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_45->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "alien";
                QString Value = getPack1(Valor);
                ui->label_45->setText(QString::fromUtf8(Value));
            }
        }
        if (i==31)
        {
            Localizar = getRpm("urpmi");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_47->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "urpmi";
                QString Value = getPack1(Valor);
                ui->label_47->setText(QString::fromUtf8(Value));
            }
        }
        if (i==32)
        {
            Localizar = getRpm("fakeroot");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_49->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "fakeroot";
                QString Value = getPack1(Valor);
                ui->label_49->setText(QString::fromUtf8(Value));
            }
        }
        if (i==33)
        {
            Localizar = getRpm("rpmdrake");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_51->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "rpmdrake";
                QString Value = getPack1(Valor);
                ui->label_51->setText(QString::fromUtf8(Value));
            }
        }
        if (i==34)
        {
            Localizar = getRpm("mkvtoolnix");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_53->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "mkvtoolnix";
                QString Value = getPack1(Valor);
                ui->label_53->setText(QString::fromUtf8(Value));
            }
        }
        if (i==35)
        {
            Localizar = getRpm("clamav");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_55->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "clamav";
                QString Value = getPack1(Valor);
                ui->label_55->setText(QString::fromUtf8(Value));
            }
        }
        if (i==36)
        {
            Localizar = getRpm("dolphin");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_59->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "dolphin";
                QString Value = getPack1(Valor);
                ui->label_59->setText(QString::fromUtf8(Value));
            }
        }
        if (i==37)
        {
            Localizar = getRpm("unrar");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_61->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "unrar";
                QString Value = getPack1(Valor);
                ui->label_61->setText(QString::fromUtf8(Value));
            }
        }
        if (i==38)
        {
            Localizar = getRpm("gnomeutils");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_63->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "gnomeutils";
                QString Value = getPack1(Valor);
                ui->label_63->setText(QString::fromUtf8(Value));
            }
        }
        if (i==39)
        {
            Localizar = getRpm("ffmpeg");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_65->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "ffmpeg";
                QString Value = getPack1(Valor);
                ui->label_65->setText(QString::fromUtf8(Value));
            }
        }
        if (i==40)
        {
            Localizar = getRpm("mencoder");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_67->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "mencoder";
                QString Value = getPack1(Valor);
                ui->label_67->setText(QString::fromUtf8(Value));
            }
        }
        if (i==41)
        {
            Localizar = getRpm("transcode");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_69->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "transcode";
                QString Value = getPack1(Valor);
                ui->label_69->setText(QString::fromUtf8(Value));
            }
        }
        if (i==42)
        {
            Localizar = getRpm("convmv");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_71->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "convmv";
                QString Value = getPack1(Valor);
                ui->label_71->setText(QString::fromUtf8(Value));
            }
        }
        if (i==43)
        {
            Localizar = getRpm("cdrdao");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_73->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "cdrdao";
                QString Value = getPack1(Valor);
                ui->label_73->setText(QString::fromUtf8(Value));
            }
        }
        if (i==44)
        {
            Localizar = getRpm("unzip");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_75->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "unzip";
                QString Value = getPack1(Valor);
                ui->label_75->setText(QString::fromUtf8(Value));
            }
        }
        if (i==45)
        {
            Localizar = getRpm("dalle");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_77->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "dalle";
                QString Value = getPack1(Valor);
                ui->label_77->setText(QString::fromUtf8(Value));
            }
        }
        if (i==46)
        {
            Localizar = getRpm("lsdvd");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_79->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "lsdvd";
                QString Value = getPack1(Valor);
                ui->label_79->setText(QString::fromUtf8(Value));
            }
        }
        if (i==47)
        {
            Localizar = getRpm("vcdimager");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_81->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "vcdimager";
                QString Value = getPack1(Valor);
                ui->label_81->setText(QString::fromUtf8(Value));
            }
        }
        if (i==48)
        {
            Localizar = getRpm("gzip");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_83->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "gzip";
                QString Value = getPack1(Valor);
                ui->label_83->setText(QString::fromUtf8(Value));
            }
        }
        if (i==49)
        {
            Localizar = getRpm("imagemagick");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_85->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "imagemagick";
                QString Value = getPack1(Valor);
                ui->label_85->setText(QString::fromUtf8(Value));
            }
        }
        if (i==50)
        {
            Localizar = getRpm("dvd+rw-tools");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_87->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "dvd+rw-tools";
                QString Value = getPack1(Valor);
                ui->label_87->setText(QString::fromUtf8(Value));
            }
        }
        if (i==51)
        {
            Localizar = getRpm("ccd2iso");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_89->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "ccd2iso";
                QString Value = getPack1(Valor);
                ui->label_89->setText(QString::fromUtf8(Value));
            }
        }
        if (i==52)
        {
            Localizar = getRpm("mdf2iso");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_91->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "mdf2iso";
                QString Value = getPack1(Valor);
                ui->label_91->setText(QString::fromUtf8(Value));
            }
        }
        if (i==53)
        {
            Localizar = getRpm("cdi2iso");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_93->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "cdi2iso";
                QString Value = getPack1(Valor);
                ui->label_93->setText(QString::fromUtf8(Value));
            }
        }
        if (i==54)
        {
            Localizar = getRpm("nrg2iso");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_95->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "nrg2iso";
                QString Value = getPack1(Valor);
                ui->label_95->setText(QString::fromUtf8(Value));
            }
        }
        if (i==55)
        {
            Localizar = getRpm("libnotify");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_97->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "libnotify";
                QString Value = getPack1(Valor);
                ui->label_97->setText(QString::fromUtf8(Value));
            }
        }
        if (i==56)
        {
            Localizar = getRpm("id3lib");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_101->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "id3lib";
                QString Value = getPack1(Valor);
                ui->label_101->setText(QString::fromUtf8(Value));
            }
        }
        if (i==57)
        {
            Localizar = getRpm("nmap");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_103->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "nmap";
                QString Value = getPack1(Valor);
                ui->label_103->setText(QString::fromUtf8(Value));
            }
        }
        if (i==58)
        {
            Localizar = getRpm("iptables");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_105->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "iptables";
                QString Value = getPack1(Valor);
                ui->label_105->setText(QString::fromUtf8(Value));
            }
        }
        if (i==59)
        {
            Localizar = getRpm("konsole");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_135->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "konsole";
                QString Value = getPack1(Valor);
                ui->label_135->setText(QString::fromUtf8(Value));
            }
        }
        if (i==60)
        {
            Localizar = getRpm("vlc");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_116->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "vlc";
                QString Value = getPack1(Valor);
                ui->label_116->setText(QString::fromUtf8(Value));
            }
        }
        if (i==61)
        {
            if (ui->radioButton_14->isChecked())
            {
                ui->groupBox_10->setEnabled(false);
                ui->groupBox_9->setEnabled(true);
            }
            if (ui->radioButton_15->isChecked())
            {
                ui->groupBox_9->setEnabled(false);
                ui->groupBox_10->setEnabled(true);
            }
        }
        if (i==62)
        {
            Localizar = getRpm("grub2");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_137->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "grub2";
                QString Value = getPack1(Valor);
                ui->label_137->setText(QString::fromUtf8(Value));
            }
        }
        if (i==63)
        {
            Localizar = getRpm("syslinux");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_139->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "syslinux";
                QString Value = getPack1(Valor);
                ui->label_139->setText(QString::fromUtf8(Value));
            }
        }
        if (i==64)
        {
            Localizar = getRpm("grub");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_140->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "grub";
                QString Value = getPack1(Valor);
                ui->label_140->setText(QString::fromUtf8(Value));
            }
        }
        if (i==65)
        {
            Localizar = getRpm("file-roller");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_143->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "file-roller";
                QString Value = getPack1(Valor);
                ui->label_143->setText(QString::fromUtf8(Value));
            }
        }
        if (i==66)
        {
            Localizar = getRpm("mtools");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_144->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "mtools";
                QString Value = getPack1(Valor);
                ui->label_144->setText(QString::fromUtf8(Value));
            }
        }
        if (i==67)
        {
            Localizar = getRpm("qemu");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_146->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "qemu";
                QString Value = getPack1(Valor);
                ui->label_146->setText(QString::fromUtf8(Value));
            }
        }
        if (i==68)
        {
            QString konsola;
            QSqlQuery consola(db);
            consola.exec("SELECT Fondo FROM Consola WHERE id=2");
            consola.first();
            if (consola.isValid())
                konsola=consola.value(0).toString();
            if ( konsola == "2")
            {
                ui->radioButton_42->setChecked(true);
                ui->radioButton_41->setChecked(false);
            }
            else
            {
                ui->radioButton_42->setChecked(false);
                ui->radioButton_41->setChecked(true);
            }
        }
        if (i==69)
        {
            Localizar = getRpm("gcstar");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_148->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "gcstar";
                QString Value = getPack1(Valor);
                ui->label_148->setText(QString::fromUtf8(Value));
            }
        }
        if (i==70)
        {
            Localizar = getRpm("x11vnc");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_150->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "x11vnc";
                QString Value = getPack1(Valor);
                ui->label_150->setText(QString::fromUtf8(Value));
            }
        }
        if (i==71)
        {
            Localizar = getRpm("mutt");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_152->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "mutt";
                QString Value = getPack1(Valor);
                ui->label_152->setText(QString::fromUtf8(Value));
            }
        }
        if (i==72)
        {
            Localizar = getRpm("sendmail");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_155->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "sendmail";
                QString Value = getPack1(Valor);
                ui->label_155->setText(QString::fromUtf8(Value));
            }
        }
        if (i==73)
        {
            Localizar = getRpm("ssmtp");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_157->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "ssmtp";
                QString Value = getPack1(Valor);
                ui->label_157->setText(QString::fromUtf8(Value));
            }
        }
        if (i==74)
        {
            Localizar = getRpm("tigervnc");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_158->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "tigervnc";
                QString Value = getPack1(Valor);
                ui->label_158->setText(QString::fromUtf8(Value));
            }
        }
        if (i==75)
        {
            Localizar = getRpm("transmission-cli");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_160->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "transmission-cli";
                QString Value = getPack1(Valor);
                ui->label_160->setText(QString::fromUtf8(Value));
            }
        }
        if (i==76)
        {
            QSqlQuery query51(db);
            query51.exec("SELECT Tipo_Menu FROM Menus WHERE id=2");
            query51.first();
            if (query51.isValid())
                cantidad55=query51.value(0).toString();
            if (cantidad55 == "0")
                ui->radioButton_43->setChecked(true);
            else if (cantidad55 == "1")
                ui->radioButton_44->setChecked(true);
            else if (cantidad55 == "2")
                ui->radioButton_45->setChecked(true);
        }
        if (i==77)
        {
            QSqlQuery query52(db);
            query52.exec("SELECT Aplicacion FROM Aplicacion WHERE id=2");
            query52.first();
            if (query52.isValid())
                cantidad56=query52.value(0).toString();
            if (cantidad56 == "0")
                ui->radioButton_46->setChecked(true);
            else if (cantidad56 == "1")
                ui->radioButton_47->setChecked(true);
        }
        if (i==78)
        {
            QSqlQuery query53(db);
            query53.exec("SELECT visionado FROM chat WHERE id=2");
            query53.first();
            if (query53.isValid())
                cantidad57=query53.value(0).toString();
            if (cantidad57 == "0")
                ui->radioButton_48->setChecked(true);
            else if (cantidad57 == "1")
                ui->radioButton_50->setChecked(true);
        }
        if (i==79)
        {
            Localizar = getRpm("firefox");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_165->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "firefox";
                QString Value = getPack1(Valor);
                ui->label_165->setText(QString::fromUtf8(Value));
            }
        }
        if (i==80)
        {
            QSqlQuery query54(db);
            query54.exec("SELECT Aspecto FROM Formato WHERE id=2");
            query54.first();
            if (query54.isValid())
                cantidad58=query54.value(0).toString();
            if (cantidad58 == "0")
                ui->radioButton_49->setChecked(true);
            else if (cantidad58 == "1")
                ui->radioButton_51->setChecked(true);
        }
        if (i==81)
        {
            int Valor=0;
            QSqlQuery query55(db);
            query55.exec("SELECT Style FROM Estilo WHERE id=2");
            query55.first();
            if (query55.isValid())
                cantidad59=query55.value(0).toString();
            for(int a=0;a<ui->comboBox_3->count();a++)
            {
                QString Comparar = ui->comboBox_3->text(a);
                if (cantidad59 == Comparar)
                {
                    ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(cantidad59));
                    Valor = 0;
                    break;
                }
                Valor = 1;
            }
            if (Valor == 1)
                ui->comboBox_3->setCurrentIndex(0);
        }
        if (i==82)
        {
            Localizar = getRpm("dvdbackup");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_168->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "dvdbackup";
                QString Value = getPack1(Valor);
                ui->label_168->setText(QString::fromUtf8(Value));
            }
        }
        if (i==83)
        {
            Localizar = getRpm("gcc");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_172->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "gcc";
                QString Value = getPack1(Valor);
                ui->label_172->setText(QString::fromUtf8(Value));
            }
        }
        if (i==84)
        {
            Localizar = getRpm("make");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_348->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "make";
                QString Value = getPack1(Valor);
                ui->label_348->setText(QString::fromUtf8(Value));
            }
        }
        if (i==85)
        {
            QString Valor;
            if (arqt =="x86_64")
            {
                Valor= "lib64ncurses-devel";
                Localizar = getRpm(Valor);
            }
            else
            {
                Valor= "libncurses-devel";
                Localizar = getRpm(Valor);
            }
            ui->label_350->setText(Valor);
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_349->setText(QString::fromUtf8("..."));
            else
            {
                QString Value = getPack1(Valor);
                ui->label_349->setText(QString::fromUtf8(Value));                
            }
        }
        if (i==86)
        {
            QString Valor;
            if (arqt =="x86_64")
            {
                Valor= "lib64ncursesw-devel";
                Localizar = getRpm(Valor);
            }
            else
            {
                Valor= "libncursesw-devel";
                Localizar = getRpm(Valor);
            }
            ui->label_351->setText(Valor);
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_352->setText(QString::fromUtf8("..."));
            else
            {
                QString Value = getPack1(Valor);
                ui->label_352->setText(QString::fromUtf8(Value));                
            }
        }
        if (i==87)
        {
            QSqlQuery query50(db);
            query50.exec("SELECT ColorTexto FROM Color WHERE id=2");
            query50.first();
            if (query50.isValid())
                cantidad50=query50.value(0).toString();
            QSqlQuery query51(db);
            query51.exec("SELECT ColorFondo FROM Color WHERE id=2");
            query51.first();
            if (query51.isValid())
                cantidad51=query51.value(0).toString();
            ui->textEdit_3->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            ui->label_126->setText(cantidad47);
            ui->label_126->setStyleSheet("font-family: "+cantidad47+"");
            ui->label_127->setText(cantidad48);
            ui->label_127->setStyleSheet("font-style: "+DatoTalla+"; font-weight: "+DatoNegro+"");
            ui->label_128->setText(cantidad49);
            ui->label_128->setStyleSheet("font-size: "+cantidad49+"pt");
            ui->label_131->setText(cantidad50);
            ui->label_131->setStyleSheet("color: "+cantidad50+"");
            ui->label_133->setText(cantidad51);
            ui->label_133->setStyleSheet("background-color: "+cantidad51+"");
            ui->textEdit_3->setText(tr("<center>Esto es una prueba de fuente, estilo, colores y talla"));
            ui->fontComboBox->setCurrentIndex(ui->fontComboBox->findText(cantidad47));
            ui->comboBox->setCurrentIndex(ui->comboBox->findText(cantidad48));
            ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(cantidad49));
            ui->pushButton_9->setStyleSheet("color: "+cantidad50+"");
            ui->pushButton_10->setStyleSheet("background-color: "+cantidad51+"");
            Stilo = "A";
        }
        if (i==88)
        {
            QSqlQuery query25(db);
            query25.exec("SELECT activo,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10 FROM Ecualizador WHERE id=2");
            query25.first();
            if (query25.isValid())
            {
                cantidad60=query25.value(0).toString();
                banda1=query25.value(1).toString();
                banda2=query25.value(2).toString();
                banda3=query25.value(3).toString();
                banda4=query25.value(4).toString();
                banda5=query25.value(5).toString();
                banda6=query25.value(6).toString();
                banda7=query25.value(7).toString();
                banda8=query25.value(8).toString();
                banda9=query25.value(9).toString();
                banda10=query25.value(10).toString();
            }
            if (cantidad60 == "Si")
                ui->checkBox_4->setChecked(true);
            else
                ui->checkBox_4->setChecked(false);
            ui->verticalSlider->setValue(banda1.toInt());
            ui->verticalSlider_2->setValue(banda2.toInt());
            ui->verticalSlider_3->setValue(banda3.toInt());
            ui->verticalSlider_4->setValue(banda4.toInt());
            ui->verticalSlider_5->setValue(banda5.toInt());
            ui->verticalSlider_6->setValue(banda6.toInt());
            ui->verticalSlider_7->setValue(banda7.toInt());
            ui->verticalSlider_8->setValue(banda8.toInt());
            ui->verticalSlider_9->setValue(banda9.toInt());
            ui->verticalSlider_10->setValue(banda10.toInt());
        }
        if (i==89)
        {
            Localizar = getRpm("pulseaudio-utils");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_187->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "pulseaudio-utils";
                QString Value = getPack1(Valor);
                ui->label_187->setText(QString::fromUtf8(Value));
            }
        }
        if (i==90)
        {
            QString pais;
            QSqlQuery Pais(db);
            Pais.exec("SELECT Tipo FROM Pais WHERE id=1");
            Pais.first();
            if (Pais.isValid())
                pais=Pais.value(0).toString();
            if ( pais == "1")
            {
                ui->radioButton_52->setChecked(true);
                ui->radioButton_53->setChecked(false);
            }
            else if (pais == "2")
            {
                ui->radioButton_52->setChecked(false);
                ui->radioButton_53->setChecked(true);
            }
        }
        if (i==91)
        {
            QString Valor;
            if (arqt =="x86_64")
            {
                Valor= "lib64qrencode-devel";
                Localizar = getRpm(Valor);
            }
            else
            {
                Valor= "libqrencode-devel";
                Localizar = getRpm(Valor);
            }
            ui->label_196->setText(Valor);
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_197->setText(QString::fromUtf8("..."));
            else
            {
                QString Value = getPack1(Valor);
                ui->label_197->setText(QString::fromUtf8(Value));
            }
        }
        if (i==92)
        {
            Localizar = getRpm("bzip2");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_198->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "bzip2";
                QString Value = getPack1(Valor);
                ui->label_198->setText(QString::fromUtf8(Value));
            }
        }
        if (i==93)
        {
            Localizar = getRpm("zip");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_200->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "zip";
                QString Value = getPack1(Valor);
                ui->label_200->setText(QString::fromUtf8(Value));
            }
        }
        if (i==94)
        {
            Localizar = getRpm("zoo");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_202->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "zoo";
                QString Value = getPack1(Valor);
                ui->label_202->setText(QString::fromUtf8(Value));
            }
        }
        if (i==95)
        {
            Localizar = getRpm("arj");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_204->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "arj";
                QString Value = getPack1(Valor);
                ui->label_204->setText(QString::fromUtf8(Value));
            }
        }
        if (i==96)
        {
            Localizar = getRpm("p7zip");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_207->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "p7zip";
                QString Value = getPack1(Valor);
                ui->label_207->setText(QString::fromUtf8(Value));
            }
        }
        if (i==97)
        {
            Localizar = getRpm("rar");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_209->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "rar";
                QString Value = getPack1(Valor);
                ui->label_209->setText(QString::fromUtf8(Value));
            }
        }
        if (i==98)
        {
            Localizar = getRpm("tree");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_210->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "tree";
                QString Value = getPack1(Valor);
                ui->label_210->setText(QString::fromUtf8(Value));
            }
        }
        if (i==99)
        {
            Localizar = getRpm("hexedit");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_213->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "hexedit";
                QString Value = getPack1(Valor);
                ui->label_213->setText(QString::fromUtf8(Value));
            }
        }
        if (i==100)
        {
            Localizar = getRpm("webmin");
            if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
                ui->label_215->setText(QString::fromUtf8("..."));
            else
            {
                QString Valor= "webmin";
                QString Value = getPack1(Valor);
                ui->label_215->setText(QString::fromUtf8(Value));
            }
        }
    }
    progress.setValue(101);
    setUpdatesEnabled(true);
}

void opciones::on_pushButton_clicked()
{
    if ( Save == 0)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, tr(QString::fromUtf8("Guardar cambios")),
                         tr(QString::fromUtf8("<center><b>Guardar cambios</center><p>"
                         "&iquest;Guardar cambios antes de salir?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            on_pushButton_2_clicked();
            close();
        }
        else
            close();
    }
    else
    {
        close();
        QTest::qWait(1000);
    }
}

void opciones::cambiaFila(QModelIndex actual)
{
        int i;
        i=actual.row();
        QModelIndex index;
        index=ui->tableView->model()->index(i,0);
        this->id= index.data().toInt();
        index=ui->tableView->model()->index(i,1);
        ui->lineEdit_7->setText(tr(index.data().toString()));
        this->fila=i;
}

QString opciones::getPack()
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "-qa" << "--queryformat='%{N} '";
    procesoRPM->start("rpm",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res =  QString(Paquete);
    res.chop(1);
    return res;
}

QString opciones::getPack1(QString Valor)
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "-q" << ""+Valor+"";
    procesoRPM->start("rpm",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res =  QString(Paquete);
    res.chop(1);
    return res;
}

void opciones::on_pushButton_2_clicked()
{
    Save = 1;
    QSqlQuery query(db);
    query.exec("SELECT id FROM Opcion WHERE id=2");
    query.first();
    if (query.isValid())
        cantidad=query.value(0).toString();
    fila=1;
    if (cantidad == "2")
    {
        if(ui->radioButton->isChecked())
        {
            QSqlRecord record= Model->record(this->fila);
            record.setValue(0,cantidad.toInt());
            record.setValue(1,"2");
            record.setValue(2,"0");
            record.setValue(3,"0");
            Model->setRecord(this->fila,record);
            Model->submitAll();
        }
        else if(ui->radioButton_2->isChecked())
        {
            QSqlRecord record= Model->record(this->fila);
            record.setValue(0,cantidad.toInt());
            record.setValue(1,"0");
            record.setValue(2,"2");
            record.setValue(3,"0");
            Model->setRecord(this->fila,record);
            Model->submitAll();
        }
        else if(ui->radioButton_3->isChecked())
        {
            QSqlRecord record= Model->record(this->fila);
            record.setValue(0,cantidad.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"2");
            Model->setRecord(this->fila,record);
            Model->submitAll();
        }
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QSqlQuery query1(db);
    query1.exec("SELECT id FROM opcion2 WHERE id=2");
    query1.first();
    if (query1.isValid())
        cantidad1=query1.value(0).toString();
    fila1=1;
    if (cantidad1 == "2")
    {
        if(ui->radioButton_29->isChecked())
        {
            QSqlRecord record= Model1->record(this->fila1);
            record.setValue(0,cantidad1.toInt());
            record.setValue(1,"2");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"0");
            record.setValue(7,"0");
            record.setValue(8,"0");
            record.setValue(9,"0");
            record.setValue(10,"0");
            record.setValue(11,"0");
            Model1->setRecord(this->fila1,record);
            Model1->submitAll();
        }
        else if(ui->radioButton_28->isChecked())
        {
            QSqlRecord record= Model1->record(this->fila1);
            record.setValue(0,cantidad1.toInt());
            record.setValue(1,"0");
            record.setValue(2,"2");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"0");
            record.setValue(7,"0");
            record.setValue(8,"0");
            record.setValue(9,"0");
            record.setValue(10,"0");
            record.setValue(11,"0");
            Model1->setRecord(this->fila1,record);
            Model1->submitAll();
        }
        else if(ui->radioButton_27->isChecked())
        {
            QSqlRecord record= Model1->record(this->fila1);
            record.setValue(0,cantidad1.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"2");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"0");
            record.setValue(7,"0");
            record.setValue(8,"0");
            record.setValue(9,"0");
            record.setValue(10,"0");
            record.setValue(11,"0");
            Model1->setRecord(this->fila1,record);
            Model1->submitAll();
        }
        else if(ui->radioButton_31->isChecked())
        {
            QSqlRecord record= Model1->record(this->fila1);
            record.setValue(0,cantidad1.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"2");
            record.setValue(5,"0");
            record.setValue(6,"0");
            record.setValue(7,"0");
            record.setValue(8,"0");
            record.setValue(9,"0");
            record.setValue(10,"0");
            record.setValue(11,"0");
            Model1->setRecord(this->fila1,record);
            Model1->submitAll();
        }
        else if(ui->radioButton_30->isChecked())
        {
            QSqlRecord record= Model1->record(this->fila1);
            record.setValue(0,cantidad1.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"2");
            record.setValue(6,"0");
            record.setValue(7,"0");
            record.setValue(8,"0");
            record.setValue(9,"0");
            record.setValue(10,"0");
            record.setValue(11,"0");
            Model1->setRecord(this->fila1,record);
            Model1->submitAll();
        }
        else if(ui->radioButton_26->isChecked())
        {
            QSqlRecord record= Model1->record(this->fila1);
            record.setValue(0,cantidad1.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"2");
            record.setValue(7,"0");
            record.setValue(8,"0");
            record.setValue(9,"0");
            record.setValue(10,"0");
            record.setValue(11,"0");
            Model1->setRecord(this->fila1,record);
            Model1->submitAll();
        }
        else if(ui->radioButton_25->isChecked())
        {
            QSqlRecord record= Model1->record(this->fila1);
            record.setValue(0,cantidad1.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"0");
            record.setValue(7,"2");
            record.setValue(8,"0");
            record.setValue(9,"0");
            record.setValue(10,"0");
            record.setValue(11,"0");
            Model1->setRecord(this->fila1,record);
            Model1->submitAll();
        }
        else if(ui->radioButton_24->isChecked())
        {
            QSqlRecord record= Model1->record(this->fila1);
            record.setValue(0,cantidad1.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"2");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"0");
            record.setValue(7,"0");
            record.setValue(8,"2");
            record.setValue(9,"0");
            record.setValue(10,"0");
            record.setValue(11,"0");
            Model1->setRecord(this->fila1,record);
            Model1->submitAll();
        }
        else if(ui->radioButton_23->isChecked())
        {
            QSqlRecord record= Model1->record(this->fila1);
            record.setValue(0,cantidad1.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"2");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"0");
            record.setValue(7,"0");
            record.setValue(8,"0");
            record.setValue(9,"2");
            record.setValue(10,"0");
            record.setValue(11,"0");
            Model1->setRecord(this->fila1,record);
            Model1->submitAll();
        }
        else if(ui->radioButton_21->isChecked())
        {
            QSqlRecord record= Model1->record(this->fila1);
            record.setValue(0,cantidad1.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"0");
            record.setValue(7,"0");
            record.setValue(8,"0");
            record.setValue(9,"0");
            record.setValue(10,"2");
            record.setValue(11,"0");
            Model1->setRecord(this->fila1,record);
            Model1->submitAll();
        }
        else if(ui->radioButton_20->isChecked())
        {
            QSqlRecord record= Model1->record(this->fila1);
            record.setValue(0,cantidad1.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"0");
            record.setValue(7,"0");
            record.setValue(8,"0");
            record.setValue(9,"0");
            record.setValue(10,"0");
            record.setValue(11,"2");
            Model1->setRecord(this->fila1,record);
            Model1->submitAll();
        }
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QSqlQuery query2(db);
    query2.exec("SELECT id FROM opcion1 WHERE id=2");
    query2.first();
    if (query2.isValid())
        cantidad2=query2.value(0).toString();
    fila2=1;
    if (cantidad2 == "2")
    {
        if(ui->radioButton_22->isChecked())
        {
            QSqlRecord record= Model2->record(this->fila2);
            record.setValue(0,cantidad2.toInt());
            record.setValue(1,"2");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            Model2->setRecord(this->fila2,record);
            Model2->submitAll();
        }
        else if(ui->radioButton_32->isChecked())
        {
            QSqlRecord record= Model2->record(this->fila2);
            record.setValue(0,cantidad2.toInt());
            record.setValue(1,"0");
            record.setValue(2,"2");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            Model2->setRecord(this->fila2,record);
            Model2->submitAll();
        }
        else if(ui->radioButton_33->isChecked())
        {
            QSqlRecord record= Model2->record(this->fila2);
            record.setValue(0,cantidad2.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"2");
            record.setValue(4,"0");
            record.setValue(5,"0");
            Model2->setRecord(this->fila2,record);
            Model2->submitAll();
        }
        else if(ui->radioButton_34->isChecked())
        {
            QSqlRecord record= Model2->record(this->fila2);
            record.setValue(0,cantidad2.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"2");
            record.setValue(5,"0");
            Model2->setRecord(this->fila2,record);
            Model2->submitAll();
        }
        else if(ui->radioButton_35->isChecked())
        {
            QSqlRecord record= Model2->record(this->fila2);
            record.setValue(0,cantidad2.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"2");
            Model2->setRecord(this->fila2,record);
            Model2->submitAll();
        }
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QSqlQuery query3(db);
    query3.exec("SELECT id FROM opcion4 WHERE id=2");
    query3.first();
    if (query3.isValid())
        cantidad3=query3.value(0).toString();
    fila3=1;
    if (cantidad3 == "2")
    {
        if(ui->radioButton_36->isChecked())
        {
            QSqlRecord record= Model4->record(this->fila3);
            record.setValue(0,cantidad3.toInt());
            record.setValue(1,"2");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            Model4->setRecord(this->fila3,record);
            Model4->submitAll();
        }
        else if(ui->radioButton_37->isChecked())
        {
            QSqlRecord record= Model4->record(this->fila3);
            record.setValue(0,cantidad3.toInt());
            record.setValue(1,"0");
            record.setValue(2,"2");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            Model4->setRecord(this->fila3,record);
            Model4->submitAll();
        }
        else if(ui->radioButton_38->isChecked())
        {
            QSqlRecord record= Model4->record(this->fila3);
            record.setValue(0,cantidad3.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"2");
            record.setValue(4,"0");
            record.setValue(5,"0");
            Model4->setRecord(this->fila3,record);
            Model4->submitAll();
        }
        else if(ui->radioButton_39->isChecked())
        {
            QSqlRecord record= Model4->record(this->fila3);
            record.setValue(0,cantidad3.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"2");
            record.setValue(5,"0");
            Model4->setRecord(this->fila3,record);
            Model4->submitAll();
        }
        else if(ui->radioButton_40->isChecked())
        {
            QSqlRecord record= Model4->record(this->fila3);
            record.setValue(0,cantidad3.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"2");
            Model4->setRecord(this->fila3,record);
            Model4->submitAll();
        }
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QSqlQuery query4(db);
    query4.exec("SELECT id FROM opcion3 WHERE id=2");
    query4.first();
    if (query4.isValid())
        cantidad4=query4.value(0).toString();
    fila4=1;
    if (cantidad4 == "2")
    {
        QSqlRecord record= Model3->record(this->fila4);
        record.setValue(0,cantidad4.toInt());
        record.setValue(1,ui->lineEdit->text());
        record.setValue(2,ui->lineEdit_2->text());
        record.setValue(3,ui->lineEdit_3->text());
        Model3->setRecord(this->fila4,record);
        Model3->submitAll();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QSqlQuery query5(db);
    query5.exec("SELECT id FROM opcion5 WHERE id=2");
    query5.first();
    if (query5.isValid())
        cantidad5=query5.value(0).toString();
    fila5=1;
    if (cantidad5 == "2")
    {
        if(ui->radioButton_4->isChecked())
        {
            QSqlRecord record= Model5->record(this->fila5);
            record.setValue(0,cantidad5.toInt());
            record.setValue(1,"2");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"0");
            Model5->setRecord(this->fila5,record);
            Model5->submitAll();
        }
        else if(ui->radioButton_5->isChecked())
        {
            QSqlRecord record= Model5->record(this->fila5);
            record.setValue(0,cantidad5.toInt());
            record.setValue(1,"0");
            record.setValue(2,"2");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"0");
            Model5->setRecord(this->fila5,record);
            Model5->submitAll();
        }
        else if(ui->radioButton_6->isChecked())
        {
            QSqlRecord record= Model5->record(this->fila5);
            record.setValue(0,cantidad5.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"2");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"0");
            Model5->setRecord(this->fila5,record);
            Model5->submitAll();
        }
        else if(ui->radioButton_7->isChecked())
        {
            QSqlRecord record= Model5->record(this->fila5);
            record.setValue(0,cantidad5.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"2");
            record.setValue(5,"0");
            record.setValue(6,"0");
            Model5->setRecord(this->fila5,record);
            Model5->submitAll();
        }
        else if(ui->radioButton_8->isChecked())
        {
            QSqlRecord record= Model5->record(this->fila5);
            record.setValue(0,cantidad5.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"2");
            record.setValue(6,"0");
            Model5->setRecord(this->fila5,record);
            Model5->submitAll();
        }
        else if(ui->radioButton_9->isChecked())
        {
            QSqlRecord record= Model5->record(this->fila5);
            record.setValue(0,cantidad5.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            record.setValue(5,"0");
            record.setValue(6,"2");
            Model5->setRecord(this->fila5,record);
            Model5->submitAll();
        }
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QSqlQuery query6(db);
    query6.exec("SELECT id FROM Miscelanea WHERE id=2");
    query6.first();
    if (query6.isValid())
        cantidad6=query6.value(0).toString();
    fila6=1;    
    QString Valor1, Valor2, Valor3;
    if (cantidad6 == "2")
    {
        if(ui->checkBox->isChecked())
        {
            Valor2 = "2";
        }
        else
        {
            Valor2 = "0";
        }
        if(ui->checkBox_2->isChecked())
        {
            Valor1 = "2";
        }
        else
        {
            Valor1 = "0";
        }
        if(ui->checkBox_3->isChecked())
        {
            Valor3 = "2";
        }
        else
        {
            Valor3 = "0";
        }
        QSqlRecord record= Model6->record(this->fila6);
        record.setValue(0,cantidad6.toInt());
        record.setValue(1,Valor1);
        record.setValue(2,Valor2);
        record.setValue(3,Valor3);
        Model6->setRecord(this->fila6,record);
        Model6->submitAll();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QSqlQuery query7(db);
    query7.exec("SELECT id FROM Parental WHERE id=2");
    query7.first();
    if (query7.isValid())
        cantidad7=query7.value(0).toString();
    fila7=1;
    if (cantidad7 == "2")
    {
        if(ui->radioButton_10->isChecked())
        {
            QSqlRecord record= Model7->record(this->fila7);
            record.setValue(0,cantidad7.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"2");
            Model7->setRecord(this->fila7,record);
            Model7->submitAll();
        }
        else if(ui->radioButton_11->isChecked())
        {
            QSqlRecord record= Model7->record(this->fila7);
            record.setValue(0,cantidad7.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"2");
            record.setValue(4,"0");
            Model7->setRecord(this->fila7,record);
            Model7->submitAll();
        }
        else if(ui->radioButton_12->isChecked())
        {
            QSqlRecord record= Model7->record(this->fila7);
            record.setValue(0,cantidad7.toInt());
            record.setValue(1,"2");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"0");
            Model7->setRecord(this->fila7,record);
            Model7->submitAll();
        }
        else if(ui->radioButton_13->isChecked())
        {
            QSqlRecord record= Model7->record(this->fila7);
            record.setValue(0,cantidad7.toInt());
            record.setValue(1,"0");
            record.setValue(2,"2");
            record.setValue(3,"0");
            record.setValue(4,"0");
            Model7->setRecord(this->fila7,record);
            Model7->submitAll();
        }
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QSqlQuery query8(db);
    query8.exec("SELECT id FROM wifi WHERE id=2");
    query8.first();
    if (query8.isValid())
        cantidad8=query8.value(0).toString();
    fila8=1;
    QSqlRecord record= Model8->record(this->fila8);
    record.setValue(0,cantidad8.toInt());
    record.setValue(1,ui->lineEdit_6->text());
    record.setValue(2,ui->lineEdit_4->text());
    Model8->setRecord(this->fila8,record);
    Model8->submitAll();
    QSqlQuery query9(db);
    query9.exec("SELECT id FROM ethernet WHERE id=2");
    query9.first();
    if (query9.isValid())
        cantidad9=query8.value(0).toString();
    fila9=1;
    QSqlRecord record1= Model9->record(this->fila9);
    record1.setValue(0,cantidad9.toInt());
    record1.setValue(1,ui->lineEdit_5->text());
    Model9->setRecord(this->fila9,record1);
    Model9->submitAll();
    QSqlQuery query10(db);
    query10.exec("SELECT id FROM red WHERE id=2");
    query10.first();
    if (query10.isValid())
        cantidad10=query10.value(0).toString();
    fila10=1;
    if (cantidad10 == "2")
    {
        if(ui->radioButton_14->isChecked())
        {
            QSqlRecord record= Model10->record(this->fila10);
            record.setValue(0,cantidad10.toInt());
            record.setValue(1,"2");
            record.setValue(2,"0");
            Model10->setRecord(this->fila10,record);
            Model10->submitAll();
        }
        else if(ui->radioButton_15->isChecked())
        {
            record.setValue(0,cantidad10.toInt());
            QSqlRecord record= Model10->record(this->fila10);
            record.setValue(1,"0");
            record.setValue(2,"2");
            Model10->setRecord(this->fila10,record);
            Model10->submitAll();
        }
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QSqlQuery queryIdioma(db);
    queryIdioma.exec("SELECT id FROM Idioma WHERE id=2");
    queryIdioma.first();
    if (queryIdioma.isValid())
        cantidad25=queryIdioma.value(0).toString();
    fila11=1;
    if (cantidad25 == "2")
    {
        if(ui->radioButton_16->isChecked())
        {
            QSqlRecord record25= Model11->record(this->fila11);
            record25.setValue(0,cantidad25.toInt());
            record25.setValue(1,"2");
            record25.setValue(2,"0");
            Model11->setRecord(this->fila11,record25);
            Model11->submitAll();
        }
        else if(ui->radioButton_17->isChecked())
        {
            QSqlRecord record25= Model11->record(this->fila11);
            record25.setValue(0,cantidad25.toInt());
            record25.setValue(1,"0");
            record25.setValue(2,"2");
            Model11->setRecord(this->fila11,record25);
            Model11->submitAll();
        }
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QSqlQuery queryVideo(db);
    queryVideo.exec("SELECT id FROM Video WHERE id=2");
    queryVideo.first();
    if (queryVideo.isValid())
        cantidad26=queryVideo.value(0).toString();
    fila12=1;
    if (cantidad26 == "2")
    {
        if(ui->radioButton_18->isChecked())
        {
            QSqlRecord record26= Model13->record(this->fila12);
            record26.setValue(0,cantidad26.toInt());
            record26.setValue(1,"2");
            record26.setValue(2,"0");
            Model13->setRecord(this->fila12,record26);
            Model13->submitAll();
        }
        else if(ui->radioButton_19->isChecked())
        {
            QSqlRecord record26= Model13->record(this->fila12);
            record26.setValue(0,cantidad26.toInt());
            record26.setValue(1,"0");
            record26.setValue(2,"2");
            Model13->setRecord(this->fila12,record26);
            Model13->submitAll();
        }
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QSqlQuery queryFont(db);
    queryFont.exec("SELECT id FROM Font WHERE id=2");
    queryFont.first();
    if (queryFont.isValid())
        cantidad27=queryFont.value(0).toString();
    fila13=1;
    if (cantidad27 == "2")
    {
        QString f0;
        QString f1;
        QString f2;
       if (Retro == 1)
       {
           f0 = cantidad47;
           f1 = cantidad48;
           f2 = cantidad49;
       }
       else if (Retro == 0)
       {
           f0 = ui->fontComboBox->currentText();
           f1 = ui->comboBox->currentText();
           f2 = ui->comboBox_2->currentText();
       }
       QSqlRecord record27= Model14->record(this->fila13);
       record27.setValue(0,cantidad27.toInt());
       record27.setValue(1,f0);
       record27.setValue(2,f1);
       record27.setValue(3,f2);
       Model14->setRecord(this->fila13,record27);
       Model14->submitAll();
       ui->label_126->setText(f0);
       ui->label_127->setText(f1);
       ui->label_128->setText(f2);
       ui->fontComboBox->setCurrentIndex(ui->fontComboBox->findText(f0));
       ui->comboBox->setCurrentIndex(ui->comboBox->findText(f1));
       ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(f2));
       if (f1 == "Regular")
       {
           DatoTalla = "normal";
           DatoNegro = "normal";
       }
       if (f1 == "Italic")
       {
           DatoTalla = "italic";
           DatoNegro = "normal";
       }
       if (f1 == "Bold Italic")
       {
           DatoTalla = "italic";
           DatoNegro = "bold";
       }
       if (f1 == "Bold")
       {
           DatoTalla = "normal";
           DatoNegro = "bold";
       }
       ui->label_126->setStyleSheet("font-family: "+f0+"");
       ui->label_127->setStyleSheet("font-style: "+DatoTalla+"; font-weight: "+DatoNegro+"");
       ui->label_128->setStyleSheet("font-size: "+f2+"pt");
       ui->textEdit_3->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QSqlQuery queryColor(db);
    queryColor.exec("SELECT id FROM Font WHERE id=2");
    queryColor.first();
    if (queryColor.isValid())
        cantidad28=queryColor.value(0).toString();
    fila14=1;
    if (cantidad28 == "2")
    {
       QSqlRecord record28= Model15->record(this->fila14);
       record28.setValue(0,cantidad28.toInt());
       record28.setValue(1,cantidad50);
       record28.setValue(2,cantidad51);
       Model15->setRecord(this->fila14,record28);
       Model15->submitAll();
       ui->label_131->setText(cantidad50);
       ui->label_133->setText(cantidad51);
       ui->pushButton_9->setStyleSheet("color: "+cantidad50+"");
       ui->pushButton_10->setStyleSheet("background-color: "+cantidad51+"");
       ui->label_131->setStyleSheet("color: "+cantidad50+"");
       ui->label_133->setStyleSheet("background-color: "+cantidad51+"");
       ui->textEdit_3->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QString konsola;
    QSqlQuery consola(db);
    consola.exec("SELECT id FROM consola WHERE id=2");
    consola.first();
    if (consola.isValid())
        konsola=consola.value(0).toString();
    int filaconsola=1;
    QString Valor11;
    if (konsola == "2")
    {
        if(ui->radioButton_42->isChecked())
        {
            Valor11 = "2";
        }
        else
        {
            Valor11 = "0";
        }
        QSqlRecord record= Model16->record(filaconsola);
        record.setValue(0,konsola.toInt());
        record.setValue(1,Valor11);
        Model16->setRecord(filaconsola,record);
        Model16->submitAll();
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QString pais;
    QSqlQuery Pais(db);
    Pais.exec("SELECT id FROM Pais WHERE id=1");
    Pais.first();
    if (Pais.isValid())
        pais=Pais.value(0).toString();
    int filapais=0;
    QString ValorP11;
    if (pais == "1")
    {
        if(ui->radioButton_52->isChecked())
        {
            ValorP11 = "1";
        }
        else if(ui->radioButton_53->isChecked())
        {
            ValorP11 = "2";
        }
        QSqlRecord record= Model23->record(filapais);
        record.setValue(0,pais.toInt());
        record.setValue(1,ValorP11);
        Model23->setRecord(filapais,record);
        Model23->submitAll();
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QString Menu;
    QSqlQuery menus(db);
    menus.exec("SELECT id FROM Menus WHERE id=2");
    menus.first();
    if (menus.isValid())
        Menu=menus.value(0).toString();
    int filamenu=1;
    QString Valor10;
    if (Menu == "2")
    {
        if (ui->radioButton_43->isChecked())
        {
            Valor10 = "0";
        }
        else if (ui->radioButton_44->isChecked())
        {
            Valor10 = "1";
        }
        else if (ui->radioButton_45->isChecked())
        {
            Valor10 = "2";
        }
        QSqlRecord record= Model17->record(filamenu);
        record.setValue(0,Menu.toInt());
        record.setValue(1,Valor10);
        Model17->setRecord(filamenu,record);
        Model17->submitAll();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QString Aplicacion;
    QSqlQuery Aplic(db);
    Aplic.exec("SELECT id FROM Aplicacion WHERE id=2");
    Aplic.first();
    if (Aplic.isValid())
        Aplicacion=Aplic.value(0).toString();
    int filaAplic=1;
    QString ValorAplic;
    if (Aplicacion == "2")
    {
        if (ui->radioButton_46->isChecked())
        {
            ValorAplic = "0";
        }
        else if (ui->radioButton_47->isChecked())
        {
            ValorAplic = "1";
        }
        QSqlRecord record= Model18->record(filaAplic);
        record.setValue(0,Aplicacion.toInt());
        record.setValue(1,ValorAplic);
        Model18->setRecord(filaAplic,record);
        Model18->submitAll();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QString Chat;
    QSqlQuery chat(db);
    chat.exec("SELECT id FROM chat WHERE id=2");
    chat.first();
    if (chat.isValid())
        Chat=chat.value(0).toString();
    int filaChat=1;
    QString ValorChat;
    if (Chat == "2")
    {
        if (ui->radioButton_48->isChecked())
        {
            ValorChat = "0";
        }
        else if (ui->radioButton_50->isChecked())
        {
            ValorChat = "1";
        }
        QSqlRecord record= Model19->record(filaChat);
        record.setValue(0,Chat.toInt());
        record.setValue(1,ValorChat);
        Model19->setRecord(filaChat,record);
        Model19->submitAll();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QString Formato;
    QSqlQuery formato(db);
    formato.exec("SELECT id FROM Formato WHERE id=2");
    formato.first();
    if (formato.isValid())
        Formato=formato.value(0).toString();
    int filaFormato=1;
    QString ValorFormato;
    if (Formato == "2")
    {
        if (ui->radioButton_49->isChecked())
        {
            ValorFormato = "0";
        }
        else if (ui->radioButton_51->isChecked())
        {
            ValorFormato = "1";
        }
        QSqlRecord record= Model20->record(filaFormato);
        record.setValue(0,Formato.toInt());
        record.setValue(1,ValorFormato);
        Model20->setRecord(filaFormato,record);
        Model20->submitAll();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QString Estilo;
    QSqlQuery estilo(db);
    estilo.exec("SELECT id FROM Estilo WHERE id=2");
    estilo.first();
    if (estilo.isValid())
        Estilo=estilo.value(0).toString();
    int filaEstilo=1;
    QString ValorEstilo;
    if (Estilo == "2")
    {        
        ValorEstilo = ui->comboBox_3->currentText();
        QSqlRecord record= Model21->record(filaEstilo);
        record.setValue(0,Estilo.toInt());
        record.setValue(1,ValorEstilo);
        Model21->setRecord(filaEstilo,record);
        Model21->submitAll();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
    QString Ecualizador;
    QSqlQuery ecualizador(db);
    ecualizador.exec("SELECT id FROM Ecualizador WHERE id=2");
    ecualizador.first();
    if (ecualizador.isValid())
        Ecualizador=ecualizador.value(0).toString();
    int filaEcualizador=1;
    QString Cantidad,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10;
    if (Ecualizador == "2")
    {
        if (ui->checkBox_4->isChecked())
            Cantidad = "Si";
        else
            Cantidad = "No";
        banda1=QString::number(ui->verticalSlider->value());
        banda2=QString::number(ui->verticalSlider_2->value());
        banda3=QString::number(ui->verticalSlider_3->value());
        banda4=QString::number(ui->verticalSlider_4->value());
        banda5=QString::number(ui->verticalSlider_5->value());
        banda6=QString::number(ui->verticalSlider_6->value());
        banda7=QString::number(ui->verticalSlider_7->value());
        banda8=QString::number(ui->verticalSlider_8->value());
        banda9=QString::number(ui->verticalSlider_9->value());
        banda10=QString::number(ui->verticalSlider_10->value());
        QSqlRecord record= Model22->record(filaEcualizador);
        record.setValue(0,Ecualizador.toInt());
        record.setValue(1,Cantidad);
        record.setValue(2,banda1);
        record.setValue(3,banda2);
        record.setValue(4,banda3);
        record.setValue(5,banda4);
        record.setValue(6,banda5);
        record.setValue(7,banda6);
        record.setValue(8,banda7);
        record.setValue(9,banda8);
        record.setValue(10,banda9);
        record.setValue(11,banda10);
        Model22->setRecord(filaEcualizador,record);
        Model22->submitAll();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
}

void opciones::on_pushButton_3_clicked()
{
    int respuesta = 0;
    respuesta = QMessageBox::question(this, tr("Restaurar valores por defecto"),
               tr("<center><b>Restaurar valores por defecto</b></center><p>"
                  "<b>IMPORTANTE:</b> Estas a punto de eliminar las configuraciones "
                  "personalizadas que hayas introducido manualmente.<p>"
                  "Procede con cuidado!!!<p>"
                  "&iquest;Restaurar valores por defecto?"), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        Retro = 1;
        QSqlQuery query(db);
        query.exec("SELECT Audio128 FROM Opcion WHERE id=1");
        query.first();
        if (query.isValid())
            cantidad=query.value(0).toString();
        QSqlQuery query0(db);
        query0.exec("SELECT Audio192 FROM Opcion WHERE id=1");
        query0.first();
        if (query0.isValid())
            cantidad1=query0.value(0).toString();
        QSqlQuery query1(db);
        query1.exec("SELECT Audio320 FROM Opcion WHERE id=1");
        query1.first();
        if (query1.isValid())
            cantidad2=query1.value(0).toString();
        if ( cantidad == "2")
           {
            ui->radioButton->setChecked(true);
            ui->radioButton_2->setChecked(false);
            ui->radioButton_3->setChecked(false);
            QSqlQuery query(db);
            query.exec("SELECT id FROM Opcion WHERE id=2");
            query.first();
            if (query.isValid())
                cantidad=query.value(0).toString();
            fila=1;
            QSqlRecord record= Model->record(this->fila);
            record.setValue(0,cantidad.toInt());
            record.setValue(1,"2");
            record.setValue(2,"0");
            record.setValue(3,"0");
            Model->setRecord(this->fila,record);
            Model->submitAll();
           }
        else if ( cantidad1 == "2")
           {
            ui->radioButton->setChecked(false);
            ui->radioButton_2->setChecked(true);
            ui->radioButton_3->setChecked(false);
            QSqlQuery query(db);
            query.exec("SELECT id FROM Opcion WHERE id=2");
            query.first();
            if (query.isValid())
                cantidad=query.value(0).toString();
            fila=1;
            QSqlRecord record= Model->record(this->fila);
            record.setValue(0,cantidad.toInt());
            record.setValue(1,"0");
            record.setValue(2,"2");
            record.setValue(3,"0");
            Model->setRecord(this->fila,record);
            Model->submitAll();
           }
        else if ( cantidad2 == "2")
           {
            ui->radioButton->setChecked(false);
            ui->radioButton_2->setChecked(false);
            ui->radioButton_3->setChecked(true);
            QSqlQuery query(db);
            query.exec("SELECT id FROM Opcion WHERE id=2");
            query.first();
            if (query.isValid())
                cantidad=query.value(0).toString();
            fila=1;
            QSqlRecord record= Model->record(this->fila);
            record.setValue(0,cantidad.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"2");
            Model->setRecord(this->fila,record);
            Model->submitAll();
           }
        QSqlQuery query3(db);
        query3.exec("SELECT camouflage_pa FROM Opcion2 WHERE id=1");
        query3.first();
        if (query3.isValid())
            cantidad3=query3.value(0).toString();
        QSqlQuery query4(db);
        query4.exec("SELECT efsplitter_pa FROM Opcion2 WHERE id=1");
        query4.first();
        if (query4.isValid())
            cantidad4=query4.value(0).toString();
        QSqlQuery query5(db);
        query5.exec("SELECT generico_pa FROM Opcion2 WHERE id=1");
        query5.first();
        if (query5.isValid())
            cantidad5=query5.value(0).toString();
        QSqlQuery query6(db);
        query6.exec("SELECT hacha1_pa FROM Opcion2 WHERE id=1");
        query6.first();
        if (query6.isValid())
            cantidad6=query6.value(0).toString();
        QSqlQuery query7(db);
        query7.exec("SELECT hacha2_pa FROM Opcion2 WHERE id=1");
        query7.first();
        if (query7.isValid())
            cantidad7=query7.value(0).toString();
        QSqlQuery query8(db);
        query8.exec("SELECT hachapro_pa FROM Opcion2 WHERE id=1");
        query8.first();
        if (query8.isValid())
            cantidad8=query8.value(0).toString();
        QSqlQuery query9(db);
        query9.exec("SELECT mxs_pa FROM Opcion2 WHERE id=1");
        query9.first();
        if (query9.isValid())
            cantidad9=query9.value(0).toString();
        QSqlQuery query10(db);
        query10.exec("SELECT sf_pa FROM Opcion2 WHERE id=1");
        query10.first();
        if (query10.isValid())
            cantidad10=query10.value(0).toString();
        QSqlQuery query11(db);
        query11.exec("SELECT zip_pa FROM Opcion2 WHERE id=1");
        query11.first();
        if (query11.isValid())
            cantidad11=query11.value(0).toString();
        QSqlQuery query12(db);
        query12.exec("SELECT camaleon1_pa FROM Opcion2 WHERE id=1");
        query12.first();
        if (query12.isValid())
            cantidad12=query12.value(0).toString();
        QSqlQuery query13(db);
        query13.exec("SELECT camaleon2_pa FROM Opcion2 WHERE id=1");
        query13.first();
        if (query13.isValid())
            cantidad13=query13.value(0).toString();
        if ( cantidad3 == "2")
           {
               ui->radioButton_20->setChecked(true);
               ui->radioButton_21->setChecked(false);
               ui->radioButton_23->setChecked(false);
               ui->radioButton_24->setChecked(false);
               ui->radioButton_25->setChecked(false);
               ui->radioButton_26->setChecked(false);
               ui->radioButton_27->setChecked(false);
               ui->radioButton_28->setChecked(false);
               ui->radioButton_29->setChecked(false);
               ui->radioButton_30->setChecked(false);
               ui->radioButton_31->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model1->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"0");
               record.setValue(7,"0");
               record.setValue(8,"0");
               record.setValue(9,"0");
               record.setValue(10,"0");
               record.setValue(11,"2");
               Model1->setRecord(this->fila,record);
               Model1->submitAll();
           }
        else if ( cantidad4 == "2")
           {
               ui->radioButton_20->setChecked(false);
               ui->radioButton_21->setChecked(true);
               ui->radioButton_23->setChecked(false);
               ui->radioButton_24->setChecked(false);
               ui->radioButton_25->setChecked(false);
               ui->radioButton_26->setChecked(false);
               ui->radioButton_27->setChecked(false);
               ui->radioButton_28->setChecked(false);
               ui->radioButton_29->setChecked(false);
               ui->radioButton_30->setChecked(false);
               ui->radioButton_31->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model1->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"0");
               record.setValue(7,"0");
               record.setValue(8,"0");
               record.setValue(9,"0");
               record.setValue(10,"2");
               record.setValue(11,"0");
               Model1->setRecord(this->fila,record);
               Model1->submitAll();
           }
        else if ( cantidad5 == "2")
           {
               ui->radioButton_20->setChecked(false);
               ui->radioButton_21->setChecked(false);
               ui->radioButton_23->setChecked(true);
               ui->radioButton_24->setChecked(false);
               ui->radioButton_25->setChecked(false);
               ui->radioButton_26->setChecked(false);
               ui->radioButton_27->setChecked(false);
               ui->radioButton_28->setChecked(false);
               ui->radioButton_29->setChecked(false);
               ui->radioButton_30->setChecked(false);
               ui->radioButton_31->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model1->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"0");
               record.setValue(7,"0");
               record.setValue(8,"0");
               record.setValue(9,"2");
               record.setValue(10,"0");
               record.setValue(11,"0");
               Model1->setRecord(this->fila,record);
               Model1->submitAll();
           }
        else if ( cantidad6 == "2")
           {
               ui->radioButton_20->setChecked(false);
               ui->radioButton_21->setChecked(false);
               ui->radioButton_23->setChecked(false);
               ui->radioButton_24->setChecked(true);
               ui->radioButton_25->setChecked(false);
               ui->radioButton_26->setChecked(false);
               ui->radioButton_27->setChecked(false);
               ui->radioButton_28->setChecked(false);
               ui->radioButton_29->setChecked(false);
               ui->radioButton_30->setChecked(false);
               ui->radioButton_31->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model1->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"0");
               record.setValue(7,"0");
               record.setValue(8,"2");
               record.setValue(9,"0");
               record.setValue(10,"0");
               record.setValue(11,"0");
               Model1->setRecord(this->fila,record);
               Model1->submitAll();
           }
        else if ( cantidad7 == "2")
           {
               ui->radioButton_20->setChecked(false);
               ui->radioButton_21->setChecked(false);
               ui->radioButton_23->setChecked(false);
               ui->radioButton_24->setChecked(false);
               ui->radioButton_25->setChecked(true);
               ui->radioButton_26->setChecked(false);
               ui->radioButton_27->setChecked(false);
               ui->radioButton_28->setChecked(false);
               ui->radioButton_29->setChecked(false);
               ui->radioButton_30->setChecked(false);
               ui->radioButton_31->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model1->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"0");
               record.setValue(7,"2");
               record.setValue(8,"0");
               record.setValue(9,"0");
               record.setValue(10,"0");
               record.setValue(11,"0");
               Model1->setRecord(this->fila,record);
               Model1->submitAll();
           }
        else if ( cantidad8 == "2")
           {
               ui->radioButton_20->setChecked(false);
               ui->radioButton_21->setChecked(false);
               ui->radioButton_23->setChecked(false);
               ui->radioButton_24->setChecked(false);
               ui->radioButton_25->setChecked(false);
               ui->radioButton_26->setChecked(true);
               ui->radioButton_27->setChecked(false);
               ui->radioButton_28->setChecked(false);
               ui->radioButton_29->setChecked(false);
               ui->radioButton_30->setChecked(false);
               ui->radioButton_31->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                   cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model1->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"2");
               record.setValue(7,"0");
               record.setValue(8,"0");
               record.setValue(9,"0");
               record.setValue(10,"0");
               record.setValue(11,"0");
               Model1->setRecord(this->fila,record);
               Model1->submitAll();
           }
        else if ( cantidad9 == "2")
           {
               ui->radioButton_20->setChecked(false);
               ui->radioButton_21->setChecked(false);
               ui->radioButton_23->setChecked(false);
               ui->radioButton_24->setChecked(false);
               ui->radioButton_25->setChecked(false);
               ui->radioButton_26->setChecked(false);
               ui->radioButton_27->setChecked(true);
               ui->radioButton_28->setChecked(false);
               ui->radioButton_29->setChecked(false);
               ui->radioButton_30->setChecked(false);
               ui->radioButton_31->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model1->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"2");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"0");
               record.setValue(7,"0");
               record.setValue(8,"0");
               record.setValue(9,"0");
               record.setValue(10,"0");
               record.setValue(11,"0");
               Model1->setRecord(this->fila,record);
               Model1->submitAll();
           }
        else if ( cantidad10 == "2")
           {
               ui->radioButton_20->setChecked(false);
               ui->radioButton_21->setChecked(false);
               ui->radioButton_23->setChecked(false);
               ui->radioButton_24->setChecked(false);
               ui->radioButton_25->setChecked(false);
               ui->radioButton_26->setChecked(false);
               ui->radioButton_27->setChecked(false);
               ui->radioButton_28->setChecked(true);
               ui->radioButton_29->setChecked(false);
               ui->radioButton_30->setChecked(false);
               ui->radioButton_31->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model1->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"2");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"0");
               record.setValue(7,"0");
               record.setValue(8,"0");
               record.setValue(9,"0");
               record.setValue(10,"0");
               record.setValue(11,"0");
               Model1->setRecord(this->fila,record);
               Model1->submitAll();
           }
        else if ( cantidad11 == "2")
           {
               ui->radioButton_20->setChecked(false);
               ui->radioButton_21->setChecked(false);
               ui->radioButton_23->setChecked(false);
               ui->radioButton_24->setChecked(false);
               ui->radioButton_25->setChecked(false);
               ui->radioButton_26->setChecked(false);
               ui->radioButton_27->setChecked(false);
               ui->radioButton_28->setChecked(false);
               ui->radioButton_29->setChecked(true);
               ui->radioButton_30->setChecked(false);
               ui->radioButton_31->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model1->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"2");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"0");
               record.setValue(7,"0");
               record.setValue(8,"0");
               record.setValue(9,"0");
               record.setValue(10,"0");
               record.setValue(11,"0");
               Model1->setRecord(this->fila,record);
               Model1->submitAll();
           }
        else if ( cantidad12 == "2")
           {
               ui->radioButton_20->setChecked(false);
               ui->radioButton_21->setChecked(false);
               ui->radioButton_23->setChecked(false);
               ui->radioButton_24->setChecked(false);
               ui->radioButton_25->setChecked(false);
               ui->radioButton_26->setChecked(false);
               ui->radioButton_27->setChecked(false);
               ui->radioButton_28->setChecked(false);
               ui->radioButton_29->setChecked(false);
               ui->radioButton_30->setChecked(true);
               ui->radioButton_31->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model1->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"2");
               record.setValue(6,"0");
               record.setValue(7,"0");
               record.setValue(8,"0");
               record.setValue(9,"0");
               record.setValue(10,"0");
               record.setValue(11,"0");
               Model1->setRecord(this->fila,record);
               Model1->submitAll();
           }
        else if ( cantidad13 == "2")
           {
               ui->radioButton_20->setChecked(false);
               ui->radioButton_21->setChecked(false);
               ui->radioButton_23->setChecked(false);
               ui->radioButton_24->setChecked(false);
               ui->radioButton_25->setChecked(false);
               ui->radioButton_26->setChecked(false);
               ui->radioButton_27->setChecked(false);
               ui->radioButton_28->setChecked(false);
               ui->radioButton_29->setChecked(false);
               ui->radioButton_30->setChecked(false);
               ui->radioButton_31->setChecked(true);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model1->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"2");
               record.setValue(5,"0");
               record.setValue(6,"0");
               record.setValue(7,"0");
               record.setValue(8,"0");
               record.setValue(9,"0");
               record.setValue(10,"0");
               record.setValue(11,"0");
               Model1->setRecord(this->fila,record);
               Model1->submitAll();
           }
        QSqlQuery query14(db);
        query14.exec("SELECT tamano1 FROM Opcion1 WHERE id=1");
        query14.first();
        if (query14.isValid())
            cantidad14=query14.value(0).toString();
        QSqlQuery query15(db);
        query15.exec("SELECT tamano2 FROM Opcion1 WHERE id=1");
        query15.first();
        if (query15.isValid())
            cantidad15=query15.value(0).toString();
        QSqlQuery query16(db);
        query16.exec("SELECT tamano3 FROM Opcion1 WHERE id=1");
        query16.first();
        if (query16.isValid())
            cantidad16=query16.value(0).toString();
        QSqlQuery query17(db);
        query17.exec("SELECT tamano4 FROM Opcion1 WHERE id=1");
        query17.first();
        if (query17.isValid())
            cantidad17=query17.value(0).toString();
        QSqlQuery query18(db);
        query18.exec("SELECT tamano5 FROM Opcion1 WHERE id=1");
        query18.first();
        if (query18.isValid())
            cantidad18=query18.value(0).toString();
        if ( cantidad14 == "2")
           {
               ui->radioButton_22->setChecked(true);
               ui->radioButton_32->setChecked(false);
               ui->radioButton_33->setChecked(false);
               ui->radioButton_34->setChecked(false);
               ui->radioButton_35->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model2->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"2");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               Model2->setRecord(this->fila,record);
               Model2->submitAll();
           }
        else if ( cantidad15 == "2")
           {
               ui->radioButton_22->setChecked(false);
               ui->radioButton_32->setChecked(true);
               ui->radioButton_33->setChecked(false);
               ui->radioButton_34->setChecked(false);
               ui->radioButton_35->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model2->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"2");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               Model2->setRecord(this->fila,record);
               Model2->submitAll();
           }
        else if ( cantidad16 == "2")
           {
               ui->radioButton_22->setChecked(false);
               ui->radioButton_32->setChecked(false);
               ui->radioButton_33->setChecked(true);
               ui->radioButton_34->setChecked(false);
               ui->radioButton_35->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model2->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"2");
               record.setValue(4,"0");
               record.setValue(5,"0");
               Model2->setRecord(this->fila,record);
               Model2->submitAll();
           }
        else if ( cantidad17 == "2")
           {
               ui->radioButton_22->setChecked(false);
               ui->radioButton_32->setChecked(false);
               ui->radioButton_33->setChecked(false);
               ui->radioButton_34->setChecked(true);
               ui->radioButton_35->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model2->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"2");
               record.setValue(5,"0");
               Model2->setRecord(this->fila,record);
               Model2->submitAll();
           }
        else if ( cantidad18 == "2")
           {
               ui->radioButton_22->setChecked(false);
               ui->radioButton_32->setChecked(false);
               ui->radioButton_33->setChecked(false);
               ui->radioButton_34->setChecked(false);
               ui->radioButton_35->setChecked(true);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion2 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model2->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"2");
               Model2->setRecord(this->fila,record);
               Model2->submitAll();
           }
        QSqlQuery query19(db);
        query19.exec("SELECT Velocidad2x FROM Opcion4 WHERE id=1");
        query19.first();
        if (query19.isValid())
            cantidad19=query19.value(0).toString();
        QSqlQuery query20(db);
        query20.exec("SELECT Velocidad4x FROM Opcion4 WHERE id=1");
        query20.first();
        if (query20.isValid())
            cantidad20=query20.value(0).toString();
        QSqlQuery query21(db);
        query21.exec("SELECT Velocidad8x FROM Opcion4 WHERE id=1");
        query21.first();
        if (query21.isValid())
            cantidad21=query21.value(0).toString();
        QSqlQuery query22(db);
        query22.exec("SELECT Velocidad16x FROM Opcion4 WHERE id=1");
        query22.first();
        if (query22.isValid())
            cantidad22=query22.value(0).toString();
        QSqlQuery query23(db);
        query23.exec("SELECT Velocidad32x FROM Opcion4 WHERE id=1");
        query23.first();
        if (query23.isValid())
            cantidad23=query23.value(0).toString();
        if ( cantidad19 == "2")
           {
               ui->radioButton_36->setChecked(true);
               ui->radioButton_37->setChecked(false);
               ui->radioButton_38->setChecked(false);
               ui->radioButton_39->setChecked(false);
               ui->radioButton_40->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion4 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model4->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"2");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               Model4->setRecord(this->fila,record);
               Model4->submitAll();
           }
        else if ( cantidad20 == "2")
           {
               ui->radioButton_36->setChecked(false);
               ui->radioButton_37->setChecked(true);
               ui->radioButton_38->setChecked(false);
               ui->radioButton_39->setChecked(false);
               ui->radioButton_40->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion4 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model4->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"2");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               Model4->setRecord(this->fila,record);
               Model4->submitAll();
           }
        else if ( cantidad21 == "2")
           {
               ui->radioButton_36->setChecked(false);
               ui->radioButton_37->setChecked(false);
               ui->radioButton_38->setChecked(true);
               ui->radioButton_39->setChecked(false);
               ui->radioButton_40->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion4 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model4->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"2");
               record.setValue(4,"0");
               record.setValue(5,"0");
               Model4->setRecord(this->fila,record);
               Model4->submitAll();
           }
        else if ( cantidad22 == "2")
           {
               ui->radioButton_36->setChecked(false);
               ui->radioButton_37->setChecked(false);
               ui->radioButton_38->setChecked(false);
               ui->radioButton_39->setChecked(true);
               ui->radioButton_40->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion4 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model4->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"2");
               record.setValue(5,"0");
               Model4->setRecord(this->fila,record);
               Model4->submitAll();
           }
        else if ( cantidad23 == "2")
           {
               ui->radioButton_36->setChecked(false);
               ui->radioButton_37->setChecked(false);
               ui->radioButton_38->setChecked(false);
               ui->radioButton_39->setChecked(false);
               ui->radioButton_40->setChecked(true);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion4 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model4->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"2");
               Model4->setRecord(this->fila,record);
               Model4->submitAll();
           }
        QSqlQuery query24(db);
        query24.exec("SELECT Numero1,Numero2,Numero3 FROM Opcion3 WHERE id=1");
        query24.first();
        if (query24.isValid())
        {
            cantidad24=query24.value(0).toString();
            cantidad25=query24.value(1).toString();
            cantidad26=query24.value(2).toString();
        }
        ui->lineEdit->setText(cantidad24);
        ui->lineEdit_2->setText(cantidad25);
        ui->lineEdit_3->setText(cantidad26);
        QSqlQuery queryB25(db);
        queryB25.exec("SELECT id FROM Opcion3 WHERE id=2");
        queryB25.first();
        if (queryB25.isValid())
            cantidad=queryB25.value(0).toString();
        fila=1;
        QSqlRecord record1= Model3->record(this->fila);
        record1.setValue(0,cantidad.toInt());
        record1.setValue(1,cantidad24);
        record1.setValue(2,cantidad25);
        record1.setValue(3,cantidad26);
        Model3->setRecord(this->fila,record1);
        Model3->submitAll();
        QSqlQuery query25(db);
        query25.exec("SELECT i480 FROM Opcion5 WHERE id=1");
        query25.first();
        if (query25.isValid())
            cantidad27=query25.value(0).toString();
        QSqlQuery query26(db);
        query26.exec("SELECT i576 FROM Opcion5 WHERE id=1");
        query26.first();
        if (query26.isValid())
            cantidad28=query26.value(0).toString();
        QSqlQuery query27(db);
        query27.exec("SELECT i2_576 FROM Opcion5 WHERE id=1");
        query27.first();
        if (query27.isValid())
            cantidad29=query27.value(0).toString();
        QSqlQuery query28(db);
        query28.exec("SELECT p720 FROM Opcion5 WHERE id=1");
        query28.first();
        if (query28.isValid())
            cantidad30=query28.value(0).toString();
        QSqlQuery query29(db);
        query29.exec("SELECT p1080 FROM Opcion5 WHERE id=1");
        query29.first();
        if (query29.isValid())
            cantidad31=query29.value(0).toString();
        QSqlQuery query30(db);
        query30.exec("SELECT kapy FROM Opcion5 WHERE id=1");
        query30.first();
        if (query30.isValid())
            cantidad32=query30.value(0).toString();
        if ( cantidad27 == "2")
           {
               ui->radioButton_4->setChecked(true);
               ui->radioButton_5->setChecked(false);
               ui->radioButton_6->setChecked(false);
               ui->radioButton_7->setChecked(false);
               ui->radioButton_8->setChecked(false);
               ui->radioButton_9->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion5 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model5->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"2");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"0");
               Model5->setRecord(this->fila,record);
               Model5->submitAll();
           }
        else if ( cantidad28 == "2")
           {
               ui->radioButton_4->setChecked(false);
               ui->radioButton_5->setChecked(true);
               ui->radioButton_6->setChecked(false);
               ui->radioButton_7->setChecked(false);
               ui->radioButton_8->setChecked(false);
               ui->radioButton_9->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion5 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model5->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"2");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"0");
               Model5->setRecord(this->fila,record);
               Model5->submitAll();
           }
        else if ( cantidad29 == "2")
           {
               ui->radioButton_4->setChecked(false);
               ui->radioButton_5->setChecked(false);
               ui->radioButton_6->setChecked(true);
               ui->radioButton_7->setChecked(false);
               ui->radioButton_8->setChecked(false);
               ui->radioButton_9->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion5 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model5->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"2");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"0");
               Model5->setRecord(this->fila,record);
               Model5->submitAll();
           }
        else if ( cantidad30 == "2")
           {
               ui->radioButton_4->setChecked(false);
               ui->radioButton_5->setChecked(false);
               ui->radioButton_6->setChecked(false);
               ui->radioButton_7->setChecked(true);
               ui->radioButton_8->setChecked(false);
               ui->radioButton_9->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion5 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model5->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"2");
               record.setValue(5,"0");
               record.setValue(6,"0");
               Model5->setRecord(this->fila,record);
               Model5->submitAll();
           }
        else if ( cantidad31 == "2")
           {
               ui->radioButton_4->setChecked(false);
               ui->radioButton_5->setChecked(false);
               ui->radioButton_6->setChecked(false);
               ui->radioButton_7->setChecked(false);
               ui->radioButton_8->setChecked(true);
               ui->radioButton_9->setChecked(false);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion5 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model5->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"2");
               record.setValue(6,"0");
               Model5->setRecord(this->fila,record);
               Model5->submitAll();
           }
        else if ( cantidad32 == "2")
           {
               ui->radioButton_4->setChecked(false);
               ui->radioButton_5->setChecked(false);
               ui->radioButton_6->setChecked(false);
               ui->radioButton_7->setChecked(false);
               ui->radioButton_8->setChecked(false);
               ui->radioButton_9->setChecked(true);
               QSqlQuery query(db);
               query.exec("SELECT id FROM Opcion5 WHERE id=2");
               query.first();
               if (query.isValid())
                    cantidad=query.value(0).toString();
               fila=1;
               QSqlRecord record= Model5->record(this->fila);
               record.setValue(0,cantidad.toInt());
               record.setValue(1,"0");
               record.setValue(2,"0");
               record.setValue(3,"0");
               record.setValue(4,"0");
               record.setValue(5,"0");
               record.setValue(6,"2");
               Model5->setRecord(this->fila,record);
               Model5->submitAll();
           }
        QSqlQuery query31(db);
        query31.exec("SELECT Defecto FROM Miscelanea WHERE id=1");
        query31.first();
        if (query31.isValid())
            cantidad33=query31.value(0).toString();
        QSqlQuery queryDefecto(db);
        queryDefecto.exec("SELECT Inicio FROM Miscelanea WHERE id=1");
        queryDefecto.first();
        if (queryDefecto.isValid())
            cantidad53=queryDefecto.value(0).toString();
        QSqlQuery queryDependencia(db);
        queryDependencia.exec("SELECT Dependencia FROM Miscelanea WHERE id=1");
        queryDependencia.first();
        if (queryDependencia.isValid())
            cantidad54=queryDependencia.value(0).toString();
        QString Valor1, Valor2, Valor3;
        if (cantidad33 == "2")
        {
           Valor1 = "2";
           ui->checkBox_2->setChecked(true);
        }
        else
        {
           Valor1 = "0";
           ui->checkBox_2->setChecked(false);
        }
        if (cantidad53 == "2")
        {
           Valor2 = "2";
           ui->checkBox->setChecked(true);
        }
        else
        {
           Valor2 = "0";
           ui->checkBox->setChecked(false);
        }
        if (cantidad54 == "2")
        {
           Valor3 = "2";
           ui->checkBox_3->setChecked(true);
        }
        else
        {
           Valor3 = "0";
           ui->checkBox_3->setChecked(true);
        }
        QSqlQuery queryd(db);
        queryd.exec("SELECT id FROM Miscelanea WHERE id=2");
        queryd.first();
        if (queryd.isValid())
            cantidad=queryd.value(0).toString();
        fila=1;
        QSqlRecord record= Model6->record(this->fila6);
        record.setValue(0,cantidad.toInt());
        record.setValue(1,Valor1);
        record.setValue(2,Valor2);
        record.setValue(3,Valor3);
        Model6->setRecord(this->fila6,record);
        Model6->submitAll();
        QSqlQuery query32(db);
        query32.exec("SELECT tiempo120 FROM Parental WHERE id=1");
        query32.first();
        if (query32.isValid())
            cantidad34=query32.value(0).toString();
        QSqlQuery query33(db);
        query33.exec("SELECT tiempo90 FROM Parental WHERE id=1");
        query33.first();
        if (query33.isValid())
            cantidad35=query33.value(0).toString();
        QSqlQuery query34(db);
        query34.exec("SELECT tiempo60 FROM Parental WHERE id=1");
        query34.first();
        if (query34.isValid())
            cantidad36=query34.value(0).toString();
        QSqlQuery query35(db);
        query35.exec("SELECT tiempo30 FROM Parental WHERE id=1");
        query35.first();
        if (query35.isValid())
            cantidad37=query35.value(0).toString();
        if ( cantidad34 == "2")
           {
                ui->radioButton_10->setChecked(false);
                ui->radioButton_11->setChecked(false);
                ui->radioButton_12->setChecked(true);
                ui->radioButton_13->setChecked(false);
                QSqlQuery query7(db);
                query7.exec("SELECT id FROM Parental WHERE id=2");
                query7.first();
                if (query7.isValid())
                    cantidad7=query7.value(0).toString();
                fila7=1;
                QSqlRecord record= Model7->record(this->fila7);
                record.setValue(0,cantidad7.toInt());
                record.setValue(1,"2");
                record.setValue(2,"0");
                record.setValue(3,"0");
                record.setValue(4,"0");
                Model7->setRecord(this->fila7,record);
                Model7->submitAll();
           }
        else if ( cantidad35 == "2")
           {
            ui->radioButton_10->setChecked(false);
            ui->radioButton_11->setChecked(false);
            ui->radioButton_12->setChecked(false);
            ui->radioButton_13->setChecked(true);
            QSqlQuery query7(db);
            query7.exec("SELECT id FROM Parental WHERE id=2");
            query7.first();
            if (query7.isValid())
                cantidad7=query7.value(0).toString();
            fila7=1;
            QSqlRecord record= Model7->record(this->fila7);
            record.setValue(0,cantidad7.toInt());
            record.setValue(1,"0");
            record.setValue(2,"2");
            record.setValue(3,"0");
            record.setValue(4,"0");
            Model7->setRecord(this->fila7,record);
            Model7->submitAll();
           }
        else if ( cantidad36 == "2")
           {
            ui->radioButton_10->setChecked(false);
            ui->radioButton_11->setChecked(true);
            ui->radioButton_12->setChecked(false);
            ui->radioButton_13->setChecked(false);
            QSqlQuery query7(db);
            query7.exec("SELECT id FROM Parental WHERE id=2");
            query7.first();
            if (query7.isValid())
                cantidad7=query7.value(0).toString();
            fila7=1;
            QSqlRecord record= Model7->record(this->fila7);
            record.setValue(0,cantidad7.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"2");
            record.setValue(4,"0");
            Model7->setRecord(this->fila7,record);
            Model7->submitAll();
           }
        else if ( cantidad37 == "2")
           {
            ui->radioButton_10->setChecked(true);
            ui->radioButton_11->setChecked(false);
            ui->radioButton_12->setChecked(false);
            ui->radioButton_13->setChecked(false);
            QSqlQuery query7(db);
            query7.exec("SELECT id FROM Parental WHERE id=2");
            query7.first();
            if (query7.isValid())
                cantidad7=query7.value(0).toString();
            fila7=1;
            QSqlRecord record= Model7->record(this->fila7);
            record.setValue(0,cantidad7.toInt());
            record.setValue(1,"0");
            record.setValue(2,"0");
            record.setValue(3,"0");
            record.setValue(4,"2");
            Model7->setRecord(this->fila7,record);
            Model7->submitAll();
           }
        QSqlQuery query36(db);
        query36.exec("SELECT essid FROM wifi WHERE id=1");
        query36.first();
        if (query36.isValid())
            cantidad38=query36.value(0).toString();
        QSqlQuery query38(db);
        query38.exec("SELECT conexion FROM wifi WHERE id=1");
        query38.first();
        if (query38.isValid())
            cantidad39=query38.value(0).toString();
        QSqlQuery query37(db);
        query37.exec("SELECT id FROM wifi WHERE id=2");
        query37.first();
        if (query37.isValid())
            cantidad8=query37.value(0).toString();
        fila8=1;
        QSqlRecord record8= Model8->record(this->fila8);
        record8.setValue(0,cantidad8.toInt());
        record8.setValue(1,""+cantidad39+"");
        record8.setValue(2,""+cantidad38+"");
        Model8->setRecord(this->fila8,record8);
        Model8->submitAll();
        ui->lineEdit_4->setText(""+cantidad38+"");
        ui->lineEdit_6->setText(""+cantidad39+"");
        QSqlQuery query39(db);
        query39.exec("SELECT conexion FROM ethernet WHERE id=1");
        query39.first();
        if (query39.isValid())
            cantidad40=query39.value(0).toString();
        QSqlQuery query40(db);
        query40.exec("SELECT id FROM ethernet WHERE id=2");
        query40.first();
        if (query40.isValid())
            cantidad9=query40.value(0).toString();
        fila9=1;
        QSqlRecord record9= Model9->record(this->fila8);
        record9.setValue(0,cantidad9.toInt());
        record9.setValue(1,""+cantidad40+"");
        Model9->setRecord(this->fila8,record9);
        Model9->submitAll();
        ui->lineEdit_5->setText(""+cantidad40+"");
        QSqlQuery query41(db);
        query41.exec("SELECT ethernet FROM red WHERE id=1");
        query41.first();
        if (query41.isValid())
            cantidad41=query41.value(0).toString();
        QSqlQuery query42(db);
        query42.exec("SELECT wifi FROM red WHERE id=1");
        query42.first();
        if (query42.isValid())
            cantidad42=query42.value(0).toString();
        if ( cantidad41 == "2")
           {
                ui->radioButton_14->setChecked(true);
                ui->radioButton_15->setChecked(false);
                QSqlQuery query8(db);
                query8.exec("SELECT id FROM red WHERE id=2");
                query8.first();
                if (query8.isValid())
                    cantidad8=query8.value(0).toString();
                fila8=1;
                QSqlRecord record= Model10->record(this->fila10);
                record.setValue(0,cantidad8.toInt());
                record.setValue(1,"2");
                record.setValue(2,"0");
                Model10->setRecord(this->fila10,record);
                Model10->submitAll();
           }
        else if ( cantidad42 == "2")
           {
            ui->radioButton_14->setChecked(false);
            ui->radioButton_15->setChecked(true);
            QSqlQuery query8(db);
            query8.exec("SELECT id FROM red WHERE id=2");
            query8.first();
            if (query8.isValid())
                cantidad8=query8.value(0).toString();
            fila8=1;
            QSqlRecord record= Model10->record(this->fila10);
            record.setValue(0,cantidad8.toInt());
            record.setValue(1,"0");
            record.setValue(2,"2");
            Model10->setRecord(this->fila10,record);
            Model10->submitAll();
           }
        QSqlQuery query44(db);
        query44.exec("SELECT spanish FROM Idioma WHERE id=1");
        query44.first();
        if (query44.isValid())
            cantidad44=query44.value(0).toString();
        QSqlQuery query43(db);
        query43.exec("SELECT english FROM Idioma WHERE id=1");
        query43.first();
        if (query43.isValid())
            cantidad43=query43.value(0).toString();
        if ( cantidad44 == "2")
           {
                ui->radioButton_16->setChecked(true);
                ui->radioButton_17->setChecked(false);
                QSqlQuery query9(db);
                query9.exec("SELECT id FROM Idioma WHERE id=2");
                query9.first();
                if (query9.isValid())
                    cantidad9=query9.value(0).toString();
                fila9=1;
                QSqlRecord record= Model11->record(this->fila11);
                record.setValue(0,cantidad9.toInt());
                record.setValue(1,"2");
                record.setValue(2,"0");
                Model11->setRecord(this->fila11,record);
                Model11->submitAll();
           }
        else if ( cantidad43 == "2")
           {
               ui->radioButton_16->setChecked(true);
               ui->radioButton_17->setChecked(false);
               QSqlQuery query9(db);
               query9.exec("SELECT id FROM Idioma WHERE id=2");
               query9.first();
               if (query9.isValid())
                    cantidad9=query9.value(0).toString();
               fila9=1;
               QSqlRecord record= Model11->record(this->fila11);
               record.setValue(0,cantidad9.toInt());
               record.setValue(1,"0");
               record.setValue(2,"2");
               Model11->setRecord(this->fila11,record);
               Model11->submitAll();
           }
        QSqlQuery query45(db);
        query45.exec("SELECT spanish FROM Idioma WHERE id=1");
        query45.first();
        if (query45.isValid())
            cantidad45=query45.value(0).toString();
        QSqlQuery query46(db);
        query46.exec("SELECT english FROM Idioma WHERE id=1");
        query46.first();
        if (query46.isValid())
            cantidad46=query46.value(0).toString();
        if ( cantidad45 == "2")
           {
                ui->radioButton_18->setChecked(true);
                ui->radioButton_19->setChecked(false);
                QSqlQuery query10(db);
                query10.exec("SELECT id FROM Video WHERE id=2");
                query10.first();
                if (query10.isValid())
                    cantidad10=query10.value(0).toString();
                fila10=1;
                QSqlRecord record= Model13->record(this->fila12);
                record.setValue(0,cantidad10.toInt());
                record.setValue(1,"2");
                record.setValue(2,"0");
                Model13->setRecord(this->fila12,record);
                Model13->submitAll();
           }
        else if ( cantidad46 == "2")
           {
               ui->radioButton_18->setChecked(true);
               ui->radioButton_19->setChecked(false);
               QSqlQuery query10(db);
               query10.exec("SELECT id FROM Video WHERE id=2");
               query10.first();
               if (query10.isValid())
                    cantidad10=query10.value(0).toString();
               fila10=1;
               QSqlRecord record= Model13->record(this->fila12);
               record.setValue(0,cantidad10.toInt());
               record.setValue(1,"0");
               record.setValue(2,"2");
               Model13->setRecord(this->fila12,record);
               Model13->submitAll();
           }
        QSqlQuery query47(db);
        query47.exec("SELECT Fuente FROM Font WHERE id=1");
        query47.first();
        if (query47.isValid())
            cantidad47=query47.value(0).toString();
        QSqlQuery query48(db);
        query48.exec("SELECT Estilo FROM Font WHERE id=1");
        query48.first();
        if (query48.isValid())
            cantidad48=query48.value(0).toString();
        QSqlQuery query49(db);
        query49.exec("SELECT Talla FROM Font WHERE id=1");
        query49.first();
        if (query49.isValid())
            cantidad49=query49.value(0).toString();
        QSqlQuery queryFont(db);
        queryFont.exec("SELECT id FROM Font WHERE id=2");
        queryFont.first();
        if (queryFont.isValid())
            cantidad27=queryFont.value(0).toString();
        fila13=1;
        if (cantidad27 == "2")
        {
           QSqlRecord record27= Model14->record(this->fila13);
           record27.setValue(0,cantidad27.toInt());
           record27.setValue(1,cantidad47);
           record27.setValue(2,cantidad48);
           record27.setValue(3,cantidad49);
           Model14->setRecord(this->fila13,record27);
           Model14->submitAll();
           ui->label_126->setText(cantidad47);
           ui->label_127->setText(cantidad48);
           ui->label_128->setText(cantidad49);
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
           ui->label_126->setStyleSheet("font-family: "+cantidad47+"");
           ui->label_127->setStyleSheet("font-style: "+DatoTalla+"; font-weight: "+DatoNegro+"");
           ui->label_128->setStyleSheet("font-size: "+cantidad49+"pt");
        }
        QSqlQuery query50(db);
        query50.exec("SELECT ColorTexto FROM Color WHERE id=1");
        query50.first();
        if (query50.isValid())
            cantidad50=query50.value(0).toString();
        QSqlQuery query51(db);
        query51.exec("SELECT ColorFondo FROM Color WHERE id=1");
        query51.first();
        if (query51.isValid())
            cantidad51=query51.value(0).toString();
        QSqlQuery queryColor(db);
        queryColor.exec("SELECT id FROM Font WHERE id=2");
        queryColor.first();
        if (queryColor.isValid())
            cantidad28=queryColor.value(0).toString();
        fila14=1;
        if (cantidad28 == "2")
        {
           QSqlRecord record28= Model15->record(this->fila14);
           record28.setValue(0,cantidad28.toInt());
           record28.setValue(1,cantidad50);
           record28.setValue(2,cantidad51);
           Model15->setRecord(this->fila14,record28);
           Model15->submitAll();
           ui->pushButton_9->setStyleSheet("color: "+cantidad50+"");
           ui->pushButton_10->setStyleSheet("background-color: "+cantidad51+"");
           ui->label_131->setText(cantidad50);
           ui->label_133->setText(cantidad51);
           ui->pushButton_9->setStyleSheet("color: "+cantidad50+"");
           ui->pushButton_10->setStyleSheet("background-color: "+cantidad51+"");
           ui->label_131->setStyleSheet("color: "+cantidad50+"");
           ui->label_133->setStyleSheet("background-color: "+cantidad51+"");
        }
        QString konsola;
        QSqlQuery consola(db);
        consola.exec("SELECT Fondo FROM Consola WHERE id=1");
        query31.first();
        if (query31.isValid())
            konsola=consola.value(0).toString();
        if ( konsola == "2")
        {
            ui->radioButton_42->setChecked(true);
            ui->radioButton_41->setChecked(false);
            QSqlQuery query9(db);
            query9.exec("SELECT id FROM consola WHERE id=2");
            query9.first();
            if (query9.isValid())
                cantidad9=query9.value(0).toString();
            fila9=1;
            QSqlRecord record= Model16->record(this->fila9);
            record.setValue(0,cantidad9.toInt());
            record.setValue(1,"2");
            Model16->setRecord(this->fila9,record);
            Model16->submitAll();
        }
        QString cantidadP;
        ui->radioButton_42->setChecked(false);
        ui->radioButton_41->setChecked(false);
        QSqlQuery queryP(db);
        queryP.exec("SELECT id FROM Pais WHERE id=1");
        queryP.first();
        if (queryP.isValid())
            cantidadP=queryP.value(0).toString();
        int filaP9=1;
        QSqlRecord recordP= Model23->record(filaP9);
        record.setValue(1,"0");
        Model23->setRecord(filaP9,recordP);
        Model23->submitAll();
        ui->radioButton_52->setChecked(false);
        ui->radioButton_53->setChecked(false);
        QString Menu, dato;
        QSqlQuery menu(db);
        menu.exec("SELECT Tipo_Menu FROM Menus WHERE id=1");
        query51.first();
        if (query51.isValid())
            Menu=menu.value(0).toString();
        if (Menu == "0")
        {
            ui->radioButton_43->setChecked(true);
            dato="0";
        }
        else if (Menu == "1")
        {
            ui->radioButton_44->setChecked(true);
            dato="1";
        }
        else if (Menu == "2")
        {
            ui->radioButton_45->setChecked(true);
            dato="2";
        }
        QSqlQuery queryMenu(db);
        queryMenu.exec("SELECT id FROM Menus WHERE id=2");
        queryMenu.first();
        if (queryMenu.isValid())
            cantidad9=queryMenu.value(0).toString();
        fila9=1;
        QSqlRecord recordMenu= Model17->record(this->fila9);
        recordMenu.setValue(0,cantidad9.toInt());
        recordMenu.setValue(1,dato);
        Model17->setRecord(this->fila9,recordMenu);
        Model17->submitAll();
        QString Menu1, dato1;
        QSqlQuery menu1(db);
        menu1.exec("SELECT Aplicacion FROM Aplicacion WHERE id=1");
        menu1.first();
        if (menu1.isValid())
            Menu1=menu1.value(0).toString();
        if (Menu1 == "0")
        {
            ui->radioButton_46->setChecked(true);
            dato1="0";
        }
        else if (Menu1 == "1")
        {
            ui->radioButton_47->setChecked(true);
            dato1="1";
        }
        QSqlQuery queryMenu1(db);
        queryMenu1.exec("SELECT id FROM Aplicacion WHERE id=2");
        queryMenu1.first();
        if (queryMenu1.isValid())
            cantidad10=queryMenu1.value(0).toString();
        fila10=1;
        QSqlRecord recordMenu1= Model18->record(this->fila10);
        recordMenu.setValue(0,cantidad10.toInt());
        recordMenu.setValue(1,dato1);
        Model18->setRecord(this->fila10,recordMenu1);
        Model18->submitAll();
        QString Menu2, dato2;
        QSqlQuery menu2(db);
        menu2.exec("SELECT visionado FROM chat WHERE id=1");
        menu2.first();
        if (menu2.isValid())
            Menu2=menu2.value(0).toString();
        if (Menu2 == "0")
        {
            ui->radioButton_48->setChecked(true);
            dato2="0";
        }
        else if (Menu2 == "1")
        {
            ui->radioButton_50->setChecked(true);
            dato2="1";
        }
        QSqlQuery queryMenu2(db);
        queryMenu2.exec("SELECT id FROM chat WHERE id=2");
        queryMenu2.first();
        if (queryMenu2.isValid())
            cantidad57=queryMenu2.value(0).toString();
        fila17=1;
        QSqlRecord recordMenu2= Model19->record(this->fila17);
        recordMenu2.setValue(0,cantidad57.toInt());
        recordMenu2.setValue(1,dato2);
        Model19->setRecord(this->fila17,recordMenu2);
        Model19->submitAll();
        QString Menu3, dato3;
        QSqlQuery menu3(db);
        menu3.exec("SELECT Aspecto FROM Formato WHERE id=1");
        menu3.first();
        if (menu3.isValid())
            Menu3=menu3.value(0).toString();
        if (Menu3 == "0")
        {
            ui->radioButton_49->setChecked(true);
            dato3="0";
        }
        else if (Menu3 == "1")
        {
            ui->radioButton_51->setChecked(true);
            dato3="1";
        }
        QSqlQuery queryMenu3(db);
        queryMenu3.exec("SELECT id FROM Formato WHERE id=2");
        queryMenu3.first();
        if (queryMenu3.isValid())
            cantidad58=queryMenu3.value(0).toString();
        fila17=1;
        QSqlRecord recordMenu3= Model20->record(this->fila17);
        recordMenu3.setValue(0,cantidad58.toInt());
        recordMenu3.setValue(1,dato3);
        Model20->setRecord(this->fila17,recordMenu3);
        Model20->submitAll();
        QString Menu4;
        QSqlQuery menu4(db);
        menu4.exec("SELECT Style FROM Estilo WHERE id=1");
        menu4.first();
        if (menu4.isValid())
            Menu4=menu4.value(0).toString();
        ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(Menu4));
        QSqlQuery queryMenu4(db);
        queryMenu4.exec("SELECT id FROM Estilo WHERE id=2");
        queryMenu4.first();
        if (queryMenu4.isValid())
            cantidad59=queryMenu4.value(0).toString();
        fila18=1;
        QSqlRecord recordMenu4= Model21->record(this->fila18);
        recordMenu4.setValue(0,cantidad59.toInt());
        recordMenu4.setValue(1,Menu4);
        Model21->setRecord(this->fila18,recordMenu4);
        Model21->submitAll();
        QString Activo,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10;
        QSqlQuery queryEcua(db);
        queryEcua.exec("SELECT activo,banda1,banda2,banda3,banda4,banda5,banda6,banda7,banda8,banda9,banda10 FROM Ecualizador WHERE id=1");
        queryEcua.first();
        if (queryEcua.isValid())
        {
            Activo=queryEcua.value(0).toString();
            banda1=queryEcua.value(1).toString();
            banda2=queryEcua.value(2).toString();
            banda3=queryEcua.value(3).toString();
            banda4=queryEcua.value(4).toString();
            banda5=queryEcua.value(5).toString();
            banda6=queryEcua.value(6).toString();
            banda7=queryEcua.value(7).toString();
            banda8=queryEcua.value(8).toString();
            banda9=queryEcua.value(9).toString();
            banda10=queryEcua.value(10).toString();
        }
        if (Activo == "Si")
            ui->checkBox_4->setChecked(true);
        else
            ui->checkBox_4->setChecked(false);
        ui->verticalSlider->setValue(banda1.toInt());
        ui->verticalSlider_2->setValue(banda2.toInt());
        ui->verticalSlider_3->setValue(banda3.toInt());
        ui->verticalSlider_4->setValue(banda4.toInt());
        ui->verticalSlider_5->setValue(banda5.toInt());
        ui->verticalSlider_6->setValue(banda6.toInt());
        ui->verticalSlider_7->setValue(banda7.toInt());
        ui->verticalSlider_8->setValue(banda8.toInt());
        ui->verticalSlider_9->setValue(banda9.toInt());
        ui->verticalSlider_10->setValue(banda10.toInt());
        QString Ecualizador;
        QSqlQuery ecualizador(db);
        ecualizador.exec("SELECT id FROM Ecualizador WHERE id=2");
        ecualizador.first();
        if (ecualizador.isValid())
            Ecualizador=ecualizador.value(0).toString();
        int filaEcualizador=1;
        QSqlRecord record22= Model22->record(filaEcualizador);
        record22.setValue(0,Ecualizador.toInt());
        record22.setValue(1,Activo);
        record22.setValue(2,banda1);
        record22.setValue(3,banda2);
        record22.setValue(4,banda3);
        record22.setValue(5,banda4);
        record22.setValue(6,banda5);
        record22.setValue(7,banda6);
        record22.setValue(8,banda7);
        record22.setValue(9,banda8);
        record22.setValue(10,banda9);
        record22.setValue(11,banda10);
        Model22->setRecord(filaEcualizador,record22);
        Model22->submitAll();
    }
    return;
}

void opciones::on_pushButton_4_clicked()
{
    QString User;
    User=ui->lineEdit_7->text();
    QSqlQuery query1(db);
    query1.exec("SELECT Palabra FROM Palabra WHERE Palabra='"+User+"'");
    query1.first();
    if (query1.isValid())
        cantidad=query1.value(0).toString();
    if (User == cantidad)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se pueden duplicar palabras clave. Cambia los datos de palabra clave para poder insertarla."));
        m.exec();
        return;
    }
    QSqlQuery query(db);
    query.prepare("INSERT INTO Palabra (Palabra)"
                  "VALUES (:Palabra)");
    query.bindValue(":Palabra", ui->lineEdit_7->text());
    query.exec();
    Model12->select();
    ui->tableView->setModel(Model12);
}

void opciones::on_pushButton_6_clicked()
{
    QString User;
    User= ui->lineEdit_7->text();
    QSqlQuery query2(db);
    query2.exec("SELECT Palabra FROM Palabra WHERE Palabra='"+User+"'");
    query2.first();    
    QSqlRecord record= Model12->record(this->fila);
    record.setValue(1,ui->lineEdit_7->text());
    Model12->setRecord(this->fila,record);
    Model12->submitAll();
}

void opciones::on_pushButton_7_clicked()
{
    Model12->setFilter("Palabra like'"+ui->lineEdit_7->text()+"%'");
    ui->tableView->setModel(Model12);
}

void opciones::on_pushButton_5_clicked()
{
    QString usuario;
    usuario= ui->lineEdit_7->text();
    QSqlQuery query1(db);
    query1.exec("SELECT Palabra FROM Palabra WHERE Palabra='"+usuario+"'");
    query1.first();
    ui->tableView->model()->removeRow(fila);
}

void opciones::on_pushButton_8_clicked()
{
    this->ui->lineEdit_7->setText(tr(""));
}

void opciones::on_fontComboBox_currentFontChanged(QFont f)
{
    f = ui->fontComboBox->currentText();
    cantidad47 = ui->fontComboBox->currentText();
    ui->textEdit_3->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
}

void opciones::on_comboBox_currentIndexChanged(QString f)
{
    cantidad48=f;
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
    ui->textEdit_3->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
}

void opciones::on_comboBox_2_currentIndexChanged(QString f)
{
    cantidad49 = f;
    ui->textEdit_3->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
}

void opciones::on_pushButton_9_clicked()
{
    QColor color;
    color = QColorDialog::getColor(Qt::green, this, "Selecciona Color del Texto", QColorDialog::DontUseNativeDialog);
    cantidad50 = color.name();
    ui->pushButton_9->setStyleSheet("color: "+cantidad50+"");
    ui->textEdit_3->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
}

void opciones::on_pushButton_10_clicked()
{
    QColor color;
    color = QColorDialog::getColor(Qt::green, this, "Selecciona Color de Fondo", QColorDialog::DontUseNativeDialog);
    cantidad51 = color.name();
    ui->pushButton_10->setStyleSheet("background-color: "+cantidad51+"");
    ui->textEdit_3->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
}

void opciones::Eth()
{
    if (ui->radioButton_14->isChecked())
    {
        ui->groupBox_10->setEnabled(false);
        ui->groupBox_9->setEnabled(true);
    }
}

void opciones::Wlan()
{
    if (ui->radioButton_15->isChecked())
    {
        ui->groupBox_9->setEnabled(false);
        ui->groupBox_10->setEnabled(true);
    }
}

void opciones::Spanish()
{
    if (ui->radioButton_16->isChecked())
    {
        qTranslator->load("/usr/share/RecoverDrake/RecoverDrake_es.qm", ".");
        QLocale::setDefault(QLocale(QLocale::Spanish,QLocale::Spain));
    }
}

void opciones::English()
{
    if (ui->radioButton_17->isChecked())
    {
        qTranslator->load("/usr/share/RecoverDrake/RecoverDrake_en.qm", ".");
        QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
    }
}

void opciones::changeStyle(QString stilo)
{
    QApplication::setStyle(QStyleFactory::create(stilo));
}

void opciones::on_pushButton_11_clicked()
{
    system("su - "+user+" -c \"firefox http://rpm.pbone.net\"");
    return;
}

void opciones::on_pushButton_12_clicked()
{
    system("su - "+user+" -c \"firefox http://rpm.pbone.net\"");
    return;
}

void opciones::on_pushButton_13_clicked()
{
    system("su - "+user+" -c \"firefox http://rpm.pbone.net\"");
    return;
}

QString opciones::getRpm(QString Valor)
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "-q" << Valor;
    procesoRPM->start("rpm",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res =  QString(Paquete);
    res.chop(1);
    return res;
}

void opciones::cambiaFila1(QModelIndex actual)
{
        int i;
        i=actual.row();
        QModelIndex index;
        index=ui->tableView_2->model()->index(i,0);
        this->id= index.data().toInt();
        index=ui->tableView_2->model()->index(i,1);
        ui->lineEdit_8->setText(tr(index.data().toString()));
        if (ui->lineEdit_8->text().contains("@gmail.com"))
        {
            ui->radioButton_54->setChecked(true);
            ui->lineEdit_8->setText(ui->lineEdit_8->text().remove("@gmail.com"));
        }
        else
        {
            ui->radioButton_55->setChecked(true);
        }
        this->Smtp();
        index=ui->tableView_2->model()->index(i,2);
        ui->lineEdit_9->setText(tr(index.data().toString()));
        index=ui->tableView_2->model()->index(i,3);
        ui->lineEdit_10->setText(tr(index.data().toString()));
        index=ui->tableView_2->model()->index(i,4);
        QString Valor= index.data().toString();
        if (Valor == "Si")
            ui->checkBox_6->setChecked(true);
        else
            ui->checkBox_6->setChecked(false);
        index=ui->tableView_2->model()->index(i,5);
        QString Valor1= index.data().toString();
        if (Valor1 == "Si")
            ui->checkBox_5->setChecked(true);
        else
            ui->checkBox_5->setChecked(false);
        index=ui->tableView_2->model()->index(i,6);
        ui->lineEdit_12->setText(tr(index.data().toString()));
        index=ui->tableView_2->model()->index(i,7);
        int Valor2= index.data().toInt();
        ui->spinBox->setValue(Valor2);
        this->fila0=i;
}

void opciones::Smtp()
{
    if (ui->radioButton_54->isChecked())
    {
        ui->label_192->setVisible(true);
        if (ui->lineEdit_8->text().contains("@gmail.com"))
        {
            ui->lineEdit_8->setText(ui->lineEdit_8->text().remove("@gmail.com"));
        }
        if (ui->lineEdit_8->text() == "")
            ui->lineEdit_9->setText("smtp.gmail.com");
    }
    else if (ui->radioButton_55->isChecked())
    {
        ui->label_192->setVisible(false);
        if (ui->lineEdit_8->text() == "")
            ui->lineEdit_9->setText("");
    }

}

void opciones::password()
{
    if (ui->checkBox_7->isChecked() == true)
    {
        ui->lineEdit_10->setEchoMode(QLineEdit::Normal);
    }
    else if (ui->checkBox_7->isChecked() == false)
    {
        ui->lineEdit_10->setEchoMode(QLineEdit::Password);
    }
}

void opciones::on_pushButton_14_clicked()
{
    QString Correo, Server, Clave, Autentic, SSL, User, Port, Dato;
    Correo=ui->lineEdit_8->text();
    if (ui->radioButton_54->isChecked())
    {
        if (!ui->lineEdit_8->text().contains("@gmail.com"))
        {
            ui->lineEdit_8->setText(ui->lineEdit_8->text()+"@gmail.com");
            Correo=ui->lineEdit_8->text();
        }
    }
    Server=ui->lineEdit_9->text();
    Clave=ui->lineEdit_10->text();
    if (ui->checkBox_6->isChecked())
        Autentic="Si";
    else
        Autentic="No";
    if (ui->checkBox_5->isChecked())
        SSL="Si";
    else
        SSL="No";
    User=ui->lineEdit_12->text();
    Port=ui->spinBox->text();
    QSqlQuery query(db);
    query.exec("SELECT Correo FROM Smtp WHERE Correo='"+Correo+"'");
    query.first();
    if (query.isValid())
        Dato=query.value(0).toString();
    if (Correo == Dato && Correo !="")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se puede duplicar el correo electronico por razones obvias."));
        m.exec();
        return;
    }
    if (Correo == "" || Server == "" || Clave == "" || Autentic == "" || SSL == "" || User == "" || Port == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No pueden haber datos vacios.<p>Todos los datos son necesarios para una perfecta configuracion."));
        m.exec();
        return;
    }
    QSqlQuery Wdark(db);
    Wdark.prepare("INSERT INTO Smtp (Correo,smptserver,Clave,Autenticacion,SSL,User,Port)"
                  "VALUES (:Correo,:smptserver,:Clave,:Autenticacion,:SSL,:User,:Port)");
    Wdark.bindValue(":Correo", Correo);
    Wdark.bindValue(":smptserver", Server);
    Wdark.bindValue(":Clave", Clave);
    Wdark.bindValue(":Autenticacion", Autentic);
    Wdark.bindValue(":SSL", SSL);
    Wdark.bindValue(":User", User);
    Wdark.bindValue(":Port", Port);
    Wdark.exec();
    Model24->select();
    ui->tableView_2->setModel(Model24);
    ui->tableView_2->resizeColumnsToContents();
}

void opciones::on_pushButton_16_clicked()
{
    QString Correo;
    Correo= ui->lineEdit_8->text();
    QSqlQuery query1(db);
    query1.exec("SELECT Correo FROM Smtp WHERE Correo='"+Correo+"'");
    query1.first();
    ui->tableView_2->model()->removeRow(fila0);
    ui->tableView_2->resizeColumnsToContents();
}

void opciones::on_pushButton_18_clicked()
{
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("smtp.gmail.com");
    ui->lineEdit_10->setText("");
    ui->checkBox_6->setChecked(true);
    ui->checkBox_5->setChecked(true);
    ui->lineEdit_12->setText("");
    ui->spinBox->setValue(465);
    ui->radioButton_54->setChecked(true);
    this->Smtp();
    ui->checkBox_7->setChecked(false);
}

void opciones::on_pushButton_15_clicked()
{
    QString Correo, Server, Clave, Autentic, SSL, User, Port, Dato;
    Correo=ui->lineEdit_8->text();
    if (ui->radioButton_54->isChecked())
    {
        if (!ui->lineEdit_8->text().contains("@gmail.com"))
        {
            ui->lineEdit_8->setText(ui->lineEdit_8->text()+"@gmail.com");
            Correo=ui->lineEdit_8->text();
        }
    }
    Server=ui->lineEdit_9->text();
    Clave=ui->lineEdit_10->text();
    if (ui->checkBox_6->isChecked())
        Autentic="Si";
    else
        Autentic="No";
    if (ui->checkBox_5->isChecked())
        SSL="Si";
    else
        SSL="No";
    User=ui->lineEdit_12->text();
    Port=ui->spinBox->text();
    QSqlQuery query(db);
    query.exec("SELECT Correo FROM Smtp WHERE Correo='"+Correo+"'");
    query.first();
    if (query.isValid())
        Dato=query.value(0).toString();
    if (Correo != Dato)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ningun correo creado con ese nombre."));
        m.exec();
        return;
    }
    if (Correo == "" || Server == "" || Clave == "" || Autentic == "" || SSL == "" || User == "" || Port == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No pueden haber datos vacios.<p>Todos los datos son necesarios para una perfecta configuracion."));
        m.exec();
        return;
    }
    QSqlRecord record= Model24->record(this->fila0);
    record.setValue(1,Correo);
    record.setValue(2,Server);
    record.setValue(3,Clave);
    record.setValue(4,Autentic);
    record.setValue(5,SSL);
    record.setValue(6,User);
    record.setValue(7,Port);
    Model24->setRecord(this->fila0,record);
    Model24->submitAll();
    ui->tableView_2->selectRow(0);
    ui->tableView_2->resizeColumnsToContents();
}

void opciones::on_pushButton_17_clicked()
{
    QMessageBox okMessage (this);
    QString Correo, Server, Clave, User, Port, Envio;
    bool SSL;
    bool Autentic;
    Correo=ui->lineEdit_8->text();
    if (ui->radioButton_54->isChecked())
    {
        if (!ui->lineEdit_8->text().contains("@gmail.com"))
        {
            ui->lineEdit_8->setText(ui->lineEdit_8->text()+"@gmail.com");
            Correo=ui->lineEdit_8->text();
        }
    }
    Server=ui->lineEdit_9->text();
    Clave=ui->lineEdit_10->text();
    Autentic = ui->checkBox_6->isChecked();
    SSL = ui->checkBox_5->isChecked();
    User=ui->lineEdit_12->text();
    Port=ui->spinBox->text();
    Envio=ui->lineEdit_11->text();
    if (Envio == "" || !Envio.contains("@"))
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Introduce una direccion de correo donde enviar la prueba."));
        m.exec();
    }
    SmtpClient smtp(Server, Port.toInt(), SSL ? SmtpClient::SslConnection : SmtpClient::TcpConnection);
    smtp.setUser(User);
    smtp.setPassword(Clave);
    MimeMessage message;
    message.setSender(new EmailAddress(Correo, User));
    message.addRecipient(new EmailAddress(Envio, Envio));
    message.setSubject(tr("Mensaje de prueba"));
    MimeText text;
    text.setText(tr("Hola!\n Esto es un mensaje de prueba."));
    message.addPart(&text);
    if (!smtp.connectToHost())
    {
        okMessage.setText(tr("La conexion ha fallado"));
        okMessage.exec();
        return;
    }
    if (Autentic)
        if (!smtp.login(User, Clave))
        {
            okMessage.setText(tr("La autentificacion ha fallado"));
            okMessage.exec();
            return;
        }

    if (!smtp.sendMail(message))
    {
        okMessage.setText(tr("El envio del mail ha fallado"));
        okMessage.exec();
        return;
    }
    else
    {
        okMessage.setText(tr("El email ha sido enviado con exito."));
        okMessage.exec();
    }
    smtp.quit();
}
