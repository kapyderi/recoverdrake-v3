/********************************************************************************
** Form generated from reading UI file 'sincrono.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINCRONO_H
#define UI_SINCRONO_H

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
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sincrono
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QTableWidget *tableWidget_2;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_3;
    QPushButton *pushButton_15;
    QGridLayout *gridLayout_8;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QTextEdit *textEdit;
    QPushButton *pushButton_14;
    QLabel *label;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_4;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_10;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QPushButton *pushButton_9;
    QPushButton *pushButton_2;
    QPushButton *pushButton_13;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLineEdit *lineEdit_4;

    void setupUi(QDialog *sincrono)
    {
        if (sincrono->objectName().isEmpty())
            sincrono->setObjectName(QString::fromUtf8("sincrono"));
        sincrono->resize(1185, 615);
        QFont font;
        font.setPointSize(7);
        sincrono->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/Sincronizar.png"), QSize(), QIcon::Normal, QIcon::Off);
        sincrono->setWindowIcon(icon);
        gridLayout = new QGridLayout(sincrono);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(sincrono);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1292, 594));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 1, 1, 1, 1);

        tableWidget_2 = new QTableWidget(scrollAreaWidgetContents);
        if (tableWidget_2->columnCount() < 10)
            tableWidget_2->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setMinimumSize(QSize(0, 150));
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->setAlternatingRowColors(true);
        tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_2->setSortingEnabled(true);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget_2->horizontalHeader()->setMinimumSectionSize(50);

        gridLayout_5->addWidget(tableWidget_2, 2, 0, 1, 9);

        progressBar = new QProgressBar(scrollAreaWidgetContents);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_5->addWidget(progressBar, 4, 0, 1, 9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 1, 3, 1, 1);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_5->addWidget(checkBox_3, 1, 6, 1, 1);

        pushButton_15 = new QPushButton(scrollAreaWidgetContents);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon1);
        pushButton_15->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_15, 1, 8, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_8->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);
        lineEdit_3->setMinimumSize(QSize(200, 0));

        gridLayout_8->addWidget(lineEdit_3, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_8, 1, 0, 1, 1);

        textEdit = new QTextEdit(scrollAreaWidgetContents);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_5->addWidget(textEdit, 6, 0, 1, 9);

        pushButton_14 = new QPushButton(scrollAreaWidgetContents);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/embudo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon2);
        pushButton_14->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_14, 1, 7, 1, 1);

        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 5, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/lupa.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon3);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_3->addWidget(lineEdit, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/logo_disco-duro.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon4);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_3, 0, 3, 1, 1);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_3->addWidget(lineEdit_2, 0, 5, 1, 1);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_2, 0, 1, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_4, 0, 4, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 9);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_10 = new QGridLayout(groupBox_2);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/diskdrake_hd.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon5);
        pushButton_7->setIconSize(QSize(25, 25));

        gridLayout_10->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/thumbs_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon6);
        pushButton_8->setIconSize(QSize(25, 25));

        gridLayout_10->addWidget(pushButton_8, 0, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setChecked(true);

        gridLayout_4->addWidget(checkBox_4, 0, 0, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_4->addWidget(checkBox_5, 1, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_4, 0, 2, 1, 1);

        pushButton_9 = new QPushButton(groupBox_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/Error.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon7);
        pushButton_9->setIconSize(QSize(25, 25));

        gridLayout_10->addWidget(pushButton_9, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon8);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout_10->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_13 = new QPushButton(groupBox_2);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon9);
        pushButton_13->setIconSize(QSize(25, 25));

        gridLayout_10->addWidget(pushButton_13, 1, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 2, 1, 1);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_9 = new QGridLayout(groupBox);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon10);
        pushButton_11->setIconSize(QSize(25, 25));

        gridLayout_6->addWidget(pushButton_11, 3, 1, 1, 1);

        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Imagenes/borrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon11);
        pushButton_10->setIconSize(QSize(25, 25));

        gridLayout_6->addWidget(pushButton_10, 3, 2, 1, 1);

        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setIcon(icon9);
        pushButton_12->setIconSize(QSize(25, 25));

        gridLayout_6->addWidget(pushButton_12, 3, 4, 1, 1);


        gridLayout_9->addLayout(gridLayout_6, 2, 0, 1, 2);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Imagenes/lupaO.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon12);
        pushButton_4->setIconSize(QSize(25, 25));

        gridLayout_7->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Imagenes/sustituir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon13);
        pushButton_5->setIconSize(QSize(25, 25));

        gridLayout_7->addWidget(pushButton_5, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Imagenes/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon14);
        pushButton_6->setIconSize(QSize(25, 25));

        gridLayout_7->addWidget(pushButton_6, 0, 2, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 0, 0, 1, 2);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 3, 0, 1, 9);

        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_5->addWidget(checkBox, 1, 4, 1, 1);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_5->addWidget(checkBox_2, 1, 5, 1, 1);

        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(40, 0));
        lineEdit_4->setMaximumSize(QSize(40, 16777215));
        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_4->setReadOnly(true);

        gridLayout_5->addWidget(lineEdit_4, 1, 2, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 1, 1, 1);


        retranslateUi(sincrono);

        QMetaObject::connectSlotsByName(sincrono);
    } // setupUi

    void retranslateUi(QDialog *sincrono)
    {
        sincrono->setWindowTitle(QApplication::translate("sincrono", "Sincrono v.0.1.0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("sincrono", "Numero Sincronizacion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("sincrono", "Nombre del objetivo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("sincrono", "Ruta del objetivo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("sincrono", "Peso del objetivo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("sincrono", "Fecha del objetivo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("sincrono", "Tipo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("sincrono", "Estado", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("sincrono", "Nombre del destino", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("sincrono", "Ruta del destino", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("sincrono", "Peso destino", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("sincrono", "Fecha destino", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget_2->setToolTip(QApplication::translate("sincrono", "Muestra los objetivos localizados con sus propiedades", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget_2->setStatusTip(QApplication::translate("sincrono", "Muestra los objetivos localizados con sus propiedades", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget_2->setWhatsThis(QApplication::translate("sincrono", "Muestra los objetivos localizados con sus propiedades", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        progressBar->setToolTip(QApplication::translate("sincrono", "Barra de progreso", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        progressBar->setStatusTip(QApplication::translate("sincrono", "Barra de progreso", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        progressBar->setWhatsThis(QApplication::translate("sincrono", "Barra de progreso", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_3->setText(QApplication::translate("sincrono", "Analizar archivos ocultos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_15->setToolTip(QApplication::translate("sincrono", "Recuperacion por fechas de ultimos cambios.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_15->setStatusTip(QApplication::translate("sincrono", "Recuperacion por fechas de ultimos cambios.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_15->setWhatsThis(QApplication::translate("sincrono", "Recuperacion por fechas de ultimos cambios.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_15->setText(QApplication::translate("sincrono", "Recuperar ultimo cambio", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("sincrono", "Nombre del proyecto:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("sincrono", "Visualizador de procesos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit->setStatusTip(QApplication::translate("sincrono", "Visualizador de procesos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QApplication::translate("sincrono", "Visualizador de procesos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_14->setToolTip(QApplication::translate("sincrono", "Filtrar palabras a omitir.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_14->setStatusTip(QApplication::translate("sincrono", "Filtrar palabras a omitir.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_14->setWhatsThis(QApplication::translate("sincrono", "Filtrar palabras a omitir.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_14->setText(QApplication::translate("sincrono", "Filtrar palabras", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("sincrono", "Visualizacion de procesos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("sincrono", "Examinar el directorio fuente para sincronizacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("sincrono", "Examinar el directorio fuente para sincronizacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("sincrono", "Examinar el directorio fuente para sincronizacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("sincrono", "Examinar objetivo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("sincrono", "Ruta de origen.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QApplication::translate("sincrono", "Ruta de origen.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit->setWhatsThis(QApplication::translate("sincrono", "Ruta de origen.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("sincrono", "Elegir directorio destino de sincronizacion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("sincrono", "Elegir directorio destino de sincronizacion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("sincrono", "Elegir directorio destino de sincronizacion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("sincrono", "Examinar destino", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("sincrono", "Ruta de destino.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QApplication::translate("sincrono", "Ruta de destino.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("sincrono", "Ruta de destino.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QString());
        label_4->setText(QString());
        groupBox_2->setTitle(QApplication::translate("sincrono", "Visualizar destino", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("sincrono", "Muestra todos los ficheros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_7->setStatusTip(QApplication::translate("sincrono", "Muestra todos los ficheros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_7->setWhatsThis(QApplication::translate("sincrono", "Muestra todos los ficheros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_7->setText(QApplication::translate("sincrono", "Todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_8->setToolTip(QApplication::translate("sincrono", "Filtra por los que no han sufrido cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_8->setStatusTip(QApplication::translate("sincrono", "Filtra por los que no han sufrido cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_8->setWhatsThis(QApplication::translate("sincrono", "Filtra por los que no han sufrido cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_8->setText(QApplication::translate("sincrono", "Iguales", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_4->setToolTip(QApplication::translate("sincrono", "Si esta seleccionada solo muestras los cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_4->setStatusTip(QApplication::translate("sincrono", "Si esta seleccionada solo muestras los cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_4->setWhatsThis(QApplication::translate("sincrono", "Si esta seleccionada solo muestras los cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_4->setText(QApplication::translate("sincrono", "Mostrar solo diferencias", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_5->setToolTip(QApplication::translate("sincrono", "Si esta sin seleccionar no se muestran los archivos que estan en destino y que no estan en origen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_5->setStatusTip(QApplication::translate("sincrono", "Si esta sin seleccionar no se muestran los archivos que estan en destino y que no estan en origen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_5->setWhatsThis(QApplication::translate("sincrono", "Si esta sin seleccionar no se muestran los archivos que estan en destino y que no estan en origen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_5->setText(QApplication::translate("sincrono", "Mostrar eliminados", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_9->setToolTip(QApplication::translate("sincrono", "Filtra por los que han sufrido cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_9->setStatusTip(QApplication::translate("sincrono", "Filtra por los que han sufrido cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_9->setWhatsThis(QApplication::translate("sincrono", "Filtra por los que han sufrido cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_9->setText(QApplication::translate("sincrono", "Cambios", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("sincrono", "Filtra por los archivos nuevos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("sincrono", "Filtra por los archivos nuevos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("sincrono", "Filtra por los archivos nuevos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("sincrono", "Nuevos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_13->setToolTip(QApplication::translate("sincrono", "Filtra por los ficheros eliminados o no encontrados en el directorio fuente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_13->setStatusTip(QApplication::translate("sincrono", "Filtra por los ficheros eliminados o no encontrados en el directorio fuente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_13->setWhatsThis(QApplication::translate("sincrono", "Filtra por los ficheros eliminados o no encontrados en el directorio fuente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_13->setText(QApplication::translate("sincrono", "Eliminados", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("sincrono", "Acciones", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_11->setToolTip(QApplication::translate("sincrono", "Insertar proyecto a la base de datos de sincronizaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_11->setStatusTip(QApplication::translate("sincrono", "Insertar proyecto a la base de datos de sincronizaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_11->setWhatsThis(QApplication::translate("sincrono", "Insertar proyecto a la base de datos de sincronizaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_11->setText(QApplication::translate("sincrono", "Insertar proyecto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QApplication::translate("sincrono", "Modificar proyecto a la base de datos de sincronizaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_10->setStatusTip(QApplication::translate("sincrono", "Modificar proyecto a la base de datos de sincronizaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_10->setWhatsThis(QApplication::translate("sincrono", "Modificar proyecto a la base de datos de sincronizaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_10->setText(QApplication::translate("sincrono", "Modificar proyecto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_12->setToolTip(QApplication::translate("sincrono", "Eliminar proyecto a la base de datos de sincronizaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_12->setStatusTip(QApplication::translate("sincrono", "Eliminar proyecto a la base de datos de sincronizaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_12->setWhatsThis(QApplication::translate("sincrono", "Eliminar proyecto a la base de datos de sincronizaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_12->setText(QApplication::translate("sincrono", "Eliminar proyecto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("sincrono", "Analizar el directorio fuente en busca de cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("sincrono", "Analizar el directorio fuente en busca de cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("sincrono", "Analizar el directorio fuente en busca de cambios", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("sincrono", "Analizar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("sincrono", "Sincronizar los cambios localizados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("sincrono", "Sincronizar los cambios localizados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("sincrono", "Sincronizar los cambios localizados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QApplication::translate("sincrono", "Sincronizar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("sincrono", "Parar los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_6->setStatusTip(QApplication::translate("sincrono", "Parar los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_6->setWhatsThis(QApplication::translate("sincrono", "Parar los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_6->setText(QApplication::translate("sincrono", "Parar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("sincrono", "Eliminar en la sincronizacion los archivos no localizados en el directorio fuente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox->setStatusTip(QApplication::translate("sincrono", "Eliminar en la sincronizacion los archivos no localizados en el directorio fuente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox->setWhatsThis(QApplication::translate("sincrono", "Eliminar en la sincronizacion los archivos no localizados en el directorio fuente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox->setText(QApplication::translate("sincrono", "Quitar eliminados en destino", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_2->setToolTip(QApplication::translate("sincrono", "Guarda de forma oculta la ultima modificacion para poder recuperarla en caso necesario", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_2->setStatusTip(QApplication::translate("sincrono", "Guarda de forma oculta la ultima modificacion para poder recuperarla en caso necesario", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_2->setWhatsThis(QApplication::translate("sincrono", "Guarda de forma oculta la ultima modificacion para poder recuperarla en caso necesario", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_2->setText(QApplication::translate("sincrono", "Guardar ultimo cambio", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class sincrono: public Ui_sincrono {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINCRONO_H
