/********************************************************************************
** Form generated from reading UI file 'totalsincrono.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOTALSINCRONO_H
#define UI_TOTALSINCRONO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_TotalSincrono
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_12;
    QPushButton *pushButton_14;
    QPushButton *pushButton_10;
    QTableView *tableView;

    void setupUi(QDialog *TotalSincrono)
    {
        if (TotalSincrono->objectName().isEmpty())
            TotalSincrono->setObjectName(QString::fromUtf8("TotalSincrono"));
        TotalSincrono->resize(687, 507);
        QFont font;
        font.setPointSize(7);
        TotalSincrono->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/Sincronizar.png"), QSize(), QIcon::Normal, QIcon::Off);
        TotalSincrono->setWindowIcon(icon);
        gridLayout = new QGridLayout(TotalSincrono);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 9);
        splitter = new QSplitter(TotalSincrono);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        splitter->addWidget(tabWidget);
        groupBox_3 = new QGroupBox(splitter);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 147));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon2);
        pushButton_5->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_5, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 1, 1, 1);

        line = new QFrame(groupBox_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 0, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_12 = new QPushButton(groupBox_3);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/BACKUP.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon3);
        pushButton_12->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_12, 1, 0, 1, 2);

        pushButton_14 = new QPushButton(groupBox_3);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/disco-duro.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon4);
        pushButton_14->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_14, 0, 0, 1, 2);

        pushButton_10 = new QPushButton(groupBox_3);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon5);
        pushButton_10->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_10, 3, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 3, 1, 1);

        tableView = new QTableView(groupBox_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy1);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        gridLayout_4->addWidget(tableView, 0, 0, 1, 1);

        splitter->addWidget(groupBox_3);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(TotalSincrono);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(TotalSincrono);
    } // setupUi

    void retranslateUi(QDialog *TotalSincrono)
    {
        TotalSincrono->setWindowTitle(QApplication::translate("TotalSincrono", "Sincrono v.0.1.0", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("TotalSincrono", "Objetivos guardados", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("TotalSincrono", "Inserta una nueva pestana vacia a sincronizadores", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("TotalSincrono", "Inserta una nueva pestana vacia a sincronizadores", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("TotalSincrono", "Inserta una nueva pestana vacia a sincronizadores", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("TotalSincrono", "Insertar Sincronizacion", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("TotalSincrono", "Elimina la pestana activa en sincronizadores", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("TotalSincrono", "Elimina la pestana activa en sincronizadores", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("TotalSincrono", "Elimina la pestana activa en sincronizadores", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QApplication::translate("TotalSincrono", "Eliminar Sincronizacion", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_12->setToolTip(QApplication::translate("TotalSincrono", "Analiza y sincroniza automaticamente los objetivos guardados en la base de datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_12->setStatusTip(QApplication::translate("TotalSincrono", "Analiza y sincroniza automaticamente los objetivos guardados en la base de datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_12->setWhatsThis(QApplication::translate("TotalSincrono", "Analiza y sincroniza automaticamente los objetivos guardados en la base de datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_12->setText(QApplication::translate("TotalSincrono", "Sincronizar Objetivos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_14->setToolTip(QApplication::translate("TotalSincrono", "Analiza todos los objetivos guardados en la base de datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_14->setStatusTip(QApplication::translate("TotalSincrono", "Analiza todos los objetivos guardados en la base de datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_14->setWhatsThis(QApplication::translate("TotalSincrono", "Analiza todos los objetivos guardados en la base de datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_14->setText(QApplication::translate("TotalSincrono", "Analizar Objetivos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QApplication::translate("TotalSincrono", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_10->setStatusTip(QApplication::translate("TotalSincrono", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_10->setWhatsThis(QApplication::translate("TotalSincrono", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_10->setText(QApplication::translate("TotalSincrono", "Salir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableView->setToolTip(QApplication::translate("TotalSincrono", "Lista de objetivos guardados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableView->setStatusTip(QApplication::translate("TotalSincrono", "Lista de objetivos guardados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableView->setWhatsThis(QApplication::translate("TotalSincrono", "Lista de objetivos guardados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class TotalSincrono: public Ui_TotalSincrono {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALSINCRONO_H
