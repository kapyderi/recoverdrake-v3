/********************************************************************************
** Form generated from reading UI file 'rpm.ui'
**
** Created: Fri Oct 21 20:25:47 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RPM_H
#define UI_RPM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_rpm
{
public:
    QTableWidget *tableWidget;

    void setupUi(QDialog *rpm)
    {
        if (rpm->objectName().isEmpty())
            rpm->setObjectName(QString::fromUtf8("rpm"));
        rpm->resize(723, 427);
        rpm->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 127);"));
        tableWidget = new QTableWidget(rpm);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::Dense4Pattern);
        QFont font;
        font.setPointSize(8);
        font.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem->setFont(font);
        __qtablewidgetitem->setForeground(brush);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 701, 371));
        tableWidget->setAutoScrollMargin(26);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);
        tableWidget->verticalHeader()->setMinimumSectionSize(50);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->verticalHeader()->setStretchLastSection(true);

        retranslateUi(rpm);

        QMetaObject::connectSlotsByName(rpm);
    } // setupUi

    void retranslateUi(QDialog *rpm)
    {
        rpm->setWindowTitle(QApplication::translate("rpm", "Dialog", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("rpm", "Nombre RPM", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("rpm", "Descripci\303\263n", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class rpm: public Ui_rpm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RPM_H
