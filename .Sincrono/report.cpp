#include "report.h"
#include "ui_report.h"
#include <QSqlQuery>
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>

Report::Report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Model= new QSqlTableModel(0,db);
    Model->setTable("ReportModelo");
    Model->select();
    Model->setHeaderData(5,Qt::Horizontal,tr("Margen superior"));
    Model->setHeaderData(6,Qt::Horizontal,tr("Margen izquierdo"));
    Model->setHeaderData(8,Qt::Horizontal,tr("Modelo por defecto"));
    ui->tableView->setModel(Model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(9, true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();    
    Model1= new QSqlTableModel(0,db);
    Model1->setTable("ReportLineas");
    Model1->select();
    ui->tableView_2->setModel(Model1);
    ui->tableView_2->setColumnHidden(0, true);
    ui->tableView_2->setColumnHidden(10, true);
    ui->tableView_2->resizeColumnsToContents();
    ui->tableView_2->resizeRowsToContents();
    Model2= new QSqlTableModel(0,db);
    Model2->setTable("ReportCampos");
    Model2->select();
    ui->tableView_3->setModel(Model2);
    Model2->setHeaderData(3,Qt::Horizontal,tr("Tipo de documento"));
    ui->tableView_3->setColumnHidden(0, true);
    ui->tableView_3->setColumnHidden(4, true);
    ui->tableView_3->resizeColumnsToContents();
    ui->tableView_3->resizeRowsToContents();
    Model3= new QSqlTableModel(0,db);
    Model3->setTable("ReportDocumento");
    Model3->select();
    ui->tableView_4->setModel(Model3);
    ui->tableView_4->setColumnHidden(0, true);
    ui->tableView_4->setColumnHidden(3, true);
    ui->tableView_4->resizeColumnsToContents();
    ui->tableView_4->resizeRowsToContents();
    Stilo = "B";
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila(QModelIndex)));
    connect(ui->tableView_2->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila1(QModelIndex)));
    connect(ui->tableView_3->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila2(QModelIndex)));
    connect(ui->tableView_4->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila3(QModelIndex)));
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
    ui->comboBox_7->addItem("");
    ui->comboBox_2->addItem("");
    QSqlQuery Variable(db);
    Variable.exec("SELECT Descripcion FROM ReportDocumento");
    while(Variable.next())
    {
        ui->comboBox_7->addItem(Variable.value(0).toString());
        ui->comboBox_2->addItem(Variable.value(0).toString());
    }
    QSqlQuery query(db);
    query.exec("SELECT Descripcion,TipoDocumento FROM ReportCampos");
    while(query.next())
    {
        QString valor = query.value(1).toString();
        QSqlQuery query1(db);
        query1.exec("SELECT Descripcion FROM ReportDocumento WHERE Codigo='"+valor+"'");
        query1.first();
        QString Tipo = query1.value(0).toString();
        ui->comboBox_12->addItem(Tipo+": "+query.value(0).toString());
    }
    ui->tabWidget->clear();
    ui->tabWidget->insertTab(0,ui->tab,tr("Modelos de informe"));
    Llamada = 0;
    ui->pushButton_23->setVisible(false);
    ui->pushButton_24->setVisible(false);
    ui->radioButton->setChecked(true);
    this->installEventFilter(this);
}

Report::~Report()
{
    delete ui;
    delete Model;
    delete Model1;
    delete Model2;
    delete Model3;
}

void Report::on_pushButton_4_clicked()
{
    close();
}

void Report::cambiaFila(QModelIndex actual)
{
    int i;
    i=actual.row();
    QModelIndex index;
    index=ui->tableView->model()->index(i,1);
    ui->lineEdit_2->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,2);
    ui->lineEdit->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,3);
    ui->lineEdit_5->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,4);
    ui->lineEdit_6->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,5);
    ui->lineEdit_3->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,6);
    ui->lineEdit_4->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,7);
    if (index.data().toString() == "V")
        ui->radioButton->setChecked(true);
    else if (index.data().toString() == "H")
            ui->radioButton_2->setChecked(true);
    index=ui->tableView->model()->index(i,8);
    if (index.data().toString() == "Si")
        ui->checkBox->setChecked(true);
    else
        ui->checkBox->setChecked(false);
    index=ui->tableView->model()->index(i,10);
    QSqlQuery query0(db);
    query0.exec("SELECT Descripcion FROM ReportDocumento WHERE Codigo='"+index.data().toString()+"'");
    query0.first();
    QString TipoF = query0.value(0).toString();
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(TipoF));
    this->fila=i;
}

void Report::cambiaFila1(QModelIndex actual)
{
    //falta esta parte
}

void Report::cambiaFila2(QModelIndex actual)
{
    int i;
    i=actual.row();
    QModelIndex index;
    index=ui->tableView_3->model()->index(i,1);
    ui->lineEdit_12->setText(tr(index.data().toString()));
    index=ui->tableView_3->model()->index(i,2);
    ui->lineEdit_13->setText(tr(index.data().toString()));
    index=ui->tableView_3->model()->index(i,3);
    QSqlQuery query0(db);
    query0.exec("SELECT Descripcion FROM ReportDocumento WHERE Codigo='"+index.data().toString()+"'");
    query0.first();
    QString TipoF = query0.value(0).toString();
    ui->comboBox_7->setCurrentIndex(ui->comboBox_7->findText(TipoF));
    this->fila=i;
}

void Report::cambiaFila3(QModelIndex actual)
{
    int i;
    i=actual.row();
    QModelIndex index;
    index=ui->tableView_4->model()->index(i,1);
    ui->lineEdit_14->setText(tr(index.data().toString()));
    index=ui->tableView_4->model()->index(i,2);
    ui->lineEdit_15->setText(tr(index.data().toString()));
    this->fila=i;
}

void Report::changeEvent(QEvent *e)
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

bool Report::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("Report"));
                return true;
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Escape)
            {
                close();
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void Report::on_pushButton_15_clicked()
{
   ui->lineEdit_14->setText("");
   ui->lineEdit_15->setText("");
   ui->lineEdit_14->setFocus();
}

void Report::on_pushButton_16_clicked()
{
    QString Codigo, Descripcion;
    Codigo = ui->lineEdit_14->text();
    Descripcion = ui->lineEdit_15->text();
    QSqlQuery query(db);
    query.exec("SELECT Codigo FROM ReportDocumento WHERE Codigo='"+Codigo+"'");
    query.first();
    QString Code = query.value(0).toString();
    if (Code == Codigo)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El documento que estas intentando insertar ya existe con ese codigo."));
        m.exec();
        return;
    }
    QSqlQuery query1(db);
    query1.prepare("INSERT INTO ReportDocumento (Codigo,Descripcion,Marca)"
                  "VALUES (:Codigo,:Descripcion,:Marca)");
    query1.bindValue(":Codigo", Codigo);
    query1.bindValue(":Descripcion", Descripcion);
    query1.bindValue(":Marca", "");
    query1.exec();
    Model3->select();
    ui->tableView_4->setModel(Model3);
    ui->tableView_4->resizeColumnsToContents();
    ui->tableView_4->resizeRowsToContents();
}

void Report::on_pushButton_17_clicked()
{
    QString Codigo, Descripcion;
    Codigo = ui->lineEdit_14->text();
    Descripcion = ui->lineEdit_15->text();
    QSqlQuery query(db);
    query.exec("SELECT Marca FROM ReportDocumento WHERE Codigo='"+Codigo+"'");
    query.first();
    QString Marca = query.value(0).toString();
    if (Marca == "*")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se pueden modificar los modelos por defecto."));
        m.exec();
        return;
    }
    QSqlRecord record= Model3->record(this->fila);
    record.setValue(2,Descripcion);
    Model3->setRecord(this->fila,record);
    Model3->submitAll();
    ui->tableView_4->resizeColumnsToContents();
    ui->tableView_4->resizeRowsToContents();
}

void Report::on_pushButton_18_clicked()
{
    QString Codigo = ui->lineEdit_14->text();
    QString Descripcion = ui->lineEdit_15->text();
    if (Codigo != "")
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Borrar documento")),
                     QString::fromUtf8(tr("<center><b>Confirmar borrado de documento</center><p>"
                     "Vas a proceder al borrado del documento...<p>"
                     "<b>"+Codigo+" - "+Descripcion+"</b><p>"
                     "&iquest;Borrar documento?")), QMessageBox::Ok, QMessageBox::No);
         if (respuesta == QMessageBox::Ok)
         {
             QSqlQuery query(db);
             query.exec("SELECT Marca FROM ReportDocumento WHERE Codigo='"+Codigo+"'");
             query.first();
             QString Marca = query.value(0).toString();
             if (Marca == "*")
             {
                 QMessageBox m;
                 if (Stilo == "A")
                     m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                 m.setText(tr("No se pueden borrar los modelos por defecto."));
                 m.exec();
                 return;
             }
             ui->tableView_4->model()->removeRow(fila);
             ui->tableView_4->resizeColumnsToContents();
             ui->tableView_4->resizeRowsToContents();
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
        m.setText(tr("Nada que borrar."));
        m.exec();
        return;
    }
}

void Report::on_pushButton_14_clicked()
{
    ui->lineEdit_12->setText("");
    ui->lineEdit_13->setText("");
    ui->lineEdit_12->setFocus();
    ui->comboBox_7->setCurrentItem(0);
}

void Report::on_pushButton_12_clicked()
{
    QString Codigo, Descripcion,Tipo;
    Codigo = ui->lineEdit_12->text();
    Descripcion = ui->lineEdit_13->text();
    Tipo = ui->comboBox_7->currentText();
    if (Tipo == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes elegir un tipo de documento."));
        m.exec();
        return;
    }
    QSqlQuery query0(db);
    query0.exec("SELECT Codigo FROM ReportDocumento WHERE Descripcion='"+Tipo+"'");
    query0.first();
    QString TipoF = query0.value(0).toString();
    QSqlQuery query(db);
    query.exec("SELECT Codigo FROM ReportCampos WHERE Codigo='"+Codigo+"'");
    query.first();
    QString Code = query.value(0).toString();
    if (Code == Codigo)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El campo que estas intentando insertar ya existe con ese codigo."));
        m.exec();
        return;
    }
    QSqlQuery query1(db);
    query1.prepare("INSERT INTO ReportCampos (Codigo,Descripcion,TipoDocumento,Marca)"
                  "VALUES (:Codigo,:Descripcion,:TipoDocumento,:Marca)");
    query1.bindValue(":Codigo", Codigo);
    query1.bindValue(":Descripcion", Descripcion);
    query1.bindValue(":TipoDocumento", TipoF);
    query1.bindValue(":Marca", "");
    query1.exec();
    Model2->select();
    ui->tableView_3->setModel(Model2);
    ui->tableView_3->resizeColumnsToContents();
    ui->tableView_3->resizeRowsToContents();
}

void Report::on_pushButton_13_clicked()
{
    QString Codigo, Descripcion,Tipo;
    Codigo = ui->lineEdit_12->text();
    Descripcion = ui->lineEdit_13->text();
    Tipo = ui->comboBox_7->currentText();
    if (Tipo == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes elegir un tipo de documento para poder modificar."));
        m.exec();
        return;
    }
    QSqlQuery query0(db);
    query0.exec("SELECT Codigo FROM ReportDocumento WHERE Descripcion='"+Tipo+"'");
    query0.first();
    QString TipoF = query0.value(0).toString();
    QSqlQuery query(db);
    query.exec("SELECT Marca FROM ReportCampos WHERE Codigo='"+Codigo+"'");
    query.first();
    QString Marca = query.value(0).toString();
    if (Marca == "*")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se pueden modificar los campos por defecto."));
        m.exec();
        return;
    }
    QSqlRecord record= Model2->record(this->fila);
    record.setValue(2,Descripcion);
    record.setValue(3,TipoF);
    Model2->setRecord(this->fila,record);
    Model2->submitAll();
    ui->tableView_3->resizeColumnsToContents();
    ui->tableView_3->resizeRowsToContents();
}

void Report::on_pushButton_10_clicked()
{
    QString Codigo = ui->lineEdit_12->text();
    QString Descripcion = ui->lineEdit_13->text();
    QString Tipo = ui->comboBox_7->currentText();
    if (Codigo != "")
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Borrar campo")),
                     QString::fromUtf8(tr("<center><b>Confirmar borrado de campo</center><p>"
                     "Vas a proceder al borrado del campo...<p>"
                     "<b>"+Codigo+" - "+Descripcion+"</b><p>"
                     "<b>"+Tipo+"</b><p>"
                     "&iquest;Borrar campo?")), QMessageBox::Ok, QMessageBox::No);
         if (respuesta == QMessageBox::Ok)
         {
             QSqlQuery query(db);
             query.exec("SELECT Marca FROM ReportCampos WHERE Codigo='"+Codigo+"'");
             query.first();
             QString Marca = query.value(0).toString();
             if (Marca == "*")
             {
                 QMessageBox m;
                 if (Stilo == "A")
                     m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                 m.setText(tr("No se pueden borrar los campos por defecto."));
                 m.exec();
                 return;
             }
             ui->tableView_3->model()->removeRow(fila);
             ui->tableView_3->resizeColumnsToContents();
             ui->tableView_3->resizeRowsToContents();
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
        m.setText(tr("Nada que borrar."));
        m.exec();
        return;
    }
}

void Report::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    ui->tabWidget->removeTab(0);
    if (arg1 == tr("Modelos de informe"))
    {
        ui->tabWidget->insertTab(0,ui->tab,arg1);
        ui->tabWidget->setCurrentPage(0);
    }
    if (arg1 == tr("Lista de campos"))
    {
        ui->tabWidget->insertTab(0,ui->tab_3,arg1);
        ui->tabWidget->setCurrentPage(0);
    }
    if (arg1 == tr("Tipo de documento"))
    {
        ui->tabWidget->insertTab(0,ui->tab_6,arg1);
        ui->tabWidget->setCurrentPage(0);
    }
}

void Report::on_pushButton_8_clicked()
{
    Llamada = 1;
    ui->tabWidget->removeTab(0);
    ui->tabWidget->insertTab(0,ui->tab_6,tr("Tipo de documento"));
    ui->tabWidget->setCurrentPage(0);
    if (Llamada == 1)
        ui->pushButton_23->setVisible(true);
}

void Report::on_pushButton_23_clicked()
{
    Llamada = 0;
    ui->tabWidget->removeTab(0);
    ui->tabWidget->insertTab(0,ui->tab,tr("Modelos de informe"));
    ui->tabWidget->setCurrentPage(0);
    ui->pushButton_23->setVisible(false);
}

void Report::on_pushButton_19_clicked()
{
    Llamada = 1;
    ui->tabWidget->removeTab(0);
    ui->tabWidget->insertTab(0,ui->tab_3,tr("Lista de campos"));
    ui->tabWidget->setCurrentPage(0);
    if (Llamada == 1)
        ui->pushButton_24->setVisible(true);
}

void Report::on_pushButton_22_clicked()
{
    QColor color;
    color = QColorDialog::getColor(Qt::green, this, tr("Selecciona Color del Texto"), QColorDialog::DontUseNativeDialog);
    QString cantidad = color.name();
    ui->pushButton_22->setStyleSheet("Color: "+cantidad+"");
}

void Report::on_pushButton_20_clicked()
{
    ui->comboBox_12->setCurrentIndex(0);
    ui->lineEdit_20->setText("");
    ui->lineEdit_20->setFocus();
    ui->lineEdit_21->setText("");
    ui->lineEdit_22->setText("");
    ui->comboBox->setCurrentIndex(0);
    ui->pushButton_22->setStyleSheet("Color: black");
    ui->fontComboBox_2->setCurrentText("DejaVu Sans");
}

void Report::on_pushButton_6_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_2->setFocus();
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->checkBox->setChecked(false);
    ui->comboBox_2->setCurrentIndex(0);
    ui->radioButton->setChecked(true);
}

void Report::on_pushButton_24_clicked()
{
    Llamada = 0;
    ui->tabWidget->removeTab(0);
    ui->tabWidget->insertTab(0,ui->tab,tr("Modelos de informe"));
    ui->tabWidget->setCurrentPage(0);
    ui->pushButton_23->setVisible(false);
}

void Report::on_pushButton_clicked()
{
    QString Codigo, Descripcion,Alto,Ancho,MgSuperior,MgIzquierdo,Orientacion,Defecto,Documento,Tipo;
    Codigo = ui->lineEdit_2->text();
    Descripcion = ui->lineEdit->text();
    Alto = ui->lineEdit_5->text();
    Ancho = ui->lineEdit_6->text();
    MgSuperior = ui->lineEdit_3->text();
    MgIzquierdo = ui->lineEdit_4->text();
    if (ui->radioButton->isChecked())
        Orientacion = "V";
    else if (ui->radioButton_2->isChecked())
        Orientacion = "H";
    if (ui->checkBox->isChecked())
        Defecto = "Si";
    else
        Defecto = "No";
    Tipo = ui->comboBox_2->currentText();
    if (Tipo == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes elegir un tipo de documento."));
        m.exec();
        return;
    }
    QSqlQuery query0(db);
    query0.exec("SELECT Codigo FROM ReportDocumento WHERE Descripcion='"+Tipo+"'");
    query0.first();
    Documento = query0.value(0).toString();
    QSqlQuery query(db);
    query.exec("SELECT Codigo FROM ReportModelo WHERE Codigo='"+Codigo+"'");
    query.first();
    QString Code = query.value(0).toString();
    if (Code == Codigo)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El modelo que estas intentando insertar ya existe con ese codigo."));
        m.exec();
        return;
    }
    QSqlQuery query1(db);
    query1.prepare("INSERT INTO ReportModelo (Codigo,Descripcion,Alto,Ancho,MgSuperior,MgIzquierdo,Orientacion,PorDefecto,Marca,Documento)"
                  "VALUES (:Codigo,:Descripcion,:Alto,:Ancho,:MgSuperior,:MgIzquierdo,:Orientacion,:PorDefecto,:Marca,:Documento)");
    query1.bindValue(":Codigo", Codigo);
    query1.bindValue(":Descripcion", Descripcion);
    query1.bindValue(":Alto", Alto);
    query1.bindValue(":Ancho", Ancho);
    query1.bindValue(":MgSuperior", MgSuperior);
    query1.bindValue(":MgIzquierdo", MgIzquierdo);
    query1.bindValue(":Orientacion", Orientacion);
    query1.bindValue(":PorDefecto", Defecto);
    query1.bindValue(":Marca", "");
    query1.bindValue(":Documento", Documento);
    query1.exec();
    Model->select();
    ui->tableView->setModel(Model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

void Report::on_pushButton_2_clicked()
{
    QString Codigo, Descripcion,Alto,Ancho,MgSuperior,MgIzquierdo,Orientacion,Defecto,Documento,Tipo;
    Codigo = ui->lineEdit_2->text();
    Descripcion = ui->lineEdit->text();
    Alto = ui->lineEdit_5->text();
    Ancho = ui->lineEdit_6->text();
    MgSuperior = ui->lineEdit_3->text();
    MgIzquierdo = ui->lineEdit_4->text();
    if (ui->radioButton->isChecked())
        Orientacion = "V";
    else if (ui->radioButton_2->isChecked())
        Orientacion = "H";
    if (ui->checkBox->isChecked())
        Defecto = "Si";
    else
        Defecto = "No";
    Tipo = ui->comboBox_2->currentText();
    if (Tipo == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Debes elegir un tipo de documento para poder modificar."));
        m.exec();
        return;
    }
    QSqlQuery query0(db);
    query0.exec("SELECT Codigo FROM ReportDocumento WHERE Descripcion='"+Tipo+"'");
    query0.first();
    Documento = query0.value(0).toString();
    QSqlQuery query(db);
    query.exec("SELECT Marca FROM ReportModelo WHERE Codigo='"+Codigo+"'");
    query.first();
    QString Marca = query.value(0).toString();
    if (Marca == "*")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se pueden modificar los modelos por defecto."));
        m.exec();
       return;
    }
    QSqlRecord record= Model->record(this->fila);
    record.setValue(2,Descripcion);
    record.setValue(3,Alto);
    record.setValue(4,Ancho);
    record.setValue(5,MgSuperior);
    record.setValue(6,MgIzquierdo);
    record.setValue(7,Orientacion);
    record.setValue(8,Defecto);
    record.setValue(10,Documento);
    Model->setRecord(this->fila,record);
    Model->submitAll();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

void Report::on_pushButton_3_clicked()
{
    //falta esta parte ya que para eliminar tambien hay que eliminar las lineas que corresponden al modelo... tener en cuenta
    //tambien falta la parte de duplicar modelo, que es facil con solo hacer una pregunta y decir que modelo copia y el nombre de destino..
}
