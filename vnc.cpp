#include "vnc.h"
#include "ui_vnc.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include "drakesistema.h"
#include <QFile>

vnc::vnc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vnc)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Model= new QSqlTableModel(0,db);
    Model->setTable("DatosVnc");
    Model->select();
    Model1= new QSqlTableModel(0,db);
    Model1->setTable("ipvnc");
    Model1->select();
    ui->tableView->setModel(Model1);
    ui->tableView->setColumnHidden(0, true);
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila(QModelIndex)));
    connect(ui->checkBox_5,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->checkBox_6,SIGNAL(clicked()),this,SLOT(password()));
    connect(ui->checkBox_7,SIGNAL(clicked()),this,SLOT(password1()));
    ui->label_13->setVisible(false);
    Save = 0;
    QSqlQuery query(db);
    query.exec("SELECT tipoIp,clave,contraclave,segundoplano,menuGrafico,escuchar,soloVisual,LimitarIp FROM DatosVnc WHERE id=2");
    query.first();
    if (query.isValid())
    {
        Cantidad=query.value(0).toString();
        Cantidad1=query.value(1).toString();
        Cantidad2=query.value(2).toString();
        Cantidad3=query.value(3).toString();
        Cantidad4=query.value(4).toString();
        Cantidad5=query.value(5).toString();
        Cantidad6=query.value(6).toString();
        Cantidad7=query.value(7).toString();
        if (Cantidad == "0")
        {
            ui->radioButton->setChecked(true);
            ui->groupBox_5->setEnabled(false);
        }
        else if (Cantidad == "1")
        {
            ui->radioButton_2->setChecked(true);
            ui->groupBox_5->setEnabled(true);
        }
        if (Cantidad1 != "")
        {
            ui->lineEdit->setText(Cantidad1);
        }
        else if (Cantidad1 == "")
                ui->label_11->setVisible(false);
        if (Cantidad2 != "")
        {
            ui->lineEdit_2->setText(Cantidad2);
        }
        else if (Cantidad2 == "")
                ui->label_12->setVisible(false);
        if (Cantidad1 == Cantidad2 && Cantidad1 !="")
        {
            ui->label_11->setVisible(true);
            ui->label_12->setVisible(true);
        }
        if (Cantidad3 == "0")
            ui->checkBox->setChecked(false);
        else if (Cantidad3 == "1")
            ui->checkBox->setChecked(true);
        if (Cantidad4 == "0")
            ui->checkBox_2->setChecked(false);
        else if (Cantidad4 == "1")
            ui->checkBox_2->setChecked(true);
        if (Cantidad5 == "0")
            ui->checkBox_3->setChecked(false);
        else if (Cantidad5 == "1")
            ui->checkBox_3->setChecked(true);
        if (Cantidad6 == "0")
            ui->checkBox_4->setChecked(false);
        else if (Cantidad6 == "1")
            ui->checkBox_4->setChecked(true);
        if (Cantidad7 == "0")
        {
            ui->checkBox_5->setChecked(false);
            ui->groupBox_4->setEnabled(false);
        }
        else if (Cantidad7 == "1")
        {
            ui->checkBox_5->setChecked(true);
            ui->groupBox_4->setEnabled(true);
        }
    }
    QSqlQuery query1(db);
    query1.exec("SELECT correo,smtp,pass,destino FROM Correo WHERE id=1");
    query1.first();
    if (query1.isValid())
    {
        Cantidad8=query1.value(0).toString();
        Cantidad9=query1.value(1).toString();
        Cantidad10=query1.value(2).toString();
        Cantidad11=query1.value(3).toString();
        ui->lineEdit_4->setText(Cantidad8);
        ui->lineEdit_5->setText(Cantidad9);
        ui->lineEdit_6->setText(Cantidad10);
        ui->lineEdit_8->setText(Cantidad11);
        ui->label_13->setVisible(true);
    }
    drakeSistema drake;
    QString ip = drake.getIP();
    user = drake.getUser();
    ui->lineEdit_7->setText(ip);
    Stilo = "B";
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
}

vnc::~vnc()
{
    delete ui;
    delete Model;
    delete Model1;
}

void vnc::on_pushButton_2_clicked()
{
    if ( Save == 0)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, tr(QString::fromUtf8("Guardar cambios")),
                         tr(QString::fromUtf8("<center><b>Guardar cambios</center><p>"
                         "&iquest;Guardar cambios antes de salir?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            on_pushButton_clicked();
            close();
        }
        else
        {
            close();
        }
    }
    else
    {
        close();
    }
}

void vnc::Comprobar()
{
    Save = 0;
    if (ui->checkBox_5->isChecked() == true)
    {
        ui->groupBox_4->setEnabled(true);
    }
    else if (ui->checkBox_5->isChecked() == false)
    {
        ui->groupBox_4->setEnabled(false);
    }    
}

void vnc::Comprobar1()
{
    Save = 0;
    if (ui->radioButton_2->isChecked() == true)
    {
        ui->groupBox_5->setEnabled(true);
    }
    else if (ui->radioButton_2->isChecked() == false)
    {
        ui->groupBox_5->setEnabled(false);
    }
    if (ui->radioButton->isChecked() == true)
    {
        ui->groupBox_5->setEnabled(false);
    }
    else if (ui->radioButton->isChecked() == false)
    {
        ui->groupBox_5->setEnabled(true);
    }
}

void vnc::password()
{
    Save = 0;
    if (ui->checkBox_6->isChecked() == true)
    {
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }
    else if (ui->checkBox_6->isChecked() == false)
    {
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
}

void vnc::password1()
{
    Save = 0;
    if (ui->checkBox_7->isChecked() == true)
    {
        ui->lineEdit_6->setEchoMode(QLineEdit::Normal);
    }
    else if (ui->checkBox_7->isChecked() == false)
    {
        ui->lineEdit_6->setEchoMode(QLineEdit::Password);
    }
}

void vnc::cambiaFila(QModelIndex actual)
{
    int i = 0;
    i=actual.row();
    QModelIndex index;
    index=ui->tableView->model()->index(i,0);
    this->id= index.data().toInt();
    index=ui->tableView->model()->index(i,1);
    ui->lineEdit_3->setText(index.data().toString());
    this->fila=i;
}

void vnc::on_pushButton_5_clicked()
{
    Save = 1;
    QSqlQuery query(db);
    query.exec("SELECT tipoIp,clave,contraclave,segundoplano,menuGrafico,escuchar,soloVisual,LimitarIp FROM DatosVnc WHERE id=1");
    query.first();
    if (query.isValid())
    {
        Cantidad=query.value(0).toString();
        Cantidad1=query.value(1).toString();
        Cantidad2=query.value(2).toString();
        Cantidad3=query.value(3).toString();
        Cantidad4=query.value(4).toString();
        Cantidad5=query.value(5).toString();
        Cantidad6=query.value(6).toString();
        Cantidad7=query.value(7).toString();
        if (Cantidad == "0")
        {
            ui->radioButton->setChecked(true);
            ui->groupBox_5->setEnabled(false);
        }
        else if (Cantidad == "1")
        {
            ui->radioButton_2->setChecked(true);
            ui->groupBox_5->setEnabled(true);
        }
        if (Cantidad1 != "")
        {
            ui->lineEdit->setText(Cantidad1);
        }
        else if (Cantidad1 == "")
        {
            ui->label_11->setVisible(false);
            ui->lineEdit->setText(Cantidad1);
        }
        if (Cantidad2 != "")
        {
            ui->lineEdit_2->setText(Cantidad2);
        }
        else if (Cantidad2 == "")
        {
            ui->label_12->setVisible(false);
            ui->lineEdit_2->setText(Cantidad2);
        }
        if (Cantidad1 == Cantidad2 && Cantidad1 !="")
        {
            ui->label_11->setVisible(true);
            ui->label_12->setVisible(true);
        }
        if (Cantidad3 == "0")
            ui->checkBox->setChecked(false);
        else if (Cantidad3 == "1")
            ui->checkBox->setChecked(true);
        if (Cantidad4 == "0")
            ui->checkBox_2->setChecked(false);
        else if (Cantidad4 == "1")
            ui->checkBox_2->setChecked(true);
        if (Cantidad5 == "0")
            ui->checkBox_3->setChecked(false);
        else if (Cantidad5 == "1")
            ui->checkBox_3->setChecked(true);
        if (Cantidad6 == "0")
            ui->checkBox_4->setChecked(false);
        else if (Cantidad6 == "1")
            ui->checkBox_4->setChecked(true);
        if (Cantidad7 == "0")
        {
            ui->checkBox_5->setChecked(false);
            ui->groupBox_4->setEnabled(false);
        }
        else if (Cantidad7 == "1")
        {
            ui->checkBox_5->setChecked(true);
            ui->groupBox_4->setEnabled(true);
        }
    }
    QString cantidad;
    QSqlQuery query1(db);
    query1.exec("SELECT id FROM DatosVnc WHERE id=2");
    query1.first();
    if (query1.isValid())
        cantidad=query1.value(0).toString();
    fila=1;
    if (cantidad == "2")
    {
        QSqlRecord record= Model->record(this->fila);
        record.setValue(0,cantidad.toInt());
        record.setValue(1,Cantidad);
        record.setValue(2,Cantidad1);
        record.setValue(3,Cantidad2);
        record.setValue(4,Cantidad3);
        record.setValue(5,Cantidad4);
        record.setValue(6,Cantidad5);
        record.setValue(7,Cantidad6);
        record.setValue(8,Cantidad7);
        Model->setRecord(this->fila,record);
        Model->submitAll();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
}

void vnc::on_pushButton_clicked()
{
    Save = 1;
    if (ui->radioButton->isChecked())
        Cantidad = "0";
    else if (ui->radioButton_2->isChecked())
        Cantidad = "1";
    Cantidad1 = ui->lineEdit->text();
    Cantidad2 = ui->lineEdit_2->text();
    if (ui->checkBox->isChecked() == false)
        Cantidad3 = "0";
    else if (ui->checkBox->isChecked() == true)
        Cantidad3 = "1";
    if (ui->checkBox_2->isChecked() == false)
        Cantidad4 = "0";
    else if (ui->checkBox_2->isChecked() == true)
        Cantidad4 = "1";
    if (ui->checkBox_3->isChecked() == false)
        Cantidad5 = "0";
    else if (ui->checkBox_3->isChecked() == true)
        Cantidad5 = "1";
    if (ui->checkBox_4->isChecked() == false)
        Cantidad6 = "0";
    else if (ui->checkBox_4->isChecked() == true)
        Cantidad6 = "1";
    if (ui->checkBox_5->isChecked() == false)
        Cantidad7 = "0";
    else if (ui->checkBox_5->isChecked() == true)
        Cantidad7 = "1";
    QString cantidad;
    QSqlQuery query1(db);
    query1.exec("SELECT id FROM DatosVnc WHERE id=2");
    query1.first();
    if (query1.isValid())
        cantidad=query1.value(0).toString();
    fila=1;
    if (cantidad == "2")
    {
        QSqlRecord record= Model->record(this->fila);
        record.setValue(0,cantidad.toInt());
        record.setValue(1,Cantidad);
        record.setValue(2,Cantidad1);
        record.setValue(3,Cantidad2);
        record.setValue(4,Cantidad3);
        record.setValue(5,Cantidad4);
        record.setValue(6,Cantidad5);
        record.setValue(7,Cantidad6);
        record.setValue(8,Cantidad7);
        Model->setRecord(this->fila,record);
        Model->submitAll();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se han podido realizar los cambios. Compruebe la accesibilidad de la base de datos."));
        m.exec();
        return;
    }
}

void vnc::on_lineEdit_2_editingFinished()
{
    Save = 0;
    if (ui->lineEdit_2->text() != "")
    {
        if (ui->lineEdit->text() == ui->lineEdit_2->text())
        {
            ui->label_11->setVisible(true);
            ui->label_12->setVisible(true);
        }
        else if (ui->lineEdit->text() != ui->lineEdit_2->text())
        {
            ui->label_11->setVisible(false);
            ui->label_12->setVisible(false);
        }
    }
}

void vnc::on_pushButton_3_clicked()
{
    Save=0;
    QString ip, Cantidad;
    ip=ui->lineEdit_3->text();
    if (ip == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay datos para insertar."));
        m.exec();
        return;
    }
    QSqlQuery query(db);
    query.exec("SELECT ip FROM ipVnc WHERE ip='"+ip+"'");
    query.first();
    if (query.isSelect())
        Cantidad=query.value(0).toString();
    if (ip == Cantidad)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Ya esta introducida esta ip en la base de datos."));
        m.exec();
        return;
    }

    QSqlQuery query1(db);
    query1.prepare("INSERT INTO ipVnc (ip)"
                  "VALUES (:ip)");
    query1.bindValue(":ip", ip);
    query1.exec();
    Model1->select();
    ui->tableView->setModel(Model1);
    ui->lineEdit_3->setText("");
}

void vnc::on_pushButton_4_clicked()
{
    if (ui->lineEdit_3->text() != "")
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Borrar ip")),
                    QString::fromUtf8(tr("<center><b>Confirmar borrado de ip</center><p>"

                    "Vas a proceder al borrado de la ip...<p>"
                    "<b>"+ui->lineEdit_3->text()+"</b><p>"

                    "&iquest;Borrar ip seleccionada?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            ui->tableView->model()->removeRow(fila);
        }
        else if (respuesta == QMessageBox::No)
        {
            return;
        }
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Nada que procesar."));
        m.exec();
        return;
    }
}

void vnc::on_pushButton_6_clicked()
{
    QString cantidad;
    QSqlQuery query1(db);
    query1.exec("SELECT id FROM Correo WHERE id=1");
    query1.first();
    if (query1.isValid())
        cantidad=query1.value(0).toString();
    fila=1;
    if (ui->lineEdit_8->text() == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has introducido un correo de destino."));
        m.exec();
        return;
    }
    if (cantidad == "1")
    {
        QSqlQuery query2(db);
        query2.exec("UPDATE Correo SET Correo='"+ui->lineEdit_4->text()+"',smtp='"+ui->lineEdit_5->text()+"',pass='"+ui->lineEdit_6->text()+"',destino='"+ui->lineEdit_8->text()+"' WHERE id=1");
    }
    if (ui->lineEdit_4->text() == "" || ui->lineEdit_6->text() == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se pueden crear los ficheros de configuracion sin introducir todos los datos."));
        m.exec();
        return;
    }
    system("touch /home/"+user+"/.smtprc");
    system("cp /etc/ssmtp/ssmtp.conf /etc/ssmtp/ssmtp.conf.bak");
    system("rm /etc/ssmtp/ssmtp.conf");
    system("touch /etc/ssmtp/ssmtp.conf");
    system("cp /etc/ssmtp/revaliases /etc/ssmtp/revaliases.bak");
    system("rm /etc/ssmtp/revaliases");
    system("touch /etc/ssmtp/revaliases");
    QFile file("/home/"+user+"/.smtprc");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream in2(&file);
    in2 << "defaults" << "\n";
    in2 << "account default" << "\n";
    in2 << "from " << ui->lineEdit_4->text() << "@gmail.com" << "\n";
    in2 << "protocol smtp" << "\n";
    in2 << "host smtp.gmail.com" << "\n";
    in2 << "port 25" << "\n";
    in2 << "user " <<  ui->lineEdit_4->text() << "@gmail.com" << "\n";
    in2 << "password " << ui->lineEdit_6->text() << "\n";
    in2 << "auth on" << "\n";
    in2 << "tls on" << "\n";
    file.close();
    QFile file1("/etc/ssmtp/ssmtp.conf");
    file1.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream in(&file1);
    in << "root=" << ui->lineEdit_4->text() << "\n";
    in << "mailhub=smtp.gmail.com:25" << "\n";
    in << "rewriteDomain=" << "\n";
    in << "hostname=" << ui->lineEdit_4->text() << "@gmail.com" << "\n";
    in << "UseSTARTTLS=YES" << "\n";
    in << "AuthUser=" << ui->lineEdit_4->text() << "@gmail.com" << "\n";
    in << "AuthPass=" << ui->lineEdit_6->text() << "\n";
    in << "FromLineOverride=YES" << "\n";
    file1.close();
    QFile file2("/etc/ssmtp/revaliases");
    file2.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream in1(&file2);
    in1 << "root:" << ui->lineEdit_4->text() << ":smtp.gmail.com:25" << "\n";
    in1 << "mainuser:" << ui->lineEdit_4->text() << "@gmail.com" << ":smtp.gmail.com:25" << "\n";
    file2.close();
    system("chown "+user+":"+user+" /home/"+user+"/.smtprc");
    system("unlink /usr/sbin/sendmail");
    system("ln -s /usr/sbin/ssmtp /usr/sbin/sendmail");
    ui->label_13->setVisible(true);
}

void vnc::on_pushButton_7_clicked()
{
    QString Explorador;
    drakeSistema drake;
    Explorador = drake.getStart("find /usr/bin/ -name firefox");
    Explorador.remove("\n");
    if (Explorador == "/usr/bin/firefox")
        system("su - "+user+" -c \"firefox https://accounts.google.com/SignUp?service=mail\"");
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No tienes instalado firefox. Utiliza tu explorador favorito para crear la cuenta de gmail."));
        m.exec();
        return;
    }
}
