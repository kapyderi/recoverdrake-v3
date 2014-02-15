#include "dbpelis.h"
#include "ui_dbpelis.h"
#include "drakesistema.h"
#include <QFileDialog>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QProgressDialog>
#include <QTest>
#include <QFile>
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
#include <QRect>
#include <QFontDialog>
#include "ordenar.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFile>
#include <QKeyEvent>
#include <QPrintPreviewDialog>

dbpelis::dbpelis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dbpelis)
{
    ui->setupUi(this);
    drakeSistema drake;
    user = drake.getUser();
    import=0;
    db=QSqlDatabase::database("PRINCIPAL");
    Model= new QSqlTableModel(0,db);
    Model->setTable("pelis");
    Model->select();
    Model->setHeaderData(1,Qt::Horizontal,"Titulo");
    Model->setHeaderData(2,Qt::Horizontal,"Titulo Original");
    Model->setHeaderData(3,Qt::Horizontal,"Calificacion por edades");
    Model->setHeaderData(4,Qt::Horizontal,"Genero: Drama");
    Model->setHeaderData(5,Qt::Horizontal,"Genero: Comedia");
    Model->setHeaderData(6,Qt::Horizontal,"Genero: Accion");
    Model->setHeaderData(7,Qt::Horizontal,"Genero: Aventura");
    Model->setHeaderData(8,Qt::Horizontal,"Genero: Ciencia Ficcion");
    Model->setHeaderData(9,Qt::Horizontal,"Genero: Romantico");
    Model->setHeaderData(10,Qt::Horizontal,"Genero: Musical");
    Model->setHeaderData(11,Qt::Horizontal,"Genero: Catastrofes");
    Model->setHeaderData(12,Qt::Horizontal,"Genero: Suspense");
    Model->setHeaderData(13,Qt::Horizontal,"Genero: Fantasia");
    Model->setHeaderData(14,Qt::Horizontal,"Genero: Erotico");
    Model->setHeaderData(15,Qt::Horizontal,"Genero: Porno");
    Model->setHeaderData(16,Qt::Horizontal,"Genero: Historico");
    Model->setHeaderData(17,Qt::Horizontal,"Genero: Policiaco");
    Model->setHeaderData(18,Qt::Horizontal,"Genero: Terror");
    Model->setHeaderData(19,Qt::Horizontal,"Genero: Western");
    Model->setHeaderData(20,Qt::Horizontal,"Genero: Belico");
    Model->setHeaderData(21,Qt::Horizontal,"Genero: Deportes");
    Model->setHeaderData(22,Qt::Horizontal,"Genero: Animacion/dibujos");
    Model->setHeaderData(23,Qt::Horizontal,"Genero: Documental");
    Model->setHeaderData(24,Qt::Horizontal,"Genero: Gore/Zombies");
    Model->setHeaderData(25,Qt::Horizontal,"Caratula");
    Model->setHeaderData(26,Qt::Horizontal,"Actor principal");
    Model->setHeaderData(27,Qt::Horizontal,"Actor secundario");
    Model->setHeaderData(28,Qt::Horizontal,"Calificacion");
    Model->setHeaderData(29,Qt::Horizontal,"Sinopsis");
    Model->setHeaderData(30,Qt::Horizontal,"Nº Soporte");
    Model->setHeaderData(31,Qt::Horizontal,"Nº Posicion");
    Model->setHeaderData(32,Qt::Horizontal,"Visionada");
    Model->setHeaderData(33,Qt::Horizontal,"Duracion");
    Model->setHeaderData(34,Qt::Horizontal,"Color/BW");
    Model->setHeaderData(35,Qt::Horizontal,"Idioma");
    Model->setHeaderData(36,Qt::Horizontal,"Formato Video");
    Model->setHeaderData(37,Qt::Horizontal,"Director");
    Model->setHeaderData(38,Qt::Horizontal,"Ano");
    ui->tableView->setModel(Model);
    ui->comboBox_2->setCurrentItem(1);
    inicio();
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,
    QModelIndex)),this,SLOT(cambiaFila(QModelIndex)));
    connect(ui->checkBox_22,SIGNAL(clicked()),this,SLOT(orden()));
    connect(ui->lineEdit_8,SIGNAL(textChanged(QString)),this,SLOT(orden()));
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
    CierreTotal = 0;

//    QPrinter             printer( QPrinter::HighResolution );
//      QPrintPreviewDialog  preview( &printer, this );
//      connect( &preview, SIGNAL(paintRequested(QPrinter*)), SLOT(on_pushButton_9_clicked()));
//      preview.exec();

    //falta ver esta parte segun la pagina web http://www.dazzle.plus.com/linux/Qt4/part12.htm
}

dbpelis::~dbpelis()
{
    delete ui;
    delete Model;
    if (import != 0)
        delete import;
}

void dbpelis::Valor(QString valor)
{
    if (valor == "Quitar")
    {        
        CierreTotal = 1;
    }
}

void dbpelis::closeEvent ( QCloseEvent * event )
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

void dbpelis::inicio()
{
    int i = 0;
    ui->tableView->selectRow(i);
    QString Valor;
    QString tiempo;
    QStringList tempo;
    QModelIndex index;
    index=ui->tableView->model()->index(i,0);
    this->id= index.data().toInt();
    ui->lineEdit_5->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,1);
    ui->lineEdit->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,2);
    ui->lineEdit_2->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,3);
    if (index.data().toInt() == 0)
    {
        ui->radioButton->setChecked(true);
    }
    else if (index.data().toInt() == 1)
    {
        ui->radioButton_2->setChecked(true);
    }
    else if (index.data().toInt() == 2)
    {
        ui->radioButton_3->setChecked(true);
    }
    else if (index.data().toInt() == 3)
    {
        ui->radioButton_4->setChecked(true);
    }
    else if (index.data().toInt() == 4)
    {
        ui->radioButton_5->setChecked(true);
    }
    else if (index.data().toInt() == 5)
    {
        ui->radioButton_21->setChecked(true);
    }
    else if (index.data().toInt() == 6)
    {
        ui->radioButton_25->setChecked(true);
    }
    index=ui->tableView->model()->index(i,4);
    if (index.data().toInt() == 0)
    {
        ui->checkBox->setChecked(false);
    }
    else
    {
        ui->checkBox->setChecked(true);
    }
    index=ui->tableView->model()->index(i,5);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_2->setChecked(false);
    }
    else
    {
        ui->checkBox_2->setChecked(true);
    }
    index=ui->tableView->model()->index(i,6);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_3->setChecked(false);
    }
    else
    {
        ui->checkBox_3->setChecked(true);
    }
    index=ui->tableView->model()->index(i,7);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_4->setChecked(false);
    }
    else
    {
        ui->checkBox_4->setChecked(true);
    }
    index=ui->tableView->model()->index(i,8);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_6->setChecked(false);
    }
    else
    {
        ui->checkBox_6->setChecked(true);
    }
    index=ui->tableView->model()->index(i,9);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_7->setChecked(false);
    }
    else
    {
        ui->checkBox_7->setChecked(true);
    }
    index=ui->tableView->model()->index(i,10);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_8->setChecked(false);
    }
    else
    {
        ui->checkBox_8->setChecked(true);
    }
    index=ui->tableView->model()->index(i,11);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_9->setChecked(false);
    }
    else
    {
        ui->checkBox_9->setChecked(true);
    }
    index=ui->tableView->model()->index(i,12);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_10->setChecked(false);
    }
    else
    {
        ui->checkBox_10->setChecked(true);
    }
    index=ui->tableView->model()->index(i,13);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_11->setChecked(false);
    }
    else
    {
        ui->checkBox_11->setChecked(true);
    }
    index=ui->tableView->model()->index(i,14);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_12->setChecked(false);
    }
    else
    {
        ui->checkBox_12->setChecked(true);
    }
    index=ui->tableView->model()->index(i,15);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_13->setChecked(false);
    }
    else
    {
        ui->checkBox_13->setChecked(true);
    }
    index=ui->tableView->model()->index(i,16);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_14->setChecked(false);
    }
    else
    {
        ui->checkBox_14->setChecked(true);
    }
    index=ui->tableView->model()->index(i,17);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_15->setChecked(false);
    }
    else
    {
        ui->checkBox_15->setChecked(true);
    }
    index=ui->tableView->model()->index(i,18);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_5->setChecked(false);
    }
    else
    {
        ui->checkBox_5->setChecked(true);
    }
    index=ui->tableView->model()->index(i,19);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_16->setChecked(false);
    }
    else
    {
        ui->checkBox_16->setChecked(true);
    }
    index=ui->tableView->model()->index(i,20);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_17->setChecked(false);
    }
    else
    {
        ui->checkBox_17->setChecked(true);
    }
    index=ui->tableView->model()->index(i,21);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_18->setChecked(false);
    }
    else
    {
        ui->checkBox_18->setChecked(true);
    }
    index=ui->tableView->model()->index(i,22);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_19->setChecked(false);
    }
    else
    {
        ui->checkBox_19->setChecked(true);
    }
    index=ui->tableView->model()->index(i,23);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_20->setChecked(false);
    }
    else
    {
        ui->checkBox_20->setChecked(true);
    }
    index=ui->tableView->model()->index(i,24);
    if (index.data().toInt() == 0)
    {
        ui->checkBox_21->setChecked(false);
    }
    else
    {
        ui->checkBox_21->setChecked(true);
    }
    index=ui->tableView->model()->index(i,25);
    Valor = index.data().toString();
    if (Valor != "")
    {
        QImage image(""+Valor+"");
        ui->label_11->setPixmap(QPixmap::fromImage(image));
        ui->label_11->setScaledContents(true);
        ui->label_11->adjustSize();
    }
    else
    {
        ui->label_11->setText(tr("<center>Sin<p><center>imagen<p><center>disponible<p>"));
    }
    index=ui->tableView->model()->index(i,26);
    ui->lineEdit_4->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,27);
    ui->lineEdit_3->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,28);
    if (index.data().toInt() == 0)
    {
        ui->radioButton_6->setChecked(true);
    }
    else if (index.data().toInt() == 1)
    {
        ui->radioButton_7->setChecked(true);
    }
    else if (index.data().toInt() == 2)
    {
        ui->radioButton_8->setChecked(true);
    }
    else if (index.data().toInt() == 3)
    {
        ui->radioButton_9->setChecked(true);
    }
    else if (index.data().toInt() == 4)
    {
        ui->radioButton_10->setChecked(true);
    }
    else if (index.data().toInt() == 5)
    {
        ui->radioButton_11->setChecked(true);
    }
    else if (index.data().toInt() == 6)
    {
        ui->radioButton_12->setChecked(true);
    }
    else if (index.data().toInt() == 7)
    {
        ui->radioButton_13->setChecked(true);
    }
    else if (index.data().toInt() == 8)
    {
        ui->radioButton_15->setChecked(true);
    }
    else if (index.data().toInt() == 9)
    {
        ui->radioButton_14->setChecked(true);
    }
    else if (index.data().toInt() == 10)
    {
        ui->radioButton_16->setChecked(true);
    }
    index=ui->tableView->model()->index(i,29);
    ui->textEdit_2->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,30);
    ui->lineEdit_7->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,31);
    ui->lineEdit_6->setText(tr(index.data().toString()));
    index=ui->tableView->model()->index(i,32);
    if (index.data().toInt() == 0)
    {
        ui->radioButton_17->setChecked(true);
    }
    else if (index.data().toInt() == 1)
    {
        ui->radioButton_18->setChecked(true);
    }
    index=ui->tableView->model()->index(i,33);
    tiempo = index.data().toString();
    tempo = tiempo.split(":");
    int Tiempo1 = tempo.value(0).toInt();
    int Tiempo2 = tempo.value(1).toInt();
    int Tiempo3 = tempo.value(2).toInt();
    QTime time(Tiempo1, Tiempo2, Tiempo3);
    ui->timeEdit->setTime(time);
    index=ui->tableView->model()->index(i,34);
    if (index.data().toInt() == 0)
    {
        ui->radioButton_19->setChecked(true);
    }
    else if (index.data().toInt() == 1)
    {
        ui->radioButton_20->setChecked(true);
    }
    index=ui->tableView->model()->index(i,35);
    if (index.data().toInt() == 0)
    {
        ui->radioButton_22->setChecked(true);
    }
    else if (index.data().toInt() == 1)
    {
        ui->radioButton_24->setChecked(true);
    }
    else if (index.data().toInt() == 2)
    {
        ui->radioButton_23->setChecked(true);
    }
    index=ui->tableView->model()->index(i,36);
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(index.data().toString()));
    index=ui->tableView->model()->index(i,37);
    ui->lineEdit_9->setText(index.data().toString());
    index=ui->tableView->model()->index(i,38);
    ui->lineEdit_10->setText(index.data().toString());
    this->fila=i;
    QSqlQuery query(db);
    query.exec("SELECT id FROM pelis");
    query.last();
    int valor = query.value(0).toInt();
    ui->label_15->setText(""+QString::number(fila+1)+"/"+QString::number(valor)+"");
}

void dbpelis::cambiaFila(QModelIndex actual)
{
        int i;
        QString Valor;
        QString tiempo;
        QStringList tempo;
        i=actual.row();
        QModelIndex index;
        index=ui->tableView->model()->index(i,0);
        this->id= index.data().toInt();
        ui->lineEdit_5->setText(tr(index.data().toString()));
        index=ui->tableView->model()->index(i,1);
        ui->lineEdit->setText(tr(index.data().toString()));
        index=ui->tableView->model()->index(i,2);
        ui->lineEdit_2->setText(tr(index.data().toString()));
        index=ui->tableView->model()->index(i,3);
        if (index.data().toInt() == 0)
        {
            ui->radioButton->setChecked(true);
        }
        else if (index.data().toInt() == 1)
        {
            ui->radioButton_2->setChecked(true);
        }
        else if (index.data().toInt() == 2)
        {
            ui->radioButton_3->setChecked(true);
        }
        else if (index.data().toInt() == 3)
        {
            ui->radioButton_4->setChecked(true);
        }
        else if (index.data().toInt() == 4)
        {
            ui->radioButton_5->setChecked(true);
        }
        else if (index.data().toInt() == 5)
        {
            ui->radioButton_21->setChecked(true);
        }
        else if (index.data().toInt() == 6)
        {
            ui->radioButton_25->setChecked(true);
        }
        index=ui->tableView->model()->index(i,4);
        if (index.data().toInt() == 0)
        {
            ui->checkBox->setChecked(false);
        }
        else
        {
            ui->checkBox->setChecked(true);
        }
        index=ui->tableView->model()->index(i,5);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_2->setChecked(false);
        }
        else
        {
            ui->checkBox_2->setChecked(true);
        }
        index=ui->tableView->model()->index(i,6);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_3->setChecked(false);
        }
        else
        {
            ui->checkBox_3->setChecked(true);
        }
        index=ui->tableView->model()->index(i,7);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_4->setChecked(false);
        }
        else
        {
            ui->checkBox_4->setChecked(true);
        }
        index=ui->tableView->model()->index(i,8);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_6->setChecked(false);
        }
        else
        {
            ui->checkBox_6->setChecked(true);
        }
        index=ui->tableView->model()->index(i,9);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_7->setChecked(false);
        }
        else
        {
            ui->checkBox_7->setChecked(true);
        }
        index=ui->tableView->model()->index(i,10);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_8->setChecked(false);
        }
        else
        {
            ui->checkBox_8->setChecked(true);
        }
        index=ui->tableView->model()->index(i,11);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_9->setChecked(false);
        }
        else
        {
            ui->checkBox_9->setChecked(true);
        }
        index=ui->tableView->model()->index(i,12);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_10->setChecked(false);
        }
        else
        {
            ui->checkBox_10->setChecked(true);
        }
        index=ui->tableView->model()->index(i,13);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_11->setChecked(false);
        }
        else
        {
            ui->checkBox_11->setChecked(true);
        }
        index=ui->tableView->model()->index(i,14);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_12->setChecked(false);
        }
        else
        {
            ui->checkBox_12->setChecked(true);
        }
        index=ui->tableView->model()->index(i,15);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_13->setChecked(false);
        }
        else
        {
            ui->checkBox_13->setChecked(true);
        }
        index=ui->tableView->model()->index(i,16);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_14->setChecked(false);
        }
        else
        {
            ui->checkBox_14->setChecked(true);
        }
        index=ui->tableView->model()->index(i,17);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_15->setChecked(false);
        }
        else
        {
            ui->checkBox_15->setChecked(true);
        }
        index=ui->tableView->model()->index(i,18);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_5->setChecked(false);
        }
        else
        {
            ui->checkBox_5->setChecked(true);
        }
        index=ui->tableView->model()->index(i,19);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_16->setChecked(false);
        }
        else
        {
            ui->checkBox_16->setChecked(true);
        }
        index=ui->tableView->model()->index(i,20);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_17->setChecked(false);
        }
        else
        {
            ui->checkBox_17->setChecked(true);
        }
        index=ui->tableView->model()->index(i,21);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_18->setChecked(false);
        }
        else
        {
            ui->checkBox_18->setChecked(true);
        }
        index=ui->tableView->model()->index(i,22);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_19->setChecked(false);
        }
        else
        {
            ui->checkBox_19->setChecked(true);
        }
        index=ui->tableView->model()->index(i,23);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_20->setChecked(false);
        }
        else
        {
            ui->checkBox_20->setChecked(true);
        }
        index=ui->tableView->model()->index(i,24);
        if (index.data().toInt() == 0)
        {
            ui->checkBox_21->setChecked(false);
        }
        else
        {
            ui->checkBox_21->setChecked(true);
        }
        index=ui->tableView->model()->index(i,25);
        Valor = index.data().toString();
        if (Valor != "")
        {
            QImage image(""+Valor+"");
            ui->label_11->setPixmap(QPixmap::fromImage(image));
            ui->label_11->setScaledContents(true);
            ui->label_11->adjustSize();
        }
        else
        {
            ui->label_11->setText(tr("<center>Sin<p><center>imagen<p><center>disponible<p>"));
        }
        index=ui->tableView->model()->index(i,26);
        ui->lineEdit_4->setText(tr(index.data().toString()));
        index=ui->tableView->model()->index(i,27);
        ui->lineEdit_3->setText(tr(index.data().toString()));
        index=ui->tableView->model()->index(i,28);
        if (index.data().toInt() == 0)
        {
            ui->radioButton_6->setChecked(true);
        }
        else if (index.data().toInt() == 1)
        {
            ui->radioButton_7->setChecked(true);
        }
        else if (index.data().toInt() == 2)
        {
            ui->radioButton_8->setChecked(true);
        }
        else if (index.data().toInt() == 3)
        {
            ui->radioButton_9->setChecked(true);
        }
        else if (index.data().toInt() == 4)
        {
            ui->radioButton_10->setChecked(true);
        }
        else if (index.data().toInt() == 5)
        {
            ui->radioButton_11->setChecked(true);
        }
        else if (index.data().toInt() == 6)
        {
            ui->radioButton_12->setChecked(true);
        }
        else if (index.data().toInt() == 7)
        {
            ui->radioButton_13->setChecked(true);
        }
        else if (index.data().toInt() == 8)
        {
            ui->radioButton_15->setChecked(true);
        }
        else if (index.data().toInt() == 9)
        {
            ui->radioButton_14->setChecked(true);
        }
        else if (index.data().toInt() == 10)
        {
            ui->radioButton_16->setChecked(true);
        }
        index=ui->tableView->model()->index(i,29);
        ui->textEdit_2->setText(tr(index.data().toString()));
        index=ui->tableView->model()->index(i,30);
        ui->lineEdit_7->setText(tr(index.data().toString()));
        index=ui->tableView->model()->index(i,31);
        ui->lineEdit_6->setText(tr(index.data().toString()));
        index=ui->tableView->model()->index(i,32);
        if (index.data().toInt() == 0)
        {
            ui->radioButton_17->setChecked(true);
        }
        else if (index.data().toInt() == 1)
        {
            ui->radioButton_18->setChecked(true);
        }
        index=ui->tableView->model()->index(i,33);
        tiempo = index.data().toString();
        tempo = tiempo.split(":");
        int Tiempo1 = tempo.value(0).toInt();
        int Tiempo2 = tempo.value(1).toInt();
        int Tiempo3 = tempo.value(2).toInt();
        QTime time(Tiempo1, Tiempo2, Tiempo3);
        ui->timeEdit->setTime(time);
        index=ui->tableView->model()->index(i,34);
        if (index.data().toInt() == 0)
        {
            ui->radioButton_19->setChecked(true);
        }
        else if (index.data().toInt() == 1)
        {
            ui->radioButton_20->setChecked(true);
        }
        index=ui->tableView->model()->index(i,35);
        if (index.data().toInt() == 0)
        {
            ui->radioButton_22->setChecked(true);
        }
        else if (index.data().toInt() == 1)
        {
            ui->radioButton_24->setChecked(true);
        }
        else if (index.data().toInt() == 2)
        {
            ui->radioButton_23->setChecked(true);
        }
        index=ui->tableView->model()->index(i,36);
        ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(index.data().toString()));
        index=ui->tableView->model()->index(i,37);
        ui->lineEdit_9->setText(index.data().toString());
        index=ui->tableView->model()->index(i,38);
        ui->lineEdit_10->setText(index.data().toString());
        this->fila=i;
        QSqlQuery query(db);
        query.exec("SELECT id FROM pelis");
        query.last();
        int valor = query.value(0).toInt();
        ui->label_15->setText(""+QString::number(fila+1)+"/"+QString::number(valor)+"");
}

void dbpelis::changeEvent(QEvent *e)
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

void dbpelis::on_pushButton_4_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void dbpelis::on_pushButton_clicked()
{
    QString titulo,titulo1,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico;
    QString policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis;
    QString soporte,posicion,visionada,duracion,color,vose,formato,director,fecha;
    titulo = ui->lineEdit->text();
    if (titulo == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se puede insertar si no se ha introducido como minimo el campo titulo de pelicula."));
        m.exec();
        return;
    }
    titulo1 = ui->lineEdit_2->text();
    if (ui->radioButton->isChecked() == true)
    {
        edad="0";
    }
    else if (ui->radioButton_2->isChecked() == true)
    {
        edad="1";
    }
    else if (ui->radioButton_3->isChecked() == true)
    {
        edad="2";
    }
    else if (ui->radioButton_4->isChecked() == true)
    {
        edad="3";
    }
    else if (ui->radioButton_5->isChecked() == true)
    {
        edad="4";
    }
    else if (ui->radioButton_21->isChecked() == true)
    {
        edad="5";
    }
    else if (ui->radioButton_25->isChecked() == true)
    {
        edad="6";
    }
    if (ui->checkBox->isChecked() == false)
    {
        drama="0";
    }
    else
    {
        drama="1";
    }
    if (ui->checkBox_2->isChecked() == false)
    {
        comedia="0";
    }
    else
    {
        comedia="1";
    }
    if (ui->checkBox_3->isChecked() == false)
    {
        accion="0";
    }
    else
    {
        accion="1";
    }
    if (ui->checkBox_4->isChecked() == false)
    {
        aventura="0";
    }
    else
    {
        aventura="1";
    }
    if (ui->checkBox_6->isChecked() == false)
    {
        scifi="0";
    }
    else
    {
        scifi="1";
    }
    if (ui->checkBox_7->isChecked() == false)
    {
        romantica="0";
    }
    else
    {
        romantica="1";
    }
    if (ui->checkBox_8->isChecked() == false)
    {
        musical="0";
    }
    else
    {
        musical="1";
    }
    if (ui->checkBox_9->isChecked() == false)
    {
        catastrofes="0";
    }
    else
    {
        catastrofes="1";
    }
    if (ui->checkBox_10->isChecked() == false)
    {
        suspense="0";
    }
    else
    {
        suspense="1";
    }
    if (ui->checkBox_11->isChecked() == false)
    {
        fantasia="0";
    }
    else
    {
        fantasia="1";
    }
    if (ui->checkBox_12->isChecked() == false)
    {
        erotico="0";
    }
    else
    {
        erotico="1";
    }
    if (ui->checkBox_13->isChecked() == false)
    {
        porno="0";
    }
    else
    {
        porno="1";
    }
    if (ui->checkBox_14->isChecked() == false)
    {
        historico="0";
    }
    else
    {
        historico="1";
    }
    if (ui->checkBox_15->isChecked() == false)
    {
        policiaco="0";
    }
    else
    {
        policiaco="1";
    }
    if (ui->checkBox_5->isChecked() == false)
    {
        terror="0";
    }
    else
    {
        terror="1";
    }
    if (ui->checkBox_16->isChecked() == false)
    {
        western="0";
    }
    else
    {
        western="1";
    }
    if (ui->checkBox_17->isChecked() == false)
    {
        belico="0";
    }
    else
    {
        belico="1";
    }
    if (ui->checkBox_18->isChecked() == false)
    {
        deportes="0";
    }
    else
    {
        deportes="1";
    }
    if (ui->checkBox_19->isChecked() == false)
    {
        animacion="0";
    }
    else
    {
        animacion="1";
    }
    if (ui->checkBox_20->isChecked() == false)
    {
        documental="0";
    }
    else
    {
        documental="1";
    }
    if (ui->checkBox_21->isChecked() == false)
    {
        gore_zombies="0";
    }
    else
    {
        gore_zombies="1";
    }
    caratula = fileNameOrigen;
    actor = ui->lineEdit_4->text();
    secundario = ui->lineEdit_3->text();
    if (ui->radioButton_6->isChecked() == true)
    {
        calificacion="0";
    }
    else if (ui->radioButton_7->isChecked() == true)
    {
        calificacion="1";
    }
    else if ( ui->radioButton_8->isChecked() == true)
    {
        calificacion="2";
    }
    else if (ui->radioButton_9->isChecked() == true)
    {
        calificacion="3";
    }
    else if (ui->radioButton_10->isChecked() == true)
    {
        calificacion="4";
    }
    else if (ui->radioButton_11->isChecked() == true)
    {
        calificacion="5";
    }
    else if (ui->radioButton_12->isChecked() == true)
    {
        calificacion="6";
    }
    else if (ui->radioButton_13->isChecked() == true)
    {
        calificacion="7";
    }
    else if (ui->radioButton_15->isChecked() == true)
    {
        calificacion="8";
    }
    else if (ui->radioButton_14->isChecked() == true)
    {
        calificacion="9";
    }
    else if (ui->radioButton_16->isChecked() == true)
    {
        calificacion="10";
    }
    sinopsis = ui->textEdit_2->toPlainText();
    soporte = ui->lineEdit_7->text();
    posicion = ui->lineEdit_6->text();
    if (ui->radioButton_17->isChecked() == true)
    {
        visionada="0";
    }
    else if (ui->radioButton_18->isChecked() == true)
    {
        visionada="1";
    }
    duracion = ui->timeEdit->time().toString("HH:mm:ss");
    if (ui->radioButton_19->isChecked() == true)
    {
        color="0";
    }
    else if (ui->radioButton_20->isChecked() == true)
    {
        color="1";
    }
    if (ui->radioButton_22->isChecked() == true)
    {
        vose="0";
    }
    else if (ui->radioButton_24->isChecked() == true)
    {
        vose="1";
    }
    else if (ui->radioButton_23->isChecked() == true)
    {
        vose="2";
    }
    formato = ui->comboBox_2->currentText();
    director = ui->lineEdit_9->text();
    fecha= ui->lineEdit_10->text();
    QSqlQuery query1(db);
    query1.exec("SELECT titulo FROM pelis WHERE titulo='"+titulo+"'");
    query1.first();
    if (query1.isSelect())
        Cantidad=query1.value(0).toString();
    if (titulo == Cantidad)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se pueden duplicar titulos de peliculas. Cambia los datos del campo titulo para poder insertar."));
        m.exec();
        return;
    }
    QSqlQuery query(db);
    query.prepare("INSERT INTO pelis (titulo,titulo_original,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico,policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis,soporte,posicion,visionada,duracion,color,vose,formato,director,fecha)"
                  "VALUES (:titulo,:titulo1,:edad,:drama,:comedia,:accion,:aventura,:scifi,:romantica,:musical,:catastrofes,:suspense,:fantasia,:erotico,:porno,:historico,:policiaco,:terror,:western,:belico,:deportes,:animacion,:documental,:gore_zombies,:caratula,:actor,:secundario,:calificacion,:sinopsis,:soporte,:posicion,:visionada,:duracion,:color,:vose,:formato,:director,:fecha)");
    query.bindValue(":titulo", titulo);
    query.bindValue(":titulo1", titulo1);
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
    query.bindValue(":fecha", fecha);
    query.exec();
    Model->select();
    ui->tableView->setModel(Model);
}

void dbpelis::on_pushButton_10_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de imagen")),
                        path,trUtf8(tr("Todos los ficheros de imagen soportados (*.png *jpg)")));
    if (fileNameOrigen.isEmpty())
        return;

    QImage image(""+fileNameOrigen+"");
    ui->label_11->setPixmap(QPixmap::fromImage(image));
    ui->label_11->setScaledContents(true);
    ui->label_11->adjustSize();
}

void dbpelis::on_pushButton_3_clicked()
{
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Borrar pelicula")),
                 QString::fromUtf8(tr("<center><b>Confirmar borrado de pelicula</center><p>"
                 "Vas a proceder al borrado de la pelicula...<p>"
                 "<b>"+ui->lineEdit->text()+"</b><p>"
                 "&iquest;Borrar pelicula?")), QMessageBox::Ok, QMessageBox::No);
     if (respuesta == QMessageBox::Ok)
     {
         ui->tableView->model()->removeRow(fila);
     }
     else if (respuesta == QMessageBox::No)
     {
         return;
     }
}

void dbpelis::on_pushButton_6_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->radioButton_25->setChecked(true);
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    ui->checkBox_11->setChecked(false);
    ui->checkBox_12->setChecked(false);
    ui->checkBox_13->setChecked(false);
    ui->checkBox_14->setChecked(false);
    ui->checkBox_15->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_16->setChecked(false);
    ui->checkBox_17->setChecked(false);
    ui->checkBox_18->setChecked(false);
    ui->checkBox_19->setChecked(false);
    ui->checkBox_20->setChecked(false);
    ui->checkBox_21->setChecked(false);
    ui->label_11->setText(tr("<center>Sin<p><center>imagen<p><center>disponible<p>"));
    ui->lineEdit_4->setText("");
    ui->lineEdit_3->setText("");
    ui->radioButton_12->setChecked(true);
    ui->textEdit_2->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_6->setText("");
    ui->radioButton_18->setChecked(true);
    QTime time(0, 0, 0);
    ui->timeEdit->setTime(time);
    ui->radioButton_19->setChecked(true);
    ui->radioButton_23->setChecked(true);
    ui->comboBox_2->setCurrentItem(1);
    ui->lineEdit_9->setText("");
    ui->lineEdit_10->setText("");
}

void dbpelis::on_comboBox_currentIndexChanged(QString busca)
{
    if (busca == "Sin filtro (todas las peliculas)")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("titulo like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("titulo != '""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(1,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Titulo")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("titulo like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("titulo != '""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(1,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Titulo original")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("titulo_original like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("titulo_original != '""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(2,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Calificacion: Todos los publicos")
    {
       Model->setFilter("edad like '0'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Calificacion: N.R. a menores de 7")
    {
       Model->setFilter("edad like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Calificacion: N.R. a menores de 12")
    {
       Model->setFilter("edad like '2'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Calificacion: N.R. a menores de 16")
    {
       Model->setFilter("edad like '3'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Calificacion: N.R. a menores de 18")
    {
       Model->setFilter("edad like '4'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Calificacion: Adultos")
    {
       Model->setFilter("edad like '5'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Calificacion: Sin clasificar")
    {
       Model->setFilter("edad like '6'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Drama")
    {
       Model->setFilter("drama like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Comedia")
    {
       Model->setFilter("comedia like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Accion")
    {
       Model->setFilter("accion like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Aventura")
    {
       Model->setFilter("aventura like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Ciencia-Ficcion")
    {
       Model->setFilter("scifi like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Romantica")
    {
       Model->setFilter("romantica like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Musical")
    {
       Model->setFilter("musical like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Catastrofes")
    {
       Model->setFilter("catastrofes like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Suspense")
    {
       Model->setFilter("suspense like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Fantasia")
    {
       Model->setFilter("fantasia like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Erotico")
    {
       Model->setFilter("erotico like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Porno")
    {
       Model->setFilter("porno like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Historico")
    {
       Model->setFilter("historico like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Policiaco")
    {
       Model->setFilter("policiaco like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Terror")
    {
       Model->setFilter("terror like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Western")
    {
       Model->setFilter("western like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Belico")
    {
       Model->setFilter("belico like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Deportes")
    {
       Model->setFilter("deportes like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Animacion/Dibujos")
    {
       Model->setFilter("animacion like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Documental")
    {
       Model->setFilter("documental like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Gore/Zombies")
    {
       Model->setFilter("gore_zombies like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Actor principal")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("actor like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("actor !='""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(26,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Actor secundario")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("secundario like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("secundario !='""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(27,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Valoracion: 0")
    {
       Model->setFilter("calificacion like '0'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 1")
    {
       Model->setFilter("calificacion like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 2")
    {
       Model->setFilter("calificacion like '2'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 3")
    {
       Model->setFilter("calificacion like '3'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 4")
    {
       Model->setFilter("calificacion like '4'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 5")
    {
       Model->setFilter("calificacion like '5'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 6")
    {
       Model->setFilter("calificacion like '6'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 7")
    {
       Model->setFilter("calificacion like '7'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 8")
    {
       Model->setFilter("calificacion like '8'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 9")
    {
       Model->setFilter("calificacion like '9'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 10 (Obra Maestra)")
    {
       Model->setFilter("calificacion like '10'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Soporte")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("soporte like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("soporte !='""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(30,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Posicion")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("posicion like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("posicion !='""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(31,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Visionada: Si")
    {
       Model->setFilter("visionada like '0'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Visionada: No")
    {
       Model->setFilter("visionada like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Color")
    {
       Model->setFilter("color like '0'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "B/W")
    {
       Model->setFilter("color like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Version Original")
    {
       Model->setFilter("vose like '0'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Subtitulada")
    {
       Model->setFilter("vose like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Doblada")
    {
       Model->setFilter("vose like '2'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: DVD")
    {
       Model->setFilter("formato like 'DVD'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: avi")
    {
       Model->setFilter("formato like 'avi'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: VCD")
    {
       Model->setFilter("formato like 'VCD'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: VHS")
    {
       Model->setFilter("formato like 'VHS'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: mkv")
    {
       Model->setFilter("formato like 'mkv'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: LD")
    {
       Model->setFilter("formato like 'LD'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: B-Ray")
    {
       Model->setFilter("formato like 'B-Ray'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Director")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("director like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("director !='""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(37,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Fecha")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("fecha like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("fecha !='""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(38,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
}

void dbpelis::orden()
{
    QString busca;
    busca = ui->comboBox->currentText();
    if (busca == "Sin filtro (todas las peliculas)")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("titulo like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("titulo != '""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(1,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Titulo")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("titulo like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("titulo != '""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(1,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Titulo original")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("titulo_original like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("titulo_original != '""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(2,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Calificacion: Todos los publicos")
    {
       Model->setFilter("edad like '0'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Calificacion: N.R. a menores de 7")
    {
       Model->setFilter("edad like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Calificacion: N.R. a menores de 12")
    {
       Model->setFilter("edad like '2'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Calificacion: N.R. a menores de 16")
    {
       Model->setFilter("edad like '3'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Calificacion: N.R. a menores de 18")
    {
       Model->setFilter("edad like '4'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Calificacion: Adultos")
    {
       Model->setFilter("edad like '5'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Calificacion: Sin clasificar")
    {
       Model->setFilter("edad like '6'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Drama")
    {
       Model->setFilter("drama like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Comedia")
    {
       Model->setFilter("comedia like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Accion")
    {
       Model->setFilter("accion like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Aventura")
    {
       Model->setFilter("aventura like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Ciencia-Ficcion")
    {
       Model->setFilter("scifi like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Romantica")
    {
       Model->setFilter("romantica like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Musical")
    {
       Model->setFilter("musical like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Catastrofes")
    {
       Model->setFilter("catastrofes like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Suspense")
    {
       Model->setFilter("suspense like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Fantasia")
    {
       Model->setFilter("fantasia like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Erotico")
    {
       Model->setFilter("erotico like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Porno")
    {
       Model->setFilter("porno like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Historico")
    {
       Model->setFilter("historico like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Policiaco")
    {
       Model->setFilter("policiaco like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Terror")
    {
       Model->setFilter("terror like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Western")
    {
       Model->setFilter("western like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Belico")
    {
       Model->setFilter("belico like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Deportes")
    {
       Model->setFilter("deportes like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Animacion/Dibujos")
    {
       Model->setFilter("animacion like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Documental")
    {
       Model->setFilter("documental like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Genero: Gore/Zombies")
    {
       Model->setFilter("gore_zombies like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Actor principal")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("actor like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("actor !='""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(26,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Actor secundario")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("secundario like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("secundario !='""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(27,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Valoracion: 0")
    {
       Model->setFilter("calificacion like '0'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 1")
    {
       Model->setFilter("calificacion like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 2")
    {
       Model->setFilter("calificacion like '2'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 3")
    {
       Model->setFilter("calificacion like '3'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 4")
    {
       Model->setFilter("calificacion like '4'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 5")
    {
       Model->setFilter("calificacion like '5'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 6")
    {
       Model->setFilter("calificacion like '6'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 7")
    {
       Model->setFilter("calificacion like '7'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 8")
    {
       Model->setFilter("calificacion like '8'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 9")
    {
       Model->setFilter("calificacion like '9'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Valoracion: 10 (Obra Maestra)")
    {
       Model->setFilter("calificacion like '10'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Soporte")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("soporte like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("soporte !='""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(30,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Posicion")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("posicion like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("posicion !='""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(31,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Visionada: Si")
    {
       Model->setFilter("visionada like '0'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Visionada: No")
    {
       Model->setFilter("visionada like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Color")
    {
       Model->setFilter("color like '0'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "B/W")
    {
       Model->setFilter("color like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Version Original")
    {
       Model->setFilter("vose like '0'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Subtitulada")
    {
       Model->setFilter("vose like '1'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Doblada")
    {
       Model->setFilter("vose like '2'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: DVD")
    {
       Model->setFilter("formato like 'DVD'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: avi")
    {
       Model->setFilter("formato like 'avi'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: VCD")
    {
       Model->setFilter("formato like 'VCD'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: VHS")
    {
       Model->setFilter("formato like 'VHS'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: mkv")
    {
       Model->setFilter("formato like 'mkv'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: LD")
    {
       Model->setFilter("formato like 'LD'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Formato: B-Ray")
    {
       Model->setFilter("formato like 'B-Ray'");
       ui->tableView->setModel(Model);
       ui->lineEdit_8->setDisabled(true);
       if (ui->checkBox_22->isChecked() == true)
       {
           ui->tableView->sortByColumn(1,Qt::SortOrder(0));
       }
       else
       {
           ui->tableView->sortByColumn(0,Qt::SortOrder(0));
       }
    }
    if (busca == "Director")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("director like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("director !='""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(37,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
    if (busca == "Fecha")
    {
        ui->lineEdit_8->setDisabled(false);
        if (ui->lineEdit_8->text() != "")
        {
            Model->setFilter("fecha like '%"+ui->lineEdit_8->text()+"%'");
        }
        else
        {
            Model->setFilter("fecha !='""'");
        }
        ui->tableView->setModel(Model);
        if (ui->checkBox_22->isChecked() == true)
        {
            ui->tableView->sortByColumn(38,Qt::SortOrder(0));
        }
        else
        {
            ui->tableView->sortByColumn(0,Qt::SortOrder(0));
        }
    }
}

void dbpelis::on_pushButton_7_clicked()
{
    ui->tableView->selectRow(fila-1);
}

void dbpelis::on_pushButton_8_clicked()
{
    ui->tableView->selectRow(fila+1);
}

void dbpelis::on_pushButton_11_clicked()
{
    if (ui->tableView->model()->rowCount() != 0)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Borrado de base de datos de peliculas")),
                               QString::fromUtf8(tr("<center><b>Borrado de base de datos de peliculas<b></center><p>"
                               "Se borrara toda la lista de peliculas, por lo que no se podra recuperar.</B><p>"
                               "Como es algo muy peligroso, ya que puedes perder datos muy importantes, tendras que introducir la clave "
                               "de usuario para realizar este paso.<p>"
                               "&iquest;Estas seguro de borrar la base de datos de peliculas?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            Desbloquear *pass=new Desbloquear(this);
            if (Stilo == "A")
                pass->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            pass->exec();
            DatoRev=pass->Resultado;
            if (DatoRev == "1")
            {                
                QSqlQuery query(db);
                query.exec("Delete from pelis");
                Model->select();
                ui->tableView->setModel(Model);
            }
            else if(DatoRev == "0")
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Sin una clave valida no vas a poder borrar la base de datos."));
                m.exec();
                return;
            }
        }
        return;
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Nada que procesar."));
        m.exec();
        return;
    }
}

void dbpelis::on_pushButton_5_clicked()
{
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Importar fichero .cvs")),
                           QString::fromUtf8(tr("<b>Importar fichero .cvs</b><p>"
                           "Es importante que diferencies en el fichero .cvs que hayas generado, los "
                           "saltos de linea correctos, para que no interfieran en los datos a importar.<p>"
                           "Te recomiendo que no utilices la coma (,) ya que es comun en el titulo de las "
                           "peliculas, al igual que el punto (.). Yo recomiendo el standar punto y coma (;) que "
                           "es el mas comun, aunque el tabulador (tab) seria el mas idoneo. Comprueba antes de "
                           "importar cual has definido por defecto.</p>"
                           "Se insertaran los nuevos registros al final de la tabla.<p>"
                           "&iquest;Importar fichero .cvs?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        QString path=tr("/home/%1/Documentos/");
        path=path.arg(user);
        fileNameOrigen = QFileDialog::getOpenFileName(this,QString::fromUtf8(tr("Abrir archivo de texto en formato .csv")),
                            path,trUtf8(tr("Fichero .csv (*.csv)")));
        if (fileNameOrigen.isEmpty())
            return;
        QFile file(fileNameOrigen);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in(&file);
        QString datoslst = in.readAll();
        file.close();
        QStringList datos = datoslst.split("\n");
        if (import != 0)
            delete import;
        import=new importar(this);
        if (Stilo == "A")
            import->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        import->Valor(datos);
        import->exec();
        QString Recibido=import->Resultado;
        if (Recibido == "Negativo")
        {
            return;
        }
        else if (Recibido == "Positivo")
        {
            Model->select();
            ui->tableView->setModel(Model);
        }
    }
    else if (respuesta == QMessageBox::No)
    {
        return;
    }
}

void dbpelis::on_pushButton_9_clicked()
{
    int posicion;
    QPrinter usu(QPrinter::HighResolution);
    QPainter txt;
    QFont font;
    QColor color, color1;
    QPen pen;
    QPen pen1;
    QString NomOrden, NomOrdenFin;
    int LocPos;
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Definir tipo de letra y datos")),
                           QString::fromUtf8(tr("<b>Definir tipo, proporcion y grosor de letra y orden de datos.</b><p>"
                           "Puedes definir el tipo de letra que quieras "
                           "con las caracteristicas de grosor, proporcion, color, etc.<p>"
                           "Por defecto es... Familia: HELVETICA, Proporcion: 6, Grosor: NORMAL.<p>"
                           "Tambien puedes ordenar por cualquier tipo de dato, aunque siempre iran por defecto los datos "
                           "de Titulo o Titulo original, Soporte y Posicion por razones obvias.</p>"
                           "&iquest;Definir tipo de letra?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        ordenar *Orden=new ordenar();
        if (Stilo == "A")
            Orden->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        Orden->Dato("pelis");
        Orden->exec();
        NomOrden=Orden->NOrden;
        font=Orden->TLetra;
        color=Orden->TColor;
        color1=Orden->TColor1;
        if (NomOrden == "")
        {
            NomOrden="Titulo";
            font = QFont("Helvetica",6,50);
            color = QColor(Qt::black);
            color1= QColor(Qt::black);
        }
    }
    else if (respuesta == QMessageBox::No)
    {
        NomOrden="Titulo";
        font = QFont("Helvetica",6,50);
        color = QColor(Qt::black);
        color1= QColor(Qt::black);
    }
    QFontMetrics medidas(font);
    QPrintDialog *dialog = new QPrintDialog(&usu, this);
    dialog->setWindowTitle(tr("Imprimir listado de peliculas por orden de "+NomOrden+""));
    dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if (dialog->exec() == QDialog::Accepted)
    {
        // imprimir(&usu, NomOrden, font, color, color1);
        txt.begin(&usu);
        txt.setFont(font);
        pen.setColor(color);
        pen1.setColor(color1);
        QRect columnas[4];
        columnas[0].setRect(10, medidas.lineSpacing(), usu.pageRect().width() / 2, medidas.lineSpacing());
        int anchoColumna = columnas[0].width() / 3;
        columnas[1].setRect(columnas[0].x() + columnas[0].width(), medidas.lineSpacing(), anchoColumna, medidas.lineSpacing());
        columnas[2].setRect(columnas[1].x() + columnas[1].width(), medidas.lineSpacing(), anchoColumna, medidas.lineSpacing());
        columnas[3].setRect(columnas[2].x() + columnas[2].width(), medidas.lineSpacing(), anchoColumna, medidas.lineSpacing());
        posicion = medidas.lineSpacing();
        bool sombrear = false;
        QSqlQuery pelis(db);
        LocPos=0;
        if (NomOrden == "Sin filtro (todas las peliculas)")
        {
            NomOrdenFin= "titulo";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Titulo")
        {
            NomOrdenFin="titulo";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Titulo original")
        {
            NomOrdenFin="titulo_original";
            LocPos=1;
            pelis.exec("SELECT titulo_original,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" !='' ORDER BY "+NomOrdenFin+" ASC ");
        }
        else if (NomOrden == "Calificacion: Todos los publicos")
        {
            NomOrdenFin="edad";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '0' ORDER BY Soporte ASC");
        }
        else if (NomOrden == "Calificacion: N.R. a menores de 7")
        {
            NomOrdenFin="edad";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '1' ORDER BY Soporte ASC");
        }
        else if (NomOrden == "Calificacion: N.R. a menores de 12")
        {
            NomOrdenFin="edad";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '2' ORDER BY Soporte ASC");
        }
        else if (NomOrden == "Calificacion: N.R. a menores de 16")
        {
            NomOrdenFin="edad";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '3' ORDER BY Soporte ASC");
        }
        else if (NomOrden == "Calificacion: N.R. a menores de 18")
        {
            NomOrdenFin="edad";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '4' ORDER BY Soporte ASC");
        }
        else if (NomOrden == "Calificacion: Adultos")
        {
            NomOrdenFin="edad";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '5' ORDER BY Soporte ASC");
        }
        else if (NomOrden == "Calificacion: Sin clasificar")
        {
            NomOrdenFin="edad";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '6' ORDER BY Soporte ASC");
        }
        else if (NomOrden == "Genero: Drama")
        {
            NomOrdenFin="drama";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Comedia")
        {
            NomOrdenFin="comedia";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Accion")
        {
            NomOrdenFin="accion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Aventura")
        {
            NomOrdenFin="aventura";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Ciencia-Ficcion")
        {
            NomOrdenFin="scifi";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Romantica")
        {
            NomOrdenFin="romantica";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Musical")
        {
            NomOrdenFin="musical";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Catastrofes")
        {
            NomOrdenFin="catastrofes";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Suspense")
        {
            NomOrdenFin="suspense";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Fantasia")
        {
            NomOrdenFin="fantasia";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Erotico")
        {
            NomOrdenFin="erotico";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Porno")
        {
            NomOrdenFin="porno";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Historico")
        {
            NomOrdenFin="historico";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Policiaco")
        {
            NomOrdenFin="policiaco";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Terror")
        {
            NomOrdenFin="terror";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Western")
        {
            NomOrdenFin="western";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Belico")
        {
            NomOrdenFin="belico";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Deportes")
        {
            NomOrdenFin="deportes";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Animacion/Dibujos")
        {
            NomOrdenFin="animacion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Documental")
        {
            NomOrdenFin="documental";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Genero: Gore/Zombies")
        {
            NomOrdenFin="gore";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '0' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if (NomOrden == "Actor principal")
        {
            NomOrdenFin="actor";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if(NomOrden == "Actor secundario")
        {
            NomOrdenFin="secundario";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if(NomOrden == "Valoracion: 0")
        {
            NomOrdenFin="calificacion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '0' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Valoracion: 1")
        {
            NomOrdenFin="calificacion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '1' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Valoracion: 2")
        {
            NomOrdenFin="calificacion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '2' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Valoracion: 3")
        {
            NomOrdenFin="calificacion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '3' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Valoracion: 4")
        {
            NomOrdenFin="calificacion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '4' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Valoracion: 5")
        {
            NomOrdenFin="calificacion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '5' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Valoracion: 6")
        {
            NomOrdenFin="calificacion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '6' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Valoracion: 7")
        {
            NomOrdenFin="calificacion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '7' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Valoracion: 8")
        {
            NomOrdenFin="calificacion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '8' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Valoracion: 9")
        {
            NomOrdenFin="calificacion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '9' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Valoracion: 10 (Obra Maestra)")
        {
            NomOrdenFin="calificacion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '10' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Soporte")
        {
            NomOrdenFin="soporte";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if(NomOrden == "Posicion")
        {
            NomOrdenFin="posicion";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '' ORDER BY Soporte ASC and "+NomOrdenFin+" ASC ");
        }
        else if(NomOrden == "Visionada: Si")
        {
            NomOrdenFin="visionada";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '0' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Visionada: No")
        {
            NomOrdenFin="visionada";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '1' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Color")
        {
            NomOrdenFin="color";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '0' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "B/W")
        {
            NomOrdenFin="color";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '1' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Version Original")
        {
            NomOrdenFin="vose";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '0' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Subtitulada")
        {
            NomOrdenFin="vose";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '1' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Doblada")
        {
            NomOrdenFin="vose";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = '2' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Formato: DVD")
        {
            NomOrdenFin="formato";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = 'DVD' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Formato: avi")
        {
            NomOrdenFin="formato";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = 'avi' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Formato: VCD")
        {
            NomOrdenFin="formato";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = 'VCD' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Formato: VHS")
        {
            NomOrdenFin="formato";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = 'VHS' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Formato: mkv")
        {
            NomOrdenFin="formato";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = 'mkv' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Formato: LD")
        {
            NomOrdenFin="formato";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = 'LD' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Formato: B-Ray")
        {
            NomOrdenFin="formato";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" = 'B-Ray' ORDER BY Soporte ASC");
        }
        else if(NomOrden == "Director")
        {
            NomOrdenFin="director";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '' ORDER BY "+NomOrdenFin+" ASC");
        }
        else if(NomOrden == "Fecha")
        {
            NomOrdenFin="fecha";
            pelis.exec("SELECT Titulo,Soporte,Posicion,visionada FROM Pelis WHERE "+NomOrdenFin+" != '' ORDER BY "+NomOrdenFin+" ASC");
        }
        while(pelis.next())
        {
            txt.setPen(pen);
            QString Titulo = pelis.value(0).toString();
            QString Soporte = pelis.value(1).toString();
            QString Posicion = pelis.value(2).toString();
            QString Visionada = pelis.value(3).toString();
            if (posicion > usu.pageRect().height())
            {
                usu.newPage();
                posicion = medidas.lineSpacing();
                columnas[0].moveTop(posicion);
                columnas[1].moveTop(posicion);
                columnas[2].moveTop(posicion);
                columnas[3].moveTop(posicion);
                sombrear = false;
            }
            if (posicion == medidas.lineSpacing())
            {
                txt.drawText(10,posicion,"Listado ordenado por... "+NomOrden+"");
                txt.setPen(pen1);
                if (LocPos==1)
                    txt.drawText(columnas[0], Qt::AlignHCenter, NomOrdenFin);
                else
                    txt.drawText(columnas[0], Qt::AlignHCenter, "Titulo");
                txt.drawText(columnas[1], Qt::AlignHCenter, "Soporte");
                txt.drawText(columnas[2], Qt::AlignHCenter, "Posicion");
                txt.drawText(columnas[3], Qt::AlignHCenter, "Visionada");
                txt.drawLine(columnas[0].x(), columnas[0].bottom(), columnas[3].x() + columnas[3].width(), columnas[3].bottom());
                columnas[0].translate(0, medidas.lineSpacing());
                columnas[1].translate(0, medidas.lineSpacing());
                columnas[2].translate(0, medidas.lineSpacing());
                columnas[3].translate(0, medidas.lineSpacing());
                posicion += medidas.lineSpacing();
                if(sombrear)
                {
                    txt.fillRect(columnas[0], Qt::lightGray);
                    txt.fillRect(columnas[1], Qt::lightGray);
                    txt.fillRect(columnas[2], Qt::lightGray);
                    txt.fillRect(columnas[3], Qt::lightGray);
                }
                sombrear = !sombrear;
                txt.setPen(pen);
                txt.drawText(columnas[0], Qt::AlignLeft, Titulo);
                txt.drawText(columnas[1], Qt::AlignRight, Soporte);
                txt.drawText(columnas[2], Qt::AlignRight, Posicion);
                txt.drawText(columnas[3], Qt::AlignHCenter, Visionada);
            }
            else
            {
                 if(sombrear)
                 {
                     txt.fillRect(columnas[0], Qt::lightGray);
                     txt.fillRect(columnas[1], Qt::lightGray);
                     txt.fillRect(columnas[2], Qt::lightGray);
                     txt.fillRect(columnas[3], Qt::lightGray);
                 }
                 sombrear = !sombrear;
                 txt.drawText(columnas[0], Qt::AlignLeft, Titulo);
                 txt.drawText(columnas[1], Qt::AlignRight, Soporte);
                 txt.drawText(columnas[2], Qt::AlignRight, Posicion);
                 txt.drawText(columnas[3], Qt::AlignHCenter, Visionada);
            }
            columnas[0].translate(0, medidas.lineSpacing());
            columnas[1].translate(0, medidas.lineSpacing());
            columnas[2].translate(0, medidas.lineSpacing());
            columnas[3].translate(0, medidas.lineSpacing());
            posicion += medidas.lineSpacing();
        }
        txt.end();
    }
}

void dbpelis::on_pushButton_2_clicked()
{
    QString titulo,titulo1,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico;
    QString policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis;
    QString soporte,posicion,visionada,duracion,color,vose,formato,director,fecha;
    titulo = ui->lineEdit->text();
    if (titulo == "")
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se puede modificar si no se tienen datos en el campo titulo de pelicula."));
        m.exec();
        return;
    }
    titulo1 = ui->lineEdit_2->text();
    if (ui->radioButton->isChecked() == true)
    {
        edad="0";
    }
    else if (ui->radioButton_2->isChecked() == true)
    {
        edad="1";
    }
    else if (ui->radioButton_3->isChecked() == true)
    {
        edad="2";
    }
    else if (ui->radioButton_4->isChecked() == true)
    {
        edad="3";
    }
    else if (ui->radioButton_5->isChecked() == true)
    {
        edad="4";
    }
    else if (ui->radioButton_21->isChecked() == true)
    {
        edad="5";
    }
    else if (ui->radioButton_25->isChecked() == true)
    {
        edad="6";
    }
    if (ui->checkBox->isChecked() == false)
    {
        drama="0";
    }
    else
    {
        drama="1";
    }
    if (ui->checkBox_2->isChecked() == false)
    {
        comedia="0";
    }
    else
    {
        comedia="1";
    }
    if (ui->checkBox_3->isChecked() == false)
    {
        accion="0";
    }
    else
    {
        accion="1";
    }
    if (ui->checkBox_4->isChecked() == false)
    {
        aventura="0";
    }
    else
    {
        aventura="1";
    }
    if (ui->checkBox_6->isChecked() == false)
    {
        scifi="0";
    }
    else
    {
        scifi="1";
    }
    if (ui->checkBox_7->isChecked() == false)
    {
        romantica="0";
    }
    else
    {
        romantica="1";
    }
    if (ui->checkBox_8->isChecked() == false)
    {
        musical="0";
    }
    else
    {
        musical="1";
    }
    if (ui->checkBox_9->isChecked() == false)
    {
        catastrofes="0";
    }
    else
    {
        catastrofes="1";
    }
    if (ui->checkBox_10->isChecked() == false)
    {
        suspense="0";
    }
    else
    {
        suspense="1";
    }
    if (ui->checkBox_11->isChecked() == false)
    {
        fantasia="0";
    }
    else
    {
        fantasia="1";
    }
    if (ui->checkBox_12->isChecked() == false)
    {
        erotico="0";
    }
    else
    {
        erotico="1";
    }
    if (ui->checkBox_13->isChecked() == false)
    {
        porno="0";
    }
    else
    {
        porno="1";
    }
    if (ui->checkBox_14->isChecked() == false)
    {
        historico="0";
    }
    else
    {
        historico="1";
    }
    if (ui->checkBox_15->isChecked() == false)
    {
        policiaco="0";
    }
    else
    {
        policiaco="1";
    }
    if (ui->checkBox_5->isChecked() == false)
    {
        terror="0";
    }
    else
    {
        terror="1";
    }
    if (ui->checkBox_16->isChecked() == false)
    {
        western="0";
    }
    else
    {
        western="1";
    }
    if (ui->checkBox_17->isChecked() == false)
    {
        belico="0";
    }
    else
    {
        belico="1";
    }
    if (ui->checkBox_18->isChecked() == false)
    {
        deportes="0";
    }
    else
    {
        deportes="1";
    }
    if (ui->checkBox_19->isChecked() == false)
    {
        animacion="0";
    }
    else
    {
        animacion="1";
    }
    if (ui->checkBox_20->isChecked() == false)
    {
        documental="0";
    }
    else
    {
        documental="1";
    }
    if (ui->checkBox_21->isChecked() == false)
    {
        gore_zombies="0";
    }
    else
    {
        gore_zombies="1";
    }
    caratula = fileNameOrigen;
    actor = ui->lineEdit_4->text();
    secundario = ui->lineEdit_3->text();
    if (ui->radioButton_6->isChecked() == true)
    {
        calificacion="0";
    }
    else if (ui->radioButton_7->isChecked() == true)
    {
        calificacion="1";
    }
    else if ( ui->radioButton_8->isChecked() == true)
    {
        calificacion="2";
    }
    else if (ui->radioButton_9->isChecked() == true)
    {
        calificacion="3";
    }
    else if (ui->radioButton_10->isChecked() == true)
    {
        calificacion="4";
    }
    else if (ui->radioButton_11->isChecked() == true)
    {
        calificacion="5";
    }
    else if (ui->radioButton_12->isChecked() == true)
    {
        calificacion="6";
    }
    else if (ui->radioButton_13->isChecked() == true)
    {
        calificacion="7";
    }
    else if (ui->radioButton_15->isChecked() == true)
    {
        calificacion="8";
    }
    else if (ui->radioButton_14->isChecked() == true)
    {
        calificacion="9";
    }
    else if (ui->radioButton_16->isChecked() == true)
    {
        calificacion="10";
    }
    sinopsis = ui->textEdit_2->toPlainText();
    soporte = ui->lineEdit_7->text();
    posicion = ui->lineEdit_6->text();
    if (ui->radioButton_17->isChecked() == true)
    {
        visionada="0";
    }
    else if (ui->radioButton_18->isChecked() == true)
    {
        visionada="1";
    }
    duracion = ui->timeEdit->time().toString("HH:mm:ss");
    if (ui->radioButton_19->isChecked() == true)
    {
        color="0";
    }
    else if (ui->radioButton_20->isChecked() == true)
    {
        color="1";
    }
    if (ui->radioButton_22->isChecked() == true)
    {
        vose="0";
    }
    else if (ui->radioButton_24->isChecked() == true)
    {
        vose="1";
    }
    else if (ui->radioButton_23->isChecked() == true)
    {
        vose="2";
    }
    formato = ui->comboBox_2->currentText();
    director = ui->lineEdit_9->text();
    fecha= ui->lineEdit_10->text();
    QSqlQuery query1(db);
    query1.exec("SELECT titulo FROM pelis WHERE titulo='"+titulo+"'");
    query1.first();
    QSqlRecord record= Model->record(this->fila);
    record.setValue(1,titulo);
    record.setValue(2,titulo1);
    record.setValue(3,edad);
    record.setValue(4,drama);
    record.setValue(5,comedia);
    record.setValue(6,accion);
    record.setValue(7,aventura);
    record.setValue(8,scifi);
    record.setValue(9,romantica);
    record.setValue(10,musical);
    record.setValue(11,catastrofes);
    record.setValue(12,suspense);
    record.setValue(13,fantasia);
    record.setValue(14,erotico);
    record.setValue(15,porno);
    record.setValue(16,historico);
    record.setValue(17,policiaco);
    record.setValue(18,terror);
    record.setValue(19,western);
    record.setValue(20,belico);
    record.setValue(21,deportes);
    record.setValue(22,animacion);
    record.setValue(23,documental);
    record.setValue(24,gore_zombies);
    record.setValue(25,caratula);
    record.setValue(26,actor);
    record.setValue(27,secundario);
    record.setValue(28,calificacion);
    record.setValue(29,sinopsis);
    record.setValue(30,soporte);
    record.setValue(31,posicion);
    record.setValue(32,visionada);
    record.setValue(33,duracion);
    record.setValue(34,color);
    record.setValue(35,vose);
    record.setValue(36,formato);
    record.setValue(37,director);
    record.setValue(38,fecha);
    Model->setRecord(this->fila,record);
    Model->submitAll();
}

void dbpelis::on_pushButton_12_clicked()
{
    Separador *Separa=new Separador(this);
    if (Stilo == "A")
        Separa->setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    Separa->Valor("Titulo;Director;Tiempo;Posicion;etc.");
    Separa->exec();
    QString SaltoDat=Separa->SaltoDato;
    if (SaltoDat == "Tab")
        SaltoDat = "\t";
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameDestino = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar archivo .csv")),
                      path,trUtf8(tr("Archivo .csv (*.csv)")));
    if (fileNameDestino.isEmpty())
        return;
    QString fileName = fileNameDestino.replace(" ", "\\ ").replace("&","\\&").replace("'","\\'").replace("(","\\(").replace(")","\\)").replace(".lst","");
    QFile file(""+fileName+".csv");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream in(&file);
    in << "Titulo" << SaltoDat << "Titulo Original" << SaltoDat << "Edad" << SaltoDat << "Drama" << SaltoDat <<  "Comedia" << SaltoDat << "Accion" << SaltoDat << "Aventura" << SaltoDat << "Scifi" << SaltoDat << "Romantica" << SaltoDat << "Musical" << SaltoDat << "Catastrofes" << SaltoDat << "Suspense" << SaltoDat << "Fantasia" << SaltoDat << "Erotico" << SaltoDat << "Porno" << SaltoDat << "Historico" << SaltoDat << "Policiaco" << SaltoDat << "Terror" << SaltoDat << "Western" << SaltoDat << "Belico" << SaltoDat << "Deportes" << SaltoDat << "Animacion" << SaltoDat << "Documental" << SaltoDat << "Gore_zombies" << SaltoDat << "Caratula" << SaltoDat << "Actor" << SaltoDat << "Secundario" << SaltoDat << "Calificacion" << SaltoDat << "Sinopsis" << SaltoDat << "Soporte" << SaltoDat << "Posicion" << SaltoDat << "Visionada" << SaltoDat << "Duracion" << SaltoDat << "Color" << SaltoDat << "Vose" << SaltoDat << "Formato" << SaltoDat << "Director" << SaltoDat << "Fecha" << "\n";
    QSqlQuery Acces(db);
    Acces.exec("SELECT COUNT(id) as Cantidad FROM pelis");
    int cuenta, comienzo;
    Acces.first();
    cuenta = Acces.value(0).toInt();
    QSqlQuery Acceso(db);
    Acceso.exec("SELECT titulo,titulo_original,edad,drama,comedia,accion,aventura,scifi,romantica,musical,catastrofes,suspense,fantasia,erotico,porno,historico,policiaco,terror,western,belico,deportes,animacion,documental,gore_zombies,caratula,actor,secundario,calificacion,sinopsis,soporte,posicion,visionada,duracion,color,vose,formato,fecha FROM pelis");
    setUpdatesEnabled(false);
    QProgressDialog progressPelis("Creando archivo... Espera por favor", "Cancelar", 0, cuenta);
    progressPelis.show();
    comienzo=0;
    while(Acceso.next())
    {
         qApp->processEvents();
         progressPelis.setValue(comienzo++);
         if (progressPelis.wasCanceled())
             break;
         QString titulo = Acceso.value(0).toString();
         titulo = titulo.replace("'", " ");
         QString titulo1 = Acceso.value(1).toString();
         titulo1 = titulo.replace("'", " ");
         QString edad = Acceso.value(2).toString();
         QString drama = Acceso.value(3).toString();
         QString comedia = Acceso.value(4).toString();
         QString accion = Acceso.value(5).toString();
         QString aventura = Acceso.value(6).toString();
         QString scifi = Acceso.value(7).toString();
         QString romantica = Acceso.value(8).toString();
         QString musical = Acceso.value(9).toString();
         QString catastrofes = Acceso.value(10).toString();
         QString suspense = Acceso.value(11).toString();
         QString fantasia = Acceso.value(12).toString();
         QString erotico = Acceso.value(13).toString();
         QString porno = Acceso.value(14).toString();
         QString historico = Acceso.value(15).toString();
         QString policiaco = Acceso.value(16).toString();
         QString terror = Acceso.value(17).toString();
         QString western = Acceso.value(18).toString();
         QString belico = Acceso.value(19).toString();
         QString deportes = Acceso.value(20).toString();
         QString animacion = Acceso.value(21).toString();
         QString documental = Acceso.value(22).toString();
         QString gore_zombies = Acceso.value(23).toString();
         QString caratula = Acceso.value(24).toString();
         QString actor = Acceso.value(25).toString();
         QString secundario = Acceso.value(26).toString();
         QString calificacion = Acceso.value(27).toString();
         QString sinopsis = Acceso.value(28).toString();
         QString soporte = Acceso.value(29).toString();
         QString posicion = Acceso.value(30).toString();
         QString visionada = Acceso.value(31).toString();
         QString duracion = Acceso.value(32).toString();
         QString color = Acceso.value(33).toString();
         QString vose = Acceso.value(34).toString();
         QString formato = Acceso.value(35).toString();
         QString director = Acceso.value(36).toString();
         QString fecha = Acceso.value(37).toString();
         in << titulo << SaltoDat << titulo1 << SaltoDat << edad << SaltoDat << drama << SaltoDat <<  comedia << SaltoDat << accion << SaltoDat << aventura << SaltoDat << scifi << SaltoDat << romantica << SaltoDat << musical << SaltoDat << catastrofes << SaltoDat << suspense << SaltoDat << fantasia << SaltoDat << erotico << SaltoDat << porno << SaltoDat << historico << SaltoDat << policiaco << SaltoDat << terror << SaltoDat << western << SaltoDat << belico << SaltoDat << deportes << SaltoDat << animacion << SaltoDat << documental << SaltoDat << gore_zombies << SaltoDat << caratula << SaltoDat << actor << SaltoDat << secundario << SaltoDat << calificacion << SaltoDat << sinopsis << SaltoDat << soporte << SaltoDat << posicion << SaltoDat << visionada << SaltoDat << duracion << SaltoDat << color << SaltoDat << vose << SaltoDat << formato << SaltoDat << director << SaltoDat << fecha << "\n";
    }
    progressPelis.setValue(cuenta);
    file.close();
    setUpdatesEnabled(true);
    QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    m.setText(tr("Exportacion a fichero realizada."));
    m.exec();
    return;
}

bool dbpelis::eventFilter(QObject* obj, QEvent *event)
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
        return false;
    }
    return QDialog::eventFilter(obj, event);
}
