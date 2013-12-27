/********************************************************************************
** Form generated from reading UI file 'orphans.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORPHANS_H
#define UI_ORPHANS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
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

class Ui_orphans
{
public:
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QTextEdit *textEdit;
    QGridLayout *gridLayout_3;
    QProgressBar *progressBar;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_14;
    QPushButton *pushButton;
    QFrame *line;
    QPushButton *pushButton_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_11;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *orphans)
    {
        if (orphans->objectName().isEmpty())
            orphans->setObjectName(QString::fromUtf8("orphans"));
        orphans->resize(710, 569);
        QFont font;
        font.setPointSize(7);
        orphans->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/huerfano.png"), QSize(), QIcon::Normal, QIcon::Off);
        orphans->setWindowIcon(icon);
        orphans->setStyleSheet(QString::fromUtf8(""));
        gridLayout_6 = new QGridLayout(orphans);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tableWidget = new QTableWidget(orphans);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setIcon(icon1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/rpm.png"), QSize(), QIcon::Normal, QIcon::Off);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::Dense4Pattern);
        QFont font1;
        font1.setPointSize(9);
        font1.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem1->setFont(font1);
        __qtablewidgetitem1->setForeground(brush);
        __qtablewidgetitem1->setIcon(icon2);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        tableWidget->setFont(font2);
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

        gridLayout_5->addWidget(tableWidget, 0, 0, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(269, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        label = new QLabel(orphans);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(93, 20));
        QFont font3;
        font3.setPointSize(7);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);

        gridLayout_5->addWidget(label, 1, 1, 1, 1);

        lineEdit_2 = new QLineEdit(orphans);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(50, 50));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setWeight(75);
        lineEdit_2->setFont(font4);
        lineEdit_2->setLayoutDirection(Qt::LeftToRight);
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lineEdit_2, 1, 2, 1, 1);

        textEdit = new QTextEdit(orphans);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setMaximumSize(QSize(16777215, 234));
        textEdit->setSizeIncrement(QSize(0, 0));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Nimbus Sans L Condensed"));
        font5.setPointSize(8);
        textEdit->setFont(font5);
        textEdit->setFocusPolicy(Qt::TabFocus);
        textEdit->setStyleSheet(QString::fromUtf8(""));

        gridLayout_5->addWidget(textEdit, 2, 0, 1, 3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        progressBar = new QProgressBar(orphans);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_3->addWidget(progressBar, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(orphans);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(201, 26));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 3, 0, 1, 3);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_2 = new QGroupBox(orphans);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(131, 0));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon4);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_3, 6, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(131, 0));
        pushButton_6->setIcon(icon1);
        pushButton_6->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_6, 4, 0, 1, 1);

        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(131, 0));
        pushButton_7->setIcon(icon4);
        pushButton_7->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_7, 5, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(131, 0));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon5);
        pushButton_5->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/escoba.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon6);
        pushButton_8->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_8, 7, 0, 1, 1);

        pushButton_14 = new QPushButton(groupBox_2);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/lupaO.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon7);
        pushButton_14->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_14, 0, 0, 1, 1);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon8);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton, 10, 0, 1, 1);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 8, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(131, 0));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Imagenes/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon9);
        pushButton_4->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_4, 9, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(orphans);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(131, 0));
        pushButton_10->setIcon(icon1);
        pushButton_10->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_10, 0, 0, 1, 2);

        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(131, 0));
        pushButton_12->setIcon(icon4);
        pushButton_12->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_12, 3, 0, 1, 2);

        pushButton_13 = new QPushButton(groupBox);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(131, 0));
        pushButton_13->setIcon(icon4);
        pushButton_13->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_13, 5, 0, 1, 2);

        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(131, 0));
        pushButton_11->setIcon(icon4);
        pushButton_11->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_11, 4, 0, 1, 2);


        gridLayout_4->addWidget(groupBox, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_4, 0, 1, 1, 1);


        retranslateUi(orphans);

        QMetaObject::connectSlotsByName(orphans);
    } // setupUi

    void retranslateUi(QDialog *orphans)
    {
        orphans->setWindowTitle(QApplication::translate("orphans", "Mantenimiento de paquetes huerfanos", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("orphans", "Marca", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("orphans", "Nombre de paquete huerfano", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QApplication::translate("orphans", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget->setStatusTip(QApplication::translate("orphans", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget->setWhatsThis(QApplication::translate("orphans", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("orphans", "Total Registros:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("orphans", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QApplication::translate("orphans", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("orphans", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("orphans", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit->setStatusTip(QApplication::translate("orphans", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QApplication::translate("orphans", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        textEdit->setHtml(QApplication::translate("orphans", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Nimbus Sans L Condensed'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans Serif'; font-size:7pt; font-weight:600;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        progressBar->setToolTip(QApplication::translate("orphans", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        progressBar->setStatusTip(QApplication::translate("orphans", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        progressBar->setWhatsThis(QApplication::translate("orphans", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("orphans", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("orphans", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("orphans", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("orphans", "Salir", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("orphans", "Acceso global", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("orphans", "Actualizacion de los paquetes seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("orphans", "Deseleccion masiva de todos los registros.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("orphans", "Deseleccion masiva de todos los registros.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        pushButton_3->setAccessibleName(QApplication::translate("orphans", "Deseleccion masiva de todos los registros.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        pushButton_3->setText(QApplication::translate("orphans", "Eliminar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("orphans", "Seleccion masiva de todos los paquetes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_6->setStatusTip(QApplication::translate("orphans", "Seleccion masiva de todos los paquetes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_6->setWhatsThis(QApplication::translate("orphans", "Seleccion masiva de todos los paquetes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_6->setText(QApplication::translate("orphans", "Seleccionar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("orphans", "Deseleccion masiva de todos los paquetes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_7->setStatusTip(QApplication::translate("orphans", "Deseleccion masiva de todos los paquetes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_7->setWhatsThis(QApplication::translate("orphans", "Deseleccion masiva de todos los paquetes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_7->setText(QApplication::translate("orphans", "Deseleccionar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("orphans", "Generar un fichero .lst tanto de la carga de otro fichero tras depurarlo, como de la generaci\303\263n de paquete huerfanos activos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("orphans", "Generar un fichero .lst tanto de la carga de otro fichero tras depurarlo, como de la generaci\303\263n de paquete huerfanos activos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("orphans", "Generar un fichero .lst tanto de la carga de otro fichero tras depurarlo, como de la generaci\303\263n de paquete huerfanos activos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        pushButton_5->setAccessibleName(QApplication::translate("orphans", "Generar un fichero .lst tanto de la carga de otro fichero tras depurarlo, como de la generaci\303\263n de paquete huerfanos activos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        pushButton_5->setText(QApplication::translate("orphans", "Generar fichero", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_8->setToolTip(QApplication::translate("orphans", "Limpia la ventana de registros.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_8->setStatusTip(QApplication::translate("orphans", "Limpia la ventana de registros.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_8->setWhatsThis(QApplication::translate("orphans", "Limpia la ventana de registros.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_8->setText(QApplication::translate("orphans", "Limpiar/Vaciar lista", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_14->setToolTip(QApplication::translate("orphans", "Comprobacion de los paquetes huefanos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_14->setStatusTip(QApplication::translate("orphans", "Comprobacion de los paquetes huefanos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_14->setWhatsThis(QApplication::translate("orphans", "Comprobacion de los paquetes huefanos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_14->setText(QApplication::translate("orphans", "Verificar huerfanos", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("orphans", "Recuperar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("orphans", "Carga de fichero de una salvaguarda anterior para poder instalar, depurar o modificar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("orphans", "Carga de fichero de una salvaguarda anterior para poder instalar, depurar o modificar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("orphans", "Carga de fichero de una salvaguarda anterior para poder instalar, depurar o modificar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("orphans", "Cargar fichero", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("orphans", "Acceso individual", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QApplication::translate("orphans", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_10->setStatusTip(QApplication::translate("orphans", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_10->setWhatsThis(QApplication::translate("orphans", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_10->setText(QApplication::translate("orphans", "Marcar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_12->setToolTip(QApplication::translate("orphans", "Desmarca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_12->setStatusTip(QApplication::translate("orphans", "Desmarca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_12->setWhatsThis(QApplication::translate("orphans", "Desmarca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_12->setText(QApplication::translate("orphans", "Desmarcar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_13->setToolTip(QApplication::translate("orphans", "Elimina todos los registros seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_13->setStatusTip(QApplication::translate("orphans", "Elimina todos los registros seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_13->setWhatsThis(QApplication::translate("orphans", "Elimina todos los registros seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_13->setText(QApplication::translate("orphans", "Eliminar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_11->setToolTip(QApplication::translate("orphans", "Quita de la lista el registro seleccionado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_11->setStatusTip(QApplication::translate("orphans", "Quita de la lista el registro seleccionado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_11->setWhatsThis(QApplication::translate("orphans", "Quita de la lista el registro seleccionado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_11->setText(QApplication::translate("orphans", "Quitar seleccionado", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class orphans: public Ui_orphans {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORPHANS_H
