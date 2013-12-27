/********************************************************************************
** Form generated from reading UI file 'dblibros.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBLIBROS_H
#define UI_DBLIBROS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_dblibros
{
public:

    void setupUi(QDialog *dblibros)
    {
        if (dblibros->objectName().isEmpty())
            dblibros->setObjectName(QString::fromUtf8("dblibros"));
        dblibros->resize(669, 455);
        QFont font;
        font.setPointSize(7);
        dblibros->setFont(font);

        retranslateUi(dblibros);

        QMetaObject::connectSlotsByName(dblibros);
    } // setupUi

    void retranslateUi(QDialog *dblibros)
    {
        dblibros->setWindowTitle(QApplication::translate("dblibros", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dblibros: public Ui_dblibros {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBLIBROS_H
