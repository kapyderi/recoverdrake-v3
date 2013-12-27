#include "usblive.h"
#include "ui_usblive.h"
#include "drakesistema.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QProcess>
#include <QTest>
#include <QProgressBar>
#include "drakeprocesos.h"
#include <QFile>
#include <QChar>
#include <QSqlQuery>

UsbLive::UsbLive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsbLive)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    drakeSistema drake;
    user = drake.getUser();
    DistroTip = drake.getDistrop();
    dist = drake.getDistribucion();
    if (DistroTip == "Mageia")
    {
        if (dist == "3")
            ruta = "/run/media/"+user+"/";
        else
            ruta = "/media/";
    }
    else
    {
        ruta = "/media/";
    }
    Duplicado = 0;
    Control = 0;
    TamanoTotal = 0;
    mib=0;
    Ctrl = 0;
    Marcado = 0;
    Stilo = "B";
    ui->progressBar->hide();
    ui->label_6->hide();
    Localizar = getPack();
    qemu= "qemu";
    if (Localizar.contains(qemu) == false)
    {
            qemu = "0";
    }
    else
    {
            qemu = "1";
    }
    connect(ui->tableWidget, SIGNAL(cellPressed(int,int)), this, SLOT(tableClicked(int,int)));
    connect(ui->radioButton_7,SIGNAL(clicked()),this,SLOT(Enable()));
    connect(ui->radioButton_12,SIGNAL(clicked()),this,SLOT(Disabled()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Disabled()));
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
    this->Arranque();    
}

UsbLive::~UsbLive()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void UsbLive::Arranque()
{    
    ui->comboBox->setEnabled(false);
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->label_8->setEnabled(false);
    ui->comboBox_2->setEnabled(false);
    ui->radioButton_5->setEnabled(false);
    ui->radioButton_6->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->label_31->setEnabled(false);
    ui->comboBox_3->setEnabled(false);
    ui->radioButton_9->setEnabled(false);
    ui->radioButton_10->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->label_39->setEnabled(false);
    ui->comboBox_4->setEnabled(false);
    ui->radioButton_13->setEnabled(false);
    ui->radioButton_14->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->label_46->setEnabled(false);
    ui->comboBox_5->setEnabled(false);
    ui->radioButton_17->setEnabled(false);
    ui->radioButton_18->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->label_91->setEnabled(false);
    ui->comboBox_6->setEnabled(false);
    ui->radioButton_39->setEnabled(false);
    ui->radioButton_40->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->label_101->setEnabled(false);
    ui->comboBox_7->setEnabled(false);
    ui->radioButton_43->setEnabled(false);
    ui->radioButton_44->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->label_110->setEnabled(false);
    ui->comboBox_8->setEnabled(false);
    ui->radioButton_55->setEnabled(false);
    ui->radioButton_56->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
    ui->label_136->setEnabled(false);
    ui->comboBox_9->setEnabled(false);
    ui->radioButton_51->setEnabled(false);
    ui->radioButton_52->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
    ui->label_127->setEnabled(false);
    ui->comboBox_10->setEnabled(false);
    ui->radioButton_47->setEnabled(false);
    ui->radioButton_48->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    ui->label_118->setEnabled(false);
    ui->radioButton->setChecked(true);
    ui->radioButton_5->setChecked(true);
    ui->radioButton_9->setChecked(true);
    ui->radioButton_13->setChecked(true);
    ui->radioButton_17->setChecked(true);
    ui->radioButton_39->setChecked(true);
    ui->radioButton_43->setChecked(true);
    ui->radioButton_55->setChecked(true);
    ui->radioButton_51->setChecked(true);
    ui->radioButton_47->setChecked(true);
    ui->tabWidget->setCurrentPage(0);
    if (DistroTip=="Mageia")
    {
        ui->radioButton_4->setEnabled(false);
        ui->radioButton_12->setChecked(true);
        ui->radioButton_7->setChecked(false);
        ui->radioButton_4->setChecked(false);
    }
    else
    {
        ui->radioButton_12->setChecked(true);
        ui->radioButton_7->setChecked(false);
        ui->radioButton_4->setChecked(false);
    }
    ui->radioButton_8->setChecked(true);
    ui->radioButton_11->setChecked(false);
}

void UsbLive::on_pushButton_6_clicked()
{
    ui->tabWidget->setCurrentPage(1);
}

void UsbLive::on_pushButton_9_clicked()
{
    ui->tabWidget->setCurrentPage(0);
}

void UsbLive::on_pushButton_7_clicked()
{
    close();
}

void UsbLive::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked() == true)
    {
        ui->comboBox->setEnabled(true);
        ui->radioButton->setEnabled(true);
        ui->radioButton_2->setEnabled(true);
        ui->label_8->setEnabled(true);
    }
    else
    {
        ui->comboBox->setEnabled(false);
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->label_8->setEnabled(false);
    }
}

void UsbLive::on_checkBox_2_clicked()
{
    if (ui->checkBox_2->isChecked() == true)
    {
        ui->comboBox_2->setEnabled(true);
        ui->radioButton_5->setEnabled(true);
        ui->radioButton_6->setEnabled(true);
        ui->label_31->setEnabled(true);
    }
    else
    {
        ui->comboBox_2->setEnabled(false);
        ui->radioButton_5->setEnabled(false);
        ui->radioButton_6->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->label_31->setEnabled(false);
    }
}

void UsbLive::on_checkBox_3_clicked()
{
    if (ui->checkBox_3->isChecked() == true)
    {
        ui->comboBox_3->setEnabled(true);
        ui->radioButton_9->setEnabled(true);
        ui->radioButton_10->setEnabled(true);
        ui->label_39->setEnabled(true);
    }
    else
    {
        ui->comboBox_3->setEnabled(false);
        ui->radioButton_9->setEnabled(false);
        ui->radioButton_10->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->label_39->setEnabled(false);
    }
}

void UsbLive::on_checkBox_4_clicked()
{
    if (ui->checkBox_4->isChecked() == true)
    {
        ui->comboBox_4->setEnabled(true);
        ui->radioButton_13->setEnabled(true);
        ui->radioButton_14->setEnabled(true);
        ui->label_46->setEnabled(true);
    }
    else
    {
        ui->comboBox_4->setEnabled(false);
        ui->radioButton_13->setEnabled(false);
        ui->radioButton_14->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->label_46->setEnabled(false);
    }
}

void UsbLive::on_checkBox_5_clicked()
{
    if (ui->checkBox_5->isChecked() == true)
    {
        ui->comboBox_5->setEnabled(true);
        ui->radioButton_17->setEnabled(true);
        ui->radioButton_18->setEnabled(true);
        ui->label_91->setEnabled(true);
    }
    else
    {
        ui->comboBox_5->setEnabled(false);
        ui->radioButton_17->setEnabled(false);
        ui->radioButton_18->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->label_91->setEnabled(false);
    }
}

void UsbLive::on_checkBox_6_clicked()
{
    if (ui->checkBox_6->isChecked() == true)
    {
        ui->comboBox_6->setEnabled(true);
        ui->radioButton_39->setEnabled(true);
        ui->radioButton_40->setEnabled(true);
        ui->label_101->setEnabled(true);
    }
    else
    {
        ui->comboBox_6->setEnabled(false);
        ui->radioButton_39->setEnabled(false);
        ui->radioButton_40->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->label_101->setEnabled(false);
    }
}

void UsbLive::on_checkBox_7_clicked()
{
    if (ui->checkBox_7->isChecked() == true)
    {
        ui->comboBox_7->setEnabled(true);
        ui->radioButton_43->setEnabled(true);
        ui->radioButton_44->setEnabled(true);
        ui->label_110->setEnabled(true);
    }
    else
    {
        ui->comboBox_7->setEnabled(false);
        ui->radioButton_43->setEnabled(false);
        ui->radioButton_44->setEnabled(false);
        ui->pushButton_10->setEnabled(false);
        ui->label_110->setEnabled(false);
    }
}

void UsbLive::on_checkBox_19_clicked()
{
    if (ui->checkBox_19->isChecked() == true)
    {
        ui->comboBox_8->setEnabled(true);
        ui->radioButton_55->setEnabled(true);
        ui->radioButton_56->setEnabled(true);
        ui->label_136->setEnabled(true);
    }
    else
    {
        ui->comboBox_8->setEnabled(false);
        ui->radioButton_55->setEnabled(false);
        ui->radioButton_56->setEnabled(false);
        ui->pushButton_14->setEnabled(false);
        ui->label_136->setEnabled(false);
    }
}

void UsbLive::on_checkBox_9_clicked()
{
    if (ui->checkBox_9->isChecked() == true)
    {
        ui->comboBox_9->setEnabled(true);
        ui->radioButton_51->setEnabled(true);
        ui->radioButton_52->setEnabled(true);
        ui->label_127->setEnabled(true);
    }
    else
    {
        ui->comboBox_9->setEnabled(false);
        ui->radioButton_51->setEnabled(false);
        ui->radioButton_52->setEnabled(false);
        ui->pushButton_13->setEnabled(false);
        ui->label_127->setEnabled(false);
    }
}

void UsbLive::on_checkBox_8_clicked()
{
    if (ui->checkBox_8->isChecked() == true)
    {
        ui->comboBox_10->setEnabled(true);
        ui->radioButton_47->setEnabled(true);
        ui->radioButton_48->setEnabled(true);
        ui->label_118->setEnabled(true);
    }
    else
    {
        ui->comboBox_10->setEnabled(false);
        ui->radioButton_47->setEnabled(false);
        ui->radioButton_48->setEnabled(false);
        ui->pushButton_12->setEnabled(false);
        ui->label_118->setEnabled(false);
    }
}

void UsbLive::on_radioButton_clicked()
{
    if (ui->radioButton->isChecked() == true)
        ui->pushButton->setEnabled(false);
    else
        ui->pushButton->setEnabled(true);
}

void UsbLive::on_radioButton_2_clicked()
{
    if (ui->radioButton_2->isChecked() == true)
        ui->pushButton->setEnabled(true);
    else
        ui->pushButton->setEnabled(false);
}

void UsbLive::on_radioButton_5_clicked()
{
    if (ui->radioButton_5->isChecked() == true)
        ui->pushButton_2->setEnabled(false);
    else
        ui->pushButton_2->setEnabled(true);
}

void UsbLive::on_radioButton_6_clicked()
{
    if (ui->radioButton_6->isChecked() == true)
        ui->pushButton_2->setEnabled(true);
    else
        ui->pushButton_2->setEnabled(false);
}

void UsbLive::on_radioButton_9_clicked()
{
    if (ui->radioButton_9->isChecked() == true)
        ui->pushButton_3->setEnabled(false);
    else
        ui->pushButton_3->setEnabled(true);
}

void UsbLive::on_radioButton_10_clicked()
{
    if (ui->radioButton_10->isChecked() == true)
        ui->pushButton_3->setEnabled(true);
    else
        ui->pushButton_3->setEnabled(false);
}

void UsbLive::on_radioButton_13_clicked()
{
    if (ui->radioButton_13->isChecked() == true)
        ui->pushButton_4->setEnabled(false);
    else
        ui->pushButton_4->setEnabled(true);
}

void UsbLive::on_radioButton_14_clicked()
{
    if (ui->radioButton_14->isChecked() == true)
        ui->pushButton_4->setEnabled(true);
    else
        ui->pushButton_4->setEnabled(false);
}

void UsbLive::on_radioButton_17_clicked()
{
    if (ui->radioButton_17->isChecked() == true)
        ui->pushButton_5->setEnabled(false);
    else
        ui->pushButton_5->setEnabled(true);
}

void UsbLive::on_radioButton_18_clicked()
{
    if (ui->radioButton_18->isChecked() == true)
        ui->pushButton_5->setEnabled(true);
    else
        ui->pushButton_5->setEnabled(false);
}

void UsbLive::on_radioButton_39_clicked()
{
    if (ui->radioButton_39->isChecked() == true)
        ui->pushButton_8->setEnabled(false);
    else
        ui->pushButton_8->setEnabled(true);
}

void UsbLive::on_radioButton_40_clicked()
{
    if (ui->radioButton_40->isChecked() == true)
        ui->pushButton_8->setEnabled(true);
    else
        ui->pushButton_8->setEnabled(false);
}

void UsbLive::on_radioButton_43_clicked()
{
    if (ui->radioButton_43->isChecked() == true)
        ui->pushButton_10->setEnabled(false);
    else
        ui->pushButton_10->setEnabled(true);
}

void UsbLive::on_radioButton_44_clicked()
{
    if (ui->radioButton_44->isChecked() == true)
        ui->pushButton_10->setEnabled(true);
    else
        ui->pushButton_10->setEnabled(false);
}

void UsbLive::on_radioButton_55_clicked()
{
    if (ui->radioButton_55->isChecked() == true)
        ui->pushButton_14->setEnabled(false);
    else
        ui->pushButton_14->setEnabled(true);
}

void UsbLive::on_radioButton_56_clicked()
{
    if (ui->radioButton_56->isChecked() == true)
        ui->pushButton_14->setEnabled(true);
    else
        ui->pushButton_14->setEnabled(false);
}

void UsbLive::on_radioButton_51_clicked()
{
    if (ui->radioButton_51->isChecked() == true)
        ui->pushButton_13->setEnabled(false);
    else
        ui->pushButton_13->setEnabled(true);
}

void UsbLive::on_radioButton_52_clicked()
{
    if (ui->radioButton_52->isChecked() == true)
        ui->pushButton_13->setEnabled(true);
    else
        ui->pushButton_13->setEnabled(false);
}

void UsbLive::on_radioButton_47_clicked()
{
    if (ui->radioButton_47->isChecked() == true)
        ui->pushButton_12->setEnabled(false);
    else
        ui->pushButton_12->setEnabled(true);
}

void UsbLive::on_radioButton_48_clicked()
{
    if (ui->radioButton_48->isChecked() == true)
        ui->pushButton_12->setEnabled(true);
    else
        ui->pushButton_12->setEnabled(false);
}

void UsbLive::on_pushButton_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de imagen de Mandriva .iso")),
                        path,trUtf8(tr("Imagen .iso (*.iso)")));
    if (fileNameOrigen.isEmpty())
         return;
    fileName = fileNameOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");    
    QString Version = ui->comboBox_11->currentText();
    Version = Version.split(".").value(0);
    QString Distribucion = ui->groupBox->title();
    QString Arquitectura;
    if (ui->comboBox->currentText() == "32bit")
    {
        Arquitectura = "i586";
    }
    else if (ui->comboBox->currentText() == "64bit")
    {
        Arquitectura = "x86_64";
    }
    if (fileNameOrigen.contains(Distribucion, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Version, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Arquitectura, Qt::CaseInsensitive) != true)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El nombre de la imagen debe contener "+Distribucion+", "+Arquitectura+" y "+Version+" para poder continuar."));
        m.exec();
        return;
    }
    ui->label_47->setText(fileNameOrigen);
}

void UsbLive::on_pushButton_2_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de imagen de PCLinuxOS.iso")),
                        path,trUtf8(tr("Imagen .iso (*.iso)")));
    if (fileNameOrigen.isEmpty())
         return;
    fileName1 = fileNameOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    QString Version = ui->comboBox_12->currentText();
    QString Distribucion = ui->groupBox_2->title();
    if (fileNameOrigen.contains(Distribucion, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Version, Qt::CaseInsensitive) != true)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El nombre de la imagen debe contener "+Distribucion+" y "+Version+" para poder continuar."));
        m.exec();
        return;
    }
    ui->label_80->setText(fileNameOrigen);
}

void UsbLive::on_pushButton_3_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de imagen de Fedora .iso")),
                        path,trUtf8(tr("Imagen .iso (*.iso)")));
    if (fileNameOrigen.isEmpty())
         return;
    fileName2 = fileNameOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    QString Version = ui->comboBox_13->currentText();
    Version = Version.split(".").value(0);
    QString Distribucion = ui->groupBox_3->title();
    QString Arquitectura;
    if (ui->comboBox_3->currentText() == "32bit")
    {
        Arquitectura = "i686";
    }
    else if (ui->comboBox_3->currentText() == "64bit")
    {
        Arquitectura = "x86_64";
    }
    if (fileNameOrigen.contains(Distribucion, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Version, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Arquitectura, Qt::CaseInsensitive) != true)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El nombre de la imagen debe contener "+Distribucion+", "+Arquitectura+" y "+Version+" para poder continuar."));
        m.exec();
        return;
    }
    ui->label_81->setText(fileNameOrigen);
}

void UsbLive::on_pushButton_4_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de imagen de Ubuntu .iso")),
                        path,trUtf8(tr("Imagen .iso (*.iso)")));
    if (fileNameOrigen.isEmpty())
         return;
    fileName3 = fileNameOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    QString Version = ui->comboBox_14->currentText();
    QString Distribucion;
    if (Version == "12.04")
    {
        Distribucion = "precise";
    }
    else
    {
        Distribucion = ui->groupBox_4->title();
    }
    QString Arquitectura;
    if (ui->comboBox_4->currentText() == "32bit")
    {
        Arquitectura = "i386";
    }
    else if (ui->comboBox_4->currentText() == "64bit")
    {
        Arquitectura = "amd64";
    }
    if (fileNameOrigen.contains(Distribucion, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Version, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Arquitectura, Qt::CaseInsensitive) != true)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El nombre de la imagen debe contener "+Distribucion+", "+Arquitectura+" y "+Version+" para poder continuar."));
        m.exec();
        return;
    }
    ui->label_81->setText(fileNameOrigen);
}

void UsbLive::on_pushButton_5_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de imagen de ArchLinux .iso")),
                        path,trUtf8(tr("Imagen .iso (*.iso)")));
    if (fileNameOrigen.isEmpty())
         return;
    fileName4 = fileNameOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    QString Version = ui->comboBox_15->currentText();
    QString Distribucion = ui->groupBox_5->title();
    QString Arquitectura = ui->comboBox_4->currentText();
    if (fileNameOrigen.contains(Distribucion, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Version, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Arquitectura, Qt::CaseInsensitive) != true)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El nombre de la imagen debe contener "+Distribucion+", "+Arquitectura+" y "+Version+" para poder continuar."));
        m.exec();
        return;
    }
    ui->label_89->setText(fileNameOrigen);
}

void UsbLive::on_pushButton_8_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de imagen de CentOS .iso")),
                        path,trUtf8(tr("Imagen .iso (*.iso)")));
    if (fileNameOrigen.isEmpty())
         return;
    fileName5 = fileNameOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    QString Version = ui->comboBox_16->currentText();
    QString Distribucion = ui->groupBox_6->title();
    QString Arquitectura;
    if (ui->comboBox_6->currentText() == "32bit")
    {
        Arquitectura = "i386";
    }
    else if (ui->comboBox_6->currentText() == "64bit")
    {
        Arquitectura = "x86_64";
    }
    if (fileNameOrigen.contains(Distribucion, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Version, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Arquitectura, Qt::CaseInsensitive) != true)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El nombre de la imagen debe contener "+Distribucion+", "+Arquitectura+" y "+Version+" para poder continuar."));
        m.exec();
        return;
    }
    ui->label_99->setText(fileNameOrigen);
}

void UsbLive::on_pushButton_10_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de imagen de Debian .iso")),
                        path,trUtf8(tr("Imagen .iso (*.iso)")));
    if (fileNameOrigen.isEmpty())
         return;
    fileName6 = fileNameOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    QString Version = ui->comboBox_17->currentText();
    QString Distribucion = ui->groupBox_7->title();
    QString Arquitectura;
    if (ui->comboBox_7->currentText() == "32bit")
    {
        Arquitectura = "i386";
    }
    else if (ui->comboBox_7->currentText() == "64bit")
    {
        Arquitectura = "amd64";
    }
    if (fileNameOrigen.contains(Distribucion, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Version, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Arquitectura, Qt::CaseInsensitive) != true)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El nombre de la imagen debe contener "+Distribucion+", "+Arquitectura+" y "+Version+" para poder continuar."));
        m.exec();
        return;
    }
    ui->label_108->setText(fileNameOrigen);
}

void UsbLive::on_pushButton_14_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de imagen de KNOPPIX .iso")),
                        path,trUtf8(tr("Imagen .iso (*.iso)")));
    if (fileNameOrigen.isEmpty())
         return;
    fileName7 = fileNameOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    QString Version = ui->comboBox_18->currentText();
    QString Distribucion = ui->groupBox_10->title();
    if (fileNameOrigen.contains(Distribucion, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Version, Qt::CaseInsensitive) != true)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El nombre de la imagen debe contener "+Distribucion+" y "+Version+" para poder continuar."));
        m.exec();
        return;
    }
    ui->label_134->setText(fileNameOrigen);
}

void UsbLive::on_pushButton_13_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de imagen de OpenSUSE .iso")),
                        path,trUtf8(tr("Imagen .iso (*.iso)")));
    if (fileNameOrigen.isEmpty())
         return;
    fileName8 = fileNameOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    QString Version = ui->comboBox_19->currentText();
    QString Distribucion = ui->groupBox_9->title();
    QString Arquitectura;
    if (ui->comboBox_9->currentText() == "32bit")
    {
        Arquitectura = "i686";
    }
    else if (ui->comboBox_9->currentText() == "64bit")
    {
        Arquitectura = "x86_64";
    }
    if (fileNameOrigen.contains(Distribucion, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Version, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Arquitectura, Qt::CaseInsensitive) != true)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El nombre de la imagen debe contener "+Distribucion+", "+Arquitectura+" y "+Version+" para poder continuar."));
        m.exec();
        return;
    }
    ui->label_125->setText(fileNameOrigen);
}

void UsbLive::on_pushButton_12_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de imagen de Gentoo .iso")),
                        path,trUtf8(tr("Imagen .iso (*.iso)")));
    if (fileNameOrigen.isEmpty())
         return;
    fileName9 = fileNameOrigen.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    QString Version = ui->comboBox_20->currentText();
    QString Distribucion = ui->groupBox_8->title();
    QString Arquitectura = ui->comboBox_10->currentText();
    if (fileNameOrigen.contains(Distribucion, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Version, Qt::CaseInsensitive) != true || fileNameOrigen.contains(Arquitectura, Qt::CaseInsensitive) != true)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El nombre de la imagen debe contener "+Distribucion+", "+Arquitectura+" y "+Version+" para poder continuar."));
        m.exec();
        return;
    }
    ui->label_116->setText(fileNameOrigen);
}

void UsbLive::on_pushButton_11_clicked()
{
    ui->tabWidget->setCurrentPage(2);
}

void UsbLive::UsbInfo()
{    
    ui->tabWidget->setCurrentPage(2);
    drakeSistema drake;
    Media = drake.getMedia();    
    if (Duplicado == 1)
        return;
    int Borrado, x;
    Borrado = ui->tableWidget->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    int iFilas;
    Lista = Media.split("\n");
    if (Lista.count() == 1)
    {
        if (Lista.value(0) == "")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Nada que procesar.<p>No hay nada en la ruta /media para procesar. Cambia a Syslinux/Isolinux o introduce un pendrive valido para continuar."));
            m.exec();
            return;
        }
        else
        {
            Value0 = Lista.value(0);
            Valor = Value0.split(" ");
            if (Valor.value(4) != "vfat")
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Nada que procesar.<p>No hay nada valido en la ruta /media para procesar. Cambia a Syslinux/Isolinux o introduce un pendrive valido para continuar."));
                m.exec();
                return;
            }
        }
    }
    for(int i=0;i<Lista.count();i++)
    {
        Value0 = Lista.value(i);
        if (Value0 != "")
        {
            Valor = Value0.split(" ");
            for(int a=0;a<Valor.count();a++)
            {
                if (a == 0)
                {
                    Parte1 = Valor.value(a);
                    Value1 = Parte1.left(8);
                    Peso = getTalla(Parte1);
                    Value4 = Parte1;
                    Value5 = Peso.left(33).right(8).remove(" ");
                    drakeSistema drake;
                    LabelOld = drake.getLabelOld(Value4);
                    LabelOld=LabelOld.remove("Volume label is ").remove(" ");
                    Value6 = LabelOld;
                }
                if (a == 2)
                {
                    Parte2 = Valor.value(a);
                    if (DistroTip=="Mageia")
                    {
                        if (dist == "3")
                            Value2 = Parte2.remove("/run/media/"+user+"/");
                        else
                            Value2 = Parte2.remove("/media/");
                    }
                    else
                        Value2 = Parte2.remove("/media/");
                }
                if (a == 4)
                {
                    Parte3 = Valor.value(a);
                    Value3 = Parte3;
                }
            }
        }
        if (Value3 == "vfat" && Value5 !="")
        {
            QTableWidgetItem *item1, *item2, *item3, *item4, *item5, *item6, *item7;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            item5=new QTableWidgetItem;
            item6=new QTableWidgetItem;
            item7=new QTableWidgetItem;
            item1->setText(""+Value1+"");
            item2->setText(""+Value2+"");
            item3->setText(""+Value3+"");
            item4->setText(""+Value4+"");
            item5->setText(""+Value5+"");
            item6->setText("");
            item7->setText(""+Value6+"");
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->setItem(iFilas,2,item3);
            ui->tableWidget->setItem(iFilas,3,item4);
            ui->tableWidget->setItem(iFilas,4,item5);
            ui->tableWidget->setItem(iFilas,5,item6);
            ui->tableWidget->setItem(iFilas,6,item7);
            ui->tableWidget->item(iFilas,5)->setIcon(QIcon(":/Imagenes/bad.png"));
        }
    }
    Duplicado=1;
}

void UsbLive::on_tabWidget_currentChanged(int /*index*/)
{
    if (ui->tabWidget->currentIndex() == 2)
        UsbInfo();
    else if (ui->tabWidget->currentIndex() == 3)
        Multiboot();
}

QString UsbLive::getTalla(QString Peso)
{
    QProcess *procesoFree, *procesoGrep;
    QStringList argumentosFree;
    QStringList argumentosGrep;
    QByteArray Total;

    procesoFree=new QProcess(this);
    procesoGrep=new QProcess(this);

    argumentosFree << "--block-size=G" << ""+Peso+"";
    argumentosGrep << ""+Peso+"";

    procesoFree->setStandardOutputProcess(procesoGrep);

    procesoFree->start("df", argumentosFree);
    procesoGrep->start("grep", argumentosGrep);

    if (! procesoGrep->waitForStarted())
        return QString("");

    procesoFree->waitForFinished();
    procesoGrep->waitForFinished();

    Total = procesoGrep->readAllStandardOutput();

    delete procesoFree;
    delete procesoGrep;    
    QString res = QString(Total);
    res.chop(0);
    return res;
}

void UsbLive::on_tableWidget_itemSelectionChanged()
{
    ui->textEdit->setText("");
    int Row = ui->tableWidget->currentRow();
    QTableWidgetItem *item1, *item2;
    item1=new QTableWidgetItem;
    item2=new QTableWidgetItem;
    item1=ui->tableWidget->item(Row,1);
    item2=ui->tableWidget->item(Row,2);
    QString valor1=item1->text();
    QString valor2= item2->text();
    if (valor2 == "vfat")
    {
        QString comando;
        if (DistroTip=="Mageia")
        {
            if (dist == "3")
            {
                comando="/run/media/"+user+"/%1";
                comando = comando.arg(valor1);
            }
            else
            {
                comando="/media/%1";
                comando = comando.arg(valor1);
            }
        }
        else
        {
            comando="/media/%1";
            comando = comando.arg(valor1);
        }
        QString Recibir = getTree(comando);
        ui->textEdit->setText(Recibir);
    }
}

QString UsbLive::getTree(QString Tree)
{
    QProcess *procesoTree;
    QStringList argumentosFree;
    QByteArray Total;

    procesoTree=new QProcess(this);

    argumentosFree << ""+Tree+"";

    procesoTree->start("tree", argumentosFree);

    if (! procesoTree->waitForStarted())
        return QString("");

    procesoTree->waitForFinished();

    Total = procesoTree->readAllStandardOutput();

    delete procesoTree;
    QString res = QString(Total);
    res.chop(0);
    return res;
}

void UsbLive::on_pushButton_18_clicked()
{
    ui->tabWidget->setCurrentPage(1);
}

void UsbLive::on_pushButton_19_clicked()
{    
    if (Marcado > 0)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Solo puede haber un USB marcado. Desactiva el marcado y vuelve a intentarlo."));
        m.exec();
        return;
    }
    else if (Marcado == 0)
    {
        int iFilas;
        QString valor;
        iFilas=ui->tableWidget->currentRow();
        if (iFilas == -1)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
            m.exec();
            return;
        }
        else
        {
            QTableWidgetItem *item;
            item=new QTableWidgetItem;
            item=ui->tableWidget->item(iFilas,5);
            valor=item->text();
            if(valor != "Ok")
            {
                ui->tableWidget->item(iFilas,5)->setIcon(QIcon(":/Imagenes/good.png"));
                item->setText("Ok");
                ui->tableWidget->setItem(iFilas,5,item);
                Marcado++;
            }
        }
    }
}

void UsbLive::on_pushButton_20_clicked()
{
    if (Marcado == 0)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Nada que desmarcar."));
        m.exec();
        return;
    }
    else if (Marcado > 0)
    {
        int iFilas;
        QString valor;
        iFilas=ui->tableWidget->currentRow();
        if (iFilas == -1)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
            m.exec();
            return;
        }
        else
        {
            QTableWidgetItem *item;
            item=new QTableWidgetItem;
            item=ui->tableWidget->item(iFilas,5);
            valor=item->text();
            if(valor == "Ok")
            {
                ui->tableWidget->item(iFilas,5)->setIcon(QIcon(":/Imagenes/bad.png"));
                item->setText("");
                ui->tableWidget->setItem(iFilas,5,item);
                Marcado--;
            }
        }
    }
}

void UsbLive::on_pushButton_15_clicked()
{
    Ctrl = 1;
    ui->label_4->hide();
    ui->textEdit->setText("");
    QTableWidgetItem *item, *item1, *item2;
    QString activo, activo1, activo2;
    QStringList comandos;
    int itemCount = ui->tableWidget->currentRow();
    if (itemCount == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {       
        item = ui->tableWidget->item(itemCount,3);
        item1 = ui->tableWidget->item(itemCount,5);
        item2 = ui->tableWidget->item(itemCount,1);
        activo = item->text();
        activo1 = item1->text();
        activo2 = item2->text();
        if (activo1 == "Ok")
        {
            int respuesta = 0;
            {
                respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Formatear USB")),
                                   QString::fromUtf8(tr("<center><b>Formatear USB<b></center><p>"

                                   "<b>Procede con mucha precaución.<p>"

                                   "&iquest;Estas seguro de querer formatear la unidad "+activo+" denominada "+activo2+"?")), QMessageBox::Ok, QMessageBox::No);
            }
            if (respuesta == QMessageBox::Ok){
                QString cm = QString::fromUtf8(tr("echo Desmontando USB..."));
                QString cmd1 = "umount %1";
                cmd1=cmd1.arg(activo);
                QString cm1= QString::fromUtf8(tr("echo Formateando USB..."));
                QString cmd2 = "mkfs.vfat -F 32 -n DRAKLIVE %2";
                cmd2=cmd2.arg(activo);
                QString cm2= QString::fromUtf8(tr("echo Montando USB..."));
                QString cmd4, cmd3;
                if (DistroTip=="Mageia")
                {
                    if (dist == "3")
                    {
                        cmd4 = "mkdir /run/media/"+user+"/DRAKLIVE";
                        cmd3 = "mount %1 /run/media/"+user+"/DRAKLIVE";
                        cmd3=cmd3.arg(activo);
                    }
                    else
                    {
                        cmd4 = "mkdir /media/DRAKLIVE";
                        cmd3 = "mount %1 /media/DRAKLIVE";
                        cmd3=cmd3.arg(activo);
                    }
                }
                else
                {
                    cmd4 = "mkdir /media/DRAKLIVE";
                    cmd3 = "mount %1 /media/DRAKLIVE";
                    cmd3=cmd3.arg(activo);
                }
                comandos << cm << cmd1 << cm1 << cmd2 << cm2 << cmd4 << cmd3;
                if (mib != 0)
                    delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                int valor= comandos.count(); mib->Valor(valor,2); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
            }
            return;
        }
        else
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("El USB seleccionado no esta activado, por lo que no puedes procesar la solicitud."));
            m.exec();
            return;
        }
    }
}

void UsbLive::on_pushButton_16_clicked()
{
    Duplicado=0;
    UsbInfo();
}

QString UsbLive::getPack()
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

void UsbLive::on_pushButton_17_clicked()
{    
    ui->tabWidget->setCurrentPage(3);
}

void UsbLive::Multiboot()
{
    TamanoTotal = 0;
    Control = 0;
    ui->textEdit_3->setText("");
    ui->textEdit_2->setText("");
    comandos.clear();
    grub.clear();
    QTableWidgetItem *item1, *item2, *item3, *item4, *item5;
    int itemCount;
    if (ui->radioButton_7->isChecked() == false)
    {
        int Sumar = 0;
        itemCount = ui->tableWidget->rowCount();
        for(int a=0;a<itemCount;a++)
        {
            item1 = ui->tableWidget->item(a,5);
            activo1=item1->text();
            if (activo1 == "Ok")
            {
                Sumar++;
            }
        }
        itemCount = Sumar;
    }
    else if (ui->radioButton_7->isChecked() == true)
    {
        itemCount = 1;
    }
    if (itemCount == -1 || itemCount == 0)
    {
        if (ui->radioButton_7->isChecked() == false)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No has seleccionado ningun USB, por lo que no puedes procesar la solicitud. Solo funcionara en modo Syslinux/Isolinux."));
            m.exec();
            return ui->tabWidget->setCurrentPage(2);
        }        
    }
    else
    {
        if (ui->radioButton_7->isChecked() == true)
        {
            QString path="/home/%1/";
            path=path.arg(user);
            fileNameDirectori = QFileDialog::getExistingDirectory(this,QString::fromUtf8(tr("Donde guardar la iso resultante?")),path,QFileDialog::ShowDirsOnly);
            if (fileNameDirectori.isEmpty())
                return ui->tabWidget->setCurrentPage(2);
        }
        for(int i=0;i<itemCount;i++)
        {
            if (ui->radioButton_7->isChecked() == false)
            {
                item1 = ui->tableWidget->item(i,5);
                item2 = ui->tableWidget->item(i,1);
                item3 = ui->tableWidget->item(i,0);
                item4 = ui->tableWidget->item(i,3);
                item5 = ui->tableWidget->item(i,4);
                activo1 = item1->text();
                activo2 = item2->text();
                activo3 = item3->text();
                activo4 = item4->text();
                activo5 = item5->text();
            }
            if (ui->radioButton_7->isChecked() == true)
            {
                activo1 = "Ok";
            }
            if (activo1 == "Ok")
            {
                if (ui->radioButton_7->isChecked() == false)
                {
                    Valor1 = activo3;
                    QString Localizar = getDistroIns(""+ruta+""+activo2+"/boot/grub/", "menu.lst");
                    QString TipGrub3 = getIso(""+ruta+""+activo2+"/boot/");
                    TipGrub3.remove("/");
                    QString Localizar1;
                    if (TipGrub3 == "grub")
                    {
                        Localizar1 = getDistroIns(""+ruta+""+activo2+"/boot/grub/", "grub.cfg");
                    }
                    else if (TipGrub3 == "grub2")
                    {
                        Localizar1 = getDistroIns(""+ruta+""+activo2+"/boot/grub2/", "grub.cfg");
                    }
//                    QString Localizar2 = getDistroIns(""+ruta+""+activo2+"/draklive/", "syslinux.cfg");
                    if (Localizar == "menu.lst")
                    {
                        ui->radioButton_12->setChecked(true);
                        ui->radioButton_4->setChecked(false);
                        ui->radioButton_7->setChecked(false);
                    }
                    else if (Localizar1 == "grub.cfg")
                    {
                        ui->radioButton_12->setChecked(false);
                        ui->radioButton_4->setChecked(true);
                        ui->radioButton_7->setChecked(false);
                    }
//                    else if (Localizar2 == "syslinux.cfg")
//                    {
//                        ui->radioButton_12->setChecked(false);
//                        ui->radioButton_4->setChecked(false);
//                        ui->radioButton_7->setChecked(true);
//                    }
                }
                if (ui->radioButton_12->isChecked())
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">Menu de arranque en pendrive: GRUB (GRand Unifier Bootloader)");
                }
                else if(ui->radioButton_4->isChecked())
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">Menu de arranque en pendrive: GRUB2 (GRand Unifier Bootloader 2)");
                }
                else if(ui->radioButton_7->isChecked())
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">Menu de arranque en CD/DVD: Syslinux/Isolinux");
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">Se guardara MultibootDrake.iso en la ruta: "+fileNameDirectori+"");
                }
                ui->textEdit_3->append("");
                if (ui->radioButton_7->isChecked() == false)
                {
                    drakeSistema drake;
                    LabelOld = drake.getLabelOld(activo4);
                    LabelOld=LabelOld.remove("Volume label is ").remove(" ").remove("\n");
                    if (LabelOld != "DRAKLIVE")
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"RED\">Etiqueta de Pendrive: "+LabelOld+" (Se renombrara para plena compatibilidad).");
                        QString label0 = "echo Renombrando etiqueta de USB...";
                        QString label1 = "mlabel -i %1 ::DRAKLIVE";
                        label1=label1.arg(activo4);
                        comandos << label0 << label1;
                    }
                    else if (LabelOld == "DRAKLIVE")
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">Etiqueta de Pendrive: Correcta ("+LabelOld+").");
                    }
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">Ruta de la Unidad: "+activo4+".");
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">Nombre asignado por el punto de montaje: "+activo2+".");
                    ui->textEdit_3->append("");
                    QString Localizar3 = getDistroIns(""+ruta+""+activo2+"/", "boot");
                    Localizar3=Localizar3.remove("/");
                    QString Localizar4 = getDistroIns(""+ruta+""+activo2+"/", "draklive");
                    Localizar4=Localizar4.remove("/");
                    if (Localizar4 == "draklive" || Localizar3 == "boot")
                    {
                        ui->radioButton_8->setChecked(true);
                        ui->radioButton_11->setChecked(false);
                    }
                    else
                    {
                        ui->radioButton_8->setChecked(false);
                        ui->radioButton_11->setChecked(true);
                    }
                    if(ui->radioButton_8->isChecked())
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">Tipo de instalacion: Seguir instalando Distros.");
                    }
                    else if(ui->radioButton_11->isChecked())
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"RED\">Tipo de instalacion: Nueva instalacion. SE PERDERAN TODOS LOS DATOS ANTERIORES.");
                    }
                    ui->textEdit_3->append("");
                }                
                if (ui->checkBox->isChecked() == true)
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">1) Instalar Mandriva: Si");
                    if (ui->radioButton_2->isChecked() == true)
                    {
                        if (ui->label_47->text() == "")
                        {
                            Control++;
                            ui->textEdit_3->append("<FONT COLOR=\"RED\">- ERROR("+QString::number(Control)+"): Ruta iso/Mandriva en equipo: NO SE HA DEFINIDO NINGUNA RUTA y NO SE PUEDE CONTINUAR.");
                        }
                        else if(ui->label_47->text() != "")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Mandriva_"+ui->comboBox_11->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Mandriva_"+ui->comboBox_11->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira.");
                            }
                            else
                            {
                                TipMandriva = "Mandriva";
                                QFile file(ui->label_47->text());
                                qint64 size = QFileInfo(file).size();
                                float f;
                                f=(size + 1023) / 1024;
                                f=(f/1024)/1024;
                                TamanoTotal = TamanoTotal + f;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Ruta iso/Mandriva en equipo: "+ui->label_47->text()+"");
                                QString md11 = tr("echo Creando directorio Mandriva_"+ui->comboBox_11->currentText()+"...");
                                QString mdd9, md12, mdd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    mdd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    mdd9 = mdd9.arg(user).arg(TipMandriva).arg(ui->comboBox_11->currentText());
                                    md12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    mdd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    mdd10 = mdd10.arg(user).arg(ui->label_47->text()).arg(TipMandriva).arg(ui->comboBox_11->currentText());
                                }
                                else
                                {
                                    mdd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    mdd9 = mdd9.arg(activo2);
                                    md12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    mdd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    mdd10 = mdd10.arg(activo2).arg(user).arg(ui->label_47->text()).arg(TipMandriva).arg(ui->comboBox_11->currentText());
                                }
                                comandos << md11 << mdd9 << md12 << mdd10;
                            }
                        }
                    }
                    else if (ui->radioButton_2->isChecked() == false)
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Descargar iso/Mandriva del servidor: Si");
                        if (ui->comboBox->currentText() ==  "32bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Mandriva32_"+ui->comboBox_11->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Mandriva32_"+ui->comboBox_11->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira.");
                            }
                            else
                            {
                                QString Mandriva;
                                TipMandriva = "Mandriva32";
                                QString Mandriva1 = "Mandriva";
                                QSqlQuery query(db);
                                query.exec("SELECT Direccion FROM Distro WHERE NomDistro='"+Mandriva1+"' AND Version='"+ui->comboBox_11->currentText()+"' AND Arquitectura='"+ui->comboBox->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    Mandriva=query.value(0).toString();
                                QStringList ParcIso = Mandriva.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "1638 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_11->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+Mandriva+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString md3 = tr("echo Descargando del servidor...");
                                QString mdd1 = "wget -c -P/home/%1/tmp/ %2";
                                mdd1=mdd1.arg(user).arg(Mandriva);
                                QString md15 = tr("echo Creando directorio Mandriva32_"+ui->comboBox_11->currentText()+"...");
                                QString mdd13, md16, mdd14;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    mdd13 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    mdd13 = mdd13.arg(user).arg(TipMandriva).arg(ui->comboBox_11->currentText());
                                    md16 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    mdd14 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    mdd14 = mdd14.arg(user).arg(TipMandriva).arg(Iso).arg(ui->comboBox_11->currentText());
                                }
                                else
                                {
                                    mdd13 = "mkdir -pv "+ruta+"%1/iso/";
                                    mdd13 = mdd13.arg(activo2);
                                    md16 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    mdd14 = "file-roller --force --extract-to="+ruta+"%1/iso/%3_%5/ /home/%2/tmp/%4";
                                    mdd14 = mdd14.arg(activo2).arg(user).arg(TipMandriva).arg(Iso).arg(ui->comboBox_11->currentText());
                                }
                                comandos << md3 << mdd1 << md15 << mdd13 << md16 << mdd14;
                            }
                        }
                        else if(ui->comboBox->currentText() == "64bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Mandriva64_"+ui->comboBox_11->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Mandriva64_"+ui->comboBox_11->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString Mandriva;
                                TipMandriva = "Mandriva64";
                                QString Mandriva1 = "Mandriva";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+Mandriva1+"' AND Version='"+ui->comboBox_11->currentText()+"' AND Arquitectura='"+ui->comboBox->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                        Mandriva=query.value(0).toString();
                                QStringList ParcIso = Mandriva.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "1740 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_11->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+Mandriva+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString md3 = tr("echo Descargando del servidor...");
                                QString mdd1 = "wget -c -P/home/%1/tmp/ %2";
                                mdd1=mdd1.arg(user).arg(Mandriva);
                                QString md15 = tr("echo Creando directorio Mandriva64_"+ui->comboBox_11->currentText()+"...");
                                QString mdd13, md16, mdd14;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    mdd13 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    mdd13 = mdd13.arg(user).arg(TipMandriva).arg(ui->comboBox_11->currentText());
                                    md16 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    mdd14 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    mdd14 = mdd14.arg(user).arg(TipMandriva).arg(Iso).arg(ui->comboBox_11->currentText());
                                }
                                else
                                {
                                    mdd13 = "mkdir -pv "+ruta+"%1/iso/";
                                    mdd13 = mdd13.arg(activo2);
                                    md16 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    mdd14 = "file-roller --force --extract-to="+ruta+"%1/iso/%3_%5/ /home/%2/tmp/%4";
                                    mdd14 = mdd14.arg(activo2).arg(user).arg(TipMandriva).arg(Iso).arg(ui->comboBox_11->currentText());
                                }
                                comandos << md3 << mdd1 << md15 << mdd13 << md16 << mdd14;
                            }
                        }
                    }
                }
                else if (ui->checkBox->isChecked() == false)
                {
                    TipMandriva = "";
                    ui->textEdit_3->append("<FONT COLOR=\"RED\">1) Instalar Mandriva: No");
                }
                ui->textEdit_3->append("");
                if (ui->checkBox_2->isChecked() == true)
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">2) Instalar PCLinuxOS: Si");
                    if (ui->radioButton_6->isChecked() == true)
                    {
                        if (ui->label_80->text() == "")
                        {
                            Control++;
                            ui->textEdit_3->append("<FONT COLOR=\"RED\">- ERROR("+QString::number(Control)+"): Ruta iso/PCLinuxOS en equipo: NO SE HA DEFINIDO NINGUNA RUTA y NO SE PUEDE CONTINUAR");
                        }
                        else if(ui->label_80->text() != "")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "PCLinuxOS_"+ui->comboBox_12->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "PCLinuxOS_"+ui->comboBox_12->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                TipPCLinuxOS = "PCLinuxOS";
                                QFile file(ui->label_80->text());
                                qint64 size = QFileInfo(file).size();
                                float f;
                                f=(size + 1023) / 1024;
                                f=(f/1024)/1024;
                                TamanoTotal = TamanoTotal + f;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Ruta iso/PCLinuxOS en equipo: "+ui->label_80->text()+"");
                                QString pc11 = tr("echo Creando directorio PCLinuxOS_"+ui->comboBox_12->currentText()+"...");
                                QString pcd9, pc12, pcd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    pcd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    pcd9 = pcd9.arg(user).arg(TipPCLinuxOS).arg(ui->comboBox_12->currentText());
                                    pc12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    pcd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    pcd10 = pcd10.arg(user).arg(ui->label_80->text()).arg(TipPCLinuxOS).arg(ui->comboBox_12->currentText());
                                }
                                else
                                {
                                    pcd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    pcd9 = pcd9.arg(activo2);
                                    pc12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    pcd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    pcd10 = pcd10.arg(activo2).arg(user).arg(ui->label_80->text()).arg(TipPCLinuxOS).arg(ui->comboBox_12->currentText());
                                }
                                comandos << pc11 << pcd9 << pc12 << pcd10;
                            }
                        }
                    }
                    else if (ui->radioButton_6->isChecked() == false)
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Descargar iso/PCLinuxOS del servidor: Si");
                        if (ui->comboBox_2->currentText() ==  "32bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "PCLinuxOS_"+ui->comboBox_12->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "PCLinuxOS_"+ui->comboBox_12->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString PCLinuxOS;
                                TipPCLinuxOS = "PCLinuxOS";
                                QString PCLinuxOS1 = "PCLinuxOS";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+PCLinuxOS1+"' AND Version='"+ui->comboBox_12->currentText()+"' AND Arquitectura='"+ui->comboBox_2->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    PCLinuxOS=query.value(0).toString();
                                QStringList ParcIso = PCLinuxOS.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "690 b";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_2->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_12->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+PCLinuxOS+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString pc3 = tr("echo Descargando del servidor...");
                                QString pcd1 = "wget -c -P/home/%1/tmp/ %2";
                                pcd1=pcd1.arg(user).arg(PCLinuxOS);
                                QString pc15 = tr("echo Creando directorio PCLinuxOS32_"+ui->comboBox_12->currentText()+"...");
                                QString pcd13, pc16, pcd14;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    pcd13 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    pcd13 = pcd13.arg(user).arg(TipPCLinuxOS).arg(ui->comboBox_12->currentText());
                                    pc16 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    pcd14 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    pcd14 = pcd14.arg(user).arg(TipPCLinuxOS).arg(Iso).arg(ui->comboBox_12->currentText());
                                }
                                else
                                {
                                    pcd13 = "mkdir -pv "+ruta+"%1/iso/";
                                    pcd13 = pcd13.arg(activo2);
                                    pc16 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    pcd14 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    pcd14 = pcd14.arg(activo2).arg(user).arg(TipPCLinuxOS).arg(Iso).arg(ui->comboBox_12->currentText());
                                }
                                comandos << pc3 << pcd1 << pc15 << pcd13 << pc16 << pcd14;
                            }
                        }
                    }
                }
                else if (ui->checkBox_2->isChecked() == false)
                {
                    TipPCLinuxOS = "";
                    ui->textEdit_3->append("<FONT COLOR=\"RED\">2) Instalar PCLinuxOS: No");
                }
                ui->textEdit_3->append("");
                if (ui->checkBox_3->isChecked() == true)
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">3) Instalar Fedora: Si");
                    if (ui->radioButton_10->isChecked() == true)
                    {
                        if (ui->label_81->text() == "")
                        {
                            Control++;
                            ui->textEdit_3->append("<FONT COLOR=\"RED\">- ERROR("+QString::number(Control)+"): Ruta iso/Fedora en equipo: NO SE HA DEFINIDO NINGUNA RUTA y NO SE PUEDE CONTINUAR.");
                        }
                        else if(ui->label_81->text() != "")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Fedora_"+ui->comboBox_13->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Fedora_"+ui->comboBox_13->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                TipFedora = "Fedora";
                                QFile file(ui->label_81->text());
                                qint64 size = QFileInfo(file).size();
                                float f;
                                f=(size + 1023) / 1024;
                                f=(f/1024)/1024;
                                TamanoTotal = TamanoTotal + f;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Ruta iso/Fedora en equipo: "+ui->label_81->text()+"");
                                QString fd11 = tr("echo Creando directorio Fedora_"+ui->comboBox_13->currentText()+"...");
                                QString fdd9, fd12, fdd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    fdd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    fdd9 = fdd9.arg(user).arg(TipFedora).arg(ui->comboBox_13->currentText());
                                    fd12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    fdd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    fdd10 = fdd10.arg(user).arg(ui->label_81->text()).arg(TipFedora).arg(ui->comboBox_13->currentText());
                                }
                                else
                                {
                                    fdd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    fdd9 = fdd9.arg(activo2);
                                    fd12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    fdd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    fdd10 = fdd10.arg(activo2).arg(user).arg(ui->label_81->text()).arg(TipFedora).arg(ui->comboBox_13->currentText());
                                }
                                comandos << fd11 << fdd9 << fd12 << fdd10;
                            }
                        }
                    }
                    else if (ui->radioButton_10->isChecked() == false)
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Descargar iso/Fedora del servidor: Si");
                        if (ui->comboBox_2->currentText() ==  "32bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Fedora32_"+ui->comboBox_13->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Fedora32_"+ui->comboBox_13->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString Fedora;
                                TipFedora = "Fedora32";
                                QString Fedora1 = "Fedora";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+Fedora1+"' AND Version='"+ui->comboBox_13->currentText()+"' AND Arquitectura='"+ui->comboBox_3->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    Fedora=query.value(0).toString();
                                QStringList ParcIso = Fedora.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "697 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_3->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_13->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+Fedora+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString fe3 = tr("echo Descargando del servidor...");
                                QString fed1 = "wget -c -P/home/%1/tmp/ %2";
                                fed1=fed1.arg(user).arg(Fedora);
                                QString fe15 = tr("echo Creando directorio Fedora32_"+ui->comboBox_13->currentText()+"...");
                                QString fdd9, fd12, fdd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    fdd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    fdd9 = fdd9.arg(user).arg(TipFedora).arg(ui->comboBox_13->currentText());
                                    fd12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    fdd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    fdd10 = fdd10.arg(user).arg(TipFedora).arg(Iso).arg(ui->comboBox_13->currentText());
                                }
                                else
                                {
                                    fdd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    fdd9 = fdd9.arg(activo2);
                                    fd12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    fdd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    fdd10 = fdd10.arg(activo2).arg(user).arg(TipFedora).arg(Iso).arg(ui->comboBox_13->currentText());
                                }
                                comandos << fe3 << fed1 << fe15 << fdd9 << fd12 << fdd10;
                            }
                        }
                        else if(ui->comboBox_2->currentText() == "64bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Fedora64_"+ui->comboBox_13->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Fedora64_"+ui->comboBox_13->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString Fedora;
                                TipFedora = "Fedora64";
                                QString Fedora1 = "Fedora";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+Fedora1+"' AND Version='"+ui->comboBox_13->currentText()+"' AND Arquitectura='"+ui->comboBox_3->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    Fedora=query.value(0).toString();
                                QStringList ParcIso = Fedora.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "696 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_3->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_13->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+Fedora+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString fe3 = tr("echo Descargando del servidor...");
                                QString fed1 = "wget -c -P/home/%1/tmp/ %2";
                                fed1=fed1.arg(user).arg(Fedora);
                                QString fe15 = tr("echo Creando directorio Fedora64_"+ui->comboBox_13->currentText()+"...");
                                QString fdd9, fd12, fdd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    fdd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    fdd9 = fdd9.arg(user).arg(TipFedora).arg(ui->comboBox_13->currentText());
                                    fd12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    fdd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    fdd10 = fdd10.arg(user).arg(TipFedora).arg(Iso).arg(ui->comboBox_13->currentText());
                                }
                                else
                                {
                                    fdd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    fdd9 = fdd9.arg(activo2);
                                    fd12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    fdd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    fdd10 = fdd10.arg(activo2).arg(user).arg(TipFedora).arg(Iso).arg(ui->comboBox_13->currentText());
                                }
                                comandos << fe3 << fed1 << fe15 << fdd9 << fd12 << fdd10;
                            }
                        }
                    }
                }
                else if (ui->checkBox_3->isChecked() == false)
                {
                    ui->textEdit_3->append("<FONT COLOR=\"RED\">3) Instalar Fedora: No");
                }
                ui->textEdit_3->append("");
                if (ui->checkBox_4->isChecked() == true)
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">4) Instalar Ubuntu: Si");
                    if (ui->radioButton_14->isChecked() == true)
                    {
                        if (ui->label_82->text() == "")
                        {
                            Control++;
                            ui->textEdit_3->append("<FONT COLOR=\"RED\">- ERROR("+QString::number(Control)+"): Ruta iso/Ubuntu en equipo: NO SE HA DEFINIDO NINGUNA RUTA y NO SE PUEDE CONTINUAR.");
                        }
                        else if(ui->label_82->text() != "")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Ubuntu_"+ui->comboBox_14->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Ubuntu_"+ui->comboBox_14->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                TipUbuntu = "Ubuntu";
                                QFile file(ui->label_82->text());
                                qint64 size = QFileInfo(file).size();
                                float f;
                                f=(size + 1023) / 1024;
                                f=(f/1024)/1024;
                                TamanoTotal = TamanoTotal + f;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Ruta iso/Ubuntu en equipo: "+ui->label_82->text()+"");
                                QString ub11 = tr("echo Creando directorio Ubuntu_"+ui->comboBox_14->currentText()+"...");
                                QString ubd9, ub12, ubd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    ubd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    ubd9 = ubd9.arg(user).arg(TipUbuntu).arg(ui->comboBox_14->currentText());
                                    ub12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ubd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    ubd10 = ubd10.arg(user).arg(ui->label_82->text()).arg(TipUbuntu).arg(ui->comboBox_14->currentText());
                                }
                                else
                                {
                                    ubd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    ubd9 = ubd9.arg(activo2);
                                    ub12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ubd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    ubd10 = ubd10.arg(activo2).arg(user).arg(ui->label_82->text()).arg(TipUbuntu).arg(ui->comboBox_14->currentText());
                                }
                                comandos << ub11 << ubd9 << ub12 << ubd10;
                            }
                        }
                    }
                    else if (ui->radioButton_14->isChecked() == false)
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Descargar iso/Ubuntu del servidor: Si");
                        if (ui->comboBox_4->currentText() ==  "32bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Ubuntu32_"+ui->comboBox_14->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Ubuntu32_"+ui->comboBox_14->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString Ubuntu;
                                TipUbuntu = "Ubuntu32";
                                QString Ubuntu1 = "Ubuntu";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+Ubuntu1+"' AND Version='"+ui->comboBox_14->currentText()+"' AND Arquitectura='"+ui->comboBox_4->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    Ubuntu=query.value(0).toString();
                                QStringList ParcIso = Ubuntu.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "701 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_4->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_14->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+Ubuntu+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");                                
                                QString ub3 = tr("echo Descargando del servidor...");
                                QString ubd1 = "wget -c -P/home/%1/tmp/ %2";
                                ubd1=ubd1.arg(user).arg(Ubuntu);
                                QString ub15 = tr("echo Creando directorio Ubuntu32_"+ui->comboBox_14->currentText()+"...");
                                QString ubd9, ub12, ubd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    ubd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    ubd9 = ubd9.arg(user).arg(TipUbuntu).arg(ui->comboBox_14->currentText());
                                    ub12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ubd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    ubd10 = ubd10.arg(user).arg(TipUbuntu).arg(Iso).arg(ui->comboBox_14->currentText());
                                }
                                else
                                {
                                    ubd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    ubd9 = ubd9.arg(activo2);
                                    ub12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ubd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    ubd10 = ubd10.arg(activo2).arg(user).arg(TipUbuntu).arg(Iso).arg(ui->comboBox_14->currentText());
                                }
                                comandos << ub3 << ubd1 << ub15 << ubd9 << ub12 << ubd10;
                            }
                        }
                        else if(ui->comboBox_4->currentText() == "64bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Ubuntu64_"+ui->comboBox_14->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Ubuntu64_"+ui->comboBox_14->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString Ubuntu;
                                TipUbuntu = "Ubuntu64";
                                QString Ubuntu1 = "Ubuntu";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+Ubuntu1+"' AND Version='"+ui->comboBox_14->currentText()+"' AND Arquitectura='"+ui->comboBox_4->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    Ubuntu=query.value(0).toString();
                                QStringList ParcIso = Ubuntu.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "698 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_4->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_14->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+Ubuntu+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString ub3 = tr("echo Descargando del servidor...");
                                QString ubd1 = "wget -c -P/home/%1/tmp/ %2";
                                ubd1=ubd1.arg(user).arg(Ubuntu);
                                QString ub15 = tr("echo Creando directorio Ubuntu64_"+ui->comboBox_14->currentText()+"...");
                                QString ubd9, ub12, ubd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    ubd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    ubd9 = ubd9.arg(user).arg(TipUbuntu).arg(ui->comboBox_14->currentText());
                                    ub12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ubd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    ubd10 = ubd10.arg(user).arg(TipUbuntu).arg(Iso).arg(ui->comboBox_14->currentText());
                                }
                                else
                                {
                                    ubd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    ubd9 = ubd9.arg(activo2);
                                    ub12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ubd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    ubd10 = ubd10.arg(activo2).arg(user).arg(TipUbuntu).arg(Iso).arg(ui->comboBox_14->currentText());
                                }
                                comandos << ub3 << ubd1 << ub15 << ubd9 << ub12 << ubd10;
                            }
                        }
                    }
                }
                else if (ui->checkBox_4->isChecked() == false)
                {
                    TipUbuntu = "";
                    ui->textEdit_3->append("<FONT COLOR=\"RED\">4) Instalar Ubuntu: No");
                }
                ui->textEdit_3->append("");
                if (ui->checkBox_5->isChecked() == true)
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">5) Instalar ArchLinux: Si");
                    if (ui->radioButton_18->isChecked() == true)
                    {
                        if (ui->label_89->text() == "")
                        {
                            Control++;
                            ui->textEdit_3->append("<FONT COLOR=\"RED\">- ERROR("+QString::number(Control)+"): Ruta iso/ArchLinux en equipo: NO SE HA DEFINIDO NINGUNA RUTA y NO SE PUEDE CONTINUAR");
                        }
                        else if(ui->label_89->text() != "")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "ArchLinux_"+ui->comboBox_15->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "ArchLinux_"+ui->comboBox_15->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                TipArchLinux = "ArchLinux";
                                QFile file(ui->label_89->text());
                                qint64 size = QFileInfo(file).size();
                                float f;
                                f=(size + 1023) / 1024;
                                f=(f/1024)/1024;
                                TamanoTotal = TamanoTotal + f;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Ruta iso/ArchLinux en equipo: "+ui->label_89->text()+"");
                                QString ar11 = tr("echo Creando directorio ArchLinux_"+ui->comboBox_15->currentText()+"...");
                                QString ard9, ar12, ard10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    ard9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    ard9 = ard9.arg(user).arg(TipArchLinux).arg(ui->comboBox_15->currentText());
                                    ar12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ard10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    ard10 = ard10.arg(user).arg(ui->label_89->text()).arg(TipArchLinux).arg(ui->comboBox_15->currentText());
                                }
                                else
                                {
                                    ard9 = "mkdir -pv "+ruta+"%1/iso/";
                                    ard9 = ard9.arg(activo2);
                                    ar12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ard10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    ard10 = ard10.arg(activo2).arg(user).arg(ui->label_89->text()).arg(TipArchLinux).arg(ui->comboBox_15->currentText());
                                }
                                comandos << ar11 << ard9 << ar12 << ard10;
                            }
                        }
                    }
                    else if (ui->radioButton_18->isChecked() == false)
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Descargar iso/ArchLinux del servidor: Si");
                        if (ui->comboBox_5->currentText() ==  "Dual")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "ArchLinux_"+ui->comboBox_15->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "ArchLinux_"+ui->comboBox_15->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString ArchLinux;
                                TipArchLinux = "ArchLinux";
                                QString ArchLinux1 = "ArchLinux";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+ArchLinux1+"' AND Version='"+ui->comboBox_15->currentText()+"' AND Arquitectura='"+ui->comboBox_5->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    ArchLinux=query.value(0).toString();
                                QStringList ParcIso = ArchLinux.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "673 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_5->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_15->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+ArchLinux+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString ar3 = tr("echo Descargando del servidor...");
                                QString ard1 = "wget -c -P/home/%1/tmp/ %2";
                                ard1=ard1.arg(user).arg(ArchLinux);
                                QString ar15 = tr("echo Creando directorio ArchLinux_"+ui->comboBox_15->currentText()+"...");
                                QString ard9, ar12, ard10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    ard9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    ard9 = ard9.arg(user).arg(TipArchLinux).arg(ui->comboBox_15->currentText());
                                    ar12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ard10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    ard10 = ard10.arg(user).arg(ui->label_89->text()).arg(TipArchLinux).arg(ui->comboBox_15->currentText());
                                }
                                else
                                {
                                    ard9 = "mkdir -pv "+ruta+"%1/iso/";
                                    ard9 = ard9.arg(activo2);
                                    ar12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ard10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    ard10 = ard10.arg(activo2).arg(user).arg(ui->label_89->text()).arg(TipArchLinux).arg(ui->comboBox_15->currentText());
                                }
                                comandos << ar3 << ard1 << ar15 << ard9 << ar12 << ard10;
                            }
                        }
                    }
                }
                else if (ui->checkBox_5->isChecked() == false)
                {
                    TipArchLinux = "";
                    ui->textEdit_3->append("<FONT COLOR=\"RED\">5) Instalar ArchLinux: No");
                }
                ui->textEdit_3->append("");
                if (ui->checkBox_6->isChecked() == true)
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">6) Instalar CentOS: Si");
                    if (ui->radioButton_40->isChecked() == true)
                    {
                        if (ui->label_99->text() == "")
                        {
                            Control++;
                            ui->textEdit_3->append("<FONT COLOR=\"RED\">- ERROR("+QString::number(Control)+"): Ruta iso/CentOS en equipo: NO SE HA DEFINIDO NINGUNA RUTA y NO SE PUEDE CONTINUAR.");
                        }
                        else if(ui->label_99->text() != "")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "CentOS_"+ui->comboBox_16->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "CentOS_"+ui->comboBox_16->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                TipCentOS = "CentOS";
                                QFile file(ui->label_99->text());
                                qint64 size = QFileInfo(file).size();
                                float f;
                                f=(size + 1023) / 1024;
                                f=(f/1024)/1024;
                                TamanoTotal = TamanoTotal + f;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Ruta iso/CentOS en equipo: "+ui->label_99->text()+"");
                                QString ct11 = tr("echo Creando directorio CentOS_"+ui->comboBox_16->currentText()+"...");
                                QString ctd9, ct12, ctd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    ctd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    ctd9 = ctd9.arg(user).arg(TipCentOS).arg(ui->comboBox_16->currentText());
                                    ct12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ctd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    ctd10 = ctd10.arg(user).arg(ui->label_99->text()).arg(TipCentOS).arg(ui->comboBox_16->currentText());
                                }
                                else
                                {
                                    ctd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    ctd9 = ctd9.arg(activo2);
                                    ct12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ctd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    ctd10 = ctd10.arg(activo2).arg(user).arg(ui->label_99->text()).arg(TipCentOS).arg(ui->comboBox_16->currentText());
                                }
                                comandos << ct11 << ctd9 << ct12 << ctd10;
                            }
                        }
                    }
                    else if (ui->radioButton_40->isChecked() == false)
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Descargar iso/CentOS del servidor: Si");
                        if (ui->comboBox_6->currentText() ==  "32bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "CentOS32_"+ui->comboBox_16->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "CentOS32_"+ui->comboBox_16->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString CentOS;
                                TipCentOS = "CentOS32";
                                QString CentOS1 = "CentOS";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+CentOS1+"' AND Version='"+ui->comboBox_16->currentText()+"' AND Arquitectura='"+ui->comboBox_6->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    CentOS=query.value(0).toString();
                                QStringList ParcIso = CentOS.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "696 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_6->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_16->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+CentOS+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString ct3 = tr("echo Descargando del servidor...");
                                QString ctd1 = "wget -c -P/home/%1/tmp/ %2";
                                ctd1=ctd1.arg(user).arg(CentOS);
                                QString ct15 = tr("echo Creando directorio CentOS32_"+ui->comboBox_16->currentText()+"...");
                                QString ctd9, ct12, ctd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    ctd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    ctd9 = ctd9.arg(user).arg(TipCentOS).arg(ui->comboBox_16->currentText());
                                    ct12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ctd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    ctd10 = ctd10.arg(user).arg(ui->label_99->text()).arg(TipCentOS).arg(ui->comboBox_16->currentText());
                                }
                                else
                                {
                                    ctd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    ctd9 = ctd9.arg(activo2);
                                    ct12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ctd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    ctd10 = ctd10.arg(activo2).arg(user).arg(ui->label_99->text()).arg(TipCentOS).arg(ui->comboBox_16->currentText());
                                }
                                comandos << ct3 << ctd1 << ct15 << ctd9 << ct12 << ctd10;
                            }
                        }
                        else if(ui->comboBox_6->currentText() == "64bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "CentOS64_"+ui->comboBox_16->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "CentOS64_"+ui->comboBox_16->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString CentOS;
                                TipCentOS = "CentOS64";
                                QString CentOS1 = "CentOS";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+CentOS1+"' AND Version='"+ui->comboBox_16->currentText()+"' AND Arquitectura='"+ui->comboBox_6->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    CentOS=query.value(0).toString();
                                QStringList ParcIso = CentOS.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "698 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_6->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_16->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+CentOS+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString ct3 = tr("echo Descargando del servidor...");
                                QString ctd1 = "wget -c -P/home/%1/tmp/ %2";
                                ctd1=ctd1.arg(user).arg(CentOS);
                                QString ct15 = tr("echo Creando directorio CentOS64_"+ui->comboBox_16->currentText()+"...");
                                QString ctd9, ct12, ctd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    ctd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    ctd9 = ctd9.arg(user).arg(TipCentOS).arg(ui->comboBox_16->currentText());
                                    ct12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ctd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    ctd10 = ctd10.arg(user).arg(ui->label_99->text()).arg(TipCentOS).arg(ui->comboBox_16->currentText());
                                }
                                else
                                {
                                    ctd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    ctd9 = ctd9.arg(activo2);
                                    ct12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    ctd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    ctd10 = ctd10.arg(activo2).arg(user).arg(ui->label_99->text()).arg(TipCentOS).arg(ui->comboBox_16->currentText());
                                }
                                comandos << ct3 << ctd1 << ct15 << ctd9 << ct12 << ctd10;
                            }
                        }
                    }
                }
                else if (ui->checkBox_6->isChecked() == false)
                {
                    TipCentOS = "";
                    ui->textEdit_3->append("<FONT COLOR=\"RED\">6) Instalar CentOS: No");
                }
                ui->textEdit_3->append("");
                if (ui->checkBox_7->isChecked() == true)
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">7) Instalar Debian: Si");
                    if (ui->radioButton_44->isChecked() == true)
                    {
                        if (ui->label_108->text() == "")
                        {
                            Control++;
                            ui->textEdit_3->append("<FONT COLOR=\"RED\">- ERROR("+QString::number(Control)+"): Ruta iso/Debian en equipo: NO SE HA DEFINIDO NINGUNA RUTA y NO SE PUEDE CONTINUAR.");
                        }
                        else if(ui->label_108->text() != "")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Debian_"+ui->comboBox_17->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Debian_"+ui->comboBox_17->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                TipDebian = "Debian";
                                QFile file(ui->label_108->text());
                                qint64 size = QFileInfo(file).size();
                                float f;
                                f=(size + 1023) / 1024;
                                f=(f/1024)/1024;
                                TamanoTotal = TamanoTotal + f;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Ruta iso/Debian en equipo: "+ui->label_108->text()+"");
                                QString db11 = tr("echo Creando directorio Debian_"+ui->comboBox_17->currentText()+"...");
                                QString dbd9, db12, dbd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    dbd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    dbd9 = dbd9.arg(user).arg(TipDebian).arg(ui->comboBox_17->currentText());
                                    db12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    dbd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    dbd10 = dbd10.arg(user).arg(ui->label_108->text()).arg(TipDebian).arg(ui->comboBox_17->currentText());
                                }
                                else
                                {
                                    dbd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    dbd9 = dbd9.arg(activo2);
                                    db12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    dbd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    dbd10 = dbd10.arg(activo2).arg(user).arg(ui->label_108->text()).arg(TipDebian).arg(ui->comboBox_17->currentText());
                                }
                                comandos << db11 << dbd9 << db12 << dbd10;
                            }
                        }
                    }
                    else if (ui->radioButton_44->isChecked() == false)
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Descargar iso/Debian del servidor: Si");
                        if (ui->comboBox_7->currentText() ==  "32bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Debian32_"+ui->comboBox_17->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Debian32_"+ui->comboBox_17->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString Debian;
                                TipDebian = "Debian32";
                                QString Debian1 = "Debian";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+Debian1+"' AND Version='"+ui->comboBox_17->currentText()+"' AND Arquitectura='"+ui->comboBox_7->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    Debian=query.value(0).toString();
                                QStringList ParcIso = Debian.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "1024 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_7->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_17->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+Debian+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString db3 = tr("echo Descargando del servidor...");
                                QString dbd1 = "wget -c -P/home/%1/tmp/ %2";
                                dbd1=dbd1.arg(user).arg(Debian);
                                QString db15 = tr("echo Creando directorio Debian32_"+ui->comboBox_17->currentText()+"...");
                                QString dbd9, db12, dbd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    dbd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    dbd9 = dbd9.arg(user).arg(TipDebian).arg(ui->comboBox_17->currentText());
                                    db12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    dbd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    dbd10 = dbd10.arg(user).arg(ui->label_108->text()).arg(TipDebian).arg(ui->comboBox_17->currentText());
                                }
                                else
                                {
                                    dbd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    dbd9 = dbd9.arg(activo2);
                                    db12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    dbd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    dbd10 = dbd10.arg(activo2).arg(user).arg(ui->label_108->text()).arg(TipDebian).arg(ui->comboBox_17->currentText());
                                }
                                comandos << db3 << dbd1 << db15 << dbd9 << db12 << dbd10;
                            }
                        }
                        else if(ui->comboBox_7->currentText() == "64bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Debian64_"+ui->comboBox_17->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Debian64_"+ui->comboBox_17->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString Debian;
                                TipDebian = "Debian64";
                                QString Debian1 = "Debian";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+Debian1+"' AND Version='"+ui->comboBox_17->currentText()+"' AND Arquitectura='"+ui->comboBox_7->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    Debian=query.value(0).toString();
                                QStringList ParcIso = Debian.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "1024 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_7->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_17->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+Debian+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString db3 = tr("echo Descargando del servidor...");
                                QString dbd1 = "wget -c -P/home/%1/tmp/ %2";
                                dbd1=dbd1.arg(user).arg(Debian);
                                QString db15 = tr("echo Creando directorio Debian64_"+ui->comboBox_17->currentText()+"...");
                                QString dbd9, db12, dbd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    dbd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    dbd9 = dbd9.arg(user).arg(TipDebian).arg(ui->comboBox_17->currentText());
                                    db12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    dbd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    dbd10 = dbd10.arg(user).arg(ui->label_108->text()).arg(TipDebian).arg(ui->comboBox_17->currentText());
                                }
                                else
                                {
                                    dbd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    dbd9 = dbd9.arg(activo2);
                                    db12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    dbd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    dbd10 = dbd10.arg(activo2).arg(user).arg(ui->label_108->text()).arg(TipDebian).arg(ui->comboBox_17->currentText());
                                }
                                comandos << db3 << dbd1 << db15 << dbd9 << db12 << dbd10;
                            }
                        }
                    }
                }
                else if (ui->checkBox_7->isChecked() == false)
                {
                    TipDebian = "";
                    ui->textEdit_3->append("<FONT COLOR=\"RED\">7) Instalar Debian: No");
                }
                ui->textEdit_3->append("");
                if (ui->checkBox_19->isChecked() == true)
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">8) Instalar Knoppix: Si");
                    if (ui->radioButton_56->isChecked() == true)
                    {
                        if (ui->label_134->text() == "")
                        {
                            Control++;
                            ui->textEdit_3->append("<FONT COLOR=\"RED\">- ERROR("+QString::number(Control)+"): Ruta iso/Knoppix en equipo: NO SE HA DEFINIDO NINGUNA RUTA y NO SE PUEDE CONTINUAR");
                        }
                        else if(ui->label_134->text() != "")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Knoppix_"+ui->comboBox_18->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Knoppix_"+ui->comboBox_18->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                TipKnoppix = "Knoppix";
                                QFile file(ui->label_134->text());
                                qint64 size = QFileInfo(file).size();
                                float f;
                                f=(size + 1023) / 1024;
                                f=(f/1024)/1024;
                                TamanoTotal = TamanoTotal + f;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Ruta iso/Knoppix en equipo: "+ui->label_134->text()+"");
                                QString kn11 = tr("echo Creando directorio Knoppix_"+ui->comboBox_18->currentText()+"...");
                                QString knd9, kn12, knd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    knd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    knd9 = knd9.arg(user).arg(TipKnoppix).arg(ui->comboBox_18->currentText());
                                    kn12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    knd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    knd10 = knd10.arg(user).arg(ui->label_134->text()).arg(TipKnoppix).arg(ui->comboBox_18->currentText());
                                }
                                else
                                {
                                    knd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    knd9 = knd9.arg(activo2);
                                    kn12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    knd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    knd10 = knd10.arg(activo2).arg(user).arg(ui->label_134->text()).arg(TipKnoppix).arg(ui->comboBox_18->currentText());
                                }
                                comandos << kn11 << knd9 << kn12 << knd10;
                            }
                        }
                    }
                    else if (ui->radioButton_56->isChecked() == false)
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Descargar iso/Knoppix del servidor: Si");
                        if (ui->comboBox_8->currentText() ==  "32bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "Knoppix_"+ui->comboBox_18->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "Knoppix_"+ui->comboBox_18->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString Knoppix;
                                TipKnoppix = "Knoppix";
                                QString Knoppix1 = "Knoppix";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+Knoppix1+"' AND Version='"+ui->comboBox_18->currentText()+"' AND Arquitectura='"+ui->comboBox_8->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    Knoppix=query.value(0).toString();
                                QStringList ParcIso = Knoppix.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "700 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_8->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_18->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+Knoppix+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString kn3 = tr("echo Descargando del servidor...");
                                QString knd1 = "wget -c -P/home/%1/tmp/ %2";
                                knd1=knd1.arg(user).arg(Knoppix);
                                QString kn15 = tr("echo Creando directorio Knoppix32_"+ui->comboBox_18->currentText()+"...");
                                QString knd9, kn12, knd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    knd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    knd9 = knd9.arg(user).arg(TipKnoppix).arg(ui->comboBox_18->currentText());
                                    kn12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    knd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    knd10 = knd10.arg(user).arg(ui->label_134->text()).arg(TipKnoppix).arg(ui->comboBox_18->currentText());
                                }
                                else
                                {
                                    knd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    knd9 = knd9.arg(activo2);
                                    kn12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    knd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    knd10 = knd10.arg(activo2).arg(user).arg(ui->label_134->text()).arg(TipKnoppix).arg(ui->comboBox_18->currentText());
                                }
                                comandos << kn3 << knd1 << kn15 << knd9 << kn12 << knd10;
                            }
                        }
                    }
                }
                else if (ui->checkBox_19->isChecked() == false)
                {
                    TipKnoppix = "";
                    ui->textEdit_3->append("<FONT COLOR=\"RED\">8) Instalar Knoppix: No");
                }
                ui->textEdit_3->append("");
                if (ui->checkBox_9->isChecked() == true)
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">9) Instalar OpenSUSE: Si");
                    if (ui->radioButton_52->isChecked() == true)
                    {
                        if (ui->label_125->text() == "")
                        {
                            Control++;
                            ui->textEdit_3->append("<FONT COLOR=\"RED\">- ERROR("+QString::number(Control)+"): Ruta iso/OpenSUSE en equipo: NO SE HA DEFINIDO NINGUNA RUTA y NO SE PUEDE CONTINUAR.");
                        }
                        else if(ui->label_125->text() != "")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "OpenSUSE_"+ui->comboBox_19->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "OpenSUSE_"+ui->comboBox_19->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                TipOpenSUSE = "OpenSUSE";
                                QFile file(ui->label_125->text());
                                qint64 size = QFileInfo(file).size();
                                float f;
                                f=(size + 1023) / 1024;
                                f=(f/1024)/1024;
                                TamanoTotal = TamanoTotal + f;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Ruta iso/OpenSUSE en equipo: "+ui->label_125->text()+"");
                                QString op11 = tr("echo Creando directorio OpenSUSE_"+ui->comboBox_19->currentText()+"...");
                                QString opd9, op12, opd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    opd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    opd9 = opd9.arg(user).arg(TipOpenSUSE).arg(ui->comboBox_19->currentText());
                                    op12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    opd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    opd10 = opd10.arg(user).arg(ui->label_125->text()).arg(TipOpenSUSE).arg(ui->comboBox_19->currentText());
                                }
                                else
                                {
                                    opd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    opd9 = opd9.arg(activo2);
                                    op12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    opd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    opd10 = opd10.arg(activo2).arg(user).arg(ui->label_125->text()).arg(TipOpenSUSE).arg(ui->comboBox_19->currentText());
                                }
                                comandos << op11 << opd9 << op12 << opd10;
                            }
                        }
                    }
                    else if (ui->radioButton_52->isChecked() == false)
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Descargar iso/OpenSUSE del servidor: Si");
                        if (ui->comboBox_9->currentText() ==  "32bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "OpenSUSE32_"+ui->comboBox_19->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "OpenSUSE32_"+ui->comboBox_19->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString OpenSUSE;
                                TipOpenSUSE = "OpenSUSE32";
                                QString OpenSUSE1 = "OpenSUSE";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+OpenSUSE1+"' AND Version='"+ui->comboBox_19->currentText()+"' AND Arquitectura='"+ui->comboBox_9->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    OpenSUSE=query.value(0).toString();
                                QStringList ParcIso = OpenSUSE.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "662 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_9->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_19->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+OpenSUSE+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString op3 = tr("echo Descargando del servidor...");
                                QString opd1 = "wget -c -P/home/%1/tmp/ %2";
                                opd1=opd1.arg(user).arg(OpenSUSE);
                                QString op15 = tr("echo Creando directorio OpenSUSE32_"+ui->comboBox_19->currentText()+"...");
                                QString opd9, op12, opd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    opd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    opd9 = opd9.arg(user).arg(TipOpenSUSE).arg(ui->comboBox_19->currentText());
                                    op12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    opd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    opd10 = opd10.arg(user).arg(ui->label_125->text()).arg(TipOpenSUSE).arg(ui->comboBox_19->currentText());
                                }
                                else
                                {
                                    opd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    opd9 = opd9.arg(activo2);
                                    op12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    opd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    opd10 = opd10.arg(activo2).arg(user).arg(ui->label_125->text()).arg(TipOpenSUSE).arg(ui->comboBox_19->currentText());
                                }
                                comandos << op3 << opd1 << op15 << opd9 << op12 << opd10;
                            }
                        }
                        else if(ui->comboBox_9->currentText() == "64bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "OpenSUSE64_"+ui->comboBox_19->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "OpenSUSE64_"+ui->comboBox_19->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString OpenSUSE;
                                TipOpenSUSE = "OpenSUSE64";
                                QString OpenSUSE1 = "OpenSUSE";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+OpenSUSE1+"' AND Version='"+ui->comboBox_19->currentText()+"' AND Arquitectura='"+ui->comboBox_9->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    OpenSUSE=query.value(0).toString();
                                QStringList ParcIso = OpenSUSE.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "675 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_9->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_19->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+OpenSUSE+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString op3 = tr("echo Descargando del servidor...");
                                QString opd1 = "wget -c -P/home/%1/tmp/ %2";
                                opd1=opd1.arg(user).arg(OpenSUSE);
                                QString op15 = tr("echo Creando directorio OpenSUSE64_"+ui->comboBox_19->currentText()+"...");
                                QString opd9, op12, opd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    opd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    opd9 = opd9.arg(user).arg(TipOpenSUSE).arg(ui->comboBox_19->currentText());
                                    op12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    opd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    opd10 = opd10.arg(user).arg(ui->label_125->text()).arg(TipOpenSUSE).arg(ui->comboBox_19->currentText());
                                }
                                else
                                {
                                    opd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    opd9 = opd9.arg(activo2);
                                    op12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    opd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    opd10 = opd10.arg(activo2).arg(user).arg(ui->label_125->text()).arg(TipOpenSUSE).arg(ui->comboBox_19->currentText());
                                }
                                comandos << op3 << opd1 << op15 << opd9 << op12 << opd10;
                            }
                        }
                    }
                }
                else if (ui->checkBox_9->isChecked() == false)
                {
                    TipOpenSUSE = "";
                    ui->textEdit_3->append("<FONT COLOR=\"RED\">9) Instalar OpenSUSE: No");
                }
                ui->textEdit_3->append("");
                if (ui->checkBox_8->isChecked() == true)
                {
                    ui->textEdit_3->append("<FONT COLOR=\"BLUE\">10) Instalar LinuxMint: Si");
                    if (ui->radioButton_48->isChecked() == true)
                    {
                        if (ui->label_116->text() == "")
                        {
                            Control++;
                            ui->textEdit_3->append("<FONT COLOR=\"RED\">- ERROR("+QString::number(Control)+"): Ruta iso/LinuxMint en equipo: NO SE HA DEFINIDO NINGUNA RUTA y NO SE PUEDE CONTINUAR.");
                        }
                        else if(ui->label_116->text() != "")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "LinuxMint_"+ui->comboBox_20->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "LinuxMint_"+ui->comboBox_20->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                TipLinuxMint = "LinuxMint";
                                QFile file(ui->label_116->text());
                                qint64 size = QFileInfo(file).size();
                                float f;
                                f=(size + 1023) / 1024;
                                f=(f/1024)/1024;
                                TamanoTotal = TamanoTotal + f;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Ruta iso/LinuxMint en equipo: "+ui->label_116->text()+"");
                                QString lm11 = tr("echo Creando directorio LinuxMint_"+ui->comboBox_20->currentText()+"...");
                                QString lmd9, lm12, lmd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    lmd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    lmd9 = lmd9.arg(user).arg(TipLinuxMint).arg(ui->comboBox_20->currentText());
                                    lm12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    lmd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    lmd10 = lmd10.arg(user).arg(ui->label_116->text()).arg(TipLinuxMint).arg(ui->comboBox_20->currentText());
                                }
                                else
                                {
                                    lmd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    lmd9 = lmd9.arg(activo2);
                                    lm12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    lmd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    lmd10 = lmd10.arg(activo2).arg(user).arg(ui->label_116->text()).arg(TipLinuxMint).arg(ui->comboBox_20->currentText());
                                }
                                comandos << lm11 << lmd9 << lm12 << lmd10;
                            }
                        }
                    }
                    else if (ui->radioButton_48->isChecked() == false)
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Descargar iso/LinuxMint del servidor: Si");
                        if (ui->comboBox_10->currentText() ==  "32bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "LinuxMint32_"+ui->comboBox_20->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "LinuxMint32_"+ui->comboBox_20->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString LinuxMint;
                                TipLinuxMint = "LinuxMint32";
                                QString LinuxMint1 = "LinuxMint";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+LinuxMint1+"' AND Version='"+ui->comboBox_20->currentText()+"' AND Arquitectura='"+ui->comboBox_10->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    LinuxMint=query.value(0).toString();
                                QStringList ParcIso = LinuxMint.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "1106 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_10->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_20->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+LinuxMint+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString lm3 = tr("echo Descargando del servidor...");
                                QString lmd1 = "wget -c -P/home/%1/tmp/ %2";
                                lmd1=lmd1.arg(user).arg(LinuxMint);
                                QString lm15 = tr("echo Creando directorio LinuxMint32_"+ui->comboBox_20->currentText()+"...");
                                QString lmd9, lm12, lmd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    lmd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    lmd9 = lmd9.arg(user).arg(TipLinuxMint).arg(ui->comboBox_20->currentText());
                                    lm12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    lmd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    lmd10 = lmd10.arg(user).arg(ui->label_116->text()).arg(TipLinuxMint).arg(ui->comboBox_20->currentText());
                                }
                                else
                                {
                                    lmd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    lmd9 = lmd9.arg(activo2);
                                    lm12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    lmd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    lmd10 = lmd10.arg(activo2).arg(user).arg(ui->label_116->text()).arg(TipLinuxMint).arg(ui->comboBox_20->currentText());
                                }
                                comandos << lm3 << lmd1 << lm15 << lmd9 << lm12 << lmd10;
                            }
                        }
                        else if(ui->comboBox_10->currentText() == "64bit")
                        {
                            QString Localizar = getDistroIns(""+ruta+""+activo2+"/iso/", "LinuxMint64_"+ui->comboBox_20->currentText()+"");
                            Localizar=Localizar.remove("/");
                            if (Localizar == "LinuxMint64_"+ui->comboBox_20->currentText()+"")
                            {
                                 ui->textEdit_3->append("<FONT COLOR=\"RED\">Ya esta instalada, se omitira");
                            }
                            else
                            {
                                QString LinuxMint;
                                TipLinuxMint = "LinuxMint64";
                                QString LinuxMint1 = "LinuxMint";
                                QSqlQuery query(db);
                                query.exec("SELECT direccion FROM Distro WHERE NomDistro='"+LinuxMint1+"' AND Version='"+ui->comboBox_20->currentText()+"' AND Arquitectura='"+ui->comboBox_10->currentText()+"'");
                                query.first();
                                if (query.isValid())
                                    LinuxMint=query.value(0).toString();
                                QStringList ParcIso = LinuxMint.split("/");
                                int TamIso = ParcIso.count();
                                QString Iso = ParcIso.value(TamIso-1);
                                Tamano = "675 Mb";
                                QString TamanoMb = Tamano.remove(" ").remove("M").remove("b");
                                TamanoTotal = (TamanoMb.toFloat()/1024)+TamanoTotal;
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Arquitectura: "+ui->comboBox_10->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Version: "+ui->comboBox_20->currentText()+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Direccion de descarga: "+LinuxMint+"");
                                ui->textEdit_3->append("<FONT COLOR=\"BLUE\">- Peso de la descarga: "+Tamano+" Mb");
                                QString lm3 = tr("echo Descargando del servidor...");
                                QString lmd1 = "wget -c -P/home/%1/tmp/ %2";
                                lmd1=lmd1.arg(user).arg(LinuxMint);
                                QString lm15 = tr("echo Creando directorio LinuxMint64_"+ui->comboBox_20->currentText()+"...");
                                QString lmd9, lm12, lmd10;
                                if (ui->radioButton_7->isChecked() == true)
                                {
                                    lmd9 = "mkdir -pv /home/%1/tmp/boot/boot/%2_%3";
                                    lmd9 = lmd9.arg(user).arg(TipLinuxMint).arg(ui->comboBox_20->currentText());
                                    lm12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    lmd10 = "file-roller --force --extract-to=/home/%1/tmp/boot/boot/%2_%4/ /home/%1/tmp/%3";
                                    lmd10 = lmd10.arg(user).arg(ui->label_116->text()).arg(TipLinuxMint).arg(ui->comboBox_20->currentText());
                                }
                                else
                                {
                                    lmd9 = "mkdir -pv "+ruta+"%1/iso/";
                                    lmd9 = lmd9.arg(activo2);
                                    lm12 = tr("echo Copiando ficheros al pendrive. Puede tardar un tiempo, segun capacidad de la iso...");
                                    lmd10 = "file-roller --force --extract-to="+ruta+"%1/iso/%4_%5/ /home/%2/tmp/%3";
                                    lmd10 = lmd10.arg(activo2).arg(user).arg(ui->label_116->text()).arg(TipLinuxMint).arg(ui->comboBox_20->currentText());
                                }
                                comandos << lm3 << lmd1 << lm15 << lmd9 << lm12 << lmd10;
                            }
                        }
                    }
                }
                else if (ui->checkBox_8->isChecked() == false)
                {
                    TipLinuxMint = "";
                    ui->textEdit_3->append("<FONT COLOR=\"RED\">10) Instalar LinuxMint: No");
                }
                ui->textEdit_3->append("");
                int Total;
                if (ui->radioButton_7->isChecked() == false)
                {
                    activo5 = activo5.remove("G");
                    Total = activo5.toFloat();
                    if (TamanoTotal > Total)
                    {
                        Control++;
                        ui->textEdit_3->append("<FONT COLOR=\"RED\">ERROR("+QString::number(Control)+"): Total Gigas a grabar ("+QString::number(TamanoTotal,'f',3)+" Gb) superior a la capacidad del pendrive ("+activo5+" Gb)");
                        ui->textEdit_3->append("");
                    }
                    else if (TamanoTotal < Total)
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">Total Gigas a grabar en Pendrive: "+QString::number(TamanoTotal,'f',3)+" Gb. de ("+activo5+" Gb)");
                        ui->textEdit_3->append("");
                    }
                }
                else if (ui->radioButton_7->isChecked() == true)
                {
                    Total = float(9.40);
                    if (TamanoTotal > Total)
                    {
                        Control++;
                        ui->textEdit_3->append("<FONT COLOR=\"RED\">ERROR("+QString::number(Control)+"): Total Gigas a grabar ("+QString::number(TamanoTotal,'f',3)+" Gb) superior a la capacidad del DVD de mayor capacidad (9.400 Gb)");
                        ui->textEdit_3->append("");
                    }
                    else if (TamanoTotal < Total)
                    {
                        ui->textEdit_3->append("<FONT COLOR=\"BLUE\">Total Gigas a grabar en DVD de mayor capacidad: "+QString::number(TamanoTotal,'f',3)+" Gb. de (9.400 Gb)");
                        ui->textEdit_3->append("");
                    }
                }
                if (TamanoTotal == 0)
                {
                    Control++;
                    ui->textEdit_3->append("<FONT COLOR=\"RED\">ERROR("+QString::number(Control)+"): Ninguna Distro que instalar o ya estan instaladas, revisa las distros marcadas. No se puede continuar.");
                    ui->textEdit_3->append("");
                }
                if (Control > 0)
                {
                    ui->label_5->setText(tr("<FONT COLOR=\"RED\">Datos de Configuración (Hay ")+QString::number(Control)+tr(" errores sin solucionar):"));
                }
                if (ui->radioButton_12->isChecked() == true)
                {
                    QString TipGrub1 = getGrub("/sbin/grub-install");
                    if (ui->radioButton_8->isChecked() == false)
                    {
                        if (TipGrub1 == "")
                        {
                            QMessageBox m;
                            if (Stilo == "A")
                                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                            m.setText(tr("No tienes instalado grub en tu sistema y es necesario para este proposito. Por favor instalalo si quieres continuar."));
                            m.exec();
                            return;
                        }
                        else if (TipGrub1 == "/sbin/grub-install")
                        {
                            QString gru1 = "echo instalando grub en el USB...";
                            QString grub1 = "/sbin/grub-install --root-directory="+ruta+"%1 %2 --no-floppy";
                            grub1 = grub1.arg(activo2).arg(activo3);
                            comandos << gru1 << grub1;
                        }
                        QString Kill = "echo Creando fichero de mapeo de unidades y menu.lst...";
                        QString Kill0 = "rm -vR -f "+ruta+"%1/boot/grub/device.map";
                        Kill0 = Kill0.arg(activo2);
                        QString Kill1 = "touch "+ruta+"%1/boot/grub/device.map";
                        Kill1 = Kill1.arg(activo2);
                        QString Kill2 = "touch "+ruta+"%1/boot/grub/menu.lst";
                        Kill2 = Kill2.arg(activo2);
                        QString device0 = "echo Introduciendo datos de mapeo y configuracion de inicio de distros para grub...";
                        comandos << Kill << Kill0 << Kill1 << Kill2 << device0;
                        QString gru2 = "echo Reinstalando grub en el USB...";
                        QString grub2 = "/sbin/grub-install --root-directory="+ruta+"%1 %2 --no-floppy";
                        grub2 = grub2.arg(activo2).arg(activo3);
                        comandos << gru2 << grub2;
                    }
                    else if (ui->radioButton_8->isChecked() == true)
                    {
                        QString Kill0 = "rm -vR -f "+ruta+"%1/boot/grub/device.map";
                        Kill0 = Kill0.arg(activo2);
                        QString Kill1 = "touch "+ruta+"%1/boot/grub/device.map";
                        Kill1 = Kill1.arg(activo2);
                        comandos << Kill0 << Kill1;
                        QString gru2 = "echo Reinstalando grub en el USB...";
                        QString grub2 = "/sbin/grub-install --root-directory="+ruta+"%1 %2 --no-floppy";
                        grub2 = grub2.arg(activo2).arg(activo3);
                        comandos << gru2 << grub2;
                        QString device0 = "echo Actualizando datos de mapeo de grub...";
                        QString reelido = "echo Realizando proceso de reinstalado en device.map...";
                        comandos << device0 << reelido;
                    }
                    QString procesando = "echo Realizando proceso de insercion de datos de distros en menu.lst...";
                    comandos << procesando;
                    if (ui->radioButton_8->isChecked() == false)
                    {
                       grub << "timeout 10" << "color black/cyan yellow/cyan" << "default 0" << "";
                    }
                    if (TipMandriva !="")
                    {
                        QString Mandriva;
                        QString Mandriva1 = "Mandriva";
                        TipMandriva = ""+TipMandriva+"_"+ui->comboBox_11->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub FROM Distro WHERE NomDistro='"+Mandriva1+"' AND Version='"+ui->comboBox_11->currentText()+"' AND Arquitectura='"+ui->comboBox->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Mandriva=query.value(0).toString();
                        Mandriva.replace( QString("MANDRIVA"), QString(TipMandriva));
                        Mandriva.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList MandrivaDat  = Mandriva.split("\n");
                        for(int i=0;i<MandrivaDat.count();i++)
                        {
                            QString Value = MandrivaDat.value(i);
                            grub << ""+Value+"";
                        }
                        grub << "#";
                    }
                    if (TipPCLinuxOS != "")
                    {
                        QString PCLinuxOS;
                        QString PCLinuxOS1 = "PCLinuxOS";
                        TipPCLinuxOS = ""+TipPCLinuxOS+"_"+ui->comboBox_12->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub FROM Distro WHERE NomDistro='"+PCLinuxOS1+"' AND Version='"+ui->comboBox_12->currentText()+"' AND Arquitectura='"+ui->comboBox_2->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            PCLinuxOS=query.value(0).toString();
                        PCLinuxOS.replace( QString("PCLINUXOS"), QString(TipPCLinuxOS));
                        PCLinuxOS.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList PCLinuxOSDat  = PCLinuxOS.split("\n");
                        for(int i=0;i<PCLinuxOSDat.count();i++)
                        {
                            QString Value1 = PCLinuxOSDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipFedora !="")
                    {
                        QString Fedora;
                        QString Fedora1 = "Fedora";
                        TipFedora = ""+TipFedora+"_"+ui->comboBox_13->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub FROM Distro WHERE NomDistro='"+Fedora1+"' AND Version='"+ui->comboBox_13->currentText()+"' AND Arquitectura='"+ui->comboBox_3->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Fedora=query.value(0).toString();
                        Fedora.replace( QString("FEDORA"), QString(TipFedora));
                        Fedora.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList FedoraDat  = Fedora.split("\n");
                        for(int i=0;i<FedoraDat.count();i++)
                        {
                            QString Value1 = FedoraDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipUbuntu !="")
                    {
                        QString Ubuntu;
                        QString Ubuntu1 = "Ubuntu";
                        TipUbuntu = ""+TipUbuntu+"_"+ui->comboBox_14->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub FROM Distro WHERE NomDistro='"+Ubuntu1+"' AND Version='"+ui->comboBox_14->currentText()+"' AND Arquitectura='"+ui->comboBox_4->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Ubuntu=query.value(0).toString();
                        Ubuntu.replace( QString("UBUNTU"), QString(TipUbuntu));
                        Ubuntu.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList UbuntuDat  = Ubuntu.split("\n");
                        for(int i=0;i<UbuntuDat.count();i++)
                        {
                            QString Value1 = UbuntuDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipArchLinux !="")
                    {
                        QString ArchLinux;
                        QString ArchLinux1 = "ArchLinux";
                        TipArchLinux = ""+TipArchLinux+"_"+ui->comboBox_15->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub FROM Distro WHERE NomDistro='"+ArchLinux1+"' AND Version='"+ui->comboBox_15->currentText()+"' AND Arquitectura='"+ui->comboBox_5->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            ArchLinux=query.value(0).toString();
                        ArchLinux.replace( QString("ARCHLINUX"), QString(TipArchLinux));
                        ArchLinux.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList ArchLinuxDat  = ArchLinux.split("\n");
                        for(int i=0;i<ArchLinuxDat.count();i++)
                        {
                            QString Value1 = ArchLinuxDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipCentOS !="")
                    {
                        QString CentOS;
                        QString CentOS1 = "CentOS";
                        TipCentOS = ""+TipCentOS+"_"+ui->comboBox_16->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub FROM Distro WHERE NomDistro='"+CentOS1+"' AND Version='"+ui->comboBox_16->currentText()+"' AND Arquitectura='"+ui->comboBox_6->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            CentOS=query.value(0).toString();
                        CentOS.replace( QString("CENTOS"), QString(TipCentOS));
                        CentOS.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList CentOSDat  = CentOS.split("\n");
                        for(int i=0;i<CentOSDat.count();i++)
                        {
                            QString Value1 = CentOSDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipDebian !="")
                    {
                        QString Debian;
                        QString Debian1 = "Debian";
                        TipDebian = ""+TipDebian+"_"+ui->comboBox_17->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub FROM Distro WHERE NomDistro='"+Debian1+"' AND Version='"+ui->comboBox_17->currentText()+"' AND Arquitectura='"+ui->comboBox_7->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Debian=query.value(0).toString();
                        Debian.replace( QString("DEBIAN"), QString(TipDebian));
                        Debian.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList DebianDat  = Debian.split("\n");
                        for(int i=0;i<DebianDat.count();i++)
                        {
                            QString Value1 = DebianDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipKnoppix !="")
                    {
                        QString Knoppix;
                        QString Knoppix1 = "Knoppix";
                        TipKnoppix = ""+TipKnoppix+"_"+ui->comboBox_18->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub FROM Distro WHERE NomDistro='"+Knoppix1+"' AND Version='"+ui->comboBox_18->currentText()+"' AND Arquitectura='"+ui->comboBox_8->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Knoppix=query.value(0).toString();
                        Knoppix.replace( QString("KNOPPIX"), QString(TipKnoppix));
                        Knoppix.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList KnoppixDat  = Knoppix.split("\n");
                        for(int i=0;i<KnoppixDat.count();i++)
                        {
                            QString Value1 = KnoppixDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipOpenSUSE !="")
                    {
                        QString OpenSUSE;
                        QString OpenSUSE1 = "OpenSUSE";
                        TipOpenSUSE = ""+TipOpenSUSE+"_"+ui->comboBox_19->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub FROM Distro WHERE NomDistro='"+OpenSUSE1+"' AND Version='"+ui->comboBox_19->currentText()+"' AND Arquitectura='"+ui->comboBox_9->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            OpenSUSE=query.value(0).toString();
                        OpenSUSE.replace( QString("OPENSUSE"), QString(TipOpenSUSE));
                        OpenSUSE.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList OpenSUSEDat  = OpenSUSE.split("\n");
                        for(int i=0;i<OpenSUSEDat.count();i++)
                        {
                            QString Value1 = OpenSUSEDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipLinuxMint !="")
                    {
                        QString LinuxMint;
                        QString LinuxMint1 = "LinuxMint";
                        TipLinuxMint = ""+TipLinuxMint+"_"+ui->comboBox_20->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub FROM Distro WHERE NomDistro='"+LinuxMint1+"' AND Version='"+ui->comboBox_20->currentText()+"' AND Arquitectura='"+ui->comboBox_10->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            LinuxMint=query.value(0).toString();
                        LinuxMint.replace( QString("LINUXMINT"), QString(TipLinuxMint));
                        LinuxMint.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList LinuxMintDat  = LinuxMint.split("\n");
                        for(int i=0;i<LinuxMintDat.count();i++)
                        {
                            QString Value1 = LinuxMintDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                }
                if (ui->radioButton_4->isChecked() == true)
                {
                    QString TipGrub1 = getGrub("/usr/sbin/grub-install");
                    QString TipGrub2 = getGrub("/usr/sbin/grub2-install");
                    QString TipGrub3 = getIso(""+ruta+""+activo2+"/boot/");
                    TipGrub3.remove("/");
                    if (ui->radioButton_8->isChecked() == false)
                    {
                        if (TipGrub1 == "")
                        {
                            if (TipGrub2 == "")
                            {
                                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                                m.setText(tr("No tienes instalado grub2 en tu sistema y es necesario para este proposito. Por favor instalalo si quieres continuar."));
                                m.exec();
                                return;
                            }
                            else if (TipGrub2 == "/usr/sbin/grub2-install")
                            {
                                QString gru1 = "echo instalando grub2 en el USB...";
                                QString grub1 = "/usr/sbin/grub2-install --root-directory="+ruta+"%1 %2 --no-floppy";
                                grub1 = grub1.arg(activo2).arg(activo3);
                                comandos << gru1 << grub1;
                            }
                        }
                        else if (TipGrub1 == "/usr/sbin/grub-install")
                        {
                            QString gru1 = "echo instalando grub2 en el USB...";
                            QString grub1 = "/usr/sbin/grub-install --root-directory="+ruta+"%1 %2 --no-floppy";
                            grub1 = grub1.arg(activo2).arg(activo3);
                            comandos << gru1 << grub1;
                        }
                        if (TipGrub3 == "grub2")
                        {
                            QString Kill = "echo Creando fichero de mapeo de unidades y grub.cfg...";
                            QString Kill0 = "rm -vR -f "+ruta+"%1/boot/grub2/device.map";
                            Kill0 = Kill0.arg(activo2);
                            QString Kill1 = "touch "+ruta+"%1/boot/grub2/device.map";
                            Kill1 = Kill1.arg(activo2);
                            QString Kill2 = "touch "+ruta+"%1/boot/grub2/grub.cfg";
                            Kill2 = Kill2.arg(activo2);
                            QString device0 = "echo Introduciendo datos de mapeo y configuracion de inicio de distros...";
                            comandos << Kill << Kill0 << Kill1 << Kill2 << device0;
                            QString gru2 = "echo Reinstalando grub en el USB...";
                            QString grub2 = "/usr/sbin/grub2-install --root-directory="+ruta+"%1 %2 --no-floppy";
                            grub2 = grub2.arg(activo2).arg(activo3);
                            comandos << gru2 << grub2;
                        }
                        else if (TipGrub3 != "grub2")
                        {
                            QString Kill = "echo Creando fichero de mapeo de unidades y grub.cfg...";
                            QString Kill0 = "rm -vR -f "+ruta+"%1/boot/grub/device.map";
                            Kill0 = Kill0.arg(activo2);
                            QString Kill1 = "touch "+ruta+"%1/boot/grub/device.map";
                            Kill1 = Kill1.arg(activo2);
                            QString Kill2 = "touch "+ruta+"%1/boot/grub/grub.cfg";
                            Kill2 = Kill2.arg(activo2);
                            QString device0 = "echo Introduciendo datos de mapeo y configuracion de inicio de distros...";
                            comandos << Kill << Kill0 << Kill1 << Kill2 << device0;
                            QString gru2 = "echo Reinstalando grub en el USB...";
                            QString grub2 = "/usr/sbin/grub-install --root-directory="+ruta+"%1 %2 --no-floppy";
                            grub2 = grub2.arg(activo2).arg(activo3);
                            comandos << gru2 << grub2;
                        }
                    }
                    else if (ui->radioButton_8->isChecked() == true)
                    {
                        if (TipGrub3 == "grub2")
                        {
                            QString kill = "rm -vR -f "+ruta+"%1/boot/grub2/device.map";
                            kill = kill.arg(activo2);
                            QString killa = "touch "+ruta+"%1/boot/grub2/device.map";
                            killa = killa.arg(activo2);
                            comandos << kill << killa;
                            QString gru2 = "echo Reinstalando grub en el USB...";
                            QString grub2 = "/usr/sbin/grub2-install --root-directory="+ruta+"%1 %2 --no-floppy";
                            grub2 = grub2.arg(activo2).arg(activo3);
                            comandos << gru2 << grub2;
                        }
                        else if (TipGrub3 != "grub2")
                        {
                            QString Kill0 = "rm -vR -f "+ruta+"%1/boot/grub/device.map";
                            Kill0 = Kill0.arg(activo2);
                            QString Kill1 = "touch "+ruta+"%1/boot/grub/device.map";
                            Kill1 = Kill1.arg(activo2);
                            comandos << Kill0 << Kill1;
                            QString gru2 = "echo Reinstalando grub en el USB...";
                            QString grub2 = "/usr/sbin/grub-install --root-directory="+ruta+"%1 %2 --no-floppy";
                            grub2 = grub2.arg(activo2).arg(activo3);
                            comandos << gru2 << grub2;
                        }
                        QString device0 = "echo Actualizando datos de mapeo...";
                        QString reelido = "echo Realizando proceso de reinstalado en device.map...";
                        comandos << device0 << reelido;
                    }
                    QString procesando = "echo Realizando proceso de insercion de datos de distros en grub.cfg...";
                    comandos << procesando;
                    if (ui->radioButton_8->isChecked() == false)
                    {
                       grub << "set default=0" << "set timeout=10" << "set root=(hd0,1)" << "terminal console" << "";
                    }
                    if (TipMandriva !="")
                    {
                        QString Mandriva;
                        QString Mandriva1 = "Mandriva";
                        TipMandriva = ""+TipMandriva+"_"+ui->comboBox_11->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub2 FROM Distro WHERE NomDistro='"+Mandriva1+"' AND Version='"+ui->comboBox_11->currentText()+"' AND Arquitectura='"+ui->comboBox->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Mandriva=query.value(0).toString();
                        Mandriva.replace( QString("MANDRIVA"), QString(TipMandriva));
                        Mandriva.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList MandrivaDat  = Mandriva.split("\n");
                        for(int i=0;i<MandrivaDat.count();i++)
                        {
                            QString Value = MandrivaDat.value(i);
                            grub << ""+Value+"";
                        }
                        grub << "#";
                    }
                    if (TipPCLinuxOS != "")
                    {
                        QString PCLinuxOS;
                        QString PCLinuxOS1 = "PCLinuxOS";
                        TipPCLinuxOS = ""+TipPCLinuxOS+"_"+ui->comboBox_12->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub2 FROM Distro WHERE NomDistro='"+PCLinuxOS1+"' AND Version='"+ui->comboBox_12->currentText()+"' AND Arquitectura='"+ui->comboBox_2->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            PCLinuxOS=query.value(0).toString();
                        PCLinuxOS.replace( QString("PCLINUXOS"), QString(TipPCLinuxOS));
                        PCLinuxOS.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList PCLinuxOSDat  = PCLinuxOS.split("\n");
                        for(int i=0;i<PCLinuxOSDat.count();i++)
                        {
                            QString Value1 = PCLinuxOSDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipFedora !="")
                    {
                        QString Fedora;
                        QString Fedora1 = "Fedora";
                        TipFedora = ""+TipFedora+"_"+ui->comboBox_13->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub2 FROM Distro WHERE NomDistro='"+Fedora1+"' AND Version='"+ui->comboBox_13->currentText()+"' AND Arquitectura='"+ui->comboBox_3->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Fedora=query.value(0).toString();
                        Fedora.replace( QString("FEDORA"), QString(TipFedora));
                        Fedora.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList FedoraDat  = Fedora.split("\n");
                        for(int i=0;i<FedoraDat.count();i++)
                        {
                            QString Value1 = FedoraDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipUbuntu !="")
                    {
                        QString Ubuntu;
                        QString Ubuntu1 = "Ubuntu";
                        TipUbuntu = ""+TipUbuntu+"_"+ui->comboBox_14->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub2 FROM Distro WHERE NomDistro='"+Ubuntu1+"' AND Version='"+ui->comboBox_14->currentText()+"' AND Arquitectura='"+ui->comboBox_4->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Ubuntu=query.value(0).toString();
                        Ubuntu.replace( QString("UBUNTU"), QString(TipUbuntu));
                        Ubuntu.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList UbuntuDat  = Ubuntu.split("\n");
                        for(int i=0;i<UbuntuDat.count();i++)
                        {
                            QString Value1 = UbuntuDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipArchLinux !="")
                    {
                        QString ArchLinux;
                        QString ArchLinux1 = "ArchLinux";
                        TipArchLinux = ""+TipArchLinux+"_"+ui->comboBox_15->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub2 FROM Distro WHERE NomDistro='"+ArchLinux1+"' AND Version='"+ui->comboBox_15->currentText()+"' AND Arquitectura='"+ui->comboBox_5->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            ArchLinux=query.value(0).toString();
                        ArchLinux.replace( QString("ARCHLINUX"), QString(TipArchLinux));
                        ArchLinux.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList ArchLinuxDat  = ArchLinux.split("\n");
                        for(int i=0;i<ArchLinuxDat.count();i++)
                        {
                            QString Value1 = ArchLinuxDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipCentOS !="")
                    {
                        QString CentOS;
                        QString CentOS1 = "CentOS";
                        TipCentOS = ""+TipCentOS+"_"+ui->comboBox_16->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub2 FROM Distro WHERE NomDistro='"+CentOS1+"' AND Version='"+ui->comboBox_16->currentText()+"' AND Arquitectura='"+ui->comboBox_6->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            CentOS=query.value(0).toString();
                        CentOS.replace( QString("CENTOS"), QString(TipCentOS));
                        CentOS.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList CentOSDat  = CentOS.split("\n");
                        for(int i=0;i<CentOSDat.count();i++)
                        {
                            QString Value1 = CentOSDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipDebian !="")
                    {
                        QString Debian;
                        QString Debian1 = "Debian";
                        TipDebian = ""+TipDebian+"_"+ui->comboBox_17->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub2 FROM Distro WHERE NomDistro='"+Debian1+"' AND Version='"+ui->comboBox_17->currentText()+"' AND Arquitectura='"+ui->comboBox_7->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Debian=query.value(0).toString();
                        Debian.replace( QString("DEBIAN"), QString(TipDebian));
                        Debian.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList DebianDat  = Debian.split("\n");
                        for(int i=0;i<DebianDat.count();i++)
                        {
                            QString Value1 = DebianDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipKnoppix !="")
                    {
                        QString Knoppix;
                        QString Knoppix1 = "Knoppix";
                        TipKnoppix = ""+TipKnoppix+"_"+ui->comboBox_18->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub2 FROM Distro WHERE NomDistro='"+Knoppix1+"' AND Version='"+ui->comboBox_18->currentText()+"' AND Arquitectura='"+ui->comboBox_8->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Knoppix=query.value(0).toString();
                        Knoppix.replace( QString("KNOPPIX"), QString(TipKnoppix));
                        Knoppix.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList KnoppixDat  = Knoppix.split("\n");
                        for(int i=0;i<KnoppixDat.count();i++)
                        {
                            QString Value1 = KnoppixDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipOpenSUSE !="")
                    {
                        QString OpenSUSE;
                        QString OpenSUSE1 = "OpenSUSE";
                        TipOpenSUSE = ""+TipOpenSUSE+"_"+ui->comboBox_19->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub2 FROM Distro WHERE NomDistro='"+OpenSUSE1+"' AND Version='"+ui->comboBox_19->currentText()+"' AND Arquitectura='"+ui->comboBox_9->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            OpenSUSE=query.value(0).toString();
                        OpenSUSE.replace( QString("OPENSUSE"), QString(TipOpenSUSE));
                        OpenSUSE.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList OpenSUSEDat  = OpenSUSE.split("\n");
                        for(int i=0;i<OpenSUSEDat.count();i++)
                        {
                            QString Value1 = OpenSUSEDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                    if (TipLinuxMint !="")
                    {
                        QString LinuxMint;
                        QString LinuxMint1 = "LinuxMint";
                        TipLinuxMint = ""+TipLinuxMint+"_"+ui->comboBox_20->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT grub2 FROM Distro WHERE NomDistro='"+LinuxMint1+"' AND Version='"+ui->comboBox_20->currentText()+"' AND Arquitectura='"+ui->comboBox_10->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            LinuxMint=query.value(0).toString();
                        LinuxMint.replace( QString("LINUXMINT"), QString(TipLinuxMint));
                        LinuxMint.replace( QString("ETIQUETA"), QString(LabelOld));
                        QStringList LinuxMintDat  = LinuxMint.split("\n");
                        for(int i=0;i<LinuxMintDat.count();i++)
                        {
                            QString Value1 = LinuxMintDat.value(i);
                            grub << ""+Value1+"";
                        }
                        grub << "#";
                    }
                }
                if (ui->radioButton_7->isChecked() == true)
                {
//                    QString TipGrub3 = getIso(""+ruta+""+activo2+"/");
//                    TipGrub3.remove("/");
                    QString TipSyslinux = getLs("/home/"+user+"/tmp/syslinux-4.05/","vesamenu.c32");
                    TipSyslinux.remove("*");
                    Tamano = "6 Mb";
//                    if (ui->radioButton_8->isChecked() == false)
//                    {
                        QString Kill = "echo Creando carpeta temporal...";
                        QString Kill0 = "mkdir /home/%1/tmp/boot/";
                        Kill0 = Kill0.arg(user);
                        QString Kill1 = "echo Creando carpeta principal...";
                        QString Kill2 = "mkdir /home/%1/tmp/boot/boot/";
                        Kill2 = Kill2.arg(user);
                        QString Kill3 = "echo Creando subcarpeta de menus...";
                        QString Kill4 = "mkdir /home/%1/tmp/boot/boot/menu/";
                        Kill4 = Kill4.arg(user);
                        QString Kill31 = "echo Creando subcarpeta isolinux...";
                        QString Kill41 = "mkdir /home/%1/tmp/boot/boot/isolinux/";
                        Kill41 = Kill41.arg(user);
                        comandos << Kill << Kill0 << Kill1 << Kill2 << Kill3 << Kill4 << Kill31 << Kill41;
                        if (TipSyslinux != "vesamenu.c32")
                        {
                            QString Kill5 = "echo Descargando syslinux...";
                            QString Kill6 = "wget -c -P/home/%1/tmp/ http://www.kernel.org/pub/linux/utils/boot/syslinux/syslinux-4.05.tar.gz";
                            Kill6 = Kill6.arg(user);
                            QString Kill7 = "tar xvzf /home/%1/tmp/syslinux-4.05.tar.gz --directory=/home/%1/tmp/";
                            Kill7 = Kill7.arg(user);
                            comandos << Kill5 << Kill6 << Kill7;
                        }
                        QString Kill8 = "echo Recopilando los archivos necesarios...";
                        QString Kill9 = "cp -v /home/%1/tmp/syslinux-4.05/core/isolinux.bin /home/%1/tmp/syslinux-4.05/memdisk/memdisk /home/%1/tmp/boot/boot/isolinux/";
                        Kill9 = Kill9.arg(user);
                        QString Kill10 = "cp -v /home/%1/tmp/syslinux-4.05/com32/menu/menu.c32 /home/%1/tmp/syslinux-4.05/com32/menu/vesamenu.c32 /home/%1/tmp/boot/boot/isolinux/";
                        Kill10 = Kill10.arg(user);
                        QString Kill11 = "cp -v /home/%1/tmp/syslinux-4.05/com32/modules/chain.c32 /home/%1/tmp/boot/boot/isolinux/";
                        Kill11 = Kill11.arg(user);
                        QString Kill12 = "cp -v /usr/share/RecoverDrake/kapyderi.png /home/%1/tmp/boot/isolinux/";
                        Kill12 = Kill12.arg(user);
                        QString Kill13 = "echo Creando el fichero de configuracion isolinux.cfg...";
                        QString Kill14 = "touch /home/%1/tmp/boot/boot/isolinux/isolinux.cfg";
                        Kill14 = Kill14.arg(user);
                        QString Kill15 = "echo Configurando isolinux.cfg...";
                        comandos << Kill8 << Kill9 << Kill10 << Kill11 << Kill12 << Kill13 << Kill14 << Kill15;
//                    }
                    QString Tiplinux = getLs("/home/"+user+"/tmp/boot/boot/menu/","linux.cfg");
                    Tiplinux.remove("*");
                    if (Tiplinux != "linux.cfg")
                    {
                        QString ill13 = "echo Creando el fichero de configuracion de distros linux.cfg...";
                        QString ill14 = "touch /home/%1/tmp/boot/boot/menu/linux.cfg";
                        ill14 = ill14.arg(user);
                        QString ill15 = "echo Configurando menu linux.cfg...";
                        comandos << ill13 << ill14 << ill15;
                    }
                    if (TipMandriva !="")
                    {
                        QString Mandriva;
                        QString Mandriva1 = "Mandriva";
                        TipMandriva = ""+TipMandriva+"_"+ui->comboBox_11->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT isolinux FROM Distro WHERE NomDistro='"+Mandriva1+"' AND Version='"+ui->comboBox_11->currentText()+"' AND Arquitectura='"+ui->comboBox->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Mandriva=query.value(0).toString();
                        Mandriva.replace( QString("MANDRIVA"), QString(TipMandriva));
                        Mandriva.replace( QString("ETIQUETA"), QString("DRAKLIVE"));
                        QStringList MandrivaDat  = Mandriva.split("\n");
                        for(int i=0;i<MandrivaDat.count();i++)
                        {
                            QString Value = MandrivaDat.value(i);
                            MdCfg << ""+Value+"";
                        }
                        MdCfg << "#";
                        QString Md1 = "echo Creando fichero de configuracion de "+TipMandriva+"...";
                        QString Md2 = "touch /home/%1/tmp/boot/boot/menu/%1.cfg";
                        Md2 = Md2.arg(TipMandriva);
                        QString Md3 = "echo Configurando "+TipMandriva+"...";
                        comandos << Md1 << Md2 << Md3;
                        MenuCfg << "label "+TipMandriva+"";
                        MenuCfg << "menu label "+TipMandriva+"";
                        MenuCfg << "MENU INDENT 1";
                        MenuCfg << "kernel vesamenu.c32";
                        MenuCfg << "APPEND /boot/menu/"+TipMandriva+".cfg";
                        MenuCfg << "#";
                    }
                    if (TipPCLinuxOS != "")
                    {
                        QString PCLinuxOS;
                        QString PCLinuxOS1 = "PCLinuxOS";
                        TipPCLinuxOS = ""+TipPCLinuxOS+"_"+ui->comboBox_12->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT isolinux FROM Distro WHERE NomDistro='"+PCLinuxOS1+"' AND Version='"+ui->comboBox_12->currentText()+"' AND Arquitectura='"+ui->comboBox_2->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            PCLinuxOS=query.value(0).toString();
                        PCLinuxOS.replace( QString("PCLINUXOS"), QString(TipPCLinuxOS));
                        PCLinuxOS.replace( QString("ETIQUETA"), QString("DRAKLIVE"));
                        QStringList PCLinuxOSDat  = PCLinuxOS.split("\n");
                        for(int i=0;i<PCLinuxOSDat.count();i++)
                        {
                            QString Value1 = PCLinuxOSDat.value(i);
                            PlCfg << ""+Value1+"";
                        }
                        PlCfg << "#";
                        QString Pl1 = "echo Creando fichero de configuracion de "+TipPCLinuxOS+"...";
                        QString Pl2 = "touch /home/%1/tmp/boot/boot/menu/%1.cfg";
                        Pl2 = Pl2.arg(TipPCLinuxOS);
                        QString Pl3 = "echo Configurando "+TipPCLinuxOS+"...";
                        comandos << Pl1 << Pl2 << Pl3;
                        MenuCfg << "label "+TipPCLinuxOS+"";
                        MenuCfg << "menu label "+TipPCLinuxOS+"";
                        MenuCfg << "MENU INDENT 1";
                        MenuCfg << "kernel vesamenu.c32";
                        MenuCfg << "APPEND /boot/menu/"+TipPCLinuxOS+".cfg";
                        MenuCfg << "#";
                    }
                    if (TipFedora !="")
                    {
                        QString Fedora;
                        QString Fedora1 = "Fedora";
                        TipFedora = ""+TipFedora+"_"+ui->comboBox_13->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT isolinux FROM Distro WHERE NomDistro='"+Fedora1+"' AND Version='"+ui->comboBox_13->currentText()+"' AND Arquitectura='"+ui->comboBox_3->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Fedora=query.value(0).toString();
                        Fedora.replace( QString("FEDORA"), QString(TipFedora));
                        Fedora.replace( QString("ETIQUETA"), QString("DRAKLIVE"));
                        QStringList FedoraDat  = Fedora.split("\n");
                        for(int i=0;i<FedoraDat.count();i++)
                        {
                            QString Value1 = FedoraDat.value(i);
                            FdCfg << ""+Value1+"";
                        }
                        FdCfg << "#";
                        QString Fd1 = "echo Creando fichero de configuracion de "+TipFedora+"...";
                        QString Fd2 = "touch /home/%1/tmp/boot/boot/menu/%1.cfg";
                        Fd2 = Fd2.arg(TipFedora);
                        QString Fd3 = "echo Configurando "+TipFedora+"...";
                        comandos << Fd1 << Fd2 << Fd3;
                        MenuCfg << "label "+TipFedora+"";
                        MenuCfg << "menu label "+TipFedora+"";
                        MenuCfg << "MENU INDENT 1";
                        MenuCfg << "kernel vesamenu.c32";
                        MenuCfg << "APPEND /boot/menu/"+TipFedora+".cfg";
                        MenuCfg << "#";
                    }
                    if (TipUbuntu !="")
                    {
                        QString Ubuntu;
                        QString Ubuntu1 = "Ubuntu";
                        TipUbuntu = ""+TipUbuntu+"_"+ui->comboBox_14->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT isolinux FROM Distro WHERE NomDistro='"+Ubuntu1+"' AND Version='"+ui->comboBox_14->currentText()+"' AND Arquitectura='"+ui->comboBox_4->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Ubuntu=query.value(0).toString();
                        Ubuntu.replace( QString("UBUNTU"), QString(TipUbuntu));
                        Ubuntu.replace( QString("ETIQUETA"), QString("DRAKLIVE"));
                        QStringList UbuntuDat  = Ubuntu.split("\n");
                        for(int i=0;i<UbuntuDat.count();i++)
                        {
                            QString Value1 = UbuntuDat.value(i);
                            UbCfg << ""+Value1+"";
                        }
                        UbCfg << "#";
                        QString Ub1 = "echo Creando fichero de configuracion de "+TipUbuntu+"...";
                        QString Ub2 = "touch /home/%1/tmp/boot/boot/menu/%1.cfg";
                        Ub2 = Ub2.arg(TipUbuntu);
                        QString Ub3 = "echo Configurando "+TipUbuntu+"...";
                        comandos << Ub1 << Ub2 << Ub3;
                        MenuCfg << "label "+TipUbuntu+"";
                        MenuCfg << "menu label "+TipUbuntu+"";
                        MenuCfg << "MENU INDENT 1";
                        MenuCfg << "kernel vesamenu.c32";
                        MenuCfg << "APPEND /boot/menu/"+TipUbuntu+".cfg";
                        MenuCfg << "#";
                    }
                    if (TipArchLinux !="")
                    {
                        QString ArchLinux;
                        QString ArchLinux1 = "ArchLinux";
                        TipArchLinux = ""+TipArchLinux+"_"+ui->comboBox_15->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT isolinux FROM Distro WHERE NomDistro='"+ArchLinux1+"' AND Version='"+ui->comboBox_15->currentText()+"' AND Arquitectura='"+ui->comboBox_5->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            ArchLinux=query.value(0).toString();
                        ArchLinux.replace( QString("ARCHLINUX"), QString(TipArchLinux));
                        ArchLinux.replace( QString("ETIQUETA"), QString("DRAKLIVE"));
                        QStringList ArchLinuxDat  = ArchLinux.split("\n");
                        for(int i=0;i<ArchLinuxDat.count();i++)
                        {
                            QString Value1 = ArchLinuxDat.value(i);
                            AlCfg << ""+Value1+"";
                        }
                        AlCfg << "#";
                        QString Al1 = "echo Creando fichero de configuracion de "+TipArchLinux+"...";
                        QString Al2 = "touch /home/%1/tmp/boot/boot/menu/%1.cfg";
                        Al2 = Al2.arg(TipArchLinux);
                        QString Al3 = "echo Configurando "+TipArchLinux+"...";
                        comandos << Al1 << Al2 << Al3;
                        MenuCfg << "label "+TipArchLinux+"";
                        MenuCfg << "menu label "+TipArchLinux+"";
                        MenuCfg << "MENU INDENT 1";
                        MenuCfg << "kernel vesamenu.c32";
                        MenuCfg << "APPEND /boot/menu/"+TipArchLinux+".cfg";
                        MenuCfg << "#";
                    }
                    if (TipCentOS !="")
                    {
                        QString CentOS;
                        QString CentOS1 = "CentOS";
                        TipCentOS = ""+TipCentOS+"_"+ui->comboBox_16->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT isolinux FROM Distro WHERE NomDistro='"+CentOS1+"' AND Version='"+ui->comboBox_16->currentText()+"' AND Arquitectura='"+ui->comboBox_6->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            CentOS=query.value(0).toString();
                        CentOS.replace( QString("CENTOS"), QString(TipCentOS));
                        CentOS.replace( QString("ETIQUETA"), QString("DRAKLIVE"));
                        QStringList CentOSDat  = CentOS.split("\n");
                        for(int i=0;i<CentOSDat.count();i++)
                        {
                            QString Value1 = CentOSDat.value(i);
                            CtCfg << ""+Value1+"";
                        }
                        CtCfg << "#";
                        QString Ct1 = "echo Creando fichero de configuracion de "+TipCentOS+"...";
                        QString Ct2 = "touch /home/%1/tmp/boot/boot/menu/%1.cfg";
                        Ct2 = Ct2.arg(TipCentOS);
                        QString Ct3 = "echo Configurando "+TipCentOS+"...";
                        comandos << Ct1 << Ct2 << Ct3;
                        MenuCfg << "label "+TipCentOS+"";
                        MenuCfg << "menu label "+TipCentOS+"";
                        MenuCfg << "MENU INDENT 1";
                        MenuCfg << "kernel vesamenu.c32";
                        MenuCfg << "APPEND /boot/menu/"+TipCentOS+".cfg";
                        MenuCfg << "#";
                    }
                    if (TipDebian !="")
                    {
                        QString Debian;
                        QString Debian1 = "Debian";
                        TipDebian = ""+TipDebian+"_"+ui->comboBox_17->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT isolinux FROM Distro WHERE NomDistro='"+Debian1+"' AND Version='"+ui->comboBox_17->currentText()+"' AND Arquitectura='"+ui->comboBox_7->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Debian=query.value(0).toString();
                        Debian.replace( QString("DEBIAN"), QString(TipDebian));
                        Debian.replace( QString("ETIQUETA"), QString("DRAKLIVE"));
                        QStringList DebianDat  = Debian.split("\n");
                        for(int i=0;i<DebianDat.count();i++)
                        {
                            QString Value1 = DebianDat.value(i);
                            DbCfg << ""+Value1+"";
                        }
                        DbCfg << "#";
                        QString Db1 = "echo Creando fichero de configuracion de "+TipDebian+"...";
                        QString Db2 = "touch /home/%1/tmp/boot/boot/menu/%1.cfg";
                        Db2 = Db2.arg(TipDebian);
                        QString Db3 = "echo Configurando "+TipDebian+"...";
                        comandos << Db1 << Db2 << Db3;
                        MenuCfg << "label "+TipDebian+"";
                        MenuCfg << "menu label "+TipDebian+"";
                        MenuCfg << "MENU INDENT 1";
                        MenuCfg << "kernel vesamenu.c32";
                        MenuCfg << "APPEND /boot/menu/"+TipDebian+".cfg";
                        MenuCfg << "#";
                    }
                    if (TipKnoppix !="")
                    {
                        QString Knoppix;
                        QString Knoppix1 = "Knoppix";
                        TipKnoppix = ""+TipKnoppix+"_"+ui->comboBox_18->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT isolinux FROM Distro WHERE NomDistro='"+Knoppix1+"' AND Version='"+ui->comboBox_18->currentText()+"' AND Arquitectura='"+ui->comboBox_8->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            Knoppix=query.value(0).toString();
                        Knoppix.replace( QString("KNOPPIX"), QString(TipKnoppix));
                        Knoppix.replace( QString("ETIQUETA"), QString("DRAKLIVE"));
                        QStringList KnoppixDat  = Knoppix.split("\n");
                        for(int i=0;i<KnoppixDat.count();i++)
                        {
                            QString Value1 = KnoppixDat.value(i);
                            KnCfg << ""+Value1+"";
                        }
                        KnCfg << "#";
                        QString Kn1 = "echo Creando fichero de configuracion de "+TipKnoppix+"...";
                        QString Kn2 = "touch /home/%1/tmp/boot/boot/menu/%1.cfg";
                        Kn2 = Kn2.arg(TipKnoppix);
                        QString Kn3 = "echo Configurando "+TipKnoppix+"...";
                        comandos << Kn1 << Kn2 << Kn3;
                        MenuCfg << "label "+TipKnoppix+"";
                        MenuCfg << "menu label "+TipKnoppix+"";
                        MenuCfg << "MENU INDENT 1";
                        MenuCfg << "kernel vesamenu.c32";
                        MenuCfg << "APPEND /boot/menu/"+TipKnoppix+".cfg";
                        MenuCfg << "#";
                    }
                    if (TipOpenSUSE !="")
                    {
                        QString OpenSUSE;
                        QString OpenSUSE1 = "OpenSUSE";
                        TipOpenSUSE = ""+TipOpenSUSE+"_"+ui->comboBox_19->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT isolinux FROM Distro WHERE NomDistro='"+OpenSUSE1+"' AND Version='"+ui->comboBox_19->currentText()+"' AND Arquitectura='"+ui->comboBox_9->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            OpenSUSE=query.value(0).toString();
                        OpenSUSE.replace( QString("OPENSUSE"), QString(TipOpenSUSE));
                        OpenSUSE.replace( QString("ETIQUETA"), QString("DRAKLIVE"));
                        QStringList OpenSUSEDat  = OpenSUSE.split("\n");
                        for(int i=0;i<OpenSUSEDat.count();i++)
                        {
                            QString Value1 = OpenSUSEDat.value(i);
                            OsCfg << ""+Value1+"";
                        }
                        OsCfg << "#";
                        QString Os1 = "echo Creando fichero de configuracion de "+TipOpenSUSE+"...";
                        QString Os2 = "touch /home/%1/tmp/boot/boot/menu/%1.cfg";
                        Os2 = Os2.arg(TipOpenSUSE);
                        QString Os3 = "echo Configurando "+TipOpenSUSE+"...";
                        comandos << Os1 << Os2 << Os3;
                        MenuCfg << "label "+TipOpenSUSE+"";
                        MenuCfg << "menu label "+TipOpenSUSE+"";
                        MenuCfg << "MENU INDENT 1";
                        MenuCfg << "kernel vesamenu.c32";
                        MenuCfg << "APPEND /boot/menu/"+TipOpenSUSE+".cfg";
                        MenuCfg << "#";
                    }
                    if (TipLinuxMint !="")
                    {
                        QString LinuxMint;
                        QString LinuxMint1 = "LinuxMint";
                        TipLinuxMint = ""+TipLinuxMint+"_"+ui->comboBox_20->currentText()+"";
                        QSqlQuery query(db);
                        query.exec("SELECT isolinux FROM Distro WHERE NomDistro='"+LinuxMint1+"' AND Version='"+ui->comboBox_20->currentText()+"' AND Arquitectura='"+ui->comboBox_10->currentText()+"'");
                        query.first();
                        if (query.isValid())
                            LinuxMint=query.value(0).toString();
                        LinuxMint.replace( QString("LINUXMINT"), QString(TipLinuxMint));
                        LinuxMint.replace( QString("ETIQUETA"), QString("DRAKLIVE"));
                        QStringList LinuxMintDat  = LinuxMint.split("\n");
                        for(int i=0;i<LinuxMintDat.count();i++)
                        {
                            QString Value1 = LinuxMintDat.value(i);
                            LmCfg << ""+Value1+"";
                        }
                        LmCfg << "#";
                        QString Lm1 = "echo Creando fichero de configuracion de "+TipLinuxMint+"...";
                        QString Lm2 = "touch /home/%1/tmp/boot/boot/menu/%1.cfg";
                        Lm2 = Lm2.arg(TipLinuxMint);
                        QString Lm3 = "echo Configurando "+TipLinuxMint+"...";
                        comandos << Lm1 << Lm2 << Lm3;
                        MenuCfg << "label "+TipLinuxMint+"";
                        MenuCfg << "menu label "+TipLinuxMint+"";
                        MenuCfg << "MENU INDENT 1";
                        MenuCfg << "kernel vesamenu.c32";
                        MenuCfg << "APPEND /boot/menu/"+TipLinuxMint+".cfg";
                        MenuCfg << "#";
                    }
                    QString menu2 = "echo Actualizando submenus en linux.cfg...";
                    comandos << menu2;
                }
                if (ui->radioButton_12->isChecked() == true)
                {
                    QString gru2 = "echo Actualizando grub en el USB...";
                    QString grub2 = "/sbin/grub-install --root-directory="+ruta+"%1 %2 --no-floppy";
                    grub2 = grub2.arg(activo2).arg(activo3);
                    comandos << gru2 << grub2;
                }
                else if (ui->radioButton_4->isChecked() == true)
                {
                    QString TipGrub3 = getIso(""+ruta+""+activo2+"/boot/");
                    TipGrub3.remove("/");
                    if (TipGrub3 == "grub2")
                    {
                        QString gru2 = "echo Actualizando grub en el USB...";
                        QString grub2 = "/usr/sbin/grub2-install --root-directory="+ruta+"%1 %2 --no-floppy";
                        grub2 = grub2.arg(activo2).arg(activo3);
                        comandos << gru2 << grub2;
                    }
                    else if (TipGrub3 != "grub2")
                    {
                        QString gru2 = "echo Actualizando grub en el USB...";
                        QString grub2 = "/usr/sbin/grub-install --root-directory="+ruta+"%1 %2 --no-floppy";
                        grub2 = grub2.arg(activo2).arg(activo3);
                        comandos << gru2 << grub2;
                    }
                }
                else if (ui->radioButton_7->isChecked() == true)
                {
                    QString iso1 = "echo Creando iso con todos los datos recopilados...";
                    QString iso2 = "mkisofs -o /home/%1/tmp/MultibootDrake.iso -b draklive/isolinux.bin -c draklive/boot.cat -no-emul-boot -boot-load-size 4 -boot-info-table -r -J -V \"draklive\" /home/%1/tmp/boot/";
                    iso2 = iso2.arg(user);
                    QString iso3 = "mv /home/%1/tmp/MultibootDrake.iso %2";
                    iso3=iso3.arg(user).arg(fileNameDirectori);
                    comandos << iso1 << iso2 << iso3;
                }

            }            
        }
    }
}

void UsbLive::on_pushButton_21_clicked()
{
    ui->textEdit_2->setText("");
    if (ui->pushButton_21->text() == tr("Comenzar"))
    {
        ui->pushButton_21->setText(tr("Cancelar"));
        if (Control > 0)
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Hay errores que corregir. Debes corregirlos para poder continuar."));
            m.exec();
            return;
        }
        if (comandos.count() <= 0)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No hay procesos para realizar. Comprueba que este todo correcto."));
            m.exec();
            return;
        }
        ui->progressBar->show();
        ui->label_6->show();
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Crear USB Live Multiboot")),
                    QString::fromUtf8(tr("<center><b>Crear USB Live Multiboot<b></center><p>"

                            "A partir de dar a aceptar ya no se podrá invertir el proceso<p>"

                            "&iquest;Estas seguro de querer continuar?")), QMessageBox ::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            if (mib != 0)
                delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(DatoComand(QString)), this, SLOT(mibReferencia(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            connect(mib, SIGNAL(finProceso()), this, SLOT(ProbarUSB()));
            int valor= comandos.count();
            mib->Valor(valor,0);
            mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
            mib->iniciarProceso();
        }
        else if (respuesta == QMessageBox::No)
        {
            ui->pushButton_21->setText(tr("Comenzar"));
            ui->label_4->show();
            ui->progressBar->hide();
            ui->label_6->show();
        }
        return;
    }
    else if (ui->pushButton_21->text() == "Cancelar")
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Cancelar procesos")),
                    QString::fromUtf8(tr("<center><b>Cancelar procesos<b></center><p>"

                            "Debes confirmar para verificar que no ha sido un error.<p>"

                            "&iquest;Estas seguro de querer cancelar?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            comandos.clear();
            QString cmd1 = "killall wget";
            comandos << cmd1;

            if (mib != 0)
                delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
            connect(mib, SIGNAL(DatoComand(QString)), this, SLOT(mibReferencia(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count();
            mib->Valor(valor,0);
            mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
            mib->iniciarProceso();
        }
        else if (respuesta == QMessageBox::No)
        {
            ui->pushButton_21->setText(tr("Comenzar"));
            ui->label_4->show();
            ui->progressBar->hide();
            ui->label_6->show();
        }
        return;
    }
}

void UsbLive::on_pushButton_22_clicked()
{
    ui->tabWidget->setCurrentPage(2);
}

void UsbLive::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    if (DatoComand == "wget")
    {
        valor.remove(".");
        QString Dato = valor.right(1);
        if (Dato != "")
        {
            if (Dato == " ")
            {
                valor.remove("K");
                int Megas = valor.toInt();
                Megas = Megas/1024;
                if (Megas != 0)
                   ui->label_6->setText(tr("Descargando ")+QString::number(Megas)+tr(" Mb de ")+Tamano+"");
            }
        }
    }
    else
    {
        if (Ctrl == 1)
        {
            ui->textEdit->append(valor);
        }
        else
        {
            ui->textEdit_2->append(valor);
        }
    }
}

void UsbLive::mibprogreso(QString Dat)
{
    ui->progressBar->setValue(Dat.toInt());
}

void UsbLive::mibReferencia(QString comando)
{
    QString ValorGrub;
    QString TipGrub1 = getGrub("/usr/sbin/grub-install");
    if (TipGrub1 == "")
    {
        QString TipGrub2 = getGrub("/usr/sbin/grub2-install");
        if (TipGrub2 == "/usr/sbin/grub2-install")
        {
            ValorGrub = "grub2";
        }
    }
    else if (TipGrub1 == "/usr/sbin/grub-install")
    {
        ValorGrub = "grub";
    }
    if (comando == "echo Introduciendo datos de mapeo y configuracion de inicio de distros..." || comando == "echo Actualizando datos de mapeo...")
    {
        QString device = "(hd0)   %1";
        device = device.arg(activo3);
        QFile file(""+ruta+""+activo2+"/boot/"+ValorGrub+"/device.map");
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream in(&file);
        in << ""+device+"";
        file.close();
    }
    if (comando == "echo Introduciendo datos de mapeo y configuracion de inicio de distros para grub..." || comando == "echo Actualizando datos de mapeo de grub...")
    {
        QString device = "(hd0)   %1";
        device = device.arg(activo3);
        QFile file(""+ruta+""+activo2+"/boot/grub/device.map");
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream in(&file);
        in << ""+device+"";
        file.close();
    }
    if (comando == "echo Realizando proceso de insercion de datos de distros en grub.cfg...")
    {
        QString Value0;
        QString Ruta;
        QString Compara;
        Ruta = ""+ruta+""+activo2+"/boot/"+ValorGrub+"/grub.cfg";
        QFile file(""+ruta+""+activo2+"/boot/"+ValorGrub+"/grub.cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<grub.count();i++)
        {
            Value0 = grub.value(i);
            if (Value0 != " ")
            {
                Compara = getCompara(Value0, Ruta);
                if (Value0 != Compara)
                {
                    in2 << ""+Value0+"" << "\n";
                }
            }
        }
        grub.clear();
        file.close();
    }
    if (comando == "echo Realizando proceso de insercion de datos de distros en menu.lst...")
    {
        QString Value0;
        QString Ruta;
        QString Compara;
        Ruta = ""+ruta+""+activo2+"/boot/grub/menu.lst";
        QFile file(""+ruta+""+activo2+"/boot/grub/menu.lst");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<grub.count();i++)
        {
            Value0 = grub.value(i);
            if (Value0 != " ")
            {
                Compara = getCompara(Value0, Ruta);
                if (Value0 != Compara)
                {
                    in2 << ""+Value0+"" << "\n";
                }
            }
        }
        grub.clear();
        file.close();
    }
    if (comando == "echo Configurando isolinux.cfg...")
    {
        QFile file("/home/"+user+"/tmp/boot/boot/isolinux/isolinux.cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream in2(&file);
        in2 << "default vesamenu.c32" << "\n";
        in2 << "prompt 0" << "\n";
        in2 << "timeout 300" << "\n";
        in2 << "menu title DrakLive -- Universal Instalador MultiDistro" << "\n";
        in2 << "menu background kapyderi.png" << "\n";
        in2 << "MENU TABMSG  http://www.blogdrake.net" << "\n";
        in2 << "MENU WIDTH 72" << "\n";
        in2 << "MENU MARGIN 10" << "\n";
        in2 << "MENU VSHIFT 3" << "\n";
        in2 << "MENU HSHIFT 6" << "\n";
        in2 << "MENU ROWS 15" << "\n";
        in2 << "MENU TABMSGROW 20" << "\n";
        in2 << "MENU TIMEOUTROW 22";
        in2 << "menu color title 1;36;44 #66A0FF #00000000 none" << "\n";
        in2 << "menu color hotsel 30;47 #C00000 #DDDDDDDD" << "\n";
        in2 << "menu color sel 30;47 #000000 #FFFFFFFF" << "\n";
        in2 << "menu color border 30;44	#D00000 #00000000 std" << "\n";
        in2 << "menu color scrollbar 30;44 #DDDDDDDD #00000000 none"<< "\n";
        in2 << " " << "\n";
        in2 << "label Iniciar desde el primer HD" << "\n";
        in2 << "menu label Continuar desde el ^Primer HD (Por defecto)" << "\n";
        in2 << "KERNEL chain.c32" << "\n";
        in2 << "APPEND hd1" << "\n";
        in2 << "MENU DEFAULT" << "\n";
        in2 << " " << "\n";
        in2 << "label Distribuciones Linux" << "\n";
        in2 << "menu label Distribuciones Linux ->" << "\n";
        in2 << "MENU INDENT 1" << "\n";
        in2 << "kernel vesamenu.c32" << "\n";
        in2 << "APPEND /boot/menu/linux.cfg" << "\n";
        file.close();
    }
    if (comando == "echo Configurando menu linux.cfg...")
    {
        QFile file("/home/"+user+"/tmp/boot/boot/menu/linux.cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QTextStream in2(&file);
        in2 << "default vesamenu.c32" << "\n";
        in2 << "prompt 0" << "\n";
        in2 << "menu title DrakLive -- Distribuciones Linux" << "\n";
        in2 << "menu background kapyderi.png" << "\n";
        in2 << "MENU TABMSG  http://www.blogdrake.net" << "\n";
        in2 << "MENU WIDTH 72" << "\n";
        in2 << "MENU MARGIN 10" << "\n";
        in2 << "MENU VSHIFT 3" << "\n";
        in2 << "MENU HSHIFT 6" << "\n";
        in2 << "MENU ROWS 15" << "\n";
        in2 << "MENU TABMSGROW 20" << "\n";
        in2 << "MENU TIMEOUTROW 22";
        in2 << "menu color title 1;36;44 #66A0FF #00000000 none" << "\n";
        in2 << "menu color hotsel 30;47 #C00000 #DDDDDDDD" << "\n";
        in2 << "menu color sel 30;47 #000000 #FFFFFFFF" << "\n";
        in2 << "menu color border 30;44	#D00000 #00000000 std" << "\n";
        in2 << "menu color scrollbar 30;44 #DDDDDDDD #00000000 none"<< "\n";
        in2 << " " << "\n";
        in2 << "label <-- Volver al Menu Principal" << "\n";
        in2 << "kernel vesamenu.c32" << "\n";
        in2 << "APPEND /draklive/syslinux.cfg" << "\n";
        in2 << "MENU SEPARATOR" << "\n";
        in2 << " " << "\n";
        file.close();
    }
    if (comando == "echo Actualizando submenus en linux.cfg...")
    {
        QFile file("/home/"+user+"/tmp/boot/boot/menu/linux.cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<MenuCfg.count();i++)
        {
            Value0 = MenuCfg.value(i);
            if (Value0 != " ")
            {
               in2 << ""+Value0+"" << "\n";
            }
        }
        MenuCfg.clear();
        file.close();
    }
    if (comando == "echo Configurando "+TipMandriva+"...")
    {
        QString Value0;
        QString Ruta;
        QString Compara;
        Ruta = "/home/"+user+"/tmp/boot/boot/menu/%1.cfg";
        Ruta = Ruta.arg(TipMandriva);
        QFile file("/home/"+user+"/tmp/boot/boot/menu/"+TipMandriva+".cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<MdCfg.count();i++)
        {
            Value0 = MdCfg.value(i);
            if (Value0 != " ")
            {
                Compara = getCompara(Value0, Ruta);
                if (Value0 != Compara)
                {
                    in2 << ""+Value0+"" << "\n";
                }
            }
        }
        MdCfg.clear();
        file.close();
    }
    if (comando == "echo Configurando "+TipPCLinuxOS+"...")
    {
        QString Value0;
        QString Ruta;
        QString Compara;
        Ruta = "/home/"+user+"/tmp/boot/boot/menu/%1.cfg";
        Ruta = Ruta.arg(TipPCLinuxOS);
        QFile file("/home/"+user+"/tmp/boot/boot/menu/"+TipPCLinuxOS+".cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<PlCfg.count();i++)
        {
            Value0 = PlCfg.value(i);
            if (Value0 != " ")
            {
                Compara = getCompara(Value0, Ruta);
                if (Value0 != Compara)
                {
                    in2 << ""+Value0+"" << "\n";
                }
            }
        }
        PlCfg.clear();
        file.close();
    }
    if (comando == "echo Configurando "+TipFedora+"...")
    {
        QString Value0;
        QString Ruta;
        QString Compara;
        Ruta = "/home/"+user+"/tmp/boot/boot/menu/%1.cfg";
        Ruta = Ruta.arg(TipFedora);
        QFile file("/home/"+user+"/tmp/boot/boot/menu/"+TipFedora+".cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<FdCfg.count();i++)
        {
            Value0 = FdCfg.value(i);
            if (Value0 != " ")
            {
                Compara = getCompara(Value0, Ruta);
                if (Value0 != Compara)
                {
                    in2 << ""+Value0+"" << "\n";
                }
            }
        }
        FdCfg.clear();
        file.close();
    }
    if (comando == "echo Configurando "+TipUbuntu+"...")
    {
        QString Value0;
        QString Ruta;
        QString Compara;
        Ruta = "/home/"+user+"/tmp/boot/boot/menu/%1.cfg";
        Ruta = Ruta.arg(TipUbuntu);
        QFile file("/home/"+user+"/tmp/boot/boot/menu/"+TipUbuntu+".cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<UbCfg.count();i++)
        {
            Value0 = UbCfg.value(i);
            if (Value0 != " ")
            {
                Compara = getCompara(Value0, Ruta);
                if (Value0 != Compara)
                {
                    in2 << ""+Value0+"" << "\n";
                }
            }
        }
        UbCfg.clear();
        file.close();
    }
    if (comando == "echo Configurando "+TipArchLinux+"...")
    {
        QString Value0;
        QString Ruta;
        QString Compara;
        Ruta = "/home/"+user+"/tmp/boot/boot/menu/%1.cfg";
        Ruta = Ruta.arg(TipArchLinux);
        QFile file("/home/"+user+"/tmp/boot/boot/menu/"+TipArchLinux+".cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<AlCfg.count();i++)
        {
            Value0 = AlCfg.value(i);
            if (Value0 != " ")
            {
                Compara = getCompara(Value0, Ruta);
                if (Value0 != Compara)
                {
                    in2 << ""+Value0+"" << "\n";
                }
            }
        }
        AlCfg.clear();
        file.close();
    }
    if (comando == "echo Configurando "+TipCentOS+"...")
    {
        QString Value0;
        QString Ruta;
        QString Compara;
        Ruta = "/home/"+user+"/tmp/boot/boot/menu/%1.cfg";
        Ruta = Ruta.arg(TipCentOS);
        QFile file("/home/"+user+"/tmp/boot/boot/menu/"+TipCentOS+".cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<CtCfg.count();i++)
        {
            Value0 = CtCfg.value(i);
            if (Value0 != " ")
            {
                Compara = getCompara(Value0, Ruta);
                if (Value0 != Compara)
                {
                    in2 << ""+Value0+"" << "\n";
                }
            }
        }
        CtCfg.clear();
        file.close();
    }
    if (comando == "echo Configurando "+TipDebian+"...")
    {
        QString Value0;
        QString Ruta;
        QString Compara;
        Ruta = "/home/"+user+"/tmp/boot/boot/menu/%1.cfg";
        Ruta = Ruta.arg(TipDebian);
        QFile file("/home/"+user+"/tmp/boot/boot/menu/"+TipDebian+".cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<DbCfg.count();i++)
        {
            Value0 = DbCfg.value(i);
            if (Value0 != " ")
            {
                Compara = getCompara(Value0, Ruta);
                if (Value0 != Compara)
                {
                    in2 << ""+Value0+"" << "\n";
                }
            }
        }
        DbCfg.clear();
        file.close();
    }
    if (comando == "echo Configurando "+TipKnoppix+"...")
    {
        QString Value0;
        QString Ruta;
        QString Compara;
        Ruta = "/home/"+user+"/tmp/boot/boot/menu/%1.cfg";
        Ruta = Ruta.arg(TipKnoppix);
        QFile file("/home/"+user+"/tmp/boot/boot/menu/"+TipKnoppix+".cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<KnCfg.count();i++)
        {
            Value0 = KnCfg.value(i);
            if (Value0 != " ")
            {
                Compara = getCompara(Value0, Ruta);
                if (Value0 != Compara)
                {
                    in2 << ""+Value0+"" << "\n";
                }
            }
        }
        KnCfg.clear();
        file.close();
    }
    if (comando == "echo Configurando "+TipOpenSUSE+"...")
    {
        QString Value0;
        QString Ruta;
        QString Compara;
        Ruta = "/home/"+user+"/tmp/boot/boot/menu/%1.cfg";
        Ruta = Ruta.arg(TipOpenSUSE);
        QFile file("/home/"+user+"/tmp/boot/boot/menu/"+TipOpenSUSE+".cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<OsCfg.count();i++)
        {
            Value0 = OsCfg.value(i);
            if (Value0 != " ")
            {
                Compara = getCompara(Value0, Ruta);
                if (Value0 != Compara)
                {
                    in2 << ""+Value0+"" << "\n";
                }
            }
        }
        OsCfg.clear();
        file.close();
    }
    if (comando == "echo Configurando "+TipLinuxMint+"...")
    {
        QString Value0;
        QString Ruta;
        QString Compara;
        Ruta = "/home/"+user+"/tmp/boot/boot/menu/%1.cfg";
        Ruta = Ruta.arg(TipLinuxMint);
        QFile file("/home/"+user+"/tmp/boot/boot/menu/"+TipLinuxMint+".cfg");
        file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Append);
        QTextStream in2(&file);
        for(int i=0;i<LmCfg.count();i++)
        {
            Value0 = LmCfg.value(i);
            if (Value0 != " ")
            {
                Compara = getCompara(Value0, Ruta);
                if (Value0 != Compara)
                {
                    in2 << ""+Value0+"" << "\n";
                }
            }
        }
        LmCfg.clear();
        file.close();
    }
    else
    {
        DatoComand = comando.left(4);
    }
}

QString UsbLive::getCompara (QString Valor, QString Ruta)
{
    QProcess *procesoFind, *procesoCut;
    QStringList argumentosFind;
    QStringList argumentosCut;
    QByteArray TipVirtual;
    procesoFind=new QProcess(this);
    procesoCut=new QProcess(this);
    argumentosFind << ""+Ruta+"";
    argumentosCut << ""+Valor+"";
    procesoFind->setStandardOutputProcess(procesoCut);
    procesoFind->start("cat",argumentosFind);
    procesoCut->start("grep",argumentosCut);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoFind->waitForFinished();
    procesoCut->waitForFinished();
    TipVirtual = QString(procesoCut->readAllStandardOutput());
    delete procesoFind;
    delete procesoCut;
    QString res =  QString(TipVirtual);
    res.chop(1);
    return res;
}

void UsbLive::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(DatoComand(QString)), this, SLOT(mibReferencia(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    ui->label_4->show();
    ui->progressBar->setValue(0);
    ui->progressBar->hide();
    ui->label_6->hide();
    ui->pushButton_21->setText(tr("Comenzar"));
    Ctrl = 0;
    comandos.clear();
}

QString UsbLive::getGrub(QString grub)
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << ""+grub+"";
    procesoRPM->start("find",argumentosRPM);
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

QString UsbLive::getIso(QString iso)
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << ""+iso+"";
    procesoRPM->start("ls",argumentosRPM);
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

void UsbLive::on_pushButton_23_clicked()
{
    Ctrl = 1;
    ui->label_4->hide();
    ui->textEdit->setText("");
    QTableWidgetItem *item, *item1, *item2;
    QString activo, activo1, activo2;
    QStringList comandos;
    int itemCount = ui->tableWidget->currentRow();
    if (itemCount == -1)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        item = ui->tableWidget->item(itemCount,3);
        item1 = ui->tableWidget->item(itemCount,5);
        item2 = ui->tableWidget->item(itemCount,1);
        activo = item->text();
        activo1 = item1->text();
        activo2 = item2->text();
        if (activo1 == "Ok")
        {
            int respuesta = 0;
            {
                respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Vaciar el contenido del USB")),
                                   QString::fromUtf8(tr("<center><b>Vaciar USB<b></center><p>"

                                   "En el caso de instalar/utilizar GRUB/GRUB2, no es necesario formatear el USB, ya que con "
                                   "simple hecho de borrar su contenido es posible utilizarlo correctamente.<p>"

                                   "Tambien es aconsejable si quieres vaciarlo por algun motivo, como para cambiar las ISO's "
                                   "instaladas sin tener que formatear, siempre que se utilice GRUB/GRUB2.<p>"

                                   "<b>Procede con mucha precaución.<p>"

                                   "&iquest;Estas seguro de querer vaciar la unidad "+activo+" denominada "+activo2+"?")), QMessageBox::Ok, QMessageBox::No);
            }
            if (respuesta == QMessageBox::Ok){
                QString cm1= QString::fromUtf8(tr("echo Borrado el contenido del USB"));
                system("rm -vR -f "+ruta+""+activo2+"/*");
                ui->radioButton_8->setChecked(false);
                comandos << cm1;
                if (mib != 0)
                    delete mib;
                mib = new DrakeProcesos(comandos, this);
                connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
                connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
                int valor= comandos.count(); mib->Valor(valor,2); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
            }
            return;
        }
        else
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("El USB seleccionado no esta activado, por lo que no puedes procesar la solicitud."));
            m.exec();
            return;
        }
    }
}

QString UsbLive::getDistroIns(QString dev, QString distro)
{
    QProcess *procesoCat, *procesoGrep;
    QStringList argumentosCat, argumentosGrep;
    QByteArray Label;

    procesoCat=new QProcess(this);
    procesoGrep=new QProcess(this);

    argumentosCat << ""+dev+"";
    argumentosGrep << ""+distro+"";

    procesoCat->setStandardOutputProcess(procesoGrep);

    procesoCat->start("ls", argumentosCat);
    procesoGrep->start("grep", argumentosGrep);

    if (! procesoGrep->waitForStarted())
        return QString("");

    procesoCat->waitForFinished();
    procesoGrep->waitForFinished();

    Label = procesoGrep->readAllStandardOutput();

    delete procesoCat;
    delete procesoGrep;
    QString res = QString(Label);
    res.chop(1);
    return res;
}

void UsbLive::ProbarUSB()
{
    comandos.clear();
    if (qemu != "0")
    {
        int respuesta = 0;
        {
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Probar USB")),
                        QString::fromUtf8(tr("<center><b>Probar USB<b></center><p>"

                        "Puedes probar la distros instaladas en el USB mediante emulacion para ver si "
                        "todo ha ido correcto.<p>"

                        "&iquest;Probar la instalacion realizada en el USB "+Valor1+"?")), QMessageBox::Ok, QMessageBox::No);
        }
        if (respuesta == QMessageBox::Ok){
            QString cm1= QString::fromUtf8(tr("echo Probando la instalacion realizada..."));
            QString cm2= "qemu %2";
            cm2=cm2.arg(Valor1);
            comandos << cm1 << cm2;
            if (mib != 0)
                delete mib;
            mib = new DrakeProcesos(comandos, this);
            connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
            connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
            int valor= comandos.count(); mib->Valor(valor,2); mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro); mib->iniciarProceso();
        }
        return;
    }
    else if (qemu == "0")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Para otra ocasion si tras la instalacion quieres probar si funciona, debes instalar qemu o comprobar dependencias para que RecoverDrake lo haga por ti."));
        m.exec();
    }
}

void UsbLive::tableClicked(int row, int /*column*/)
{
    QTableWidgetItem *item1, *item2, *item3, *item4, *item5;
    row = ui->tableWidget->currentRow();
    item1=new QTableWidgetItem;
    item2=new QTableWidgetItem;
    item3=new QTableWidgetItem;
    item4=new QTableWidgetItem;
    item5=new QTableWidgetItem;
    item1 = ui->tableWidget->item(row,5);
    item2 = ui->tableWidget->item(row,1);
    item3 = ui->tableWidget->item(row,0);
    item4 = ui->tableWidget->item(row,3);
    item5 = ui->tableWidget->item(row,4);
    activo1 = item1->text();
    activo2 = item2->text();
    activo3 = item3->text();
    activo4 = item4->text();
    activo5 = item5->text();
    QString Localizar = getDistroIns(""+ruta+""+activo2+"/boot/grub/", "menu.lst");
    QString TipGrub3 = getIso(""+ruta+""+activo2+"/boot/");
    TipGrub3.remove("/");
    QString Localizar1;
    if (TipGrub3 == "grub")
    {
        Localizar1 = getDistroIns(""+ruta+""+activo2+"/boot/grub/", "grub.cfg");
    }
    else if (TipGrub3 == "grub2")
    {
        Localizar1 = getDistroIns(""+ruta+""+activo2+"/boot/grub2/", "grub.cfg");
    }
//    QString Localizar2 = getDistroIns(""+ruta+""+activo2+"/draklive/", "syslinux.cfg");
    if (Localizar == "menu.lst")
    {
        ui->radioButton_12->setChecked(true);
        ui->radioButton_4->setChecked(false);
        ui->radioButton_7->setChecked(false);
    }
    else if (Localizar1 == "grub.cfg")
    {
        ui->radioButton_12->setChecked(false);
        ui->radioButton_4->setChecked(true);
        ui->radioButton_7->setChecked(false);
    }
//    else if (Localizar2 == "syslinux.cfg")
//    {
//        ui->radioButton_12->setChecked(false);
//        ui->radioButton_4->setChecked(false);
//        ui->radioButton_7->setChecked(true);
//    }
    QString Localizar3 = getDistroIns(""+ruta+""+activo2+"/", "boot");
    Localizar3=Localizar3.remove("/");
    QString Localizar4 = getDistroIns(""+ruta+""+activo2+"/", "draklive");
    Localizar4=Localizar4.remove("/");
    if (Localizar4 == "draklive" || Localizar3 == "boot")
    {
        ui->radioButton_8->setChecked(true);
        ui->radioButton_11->setChecked(false);
    }
    else
    {
        ui->radioButton_8->setChecked(false);
        ui->radioButton_11->setChecked(true);
    }
}

QString UsbLive::getLs (QString Ruta, QString Dato)
{
    QProcess *procesoFind, *procesoCut;
    QStringList argumentosFind;
    QStringList argumentosCut;
    QByteArray TipVirtual;

    procesoFind=new QProcess(this);
    procesoCut=new QProcess(this);

    argumentosFind << ""+Ruta+"";
    argumentosCut << ""+Dato+"";

    procesoFind->setStandardOutputProcess(procesoCut);

    procesoFind->start("ls",argumentosFind);
    procesoCut->start("grep",argumentosCut);

    if (! procesoCut->waitForStarted())
        return QString("");

    procesoFind->waitForFinished();
    procesoCut->waitForFinished();

    TipVirtual = QString(procesoCut->readAllStandardOutput());

    delete procesoFind;
    delete procesoCut;
    QString res =  QString(TipVirtual);
    res.chop(1);
    return res;
}

void UsbLive::Enable()
{
    ui->groupBox_12->setEnabled(false);
    ui->pushButton_19->setEnabled(false);
    ui->pushButton_20->setEnabled(false);
    ui->pushButton_23->setEnabled(false);
    ui->pushButton_16->setEnabled(false);
    ui->pushButton_15->setEnabled(false);
    ui->tableWidget->setEnabled(false);
    ui->label_9->hide();
}

void UsbLive::Disabled()
{
    ui->groupBox_12->setEnabled(true);
    ui->pushButton_19->setEnabled(true);
    ui->pushButton_20->setEnabled(true);
    ui->pushButton_23->setEnabled(true);
    ui->pushButton_16->setEnabled(true);
    ui->pushButton_15->setEnabled(true);
    ui->tableWidget->setEnabled(true);
    ui->label_9->show();
}
