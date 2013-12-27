/********************************************************************************
** Form generated from reading UI file 'busca.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSCA_H
#define UI_BUSCA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Busca
{
public:
    QGridLayout *gridLayout_10;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_8;
    QCheckBox *checkBox_4;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QLineEdit *lineEdit_3;
    QRadioButton *radioButton_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_9;
    QRadioButton *radioButton_9;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_10;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;

    void setupUi(QDialog *Busca)
    {
        if (Busca->objectName().isEmpty())
            Busca->setObjectName(QString::fromUtf8("Busca"));
        Busca->resize(697, 670);
        Busca->setMinimumSize(QSize(564, 543));
        QFont font;
        font.setPointSize(7);
        Busca->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/lupa.png"), QSize(), QIcon::Normal, QIcon::Off);
        Busca->setWindowIcon(icon);
        gridLayout_10 = new QGridLayout(Busca);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        groupBox_2 = new QGroupBox(Busca);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_4 = new QGridLayout(groupBox_6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(groupBox_6);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_4->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_6);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_4->addWidget(radioButton_2, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_6, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_7->addWidget(lineEdit_2, 0, 0, 1, 1);

        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(25, 16777215));

        gridLayout_7->addWidget(pushButton, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setMaximumSize(QSize(350, 16777215));
        gridLayout_8 = new QGridLayout(groupBox_7);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        checkBox_4 = new QCheckBox(groupBox_7);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_8->addWidget(checkBox_4, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_7);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        radioButton_4 = new QRadioButton(groupBox_4);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout_5->addWidget(radioButton_4, 0, 3, 1, 1);

        radioButton_3 = new QRadioButton(groupBox_4);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_5->addWidget(radioButton_3, 0, 1, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox_4);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMaximumSize(QSize(40, 16777215));

        gridLayout_5->addWidget(lineEdit_3, 0, 6, 1, 1);

        radioButton_5 = new QRadioButton(groupBox_4);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

        gridLayout_5->addWidget(radioButton_5, 0, 5, 1, 1);

        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 0, 4, 1, 1);


        gridLayout_8->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox_5 = new QGroupBox(groupBox_7);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        radioButton_6 = new QRadioButton(groupBox_5);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));

        gridLayout_6->addWidget(radioButton_6, 0, 0, 1, 1);

        radioButton_7 = new QRadioButton(groupBox_5);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));

        gridLayout_6->addWidget(radioButton_7, 0, 1, 1, 1);

        radioButton_8 = new QRadioButton(groupBox_5);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));

        gridLayout_6->addWidget(radioButton_8, 0, 2, 1, 1);


        gridLayout_8->addWidget(groupBox_5, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_7, 0, 1, 2, 1);


        gridLayout_10->addWidget(groupBox_2, 2, 0, 1, 4);

        label_4 = new QLabel(Busca);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout_10->addWidget(label_4, 4, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_3, 4, 1, 1, 1);

        pushButton_6 = new QPushButton(Busca);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/lupaO.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon1);
        pushButton_6->setIconSize(QSize(25, 25));

        gridLayout_10->addWidget(pushButton_6, 4, 2, 1, 1);

        pushButton_3 = new QPushButton(Busca);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(100, 16777215));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(40, 25));

        gridLayout_10->addWidget(pushButton_3, 4, 3, 1, 1);

        groupBox_8 = new QGroupBox(Busca);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_9 = new QGridLayout(groupBox_8);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        radioButton_9 = new QRadioButton(groupBox_8);
        radioButton_9->setObjectName(QString::fromUtf8("radioButton_9"));

        gridLayout_9->addWidget(radioButton_9, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton_10 = new QRadioButton(groupBox_8);
        radioButton_10->setObjectName(QString::fromUtf8("radioButton_10"));

        gridLayout->addWidget(radioButton_10, 0, 0, 1, 1);

        pushButton_7 = new QPushButton(groupBox_8);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setIcon(icon1);
        pushButton_7->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_7, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_4, 0, 1, 1, 1);


        gridLayout_10->addWidget(groupBox_8, 0, 0, 1, 4);

        groupBox = new QGroupBox(Busca);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 4);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(100, 16777215));
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(40, 25));

        gridLayout_2->addWidget(pushButton_4, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(160, 16777215));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon3);
        pushButton_5->setIconSize(QSize(40, 25));

        gridLayout_2->addWidget(pushButton_5, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(100, 35));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/tirachinas.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);

        gridLayout_2->addWidget(pushButton_2, 0, 3, 1, 1);


        gridLayout_10->addWidget(groupBox, 1, 0, 1, 4);

        tableWidget = new QTableWidget(Busca);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/64px-Dolphin-icon.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setIcon(icon5);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);

        gridLayout_10->addWidget(tableWidget, 3, 0, 1, 4);


        retranslateUi(Busca);

        QMetaObject::connectSlotsByName(Busca);
    } // setupUi

    void retranslateUi(QDialog *Busca)
    {
        Busca->setWindowTitle(QApplication::translate("Busca", "Buscador", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Busca", "Opciones de busqueda", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("Busca", "Mayusculas/Minusculas", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton->setToolTip(QApplication::translate("Busca", "No distingir entre mayusculas y minusculas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton->setStatusTip(QApplication::translate("Busca", "No distingir entre mayusculas y minusculas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton->setWhatsThis(QApplication::translate("Busca", "No distingir entre mayusculas y minusculas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton->setText(QApplication::translate("Busca", "No distingir Mayusculas/Minusculas", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_2->setToolTip(QApplication::translate("Busca", "Distingir entre mayusculas y minusculas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_2->setStatusTip(QApplication::translate("Busca", "Distingir entre mayusculas y minusculas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_2->setWhatsThis(QApplication::translate("Busca", "Distingir entre mayusculas y minusculas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_2->setText(QApplication::translate("Busca", "Distingir Mayusculas/Minusculas", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Busca", "Desde donde buscar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("Busca", "Ruta desde donde buscar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QApplication::translate("Busca", "Ruta desde donde buscar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("Busca", "Ruta desde donde buscar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("Busca", "Acceso a directorio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("Busca", "Acceso a directorio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("Busca", "Acceso a directorio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("Busca", "...", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("Busca", "Peso/Tipo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_4->setToolTip(QApplication::translate("Busca", "Buscar condicionales por peso de ficheros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_4->setStatusTip(QApplication::translate("Busca", "Buscar condicionales por peso de ficheros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_4->setWhatsThis(QApplication::translate("Busca", "Buscar condicionales por peso de ficheros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_4->setText(QApplication::translate("Busca", "Buscar por peso de ficheros", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Busca", "Peso", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_4->setToolTip(QApplication::translate("Busca", "Menor que...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_4->setStatusTip(QApplication::translate("Busca", "Menor que...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_4->setWhatsThis(QApplication::translate("Busca", "Menor que...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_4->setText(QApplication::translate("Busca", "Menor", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_3->setToolTip(QApplication::translate("Busca", "Mayor que...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_3->setStatusTip(QApplication::translate("Busca", "Mayor que...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_3->setWhatsThis(QApplication::translate("Busca", "Mayor que...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_3->setText(QApplication::translate("Busca", "Mayor", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_3->setToolTip(QApplication::translate("Busca", "Cantidad a buscar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_3->setStatusTip(QApplication::translate("Busca", "Cantidad a buscar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_3->setWhatsThis(QApplication::translate("Busca", "Cantidad a buscar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        radioButton_5->setToolTip(QApplication::translate("Busca", "Igual que...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_5->setStatusTip(QApplication::translate("Busca", "Igual que...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_5->setWhatsThis(QApplication::translate("Busca", "Igual que...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_5->setText(QApplication::translate("Busca", "Igual", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
#ifndef QT_NO_TOOLTIP
        groupBox_5->setToolTip(QApplication::translate("Busca", "Tipo de busqueda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_5->setStatusTip(QApplication::translate("Busca", "Tipo de busqueda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupBox_5->setWhatsThis(QApplication::translate("Busca", "Tipo de busqueda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_5->setTitle(QApplication::translate("Busca", "Tipo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_6->setToolTip(QApplication::translate("Busca", "Busqueda por Kb", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_6->setStatusTip(QApplication::translate("Busca", "Busqueda por Kb", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_6->setWhatsThis(QApplication::translate("Busca", "Busqueda por Kb", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_6->setText(QApplication::translate("Busca", "Kilobyte", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_7->setToolTip(QApplication::translate("Busca", "Busqueda por Mb", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_7->setStatusTip(QApplication::translate("Busca", "Busqueda por Mb", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_7->setWhatsThis(QApplication::translate("Busca", "Busqueda por Mb", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_7->setText(QApplication::translate("Busca", "Megas", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_8->setToolTip(QApplication::translate("Busca", "Busqueda por Gb", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_8->setStatusTip(QApplication::translate("Busca", "Busqueda por Gb", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_8->setWhatsThis(QApplication::translate("Busca", "Busqueda por Gb", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_8->setText(QApplication::translate("Busca", "Gigas", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        pushButton_6->setText(QApplication::translate("Busca", "Abrir ruta", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("Busca", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("Busca", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("Busca", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("Busca", "Salir", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("Busca", "Tipo de busqueda", 0, QApplication::UnicodeUTF8));
        radioButton_9->setText(QApplication::translate("Busca", "Por nombre", 0, QApplication::UnicodeUTF8));
        radioButton_10->setText(QApplication::translate("Busca", "Por espacio (los 10 archivos/carpetas que mas ocupan)", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Busca", "Buscar", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Busca", "Nombre a buscar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("Busca", "Palabra clave a buscar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QApplication::translate("Busca", "Palabra clave a buscar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit->setWhatsThis(QApplication::translate("Busca", "Palabra clave a buscar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("Busca", "*Utiliza comodines para ampliar la busqueda. (Ejem. *mos*.avi, *mos*, *.avi, *mos o mos*)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("Busca", "Lanzar la busqueda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("Busca", "Lanzar la busqueda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("Busca", "Lanzar la busqueda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("Busca", "Buscar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("Busca", "Cancelar la busqueda comenzada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("Busca", "Cancelar la busqueda comenzada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("Busca", "Cancelar la busqueda comenzada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QApplication::translate("Busca", "Cancelar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("Busca", "Ejecutar los archivos localizados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("Busca", "Ejecutar los archivos localizados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("Busca", "Ejecutar los archivos localizados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("Busca", "Ejecutar", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Busca", "Ruta/Archivo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Busca", "Peso", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QApplication::translate("Busca", "Fichero localizados en la busqueda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget->setStatusTip(QApplication::translate("Busca", "Fichero localizados en la busqueda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget->setWhatsThis(QApplication::translate("Busca", "Fichero localizados en la busqueda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class Busca: public Ui_Busca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSCA_H
