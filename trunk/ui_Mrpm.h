/********************************************************************************
** Form generated from reading UI file 'Mrpm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MRPM_H
#define UI_MRPM_H

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
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Mrpm
{
public:
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_16;
    QPushButton *pushButton_2;
    QGridLayout *gridLayout_3;
    QProgressBar *progressBar;
    QTableWidget *tableWidget;
    QTextEdit *textEdit;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_4;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_9;
    QPushButton *pushButton_3;
    QPushButton *pushButton_15;
    QPushButton *pushButton_14;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_17;
    QPushButton *pushButton_13;
    QLineEdit *lineEdit;
    QPushButton *pushButton_18;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_4;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QCheckBox *checkBox_5;
    QPushButton *pushButton_19;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_5;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QPushButton *pushButton_8;

    void setupUi(QDialog *Mrpm)
    {
        if (Mrpm->objectName().isEmpty())
            Mrpm->setObjectName(QString::fromUtf8("Mrpm"));
        Mrpm->resize(901, 609);
        Mrpm->setMinimumSize(QSize(738, 609));
        QFont font;
        font.setPointSize(7);
        Mrpm->setFont(font);
        Mrpm->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/rpm.png"), QSize(), QIcon::Normal, QIcon::Off);
        Mrpm->setWindowIcon(icon);
        gridLayout_9 = new QGridLayout(Mrpm);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        pushButton_16 = new QPushButton(Mrpm);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_16->setIcon(icon1);

        gridLayout_7->addWidget(pushButton_16, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(Mrpm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);

        gridLayout_7->addWidget(pushButton_2, 0, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_7, 4, 2, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        progressBar = new QProgressBar(Mrpm);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_3->addWidget(progressBar, 0, 1, 1, 2);


        gridLayout_9->addLayout(gridLayout_3, 4, 0, 1, 1);

        tableWidget = new QTableWidget(Mrpm);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        __qtablewidgetitem->setIcon(icon);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/mandrivaupdate.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setIcon(icon3);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/Correcto.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setIcon(icon4);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/notas.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setIcon(icon5);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/programacion.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setIcon(icon6);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setIcon(icon7);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        tableWidget->setFont(font1);
        tableWidget->setAutoScrollMargin(26);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->horizontalHeader()->setMinimumSectionSize(100);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(25);
        tableWidget->verticalHeader()->setMinimumSectionSize(25);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->verticalHeader()->setStretchLastSection(true);

        gridLayout_9->addWidget(tableWidget, 0, 0, 1, 1);

        textEdit = new QTextEdit(Mrpm);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nimbus Sans L Condensed"));
        font2.setPointSize(8);
        textEdit->setFont(font2);

        gridLayout_9->addWidget(textEdit, 3, 0, 1, 3);

        groupBox_4 = new QGroupBox(Mrpm);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_8 = new QGridLayout(groupBox_4);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon8);
        pushButton_4->setIconSize(QSize(25, 25));

        gridLayout_8->addWidget(pushButton_4, 0, 0, 1, 1);

        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font3;
        font3.setPointSize(7);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);

        gridLayout_8->addWidget(label, 0, 1, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setMinimumSize(QSize(51, 20));
        lineEdit_2->setMaximumSize(QSize(61, 20));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setWeight(75);
        lineEdit_2->setFont(font4);
        lineEdit_2->setLayoutDirection(Qt::LeftToRight);
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_8->addWidget(lineEdit_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer, 0, 3, 1, 1);

        pushButton_9 = new QPushButton(groupBox_4);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Imagenes/peligro.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon9);
        pushButton_9->setIconSize(QSize(25, 25));

        gridLayout_8->addWidget(pushButton_9, 0, 4, 1, 1);

        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Imagenes/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon10);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout_8->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_15 = new QPushButton(groupBox_4);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Imagenes/ccm1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_15->setIcon(icon11);
        pushButton_15->setIconSize(QSize(25, 25));

        gridLayout_8->addWidget(pushButton_15, 1, 4, 1, 1);

        pushButton_14 = new QPushButton(groupBox_4);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setIcon(icon5);
        pushButton_14->setIconSize(QSize(25, 25));

        gridLayout_8->addWidget(pushButton_14, 2, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButton_17 = new QPushButton(groupBox_4);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Imagenes/atras.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_17->setIcon(icon12);

        gridLayout_6->addWidget(pushButton_17, 0, 3, 1, 1);

        pushButton_13 = new QPushButton(groupBox_4);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Imagenes/embudo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon13);
        pushButton_13->setIconSize(QSize(25, 25));

        gridLayout_6->addWidget(pushButton_13, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setWeight(75);
        lineEdit->setFont(font5);

        gridLayout_6->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton_18 = new QPushButton(groupBox_4);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Imagenes/adelante.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_18->setIcon(icon14);

        gridLayout_6->addWidget(pushButton_18, 0, 4, 1, 1);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: bold;\n"
"color: rgb(0, 0, 255);"));

        gridLayout_6->addWidget(label_2, 0, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout_6, 2, 1, 1, 4);


        gridLayout_9->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(Mrpm);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 60));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_4->addWidget(checkBox_3, 0, 0, 1, 1);

        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_4->addWidget(checkBox, 0, 1, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_4->addWidget(checkBox_2, 0, 2, 1, 1);

        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_4->addWidget(checkBox_4, 0, 3, 1, 1);


        gridLayout_9->addWidget(groupBox_3, 2, 0, 1, 3);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_2 = new QGroupBox(Mrpm);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(131, 0));
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(131, 0));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Imagenes/lupa.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon15);
        pushButton_6->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(131, 0));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Imagenes/sustituir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon16);
        pushButton_7->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_7, 4, 0, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout->addWidget(checkBox_5, 0, 0, 1, 1);

        pushButton_19 = new QPushButton(groupBox_2);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/Imagenes/escoba.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_19->setIcon(icon17);
        pushButton_19->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_19, 5, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(Mrpm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(131, 0));
        pushButton_10->setIcon(icon7);
        pushButton_10->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_10, 0, 0, 1, 2);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/Imagenes/lupaO.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon18);
        pushButton_5->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_5, 4, 0, 1, 2);

        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(131, 0));
        pushButton_12->setIcon(icon);
        pushButton_12->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_12, 3, 0, 1, 2);

        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(131, 0));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon19);
        pushButton_11->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_11, 6, 0, 1, 2);

        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(131, 0));
        pushButton_8->setIcon(icon);
        pushButton_8->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_8, 5, 0, 1, 2);


        gridLayout_5->addWidget(groupBox, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_5, 0, 2, 2, 1);

        QWidget::setTabOrder(lineEdit, pushButton_2);
        QWidget::setTabOrder(pushButton_2, textEdit);
        QWidget::setTabOrder(textEdit, pushButton_16);
        QWidget::setTabOrder(pushButton_16, pushButton_4);
        QWidget::setTabOrder(pushButton_4, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, pushButton_9);
        QWidget::setTabOrder(pushButton_9, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_15);
        QWidget::setTabOrder(pushButton_15, pushButton_14);
        QWidget::setTabOrder(pushButton_14, checkBox_3);
        QWidget::setTabOrder(checkBox_3, checkBox);
        QWidget::setTabOrder(checkBox, checkBox_2);
        QWidget::setTabOrder(checkBox_2, checkBox_4);
        QWidget::setTabOrder(checkBox_4, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_7);
        QWidget::setTabOrder(pushButton_7, checkBox_5);
        QWidget::setTabOrder(checkBox_5, pushButton_10);
        QWidget::setTabOrder(pushButton_10, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton_12);
        QWidget::setTabOrder(pushButton_12, pushButton_11);
        QWidget::setTabOrder(pushButton_11, pushButton_8);
        QWidget::setTabOrder(pushButton_8, pushButton_13);
        QWidget::setTabOrder(pushButton_13, tableWidget);

        retranslateUi(Mrpm);

        QMetaObject::connectSlotsByName(Mrpm);
    } // setupUi

    void retranslateUi(QDialog *Mrpm)
    {
        Mrpm->setWindowTitle(QApplication::translate("Mrpm", "Salvaguarda v.0.1.0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_16->setToolTip(QApplication::translate("Mrpm", "Parar los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_16->setStatusTip(QApplication::translate("Mrpm", "Parar los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_16->setWhatsThis(QApplication::translate("Mrpm", "Parar los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_16->setText(QApplication::translate("Mrpm", "Parar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("Mrpm", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("Mrpm", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("Mrpm", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("Mrpm", "Salir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        progressBar->setToolTip(QApplication::translate("Mrpm", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        progressBar->setStatusTip(QApplication::translate("Mrpm", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        progressBar->setWhatsThis(QApplication::translate("Mrpm", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Mrpm", "Nombre RPM", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Mrpm", "Instalado", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Mrpm", "Instalable", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Mrpm", "Descripcion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Mrpm", "Categoria", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Mrpm", "Marca", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QApplication::translate("Mrpm", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget->setStatusTip(QApplication::translate("Mrpm", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget->setWhatsThis(QApplication::translate("Mrpm", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("Mrpm", "Consola de procesos, donde se detalla al maximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit->setStatusTip(QApplication::translate("Mrpm", "Consola de procesos, donde se detalla al maximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QApplication::translate("Mrpm", "Consola de procesos, donde se detalla al maximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        textEdit->setHtml(QApplication::translate("Mrpm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Nimbus Sans L Condensed'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:7pt; font-weight:600;\"><br /></span></p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Mrpm", "Tratamiento de paquetes", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("Mrpm", "Carga de fichero de una salvaguarda anterior para poder instalar, depurar o modificar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("Mrpm", "Carga de fichero de una salvaguarda anterior para poder instalar, depurar o modificar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("Mrpm", "Carga de fichero de una salvaguarda anterior para poder instalar, depurar o modificar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("Mrpm", "Cargar fichero .lst", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Mrpm", "Total registros:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("Mrpm", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QApplication::translate("Mrpm", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("Mrpm", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_9->setToolTip(QApplication::translate("Mrpm", "Purgar la base de datos de paquetes con un diccionario de palabras a evitar. Para poder quitar, modificar o insertar palabras nuevas, entra en la opcion correspondiente en Preferencias.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_9->setStatusTip(QApplication::translate("Mrpm", "Purgar la base de datos de paquetes con un diccionario de palabras a evitar. Para poder quitar, modificar o insertar palabras nuevas, entra en la opcion correspondiente en Preferencias.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_9->setWhatsThis(QApplication::translate("Mrpm", "Purgar la base de datos de paquetes con un diccionario de palabras a evitar. Para poder quitar, modificar o insertar palabras nuevas, entra en la opcion correspondiente en Preferencias.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_9->setText(QApplication::translate("Mrpm", "Evitar \"Palabras Clave\"", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("Mrpm", "Generar un fichero .lst tanto de la carga de otro fichero tras depurarlo, como de la generacion de rpms del sistema.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("Mrpm", "Generar un fichero .lst tanto de la carga de otro fichero tras depurarlo, como de la generacion de rpms del sistema.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("Mrpm", "Generar un fichero .lst tanto de la carga de otro fichero tras depurarlo, como de la generacion de rpms del sistema.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("Mrpm", "Guardar fichero .lst", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_15->setToolTip(QApplication::translate("Mrpm", "Purgar los paquetes ya instalados en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_15->setStatusTip(QApplication::translate("Mrpm", "Purgar los paquetes ya instalados en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_15->setWhatsThis(QApplication::translate("Mrpm", "Purgar los paquetes ya instalados en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_15->setText(QApplication::translate("Mrpm", "Evitar \"Instalados\"", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_14->setToolTip(QApplication::translate("Mrpm", "Se genera el listado para poder luego guardarlo en un fichero (Salvaguarda)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_14->setStatusTip(QApplication::translate("Mrpm", "Se genera el listado para poder luego guardarlo en un fichero (Salvaguarda)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_14->setWhatsThis(QApplication::translate("Mrpm", "Se genera el listado para poder luego guardarlo en un fichero (Salvaguarda)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_14->setText(QApplication::translate("Mrpm", "Generar listado .lst", 0, QApplication::UnicodeUTF8));
        pushButton_17->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_13->setToolTip(QApplication::translate("Mrpm", "Se introduce la palabra clave a buscar y se localizaran todos los que contengan dichos caracteres resaltandolo de rojo.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_13->setStatusTip(QApplication::translate("Mrpm", "Se introduce la palabra clave a buscar y se localizaran todos los que contengan dichos caracteres resaltandolo de rojo.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_13->setWhatsThis(QApplication::translate("Mrpm", "Se introduce la palabra clave a buscar y se localizaran todos los que contengan dichos caracteres resaltandolo de rojo.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_13->setText(QApplication::translate("Mrpm", "Localizar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("Mrpm", "Introducir palabra o caracteres a buscar, luego pulsar el boton de localizar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QApplication::translate("Mrpm", "Introducir palabra o caracteres a buscar, luego pulsar el boton de localizar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit->setWhatsThis(QApplication::translate("Mrpm", "Introducir palabra o caracteres a buscar, luego pulsar el boton de localizar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        groupBox_3->setToolTip(QApplication::translate("Mrpm", "Opciones de urpmi que pueden ser elegidas entre las mostradas.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_3->setStatusTip(QApplication::translate("Mrpm", "Opciones de urpmi que pueden ser elegidas entre las mostradas.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupBox_3->setWhatsThis(QApplication::translate("Mrpm", "Opciones de urpmi que pueden ser elegidas entre las mostradas.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_3->setTitle(QApplication::translate("Mrpm", "Opciones de urpmi (para actualizacion)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_3->setToolTip(QApplication::translate("Mrpm", "Opcion de urpmi interactivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_3->setStatusTip(QApplication::translate("Mrpm", "Opcion de urpmi interactivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_3->setWhatsThis(QApplication::translate("Mrpm", "Opcion de urpmi interactivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_3->setText(QApplication::translate("Mrpm", "--auto (por defecto)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("Mrpm", "Opcion de urpmi para elegir todas las opciones posibles", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox->setStatusTip(QApplication::translate("Mrpm", "Opcion de urpmi para elegir todas las opciones posibles", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox->setWhatsThis(QApplication::translate("Mrpm", "Opcion de urpmi para elegir todas las opciones posibles", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox->setText(QApplication::translate("Mrpm", "--a", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_2->setToolTip(QApplication::translate("Mrpm", "Opcion de urpmi para forzar la instalaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_2->setStatusTip(QApplication::translate("Mrpm", "Opcion de urpmi para forzar la instalaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_2->setWhatsThis(QApplication::translate("Mrpm", "Opcion de urpmi para forzar la instalaciones", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_2->setText(QApplication::translate("Mrpm", "--force (No recomendado)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_4->setToolTip(QApplication::translate("Mrpm", "Opcion de urpmi para usar todas las opciones posibles de paquete", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_4->setStatusTip(QApplication::translate("Mrpm", "Opcion de urpmi para usar todas las opciones posibles de paquete", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_4->setWhatsThis(QApplication::translate("Mrpm", "Opcion de urpmi para usar todas las opciones posibles de paquete", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_4->setText(QApplication::translate("Mrpm", "--fuzzy (No recomendado)", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Mrpm", "Global", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("Mrpm", "Actualizacion de todos los paquetes de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("Mrpm", "Actualizacion de todos los paquetes de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("Mrpm", "Actualizacion de todos los paquetes de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("Mrpm", "Actualizar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("Mrpm", "Se realiza la comprobacion de todos los paquetes de la base de datos (Es un proceso muy largo, pero te informa de muchos datos adicionales).", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_6->setStatusTip(QApplication::translate("Mrpm", "Se realiza la comprobacion de todos los paquetes de la base de datos (Es un proceso muy largo, pero te informa de muchos datos adicionales).", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_6->setWhatsThis(QApplication::translate("Mrpm", "Se realiza la comprobacion de todos los paquetes de la base de datos (Es un proceso muy largo, pero te informa de muchos datos adicionales).", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_6->setText(QApplication::translate("Mrpm", "Comprobar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("Mrpm", "Se depura la base de datos activos, eliminando los que no se pueden instalar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_7->setStatusTip(QApplication::translate("Mrpm", "Se depura la base de datos activos, eliminando los que no se pueden instalar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_7->setWhatsThis(QApplication::translate("Mrpm", "Se depura la base de datos activos, eliminando los que no se pueden instalar.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_7->setText(QApplication::translate("Mrpm", "Depurar rpms", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_5->setToolTip(QApplication::translate("Mrpm", "Si esta marcado no se comprobaran los paquetes por lo que se acelera en un 50% el tiempo de espera para finalizar el proceso", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_5->setStatusTip(QApplication::translate("Mrpm", "Si esta marcado no se comprobaran los paquetes por lo que se acelera en un 50% el tiempo de espera para finalizar el proceso", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_5->setWhatsThis(QApplication::translate("Mrpm", "Si esta marcado no se comprobaran los paquetes por lo que se acelera en un 50% el tiempo de espera para finalizar el proceso", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_5->setText(QApplication::translate("Mrpm", "No realizar comprobacion", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_19->setToolTip(QApplication::translate("Mrpm", "Limpiar los datos cargados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_19->setStatusTip(QApplication::translate("Mrpm", "Limpiar los datos cargados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_19->setWhatsThis(QApplication::translate("Mrpm", "Limpiar los datos cargados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_19->setText(QApplication::translate("Mrpm", "Vaciar datos cargados", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Mrpm", "Individual", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QApplication::translate("Mrpm", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_10->setStatusTip(QApplication::translate("Mrpm", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_10->setWhatsThis(QApplication::translate("Mrpm", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_10->setText(QApplication::translate("Mrpm", "Marcar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("Mrpm", "Comprueba la disponibilidad solo el registro marcado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("Mrpm", "Comprueba la disponibilidad solo el registro marcado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("Mrpm", "Comprueba la disponibilidad solo el registro marcado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QApplication::translate("Mrpm", "Comprobar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_12->setToolTip(QApplication::translate("Mrpm", "Actualiza solo el registro marcado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_12->setStatusTip(QApplication::translate("Mrpm", "Actualiza solo el registro marcado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_12->setWhatsThis(QApplication::translate("Mrpm", "Actualiza solo el registro marcado.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_12->setText(QApplication::translate("Mrpm", "Actualizar marcados", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_11->setToolTip(QApplication::translate("Mrpm", "Elimina todos los registros marcados anteriormente.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_11->setStatusTip(QApplication::translate("Mrpm", "Elimina todos los registros marcados anteriormente.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_11->setWhatsThis(QApplication::translate("Mrpm", "Elimina todos los registros marcados anteriormente.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_11->setText(QApplication::translate("Mrpm", "Eliminar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_8->setToolTip(QApplication::translate("Mrpm", "Actualiza todos los registros marcados anteriormente.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_8->setStatusTip(QApplication::translate("Mrpm", "Actualiza todos los registros marcados anteriormente.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_8->setWhatsThis(QApplication::translate("Mrpm", "Actualiza todos los registros marcados anteriormente.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_8->setText(QApplication::translate("Mrpm", "Actualizar seleccionado", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Mrpm: public Ui_Mrpm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MRPM_H
