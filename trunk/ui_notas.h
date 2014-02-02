/********************************************************************************
** Form generated from reading UI file 'notas.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTAS_H
#define UI_NOTAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_notas
{
public:
    QGridLayout *gridLayout_6;
    QLabel *label_2;
    QLabel *label_3;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_5;
    QTextEdit *textEdit_5;
    QPushButton *pushButton_2;
    QLabel *label;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit_3;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QTextEdit *textEdit_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QTextEdit *textEdit;
    QWidget *tab_4;
    QGridLayout *gridLayout;
    QTextEdit *textEdit_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *notas)
    {
        if (notas->objectName().isEmpty())
            notas->setObjectName(QString::fromUtf8("notas"));
        notas->setEnabled(true);
        notas->resize(470, 406);
        notas->setMinimumSize(QSize(470, 406));
        notas->setMaximumSize(QSize(470, 406));
        QPalette palette;
        QBrush brush(QColor(53, 53, 53, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        notas->setPalette(palette);
        QFont font;
        font.setPointSize(7);
        notas->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/kapyderi.png"), QSize(), QIcon::Normal, QIcon::Off);
        notas->setWindowIcon(icon);
        gridLayout_6 = new QGridLayout(notas);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_2 = new QLabel(notas);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 11pt \"Sans Serif\";\n"
"font: bold Italic;\n"
"color: rgb(0, 0, 255);"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(notas);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 11pt \"Sans Serif\";\n"
"font: bold Italic;\n"
"color: rgb(0, 0, 255);"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_3, 3, 0, 1, 1);

        tabWidget = new QTabWidget(notas);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(127, 127, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(170, 170, 170, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        tabWidget->setPalette(palette1);
        QFont font1;
        font1.setPointSize(7);
        font1.setBold(true);
        font1.setWeight(75);
        tabWidget->setFont(font1);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tab_5->setEnabled(true);
        gridLayout_5 = new QGridLayout(tab_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        textEdit_5 = new QTextEdit(tab_5);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setEnabled(true);
        textEdit_5->setMaximumSize(QSize(16777215, 315));
        textEdit_5->setStyleSheet(QString::fromUtf8(""));
        textEdit_5->setReadOnly(true);

        gridLayout_5->addWidget(textEdit_5, 0, 3, 2, 1);

        pushButton_2 = new QPushButton(tab_5);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout_5->addWidget(pushButton_2, 2, 3, 1, 1);

        label = new QLabel(tab_5);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 0, 1, 3, 1);

        tabWidget->addTab(tab_5, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textEdit_3 = new QTextEdit(tab);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setStyleSheet(QString::fromUtf8(""));
        textEdit_3->setOverwriteMode(true);

        gridLayout_2->addWidget(textEdit_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textEdit_2 = new QTextEdit(tab_3);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setOverwriteMode(true);

        gridLayout_3->addWidget(textEdit_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        textEdit = new QTextEdit(tab_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setOverwriteMode(true);

        gridLayout_4->addWidget(textEdit, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout = new QGridLayout(tab_4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit_4 = new QTextEdit(tab_4);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setReadOnly(true);

        gridLayout->addWidget(textEdit_4, 0, 0, 1, 2);

        pushButton_3 = new QPushButton(tab_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(tab_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout->addWidget(pushButton_4, 1, 1, 1, 1);

        tabWidget->addTab(tab_4, QString());

        gridLayout_6->addWidget(tabWidget, 1, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 2, 1, 1, 1);

        pushButton = new QPushButton(notas);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(57, 26));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout_6->addWidget(pushButton, 2, 2, 2, 1);


        retranslateUi(notas);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(notas);
    } // setupUi

    void retranslateUi(QDialog *notas)
    {
        notas->setWindowTitle(QApplication::translate("notas", "Acerca de...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("notas", "Version 3.149.91 T.E.U. La Version final", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("notas", "RecoverDrake -- Proyecto Derix", 0, QApplication::UnicodeUTF8));
        textEdit_5->setHtml(QApplication::translate("notas", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:7pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400; color:#0000ff;\">kapyderi 2010/2013 -- BOFH de Blogdrake.net</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">RecoverDrake es una utilidad que le puede sacar de muchos apuros.</span></p"
                        ">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">En un principio fue creada para recuperar paquetes instalados en su ordenardor y poder volver a instalarlos sin tener que recordar que habia instalado anteriormente, a quien no le ha pasado alguna vez, \302\277verdad?.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">Con el paso del tiempo, se ha hecho mas extenso y e"
                        "n estos momentos cubre muchas aplicaciones en una, ya que tienes infinidad de soporte a problemas, configuraciones y extras.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">No me hago responsable por el uso que se le de a </span><span style=\" font-style:italic; color:#0000ff;\">Recover</span><span style=\" font-style:italic; color:#ff0000;\">Drake</span><span style=\" font-style:italic;\"> o defectos y perdidas que puedan ser derivadas de su uso, como por ejemplo &quot;bugs&quot; o mala utilizaci\303\263n de sus herramientas.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><sp"
                        "an style=\" font-style:italic;\">Todos las utilidades son externas a RecoverDrake por lo que cualquier fallo de uso es derivado del c\303\263digo anfitri\303\263n y no del codigo huesped.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-style:italic;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">Gracias por usarlo.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-style:italic;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Dedicado a mi mujer Paky y a mis dos hijas, Atenea y Minerva. </p>\n"
"<p align=\""
                        "center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">(Sois mis inspiraci\303\263n)</p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Para cualquier bugs o comentario: <span style=\" font-style:italic; color:#ff0000;\">kapyderi@eresmas.com</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-style:italic; color:#ff0000;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-style:italic; color:#0000ff;\">Recover"
                        "</span><span style=\" font-size:9pt; font-style:italic; color:#ff0000;\">Drake</span><span style=\" font-style:italic; color:#ff0000;\"> </span><span style=\" font-style:italic; color:#000000;\">forma parte del </span><span style=\" font-size:9pt; font-style:italic; color:#ff0000;\">Proyecto Derix</span><span style=\" font-style:italic; color:#000000;\">, un proyecto que en el futuro abarcara muchas herramientas diferentes totalmente gratuitas y otros paquetes de software para entornos web y aplicaciones.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-style:italic; color:#000000;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic; color:#000000;\">...Bienvenido al mundo </span><span style=\" font-style:italic; color:#ff0000;\">DERIX!!!</span></"
                        "p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("notas", "www.kapyderi.blogspot.com", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("notas", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:7pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/Imagenes/kapyderi.jpg\" width=\"100\" height=\"75\" /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0;"
                        " text-indent:0px;\"><img src=\":/Imagenes/LogoRD.png\" width=\"65\" height=\"50\" /><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/Imagenes/URI_www_kapyderi_blogspog.png\" width=\"120\" height=\"120\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("notas", "Acerca de...", 0, QApplication::UnicodeUTF8));
        textEdit_3->setHtml(QApplication::translate("notas", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:7pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-style:italic; color:#0000ff;\">RecoverDrake 2.31.28 T.E.U. The Final Release</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; color:#ff0000; vertical-align:super;\">Proyecto Derix</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Programaci\303\263n:<span style=\" color:#0000"
                        "ff;\"> kapyderi</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000ff;\">                        </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#000000;\">Apoyo:</span><span style=\" color:#0000ff;\"> lexblas, Adriamag, Thanatos, JC, Er Bardo, Motitos</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#0000ff;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Diseno: <span style=\" color:#0000ff;\">kapyderi</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; m"
                        "argin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Idea: <span style=\" color:#0000ff;\">kapyderi</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Lenguajes utilizados: </p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000ff;\">Qt 4.7.2 o superior (Librerias y programaci\303\263n)</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000ff;\""
                        ">Qt-Creator (Montaje Visual)</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000ff;\">Bash (Linea de comandos)</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000ff;\">Zenity (Ventanas interactivas)</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000ff;\">C++ (Programaci\303\263n)</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000ff;\">Sqlite (Base de datos)</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-in"
                        "dent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400; font-style:italic; color:#0000ff;\">* Podria haber evitado varios como, Zenity o Bash, pero he querido utilizarlos para ampliar el horizonte de programacion y aprendizaje.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400; font-style:italic; color:#0000ff;\"><br /></span>Distribuciones Linux soportadas:</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> <img src=\":/Imagenes/mandriva.png\" width=\"20\" height=\"20\" /><span style=\" color:#0000ff;\">Mandriva 2011.x o superior (100%)</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px;"
                        " margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000ff;\"> </span><img src=\":/Imagenes/Mageia.png\" width=\"20\" height=\"20\" /><span style=\" color:#0000ff;\">Mageia 1 o superior (100%)</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/Imagenes/mandriva.png\" width=\"20\" height=\"20\" /><span style=\" color:#0000ff;\">Mandriva 2010.2 o inferiores (con kde 4.5.5)</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000ff;\"><br /></span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0000ff;\">Otras distribuciones (Funcional en algunas opciones, resto en proceso).</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("notas", "Creditos", 0, QApplication::UnicodeUTF8));
        textEdit_2->setHtml(QApplication::translate("notas", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:7pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:400;\"><br /></span><img src=\":/Imagenes/SPAIN.png\" width=\"50\" height=\"25\" /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Idioma Espanol: <span style=\" color:#0000ff;\">kapyderi</span></p>\n"
""
                        "<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/Imagenes/ingles.jpeg\" width=\"50\" height=\"25\" /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Idioma Ingles: <span style=\" color:#0000ff;\">motitos/kapyderi (Perdon por mi mala traduccion)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("notas", "Traduccion", 0, QApplication::UnicodeUTF8));
        textEdit->setHtml(QApplication::translate("notas", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:7pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">changelog:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Wes Jun 25 2012 &lt;kapyd"
                        "er@eresmas.com&gt; 2.30.28.bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Bugs corregidos.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Google Translate incluido en browser.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Centro de Control de Mandriva/Mageia incluido.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><b"
                        "r /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic; color:#071638;\">**VERSION 2.25.21 a 2.29.27 tratadas de forma interna (NO liberadas)**</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Tue Jun 10 2012 &lt;kapyder@eresmas.com&gt; 2.24.20.bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Bugs corregidos.</span></p>\n"
""
                        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Cambio automatico en idioma al seleccionar.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic; color:#071638;\">**VERSION 2.23.19 tratada de forma interna (NO liberada)**</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Mon Jun 9 2012 &lt;kapyder@eresmas.com&gt; 2.22.18.bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Bugs corregidos.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Menu de administrador (no para usuarios).</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; ma"
                        "rgin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Sun Jun 8 2012 &lt;kapyder@eresmas.com&gt; 2.21.17.bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Bugs corregidos.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Reproductor de Video.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Reproductor de Audio.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block"
                        "-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Televisi\303\263n por Internet.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Radio por Internet.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Funciones principales Interactivas.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">y mucho mas...xD</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; te"
                        "xt-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic; color:#071638;\">**VERSION 2.1.0 a 2.21.16 tratadas de forma interna (NO liberadas)**</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Sat Feb 26 2011 &lt;kapyderi@eresmas.com&gt; 2.0.0.bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; fo"
                        "nt-weight:400; font-style:italic; color:#071638;\">- Bugs corregidos.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Programaci\303\263n mixta de Qt, C++, Script/Bash, zennity.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Creacion de usuarios de mantenimiento de RecoverDrake.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Acceso con claves (Por defecto admin/admin)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"
                        "\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Comprobaci\303\263n de dependencias necesarias.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Recuperar paquetes huerfanos eliminados.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Crear usb-live.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Eliminar imagen iso.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style="
                        "\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Anadir kde inestable.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Actualizar kde inestable.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Eliminar kde inestable.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Instalar paquetes.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:ital"
                        "ic; color:#071638;\">- Instalar todos los escritorio, individual o masivo.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Instalar impresoras.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Instalar wifi con ndiswrapper.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Instalar drivers wifi propietarios (Los m\303\241s comunes y licencia).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8p"
                        "t; font-weight:400; font-style:italic; color:#071638;\">- Convertir cararcteres especiales a UTF-8.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Sustituir espacios en blanco en nombre de archivos por rutas.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Resetear configuraci\303\263n kde, sin cambios. </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Actualizar kde a idioma espanol.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; t"
                        "ext-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- NTFS sin permisos (correcci\303\263n de bugs).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Recuperar contrasena de usuario.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Recuperar ficheros/directorios borrados por accidente.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Excluir/incluir paquetes a actualizar.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin"
                        "-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Anadir usuario a sudo.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Cargar direcci\303\263n sop y visualizar evento (Sopcast).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Consola como root.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Conversi\303\263n de .deb a .rpm</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:"
                        "0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Extraer audio a un video.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Anadir audio a un video.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Convertir formatos de audio.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Ripeado de CD's.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
                        "<span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Convertir formatos de video, incluido contenedor MATROSKA.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Convertir avi HD a avi Standard.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Informaci\303\263n de librerias de binarios.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Informaci\303\263n de paquetes dependientes.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px"
                        "; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Quemador de discos.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Preparaci\303\263n de compatibilidad con Mageia. </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Agradecimientos.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Ayuda a comandos consola m\303\241s usuales.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-blo"
                        "ck-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Ayuda a programas de consola m\303\241s usuales.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Notas de versi\303\263n.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Todas las opciones se pueden cancelar en la ventana de informaci\303\263n del evento.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Informaci\303\263n detallada y licencias en todas las opciones.</span></p>\n"
"<p sty"
                        "le=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Ventana de bienvenida.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Acceso como root.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Consola externa y consola incrutada (interna).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">y mucho mas...</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-to"
                        "p:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Sat Oct 23 2010 &lt;kapyderi@eresmas.com&gt; 0.5.1.3bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Bugs corregidos</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; t"
                        "ext-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Wed Oct 13 2010 &lt;kapyderi@eresmas.com&gt; 0.5.0.3bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Elecci\303\263n de ruta para copiar los rpms y tambien para el volcado</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Generaci\303\263n de fichero de cambios realizados durante el volcado</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Instalaci\303\263n de dependencias</span></p>\n"
"<p style=\" "
                        "margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Instalaci\303\263n de versiones inestables o no soportados de kde y restauracion</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Instalaci\303\263n de cualquier escritorio (necesario por si falla un escritorio)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Instalaci\303\263n de drivers wifi con ndiswrapper</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weig"
                        "ht:400; font-style:italic; color:#071638;\">- Guardar configuraciones de sistema y restauracion</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Copia de seguridad y restauracion </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: Desconexion Wifi WEB/WPA</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: Desconexion Wifi Abierta</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bl"
                        "ock-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: Codecs audio/video</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: Exceso de memoria en procesos con Dolphin</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: Configurar sopcast/qsopcast</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos:"
                        " Firefox con pdf</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: kdeinit4 inicia con error</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: Recuperar configuraci\303\263n de kde</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: VirtualBox no se ejecuta</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><sp"
                        "an style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: RPM database bloqued</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: Excluir actualizaci\303\263n de paquete</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: KTTSD no se esta ejecutando</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: NTFS sin permisos.</span></p>\n"
"<"
                        "p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: Preparar para autocompilar (DKMS)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Soluci\303\263n a problemas conocidos: Recuperar ficheros/directorios borrados por accidente.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Duplicado de discos completos.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:40"
                        "0; font-style:italic; color:#071638;\">- Montaje de imagenes .iso</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Desmontaje de imagenes .iso</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Duplicado de particiones.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Creaci\303\263n de imagenes .iso  </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color"
                        ":#071638;\">- Modificaci\303\263n automatica del fichero .lst con la versi\303\263n de Mandriva que se este utilizando Free, One, Flash o Powerpack</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Bugs corregidos</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-style:italic; color:#071638;\">**VERSION 0.4.0 tratada de forma interna (NO liberada)**</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:"
                        "0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Sat Jun 12 2010 &lt;kapyderi@eresmas.com&gt; 0.3.0-2bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Modo interactivo.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Edici\303\263n de repositorios.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weig"
                        "ht:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Fri Apr 23 2010 &lt;kapyderi@eresmas.com&gt; 0.2.0-2bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Introducci\303\263n de repositorios de forma manual.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Bugs corregidos.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-styl"
                        "e:italic; color:#071638;\">- Comentarios en consola para todas las opciones.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Volcado totalmente automatico.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Sun Apr 4 2010 &lt;kapyderi@eresmas.com&gt; 0.1.3-2bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style"
                        ":italic; color:#071638;\">- Introducci\303\263n de nombre de usuario para evitar conflictos.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Sun Apr 4 2010 &lt;kapyderi@eresmas.com&gt; 0.1.2-2bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Correccion de usuarios con nombre muy largo.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font"
                        "-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Sat Apr 3 2010 &lt;kapyderi@eresmas.com&gt; 0.1.1-2bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Reducci\303\263n ventana de bienvenida.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Instalaci\303\263n de dependencias.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-siz"
                        "e:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Mon Mar 22 2010 &lt;kapyderi@eresmas.com&gt; 0.1.0-2bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Se puede ejecutar abriendo una consola para ver los resultados</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br />* Sat Feb 27 2010 &lt;kapyderi@eresmas.com&gt; 0.1.1-1bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text"
                        "-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Bugs corregidos</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Opci\303\263n de auto-orphans</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Opci\303\263n de confirmaci\303\263n de actualizar repositorios</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span styl"
                        "e=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">* Sat Feb 19 2010 &lt;kapyderi@eresmas.com&gt; 0.1.0-1bdk</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:400; font-style:italic; color:#071638;\">- Comienzo del Script</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; font-weight:400; font-style:italic; color:#071638;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic; color:#071638;\">NOTA: Las versiones intermedias que no aparecen en changelot es debido a versiones internas y correcciones que no considero que deban estar representadas como release.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("notas", "Notas de la versi\303\263n", 0, QApplication::UnicodeUTF8));
        textEdit_4->setHtml(QApplication::translate("notas", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:7pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">No por ultimo menos importante, quiero agradecer a...</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Katnatek<span style=\" font-weight:400;\">, por parte de su codigo y por la ayuda desinteresada.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; "
                        "margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">SinnerBOFH<span style=\" font-weight:400;\">, por su experiencia.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Drakor<span style=\" font-weight:400;\">, por su ayuda e interes.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-ind"
                        "ent:0; text-indent:0px;\">Paky<span style=\" font-weight:400;\">, mi mujer, por soportarme en el teclado.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Atenea<span style=\" font-weight:400;\">, mi hija mayor, por su admiraci\303\263n por mi hobbie.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Minerva<span style=\" font-weight:400;\">, mi hija menor, por los ratos sentada en mi regazo mientras programo.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; "
                        "margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Motitos<span style=\" font-weight:400;\">, por sus reflexiones de como deber\303\255a ser RecoverDrake y </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">traducciones. Muchisimas Gracias!!!</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Adrimag<span style=\" font-weight:400;\">, </span>Er Bardo, JC y Thanatos, <span style=\" font-weight:400;\""
                        ">del foro www.zonaqt.com, por sus explicaciones sobre el compilador y su gran aportacion a la construcion de este programa basado en C++/Qt. Gracias companeros!!!</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Menci\303\263n especial a<span style=\" font-weight:400;\"> </span>Leo Vasquez (lexblas) [Miembro del Proyecto Derix]<span style=\" font-weight:400;\">, de ZonaQt, por las horas de ayuda y explicaciones. </span><span style=\" font-weight:400; font-style:italic;\">Sin ti no habria sido posible esto...que lo sepas xD </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">Colaborador activo del proyecto RecoverDrake "
                        "y creador de codigo y adem\303\241s he conseguido que se instale Mageia, jeje</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Michael Jackson<span style=\" font-weight:400;\">, mi inspiraci\303\263n, por la inspiraci\303\263n mientras oigo su musica - R.I.P. 25-06-2009.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Linus Tolvards<span style=\" font-weight:400;\">, por crear casi sin querer este hermoso mundo llamado Linux (No hay mejor nombre para darle un homenaje).</spa"
                        "n></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Luigi<span style=\" font-weight:400;\">, por su interes y pruebas y he conseguido que se instale Mandriva, jeje</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">vinxenso [Miembro del Proyecto Derix]<span style=\" font-weight:400;\">, porque si Internet fuera una persona, seguro seria el.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block"
                        "-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Carlos &quot;Toro&quot;<span style=\" font-weight:400;\">, no te olvido, estes donde estes - R.I.P. 25-08-2000.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Jean-Pierre<span style=\" font-weight:400;\">, la enfermedad te pudo, no te olvido, estes donde estes - R.I.P. 2012.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-i"
                        "ndent:0px;\">Blogdrake y ZonaQt<span style=\" font-weight:400;\">, porque sin ellas, no habria sido lo que es ahora RecoverDrake.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:400;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">...si me dejo alguien que me perdone, pero es que es &quot;muuu&quot; tarde.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("notas", "www.blogdrake.net", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("notas", "www.codigoqt.com", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("notas", "Agradecimientos", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("notas", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class notas: public Ui_notas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTAS_H
