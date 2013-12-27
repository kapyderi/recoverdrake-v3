/********************************************************************************
** Form generated from reading UI file 'pregunta.ui'
**
** Created: Wed Sep 12 21:01:52 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREGUNTA_H
#define UI_PREGUNTA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Pregunta
{
public:
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *Pregunta)
    {
        if (Pregunta->objectName().isEmpty())
            Pregunta->setObjectName(QString::fromUtf8("Pregunta"));
        Pregunta->resize(521, 212);
        tableView = new QTableView(Pregunta);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 30, 501, 131));
        tableView->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);
        pushButton = new QPushButton(Pregunta);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(420, 180, 83, 25));
        pushButton_2 = new QPushButton(Pregunta);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 180, 83, 25));
        label = new QLabel(Pregunta);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 251, 16));

        retranslateUi(Pregunta);

        QMetaObject::connectSlotsByName(Pregunta);
    } // setupUi

    void retranslateUi(QDialog *Pregunta)
    {
        Pregunta->setWindowTitle(QApplication::translate("Pregunta", "Pregunta", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Pregunta", "Continuar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Pregunta", "Marcar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Pregunta", "Se han encontrado varios registros con el mismo nombre, marca donde aplicar cambios", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Pregunta: public Ui_Pregunta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREGUNTA_H
