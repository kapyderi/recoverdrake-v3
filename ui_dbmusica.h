/********************************************************************************
** Form generated from reading UI file 'dbmusica.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBMUSICA_H
#define UI_DBMUSICA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_dbmusica
{
public:

    void setupUi(QDialog *dbmusica)
    {
        if (dbmusica->objectName().isEmpty())
            dbmusica->setObjectName(QString::fromUtf8("dbmusica"));
        dbmusica->resize(400, 300);
        QFont font;
        font.setPointSize(7);
        dbmusica->setFont(font);

        retranslateUi(dbmusica);

        QMetaObject::connectSlotsByName(dbmusica);
    } // setupUi

    void retranslateUi(QDialog *dbmusica)
    {
        dbmusica->setWindowTitle(QApplication::translate("dbmusica", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dbmusica: public Ui_dbmusica {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBMUSICA_H
