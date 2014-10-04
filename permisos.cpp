#include "permisos.h"
#include "ui_permisos.h"
#include <QSqlQuery>
#include "drakesistema.h"
#include <QFileDialog>
#include <QDateTime>
#include <QMessageBox>
#include <QDateTimeEdit>
#include <QDebug>
#include <QCloseEvent>
#include <QKeyEvent>

Permisos::Permisos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Permisos)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Stilo = "B";
    drakeSistema drake;
    user = drake.getUser();
    QString usuarios = drake.getUsuarios();
    QStringList Usuar = usuarios.split("\n");
    for (int a=0;a<Usuar.count();a++)
    {
        ui->comboBox->addItem(Usuar.value(a));
        ui->comboBox_2->addItem(Usuar.value(a));
        ui->comboBox_3->addItem(Usuar.value(a));
        ui->comboBox_4->addItem(Usuar.value(a));
    }
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(user));
    ui->comboBox->setCurrentIndex(ui->comboBox->findText("root"));
    ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(user));
    ui->comboBox_4->setCurrentIndex(ui->comboBox_4->findText("root"));
    ui->comboBox->model()->sort(0,Qt::AscendingOrder);
    ui->comboBox_2->model()->sort(0,Qt::AscendingOrder);
    ui->comboBox_3->model()->sort(0,Qt::AscendingOrder);
    ui->comboBox_4->model()->sort(0,Qt::AscendingOrder);
    ui->comboBox_3->setEnabled(false);
    ui->comboBox_2->setEnabled(false);
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
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_9,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_7,SIGNAL(clicked()),this,SLOT(Verificar()));
    connect(ui->radioButton_8,SIGNAL(clicked()),this,SLOT(Verificar()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Permisive()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Permisive()));
    connect(ui->radioButton_5,SIGNAL(clicked()),this,SLOT(Permisive()));
    connect(ui->radioButton_6,SIGNAL(clicked()),this,SLOT(Permisive()));
    ui->radioButton_7->setChecked(true);
    ui->radioButton_3->setChecked(true);
    ui->radioButton->setChecked(true);
    this->Comprobar();
    this->Verificar();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    mib = 0;
    this->installEventFilter(this);
}

Permisos::~Permisos()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void Permisos::Valor(QString valor)
{
    if (valor == "Quitar")
        CierreTotal = 1;
    if (this->isMaximized())
    {
        ui->label_10->show();
        ui->verticalSpacer->changeSize(0,0);
    }
    else
    {
        ui->label_10->hide();
        ui->verticalSpacer->changeSize(20,40,QSizePolicy::Expanding,QSizePolicy::Expanding);
    }
}

void Permisos::on_pushButton_3_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void Permisos::closeEvent ( QCloseEvent * event )
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

bool Permisos::eventFilter(QObject* obj, QEvent *event)
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
                ayuda->Valor(tr("Permisos"));
                return true;
            }
        }      
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void Permisos::on_pushButton_2_clicked()
{
    QString fileName;
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    if (ui->radioButton_7->isChecked())
        fileName = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Elegir Archivo")),path);
    else if (ui->radioButton_8->isChecked())
        fileName = QFileDialog::getExistingDirectory(this,tr("Elegir Directorio"),path,QFileDialog::ShowDirsOnly);
    if (fileName.isEmpty())
       return;
    ui->lineEdit->setText(fileName);
}

void Permisos::Comprobar()
{
    if (ui->radioButton->isChecked())
    {
        ui->groupBox_4->setEnabled(true);
        ui->groupBox_2->setEnabled(false);
        ui->groupBox_7->setEnabled(false);
        if (ui->radioButton_8->isChecked())
        {
            ui->groupBox_3->setEnabled(true);
        }
    }
    if (ui->radioButton_2->isChecked())
    {
        ui->groupBox_4->setEnabled(false);
        ui->groupBox_2->setEnabled(true);
        ui->groupBox_7->setEnabled(false);
        if (ui->radioButton_8->isChecked())
        {
            ui->groupBox_3->setEnabled(true);
        }
        this->Permisive();
    }
    if (ui->radioButton_9->isChecked())
    {
        ui->groupBox_4->setEnabled(false);
        ui->groupBox_2->setEnabled(false);
        ui->groupBox_7->setEnabled(true);
        if (ui->radioButton_8->isChecked() && ui->radioButton_9->isChecked())
        {
            ui->groupBox_3->setEnabled(false);
        }
    }
}

void Permisos::Verificar()
{
    if (ui->radioButton_7->isChecked())
    {
        ui->groupBox_3->setEnabled(false);
        ui->lineEdit->setText("");
        ui->checkBox_5->setChecked(false);
        ui->checkBox_6->setChecked(false);
        ui->checkBox_7->setChecked(false);
        ui->checkBox_8->setChecked(false);
        ui->checkBox_9->setChecked(false);
        ui->checkBox_10->setChecked(false);
        ui->checkBox_11->setChecked(false);
        ui->checkBox_12->setChecked(false);
        ui->checkBox_13->setChecked(false);
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
    }
    if (ui->radioButton_8->isChecked())
    {        
        ui->groupBox_3->setEnabled(true);
        ui->lineEdit->setText("");
        ui->checkBox_5->setChecked(false);
        ui->checkBox_6->setChecked(false);
        ui->checkBox_7->setChecked(false);
        ui->checkBox_8->setChecked(false);
        ui->checkBox_9->setChecked(false);
        ui->checkBox_10->setChecked(false);
        ui->checkBox_11->setChecked(false);
        ui->checkBox_12->setChecked(false);
        ui->checkBox_13->setChecked(false);
        ui->checkBox->setChecked(false);
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
    }
}

void Permisos::on_lineEdit_textChanged(QString )
{
    this->Revisar();
}

void Permisos::Revisar()
{
    QString Ruta;
    drakeSistema drake;
    if (ui->radioButton_7->isChecked())
        Ruta = drake.getLslh(ui->lineEdit->text());
    else if (ui->radioButton_8->isChecked())
        Ruta = drake.getLslhd(ui->lineEdit->text());
    QStringList Valores = Ruta.split(" ");
    QString Permisos = Valores.value(0);
    QStringList Permitir = Permisos.split("");
    if (Permitir.value(2) == "r")
    {
        ui->checkBox_5->setChecked(true);
        LecturaU = "Si";
    }
    else if (Permitir.value(2) == "-")
    {
        ui->checkBox_5->setChecked(false);
        LecturaU = "No";
    }
    if (Permitir.value(3) == "w")
    {
        ui->checkBox_6->setChecked(true);
        EscrituraU = "Si";
    }
    else if (Permitir.value(3) == "-")
    {
        ui->checkBox_6->setChecked(false);
        EscrituraU = "No";
    }
    if (Permitir.value(4) == "x")
    {
        ui->checkBox_7->setChecked(true);
        EjecucionU = "Si";
    }
    else if (Permitir.value(4) == "-")
    {
        ui->checkBox_7->setChecked(false);
        EjecucionU = "No";
    }
    if (Permitir.value(5) == "r")
    {
        ui->checkBox_8->setChecked(true);
        LecturaG = "Si";
    }
    else if (Permitir.value(5) == "-")
    {
        ui->checkBox_8->setChecked(false);
        LecturaG = "No";
    }
    if (Permitir.value(6) == "w")
    {
        ui->checkBox_9->setChecked(true);
        EscrituraG = "Si";
    }
    else if (Permitir.value(6) == "-")
    {
        ui->checkBox_9->setChecked(false);
        EscrituraG = "No";
    }
    if (Permitir.value(7) == "x")
    {
        ui->checkBox_10->setChecked(true);
        EjecucionG = "Si";
    }
    else if (Permitir.value(7) == "-")
    {
        ui->checkBox_10->setChecked(false);
        EjecucionG = "No";
    }
    if (Permitir.value(8) == "r")
    {
        ui->checkBox_11->setChecked(true);
        LecturaO = "Si";
    }
    else if (Permitir.value(8) == "-")
    {
        ui->checkBox_11->setChecked(false);
        LecturaO = "No";
    }
    if (Permitir.value(9) == "w")
    {
        ui->checkBox_12->setChecked(true);
        EscrituraO = "Si";
    }
    else if (Permitir.value(9) == "-")
    {
        ui->checkBox_12->setChecked(false);
        EscrituraO = "No";
    }
    if (Permitir.value(10) == "x")
    {
        ui->checkBox_13->setChecked(true);
        EjecucionO = "Si";
    }
    else if (Permitir.value(10) == "-")
    {
        ui->checkBox_13->setChecked(false);
        EjecucionO = "No";
    }
    ui->lineEdit_2->setText(Valores.value(2));
    ui->lineEdit_3->setText(Valores.value(3));
    ui->lineEdit_4->setText(Valores.value(1));
    if (Valores.value(7).contains("/"))
        ui->lineEdit_5->setText(""+Valores.value(5)+" "+Valores.value(6)+"");
    else
        ui->lineEdit_5->setText(""+Valores.value(5)+" "+Valores.value(6)+" "+Valores.value(7)+"");
    ui->lineEdit_6->setText(Valores.value(4));
    if (ui->lineEdit_2->text() == user)
    {
        ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(user));
        ui->comboBox->setCurrentIndex(ui->comboBox->findText("root"));
    }
    else if (ui->lineEdit_2->text() == "root")
    {
        ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText("root"));
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(user));
    }
    else
    {
        ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(ui->lineEdit_2->text()));
        ui->comboBox->setCurrentIndex(ui->comboBox->findText(user));
    }
    if (ui->lineEdit_3->text() == user)
    {
        ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(user));
        ui->comboBox_4->setCurrentIndex(ui->comboBox_4->findText("root"));
    }
    else if (ui->lineEdit_3->text() == "root")
    {
        ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText("root"));
        ui->comboBox_4->setCurrentIndex(ui->comboBox_4->findText(user));
    }
    else
    {
        ui->comboBox_3->setCurrentIndex(ui->comboBox_3->findText(ui->lineEdit_3->text()));
        ui->comboBox_4->setCurrentIndex(ui->comboBox_4->findText(user));
    }
    this->Permisive();
}

void Permisos::on_pushButton_clicked()
{
    QString Objetivo = ui->lineEdit->text();
    if (Objetivo == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay datos para realizar el cambio."));
        m.exec();
        return;
    }
    if (ui->radioButton->isChecked())
    {
        QString UsuarioF = ui->comboBox->currentText();
        QString UsuarioI = ui->lineEdit_2->text();
        QString GrupoF = ui->comboBox_4->currentText();
        QString GrupoI = ui->lineEdit_3->text();        
        if (UsuarioF == UsuarioI && GrupoF == GrupoI)
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("El usuario y grupo elegido es igual al que tiene ahora mismo."));
            m.exec();
            return;
        }
        if (ui->radioButton_8->isChecked())
        {
            if (ui->checkBox_4->isChecked())
                system("chown '"+UsuarioF+"':'"+GrupoF+"' '"+Objetivo+"' -R");
            else
                system("chown '"+UsuarioF+"':'"+GrupoF+"' '"+Objetivo+"'");
        }
        else
            system("chown '"+UsuarioF+"':'"+GrupoF+"' '"+Objetivo+"'");
        this->Revisar();
    }
    else if (ui->radioButton_2->isChecked())
    {
        QString Lectura, Escritura, Ejecucion;
        if (ui->checkBox->isChecked())
            Lectura = "+r";
        else
            Lectura = "-r";
        if (ui->checkBox_2->isChecked())
            Escritura = "+w";
        else
            Escritura = "-w";
        if (ui->checkBox_3->isChecked())
            Ejecucion = "+x";
        else
            Ejecucion = "-x";
        if (ui->radioButton_3->isChecked())
        {
            if (ui->radioButton_8->isChecked())
            {
                if (ui->checkBox_4->isChecked())
                {
                    system("chmod -R u'"+Lectura+"' '"+Objetivo+"'");
                    system("chmod -R u'"+Escritura+"' '"+Objetivo+"'");
                    system("chmod -R u'"+Ejecucion+"' '"+Objetivo+"'");
                }
                else
                {
                    system("chmod u'"+Lectura+"' '"+Objetivo+"'");
                    system("chmod u'"+Escritura+"' '"+Objetivo+"'");
                    system("chmod u'"+Ejecucion+"' '"+Objetivo+"'");
                }
            }
            else
            {
                system("chmod u'"+Lectura+"' '"+Objetivo+"'");
                system("chmod u'"+Escritura+"' '"+Objetivo+"'");
                system("chmod u'"+Ejecucion+"' '"+Objetivo+"'");
            }
        }
        if (ui->radioButton_4->isChecked())
        {
            if (ui->radioButton_8->isChecked())
            {
                if (ui->checkBox_4->isChecked())
                {
                    system("chmod -R g'"+Lectura+"' '"+Objetivo+"'");
                    system("chmod -R g'"+Escritura+"' '"+Objetivo+"'");
                    system("chmod -R g'"+Ejecucion+"' '"+Objetivo+"'");
                }
                else
                {
                    system("chmod g'"+Lectura+"' '"+Objetivo+"'");
                    system("chmod g'"+Escritura+"' '"+Objetivo+"'");
                    system("chmod g'"+Ejecucion+"' '"+Objetivo+"'");
                }
            }
            else
            {
                system("chmod g'"+Lectura+"' '"+Objetivo+"'");
                system("chmod g'"+Escritura+"' '"+Objetivo+"'");
                system("chmod g'"+Ejecucion+"' '"+Objetivo+"'");
            }
        }
        if (ui->radioButton_5->isChecked())
        {
            if (ui->radioButton_8->isChecked())
            {
                if (ui->checkBox_4->isChecked())
                {
                    system("chmod -R o'"+Lectura+"' '"+Objetivo+"'");
                    system("chmod -R o'"+Escritura+"' '"+Objetivo+"'");
                    system("chmod -R o'"+Ejecucion+"' '"+Objetivo+"'");
                }
                else
                {
                    system("chmod o'"+Lectura+"' '"+Objetivo+"'");
                    system("chmod o'"+Escritura+"' '"+Objetivo+"'");
                    system("chmod o'"+Ejecucion+"' '"+Objetivo+"'");
                }
            }
            else
            {
                system("chmod o'"+Lectura+"' '"+Objetivo+"'");
                system("chmod o'"+Escritura+"' '"+Objetivo+"'");
                system("chmod o'"+Ejecucion+"' '"+Objetivo+"'");
            }
        }
        if (ui->radioButton_6->isChecked())
        {
            if (ui->radioButton_8->isChecked())
            {
                if (ui->checkBox_4->isChecked())
                {
                    system("chmod -R a'"+Lectura+"' '"+Objetivo+"'");
                    system("chmod -R a'"+Escritura+"' '"+Objetivo+"'");
                    system("chmod -R a'"+Ejecucion+"' '"+Objetivo+"'");
                }
                else
                {
                    system("chmod a'"+Lectura+"' '"+Objetivo+"'");
                    system("chmod a'"+Escritura+"' '"+Objetivo+"'");
                    system("chmod a'"+Ejecucion+"' '"+Objetivo+"'");
                }
            }
            else
            {
                system("chmod a'"+Lectura+"' '"+Objetivo+"'");
                system("chmod a'"+Escritura+"' '"+Objetivo+"'");
                system("chmod a'"+Ejecucion+"' '"+Objetivo+"'");
            }
        }
        this->Revisar();
    }
    else if (ui->radioButton_9->isChecked())
    {        
        QDateTimeEdit *date = new QDateTimeEdit;
        date->setDateTime(ui->dateTimeEdit->dateTime());
        date->setDisplayFormat("yyyyMMddHHmm");
        QString Fecha = date->text();
        QString Usuario = ui->lineEdit_2->text();
        system("su - "+Usuario+" -c \"touch -t '"+Fecha+"' '"+Objetivo+"'\"");
        this->Revisar();
    }
}

void Permisos::Permisive()
{
    if (ui->radioButton_3->isChecked())
    {
        if (LecturaU == "Si")
            ui->checkBox->setChecked(true);
        else if (LecturaU == "No")
            ui->checkBox->setChecked(false);
        if (EscrituraU == "Si")
            ui->checkBox_2->setChecked(true);
        else if (EscrituraU == "No")
            ui->checkBox_2->setChecked(false);
        if (EjecucionU == "Si")
            ui->checkBox_3->setChecked(true);
        else if (EjecucionU == "No")
            ui->checkBox_3->setChecked(false);
    }
    if (ui->radioButton_4->isChecked())
    {
        if (LecturaG == "Si")
            ui->checkBox->setChecked(true);
        else if (LecturaG == "No")
            ui->checkBox->setChecked(false);
        if (EscrituraG == "Si")
            ui->checkBox_2->setChecked(true);
        else if (EscrituraG == "No")
            ui->checkBox_2->setChecked(false);
        if (EjecucionG == "Si")
            ui->checkBox_3->setChecked(true);
        else if (EjecucionG == "No")
            ui->checkBox_3->setChecked(false);
    }
    if (ui->radioButton_5->isChecked())
    {
        if (LecturaO == "Si")
            ui->checkBox->setChecked(true);
        else if (LecturaO == "No")
            ui->checkBox->setChecked(false);
        if (EscrituraO == "Si")
            ui->checkBox_2->setChecked(true);
        else if (EscrituraO == "No")
            ui->checkBox_2->setChecked(false);
        if (EjecucionO == "Si")
            ui->checkBox_3->setChecked(true);
        else if (EjecucionO == "No")
            ui->checkBox_3->setChecked(false);
    }
    if (ui->radioButton_6->isChecked())
    {
        if (LecturaU == "Si")
            ui->checkBox->setChecked(true);
        else if (LecturaU == "No")
            ui->checkBox->setChecked(false);
        if (EscrituraU == "Si")
            ui->checkBox_2->setChecked(true);
        else if (EscrituraU == "No")
            ui->checkBox_2->setChecked(false);
        if (EjecucionU == "Si")
            ui->checkBox_3->setChecked(true);
        else if (EjecucionU == "No")
            ui->checkBox_3->setChecked(false);
    }
}
