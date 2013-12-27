#include "comparador.h"
#include "ui_comparador.h"
#include <QMessageBox>
#include "drakesistema.h"
#include <QSqlQuery>
#include <QFileDialog>
#include <QTest>
#include <QProgressDialog>
#include <QDebug>

Comparador::Comparador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Comparador)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    drakeSistema drake;
    user = drake.getUser();
    Stilo = "B";
    QSqlQuery queryDefecto(db);
    queryDefecto.exec("SELECT Defecto FROM Miscelanea WHERE id=2");
    queryDefecto.first();
    if (queryDefecto.isValid())
        cantidadDefecto=queryDefecto.value(0).toString();
    if (cantidadDefecto == "0")
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
        Stilo = "A";
    }
    CierreTotal = 0;
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar()));
    ui->radioButton->setChecked(true);
    this->installEventFilter(this);
    ui->pushButton_15->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->groupBox->setVisible(false);
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_5,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    ui->radioButton_3->setChecked(true);
    Tipo = 0;
}

Comparador::~Comparador()
{
    delete ui;    
}

void Comparador::Valor(QString valor, QString Logs)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
    if (Logs == "S")
        Log = "S";
    else
        Log = "N";
}

void Comparador::closeEvent ( QCloseEvent * event )
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

bool Comparador::eventFilter(QObject* obj, QEvent *event)
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
                ayuda->Valor("Comparador");
                return true;
            }
        }
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
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void Comparador::on_pushButton_clicked()
{
    if (CierreTotal == 1)
    {
        if (Log == "S")
        {
            system(QString::fromUtf8("echo '"+ui->textEdit_3->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
        }
        emit Cerrar();
    }
    else
    {
        if (Log == "S")
        {
            system(QString::fromUtf8("echo '"+ui->textEdit_3->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
        }
        close();
    }
}

void Comparador::Comprobar()
{
    if (ui->radioButton->isChecked())
    {
        ui->pushButton_2->setText(tr("Directorio objetivo"));
        ui->pushButton_3->setText(tr("Directorio destino"));
        ui->groupBox_2->setEnabled(true);
        ui->tableWidget_2->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(false);
        ui->checkBox->setEnabled(true);
        ui->label->setVisible(true);
        ui->textEdit_3->setVisible(true);
        ui->groupBox->setVisible(false);
        ui->groupBox_4->setVisible(true);
        ui->label_6->setText("");
        ui->label_3->setText("");
        ui->label_4->setText("");
        ui->pushButton_14->setText(tr("Todas las diferencias"));
        ui->pushButton_12->setText(tr("Mostrar lineas diferentes"));
        ui->pushButton_10->setText(tr("Mostrar destino vacio"));
        ui->pushButton_11->setText(tr("Mostrar origen vacio"));
        ui->tableWidget_2->setVisible(true);
        ui->pushButton_14->setEnabled(false);
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_10->setEnabled(false);
        ui->pushButton_11->setEnabled(false);
        ui->treeWidget->clear();
        int Borrado, x;
        Borrado = ui->tableWidget->rowCount();
        for(x=0;x<Borrado;x++)
        {
             ui->tableWidget->removeRow(x);
             x=x-1;
             Borrado=Borrado-1;
        }
    }
    if (ui->radioButton_2->isChecked())
    {
        ui->pushButton_2->setText(tr("Archivo objetivo"));
        ui->pushButton_3->setText(tr("Archivo destino"));
        ui->groupBox_2->setEnabled(false);
        ui->tableWidget_2->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(true);
        ui->checkBox->setEnabled(false);
        ui->label->setVisible(false);
        ui->textEdit_3->setVisible(false);
        ui->tableWidget_2->setVisible(false);
        ui->groupBox->setVisible(true);
        ui->groupBox_4->setVisible(false);
        ui->pushButton_14->setText(tr("Todas las diferencias"));
        ui->pushButton_12->setText(tr("Mostrar lineas diferentes"));
        ui->pushButton_10->setText(tr("Mostrar destino vacio"));
        ui->pushButton_11->setText(tr("Mostrar origen vacio"));
        ui->pushButton_14->setEnabled(false);
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_10->setEnabled(false);
        ui->pushButton_11->setEnabled(false);
    }
}

void Comparador::Comprobar1()
{
    if (ui->radioButton_3->isChecked())
    {
        Tipo = 0;        
    }
    if (ui->radioButton_4->isChecked())
    {
        Tipo = 1;
    }
    if (ui->radioButton_5->isChecked())
    {
        Tipo = 2;
    }
    if (ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "")
    {
        return;
    }
    else
    {
        this->on_pushButton_6_clicked();
    }
}

void Comparador::on_pushButton_2_clicked()
{
    if (ui->pushButton_2->text() == tr("Directorio objetivo"))
    {
        QString path;
        if (ui->lineEdit->text() == "")
        {
            path=tr("/home/%1/Documentos/");
            path=path.arg(user);
        }
        else
        {
            path=ui->lineEdit->text();
        }
        QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio fuente?"),path,QFileDialog::ShowDirsOnly);
        if (fileNameDirectori.isEmpty())
           return;
        ui->lineEdit->setText(fileNameDirectori);
    }
    else
    {
        QString path=tr("/home/%1/Documentos/");
        path=path.arg(user);
        if (ui->lineEdit->text() == "")
        {
            path=tr("/home/%1/Documentos/");
            path=path.arg(user);
        }
        else
        {
            path=ui->lineEdit->text();
        }
        QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Todos los archivos")),
                            path);
        if (fileNameOrigen.isEmpty())
            return;
        ui->lineEdit->setText(fileNameOrigen);
    }
}

void Comparador::on_pushButton_3_clicked()
{
    if (ui->pushButton_3->text() == tr("Directorio destino"))
    {
        QString path;
        if (ui->lineEdit_2->text() == "")
        {
            path=tr("/home/%1/Documentos/");
            path=path.arg(user);
        }
        else
        {
            path=ui->lineEdit_2->text();
        }
        QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio destino?"),path,QFileDialog::ShowDirsOnly);
        if (fileNameDirectori.isEmpty())
           return;
        ui->lineEdit_2->setText(fileNameDirectori);
    }
    else
    {
        QString path=tr("/home/%1/Documentos/");
        path=path.arg(user);
        if (ui->lineEdit_2->text() == "")
        {
            path=tr("/home/%1/Documentos/");
            path=path.arg(user);
        }
        else
        {
            path=ui->lineEdit_2->text();
        }
        QString fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Todos los archivos")),
                            path);
        if (fileNameOrigen.isEmpty())
            return;
        ui->lineEdit_2->setText(fileNameOrigen);
    }
}

void Comparador::on_pushButton_5_clicked()
{
    ui->textEdit_3->setText("");
    ui->tableWidget_2->setSortingEnabled(false);
    ui->pushButton_7->setText(tr("Todos"));
    ui->pushButton_8->setText(tr("Iguales"));
    ui->pushButton_9->setText(tr("Diferentes"));
    ui->pushButton_4->setText(tr("Nuevos"));
    ui->pushButton_13->setText(tr("Eliminados"));
    if (ui->lineEdit->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has definido una ruta fuente para poder marcar objetivos."));
        m.exec();
        return;
    }
    if (ui->lineEdit_2->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has definido una ruta destino para poder comparar objetivos."));
        m.exec();
        return;
    }
    Evento = 0;
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_15->setEnabled(true);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    int Borrado, x;
    Borrado = ui->tableWidget_2->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget_2->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    int iFilas;
    drakeSistema drake;
    QString Objetivo = drake.getDu(ui->lineEdit->text());
    if (Objetivo == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has introducido la ruta correcta del objetivo o no es accesible. Comprueba que tienes acceso."));
        m.exec();
        ui->progressBar->setRange(0,100);
        ui->progressBar->setValue(0);
        ui->progressBar->setFormat("%p%");
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_13->setEnabled(false);
        ui->pushButton_15->setEnabled(false);
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
        return;

    }
    QString Destino = drake.getDu(ui->lineEdit_2->text());
    QStringList listaArchivos = Objetivo.split("\n");
    QStringList listaDestino = Destino.split("\n");
    ui->progressBar->setRange(0,listaArchivos.count());
    ui->progressBar->setTextVisible(true);
    ui->progressBar->setFormat(tr("Analizando objetivos... %p%"));
    ui->textEdit_3->append(tr("Iniciando analisis de objetivos"));
    QTest::qWait(20);
    for(int i=1;i<listaArchivos.count();i++)
    {
        qApp->processEvents();
        if (Evento == 1)
        {
            ui->progressBar->setRange(0,100);
            ui->progressBar->setValue(0);
            ui->progressBar->setFormat("%p%");
            ui->pushButton_4->setEnabled(false);
            ui->pushButton_5->setEnabled(true);
            ui->pushButton_7->setEnabled(false);
            ui->pushButton_8->setEnabled(false);
            ui->pushButton_9->setEnabled(false);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->lineEdit->setEnabled(true);
            ui->lineEdit_2->setEnabled(true);
            int Borrado, x;
            Borrado = ui->tableWidget_2->rowCount();
            for(x=0;x<Borrado;x++)
            {
                 ui->tableWidget_2->removeRow(x);
                 x=x-1;
                 Borrado=Borrado-1;
            }
            ui->textEdit_3->append(tr("Trabajo cancelado"));
            return;
        }
        QString ruta, final;
        QTableWidgetItem *item1,*item2,*item3,*item4,*item5,*item6,*item7,*item8,*item9,*item10;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        item4=new QTableWidgetItem;
        item5=new QTableWidgetItem;
        item6=new QTableWidgetItem;
        item7=new QTableWidgetItem;
        item8=new QTableWidgetItem;
        item9=new QTableWidgetItem;
        item10=new QTableWidgetItem;
        ruta=listaArchivos.value(i);
        QFile file(ruta);
        QString Buscar = ruta;
        if (ui->checkBox->isChecked() == false)
        {
            QString Value = QFileInfo(file).absoluteFilePath();
            if (Value.contains("/.") == false)
            {
                item1->setText(QFileInfo(file).fileName());
                item2->setText(QString::fromUtf8(ruta.remove(ui->lineEdit->text())));
                ui->progressBar->setFormat(""+Value+"... %p%");
                ui->textEdit_3->append(tr("Analizando...")+Value+"");
                item3->setText(QString::number(QFileInfo(file).size()));
                QDateTime Fecha = QFileInfo(file).lastModified();
                item4->setText(Fecha.toString());
                drakeSistema drake;
                QString tipo = drake.getTipo(Buscar);
                QStringList Tipo = tipo.split(":");
                QString tipe = Tipo.value(1);
                if (tipe.contains("directory"))
                {
                    item5->setText(tr("Directorio"));
                    item3->setText("");
                    item4->setText("");
                }
                else
                    item5->setText(tr("Archivo"));
                QStringList result;
                result = listaDestino.filter(ruta);
                for(int a=0;a<result.count();a++)
                {
                    final=result.value(a);
                    QFile file1(final);
                    QString Buscar = QFileInfo(file1).fileName();
                    QString Buscar0 = QString::fromUtf8(final.remove(ui->lineEdit_2->text()));
                    QString Buscar1 = QString::number(QFileInfo(file1).size());
                    QString Buscar2 = QFileInfo(file1).lastModified().toString();
                    if (QString::fromUtf8(ruta.remove(ui->lineEdit->text())) == QString::fromUtf8(final.remove(ui->lineEdit_2->text())))
                    {
                        if (QFileInfo(file1).fileName() == QFileInfo(file).fileName())
                        {
                            if (QString::number(QFileInfo(file1).size()) == QString::number(QFileInfo(file).size()))
                            {
                                if (tipe.contains("directory"))
                                {
                                   item6->setText(tr("Sin cambios"));
                                    item7->setText(Buscar);
                                    item8->setText(Buscar0);
                                    item9->setText("");
                                    item10->setText("");
                                }
                                else
                                {
                                    QDateTime Fecha1 = QFileInfo(file).lastModified();
                                    QDateTime Fecha2 = QFileInfo(file1).lastModified();
                                    QDate date1 = Fecha1.date();
                                    QDate date2 = Fecha2.date();
                                    QTime time1 = Fecha1.time();
                                    QTime time2 = Fecha2.time();
                                    int Hora1 = time1.hour();
                                    int Hora2 = time2.hour();
                                    int Minuto1 = time1.minute();
                                    int Minuto2 = time1.minute();
                                    if (QFileInfo(file1).lastModified().toString() == QFileInfo(file).lastModified().toString())
                                    {
                                        item6->setText(tr("Sin cambios"));
                                        item7->setText(Buscar);
                                        item8->setText(Buscar0);
                                        item9->setText(Buscar1);
                                        item10->setText(Buscar2);
                                    }
                                    else if (QFileInfo(file1).lastModified().toString() != QFileInfo(file).lastModified().toString())
                                    {
                                        if (Fecha1 == Fecha2)
                                        {
                                            item6->setText(tr("Sin cambios"));
                                            item7->setText(Buscar);
                                            item8->setText(Buscar0);
                                            item9->setText(Buscar1);
                                            item10->setText(Buscar2);
                                        }
                                        else
                                        {
                                            if (date1 == date2)
                                            {
                                                item6->setText(tr("Sin cambios"));
                                                item7->setText(Buscar);
                                                item8->setText(Buscar0);
                                                item9->setText(Buscar1);
                                                item10->setText(Buscar2);
                                            }
                                            else
                                            {
                                                if (Hora1 == Hora2 && Minuto1 == Minuto2)
                                                {
                                                    item6->setText(tr("Sin cambios"));
                                                    item7->setText(Buscar);
                                                    item8->setText(Buscar0);
                                                    item9->setText(Buscar1);
                                                    item10->setText(Buscar2);
                                                }
                                                else
                                                {
                                                    item6->setText(tr("Diferente"));
                                                    item7->setText(Buscar);
                                                    item8->setText(Buscar0);
                                                    item9->setText(Buscar1);
                                                    item10->setText(Buscar2);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (QString::number(QFileInfo(file1).size()) != QString::number(QFileInfo(file).size()))
                            {
                                if (tipe.contains("directory"))
                                {
                                    item6->setText(tr("Sin cambios"));
                                    item7->setText(Buscar);
                                    item8->setText(Buscar0);
                                    item9->setText("");
                                    item10->setText("");
                                }
                                else
                                {
                                    item6->setText(tr("Diferente"));
                                    item7->setText(Buscar);
                                    item8->setText(Buscar0);
                                    item9->setText(Buscar1);
                                    item10->setText(Buscar2);
                                }
                            }
                        }
                    }
                }
                if (item6->text() == "")
                {
                    item6->setText(tr("Sin destino"));
                    item7->setText("");
                    item8->setText("");
                    item9->setText("");
                    item10->setText("");
                }
                QString valor;
                if (item6->text() == tr("Sin cambios"))
                    valor = ":/Imagenes/thumbs_up.png";
                else if (item6->text() == tr("Diferente"))
                    valor = ":/Imagenes/Error.png";
                else if (item6->text() == tr("Sin destino"))
                    valor = ":/Imagenes/help.png";
                iFilas=ui->tableWidget_2->rowCount();
                ui->tableWidget_2->insertRow(iFilas);
                ui->tableWidget_2->setItem(iFilas,0,item1);
                ui->tableWidget_2->setItem(iFilas,1,item2);
                ui->tableWidget_2->setItem(iFilas,2,item3);
                ui->tableWidget_2->setItem(iFilas,3,item4);
                ui->tableWidget_2->setItem(iFilas,4,item5);
                ui->tableWidget_2->setItem(iFilas,5,item6);
                ui->tableWidget_2->item(iFilas,5)->setIcon(QIcon(valor));
                ui->tableWidget_2->setItem(iFilas,6,item7);
                ui->tableWidget_2->setItem(iFilas,7,item8);
                ui->tableWidget_2->setItem(iFilas,8,item9);
                ui->tableWidget_2->setItem(iFilas,9,item10);
                ui->progressBar->setValue(i);
            }
        }
        else
        {
            QString Value = QFileInfo(file).absoluteFilePath();
            item1->setText(QFileInfo(file).fileName());
            item2->setText(QString::fromUtf8(ruta.remove(ui->lineEdit->text())));
            ui->progressBar->setFormat(""+Value+"... %p%");
            ui->textEdit_3->append(tr("Analizando...")+Value+"");
            item3->setText(QString::number(QFileInfo(file).size()));
            QDateTime Fecha = QFileInfo(file).lastModified();
            item4->setText(Fecha.toString());
            drakeSistema drake;
            QString tipo = drake.getTipo(Buscar);
            QStringList Tipo = tipo.split(":");
            QString tipe = Tipo.value(1);
            if (tipe.contains("directory"))
            {
                item5->setText(tr("Directorio"));
                item3->setText("");
                item4->setText("");
            }
            else
                item5->setText(tr("Archivo"));
            QStringList result;
            result = listaDestino.filter(ruta);
            for(int a=0;a<result.count();a++)
            {
                final=result.value(a);
                QFile file1(final);
                QString Buscar = QFileInfo(file1).fileName();
                QString Buscar0 = QString::fromUtf8(final.remove(ui->lineEdit_2->text()));
                QString Buscar1 = QString::number(QFileInfo(file1).size());
                QString Buscar2 = QFileInfo(file1).lastModified().toString();
                if (QString::fromUtf8(ruta.remove(ui->lineEdit->text())) == QString::fromUtf8(final.remove(ui->lineEdit_2->text())))
                {
                    if (QFileInfo(file1).fileName() == QFileInfo(file).fileName())
                    {
                        if (QString::number(QFileInfo(file1).size()) == QString::number(QFileInfo(file).size()))
                        {
                            if (tipe.contains("directory"))
                            {
                                item6->setText(tr("Sin cambios"));
                                item7->setText(Buscar);
                                item8->setText(Buscar0);
                                item9->setText("");
                                item10->setText("");
                            }
                            else
                            {
                                QDateTime Fecha1 = QFileInfo(file).lastModified();
                                QDateTime Fecha2 = QFileInfo(file1).lastModified();
                                QDate date1 = Fecha1.date();
                                QDate date2 = Fecha2.date();
                                QTime time1 = Fecha1.time();
                                QTime time2 = Fecha2.time();
                                int Hora1 = time1.hour();
                                int Hora2 = time2.hour();
                                int Minuto1 = time1.minute();
                                int Minuto2 = time1.minute();
                                if (QFileInfo(file1).lastModified().toString() == QFileInfo(file).lastModified().toString())
                                {
                                    item6->setText(tr("Sin cambios"));
                                    item7->setText(Buscar);
                                    item8->setText(Buscar0);
                                    item9->setText(Buscar1);
                                    item10->setText(Buscar2);
                                }
                                else if (QFileInfo(file1).lastModified().toString() != QFileInfo(file).lastModified().toString())
                                {
                                    if (Fecha1 == Fecha2)
                                    {
                                        item6->setText(tr("Sin cambios"));
                                        item7->setText(Buscar);
                                        item8->setText(Buscar0);
                                        item9->setText(Buscar1);
                                        item10->setText(Buscar2);
                                    }
                                    else
                                    {
                                        if (date1 == date2)
                                        {
                                            item6->setText(tr("Sin cambios"));
                                            item7->setText(Buscar);
                                            item8->setText(Buscar0);
                                            item9->setText(Buscar1);
                                            item10->setText(Buscar2);
                                        }
                                        else
                                        {
                                            if (Hora1 == Hora2 && Minuto1 == Minuto2)
                                            {
                                                item6->setText(tr("Sin cambios"));
                                                item7->setText(Buscar);
                                                item8->setText(Buscar0);
                                                item9->setText(Buscar1);
                                                item10->setText(Buscar2);
                                            }
                                            else
                                            {
                                                item6->setText(tr("Diferente"));
                                                item7->setText(Buscar);
                                                item8->setText(Buscar0);
                                                item9->setText(Buscar1);
                                                item10->setText(Buscar2);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else if (QString::number(QFileInfo(file1).size()) != QString::number(QFileInfo(file).size()))
                        {
                            if (tipe.contains("directory"))
                            {
                                item6->setText(tr("Sin cambios"));
                                item7->setText(Buscar);
                                item8->setText(Buscar0);
                                item9->setText("");
                                item10->setText("");
                            }
                            else
                            {
                                item6->setText(tr("Diferente"));
                                item7->setText(Buscar);
                                item8->setText(Buscar0);
                                item9->setText(Buscar1);
                                item10->setText(Buscar2);
                            }
                        }
                    }
                }
            }
            if (item6->text() == "")
            {
                item6->setText(tr("Sin destino"));
                item7->setText("");
                item8->setText("");
                item9->setText("");
                item10->setText("");
            }
            QString valor;
            if (item6->text() == tr("Sin cambios"))
                valor = ":/Imagenes/thumbs_up.png";
            else if (item6->text() == tr("Diferente"))
                valor = ":/Imagenes/Error.png";
            else if (item6->text() == tr("Sin destino"))
                valor = ":/Imagenes/help.png";
            iFilas=ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(iFilas);
            ui->tableWidget_2->setItem(iFilas,0,item1);
            ui->tableWidget_2->setItem(iFilas,1,item2);
            ui->tableWidget_2->setItem(iFilas,2,item3);
            ui->tableWidget_2->setItem(iFilas,3,item4);
            ui->tableWidget_2->setItem(iFilas,4,item5);
            ui->tableWidget_2->setItem(iFilas,5,item6);
            ui->tableWidget_2->item(iFilas,5)->setIcon(QIcon(valor));
            ui->tableWidget_2->setItem(iFilas,6,item7);
            ui->tableWidget_2->setItem(iFilas,7,item8);
            ui->tableWidget_2->setItem(iFilas,8,item9);
            ui->tableWidget_2->setItem(iFilas,9,item10);
            ui->progressBar->setValue(i);
        }
    }
    ui->progressBar->setValue(listaArchivos.count());
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    ui->progressBar->setFormat("%p%");
    ui->progressBar->setRange(0,listaDestino.count());
    ui->progressBar->setTextVisible(true);
    ui->progressBar->setFormat(tr("Analizando eliminados... %p%"));
    QTest::qWait(20);
    for(int i=1;i<listaDestino.count();i++ )
    {
        qApp->processEvents();
        if (Evento == 1)
        {
            ui->progressBar->setRange(0,100);
            ui->progressBar->setValue(0);
            ui->progressBar->setFormat("%p%");
            ui->pushButton_4->setEnabled(false);
            ui->pushButton_5->setEnabled(true);
            ui->pushButton_7->setEnabled(false);
            ui->pushButton_8->setEnabled(false);
            ui->pushButton_9->setEnabled(false);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_15->setEnabled(false);
            ui->lineEdit->setEnabled(true);
            ui->lineEdit_2->setEnabled(true);
            int Borrado, x;
            Borrado = ui->tableWidget_2->rowCount();
            for(x=0;x<Borrado;x++)
            {
                 ui->tableWidget_2->removeRow(x);
                 x=x-1;
                 Borrado=Borrado-1;
            }
            ui->textEdit_3->append(tr("Trabajo cancelado"));
            return;
        }
        QString ruta;
        QTableWidgetItem *item1,*item2,*item3,*item4,*item5,*item6,*item7,*item8,*item9, *item10;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        item4=new QTableWidgetItem;
        item5=new QTableWidgetItem;
        item6=new QTableWidgetItem;
        item7=new QTableWidgetItem;
        item8=new QTableWidgetItem;
        item9=new QTableWidgetItem;
        item10=new QTableWidgetItem;
        ruta=listaDestino.value(i);        
        QFile file(ruta);
        QString Buscar = ruta;
        QString Value = QFileInfo(file).absoluteFilePath();
        item7->setText(QFileInfo(file).fileName());
        item8->setText(QString::fromUtf8(ruta.remove(ui->lineEdit_2->text())));
        ui->progressBar->setFormat(""+Value+" ... %p%");
        ui->textEdit_3->append(tr("Analizando...")+Value+"");
        item9->setText(QString::number(QFileInfo(file).size()));
        QDateTime Fecha = QFileInfo(file).lastModified();
        item10->setText(Fecha.toString());
        QStringList result;
        result = listaArchivos.filter(ruta);
        if (result.count() == 0)
        {
            item6->setText(tr("Sin origen"));
            item1->setText("");
            item2->setText("");
            item3->setText("");
            item4->setText("");
            drakeSistema drake;
            QString tipo = drake.getTipo(Buscar);
            QStringList Tipo = tipo.split(":");
            QString tipe = Tipo.value(1);
            if (tipe.contains("directory"))
            {
                item5->setText(tr("Directorio"));
                item4->setText("");
            }
            else
                item5->setText(tr("Archivo"));
        }
        if (item6->text() == tr("Sin origen"))
        {
            iFilas=ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(iFilas);
            ui->tableWidget_2->setItem(iFilas,0,item1);
            ui->tableWidget_2->setItem(iFilas,1,item2);
            ui->tableWidget_2->setItem(iFilas,2,item3);
            ui->tableWidget_2->setItem(iFilas,3,item4);
            ui->tableWidget_2->setItem(iFilas,4,item5);
            ui->tableWidget_2->setItem(iFilas,5,item6);
            ui->tableWidget_2->item(iFilas,5)->setIcon(QIcon(":/Imagenes/bad.png"));
            ui->tableWidget_2->setItem(iFilas,6,item7);
            ui->tableWidget_2->setItem(iFilas,7,item8);
            ui->tableWidget_2->setItem(iFilas,8,item9);
            ui->tableWidget_2->setItem(iFilas,9,item10);
        }
        ui->progressBar->setValue(i);
    }
    ui->progressBar->setValue(listaDestino.count());
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    ui->progressBar->setFormat("%p%");
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(false);
    ui->tableWidget_2->setSortingEnabled(true);
    ui->tableWidget_2->sortByColumn(1,Qt::AscendingOrder);
    ui->textEdit_3->append(tr("Finalizado analisis de objetivos"));
    ui->textEdit_3->append("");
    ui->textEdit_3->append(tr(":::RESULTADO DEL ANALISIS:::"));
    ui->textEdit_3->append("");
    int Contador = ui->tableWidget_2->rowCount();
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_13->setEnabled(true);
    ui->pushButton_15->setEnabled(false);
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
    ui->pushButton_7->setText(tr("Todos (")+QString::number(Contador)+")");
    ui->textEdit_3->append(tr("Archivos totales: ")+QString::number(Contador)+"");
    itemsa = ui->tableWidget_2->findItems(tr("Sin cambios") , Qt::MatchExactly);
    ui->pushButton_8->setText(tr("Iguales (")+QString::number(itemsa.count())+")");
    if (itemsa.count() == 0)
        ui->pushButton_8->setEnabled(false);
    ui->textEdit_3->append(tr("Archivos iguales: ")+QString::number(itemsa.count())+"");
    items1 = ui->tableWidget_2->findItems(tr("Diferente") , Qt::MatchExactly);
    ui->pushButton_9->setText(tr("Diferentes (")+QString::number(items1.count())+")");
    if (items1.count() == 0)
        ui->pushButton_9->setEnabled(false);
    ui->textEdit_3->append(tr("Archivos diferentes: ")+QString::number(items1.count())+"");
    items = ui->tableWidget_2->findItems(tr("Sin destino") , Qt::MatchExactly);
    ui->pushButton_4->setText(tr("Sin destino (")+QString::number(items.count())+")");
    if (items.count() == 0)
        ui->pushButton_4->setEnabled(false);
    ui->textEdit_3->append(tr("Archivos sin destino: ")+QString::number(items.count())+"");
    items2 = ui->tableWidget_2->findItems(tr("Sin origen") , Qt::MatchExactly);
    ui->pushButton_13->setText(tr("Sin origen (")+QString::number(items2.count())+")");
    if (items2.count() == 0)
        ui->pushButton_13->setEnabled(false);
    ui->textEdit_3->append(tr("Archivos sin origen: ")+QString::number(items2.count())+"");
    ui->textEdit_3->append("");
    if (Log == "S")
    {
        system(QString::fromUtf8("echo '"+ui->textEdit_3->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
    }
    ui->tableWidget_2->resizeColumnsToContents();
    ui->tableWidget_2->resizeRowsToContents();
}

void Comparador::on_pushButton_7_clicked()
{
    ui->tableWidget_2->setSortingEnabled(false);
    for(int i = 0; i < itemsa.count(); i++)
        ui->tableWidget_2->showRow(itemsa.at(i)->row());
    for(int i = 0; i < items1.count(); i++)
        ui->tableWidget_2->showRow(items1.at(i)->row());
    for(int i = 0; i < items.count(); i++)
        ui->tableWidget_2->showRow(items.at(i)->row());
    for(int i = 0; i < items2.count(); i++)
        ui->tableWidget_2->showRow(items2.at(i)->row());
    ui->tableWidget_2->setSortingEnabled(true);
}

void Comparador::on_pushButton_8_clicked()
{
    ui->tableWidget_2->setSortingEnabled(false);
    for(int i = 0; i < itemsa.count(); i++)
        ui->tableWidget_2->showRow(itemsa.at(i)->row());
    for(int i = 0; i < items.count(); i++)
        ui->tableWidget_2->hideRow(items.at(i)->row());
    for(int i = 0; i < items1.count(); i++)
        ui->tableWidget_2->hideRow(items1.at(i)->row());
    for(int i = 0; i < items2.count(); i++)
        ui->tableWidget_2->hideRow(items2.at(i)->row());
    ui->tableWidget_2->setSortingEnabled(true);
}

void Comparador::on_pushButton_9_clicked()
{
    ui->tableWidget_2->setSortingEnabled(false);
    for(int i = 0; i < items1.count(); i++)
        ui->tableWidget_2->showRow(items1.at(i)->row());
    for(int i = 0; i < itemsa.count(); i++)
        ui->tableWidget_2->hideRow(itemsa.at(i)->row());
    for(int i = 0; i < items.count(); i++)
        ui->tableWidget_2->hideRow(items.at(i)->row());
    for(int i = 0; i < items2.count(); i++)
        ui->tableWidget_2->hideRow(items2.at(i)->row());
    ui->tableWidget_2->setSortingEnabled(true);
}

void Comparador::on_pushButton_4_clicked()
{
    ui->tableWidget_2->setSortingEnabled(false);
    for(int i = 0; i < items.count(); i++)
        ui->tableWidget_2->showRow(items.at(i)->row());
    for(int i = 0; i < itemsa.count(); i++)
        ui->tableWidget_2->hideRow(itemsa.at(i)->row());
    for(int i = 0; i < items1.count(); i++)
        ui->tableWidget_2->hideRow(items1.at(i)->row());
    for(int i = 0; i < items2.count(); i++)
        ui->tableWidget_2->hideRow(items2.at(i)->row());
    ui->tableWidget_2->setSortingEnabled(true);
}

void Comparador::on_pushButton_13_clicked()
{
    ui->tableWidget_2->setSortingEnabled(false);
    for(int i = 0; i < items2.count(); i++)
        ui->tableWidget_2->showRow(items2.at(i)->row());
    for(int i = 0; i < itemsa.count(); i++)
        ui->tableWidget_2->hideRow(itemsa.at(i)->row());
    for(int i = 0; i < items1.count(); i++)
        ui->tableWidget_2->hideRow(items1.at(i)->row());
    for(int i = 0; i < items.count(); i++)
        ui->tableWidget_2->hideRow(items.at(i)->row());
    ui->tableWidget_2->setSortingEnabled(true);
}

void Comparador::on_pushButton_15_clicked()
{
    Evento = 1;   
}

void Comparador::on_pushButton_6_clicked()
{
    if (ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has introducido rutas para poder comparar."));
        m.exec();
        return;
    }
    ui->treeWidget->clear();
    int Borrado, x;
    Borrado = ui->tableWidget->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    ui->label_6->setText("");
    ui->label_3->setText("");
    ui->label_4->setText("");
    ui->pushButton_14->setText(tr("Todas las diferencias"));
    ui->pushButton_12->setText(tr("Mostrar lineas diferentes"));
    ui->pushButton_10->setText(tr("Mostrar destino vacio"));
    ui->pushButton_11->setText(tr("Mostrar origen vacio"));
    ui->pushButton_14->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->lineEdit_2->setEnabled(false);
    QTest::qWait(20);
    QString ruta, ruta1;
    ruta = ui->lineEdit->text();
    ruta1 = ui->lineEdit_2->text();
    QFile file(ruta);
    QFile file1(ruta1);
    if (QString::number(QFileInfo(file1).size()) == QString::number(QFileInfo(file).size()))
    {
        if (QFileInfo(file1).lastModified().toString() == QFileInfo(file).lastModified().toString())
        {
            ui->label_6->setText(tr("<FONT COLOR=\"BLUE\"><B>Los archivos son identicos</B>"));
            ui->pushButton_14->setText(tr("Todas las diferencias"));
            ui->pushButton_12->setText(tr("Mostrar lineas diferentes"));
            ui->pushButton_10->setText(tr("Mostrar destino vacio"));
            ui->pushButton_11->setText(tr("Mostrar origen vacio"));
            ui->pushButton_14->setEnabled(false);
            ui->pushButton_12->setEnabled(false);
            ui->pushButton_10->setEnabled(false);
            ui->pushButton_11->setEnabled(false);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            ui->lineEdit->setEnabled(true);
            ui->lineEdit_2->setEnabled(true);
            return;
        }
        else
        {
            ui->label_6->setText(tr("<FONT COLOR=\"RED\"><B>Los archivos son distintos</B>"));
        }
    }
    else
    {
        ui->label_6->setText(tr("<FONT COLOR=\"RED\"><B>Los archivos son distintos</B>"));
    }
    QTest::qWait(20);
    int Romper;
    Romper = 0;
    drakeSistema drake;
    QString Dato = "diff -y \"%1\" \"%2\"";
    Dato = Dato.arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text());
    QString Valor = drake.getStart(Dato);
    if (Valor.contains(ui->lineEdit->text()))
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El fichero no es legible para poder comparar."));
        m.exec();
        ui->label_6->setText("");
        ui->label_3->setText("");
        ui->label_4->setText("");
        ui->pushButton_14->setText(tr("Todas las diferencias"));
        ui->pushButton_12->setText(tr("Mostrar lineas diferentes"));
        ui->pushButton_10->setText(tr("Mostrar destino vacio"));
        ui->pushButton_11->setText(tr("Mostrar origen vacio"));
        ui->pushButton_14->setEnabled(false);
        ui->pushButton_12->setEnabled(false);
        ui->pushButton_10->setEnabled(false);
        ui->pushButton_11->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setEnabled(true);
        return;
    }
    else
    {
        if (Tipo == 0)
        {
            system("cat \""+ui->lineEdit->text()+"\" > /usr/share/RecoverDrake/Comparador1.txt");
            system("cat \""+ui->lineEdit_2->text()+"\" > /usr/share/RecoverDrake/Comparador2.txt");
            QFile file("/usr/share/RecoverDrake/Comparador1.txt");
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in(&file);
            QString datoslst = in.readAll();
            file.close();
            QFile file1("/usr/share/RecoverDrake/Comparador2.txt");
            file1.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in1(&file1);
            QString datoslst1 = in1.readAll();
            file1.close();
            QStringList lista = datoslst.split("\n");
            QStringList lista1 = datoslst1.split("\n");
            int iFilas;
            QTableWidgetItem *item1, *item2, *item3;
            int a = lista.count();
            int b = lista1.count();
            ui->label_3->setText(QString::number(b));
            ui->label_4->setText(QString::number(a));
            ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem(tr("Linea origen")));
            ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem(tr("Linea destino")));
            ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("Tipo de diferencia")));
            if (lista.count() > lista1.count())
            {
                setUpdatesEnabled(false);
                QProgressDialog progress(tr("Comparando archivos... Espera por favor"), tr("Cancelar"), 0, lista.count(),this);
                progress.show();
                for(int i=0;i<lista.count();i++)
                {
                    qApp->processEvents();
                    progress.setValue(i);
                    if (progress.wasCanceled())
                    {
                        ui->treeWidget->clear();
                        int Borrado, x;
                        Borrado = ui->tableWidget->rowCount();
                        for(x=0;x<Borrado;x++)
                        {
                             ui->tableWidget->removeRow(x);
                             x=x-1;
                             Borrado=Borrado-1;
                        }
                        ui->label_6->setText("");
                        ui->label_3->setText("");
                        ui->label_4->setText("");
                        ui->pushButton_14->setText(tr("Todas las diferencias"));
                        ui->pushButton_12->setText(tr("Mostrar lineas diferentes"));
                        ui->pushButton_10->setText(tr("Mostrar destino vacio"));
                        ui->pushButton_11->setText(tr("Mostrar origen vacio"));
                        ui->pushButton_14->setEnabled(false);
                        ui->pushButton_12->setEnabled(false);
                        ui->pushButton_10->setEnabled(false);
                        ui->pushButton_11->setEnabled(false);
                        ui->pushButton_2->setEnabled(true);
                        ui->pushButton_3->setEnabled(true);
                        ui->lineEdit->setEnabled(true);
                        ui->lineEdit_2->setEnabled(true);
                        Romper = 1;
                        break;
                    }
                    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
                    item->setText(0,QString::number(i+1));
                    item->setText(1,lista.value(i));
                    item->setText(3,QString::number(i+1));
                    item->setText(4,lista1.value(i));
                    if (lista.value(i) != lista1.value(i))
                    {
                        item1=new QTableWidgetItem;
                        item2=new QTableWidgetItem;
                        item3=new QTableWidgetItem;
                        item1->setText(QString::number(i+1));
                        item2->setText(QString::number(i+1));
                        if (lista.value(i) == "" || lista1.value(i) == "")
                        {
                            if (lista.value(i) == "")
                            {
                                item3->setText(tr("Origen vacio"));
                                item->setText(5,"#VD");
                            }
                            else if (lista1.value(i) == "")
                            {
                                item3->setText(tr("Destino vacio"));
                                item->setText(5,"#VI");
                            }
                        }
                        else
                        {
                            item3->setText(tr("Los datos de la linea son diferentes"));
                            item->setText(5,"#D");
                        }
                        iFilas=ui->tableWidget->rowCount();
                        ui->tableWidget->insertRow(iFilas);
                        ui->tableWidget->setItem(iFilas,0,item1);
                        ui->tableWidget->setItem(iFilas,1,item2);
                        ui->tableWidget->setItem(iFilas,2,item3);
                    }
                    ui->treeWidget->addTopLevelItem(item);
                }
                ui->treeWidget->resizeColumnToContents(0);
                ui->treeWidget->resizeColumnToContents(1);
                ui->treeWidget->resizeColumnToContents(2);
                ui->treeWidget->resizeColumnToContents(3);
                ui->treeWidget->resizeColumnToContents(4);
                ui->treeWidget->resizeColumnToContents(5);
                progress.setValue(lista.count());
                setUpdatesEnabled(true);
            }
            else if (lista.count() < lista1.count())
            {
                setUpdatesEnabled(false);
                QProgressDialog progress(tr("Comparando archivos... Espera por favor"), tr("Cancelar"), 0, lista.count(),this);
                progress.show();
                for(int i=0;i<lista1.count();i++)
                {
                    qApp->processEvents();
                    progress.setValue(i);
                    if (progress.wasCanceled())
                    {
                        ui->treeWidget->clear();
                        int Borrado, x;
                        Borrado = ui->tableWidget->rowCount();
                        for(x=0;x<Borrado;x++)
                        {
                             ui->tableWidget->removeRow(x);
                             x=x-1;
                             Borrado=Borrado-1;
                        }
                        ui->label_6->setText("");
                        ui->label_3->setText("");
                        ui->label_4->setText("");
                        ui->pushButton_14->setText(tr("Todas las diferencias"));
                        ui->pushButton_12->setText(tr("Mostrar lineas diferentes"));
                        ui->pushButton_10->setText(tr("Mostrar destino vacio"));
                        ui->pushButton_11->setText(tr("Mostrar origen vacio"));
                        ui->pushButton_14->setEnabled(false);
                        ui->pushButton_12->setEnabled(false);
                        ui->pushButton_10->setEnabled(false);
                        ui->pushButton_11->setEnabled(false);
                        ui->pushButton_2->setEnabled(true);
                        ui->pushButton_3->setEnabled(true);
                        ui->lineEdit->setEnabled(true);
                        ui->lineEdit_2->setEnabled(true);
                        Romper = 1;
                        break;
                    }
                    QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
                    item->setText(0,QString::number(i+1));
                    item->setText(1,lista.value(i));
                    item->setText(3,QString::number(i+1));
                    item->setText(4,lista1.value(i));
                    if (lista.value(i) != lista1.value(i))
                    {
                        item1=new QTableWidgetItem;
                        item2=new QTableWidgetItem;
                        item3=new QTableWidgetItem;
                        item1->setText(QString::number(i+1));
                        item2->setText(QString::number(i+1));
                        if (lista.value(i) == "" || lista1.value(i) == "")
                        {
                            if (lista.value(i) == "")
                            {
                                item3->setText(tr("Origen vacio"));
                                item->setText(5,"#VD");
                            }
                            else if (lista1.value(i) == "")
                            {
                                item3->setText(tr("Destino vacio"));
                                item->setText(5,"#VI");
                            }
                        }
                        else
                        {
                            item3->setText(tr("Los datos de la linea son diferentes"));
                            item->setText(5,"#D");
                        }
                        iFilas=ui->tableWidget->rowCount();
                        ui->tableWidget->insertRow(iFilas);
                        ui->tableWidget->setItem(iFilas,0,item1);
                        ui->tableWidget->setItem(iFilas,1,item2);
                        ui->tableWidget->setItem(iFilas,2,item3);
                    }
                    ui->treeWidget->addTopLevelItem(item);
                }
                ui->treeWidget->resizeColumnToContents(0);
                ui->treeWidget->resizeColumnToContents(1);
                ui->treeWidget->resizeColumnToContents(2);
                ui->treeWidget->resizeColumnToContents(3);
                ui->treeWidget->resizeColumnToContents(4);
                ui->treeWidget->resizeColumnToContents(5);
                progress.setValue(lista.count());
                setUpdatesEnabled(true);
            }
            ui->tableWidget->resizeColumnsToContents();
            ui->tableWidget->resizeRowsToContents();
        }
        if (Tipo == 1)
        {
            system("cat \""+ui->lineEdit->text()+"\" > /usr/share/RecoverDrake/Comparador1.txt");
            system("cat \""+ui->lineEdit_2->text()+"\" > /usr/share/RecoverDrake/Comparador2.txt");
            QFile file("/usr/share/RecoverDrake/Comparador1.txt");
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in(&file);
            QString datoslst = in.readAll();
            file.close();
            QFile file1("/usr/share/RecoverDrake/Comparador2.txt");
            file1.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream in1(&file1);
            QString datoslst1 = in1.readAll();
            file1.close();
            QStringList lista = datoslst.split("\n");
            QStringList lista1 = datoslst1.split("\n");
            int iFilas;
            QTableWidgetItem *item1, *item2, *item3;
            int a = lista.count();
            int b = lista1.count();
            ui->label_3->setText(QString::number(b));
            ui->label_4->setText(QString::number(a));
            ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem(tr("Dato Linea origen")));
            ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem(tr("Repeticiones en destino")));
            ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("Situacion")));
            setUpdatesEnabled(false);
            QProgressDialog progress(tr("Comparando archivos... Espera por favor"), tr("Cancelar"), 0, lista.count(),this);
            progress.show();
            for(int i=0;i<lista.count();i++)
            {
                qApp->processEvents();
                progress.setValue(i);
                if (progress.wasCanceled())
                {
                    ui->treeWidget->clear();
                    int Borrado, x;
                    Borrado = ui->tableWidget->rowCount();
                    for(x=0;x<Borrado;x++)
                    {
                         ui->tableWidget->removeRow(x);
                         x=x-1;
                         Borrado=Borrado-1;
                    }
                    ui->label_6->setText("");
                    ui->label_3->setText("");
                    ui->label_4->setText("");
                    ui->pushButton_14->setText(tr("Todas las diferencias"));
                    ui->pushButton_12->setText(tr("Mostrar lineas diferentes"));
                    ui->pushButton_10->setText(tr("Mostrar destino vacio"));
                    ui->pushButton_11->setText(tr("Mostrar origen vacio"));
                    ui->pushButton_14->setEnabled(false);
                    ui->pushButton_12->setEnabled(false);
                    ui->pushButton_10->setEnabled(false);
                    ui->pushButton_11->setEnabled(false);
                    ui->pushButton_2->setEnabled(true);
                    ui->pushButton_3->setEnabled(true);
                    ui->lineEdit->setEnabled(true);
                    ui->lineEdit_2->setEnabled(true);
                    Romper = 1;
                    break;
                }
                QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
                item->setText(0,QString::number(i+1));
                item->setText(1,lista.value(i));
                item->setText(3,QString::number(i+1));
                item->setText(4,lista1.value(i));
                int Sumar = 0;
                for(int a=0;a<lista1.count();a++)
                {
                    if (lista.value(i) == lista1.value(a))
                    {
                        Sumar = Sumar+1 ;
                    }
                }
                item1=new QTableWidgetItem;
                item2=new QTableWidgetItem;
                item3=new QTableWidgetItem;
                item1->setText(lista.value(i));
                if (Sumar > 0)
                {
                    item2->setText(tr("Se repite en ")+QString::number(Sumar)+tr(" ocasiones"));
                    item3->setText(tr("Positiva"));
                }
                else
                {
                    item2->setText(tr("No hay coincidencias"));
                    item3->setText(tr("Negativa"));
                }
                if (item1->text() != "")
                {
                    iFilas=ui->tableWidget->rowCount();
                    ui->tableWidget->insertRow(iFilas);
                    ui->tableWidget->setItem(iFilas,0,item1);
                    ui->tableWidget->setItem(iFilas,1,item2);
                    ui->tableWidget->setItem(iFilas,2,item3);
                }
                ui->treeWidget->addTopLevelItem(item);
            }
            ui->treeWidget->resizeColumnToContents(0);
            ui->treeWidget->resizeColumnToContents(1);
            ui->treeWidget->resizeColumnToContents(2);
            ui->treeWidget->resizeColumnToContents(3);
            ui->treeWidget->resizeColumnToContents(4);
            ui->treeWidget->resizeColumnToContents(5);
            progress.setValue(lista.count());
            setUpdatesEnabled(true);
            ui->tableWidget->resizeColumnsToContents();
            ui->tableWidget->resizeRowsToContents();
        }
        if (Tipo == 2)
        {
             system("diff \""+ui->lineEdit->text()+"\" \""+ui->lineEdit_2->text()+"\" > /usr/share/RecoverDrake/Comparador.txt");
             system("cat \""+ui->lineEdit->text()+"\" > /usr/share/RecoverDrake/Comparador1.txt");
             system("cat \""+ui->lineEdit_2->text()+"\" > /usr/share/RecoverDrake/Comparador2.txt");
             QFile file0("/usr/share/RecoverDrake/Comparador.txt");
             file0.open(QIODevice::ReadOnly | QIODevice::Text);
             QTextStream in0(&file0);
             QString datoslst0 = in0.readAll();
             file0.close();
             QFile file("/usr/share/RecoverDrake/Comparador1.txt");
             file.open(QIODevice::ReadOnly | QIODevice::Text);
             QTextStream in(&file);
             QString datoslst = in.readAll();
             file.close();
             QFile file1("/usr/share/RecoverDrake/Comparador2.txt");
             file1.open(QIODevice::ReadOnly | QIODevice::Text);
             QTextStream in1(&file1);
             QString datoslst1 = in1.readAll();
             file1.close();
             QStringList Base = datoslst0.split("\n");
             QStringList lista = datoslst.split("\n");
             QStringList lista1 = datoslst1.split("\n");
             int iFilas;
             QTableWidgetItem *item1, *item2, *item3;
             int a = lista.count();
             int b = lista1.count();
             ui->label_3->setText(QString::number(b));
             ui->label_4->setText(QString::number(a));
             ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem(tr("Linea origen")));
             ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem(tr("Linea destino")));
             ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("Tipo de diferencia")));
             setUpdatesEnabled(false);
             QProgressDialog progress(tr("Comparando archivos... Espera por favor"), tr("Cancelar"), 0, lista.count(),this);
             progress.show();
             for(int i=0;i<lista.count();i++)
             {
                 qApp->processEvents();
                 progress.setValue(i);
                 if (progress.wasCanceled())
                 {
                     ui->treeWidget->clear();
                     int Borrado, x;
                     Borrado = ui->tableWidget->rowCount();
                     for(x=0;x<Borrado;x++)
                     {
                          ui->tableWidget->removeRow(x);
                          x=x-1;
                          Borrado=Borrado-1;
                     }
                     ui->label_6->setText("");
                     ui->label_3->setText("");
                     ui->label_4->setText("");
                     ui->pushButton_14->setText(tr("Todas las diferencias"));
                     ui->pushButton_12->setText(tr("Mostrar lineas diferentes"));
                     ui->pushButton_10->setText(tr("Mostrar destino vacio"));
                     ui->pushButton_11->setText(tr("Mostrar origen vacio"));
                     ui->pushButton_14->setEnabled(false);
                     ui->pushButton_12->setEnabled(false);
                     ui->pushButton_10->setEnabled(false);
                     ui->pushButton_11->setEnabled(false);
                     ui->pushButton_2->setEnabled(true);
                     ui->pushButton_3->setEnabled(true);
                     ui->lineEdit->setEnabled(true);
                     ui->lineEdit_2->setEnabled(true);
                     Romper = 1;
                     break;
                 }
                 QTreeWidgetItem *item = new QTreeWidgetItem(ui->treeWidget);
                 item->setText(0,QString::number(i+1));
                 item->setText(1,lista.value(i));
                 item->setText(3,QString::number(i+1));
                 item->setText(4,lista1.value(i));
                 ui->treeWidget->addTopLevelItem(item);
             }
             ui->treeWidget->resizeColumnToContents(0);
             ui->treeWidget->resizeColumnToContents(1);
             ui->treeWidget->resizeColumnToContents(2);
             ui->treeWidget->resizeColumnToContents(3);
             ui->treeWidget->resizeColumnToContents(4);
             ui->treeWidget->resizeColumnToContents(5);
             progress.setValue(lista.count());
             setUpdatesEnabled(true);
             QStringList Depurado;
             for (int a=0;a<Base.count();a++)
             {
                 QString Valor = Base.value(a);
                 if (Valor.left(1) != "<" && Valor.left(1) != ">" && Valor != "---")
                 {
                     Depurado << Valor;
                 }
             }
             for (int b=0;b<Depurado.count()-1;b++)
             {
                 int Dato1, Dato2, Dato3, Dato4, DatoA;
                 Dato1 = 0;
                 Dato2 = 0;
                 Dato3 = 0;
                 Dato4 = 0;
                 DatoA = 0;
                 QString Type;
                 QString Value = Depurado.value(b);
                 if (Value.contains("a"))
                 {
                     QStringList Partir = Value.split("a");
                     if (Partir.value(0).contains(","))
                     {
                         QString Separar = Partir.value(0);
                         QStringList Partes = Separar.split(",");
                         Dato1 = Partes.value(0).toInt();
                         Dato2 = Partes.value(1).toInt();
                         DatoA = (Dato2 - Dato1) + 1;
                     }
                     else
                     {
                         Dato1 = Partir.value(0).toInt();
                         DatoA = Dato1;
                     }
                     if (Partir.value(1).contains(","))
                     {
                         QString Separar = Partir.value(1);
                         QStringList Partes = Separar.split(",");
                         Dato3 = Partes.value(0).toInt();
                         Dato4 = Partes.value(1).toInt();
                     }
                     else
                     {
                         Dato3 = Partir.value(1).toInt();
                     }
                     Type = "a";
                 }
                 else if (Value.contains("c"))
                 {
                     QStringList Partir = Value.split("c");
                     if (Partir.value(0).contains(","))
                     {
                         QString Separar = Partir.value(0);
                         QStringList Partes = Separar.split(",");
                         Dato1 = Partes.value(0).toInt();
                         Dato2 = Partes.value(1).toInt();
                         DatoA = (Dato2 - Dato1) + 1;
                     }
                     else
                     {
                         Dato1 = Partir.value(0).toInt();
                         DatoA = Dato1;
                     }
                     if (Partir.value(1).contains(","))
                     {
                         QString Separar = Partir.value(1);
                         QStringList Partes = Separar.split(",");
                         Dato3 = Partes.value(0).toInt();
                         Dato4 = Partes.value(1).toInt();
                     }
                     else
                     {
                         Dato3 = Partir.value(1).toInt();
                     }
                     Type = "c";
                 }
                 else if (Value.contains("d"))
                 {
                     QStringList Partir = Value.split("d");
                     if (Partir.value(0).contains(","))
                     {
                         QString Separar = Partir.value(0);
                         QStringList Partes = Separar.split(",");
                         Dato1 = Partes.value(0).toInt();
                         Dato2 = Partes.value(1).toInt();
                         DatoA = (Dato2 - Dato1) + 1;
                     }
                     else
                     {
                         Dato1 = Partir.value(0).toInt();
                         DatoA = Dato1;
                     }
                     if (Partir.value(1).contains(","))
                     {
                         QString Separar = Partir.value(1);
                         QStringList Partes = Separar.split(",");
                         Dato3 = Partes.value(0).toInt();
                         Dato4 = Partes.value(1).toInt();
                     }
                     else
                     {
                         Dato3 = Partir.value(1).toInt();
                     }
                     Type = "d";
                 }
                 item1=new QTableWidgetItem;
                 item2=new QTableWidgetItem;
                 item3=new QTableWidgetItem;
                 item1->setText(QString::number(Dato1));
                 item2->setText(QString::number(Dato3));
                 if (Type == "a")
                     item3->setText(tr("Insertadas ")+QString::number(DatoA)+tr(" lineas"));
                 if (Type == "c")
                     item3->setText(tr("Cambiadas ")+QString::number(DatoA)+tr(" lineas"));
                 if (Type == "b")
                     item3->setText(tr("Eliminadas ")+QString::number(DatoA)+tr(" lineas"));
                 iFilas=ui->tableWidget->rowCount();
                 ui->tableWidget->insertRow(iFilas);
                 ui->tableWidget->setItem(iFilas,0,item1);
                 ui->tableWidget->setItem(iFilas,1,item2);
                 ui->tableWidget->setItem(iFilas,2,item3);
                 ui->tableWidget->resizeColumnsToContents();
                 ui->tableWidget->resizeRowsToContents();
             }
        }
    }
    if (Tipo == 0)
    {
        if (Romper == 0)
        {
            int Contador = ui->tableWidget->rowCount();
            ui->pushButton_14->setEnabled(true);
            ui->pushButton_12->setEnabled(true);
            ui->pushButton_10->setEnabled(true);
            ui->pushButton_11->setEnabled(true);
            if (Contador == 0)
                ui->pushButton_14->setEnabled(false);
            ui->pushButton_14->setText(tr("Todas las diferencias (")+QString::number(Contador)+")");
            itemsa = ui->tableWidget->findItems(tr("Los datos de la linea son diferentes") , Qt::MatchExactly);
            ui->pushButton_12->setText(tr("Mostrar lineas diferentes (")+QString::number(itemsa.count())+")");
            if (itemsa.count() == 0)
                ui->pushButton_12->setEnabled(false);
            items1 = ui->tableWidget->findItems(tr("Destino vacio") , Qt::MatchExactly);
            ui->pushButton_10->setText(tr("Mostrar destino vacio (")+QString::number(items1.count())+")");
            if (items1.count() == 0)
                ui->pushButton_10->setEnabled(false);
            items = ui->tableWidget->findItems(tr("Origen vacio") , Qt::MatchExactly);
            ui->pushButton_11->setText(tr("Mostrar origen vacio (")+QString::number(items.count())+")");
            if (items.count() == 0)
                ui->pushButton_11->setEnabled(false);
        }
    }
    system("rm -f /usr/share/RecoverDrake/Comparador.txt");
    system("rm -f /usr/share/RecoverDrake/Comparador1.txt");
    system("rm -f /usr/share/RecoverDrake/Comparador2.txt");
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setEnabled(true);
}

void Comparador::on_tableWidget_itemSelectionChanged()
{
    QTreeWidgetItemIterator limpiar(ui->treeWidget);
    while (*limpiar)
    {
        (*limpiar)->setSelected(false);
        ++limpiar;
    }
    QString contador;
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it)
    {
        if (Tipo == 0)
        {
            contador = ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text();
            if ((*it)->text(5) == contador)
            (*it)->setSelected(true);
            ++it;
        }
        if (Tipo == 1)
        {
            contador = ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text();
            if ((*it)->text(1) == contador || (*it)->text(4) == contador)
            (*it)->setSelected(true);
            ++it;
        }
        if (Tipo == 2)
        {
            QString Valor1 = ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text();
            QString Valor2 = ui->tableWidget->item(ui->tableWidget->currentRow(), 2)->text();
            Valor2 = Valor2.remove(tr("Insertadas ")).remove(tr(" lineas")).remove(tr("Cambiadas ")).remove(tr("Eliminadas "));
            int Resto = (Valor2.toInt() + Valor1.toInt());
            int a;
            a = Valor1.toInt();
            for (int c=a;c<Resto;c++)
            {
                contador = QString::number(c); //contador = QString::number(Resto);
                if ((*it)->text(0) == contador)
                (*it)->setSelected(true);
            }
            ++it;
        }
    }
    QModelIndex index;
    index = ui->treeWidget->model()->index(contador.toInt(),0);
    ui->treeWidget->scrollTo(index,QAbstractItemView::PositionAtCenter);
}

void Comparador::on_pushButton_12_clicked()
{
    QTreeWidgetItemIterator limpiar(ui->treeWidget);
    while (*limpiar)
    {
        (*limpiar)->setSelected(false);
        ++limpiar;
    }
    for(int i = 0; i < itemsa.count(); i++)
        ui->tableWidget->showRow(itemsa.at(i)->row());
    for(int i = 0; i < items1.count(); i++)
        ui->tableWidget->hideRow(items1.at(i)->row());
    for(int i = 0; i < items.count(); i++)
        ui->tableWidget->hideRow(items.at(i)->row());
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it)
    {
        if ((*it)->text(5) == "#D")
        (*it)->setSelected(true);
        ++it;
    }
    QModelIndex index;
    index = ui->treeWidget->model()->index(itemsa.at(0)->row()+1,0);
    ui->treeWidget->scrollTo(index,QAbstractItemView::PositionAtCenter);
}

void Comparador::on_pushButton_10_clicked()
{
    QTreeWidgetItemIterator limpiar(ui->treeWidget);
    while (*limpiar)
    {
        (*limpiar)->setSelected(false);
        ++limpiar;
    }
    for(int i = 0; i < itemsa.count(); i++)
        ui->tableWidget->hideRow(itemsa.at(i)->row());
    for(int i = 0; i < items1.count(); i++)
        ui->tableWidget->showRow(items1.at(i)->row());
    for(int i = 0; i < items.count(); i++)
        ui->tableWidget->hideRow(items.at(i)->row());
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it)
    {
        if ((*it)->text(5) == "#VI")
        (*it)->setSelected(true);
        ++it;
    }
    QModelIndex index;
    index = ui->treeWidget->model()->index(items1.at(0)->row()+1,0);
    ui->treeWidget->scrollTo(index,QAbstractItemView::PositionAtCenter);
}

void Comparador::on_pushButton_11_clicked()
{
    QTreeWidgetItemIterator limpiar(ui->treeWidget);
    while (*limpiar)
    {
        (*limpiar)->setSelected(false);
        ++limpiar;
    }
    for(int i = 0; i < itemsa.count(); i++)
        ui->tableWidget->hideRow(itemsa.at(i)->row());
    for(int i = 0; i < items1.count(); i++)
        ui->tableWidget->hideRow(items1.at(i)->row());
    for(int i = 0; i < items.count(); i++)
        ui->tableWidget->showRow(items.at(i)->row());
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it)
    {
        if ((*it)->text(5) == "#VD")
        (*it)->setSelected(true);
        ++it;
    }
    QModelIndex index;
    index = ui->treeWidget->model()->index(items.at(0)->row()+1,0);
    ui->treeWidget->scrollTo(index,QAbstractItemView::PositionAtCenter);
}

void Comparador::on_pushButton_14_clicked()
{
    QTreeWidgetItemIterator limpiar(ui->treeWidget);
    while (*limpiar)
    {
        (*limpiar)->setSelected(false);
        ++limpiar;
    }
    for(int i = 0; i < itemsa.count(); i++)
        ui->tableWidget->showRow(itemsa.at(i)->row());
    for(int i = 0; i < items1.count(); i++)
        ui->tableWidget->showRow(items1.at(i)->row());
    for(int i = 0; i < items.count(); i++)
        ui->tableWidget->showRow(items.at(i)->row());
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it)
    {
        if ((*it)->text(5) == "#VD")
        (*it)->setSelected(true);
        if ((*it)->text(5) == "#VI")
        (*it)->setSelected(true);
        if ((*it)->text(5) == "#D")
        (*it)->setSelected(true);
        ++it;
    }
    int Valor, a, b, c;
    a = itemsa.at(0)->row()+1;
    b = items1.at(0)->row()+1;
    c = items.at(0)->row()+1;
    if (a < b)
    {
        if (a < c)
        {
            Valor = a;
        }
    }
    if (b < a)
    {
        if (b < c)
        {
            Valor = b;
        }
    }
    else if (c < a)
    {
        if (c < b)
        {
            Valor = c;
        }
    }
    QModelIndex index;
    index = ui->treeWidget->model()->index(Valor,0);
    ui->treeWidget->scrollTo(index,QAbstractItemView::PositionAtCenter);
}
