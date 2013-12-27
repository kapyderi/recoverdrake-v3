/********************************************************************************
** Form generated from reading UI file 'remoto.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTO_H
#define UI_REMOTO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_remoto
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *remoto)
    {
        if (remoto->objectName().isEmpty())
            remoto->setObjectName(QString::fromUtf8("remoto"));
        remoto->resize(472, 185);
        remoto->setMaximumSize(QSize(472, 234));
        QFont font;
        font.setPointSize(7);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        remoto->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/conexion.png"), QSize(), QIcon::Normal, QIcon::Off);
        remoto->setWindowIcon(icon);
        remoto->setStyleSheet(QString::fromUtf8("font: bold;"));
        gridLayout = new QGridLayout(remoto);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(remoto);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 18pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_2 = new QLabel(remoto);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(remoto);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit = new QLineEdit(remoto);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 2);

        label_4 = new QLabel(remoto);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 75 7pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout->addWidget(label_4, 2, 1, 1, 2);

        pushButton_3 = new QPushButton(remoto);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_3, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(remoto);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(22, 22));

        gridLayout->addWidget(pushButton_2, 3, 2, 1, 1);


        retranslateUi(remoto);

        QMetaObject::connectSlotsByName(remoto);
    } // setupUi

    void retranslateUi(QDialog *remoto)
    {
        remoto->setWindowTitle(QApplication::translate("remoto", "Conexion remota viewer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("remoto", "Conexion remota a VNC", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("remoto", "<html><head/><body><p align=\"center\"><img src=\":/Imagenes/conexion.png\" width=\"110\" height=\"85\"/></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("remoto", "IP del servidor (:port*):", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("remoto", "* Puerto opcional. Ejemplo (192.168.1.50:5900)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("remoto", "Conexion remota", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("remoto", "Conexion remota", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("remoto", "Conexion remota", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("remoto", "Conectar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("remoto", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("remoto", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("remoto", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("remoto", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class remoto: public Ui_remoto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTO_H
