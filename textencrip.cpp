#include "textencrip.h"
#include "ui_textencrip.h"
#include <QSqlQuery>
#include <QColorDialog>
#include <QFileDialog>
#include <QTextDocumentWriter>
#include "drakesistema.h"
#include <QMessageBox>
#include <QTextCodec>
#include <QDebug>
#include "Report/savetobdfrm.h"

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
    ui->textEdit->setFontFamily(ui->fontComboBox_2->currentText());
    ui->textEdit->setPointSize(ui->sizeSpin_2->text().toInt());
    connect(ui->checkBox,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(Validar(QString)));
    ui->radioButton->setChecked(true);
    ui->textEdit_2->setFocus();
    cursor = ui->textEdit_2->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox->setEnabled(true);
    ui->label->setText(tr("Texto original"));
    ui->label_2->setText(tr("Texto encriptado"));
    ui->lineEdit_13->setEnabled(false);
    ui->lineEdit_14->setEnabled(false);
    ui->lineEdit_16->setEnabled(false);
    ui->lineEdit_18->setEnabled(false);
}

textencrip::~textencrip()
{
    delete ui;
}

void textencrip::Validar(QString Value)
{
    if (Value == tr("Simple"))
    {
        ui->lineEdit_13->setEnabled(false);
        ui->lineEdit_14->setEnabled(false);
        ui->lineEdit_13->setText("");
        ui->lineEdit_14->setText("");
    }
    if (Value == tr("Doble"))
    {
        ui->lineEdit_13->setEnabled(true);
        ui->lineEdit_14->setEnabled(false);
        ui->lineEdit_14->setText("");
    }
    if (Value == tr("Triple"))
    {
        ui->lineEdit_13->setEnabled(true);
        ui->lineEdit_14->setEnabled(true);
    }
    this->Reencriptar();
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
        ui->groupBox_2->show();
        ui->textEdit_2->setText("");
        ui->textEdit->setText("");
        ui->txtNombre_2->setText("");
        ui->txtNombre_3->setText("");
        ui->lineEdit_13->setText("");
        ui->lineEdit_14->setText("");
        ui->lineEdit_16->setText("");
        ui->lineEdit_18->setText("");
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->comboBox->setEnabled(false);
        ui->label->setText(tr("Texto encriptado"));
        ui->label_2->setText(tr("Texto original"));
        ui->groupBox_2->hide();
        ui->textEdit_2->setText("");
        ui->textEdit->setText("");
        ui->txtNombre_2->setText("");
        ui->txtNombre_3->setText("");
        ui->lineEdit_13->setText("");
        ui->lineEdit_14->setText("");
        ui->lineEdit_16->setText("");
        ui->lineEdit_18->setText("");
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
    ui->textEdit->setPointSize(arg1.toInt());
    ui->textEdit_2->setFocus();
}

void textencrip::on_btnBold_2_toggled(bool checked)
{
    if(checked)
    {
        ui->textEdit_2->setFontWeight(QFont::Bold);
        ui->textEdit->setFontWeight(QFont::Bold);
    }
    else
    {
        ui->textEdit_2->setFontWeight(QFont::Normal);
        ui->textEdit->setFontWeight(QFont::Normal);
    }
    ui->textEdit_2->setFocus();
}

void textencrip::on_btnItalic_2_toggled(bool checked)
{
    ui->textEdit_2->setItalic(checked);
    ui->textEdit->setItalic(checked);
    ui->textEdit_2->setFocus();
}

void textencrip::on_btnUnder_2_toggled(bool checked)
{
    ui->textEdit_2->setUnderline(checked);
    ui->textEdit->setUnderline(checked);
    ui->textEdit_2->setFocus();
}

void textencrip::on_btnColor_2_clicked()
{
    QColorDialog d(this);
    if(d.exec() == QDialog::Accepted)
    {
        ui->textEdit_2->setColor(d.selectedColor());
        ui->textEdit->setColor(d.selectedColor());
        ui->textEdit_2->setFocus();
    }
}

void textencrip::on_pushButton_2_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameDestino = QFileDialog::getSaveFileName(this,QString::fromUtf8(tr("Guardar archivo")),
                        path,trUtf8(tr("Archivo HTML (*.htm *.html)")));
    if (fileNameDestino.isEmpty())
        return;
    if (!(fileNameDestino.endsWith(".htm", Qt::CaseInsensitive) || fileNameDestino.endsWith(".html", Qt::CaseInsensitive)) )
             fileNameDestino += ".htm";
    ui->txtNombre_2->setText(fileNameDestino);
}

void textencrip::on_pushButton_clicked()
{
    if (ui->txtNombre_2->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun destino y no se puede guardar.<p>Tienes que introducir primero una ruta de destino valida."));
        m.exec();
        return;
    }
    if (ui->textEdit_2->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ningun texto para guardar."));
        m.exec();
        return;
    }
    if (ui->textEdit_2->text() == ui->textEdit->toPlainText())
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has encriptado el texto a guardar."));
        m.exec();
        return;
    }
    QTextDocumentWriter writer(ui->txtNombre_2->text());
    writer.write(ui->textEdit->document());
    QMessageBox m;
    if (Stilo == "A")
        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    m.setText(tr("Archivo guardado correctamente."));
    m.exec();
}

void textencrip::on_btnLeft_2_clicked()
{
    ui->textEdit_2->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
    ui->textEdit->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
    ui->textEdit_2->setFocus();
}

void textencrip::on_btnCenter_2_clicked()
{
    ui->textEdit_2->setAlignment(Qt::AlignCenter);
    ui->textEdit->setAlignment(Qt::AlignCenter);
    ui->textEdit_2->setFocus();
}

void textencrip::on_btnRigth_2_clicked()
{
    ui->textEdit_2->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
    ui->textEdit->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
    ui->textEdit_2->setFocus();
}

void textencrip::on_pushButton_7_clicked()
{
    ui->textEdit_2->setText("");
    ui->textEdit->setText("");
    ui->textEdit_2->setFocus();
}

void textencrip::on_pushButton_6_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameOrigen = QFileDialog::getOpenFileName(this, tr("Abrir archivo"),
                      path,trUtf8(tr("Archivo HTML (*.htm *.html)")));;
     if (fileNameOrigen.isEmpty())
         return;
     ui->txtNombre_3->setText(fileNameOrigen);
     QFile file(fileNameOrigen);
     if (!file.open(QFile::ReadOnly))
         return;
     QByteArray data = file.readAll();
     QTextCodec *codec = Qt::codecForHtml(data);
     QString str = codec->toUnicode(data);
     ui->textEdit_2->setHtml(str);
     QStringList Validar = ui->textEdit->toPlainText().split(" ");
     QString Valor = Validar.value(Validar.count()-2);
     if (Valor == "%")
     {
         Cripto = 1;
         ui->lineEdit_16->setEnabled(true);
         ui->lineEdit_18->setEnabled(false);
     }
     if (Valor == "&")
     {
         Cripto = 2;
         ui->lineEdit_16->setEnabled(true);
         ui->lineEdit_18->setEnabled(true);
     }
}

void textencrip::on_pushButton_4_clicked()
{
    if (ui->textEdit_2->text() != ui->textEdit->toPlainText())
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Ya esta encriptado el texto."));
        m.exec();
        return;
    }
    int ramdom3, ramdom4;
    if (ui->comboBox->currentText() == tr("Doble"))
    {
        ramdom3 = ramdomize();
        ui->lineEdit_13->setText(QString::number(ramdom3));
    }
    if (ui->comboBox->currentText() == tr("Triple"))
    {
        ramdom3 = ramdomize();
        ramdom4 = ramdomize();
        ui->lineEdit_13->setText(QString::number(ramdom3));
        ui->lineEdit_14->setText(QString::number(ramdom4));
    }
    QStringList Valor = ui->textEdit->toPlainText().split("\n");
    for (int a=0;a<Valor.count();a++)
    {
        if (Valor.value(a) != "")
        {
            QString Parcial = Valor.value(a);
            QString Encrip = Encriptar(Parcial);
            QString FEncrip = Traducir(Encrip);
            ui->textEdit->find(Valor.value(a),QTextDocument::FindWholeWords);
            ui->textEdit->textCursor().insertText(FEncrip);
        }
        else
            ui->textEdit->textCursor().insertText(Valor.value(a));
    }
}

void textencrip::Reencriptar()
{
    if (ui->textEdit_2->text() != ui->textEdit->toPlainText())
    {
        ui->textEdit->setText(ui->textEdit_2->text());
        int ramdom3, ramdom4;
        if (ui->comboBox->currentText() == tr("Doble"))
        {
            ramdom3 = ramdomize();
            ui->lineEdit_13->setText(QString::number(ramdom3));
        }
        if (ui->comboBox->currentText() == tr("Triple"))
        {
            ramdom3 = ramdomize();
            ramdom4 = ramdomize();
            ui->lineEdit_13->setText(QString::number(ramdom3));
            ui->lineEdit_14->setText(QString::number(ramdom4));
        }
        QStringList Valor = ui->textEdit->toPlainText().split("\n");
        for (int a=0;a<Valor.count();a++)
        {
            if (Valor.value(a) != "")
            {
                QString Parcial = Valor.value(a);
                QString Encrip = Encriptar(Parcial);
                QString FEncrip = Traducir(Encrip);
                ui->textEdit->find(Valor.value(a),QTextDocument::FindWholeWords);
                ui->textEdit->textCursor().insertText(FEncrip);
            }
            else
                ui->textEdit->textCursor().insertText(Valor.value(a));
        }
    }
}

QString textencrip::Traducir(QString dato)
{
    QString Valor;
    QStringList DatoParc = dato.split("-");
    for(int a=0;a<DatoParc.count();a++)
    {
        QString Restando = DatoParc.value(a);
        QStringList ValorR = Restando.split("");
        for(int b=1;b<ValorR.count()-1;b++)
        {
            QString Resto = ValorR.value(b);
            if (Resto == "0")
                Valor.append("!");
            if (Resto == "1")
                Valor.append("$");
            if (Resto == "2")
                Valor.append("%");
            if (Resto == "3")
                Valor.append("&");
            if (Resto == "4")
                Valor.append("#");
            if (Resto == "5")
                Valor.append("(");
            if (Resto == "6")
                Valor.append(")");
            if (Resto == "7")
                Valor.append("*");
            if (Resto == "8")
                Valor.append("?");
            if (Resto == "9")
                Valor.append("@");
        }
        Valor.append(" ");
    }
    return Valor;
}

int textencrip::ramdomize()
{
    int dato;
    dato = randInt(0,99);
    return dato;
}

int textencrip::randInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

QString textencrip::Encriptar(QString dato)
{
    QString DatEncrip;
    int PosseU = dato.count();
    int ramdom1 = ramdomize();
    int ramdom2 = ramdomize();
    int ramdom3 = ui->lineEdit_13->text().toInt();
    int ramdom4 = ui->lineEdit_14->text().toInt();
    QStringList Pass = dato.split("");
    if (ui->comboBox->currentText() == tr("Simple"))
    {
        for(int a=1;a<Pass.count()-1;a++)
        {
            QString Posicion;
            int Final, Dato, DatUser;
            Posicion = Pass.value(a);
            QSqlQuery query(db);
            query.exec("SELECT Decimal FROM Ascii WHERE Unicode='"+Posicion+"'");
            query.first();
            Final = query.value(0).toInt();
            Dato = PosseU+a+1;
            DatUser = Final * Dato;
            if (a != Pass.count()-1)
                DatEncrip = DatEncrip.append(QString::number(DatUser)+"-");
            else
                DatEncrip = DatEncrip.append(QString::number(DatUser));
        }
        DatEncrip = DatEncrip.append(QString::number(PosseU)+"-1");
    }
    if (ui->comboBox->currentText() == tr("Doble"))
    {
        for(int a=1;a<Pass.count()-1;a++)
        {
            QString Posicion;
            int Final, Dato, DatUser;
            Posicion = Pass.value(a);
            QSqlQuery query(db);
            query.exec("SELECT Decimal FROM Ascii WHERE Unicode='"+Posicion+"'");
            query.first();
            Final = query.value(0).toInt();
            Dato = PosseU+ramdom1+a+1+ramdom3;
            DatUser = Final * Dato;
            if (a != Pass.count()-1)
                DatEncrip = DatEncrip.append(QString::number(DatUser)+"-");
            else
                DatEncrip = DatEncrip.append(QString::number(DatUser));
        }
        DatEncrip = DatEncrip.append(QString::number(ramdom1)+"-"+QString::number(PosseU)+"-2");
    }
    if (ui->comboBox->currentText() == tr("Triple"))
    {
        for(int a=1;a<Pass.count()-1;a++)
        {
            QString Posicion;
            int Final, Dato, DatUser;
            Posicion = Pass.value(a);
            QSqlQuery query(db);
            query.exec("SELECT Decimal FROM Ascii WHERE Unicode='"+Posicion+"'");
            query.first();
            Final = query.value(0).toInt();
            Dato = PosseU+ramdom1+ramdom2+a+1+ramdom3+ramdom4;
            DatUser = Final * Dato;
            if (a != Pass.count()-1)
                DatEncrip = DatEncrip.append(QString::number(DatUser)+"-");
            else
                DatEncrip = DatEncrip.append(QString::number(DatUser));
        }
        DatEncrip = DatEncrip.append(QString::number(ramdom1)+"-"+QString::number(ramdom2)+"-"+QString::number(PosseU)+"-3");
    }
    return DatEncrip;
}

void textencrip::on_pushButton_8_clicked()
{
    if (ui->textEdit_2->toPlainText() != ui->textEdit->toPlainText())
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Ya esta desencriptado el texto."));
        m.exec();
        return;
    }
    if (Cripto == 1)
    {
        if (ui->lineEdit_16->text() == "")
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Debes de introducir los datos que te han sido facilitados para desencriptar.<p>Sino es asi, debes solicitar estos datos o no podras leer el texto."));
            m.exec();
            return;
        }
    }
    if (Cripto == 2)
    {
        if (ui->lineEdit_16->text() == "" || ui->lineEdit_18->text() == "")
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Debes de introducir los datos que te han sido facilitados para desencriptar.<p>Sino es asi, debes solicitar estos datos o no podras leer el texto."));
            m.exec();
            return;
        }
    }
    QStringList Valor = ui->textEdit->toPlainText().split("\n");
    for (int a=0;a<Valor.count();a++)
    {
        if (Valor.value(a) != "")
        {
            QString Parcial = Valor.value(a);
            QString Dencrip = Destraducir(Parcial);
            QString Encrip = Desencriptar(Dencrip);
            ui->textEdit->find(Valor.value(a),QTextDocument::FindWholeWords);
            ui->textEdit->textCursor().insertText(Encrip);
        }
        else
            ui->textEdit->textCursor().insertText(Valor.value(a));
    }
}

QString textencrip::Destraducir(QString dato)
{
    QString Valor;
    QStringList DatoParc = dato.split(" ");
    for(int a=0;a<DatoParc.count()-1;a++)
    {
        QString Restando = DatoParc.value(a);
        QStringList ValorR = Restando.split("");
        for(int b=1;b<ValorR.count()-1;b++)
        {
            QString Resto = ValorR.value(b);
            if (Resto == "!")
                Valor.append("0");
            if (Resto == "$")
                Valor.append("1");
            if (Resto == "%")
                Valor.append("2");
            if (Resto == "&")
                Valor.append("3");
            if (Resto == "#")
                Valor.append("4");
            if (Resto == "(")
                Valor.append("5");
            if (Resto == ")")
                Valor.append("6");
            if (Resto == "*")
                Valor.append("7");
            if (Resto == "?")
                Valor.append("8");
            if (Resto == "@")
                Valor.append("9");
        }
        Valor.append("-");
    }
    Valor.chop(1);
    return Valor;
}

QString textencrip::Desencriptar(QString dato)
{
    QString DatEncrip;
    int ramdom3, ramdom4;
    if (Cripto == 1)
        ramdom3 = ui->lineEdit_16->text().toInt();
    if (Cripto == 2)
    {
        ramdom3 = ui->lineEdit_16->text().toInt();
        ramdom4 = ui->lineEdit_18->text().toInt();
    }
    QStringList Pass = dato.split("-");
    if (Pass.value(Pass.count()-1) == "1")
    {
        int PosseU = Pass.value(Pass.count()-2).toInt();
        for(int a=0;a<Pass.count()-2;a++)
        {
            int Posicion, Dato, DatUser;
            QString Final;
            Posicion = Pass.value(a).toInt();
            Dato = PosseU+(a+1)+1;
            DatUser = Posicion / Dato;
            QSqlQuery query(db);
            query.exec("SELECT Unicode FROM Ascii WHERE Decimal='"+QString::number(DatUser)+"'");
            query.first();
            Final = query.value(0).toString();
            DatEncrip = DatEncrip.append(Final);
        }
    }
    if (Pass.value(Pass.count()-1) == "2")
    {
        int PosseA = Pass.value(Pass.count()-2).toInt();
        int PosseU = Pass.value(Pass.count()-3).toInt();
        for(int a=0;a<Pass.count()-3;a++)
        {
            int Posicion, Dato, DatUser;
            QString Final;
            Posicion = Pass.value(a).toInt();
            Dato = PosseU+PosseA+(a+1)+1+ramdom3;
            DatUser = Posicion / Dato;
            QSqlQuery query(db);
            query.exec("SELECT Unicode FROM Ascii WHERE Decimal='"+QString::number(DatUser)+"'");
            query.first();
            Final = query.value(0).toString();
            DatEncrip = DatEncrip.append(Final);
        }
    }
    if (Pass.value(Pass.count()-1) == "3")
    {
        int PosseA = Pass.value(Pass.count()-2).toInt();
        int PosseI = Pass.value(Pass.count()-3).toInt();
        int PosseU = Pass.value(Pass.count()-4).toInt();
        for(int a=0;a<Pass.count()-4;a++)
        {
            int Posicion, Dato, DatUser;
            QString Final;
            Posicion = Pass.value(a).toInt();
            Dato = PosseU+PosseI+PosseA+(a+1)+1+ramdom3+ramdom4;
            DatUser = Posicion / Dato;
            QSqlQuery query(db);
            query.exec("SELECT Unicode FROM Ascii WHERE Decimal='"+QString::number(DatUser)+"'");
            query.first();
            Final = query.value(0).toString();
            DatEncrip = DatEncrip.append(Final);
        }
    }
    return DatEncrip;
}

void textencrip::on_pushButton_3_clicked()
{
    if (ui->textEdit_2->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay texto a imprimir."));
        m.exec();
        return;
    }
    if (ui->textEdit_2->text() == ui->textEdit->toPlainText())
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        if (ui->radioButton->isChecked())
            m.setText(tr("No has encriptado el texto.<p>Se imprimira sin encriptacion."));
        else
            m.setText(tr("No has desencriptado el texto.<p>Se imprimira con encriptacion"));
        m.exec();
    }
    SaveToBDFrm frm(this);
    frm.Valor("3","","",ui->textEdit->toHtml());
    frm.exec();
}
