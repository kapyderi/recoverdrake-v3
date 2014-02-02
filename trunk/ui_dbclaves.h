/********************************************************************************
** Form generated from reading UI file 'dbclaves.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBCLAVES_H
#define UI_DBCLAVES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_dbclaves
{
public:
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_8;
    QCheckBox *checkBox_22;
    QPushButton *pushButton_4;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_11;
    QPushButton *pushButton_9;
    QPushButton *pushButton_12;
    QPushButton *pushButton_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_13;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QTableView *tableView;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QGridLayout *gridLayout_6;
    QComboBox *comboBox_2;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QLabel *label_3;
    QCheckBox *checkBox;
    QPushButton *pushButton_10;
    QTableWidget *tableWidget;

    void setupUi(QDialog *dbclaves)
    {
        if (dbclaves->objectName().isEmpty())
            dbclaves->setObjectName(QString::fromUtf8("dbclaves"));
        dbclaves->resize(956, 698);
        QFont font;
        font.setPointSize(7);
        dbclaves->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/security-mdk.png"), QSize(), QIcon::Normal, QIcon::Off);
        dbclaves->setWindowIcon(icon);
        gridLayout_8 = new QGridLayout(dbclaves);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton_7 = new QPushButton(dbclaves);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMaximumSize(QSize(31, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/izquierda.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon1);
        pushButton_7->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(dbclaves);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMaximumSize(QSize(31, 23));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/derecha.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon2);
        pushButton_8->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_8, 0, 1, 1, 1);

        lineEdit_8 = new QLineEdit(dbclaves);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy);

        gridLayout_5->addWidget(lineEdit_8, 0, 5, 1, 1);

        checkBox_22 = new QCheckBox(dbclaves);
        checkBox_22->setObjectName(QString::fromUtf8("checkBox_22"));
        checkBox_22->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));

        gridLayout_5->addWidget(checkBox_22, 0, 4, 1, 1);

        pushButton_4 = new QPushButton(dbclaves);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(25, 25));

        gridLayout_5->addWidget(pushButton_4, 0, 6, 1, 1);

        comboBox = new QComboBox(dbclaves);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));

        gridLayout_5->addWidget(comboBox, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_8->addLayout(gridLayout_5, 5, 0, 1, 2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_6 = new QPushButton(dbclaves);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/pelis.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon4);
        pushButton_6->setIconSize(QSize(25, 25));

        gridLayout_4->addWidget(pushButton_6, 0, 0, 1, 1);

        pushButton = new QPushButton(dbclaves);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon5);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout_4->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(dbclaves);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/sustituir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon6);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout_4->addWidget(pushButton_2, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(dbclaves);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon7);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout_4->addWidget(pushButton_3, 0, 3, 1, 1);

        pushButton_11 = new QPushButton(dbclaves);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/Error.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon8);
        pushButton_11->setIconSize(QSize(25, 25));

        gridLayout_4->addWidget(pushButton_11, 0, 4, 1, 1);

        pushButton_9 = new QPushButton(dbclaves);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setEnabled(true);
        pushButton_9->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Imagenes/impresora.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon9);
        pushButton_9->setIconSize(QSize(25, 25));

        gridLayout_4->addWidget(pushButton_9, 0, 5, 1, 1);

        pushButton_12 = new QPushButton(dbclaves);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Imagenes/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon10);
        pushButton_12->setIconSize(QSize(25, 25));

        gridLayout_4->addWidget(pushButton_12, 0, 6, 1, 1);

        pushButton_5 = new QPushButton(dbclaves);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Imagenes/Correcto.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon11);
        pushButton_5->setIconSize(QSize(25, 25));

        gridLayout_4->addWidget(pushButton_5, 0, 7, 1, 1);


        gridLayout_8->addLayout(gridLayout_4, 2, 0, 1, 2);

        groupBox = new QGroupBox(dbclaves);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 0, 4, 1, 1);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 0, 2, 1, 1);

        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout->addWidget(radioButton_4, 0, 6, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 7, 1, 1);

        pushButton_13 = new QPushButton(groupBox);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Imagenes/Fondo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_13->setIcon(icon12);
        pushButton_13->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_13, 0, 8, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 5, 1, 1);


        gridLayout_8->addWidget(groupBox, 1, 0, 1, 2);

        tableView = new QTableView(dbclaves);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        tableView->setFrameShadow(QFrame::Sunken);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        gridLayout_8->addWidget(tableView, 3, 0, 1, 2);

        groupBox_3 = new QGroupBox(dbclaves);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_9 = new QGridLayout(groupBox_3);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);

        gridLayout_2->addWidget(label_6, 0, 11, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout_2->addWidget(label_4, 0, 4, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font2);

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font2);

        gridLayout_2->addWidget(lineEdit_2, 0, 3, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(35, 0));
        lineEdit_3->setMaximumSize(QSize(35, 16777215));
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_3->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_3, 0, 5, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        gridLayout_2->addWidget(label_5, 0, 6, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setMinimumSize(QSize(35, 0));
        lineEdit_4->setMaximumSize(QSize(35, 16777215));
        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_4->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_4, 0, 10, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMinimumSize(QSize(45, 0));
        lineEdit_5->setMaximumSize(QSize(45, 16777215));
        lineEdit_5->setAlignment(Qt::AlignCenter);
        lineEdit_5->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_5, 0, 12, 1, 1);


        gridLayout_9->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setFont(font2);

        gridLayout_6->addWidget(comboBox_2, 0, 4, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        label_7->setFont(font3);

        gridLayout_6->addWidget(label_7, 0, 0, 1, 1);

        lineEdit_6 = new QLineEdit(groupBox_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout_6->addWidget(lineEdit_6, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        gridLayout_6->addWidget(label_3, 0, 3, 1, 1);

        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_6->addWidget(checkBox, 0, 7, 1, 1);

        pushButton_10 = new QPushButton(groupBox_3);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Imagenes/firefox.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon13);
        pushButton_10->setIconSize(QSize(25, 25));

        gridLayout_6->addWidget(pushButton_10, 0, 2, 1, 1);


        gridLayout_9->addLayout(gridLayout_6, 1, 0, 1, 1);


        gridLayout_8->addWidget(groupBox_3, 0, 0, 1, 2);

        tableWidget = new QTableWidget(dbclaves);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);

        gridLayout_8->addWidget(tableWidget, 4, 0, 1, 2);


        retranslateUi(dbclaves);

        QMetaObject::connectSlotsByName(dbclaves);
    } // setupUi

    void retranslateUi(QDialog *dbclaves)
    {
        dbclaves->setWindowTitle(QApplication::translate("dbclaves", "DBClaves v.0.1.0", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        checkBox_22->setText(QApplication::translate("dbclaves", "Ordenar", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("dbclaves", "Salir", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("dbclaves", "Sin filtro (todas las claves)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Tipo: Web", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Tipo: Banco", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Tipo: Movil", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Tipo: Ordenador", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Tipo: Caja fuerte", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Tipo: Otros", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Usuario", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Clave", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Encriptacion: Sin encriptar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Encriptacion: Encriptacion simple", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Encriptacion: Encriptacion doble", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Encriptacion: Encriptacion triple", 0, QApplication::UnicodeUTF8)
        );
        pushButton_6->setText(QApplication::translate("dbclaves", "Nueva clave", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("dbclaves", "Insertar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("dbclaves", "Modificar", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("dbclaves", "Eliminar", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("dbclaves", "Eliminar toda la DB", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("dbclaves", "Imprimir", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("dbclaves", "Exportar DB (.csv)", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("dbclaves", "Importar DB (.csv)", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("dbclaves", "Encriptacion", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("dbclaves", "Sin encriptar", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("dbclaves", "Encriptacion doble", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("dbclaves", "Encriptacion simple (Por defecto)", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("dbclaves", "Encriptacion triple", 0, QApplication::UnicodeUTF8));
        pushButton_13->setText(QApplication::translate("dbclaves", "Encriptar", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("dbclaves", "Datos", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("dbclaves", "-", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("dbclaves", "-", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("dbclaves", "Usuario", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("dbclaves", "Clave", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("dbclaves", "-", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("dbclaves", "Web", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Banco", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Movil", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Ordenador", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Caja fuerte", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("dbclaves", "Otros", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("dbclaves", "Pertenece a", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("dbclaves", "Tipo", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("dbclaves", "Mostrar normal", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("dbclaves", "Abrir", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("dbclaves", "Usuario", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("dbclaves", "Clave", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("dbclaves", "Tipo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("dbclaves", "Ubicacion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("dbclaves", "Pertenece a...", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("dbclaves", "Encriptada", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dbclaves: public Ui_dbclaves {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBCLAVES_H
