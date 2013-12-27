/********************************************************************************
** Form generated from reading UI file 'vnc.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VNC_H
#define UI_VNC_H

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
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_vnc
{
public:
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_11;
    QLabel *label_3;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *label_11;
    QLabel *label_4;
    QGridLayout *gridLayout_10;
    QLineEdit *lineEdit_2;
    QLabel *label_12;
    QCheckBox *checkBox_6;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_16;
    QLabel *label_10;
    QPushButton *pushButton_7;
    QGridLayout *gridLayout_6;
    QLabel *label_13;
    QPushButton *pushButton_6;
    QCheckBox *checkBox_7;
    QGridLayout *gridLayout_14;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_14;
    QGridLayout *gridLayout_13;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QGridLayout *gridLayout_12;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QGridLayout *gridLayout_15;
    QLabel *label_15;
    QLineEdit *lineEdit_8;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_2;
    QGridLayout *gridLayout_8;
    QLabel *label_9;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QPushButton *pushButton_5;
    QLabel *label;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QTableView *tableView;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;

    void setupUi(QDialog *vnc)
    {
        if (vnc->objectName().isEmpty())
            vnc->setObjectName(QString::fromUtf8("vnc"));
        vnc->resize(743, 544);
        QFont font;
        font.setPointSize(7);
        vnc->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/vnc.png"), QSize(), QIcon::Normal, QIcon::Off);
        vnc->setWindowIcon(icon);
        vnc->setStyleSheet(QString::fromUtf8(""));
        gridLayout_9 = new QGridLayout(vnc);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_2 = new QGroupBox(vnc);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sans Serif"));
        font1.setPointSize(7);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        groupBox_2->setFont(font1);
        gridLayout_11 = new QGridLayout(groupBox_2);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(false);
        font2.setWeight(50);
        label_3->setFont(font2);

        gridLayout_11->addWidget(label_3, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(30, 25));
        label_11->setMaximumSize(QSize(30, 25));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/good.png")));
        label_11->setScaledContents(true);

        gridLayout->addWidget(label_11, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Sans Serif"));
        font3.setPointSize(7);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_4->setFont(font3);

        gridLayout_11->addWidget(label_4, 2, 0, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEchoMode(QLineEdit::Password);

        gridLayout_10->addWidget(lineEdit_2, 0, 0, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(30, 25));
        label_12->setMaximumSize(QSize(30, 25));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/good.png")));
        label_12->setScaledContents(true);

        gridLayout_10->addWidget(label_12, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 3, 0, 1, 1);

        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setFont(font2);

        gridLayout_11->addWidget(checkBox_6, 4, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(vnc);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy);
        groupBox_5->setFont(font3);
        gridLayout_16 = new QGridLayout(groupBox_5);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font: 6pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_16->addWidget(label_10, 1, 0, 1, 1);

        pushButton_7 = new QPushButton(groupBox_5);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setFont(font2);

        gridLayout_16->addWidget(pushButton_7, 1, 1, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(30, 25));
        label_13->setMaximumSize(QSize(30, 25));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/good.png")));
        label_13->setScaledContents(true);

        gridLayout_6->addWidget(label_13, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox_5);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/nucleo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon1);
        pushButton_6->setIconSize(QSize(20, 20));

        gridLayout_6->addWidget(pushButton_6, 0, 1, 1, 1);

        checkBox_7 = new QCheckBox(groupBox_5);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setFont(font);

        gridLayout_6->addWidget(checkBox_7, 0, 2, 1, 1);


        gridLayout_16->addLayout(gridLayout_6, 4, 0, 1, 2);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_14->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox_5);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_14->addWidget(lineEdit_4, 0, 1, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_14->addWidget(label_14, 0, 2, 1, 1);


        gridLayout_16->addLayout(gridLayout_14, 0, 0, 1, 2);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_13->addWidget(label_7, 0, 0, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox_5);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout_13->addWidget(lineEdit_5, 0, 1, 1, 1);


        gridLayout_16->addLayout(gridLayout_13, 2, 0, 1, 2);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_12->addWidget(label_8, 0, 0, 1, 1);

        lineEdit_6 = new QLineEdit(groupBox_5);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setEchoMode(QLineEdit::Password);

        gridLayout_12->addWidget(lineEdit_6, 0, 1, 1, 1);


        gridLayout_16->addLayout(gridLayout_12, 3, 0, 1, 2);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_15->addWidget(label_15, 0, 0, 1, 1);

        lineEdit_8 = new QLineEdit(groupBox_5);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        gridLayout_15->addWidget(lineEdit_8, 0, 1, 1, 1);


        gridLayout_16->addLayout(gridLayout_15, 5, 0, 1, 2);


        gridLayout_5->addWidget(groupBox_5, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_5, 3, 0, 1, 6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_3, 7, 4, 1, 1);

        groupBox = new QGroupBox(vnc);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font);
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Sans Serif"));
        font4.setPointSize(7);
        font4.setItalic(false);
        radioButton->setFont(font4);

        gridLayout_4->addWidget(radioButton, 0, 0, 1, 2);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_4->addWidget(radioButton_2, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 6pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(70, 16777215));
        label_9->setFont(font3);

        gridLayout_8->addWidget(label_9, 0, 0, 1, 1);

        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setStyleSheet(QString::fromUtf8("font: 75 10pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout_8->addWidget(lineEdit_7, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_8, 1, 2, 1, 1);


        gridLayout_9->addWidget(groupBox, 1, 0, 1, 6);

        pushButton_2 = new QPushButton(vnc);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(80, 33));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(20, 20));

        gridLayout_9->addWidget(pushButton_2, 7, 5, 1, 1);

        pushButton = new QPushButton(vnc);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(89, 33));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon3);

        gridLayout_9->addWidget(pushButton, 7, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(297, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer, 7, 1, 1, 1);

        label_5 = new QLabel(vnc);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 6pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_9->addWidget(label_5, 6, 0, 1, 2);

        pushButton_5 = new QPushButton(vnc);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/sustituir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon4);
        pushButton_5->setIconSize(QSize(24, 24));

        gridLayout_9->addWidget(pushButton_5, 7, 0, 1, 1);

        label = new QLabel(vnc);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"Sans Serif\";\n"
"font: bold;"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label, 0, 0, 1, 6);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_4 = new QGroupBox(vnc);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        groupBox_4->setFont(font1);
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(groupBox_4);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setAlternatingRowColors(true);

        gridLayout_3->addWidget(tableView, 0, 0, 1, 3);

        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(84, 26));
        pushButton_3->setFont(font2);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/thumbs_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon5);

        gridLayout_3->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(85, 26));
        pushButton_4->setFont(font2);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon6);

        gridLayout_3->addWidget(pushButton_4, 2, 2, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox_4);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_3->addWidget(lineEdit_3, 1, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_4, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(vnc);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMaximumSize(QSize(360, 16777215));
        groupBox_3->setFont(font3);
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_2->addWidget(checkBox, 0, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_2->addWidget(checkBox_2, 1, 0, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_2->addWidget(checkBox_3, 2, 0, 1, 1);

        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_2->addWidget(checkBox_4, 3, 0, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_3);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_2->addWidget(checkBox_5, 4, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_3, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 4, 0, 1, 6);


        retranslateUi(vnc);

        QMetaObject::connectSlotsByName(vnc);
    } // setupUi

    void retranslateUi(QDialog *vnc)
    {
        vnc->setWindowTitle(QApplication::translate("vnc", "Configurar VNC", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("vnc", "Password para acceder con conexion remota", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("vnc", "Introducir password:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        label_4->setText(QApplication::translate("vnc", "Confirmar password:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QString());
        checkBox_6->setText(QApplication::translate("vnc", "Visualizar password", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("vnc", "Datos de e-mail para envio de ip", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("vnc", "*Tiene que ser una cuenta de gmail", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("vnc", "Crear cuenta", 0, QApplication::UnicodeUTF8));
        label_13->setText(QString());
        pushButton_6->setText(QApplication::translate("vnc", "Configurar", 0, QApplication::UnicodeUTF8));
        checkBox_7->setText(QApplication::translate("vnc", "Visualizar clave", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("vnc", "e-mail", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        lineEdit_4->setWhatsThis(QApplication::translate("vnc", "Si activas esta opcion tendras que abrir los puertos de tu router desde 5900 al 5910 minimo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_14->setText(QApplication::translate("vnc", "@gmail.com", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("vnc", "smtp", 0, QApplication::UnicodeUTF8));
        lineEdit_5->setText(QApplication::translate("vnc", "smtp.gmail.com", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("vnc", "Clave", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("vnc", "e-mail receptor", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("vnc", "Tipo de IP publica para servidor", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("vnc", "IP fija (Estatica) [Por defecto]", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        radioButton_2->setWhatsThis(QApplication::translate("vnc", "Si activas esta opcion tendras que abrir los puertos de tu router desde 5900 al 5910 minimo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_2->setText(QApplication::translate("vnc", "IP variable (Dinamica)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("vnc", "* Si no sabes que contestar te aconsejo que selecciones IP variable (Dinamica)", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("vnc", "IP publica", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("vnc", "Salir", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("vnc", "Guardar", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("vnc", "* Si se marca \"Limitar acceso a lista de ip's\" no podras acceder con ip remota dinamica.", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("vnc", "Por Defecto", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("vnc", "Datos de configuracion del servidor VNC", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("vnc", "Lista de ip's aceptadas", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("vnc", "Insertar", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("vnc", "Eliminar", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("vnc", "Opciones de configuracion", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("vnc", "Servidor en segundo plano", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("vnc", "Iniciar menu grafico", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("vnc", "Siempre escuchando peticiones", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("vnc", "Solo se puede visualizar", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("vnc", "Limitar acceso a lista de ip's", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class vnc: public Ui_vnc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VNC_H
