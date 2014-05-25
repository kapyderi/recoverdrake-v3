#include "televideo.h"
#include "ui_televideo.h"
#include <QTest>
#include <QSqlQuery>
#include <QMessageBox>
#include <QInputDialog>
#include <QMouseEvent>
#include <QTimer>
#include <QDesktopWidget>

Televideo::Televideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Televideo)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    ui->pushButton->setEnabled(true);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    Model= new QSqlTableModel(0,db);
    Model->setTable("Television");
    Model->select();
    ui->tableView->setModel(Model);
    ui->tableView->setColumnHidden(0, true);
    connect(ui->tableView->selectionModel(),SIGNAL(currentChanged(QModelIndex,QModelIndex)),this,SLOT(cambiaFila(QModelIndex)));
    connect(ui->tableView, SIGNAL(pressed(QModelIndex)), this, SLOT(tableClicked()));
    Model1= new QSqlTableModel(0,db);
    Model1->setTable("PosTele");
    Model1->select();
    setMouseTracking(true);
    Contador = new QTimer(this);
    connect(Contador, SIGNAL(timeout()), this, SLOT(Comprobar()));
    Contador->stop();
    Value = "No";
    qApp->installEventFilter(this);
    Stilo = "B";
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
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

Televideo::~Televideo()
{
    delete ui;
    delete Model;
    delete Model1;
}

void Televideo::Valor(Phonon::MediaObject *mediaObject, Phonon::AudioOutput *audioOutput, Phonon::Path path, Phonon::Effect *effect)
{
    MediaObject = mediaObject;
    AudioOutput = audioOutput;
    Path = path;
    Effect = effect;
}

void Televideo::changeEvent(QEvent *e)
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

void Televideo::on_pushButton_7_clicked()
{
    if (ui->tableView->isShown() == true)
    {
        ui->tableView->hide();
        ui->pushButton_8->hide();
        ui->pushButton_7->setText(tr("Mostrar lista"));
    }
    else
    {
        ui->tableView->show();
        ui->pushButton_8->show();
        ui->pushButton_7->setText(tr("Ocultar lista"));
    }
}

void Televideo::on_pushButton_5_clicked()
{
    if (Value == "Si")
    {
        Value = "No";
        this->setWindowFlags(Qt::Dialog);        
        this->resize(w, h);
        this->showNormal();
        ui->widget->show();
        ui->pushButton_5->setText(tr("Pantalla completa"));
        Televideo::setCursor(Qt::ArrowCursor);
        QDesktopWidget screen;
        QRect screenGeom = screen.screenGeometry(this);
        int screenCenterX = screenGeom.center().x();
        int screenCenterY = screenGeom.center().y();
        move(screenCenterX - width () / 2, screenCenterY - height() / 2);
    }
    else if (Value == "No")
    {
        Value = "Si";
        w = this->width();
        h = this->height();
        this->showMaximized();
        while(this->isMaximized())
        {
              QTest::qWait(100);
              break;
        }
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
        this->resize(QApplication::desktop()->size());
        this->show();
        ui->widget->hide();
        ui->pushButton_5->setText(tr("Pantalla normal"));
        Televideo::setCursor(Qt::BlankCursor);
        Contador->stop();
    }
}

void Televideo::mouseDoubleClickEvent( QMouseEvent* )
{
    if (Value == "Si")
    {
        Value = "No";
        this->setWindowFlags(Qt::Dialog);        
        this->resize(w, h);
        this->showNormal();
        ui->widget->show();
        ui->pushButton_5->setText(tr("Pantalla completa"));
        Televideo::setCursor(Qt::ArrowCursor);
        QDesktopWidget screen;
        QRect screenGeom = screen.screenGeometry(this);
        int screenCenterX = screenGeom.center().x();
        int screenCenterY = screenGeom.center().y();
        move(screenCenterX - width () / 2, screenCenterY - height() / 2);
    }
    else if (Value == "No")
    {
        Value = "Si";
        w = this->width();
        h = this->height();
        this->showMaximized();
        while(this->isMaximized())
        {
              QTest::qWait(100);
              break;
        }
        this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
        this->resize(QApplication::desktop()->size());
        this->show();
        ui->widget->hide();
        ui->pushButton_5->setText(tr("Pantalla normal"));
        Televideo::setCursor(Qt::BlankCursor);
        Contador->stop();
    }
}

void Televideo::mouse()
{
    if (Value == "Si")
    {
        if (ui->widget->isHidden() == true)
        {
            ui->widget->show();
            Televideo::setCursor(Qt::ArrowCursor);
            Contador->start(2000);
        }
        else
        {
            ui->widget->hide();
            Televideo::setCursor(Qt::BlankCursor);
            Contador->stop();
        }
    }    
}

void Televideo::on_pushButton_4_clicked()
{
    if (ui->videoPlayer->isPlaying())
       ui->videoPlayer->stop();
    close();
}

bool Televideo::event( QEvent* event )
{
    switch( event->type() )
    {    
    case QEvent::KeyPress:
            this->mouse();
            break;
    case QEvent::MouseMove:       
    case QEvent::Leave:
    case QEvent::Enter:
    default:
            return QDialog::event( event );
            break;
    }
    return false;
}

bool Televideo::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        mouseEvent->accept();
        if (Value == "Si")
        {
            ui->widget->show();
            Televideo::setCursor(Qt::ArrowCursor);
            Contador->start(2000);
        }
    }
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_F1)
        {
            ayuda = new Ayuda(this);
            ayuda->show();
            ayuda->Valor(tr("TeleDrake"));
            return true;
        }
    }
    return false;
}

void Televideo::cambiaFila(QModelIndex actual)
{
        ActualRow=actual.row();
        QModelIndex index;
        index=ui->tableView->model()->index(ActualRow,0);
        this->id= index.data().toInt();
        index=ui->tableView->model()->index(ActualRow,1);
        index=ui->tableView->model()->index(ActualRow,2);
        index=ui->tableView->model()->index(ActualRow,3);
        Emisora = index.data().toString();
        this->filaVideo=ActualRow;
}

void Televideo::tableClicked()
{
    ui->videoPlayer->stop();
    QTest::qWait(500);
    ui->tableView->selectRow(ActualRow);
    ui->videoPlayer->load(Phonon::MediaSource(Emisora));;
    QSqlQuery Cancion(db);
    Cancion.exec("SELECT Posicion FROM PosTele WHERE id=1");
    Cancion.first();
    QSqlRecord record= Model1->record(0);
    record.setValue(0,1);
    record.setValue(1,ActualRow);
    Model1->setRecord(0,record);
    Model1->submitAll();
    this->play();
}

void Televideo::on_pushButton_clicked()
{
    if (ui->tableView->model()->rowCount() != 0)
    {
        int cantidad;
        QSqlQuery Cancion(db);
        Cancion.exec("SELECT Posicion FROM PosTele WHERE id=1");
        Cancion.first();
        if (Cancion.isValid())
            cantidad=Cancion.value(0).toInt();
        ui->tableView->selectRow(cantidad);
        ui->videoPlayer->load(Phonon::MediaSource(Emisora));;
        this->play();
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay nada en la lista de emisoras. Inserta alguna direccion de television por Internet."));
        m.exec();
        QSqlQuery Cancion(db);
        Cancion.exec("SELECT Posicion FROM PosTele WHERE id=1");
        Cancion.first();
        QSqlRecord record= Model1->record(0);
        record.setValue(0,1);
        record.setValue(1,0);
        Model1->setRecord(0,record);
        Model1->submitAll();
    }
}

void Televideo::play()
{
    QSqlQuery Cancion(db);
    Cancion.exec("SELECT Posicion FROM PosTele WHERE id=1");
    Cancion.first();
    QSqlRecord record= Model1->record(0);
    record.setValue(0,1);
    record.setValue(1,ActualRow);
    Model1->setRecord(0,record);
    Model1->submitAll();
    ui->videoPlayer->play();
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->volumeSlider_6->setAudioOutput(AudioOutput);
    //ui->volumeSlider_6->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    Contador->start(1000);
}

void Televideo::on_pushButton_3_clicked()
{
    ui->videoPlayer->stop();
    ui->pushButton->setEnabled(true);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    Contador->stop();
}

void Televideo::on_pushButton_6_clicked()
{
    if (ui->videoPlayer->isPaused())
    {
        ui->videoPlayer->play();
    }
    else
    {
        ui->videoPlayer->pause();
    }
}

void Televideo::on_pushButton_2_clicked()
{
    bool ok, ok1, ok2;
    QString Nombre, Direccion, Categoria;
    Nombre = QInputDialog::getText(this, QString::fromUtf8(tr("Nombre de Emisora")),
    QString::fromUtf8(tr("Introduce el nombre de la emisora.<P> ")),
    QLineEdit::Normal,
    "",&ok);
    if (ok && !Nombre.isEmpty())
    {
        Categoria = QInputDialog::getText(this, QString::fromUtf8(tr("Clasificacion de Emisora")),
        QString::fromUtf8(tr("Introduce la categoria de la emisora.<P> "
                "Ejemplo:<p> "
                "Generalista, Tematica, Deporte, etc." )),
        QLineEdit::Normal,
        "Generalista",&ok2);
        if (ok2 && !Categoria.isEmpty())
        {
            Direccion = QInputDialog::getText(this, QString::fromUtf8(tr("Direccion Url de la emision")),
            QString::fromUtf8(tr("Introduce la direccion completa de la emisora.<P> ")),
            QLineEdit::Normal,
            "",&ok1);
            if (ok1 && !Direccion.isEmpty())
            {
                QString Valor;
                QSqlQuery queryVal(db);
                queryVal.exec("SELECT Direccion FROM Television WHERE Url='"+Direccion+"'");
                queryVal.first();
                if (queryVal.isValid())
                    Valor=queryVal.value(0).toString();
                if (Direccion != Valor)
                {
                    QSqlQuery queryValor(db);
                    queryValor.prepare("INSERT INTO Television (Categoria,Nombre,Direccion)"
                                       "VALUES (:Categoria, :Nombre, :Direccion)");
                    queryValor.bindValue(":Categoria", Categoria);
                    queryValor.bindValue(":Nombre", Nombre);
                    queryValor.bindValue(":Direccion", Direccion);
                    queryValor.exec();
                    Model->select();
                    ui->tableView->setModel(Model);
                }
            }
            else
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("No has introducido la direccion del Internet de una emisora."));
                m.exec();
            }
        }
        else
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Hay que poner la categoria para poder clasificar la emisora."));
            m.exec();
        }
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Tienes que poner algun nombre para poder grabar una emisora."));
        m.exec();
    }
}

void Televideo::on_pushButton_8_clicked()
{
    int iFilas;
    iFilas=ActualRow;
    if (iFilas == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        int respuesta = 0;
        {
            respuesta = QMessageBox::question(0,QString::fromUtf8("Confirmar borrado"),
                               QString::fromUtf8("<center><b>Confirma el borrado de emision<b></center><p>"
                               "Debes estar seguro de querer borrar una emisora predefinida, ya que no podras escucharla mas "
                               "salvo que recupereres una copia de seguridad o la introduzcas de nuevo.<p>"
                               "&iquest;Borrar emisora seleccionada?"), QMessageBox::Ok, QMessageBox::No);
        }
        if (respuesta == QMessageBox::Ok)
        {
            ui->tableView->model()->removeRow(ActualRow);
        }
        else
            return;
    }
}

void Televideo::on_pushButton_9_clicked()
{
    bool ok;
    QString Nombre;
    Nombre = QInputDialog::getText(this, QString::fromUtf8(tr("Direccion Sop")),
    QString::fromUtf8(tr("Introduce la direccion completa de conexion Sop.<P> ")),
    QLineEdit::Normal,
    "sop://",&ok);
    if (ok && !Nombre.isEmpty())
    {
        system("sp-sc '"+Nombre+"' 3908 8908 > /dev/null &");
        QTest::qWait(8000);
        ui->videoPlayer->stop();
        ui->videoPlayer->load(Phonon::MediaSource("http://localhost:8908/tv.asf"));
        ui->videoPlayer->play();
        ui->pushButton->setEnabled(false);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->volumeSlider_6->setAudioOutput(ui->videoPlayer->audioOutput());
        //ui->volumeSlider_6->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    }
    else
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Tienes que poner alguna direccion Sop para poder hacer esto."));
        m.exec();

    }
}

void Televideo::Comprobar()
{
    if (Value == "Si")
    {
        if (ui->widget->isHidden() == false)
        {
            ui->widget->hide();
            Televideo::setCursor(Qt::BlankCursor);
            Contador->stop();
        }
    }
}
