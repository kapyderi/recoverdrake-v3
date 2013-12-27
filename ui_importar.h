/********************************************************************************
** Form generated from reading UI file 'importar.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTAR_H
#define UI_IMPORTAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_importar
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QTableWidget *tableWidget;

    void setupUi(QDialog *importar)
    {
        if (importar->objectName().isEmpty())
            importar->setObjectName(QString::fromUtf8("importar"));
        importar->resize(701, 371);
        QFont font;
        font.setPointSize(7);
        importar->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/migrationtools.png"), QSize(), QIcon::Normal, QIcon::Off);
        importar->setWindowIcon(icon);
        gridLayout = new QGridLayout(importar);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_2 = new QPushButton(importar);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);

        gridLayout->addWidget(pushButton_2, 10, 1, 1, 1);

        label_2 = new QLabel(importar);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 1, 1, 1);

        pushButton = new QPushButton(importar);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/service-mdk.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(30, 30));

        gridLayout->addWidget(pushButton, 6, 1, 1, 2);

        lineEdit = new QLineEdit(importar);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 3, 1, 1, 2);

        comboBox_2 = new QComboBox(importar);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 2);

        lineEdit_2 = new QLineEdit(importar);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 5, 1, 1, 2);

        label_4 = new QLabel(importar);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 2);

        pushButton_4 = new QPushButton(importar);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/snapshots.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(30, 30));

        gridLayout->addWidget(pushButton_4, 8, 1, 1, 2);

        pushButton_3 = new QPushButton(importar);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setIcon(icon);

        gridLayout->addWidget(pushButton_3, 10, 2, 1, 1);

        label = new QLabel(importar);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 9, 2, 1, 1);

        label_3 = new QLabel(importar);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 10));
        label_3->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"font: bold;"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_3, 10, 0, 1, 1);

        tableWidget = new QTableWidget(importar);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout->addWidget(tableWidget, 0, 0, 10, 1);


        retranslateUi(importar);

        QMetaObject::connectSlotsByName(importar);
    } // setupUi

    void retranslateUi(QDialog *importar)
    {
        importar->setWindowTitle(QApplication::translate("importar", "Importar datos", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("importar", "Salir", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("importar", "Valor destino:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("importar", "Relacionar", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("importar", "titulo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "titulo_original", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "edad", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "drama", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "comedia", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "accion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "aventura", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "scifi", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "romantica", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "musical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "catastrofes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "suspense", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "fantasia", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "erotico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "porno", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "historico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "policiaco", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "terror", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "western", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "belico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "deportes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "animacion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "documental", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "gore_zombies", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "caratula", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "actor", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "secundario", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "calificacion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "sinopsis", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "soporte", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "posicion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "visionada", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "duracion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "color", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "vose", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "formato", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "director", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("importar", "Fecha", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("importar", "Campos de la Base de Datos:", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("importar", "Deshacer relacion", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("importar", "Importar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("importar", "Valor origen:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("importar", "*Los campos que no esten relacionados no se importaran a la base de datos.", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("importar", "Campo a importar", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("importar", "Campo DB a relacionar", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("importar", "Valor origen", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("importar", "Valor destino", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("importar", "Aceptado", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class importar: public Ui_importar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTAR_H
