/********************************************************************************
** Form generated from reading UI file 'examen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMEN_H
#define UI_EXAMEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_examen
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_8;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QLabel *label_6;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_7;
    QPushButton *pushButton_7;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QLabel *label_2;
    QLabel *label_9;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_7;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_6;
    QLabel *label;
    QLabel *label_8;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QDialog *examen)
    {
        if (examen->objectName().isEmpty())
            examen->setObjectName(QString::fromUtf8("examen"));
        examen->resize(596, 594);
        QFont font;
        font.setPointSize(7);
        examen->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/libro.png"), QSize(), QIcon::Normal, QIcon::Off);
        examen->setWindowIcon(icon);
        examen->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(examen);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(examen);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 58));

        gridLayout_2->addWidget(textEdit, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 6);

        pushButton_6 = new QPushButton(examen);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setLayoutDirection(Qt::RightToLeft);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/derecha.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon1);
        pushButton_6->setIconSize(QSize(25, 25));
        pushButton_6->setAutoDefault(true);

        gridLayout->addWidget(pushButton_6, 10, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 10, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 10, 4, 1, 1);

        groupBox_7 = new QGroupBox(examen);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_8 = new QGridLayout(groupBox_7);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_4, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox_7);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font1;
        font1.setPointSize(10);
        label_5->setFont(font1);

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(201, 26));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Sans Serif\";\n"
"font: bold;"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);
        pushButton_4->setIconSize(QSize(30, 30));

        gridLayout_4->addWidget(pushButton_4, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 1, 1, 1);


        gridLayout_8->addWidget(groupBox_3, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_7);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(201, 26));
        pushButton_5->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Sans Serif\";\n"
"font: bold;"));
        pushButton_5->setIcon(icon2);
        pushButton_5->setIconSize(QSize(30, 30));

        gridLayout_5->addWidget(pushButton_5, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 0, 1, 1, 1);


        gridLayout_8->addWidget(groupBox_4, 4, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox_7);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(201, 26));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 75 14pt \"Sans Serif\";\n"
"font: bold;"));
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(30, 30));

        gridLayout_3->addWidget(pushButton_3, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 1, 1, 1);


        gridLayout_8->addWidget(groupBox_2, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_5, 3, 0, 1, 1);

        label_7 = new QLabel(groupBox_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold;\n"
"color: rgb(0, 0, 255);"));

        gridLayout_8->addWidget(label_7, 5, 0, 1, 1);


        gridLayout->addWidget(groupBox_7, 3, 0, 1, 6);

        pushButton_7 = new QPushButton(examen);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon3);
        pushButton_7->setIconSize(QSize(25, 25));
        pushButton_7->setAutoDefault(true);

        gridLayout->addWidget(pushButton_7, 10, 2, 1, 2);

        groupBox_5 = new QGroupBox(examen);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setAlignment(Qt::AlignCenter);
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(groupBox_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Sans Serif\";\n"
"font: bold;"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_2, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 12pt \"Sans Serif\";\n"
"font: bold;"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_9, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_5, 9, 2, 1, 2);

        groupBox_6 = new QGroupBox(examen);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_7 = new QGridLayout(groupBox_6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(groupBox_6);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_7->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_6);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_7->addWidget(radioButton_2, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_6, 1, 4, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 6);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 2, 4, 1, 1);

        label = new QLabel(examen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 18pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"font: bold;"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 9, 0, 1, 2);

        label_8 = new QLabel(examen);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 18pt \"Sans Serif\";\n"
"color: rgb(255, 0, 0);\n"
"font: bold;"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 9, 4, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 1);

        pushButton_2 = new QPushButton(examen);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_2, 10, 0, 1, 1);


        retranslateUi(examen);

        QMetaObject::connectSlotsByName(examen);
    } // setupUi

    void retranslateUi(QDialog *examen)
    {
        examen->setWindowTitle(QApplication::translate("examen", "Ejercicios practicos", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("examen", "Pregunta n\302\272", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("examen", "Siguiente", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("examen", "Selecciona la respuesta correcta", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("examen", "Respuesta B", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("examen", "Respuesta B", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("examen", "Respuesta B", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("examen", "Respuesta B", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("examen", "B", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("examen", "Respuesta C", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("examen", "Respuesta C", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("examen", "Respuesta C", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("examen", "Respuesta C", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QApplication::translate("examen", "C", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("examen", "Respuesta A", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("examen", "Respuesta A", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("examen", "Respuesta A", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("examen", "Respuesta A", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("examen", "A", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("examen", "*Piensalo antes de contestar... no hay vuelta atras.", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("examen", "Terminar", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("examen", "Puntuacion", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label_9->setText(QString());
        groupBox_6->setTitle(QApplication::translate("examen", "Tipo de Test", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("examen", "Test Normal", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("examen", "Test Aleatorio", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_8->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("examen", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("examen", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("examen", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("examen", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class examen: public Ui_examen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMEN_H
