/********************************************************************************
** Form generated from reading UI file 'calculadora.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULADORA_H
#define UI_CALCULADORA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Calculadora
{
public:
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_21;
    QPushButton *pushButton_26;
    QSpacerItem *horizontalSpacer_22;
    QPushButton *pushButton_18;
    QPushButton *pushButton_20;
    QPushButton *pushButton_27;
    QSpacerItem *horizontalSpacer_21;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *pushButton_23;
    QPushButton *pushButton_15;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *pushButton_29;
    QPushButton *pushButton_16;
    QPushButton *pushButton_13;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pushButton_14;
    QPushButton *pushButton_17;
    QSpacerItem *horizontalSpacer_20;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_11;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_4;
    QFrame *line_2;
    QPushButton *pushButton_25;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_19;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *lineEdit_2;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton;
    QPushButton *pushButton_32;
    QPushButton *pushButton_33;
    QPushButton *pushButton_31;
    QPushButton *pushButton_28;
    QFrame *line;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_22;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_24;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_18;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_5;
    QSlider *horizontalSlider;
    QLabel *label;
    QSlider *horizontalSlider_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QFrame *line_3;
    QPushButton *pushButton_30;
    QPushButton *pushButton_34;
    QTextEdit *textEdit;
    QFrame *line_4;

    void setupUi(QDialog *Calculadora)
    {
        if (Calculadora->objectName().isEmpty())
            Calculadora->setObjectName(QString::fromUtf8("Calculadora"));
        Calculadora->resize(1060, 482);
        Calculadora->setMaximumSize(QSize(1060, 482));
        Calculadora->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/calculadora.png"), QSize(), QIcon::Normal, QIcon::Off);
        Calculadora->setWindowIcon(icon);
        gridLayout_7 = new QGridLayout(Calculadora);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_12, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        pushButton_21 = new QPushButton(Calculadora);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setMinimumSize(QSize(50, 50));
        pushButton_21->setMaximumSize(QSize(50, 50));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        pushButton_21->setFont(font);

        gridLayout_4->addWidget(pushButton_21, 0, 6, 1, 1);

        pushButton_26 = new QPushButton(Calculadora);
        pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));
        pushButton_26->setMinimumSize(QSize(220, 50));
        pushButton_26->setMaximumSize(QSize(220, 50));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_26->setFont(font1);
        pushButton_26->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout_4->addWidget(pushButton_26, 0, 8, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_22, 0, 7, 1, 1);

        pushButton_18 = new QPushButton(Calculadora);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setMinimumSize(QSize(50, 50));
        pushButton_18->setMaximumSize(QSize(50, 50));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        pushButton_18->setFont(font2);
        pushButton_18->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));

        gridLayout_4->addWidget(pushButton_18, 0, 0, 1, 1);

        pushButton_20 = new QPushButton(Calculadora);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setMinimumSize(QSize(50, 50));
        pushButton_20->setMaximumSize(QSize(50, 50));
        pushButton_20->setFont(font);

        gridLayout_4->addWidget(pushButton_20, 0, 2, 1, 1);

        pushButton_27 = new QPushButton(Calculadora);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));
        pushButton_27->setMinimumSize(QSize(50, 50));
        pushButton_27->setMaximumSize(QSize(50, 50));
        pushButton_27->setFont(font);

        gridLayout_4->addWidget(pushButton_27, 0, 4, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_21, 0, 5, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 7, 0, 1, 3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_11, 0, 3, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_19, 0, 9, 1, 1);

        pushButton_23 = new QPushButton(Calculadora);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        pushButton_23->setMinimumSize(QSize(50, 50));
        pushButton_23->setMaximumSize(QSize(50, 50));
        pushButton_23->setFont(font1);
        pushButton_23->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout_3->addWidget(pushButton_23, 0, 10, 1, 1);

        pushButton_15 = new QPushButton(Calculadora);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(50, 50));
        pushButton_15->setMaximumSize(QSize(50, 50));
        pushButton_15->setFont(font);

        gridLayout_3->addWidget(pushButton_15, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_16, 0, 7, 1, 1);

        pushButton_29 = new QPushButton(Calculadora);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));
        pushButton_29->setMinimumSize(QSize(50, 50));
        pushButton_29->setMaximumSize(QSize(50, 50));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_29->setFont(font3);
        pushButton_29->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_3->addWidget(pushButton_29, 0, 12, 1, 1);

        pushButton_16 = new QPushButton(Calculadora);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setMinimumSize(QSize(50, 50));
        pushButton_16->setMaximumSize(QSize(50, 50));
        pushButton_16->setFont(font);

        gridLayout_3->addWidget(pushButton_16, 0, 6, 1, 1);

        pushButton_13 = new QPushButton(Calculadora);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(50, 50));
        pushButton_13->setMaximumSize(QSize(50, 50));
        pushButton_13->setFont(font2);
        pushButton_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));

        gridLayout_3->addWidget(pushButton_13, 0, 0, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_15, 0, 5, 1, 1);

        pushButton_14 = new QPushButton(Calculadora);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(50, 50));
        pushButton_14->setMaximumSize(QSize(50, 50));
        pushButton_14->setFont(font);

        gridLayout_3->addWidget(pushButton_14, 0, 2, 1, 1);

        pushButton_17 = new QPushButton(Calculadora);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setMinimumSize(QSize(50, 50));
        pushButton_17->setMaximumSize(QSize(50, 50));
        pushButton_17->setFont(font1);
        pushButton_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout_3->addWidget(pushButton_17, 0, 8, 1, 1);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_20, 0, 11, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 6, 0, 1, 3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        pushButton_11 = new QPushButton(Calculadora);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(50, 50));
        pushButton_11->setMaximumSize(QSize(50, 50));
        pushButton_11->setFont(font1);
        pushButton_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout->addWidget(pushButton_11, 1, 8, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 5, 1, 1);

        pushButton_4 = new QPushButton(Calculadora);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(50, 50));
        pushButton_4->setMaximumSize(QSize(50, 50));
        pushButton_4->setFont(font);
        pushButton_4->setAutoExclusive(false);
        pushButton_4->setAutoDefault(true);
        pushButton_4->setDefault(false);
        pushButton_4->setFlat(false);

        gridLayout->addWidget(pushButton_4, 1, 2, 1, 1);

        line_2 = new QFrame(Calculadora);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 0, 1, 13);

        pushButton_25 = new QPushButton(Calculadora);
        pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));
        pushButton_25->setMinimumSize(QSize(50, 50));
        pushButton_25->setMaximumSize(QSize(50, 50));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        pushButton_25->setFont(font4);
        pushButton_25->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(pushButton_25, 1, 12, 1, 1);

        pushButton_6 = new QPushButton(Calculadora);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(50, 50));
        pushButton_6->setMaximumSize(QSize(50, 50));
        pushButton_6->setFont(font);

        gridLayout->addWidget(pushButton_6, 1, 6, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 3, 1, 1);

        pushButton_3 = new QPushButton(Calculadora);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setMaximumSize(QSize(50, 50));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(Calculadora);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(50, 50));
        pushButton_5->setMaximumSize(QSize(50, 50));
        pushButton_5->setFont(font);

        gridLayout->addWidget(pushButton_5, 1, 4, 1, 1);

        pushButton_19 = new QPushButton(Calculadora);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setMinimumSize(QSize(50, 50));
        pushButton_19->setMaximumSize(QSize(50, 50));
        pushButton_19->setFont(font4);
        pushButton_19->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(pushButton_19, 1, 10, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 1, 11, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 1, 7, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 1, 9, 1, 1);


        gridLayout_7->addLayout(gridLayout, 4, 0, 1, 3);

        lineEdit_2 = new QLineEdit(Calculadora);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QFont font5;
        font5.setPointSize(14);
        lineEdit_2->setFont(font5);
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_2->setReadOnly(true);

        gridLayout_7->addWidget(lineEdit_2, 1, 0, 1, 3);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButton = new QPushButton(Calculadora);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(85, 45));
        pushButton->setMaximumSize(QSize(85, 45));
        QFont font6;
        font6.setBold(false);
        font6.setWeight(50);
        pushButton->setFont(font6);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/izquierda.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout_6->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_32 = new QPushButton(Calculadora);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));
        pushButton_32->setMinimumSize(QSize(100, 45));
        pushButton_32->setMaximumSize(QSize(100, 45));
        pushButton_32->setFont(font3);
        pushButton_32->setIconSize(QSize(25, 25));
        pushButton_32->setCheckable(true);

        gridLayout_6->addWidget(pushButton_32, 1, 2, 1, 1);

        pushButton_33 = new QPushButton(Calculadora);
        pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));
        pushButton_33->setMinimumSize(QSize(100, 45));
        pushButton_33->setMaximumSize(QSize(115, 45));
        pushButton_33->setFont(font3);
        pushButton_33->setLayoutDirection(Qt::LeftToRight);
        pushButton_33->setIconSize(QSize(25, 25));
        pushButton_33->setCheckable(true);

        gridLayout_6->addWidget(pushButton_33, 1, 3, 1, 1);

        pushButton_31 = new QPushButton(Calculadora);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));
        pushButton_31->setMinimumSize(QSize(130, 45));
        pushButton_31->setMaximumSize(QSize(130, 45));
        pushButton_31->setFont(font6);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/boli.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_31->setIcon(icon2);
        pushButton_31->setIconSize(QSize(25, 25));

        gridLayout_6->addWidget(pushButton_31, 1, 4, 1, 1);

        pushButton_28 = new QPushButton(Calculadora);
        pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));
        pushButton_28->setMinimumSize(QSize(90, 45));
        pushButton_28->setMaximumSize(QSize(90, 45));
        pushButton_28->setFont(font6);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_28->setIcon(icon3);
        pushButton_28->setIconSize(QSize(25, 25));

        gridLayout_6->addWidget(pushButton_28, 1, 5, 1, 2);

        line = new QFrame(Calculadora);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line, 0, 0, 1, 7);


        gridLayout_7->addLayout(gridLayout_6, 3, 0, 1, 3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_14, 0, 7, 1, 1);

        pushButton_22 = new QPushButton(Calculadora);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        pushButton_22->setMinimumSize(QSize(50, 50));
        pushButton_22->setMaximumSize(QSize(50, 50));
        pushButton_22->setFont(font4);
        pushButton_22->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(pushButton_22, 0, 12, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 0, 3, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_17, 0, 9, 1, 1);

        pushButton_7 = new QPushButton(Calculadora);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(50, 50));
        pushButton_7->setMaximumSize(QSize(50, 50));
        pushButton_7->setFont(font2);
        pushButton_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));

        gridLayout_2->addWidget(pushButton_7, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        pushButton_9 = new QPushButton(Calculadora);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(50, 50));
        pushButton_9->setMaximumSize(QSize(50, 50));
        pushButton_9->setFont(font);

        gridLayout_2->addWidget(pushButton_9, 0, 4, 1, 1);

        pushButton_8 = new QPushButton(Calculadora);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(50, 50));
        pushButton_8->setMaximumSize(QSize(50, 50));
        pushButton_8->setFont(font);

        gridLayout_2->addWidget(pushButton_8, 0, 2, 1, 1);

        pushButton_24 = new QPushButton(Calculadora);
        pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));
        pushButton_24->setMinimumSize(QSize(50, 50));
        pushButton_24->setMaximumSize(QSize(50, 50));
        pushButton_24->setFont(font4);
        pushButton_24->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_2->addWidget(pushButton_24, 0, 10, 1, 1);

        pushButton_10 = new QPushButton(Calculadora);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(50, 50));
        pushButton_10->setMaximumSize(QSize(50, 50));
        pushButton_10->setFont(font);

        gridLayout_2->addWidget(pushButton_10, 0, 6, 1, 1);

        pushButton_12 = new QPushButton(Calculadora);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(50, 50));
        pushButton_12->setMaximumSize(QSize(50, 50));
        pushButton_12->setFont(font1);
        pushButton_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout_2->addWidget(pushButton_12, 0, 8, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_13, 0, 5, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_18, 0, 11, 1, 1);


        gridLayout_7->addLayout(gridLayout_2, 5, 0, 1, 3);

        lineEdit = new QLineEdit(Calculadora);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font1);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);

        gridLayout_7->addWidget(lineEdit, 0, 0, 1, 3);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalSlider = new QSlider(Calculadora);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(30);
        horizontalSlider->setPageStep(5);
        horizontalSlider->setValue(12);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::TicksBothSides);
        horizontalSlider->setTickInterval(1);

        gridLayout_5->addWidget(horizontalSlider, 2, 3, 1, 1);

        label = new QLabel(Calculadora);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font7;
        font7.setPointSize(7);
        label->setFont(font7);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 3, 3, 2, 1);

        horizontalSlider_2 = new QSlider(Calculadora);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(20);
        horizontalSlider_2->setPageStep(5);
        horizontalSlider_2->setValue(3);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBothSides);

        gridLayout_5->addWidget(horizontalSlider_2, 2, 4, 1, 1);

        label_2 = new QLabel(Calculadora);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font7);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_2, 3, 4, 2, 1);

        pushButton_2 = new QPushButton(Calculadora);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(90, 35));
        pushButton_2->setMaximumSize(QSize(90, 35));
        pushButton_2->setFont(font6);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/escoba.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_2, 2, 1, 3, 1);

        line_3 = new QFrame(Calculadora);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_3, 0, 1, 1, 4);

        pushButton_30 = new QPushButton(Calculadora);
        pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));
        pushButton_30->setMinimumSize(QSize(90, 35));
        pushButton_30->setMaximumSize(QSize(90, 35));
        pushButton_30->setFont(font6);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/borrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_30->setIcon(icon5);
        pushButton_30->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_30, 2, 2, 3, 1);

        pushButton_34 = new QPushButton(Calculadora);
        pushButton_34->setObjectName(QString::fromUtf8("pushButton_34"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/sustituir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_34->setIcon(icon6);
        pushButton_34->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_34, 2, 5, 1, 1);


        gridLayout_7->addLayout(gridLayout_5, 2, 0, 1, 3);

        textEdit = new QTextEdit(Calculadora);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMinimumSize(QSize(490, 0));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"font: 14pt \"Beta Dance\";\n"
"color: rgb(255, 255, 0);\n"
"font: bold;\n"
""));

        gridLayout_7->addWidget(textEdit, 0, 4, 8, 1);

        line_4 = new QFrame(Calculadora);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_4, 0, 3, 8, 1);


        retranslateUi(Calculadora);

        QMetaObject::connectSlotsByName(Calculadora);
    } // setupUi

    void retranslateUi(QDialog *Calculadora)
    {
        Calculadora->setWindowTitle(QApplication::translate("Calculadora", "Calculadora v.0.10.0", 0, QApplication::UnicodeUTF8));
        pushButton_21->setText(QApplication::translate("Calculadora", ".", 0, QApplication::UnicodeUTF8));
        pushButton_26->setText(QApplication::translate("Calculadora", "=", 0, QApplication::UnicodeUTF8));
        pushButton_18->setText(QApplication::translate("Calculadora", "M-", 0, QApplication::UnicodeUTF8));
        pushButton_20->setText(QApplication::translate("Calculadora", "0", 0, QApplication::UnicodeUTF8));
        pushButton_27->setText(QApplication::translate("Calculadora", "00", 0, QApplication::UnicodeUTF8));
        pushButton_23->setText(QApplication::translate("Calculadora", "+", 0, QApplication::UnicodeUTF8));
        pushButton_15->setText(QApplication::translate("Calculadora", "2", 0, QApplication::UnicodeUTF8));
        pushButton_29->setText(QApplication::translate("Calculadora", "%", 0, QApplication::UnicodeUTF8));
        pushButton_16->setText(QApplication::translate("Calculadora", "3", 0, QApplication::UnicodeUTF8));
        pushButton_13->setText(QApplication::translate("Calculadora", "M+", 0, QApplication::UnicodeUTF8));
        pushButton_14->setText(QApplication::translate("Calculadora", "1", 0, QApplication::UnicodeUTF8));
        pushButton_17->setText(QApplication::translate("Calculadora", "-", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("Calculadora", "\303\267", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Calculadora", "7", 0, QApplication::UnicodeUTF8));
        pushButton_25->setText(QApplication::translate("Calculadora", "1/x", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Calculadora", "9", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Calculadora", "MR", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Calculadora", "8", 0, QApplication::UnicodeUTF8));
        pushButton_19->setText(QApplication::translate("Calculadora", "\342\210\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Calculadora", "Atras", 0, QApplication::UnicodeUTF8));
        pushButton_32->setText(QApplication::translate("Calculadora", "EUR - > PTS", 0, QApplication::UnicodeUTF8));
        pushButton_33->setText(QApplication::translate("Calculadora", "PTS - > EUR", 0, QApplication::UnicodeUTF8));
        pushButton_31->setText(QApplication::translate("Calculadora", "Copiar resultado", 0, QApplication::UnicodeUTF8));
        pushButton_28->setText(QApplication::translate("Calculadora", "Salir", 0, QApplication::UnicodeUTF8));
        pushButton_22->setText(QApplication::translate("Calculadora", "\302\261", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Calculadora", "MC", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("Calculadora", "5", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Calculadora", "4", 0, QApplication::UnicodeUTF8));
        pushButton_24->setText(QApplication::translate("Calculadora", "x\302\262", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("Calculadora", "6", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("Calculadora", "x", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Calculadora", "Numero maximo de digitos: ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Calculadora", "Numero total de decimales: ", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Calculadora", "Limpiar", 0, QApplication::UnicodeUTF8));
        pushButton_30->setText(QApplication::translate("Calculadora", "Borrar", 0, QApplication::UnicodeUTF8));
        pushButton_34->setText(QString());
        textEdit->setHtml(QApplication::translate("Calculadora", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Beta Dance'; font-size:14pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans Serif'; font-size:10pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Calculadora: public Ui_Calculadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULADORA_H
