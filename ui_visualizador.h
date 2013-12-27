/********************************************************************************
** Form generated from reading UI file 'visualizador.ui'
**
** Created: Sun Apr 24 03:32:17 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALIZADOR_H
#define UI_VISUALIZADOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Visualizador
{
public:
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QDialog *Visualizador)
    {
        if (Visualizador->objectName().isEmpty())
            Visualizador->setObjectName(QString::fromUtf8("Visualizador"));
        Visualizador->resize(400, 438);
        tableView = new QTableView(Visualizador);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(5, 11, 391, 391));
        pushButton = new QPushButton(Visualizador);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 410, 81, 23));

        retranslateUi(Visualizador);

        QMetaObject::connectSlotsByName(Visualizador);
    } // setupUi

    void retranslateUi(QDialog *Visualizador)
    {
        Visualizador->setWindowTitle(QApplication::translate("Visualizador", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Visualizador", "Cerrar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Visualizador: public Ui_Visualizador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZADOR_H
