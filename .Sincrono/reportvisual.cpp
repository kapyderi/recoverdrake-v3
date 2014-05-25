#include "reportvisual.h"
#include "ui_reportvisual.h"
#include <QFontDatabase>
#include "Report/editpaperdlg.h"
#include <QtConcurrentRun>
#include <QDebug>
#include <QMessageBox>
#include <QKeyEvent>
#include <QTest>
#include "Report/savetobdfrm.h"
#include "Report/sqlcalls.h"
#include "Auxiliares/timedmessagebox.h"
#include <QSqlQuery>

ReportVisual::ReportVisual(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ReportVisual),
    scene(this),
    view(this)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
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
    render = 0;
    insertor = 0;
    view.setScene(&scene);
    this->setCentralWidget(&view);
    QBrush *brush = new QBrush();
    brush->setStyle(Qt::Dense7Pattern);
    brush->setColor(Qt::gray);
    scene.setBackgroundBrush(*brush);;
    scene.addItem(&paper);
    paper.setSize(Paper::A4);
    paper.setOrientacion(Paper::Retrato);
    paper.setMargen(1.5);
    paper.updatePaper();
    connect(&paper,SIGNAL(itemInserted()),this,SLOT(stopInsert()));
    connect(&paper,SIGNAL(itemInserted()),this,SLOT(refreshItems()));
    connect(ui->itemList,SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(itemChanged(QListWidgetItem*)));
    connect(ui->actionRectangulo_redondeado,SIGNAL(toggled(bool)),this,SLOT(element_toggled(bool)));
    connect(ui->actionTexto,SIGNAL(toggled(bool)),this,SLOT(element_toggled(bool)));
    connect(ui->actionLinea,SIGNAL(toggled(bool)),this,SLOT(element_toggled(bool)));
    connect(ui->actionImagen,SIGNAL(toggled(bool)),this,SLOT(element_toggled(bool)));
    connect(ui->actionCampo,SIGNAL(toggled(bool)),this,SLOT(element_toggled(bool)));
    connect(ui->actionCodeBar,SIGNAL(toggled(bool)),this,SLOT(element_toggled(bool)));
    connect(ui->actionCampo_Relacional,SIGNAL(toggled(bool)),this,SLOT(element_toggled(bool)));
    connect(ui->actionParametro,SIGNAL(toggled(bool)),this,SLOT(element_toggled(bool)));
    connect(ui->actionAcumulador,SIGNAL(toggled(bool)),this,SLOT(element_toggled(bool)));
    Comprobar();
    ui->actionMostrar_ocultar_lista_de_campos->setChecked(true);
    this->installEventFilter(this);
    Posicion = 0;
    Titulo = this->windowTitle();
}

ReportVisual::~ReportVisual()
{
    delete ui;
    if (render)
        delete render;
}

void ReportVisual::Comprobar()
{
    QString Ver, Limitar;
    QSqlQuery query39(db);
    query39.exec("SELECT CheckVerContorno FROM Chequeos WHERE id=2");
    query39.first();
    if (query39.isValid())
         Ver=query39.value(0).toString();
    QSqlQuery query40(db);
    query40.exec("SELECT CheckLimitarVista FROM Chequeos WHERE id=2");
    query40.first();
    if (query40.isValid())
         Limitar=query40.value(0).toString();
    if (Ver == "Si")
    {
        ui->actionVer_contorno_objetos->setIcon(QIcon(":/Imagenes/good.png"));
        ui->actionVer_contorno_objetos->setChecked(true);
        Container::setShowBorder(true);
    }
    else if (Ver == "No")
    {
        ui->actionVer_contorno_objetos->setIcon(QIcon(""));
        ui->actionVer_contorno_objetos->setChecked(false);
        Container::setShowBorder(false);
    }
    if (Limitar == "Si")
    {
        ui->actionLimitar_vista_previa->setIcon(QIcon(":/Imagenes/good.png"));
        ui->actionLimitar_vista_previa->setChecked(true);
    }
    else if (Limitar == "No")
    {
        ui->actionLimitar_vista_previa->setIcon(QIcon(""));
        ui->actionLimitar_vista_previa->setChecked(false);
    }
}

void ReportVisual::on_actionVer_contorno_objetos_triggered(bool checked)
{
    if (checked == true)
    {
        ui->actionVer_contorno_objetos->setIcon(QIcon(":/Imagenes/good.png"));
        QSqlQuery guardar(db);
        guardar.exec("UPDATE chequeos SET CheckVerContorno='Si' WHERE id=2");
    }
    else
    {
        ui->actionVer_contorno_objetos->setIcon(QIcon(""));
        QSqlQuery guardar(db);
        guardar.exec("UPDATE chequeos SET CheckVerContorno='No' WHERE id=2");
    }
    Container::setShowBorder(checked);
    paper.updatePaper();
}

void ReportVisual::on_actionLimitar_vista_previa_triggered(bool checked)
{
    if (checked == true)
    {
        ui->actionVer_contorno_objetos->setIcon(QIcon(":/Imagenes/good.png"));
        QSqlQuery guardar(db);
        guardar.exec("UPDATE chequeos SET CheckLimitarVista='Si' WHERE id=2");
    }
    else
    {
        ui->actionVer_contorno_objetos->setIcon(QIcon(""));
        QSqlQuery guardar(db);
        guardar.exec("UPDATE chequeos SET CheckLimitarVista='No' WHERE id=2");
    }
}

void ReportVisual::on_actionSalir_triggered()
{
    close();
}

void ReportVisual::on_actionConfigurar_modelo_triggered()
{
    EditPaperDlg dlg(&paper,this);
    dlg.exec();
}

void ReportVisual::element_toggled(bool arg1)
{
    if (arg1)
    {
        QObject * send = sender();
        insertor = qobject_cast<QAction*>(send);
        if (send == ui->actionRectangulo_redondeado)
            paper.prepareItemInsert(Paper::RoundRectIt);
        else if(send == ui->actionTexto)
            paper.prepareItemInsert(Paper::Label);
        else if(send == ui->actionLinea)
            paper.prepareItemInsert(Paper::Linea);
        else if(send == ui->actionImagen)
            paper.prepareItemInsert(Paper::Imagen);
        else if(send == ui->actionCampo)
            paper.prepareItemInsert(Paper::Campo);
        else if(send == ui->actionCodeBar)
            paper.prepareItemInsert(Paper::CodeBarIt);
        else if(send == ui->actionCampo_Relacional)
            paper.prepareItemInsert(Paper::CampoRelacional);
        else if(send == ui->actionParametro)
            paper.prepareItemInsert(Paper::Parametro);
        else if(send == ui->actionAcumulador)
            paper.prepareItemInsert(Paper::Acumulador);
    }
    else
        paper.stopInsertingItems();
}

void ReportVisual::on_actionGuardar_triggered()
{
    QString file = QFileDialog::getSaveFileName(qApp->activeWindow(),tr("Guardar Reporte"),QString(),"XML (*.xml)");
    if (file.isEmpty())
    {
        return;
    }
    if (file.contains(".xml"))
        file.remove(".xml");
    int i = paper.save(file+".xml");
    if (i<0)
    {
        if (i== -1)
            QMessageBox::critical(this,tr("Error"),tr("Error al abrir el archivo."));
        else
            QMessageBox::warning(this,tr("Atencion"),tr("Tienes elementos fuera de secciones.\nEstos no han sido guardados."));
    }
    else
    {
        QString Value = Titulo+" -- "+file+".xml";
        this->setWindowTitle(Value);
    }
}

void ReportVisual::on_actionAbrir_triggered()
{
    QString fil = QFileDialog::getOpenFileName(this,tr("Abrir reporte"),QString(),"XML (*.xml)");
    if(fil.isEmpty())
    {
        return;
    }
    this->on_actionNuevo_triggered();
    _itemList.clear();
    ui->itemList->clear();
    ui->itemList->blockSignals(true);
    QMapIterator<Container*,QString> it(Container::items());
    while(it.hasNext())
    {
        it.next();
        QListWidgetItem *listItem = new QListWidgetItem(it.value(),ui->itemList);
        _itemList.insert(listItem,it.key());
        listItem->setCheckState(it.key()->isActive() ? Qt::Checked : Qt::Unchecked);
        connect(it.key(),SIGNAL(nameChanged(Container*)),this,SLOT(nameChanged(Container*)));
        contenedor->removeItem(it.key());
    }
    ui->itemList->blockSignals(false);
    QFile ff(fil);
    QString error;
    if(ff.open(QFile::ReadOnly))
    {
        QString x = ff.readAll();
        if(!paper.parseXML(x,error))
            QMessageBox::critical(this,"Error",error);
    }
    ff.close();
    refreshItems();
    QString Value = Titulo+" -- "+fil;
    this->setWindowTitle(Value);
}

void ReportVisual::stopInsert()
{
    insertor->setChecked(false);
}

void ReportVisual::on_actionBorrar_triggered()
{
    paper.removeItems(scene.selectedItems());
}

bool ReportVisual::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Delete)
            {
                paper.removeItems(scene.selectedItems());
                return true;
            }
        }
        return false;
    }
    return QMainWindow::eventFilter(obj, event);
}

void ReportVisual::on_actionVista_Previa_triggered()
{
    QProgressDialog* pDlg = new QProgressDialog(this);
    pDlg->setMaximum(0);
    pDlg->setValue(0);
    pDlg->show();
    QPrinter * printer = new QPrinter();
    if (paper.Orientacion() == 0)
        printer->setOrientation(QPrinter::Portrait);
    if (paper.Orientacion() == 1)
        printer->setOrientation(QPrinter::Landscape);
    QDomDocument doc = paper.preview();
    render = new ReportRenderer();
    render->setPrinter(printer);
    render->setDocIn(doc);
    render->setLimit(ui->actionLimitar_vista_previa->isChecked());
    QtConcurrent::run(render, &ReportRenderer::PreRender);
    connect(render,SIGNAL(end()),pDlg,SLOT(deleteLater()));
    connect(render,SIGNAL(end()),this,SLOT(previewReady()));
}

void ReportVisual::previewReady()
{
    QPrintPreviewDialog * pre = new QPrintPreviewDialog(render->getPrinter(),this);
    connect(pre, SIGNAL(paintRequested(QPrinter*)), render, SLOT(Print(QPrinter*)));
    pre->showMaximized();
    pre->exec();
}

void ReportVisual::on_actionBlock_triggered()
{
    QList<QGraphicsItem*> l = scene.selectedItems();
    for(int i = 0;i< l.size(); i++)
    {
       Container* c = qgraphicsitem_cast<Container*>(l.at(i));
       if (c)
           c->setActive(false);
    }
}
void ReportVisual::on_actionCrear_seccion_triggered()
{
    paper.Seccion();
}

void ReportVisual::on_actionDestruir_bloque_triggered()
{
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Advertencia!!!")),
                QString::fromUtf8(tr("<center><b>Eliminacion de bloques<b></center><p>"
                "Se eliminaran todos los bloques creados anteriormente.<p>"
                "&iquest;Eliminar bloques?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::No)
    {
        return;
    }
    else
    {
        QList<QGraphicsItem*> l = scene.items();
        for(int i = 0;i< l.size(); i++)
        {
           Container* c = qgraphicsitem_cast<Container*>(l.at(i));
           if (c)
               c->setActive(true);
        }
    }
}

void ReportVisual::on_actionAlinear_Izquierda_triggered()
{
  QList<QGraphicsItem*> items = scene.selectedItems();
  if(items.isEmpty())
      return;
  qreal _left = items.at(0)->x();
  foreach (QGraphicsItem* i, items) {
      if(i->x() < _left)
          _left = i->x();
  }
  foreach (QGraphicsItem* i, items) {
      i->setPos(_left,i->y());
  }
}

void ReportVisual::on_actionAlinear_Derecha_triggered()
{
    QList<QGraphicsItem*> items = scene.selectedItems();
    if(items.isEmpty())
        return;
    qreal _rigth = items.at(0)->x() + items.at(0)->boundingRect().width();
    foreach (QGraphicsItem* i, items) {
        if(i->x() + i->boundingRect().width() > _rigth)
            _rigth = i->x() + i->boundingRect().width();
    }
    foreach (QGraphicsItem* i, items) {
        i->setPos(_rigth - i->boundingRect().width(), i->y());
    }
}

void ReportVisual::on_actionAlinear_Centro_triggered()
{
    QList<QGraphicsItem*> items = scene.selectedItems();
    if(items.isEmpty())
        return;
    qreal _center = items.at(0)->x() + items.at(0)->boundingRect().width() / 2;
    foreach (QGraphicsItem* i, items) {
        i->setPos(_center - i->boundingRect().width()/2, i->y());
    }
}

void ReportVisual::on_actionAlinear_Arriba_triggered()
{
    QList<QGraphicsItem*> items = scene.selectedItems();
    if(items.isEmpty())
        return;
    qreal _up = items.at(0)->y();
    foreach (QGraphicsItem* i, items) {
        if(i->y() <  _up)
            _up = i->y();
    }
    foreach (QGraphicsItem* i, items) {
        i->setPos(i->x(),_up);
    }
}

void ReportVisual::on_actionAlinear_centro_triggered()
{
    QList<QGraphicsItem*> items = scene.selectedItems();
    if(items.isEmpty())
        return;
    qreal _center = items.at(0)->y() + items.at(0)->boundingRect().height()/2;
    foreach (QGraphicsItem* i, items) {
        i->setPos(i->x(),_center - i->boundingRect().height()/2);
    }
}

void ReportVisual::on_actionAlinear_abajo_triggered()
{
    QList<QGraphicsItem*> items = scene.selectedItems();
    if(items.isEmpty())
        return;
    qreal _center = items.at(0)->y() + items.at(0)->boundingRect().height();
    foreach (QGraphicsItem* i, items) {
        if(i->y() + i->boundingRect().height() >  _center)
            _center = i->y()  + i->boundingRect().height();
    }
    foreach (QGraphicsItem* i, items) {
        i->setPos(i->x(),_center - i->boundingRect().height());
    }
}

void ReportVisual::on_actionNuevo_triggered()
{    
    paper.newDoc();
    ui->itemList->clear();
    this->setWindowTitle(Titulo);
}

void ReportVisual::on_itemList_itemDoubleClicked(QListWidgetItem *item)
{
    if(item)
        if(_itemList.contains(item))
            _itemList.value(item)->editMe();
}

void ReportVisual::on_itemList_itemSelectionChanged()
{
    QListIterator<QListWidgetItem*> it (ui->itemList->selectedItems());
    scene.blockSignals(true);
    scene.clearSelection();
    while(it.hasNext())
    {
        QListWidgetItem* current = it.next();
        if(_itemList.contains(current))
        {
            _itemList.value(current)->setSelected(true);
        }
    }
    scene.blockSignals(false);
}

void ReportVisual::sceneSelectionChanged()
{
    QList<QGraphicsItem*> _selecteds = scene.selectedItems();
    QMapIterator<QListWidgetItem*,Container*> it(_itemList);
    ui->itemList->blockSignals(true);
    while(it.hasNext())
    {
        it.next();
        it.key()->setSelected(_selecteds.contains(it.value()));
    }
    ui->itemList->blockSignals(false);
}

void ReportVisual::refreshItems()
{
    _itemList.clear();
    ui->itemList->clear();
    ui->itemList->blockSignals(true);
    QMapIterator<Container*,QString> it(Container::items());
    while(it.hasNext())
    {
        it.next();
        QListWidgetItem *listItem = new QListWidgetItem(it.value(),ui->itemList);
        _itemList.insert(listItem,it.key());
        listItem->setCheckState(it.key()->isActive() ? Qt::Checked : Qt::Unchecked);
        connect(it.key(),SIGNAL(nameChanged(Container*)),this,SLOT(nameChanged(Container*)));
    }
    ui->itemList->blockSignals(false);
}

void ReportVisual::itemChanged(QListWidgetItem *item)
{
    if(_itemList.contains(item))
        if(_itemList.value(item))
            _itemList.value(item)->setActive(item->checkState() == Qt::Checked);
}

void ReportVisual::nameChanged(Container *c)
{
    QMapIterator<QListWidgetItem*, Container*> it(_itemList);
    while(it.hasNext())
    {
        it.next();
        if(it.value() == c)
        {
            it.key()->setText(c->name());
            break;
        }
    }
}

void ReportVisual::on_actionMostrar_ocultar_lista_de_campos_triggered()
{
    if (ui->actionMostrar_ocultar_lista_de_campos->isChecked() == false)
        ui->dockWidget->hide();
    else
        ui->dockWidget->show();
}

void ReportVisual::on_pushButton_clicked()
{
    _itemList.clear();
    ui->itemList->clear();
    ui->itemList->blockSignals(true);
    QMapIterator<Container*,QString> it(Container::items());
    while(it.hasNext())
    {
        it.next();
        QListWidgetItem *listItem = new QListWidgetItem(it.value(),ui->itemList);
        _itemList.insert(listItem,it.key());
        listItem->setCheckState(it.key()->isActive() ? Qt::Checked : Qt::Unchecked);
        connect(it.key(),SIGNAL(nameChanged(Container*)),this,SLOT(nameChanged(Container*)));
    }
    ui->itemList->blockSignals(false);
}

void ReportVisual::on_pushButton_2_clicked()
{
    _itemList.clear();
    ui->itemList->clear();
    ui->itemList->blockSignals(true);
    QMapIterator<Container*,QString> it(Container::items());
    while(it.hasNext())
    {
        it.next();
        QListWidgetItem *listItem = new QListWidgetItem(it.value(),ui->itemList);
        _itemList.insert(listItem,it.key());
        listItem->setCheckState(it.key()->isActive() ? Qt::Unchecked : Qt::Checked);
        connect(it.key(),SIGNAL(nameChanged(Container*)),this,SLOT(nameChanged(Container*)));
    }
    ui->itemList->blockSignals(false);
}

void ReportVisual::on_pushButton_3_clicked()
{
    ui->itemList->sortItems(Qt::AscendingOrder);
}

void ReportVisual::on_pushButton_4_clicked()
{
    ui->itemList->sortItems(Qt::DescendingOrder);
}

void ReportVisual::on_actionGuardar_en_BD_triggered()
{
    SaveToBDFrm frm(this);
    frm.Valor("0","","");
    if(frm.exec() == QDialog::Accepted)
    {
        QString error = "";
        QString nombre = frm.nombre;
        QString desc = frm.desc;
        int grad = frm.grad;
        QString Tabla = frm.tabla;
        QStringList clausulas;
        clausulas << QString("report_name = '%1'").arg(nombre);
        clausulas << QString("report_grade = %1").arg(grad);
        int id = SqlCalls::SelectOneField("report","report_id",clausulas,db,error).toInt();
        QHash<QString,QVariant> v;
        v["report_name"] = nombre;
        v["report_descrip"] = desc;
        v["report_source"] = paper.preview().toString();
        v["report_grade"] = grad;
        v["report_table"] = Tabla;
        if(id == 0)
        {
            id = SqlCalls::SqlInsert(v,"report",db,error);
            if(id < 0)
            {
                TimedMessageBox* t = new TimedMessageBox(this,tr("Error:\n%1").arg(error),TimedMessageBox::Critical);
                Q_UNUSED(t);
            }
            else
            {
                TimedMessageBox* t = new TimedMessageBox(this,tr("Report guardado correctamente"),TimedMessageBox::Infomation,1);
                Q_UNUSED(t);
            }
        }
        else
        {
            if(!SqlCalls::SqlUpdate(v,"report",db,clausulas,error))
            {
                TimedMessageBox *t = new TimedMessageBox(this,tr("Error:\n%1").arg(error),TimedMessageBox::Critical);
                Q_UNUSED(t);
            }
            else
            {
                TimedMessageBox *t = new TimedMessageBox(this,tr("Report actualizado correctamente"),TimedMessageBox::Infomation,1);
                Q_UNUSED(t);
            }
        }        
    }
    return;
}

void ReportVisual::on_actionAbrir_desde_BD_triggered()
{
    QString datos, error;
    SaveToBDFrm frm(this);
    frm.Valor("1","","");
    if(frm.exec() == QDialog::Accepted)
    {
        int Pose = frm.Posicion;
        QSqlQuery query(db);
        query.exec("SELECT report_source FROM Report WHERE report_id ='"+QString::number(Pose)+"'");
        query.first();
        datos = query.value(0).toString();
        paper.parseXML(datos,error);
        refreshItems();
    }
    return;
}

