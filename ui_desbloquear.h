/********************************************************************************
** Form generated from reading UI file 'desbloquear.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESBLOQUEAR_H
#define UI_DESBLOQUEAR_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Desbloquear
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Desbloquear)
    {
        if (Desbloquear->objectName().isEmpty())
            Desbloquear->setObjectName(QString::fromUtf8("Desbloquear"));
        Desbloquear->resize(400, 160);
        Desbloquear->setMaximumSize(QSize(400, 160));
        QFont font;
        font.setPointSize(7);
        Desbloquear->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/security-mdk.png"), QSize(), QIcon::Normal, QIcon::Off);
        Desbloquear->setWindowIcon(icon);
        Desbloquear->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Desbloquear);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(Desbloquear);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit->setFont(font1);
        lineEdit->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 3);

        label = new QLabel(Desbloquear);
        label->setObjectName(QString::fromUtf8("label"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(170, 170, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label->setPalette(palette);
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout->addWidget(label, 1, 0, 1, 3);

        pushButton = new QPushButton(Desbloquear);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(Desbloquear);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_2, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);


        retranslateUi(Desbloquear);

        QMetaObject::connectSlotsByName(Desbloquear);
    } // setupUi

    void retranslateUi(QDialog *Desbloquear)
    {
        Desbloquear->setWindowTitle(QApplication::translate("Desbloquear", "Introducir contrasena", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Desbloquear", "Contrasena", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Desbloquear", "*Introduzca la contrasena del usuario activo.", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Desbloquear", "Aceptar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Desbloquear", "Cancelar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Desbloquear: public Ui_Desbloquear {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESBLOQUEAR_H
