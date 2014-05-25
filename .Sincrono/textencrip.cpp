#include "textencrip.h"
#include "ui_textencrip.h"
#include <QSqlQuery>
#include <QColorDialog>
#include <QFileDialog>
#include <QTextDocumentWriter>
#include "drakesistema.h"
#include <QMessageBox>
#include <QTextCodec>

textencrip::textencrip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::textencrip)
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
    this->installEventFilter(this);
    CierreTotal = 0;
    ui->textEdit_2->setFontFamily(ui->fontComboBox_2->currentText());
    ui->textEdit_2->setPointSize(ui->sizeSpin_2->text().toInt());
    connect(ui->checkBox,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    ui->radioButton->setChecked(true);
    ui->textEdit_2->setFocus();
    cursor = ui->textEdit_2->textCursor();
    cursor.movePosition( QTextCursor::End );
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox->setEnabled(true);
    ui->label->setText(tr("Texto original"));
    ui->label_2->setText(tr("Texto encriptado"));
}

textencrip::~textencrip()
{
    delete ui;
}

void textencrip::on_pushButton_5_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void textencrip::Valor(QString valor, QString Logs)
{
    if (valor == "Quitar")
        CierreTotal = 1;
    if (Logs == "S")
        Log = "S";
    else
        Log = "N";
}

void textencrip::closeEvent ( QCloseEvent * event )
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

void textencrip::changeEvent(QEvent *e)
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

bool textencrip::eventFilter(QObject* obj, QEvent *event)
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
                ayuda->Valor(tr("Encriptador de texto"));
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void textencrip::Comprobar()
{
    if (ui->checkBox->isChecked())
        ui->textEdit_2->selectAll();
    else
    {
        ui->textEdit_2->setTextCursor(cursor);
        ui->textEdit_2->setFocus();
    }
}

void textencrip::Comprobar1()
{
    if (ui->radioButton->isChecked())
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->comboBox->setEnabled(true);
        ui->label->setText(tr("Texto original"));
        ui->label_2->setText(tr("Texto encriptado"));
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->comboBox->setEnabled(false);
        ui->label->setText(tr("Texto encriptado"));
        ui->label_2->setText(tr("Texto original"));
    }
}

void textencrip::on_textEdit_2_textChanged()
{
    ui->textEdit->setHtml(ui->textEdit_2->toHtml());
}

void textencrip::on_fontComboBox_2_currentIndexChanged(const QString &arg1)
{
    ui->textEdit_2->setFontFamily(arg1);
    ui->textEdit->setFontFamily(arg1);
    ui->textEdit_2->setFocus();
}

void textencrip::on_sizeSpin_2_valueChanged(const QString &arg1)
{
    ui->textEdit_2->setPointSize(arg1.toInt());
    ui->textEdit->setHtml(ui->textEdit_2->toHtml());
    ui->textEdit_2->setFocus();
}

void textencrip::on_btnBold_2_toggled(bool checked)
{
    if(checked)
        ui->textEdit_2->setFontWeight(QFont::Bold);
    else
        ui->textEdit_2->setTextCursor(cursor);
    ui->textEdit->setHtml(ui->textEdit_2->toHtml());
    ui->textEdit_2->setFocus();
}

void textencrip::on_btnItalic_2_toggled(bool checked)
{
    ui->textEdit_2->setItalic(checked);
    ui->textEdit->setHtml(ui->textEdit_2->toHtml());
    ui->textEdit_2->setFocus();
}

void textencrip::on_btnUnder_2_toggled(bool checked)
{
    ui->textEdit_2->setUnderline(checked);
    ui->textEdit->setHtml(ui->textEdit_2->toHtml());
    ui->textEdit_2->setFocus();
}

void textencrip::on_btnColor_2_clicked()
{
    QColorDialog d(this);
    if(d.exec() == QDialog::Accepted)
    {
        ui->textEdit_2->setColor(d.selectedColor());
        ui->textEdit->setHtml(ui->textEdit_2->toHtml());
        ui->textEdit_2->setFocus();
    }
}

void textencrip::on_pushButton_2_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameDestino = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar archivo ")),
                        path,trUtf8(tr("Archivo ODT (*.odt);;Archivo DOC (*.doc);;Archivo HTML (*.htm *.html);;Todos los archivos (*)")));
    if (fileNameDestino.isEmpty())
        return;
    if (! (fileNameDestino.endsWith(".odt", Qt::CaseInsensitive) || fileNameDestino.endsWith(".doc", Qt::CaseInsensitive) || fileNameDestino.endsWith(".htm", Qt::CaseInsensitive) || fileNameDestino.endsWith(".html", Qt::CaseInsensitive)) )
             fileNameDestino += ".odt";
    ui->txtNombre_2->setText(fileNameDestino);
}

void textencrip::on_pushButton_clicked()
{
    if (ui->txtNombre_2->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun destino y no se puede guardar.<p>Introduce primero la ruta y vuelve a guardar."));
        m.exec();
        this->on_pushButton_2_clicked();
        return;
    }
    QTextDocumentWriter writer(ui->txtNombre_2->text());
    writer.write(ui->textEdit->document());
}

void textencrip::on_btnLeft_2_clicked()
{
    ui->textEdit_2->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
    ui->textEdit->setHtml(ui->textEdit_2->toHtml());
    ui->textEdit_2->setFocus();
}

void textencrip::on_btnCenter_2_clicked()
{
    ui->textEdit_2->setAlignment(Qt::AlignCenter);
    ui->textEdit->setHtml(ui->textEdit_2->toHtml());
    ui->textEdit_2->setFocus();
}

void textencrip::on_btnRigth_2_clicked()
{
    ui->textEdit_2->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
    ui->textEdit->setHtml(ui->textEdit_2->toHtml());
    ui->textEdit_2->setFocus();
}

void textencrip::on_pushButton_7_clicked()
{
    ui->textEdit_2->setText("");
}

void textencrip::on_pushButton_6_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this, tr("Abrir archivo"),
                      path,trUtf8(tr("Archivo ODT (*.odt);;Archivo DOC (*.doc);;Archivo HTML (*.htm *.html);;Todos los archivos (*)")));;
     if (fileNameOrigen.isEmpty())
         return;
     ui->txtNombre_3->setText(fileNameOrigen);
     QFile file(fileNameOrigen);
     if (!file.open(QFile::ReadOnly))
         return;
     QByteArray data = file.readAll();
     //falla esta parte para archivos .otc
     QTextCodec *codec = Qt::codecForHtml(data);
     QString str = codec->toUnicode(data);
     ui->textEdit_2->setHtml(str);
     ui->textEdit->setHtml(ui->textEdit_2->toHtml());
     ui->textEdit_2->setFocus();
}
