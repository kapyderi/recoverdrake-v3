/********************************************************************************
** Form generated from reading UI file 'convaudio.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVAUDIO_H
#define UI_CONVAUDIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>
#include <phonon/seekslider.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_ConvAudio
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_22;
    QGridLayout *gridLayout_21;
    QTableWidget *tableWidget_2;
    QProgressBar *progressBar_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_24;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_27;
    QPushButton *pushButton_9;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_12;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_18;
    QComboBox *comboBox_7;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_20;
    QPushButton *pushButton_18;
    QPushButton *pushButton_25;
    QPushButton *pushButton_26;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_19;
    QPushButton *pushButton_11;
    QPushButton *pushButton_22;
    QPushButton *pushButton_23;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_17;
    QComboBox *comboBox_6;
    Phonon::VolumeSlider *volumeSlider_4;
    QPushButton *pushButton_14;
    QLCDNumber *lcdNumber_2;
    Phonon::SeekSlider *seekSlider_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit;

    void setupUi(QDialog *ConvAudio)
    {
        if (ConvAudio->objectName().isEmpty())
            ConvAudio->setObjectName(QString::fromUtf8("ConvAudio"));
        ConvAudio->resize(937, 596);
        QFont font;
        font.setPointSize(7);
        ConvAudio->setFont(font);
        gridLayout_2 = new QGridLayout(ConvAudio);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea = new QScrollArea(ConvAudio);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 898, 631));
        gridLayout_22 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_21 = new QGridLayout();
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        tableWidget_2 = new QTableWidget(scrollAreaWidgetContents_3);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setIcon(icon);
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/audio.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setIcon(icon1);
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setMinimumSize(QSize(640, 232));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        tableWidget_2->setFont(font1);
        tableWidget_2->setAutoScrollMargin(26);
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->setDragEnabled(true);
        tableWidget_2->setAlternatingRowColors(true);
        tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_2->setSortingEnabled(true);
        tableWidget_2->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget_2->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);
        tableWidget_2->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(25);
        tableWidget_2->verticalHeader()->setMinimumSectionSize(25);
        tableWidget_2->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget_2->verticalHeader()->setStretchLastSection(true);

        gridLayout_21->addWidget(tableWidget_2, 0, 0, 1, 5);

        progressBar_2 = new QProgressBar(scrollAreaWidgetContents_3);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setMinimumSize(QSize(570, 23));
        progressBar_2->setValue(0);

        gridLayout_21->addWidget(progressBar_2, 3, 0, 1, 5);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(51, 20));
        lineEdit_3->setMaximumSize(QSize(61, 20));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        lineEdit_3->setFont(font2);
        lineEdit_3->setLayoutDirection(Qt::LeftToRight);
        lineEdit_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_21->addWidget(lineEdit_3, 1, 2, 1, 1);

        pushButton_24 = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));
        pushButton_24->setMinimumSize(QSize(131, 0));
        pushButton_24->setMaximumSize(QSize(181, 25));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/lupaO.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_24->setIcon(icon2);

        gridLayout_21->addWidget(pushButton_24, 1, 4, 1, 1);

        label_2 = new QLabel(scrollAreaWidgetContents_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font3;
        font3.setPointSize(7);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);

        gridLayout_21->addWidget(label_2, 1, 1, 1, 1);

        textEdit_2 = new QTextEdit(scrollAreaWidgetContents_3);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setEnabled(true);
        textEdit_2->setMaximumSize(QSize(16777215, 297));
        textEdit_2->setSizeIncrement(QSize(0, 0));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Nimbus Sans L Condensed"));
        font4.setPointSize(8);
        textEdit_2->setFont(font4);
        textEdit_2->setFocusPolicy(Qt::TabFocus);
        textEdit_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_21->addWidget(textEdit_2, 4, 0, 1, 5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_21->addItem(horizontalSpacer_3, 1, 3, 1, 1);

        pushButton_27 = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_27->setIcon(icon3);

        gridLayout_21->addWidget(pushButton_27, 5, 1, 1, 1);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon4);

        gridLayout_21->addWidget(pushButton_9, 5, 2, 1, 1);

        groupBox_9 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_9->sizePolicy().hasHeightForWidth());
        groupBox_9->setSizePolicy(sizePolicy);
        groupBox_9->setMaximumSize(QSize(201, 16777215));
        gridLayout_12 = new QGridLayout(groupBox_9);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        pushButton_13 = new QPushButton(groupBox_9);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon5);

        gridLayout_12->addWidget(pushButton_13, 7, 1, 1, 1);

        pushButton_12 = new QPushButton(groupBox_9);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon6);

        gridLayout_12->addWidget(pushButton_12, 7, 0, 1, 1);

        groupBox_13 = new QGroupBox(groupBox_9);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        gridLayout_18 = new QGridLayout(groupBox_13);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        comboBox_7 = new QComboBox(groupBox_13);
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));

        gridLayout_18->addWidget(comboBox_7, 0, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_13, 1, 0, 1, 2);

        groupBox_15 = new QGroupBox(groupBox_9);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        gridLayout_20 = new QGridLayout(groupBox_15);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        pushButton_18 = new QPushButton(groupBox_15);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setMaximumSize(QSize(181, 25));
        pushButton_18->setIcon(icon);

        gridLayout_20->addWidget(pushButton_18, 0, 0, 1, 1);

        pushButton_25 = new QPushButton(groupBox_15);
        pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));
        pushButton_25->setMinimumSize(QSize(131, 0));
        pushButton_25->setMaximumSize(QSize(181, 25));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_25->setIcon(icon7);

        gridLayout_20->addWidget(pushButton_25, 1, 0, 1, 1);

        pushButton_26 = new QPushButton(groupBox_15);
        pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));
        pushButton_26->setMinimumSize(QSize(131, 0));
        pushButton_26->setMaximumSize(QSize(181, 25));
        pushButton_26->setIcon(icon7);

        gridLayout_20->addWidget(pushButton_26, 2, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_15, 5, 0, 1, 2);

        groupBox_14 = new QGroupBox(groupBox_9);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        gridLayout_19 = new QGridLayout(groupBox_14);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        pushButton_11 = new QPushButton(groupBox_14);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(131, 0));
        pushButton_11->setMaximumSize(QSize(181, 25));
        pushButton_11->setIcon(icon1);

        gridLayout_19->addWidget(pushButton_11, 4, 0, 1, 1);

        pushButton_22 = new QPushButton(groupBox_14);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        pushButton_22->setMinimumSize(QSize(131, 0));
        pushButton_22->setMaximumSize(QSize(181, 25));
        pushButton_22->setIcon(icon);

        gridLayout_19->addWidget(pushButton_22, 2, 0, 1, 1);

        pushButton_23 = new QPushButton(groupBox_14);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        pushButton_23->setMinimumSize(QSize(131, 0));
        pushButton_23->setMaximumSize(QSize(181, 25));
        pushButton_23->setIcon(icon7);

        gridLayout_19->addWidget(pushButton_23, 3, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_14, 4, 0, 1, 2);

        groupBox_12 = new QGroupBox(groupBox_9);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        gridLayout_17 = new QGridLayout(groupBox_12);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        comboBox_6 = new QComboBox(groupBox_12);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));

        gridLayout_17->addWidget(comboBox_6, 0, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_12, 0, 0, 1, 2);

        volumeSlider_4 = new Phonon::VolumeSlider(groupBox_9);
        volumeSlider_4->setObjectName(QString::fromUtf8("volumeSlider_4"));

        gridLayout_12->addWidget(volumeSlider_4, 9, 0, 1, 1);

        pushButton_14 = new QPushButton(groupBox_9);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/stop1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon8);

        gridLayout_12->addWidget(pushButton_14, 8, 0, 1, 1);

        lcdNumber_2 = new QLCDNumber(groupBox_9);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setMinimumSize(QSize(88, 23));
        lcdNumber_2->setMaximumSize(QSize(122, 23));
        lcdNumber_2->setFont(font);
        lcdNumber_2->setFrameShape(QFrame::Box);
        lcdNumber_2->setFrameShadow(QFrame::Sunken);
        lcdNumber_2->setLineWidth(1);
        lcdNumber_2->setSmallDecimalPoint(true);
        lcdNumber_2->setDigitCount(8);
        lcdNumber_2->setMode(QLCDNumber::Dec);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_2->setProperty("value", QVariant(0));
        lcdNumber_2->setProperty("intValue", QVariant(0));

        gridLayout_12->addWidget(lcdNumber_2, 9, 1, 1, 1);

        seekSlider_2 = new Phonon::SeekSlider(groupBox_9);
        seekSlider_2->setObjectName(QString::fromUtf8("seekSlider_2"));
        seekSlider_2->setMaximumSize(QSize(16777215, 20));

        gridLayout_12->addWidget(seekSlider_2, 6, 0, 1, 2);

        pushButton_10 = new QPushButton(groupBox_9);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(135, 0));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Imagenes/exaile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon9);

        gridLayout_12->addWidget(pushButton_10, 3, 0, 1, 2);

        pushButton = new QPushButton(groupBox_9);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Imagenes/sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon10);

        gridLayout_12->addWidget(pushButton, 10, 0, 1, 2);


        gridLayout_21->addWidget(groupBox_9, 0, 5, 6, 1);

        groupBox = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMaximumSize(QSize(25, 16777215));

        gridLayout->addWidget(pushButton_8, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);


        gridLayout_21->addWidget(groupBox, 2, 1, 1, 4);


        gridLayout_22->addLayout(gridLayout_21, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_3);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(ConvAudio);

        QMetaObject::connectSlotsByName(ConvAudio);
    } // setupUi

    void retranslateUi(QDialog *ConvAudio)
    {
        ConvAudio->setWindowTitle(QApplication::translate("ConvAudio", "Conversion de Audio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ConvAudio", "Marca", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ConvAudio", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ConvAudio", "Ruta", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ConvAudio", "Formato de salida", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget_2->setToolTip(QApplication::translate("ConvAudio", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget_2->setStatusTip(QApplication::translate("ConvAudio", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget_2->setWhatsThis(QApplication::translate("ConvAudio", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        progressBar_2->setToolTip(QApplication::translate("ConvAudio", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        progressBar_2->setStatusTip(QApplication::translate("ConvAudio", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        progressBar_2->setWhatsThis(QApplication::translate("ConvAudio", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_3->setToolTip(QApplication::translate("ConvAudio", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_3->setStatusTip(QApplication::translate("ConvAudio", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_3->setWhatsThis(QApplication::translate("ConvAudio", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_24->setToolTip(QApplication::translate("ConvAudio", "Capturar fichero de video", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_24->setStatusTip(QApplication::translate("ConvAudio", "Capturar fichero de video", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_24->setWhatsThis(QApplication::translate("ConvAudio", "Comprobacion de las actualizaciones disponibles.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_24->setText(QApplication::translate("ConvAudio", "Insertar ficheros de audio", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConvAudio", "Total Registros:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textEdit_2->setToolTip(QApplication::translate("ConvAudio", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit_2->setStatusTip(QApplication::translate("ConvAudio", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit_2->setWhatsThis(QApplication::translate("ConvAudio", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        textEdit_2->setHtml(QApplication::translate("ConvAudio", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Nimbus Sans L Condensed'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:7pt; font-weight:600;\"><br /></span></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_27->setToolTip(QApplication::translate("ConvAudio", "Cancela los procesos activos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_27->setStatusTip(QApplication::translate("ConvAudio", "Cancela los procesos activos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_27->setWhatsThis(QApplication::translate("ConvAudio", "Cancela los procesos activos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_27->setText(QApplication::translate("ConvAudio", "Cancelar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_9->setToolTip(QApplication::translate("ConvAudio", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_9->setStatusTip(QApplication::translate("ConvAudio", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_9->setWhatsThis(QApplication::translate("ConvAudio", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_9->setText(QApplication::translate("ConvAudio", "Salir", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("ConvAudio", "Configuracion de salida", 0, QApplication::UnicodeUTF8));
        pushButton_13->setText(QApplication::translate("ConvAudio", "Pausa", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("ConvAudio", "Play", 0, QApplication::UnicodeUTF8));
        groupBox_13->setTitle(QApplication::translate("ConvAudio", "Calidad", 0, QApplication::UnicodeUTF8));
        comboBox_7->clear();
        comboBox_7->insertItems(0, QStringList()
         << QApplication::translate("ConvAudio", "128kbs", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConvAudio", "192kbs", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConvAudio", "320kbs", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_7->setToolTip(QApplication::translate("ConvAudio", "Tipo de resolucion seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox_7->setStatusTip(QApplication::translate("ConvAudio", "Tipo de resolucion seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox_7->setWhatsThis(QApplication::translate("ConvAudio", "Tipo de resolucion seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_15->setTitle(QApplication::translate("ConvAudio", "Acceso individual", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_18->setToolTip(QApplication::translate("ConvAudio", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_18->setStatusTip(QApplication::translate("ConvAudio", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_18->setWhatsThis(QApplication::translate("ConvAudio", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_18->setText(QApplication::translate("ConvAudio", "Marcar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_25->setToolTip(QApplication::translate("ConvAudio", "Desmarca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_25->setStatusTip(QApplication::translate("ConvAudio", "Desmarca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_25->setWhatsThis(QApplication::translate("ConvAudio", "Desmarca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_25->setText(QApplication::translate("ConvAudio", "Desmarcar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_26->setToolTip(QApplication::translate("ConvAudio", "Elimina todos los registros seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_26->setStatusTip(QApplication::translate("ConvAudio", "Elimina todos los registros seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_26->setWhatsThis(QApplication::translate("ConvAudio", "Elimina todos los registros seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_26->setText(QApplication::translate("ConvAudio", "Eliminar seleccionados", 0, QApplication::UnicodeUTF8));
        groupBox_14->setTitle(QApplication::translate("ConvAudio", "Acceso global", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_11->setToolTip(QApplication::translate("ConvAudio", "Convertir todos los archivos activados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_11->setStatusTip(QApplication::translate("ConvAudio", "Convertir todos los archivos activados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_11->setWhatsThis(QApplication::translate("ConvAudio", "Convertir todos los archivos activados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_11->setText(QApplication::translate("ConvAudio", "Convertir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_22->setToolTip(QApplication::translate("ConvAudio", "Seleccion masiva de todos los archivos capturados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_22->setStatusTip(QApplication::translate("ConvAudio", "Seleccion masiva de todos los archivos capturados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_22->setWhatsThis(QApplication::translate("ConvAudio", "Seleccion masiva de todos los archivos capturados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_22->setText(QApplication::translate("ConvAudio", "Seleccionar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_23->setToolTip(QApplication::translate("ConvAudio", "Deseleccion masiva de todos los archivos capturados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_23->setStatusTip(QApplication::translate("ConvAudio", "Deseleccion masiva de todos los archivos capturados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_23->setWhatsThis(QApplication::translate("ConvAudio", "Deseleccion masiva de todos los archivos capturados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_23->setText(QApplication::translate("ConvAudio", "Deseleccionar todos", 0, QApplication::UnicodeUTF8));
        groupBox_12->setTitle(QApplication::translate("ConvAudio", "Audio", 0, QApplication::UnicodeUTF8));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("ConvAudio", "mp3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConvAudio", "pcm", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConvAudio", "ac3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConvAudio", "aac", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConvAudio", "mp2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConvAudio", "wav", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConvAudio", "wma", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_6->setToolTip(QApplication::translate("ConvAudio", "Tipo de audio seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox_6->setStatusTip(QApplication::translate("ConvAudio", "Tipo de audio seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox_6->setWhatsThis(QApplication::translate("ConvAudio", "Tipo de audio seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_14->setText(QApplication::translate("ConvAudio", "Stop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QApplication::translate("ConvAudio", "Insertar parametros de salida a proyectos seleccionado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_10->setStatusTip(QApplication::translate("ConvAudio", "Insertar parametros de salida a proyectos seleccionado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_10->setWhatsThis(QApplication::translate("ConvAudio", "Insertar parametros de salida a proyectos seleccionado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        pushButton_10->setAccessibleName(QApplication::translate("ConvAudio", "Insertar parametros de salida a proyectos seleccionado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        pushButton_10->setText(QApplication::translate("ConvAudio", "Insertar a proyecto activo", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ConvAudio", "Ecualizador", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ConvAudio", "Ruta de salida", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("ConvAudio", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConvAudio: public Ui_ConvAudio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVAUDIO_H
