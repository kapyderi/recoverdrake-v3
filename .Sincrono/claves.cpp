#include "claves.h"
#include "ui_claves.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QInputDialog>
#include <QShortcut>
#include <QDesktopWidget>
#include <QDebug>

claves::claves(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::claves)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Administrador = 0;
    Model= new QSqlTableModel(0,db);
    Model->setTable("Acceso");
    Model->select();
    ui->tableView->setModel(Model);
    ui->tableView->setColumnHidden(0, true);
    if (Administrador == 0)
        ui->tableView->setRowHidden(2, true);
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila(QModelIndex)));
    this->setWindowFlags(Qt::Window|Qt::CustomizeWindowHint|Qt::WindowTitleHint);
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
    ui->pushButton_7->hide();
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+K+P"), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(Mostrar()));
    QDesktopWidget screen;
    QRect screenGeom = screen.screenGeometry(this);
    int screenCenterX = screenGeom.center().x();
    int screenCenterY = screenGeom.center().y();
    move(screenCenterX - width () / 2, screenCenterY - height() / 2);
}

claves::~claves()
{
    delete ui;
    delete Model;
}

void claves::cambiaFila(QModelIndex actual)
{
        int i;
        bool valor;
        i=actual.row();
        QModelIndex index;
        index=ui->tableView->model()->index(i,0);
        this->id= index.data().toInt();
        ui->lineEdit_3->setText(tr(index.data().toString()));
        index=ui->tableView->model()->index(i,1);
        ui->lineEdit->setText(tr(index.data().toString()));
        index=ui->tableView->model()->index(i,2);
        ui->lineEdit_2->setText(tr(index.data().toString()));
        index=ui->tableView->model()->index(i,3);
        if (index.data() == 1)
        {
            ui->radioButton->setChecked(true);
            ui->radioButton_2->setChecked(false);
            ui->radioButton_3->setChecked(false);
        }
        else if (index.data() == 2)
        {
            ui->radioButton->setChecked(false);
            ui->radioButton_2->setChecked(true);
            ui->radioButton_3->setChecked(false);
        }
        else if (index.data() == 3)
        {
            ui->radioButton->setChecked(false);
            ui->radioButton_2->setChecked(false);
            ui->radioButton_3->setChecked(true);
        }
        index=ui->tableView->model()->index(i,4);
        valor=(index.data().toInt());
        if ( valor == 0 )
           {
            ui->checkBox->setChecked(false);
           }
        else
           {
            ui->checkBox->setChecked(true);
           }
        index=ui->tableView->model()->index(i,5);
        ui->lineEdit_4->setText(tr(index.data().toString()));
        index=ui->tableView->model()->index(i,6);
        ui->lineEdit_5->setText(tr(index.data().toString()));
        this->fila=i;
}

void claves::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void claves::on_pushButton_clicked()
{    
    QString Nivel,User;
    if (ui->radioButton->isChecked())
    {
        Nivel="1";
    }
    else if (ui->radioButton_2->isChecked())
    {
        Nivel="2";
    }
    else if (ui->radioButton_3->isChecked())
    {
        Nivel="3";
    }
    User=ui->lineEdit->text();
    QSqlQuery query1(db);
    query1.exec("SELECT Usuario FROM Acceso WHERE Usuario='"+User+"'");
    query1.first();
    if (query1.isSelect())
        Cantidad=query1.value(0).toString();
    if (User == Cantidad)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se pueden duplicar Usuarios. Cambia los datos de Usuario para poder insertar uno."));
        m.exec();
        return;
    }
        if( Nivel<"1" || Nivel>"3" )
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("El Nivel utilizado es diferente del permitido, revisalo antes de continuar."));
            m.exec();
            return;
        }
        else
        {
            if (ui->checkBox->isChecked()==false)
            {
                    QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("No se puede insertar un registro deshabilitado de inicio.<p>Activalo para poder agregarlo."));
                    m.exec();
                    return;
            }
            else
            {
                if (ui->lineEdit_4->text()=="")
                {
                        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                        m.setText(tr("No se puede insertar un registro al que no se le ha definido una pregunta/respuesta.<p>Es para poder recuperar el usuario en caso de no recordar la contrasena."));
                        m.exec();
                        return;
                }
                    QSqlQuery query(db);
                    query.prepare("INSERT INTO Acceso (Usuario,Clave,Nivel,Activo,Pregunta,Respuesta)"
                                  "VALUES (:User, :Clave, :Level, :Ok, :Pregunta, :Respuesta)");
                    query.bindValue(":Pregunta", "¿ "+ui->lineEdit_4->text()+" ?");
                    query.bindValue(":Respueta", ui->lineEdit_5->text());
                    query.bindValue(":User", ui->lineEdit->text());
                    query.bindValue(":Clave", ui->lineEdit_2->text());
                    query.bindValue(":Level", Nivel);
                    query.bindValue(":Ok", ui->checkBox->checkState());
                    query.exec();
                    Model->select();
                    ui->tableView->setModel(Model);
                    ui->tableView->setColumnHidden(0, true);
                    if (Administrador == 0)
                        ui->tableView->setRowHidden(2, true);
            }
        }
}

void claves::on_pushButton_2_clicked()
{
    QString Nivel, User;
    if (ui->radioButton->isChecked())
    {
        Nivel="1";
    }
    else if (ui->radioButton_2->isChecked())
    {
        Nivel="2";
    }
    else if (ui->radioButton_3->isChecked())
    {
        Nivel="3";
    }
    User= ui->lineEdit->text();
    if( Nivel<"1" || Nivel>"3" )
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El Nivel utilizado es diferente del permitido, revisalo antes de continuar."));
        m.exec();
        return;
    }
    else
    {
        if (User == "kapyderi")
        {
            bool ok;
            QString Clave;
            Clave = QInputDialog::getText(this, QString::fromUtf8(tr("Clave de Administrador")),
            QString::fromUtf8(tr("Introduce la clave de administrador para poder actualizar.<P> ")),
            QLineEdit::Password,
            "",&ok);
            if (ok && !Clave.isEmpty())
            {
                if (Clave != "4Rimas")
                {
                    QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("La clave introducida no concuerda con la del Administrador. Saliendo..."));
                    m.exec();
                    return;
                }
            }
            if (Clave.isEmpty())
                return;
        }
        QSqlQuery query1(db);
        query1.exec("SELECT Usuario FROM Acceso WHERE Usuario='"+User+"'");
        query1.first();
        QSqlRecord record= Model->record(this->fila);
        record.setValue(1,""+User+"");
        record.setValue(2,ui->lineEdit_2->text());
        record.setValue(3,Nivel);
        record.setValue(4,ui->checkBox->checkState());
        record.setValue(5,ui->lineEdit_4->text());
        record.setValue(6,ui->lineEdit_5->text());
        Model->setRecord(this->fila,record);
        Model->submitAll();        
        ui->tableView->setColumnHidden(0, true);
        if (Administrador == 0)
            ui->tableView->setRowHidden(2, true);
    }
}

void claves::on_pushButton_3_clicked()
{
    QString usuario;
    QString Nivel;
    if (ui->radioButton->isChecked())
    {
        Nivel="1";
    }
    else if (ui->radioButton_2->isChecked())
    {
        Nivel="2";
    }
    else if (ui->radioButton_3->isChecked())
    {
        Nivel="3";
    }
    usuario= ui->lineEdit->text();
    if(usuario=="admin" || usuario=="kapyderi" || usuario=="invitado")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El usuario "+usuario+" no se puede borrar para no perder la integridad de los datos, ya que es de los establecidos por defecto."));
        m.exec();
        return;
    }
    QSqlQuery query2(db);
    query2.exec("SELECT COUNT(Nivel) AS Cantidad FROM Acceso WHERE Nivel=3 AND Activo=2");
    query2.first();
    if (query2.isSelect())
        Cantidad=query2.value(0).toString();
    QSqlQuery query1(db);
    query1.exec("SELECT COUNT(Nivel) AS Cantidad FROM Acceso WHERE Nivel=3 AND Activo=2 AND Usuario='"+usuario+"'");
    query1.first();
    if (query1.isSelect())
        Cantidad1=query1.value(0).toString();
    if (Cantidad != Cantidad1)
    {
        ui->tableView->model()->removeRow(fila);
        ui->tableView->setColumnHidden(0, true);
        if (Administrador == 0)
             ui->tableView->setRowHidden(2, true);
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ningun usuario con Nivel 3 activo, por favor introduzca o actualice uno como minimo."));
        m.exec();
        return;
    }
}

void claves::on_pushButton_5_clicked()
{
    Model->setFilter("Usuario like'"+ui->lineEdit->text()+"%'");
    ui->tableView->setModel(Model);
    ui->tableView->setColumnHidden(0, true);
    if (Administrador == 0)
        ui->tableView->setRowHidden(2, true);
}

void claves::on_pushButton_4_clicked()
{
    QString Nivel;
    if (ui->radioButton->isChecked())
    {
        Nivel="1";
    }
    else if (ui->radioButton_2->isChecked())
    {
        Nivel="2";
    }
    else if (ui->radioButton_3->isChecked())
    {
        Nivel="3";
    }
    QSqlQuery query2(db);
    query2.exec("SELECT COUNT(Nivel) AS Cantidad FROM Acceso WHERE Nivel=3 AND Activo=2");
    query2.first();
    if (query2.isSelect())
        Cantidad=query2.value(0).toString();
    if (Cantidad >= "2" || Administrador == 1)
    {
        Administrador = 0;
        close();
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ningun usuario con Nivel 3 activo, por favor introduzca o actualice uno como minimo."));
        m.exec();
        return;
    }
}

void claves::on_pushButton_6_clicked()
{
    this->ui->lineEdit_4->setText(tr(""));
    this->ui->lineEdit_5->setText(tr(""));
    this->ui->lineEdit->setText(tr(""));
    this->ui->lineEdit_2->setText(tr(""));
    this->ui->radioButton_3->setChecked(true);
    this->ui->checkBox->setChecked(false);
    return;
}

void claves::on_pushButton_7_clicked()
{
    bool ok;
    QString Clave;
    Clave = QInputDialog::getText(this, QString::fromUtf8(tr("Clave de Administrador")),
    QString::fromUtf8(tr("Introduce la clave de administrador.<P> ")),
    QLineEdit::Password,
    "",&ok);
    if (ok && !Clave.isEmpty())
    {
       if (Clave != "4Rimas")
       {
          QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
          m.setText(tr("La clave introducida no concuerda con la del Administrador."));
          m.exec();
          return;
       }
       else
       {
           Administrador=1;
           ui->tableView->setModel(Model);
           ui->tableView->setRowHidden(2, false);
           ui->tableView->setColumnHidden(0, true);
       }
    }
}

void claves::Mostrar()
{
    if (ui->pushButton_7->isHidden())
    {
        ui->pushButton_7->show();
    }
    else
    {
        ui->pushButton_7->hide();
    }
}
