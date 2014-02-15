#include "omision.h"
#include "ui_omision.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

Omision::Omision(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Omision)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
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
    this->installEventFilter(this);
}

Omision::~Omision()
{
    delete ui;
}

void Omision::on_pushButton_2_clicked()
{
    if (Codigo == ui->textEdit->text())
        close();
    else
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Guardar ultimos cambios")),
                               QString::fromUtf8(tr("Se han realizado modificaciones en los filtros.<p>"
                               "&iquest;Quieres guardar cambios?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
         on_pushButton_clicked();
        }
        else
            close();
    }
}

void Omision::on_pushButton_3_clicked()
{
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Borrar todos los filtros")),
                           QString::fromUtf8(tr("<center><b>Borrado de todos los filtros<b></center><p>"
                           "Se procede al borrado masivo de todos los filtros de la sincronizacion activa.<p>"
                           "Si solo quieres borrar alguno en especial, edita directamente en la ventana de filtros.<p>"
                           "&iquest;Estas seguro de que quieres borrar todos los filtros activos?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        ui->textEdit->clear();
    }
}

void Omision::Valor(QString Posicion)
{
    Nombre = Posicion;
    QSqlQuery query(db);
    query.exec("SELECT Codigo FROM Sincrono WHERE Referencia='"+Nombre+"'");
    query.first();
    Codigo = query.value(0).toString();
    ui->label_3->setText(Nombre);
    ui->textEdit->setText(Codigo);
}

void Omision::on_pushButton_clicked()
{    
    QString Code;
    Code = ui->textEdit->toPlainText();
    QStringList Valor = Code.split("");
    int Resto = Valor.count();
    QString Resultado = Valor.value(Resto-2);
    if (Resultado == ";")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se puede acabar el filtro con el signo de ;"));
        m.exec();
        return;
    }
    if (Code.contains(";;"))
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Has editado mal la introduccion de filtros, comprueba el error"));
        m.exec();
        return;
    }
    QSqlQuery query(db);
    query.exec("UPDATE Sincrono SET Codigo='"+Code+"' WHERE Referencia='"+Nombre+"'");
    close();
}

bool Omision::eventFilter(QObject* obj, QEvent *event)
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
                ayuda->Valor(tr("Sincrono::Omitir palabras sincronizadas"));
                return true;
            }
        }
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Escape)
            {
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void Omision::on_pushButton_4_clicked()
{
    ui->textEdit->setFocus();
    ui->textEdit->selectedText();
}
