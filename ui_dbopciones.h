/********************************************************************************
** Form generated from reading UI file 'dbopciones.ui'
**
** Created: Thu Jul 19 19:01:19 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBOPCIONES_H
#define UI_DBOPCIONES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_dbopciones
{
public:

    void setupUi(QDialog *dbopciones)
    {
        if (dbopciones->objectName().isEmpty())
            dbopciones->setObjectName(QString::fromUtf8("dbopciones"));
        dbopciones->resize(400, 300);

        retranslateUi(dbopciones);

        QMetaObject::connectSlotsByName(dbopciones);
    } // setupUi

    void retranslateUi(QDialog *dbopciones)
    {
        dbopciones->setWindowTitle(QApplication::translate("dbopciones", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dbopciones: public Ui_dbopciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBOPCIONES_H
