/********************************************************************************
** Form generated from reading UI file 'makefile.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEFILE_H
#define UI_MAKEFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_makefile
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QTextEdit *textEdit;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QCheckBox *checkBox_7;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_3;
    QPushButton *pushButton;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_5;

    void setupUi(QDialog *makefile)
    {
        if (makefile->objectName().isEmpty())
            makefile->setObjectName(QString::fromUtf8("makefile"));
        makefile->resize(1106, 652);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(makefile->sizePolicy().hasHeightForWidth());
        makefile->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(7);
        makefile->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/nucleo.png"), QSize(), QIcon::Normal, QIcon::Off);
        makefile->setWindowIcon(icon);
        gridLayout_4 = new QGridLayout(makefile);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_2 = new QGroupBox(makefile);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMaximumSize(QSize(16777215, 60));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout->addWidget(radioButton_4, 0, 1, 1, 1);

        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 2, 1);

        groupBox = new QGroupBox(makefile);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_2->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_2->addWidget(radioButton_2, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 2, 2, 1, 2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(19, 25));

        gridLayout_2->addWidget(pushButton_3, 0, 1, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 2, 1, 2);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 1, 1, 1, 3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(19, 25));

        gridLayout_2->addWidget(pushButton_5, 2, 1, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(150, 30));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/Correcto.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);

        gridLayout_2->addWidget(pushButton_4, 3, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 2);

        textEdit = new QTextEdit(makefile);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(textEdit, 5, 0, 1, 2);

        groupBox_4 = new QGroupBox(makefile);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy2);
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        checkBox_7 = new QCheckBox(groupBox_4);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setEnabled(false);

        gridLayout_5->addWidget(checkBox_7, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout_5->addWidget(label_4, 1, 0, 1, 3);

        pushButton_6 = new QPushButton(groupBox_4);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon2);

        gridLayout_5->addWidget(pushButton_6, 2, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_4, 4, 1, 1, 1);

        pushButton_2 = new QPushButton(makefile);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(80, 16777215));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);

        gridLayout_4->addWidget(pushButton_2, 6, 0, 1, 1);

        groupBox_3 = new QGroupBox(makefile);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy2.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(false);

        gridLayout_3->addWidget(checkBox, 2, 0, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setEnabled(false);

        gridLayout_3->addWidget(checkBox_3, 2, 2, 1, 1);

        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/local-administration-mdk.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon4);

        gridLayout_3->addWidget(pushButton, 6, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setEnabled(false);

        gridLayout_3->addWidget(checkBox_2, 2, 1, 1, 1);

        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_3->addWidget(checkBox_4, 2, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 6, 1, 1, 3);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout_3->addWidget(label, 5, 0, 1, 4);


        gridLayout_4->addWidget(groupBox_3, 4, 0, 1, 1);

        groupBox_5 = new QGroupBox(makefile);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(16777215, 60));
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        checkBox_6 = new QCheckBox(groupBox_5);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setEnabled(false);

        gridLayout_6->addWidget(checkBox_6, 0, 0, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_5);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setEnabled(false);

        gridLayout_6->addWidget(checkBox_5, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_5, 1, 1, 2, 1);


        retranslateUi(makefile);

        QMetaObject::connectSlotsByName(makefile);
    } // setupUi

    void retranslateUi(QDialog *makefile)
    {
        makefile->setWindowTitle(QApplication::translate("makefile", "Compilar/desinstalar desde las fuentes", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("makefile", "\302\277Que quieres hacer?", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("makefile", "Desinstalar", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("makefile", "Instalar/Compilar (Por defecto)", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("makefile", "Ruta del archivo", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("makefile", "Ruta a buscar (tar.gz)", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("makefile", "Direccion de Internet", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("makefile", "...", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QString());
        label_2->setText(QApplication::translate("makefile", "Ruta de instalacion alternativa", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("makefile", "...", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("makefile", "Validar Archivo", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("makefile", "Procesos a realizar en desinstalacion", 0, QApplication::UnicodeUTF8));
        checkBox_7->setText(QApplication::translate("makefile", "make uninstall", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("makefile", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:7pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">*No todas las instalaciones pueden ser desinstaladas. Depende de los ficheros de construccion.</p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("makefile", "Desinstalar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("makefile", "Salir", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("makefile", "Procesos a realizar en instalacion", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("makefile", "./configure", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("makefile", "make install", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("makefile", "Compilar/Instalar", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("makefile", "make", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("makefile", "make clean (*)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("makefile", "<html><head/><body><p>*Opcional. Borra los ficheros de instalacion una vez acabado el proceso. Si se borran no se puede hacer uninstall.</p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("makefile", "Contenido", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("makefile", "Contiene fichero de instalacion", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("makefile", "Contiene fichero de configuracion", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class makefile: public Ui_makefile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEFILE_H
