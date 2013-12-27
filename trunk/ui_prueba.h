/********************************************************************************
** Form generated from reading UI file 'prueba.ui'
**
** Created: Sun Oct 7 05:53:28 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRUEBA_H
#define UI_PRUEBA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prueba
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *prueba)
    {
        if (prueba->objectName().isEmpty())
            prueba->setObjectName(QString::fromUtf8("prueba"));
        prueba->resize(400, 300);
        pushButton = new QPushButton(prueba);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 260, 73, 23));

        retranslateUi(prueba);

        QMetaObject::connectSlotsByName(prueba);
    } // setupUi

    void retranslateUi(QWidget *prueba)
    {
        prueba->setWindowTitle(QApplication::translate("prueba", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("prueba", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class prueba: public Ui_prueba {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRUEBA_H
