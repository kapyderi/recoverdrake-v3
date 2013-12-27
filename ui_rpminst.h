/********************************************************************************
** Form generated from reading UI file 'rpminst.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RPMINST_H
#define UI_RPMINST_H

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
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_rpminst
{
public:
    QGridLayout *gridLayout_4;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QTextEdit *textEdit;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_2;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *rpminst)
    {
        if (rpminst->objectName().isEmpty())
            rpminst->setObjectName(QString::fromUtf8("rpminst"));
        rpminst->resize(707, 447);
        QFont font;
        font.setPointSize(7);
        rpminst->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/rpm.png"), QSize(), QIcon::Normal, QIcon::Off);
        rpminst->setWindowIcon(icon);
        rpminst->setStyleSheet(QString::fromUtf8(""));
        gridLayout_4 = new QGridLayout(rpminst);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tableWidget = new QTableWidget(rpminst);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setIcon(icon1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem2->setIcon(icon);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setIcon(icon);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setIcon(icon);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setIcon(icon);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        tableWidget->setFont(font1);
        tableWidget->setAutoScrollMargin(26);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(25);
        tableWidget->verticalHeader()->setMinimumSectionSize(25);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->verticalHeader()->setStretchLastSection(true);

        gridLayout_4->addWidget(tableWidget, 0, 0, 1, 3);

        groupBox = new QGroupBox(rpminst);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(187, 16777215));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_14 = new QPushButton(groupBox);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(131, 0));
        pushButton_14->setMaximumSize(QSize(181, 25));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/luparpm.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon2);
        pushButton_14->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_14, 0, 0, 1, 1);

        pushButton_15 = new QPushButton(groupBox);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(131, 0));
        pushButton_15->setMaximumSize(QSize(181, 25));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/lupaO.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon3);
        pushButton_15->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_15, 1, 0, 1, 1);

        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(131, 0));
        pushButton_10->setMaximumSize(QSize(181, 25));
        pushButton_10->setIcon(icon1);
        pushButton_10->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_10, 2, 0, 1, 1);

        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(131, 0));
        pushButton_12->setMaximumSize(QSize(181, 25));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon4);
        pushButton_12->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_12, 3, 0, 1, 1);

        pushButton_13 = new QPushButton(groupBox);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(131, 0));
        pushButton_13->setMaximumSize(QSize(181, 25));
        pushButton_13->setIcon(icon4);
        pushButton_13->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_13, 4, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 2, 0, 1, 1);

        textEdit = new QTextEdit(rpminst);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setSizeIncrement(QSize(0, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nimbus Sans L Condensed"));
        font2.setPointSize(8);
        textEdit->setFont(font2);
        textEdit->setFocusPolicy(Qt::TabFocus);
        textEdit->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(textEdit, 2, 1, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_2 = new QLineEdit(rpminst);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(109, 18));
        lineEdit_2->setMaximumSize(QSize(109, 18));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setWeight(75);
        lineEdit_2->setFont(font3);
        lineEdit_2->setLayoutDirection(Qt::LeftToRight);
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 1);

        label = new QLabel(rpminst);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout, 1, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_2 = new QPushButton(rpminst);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(201, 26));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon5);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_2, 0, 0, 1, 1);

        progressBar = new QProgressBar(rpminst);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_3->addWidget(progressBar, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 3, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(433, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        retranslateUi(rpminst);

        QMetaObject::connectSlotsByName(rpminst);
    } // setupUi

    void retranslateUi(QDialog *rpminst)
    {
        rpminst->setWindowTitle(QApplication::translate("rpminst", "Mantenimiento de rpm\305\233", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("rpminst", "Marca", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("rpminst", "Fecha de instalacion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("rpminst", "Nombre de paquete", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("rpminst", "Kernel-source", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("rpminst", "Kernel-devel", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("rpminst", "Kernel-latest", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QApplication::translate("rpminst", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget->setStatusTip(QApplication::translate("rpminst", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget->setWhatsThis(QApplication::translate("rpminst", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QApplication::translate("rpminst", "Menu de opciones", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_14->setToolTip(QApplication::translate("rpminst", "Comprobacion de los paquetes instalados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_14->setStatusTip(QApplication::translate("rpminst", "Comprobacion de los paquetes instalados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_14->setWhatsThis(QApplication::translate("rpminst", "Comprobacion de los paquetes instalados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_14->setText(QApplication::translate("rpminst", "Rastrear rpms", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_15->setToolTip(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_15->setStatusTip(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_15->setWhatsThis(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_15->setText(QApplication::translate("rpminst", "Rastrear (filtro)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_10->setStatusTip(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_10->setWhatsThis(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_10->setText(QApplication::translate("rpminst", "Marcar rpm", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_12->setToolTip(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_12->setStatusTip(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_12->setWhatsThis(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_12->setText(QApplication::translate("rpminst", "Desmarcar rpm", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_13->setToolTip(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_13->setStatusTip(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_13->setWhatsThis(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_13->setText(QApplication::translate("rpminst", "Desinstalar rpms", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("rpminst", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit->setStatusTip(QApplication::translate("rpminst", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QApplication::translate("rpminst", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        textEdit->setHtml(QApplication::translate("rpminst", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Nimbus Sans L Condensed'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:7pt; font-weight:600;\"><br /></span></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("rpminst", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QApplication::translate("rpminst", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("rpminst", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("rpminst", "Total Registros:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("rpminst", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("rpminst", "Salir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        progressBar->setToolTip(QApplication::translate("rpminst", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        progressBar->setStatusTip(QApplication::translate("rpminst", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        progressBar->setWhatsThis(QApplication::translate("rpminst", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class rpminst: public Ui_rpminst {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RPMINST_H
