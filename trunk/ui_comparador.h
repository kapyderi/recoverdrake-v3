/********************************************************************************
** Form generated from reading UI file 'comparador.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPARADOR_H
#define UI_COMPARADOR_H

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
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Comparador
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_17;
    QGridLayout *gridLayout_15;
    QGridLayout *gridLayout_7;
    QLabel *label_2;
    QLabel *label_4;
    QGridLayout *gridLayout_14;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_12;
    QLabel *label_5;
    QLabel *label_3;
    QTreeWidget *treeWidget;
    QGridLayout *gridLayout_16;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_13;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_14;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_11;
    QTableWidget *tableWidget_2;
    QTextEdit *textEdit_3;
    QProgressBar *progressBar;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton;
    QCheckBox *checkBox;
    QRadioButton *radioButton_2;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_13;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_15;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *Comparador)
    {
        if (Comparador->objectName().isEmpty())
            Comparador->setObjectName(QString::fromUtf8("Comparador"));
        Comparador->resize(1070, 749);
        QFont font;
        font.setPointSize(7);
        Comparador->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/Comparador.png"), QSize(), QIcon::Normal, QIcon::Off);
        Comparador->setWindowIcon(icon);
        gridLayout = new QGridLayout(Comparador);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(Comparador);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1049, 851));
        gridLayout_9 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_17 = new QGridLayout(groupBox);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_7->addWidget(label_4, 0, 1, 1, 1);


        gridLayout_15->addLayout(gridLayout_7, 0, 0, 1, 1);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font1;
        font1.setPointSize(12);
        label_6->setFont(font1);

        gridLayout_14->addWidget(label_6, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_15->addLayout(gridLayout_14, 0, 1, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_12->addWidget(label_5, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_12->addWidget(label_3, 0, 1, 1, 1);


        gridLayout_15->addLayout(gridLayout_12, 0, 2, 1, 1);


        gridLayout_17->addLayout(gridLayout_15, 0, 0, 1, 3);

        treeWidget = new QTreeWidget(groupBox);
        QBrush brush(QColor(143, 143, 143, 255));
        brush.setStyle(Qt::NoBrush);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setForeground(2, brush);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy2);
        treeWidget->setEditTriggers(QAbstractItemView::SelectedClicked);
        treeWidget->setAlternatingRowColors(true);

        gridLayout_17->addWidget(treeWidget, 1, 0, 1, 3);

        gridLayout_16 = new QGridLayout();
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_16->addWidget(radioButton_3, 0, 0, 1, 1);

        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout_16->addWidget(radioButton_4, 0, 1, 1, 1);

        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

        gridLayout_16->addWidget(radioButton_5, 0, 2, 1, 1);


        gridLayout_17->addLayout(gridLayout_16, 2, 0, 1, 3);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_17->addWidget(label_7, 3, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_17->addItem(horizontalSpacer_4, 3, 1, 1, 1);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/logdrake-mdk.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon1);
        pushButton_11->setIconSize(QSize(25, 25));

        gridLayout_13->addWidget(pushButton_11, 0, 1, 1, 1);

        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/prisma.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon2);
        pushButton_10->setIconSize(QSize(25, 25));

        gridLayout_13->addWidget(pushButton_10, 0, 2, 1, 1);

        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/lupaO.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon3);
        pushButton_12->setIconSize(QSize(25, 25));

        gridLayout_13->addWidget(pushButton_12, 0, 3, 1, 1);

        pushButton_14 = new QPushButton(groupBox);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon4);
        pushButton_14->setIconSize(QSize(25, 25));

        gridLayout_13->addWidget(pushButton_14, 0, 0, 1, 1);


        gridLayout_17->addLayout(gridLayout_13, 3, 2, 1, 1);

        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout_17->addWidget(tableWidget, 4, 0, 1, 3);


        gridLayout_9->addWidget(groupBox, 5, 0, 1, 2);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_11 = new QGridLayout(groupBox_4);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        tableWidget_2 = new QTableWidget(groupBox_4);
        if (tableWidget_2->columnCount() < 10)
            tableWidget_2->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(7, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(8, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(9, __qtablewidgetitem12);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        sizePolicy2.setHeightForWidth(tableWidget_2->sizePolicy().hasHeightForWidth());
        tableWidget_2->setSizePolicy(sizePolicy2);
        tableWidget_2->setMinimumSize(QSize(0, 150));
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->setAlternatingRowColors(true);
        tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_2->setSortingEnabled(true);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget_2->horizontalHeader()->setMinimumSectionSize(50);

        gridLayout_11->addWidget(tableWidget_2, 0, 0, 1, 1);

        textEdit_3 = new QTextEdit(groupBox_4);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        sizePolicy.setHeightForWidth(textEdit_3->sizePolicy().hasHeightForWidth());
        textEdit_3->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(textEdit_3, 2, 0, 1, 1);

        progressBar = new QProgressBar(groupBox_4);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_11->addWidget(progressBar, 3, 0, 1, 1);

        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_11->addWidget(label, 1, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_4, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon5);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_2, 11, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon6);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setIcon(icon6);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_3, 1, 2, 1, 1);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_3->addWidget(lineEdit_2, 1, 3, 1, 1);

        radioButton = new QRadioButton(scrollAreaWidgetContents);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_3->addWidget(radioButton, 0, 0, 1, 1);

        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_3->addWidget(checkBox, 0, 2, 1, 2);

        radioButton_2 = new QRadioButton(scrollAreaWidgetContents);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_3->addWidget(radioButton_2, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton_13 = new QPushButton(groupBox_2);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon7);
        pushButton_13->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_13, 0, 4, 1, 1);

        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/thumbs_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon8);
        pushButton_8->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_8, 0, 1, 1, 1);

        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Imagenes/diskdrake_hd.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon9);
        pushButton_7->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_9 = new QPushButton(groupBox_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Imagenes/Error.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon10);
        pushButton_9->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_9, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setIcon(icon4);
        pushButton_4->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_4, 0, 3, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 2, 1, 1);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        gridLayout_10 = new QGridLayout(groupBox_3);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        pushButton_15 = new QPushButton(groupBox_3);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Imagenes/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon11);
        pushButton_15->setIconSize(QSize(25, 25));

        gridLayout_8->addWidget(pushButton_15, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setIcon(icon3);
        pushButton_5->setIconSize(QSize(25, 25));

        gridLayout_8->addWidget(pushButton_5, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setIcon(icon);
        pushButton_6->setIconSize(QSize(25, 25));

        gridLayout_8->addWidget(pushButton_6, 0, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_8, 0, 0, 1, 2);


        gridLayout_4->addWidget(groupBox_3, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 2, 0, 1, 4);


        gridLayout_9->addLayout(gridLayout_3, 0, 0, 1, 2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 3, 0, 1, 1);


        retranslateUi(Comparador);

        QMetaObject::connectSlotsByName(Comparador);
    } // setupUi

    void retranslateUi(QDialog *Comparador)
    {
        Comparador->setWindowTitle(QApplication::translate("Comparador", "Comparador v.0.1.0", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Comparador", "Archivo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("Comparador", "Numero de lineas que contiene el archivo origen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_2->setStatusTip(QApplication::translate("Comparador", "Numero de lineas que contiene el archivo origen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_2->setWhatsThis(QApplication::translate("Comparador", "Numero de lineas que contiene el archivo origen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("Comparador", "Lineas Origen:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("Comparador", "Numero de lineas que contiene el archivo destino", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_5->setStatusTip(QApplication::translate("Comparador", "Numero de lineas que contiene el archivo destino", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_5->setWhatsThis(QApplication::translate("Comparador", "Numero de lineas que contiene el archivo destino", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_5->setText(QApplication::translate("Comparador", "Lineas destino:", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("Comparador", "Tipo", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("Comparador", "Valor destino", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("Comparador", "Linea destino", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("Comparador", "Valor origen", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("Comparador", "Linea origen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        treeWidget->setToolTip(QApplication::translate("Comparador", "Muestra la comparacion de lineas de los dos archivos comparados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        treeWidget->setStatusTip(QApplication::translate("Comparador", "Muestra la comparacion de lineas de los dos archivos comparados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        treeWidget->setWhatsThis(QApplication::translate("Comparador", "Muestra la comparacion de lineas de los dos archivos comparados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        radioButton_3->setToolTip(QApplication::translate("Comparador", "Hace una comparacion de archivos linea a linea segun posicion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_3->setStatusTip(QApplication::translate("Comparador", "Hace una comparacion de archivos linea a linea segun posicion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_3->setWhatsThis(QApplication::translate("Comparador", "Hace una comparacion de archivos linea a linea segun posicion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_3->setText(QApplication::translate("Comparador", "Comparar linea a linea", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_4->setToolTip(QApplication::translate("Comparador", "Hace una comparacion de archivos mostrando el numero de repeticiones de lineas origen en destino", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_4->setStatusTip(QApplication::translate("Comparador", "Hace una comparacion de archivos mostrando el numero de repeticiones de lineas origen en destino", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_4->setWhatsThis(QApplication::translate("Comparador", "Hace una comparacion de archivos mostrando el numero de repeticiones de lineas origen en destino", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_4->setText(QApplication::translate("Comparador", "Comparar por repeticiones", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_5->setToolTip(QApplication::translate("Comparador", "Hace una comparacion exacta con el numero de lineas diferentes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_5->setStatusTip(QApplication::translate("Comparador", "Hace una comparacion exacta con el numero de lineas diferentes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_5->setWhatsThis(QApplication::translate("Comparador", "Hace una comparacion exacta con el numero de lineas diferentes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_5->setText(QApplication::translate("Comparador", "Comparar diferencias exactas", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Comparador", "Cambios localizados", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_11->setToolTip(QApplication::translate("Comparador", "Muestra las lineas de origen que estan vacias", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_11->setStatusTip(QApplication::translate("Comparador", "Muestra las lineas de origen que estan vacias", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_11->setWhatsThis(QApplication::translate("Comparador", "Muestra las lineas de origen que estan vacias", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_11->setText(QApplication::translate("Comparador", "Mostrar origen vacio", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QApplication::translate("Comparador", "Muestra las lineas de destino que estan vacias", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_10->setStatusTip(QApplication::translate("Comparador", "Muestra las lineas de destino que estan vacias", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_10->setWhatsThis(QApplication::translate("Comparador", "Muestra las lineas de destino que estan vacias", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_10->setText(QApplication::translate("Comparador", "Mostrar destino vacio", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_12->setToolTip(QApplication::translate("Comparador", "Muestra solo las lineas con diferencias", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_12->setStatusTip(QApplication::translate("Comparador", "Muestra solo las lineas con diferencias", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_12->setWhatsThis(QApplication::translate("Comparador", "Muestra solo las lineas con diferencias", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_12->setText(QApplication::translate("Comparador", "Mostrar lineas diferentes", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_14->setToolTip(QApplication::translate("Comparador", "Muestra todas las diferencias localizadas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_14->setStatusTip(QApplication::translate("Comparador", "Muestra todas las diferencias localizadas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_14->setWhatsThis(QApplication::translate("Comparador", "Muestra todas las diferencias localizadas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_14->setText(QApplication::translate("Comparador", "Todas las diferencias", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Comparador", "Linea origen", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Comparador", "Linea destino", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Comparador", "Tipo diferencia", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QApplication::translate("Comparador", "Muestra los datos de la seleccion de tipo de comparacion en archivos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget->setStatusTip(QApplication::translate("Comparador", "Muestra los datos de la seleccion de tipo de comparacion en archivos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget->setWhatsThis(QApplication::translate("Comparador", "Muestra los datos de la seleccion de tipo de comparacion en archivos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_4->setTitle(QApplication::translate("Comparador", "Directorio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Comparador", "Nombre del objetivo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Comparador", "Ruta del objetivo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("Comparador", "Peso del objetivo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("Comparador", "Fecha del objetivo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("Comparador", "Tipo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("Comparador", "Estado", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("Comparador", "Nombre del destino", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(7);
        ___qtablewidgetitem10->setText(QApplication::translate("Comparador", "Ruta del destino", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(8);
        ___qtablewidgetitem11->setText(QApplication::translate("Comparador", "Peso destino", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(9);
        ___qtablewidgetitem12->setText(QApplication::translate("Comparador", "Fecha destino", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget_2->setToolTip(QApplication::translate("Comparador", "Muestra los objetivos localizados con sus propiedades", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget_2->setStatusTip(QApplication::translate("Comparador", "Muestra los objetivos localizados con sus propiedades", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget_2->setWhatsThis(QApplication::translate("Comparador", "Muestra los objetivos localizados con sus propiedades", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_STATUSTIP
        textEdit_3->setStatusTip(QApplication::translate("Comparador", "Consola de procesos en busqueda de directorios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit_3->setWhatsThis(QApplication::translate("Comparador", "Consola de procesos en busqueda de directorios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        textEdit_3->setAccessibleName(QApplication::translate("Comparador", "Consola de procesos en busqueda de directorios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_TOOLTIP
        progressBar->setToolTip(QApplication::translate("Comparador", "Barra de progreso en directorios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        progressBar->setStatusTip(QApplication::translate("Comparador", "Barra de progreso en directorios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        progressBar->setWhatsThis(QApplication::translate("Comparador", "Barra de progreso en directorios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("Comparador", "Consola de procesos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("Comparador", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("Comparador", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("Comparador", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("Comparador", "Salir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("Comparador", "Examinar el directorio/archivo fuente para sincronizacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("Comparador", "Examinar el directorio/archivo fuente para sincronizacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("Comparador", "Examinar el directorio/archivo fuente para sincronizacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("Comparador", "Directorio objetivo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("Comparador", "Ruta de origen.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QApplication::translate("Comparador", "Ruta de origen.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit->setWhatsThis(QApplication::translate("Comparador", "Ruta de origen.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("Comparador", "Elegir directorio destino/archivo de sincronizacion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("Comparador", "Elegir directorio/archivo destino de sincronizacion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("Comparador", "Elegir directorio/archivo destino de sincronizacion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("Comparador", "Directorio destino", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("Comparador", "Ruta de destino.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QApplication::translate("Comparador", "Ruta de destino.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("Comparador", "Ruta de destino.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        radioButton->setToolTip(QApplication::translate("Comparador", "Seleccion de directorios para comparar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton->setStatusTip(QApplication::translate("Comparador", "Seleccion de directorios para comparar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton->setWhatsThis(QApplication::translate("Comparador", "Seleccion de directorios para comparar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton->setText(QApplication::translate("Comparador", "Directorio ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("Comparador", "En directorios se puede suprimir la busqueda de archivos ocultos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox->setStatusTip(QApplication::translate("Comparador", "En directorios se puede suprimir la busqueda de archivos ocultos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox->setWhatsThis(QApplication::translate("Comparador", "En directorios se puede suprimir la busqueda de archivos ocultos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox->setText(QApplication::translate("Comparador", "Analizar archivos ocultos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_2->setToolTip(QApplication::translate("Comparador", "Seleccion de archivos para comparar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_2->setStatusTip(QApplication::translate("Comparador", "Seleccion de archivos para comparar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_2->setWhatsThis(QApplication::translate("Comparador", "Seleccion de archivos para comparar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_2->setText(QApplication::translate("Comparador", "Archivo", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Comparador", "Resultados", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_13->setToolTip(QApplication::translate("Comparador", "Filtra por los ficheros eliminados o no encontrados en el directorio fuente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_13->setStatusTip(QApplication::translate("Comparador", "Filtra por los ficheros eliminados o no encontrados en el directorio fuente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_13->setWhatsThis(QApplication::translate("Comparador", "Filtra por los ficheros eliminados o no encontrados en el directorio fuente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_13->setText(QApplication::translate("Comparador", "Sin origen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_8->setToolTip(QApplication::translate("Comparador", "Filtra por los que no han sufrido cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_8->setStatusTip(QApplication::translate("Comparador", "Filtra por los que no han sufrido cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_8->setWhatsThis(QApplication::translate("Comparador", "Filtra por los que no han sufrido cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_8->setText(QApplication::translate("Comparador", "Iguales", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("Comparador", "Muestra todos los ficheros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_7->setStatusTip(QApplication::translate("Comparador", "Muestra todos los ficheros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_7->setWhatsThis(QApplication::translate("Comparador", "Muestra todos los ficheros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_7->setText(QApplication::translate("Comparador", "Todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_9->setToolTip(QApplication::translate("Comparador", "Filtra por los que han sufrido cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_9->setStatusTip(QApplication::translate("Comparador", "Filtra por los que han sufrido cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_9->setWhatsThis(QApplication::translate("Comparador", "Filtra por los que han sufrido cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_9->setText(QApplication::translate("Comparador", "Diferentes", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("Comparador", "Filtra por los archivos nuevos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("Comparador", "Filtra por los archivos nuevos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("Comparador", "Filtra por los archivos nuevos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("Comparador", "Sin destino", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Comparador", "Acciones", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_15->setToolTip(QApplication::translate("Comparador", "Parar los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_15->setStatusTip(QApplication::translate("Comparador", "Parar los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_15->setWhatsThis(QApplication::translate("Comparador", "Parar los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_15->setText(QApplication::translate("Comparador", "Parar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("Comparador", "Analizar el directorio fuente en busca de cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("Comparador", "Analizar el directorio fuente en busca de cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("Comparador", "Analizar el directorio fuente en busca de cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QApplication::translate("Comparador", "Analizar objetivos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("Comparador", "Comparacion de archivos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_6->setStatusTip(QApplication::translate("Comparador", "Comparacion de archivos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_6->setWhatsThis(QApplication::translate("Comparador", "Comparacion de archivos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_6->setText(QApplication::translate("Comparador", "Comparar archivos", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Comparador: public Ui_Comparador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPARADOR_H
