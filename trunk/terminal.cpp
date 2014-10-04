#include "terminal.h"
#include "ui_terminal.h"
#include <QDir>
#include <drakesistema.h>
#include <QDebug>
#include <QTabBar>

class MyTabWidget:public QTabWidget
{
public:
    MyTabWidget(QWidget* parent = 0){
        setParent(parent);
    }
    QTabBar* tabBar() {
      return QTabWidget::tabBar();
    }
};

Terminal::Terminal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Terminal)
{
    drakeSistema drake;
    User = drake.getUser();
    ui->setupUi(this);
    ui->tabWidget->setUsesScrollButtons(true);
    QIcon::setThemeName("oxygen");
    this->setWindowIcon(QIcon::fromTheme("utilities-terminal"));
    consola = new QTermWidget();
    QStringList ColorSchema =  QTermWidget::availableColorSchemes();
    ui->comboBox->addItems(ColorSchema);
    ui->comboBox->setCurrentText("WhiteOnBlack");
    ui->tabWidget->addTab(consola, QString(QDir::currentPath()));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
    font.setFamily("Monospace");
    font.setPointSize(12);
    consola->setTerminalFont(font);
    consola->setScrollBarPosition(QTermWidget::ScrollBarRight);
    consola->setColorScheme(ui->comboBox->currentText());
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
    //ui->tabWidget->tabBar()->setTabTextColor(0, Qt::red);
}

Terminal::~Terminal()
{
    delete ui;
}

void Terminal::finalizar()
{
    ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
}

void Terminal::on_pushButton_clicked()
{
    consola = new QTermWidget();
    ui->tabWidget->addTab(consola, QString(QDir::currentPath()));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);
    font.setFamily("Monospace");
    font.setPointSize(12);
    consola->setTerminalFont(font);
    consola->setScrollBarPosition(QTermWidget::ScrollBarRight);
    consola->setColorScheme(ui->comboBox->currentText());
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

void Terminal::on_pushButton_2_clicked()
{
    close();
}

void Terminal::on_comboBox_currentIndexChanged(const QString &arg1)
{
   consola->setColorScheme(arg1);
}

void Terminal::closeTab(int index)
{
    if (ui->tabWidget->count() > 1)
        ui->tabWidget->removeTab(index);
}
