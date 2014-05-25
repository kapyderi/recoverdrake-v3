#include "sincrono.h"
#include "ui_sincrono.h"
#include <QFileDialog>
#include "drakesistema.h"
#include <QFile>
#include <QDateTime>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTest>
#include <QKeyEvent>
#include <QDebug>
#include "totalsincrono.h"

sincrono::sincrono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sincrono)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    drakeSistema drake;
    user = drake.getUser();
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
    mib = 0;
    Evento = 0;
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
    ui->checkBox_2->setChecked(true);
    connect(ui->checkBox,SIGNAL(clicked()),this,SLOT(Comprobar()));
    Sincronizador = 0;
    NoSincro = 0;
    Value = 0;
    colorAnt = ui->pushButton_14->backgroundColor();
    this->installEventFilter(this);
    Comprueba = "No";
    Counter = 0;
    ContadorC = 0;
    Marca = 0;
    Contad = new QTimer(this);
    connect(Contad, SIGNAL(timeout()), this, SLOT(Montaje()));
    Contad->start(5000);
}

sincrono::~sincrono()
{
    delete ui;
    if (mib != 0)
        delete mib;
}

void sincrono::changeEvent(QEvent *e)
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

void sincrono::Valor(QString Ref, QString Valor1, QString Valor2, QString Valor3, QString Valor4, QString Valor5, QString Valor6, int Value, QString Log, QString Pos)
{
    QColor color;
    Referencia = Ref;
    ui->lineEdit_3->setText(Referencia);
    if (Valor1.right(1) == "/")
        Valor1.remove(Valor1.count()-1,1);
    if (Valor2.right(1) == "/")
        Valor2.remove(Valor2.count()-1,1);
    ui->lineEdit->setText(Valor1);
    ui->lineEdit_2->setText(Valor2);
    ui->lineEdit_4->setText(Pos);
    drakeSistema drake;
    QString Explora = "find \"%1\"/.Sincrono";
    Explora = Explora.arg(ui->lineEdit_2->text());
    QString valor = drake.getStart(Explora);
    QStringList Value1 = valor.split("\n");
    if (Value1.count() <= 2)
    {
        ui->pushButton_15->setBackgroundColor(colorAnt);
        ui->pushButton_15->setEnabled(false);
    }
    else
    {
        color = QColor(Qt::yellow);
        ui->pushButton_15->setBackgroundColor(color);
        ui->pushButton_15->setEnabled(true);
    }
    if (Valor3 == "Si")
    {
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->checkBox->setChecked(false);
    }
    if (Valor4 == "Si")
    {
        ui->checkBox_2->setChecked(true);
    }
    else
    {
        ui->checkBox_2->setChecked(false);
    }
    if (Valor5 == "Si")
    {
        ui->checkBox_3->setChecked(true);
    }
    else
    {
        ui->checkBox_3->setChecked(false);
    }
    if (Value == 1)
    {
        this->on_pushButton_4_clicked();
    }
    else if (Value == 2)
    {
        Marca = 1;
        this->on_pushButton_4_clicked();
        this->on_pushButton_5_clicked();
    }
    else if (Value == 0)
    {
        ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
    }
    QString Valor10 = "ls -l -d \"%1\"";
    Valor10 = Valor10.arg(ui->lineEdit->text());
    QString Valor20 = "ls -l -d \"%1\"";
    Valor20 = Valor20.arg(ui->lineEdit_2->text());
    QString PermisosO = getPropietario(Valor10);
    QString PermisosD = getPropietario(Valor20);
    QStringList RestoO = PermisosO.split(" ");
    QStringList RestoD = PermisosD.split(" ");
    QString PermiO = RestoO.value(2);
    QString PermiD = RestoD.value(2);
    if (PermiO != "")
        ui->label_2->setText(tr("Propietario: ")+PermiO+"");
    if (PermiD != "")
        ui->label_4->setText(tr("Propietario: ")+PermiD+"");
    Omitir = Valor6;
    int Cantidad;
    QString Traspaso;
    QStringList Separar;
    QString Resto;    
    Traspaso = Omitir;
    Separar = Traspaso.split(";");
    Cantidad = Separar.count();
    Resto = QString::number(Cantidad);
    if (Omitir != "")
    {
        color = QColor(Qt::yellow);
        ui->pushButton_14->setBackgroundColor(color);
        ui->pushButton_14->setText(tr("Palabras filtradas: ")+Resto+"");
        ui->pushButton_14->setToolTip(Omitir);
    }
    else
    {
        ui->pushButton_14->setBackgroundColor(colorAnt);
        ui->pushButton_14->setText(tr("Filtrar palabras"));
        ui->pushButton_14->setToolTip(Omitir);
    }   
    if (Log == "S")
        log = "S";
    else
        log = "N";
}

void sincrono::Comprobar()
{
    if (ui->checkBox->isChecked())
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("ADVERTENCIA IMPORTANTE")),
                    QString::fromUtf8(tr("<center><b>PRECAUCION</center><p>"
                               "Si marcas esta opcion tienes que tener en cuenta que lo que no este en "
                               "el directorio origen sera borrado del destino, por lo que si has "
                               "introducido un directorio de destino que tiene varios directorios dentro de el, seran "
                               "borrados con la consiguiente perdida de los datos.<p>"
                               "Siempre debes utilizar un directorio nuevo con el mismo nombre del origen para "
                               "que no haya problemas como el comentado.<p>"
                               "<B>NOTA: Procede con mucha precaucion o no marques la opcion si no "
                               "sabes lo que estas haciendo.</B><p>"
                               "&iquest;Utilizar la opcion de borrado de archivos?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::No)
        {
            ui->checkBox->setChecked(false);
        }
    }
}

void sincrono::on_pushButton_clicked()
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

void sincrono::on_pushButton_3_clicked()
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
    drakeSistema drake;
    QString Explora, Compara1, Compara2, Resto1, Resto2;
    Compara1 = ui->lineEdit->text();
    Compara2 = fileNameDirectori;
    QStringList Comparando1, Comparando2;
    Comparando1 = Compara1.split("/");
    Comparando2 = Compara2.split("/");
    Resto1 = Comparando1.value(Comparando1.count()-1);
    Resto2 = Comparando2.value(Comparando2.count()-1);
    Explora = "find \"%1\"";
    Explora = Explora.arg(fileNameDirectori);
    QString valor = drake.getStart(Explora);
    QStringList Value = valor.split("\n");
    if (Value.count() > 2)
    {
        if (Resto1 != Resto2)
        {
            int respuesta = 0;
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("ADVERTENCIA IMPORTANTE")),
                        QString::fromUtf8(tr("<center><b>PRECAUCION</center><p>"
                                   "El directorio destino no esta vacio por lo que si aceptas esta opcion tienes que tener "
                                   "en cuenta que si marcas la opcion de \"Quitar eliminados en destino\" puedes borrar cosas "
                                   "muy importantes ya que los archivos que no esten en origen seran borrados, ademas de los "
                                   "directorios dentro de el, con la consiguiente perdida de datos.<p>"
                                   "Siempre debes utilizar un directorio nuevo o como minimo con el mismo nombre del origen para "
                                   "que no haya problemas como el comentado.<p>"
                                   "<B>NOTA: Procede con mucha precaucion o no aceptes la opcion \"si\" no "
                                   "sabes lo que estas haciendo.</B><p>"
                                   "&iquest;Utilizar el directorio destino seleccionado?")), QMessageBox::Ok, QMessageBox::No);
            if (respuesta == QMessageBox::No)
            {
                ui->lineEdit_2->setText("");
                ui->label_4->setText("");
                return;
            }
        }
        else
        {
            QColor color;
            drakeSistema drake;
            QString md1 = "find \"%1\" -name .Sincrono";
            md1 = md1.arg(ui->lineEdit_2->text());
            QString Valor1 = drake.getStart(md1);
            if (Valor1 == "")
            {
                ui->pushButton_15->setBackgroundColor(colorAnt);
                ui->pushButton_15->setEnabled(false);
            }
            else
            {
                color = QColor(Qt::yellow);
                ui->pushButton_15->setBackgroundColor(color);
                ui->pushButton_15->setEnabled(true);
            }
        }
    }
    ui->lineEdit_2->setText(fileNameDirectori);
}

QString sincrono::blkid()
{
    QProcess *procesoCut;
    QByteArray du;
    procesoCut=new QProcess(this);
    procesoCut->start("blkid");
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    du = procesoCut->readAllStandardOutput();
    delete procesoCut;
    QString res =  QString(du);
    res.chop(1);
    return res;
}

QString sincrono::getMount(QString Dev)
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "-l";
    procesoRPM->start("mount",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString Recuperar = QString(Paquete);
    QStringList Depurar = Recuperar.split("\n");
    QString res;
    for (int a=0;a<Depurar.count();a++)
    {
        QString Dato = Depurar.value(a);
        if (Dato.contains(Dev))
        {
            res = "Si";
            break;
        }
        else
        {
            res = "No";
        }
    }
    return res;
}

QString sincrono::getLocal(QString Dev)
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "-l";
    procesoRPM->start("mount",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString Recuperar = QString(Paquete);
    QStringList Depurar = Recuperar.split("\n");
    QString res;
    for (int a=0;a<Depurar.count();a++)
    {
        QString Dato = Depurar.value(a);
        if (Dato.contains(Dev))
        {
           QStringList Resto = Dato.split(" ");
           QString Dat = Resto.value(2);
           res = Dat;
           break;
        }
    }
    return res;
}

void sincrono::on_pushButton_4_clicked()
{
    ui->textEdit->setText("");
    int Cantidad;
    QString Traspaso;
    QStringList Separar;
    QString Resto;
    QColor color;    
    QSqlQuery Sincroniza(db);
    Sincroniza.exec("SELECT Codigo FROM Sincrono WHERE Referencia='"+ui->lineEdit_3->text()+"'");
    Sincroniza.first();
    Omitir = Sincroniza.value(0).toString();
    Traspaso = Omitir;
    Separar = Traspaso.split(";");
    Cantidad = Separar.count();
    Resto = QString::number(Cantidad);
    if (Omitir != "")
    {
        color = QColor(Qt::yellow);
        ui->pushButton_14->setBackgroundColor(color);
        ui->pushButton_14->setText(tr("Palabras filtradas: ")+Resto+"");
        ui->pushButton_14->setToolTip(Omitir);
    }
    else
    {
        ui->pushButton_14->setBackgroundColor(colorAnt);
        ui->pushButton_14->setText(tr("Filtrar palabras"));
        ui->pushButton_14->setToolTip(Omitir);
    }
    QString Valor20 = "find \"%1\"";
    Valor20 = Valor20.arg(ui->lineEdit_2->text());
    drakeSistema drake;
    QString valor = drake.getStart(Valor20);
    QStringList Comparar = valor.split("\n");
    if (valor == "")
    {
        if (ui->lineEdit_2->text().contains("/media"))
        {
            int Contador;
            QString Valorar, Value;
            Contador = 0;
            QStringList Valor = ui->lineEdit_2->text().split("/");
            Valorar = ui->lineEdit_2->text();
            if (Valorar.contains("/run"))
                Value = Valor.value(4);
            else
                Value = Valor.value(2);
            if (Valorar.contains("/media"))
            {
                QString Vblkid = blkid();
                QStringList vblkid = Vblkid.split("\n");
                for(int a=0;a<vblkid.count();a++)
                {
                    QString Rastreo = vblkid.value(a);
                    if (Rastreo.contains(Value))
                    {
                        QStringList Unidad = Rastreo.split(" ");
                        QString Dev = Unidad.value(0);
                        Dev = Dev.remove(":");
                        QString Mount = getMount(Dev);
                        if (Mount == "Si")
                        {
                            int Resto = 0;
                            QString Valorado;
                            QString Definitivo = getLocal(Dev);
                            QString Depurar = ui->lineEdit_2->text();
                            QStringList Depurado = Depurar.split("/");
                            for (int i=0;i<Depurado.count();i++)
                            {
                                if (Depurado.value(i) == Value)
                                {
                                    Resto = i+1;
                                    break;
                                }
                            }
                            for (int b=Resto;b<Depurado.count();b++)
                            {
                                Valorado.append("/"+Depurado.value(b)+"");
                            }
                            Depurar = ""+Definitivo+""+Valorado+"";
                            ui->lineEdit_2->setText(Depurar);
                            Contador = 1;                          
                            if (Comparar.value(0) != ui->lineEdit_2->text())
                            {
                                ui->textEdit->append(tr("<FONT COLOR=\"RED\">...En analisis: La ruta introducida en destino no existe. Comprueba la accesibilidad de la misma."));
                                return;
                            }
                            break;
                        }
                        else if (Mount == "No")
                        {
                            QMessageBox m;
                            if (Stilo == "A")
                                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                            m.setText(tr("No esta montada la unidad destino, por lo que debes montarla antes de utilizar la sincronizacion."));
                            m.exec();
                            return;
                        }
                    }
                }                
            }
            if (Contador == 0)
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("No has introducido la ruta correcta de destino o no es accesible."));
                m.exec();
                return;
            }
        }
        else
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No has introducido la ruta correcta de destino o no es accesible."));
            m.exec();
            return;
        }
    }
    if (Comparar.value(0) != ui->lineEdit_2->text())
    {
        ui->textEdit->append(tr("<FONT COLOR=\"RED\">...En analisis: La ruta introducida en destino no existe. Comprueba la accesibilidad de la misma."));
        return;
    }
    QString Valor21 = "find \"%1\"";
    Valor21 = Valor21.arg(ui->lineEdit->text());
    QString valor1 = drake.getStart(Valor21);
    if (valor1 == "")
    {
        if (ui->lineEdit->text().contains("/media"))
        {
            int Contador;
            QString Valorar, Value;
            Contador = 0;
            QStringList Valor = ui->lineEdit->text().split("/");
            Valorar = ui->lineEdit->text();
            if (Valorar.contains("/run"))
                Value = Valor.value(4);
            else
                Value = Valor.value(2);
            if (Valorar.contains("/media"))
            {
                QString Vblkid = blkid();
                QStringList vblkid = Vblkid.split("\n");
                for(int a=0;a<vblkid.count();a++)
                {
                    QString Rastreo = vblkid.value(a);
                    if (Rastreo.contains(Value))
                    {
                        QStringList Unidad = Rastreo.split(" ");
                        QString Dev = Unidad.value(0);
                        Dev = Dev.remove(":");
                        QString Mount = getMount(Dev);
                        if (Mount == "Si")
                        {
                            int Resto = 0;
                            QString Valorado;
                            QString Definitivo = getLocal(Dev);
                            QString Depurar = ui->lineEdit->text();
                            QStringList Depurado = Depurar.split("/");
                            for (int i=0;i<Depurado.count();i++)
                            {
                                if (Depurado.value(i) == Value)
                                {
                                    Resto = i+1;
                                    break;
                                }
                            }
                            for (int b=Resto;b<Depurado.count();b++)
                            {
                                Valorado.append("/"+Depurado.value(b)+"");
                            }
                            Depurar = ""+Definitivo+""+Valorado+"";
                            ui->lineEdit->setText(Depurar);
                            Contador = 1;
                            break;
                        }
                        else if (Mount == "No")
                        {
                            QMessageBox m;
                            if (Stilo == "A")
                                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                            m.setText(tr("No esta montada la unidad origen, por lo que debes montarla antes de utilizar la sincronizacion."));
                            m.exec();
                            return;
                        }
                    }
                }
            }
            if (Contador == 0)
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("No has introducido la ruta correcta de origen o no es accesible."));
                m.exec();
                return;
            }
        }
        else
        {
            if (ui->lineEdit->text() == "")
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("No has introducido la ruta correcta de origen."));
                m.exec();
                return;
            }
        }
    }
    ui->tableWidget_2->setSortingEnabled(false);
    ui->pushButton_7->setText(tr("Todos"));
    ui->pushButton_8->setText(tr("Iguales"));
    ui->pushButton_9->setText(tr("Cambios"));
    ui->pushButton_2->setText(tr("Nuevos"));
    ui->pushButton_13->setText(tr("Eliminados"));
    Evento = 0;
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
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
    ui->pushButton_15->setEnabled(false);    
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    Contad->stop();
    Value = 1;
    int Borrado, x;
    Borrado = ui->tableWidget_2->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget_2->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    int iFilas;
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
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_13->setEnabled(false);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(false);        
        ui->pushButton_14->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_10->setEnabled(true);
        ui->pushButton_11->setEnabled(true);
        ui->pushButton_12->setEnabled(true);
        Contad->start(5000);
        Value = 0;
        return;
    }
    int Posibilidad = 0;
    QString Destino = drake.getDu(ui->lineEdit_2->text());
    QStringList listaArchivos = Objetivo.split("\n");    
    QStringList listaDestino = Destino.split("\n");
    Omitir = Omitir.remove(" ");
    QStringList Omite = Omitir.split(";");
    ui->progressBar->setRange(0,listaArchivos.count());
    ui->progressBar->setTextVisible(true);
    ui->progressBar->setFormat(tr("Analizando objetivos... %p%"));
    ui->textEdit->append(tr("Iniciando analisis de objetivos"));
    QTest::qWait(20);
    for(int i=1;i<listaArchivos.count();i++)
    {
        qApp->processEvents();
        if (Evento == 1)
        {
            ui->progressBar->setRange(0,100);
            ui->progressBar->setValue(0);
            ui->progressBar->setFormat("%p%");
            ui->pushButton_7->setEnabled(false);
            ui->pushButton_8->setEnabled(false);
            ui->pushButton_9->setEnabled(false);
            ui->pushButton_2->setEnabled(false);
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_4->setEnabled(true);
            ui->pushButton_5->setEnabled(true);
            ui->pushButton_6->setEnabled(false);            
            ui->pushButton_14->setEnabled(true);
            ui->pushButton_15->setEnabled(true);
            ui->pushButton_10->setEnabled(true);
            ui->pushButton_11->setEnabled(true);
            ui->pushButton_12->setEnabled(true);
            Contad->start(5000);
            int Borrado, x;
            Borrado = ui->tableWidget_2->rowCount();
            for(x=0;x<Borrado;x++)
            {
                 ui->tableWidget_2->removeRow(x);
                 x=x-1;
                 Borrado=Borrado-1;
            }
            ui->textEdit->append(tr("Trabajo cancelado"));
            Evento = 0;
            Value = 0;
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
        if (Omitir != "")
        {
            for(int A=0;A<Omite.count();A++)
            {
                QString ValorOmit = QFileInfo(file).fileName();
                QString ValorDir = QFileInfo(file).absoluteFilePath();
                QString ValorLoc = Omite.value(A);
                if (ValorLoc.contains("DIR:"))
                {
                    ValorLoc.remove("DIR:");
                    if (ValorDir.contains(ValorLoc))
                    {
                        Posibilidad=1;
                        break;
                    }
                    else
                        Posibilidad=0;
                }
                else
                {
                    if (ValorOmit.contains(ValorLoc))
                    {
                        Posibilidad=1;
                        break;
                    }
                    else
                        Posibilidad=0;
                }
            }
        }
        else
            Posibilidad = 0;
        if (Posibilidad == 0)
        {
            if (ruta.contains(".Sincrono") == false)
            {
                QString Buscar = ruta;
                if (ui->checkBox_3->isChecked() == false)
                {
                    QString Value = QFileInfo(file).absoluteFilePath();
                    if (Value.contains("/.") == false)
                    {
                        item1->setText(QFileInfo(file).fileName());
                        item2->setText(QString::fromUtf8(ruta.remove(ui->lineEdit->text())));
                        ui->progressBar->setFormat(""+Value+"... %p%");
                        ui->textEdit->append(tr("Analizando...")+Value+"");
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
                                                            item6->setText(tr("Modificado"));
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
                                            item6->setText(tr("Modificado"));
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
                            item6->setText(tr("Nuevo"));
                            item7->setText("");
                            item8->setText("");
                            item9->setText("");
                            item10->setText("");
                        }
                        QString valor;
                        if (item6->text() == tr("Sin cambios"))
                        {
                            if (ui->checkBox_4->isChecked() == false)
                            {
                                if (item6->text() == tr("Sin cambios"))
                                    valor = ":/Imagenes/thumbs_up.png";
                                else if (item6->text() == tr("Modificado"))
                                    valor = ":/Imagenes/Error.png";
                                else if (item6->text() == tr("Nuevo"))
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
                            }
                        }
                        else
                        {
                            if (item6->text() == tr("Modificado"))
                                valor = ":/Imagenes/Error.png";
                            else if (item6->text() == tr("Nuevo"))
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
                        }
                    }
                    ui->progressBar->setValue(i);
                }
                else
                {
                    QString Value = QFileInfo(file).absoluteFilePath();
                    item1->setText(QFileInfo(file).fileName());
                    item2->setText(QString::fromUtf8(ruta.remove(ui->lineEdit->text())));
                    ui->progressBar->setFormat(""+Value+"... %p%");
                    ui->textEdit->append(tr("Analizando...")+Value+"");
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
                                                        item6->setText(tr("Modificado"));
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
                                        item6->setText(tr("Modificado"));
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
                        item6->setText(tr("Nuevo"));
                        item7->setText("");
                        item8->setText("");
                        item9->setText("");
                        item10->setText("");
                    }
                    QString valor;
                    if (item6->text() == tr("Sin cambios"))
                    {
                        if (ui->checkBox_4->isChecked() == false)
                        {
                            if (item6->text() == tr("Sin cambios"))
                                valor = ":/Imagenes/thumbs_up.png";
                            else if (item6->text() == tr("Modificado"))
                                valor = ":/Imagenes/Error.png";
                            else if (item6->text() == tr("Nuevo"))
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
                        }
                    }
                    else
                    {
                        if (item6->text() == tr("Modificado"))
                            valor = ":/Imagenes/Error.png";
                        else if (item6->text() == tr("Nuevo"))
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
                    }
                }
                ui->progressBar->setValue(i);
            }
        }
    }
    ui->progressBar->setValue(listaArchivos.count());
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    ui->progressBar->setFormat("%p%");
    if (ui->checkBox_5->isChecked())
    {
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
                ui->pushButton_7->setEnabled(false);
                ui->pushButton_8->setEnabled(false);
                ui->pushButton_9->setEnabled(false);
                ui->pushButton_2->setEnabled(false);
                ui->pushButton_13->setEnabled(false);
                ui->pushButton_4->setEnabled(true);
                ui->pushButton_5->setEnabled(true);
                ui->pushButton_6->setEnabled(false);
                ui->pushButton_14->setEnabled(true);
                ui->pushButton_15->setEnabled(true);
                ui->pushButton_10->setEnabled(true);
                ui->pushButton_11->setEnabled(true);
                ui->pushButton_12->setEnabled(true);
                Contad->start(5000);
                int Borrado, x;
                Borrado = ui->tableWidget_2->rowCount();
                for(x=0;x<Borrado;x++)
                {
                     ui->tableWidget_2->removeRow(x);
                     x=x-1;
                     Borrado=Borrado-1;
                }
                ui->textEdit->append(tr("Trabajo cancelado"));
                Evento = 0;
                Value = 0;
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
            if (ruta.contains(".Sincrono") == false)
            {
                QFile file(ruta);
                QString Buscar = ruta;
                QString Value = QFileInfo(file).absoluteFilePath();
                item7->setText(QFileInfo(file).fileName());
                item8->setText(QString::fromUtf8(ruta.remove(ui->lineEdit_2->text())));
                ui->progressBar->setFormat(""+Value+" ... %p%");
                ui->textEdit->append(tr("Analizando...")+Value+"");
                item9->setText(QString::number(QFileInfo(file).size()));
                QDateTime Fecha = QFileInfo(file).lastModified();
                item10->setText(Fecha.toString());
                drakeSistema drake;
                QString tipo = drake.getTipo(Buscar);
                QStringList Tipo = tipo.split(":");
                QString tipe = Tipo.value(1);
                QStringList result;
                result = listaArchivos.filter(ruta);
                if (result.count() == 0)
                {
                    item6->setText(tr("Eliminado"));
                    item1->setText("");
                    item2->setText("");
                    item3->setText("");
                    item4->setText("");
                    if (tipe.contains("directory"))
                    {
                        item5->setText(tr("Directorio"));
                        item4->setText("");
                    }
                    else
                        item5->setText(tr("Archivo"));
                }
                else if (result.count() == 1)
                {
                    if (tipe.contains("directory"))
                    {
                        QString Compara1, Resto1;
                        Compara1 = result.value(0);
                        QStringList Comparando1;
                        Comparando1 = Compara1.split("/");
                        Resto1 = Comparando1.value(Comparando1.count()-1);
                        if (item7->text() != Resto1)
                        {
                            item6->setText(tr("Eliminado"));
                            item1->setText("");
                            item2->setText("");
                            item3->setText("");
                            item4->setText("");
                            item5->setText(tr("Directorio"));
                            item4->setText("");
                        }
                    }
                }
                if (item6->text() == tr("Eliminado"))
                {
                    if (! item8->text().contains("/.Sincrono"))
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
                }
                ui->progressBar->setValue(i);
            }
        }
        ui->progressBar->setValue(listaDestino.count());
        ui->progressBar->setRange(0,100);
        ui->progressBar->setValue(0);
        ui->progressBar->setFormat("%p%");
    }
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(false);
    ui->tableWidget_2->setSortingEnabled(true);
    ui->tableWidget_2->sortByColumn(1,Qt::AscendingOrder);
    ui->textEdit->append(tr("Finalizado analisis de objetivos"));
    ui->textEdit->append("");
    ui->textEdit->append(tr(":::RESULTADO DEL ANALISIS:::"));
    ui->textEdit->append("");
    int Contador = ui->tableWidget_2->rowCount();
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_13->setEnabled(true);
    ui->pushButton_14->setEnabled(true);
    ui->pushButton_15->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    ui->pushButton_11->setEnabled(true);
    ui->pushButton_12->setEnabled(true);
    ui->pushButton_7->setText(tr("Todos (")+QString::number(Contador)+")");
    ui->textEdit->append(tr("Archivos totales: ")+QString::number(Contador)+"");    
    itemsa = ui->tableWidget_2->findItems(tr("Sin cambios") , Qt::MatchExactly);
    ui->pushButton_8->setText(tr("Iguales (")+QString::number(itemsa.count())+")");
    if (itemsa.count() == 0)
        ui->pushButton_8->setEnabled(false);
    ui->textEdit->append(tr("Archivos iguales: ")+QString::number(itemsa.count())+"");
    items1 = ui->tableWidget_2->findItems(tr("Modificado") , Qt::MatchExactly);
    ui->pushButton_9->setText(tr("Cambios (")+QString::number(items1.count())+")");
    if (items1.count() == 0)
        ui->pushButton_9->setEnabled(false);
    ui->textEdit->append(tr("Archivos modificados: ")+QString::number(items1.count())+"");
    items = ui->tableWidget_2->findItems(tr("Nuevo") , Qt::MatchExactly);
    ui->pushButton_2->setText(tr("Nuevos (")+QString::number(items.count())+")");
    if (items.count() == 0)
        ui->pushButton_2->setEnabled(false);
    ui->textEdit->append(tr("Archivos nuevos: ")+QString::number(items.count())+"");
    items2 = ui->tableWidget_2->findItems(tr("Eliminado") , Qt::MatchExactly);
    ui->pushButton_13->setText(tr("Eliminados (")+QString::number(items2.count())+")");
    if (items2.count() == 0)
        ui->pushButton_13->setEnabled(false);
    ui->textEdit->append(tr("Archivos eliminados: ")+QString::number(items2.count())+"");
    ui->textEdit->append("");
    Sincronizador = 1;
    if (Contador == items.count())
        NoSincro = 1;
    else
        NoSincro = 0;
    if (log == "S")
    {
        system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
    }
    ui->tableWidget_2->resizeColumnsToContents();
    ui->tableWidget_2->resizeRowsToContents();
    Contad->start(5000);
    Value = 0;
    int Total = items1.count()+items.count()+items2.count();
    if (Total == 0)
        Counter = 1;
    else
        Counter = 0;
    if (Contador == 0)
    {
        ContadorC = 1;
        ui->pushButton_7->setEnabled(false);
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay nada que sincronizar en ")+ui->lineEdit_3->text()+tr(", todo esta correcto."));
        m.exec();
        return;
    }
    else
        ContadorC = 0;
}

void sincrono::on_pushButton_6_clicked()
{
    Evento = 1;
    if (mib != 0)
    {
        mib->killProceso();
        disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
        disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
        disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
        disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
        mib = 0;
    }
    ui->progressBar->setValue(0);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_14->setEnabled(true);
    ui->pushButton_15->setEnabled(true);
    if (Marca == 1)
        Marca = 0;
    Counter = 0;
    ContadorC = 0;
    Value = 0;
}

void sincrono::on_pushButton_8_clicked()
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

void sincrono::on_pushButton_9_clicked()
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

void sincrono::on_pushButton_2_clicked()
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

void sincrono::on_pushButton_7_clicked()
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

void sincrono::on_pushButton_13_clicked()
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

void sincrono::on_pushButton_11_clicked()
{
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
    QSqlQuery Compara(db);
    Compara.exec("SELECT Objetivo,Destino FROM Sincrono WHERE Objetivo='"+ui->lineEdit->text()+"' AND Destino='"+ui->lineEdit_2->text()+"'");
    Compara.first();
    QString Comparacion = Compara.value(0).toString();
    if (Comparacion == ui->lineEdit->text())
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("El objetivo que quiere guardar ya esta creado."));
        m.exec();
        return;
    }
    QString Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos;
    int cantidad;
    QSqlQuery Pos(db);
    Pos.exec("SELECT id FROM Sincrono");
    Pos.last();
    if (Pos.isSelect())
        cantidad = Pos.value(0).toInt();
    if (ui->lineEdit_3->text() == "")
        Referencia = "Objetivo "+QString::number(cantidad+1)+"";
    else
        Referencia = ui->lineEdit_3->text();
    Objetivo = ui->lineEdit->text();
    Destino = ui->lineEdit_2->text();
    if (ui->checkBox->isChecked() == true)
        Eliminar = "Si";
    else
        Eliminar = "No";
    if (ui->checkBox_2->isChecked() == true)
        Comprobar = "Si";
    else
        Comprobar = "No";
    if (ui->checkBox_3->isChecked() == true)
        Ocultos = "Si";
    else
        Ocultos = "No";
    QSqlQuery Wdark(db);
    Wdark.prepare("INSERT INTO Sincrono (Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Codigo)"
                  "VALUES (:Referencia,:Objetivo,:Destino,:Eliminar,:Comprobar,:Ocultos,:Codigo)");
    Wdark.bindValue(":Referencia", Referencia);
    Wdark.bindValue(":Objetivo", Objetivo);
    Wdark.bindValue(":Destino", Destino);
    Wdark.bindValue(":Eliminar", Eliminar);
    Wdark.bindValue(":Comprobar", Comprobar);
    Wdark.bindValue(":Ocultos", Ocultos);
    Wdark.bindValue(":Codigo", "");
    Wdark.exec();    
    emit Terminado(0,ui->lineEdit_3->text());
}

void sincrono::on_pushButton_12_clicked()
{
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Borrar sincronizacion")),
                           QString::fromUtf8(tr("<center><b>Borrado de sincronizacion guardada<b></center><p>"
                           "&iquest;Estas seguro de que quieres borrar la sincronizacion seleccionada?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        QSqlQuery query(db);
        query.exec("DELETE FROM Sincrono WHERE Objetivo='"+ui->lineEdit->text()+"' AND Destino='"+ui->lineEdit_2->text()+"'");
        emit Terminado(1,"");
    }
}

void sincrono::on_pushButton_10_clicked()
{
    QString Referencia,Objetivo,Destino,Eliminar,Comprobar,Ocultos,Final;
    QSqlQuery Compara(db);
    Compara.exec("SELECT Referencia FROM Sincrono WHERE Id='"+ui->lineEdit_4->text()+"'");
    Compara.first();
    Referencia = Compara.value(0).toString();
    if (Referencia == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se puede modificar el objetivo y el destino. Crea un proyecto nuevo."));
        m.exec();
        return;
    }
    if (ui->lineEdit_3->text() == "")
        Final = Referencia;
    else
        Final = ui->lineEdit_3->text();
    Objetivo = ui->lineEdit->text();
    Destino = ui->lineEdit_2->text();
    if (ui->checkBox->isChecked() == true)
        Eliminar = "Si";
    else
        Eliminar = "No";
    if (ui->checkBox_2->isChecked() == true)
        Comprobar = "Si";
    else
        Comprobar = "No";
    if (ui->checkBox_3->isChecked() == true)
        Ocultos = "Si";
    else
        Ocultos = "No";
    QSqlQuery Actualiza(db);
    Actualiza.exec("UPDATE Sincrono SET Referencia='"+Final+"',Objetivo='"+Objetivo+"',Destino='"+Destino+"',Eliminar='"+Eliminar+"',Comprobar='"+Comprobar+"',Ocultos='"+Ocultos+"' WHERE Referencia='"+Referencia+"'");
    emit Terminado(0,ui->lineEdit_3->text());
}

void sincrono::on_pushButton_5_clicked()
{
    if (Evento == 1)
    {
        Marca = 0;
        Counter = 0;
        ContadorC= 0;
        Evento=0;
        return;
    }
    if (Marca == 1)
    {
        if (Counter == 1)
        {
            if (ContadorC == 1)
            {
                Evento = 0;
                Marca = 0;
                Counter = 0;
                ContadorC= 0;
                return;
            }
        }
    }
    this->on_pushButton_7_clicked();
    QString Root = ui->lineEdit_2->text();
    int Contador = ui->tableWidget_2->rowCount();
    QList<QTableWidgetItem *> items = ui->tableWidget_2->findItems(tr("Sin cambios") , Qt::MatchExactly);
    if (Contador == items.count())
    {
        if (Contador > 0)
        {
            int respuesta = 0;
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Nueva Sincronizacion")),
                                   QString::fromUtf8(tr("<center><b>Sincronizacion<b></center><p>"
                                   "No hay nada que sincronizar en ")+ui->lineEdit_3->text()+tr(", todo esta correcto.<p>"
                                   "Si quieres volver a analizar y sincronizar, lo puedes hacer tambien.<p>"
                                   "&iquest;Volver a analizar y sincronizar?")), QMessageBox::Ok, QMessageBox::No);
            if (respuesta == QMessageBox::Ok)
            {
                Marca = 0;
                Counter = 0;
                ContadorC= 0;
                Evento = 0;
                int Borrado, x;
                Borrado = ui->tableWidget_2->rowCount();
                for(x=0;x<Borrado;x++)
                {
                     ui->tableWidget_2->removeRow(x);
                     x=x-1;
                     Borrado=Borrado-1;
                }
                Marca = 1;
                this->on_pushButton_5_clicked();
                return;
            }
        }
    }
    int Cantidad;
    Cantidad = ui->tableWidget_2->rowCount();
    if (Cantidad <= 0)
    {
        QString Valor20 = "find \"%1\"";
        Valor20 = Valor20.arg(ui->lineEdit_2->text());
        drakeSistema drake;
        QString valor = drake.getStart(Valor20);
        QStringList Comparar = valor.split("\n");
        if (valor == "")
        {
            Contador = 0;
            QString Valorar, Value;
            QStringList Valor = ui->lineEdit_2->text().split("/");
            Valorar = ui->lineEdit_2->text();
            if (Valorar.contains("/run"))
                Value = Valor.value(4);
            else
                Value = Valor.value(2);
            if (Valorar.contains("/media"))
            {
                QString Vblkid = blkid();
                QStringList vblkid = Vblkid.split("\n");
                for(int a=0;a<vblkid.count();a++)
                {
                    QString Rastreo = vblkid.value(a);
                    if (Rastreo.contains(Value))
                    {
                        QStringList Unidad = Rastreo.split(" ");
                        QString Dev = Unidad.value(0);
                        Dev = Dev.remove(":");
                        QString Mount = getMount(Dev);
                        if (Mount == "Si")
                        {
                            int Resto = 0;
                            QString Valorado;
                            QString Definitivo = getLocal(Dev);
                            QString Depurar = ui->lineEdit_2->text();
                            QStringList Depurado = Depurar.split("/");
                            for (int i=0;i<Depurado.count();i++)
                            {
                                if (Depurado.value(i) == Value)
                                {
                                    Resto = i+1;
                                    break;
                                }
                            }
                            for (int b=Resto;b<Depurado.count();b++)
                            {
                                Valorado.append("/"+Depurado.value(b)+"");
                            }
                            Depurar = ""+Definitivo+""+Valorado+"";
                            ui->lineEdit_2->setText(Depurar);
                            Contador = 1;                            
                            if (Comparar.value(0) != ui->lineEdit_2->text())
                            {
                                ui->textEdit->append(tr("<FONT COLOR=\"RED\">...En sincronizacion: La ruta introducida en destino no existe. Comprueba la accesibilidad de la misma."));
                                Marca = 0;
                                Counter = 0;
                                ContadorC= 0;
                                return;
                            }
                            break;
                        }
                        else if (Mount == "No")
                        {
                            QMessageBox m;
                            if (Stilo == "A")
                                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                            m.setText(tr("No esta montada la unidad destino, por lo que debes montarla antes de utilizar la sincronizacion."));
                            m.exec();
                            Marca = 0;
                            Counter = 0;
                            ContadorC= 0;
                            return;
                        }
                    }
                }
            }
            else
                Contador = 1;
        }
        else
            Contador = 1;
        if (Contador == 0)
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No has introducido la ruta correcta de destino o no es accesible."));
            m.exec();
            Evento = 0;
            Marca = 0;
            Counter = 0;
            ContadorC= 0;
            return;
        }
        else
        {
            Marca = 1;
            this->on_pushButton_4_clicked();
            if (Counter == 1)
            {
                if (ContadorC == 1)
                {
                    Evento = 0;
                    Marca = 0;
                    Counter = 0;
                    ContadorC= 0;
                    return;
                }
            }
            else
            {
                if (log == "S")
                {
                    system(QString::fromUtf8("echo '"+ui->textEdit->text()+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
                }
                if (Sincronizador == 1)
                    this->on_pushButton_5_clicked();
                Evento = 0;
                Marca = 0;
                Counter = 0;
                ContadorC= 0;
                return;
            }
        }
    }
    QString Valor20 = "find \"%1\"";
    Valor20 = Valor20.arg(ui->lineEdit_2->text());
    drakeSistema drake;
    QString value = drake.getStart(Valor20);
    QStringList Comparar = value.split("\n");
    if (Comparar.value(0) != ui->lineEdit_2->text())
    {
        ui->textEdit->append(tr("<FONT COLOR=\"RED\">...En sincronizacion: La ruta introducida en destino no existe. Comprueba la accesibilidad de la misma."));
        Marca = 0;
        Counter = 0;
        ContadorC= 0;
        Evento = 0;
        return;
    }
    ui->textEdit->append("");
    ui->textEdit->append(tr("Iniciando sincronizacion de objetivos"));
    ui->tableWidget_2->sortByColumn(1,Qt::AscendingOrder);
    QStringList comandos;
    TotalProceso = 0;
    Comprueba = "Si";
    if (ui->lineEdit->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has definido una ruta fuente para poder marcar objetivos."));
        m.exec();
        Marca = 0;
        Counter = 0;
        ContadorC= 0;
        Evento = 0;
        return;
    }
    if (ui->lineEdit_2->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has definido una ruta destino para poder comparar objetivos."));
        m.exec();
        Marca = 0;
        Counter = 0;
        ContadorC= 0;
        Evento = 0;
        return;
    }
    else
    {
        if (Comparar.value(0) != ui->lineEdit_2->text())
        {
            ui->textEdit->append(tr("<FONT COLOR=\"RED\">...En sincronizacion: La ruta introducida en destino no existe. Comprueba la accesibilidad de la misma."));
            Marca = 0;
            Counter = 0;
            ContadorC= 0;
            Evento = 0;
            return;
        }
    }
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_13->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
    ui->pushButton_15->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->pushButton_11->setEnabled(false);
    ui->pushButton_12->setEnabled(false);
    Value = 1;
    QString fileOrigen = ui->lineEdit->text().replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    QString fileDestino = ui->lineEdit_2->text().replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
    QString Valor1 = "ls -l -d \"%1\"";
    Valor1 = Valor1.arg(ui->lineEdit->text());
    QString Valor2 = "ls -l -d \"%1\"";
    Valor2 = Valor2.arg(ui->lineEdit_2->text());
    QString PermisosO = getPropietario(Valor1);
    QString PermisosD = getPropietario(Valor2);
    QStringList RestoO = PermisosO.split(" ");
    QStringList RestoD = PermisosD.split(" ");
    QString PermiO = RestoO.value(2);
    QString PermiD = RestoD.value(2);
    if (NoSincro == 0)
    {
        if (ui->checkBox_2->isChecked())
        {
            drakeSistema drake;
            QString md1 = "find \"%1/.Sincrono\"";
            md1 = md1.arg(ui->lineEdit_2->text());
            QString Buscar = drake.getStart(md1);
            if (Buscar == "")
            {
                QString cm;
                QString Valor1;
                drakeSistema drake;
                QString md1 = "find \"%1\" -name .Sincrono";
                md1 = md1.arg(ui->lineEdit_2->text());
                Valor1 = drake.getStart(md1);
                if (Valor1 == "")
                {
                    if (Root.contains("root") || PermiO.contains("root") || PermiD.contains("root"))
                    {
                        cm = "su -c \"mkdir %1/.Sincrono\"";
                        cm = cm.arg(fileDestino);
                    }
                    else
                    {
                        cm = "su - "+user+" -c \"mkdir %1/.Sincrono\"";
                        cm = cm.arg(fileDestino);
                    }
                    comandos << cm;                    
                }
            }
        }
    }
    QString RutaObj, Estado, RutaDest, Tipo;
    QTableWidgetItem *item2,*item5,*item6,*item8;
    item2=new QTableWidgetItem;
    item5=new QTableWidgetItem;
    item6=new QTableWidgetItem;
    item8=new QTableWidgetItem;
    int Update, x;
    Update = ui->tableWidget_2->rowCount();    
    for(x=0;x<Update;x++)
    {
        qApp->processEvents();
        if (Evento == 1)
        {
            ui->progressBar->setRange(0,100);
            ui->progressBar->setValue(0);
            ui->progressBar->setFormat("%p%");
            ui->pushButton_7->setEnabled(false);
            ui->pushButton_8->setEnabled(false);
            ui->pushButton_9->setEnabled(false);
            ui->pushButton_2->setEnabled(false);
            ui->pushButton_13->setEnabled(false);
            ui->pushButton_4->setEnabled(true);
            ui->pushButton_5->setEnabled(true);
            ui->pushButton_6->setEnabled(false);
            ui->pushButton_14->setEnabled(true);
            ui->pushButton_15->setEnabled(true);
            ui->pushButton_10->setEnabled(true);
            ui->pushButton_11->setEnabled(true);
            ui->pushButton_12->setEnabled(true);
            int Borrado, x;
            Borrado = ui->tableWidget_2->rowCount();
            for(x=0;x<Borrado;x++)
            {
                 ui->tableWidget_2->removeRow(x);
                 x=x-1;
                 Borrado=Borrado-1;
            }
            ui->textEdit->append(tr("Trabajo cancelado"));
            Evento = 0;
            Value = 0;
            Marca = 0;
            Counter = 0;
            ContadorC= 0;
            return;
        }
        item2 = ui->tableWidget_2->item(x,1);
        item5 = ui->tableWidget_2->item(x,4);
        item6 = ui->tableWidget_2->item(x,5);
        item8 = ui->tableWidget_2->item(x,7);
        RutaObj=item2->text();
        Tipo=item5->text();
        Estado=item6->text();
        RutaDest=item8->text();
        QString Crear= "";
        QString Origen = RutaObj;
        QString Destino = RutaDest;
        RutaObj = RutaObj.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
        RutaDest = RutaDest.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
        if (Estado == tr("Nuevo"))
        {
            QString cm1;
            if (Tipo == tr("Directorio"))
            {
                drakeSistema drake;
                QString Valor = "ls -ld \"%1%2\"";
                Valor = Valor.arg(ui->lineEdit_2->text()).arg(RutaObj);
                QString Buscar = drake.getStart(Valor);
                if (Buscar == "")
                {
                    if (Root.contains("root") || PermiO.contains("root") || PermiD.contains("root"))
                    {
                        cm1 = "su -c \"mkdir %1%2\"";
                        cm1 = cm1.arg(fileDestino).arg(RutaObj);
                    }
                    else
                    {
                        cm1 = "su - "+user+" -c \"mkdir %1%2\"";
                        cm1 = cm1.arg(fileDestino).arg(RutaObj);
                    }
                }
            }
            else if (Tipo == tr("Archivo"))
            {
                if (Root.contains("root") || PermiO.contains("root") || PermiD.contains("root"))
                {
                    cm1 = "su -c \"cp --preserve=mode,timestamps -v %1%2 %3%2\"";
                    cm1=cm1.arg(fileOrigen).arg(RutaObj).arg(fileDestino);
                }
                else
                {
                    cm1 = "su - "+user+" -c \"cp --preserve=mode,timestamps -v %1%2 %3%2\"";
                    cm1=cm1.arg(fileOrigen).arg(RutaObj).arg(fileDestino);
                }
            }
            comandos << cm1;
        }
        if (Estado == tr("Modificado"))
        {
            QString cm;
            if (NoSincro == 0)
            {
                if (ui->checkBox_2->isChecked())
                {
                    QStringList Parte1 = Origen.split("/");
                    if (Parte1.count() >= 3)
                    {
                        for (int i=1;i<Parte1.count()-1;i++)
                        {
                            QString Value = Parte1.value(i);
                            Crear.append(""+Value+"/");
                        }
                        QString Comprobar = Crear;
                        Comprobar = Comprobar.remove("/");
                        drakeSistema drake;
                        QString md1 = "find \"%1/.Sincrono\" -name %2";
                        md1 = md1.arg(ui->lineEdit_2->text()).arg(Comprobar);
                        Valor1 = drake.getStart(md1);
                        if (Valor1 == "")
                        {
                            QString cm1;
                            if (Root.contains("root") || PermiO.contains("root") || PermiD.contains("root"))
                            {
                                cm1 = "su -c \"mkdir -p %1/.Sincrono/%2\"";
                                cm1 = cm1.arg(fileDestino).arg(Crear);
                            }
                            else
                            {
                                cm1 = "su - "+user+" -c \"mkdir -p %1/.Sincrono/%2\"";
                                cm1 = cm1.arg(fileDestino).arg(Crear);
                            }
                            comandos << cm1;
                        }
                    }
                    if (Root.contains("root") || PermiO.contains("root") || PermiD.contains("root"))
                    {
                        cm = "su -c \"cp --preserve=mode,timestamps %1%2 %1/.Sincrono%2\"";
                        cm = cm.arg(fileDestino).arg(RutaDest);
                    }
                    else
                    {
                        cm = "su - "+user+" -c \"cp --preserve=mode,timestamps %1%2 %1/.Sincrono%2\"";
                        cm = cm.arg(fileDestino).arg(RutaDest);
                    }
                    comandos << cm;                    
                }
            }
            QString cm1;
            if (Root.contains("root") || PermiO.contains("root") || PermiD.contains("root"))
            {
                cm1 = "su -c \"cp --preserve=mode,timestamps -v %1%2 %3%2\"";
                cm1=cm1.arg(fileOrigen).arg(RutaObj).arg(fileDestino);
            }
            else
            {
                cm1 = "su - "+user+" -c \"cp --preserve=mode,timestamps -v %1%2 %3%2\"";
                cm1=cm1.arg(fileOrigen).arg(RutaObj).arg(fileDestino);
            }
            comandos << cm1;
        }
        if (Estado == tr("Eliminado"))
        {
            QString cm, cm1;
            if (ui->checkBox->isChecked())
            {
                if (NoSincro == 0)
                {
                    if (ui->checkBox_2->isChecked())
                    {
                        QStringList Parte1 = Destino.split("/");
                        if (Parte1.count() >= 3)
                        {
                            for (int i=1;i<Parte1.count()-1;i++)
                            {
                                QString Value = Parte1.value(i);
                                Crear.append(""+Value+"/");
                            }
                            QString Comprobar = Crear;
                            Comprobar = Comprobar.remove("/");
                            drakeSistema drake;
                            QString md1 = "find \"%1/.Sincrono\" -name %2";
                            md1 = md1.arg(ui->lineEdit_2->text()).arg(Comprobar);
                            Valor1 = drake.getStart(md1);
                            if (Valor1 == "")
                            {
                                QString cm1;
                                if (Root.contains("root") || PermiO.contains("root") || PermiD.contains("root"))
                                {
                                    cm1 = "su -c \"mkdir -p %1/.Sincrono/%2\"";
                                    cm1 = cm1.arg(fileDestino).arg(Crear);
                                }
                                else
                                {
                                    cm1 = "su - "+user+" -c \"mkdir -p %1/.Sincrono/%2\"";
                                    cm1 = cm1.arg(fileDestino).arg(Crear);
                                }
                                comandos << cm1;                                
                            }
                        }
                        if (Root.contains("root") || PermiO.contains("root") || PermiD.contains("root"))
                        {
                            cm = "su -c \"cp --preserve=mode,timestamps %1%2 %1/.Sincrono%2\"";
                            cm = cm.arg(fileDestino).arg(RutaDest);
                        }
                        else
                        {
                            cm = "su - "+user+" -c \"cp --preserve=mode,timestamps %1%2 %1/.Sincrono%2\"";
                            cm = cm.arg(fileDestino).arg(RutaDest);
                        }
                        comandos << cm;                        
                    }
                }
                if (Root.contains("root") || PermiO.contains("root") || PermiD.contains("root"))
                {
                    cm1 = "su -c \"rm -vfd %1%2\"";
                    cm1 = cm1.arg(fileDestino).arg(RutaDest);
                }
                else
                {
                    cm1 = "su - "+user+" -c \"rm -vfd %1%2\"";
                    cm1 = cm1.arg(fileDestino).arg(RutaDest);
                }
                comandos << cm1;
            }
        }
    }
    if (mib != 0)
        delete mib;
    mib = new DrakeProcesos1(comandos, this);
    connect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    connect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    connect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    connect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    int valor=comandos.count();
    mib->Valor(valor,0);
    mib->iniciarProceso();
    Totalizar = comandos.count();
    ui->progressBar->setRange(0,Totalizar);
    Counter = 0;
    Marca = 0;
    ContadorC = 0;
    Evento = 0;
    Value = 0;
}

void sincrono::mibEscribir(QString valor)
{
    valor = valor.remove("# ");
    ui->textEdit->append(valor);
    if (log == "S")
    {
        system(QString::fromUtf8("echo '"+valor+"' >> /usr/share/RecoverDrake/RecoverDrake.log"));
    }
}

void sincrono::mibprogreso(QString Dat)
{
    if (Comprueba == "No")
        ui->progressBar->setValue(Dat.toInt());
}

void sincrono::ProcesarValor(QString ValorComand)
{
    int iFilas, a;
    QString valor, valor1, valor2, valor3;
    iFilas=ui->tableWidget_2->rowCount();
    QTableWidgetItem *item, *item1, *item2, *item3, *item4, *item5, *item6, *item7, *item8;
    for(a=0;a<iFilas;a++)
    {        
        item=ui->tableWidget_2->item(a,1);
        item1=ui->tableWidget_2->item(a,5);
        item2=ui->tableWidget_2->item(a,0);
        item3=ui->tableWidget_2->item(a,2);
        item4=ui->tableWidget_2->item(a,3);
        item5=ui->tableWidget_2->item(a,6);
        item6=ui->tableWidget_2->item(a,7);
        item7=ui->tableWidget_2->item(a,8);
        item8=ui->tableWidget_2->item(a,9);
        valor=item->text();
        valor1=item2->text();
        valor2=item3->text();
        valor3=item4->text();
        if (valor != "")
        {            
            QString Ruta = ""+ui->lineEdit->text()+""+valor+"";
            QFile file(Ruta);
            QString Value = QFileInfo(file).absoluteFilePath();
            Value = Value.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)");
            if (ValorComand.contains(Value))
            {
                if(ValorComand.contains("/.Sincrono") == false)
                {
                    ui->tableWidget_2->item(a,5)->setIcon(QIcon(":/Imagenes/good.png"));
                    item1->setText(tr("Sin cambios"));
                    item5->setText(valor1);
                    item6->setText(valor);
                    item7->setText(valor2);
                    item8->setText(valor3);
                    ui->tableWidget_2->setItem(iFilas,5,item1);
                    ui->tableWidget_2->setItem(iFilas,6,item5);
                    ui->tableWidget_2->setItem(iFilas,7,item6);
                    ui->tableWidget_2->setItem(iFilas,8,item7);
                    ui->tableWidget_2->setItem(iFilas,9,item8);
                    ui->tableWidget_2->selectRow(a);
                }
            }
        }
    }
    TotalProceso = TotalProceso+1;
    ui->progressBar->setValue(TotalProceso);
}

void sincrono::mibFin()
{
    Value = 0;
    Sincronizador = 0;
    disconnect(mib, SIGNAL(publicarDatos(QString)), this, SLOT(mibEscribir(QString)));
    disconnect(mib, SIGNAL(progreso(QString)), this, SLOT(mibprogreso(QString)));
    disconnect(mib, SIGNAL(ValorDato(QString)), this, SLOT(ProcesarValor(QString)));
    disconnect(mib, SIGNAL(finProceso()), this, SLOT(mibFin()));
    if (TotalProceso == Totalizar)
    {
        TotalProceso=0;
        Comprueba = "No";
        ui->progressBar->setValue(0);
        ui->textEdit->append(tr("Finalizada sincronizacion de objetivos"));
        ui->textEdit->append("");
        ui->textEdit->append(tr(":::RESULTADO DE LA SINCRONIZACION::: "));
        ui->textEdit->append("");
        int Contador = ui->tableWidget_2->rowCount();
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(true);
        ui->pushButton_8->setEnabled(true);
        ui->pushButton_9->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_13->setEnabled(true);
        ui->pushButton_14->setEnabled(true);
        ui->pushButton_15->setEnabled(true);
        ui->pushButton_10->setEnabled(true);
        ui->pushButton_11->setEnabled(true);
        ui->pushButton_12->setEnabled(true);
        ui->pushButton_7->setText(tr("Todos (")+QString::number(Contador)+")");
        ui->textEdit->append(tr("Archivos totales: "+QString::number(Contador)+""));
        itemsa = ui->tableWidget_2->findItems(tr("Sin cambios") , Qt::MatchExactly);
        ui->pushButton_8->setText(tr("Iguales (")+QString::number(itemsa.count())+")");
        if (itemsa.count() == 0)
            ui->pushButton_8->setEnabled(false);
        ui->textEdit->append(tr("Archivos iguales: ")+QString::number(itemsa.count())+"");
        items1 = ui->tableWidget_2->findItems(tr("Modificado") , Qt::MatchExactly);
        ui->pushButton_9->setText(tr("Cambios (")+QString::number(items1.count())+")");
        if (items1.count() == 0)
            ui->pushButton_9->setEnabled(false);
        ui->textEdit->append(tr("Archivos modificados: ")+QString::number(items1.count())+"");
        items = ui->tableWidget_2->findItems(tr("Nuevo") , Qt::MatchExactly);
        ui->pushButton_2->setText(tr("Nuevos (")+QString::number(items.count())+")");
        if (items.count() == 0)
            ui->pushButton_2->setEnabled(false);
        ui->textEdit->append(tr("Archivos nuevos: ")+QString::number(items.count())+"");
        items2 = ui->tableWidget_2->findItems(tr("Eliminado") , Qt::MatchExactly);
        ui->pushButton_13->setText(tr("Eliminados (")+QString::number(items2.count())+")");
        if (items2.count() == 0)
            ui->pushButton_13->setEnabled(false);
        ui->textEdit->append(tr("Archivos eliminados: ")+QString::number(items2.count())+"");
        ui->textEdit->append("");
        QColor color;
        drakeSistema drake;
        QString md1 = "find \"%1\" -name .Sincrono";
        md1 = md1.arg(ui->lineEdit_2->text());
        QString Valor1 = drake.getStart(md1);
        if (Valor1 == "")
        {
            ui->pushButton_15->setBackgroundColor(colorAnt);
            ui->pushButton_15->setEnabled(false);
        }
        else
        {
            color = QColor(Qt::yellow);
            ui->pushButton_15->setBackgroundColor(color);
            ui->pushButton_15->setEnabled(true);
        }
    }
}

void sincrono::on_pushButton_14_clicked()
{    
    QString Comprobacion;
    QSqlQuery Comprobar(db);
    Comprobar.exec("SELECT Referencia FROM Sincrono WHERE Referencia='"+ui->lineEdit_3->text()+"'");
    Comprobar.first();
    Comprobacion = Comprobar.value(0).toString();
    if (Comprobacion != ui->lineEdit_3->text() || Comprobacion == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se pueden omitir palabras hasta que no se haya creado el proyecto en la base de datos."));
        m.exec();
        return;
    }
    else
    {
        int Cantidad;
        QString Traspaso;
        QStringList Separar;
        QString Resto;
        QColor color;        
        Omision *Omite = new Omision(this);
        if (Stilo == "A")
            Omite->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        Omite->Valor(ui->lineEdit_3->text());
        Omite->exec();
        QSqlQuery Sincroniza(db);
        Sincroniza.exec("SELECT Codigo FROM Sincrono WHERE Referencia='"+ui->lineEdit_3->text()+"'");
        Sincroniza.first();
        Omitir = Sincroniza.value(0).toString();
        Traspaso = Omitir;
        Separar = Traspaso.split(";");
        Cantidad = Separar.count();
        Resto = QString::number(Cantidad);
        if (Omitir != "")
        {
            color = QColor(Qt::yellow);
            ui->pushButton_14->setBackgroundColor(color);
            ui->pushButton_14->setText(tr("Palabras filtradas: ")+Resto+"");
            ui->pushButton_14->setToolTip(Omitir);
            Contad = new QTimer(this);
            connect(Contad, SIGNAL(timeout()), this, SLOT(Montaje()));
            Contad->start(5000);
        }
        else
        {
            ui->pushButton_14->setBackgroundColor(colorAnt);
            ui->pushButton_14->setText(tr("Filtrar palabras"));
            ui->pushButton_14->setToolTip(Omitir);
            Contad = new QTimer(this);
            connect(Contad, SIGNAL(timeout()), this, SLOT(Montaje()));
            Contad->start(5000);
        }
    }
}

QString sincrono::getPropietario(QString Valor)
{
    QProcess *procesoCut;
    QByteArray du;
    procesoCut=new QProcess(this);
    procesoCut->start(Valor);
    if (! procesoCut->waitForStarted())
        return QString("");
    procesoCut->waitForFinished();
    du = procesoCut->readAllStandardOutput();
    delete procesoCut;
    QString res = QString(du);
    res.chop(1);
    return res;
}

void sincrono::on_pushButton_15_clicked()
{
    QColor color;
    drakeSistema drake;
    QString Explora = "find \"%1\"/.Sincrono";
    Explora = Explora.arg(ui->lineEdit_2->text());
    QString valor1 = drake.getStart(Explora);
    QStringList Value = valor1.split("\n");
    if (Value.count() <= 2)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ninguna lista de copia de sincronizaciones."));
        m.exec();        
        return;
    }
    QString Valor20 = "find \"%1\"";
    Valor20 = Valor20.arg(ui->lineEdit_2->text());
    QString valor = drake.getStart(Valor20);
    if (valor == "")
    {
        QString Valorar, Value;
        QStringList Valor = ui->lineEdit_2->text().split("/");
        Valorar = ui->lineEdit_2->text();
        if (Valorar.contains("/run"))
            Value = Valor.value(4);
        else
            Value = Valor.value(2);
        if (Valorar.contains("/media"))
        {
            QString Vblkid = blkid();
            QStringList vblkid = Vblkid.split("\n");
            for(int a=0;a<vblkid.count();a++)
            {
                QString Rastreo = vblkid.value(a);
                if (Rastreo.contains(Value))
                {
                    QStringList Unidad = Rastreo.split(" ");
                    QString Dev = Unidad.value(0);
                    Dev = Dev.remove(":");
                    QString Mount = getMount(Dev);
                    if (Mount == "Si")
                    {
                        int Resto = 0;
                        QString Valorado;
                        QString Definitivo = getLocal(Dev);
                        QString Depurar = ui->lineEdit_2->text();
                        QStringList Depurado = Depurar.split("/");
                        for (int i=0;i<Depurado.count();i++)
                        {
                            if (Depurado.value(i) == Value)
                            {
                                Resto = i+1;
                                break;
                            }
                        }
                        for (int b=Resto;b<Depurado.count();b++)
                        {
                            Valorado.append("/"+Depurado.value(b)+"");
                        }
                        Depurar = ""+Definitivo+""+Valorado+"";
                        ui->lineEdit_2->setText(Depurar);
                        break;
                    }
                    else if (Mount == "No")
                    {
                        QMessageBox m;
                        if (Stilo == "A")
                            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                        m.setText(tr("No esta montada la unidad destino, por lo que debes montarla antes de utilizar esta opcion."));
                        m.exec();
                        return;
                    }
                }
            }
        }
    }
    Calendario *Fecha = new Calendario(this);
    if (Stilo == "A")
        Fecha->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    Fecha->Valor(ui->lineEdit_2->text(),log);
    Fecha->showMaximized();
    Fecha->exec();
    QString Explora1 = "find \"%1\"/.Sincrono";
    Explora1 = Explora1.arg(ui->lineEdit_2->text());
    QString valor2 = drake.getStart(Explora1);
    QStringList Value1 = valor2.split("\n");
    if (Value1.count() <= 2)
    {
        ui->pushButton_15->setBackgroundColor(colorAnt);
        ui->pushButton_15->setEnabled(false);
    }
    else
    {
        color = QColor(Qt::yellow);
        ui->pushButton_15->setBackgroundColor(color);
        ui->pushButton_15->setEnabled(true);
    }
}

void sincrono::on_lineEdit_2_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = arg1;
        if (Valor.right(1) == "/")
        {
            Valor.remove(Valor.count()-1,1);
            ui->lineEdit_2->setText(Valor);
        }
        QString Valor2 = "ls -l -d \"%1\"";
        Valor2 = Valor2.arg(ui->lineEdit_2->text());
        QString PermisosD = getPropietario(Valor2);
        QStringList RestoD = PermisosD.split(" ");
        QString PermiD = RestoD.value(2);
        if (PermiD != "")
            ui->label_4->setText(tr("Propietario: ")+PermiD+"");
        else
            ui->label_4->setText("");
    }
    else
        ui->label_4->setText("");
}

void sincrono::on_lineEdit_textChanged(const QString &arg1)
{
    if (arg1 != "")
    {
        QString Valor = arg1;
        if (Valor.right(1) == "/")
        {
            Valor.remove(Valor.count()-1,1);
            ui->lineEdit->setText(Valor);
        }
        QString Valor1 = "ls -l -d \"%1\"";
        Valor1 = Valor1.arg(ui->lineEdit->text());
        QString PermisosO = getPropietario(Valor1);
        QStringList RestoO = PermisosO.split(" ");
        QString PermiO = RestoO.value(2);
        if (PermiO != "")
            ui->label_2->setText(tr("Propietario: ")+PermiO+"");
        else
            ui->label_2->setText("");
    }
    else
        ui->label_2->setText("");
}

bool sincrono::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("Sincrono"));
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

void sincrono::closeEvent ( QCloseEvent * event )
{
    event->ignore();
}

void sincrono::on_lineEdit_2_editingFinished()
{
    if (ui->lineEdit_2->text() != "")
    {
        QString Valor2 = "ls -l -d \"%1\"";
        Valor2 = Valor2.arg(ui->lineEdit_2->text());
        QString PermisosD = getPropietario(Valor2);
        QStringList RestoD = PermisosD.split(" ");
        QString PermiD = RestoD.value(2);
        if (PermiD != "")
            ui->label_4->setText(tr("Propietario: ")+PermiD+"");
        else
        {
            ui->label_4->setText("");
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No has introducido una ruta correcta."));
            m.exec();
            ui->lineEdit_2->setText("");
            ui->label_4->setText("");
            ui->lineEdit_2->setFocus();
            return;
        }
    }
    else
        ui->label_4->setText("");
}

void sincrono::on_lineEdit_editingFinished()
{
    if (ui->lineEdit->text() != "")
    {
        QString Valor1 = "ls -l -d \"%1\"";
        Valor1 = Valor1.arg(ui->lineEdit->text());
        QString PermisosO = getPropietario(Valor1);
        QStringList RestoO = PermisosO.split(" ");
        QString PermiO = RestoO.value(2);
        if (PermiO != "")
            ui->label_2->setText(tr("Propietario: ")+PermiO+"");
        else
        {
            ui->label_2->setText("");
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("No has introducido una ruta correcta."));
            m.exec();
            ui->lineEdit->setText("");
            ui->label_2->setText("");
            ui->lineEdit->setFocus();
            return;
        }
    }
    else
        ui->label_2->setText("");
}

void sincrono::Montaje()
{
    QString Valor20 = "find \"%1\"";
    Valor20 = Valor20.arg(ui->lineEdit_2->text());
    drakeSistema drake;
    QString valor = drake.getStart(Valor20);
    QStringList Comparar = valor.split("\n");
    if (valor == "")
    {
        if (ui->lineEdit_2->text().contains("/media"))
        {
            int Contador;
            QString Valorar, Value;
            Contador = 0;
            QStringList Valor = ui->lineEdit_2->text().split("/");
            Valorar = ui->lineEdit_2->text();
            if (Valorar.contains("/run"))
                Value = Valor.value(4);
            else
                Value = Valor.value(2);
            if (Valorar.contains("/media"))
            {
                QString Vblkid = blkid();
                QStringList vblkid = Vblkid.split("\n");
                for(int a=0;a<vblkid.count();a++)
                {
                    QString Rastreo = vblkid.value(a);
                    if (Rastreo.contains(Value))
                    {
                        QStringList Unidad = Rastreo.split(" ");
                        QString Dev = Unidad.value(0);
                        Dev = Dev.remove(":");
                        QString Mount = getMount(Dev);
                        if (Mount == "Si")
                        {
                            int Resto = 0;
                            QString Valorado;
                            QString Definitivo = getLocal(Dev);
                            QString Depurar = ui->lineEdit_2->text();
                            QStringList Depurado = Depurar.split("/");
                            for (int i=0;i<Depurado.count();i++)
                            {
                                if (Depurado.value(i) == Value)
                                {
                                    Resto = i+1;
                                    break;
                                }
                            }
                            for (int b=Resto;b<Depurado.count();b++)
                            {
                                Valorado.append("/"+Depurado.value(b)+"");
                            }
                            Depurar = ""+Definitivo+""+Valorado+"";
                            ui->lineEdit_2->setText(Depurar);
                            Contador = 1;                            
                            if (Comparar.value(0) != ui->lineEdit_2->text())
                            {
                                ui->label_4->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
                                return;
                            }
                            break;
                        }
                        else if (Mount == "No")
                        {
                            ui->label_4->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
                            return;
                        }
                    }
                }
            }
            if (Contador == 0)
            {
                ui->label_4->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
                return;
            }
        }
        else
        {
            if (Comparar.value(0) != ui->lineEdit_2->text())
            {
                ui->label_4->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
                return;
            }
            else
                ui->label_4->setPixmap(QPixmap(QString::fromUtf8("")));
        }
    }
    else
    {
        if (Comparar.value(0) != ui->lineEdit_2->text())
        {
            ui->label_4->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
            return;
        }
        else
            ui->label_4->setPixmap(QPixmap(QString::fromUtf8("")));
    }
    QString Valor21 = "find \"%1\"";
    Valor21 = Valor21.arg(ui->lineEdit->text());
    QString valor1 = drake.getStart(Valor21);
    if (valor1 == "")
    {
        if (ui->lineEdit->text().contains("/media"))
        {
            int Contador;
            QString Valorar, Value;
            Contador = 0;
            QStringList Valor = ui->lineEdit->text().split("/");
            Valorar = ui->lineEdit->text();
            if (Valorar.contains("/run"))
                Value = Valor.value(4);
            else
                Value = Valor.value(2);
            if (Valorar.contains("/media"))
            {
                QString Vblkid = blkid();
                QStringList vblkid = Vblkid.split("\n");
                for(int a=0;a<vblkid.count();a++)
                {
                    QString Rastreo = vblkid.value(a);
                    if (Rastreo.contains(Value))
                    {
                        QStringList Unidad = Rastreo.split(" ");
                        QString Dev = Unidad.value(0);
                        Dev = Dev.remove(":");
                        QString Mount = getMount(Dev);
                        if (Mount == "Si")
                        {
                            int Resto = 0;
                            QString Valorado;
                            QString Definitivo = getLocal(Dev);
                            QString Depurar = ui->lineEdit->text();
                            QStringList Depurado = Depurar.split("/");
                            for (int i=0;i<Depurado.count();i++)
                            {
                                if (Depurado.value(i) == Value)
                                {
                                    Resto = i+1;
                                    break;
                                }
                            }
                            for (int b=Resto;b<Depurado.count();b++)
                            {
                                Valorado.append("/"+Depurado.value(b)+"");
                            }
                            Depurar = ""+Definitivo+""+Valorado+"";
                            ui->lineEdit->setText(Depurar);
                            Contador = 1;
                            break;
                        }
                        else if (Mount == "No")
                        {
                            ui->label_2->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
                            return;
                        }
                    }
                }
            }
            if (Contador == 0)
            {
                ui->label_2->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
                return;
            }
        }
        else
        {
            ui->label_2->setPixmap(QPixmap(QString::fromUtf8("")));
        }
    }
    else
    {
        ui->label_2->setPixmap(QPixmap(QString::fromUtf8("")));
    }
    this->Verificar();
}

void sincrono::Verificar()
{
    if (Value == 0)
    {
        if (ui->lineEdit_2->text() != "")
        {
            QColor color;
            drakeSistema drake;
            QString md1 = "find \"%1\" -name .Sincrono";
            md1 = md1.arg(ui->lineEdit_2->text());
            QString Valor1 = drake.getStart(md1);
            if (Valor1 == "")
            {
                ui->pushButton_15->setBackgroundColor(colorAnt);
                ui->pushButton_15->setEnabled(false);
            }
            else
            {
                color = QColor(Qt::yellow);
                ui->pushButton_15->setBackgroundColor(color);
                ui->pushButton_15->setEnabled(true);
            }
        }
        if (ui->lineEdit->text() != "")
        {
                QString Valor10 = "ls -l -d \"%1\"";
                Valor10 = Valor10.arg(ui->lineEdit->text());
                QString PermisosO = getPropietario(Valor10);
                QStringList RestoO = PermisosO.split(" ");
                QString PermiO = RestoO.value(2);
                if (PermiO != "")
                    ui->label_2->setText(tr("Propietario: ")+PermiO+"");
                else
                    ui->label_2->setText("");
        }
        if (ui->lineEdit_2->text() != "")
        {
            QString Valor20 = "ls -l -d \"%1\"";
            Valor20 = Valor20.arg(ui->lineEdit_2->text());
            QString PermisosD = getPropietario(Valor20);
            QStringList RestoD = PermisosD.split(" ");
            QString PermiD = RestoD.value(2);
            if (PermiD != "")
                ui->label_4->setText(tr("Propietario: ")+PermiD+"");
            else
                ui->label_4->setText("");
        }
    }
}
