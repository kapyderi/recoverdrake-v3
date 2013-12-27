/********************************************************************************
** Form generated from reading UI file 'burn.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BURN_H
#define UI_BURN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMdiArea>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_burn
{
public:
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_18;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_4;
    QSplitter *splitter;
    QTableWidget *tableWidget;
    QTextEdit *textEdit_4;
    QMdiArea *mdiArea;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_10;
    QPushButton *pushButton_4;
    QPushButton *pushButton_11;
    QPushButton *pushButton_20;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QProgressBar *progressBar_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_18;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QGridLayout *gridLayout_19;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_22;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_13;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_8;
    QComboBox *comboBox;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_12;
    QLineEdit *lineEdit_2;
    QCheckBox *checkBox_4;
    QGridLayout *gridLayout_15;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_26;
    QTextEdit *textEdit_2;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_14;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_17;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QGridLayout *gridLayout_17;
    QLabel *label_8;
    QLabel *label_9;
    QFrame *line;
    QLabel *label_10;
    QLabel *label_11;
    QFrame *line_2;
    QLabel *label_12;
    QLabel *label_13;
    QFrame *line_3;
    QLabel *label_14;
    QLabel *label_15;
    QFrame *line_4;
    QLabel *label_18;
    QFrame *line_5;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_19;
    QLabel *label_16;
    QLabel *label_32;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_21;
    QTextEdit *textEdit_3;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_16;
    QPushButton *pushButton_13;
    QPushButton *pushButton_15;
    QPushButton *pushButton_19;
    QFrame *line_7;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_27;
    QGridLayout *gridLayout_25;
    QCheckBox *checkBox;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_6;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_20;
    QProgressBar *progressBar_3;
    QGridLayout *gridLayout_11;
    QPushButton *pushButton_17;
    QPushButton *pushButton_16;
    QSpacerItem *horizontalSpacer;
    QLabel *label_33;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_24;
    QGridLayout *gridLayout_23;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QLabel *label_7;
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QLabel *label_5;
    QPushButton *pushButton_14;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_5;

    void setupUi(QDialog *burn)
    {
        if (burn->objectName().isEmpty())
            burn->setObjectName(QString::fromUtf8("burn"));
        burn->resize(1009, 776);
        QFont font;
        font.setPointSize(7);
        burn->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/duplicado.png"), QSize(), QIcon::Normal, QIcon::Off);
        burn->setWindowIcon(icon);
        burn->setSizeGripEnabled(true);
        burn->setModal(true);
        gridLayout_5 = new QGridLayout(burn);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tabWidget = new QTabWidget(burn);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(25, 25));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_18 = new QGridLayout(tab);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 965, 656));
        gridLayout_10 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        splitter = new QSplitter(scrollAreaWidgetContents);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tableWidget = new QTableWidget(splitter);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/64px-Dolphin-icon.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setIcon(icon1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/VLC.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setIcon(icon2);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/kttsd.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setIcon(icon3);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setStyleSheet(QString::fromUtf8(""));
        tableWidget->setDragEnabled(true);
        tableWidget->setDragDropMode(QAbstractItemView::DropOnly);
        tableWidget->setDefaultDropAction(Qt::CopyAction);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);
        splitter->addWidget(tableWidget);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        textEdit_4 = new QTextEdit(splitter);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit_4->sizePolicy().hasHeightForWidth());
        textEdit_4->setSizePolicy(sizePolicy);
        splitter->addWidget(textEdit_4);

        gridLayout_4->addWidget(splitter, 1, 0, 1, 1);

        mdiArea = new QMdiArea(scrollAreaWidgetContents);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        gridLayout_4->addWidget(mdiArea, 0, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_4, 0, 0, 3, 1);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 0));
        groupBox_2->setMaximumSize(QSize(260, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/audio.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon4);
        pushButton_7->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_7, 4, 0, 1, 2);

        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/cd_burning_section.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon5);
        pushButton_6->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_6, 1, 0, 1, 2);

        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/smplayer.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon6);
        pushButton_10->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_10, 5, 0, 1, 2);

        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/multimedia.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon7);
        pushButton_4->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_4, 3, 0, 1, 2);

        pushButton_11 = new QPushButton(groupBox_2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setIcon(icon);
        pushButton_11->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_11, 6, 0, 1, 2);

        pushButton_20 = new QPushButton(groupBox_2);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/DVD.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_20->setIcon(icon8);
        pushButton_20->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_20, 2, 0, 1, 2);


        gridLayout_10->addWidget(groupBox_2, 2, 1, 1, 2);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 0));
        groupBox->setMaximumSize(QSize(260, 16777215));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Imagenes/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon9);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 2);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Imagenes/carpeta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon10);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_2, 1, 0, 1, 2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon11);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_3, 2, 0, 1, 2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        progressBar_2 = new QProgressBar(groupBox_3);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setMaximumSize(QSize(250, 16777215));
        progressBar_2->setValue(0);
        progressBar_2->setOrientation(Qt::Horizontal);
        progressBar_2->setInvertedAppearance(true);
        progressBar_2->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_6->addWidget(progressBar_2, 4, 0, 1, 2);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label, 0, 0, 1, 2);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_4, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_2, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_3, 3, 0, 1, 2);


        gridLayout_2->addWidget(groupBox_3, 3, 0, 1, 2);

        pushButton_18 = new QPushButton(groupBox);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Imagenes/local-administration-mdk.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon12);
        pushButton_18->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_18, 4, 0, 1, 2);


        gridLayout_10->addWidget(groupBox, 0, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer, 1, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        groupBox_2->raise();
        groupBox->raise();

        gridLayout_18->addWidget(scrollArea, 0, 0, 1, 1);

        tabWidget->addTab(tab, icon10, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_19 = new QGridLayout(tab_2);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_22 = new QGridLayout(groupBox_4);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy1);
        gridLayout_13 = new QGridLayout(groupBox_5);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        lineEdit = new QLineEdit(groupBox_5);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(11);

        gridLayout_13->addWidget(lineEdit, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_5, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        sizePolicy1.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy1);
        gridLayout_8 = new QGridLayout(groupBox_6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        comboBox = new QComboBox(groupBox_6);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_8->addWidget(comboBox, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_6, 0, 1, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_4);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy2);
        groupBox_7->setCheckable(true);
        gridLayout_12 = new QGridLayout(groupBox_7);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        pushButton_12 = new QPushButton(groupBox_7);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMaximumSize(QSize(20, 16777215));

        gridLayout_9->addWidget(pushButton_12, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_7);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_9->addWidget(lineEdit_2, 0, 1, 1, 1);

        checkBox_4 = new QCheckBox(groupBox_7);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_9->addWidget(checkBox_4, 0, 2, 1, 1);


        gridLayout_12->addLayout(gridLayout_9, 1, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_7, 0, 2, 1, 1);


        gridLayout_22->addLayout(gridLayout_7, 0, 0, 1, 3);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        groupBox_10 = new QGroupBox(groupBox_4);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        sizePolicy2.setHeightForWidth(groupBox_10->sizePolicy().hasHeightForWidth());
        groupBox_10->setSizePolicy(sizePolicy2);
        gridLayout_26 = new QGridLayout(groupBox_10);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        textEdit_2 = new QTextEdit(groupBox_10);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        gridLayout_26->addWidget(textEdit_2, 1, 0, 1, 1);

        groupBox_14 = new QGroupBox(groupBox_10);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        gridLayout_14 = new QGridLayout(groupBox_14);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        label_22 = new QLabel(groupBox_14);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_14->addWidget(label_22, 0, 0, 1, 1);

        label_23 = new QLabel(groupBox_14);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_14->addWidget(label_23, 0, 1, 1, 1);

        label_17 = new QLabel(groupBox_14);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_14->addWidget(label_17, 0, 2, 1, 1);

        label_24 = new QLabel(groupBox_14);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_14->addWidget(label_24, 0, 3, 1, 1);

        label_25 = new QLabel(groupBox_14);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_14->addWidget(label_25, 0, 4, 1, 1);

        label_26 = new QLabel(groupBox_14);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_14->addWidget(label_26, 0, 5, 1, 1);

        label_27 = new QLabel(groupBox_14);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_14->addWidget(label_27, 0, 6, 1, 1);

        label_28 = new QLabel(groupBox_14);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_14->addWidget(label_28, 0, 7, 1, 1);

        label_29 = new QLabel(groupBox_14);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_14->addWidget(label_29, 0, 8, 1, 1);

        label_30 = new QLabel(groupBox_14);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_14->addWidget(label_30, 0, 9, 1, 1);

        label_31 = new QLabel(groupBox_14);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_14->addWidget(label_31, 0, 10, 1, 1);


        gridLayout_26->addWidget(groupBox_14, 4, 0, 1, 1);

        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        label_8 = new QLabel(groupBox_10);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_17->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_10);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        label_9->setFont(font3);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_17->addWidget(label_9, 0, 1, 1, 2);

        line = new QFrame(groupBox_10);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line, 0, 3, 1, 1);

        label_10 = new QLabel(groupBox_10);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_17->addWidget(label_10, 0, 4, 1, 1);

        label_11 = new QLabel(groupBox_10);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font3);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_17->addWidget(label_11, 0, 5, 1, 1);

        line_2 = new QFrame(groupBox_10);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_2, 0, 6, 1, 1);

        label_12 = new QLabel(groupBox_10);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_17->addWidget(label_12, 0, 7, 1, 1);

        label_13 = new QLabel(groupBox_10);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font3);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_17->addWidget(label_13, 0, 8, 1, 1);

        line_3 = new QFrame(groupBox_10);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_3, 0, 9, 1, 1);

        label_14 = new QLabel(groupBox_10);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_17->addWidget(label_14, 0, 10, 1, 1);

        label_15 = new QLabel(groupBox_10);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font3);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_17->addWidget(label_15, 0, 11, 1, 1);

        line_4 = new QFrame(groupBox_10);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_4, 2, 0, 1, 12);

        label_18 = new QLabel(groupBox_10);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_17->addWidget(label_18, 3, 0, 1, 7);

        line_5 = new QFrame(groupBox_10);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_17->addWidget(line_5, 4, 0, 1, 12);

        label_20 = new QLabel(groupBox_10);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_17->addWidget(label_20, 7, 0, 1, 8);

        label_21 = new QLabel(groupBox_10);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font3);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(label_21, 7, 8, 1, 4);

        label_19 = new QLabel(groupBox_10);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font3);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(label_19, 3, 7, 1, 1);

        label_16 = new QLabel(groupBox_10);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_17->addWidget(label_16, 3, 8, 1, 3);

        label_32 = new QLabel(groupBox_10);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setFont(font3);
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_17->addWidget(label_32, 3, 11, 1, 1);


        gridLayout_26->addLayout(gridLayout_17, 3, 0, 1, 1);


        gridLayout_15->addWidget(groupBox_10, 0, 0, 1, 1);

        groupBox_12 = new QGroupBox(groupBox_4);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        gridLayout_21 = new QGridLayout(groupBox_12);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        textEdit_3 = new QTextEdit(groupBox_12);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));

        gridLayout_21->addWidget(textEdit_3, 0, 0, 1, 1);


        gridLayout_15->addWidget(groupBox_12, 0, 1, 1, 1);


        gridLayout_22->addLayout(gridLayout_15, 1, 0, 3, 1);

        groupBox_9 = new QGroupBox(groupBox_4);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        gridLayout_16 = new QGridLayout(groupBox_9);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        pushButton_13 = new QPushButton(groupBox_9);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Imagenes/borrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon13);
        pushButton_13->setIconSize(QSize(25, 25));

        gridLayout_16->addWidget(pushButton_13, 0, 0, 1, 1);

        pushButton_15 = new QPushButton(groupBox_9);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setIcon(icon13);
        pushButton_15->setIconSize(QSize(25, 25));

        gridLayout_16->addWidget(pushButton_15, 1, 0, 1, 1);

        pushButton_19 = new QPushButton(groupBox_9);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Imagenes/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon14);
        pushButton_19->setIconSize(QSize(25, 25));

        gridLayout_16->addWidget(pushButton_19, 3, 0, 1, 1);

        line_7 = new QFrame(groupBox_9);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_16->addWidget(line_7, 2, 0, 1, 1);


        gridLayout_22->addWidget(groupBox_9, 1, 1, 1, 2);

        groupBox_8 = new QGroupBox(groupBox_4);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_27 = new QGridLayout(groupBox_8);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        gridLayout_25 = new QGridLayout();
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        checkBox = new QCheckBox(groupBox_8);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_25->addWidget(checkBox, 0, 0, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_8);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_25->addWidget(checkBox_5, 0, 1, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_8);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_25->addWidget(checkBox_3, 1, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_8);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_25->addWidget(checkBox_2, 1, 1, 1, 1);

        checkBox_6 = new QCheckBox(groupBox_8);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        gridLayout_25->addWidget(checkBox_6, 2, 0, 1, 2);


        gridLayout_27->addLayout(gridLayout_25, 0, 0, 1, 1);


        gridLayout_22->addWidget(groupBox_8, 2, 1, 1, 2);

        groupBox_11 = new QGroupBox(groupBox_4);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        sizePolicy1.setHeightForWidth(groupBox_11->sizePolicy().hasHeightForWidth());
        groupBox_11->setSizePolicy(sizePolicy1);
        groupBox_11->setMaximumSize(QSize(280, 58));
        gridLayout_20 = new QGridLayout(groupBox_11);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        progressBar_3 = new QProgressBar(groupBox_11);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setMaximumSize(QSize(221, 23));
        progressBar_3->setValue(0);

        gridLayout_20->addWidget(progressBar_3, 1, 0, 1, 1);


        gridLayout_22->addWidget(groupBox_11, 3, 1, 1, 2);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        pushButton_17 = new QPushButton(groupBox_4);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Imagenes/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon15);
        pushButton_17->setIconSize(QSize(25, 25));

        gridLayout_11->addWidget(pushButton_17, 0, 0, 1, 1);

        pushButton_16 = new QPushButton(groupBox_4);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Imagenes/abrir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon16);
        pushButton_16->setIconSize(QSize(25, 25));

        gridLayout_11->addWidget(pushButton_16, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer, 0, 1, 1, 1);

        label_33 = new QLabel(groupBox_4);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: bold;"));

        gridLayout_11->addWidget(label_33, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_3, 0, 3, 1, 1);


        gridLayout_22->addLayout(gridLayout_11, 4, 0, 1, 1);

        groupBox_13 = new QGroupBox(groupBox_4);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        gridLayout_24 = new QGridLayout(groupBox_13);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        gridLayout_23 = new QGridLayout();
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        label_6 = new QLabel(groupBox_13);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_23->addWidget(label_6, 0, 0, 1, 1);

        comboBox_2 = new QComboBox(groupBox_13);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_23->addWidget(comboBox_2, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_13);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_23->addWidget(label_7, 0, 2, 1, 1);


        gridLayout_24->addLayout(gridLayout_23, 0, 0, 1, 1);


        gridLayout_22->addWidget(groupBox_13, 4, 1, 1, 2);


        gridLayout_19->addWidget(groupBox_4, 0, 0, 1, 3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        progressBar = new QProgressBar(tab_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 0, 1, 1, 1);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        pushButton_14 = new QPushButton(tab_2);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setMaximumSize(QSize(110, 16777215));
        pushButton_14->setIcon(icon5);
        pushButton_14->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_14, 0, 2, 1, 1);


        gridLayout_19->addLayout(gridLayout, 2, 0, 1, 3);

        textEdit = new QTextEdit(tab_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setFont(font);

        gridLayout_19->addWidget(textEdit, 1, 0, 1, 3);

        tabWidget->addTab(tab_2, icon12, QString());

        gridLayout_5->addWidget(tabWidget, 0, 0, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        pushButton_5 = new QPushButton(burn);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon17);
        pushButton_5->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_5, 2, 3, 1, 1);


        retranslateUi(burn);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(burn);
    } // setupUi

    void retranslateUi(QDialog *burn)
    {
        burn->setWindowTitle(QApplication::translate("burn", "KapyRecBurn", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("burn", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("burn", "Ruta", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("burn", "Tamano", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QApplication::translate("burn", "Datos a grabar en el medio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget->setStatusTip(QApplication::translate("burn", "Datos a grabar en el medio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget->setWhatsThis(QApplication::translate("burn", "Datos a grabar en el medio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_2->setTitle(QApplication::translate("burn", "Acciones", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("burn", "Grabar CD de audio", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("burn", "Grabacion de un CD/DVD en formato de datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_6->setStatusTip(QApplication::translate("burn", "Grabacion de un CD/DVD en formato de datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_6->setWhatsThis(QApplication::translate("burn", "Grabacion de un CD/DVD en formato de datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_6->setText(QApplication::translate("burn", "Grabar CD/DVD de datos", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("burn", "Grabar CD de Video", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("burn", "Grabar DVD de video", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("burn", "Copiar Medio", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        pushButton_20->setStatusTip(QApplication::translate("burn", "Grabar un DVD de Video fiel al original", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_20->setWhatsThis(QApplication::translate("burn", "Grabar un DVD de Video fiel al original", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        pushButton_20->setAccessibleName(QApplication::translate("burn", "Grabar un DVD de Video fiel al original", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        pushButton_20->setText(QApplication::translate("burn", "Copiar DVD de video", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("burn", "Proyecto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("burn", "Anadir manualmente archivos al proyecto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("burn", "Anadir manualmente archivos al proyecto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("burn", "Anadir manualmente archivos al proyecto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("burn", "Anadir archivos a proyecto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("burn", "Anadir manualmente directorio al proyecto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("burn", "Anadir manualmente directorio al proyecto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("burn", "Anadir manualmente directorio al proyecto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("burn", "Anadir directorio a proyecto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("burn", "Eliminar un registro del proyecto actual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("burn", "Eliminar un registro del proyecto actual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("burn", "Eliminar un registro del proyecto actual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("burn", "Eliminar del proyecto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_3->setToolTip(QApplication::translate("burn", "Espacio disponible en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_3->setStatusTip(QApplication::translate("burn", "Espacio disponible en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupBox_3->setWhatsThis(QApplication::translate("burn", "Espacio disponible en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_3->setTitle(QString());
        label->setText(QApplication::translate("burn", "Tamano total", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton_18->setText(QApplication::translate("burn", "Opciones", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("burn", "Proyecto", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("burn", "Opciones", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_5->setToolTip(QApplication::translate("burn", "Nombre del volumen de disco grabado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_5->setStatusTip(QApplication::translate("burn", "Nombre del volumen de disco grabado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupBox_5->setWhatsThis(QApplication::translate("burn", "Nombre del volumen de disco grabado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_5->setTitle(QApplication::translate("burn", "Nombre del volumen", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("burn", "RCVBurn", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("burn", "Velocidad de grabacion", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("burn", "2x", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "4x", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "6x", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "8x", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "10x", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "12x", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "16x", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "18x", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "20x", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "22x", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "24x", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox->setToolTip(QApplication::translate("burn", "Velocidad de grabacion opcional", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox->setStatusTip(QApplication::translate("burn", "Velocidad de grabacion opcional", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox->setWhatsThis(QApplication::translate("burn", "Velocidad de grabacion opcional", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_STATUSTIP
        groupBox_7->setStatusTip(QApplication::translate("burn", "Creacion de imagen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupBox_7->setWhatsThis(QApplication::translate("burn", "Creacion de imagen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        groupBox_7->setAccessibleName(QApplication::translate("burn", "Creacion de imagen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        groupBox_7->setTitle(QApplication::translate("burn", "Crear imagen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_12->setToolTip(QApplication::translate("burn", "Donde guardar la imagen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_12->setStatusTip(QApplication::translate("burn", "Donde guardar la imagen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_12->setWhatsThis(QApplication::translate("burn", "Donde guardar la imagen", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_12->setText(QApplication::translate("burn", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("burn", "Direccion donde se guardara la imagen iso", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QApplication::translate("burn", "Direccion donde se guardara la imagen iso", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("burn", "Direccion donde se guardara la imagen iso", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_4->setText(QApplication::translate("burn", "Solo Imagen", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("burn", "Informacion del disco", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textEdit_2->setToolTip(QApplication::translate("burn", "Informacion del disco introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit_2->setStatusTip(QApplication::translate("burn", "Informacion del disco introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit_2->setWhatsThis(QApplication::translate("burn", "Informacion del disco introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        textEdit_2->setHtml(QApplication::translate("burn", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_14->setToolTip(QApplication::translate("burn", "Velocidades admitidas por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_14->setStatusTip(QApplication::translate("burn", "Velocidades admitidas por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupBox_14->setWhatsThis(QApplication::translate("burn", "Velocidades admitidas por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_14->setTitle(QApplication::translate("burn", "Velocidades admitidas", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_22->setToolTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_22->setStatusTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_22->setWhatsThis(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_22->setText(QApplication::translate("burn", "2x", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_23->setToolTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_23->setStatusTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_23->setWhatsThis(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_23->setText(QApplication::translate("burn", "4x", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_17->setToolTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_17->setStatusTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_17->setWhatsThis(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_17->setText(QApplication::translate("burn", "6x", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_24->setToolTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_24->setStatusTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_24->setWhatsThis(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_24->setText(QApplication::translate("burn", "8x", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_25->setToolTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_25->setStatusTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_25->setWhatsThis(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_25->setText(QApplication::translate("burn", "10x", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_26->setToolTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_26->setStatusTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_26->setWhatsThis(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_26->setText(QApplication::translate("burn", "12x", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_27->setToolTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_27->setStatusTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_27->setWhatsThis(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_27->setText(QApplication::translate("burn", "16x", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_28->setToolTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_28->setStatusTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_28->setWhatsThis(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_28->setText(QApplication::translate("burn", "18x", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_29->setToolTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_29->setStatusTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_29->setWhatsThis(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_29->setText(QApplication::translate("burn", "20x", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_30->setToolTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_30->setStatusTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_30->setWhatsThis(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_30->setText(QApplication::translate("burn", "22x", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_31->setToolTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_31->setStatusTip(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_31->setWhatsThis(QApplication::translate("burn", "Velocidad admitida por el soporte. Se recomienda la minima para mayor seguiridad de los datos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_31->setText(QApplication::translate("burn", "24x", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("burn", "Capacidad total del disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_8->setStatusTip(QApplication::translate("burn", "Capacidad total del disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_8->setWhatsThis(QApplication::translate("burn", "Capacidad total del disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_8->setText(QApplication::translate("burn", "Capacidad:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_9->setToolTip(QApplication::translate("burn", "Capacidad total del disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_9->setStatusTip(QApplication::translate("burn", "Capacidad total del disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_9->setWhatsThis(QApplication::translate("burn", "Capacidad total del disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_9->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_10->setToolTip(QApplication::translate("burn", "Tipo de disco introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_10->setStatusTip(QApplication::translate("burn", "Tipo de disco introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_10->setWhatsThis(QApplication::translate("burn", "Tipo de disco introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_10->setText(QApplication::translate("burn", "Tipo:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_11->setToolTip(QApplication::translate("burn", "Tipo de disco introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_11->setStatusTip(QApplication::translate("burn", "Tipo de disco introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_11->setWhatsThis(QApplication::translate("burn", "Tipo de disco introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_11->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_12->setToolTip(QApplication::translate("burn", "Capacidad utilizada en el disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_12->setStatusTip(QApplication::translate("burn", "Capacidad utilizada en el disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_12->setWhatsThis(QApplication::translate("burn", "Capacidad utilizada en el disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_12->setText(QApplication::translate("burn", "Utilizado:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_13->setToolTip(QApplication::translate("burn", "Capacidad utilizada en el disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_13->setStatusTip(QApplication::translate("burn", "Capacidad utilizada en el disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_13->setWhatsThis(QApplication::translate("burn", "Capacidad utilizada en el disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_13->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_14->setToolTip(QApplication::translate("burn", "Nos informa si es un disco multisesion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_14->setStatusTip(QApplication::translate("burn", "Nos informa si es un disco multisesion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_14->setWhatsThis(QApplication::translate("burn", "Nos informa si es un disco multisesion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_14->setText(QApplication::translate("burn", "Multisesion:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_15->setToolTip(QApplication::translate("burn", "Nos informa si es un disco multisesion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_15->setStatusTip(QApplication::translate("burn", "Nos informa si es un disco multisesion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_15->setWhatsThis(QApplication::translate("burn", "Nos informa si es un disco multisesion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_15->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_18->setToolTip(QApplication::translate("burn", "Numero de sesion grabadas en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_18->setStatusTip(QApplication::translate("burn", "Numero de sesion grabadas en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_18->setWhatsThis(QApplication::translate("burn", "Numero de sesion grabadas en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_18->setText(QApplication::translate("burn", "Numero de sesiones:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_20->setToolTip(QApplication::translate("burn", "Capacidad libre para poder seguir grabando en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_20->setStatusTip(QApplication::translate("burn", "Capacidad libre para poder seguir grabando en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_20->setWhatsThis(QApplication::translate("burn", "Capacidad libre para poder seguir grabando en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_20->setText(QApplication::translate("burn", "Espacio libre disponible:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_21->setToolTip(QApplication::translate("burn", "Capacidad libre para poder seguir grabando en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_21->setStatusTip(QApplication::translate("burn", "Capacidad libre para poder seguir grabando en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_21->setWhatsThis(QApplication::translate("burn", "Capacidad libre para poder seguir grabando en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_21->setText(QString());
#ifndef QT_NO_TOOLTIP
        label_19->setToolTip(QApplication::translate("burn", "Numero de sesion grabadas en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_19->setStatusTip(QApplication::translate("burn", "Numero de sesion grabadas en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_19->setWhatsThis(QApplication::translate("burn", "Numero de sesion grabadas en disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_19->setText(QString());
        label_16->setText(QApplication::translate("burn", "Regrabable:", 0, QApplication::UnicodeUTF8));
        label_32->setText(QString());
        groupBox_12->setTitle(QApplication::translate("burn", "Contenido", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textEdit_3->setToolTip(QApplication::translate("burn", "Contenido del disco introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit_3->setStatusTip(QApplication::translate("burn", "Contenido del disco introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit_3->setWhatsThis(QApplication::translate("burn", "Contenido del disco introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_9->setTitle(QApplication::translate("burn", "Opciones con regrabables", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_13->setToolTip(QApplication::translate("burn", "Borrado de disco regrabables", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_13->setStatusTip(QApplication::translate("burn", "Borrado de disco regrabables", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_13->setWhatsThis(QApplication::translate("burn", "Borrado de disco regrabables", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_13->setText(QApplication::translate("burn", "Borrar CD/DVD Regrabable", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_15->setToolTip(QApplication::translate("burn", "Formateo de disco regrabables", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_15->setStatusTip(QApplication::translate("burn", "Formateo de disco regrabables", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_15->setWhatsThis(QApplication::translate("burn", "Formateo de disco regrabables", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_15->setText(QApplication::translate("burn", "Formatear CD/DVD Regrabable", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_19->setToolTip(QApplication::translate("burn", "Terminar grabacion. Ya no se prodra ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_19->setStatusTip(QApplication::translate("burn", "Terminar grabacion. Ya no se prodra ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_19->setWhatsThis(QApplication::translate("burn", "Terminar grabacion. Ya no se prodra ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_19->setText(QApplication::translate("burn", "Cerrar disco", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("burn", "Metodo de grabacion", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("burn", "Grabar un disco al vuelo, sin crear ningun archivo temporal. Es menos efectivo pero mucho mas rapido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox->setStatusTip(QApplication::translate("burn", "Grabar un disco al vuelo, sin crear ningun archivo temporal. Es menos efectivo pero mucho mas rapido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox->setWhatsThis(QApplication::translate("burn", "Grabar un disco al vuelo, sin crear ningun archivo temporal. Es menos efectivo pero mucho mas rapido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox->setText(QApplication::translate("burn", "Al vuelo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_5->setToolTip(QApplication::translate("burn", "Terminar grabacion. Ya no se prodra volver a grabar en el", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_5->setStatusTip(QApplication::translate("burn", "Terminar grabacion. Ya no se prodra volver a grabar en el", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_5->setWhatsThis(QApplication::translate("burn", "Terminar grabacion. Ya no se prodra volver a grabar en el", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_5->setText(QApplication::translate("burn", "Cerrar disco", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_3->setToolTip(QApplication::translate("burn", "Iniciar disco multisesion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_3->setStatusTip(QApplication::translate("burn", "Iniciar disco multisesion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_3->setWhatsThis(QApplication::translate("burn", "Iniciar disco multisesion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_3->setText(QApplication::translate("burn", "Multisesion", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_2->setToolTip(QApplication::translate("burn", "Continuar un disco grabado con multisesion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_2->setStatusTip(QApplication::translate("burn", "Continuar un disco grabado con multisesion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_2->setWhatsThis(QApplication::translate("burn", "Continuar un disco grabado con multisesion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_2->setText(QApplication::translate("burn", "Continuar multisesion", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_6->setToolTip(QApplication::translate("burn", "Simular grabacion para ver si hay errores. NO graba realmente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_6->setStatusTip(QApplication::translate("burn", "Simular grabacion para ver si hay errores. NO graba realmente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_6->setWhatsThis(QApplication::translate("burn", "Simular grabacion para ver si hay errores. NO graba realmente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        checkBox_6->setAccessibleName(QApplication::translate("burn", "Simular grabacion para ver si hay errores. NO graba realmente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        checkBox_6->setText(QApplication::translate("burn", "Simular grabacion (no se graba)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        groupBox_11->setToolTip(QApplication::translate("burn", "Espacio utilizado en la grabacion de disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_11->setStatusTip(QApplication::translate("burn", "Espacio utilizado en la grabacion de disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupBox_11->setWhatsThis(QApplication::translate("burn", "Espacio utilizado en la grabacion de disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_11->setTitle(QApplication::translate("burn", "Espacio ocupado en disco", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_17->setToolTip(QApplication::translate("burn", "Refrescar estado del soporte", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_17->setStatusTip(QApplication::translate("burn", "Refrescar estado del soporte", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_17->setWhatsThis(QApplication::translate("burn", "Refrescar estado del soporte", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_17->setText(QApplication::translate("burn", "Refrescar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_16->setToolTip(QApplication::translate("burn", "Cargar/Expulsar disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_16->setStatusTip(QApplication::translate("burn", "Cargar/Expulsar disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_16->setWhatsThis(QApplication::translate("burn", "Cargar/Expulsar disco", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_16->setText(QApplication::translate("burn", "Cargar/Expulsar", 0, QApplication::UnicodeUTF8));
        label_33->setText(QString());
        groupBox_13->setTitle(QApplication::translate("burn", "Numero de copias", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("burn", "Hacer... ", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("burn", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("burn", "10", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("burn", "copias", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        progressBar->setToolTip(QApplication::translate("burn", "Barra de progreso del proceso de grabacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        progressBar->setStatusTip(QApplication::translate("burn", "Barra de progreso del proceso de grabacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        progressBar->setWhatsThis(QApplication::translate("burn", "Barra de progreso del proceso de grabacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_5->setText(QApplication::translate("burn", "Progreso:", 0, QApplication::UnicodeUTF8));
        pushButton_14->setText(QApplication::translate("burn", "Grabar", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("burn", "Grabar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("burn", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("burn", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("burn", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QApplication::translate("burn", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class burn: public Ui_burn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BURN_H
