/********************************************************************************
** Form generated from reading UI file 'conversor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERSOR_H
#define UI_CONVERSOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
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
#include <phonon/videoplayer.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_Conversor
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_13;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_15;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QGridLayout *gridLayout_11;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QGridLayout *gridLayout_16;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_17;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_21;
    QPushButton *pushButton_20;
    QProgressBar *progressBar;
    QPushButton *pushButton_7;
    QPushButton *pushButton_19;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_14;
    QLineEdit *lineEdit;
    QPushButton *pushButton_8;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_10;
    Phonon::VolumeSlider *volumeSlider_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QLCDNumber *lcdNumber;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QComboBox *comboBox;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    Phonon::VideoPlayer *videoPlayer;
    Phonon::SeekSlider *seekSlider;
    QPushButton *pushButton;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_7;
    QComboBox *comboBox_4;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_8;
    QComboBox *comboBox_5;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QComboBox *comboBox_2;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_5;
    QComboBox *comboBox_3;

    void setupUi(QDialog *Conversor)
    {
        if (Conversor->objectName().isEmpty())
            Conversor->setObjectName(QString::fromUtf8("Conversor"));
        Conversor->resize(973, 659);
        QFont font;
        font.setPointSize(7);
        Conversor->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/totem-2-24-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        Conversor->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(Conversor);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        scrollArea = new QScrollArea(Conversor);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 951, 637));
        gridLayout_13 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        groupBox_10 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_10->sizePolicy().hasHeightForWidth());
        groupBox_10->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox_10);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        tableWidget = new QTableWidget(groupBox_10);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setIcon(icon1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/Video.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setIcon(icon2);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        tableWidget->setFont(font1);
        tableWidget->setAutoScrollMargin(26);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setDragEnabled(true);
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

        gridLayout_15->addWidget(tableWidget, 0, 0, 1, 4);

        pushButton_2 = new QPushButton(groupBox_10);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);

        gridLayout_15->addWidget(pushButton_2, 8, 3, 1, 1);

        textEdit = new QTextEdit(groupBox_10);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setSizeIncrement(QSize(0, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nimbus Sans L Condensed"));
        font2.setPointSize(8);
        textEdit->setFont(font2);
        textEdit->setFocusPolicy(Qt::TabFocus);

        gridLayout_15->addWidget(textEdit, 4, 0, 1, 4);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer, 0, 4, 1, 2);

        lineEdit_2 = new QLineEdit(groupBox_10);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMinimumSize(QSize(51, 20));
        lineEdit_2->setMaximumSize(QSize(61, 20));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setWeight(75);
        lineEdit_2->setFont(font3);
        lineEdit_2->setLayoutDirection(Qt::LeftToRight);
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(lineEdit_2, 0, 1, 1, 1);

        label = new QLabel(groupBox_10);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font4;
        font4.setPointSize(7);
        font4.setBold(true);
        font4.setWeight(75);
        label->setFont(font4);

        gridLayout_11->addWidget(label, 0, 0, 1, 1);


        gridLayout_15->addLayout(gridLayout_11, 1, 0, 1, 1);

        gridLayout_16 = new QGridLayout();
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        groupBox = new QGroupBox(groupBox_10);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_9 = new QGridLayout(groupBox);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        pushButton_15 = new QPushButton(groupBox);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setIcon(icon1);

        gridLayout_9->addWidget(pushButton_15, 0, 0, 1, 1);

        pushButton_16 = new QPushButton(groupBox);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon4);

        gridLayout_9->addWidget(pushButton_16, 1, 0, 1, 1);

        pushButton_17 = new QPushButton(groupBox);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setIcon(icon4);

        gridLayout_9->addWidget(pushButton_17, 2, 0, 1, 1);


        gridLayout_16->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(groupBox_10);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/audio_video.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon5);

        gridLayout_6->addWidget(pushButton_4, 4, 0, 1, 1);

        pushButton_21 = new QPushButton(groupBox_2);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setIcon(icon4);

        gridLayout_6->addWidget(pushButton_21, 3, 0, 1, 1);

        pushButton_20 = new QPushButton(groupBox_2);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setIcon(icon1);

        gridLayout_6->addWidget(pushButton_20, 2, 0, 1, 1);


        gridLayout_16->addWidget(groupBox_2, 0, 2, 1, 1);


        gridLayout_15->addLayout(gridLayout_16, 7, 0, 2, 1);

        progressBar = new QProgressBar(groupBox_10);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_15->addWidget(progressBar, 3, 0, 1, 4);

        pushButton_7 = new QPushButton(groupBox_10);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon6);

        gridLayout_15->addWidget(pushButton_7, 8, 2, 1, 1);

        pushButton_19 = new QPushButton(groupBox_10);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/lupaO.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon7);

        gridLayout_15->addWidget(pushButton_19, 1, 2, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_2, 8, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_4, 7, 1, 1, 3);

        groupBox_11 = new QGroupBox(groupBox_10);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        gridLayout_14 = new QGridLayout(groupBox_11);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        lineEdit = new QLineEdit(groupBox_11);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_14->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton_8 = new QPushButton(groupBox_11);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMaximumSize(QSize(25, 16777215));

        gridLayout_14->addWidget(pushButton_8, 0, 0, 1, 1);


        gridLayout_15->addWidget(groupBox_11, 2, 0, 1, 4);


        gridLayout->addLayout(gridLayout_15, 0, 0, 1, 1);


        gridLayout_13->addWidget(groupBox_10, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy2);
        groupBox_3->setMaximumSize(QSize(233, 16777215));
        gridLayout_10 = new QGridLayout(groupBox_3);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        volumeSlider_2 = new Phonon::VolumeSlider(groupBox_3);
        volumeSlider_2->setObjectName(QString::fromUtf8("volumeSlider_2"));

        gridLayout_10->addWidget(volumeSlider_2, 13, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/stop1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon8);

        gridLayout_10->addWidget(pushButton_3, 12, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Imagenes/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon9);

        gridLayout_10->addWidget(pushButton_6, 12, 1, 1, 1);

        lcdNumber = new QLCDNumber(groupBox_3);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(88, 23));
        lcdNumber->setMaximumSize(QSize(122, 23));
        lcdNumber->setFont(font);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Sunken);
        lcdNumber->setLineWidth(1);
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setDigitCount(8);
        lcdNumber->setMode(QLCDNumber::Dec);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(0));
        lcdNumber->setProperty("intValue", QVariant(0));

        gridLayout_10->addWidget(lcdNumber, 13, 1, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(groupBox_4);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_4->addWidget(comboBox, 0, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_4, 0, 0, 1, 2);

        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Imagenes/exaile.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon10);

        gridLayout_10->addWidget(pushButton_5, 6, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer, 7, 0, 1, 1);

        line = new QFrame(groupBox_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_10->addWidget(line, 8, 0, 1, 2);

        videoPlayer = new Phonon::VideoPlayer(groupBox_3);
        videoPlayer->setObjectName(QString::fromUtf8("videoPlayer"));
        videoPlayer->setMinimumSize(QSize(0, 100));
        videoPlayer->setMaximumSize(QSize(16777215, 100));
        videoPlayer->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout_10->addWidget(videoPlayer, 9, 0, 1, 2);

        seekSlider = new Phonon::SeekSlider(groupBox_3);
        seekSlider->setObjectName(QString::fromUtf8("seekSlider"));
        seekSlider->setMaximumSize(QSize(16777215, 25));

        gridLayout_10->addWidget(seekSlider, 10, 0, 1, 2);

        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Imagenes/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon11);

        gridLayout_10->addWidget(pushButton, 11, 0, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_7 = new QGridLayout(groupBox_7);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        comboBox_4 = new QComboBox(groupBox_7);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));

        gridLayout_7->addWidget(comboBox_4, 0, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_7, 3, 0, 1, 2);

        groupBox_8 = new QGroupBox(groupBox_3);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_8 = new QGridLayout(groupBox_8);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        comboBox_5 = new QComboBox(groupBox_8);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));

        gridLayout_8->addWidget(comboBox_5, 0, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_8, 4, 0, 1, 2);

        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_3 = new QGridLayout(groupBox_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        comboBox_2 = new QComboBox(groupBox_5);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_3->addWidget(comboBox_2, 0, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_5, 1, 0, 1, 2);

        groupBox_6 = new QGroupBox(groupBox_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_5 = new QGridLayout(groupBox_6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBox_3 = new QComboBox(groupBox_6);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        gridLayout_5->addWidget(comboBox_3, 0, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_6, 2, 0, 1, 2);


        gridLayout_13->addWidget(groupBox_3, 0, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Conversor);

        QMetaObject::connectSlotsByName(Conversor);
    } // setupUi

    void retranslateUi(QDialog *Conversor)
    {
        Conversor->setWindowTitle(QApplication::translate("Conversor", "Conversion de Video", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("Conversor", "Datos de conversion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Conversor", "Marca", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Conversor", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Conversor", "Ruta", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Conversor", "Configuracion de salida", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QApplication::translate("Conversor", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget->setStatusTip(QApplication::translate("Conversor", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget->setWhatsThis(QApplication::translate("Conversor", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("Conversor", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("Conversor", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("Conversor", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("Conversor", "Salir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("Conversor", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit->setStatusTip(QApplication::translate("Conversor", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QApplication::translate("Conversor", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("Conversor", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QApplication::translate("Conversor", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("Conversor", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("Conversor", "Total Registros:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Conversor", "Acceso individual", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_15->setToolTip(QApplication::translate("Conversor", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_15->setStatusTip(QApplication::translate("Conversor", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_15->setWhatsThis(QApplication::translate("Conversor", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_15->setText(QApplication::translate("Conversor", "Marcar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_16->setToolTip(QApplication::translate("Conversor", "Desmarca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_16->setStatusTip(QApplication::translate("Conversor", "Desmarca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_16->setWhatsThis(QApplication::translate("Conversor", "Desmarca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_16->setText(QApplication::translate("Conversor", "Desmarcar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_17->setToolTip(QApplication::translate("Conversor", "Elimina todos los registros seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_17->setStatusTip(QApplication::translate("Conversor", "Elimina todos los registros seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_17->setWhatsThis(QApplication::translate("Conversor", "Elimina todos los registros seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_17->setText(QApplication::translate("Conversor", "Eliminar seleccionados", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Conversor", "Acceso global", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("Conversor", "Convertir todos los archivos activados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("Conversor", "Convertir todos los archivos activados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("Conversor", "Convertir todos los archivos activados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("Conversor", "Convertir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_21->setToolTip(QApplication::translate("Conversor", "Deseleccion masiva de todos los archivos capturados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_21->setStatusTip(QApplication::translate("Conversor", "Deseleccion masiva de todos los archivos capturados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_21->setWhatsThis(QApplication::translate("Conversor", "Deseleccion masiva de todos los archivos capturados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_21->setText(QApplication::translate("Conversor", "Deseleccionar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_20->setToolTip(QApplication::translate("Conversor", "Seleccion masiva de todos los archivos capturados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_20->setStatusTip(QApplication::translate("Conversor", "Seleccion masiva de todos los archivos capturados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_20->setWhatsThis(QApplication::translate("Conversor", "Seleccion masiva de todos los archivos capturados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_20->setText(QApplication::translate("Conversor", "Seleccionar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        progressBar->setToolTip(QApplication::translate("Conversor", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        progressBar->setStatusTip(QApplication::translate("Conversor", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        progressBar->setWhatsThis(QApplication::translate("Conversor", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("Conversor", "Cancelar proceso en curso.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_7->setStatusTip(QApplication::translate("Conversor", "Cancelar proceso en curso.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_7->setWhatsThis(QApplication::translate("Conversor", "Cancelar proceso en curso.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_7->setText(QApplication::translate("Conversor", "Cancelar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_19->setToolTip(QApplication::translate("Conversor", "Capturar fichero de video", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_19->setStatusTip(QApplication::translate("Conversor", "Capturar fichero de video", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_19->setWhatsThis(QApplication::translate("Conversor", "Comprobacion de las actualizaciones disponibles.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_19->setText(QApplication::translate("Conversor", "Insertar ficheros de video", 0, QApplication::UnicodeUTF8));
        groupBox_11->setTitle(QApplication::translate("Conversor", "Ruta de salida", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Conversor", "...", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Conversor", "Configuracion de salida", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("Conversor", "Parar video en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("Conversor", "Parar video en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("Conversor", "Parar video en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("Conversor", "Stop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("Conversor", "Pausar video en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_6->setStatusTip(QApplication::translate("Conversor", "Pausar video en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_6->setWhatsThis(QApplication::translate("Conversor", "Pausar video en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_6->setText(QApplication::translate("Conversor", "Pausa", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Conversor", "Video", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Conversor", "avi", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "mpg", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "DVD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "wmv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "flv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "3gp", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "mp4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "DV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "H.264", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox->setToolTip(QApplication::translate("Conversor", "Tipo de video seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox->setStatusTip(QApplication::translate("Conversor", "Tipo de video seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox->setWhatsThis(QApplication::translate("Conversor", "Tipo de video seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("Conversor", "Insertar parametros de salida a proyectos seleccionado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("Conversor", "Insertar parametros de salida a proyectos seleccionado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("Conversor", "Insertar parametros de salida a proyectos seleccionado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QApplication::translate("Conversor", "Insertar a proyecto activo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("Conversor", "Iniciar video", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("Conversor", "Iniciar video", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("Conversor", "Iniciar video", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("Conversor", "Play", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("Conversor", "Resolucion", 0, QApplication::UnicodeUTF8));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("Conversor", "Copiar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "480x720", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "576x720", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "1024x576", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "720x1280", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "1080x1920", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "592x352", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_4->setToolTip(QApplication::translate("Conversor", "Tipo de resolucion seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox_4->setStatusTip(QApplication::translate("Conversor", "Tipo de resolucion seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox_4->setWhatsThis(QApplication::translate("Conversor", "Tipo de resolucion seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_8->setTitle(QApplication::translate("Conversor", "Peso", 0, QApplication::UnicodeUTF8));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("Conversor", "Sin especificar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "700 Mg", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "900 Mg", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "1400 Mg", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_5->setToolTip(QApplication::translate("Conversor", "Tipo de resolucion seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox_5->setStatusTip(QApplication::translate("Conversor", "Tipo de resolucion seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox_5->setWhatsThis(QApplication::translate("Conversor", "Tipo de resolucion seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_5->setTitle(QApplication::translate("Conversor", "Audio", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Conversor", "Copiar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "pcm", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "mp3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "ac3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "aac", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "mp2", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_2->setToolTip(QApplication::translate("Conversor", "Tipo de audio seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox_2->setStatusTip(QApplication::translate("Conversor", "Tipo de audio seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox_2->setWhatsThis(QApplication::translate("Conversor", "Tipo de audio seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_6->setTitle(QApplication::translate("Conversor", "Formato", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("Conversor", "Copiar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "4:3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Conversor", "16:9", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_3->setToolTip(QApplication::translate("Conversor", "Tipo de aspecto de imagen seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox_3->setStatusTip(QApplication::translate("Conversor", "Tipo de aspecto de imagen seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox_3->setWhatsThis(QApplication::translate("Conversor", "Tipo de aspecto de imagen seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class Conversor: public Ui_Conversor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERSOR_H
