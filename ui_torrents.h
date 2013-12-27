/********************************************************************************
** Form generated from reading UI file 'torrents.ui'
**
** Created: Mon Oct 8 10:44:05 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TORRENTS_H
#define UI_TORRENTS_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_torrents
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton_3;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton_4;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QTableWidget *tableWidget;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QCheckBox *checkBox;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_2;
    QLabel *label_2;
    QLineEdit *lineEdit_6;
    QCheckBox *checkBox_3;
    QLineEdit *lineEdit_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_13;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;

    void setupUi(QDialog *torrents)
    {
        if (torrents->objectName().isEmpty())
            torrents->setObjectName(QString::fromUtf8("torrents"));
        torrents->setWindowModality(Qt::NonModal);
        torrents->resize(610, 604);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/drak.png"), QSize(), QIcon::Normal, QIcon::Off);
        torrents->setWindowIcon(icon);
        torrents->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Sans Serif\";\n"
"font: bold;"));
        gridLayout_2 = new QGridLayout(torrents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(torrents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout->addWidget(radioButton, 0, 0, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 2, 1, 1);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout->addWidget(radioButton_3, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 2);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 6);

        groupBox_2 = new QGroupBox(torrents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

        gridLayout_3->addWidget(radioButton_4, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_3->addWidget(lineEdit_4, 0, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 6);

        pushButton_5 = new QPushButton(torrents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/Correcto.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon1);

        gridLayout_2->addWidget(pushButton_5, 3, 0, 1, 1);

        pushButton_7 = new QPushButton(torrents);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon2);

        gridLayout_2->addWidget(pushButton_7, 3, 2, 1, 1);

        pushButton_6 = new QPushButton(torrents);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon3);

        gridLayout_2->addWidget(pushButton_6, 3, 5, 1, 1);

        tableWidget = new QTableWidget(torrents);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_2->addWidget(tableWidget, 4, 0, 1, 6);

        pushButton_4 = new QPushButton(torrents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(71, 23));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/puerta.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon4);

        gridLayout_2->addWidget(pushButton_4, 6, 5, 1, 1);

        groupBox_3 = new QGroupBox(torrents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_5->addWidget(checkBox, 0, 0, 1, 2);

        checkBox_4 = new QCheckBox(groupBox_3);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_5->addWidget(checkBox_4, 0, 6, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_3);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_5->addWidget(checkBox_5, 3, 0, 1, 2);

        checkBox_6 = new QCheckBox(groupBox_3);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        gridLayout_5->addWidget(checkBox_6, 3, 6, 1, 3);

        checkBox_2 = new QCheckBox(groupBox_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_5->addWidget(checkBox_2, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_5->addWidget(label_2, 1, 8, 1, 1);

        lineEdit_6 = new QLineEdit(groupBox_3);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setMaximumSize(QSize(31, 20));

        gridLayout_5->addWidget(lineEdit_6, 1, 7, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_3);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_5->addWidget(checkBox_3, 1, 6, 1, 1);

        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setMaximumSize(QSize(31, 20));

        gridLayout_5->addWidget(lineEdit_5, 1, 1, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 1, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 2, 0, 1, 6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        groupBox_4 = new QGroupBox(torrents);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(10, 16777215));

        gridLayout_4->addWidget(label_5, 0, 2, 1, 1);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 0, 3, 1, 1);

        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 0, 4, 1, 1);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 0, 5, 1, 5);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 2);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 1, 2, 1, 2);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 1, 4, 1, 1);

        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_4->addWidget(label_15, 1, 5, 1, 1);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_4->addWidget(label_16, 1, 6, 1, 1);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 1, 7, 1, 1);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 1, 8, 1, 1);

        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 1, 9, 1, 1);

        progressBar = new QProgressBar(groupBox_4);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_4->addWidget(progressBar, 2, 0, 1, 10);


        gridLayout_2->addWidget(groupBox_4, 5, 0, 1, 6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 6, 4, 1, 1);

        pushButton_3 = new QPushButton(torrents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 6, 0, 1, 1);


        retranslateUi(torrents);

        QMetaObject::connectSlotsByName(torrents);
    } // setupUi

    void retranslateUi(QDialog *torrents)
    {
        torrents->setWindowTitle(QApplication::translate("torrents", "KapTorrent", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("torrents", "Localizador de torrent", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("torrents", "Desde fichero", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("torrents", "...", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("torrents", "Desde url", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("torrents", "Desde magnet", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("torrents", "\302\277Donde guardar?", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("torrents", "Directorio", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("torrents", "...", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("torrents", "Insertar torrent a la cola", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("torrents", "Eliminar torrent de la cola", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("torrents", "Procesar cola", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("torrents", "Torrent", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("torrents", "Guardar en...", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("torrents", "Datos de configuracion", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("torrents", "Salir", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("torrents", "Opciones", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("torrents", "Sin limite de descarga", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("torrents", "Sin limite de subida", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("torrents", "Verificar tras la descarga", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("torrents", "Activar adicional NAT/UPnP", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("torrents", "Limitar descarga a...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("torrents", "Kb/s", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("torrents", "Limitar subida a...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("torrents", "Kb/s", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("torrents", "Datos de la descarga", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("torrents", "Pares", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label_5->setText(QApplication::translate("torrents", "/", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        label_10->setText(QApplication::translate("torrents", "Nombre", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        label_7->setText(QApplication::translate("torrents", "Descarga", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        label_9->setText(QApplication::translate("torrents", "Kb/s", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("torrents", "Compartido", 0, QApplication::UnicodeUTF8));
        label_16->setText(QString());
        label_12->setText(QApplication::translate("torrents", "Subida", 0, QApplication::UnicodeUTF8));
        label_14->setText(QString());
        label_13->setText(QApplication::translate("torrents", "Kb/s", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("torrents", "Pasar a segundo plano", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class torrents: public Ui_torrents {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TORRENTS_H
