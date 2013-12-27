/********************************************************************************
** Form generated from reading UI file 'kernel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KERNEL_H
#define UI_KERNEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Kernel
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QLabel *label;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButton_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_7;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_8;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QRadioButton *radioButton_7;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_9;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_10;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_11;
    QRadioButton *radioButton_6;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_10;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_8;
    QRadioButton *radioButton_13;
    QRadioButton *radioButton_12;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_10;
    QSpacerItem *verticalSpacer;
    QLabel *label_9;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_11;

    void setupUi(QDialog *Kernel)
    {
        if (Kernel->objectName().isEmpty())
            Kernel->setObjectName(QString::fromUtf8("Kernel"));
        Kernel->resize(887, 710);
        QFont font;
        font.setPointSize(7);
        Kernel->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/nucleo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Kernel->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(Kernel);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(Kernel);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 0, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 0, 0, 1, 1);

        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout->addWidget(radioButton, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 3, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);

        gridLayout_3->addWidget(pushButton_4, 1, 3, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 8pt \"DejaVu Sans\";\n"
"color: rgb(255, 0, 0);\n"
"font: bold;"));

        gridLayout_3->addWidget(label, 1, 0, 1, 3);


        gridLayout_2->addWidget(groupBox, 1, 1, 1, 7);

        groupBox_2 = new QGroupBox(Kernel);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(2, 2, 2, 2);
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_4->addWidget(textEdit, 1, 0, 1, 1);

        progressBar = new QProgressBar(groupBox_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setLayoutDirection(Qt::RightToLeft);
        progressBar->setValue(0);
        progressBar->setOrientation(Qt::Vertical);

        gridLayout_4->addWidget(progressBar, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 5, 1, 2, 7);

        pushButton_3 = new QPushButton(Kernel);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);

        gridLayout_2->addWidget(pushButton_3, 8, 7, 1, 1);

        groupBox_3 = new QGroupBox(Kernel);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        radioButton_4 = new QRadioButton(groupBox_3);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout_5->addWidget(radioButton_4, 0, 1, 1, 1);

        radioButton_3 = new QRadioButton(groupBox_3);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_5->addWidget(radioButton_3, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 0, 1, 1, 7);

        groupBox_4 = new QGroupBox(Kernel);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_6 = new QGridLayout(groupBox_4);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        radioButton_5 = new QRadioButton(groupBox_4);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

        gridLayout_6->addWidget(radioButton_5, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        pushButton_7 = new QPushButton(groupBox_4);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setIcon(icon1);

        gridLayout_6->addWidget(pushButton_7, 0, 6, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_8 = new QGridLayout(groupBox_6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(groupBox_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_8->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_8->addWidget(label_4, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_8->addWidget(label_2, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_6);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_8->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_8->addWidget(label_6, 1, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_6, 2, 0, 1, 7);

        radioButton_7 = new QRadioButton(groupBox_4);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));

        gridLayout_6->addWidget(radioButton_7, 0, 4, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_4);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_9 = new QGridLayout(groupBox_7);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        radioButton_8 = new QRadioButton(groupBox_7);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));

        gridLayout_9->addWidget(radioButton_8, 1, 0, 1, 1);

        radioButton_10 = new QRadioButton(groupBox_7);
        radioButton_10->setObjectName(QString::fromUtf8("radioButton_10"));

        gridLayout_9->addWidget(radioButton_10, 1, 3, 1, 1);

        radioButton_9 = new QRadioButton(groupBox_7);
        radioButton_9->setObjectName(QString::fromUtf8("radioButton_9"));

        gridLayout_9->addWidget(radioButton_9, 1, 2, 1, 1);

        radioButton_11 = new QRadioButton(groupBox_7);
        radioButton_11->setObjectName(QString::fromUtf8("radioButton_11"));

        gridLayout_9->addWidget(radioButton_11, 1, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_7, 1, 0, 1, 7);

        radioButton_6 = new QRadioButton(groupBox_4);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));

        gridLayout_6->addWidget(radioButton_6, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 0, 5, 1, 1);


        gridLayout_2->addWidget(groupBox_4, 3, 1, 1, 7);

        groupBox_5 = new QGroupBox(Kernel);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_7 = new QGridLayout(groupBox_5);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        pushButton_5 = new QPushButton(groupBox_5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(40, 16777215));

        gridLayout_7->addWidget(pushButton_5, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_5);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_7->addWidget(lineEdit_2, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(groupBox_5);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setIcon(icon1);

        gridLayout_7->addWidget(pushButton_6, 0, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_5, 2, 1, 1, 7);

        pushButton_9 = new QPushButton(Kernel);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/console-mdk.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon3);

        gridLayout_2->addWidget(pushButton_9, 8, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 8, 5, 1, 1);

        groupBox_8 = new QGroupBox(Kernel);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_11 = new QGridLayout(groupBox_8);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_7 = new QLabel(groupBox_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_10->addWidget(label_7, 0, 2, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox_8);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_10->addWidget(lineEdit_3, 0, 3, 1, 1);

        pushButton_8 = new QPushButton(groupBox_8);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setIcon(icon);

        gridLayout_10->addWidget(pushButton_8, 0, 6, 1, 1);

        radioButton_13 = new QRadioButton(groupBox_8);
        radioButton_13->setObjectName(QString::fromUtf8("radioButton_13"));

        gridLayout_10->addWidget(radioButton_13, 0, 1, 1, 1);

        radioButton_12 = new QRadioButton(groupBox_8);
        radioButton_12->setObjectName(QString::fromUtf8("radioButton_12"));

        gridLayout_10->addWidget(radioButton_12, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(0, 0, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_5, 0, 5, 1, 1);

        pushButton_10 = new QPushButton(groupBox_8);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMaximumSize(QSize(50, 38));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon4);
        pushButton_10->setIconSize(QSize(30, 30));

        gridLayout_10->addWidget(pushButton_10, 0, 4, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_8, 4, 1, 1, 7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 5, 1, 1);

        label_9 = new QLabel(Kernel);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Helvetica"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("font: 14pt \"Helvetica\";\n"
"font: bold;"));

        gridLayout_2->addWidget(label_9, 8, 4, 1, 1);

        label_8 = new QLabel(Kernel);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"Helvetica\";\n"
"font: bold;"));

        gridLayout_2->addWidget(label_8, 8, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 8, 2, 1, 1);

        pushButton_11 = new QPushButton(Kernel);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon5);

        gridLayout_2->addWidget(pushButton_11, 8, 6, 1, 1);


        retranslateUi(Kernel);

        QMetaObject::connectSlotsByName(Kernel);
    } // setupUi

    void retranslateUi(QDialog *Kernel)
    {
        Kernel->setWindowTitle(QApplication::translate("Kernel", "Kernel personalizado", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Kernel", "Preparar nucleo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("Kernel", "Direccion del archivo comprimido del nucleo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QApplication::translate("Kernel", "Direccion del archivo comprimido del nucleo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit->setWhatsThis(QApplication::translate("Kernel", "Direccion del archivo comprimido del nucleo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        lineEdit->setText(QString());
#ifndef QT_NO_TOOLTIP
        radioButton_2->setToolTip(QApplication::translate("Kernel", "Opcion de busqueda en el ordenador", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_2->setStatusTip(QApplication::translate("Kernel", "Opcion de busqueda en el ordenador", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_2->setWhatsThis(QApplication::translate("Kernel", "Opcion de busqueda en el ordenador", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_2->setText(QApplication::translate("Kernel", "Ordenador", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton->setToolTip(QApplication::translate("Kernel", "Opcion de busqueda en internet", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton->setStatusTip(QApplication::translate("Kernel", "Opcion de busqueda en internet", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton->setWhatsThis(QApplication::translate("Kernel", "Opcion de busqueda en internet", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton->setText(QApplication::translate("Kernel", "Internet", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("Kernel", "Direccion donde estan todos los nucleos oficiales", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("Kernel", "Direccion donde estan todos los nucleos oficiales", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("Kernel", "Direccion donde estan todos los nucleos oficiales", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("Kernel", "http://www.kernel.org/", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("Kernel", "Buscar en el ordenador.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("Kernel", "Buscar en el ordenador.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("Kernel", "Buscar en el ordenador.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("Kernel", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("Kernel", "Preparacion del nucleo para su posterior compilacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("Kernel", "Preparacion del nucleo para su posterior compilacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("Kernel", "Preparacion del nucleo para su posterior compilacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("Kernel", "Preparar Kernel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Kernel", "* Pegar la ruta completa de la direccion de Internet.", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Kernel", "Consola de procesos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("Kernel", "Consola de procesos con toda la informacion extendida", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit->setStatusTip(QApplication::translate("Kernel", "Consola de procesos con toda la informacion extendida", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QApplication::translate("Kernel", "Consola de procesos con toda la informacion extendida", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("Kernel", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("Kernel", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("Kernel", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("Kernel", "Salir", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Kernel", "Tratamiento del nucleo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_4->setToolTip(QApplication::translate("Kernel", "Se comienza desde la compilacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_4->setStatusTip(QApplication::translate("Kernel", "Se comienza desde la compilacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_4->setWhatsThis(QApplication::translate("Kernel", "Se comienza desde la compilacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_4->setText(QApplication::translate("Kernel", "Localizacion de Nucleo ya preparado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_3->setToolTip(QApplication::translate("Kernel", "Activa la opcion de Preparar nucleo para localizar un nucleo en bruto y realiza los pasos para compilar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_3->setStatusTip(QApplication::translate("Kernel", "Activa la opcion de Preparar nucleo para localizar un nucleo en bruto y realiza los pasos para compilar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_3->setWhatsThis(QApplication::translate("Kernel", "Activa la opcion de Preparar nucleo para localizar un nucleo en bruto y realiza los pasos para compilar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_3->setText(QApplication::translate("Kernel", "Preparacion de Nucleo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_4->setToolTip(QApplication::translate("Kernel", "Tipo de configuracion del nucleo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_4->setStatusTip(QApplication::translate("Kernel", "Tipo de configuracion del nucleo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupBox_4->setWhatsThis(QApplication::translate("Kernel", "Tipo de configuracion del nucleo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_4->setTitle(QApplication::translate("Kernel", "Configurar nucleo ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_5->setToolTip(QApplication::translate("Kernel", "Comenzar desde cero la configuracion del nucleo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_5->setStatusTip(QApplication::translate("Kernel", "Comenzar desde cero la configuracion del nucleo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_5->setWhatsThis(QApplication::translate("Kernel", "Comenzar desde cero la configuracion del nucleo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_5->setText(QApplication::translate("Kernel", "Configurar Nucleo nuevo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("Kernel", "Se accede al tipo de configuracion elegido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_7->setStatusTip(QApplication::translate("Kernel", "Se accede al tipo de configuracion elegido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_7->setWhatsThis(QApplication::translate("Kernel", "Se accede al tipo de configuracion elegido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_7->setText(QApplication::translate("Kernel", "Configurar Kernel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_6->setToolTip(QApplication::translate("Kernel", "Ayuda a las opciones del menuconfig", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_6->setStatusTip(QApplication::translate("Kernel", "Ayuda a las opciones del menuconfig", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupBox_6->setWhatsThis(QApplication::translate("Kernel", "Ayuda a las opciones del menuconfig", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_6->setTitle(QApplication::translate("Kernel", "Teclas de ayuda para menuconfig", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Kernel", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#0000ff;\">shif+?</span> = Nos muestra informacion</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Kernel", "<html><head/><body><p><span style=\" font-weight:600; color:#0000ff;\">n </span>= Deshabilitar opcion dentro del Kernel (No se compila)</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Kernel", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#0000ff;\">/ </span>= Nos permite buscar</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Kernel", "<html><head/><body><p><span style=\" font-weight:600; color:#0000ff;\">m</span> = Marcar opcion como modulo</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Kernel", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#0000ff;\">y</span> = incluye la opcion dentro del kernel</p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_7->setToolTip(QApplication::translate("Kernel", "Automatiza la configuracion de un nucleo con el hardware encontrado. No recomendado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_7->setStatusTip(QApplication::translate("Kernel", "Automatiza la configuracion de un nucleo con el hardware encontrado. No recomendado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_7->setWhatsThis(QApplication::translate("Kernel", "Automatiza la configuracion de un nucleo con el hardware encontrado. No recomendado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_7->setText(QApplication::translate("Kernel", "Configurar Nucleo automaticamente", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("Kernel", "Como configurar el nucleo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_8->setToolTip(QApplication::translate("Kernel", "Acceso estandar a la configuracion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_8->setStatusTip(QApplication::translate("Kernel", "Acceso estandar a la configuracion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_8->setWhatsThis(QApplication::translate("Kernel", "Acceso estandar a la configuracion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_8->setText(QApplication::translate("Kernel", "Utilizar menuconfig (Por defecto)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_10->setToolTip(QApplication::translate("Kernel", "Acceso mediante gui GTK a la configuracion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_10->setStatusTip(QApplication::translate("Kernel", "Acceso mediante gui GTK a la configuracion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_10->setWhatsThis(QApplication::translate("Kernel", "Acceso mediante gui GTK a la configuracion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_10->setText(QApplication::translate("Kernel", "Utilizar gconfig (X Gtk)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_9->setToolTip(QApplication::translate("Kernel", "Acceso mediante gui QT a la configuracion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_9->setStatusTip(QApplication::translate("Kernel", "Acceso mediante gui QT a la configuracion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_9->setWhatsThis(QApplication::translate("Kernel", "Acceso mediante gui QT a la configuracion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_9->setText(QApplication::translate("Kernel", "Utilizar xconfig (X Qt)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_11->setToolTip(QApplication::translate("Kernel", "Acceso por consola a la configuracion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_11->setStatusTip(QApplication::translate("Kernel", "Acceso por consola a la configuracion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_11->setWhatsThis(QApplication::translate("Kernel", "Acceso por consola a la configuracion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_11->setText(QApplication::translate("Kernel", "Utilizar config (consola)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_6->setToolTip(QApplication::translate("Kernel", "Recibir una configuracion anterior de tu ordenador", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_6->setStatusTip(QApplication::translate("Kernel", "Recibir una configuracion anterior de tu ordenador", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_6->setWhatsThis(QApplication::translate("Kernel", "Recibir una configuracion anterior de tu ordenador", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_6->setText(QApplication::translate("Kernel", "Configurar Nucleo anterior", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("Kernel", "Localizar nucleo ya preparado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("Kernel", "Localiza una carpeta de nucleo para compilar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("Kernel", "Localiza una carpeta de nucleo para compilar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("Kernel", "Localiza una carpeta de nucleo para compilar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QApplication::translate("Kernel", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("Kernel", "Direccion de la carpeta con el nucleo en bruto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QApplication::translate("Kernel", "Direccion de la carpeta con el nucleo en bruto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("Kernel", "Direccion de la carpeta con el nucleo en bruto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        lineEdit_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("Kernel", "Solo crea el enlace para la compilacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_6->setStatusTip(QApplication::translate("Kernel", "Solo crea el enlace para la compilacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_6->setWhatsThis(QApplication::translate("Kernel", "Solo crea el enlace para la compilacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_6->setText(QApplication::translate("Kernel", "Crear enlace ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_9->setToolTip(QApplication::translate("Kernel", "Mostrar/ocultar consola de procesos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_9->setStatusTip(QApplication::translate("Kernel", "Mostrar/ocultar consola de procesos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_9->setWhatsThis(QApplication::translate("Kernel", "Mostrar/ocultar consola de procesos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_9->setText(QApplication::translate("Kernel", "Mostrar consola", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("Kernel", "Compilacion", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Kernel", "Ruta", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_3->setToolTip(QApplication::translate("Kernel", "Ruta que recibes de la localizacion del modulo en cuestion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_3->setStatusTip(QApplication::translate("Kernel", "Ruta que recibes de la localizacion del modulo en cuestion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_3->setWhatsThis(QApplication::translate("Kernel", "Ruta que recibes de la localizacion del modulo en cuestion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_8->setToolTip(QApplication::translate("Kernel", "A compilar el nucleo. Se paciente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_8->setStatusTip(QApplication::translate("Kernel", "A compilar el nucleo. Se paciente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_8->setWhatsThis(QApplication::translate("Kernel", "A compilar el nucleo. Se paciente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_8->setText(QApplication::translate("Kernel", "Compilar Kernel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_13->setToolTip(QApplication::translate("Kernel", "Compila solo un modulo. Util cuando solo quieres compilar un solo modulo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_13->setStatusTip(QApplication::translate("Kernel", "Compila solo un modulo. Util cuando solo quieres compilar un solo modulo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_13->setWhatsThis(QApplication::translate("Kernel", "Compila solo un modulo. Util cuando solo quieres compilar un solo modulo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_13->setText(QApplication::translate("Kernel", "Compilar modulo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_12->setToolTip(QApplication::translate("Kernel", "Compila el nucleo configurado. Puede tardar bastante tiempo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_12->setStatusTip(QApplication::translate("Kernel", "Compila el nucleo configurado. Puede tardar bastante tiempo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_12->setWhatsThis(QApplication::translate("Kernel", "Compila el nucleo configurado. Puede tardar bastante tiempo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_12->setText(QApplication::translate("Kernel", "Compilar nucleo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QApplication::translate("Kernel", "Ayuda de como localizar la ruta del modulo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_10->setStatusTip(QApplication::translate("Kernel", "Ayuda de como localizar la ruta del modulo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_10->setWhatsThis(QApplication::translate("Kernel", "Ayuda de como localizar la ruta del modulo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_10->setText(QString());
        label_9->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("Kernel", "Direccion del nucleo enlazado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_8->setStatusTip(QApplication::translate("Kernel", "Direccion del nucleo enlazado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_8->setWhatsThis(QApplication::translate("Kernel", "Direccion del nucleo enlazado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_8->setText(QApplication::translate("Kernel", "Enlace del nucleo: /usr/src/linux ->", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_11->setToolTip(QApplication::translate("Kernel", "Cancela el proceso en ejecucion. Procede con precaucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_11->setStatusTip(QApplication::translate("Kernel", "Cancela el proceso en ejecucion. Procede con precaucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_11->setWhatsThis(QApplication::translate("Kernel", "Cancela el proceso en ejecucion. Procede con precaucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_11->setText(QApplication::translate("Kernel", "Cancelar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Kernel: public Ui_Kernel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KERNEL_H
