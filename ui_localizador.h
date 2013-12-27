/********************************************************************************
** Form generated from reading UI file 'localizador.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALIZADOR_H
#define UI_LOCALIZADOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Localizador
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QPushButton *pbAgregar;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *lblTamanio;
    QPushButton *pbEliminar;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Localizador)
    {
        if (Localizador->objectName().isEmpty())
            Localizador->setObjectName(QString::fromUtf8("Localizador"));
        Localizador->resize(624, 468);
        QFont font;
        font.setPointSize(7);
        Localizador->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        Localizador->setWindowIcon(icon);
        Localizador->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Localizador);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(Localizador);
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
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);

        gridLayout->addWidget(tableWidget, 0, 0, 12, 2);

        pbAgregar = new QPushButton(Localizador);
        pbAgregar->setObjectName(QString::fromUtf8("pbAgregar"));
        pbAgregar->setMaximumSize(QSize(210, 26));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbAgregar->setIcon(icon4);

        gridLayout->addWidget(pbAgregar, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(Localizador);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(210, 26));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/carpeta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon5);

        gridLayout->addWidget(pushButton_2, 1, 2, 1, 1);

        label = new QLabel(Localizador);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(210, 36));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Sans Serif\";\n"
"font: bold;"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 5, 2, 1, 1);

        label_4 = new QLabel(Localizador);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(210, 36));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("font: 75 20pt \"Sans Serif\";\n"
"font: bold;"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 7, 2, 1, 1);

        lblTamanio = new QLabel(Localizador);
        lblTamanio->setObjectName(QString::fromUtf8("lblTamanio"));
        lblTamanio->setMaximumSize(QSize(210, 36));
        lblTamanio->setFont(font1);
        lblTamanio->setStyleSheet(QString::fromUtf8("font: 75 20pt \"Sans Serif\";\n"
"font: bold;"));
        lblTamanio->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblTamanio, 6, 2, 1, 1);

        pbEliminar = new QPushButton(Localizador);
        pbEliminar->setObjectName(QString::fromUtf8("pbEliminar"));
        pbEliminar->setMaximumSize(QSize(210, 26));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbEliminar->setIcon(icon6);

        gridLayout->addWidget(pbEliminar, 2, 2, 1, 1);

        pushButton = new QPushButton(Localizador);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(210, 26));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon7);

        gridLayout->addWidget(pushButton, 11, 2, 1, 1);

        pushButton_3 = new QPushButton(Localizador);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(210, 26));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon8);

        gridLayout->addWidget(pushButton_3, 10, 2, 1, 1);


        retranslateUi(Localizador);

        QMetaObject::connectSlotsByName(Localizador);
    } // setupUi

    void retranslateUi(QDialog *Localizador)
    {
        Localizador->setWindowTitle(QApplication::translate("Localizador", "Ventana de anadido", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Localizador", "Archivo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Localizador", "Ruta", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Localizador", "Tamano", 0, QApplication::UnicodeUTF8));
        pbAgregar->setText(QApplication::translate("Localizador", "Agregar Ficheros", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Localizador", "Agregar Directorios", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Localizador", "Tamano total:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Localizador", "Mb", 0, QApplication::UnicodeUTF8));
        lblTamanio->setText(QString());
        pbEliminar->setText(QApplication::translate("Localizador", "Eliminar Datos", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Localizador", "Hecho!!!", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Localizador", "Salir sin cambios", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Localizador: public Ui_Localizador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALIZADOR_H
