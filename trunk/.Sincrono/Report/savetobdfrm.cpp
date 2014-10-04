#include "savetobdfrm.h"
#include "ui_savetobdfrm.h"
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <Smpt/SmtpMime>
#include <QColorDialog>
#include <drakesistema.h>
#include <QDomDocument>
#include <QProgressDialog>
#include <QPrinter>
#include <QtConcurrentRun>

SaveToBDFrm::SaveToBDFrm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveToBDFrm)
{
    db=QSqlDatabase::database("PRINCIPAL");
    grad = 1;
    ui->setupUi(this);
    Stilo = "B";
    drakeSistema drake;
    user = drake.getUser();
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
    model = new QSqlTableModel(this,db);
    model->setTable("report");
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnHidden(3,true);
    ui->tableView_2->setModel(model);
    ui->tableView_2->setColumnHidden(0,true);
    ui->tableView_2->setColumnHidden(3,true);
    QStringList headers;
    headers << "" << tr("Nombre") << tr("Descripcion")<< "" << tr("Nivel") << tr("Tabla");
    for (int i = 0; i< headers.size();i++)
        model->setHeaderData(i, Qt::Horizontal, headers.at(i));
    ui->tableView->resizeColumnsToContents();
    ui->tableView_2->resizeColumnsToContents();
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,SLOT(currentRowChanged(QModelIndex,QModelIndex)));
    connect(ui->tableView_2->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),
            this,SLOT(currentRowChanged(QModelIndex,QModelIndex)));
    QSqlQuery q(db);
    q.exec("SELECT name FROM sqlite_master WHERE type='table'");
    while(q.next())
    {
        ui->comboCampo->addItem(q.value(0).toString());
    }
    ui->radioButton->setChecked(true);
    ui->radioButton_4->setChecked(true);
    Formato = "Vista previa";
    ui->radioButton_7->setChecked(true);
    Tipo = 0;
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Cambiar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Cambiar()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Cambiar1()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Cambiar1()));
    connect(ui->radioButton_5,SIGNAL(clicked()),this,SLOT(Cambiar1()));
    connect(ui->radioButton_8,SIGNAL(clicked()),this,SLOT(Cambiar1()));
    connect(ui->radioButton_9,SIGNAL(clicked()),this,SLOT(Cambiar2()));
    connect(ui->radioButton_7,SIGNAL(clicked()),this,SLOT(Cambiar2()));    
    QFileDialog *fdlg = new QFileDialog(this, "Buscador");
    connect(fdlg, SIGNAL(finished(int)),fdlg, SLOT(open()));
    connect(fdlg, SIGNAL(finished(int)),this, SLOT(Comprueba(int)));
    connect(fdlg, SIGNAL(fileSelected(QString)), this, SLOT(ValorRuta(QString)));
    ui->gridLayout_25->addWidget(fdlg);
    fdlg->setWindowState(Qt::WindowMaximized);
    fdlg->setDir("/usr/share/RecoverDrake");
    fdlg->setNameFilter(tr("Archivos xml (*.xml)"));
    fdlg->setLabelText(QFileDialog::Reject, NULL);
    fdlg->setViewMode(QFileDialog::Detail);
    QFileDialog *fdlg1 = new QFileDialog(this, "Buscador");
    connect(fdlg1, SIGNAL(finished(int)),fdlg1, SLOT(open()));
    connect(fdlg1, SIGNAL(finished(int)),this, SLOT(Comprueba(int)));
    connect(fdlg1, SIGNAL(fileSelected(QString)), this, SLOT(ValorRuta(QString)));
    ui->gridLayout_26->addWidget(fdlg1);
    fdlg1->setWindowState(Qt::WindowMaximized);
    fdlg1->setDir("/usr/share/RecoverDrake");
    fdlg1->setNameFilter(tr("Archivos xml (*.xml)"));
    fdlg1->setLabelText(QFileDialog::Reject, NULL);
    fdlg1->setViewMode(QFileDialog::Detail);
    QSqlQuery query(db);
    query.exec("SELECT Correo FROM Smtp");
    while(query.next())
    {
        ui->comboBox->addItem(query.value(0).toString());
    }
    ui->fontComboBox->setCurrentText("DejaVu Sans");
    ui->sizeSpin->setValue(8);
    this->Cambiar();
    this->Cambiar1();
    this->Cambiar2();
    ui->attachments->installEventFilter(this);
}

SaveToBDFrm::~SaveToBDFrm()
{
    delete ui;
}

void SaveToBDFrm::Valor(QString valor, QString tipo, QString Id)
{
    if (valor == "0")
    {
        Value = 0;
        this->setWindowTitle(tr("Guardar DB como..."));
        ui->radioButton->setVisible(true);
        ui->radioButton_2->setVisible(true);
        ui->pushButton_3->setVisible(false);
        ui->groupBox_3->setVisible(false);
        ui->label_16->setVisible(false);
        ui->lineEdit->setVisible(false);
        ui->pushButton_5->setVisible(false);
    }
    else if (valor == "1")
    {
        Value = 1;
        this->setWindowTitle(tr("Abrir DB desde..."));
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(false);
        ui->tableView->selectRow(0);
        ui->groupBox->setEnabled(false);
        ui->radioButton->setVisible(true);
        ui->radioButton_2->setVisible(true);
        ui->groupBox_3->setVisible(false);
        ui->label_16->setVisible(false);
        ui->lineEdit->setVisible(false);
        ui->pushButton_5->setVisible(false);
    }
    else if (valor == "2" )
    {
        Value = 2;
        this->setWindowTitle(tr("Formatos de impresion..."));
        ui->pushButton_2->setVisible(false);
        ui->pushButton->setVisible(false);
        Listado = tipo;
        IDUser =Id;
        model->setFilter("report_table like '"+Listado+"'");
        ui->tableView->setModel(model);
        ui->tableView->selectRow(0);
        ui->groupBox->setEnabled(false);
        ui->groupBox_2->setEnabled(false);
        ui->label_16->setVisible(false);
        ui->lineEdit->setVisible(false);
        ui->pushButton_5->setVisible(false);
    }
}

void SaveToBDFrm::currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    int r = current.row();
    Posicion = ui->tableView->model()->index(r,0).data().toInt();
    ui->txtNombre->setText(ui->tableView->model()->index(r,1).data().toString());
    ui->txtDesc->setText(ui->tableView->model()->index(r,2).data().toString());
    ui->spinGrd->setValue(ui->tableView->model()->index(r,4).data().toInt());
    ui->comboCampo->setCurrentText(ui->tableView->model()->index(r,5).data().toString());
    Posicion = ui->tableView_2->model()->index(r,0).data().toInt();
    ui->txtNombre_2->setText(ui->tableView_2->model()->index(r,1).data().toString());
    ui->txtDesc_2->setText(ui->tableView_2->model()->index(r,2).data().toString());
    ui->spinGrd_2->setValue(ui->tableView_2->model()->index(r,4).data().toInt());
    ui->comboCampo_2->setCurrentText(ui->tableView_2->model()->index(r,5).data().toString());
}

void SaveToBDFrm::on_txtNombre_textChanged(const QString &arg1)
{
    nombre = arg1;
}

void SaveToBDFrm::on_txtDesc_textChanged(const QString &arg1)
{
    desc = arg1;
}

void SaveToBDFrm::on_spinGrd_valueChanged(int arg1)
{
    grad = arg1;
}

void SaveToBDFrm::Comprobar()
{
    if (Value != 2)
    {
        grad = ui->spinGrd->value();
        if (nombre == "" || desc == "")
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("El nombre y la descripcion no pueden estar vacios."));
            m.exec();
            return;
        }
        if (Value == 0)
        {
            if (grad == 0)
            {
                int respuesta = 0;
                respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                            QString::fromUtf8(tr("<center><b>Formato de nivel 0</center><p>"
                            "Has seleccionado guardar el formato en nivel 0 y yo no te lo aconsejo, ya que "
                            "a partir del momento que se haya guardado,  no se podrá borrar o modificar.<p>"
                            "Si quieres que se pueda borrar hazlo con nivel 1.<p>"
                            "&iquest;Seguir guardando?")), QMessageBox::Ok, QMessageBox::No);
                if (respuesta == QMessageBox::Ok)
                {
                    int Totalizar=0;
                    QSqlQuery query(db);
                    query.exec("SELECT report_name FROM Report WHERE report_name='"+nombre+"' AND report_grade = 0");
                    while(query.next())
                           Totalizar++;
                    if (Totalizar > 0)
                    {
                        QMessageBox m;
                        if (Stilo == "A")
                            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                        m.setText(tr("El Reporte seleccionado es de solo lectura.<p>No se puede modificar."));
                        m.exec();
                        return;
                    }
                    else
                        this->accept();;
                }
                else
                    return;
            }
            else
                this->accept();
        }
        else if (Value == 1)
            this->accept();;
    }
    else
    {
        if (Formato == "PDF")
        {
            if (ui->lineEdit->text() == "")
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("No hay una ruta para guardar el formato pdf."));
                m.exec();
                return;
            }
        }
            if (Formato == "Mail")
            {
                if (ui->lineEdit_2->text() == "")
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("No hay una ruta para guardar el formato pdf."));
                    m.exec();
                    return;
                }
            }
        if (Tipo == 0)
        {
            if (Posicion < 1)
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Tienes que seleccionar un formato para poder imprimir."));
                m.exec();
                return;
            }
        }
        else if (Tipo == 1)
        {
            if (Ruta == "")
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Tienes que seleccionar un formato para poder imprimir."));
                m.exec();
                return;
            }
        }
        this->Comenzar();
    }
}

void SaveToBDFrm::on_pushButton_clicked()
{
    grad = ui->spinGrd->value();
    int Totalizar=0;
    QSqlQuery query(db);
    query.exec("SELECT report_name FROM Report WHERE report_name='"+nombre+"' AND report_grade != 0");
    while(query.next())
           Totalizar++;
    if (Totalizar > 0)
    {
        QSqlQuery query(db);
        query.exec("DELETE FROM Report WHERE report_name='"+nombre+"' AND report_grade != 0");
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->selectRow(0);
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El Reporte seleccionado es de solo lectura.<p>No se puede borrar."));
        m.exec();
        return;
    }
}

void SaveToBDFrm::on_pushButton_2_clicked()
{
    ui->txtNombre->setText("");
    ui->txtDesc->setText("");
    ui->spinGrd->setValue(grad);
    ui->txtNombre->setFocus();
    ui->comboCampo->setCurrentIndex(0);
}

void SaveToBDFrm::on_comboCampo_currentIndexChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    tabla = ui->comboCampo->currentText();
}

void SaveToBDFrm::Cambiar()
{
    if (ui->radioButton->isChecked())
    {
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->btnAcept->setVisible(true);
        Tipo = 0;
    }
    else if (ui->radioButton_2->isChecked())
    {
        ui->stackedWidget_2->setCurrentIndex(1);
        ui->btnAcept->setVisible(true);
        Tipo = 1;
    }   
}

void SaveToBDFrm::Cambiar1()
{
    if (ui->radioButton_3->isChecked())
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->btnAcept->setVisible(false);
        ui->pushButton_3->setVisible(true);
        ui->label_16->setVisible(false);
        ui->lineEdit->setVisible(false);
        ui->pushButton_5->setVisible(false);
        Formato = "Mail";
    }
    else if (ui->radioButton_4->isChecked())
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->btnAcept->setVisible(true);
        ui->pushButton_3->setVisible(false);
        ui->label_16->setVisible(false);
        ui->lineEdit->setVisible(false);
        ui->pushButton_5->setVisible(false);
        Formato = "Vista previa";
    }
    else if (ui->radioButton_5->isChecked())
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->btnAcept->setVisible(true);
        ui->pushButton_3->setVisible(false);
        ui->label_16->setVisible(false);
        ui->lineEdit->setVisible(false);
        ui->pushButton_5->setVisible(false);
        Formato = "Imprimir";
    }
    else if (ui->radioButton_8->isChecked())
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->btnAcept->setVisible(true);
        ui->pushButton_3->setVisible(false);
        ui->label_16->setVisible(true);
        ui->lineEdit->setVisible(true);
        ui->pushButton_5->setVisible(true);
        Formato = "PDF";
    }
}

void SaveToBDFrm::Cambiar2()
{
    if (ui->radioButton_9->isChecked())
    {
        ui->stackedWidget_3->setCurrentIndex(0);
    }
    else if (ui->radioButton_7->isChecked())
    {
        ui->stackedWidget_3->setCurrentIndex(1);
    }
}

void SaveToBDFrm::ValorRuta(QString Valor)
{
    Ruta = Valor;
}

void SaveToBDFrm::Comprueba(int a)
{
    Dir = a;
    if (Dir == 1)
        this->Comprobar();
}

void SaveToBDFrm::on_pushButton_3_clicked()
{
    this->Comprobar();
    QMessageBox okMessage (this);
    QString Correo, ssl, auth, host, password, user;
    int port;
    Correo=ui->comboBox->currentText();
    QSqlQuery query(db);
    query.exec("SELECT smptserver,Clave,Autenticacion,SSL,User,Port FROM Smtp WHERE Correo='"+Correo+"'");
    query.first();
    host=query.value(0).toString();
    password=query.value(1).toString();
    auth=query.value(2).toString();
    ssl=query.value(3).toString();
    user=query.value(4).toString();
    port=query.value(5).toInt();
    EmailAddress *sender = stringToEmail(Correo);
    QStringList rcptStringList = ui->recipients->text().split(';');
    QString subject = ui->subject->text();
    QString html = ui->texteditor->toHtml();
    if (ssl == "Si")
    {
        SmtpClient smtp (host, port, SmtpClient::SslConnection);
        MimeMessage message;
        message.setSender(sender);
        message.setSubject(subject);
        for (int i = 0; i < rcptStringList.size(); ++i)
             message.addRecipient(stringToEmail(rcptStringList.at(i)));
        MimeHtml content;
        content.setHtml(html);
        message.addPart(&content);
        for (int i = 0; i < ui->attachments->count(); ++i)
        {
            message.addPart(new MimeAttachment(new QFile(ui->attachments->item(i)->text())));
        }
        if (!smtp.connectToHost())
        {
            if (ui->checkBox->isChecked())
            {
                int respuesta = 0;
                respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                            QString::fromUtf8(tr("<center><b>Conexion fallida</center><p>"
                            "La conexion ha fallado.<p>"
                            "&iquest;Quieres eliminar el pdf temporal?")), QMessageBox::Ok, QMessageBox::No);
                if (respuesta == QMessageBox::Ok)
                {
                    QFile::remove(RutaPDF);
                }
                else
                    return;
            }
            if (Stilo == "A")
                okMessage.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            okMessage.setText(tr("La conexion ha fallado."));
            okMessage.exec();
            return;
        }
        if (auth == "Si")
            if (!smtp.login(user, password))
            {
                if (ui->checkBox->isChecked())
                {
                    int respuesta = 0;
                    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                                QString::fromUtf8(tr("<center><b>Autentificacion fallida</center><p>"
                                "La autentificacion ha fallado.<p>"
                                "&iquest;Quieres eliminar el pdf temporal?")), QMessageBox::Ok, QMessageBox::No);
                    if (respuesta == QMessageBox::Ok)
                    {
                        QFile::remove(RutaPDF);
                    }
                    else
                        return;
                }
                if (Stilo == "A")
                    okMessage.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                okMessage.setText(tr("La autentificacion ha fallado."));
                okMessage.exec();
                return;
            }

        if (!smtp.sendMail(message))
        {
            if (ui->checkBox->isChecked())
            {
                int respuesta = 0;
                respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                            QString::fromUtf8(tr("<center><b>Envio fallido</center><p>"
                            "El envio del mail ha fallado.<p>"
                            "&iquest;Quieres eliminar el pdf temporal?")), QMessageBox::Ok, QMessageBox::No);
                if (respuesta == QMessageBox::Ok)
                {
                    QFile::remove(RutaPDF);
                }
                else
                    return;
            }
            if (Stilo == "A")
                okMessage.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            okMessage.setText(tr("El envio del mail ha fallado."));
            okMessage.exec();
            return;
        }
        else
        {
            if (Stilo == "A")
                okMessage.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            okMessage.setText(tr("El email ha sido enviado con exito."));
            okMessage.exec();
            if (ui->checkBox->isChecked())
                QFile::remove(RutaPDF);
        }
        smtp.quit();
    }
    else
    {
        SmtpClient smtp (host, port, SmtpClient::TcpConnection);
        MimeMessage message;
        message.setSender(sender);
        message.setSubject(subject);
        for (int i = 0; i < rcptStringList.size(); ++i)
             message.addRecipient(stringToEmail(rcptStringList.at(i)));
        MimeHtml content;
        content.setHtml(html);
        message.addPart(&content);
        for (int i = 0; i < ui->attachments->count(); ++i)
        {
            message.addPart(new MimeAttachment(new QFile(ui->attachments->item(i)->text())));
        }
        if (!smtp.connectToHost())
        {
            if (ui->checkBox->isChecked())
            {
                int respuesta = 0;
                respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                            QString::fromUtf8(tr("<center><b>Conexion fallida</center><p>"
                            "La conexion ha fallado.<p>"
                            "&iquest;Quieres eliminar el pdf temporal?")), QMessageBox::Ok, QMessageBox::No);
                if (respuesta == QMessageBox::Ok)
                {
                    QFile::remove(RutaPDF);
                }
                else
                    return;
            }
            if (Stilo == "A")
                okMessage.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            okMessage.setText(tr("La conexion ha fallado"));
            okMessage.exec();
            return;
        }
        if (auth== "Si")
            if (!smtp.login(user, password))
            {
                if (ui->checkBox->isChecked())
                {
                    int respuesta = 0;
                    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                                QString::fromUtf8(tr("<center><b>Autentificacion fallida</center><p>"
                                "La autentificacion ha fallado.<p>"
                                "&iquest;Quieres eliminar el pdf temporal?")), QMessageBox::Ok, QMessageBox::No);
                    if (respuesta == QMessageBox::Ok)
                    {
                        QFile::remove(RutaPDF);
                    }
                    else
                        return;
                }
                if (Stilo == "A")
                    okMessage.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                okMessage.setText(tr("La autentificacion ha fallado"));
                okMessage.exec();
                return;
            }

        if (!smtp.sendMail(message))
        {
            if (ui->checkBox->isChecked())
            {
                int respuesta = 0;
                respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                            QString::fromUtf8(tr("<center><b>Envio fallido</center><p>"
                            "El envio del mail ha fallado.<p>"
                            "&iquest;Quieres eliminar el pdf temporal?")), QMessageBox::Ok, QMessageBox::No);
                if (respuesta == QMessageBox::Ok)
                {
                    QFile::remove(RutaPDF);
                }
                else
                    return;
            }
            if (Stilo == "A")
                okMessage.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            okMessage.setText(tr("El envio del mail ha fallado"));
            okMessage.exec();
            return;
        }
        else
        {
            if (Stilo == "A")
                okMessage.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            okMessage.setText(tr("El mail ha sido enviado con exito."));
            okMessage.exec();
            if (ui->checkBox->isChecked())
                QFile::remove(RutaPDF);
        }
        smtp.quit();
    }
}

void SaveToBDFrm::on_pushButton_4_clicked()
{
    opciones *opcion=new opciones(this);
    if (Stilo == "A")
        opcion->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    opcion->Valor("mail");
    opcion->exec();
    QSqlQuery query(db);
    ui->comboBox->clear();
    query.exec("SELECT Correo FROM Smtp");
    while(query.next())
    {
        ui->comboBox->addItem(query.value(0).toString());
    }
}

EmailAddress* SaveToBDFrm::stringToEmail(const QString &str)
{
    int p1 = str.indexOf("<");
    int p2 = str.indexOf(">");
    if (p1 == -1)
    {
        return new EmailAddress(str);
    }
    else
    {
        return new EmailAddress(str.mid(p1 + 1, p2 - p1 - 1), str.left(p1));
    }
}

void SaveToBDFrm::on_addAttachment_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    if (dialog.exec())
        ui->attachments->addItems(dialog.selectedFiles());
}

bool SaveToBDFrm::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == ui->attachments)
    {
        if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                //falta hacer la ayuda para imprimir
//                ayuda = new Ayuda(this);
//                ayuda->show();
//                ayuda->Valor(tr("Imprimir"));
                return true;
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Delete)
            {
                ui->attachments->takeItem(ui->attachments->currentRow());
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void SaveToBDFrm::on_btnBold_clicked(bool checked)
{
    if(checked)
        ui->texteditor->setFontWeight(QFont::Bold);
    else
        ui->texteditor->setFontWeight(QFont::Normal);
    ui->texteditor->setFocus();
}

void SaveToBDFrm::on_btnItalic_clicked(bool checked)
{
    ui->texteditor->setItalic(checked);
    ui->texteditor->setFocus();
}

void SaveToBDFrm::on_btnUnder_clicked(bool checked)
{
    ui->texteditor->setUnderline(checked);
    ui->texteditor->setFocus();
}

void SaveToBDFrm::on_btnColor_clicked()
{
    QColorDialog d(this);
    if(d.exec() == QDialog::Accepted)
    {
        ui->texteditor->setColor(d.selectedColor());
    }
    ui->texteditor->setFocus();
}

void SaveToBDFrm::on_btnLeft_clicked()
{
    ui->texteditor->setAlignment(Qt::AlignLeft);
    ui->texteditor->setFocus();
}

void SaveToBDFrm::on_btnCenter_clicked()
{
    ui->texteditor->setAlignment(Qt::AlignCenter);
    ui->texteditor->setFocus();
}

void SaveToBDFrm::on_btnRigth_clicked()
{
    ui->texteditor->setAlignment(Qt::AlignRight);
    ui->texteditor->setFocus();
}

void SaveToBDFrm::on_sizeSpin_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    ui->texteditor->setFont(QFont(ui->fontComboBox->currentText(),ui->sizeSpin->value()));
    ui->texteditor->setFocus();
}

void SaveToBDFrm::on_fontComboBox_currentIndexChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    ui->texteditor->setFont(QFont(ui->fontComboBox->currentText(),ui->sizeSpin->value()));
    ui->texteditor->setFocus();
}

void SaveToBDFrm::on_pushButton_5_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileName = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar pdf")),
                        path,trUtf8(tr("Formato pdf (*.pdf)")));
    if (fileName.isEmpty())
        return;
    if (fileName.contains(".pdf"))
        ui->lineEdit->setText(fileName);
    else
        ui->lineEdit->setText(""+fileName+".pdf");
}

void SaveToBDFrm::on_lineEdit_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        RutaPDF = arg1;
        ui->lineEdit_2->setText("");
    }
}

void SaveToBDFrm::on_tableView_doubleClicked(const QModelIndex &index)
{
    int r = index.row();
    Posicion = ui->tableView->model()->index(r,0).data().toInt();
    this->Comprobar();
}

void SaveToBDFrm::on_btnAcept_clicked()
{
    this->Comprobar();
}

void SaveToBDFrm::on_btnCancel_clicked()
{
    close();
}

void SaveToBDFrm::Comenzar()
{
    QDomDocument doc("Impresion");
    if (Tipo == 0)
    {
        QSqlQuery query(db);
        query.exec("SELECT report_source FROM Report WHERE report_id ='"+QString::number(Posicion)+"'");
        query.first();
        QByteArray xmlData(query.value(0).toByteArray());
        doc.setContent(xmlData);
    }
    else if (Tipo == 1)
    {
        QFile ff(Ruta);
        if(ff.open(QFile::ReadOnly))
        {
            QByteArray xmlData(ff.readAll());
            doc.setContent(xmlData);
        }
        ff.close();
    }
    QProgressDialog* pDlg = new QProgressDialog(this);
    pDlg->setMaximum(0);
    pDlg->setValue(0);
    pDlg->show();
    QPrinter * printer = new QPrinter();
    if (Formato == "PDF" || Formato == "Mail")
    {
         printer->setOutputFormat(QPrinter::PdfFormat);
         printer->setOutputFileName(RutaPDF);
    }
    if (doc.toString().contains("<Orientation type=\"V\"/>"))
        printer->setOrientation(QPrinter::Portrait);
    else if (doc.toString().contains("<Orientation type=\"H\"/>"))
        printer->setOrientation(QPrinter::Landscape);
    render = new ReportRenderer();
    render->setPrinter(printer);
    render->setDocIn(doc);
    QMap<QString,QString> c;
    if (Listado == "Clave")
    {
        c["General.Clave"] = "UserRD = '"+IDUser+"'";
        render->setQueryClausules(c);
    }
    QtConcurrent::run(render, &ReportRenderer::PreRender);
    connect(render,SIGNAL(end()),pDlg,SLOT(deleteLater()));
    if (Formato== "Imprimir")
        connect(render,SIGNAL(end()),this,SLOT(print()));
    if (Formato == "Vista previa")
        connect(render,SIGNAL(end()),this,SLOT(previewReady()));
    if (Formato == "PDF")
        connect(render,SIGNAL(end()),this,SLOT(pdf()));
    if (Formato == "Mail")
    {
        connect(render,SIGNAL(end()),this,SLOT(pdf()));
        int Verificar = 0;
        int Peso = ui->attachments->count();
        for (int k1 = 0; k1 < Peso; k1++)
        {
               if (ui->attachments->item(k1)->text().contains(RutaPDF))
               {
                    Verificar = 1;
               }
        }
        if (Verificar == 0)
            ui->attachments->addItem(RutaPDF);
    }
}

void SaveToBDFrm::print()
{
    QPrintDialog * printDialog = new QPrintDialog(render->getPrinter(), this);
    connect(printDialog, SIGNAL(accepted(QPrinter*)), render, SLOT(Print(QPrinter*)));
    if (printDialog->exec() == QDialog::Accepted){}
}

void SaveToBDFrm::pdf()
{
    render->Print(render->getPrinter());
}

void SaveToBDFrm::previewReady()
{
    QPrintPreviewDialog * pre = new QPrintPreviewDialog(render->getPrinter(),this);
    connect(pre, SIGNAL(paintRequested(QPrinter*)), render, SLOT(Print(QPrinter*)));
    pre->showMaximized();
    pre->exec();
}

void SaveToBDFrm::on_pushButton_6_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileName = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar pdf")),
                        path,trUtf8(tr("Formato pdf (*.pdf)")));
    if (fileName.isEmpty())
        return;
    if (fileName.contains(".pdf"))
        ui->lineEdit_2->setText(fileName);
    else
        ui->lineEdit_2->setText(""+fileName+".pdf");
}

void SaveToBDFrm::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    int r = index.row();
    Posicion = ui->tableView_2->model()->index(r,0).data().toInt();
    this->Comprobar();
}

void SaveToBDFrm::on_lineEdit_2_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        RutaPDF = arg1;
        ui->lineEdit->setText("");
    }
}
