#include "qrcode.h"
#include "ui_qrcode.h"
#include <QFileDialog>
#include <QPainter>
#include <QSvgGenerator>
#include <QSvgRenderer>
#include <QImage>
#include <QDebug>
#include <QSqlQuery>
#include <QCloseEvent>

qrcode::qrcode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qrcode)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    qr =new QRWidget(this);
    ui->gridLayout->addWidget(qr);
    ui->gridLayout->setAlignment(ui->gridLayout,Qt::AlignCenter);
    extByMessage[tr("Archivo SVG (*.svg)")] = ".svg";
    extByMessage[tr("Archivo PNG (*.png)")] = ".png";
    extByMessage[tr("Archivo BMP (*.bmp)")] = ".bmp";
    extByMessage[tr("Archivo JPG (*.jpg)")] = ".jpg";
    extByMessage[tr("Archivo JPEG (*.jpeg)")] = ".jpeg";
    extByMessage[tr("Archivo PPM (*.ppm)")] = ".ppm";
    extByMessage[tr("Archivo TIFF (*.tiff)")] = ".tiff";
    extByMessage[tr("Archivo XBM (*.xbm)")] = ".xbm";
    extByMessage[tr("Archivo XBM (*.xpm)")] = ".xpm";
    QHashIterator<QString, QString> i(extByMessage);
    while (i.hasNext())
    {
        i.next();
        saveMessage += i.key();
        if (i.hasNext())
            saveMessage += ";;";
    }
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
}

qrcode::~qrcode()
{
    delete ui;
}

void qrcode::on_pushButton_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void qrcode::Valor(QString valor)
{
    if (valor == "Quitar")
    {
        CierreTotal = 1;
    }
    ui->lineEdit->setText(qr->Comprobar());
}

void qrcode::closeEvent ( QCloseEvent * event )
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

void qrcode::changeEvent(QEvent *e)
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

bool qrcode::eventFilter(QObject* obj, QEvent *event)
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
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("QRDrake"));
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void qrcode::on_pushButton_2_clicked()
{
    static QString sf;
    QString newPath = QFileDialog::getSaveFileName(this, tr("Salvar imagen"),
        path,saveMessage,&sf);
    if (newPath.isEmpty())
        return;
    path = newPath;
    QFileInfo f(newPath);
    if (f.suffix().isEmpty())
    {
        path +=extByMessage.value(sf);
    }
    QSvgGenerator generator;
    QPainter painter;
    QString svg;
    QFileInfo ff(path);
    QString Volver = ff.suffix();
    if (! path.endsWith(".svg", Qt::CaseInsensitive))
    {
        svg = path.remove(ff.suffix());
        svg.append("svg");
        generator.setFileName(svg);
        generator.setSize(QSize(740, 740));
        generator.setViewBox(QRect(0, 0, 740, 740));
        generator.setTitle(tr("Generador de SVG"));
        generator.setDescription(tr("Una imagen SVG creada con RecoverDrake"));
        painter.begin(&generator);
        qr->paint(painter);
        painter.end();
        path.append(Volver);
        QImage image(740, 740, QImage::Format_ARGB32);
        QPainter painter1(&image);
        QSvgRenderer renderer(svg);
        image.fill(0xaaA08080);
        renderer.render(&painter1);
        image.save(path);
        QFile::remove(svg);
    }
    else
    {
        generator.setFileName(path);
        generator.setSize(QSize(740, 740));
        generator.setViewBox(QRect(0, 0, 740, 740));
        generator.setTitle(tr("Generador de SVG"));
        generator.setDescription(tr("Una imagen SVG creada con RecoverDrake"));
        painter.begin(&generator);
        qr->paint(painter);
        painter.end();
    }
}

void qrcode::on_lineEdit_textChanged(const QString &arg1)
{
    qr->setQRData(arg1);
}

void qrcode::on_pushButton_3_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit->setFocus();
}
