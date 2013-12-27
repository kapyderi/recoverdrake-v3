/********************************************************************************
** Form generated from reading UI file 'cierre.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIERRE_H
#define UI_CIERRE_H

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
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Cierre
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *label_13;
    QSpinBox *spinBox;
    QLabel *label_12;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_6;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QSpinBox *spinBox_4;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_5;
    QSpinBox *spinBox_5;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_15;

    void setupUi(QDialog *Cierre)
    {
        if (Cierre->objectName().isEmpty())
            Cierre->setObjectName(QString::fromUtf8("Cierre"));
        Cierre->resize(481, 147);
        Cierre->setMaximumSize(QSize(481, 147));
        QFont font;
        font.setPointSize(7);
        Cierre->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/Despertador.png"), QSize(), QIcon::Normal, QIcon::Off);
        Cierre->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(Cierre);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(Cierre);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 11pt \"Sans Serif\";\n"
"font: bold;"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 3);

        pushButton_2 = new QPushButton(Cierre);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_2, 3, 2, 1, 1);

        pushButton = new QPushButton(Cierre);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/thumbs_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton, 3, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(Cierre);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        label_11 = new QLabel(Cierre);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 1, 6, 1, 1);

        label_13 = new QLabel(Cierre);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_13, 1, 7, 1, 2);

        spinBox = new QSpinBox(Cierre);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(31);

        gridLayout->addWidget(spinBox, 2, 0, 1, 1);

        label_12 = new QLabel(Cierre);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 1, 9, 1, 2);

        label_4 = new QLabel(Cierre);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        spinBox_2 = new QSpinBox(Cierre);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setInputMethodHints(Qt::ImhExclusiveInputMask);
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(12);

        gridLayout->addWidget(spinBox_2, 2, 2, 1, 1);

        spinBox_3 = new QSpinBox(Cierre);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setMinimum(2012);
        spinBox_3->setMaximum(10000);

        gridLayout->addWidget(spinBox_3, 2, 4, 1, 1);

        spinBox_6 = new QSpinBox(Cierre);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setMinimum(0);
        spinBox_6->setMaximum(23);
        spinBox_6->setValue(0);

        gridLayout->addWidget(spinBox_6, 2, 6, 1, 1);

        label_9 = new QLabel(Cierre);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 2, 9, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 5, 1, 1);

        label_8 = new QLabel(Cierre);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 1, 4, 1, 1);

        spinBox_4 = new QSpinBox(Cierre);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setMinimum(0);
        spinBox_4->setMaximum(12);
        spinBox_4->setValue(0);

        gridLayout->addWidget(spinBox_4, 2, 8, 1, 1);

        label_7 = new QLabel(Cierre);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 3, 1, 1);

        label_10 = new QLabel(Cierre);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 7, 1, 1);

        label_5 = new QLabel(Cierre);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        spinBox_5 = new QSpinBox(Cierre);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setMinimum(0);
        spinBox_5->setMaximum(59);
        spinBox_5->setValue(0);

        gridLayout->addWidget(spinBox_5, 2, 10, 1, 1);

        label_3 = new QLabel(Cierre);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 6, 1, 5);

        label = new QLabel(Cierre);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 5);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 3);

        label_14 = new QLabel(Cierre);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("font: 12pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout_2->addWidget(label_14, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 1, 1, 1);

        label_15 = new QLabel(Cierre);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("font: 12pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout_2->addWidget(label_15, 2, 1, 1, 2);


        retranslateUi(Cierre);

        QMetaObject::connectSlotsByName(Cierre);
    } // setupUi

    void retranslateUi(QDialog *Cierre)
    {
        Cierre->setWindowTitle(QApplication::translate("Cierre", "Cierre programado", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Cierre", "Horario programado de apagado de equipo", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Cierre", "Cancelar", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Cierre", "Aceptar", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Cierre", "Mes", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Cierre", "Hora", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Cierre", "Minutos", 0, QApplication::UnicodeUTF8));
        spinBox->setSpecialValueText(QApplication::translate("Cierre", "01", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Cierre", "Segundos", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Cierre", "/", 0, QApplication::UnicodeUTF8));
        spinBox_2->setSpecialValueText(QApplication::translate("Cierre", "01", 0, QApplication::UnicodeUTF8));
        spinBox_6->setSpecialValueText(QApplication::translate("Cierre", "00", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Cierre", ":", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Cierre", "Ano", 0, QApplication::UnicodeUTF8));
        spinBox_4->setSpecialValueText(QApplication::translate("Cierre", "00", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Cierre", "/", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Cierre", ":", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Cierre", "D\303\255a", 0, QApplication::UnicodeUTF8));
        spinBox_5->setSpecialValueText(QApplication::translate("Cierre", "00", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Cierre", "Selecciona hora", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Cierre", "Selecciona fecha", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Cierre", "Hora local:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Cierre: public Ui_Cierre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIERRE_H
