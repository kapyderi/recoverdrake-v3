/********************************************************************************
** Form generated from reading UI file 'subtitulos.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBTITULOS_H
#define UI_SUBTITULOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Subtitulos
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QTextEdit *textEdit;

    void setupUi(QDialog *Subtitulos)
    {
        if (Subtitulos->objectName().isEmpty())
            Subtitulos->setObjectName(QString::fromUtf8("Subtitulos"));
        Subtitulos->resize(621, 379);
        Subtitulos->setMaximumSize(QSize(621, 379));
        QFont font;
        font.setPointSize(7);
        Subtitulos->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/icono.png"), QSize(), QIcon::Normal, QIcon::Off);
        Subtitulos->setWindowIcon(icon);
        Subtitulos->setSizeGripEnabled(true);
        lineEdit = new QLineEdit(Subtitulos);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 551, 21));
        pushButton = new QPushButton(Subtitulos);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(570, 30, 41, 21));
        label = new QLabel(Subtitulos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 161, 16));
        pushButton_2 = new QPushButton(Subtitulos);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(570, 90, 41, 21));
        label_2 = new QLabel(Subtitulos);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 161, 16));
        lineEdit_2 = new QLineEdit(Subtitulos);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 90, 551, 21));
        pushButton_3 = new QPushButton(Subtitulos);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(570, 150, 41, 21));
        label_3 = new QLabel(Subtitulos);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 130, 161, 16));
        lineEdit_3 = new QLineEdit(Subtitulos);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 150, 551, 21));
        pushButton_4 = new QPushButton(Subtitulos);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 340, 91, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(25, 25));
        pushButton_5 = new QPushButton(Subtitulos);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(530, 340, 75, 25));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon2);
        pushButton_5->setIconSize(QSize(25, 25));
        textEdit = new QTextEdit(Subtitulos);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 190, 601, 141));

        retranslateUi(Subtitulos);

        QMetaObject::connectSlotsByName(Subtitulos);
    } // setupUi

    void retranslateUi(QDialog *Subtitulos)
    {
        Subtitulos->setWindowTitle(QApplication::translate("Subtitulos", "Insertar Subtitulos", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Subtitulos", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Subtitulos", "Fichero de Video Origen:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Subtitulos", "...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Subtitulos", "Fichero de Subtitulos:", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Subtitulos", "...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Subtitulos", "Fichero de Video Destino:", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Subtitulos", "Comenzar", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Subtitulos", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Subtitulos: public Ui_Subtitulos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBTITULOS_H
