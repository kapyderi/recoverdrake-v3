/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        Dialog->setMinimumSize(QSize(400, 300));
        Dialog->setMaximumSize(QSize(400, 300));
        QFont font;
        font.setPointSize(7);
        Dialog->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/64px-Dolphin-icon.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nimbus Sans L"));
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 4);

        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nimbus Sans L"));
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_3->setFont(font2);
        pushButton_3->setLayoutDirection(Qt::RightToLeft);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/derecha.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_3, 2, 3, 1, 1);

        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Nimbus Sans L"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Nimbus Sans L\";\n"
"font: Bold;"));
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setTextFormat(Qt::RichText);
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(true);

        gridLayout->addWidget(label_2, 1, 0, 1, 4);

        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/izquierda.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_2, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Sugerencias del dia", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Nimbus Sans L'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/Imagenes/help.png\" /> <span style=\" font-family:'Sans Serif'; font-size:16pt; font-weight:600; font-style:italic;\">Sabias que...</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Dialog", "Siguiente", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Dialog", "Cerrar", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        pushButton_2->setText(QApplication::translate("Dialog", "  Anterior", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
