/********************************************************************************
** Form generated from reading UI file 'wifi.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIFI_H
#define UI_WIFI_H

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
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_wifi
{
public:
    QGridLayout *gridLayout_5;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_11;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_7;
    QTableView *tableView;
    QLabel *label_3;
    QLineEdit *lineEdit_5;
    QLabel *label;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_12;
    QPushButton *pushButton_9;
    QTableView *tableView_2;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_4;
    QTableWidget *tableWidget;
    QPushButton *pushButton_14;
    QPushButton *pushButton_13;
    QPushButton *pushButton_6;

    void setupUi(QDialog *wifi)
    {
        if (wifi->objectName().isEmpty())
            wifi->setObjectName(QString::fromUtf8("wifi"));
        wifi->resize(740, 744);
        QFont font;
        font.setPointSize(7);
        wifi->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/tux.png"), QSize(), QIcon::Normal, QIcon::Off);
        wifi->setWindowIcon(icon);
        wifi->setStyleSheet(QString::fromUtf8(""));
        gridLayout_5 = new QGridLayout(wifi);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        textEdit = new QTextEdit(wifi);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setFont(font);
        textEdit->setReadOnly(true);

        gridLayout_5->addWidget(textEdit, 1, 0, 1, 1);

        progressBar = new QProgressBar(wifi);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_5->addWidget(progressBar, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(wifi);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_6 = new QGridLayout(groupBox);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_6->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_6->addWidget(lineEdit_3, 0, 1, 1, 1);

        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/borrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon1);

        gridLayout_6->addWidget(pushButton_11, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 3, 1, 1);

        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/embudo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon2);

        gridLayout_6->addWidget(pushButton_7, 0, 4, 1, 1);

        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        gridLayout_6->addWidget(tableView, 1, 0, 1, 5);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_6->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        lineEdit_5->setFont(font1);

        gridLayout_6->addWidget(lineEdit_5, 2, 1, 1, 2);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_6->addWidget(label, 2, 3, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font1);

        gridLayout_6->addWidget(lineEdit, 2, 4, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);

        gridLayout_3->addWidget(pushButton_3, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/sustituir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon4);

        gridLayout_3->addWidget(pushButton_10, 0, 2, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon5);

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 3, 1, 1);


        gridLayout_6->addLayout(gridLayout_3, 3, 0, 1, 5);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(wifi);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_7 = new QGridLayout(groupBox_2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_7->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_7->addWidget(lineEdit_4, 0, 1, 1, 1);

        pushButton_12 = new QPushButton(groupBox_2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setIcon(icon1);

        gridLayout_7->addWidget(pushButton_12, 0, 2, 1, 1);

        pushButton_9 = new QPushButton(groupBox_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setIcon(icon2);

        gridLayout_7->addWidget(pushButton_9, 0, 4, 1, 1);

        tableView_2 = new QTableView(groupBox_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setAlternatingRowColors(true);
        tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_2->setSortingEnabled(true);

        gridLayout_7->addWidget(tableView_2, 1, 0, 1, 5);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_7->addWidget(label_6, 2, 0, 1, 1);

        lineEdit_6 = new QLineEdit(groupBox_2);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setFont(font1);

        gridLayout_7->addWidget(lineEdit_6, 2, 1, 1, 2);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_7->addWidget(label_2, 2, 3, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font1);

        gridLayout_7->addWidget(lineEdit_2, 2, 4, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setIcon(icon5);

        gridLayout_2->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setIcon(icon4);

        gridLayout_2->addWidget(pushButton_8, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setIcon(icon3);

        gridLayout_2->addWidget(pushButton_5, 0, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 3, 1, 1);


        gridLayout_7->addLayout(gridLayout_2, 3, 0, 1, 5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_6, 0, 3, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_4 = new QPushButton(wifi);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon6);

        gridLayout_4->addWidget(pushButton_4, 4, 2, 1, 1);

        tableWidget = new QTableWidget(wifi);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/madwifi-logo-20081106-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::Dense4Pattern);
        QFont font2;
        font2.setPointSize(8);
        font2.setKerning(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem->setFont(font2);
        __qtablewidgetitem->setForeground(brush);
        __qtablewidgetitem->setIcon(icon7);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setAutoScrollMargin(26);
        tableWidget->setSortingEnabled(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);
        tableWidget->verticalHeader()->setMinimumSectionSize(50);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->verticalHeader()->setStretchLastSection(true);

        gridLayout_4->addWidget(tableWidget, 1, 0, 4, 1);

        pushButton_14 = new QPushButton(wifi);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/peligro.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon8);

        gridLayout_4->addWidget(pushButton_14, 3, 2, 1, 1);

        pushButton_13 = new QPushButton(wifi);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Imagenes/thumbs_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon9);

        gridLayout_4->addWidget(pushButton_13, 2, 2, 1, 1);

        pushButton_6 = new QPushButton(wifi);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Imagenes/Error.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon10);
        pushButton_6->setIconSize(QSize(50, 50));

        gridLayout_4->addWidget(pushButton_6, 1, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 3, 0, 1, 1);


        retranslateUi(wifi);

        QMetaObject::connectSlotsByName(wifi);
    } // setupUi

    void retranslateUi(QDialog *wifi)
    {
        wifi->setWindowTitle(QApplication::translate("wifi", "Supervisar red privada", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("wifi", "Lista blanca", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("wifi", "id", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("wifi", "Limpiar", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("wifi", "Filtrar", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("wifi", "ip", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("wifi", "MAC", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("wifi", "Eliminar", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("wifi", "Modificar", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("wifi", "Insertar", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("wifi", "Lista negra", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("wifi", "id", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("wifi", "Limpiar", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("wifi", "Filtrar", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("wifi", "ip", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("wifi", "MAC", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("wifi", "Insertar", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("wifi", "Modificar", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("wifi", "Eliminar", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("wifi", "Salir", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("wifi", "Direcci\303\263n IP localizada", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("wifi", "Mac", 0, QApplication::UnicodeUTF8));
        pushButton_14->setText(QApplication::translate("wifi", "Anadir a lista negra", 0, QApplication::UnicodeUTF8));
        pushButton_13->setText(QApplication::translate("wifi", "Anadir a lista blanca", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("wifi", "Comprobar \n"
"intrusos en\n"
"la red wifi", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wifi: public Ui_wifi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIFI_H
