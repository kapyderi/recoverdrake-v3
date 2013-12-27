/********************************************************************************
** Form generated from reading UI file 'montaje.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTAJE_H
#define UI_MONTAJE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Montaje
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_7;

    void setupUi(QDialog *Montaje)
    {
        if (Montaje->objectName().isEmpty())
            Montaje->setObjectName(QString::fromUtf8("Montaje"));
        Montaje->resize(626, 480);
        QFont font;
        font.setPointSize(7);
        Montaje->setFont(font);
        gridLayout = new QGridLayout(Montaje);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(Montaje);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 3);

        pushButton_8 = new QPushButton(Montaje);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon);

        gridLayout->addWidget(pushButton_8, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(457, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        pushButton_7 = new QPushButton(Montaje);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon1);

        gridLayout->addWidget(pushButton_7, 1, 2, 1, 1);


        retranslateUi(Montaje);

        QMetaObject::connectSlotsByName(Montaje);
    } // setupUi

    void retranslateUi(QDialog *Montaje)
    {
        Montaje->setWindowTitle(QApplication::translate("Montaje", "Dialog", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Montaje", "Unidad", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Montaje", "Identificacion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Montaje", "Sistema de archivos", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Montaje", "Particion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Montaje", "Peso", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Montaje", "Etiqueta", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Montaje", "Aceptar", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Montaje", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Montaje: public Ui_Montaje {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTAJE_H
