/********************************************************************************
** Form generated from reading UI file 'id3mp3.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ID3MP3_H
#define UI_ID3MP3_H

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
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <phonon/seekslider.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_id3mp3
{
public:
    QGridLayout *gridLayout_14;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_21;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_15;
    QComboBox *comboBox;
    QLabel *label_14;
    QLineEdit *lineEdit_12;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLabel *label_19;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_10;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout_16;
    QLabel *label_12;
    QLabel *label_11;
    QLineEdit *lineEdit_11;
    QLabel *label_10;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_16;
    QLabel *label_17;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QPushButton *pushButton_17;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit;
    QCheckBox *checkBox_2;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_18;
    QGridLayout *gridLayout_15;
    QSpacerItem *horizontalSpacer_9;
    QRadioButton *radioButton_6;
    QSpacerItem *horizontalSpacer_11;
    QRadioButton *radioButton_3;
    QLabel *label;
    QLineEdit *lineEdit_9;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *checkBox;
    QRadioButton *radioButton_5;
    QComboBox *comboBox_3;
    QLabel *label_20;
    QPushButton *pushButton_24;
    QFrame *line_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_19;
    QPushButton *pushButton_11;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout_19;
    QLabel *label_16;
    QLineEdit *lineEdit_15;
    QPushButton *pushButton_18;
    QPushButton *pushButton_10;
    QPushButton *pushButton_8;
    QPushButton *pushButton_16;
    QPushButton *pushButton_15;
    QFrame *line;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_7;
    QTextEdit *textEdit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_11;
    QLabel *label_18;
    QComboBox *comboBox_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_8;
    QLabel *label_7;
    QLineEdit *lineEdit_7;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_10;
    QLabel *label_9;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_19;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_22;
    QGridLayout *gridLayout_13;
    QPushButton *pushButton_12;
    Phonon::VolumeSlider *volumeSlider_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLCDNumber *lcdNumber_2;
    Phonon::SeekSlider *seekSlider_2;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_23;
    QGridLayout *gridLayout_20;
    QLabel *label_21;
    QRadioButton *radioButton_2;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_10;
    QComboBox *comboBox_4;
    QRadioButton *radioButton;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_4;
    QProgressBar *progressBar;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_14;
    QRadioButton *radioButton_9;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *pushButton_23;
    QRadioButton *radioButton_11;
    QPushButton *pushButton_22;
    QRadioButton *radioButton_10;
    QSpacerItem *horizontalSpacer_15;

    void setupUi(QDialog *id3mp3)
    {
        if (id3mp3->objectName().isEmpty())
            id3mp3->setObjectName(QString::fromUtf8("id3mp3"));
        id3mp3->resize(2180, 979);
        QFont font;
        font.setPointSize(7);
        id3mp3->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/etiqueta.png"), QSize(), QIcon::Normal, QIcon::Off);
        id3mp3->setWindowIcon(icon);
        id3mp3->setStyleSheet(QString::fromUtf8(""));
        gridLayout_14 = new QGridLayout(id3mp3);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        groupBox_2 = new QGroupBox(id3mp3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_21 = new QGridLayout(groupBox_2);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_15->setFont(font1);

        gridLayout->addWidget(label_15, 0, 6, 1, 1);

        comboBox = new QComboBox(groupBox_4);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 4, 1, 1);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 0, 11, 1, 1);

        lineEdit_12 = new QLineEdit(groupBox_4);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(lineEdit_12, 0, 10, 1, 1);

        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);

        gridLayout->addWidget(label_13, 0, 9, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        lineEdit_13 = new QLineEdit(groupBox_4);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(lineEdit_13, 0, 12, 1, 1);

        lineEdit_14 = new QLineEdit(groupBox_4);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        lineEdit_14->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(lineEdit_14, 0, 7, 1, 1);

        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font1);

        gridLayout->addWidget(label_19, 0, 3, 1, 1);

        checkBox_6 = new QCheckBox(groupBox_4);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setFont(font);
        checkBox_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(checkBox_6, 0, 5, 1, 1);

        checkBox_9 = new QCheckBox(groupBox_4);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));

        gridLayout->addWidget(checkBox_9, 0, 13, 1, 1);

        checkBox_7 = new QCheckBox(groupBox_4);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setFont(font);
        checkBox_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(checkBox_7, 0, 8, 1, 1);

        checkBox_8 = new QCheckBox(groupBox_4);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setFont(font);
        checkBox_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(checkBox_8, 0, 14, 1, 1);

        checkBox_10 = new QCheckBox(groupBox_4);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));

        gridLayout->addWidget(checkBox_10, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 1, 1, 1);

        gridLayout_16 = new QGridLayout();
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, -1, -1, -1);
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);

        gridLayout_16->addWidget(label_12, 4, 0, 1, 1);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        gridLayout_16->addWidget(label_11, 3, 0, 1, 1);

        lineEdit_11 = new QLineEdit(groupBox_4);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));

        gridLayout_16->addWidget(lineEdit_11, 3, 1, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);

        gridLayout_16->addWidget(label_10, 2, 0, 1, 1);

        lineEdit_10 = new QLineEdit(groupBox_4);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        gridLayout_16->addWidget(lineEdit_10, 2, 1, 1, 1);

        lineEdit_20 = new QLineEdit(groupBox_4);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));

        gridLayout_16->addWidget(lineEdit_20, 4, 1, 1, 1);

        lineEdit_16 = new QLineEdit(groupBox_4);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));

        gridLayout_16->addWidget(lineEdit_16, 0, 1, 1, 1);

        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setFont(font1);

        gridLayout_16->addWidget(label_17, 0, 0, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_4);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setFont(font);
        checkBox_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_16->addWidget(checkBox_3, 2, 2, 1, 1);

        checkBox_4 = new QCheckBox(groupBox_4);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setFont(font);
        checkBox_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_16->addWidget(checkBox_4, 3, 2, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_4);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setFont(font);
        checkBox_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_16->addWidget(checkBox_5, 4, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_16, 1, 0, 1, 2);

        pushButton_17 = new QPushButton(groupBox_4);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon1);
        pushButton_17->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_17, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(lineEdit, 0, 4, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_4);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_4->addWidget(checkBox_2, 0, 5, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_4);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        gridLayout_3 = new QGridLayout(groupBox_7);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButton_7 = new QRadioButton(groupBox_7);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));

        gridLayout_3->addWidget(radioButton_7, 0, 0, 1, 1);

        radioButton_4 = new QRadioButton(groupBox_7);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout_3->addWidget(radioButton_4, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_7, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox_4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_18 = new QGridLayout(groupBox_3);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_9, 0, 2, 1, 1);

        radioButton_6 = new QRadioButton(groupBox_3);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));

        gridLayout_15->addWidget(radioButton_6, 0, 3, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_11, 0, 8, 1, 1);

        radioButton_3 = new QRadioButton(groupBox_3);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_15->addWidget(radioButton_3, 0, 9, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_15->addWidget(label, 0, 4, 1, 1);

        lineEdit_9 = new QLineEdit(groupBox_3);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setMinimumSize(QSize(0, 0));
        lineEdit_9->setMaximumSize(QSize(50, 16777215));

        gridLayout_15->addWidget(lineEdit_9, 0, 5, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_7, 0, 10, 1, 1);

        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_15->addWidget(checkBox, 0, 1, 1, 1);

        radioButton_5 = new QRadioButton(groupBox_3);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

        gridLayout_15->addWidget(radioButton_5, 0, 0, 1, 1);

        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        gridLayout_15->addWidget(comboBox_3, 0, 7, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_15->addWidget(label_20, 0, 6, 1, 1);

        pushButton_24 = new QPushButton(groupBox_3);
        pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/grub.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_24->setIcon(icon2);
        pushButton_24->setIconSize(QSize(25, 25));

        gridLayout_15->addWidget(pushButton_24, 0, 12, 1, 1);

        line_3 = new QFrame(groupBox_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_15->addWidget(line_3, 0, 11, 1, 1);


        gridLayout_18->addLayout(gridLayout_15, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 1, 0, 1, 9);

        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);
        pushButton_4->setMinimumSize(QSize(0, 0));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/lupa.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(25, 25));

        gridLayout_4->addWidget(pushButton_4, 0, 1, 1, 3);

        pushButton_19 = new QPushButton(groupBox_4);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/m3u.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon4);
        pushButton_19->setIconSize(QSize(25, 25));

        gridLayout_4->addWidget(pushButton_19, 0, 7, 1, 1);

        pushButton_11 = new QPushButton(groupBox_4);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/lupaO.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon5);
        pushButton_11->setIconSize(QSize(25, 25));

        gridLayout_4->addWidget(pushButton_11, 0, 6, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 0, 0, 1, 2);


        gridLayout_21->addWidget(groupBox_4, 0, 0, 1, 15);

        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 11)
            tableWidget->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::AnyKeyPressed);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);

        gridLayout_21->addWidget(tableWidget, 2, 0, 1, 15);

        gridLayout_19 = new QGridLayout();
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_19->addWidget(label_16, 0, 11, 1, 1);

        lineEdit_15 = new QLineEdit(groupBox_2);
        lineEdit_15->setObjectName(QString::fromUtf8("lineEdit_15"));
        lineEdit_15->setEnabled(false);
        lineEdit_15->setMinimumSize(QSize(50, 0));
        lineEdit_15->setMaximumSize(QSize(50, 16777215));

        gridLayout_19->addWidget(lineEdit_15, 0, 12, 1, 1);

        pushButton_18 = new QPushButton(groupBox_2);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/papleratmp.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon6);
        pushButton_18->setIconSize(QSize(25, 25));

        gridLayout_19->addWidget(pushButton_18, 0, 13, 1, 1);

        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon7);
        pushButton_10->setIconSize(QSize(25, 25));

        gridLayout_19->addWidget(pushButton_10, 0, 9, 1, 1);

        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setIcon(icon1);
        pushButton_8->setIconSize(QSize(25, 25));

        gridLayout_19->addWidget(pushButton_8, 0, 14, 1, 1);

        pushButton_16 = new QPushButton(groupBox_2);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/archivoOut.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon8);
        pushButton_16->setIconSize(QSize(25, 25));

        gridLayout_19->addWidget(pushButton_16, 0, 5, 1, 1);

        pushButton_15 = new QPushButton(groupBox_2);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Imagenes/archivoIn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon9);
        pushButton_15->setIconSize(QSize(25, 25));

        gridLayout_19->addWidget(pushButton_15, 0, 0, 1, 1);

        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line, 0, 2, 1, 1);

        pushButton_9 = new QPushButton(groupBox_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Imagenes/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon10);
        pushButton_9->setIconSize(QSize(25, 25));

        gridLayout_19->addWidget(pushButton_9, 0, 6, 1, 1);

        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Imagenes/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon11);
        pushButton_6->setIconSize(QSize(25, 25));

        gridLayout_19->addWidget(pushButton_6, 0, 1, 1, 1);

        line_2 = new QFrame(groupBox_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_19->addWidget(line_2, 0, 7, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_2, 0, 10, 1, 1);

        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon12);
        pushButton_7->setIconSize(QSize(25, 25));

        gridLayout_19->addWidget(pushButton_7, 0, 8, 1, 1);


        gridLayout_21->addLayout(gridLayout_19, 3, 0, 1, 15);


        gridLayout_14->addWidget(groupBox_2, 4, 0, 1, 2);

        textEdit = new QTextEdit(id3mp3);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_14->addWidget(textEdit, 6, 0, 1, 2);

        groupBox = new QGroupBox(id3mp3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_12 = new QGridLayout(groupBox);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font1);

        gridLayout_11->addWidget(label_18, 0, 4, 1, 1);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout_11->addWidget(comboBox_2, 0, 5, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout_11->addWidget(pushButton_2, 0, 2, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Imagenes/audio.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon13);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout_11->addWidget(pushButton, 0, 0, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(label_8, 0, 10, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        gridLayout_11->addWidget(label_7, 0, 8, 1, 1);

        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setMaximumSize(QSize(50, 16777215));

        gridLayout_11->addWidget(lineEdit_7, 0, 11, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        gridLayout_11->addWidget(label_6, 0, 6, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMaximumSize(QSize(50, 16777215));

        gridLayout_11->addWidget(lineEdit_5, 0, 7, 1, 1);

        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setMaximumSize(QSize(50, 16777215));

        gridLayout_11->addWidget(lineEdit_6, 0, 9, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer, 0, 3, 1, 1);


        gridLayout_12->addLayout(gridLayout_11, 3, 0, 1, 2);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setFont(font1);

        gridLayout_10->addWidget(label_9, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout_10->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        gridLayout_10->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout_10->addWidget(label_2, 3, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8(""));

        gridLayout_10->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_10->addWidget(lineEdit_2, 3, 1, 1, 3);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_10->addWidget(lineEdit_3, 2, 1, 1, 3);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_10->addWidget(lineEdit_4, 1, 1, 1, 3);

        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setEnabled(false);

        gridLayout_10->addWidget(lineEdit_8, 0, 1, 1, 3);

        lineEdit_19 = new QLineEdit(groupBox);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));

        gridLayout_10->addWidget(lineEdit_19, 4, 1, 1, 3);


        gridLayout_12->addLayout(gridLayout_10, 1, 0, 2, 2);


        gridLayout_14->addWidget(groupBox, 2, 0, 1, 2);

        groupBox_6 = new QGroupBox(id3mp3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_22 = new QGridLayout(groupBox_6);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        pushButton_12 = new QPushButton(groupBox_6);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Imagenes/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon14);
        pushButton_12->setIconSize(QSize(25, 25));

        gridLayout_13->addWidget(pushButton_12, 0, 0, 1, 1);

        volumeSlider_4 = new Phonon::VolumeSlider(groupBox_6);
        volumeSlider_4->setObjectName(QString::fromUtf8("volumeSlider_4"));

        gridLayout_13->addWidget(volumeSlider_4, 0, 6, 1, 1);

        pushButton_5 = new QPushButton(groupBox_6);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Imagenes/sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon15);
        pushButton_5->setIconSize(QSize(25, 25));

        gridLayout_13->addWidget(pushButton_5, 0, 8, 1, 1);

        pushButton_13 = new QPushButton(groupBox_6);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Imagenes/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon16);
        pushButton_13->setIconSize(QSize(25, 25));

        gridLayout_13->addWidget(pushButton_13, 0, 1, 1, 1);

        pushButton_14 = new QPushButton(groupBox_6);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/Imagenes/stop1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon17);
        pushButton_14->setIconSize(QSize(25, 25));

        gridLayout_13->addWidget(pushButton_14, 0, 2, 1, 1);

        lcdNumber_2 = new QLCDNumber(groupBox_6);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
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

        gridLayout_13->addWidget(lcdNumber_2, 0, 3, 1, 1);

        seekSlider_2 = new Phonon::SeekSlider(groupBox_6);
        seekSlider_2->setObjectName(QString::fromUtf8("seekSlider_2"));
        seekSlider_2->setMaximumSize(QSize(16777215, 20));

        gridLayout_13->addWidget(seekSlider_2, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_3, 0, 7, 1, 1);


        gridLayout_22->addLayout(gridLayout_13, 0, 0, 1, 1);


        gridLayout_14->addWidget(groupBox_6, 8, 0, 1, 2);

        groupBox_5 = new QGroupBox(id3mp3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_23 = new QGridLayout(groupBox_5);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_23->setContentsMargins(0, 0, 0, 0);
        gridLayout_20 = new QGridLayout();
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_20->addWidget(label_21, 0, 4, 1, 1);

        radioButton_2 = new QRadioButton(groupBox_5);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_20->addWidget(radioButton_2, 0, 2, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_20->addItem(horizontalSpacer_12, 0, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_20->addItem(horizontalSpacer_10, 0, 3, 1, 1);

        comboBox_4 = new QComboBox(groupBox_5);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setMinimumSize(QSize(150, 0));

        gridLayout_20->addWidget(comboBox_4, 0, 5, 1, 1);

        radioButton = new QRadioButton(groupBox_5);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_20->addWidget(radioButton, 0, 0, 1, 1);

        pushButton_20 = new QPushButton(groupBox_5);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/Imagenes/flechaOut.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_20->setIcon(icon18);
        pushButton_20->setIconSize(QSize(25, 25));

        gridLayout_20->addWidget(pushButton_20, 0, 6, 1, 1);

        pushButton_21 = new QPushButton(groupBox_5);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/Imagenes/flechaUp.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_21->setIcon(icon19);
        pushButton_21->setIconSize(QSize(25, 25));

        gridLayout_20->addWidget(pushButton_21, 0, 7, 1, 1);


        gridLayout_23->addLayout(gridLayout_20, 0, 0, 1, 1);


        gridLayout_14->addWidget(groupBox_5, 0, 0, 1, 2);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButton_3 = new QPushButton(id3mp3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon20);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout_6->addWidget(pushButton_3, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 0, 0, 1, 1);


        gridLayout_14->addLayout(gridLayout_6, 9, 0, 1, 2);

        progressBar = new QProgressBar(id3mp3);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_14->addWidget(progressBar, 7, 0, 1, 2);

        groupBox_8 = new QGroupBox(id3mp3);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_5 = new QGridLayout(groupBox_8);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_14, 1, 1, 1, 1);

        radioButton_9 = new QRadioButton(groupBox_8);
        radioButton_9->setObjectName(QString::fromUtf8("radioButton_9"));

        gridLayout_5->addWidget(radioButton_9, 1, 2, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_13, 1, 5, 1, 1);

        pushButton_23 = new QPushButton(groupBox_8);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        pushButton_23->setIcon(icon7);
        pushButton_23->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_23, 1, 7, 1, 1);

        radioButton_11 = new QRadioButton(groupBox_8);
        radioButton_11->setObjectName(QString::fromUtf8("radioButton_11"));

        gridLayout_5->addWidget(radioButton_11, 1, 4, 1, 1);

        pushButton_22 = new QPushButton(groupBox_8);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/Imagenes/thumbs_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_22->setIcon(icon21);
        pushButton_22->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_22, 1, 6, 1, 1);

        radioButton_10 = new QRadioButton(groupBox_8);
        radioButton_10->setObjectName(QString::fromUtf8("radioButton_10"));

        gridLayout_5->addWidget(radioButton_10, 1, 0, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_15, 1, 3, 1, 1);


        gridLayout_14->addWidget(groupBox_8, 5, 0, 1, 1);

        QWidget::setTabOrder(textEdit, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit_19);
        QWidget::setTabOrder(lineEdit_19, comboBox_2);
        QWidget::setTabOrder(comboBox_2, lineEdit_5);
        QWidget::setTabOrder(lineEdit_5, lineEdit_6);
        QWidget::setTabOrder(lineEdit_6, lineEdit_7);
        QWidget::setTabOrder(lineEdit_7, lineEdit_16);
        QWidget::setTabOrder(lineEdit_16, lineEdit_10);
        QWidget::setTabOrder(lineEdit_10, lineEdit_11);
        QWidget::setTabOrder(lineEdit_11, lineEdit_20);
        QWidget::setTabOrder(lineEdit_20, comboBox);
        QWidget::setTabOrder(comboBox, lineEdit_14);
        QWidget::setTabOrder(lineEdit_14, lineEdit_12);
        QWidget::setTabOrder(lineEdit_12, lineEdit_13);
        QWidget::setTabOrder(lineEdit_13, checkBox_3);
        QWidget::setTabOrder(checkBox_3, checkBox_4);
        QWidget::setTabOrder(checkBox_4, checkBox_5);
        QWidget::setTabOrder(checkBox_5, checkBox_8);
        QWidget::setTabOrder(checkBox_8, checkBox_6);
        QWidget::setTabOrder(checkBox_6, checkBox_7);
        QWidget::setTabOrder(checkBox_7, tableWidget);
        QWidget::setTabOrder(tableWidget, lineEdit_4);
        QWidget::setTabOrder(lineEdit_4, lineEdit_8);
        QWidget::setTabOrder(lineEdit_8, pushButton_3);
        QWidget::setTabOrder(pushButton_3, radioButton);
        QWidget::setTabOrder(radioButton, radioButton_2);
        QWidget::setTabOrder(radioButton_2, pushButton_12);
        QWidget::setTabOrder(pushButton_12, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton_13);
        QWidget::setTabOrder(pushButton_13, pushButton_14);
        QWidget::setTabOrder(pushButton_14, pushButton_17);
        QWidget::setTabOrder(pushButton_17, checkBox);
        QWidget::setTabOrder(checkBox, pushButton);
        QWidget::setTabOrder(pushButton, checkBox_2);
        QWidget::setTabOrder(checkBox_2, radioButton_7);
        QWidget::setTabOrder(radioButton_7, radioButton_4);
        QWidget::setTabOrder(radioButton_4, comboBox_3);
        QWidget::setTabOrder(comboBox_3, radioButton_5);
        QWidget::setTabOrder(radioButton_5, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_2);
        QWidget::setTabOrder(pushButton_2, radioButton_6);
        QWidget::setTabOrder(radioButton_6, lineEdit_15);
        QWidget::setTabOrder(lineEdit_15, radioButton_3);
        QWidget::setTabOrder(radioButton_3, lineEdit);
        QWidget::setTabOrder(lineEdit, lineEdit_9);
        QWidget::setTabOrder(lineEdit_9, comboBox_4);
        QWidget::setTabOrder(comboBox_4, radioButton_9);
        QWidget::setTabOrder(radioButton_9, pushButton_23);
        QWidget::setTabOrder(pushButton_23, radioButton_11);
        QWidget::setTabOrder(radioButton_11, pushButton_22);
        QWidget::setTabOrder(pushButton_22, radioButton_10);
        QWidget::setTabOrder(radioButton_10, checkBox_9);
        QWidget::setTabOrder(checkBox_9, checkBox_10);
        QWidget::setTabOrder(checkBox_10, pushButton_24);
        QWidget::setTabOrder(pushButton_24, pushButton_19);
        QWidget::setTabOrder(pushButton_19, pushButton_11);
        QWidget::setTabOrder(pushButton_11, pushButton_18);
        QWidget::setTabOrder(pushButton_18, pushButton_10);
        QWidget::setTabOrder(pushButton_10, pushButton_8);
        QWidget::setTabOrder(pushButton_8, pushButton_16);
        QWidget::setTabOrder(pushButton_16, pushButton_15);
        QWidget::setTabOrder(pushButton_15, pushButton_9);
        QWidget::setTabOrder(pushButton_9, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_7);
        QWidget::setTabOrder(pushButton_7, pushButton_20);
        QWidget::setTabOrder(pushButton_20, pushButton_21);

        retranslateUi(id3mp3);

        QMetaObject::connectSlotsByName(id3mp3);
    } // setupUi

    void retranslateUi(QDialog *id3mp3)
    {
        id3mp3->setWindowTitle(QApplication::translate("id3mp3", "Etiquetador v.0.1.0", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("id3mp3", "Grupo", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("id3mp3", "Busqueda", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("id3mp3", "Ano", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        comboBox->setToolTip(QApplication::translate("id3mp3", "Referencia de genero musical", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox->setStatusTip(QApplication::translate("id3mp3", "Referencia de genero musical", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox->setWhatsThis(QApplication::translate("id3mp3", "Referencia de genero musical", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_14->setText(QApplication::translate("id3mp3", "/", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_12->setToolTip(QApplication::translate("id3mp3", "Numero de pista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_12->setStatusTip(QApplication::translate("id3mp3", "Numero de pista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_12->setWhatsThis(QApplication::translate("id3mp3", "Numero de pista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_13->setText(QApplication::translate("id3mp3", "Numero de pista/Total pistas", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_13->setToolTip(QApplication::translate("id3mp3", "Numero total de pistas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_13->setStatusTip(QApplication::translate("id3mp3", "Numero total de pistas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_13->setWhatsThis(QApplication::translate("id3mp3", "Numero total de pistas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_14->setToolTip(QApplication::translate("id3mp3", "Anuario de creacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_14->setStatusTip(QApplication::translate("id3mp3", "Anuario de creacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_14->setWhatsThis(QApplication::translate("id3mp3", "Anuario de creacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_19->setText(QApplication::translate("id3mp3", "Genero", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_6->setToolTip(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_6->setStatusTip(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_6->setWhatsThis(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_6->setText(QApplication::translate("id3mp3", "Seleccionar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_9->setToolTip(QApplication::translate("id3mp3", "Si esta marcada no sigue el patron numerico TRACK/TOTAL", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_9->setStatusTip(QApplication::translate("id3mp3", "Si esta marcada no sigue el patron numerico TRACK/TOTAL", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_9->setWhatsThis(QApplication::translate("id3mp3", "Si esta marcada no sigue el patron numerico TRACK/TOTAL", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_9->setText(QApplication::translate("id3mp3", "Sin total", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_7->setToolTip(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_7->setStatusTip(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_7->setWhatsThis(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_7->setText(QApplication::translate("id3mp3", "Seleccionar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_8->setToolTip(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_8->setStatusTip(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_8->setWhatsThis(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_8->setText(QApplication::translate("id3mp3", "Seleccionar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_10->setToolTip(QApplication::translate("id3mp3", "Evita ceros a la izquierda en estructura numerico tipo 01,001,0001", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_10->setStatusTip(QApplication::translate("id3mp3", "Evita ceros a la izquierda en estructura numerico tipo 01,001,0001", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_10->setWhatsThis(QApplication::translate("id3mp3", "Evita ceros a la izquierda en estructura numerico tipo 01,001,0001", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_10->setText(QApplication::translate("id3mp3", "Evitar ceros a la izquierda", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("id3mp3", "Comentarios", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("id3mp3", "Nombre Artista", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_11->setToolTip(QApplication::translate("id3mp3", "Nombre del artista o grupo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_11->setStatusTip(QApplication::translate("id3mp3", "Nombre del artista o grupo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_11->setWhatsThis(QApplication::translate("id3mp3", "Nombre del artista o grupo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_10->setText(QApplication::translate("id3mp3", "Titulo Album", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_10->setToolTip(QApplication::translate("id3mp3", "Nombre del album", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_10->setStatusTip(QApplication::translate("id3mp3", "Nombre del album", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_10->setWhatsThis(QApplication::translate("id3mp3", "Nombre del album", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_20->setToolTip(QApplication::translate("id3mp3", "Comentarios del archivo de audio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_20->setStatusTip(QApplication::translate("id3mp3", "Comentarios del archivo de audio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_20->setWhatsThis(QApplication::translate("id3mp3", "Comentarios del archivo de audio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_16->setToolTip(QApplication::translate("id3mp3", "Titulo de la cancion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_16->setStatusTip(QApplication::translate("id3mp3", "Titulo de la cancion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_16->setWhatsThis(QApplication::translate("id3mp3", "Titulo de la cancion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_17->setText(QApplication::translate("id3mp3", "Titulo Cancion", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_3->setToolTip(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_3->setStatusTip(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_3->setWhatsThis(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_3->setText(QApplication::translate("id3mp3", "Seleccionar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_4->setToolTip(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_4->setStatusTip(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_4->setWhatsThis(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_4->setText(QApplication::translate("id3mp3", "Seleccionar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_5->setToolTip(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_5->setStatusTip(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_5->setWhatsThis(QApplication::translate("id3mp3", "Selecciona esta opcion en modo de cambio masivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_5->setText(QApplication::translate("id3mp3", "Seleccionar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_17->setToolTip(QApplication::translate("id3mp3", "Guarda la etiqueta en modo de cambio estandar ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_17->setStatusTip(QApplication::translate("id3mp3", "Guarda la etiqueta en modo de cambio estandar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_17->setWhatsThis(QApplication::translate("id3mp3", "Guarda la etiqueta en modo de cambio estandar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_17->setText(QApplication::translate("id3mp3", "Guardar etiqueta", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_2->setToolTip(QApplication::translate("id3mp3", "En la opcion de directorios se busca de formar recursiva", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_2->setStatusTip(QApplication::translate("id3mp3", "En la opcion de directorios se busca de formar recursiva", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_2->setWhatsThis(QApplication::translate("id3mp3", "En la opcion de directorios se busca de formar recursiva", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_2->setText(QApplication::translate("id3mp3", "Incluir subdirectorios", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        radioButton_7->setToolTip(QApplication::translate("id3mp3", "Se carga un directorio y todo los archivos compatibles", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_7->setStatusTip(QApplication::translate("id3mp3", "Se carga un directorio y todo los archivos compatibles", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_7->setWhatsThis(QApplication::translate("id3mp3", "Se carga un directorio y todo los archivos compatibles", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_7->setText(QApplication::translate("id3mp3", "Buscar directorio", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_4->setToolTip(QApplication::translate("id3mp3", "Se cargan manualmente los archivos de audio seleccionados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_4->setStatusTip(QApplication::translate("id3mp3", "Se cargan manualmente los archivos de audio seleccionados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_4->setWhatsThis(QApplication::translate("id3mp3", "Se cargan manualmente los archivos de audio seleccionados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_4->setText(QApplication::translate("id3mp3", "Buscar archivos", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("id3mp3", "Tipo de datos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_6->setToolTip(QApplication::translate("id3mp3", "Inserta un numero de orden en los titulos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_6->setStatusTip(QApplication::translate("id3mp3", "Inserta un numero de orden en los titulos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_6->setWhatsThis(QApplication::translate("id3mp3", "Inserta un numero de orden en los titulos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_6->setText(QApplication::translate("id3mp3", "Insertar un numero", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_3->setToolTip(QApplication::translate("id3mp3", "Es lo mismo que el individual pero se selecciona de lista de archivos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_3->setStatusTip(QApplication::translate("id3mp3", "Es lo mismo que el individual pero se selecciona de lista de archivos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_3->setWhatsThis(QApplication::translate("id3mp3", "Es lo mismo que el individual pero se selecciona de lista de archivos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_3->setText(QApplication::translate("id3mp3", "Cambio estandar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("id3mp3", "-   Comenzar a partir de...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_9->setToolTip(QApplication::translate("id3mp3", "Numero de comienzo del orden", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_9->setStatusTip(QApplication::translate("id3mp3", "Numero de comienzo del orden", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_9->setWhatsThis(QApplication::translate("id3mp3", "Numero de comienzo del orden", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        lineEdit_9->setText(QApplication::translate("id3mp3", "1", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("id3mp3", "Si se activa esta opcion se hacen cambios masivos e iguales en cada una de las etiquetas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox->setStatusTip(QApplication::translate("id3mp3", "Si se activa esta opcion se hacen cambios masivos e iguales en cada una de las etiquetas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox->setWhatsThis(QApplication::translate("id3mp3", "Si se activa esta opcion se hacen cambios masivos e iguales en cada una de las etiquetas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox->setText(QApplication::translate("id3mp3", "Cambio masivo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_5->setToolTip(QApplication::translate("id3mp3", "Se utiliza el nombre del archivo como titulo de la etiqueta", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_5->setStatusTip(QApplication::translate("id3mp3", "Se utiliza el nombre del archivo como titulo de la etiqueta", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_5->setWhatsThis(QApplication::translate("id3mp3", "Se utiliza el nombre del archivo como titulo de la etiqueta", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_5->setText(QApplication::translate("id3mp3", "Utilizar nombre como titulo", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("id3mp3", "Por defecto", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("id3mp3", "Sin estructura", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("id3mp3", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("id3mp3", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("id3mp3", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("id3mp3", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("id3mp3", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("id3mp3", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("id3mp3", "9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("id3mp3", "10", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_3->setToolTip(QApplication::translate("id3mp3", "Tipo de estructura numerica", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox_3->setStatusTip(QApplication::translate("id3mp3", "Tipo de estructura numerica", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox_3->setWhatsThis(QApplication::translate("id3mp3", "Tipo de estructura numerica", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_20->setText(QApplication::translate("id3mp3", "Estructura numerica", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_24->setToolTip(QApplication::translate("id3mp3", "Soluciona el desorden en lista de reproduccion de algunos aparatos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_24->setStatusTip(QApplication::translate("id3mp3", "Soluciona el desorden en lista de reproduccion de algunos aparatos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_24->setWhatsThis(QApplication::translate("id3mp3", "Soluciona el desorden en lista de reproduccion de algunos aparatos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_24->setText(QApplication::translate("id3mp3", "Solucionar desorden en listas de reproduccion", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("id3mp3", "Seleccion de los directorios/archivos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("id3mp3", "Seleccion de los directorios/archivos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("id3mp3", "Seleccion de los directorios/archivos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("id3mp3", "Seleccionar directorio", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_19->setToolTip(QApplication::translate("id3mp3", "Crea una lista de reproduccion compatible", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_19->setStatusTip(QApplication::translate("id3mp3", "Crea una lista de reproduccion compatible", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_19->setWhatsThis(QApplication::translate("id3mp3", "Crea una lista de reproduccion compatible", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_19->setText(QApplication::translate("id3mp3", "Crear lista de reproduccion (.m3u)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_11->setToolTip(QApplication::translate("id3mp3", "Se analizan los archivos cargados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_11->setStatusTip(QApplication::translate("id3mp3", "Se analizan los archivos cargados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_11->setWhatsThis(QApplication::translate("id3mp3", "Se analizan los archivos cargados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_11->setText(QApplication::translate("id3mp3", "Analizar mp3/ogg", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("id3mp3", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("id3mp3", "Ruta", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("id3mp3", "Titulo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("id3mp3", "Album ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("id3mp3", "Artista", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("id3mp3", "Comentarios", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("id3mp3", "Anuario", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("id3mp3", "Track", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("id3mp3", "Genero", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("id3mp3", "Marcar", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("id3mp3", "Peso en bytes", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QApplication::translate("id3mp3", "Ventana de lista de archivos cargados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget->setStatusTip(QApplication::translate("id3mp3", "Ventana de lista de archivos cargados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget->setWhatsThis(QApplication::translate("id3mp3", "Ventana de lista de archivos cargados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_16->setText(QApplication::translate("id3mp3", "Numero de mp3/ogg", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_15->setToolTip(QApplication::translate("id3mp3", "Numero de archivos cargados en la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_15->setStatusTip(QApplication::translate("id3mp3", "Numero de archivos cargados en la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_15->setWhatsThis(QApplication::translate("id3mp3", "Numero de archivos cargados en la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_18->setToolTip(QApplication::translate("id3mp3", "Borrado de todas las etiquetas con eleccion de la version a borrar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_18->setStatusTip(QApplication::translate("id3mp3", "Borrado de todas las etiquetas con eleccion de la version a borrar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_18->setWhatsThis(QApplication::translate("id3mp3", "Borrado de todas las etiquetas con eleccion de la version a borrar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_18->setText(QApplication::translate("id3mp3", "Borrar todas las etiquetas", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QApplication::translate("id3mp3", "Para los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_10->setStatusTip(QApplication::translate("id3mp3", "Para los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_10->setWhatsThis(QApplication::translate("id3mp3", "Para los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_10->setText(QApplication::translate("id3mp3", "Parar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_8->setToolTip(QApplication::translate("id3mp3", "Guardado de todas las etiquetas de la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_8->setStatusTip(QApplication::translate("id3mp3", "Guardado de todas las etiquetas de la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_8->setWhatsThis(QApplication::translate("id3mp3", "Guardado de todas las etiquetas de la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_8->setText(QApplication::translate("id3mp3", "Guardar etiquetas seleccionadas", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_16->setToolTip(QApplication::translate("id3mp3", "Deselecciona todos los archivos de la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_16->setStatusTip(QApplication::translate("id3mp3", "Deselecciona todos los archivos de la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_16->setWhatsThis(QApplication::translate("id3mp3", "Deselecciona todos los archivos de la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_16->setText(QApplication::translate("id3mp3", "Desmarcar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_15->setToolTip(QApplication::translate("id3mp3", "Selecciona todos los archivos de la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_15->setStatusTip(QApplication::translate("id3mp3", "Selecciona todos los archivos de la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_15->setWhatsThis(QApplication::translate("id3mp3", "Selecciona todos los archivos de la lista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_15->setText(QApplication::translate("id3mp3", "Marcar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_9->setToolTip(QApplication::translate("id3mp3", "Desmarca el archivo seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_9->setStatusTip(QApplication::translate("id3mp3", "Desmarca el archivo seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_9->setWhatsThis(QApplication::translate("id3mp3", "Desmarca el archivo seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_9->setText(QApplication::translate("id3mp3", "Desmarcar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("id3mp3", "Marca el archivo seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_6->setStatusTip(QApplication::translate("id3mp3", "Marca el archivo seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_6->setWhatsThis(QApplication::translate("id3mp3", "Marca el archivo seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_6->setText(QApplication::translate("id3mp3", "Marcar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("id3mp3", "Elimina el archivo seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_7->setStatusTip(QApplication::translate("id3mp3", "Elimina el archivo seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_7->setWhatsThis(QApplication::translate("id3mp3", "Elimina el archivo seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_7->setText(QApplication::translate("id3mp3", "Eliminar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("id3mp3", "Consola de procesos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit->setStatusTip(QApplication::translate("id3mp3", "Consola de procesos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QApplication::translate("id3mp3", "Consola de procesos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QApplication::translate("id3mp3", "Individual", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("id3mp3", "Genero", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        comboBox_2->setToolTip(QApplication::translate("id3mp3", "Referencia de genero musical", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox_2->setStatusTip(QApplication::translate("id3mp3", "Referencia de genero musical", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox_2->setWhatsThis(QApplication::translate("id3mp3", "Referencia de genero musical", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("id3mp3", "Guarda los cambios introducidos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("id3mp3", "Guarda los cambios introducidos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("id3mp3", "Guarda los cambios introducidos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("id3mp3", "Guardar etiqueta", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("id3mp3", "Localizar el archivo de audio en modalidad individual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("id3mp3", "Localizar el archivo de audio en modalidad individual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("id3mp3", "Localizar el archivo de audio en modalidad individual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("id3mp3", "Localizar mp3/ogg", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("id3mp3", " /", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("id3mp3", "Numero de pista/Total pistas", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_7->setToolTip(QApplication::translate("id3mp3", "Numero total de pistas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_7->setStatusTip(QApplication::translate("id3mp3", "Numero total de pistas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_7->setWhatsThis(QApplication::translate("id3mp3", "Numero total de pistas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_6->setText(QApplication::translate("id3mp3", "Ano", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_5->setToolTip(QApplication::translate("id3mp3", "Anuario de creacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_5->setStatusTip(QApplication::translate("id3mp3", "Anuario de creacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_5->setWhatsThis(QApplication::translate("id3mp3", "Anuario de creacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_6->setToolTip(QApplication::translate("id3mp3", "Numero de pista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_6->setStatusTip(QApplication::translate("id3mp3", "Numero de pista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_6->setWhatsThis(QApplication::translate("id3mp3", "Numero de pista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_9->setText(QApplication::translate("id3mp3", "Nombre mp3/ogg", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("id3mp3", "Titulo Cancion", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("id3mp3", "Titulo Album", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("id3mp3", "Nombre Artista", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("id3mp3", "Comentarios", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("id3mp3", "Nombre del artista o grupo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QApplication::translate("id3mp3", "Nombre del artista o grupo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("id3mp3", "Nombre del artista o grupo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_3->setToolTip(QApplication::translate("id3mp3", "Nombre del album", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_3->setStatusTip(QApplication::translate("id3mp3", "Nombre del album", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_3->setWhatsThis(QApplication::translate("id3mp3", "Nombre del album", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_4->setToolTip(QApplication::translate("id3mp3", "Titulo de la cancion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_4->setStatusTip(QApplication::translate("id3mp3", "Titulo de la cancion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_4->setWhatsThis(QApplication::translate("id3mp3", "Titulo de la cancion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_8->setToolTip(QApplication::translate("id3mp3", "Nombre del fichero de audio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_8->setStatusTip(QApplication::translate("id3mp3", "Nombre del fichero de audio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_8->setWhatsThis(QApplication::translate("id3mp3", "Nombre del fichero de audio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        lineEdit_19->setToolTip(QApplication::translate("id3mp3", "Comentarios del archivo de audio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_19->setStatusTip(QApplication::translate("id3mp3", "Comentarios del archivo de audio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_19->setWhatsThis(QApplication::translate("id3mp3", "Comentarios del archivo de audio", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_6->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_12->setToolTip(QApplication::translate("id3mp3", "Lanza la cancion seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_12->setStatusTip(QApplication::translate("id3mp3", "Lanza la cancion seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_12->setWhatsThis(QApplication::translate("id3mp3", "Lanza la cancion seleccionada", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_12->setText(QApplication::translate("id3mp3", "Play", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        volumeSlider_4->setToolTip(QApplication::translate("id3mp3", "Volumen del sonido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        volumeSlider_4->setStatusTip(QApplication::translate("id3mp3", "Volumen del sonido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        volumeSlider_4->setWhatsThis(QApplication::translate("id3mp3", "Volumen del sonido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("id3mp3", "Se accede al ecualizador grafico", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("id3mp3", "Se accede al ecualizador grafico", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("id3mp3", "Se accede al ecualizador grafico", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QApplication::translate("id3mp3", "Ecualizador", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_13->setToolTip(QApplication::translate("id3mp3", "Pausar/continuar el sonido actual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_13->setStatusTip(QApplication::translate("id3mp3", "Pausar/continuar el sonido actual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_13->setWhatsThis(QApplication::translate("id3mp3", "Pausar/continuar el sonido actual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_13->setText(QApplication::translate("id3mp3", "Pausa", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_14->setToolTip(QApplication::translate("id3mp3", "Parar el sonido actual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_14->setStatusTip(QApplication::translate("id3mp3", "Parar el sonido actual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_14->setWhatsThis(QApplication::translate("id3mp3", "Parar el sonido actual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_14->setText(QApplication::translate("id3mp3", "Stop", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lcdNumber_2->setToolTip(QApplication::translate("id3mp3", "Tiempo transcurrido de la pista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lcdNumber_2->setStatusTip(QApplication::translate("id3mp3", "Tiempo transcurrido de la pista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lcdNumber_2->setWhatsThis(QApplication::translate("id3mp3", "Tiempo transcurrido de la pista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        seekSlider_2->setToolTip(QApplication::translate("id3mp3", "Posicionamiento de la cancion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        seekSlider_2->setStatusTip(QApplication::translate("id3mp3", "Posicionamiento de la cancion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        seekSlider_2->setWhatsThis(QApplication::translate("id3mp3", "Posicionamiento de la cancion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_5->setTitle(QString());
        label_21->setText(QApplication::translate("id3mp3", "Version de etiquetado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_2->setToolTip(QApplication::translate("id3mp3", "Cargar lista de registros para etiquetar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_2->setStatusTip(QApplication::translate("id3mp3", "Cargar lista de registros para etiquetar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_2->setWhatsThis(QApplication::translate("id3mp3", "Cargar lista de registros para etiquetar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_2->setText(QApplication::translate("id3mp3", "Grupo", 0, QApplication::UnicodeUTF8));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("id3mp3", "id3v1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("id3mp3", "id3v2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("id3mp3", "Todas", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_4->setToolTip(QApplication::translate("id3mp3", "Version de etiquetado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox_4->setStatusTip(QApplication::translate("id3mp3", "Version de etiquetado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox_4->setWhatsThis(QApplication::translate("id3mp3", "Version de etiquetado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        radioButton->setToolTip(QApplication::translate("id3mp3", "Etiqueta de forma individual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton->setStatusTip(QApplication::translate("id3mp3", "Etiqueta de forma individual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton->setWhatsThis(QApplication::translate("id3mp3", "Etiqueta de forma individual", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton->setText(QApplication::translate("id3mp3", "Individual", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_20->setToolTip(QApplication::translate("id3mp3", "Importar etiquetas Version 1 a Version 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_20->setStatusTip(QApplication::translate("id3mp3", "Importar etiquetas Version 1 a Version 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_20->setWhatsThis(QApplication::translate("id3mp3", "Importar etiquetas Version 1 a Version 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_20->setText(QApplication::translate("id3mp3", "Importar id3v1 a id3v2", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_21->setToolTip(QApplication::translate("id3mp3", "Importar etiquetas Version 2 a Version 1", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_21->setStatusTip(QApplication::translate("id3mp3", "Importar etiquetas Version 2 a Version 1", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_21->setWhatsThis(QApplication::translate("id3mp3", "Importar etiquetas Version 2 a Version 1", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_21->setText(QApplication::translate("id3mp3", "Importar id3v2 a id3v1", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("id3mp3", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("id3mp3", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("id3mp3", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("id3mp3", "Salir", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("id3mp3", "Seleccion de tipo de borrado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_9->setToolTip(QApplication::translate("id3mp3", "Borrado de las etiquetas version 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_9->setStatusTip(QApplication::translate("id3mp3", "Borrado de las etiquetas version 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_9->setWhatsThis(QApplication::translate("id3mp3", "Borrado de las etiquetas version 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_9->setText(QApplication::translate("id3mp3", "Borrar etiquetas id3v2", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_23->setToolTip(QApplication::translate("id3mp3", "Cancelar borrado y cierre de este subgrupo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_23->setStatusTip(QApplication::translate("id3mp3", "Cancelar borrado y cierre de este subgrupo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_23->setWhatsThis(QApplication::translate("id3mp3", "Cancelar borrado y cierre de este subgrupo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_23->setText(QApplication::translate("id3mp3", "Cancelar borrado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_11->setToolTip(QApplication::translate("id3mp3", "Borrado de etiquetas version 1 y 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_11->setStatusTip(QApplication::translate("id3mp3", "Borrado de etiquetas version 1 y 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_11->setWhatsThis(QApplication::translate("id3mp3", "Borrado de etiquetas version 1 y 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_11->setText(QApplication::translate("id3mp3", "Borrar todas las etiquetas (Por defecto)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_22->setToolTip(QApplication::translate("id3mp3", "Borrado de las etiquetas seleccionadas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_22->setStatusTip(QApplication::translate("id3mp3", "Borrado de las etiquetas seleccionadas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_22->setWhatsThis(QApplication::translate("id3mp3", "Borrado de las etiquetas seleccionadas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_22->setText(QApplication::translate("id3mp3", "Realizar borrado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        radioButton_10->setToolTip(QApplication::translate("id3mp3", "Borrado de las etiquetas version 1", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        radioButton_10->setStatusTip(QApplication::translate("id3mp3", "Borrado de las etiquetas version 1", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        radioButton_10->setWhatsThis(QApplication::translate("id3mp3", "Borrado de las etiquetas version 1", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        radioButton_10->setText(QApplication::translate("id3mp3", "Borrar etiquetas id3v1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class id3mp3: public Ui_id3mp3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ID3MP3_H
