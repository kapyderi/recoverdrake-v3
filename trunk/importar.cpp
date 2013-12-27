#include "importar.h"
#include "ui_importar.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QTest>
#include <QProgressDialog>
#include <QInputDialog>

importar::importar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::importar)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Control=0;
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

importar::~importar()
{
    delete ui;
}

void importar::Valor(QStringList datos)
{
    int iFilas;
    QString Value0;
    RDatos = datos;
    Receptor=datos.value(0);
    ReceptorComp=datos.value(1);
    Separador *Separa=new Separador(this);
    if (Stilo == "A")
        Separa->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    Separa->Valor(Receptor);
    Separa->exec();
    SaltoDat=Separa->SaltoDato;
    SaltoLine=Separa->Separa;
    if (SaltoDat == "Tab")
        SaltoDat = "\t";
    Recepcion=Receptor.split(""+SaltoDat+"");
    for(int i=0;i<Recepcion.count();i++)
    {
        Value0 = Recepcion.value(i);
        if (SaltoLine== "Si")
        {
            Value0=Value0.remove("\"");
        }
        if (Value0 != "")
        {
            QTableWidgetItem *item1, *item2, *item3, *item4, *item5;
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            item4=new QTableWidgetItem;
            item5=new QTableWidgetItem;
            item1->setText(""+Value0+"");
            item2->setText(" ");
            item3->setText(" ");
            item4->setText(" ");
            item5->setText("No");
            iFilas=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iFilas);
            ui->tableWidget->setItem(iFilas,0,item1);
            ui->tableWidget->setItem(iFilas,1,item2);
            ui->tableWidget->setItem(iFilas,2,item3);
            ui->tableWidget->setItem(iFilas,3,item4);
            ui->tableWidget->setItem(iFilas,4,item5);
        }
   }
}

void importar::on_pushButton_2_clicked()
{
    this->Resultado="Negativo";
    close();
}

void importar::on_pushButton_clicked()
{
    int iFilas;
    QString Relacion, valorOrig, valorFinal ;
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
        QTableWidgetItem *item, *item1, *item2, *item3;
        item=new QTableWidgetItem;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        Relacion = ui->comboBox_2->currentText();
        valorOrig = ui->lineEdit->text();
        valorFinal = ui->lineEdit_2->text();
        item->setText(""+Relacion+"");
        item1->setText(""+valorOrig+"");
        item2->setText(""+valorFinal+"");
        if (Relacion != "")
        {
            item3->setText(tr("Ok"));
        }
        ui->tableWidget->setItem(iFilas,1,item);
        ui->tableWidget->setItem(iFilas,2,item1);
        ui->tableWidget->setItem(iFilas,3,item2);
        ui->tableWidget->setItem(iFilas,4,item3);
        if (Relacion != "")
        {
            ui->tableWidget->item(iFilas,4)->setIcon(QIcon(":/Imagenes/good.png"));
        }
        if (Relacion == "titulo")
        {
            Control=1;
        }
    }
}

void importar::on_pushButton_4_clicked()
{
    int iFilas;
    QString Relacion;
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
        QTableWidgetItem *item, *item1, *item2, *item3;
        item=new QTableWidgetItem;
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        Relacion= item->text();
        item->setText(" ");
        item1->setText(" ");
        item2->setText(" ");
        item3->setText("No");
        ui->tableWidget->setItem(iFilas,1,item);
        ui->tableWidget->setItem(iFilas,2,item1);
        ui->tableWidget->setItem(iFilas,3,item2);
        ui->tableWidget->setItem(iFilas,4,item3);
        ui->tableWidget->item(iFilas,4)->setIcon(QIcon(""));
    }
    if (Relacion == "titulo")
    {
        Control=0;
    }
}

void importar::on_pushButton_3_clicked()
{
    if (Control == 0)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Sin el campo titulo no puedes realizar ninguna actualizacion. Activa este campo para poder continuar."));
        m.exec();
        return;
    }
    QString titulo="",titulo_original="",edad="6",drama="0",comedia="0",accion="0",aventura="0",scifi="0",romantica="0",musical="0";
    QString catastrofes="0",suspense="0",fantasia="0",erotico="0",porno="0",historico="0",policiaco="0",terror="0",western="0";
    QString belico="0",deportes="0",animacion="0",documental="0",gore_zombies="0",caratula="",actor="",secundario="";
    QString calificacion="6",sinopsis="",soporte="",posicion="",visionada="1",duracion="",color="0",vose="2",formato="avi",director="0";
    QString activo, activo1, activo2, activo3, activo4, Value, Final;
    QStringList Batida;
    QTableWidgetItem *item, *item1, *item2, *item3, *item4;
    item=new QTableWidgetItem;
    item1=new QTableWidgetItem;
    item2=new QTableWidgetItem;
    item3=new QTableWidgetItem;
    item4=new QTableWidgetItem;
    int i;
    setUpdatesEnabled(false);
    QProgressDialog progress(tr("Importando registros a la base de datos... Espera por favor"), tr("Cancelar"), 0, RDatos.count(), this);
    progress.show();
    int cantidad=1;
    for(int a=1;a<RDatos.count();a++)
    {
        qApp->processEvents();
        if (cantidad == 1)
        {
            db.transaction();
        }
        progress.setValue(a);
        if (progress.wasCanceled())
            break;
        Value = RDatos.value(a);
        int itemCount = ui->tableWidget->rowCount();
        for(i=0;i<itemCount;i++)
        {
            item = ui->tableWidget->item(i,0);
            item1 = ui->tableWidget->item(i,1);
            item2 = ui->tableWidget->item(i,2);
            item3 = ui->tableWidget->item(i,3);
            item4 = ui->tableWidget->item(i,4);
            activo = item->text();
            activo1 = item1->text();
            activo2 = item2->text();
            activo3 = item3->text();
            activo4 = item4->text();
            if (activo4 == "Ok")
            {
                Batida = Value.split(""+SaltoDat+"");
                Final = Batida.value(i);
                if (SaltoLine== "Si")
                {
                    Final = Final.remove("\"");
                }
                if (activo1 == "titulo")
                {
                    titulo=Final;
                }
                if (activo1 == "titulo_original")
                {
                    if (Final == activo2)
                        titulo_original=activo3;
                    else
                        titulo_original=Final;
                }
                if (activo1 == "edad")
                {
                    if (Final == activo2)
                        edad=activo3;
                    else
                        edad=Final;
                }
                if (activo1 == "drama")
                {
                    if (Final == activo2)
                        drama=activo3;
                    else
                        drama=Final;
                }
                if (activo1 == "comedia")
                {
                    if (Final == activo2)
                        comedia=activo3;
                    else
                        comedia=Final;
                }
                if (activo1 == "accion")
                {
                    if (Final == activo2)
                        accion=activo3;
                    else
                        accion=Final;
                }
                if (activo1 == "aventura")
                {
                    if (Final == activo2)
                        aventura=activo3;
                    else
                        aventura=Final;
                }
                if (activo1 == "scifi")
                {
                    if (Final == activo2)
                        scifi=activo3;
                    else
                        scifi=Final;
                }
                if (activo1 == "romantica")
                {
                    if (Final == activo2)
                        romantica=activo3;
                    else
                        romantica=Final;
                }
                if (activo1 == "musical")
                {
                    if (Final == activo2)
                        musical=activo3;
                    else
                        musical=Final;
                }
                if (activo1 == "catastrofes")
                {
                    if (Final == activo2)
                        catastrofes=activo3;
                    else
                        catastrofes=Final;
                }
                if (activo1 == "suspense")
                {
                    if (Final == activo2)
                        suspense=activo3;
                    else
                        suspense=Final;
                }
                if (activo1 == "fantasia")
                {
                    if (Final == activo2)
                        fantasia=activo3;
                    else
                        fantasia=Final;
                }
                if (activo1 == "erotico")
                {
                    if (Final == activo2)
                        erotico=activo3;
                    else
                        erotico=Final;
                }
                if (activo1 == "porno")
                {
                    if (Final == activo2)
                        porno=activo3;
                    else
                        porno=Final;
                }
                if (activo1 == "historico")
                {
                    if (Final == activo2)
                        historico=activo3;
                    else
                        historico=Final;
                }
                if (activo1 == "policiaco")
                {
                    if (Final == activo2)
                        policiaco=activo3;
                    else
                        policiaco=Final;
                }
                if (activo1 == "terror")
                {
                    if (Final == activo2)
                        terror=activo3;
                    else
                        terror=Final;
                }
                if (activo1 == "western")
                {
                    if (Final == activo2)
                        western=activo3;
                    else
                        western=Final;
                }
                if (activo1 == "belico")
                {
                    if (Final == activo2)
                        belico=activo3;
                    else
                        belico=Final;
                }
                if (activo1 == "deportes")
                {
                    if (Final == activo2)
                        deportes=activo3;
                    else
                        deportes=Final;
                }
                if (activo1 == "animacion")
                {
                    if (Final == activo2)
                        animacion=activo3;
                    else
                        animacion=Final;
                }
                if (activo1 == "documental")
                {
                    if (Final == activo2)
                        documental=activo3;
                    else
                        documental=Final;
                }
                if (activo1 == "gore_zombies")
                {
                    if (Final == activo2)
                        gore_zombies=activo3;
                    else
                        gore_zombies=Final;
                }
                if (activo1 == "caratula")
                {
                    if (Final == activo2)
                        caratula=activo3;
                    else
                        caratula=Final;
                }
                if (activo1 == "actor")
                {
                    if (Final == activo2)
                        actor=activo3;
                    else
                        actor=Final;
                }
                if (activo1 == "secundario")
                {
                    if (Final == activo2)
                        secundario=activo3;
                    else
                        secundario=Final;
                }
                if (activo1 == "calificacion")
                {
                    if (Final == activo2)
                        calificacion=activo3;
                    else
                        calificacion=Final;
                }
                if (activo1 == "sinopsis")
                {
                    if (Final == activo2)
                        sinopsis=activo3;
                    else
                        sinopsis=Final;
                }
                if (activo1 == "soporte")
                {
                    if (Final == activo2)
                        soporte=activo3;
                    else
                        soporte=Final;
                }
                if (activo1 == "posicion")
                {
                    if (Final == activo2)
                        posicion=activo3;
                    else
                        posicion=Final;
                }
                if (activo1 == "visionada")
                {
                    if (Final == activo2)
                        visionada=activo3;
                    else
                        visionada=Final;
                }
                if (activo1 == "duracion")
                {
                    if (Final == activo2)
                        duracion=activo3;
                    else
                        duracion=Final;
                }
                if (activo1 == "color")
                {
                    if (Final == activo2)
                        color=activo3;
                    else
                        color=Final;
                }
                if (activo1 == "vose")
                {
                    if (Final == activo2)
                        vose=activo3;
                    else
                        vose=Final;
                }
                if (activo1 == "formato")
                {
                    if (Final == activo2)
                        formato=activo3;
                    else
                        formato=Final;
                }
                if (activo1 == "director")
                {
                    if (Final == activo2)
                        director=activo3;
                    else
                        director=Final;
                }
            }
        }
        QSqlQuery querySelec(db);
        querySelec.exec("SELECT titulo FROM pelis WHERE titulo='"+titulo+"'");
        querySelec.first();
        QSqlQuery query(db);
        query.prepare("INSERT INTO pelis (titulo,titulo_original,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico,policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis,soporte,posicion,visionada,duracion,color,vose,formato,director)"                             "VALUES (:titulo,:titulo1,:edad,:drama,:comedia,:accion,:aventura,:scifi,:romantica,:musical,:catastrofes,:suspense,:fantasia,:erotico,:porno,:historico,:policiaco,:terror,:western,:belico,:deportes,:animacion,:documental,:gore_zombies,:caratula,:actor,:secundario,:calificacion,:sinopsis,:soporte,:posicion,:visionada,:duracion,:color,:vose,:formato,:director)");
        query.bindValue(":titulo", titulo);
        query.bindValue(":titulo1", titulo_original);
        query.bindValue(":edad", edad);
        query.bindValue(":drama", drama);
        query.bindValue(":comedia", comedia);
        query.bindValue(":accion", accion);
        query.bindValue(":aventura", aventura);
        query.bindValue(":scifi", scifi);
        query.bindValue(":romantica", romantica);
        query.bindValue(":musical", musical);
        query.bindValue(":catastrofes", catastrofes);
        query.bindValue(":suspense", suspense);
        query.bindValue(":fantasia", fantasia);
        query.bindValue(":erotico", erotico);
        query.bindValue(":porno", porno);
        query.bindValue(":historico", historico);
        query.bindValue(":policiaco", policiaco);
        query.bindValue(":terror", terror);
        query.bindValue(":western", western);
        query.bindValue(":belico", belico);
        query.bindValue(":deportes", deportes);
        query.bindValue(":animacion", animacion);
        query.bindValue(":documental", documental);
        query.bindValue(":gore_zombies", gore_zombies);
        query.bindValue(":caratula", caratula);
        query.bindValue(":actor", actor);
        query.bindValue(":secundario", secundario);
        query.bindValue(":calificacion", calificacion);
        query.bindValue(":sinopsis", sinopsis);
        query.bindValue(":soporte", soporte);
        query.bindValue(":posicion", posicion);
        query.bindValue(":visionada", visionada);
        query.bindValue(":duracion", duracion);
        query.bindValue(":color", color);
        query.bindValue(":vose", vose);
        query.bindValue(":formato", formato);
        query.bindValue(":director", director);
        query.exec();
        cantidad++;
        if (cantidad == 100)
        {
            cantidad=1;
            db.commit();
        }
        titulo="",titulo_original="",edad="6",drama="0",comedia="0",accion="0",aventura="0",scifi="0",romantica="0",musical="0";
        catastrofes="0",suspense="0",fantasia="0",erotico="0",porno="0",historico="0",policiaco="0",terror="0",western="0";
        belico="0",deportes="0",animacion="0",documental="0",gore_zombies="0",caratula="",actor="",secundario="";
        calificacion="6",sinopsis="",soporte="",posicion="",visionada="1",duracion="",color="0",vose="2",formato="avi",director="0";
    }
    progress.setValue(RDatos.count());
    db.commit();
    setUpdatesEnabled(true);
    Control=0;
    QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    m.setText(tr("Importación realizada."));
    m.exec();
    this->Resultado="Positivo";
    close();
}
