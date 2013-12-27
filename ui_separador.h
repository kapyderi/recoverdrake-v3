/********************************************************************************
** Form generated from reading UI file 'separador.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEPARADOR_H
#define UI_SEPARADOR_H

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

QT_BEGIN_NAMESPACE

class Ui_Separador
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QLineEdit *lineEdit_5;
    QRadioButton *radioButton_3;
    QCheckBox *checkBox;

    void setupUi(QDialog *Separador)
    {
        if (Separador->objectName().isEmpty())
            Separador->setObjectName(QString::fromUtf8("Separador"));
        Separador->resize(621, 213);
        QFont font;
        font.setPointSize(7);
        Separador->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        Separador->setWindowIcon(icon);
        gridLayout = new QGridLayout(Separador);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(251, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton = new QPushButton(Separador);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(251, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        groupBox = new QGroupBox(Separador);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(603, 162));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(110, 16777215));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_3->addWidget(lineEdit_3, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_2->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_2->addWidget(radioButton_2, 0, 1, 1, 1);

        radioButton_6 = new QRadioButton(groupBox_2);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));

        gridLayout_2->addWidget(radioButton_6, 2, 0, 1, 1);

        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout_2->addWidget(radioButton_4, 2, 1, 1, 1);

        radioButton_5 = new QRadioButton(groupBox_2);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

        gridLayout_2->addWidget(radioButton_5, 2, 2, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox_2);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMinimumSize(QSize(0, 20));

        gridLayout_2->addWidget(lineEdit_5, 2, 3, 1, 1);

        radioButton_3 = new QRadioButton(groupBox_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_2->addWidget(radioButton_3, 0, 2, 1, 1);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_2->addWidget(checkBox, 0, 3, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 3);


        retranslateUi(Separador);

        QMetaObject::connectSlotsByName(Separador);
    } // setupUi

    void retranslateUi(QDialog *Separador)
    {
        Separador->setWindowTitle(QApplication::translate("Separador", "Seleccion de delimitadores en ficheros .csv", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Separador", "Aceptar", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Separador", "Delimitadores", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Separador", "Linea de ejemplo:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Separador", "Delimitador de campos", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("Separador", "Coma (,)", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("Separador", "Punto (.)", 0, QApplication::UnicodeUTF8));
        radioButton_6->setText(QApplication::translate("Separador", "Dos puntos (:)", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("Separador", "Punto y coma (;)", 0, QApplication::UnicodeUTF8));
        radioButton_5->setText(QApplication::translate("Separador", "Otros", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("Separador", "Tabulador", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Separador", "Quitar entrecomillados al texto", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Separador: public Ui_Separador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEPARADOR_H
