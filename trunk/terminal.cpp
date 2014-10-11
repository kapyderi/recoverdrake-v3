#include "terminal.h"
#include "ui_terminal.h"
#include <QDir>
#include <drakesistema.h>
#include <QDebug>
#include <QSqlQuery>
#include <QKeyEvent>

Terminal::Terminal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Terminal)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    Stilo = "B";
    drakeSistema drake;
    User = drake.getUser();
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
    ui->tabWidget->setUsesScrollButtons(true);
    QIcon::setThemeName("oxygen");
    this->setWindowIcon(QIcon::fromTheme("utilities-terminal"));
    consola = new QTermWidget();
    QStringList ColorSchema =  QTermWidget::availableColorSchemes();
    ui->comboBox->addItems(ColorSchema);
    ui->comboBox->setCurrentText("WhiteOnBlack");
    ui->comboBox_2->setCurrentText("10");
    ui->fontComboBox->setCurrentText("Monospace");
    QString NomConsola= User;
    ui->tabWidget->addTab(consola, NomConsola+"::bash");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
    int Letra = ui->comboBox_2->currentText().toInt();
    QString Fuente = ui->fontComboBox->currentText();
    font.setFamily(Fuente);
    font.setPointSize(Letra);
    consola->setTerminalFont(font);
    consola->setScrollBarPosition(QTermWidget::ScrollBarRight);
    consola->setColorScheme(ui->comboBox->currentText());
    consola->setBackgroundPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
    consola->showMaximized();
    QString prueba = "su - "+User;
    QString enter = "\r";
    consola->sendText(prueba);
    consola->sendText(enter);
    QString prueba1 = "clear ";
    QString enter1 = "\r";
    consola->sendText(prueba1);
    consola->sendText(enter1);
    connect(consola,SIGNAL(finished()),this,SLOT(finalizar()));
    ui->tabWidget->setTabsClosable(true);
    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(closeTab(int)));
    this->installEventFilter(this);
}

Terminal::~Terminal()
{
    delete ui;
}

void Terminal::Valor(QString valor)
{
    if (valor == "Quitar")
        CierreTotal = 1;
}

void Terminal::closeEvent ( QCloseEvent * event )
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

void Terminal::changeEvent(QEvent *e)
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

void Terminal::finalizar()
{
    if (ui->tabWidget->currentIndex() > 0)
        ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
    else
    {
        ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
        this->on_pushButton_clicked();
    }
}

void Terminal::on_pushButton_clicked()
{
    QString NomConsola;
    consola = new QTermWidget();
    if (ui->radioButton->isChecked())
        NomConsola= User;
    else
        NomConsola="root";
    ui->tabWidget->addTab(consola, NomConsola+"::bash");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
    int Letra = ui->comboBox_2->currentText().toInt();
    QString Fuente = ui->fontComboBox->currentText();
    font.setFamily(Fuente);
    font.setPointSize(Letra);
    consola->setTerminalFont(font);
    consola->setScrollBarPosition(QTermWidget::ScrollBarRight);
    consola->setColorScheme(ui->comboBox->currentText());
    consola->setBackgroundPixmap(QPixmap(QString::fromUtf8(":/Imagenes/bad.png")));
    consola->showMaximized();
    if (ui->radioButton->isChecked())
    {
        QString prueba = "su - "+User;
        QString enter = "\r";
        consola->sendText(prueba);
        consola->sendText(enter);
        QString prueba1 = "clear ";
        QString enter1 = "\r";
        consola->sendText(prueba1);
        consola->sendText(enter1);
    }
    connect(consola,SIGNAL(finished()),this,SLOT(finalizar()));
}

bool Terminal::eventFilter(QObject* obj, QEvent *event)
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
                ayuda->Valor(tr("TermRDK"));
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void Terminal::on_pushButton_2_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void Terminal::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QTermWidget *pt;
    if (ui->tabWidget->currentIndex()>=0)
    {
       pt=(QTermWidget *)ui->tabWidget->currentWidget();       
       int letra = ui->comboBox_2->currentText().toInt();
       QString Fuente = ui->fontComboBox->currentText();
       QFont fontNew;
       fontNew.setFamily(Fuente);
       fontNew.setPointSize(letra);
       pt->setTerminalFont(fontNew);
       pt->setColorScheme(arg1);
    }
}

void Terminal::closeTab(int index)
{
    if (ui->tabWidget->count() > 1)
        ui->tabWidget->removeTab(index);
}

void Terminal::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QTermWidget *pt;
    if (ui->tabWidget->currentIndex()>=0)
    {
       pt=(QTermWidget *)ui->tabWidget->currentWidget();
       int letra = arg1.toInt();
       QString Fuente = ui->fontComboBox->currentText();
       QFont fontNew;
       fontNew.setFamily(Fuente);
       fontNew.setPointSize(letra);
       pt->setTerminalFont(fontNew);
       pt->setColorScheme(ui->comboBox->currentText());
    }
}

void Terminal::on_fontComboBox_currentIndexChanged(const QString &arg1)
{
    QTermWidget *pt;
    if (ui->tabWidget->currentIndex()>=0)
    {
       pt=(QTermWidget *)ui->tabWidget->currentWidget();
       int letra = ui->comboBox_2->currentText().toInt();
       QFont fontNew;
       fontNew.setFamily(arg1);
       fontNew.setPointSize(letra);
       pt->setTerminalFont(fontNew);
       pt->setColorScheme(ui->comboBox->currentText());
    }
}
