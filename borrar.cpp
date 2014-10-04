#include "borrar.h"
#include "ui_borrar.h"
#include <QSqlQuery>
#include <QKeyEvent>
#include "drakesistema.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>


//borrar los ejecutables infectados: find /home/cristian/Música/ -name *.exe -exec rm -vv {} ;



Borrar::Borrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Borrar)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Stilo = "B";
    mib = 0;
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
    connect(ui->radioButton_51,SIGNAL(clicked()),this,SLOT(Cambio()));
    connect(ui->radioButton_54,SIGNAL(clicked()),this,SLOT(Cambio()));
    ui->radioButton_51->setChecked(true);
    ui->stackedWidget_2->setCurrentIndex(0);
    connect(ui->radioButton_13,SIGNAL(clicked()),this,SLOT(Cambio1()));
    connect(ui->radioButton_14,SIGNAL(clicked()),this,SLOT(Cambio1()));
    connect(ui->radioButton_16,SIGNAL(clicked()),this,SLOT(Cambio1()));
    connect(ui->radioButton_29,SIGNAL(clicked()),this,SLOT(Cambio1()));
    connect(ui->radioButton_49,SIGNAL(clicked()),this,SLOT(Cambio1()));
    connect(ui->radioButton_39,SIGNAL(clicked()),this,SLOT(Cambio1()));
    ui->radioButton_13->setChecked(true);
    ui->stackedWidget->setCurrentIndex(0);
    ui->radioButton_6->setChecked(true);
    ui->radioButton_9->setChecked(true);
    ui->radioButton_23->setChecked(true);
    ui->radioButton_37->setChecked(true);
    ui->radioButton_43->setChecked(true);
    ui->radioButton_55->setChecked(true);
    ui->pushButton->setVisible(false);
    ui->pushButton_4->setVisible(false);
    Formato = 0;
    this->installEventFilter(this);
}

Borrar::~Borrar()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void Borrar::Valor(QString valor)
{
    if (valor == "Quitar")
        CierreTotal = 1;
}

void Borrar::closeEvent ( QCloseEvent * event )
{
    if (CierreTotal == 1)
    {
        emit Cerrar();
        event->accept();
    }
    else
    {
        close();
        event->accept();
    }
}

void Borrar::changeEvent(QEvent *e)
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

bool Borrar::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Escape)
            {
                if (CierreTotal == 0)
                    close();
                else if (CierreTotal == 1)
                    return true;
            }
        }
        if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("Borrador"));
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void Borrar::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    QStringList lista;
    float f;
    qint64 size;
    int iFilas;
    QString nombre, ruta;
    lista = valor.split("\n");
    for(int i=0;i<lista.count();i++)
    {
        QString Value0 = lista.value(i);
        QString Valor1 = Value0.left(4);
        QString Valor2 = Value0.left(1);
        if (Value0 != "")
        {
            if (Valor1 != "find")
            {
                if (Valor2 != ":")
                {
                    QFile file(Value0);
                    size = QFileInfo(file).size();
                    ruta = QFileInfo(file).absoluteFilePath();
                    nombre = QFileInfo(file).fileName();
                    f=(size + 1023) / 1024;
                    if (Tipo == "M")
                        f=f/1024;
                    else if (Tipo == "G")
                    {
                        f=f/1024;
                        f=f/1024;
                    }
                    else
                    {
                        if (f < 1024)
                            Tipo="k";
                        else if (f >= 1024 || f < 1048576)
                        {
                            f=f/1024;
                            Tipo="M";
                        }
                        else if (f >= 1048576)
                        {
                            f=f/1024;
                            f=f/1024;
                            Tipo="G";
                        }
                    }
                    QTableWidgetItem *item1, *item2, *item3;
                    item1=new QTableWidgetItem;
                    item2=new QTableWidgetItem;
                    item3=new QTableWidgetItem;
                    item1->setText(nombre);
                    item2->setText(""+QString::number(f,'f',2)+""+Tipo+"");
                    item3->setText(ruta);
                    iFilas=ui->tableWidget_2->rowCount();
                    ui->tableWidget_2->insertRow(iFilas);
                    ui->tableWidget_2->setItem(iFilas,0,item1);
                    ui->tableWidget_2->setItem(iFilas,1,item2);
                    ui->tableWidget_2->setItem(iFilas,2,item3);
                }
            }
        }
        Tipo.clear();
    }
    ui->tableWidget_2->resizeColumnsToContents();
}

void Borrar::Cambio()
{
    if (ui->radioButton_51->isChecked())
    {
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->stackedWidget->show();
    }
    if (ui->radioButton_54->isChecked())
    {
        ui->stackedWidget_2->setCurrentIndex(1);
        ui->stackedWidget->hide();
    }
}

void Borrar::Cambio1()
{
    if (ui->radioButton_13->isChecked())
        ui->stackedWidget->setCurrentIndex(0);
    if (ui->radioButton_14->isChecked())
        ui->stackedWidget->setCurrentIndex(1);
    if (ui->radioButton_16->isChecked())
        ui->stackedWidget->setCurrentIndex(2);
    if (ui->radioButton_29->isChecked())
        ui->stackedWidget->setCurrentIndex(3);
    if (ui->radioButton_49->isChecked())
        ui->stackedWidget->setCurrentIndex(4);
    if (ui->radioButton_39->isChecked())
        ui->stackedWidget->setCurrentIndex(5);
}

void Borrar::mibFin()
{
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    if (Formato == 1)
    {
        Formato = 0;
        ui->pushButton->setVisible(true);
        ui->pushButton_4->setVisible(true);
        ui->pushButton_9->setVisible(false);
    }
    else if (Formato == 0)
    {
        ui->pushButton->setVisible(false);
        ui->pushButton_4->setVisible(false);
        ui->pushButton_9->setVisible(true);
    }
}

void Borrar::on_pushButton_2_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void Borrar::on_pushButton_3_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio a buscar?"),path,QFileDialog::ShowDirsOnly);
    if (fileNameDirectori.isEmpty())
        return;
    ui->lineEdit_8->setText(fileNameDirectori);
}

void Borrar::on_pushButton_9_clicked()
{
    Formato = 1;
    int Borrado, x;
    Borrado = ui->tableWidget_2->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget_2->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    if (ui->lineEdit_8->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has definido la ruta desde donde buscar."));
        m.exec();
        return;
    }
    if (ui->radioButton_51->isChecked())
    {
        if (ui->radioButton_13->isChecked())
        {
            if (ui->radioButton_5->isChecked())
                Buscar = "*"+ui->radioButton_5->text();
            if (ui->radioButton_19->isChecked())
                Buscar = "*"+ui->radioButton_19->text();
            if (ui->radioButton_20->isChecked())
                Buscar = "*"+ui->radioButton_20->text();
            if (ui->radioButton_4->isChecked())
                Buscar = "*"+ui->radioButton_4->text();
            if (ui->radioButton_3->isChecked())
                Buscar = "*"+ui->radioButton_3->text();
            if (ui->radioButton_21->isChecked())
                Buscar = "*"+ui->radioButton_21->text();
            if (ui->radioButton_22->isChecked())
                Buscar = "*"+ui->radioButton_22->text();
            if (ui->radioButton_8->isChecked())
                Buscar = "*"+ui->radioButton_8->text();
            if (ui->radioButton_7->isChecked())
                Buscar = "*"+ui->radioButton_7->text();
            if (ui->radioButton_6->isChecked())
                Buscar = "*"+ui->radioButton_6->text();
        }
        if (ui->radioButton_14->isChecked())
        {
            if (ui->radioButton_9->isChecked())
                Buscar = "*"+ui->radioButton_9->text();
            if (ui->radioButton_12->isChecked())
                Buscar = "*"+ui->radioButton_12->text();
            if (ui->radioButton_59->isChecked())
                Buscar = "*"+ui->radioButton_59->text();
            if (ui->radioButton_11->isChecked())
                Buscar = "*"+ui->radioButton_11->text();
            if (ui->radioButton_10->isChecked())
                Buscar = "*"+ui->radioButton_10->text();
            if (ui->radioButton_15->isChecked())
                Buscar = "*"+ui->radioButton_15->text();
            if (ui->radioButton_24->isChecked())
                Buscar = "*"+ui->radioButton_24->text();
            if (ui->radioButton_33->isChecked())
                Buscar = "*"+ui->radioButton_33->text();
        }
        if (ui->radioButton_16->isChecked())
        {
            if (ui->radioButton_27->isChecked())
                Buscar = "*"+ui->radioButton_27->text();
            if (ui->radioButton_26->isChecked())
                Buscar = "*"+ui->radioButton_26->text();
            if (ui->radioButton_28->isChecked())
                Buscar = "*"+ui->radioButton_28->text();
            if (ui->radioButton_17->isChecked())
                Buscar = "*"+ui->radioButton_17->text();
            if (ui->radioButton_25->isChecked())
                Buscar = "*"+ui->radioButton_25->text();
            if (ui->radioButton_23->isChecked())
                Buscar = "*"+ui->radioButton_23->text();
            if (ui->radioButton_18->isChecked())
                Buscar = "*"+ui->radioButton_18->text();
        }
        if (ui->radioButton_29->isChecked())
        {
            if (ui->radioButton_36->isChecked())
                Buscar = "*"+ui->radioButton_36->text();
            if (ui->radioButton_38->isChecked())
                Buscar = "*"+ui->radioButton_38->text();
            if (ui->radioButton_35->isChecked())
                Buscar = "*"+ui->radioButton_35->text();
            if (ui->radioButton_37->isChecked())
                Buscar = "*"+ui->radioButton_37->text();
            if (ui->radioButton_34->isChecked())
                Buscar = "*"+ui->radioButton_34->text();
            if (ui->radioButton_30->isChecked())
                Buscar = "*"+ui->radioButton_30->text();
            if (ui->radioButton_32->isChecked())
                Buscar = "*"+ui->radioButton_32->text();
            if (ui->radioButton_31->isChecked())
                Buscar = "*"+ui->radioButton_31->text();
        }
        if (ui->radioButton_49->isChecked())
        {
            if (ui->radioButton_44->isChecked())
                Buscar = "*"+ui->radioButton_44->text();
            if (ui->radioButton_47->isChecked())
                Buscar = "*"+ui->radioButton_47->text();
            if (ui->radioButton_40->isChecked())
                Buscar = "*"+ui->radioButton_40->text();
            if (ui->radioButton_46->isChecked())
                Buscar = "*"+ui->radioButton_46->text();
            if (ui->radioButton_43->isChecked())
                Buscar = "*"+ui->radioButton_43->text();
            if (ui->radioButton_42->isChecked())
                Buscar = "*"+ui->radioButton_42->text();
            if (ui->radioButton_45->isChecked())
                Buscar = "*"+ui->radioButton_45->text();
            if (ui->radioButton_41->isChecked())
                Buscar = "*"+ui->radioButton_41->text();
        }
        if (ui->radioButton_39->isChecked())
        {
            if (ui->radioButton_57->isChecked())
                Buscar = "*"+ui->radioButton_57->text();
            if (ui->radioButton_52->isChecked())
                Buscar = "*"+ui->radioButton_52->text();
            if (ui->radioButton_48->isChecked())
                Buscar = "*"+ui->radioButton_48->text();
            if (ui->radioButton_50->isChecked())
                Buscar = "*"+ui->radioButton_50->text();
            if (ui->radioButton_53->isChecked())
                Buscar = "*"+ui->radioButton_53->text();
            if (ui->radioButton_55->isChecked())
                Buscar = "*"+ui->radioButton_55->text();
            if (ui->radioButton_2->isChecked())
            {
                if (ui->lineEdit->text() =="")
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("No has introducido el tipo de extension para este tipo de borrado."));
                    m.exec();
                    return;
                }
                Buscar = "*."+ui->lineEdit->text();
            }
        }
    }
    else if (ui->radioButton_54->isChecked())
    {
        if (ui->lineEdit_6->text() == "" || ui->lineEdit_7->text() == "")
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No has introducido todos los datos para este tipo de borrado."));
            m.exec();
            return;
        }
        Buscar = ""+ui->lineEdit_6->text()+"."+ui->lineEdit_7->text()+"";
    }
    QString cm1;
    if (ui->checkBox->isChecked())
        cm1="find %1/ -iname %2";
    else
        cm1="find %1/ -name %2";
    cm1 = cm1.arg(ui->lineEdit_8->text()).arg(Buscar);
    QStringList comandos;
    comandos << cm1;
    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor= comandos.count();
    mib->Valor(valor,3);
    mib->Mascara(cantidad51,cantidad50,cantidad49,DatoTalla,cantidad47,DatoNegro);
    mib->iniciarProceso();
}

void Borrar::on_pushButton_clicked()
{
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                QString::fromUtf8(tr("<center><b>Borrado de datos masivos<b></center><p>"
                "Vas a proceder al borrado de datos de forma masiva por lo que todos los datos de la "
                "lista ya no se podran recuperar.<p>"
                "<b>IMPORTANTE:</b> Este proceso es muy peligroso asi que procede con mucho cuidado "
                "ya que puedes dejar inservible el sistema ademas de la perdida de datos importantes.<p>"
                "&iquest;Borrar datos de la lista?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::No)
        return;
    else
    {


        //falta es parte que no se como hacerla, si directamente o desde la lista.


    }
}

void Borrar::on_pushButton_4_clicked()
{
    Formato = 0;
    int Borrado, x;
    Borrado = ui->tableWidget_2->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget_2->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    ui->pushButton->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->pushButton_9->setVisible(true);
}
