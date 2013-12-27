/********************************************************************************
** Form generated from reading UI file 'urpmi.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_URPMI_H
#define UI_URPMI_H

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

class Ui_urpmi
{
public:
    QGridLayout *gridLayout_5;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_14;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QLabel *label_2;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QLabel *label_3;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QTextEdit *textEdit;
    QGridLayout *gridLayout_3;
    QProgressBar *progressBar;
    QPushButton *pushButton_2;

    void setupUi(QDialog *urpmi)
    {
        if (urpmi->objectName().isEmpty())
            urpmi->setObjectName(QString::fromUtf8("urpmi"));
        urpmi->resize(877, 614);
        QFont font;
        font.setPointSize(7);
        urpmi->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/rpm.png"), QSize(), QIcon::Normal, QIcon::Off);
        urpmi->setWindowIcon(icon);
        urpmi->setStyleSheet(QString::fromUtf8(""));
        gridLayout_5 = new QGridLayout(urpmi);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tableWidget = new QTableWidget(urpmi);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem->setIcon(icon1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(671, 0));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        tableWidget->setFont(font1);
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setAutoScrollMargin(26);
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

        gridLayout_5->addWidget(tableWidget, 0, 0, 1, 4);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_2 = new QGroupBox(urpmi);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_14 = new QPushButton(groupBox_2);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(131, 0));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/lupaO.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon2);
        pushButton_14->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_14, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(131, 0));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_3, 4, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(131, 0));
        pushButton_6->setIcon(icon1);
        pushButton_6->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_6, 1, 0, 1, 1);

        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(131, 0));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon4);
        pushButton_7->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(131, 0));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/Correcto.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon5);
        pushButton_5->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_5, 3, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(urpmi);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setIcon(icon1);
        pushButton_10->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_10, 0, 0, 1, 2);

        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setIcon(icon4);
        pushButton_12->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_12, 3, 0, 1, 2);

        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setIcon(icon3);
        pushButton_11->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_11, 4, 0, 1, 2);


        gridLayout_4->addWidget(groupBox, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 3, 3, 1);

        horizontalSpacer_2 = new QSpacerItem(465, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        label = new QLabel(urpmi);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);

        gridLayout_5->addWidget(label, 2, 1, 1, 1);

        lineEdit_2 = new QLineEdit(urpmi);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(51, 20));
        lineEdit_2->setMaximumSize(QSize(61, 20));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setWeight(75);
        lineEdit_2->setFont(font3);
        lineEdit_2->setLayoutDirection(Qt::LeftToRight);
        lineEdit_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lineEdit_2, 2, 2, 1, 1);

        groupBox_3 = new QGroupBox(urpmi);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        label_2->setFont(font4);

        gridLayout_6->addWidget(label_2, 0, 0, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_3);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_6->addWidget(checkBox_5, 0, 1, 1, 1);

        checkBox_6 = new QCheckBox(groupBox_3);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        gridLayout_6->addWidget(checkBox_6, 0, 2, 1, 1);

        checkBox_7 = new QCheckBox(groupBox_3);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));

        gridLayout_6->addWidget(checkBox_7, 0, 3, 1, 1);

        checkBox_8 = new QCheckBox(groupBox_3);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));

        gridLayout_6->addWidget(checkBox_8, 0, 4, 1, 1);

        checkBox_9 = new QCheckBox(groupBox_3);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));

        gridLayout_6->addWidget(checkBox_9, 0, 5, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font4);

        gridLayout_6->addWidget(label_3, 1, 0, 1, 1);

        checkBox_10 = new QCheckBox(groupBox_3);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));

        gridLayout_6->addWidget(checkBox_10, 1, 1, 1, 1);

        checkBox_11 = new QCheckBox(groupBox_3);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));

        gridLayout_6->addWidget(checkBox_11, 1, 2, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 1, 0, 1, 3);

        textEdit = new QTextEdit(urpmi);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setSizeIncrement(QSize(0, 0));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Nimbus Sans L Condensed"));
        font5.setPointSize(8);
        textEdit->setFont(font5);
        textEdit->setFocusPolicy(Qt::TabFocus);
        textEdit->setStyleSheet(QString::fromUtf8(""));

        gridLayout_5->addWidget(textEdit, 3, 0, 1, 3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        progressBar = new QProgressBar(urpmi);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_3->addWidget(progressBar, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(urpmi);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon6);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 4, 0, 1, 4);


        retranslateUi(urpmi);

        QMetaObject::connectSlotsByName(urpmi);
    } // setupUi

    void retranslateUi(QDialog *urpmi)
    {
        urpmi->setWindowTitle(QApplication::translate("urpmi", "Mantenimiento de repositorios", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("urpmi", "Marca", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("urpmi", "Repositorio", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("urpmi", "Activado", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("urpmi", "Desactivado", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("urpmi", "Actualizable", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QApplication::translate("urpmi", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget->setStatusTip(QApplication::translate("urpmi", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget->setWhatsThis(QApplication::translate("urpmi", "Visor de registros de la base de datos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_2->setTitle(QApplication::translate("urpmi", "Acceso global", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_14->setToolTip(QApplication::translate("urpmi", "Comprobacion de todos los repositorios disponibles.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_14->setStatusTip(QApplication::translate("urpmi", "Comprobacion de todos los repositorios disponibles.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_14->setWhatsThis(QApplication::translate("urpmi", "Comprobacion de todos los repositorios disponibles.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_14->setText(QApplication::translate("urpmi", "Verificar repositorios", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("urpmi", "Eliminacion de todos los repositorios disponibles.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("urpmi", "Eliminacion de todos los repositorios disponibles.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("urpmi", "Eliminacion de todos los repositorios disponibles.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        pushButton_3->setAccessibleName(QApplication::translate("urpmi", "Eliminacion de todos los repositorios disponibles.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        pushButton_3->setText(QApplication::translate("urpmi", "Eliminar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("urpmi", "Seleccion masiva de todos los paquetes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_6->setStatusTip(QApplication::translate("urpmi", "Seleccion masiva de todos los paquetes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_6->setWhatsThis(QApplication::translate("urpmi", "Seleccion masiva de todos los paquetes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_6->setText(QApplication::translate("urpmi", "Marcar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("urpmi", "Deseleccion masiva de todos los paquetes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_7->setStatusTip(QApplication::translate("urpmi", "Deseleccion masiva de todos los paquetes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_7->setWhatsThis(QApplication::translate("urpmi", "Deseleccion masiva de todos los paquetes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_7->setText(QApplication::translate("urpmi", "Demarcar todos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("urpmi", "inserccion de todos los repositorios posibles de instalacion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("urpmi", "inserccion de todos los repositorios posibles de instalacion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("urpmi", "inserccion de todos los repositorios posibles de instalacion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        pushButton_5->setAccessibleName(QApplication::translate("urpmi", "inserccion de todos los repositorios posibles de instalacion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_ACCESSIBILITY
        pushButton_5->setText(QApplication::translate("urpmi", "Anadir todos", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("urpmi", "Acceso individual", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QApplication::translate("urpmi", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_10->setStatusTip(QApplication::translate("urpmi", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_10->setWhatsThis(QApplication::translate("urpmi", "Marca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_10->setText(QApplication::translate("urpmi", "Activar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_12->setToolTip(QApplication::translate("urpmi", "Desmarca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_12->setStatusTip(QApplication::translate("urpmi", "Desmarca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_12->setWhatsThis(QApplication::translate("urpmi", "Desmarca la linea activa de la base de datos para su tratamiento.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_12->setText(QApplication::translate("urpmi", "Desactivar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_11->setToolTip(QApplication::translate("urpmi", "Elimina todos los registros seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_11->setStatusTip(QApplication::translate("urpmi", "Elimina todos los registros seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_11->setWhatsThis(QApplication::translate("urpmi", "Elimina todos los registros seleccionados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_11->setText(QApplication::translate("urpmi", "Eliminar seleccionado", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("urpmi", "Total Repositorios:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("urpmi", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QApplication::translate("urpmi", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("urpmi", "Numero de registros activos en la base de datos activa.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        groupBox_3->setToolTip(QApplication::translate("urpmi", "Opciones de urpmi que pueden ser elegidas entre las mostradas.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox_3->setStatusTip(QApplication::translate("urpmi", "Opciones de urpmi que pueden ser elegidas entre las mostradas.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupBox_3->setWhatsThis(QApplication::translate("urpmi", "Opciones de urpmi que pueden ser elegidas entre las mostradas.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox_3->setTitle(QApplication::translate("urpmi", "Repositorios", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("urpmi", "Mandriva:", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("urpmi", "Oficiales", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("urpmi", "PLF", 0, QApplication::UnicodeUTF8));
        checkBox_7->setText(QApplication::translate("urpmi", "MIB", 0, QApplication::UnicodeUTF8));
        checkBox_8->setText(QApplication::translate("urpmi", "BDK", 0, QApplication::UnicodeUTF8));
        checkBox_9->setText(QApplication::translate("urpmi", "MUD", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("urpmi", "Mageia:", 0, QApplication::UnicodeUTF8));
        checkBox_10->setText(QApplication::translate("urpmi", "Oficiales", 0, QApplication::UnicodeUTF8));
        checkBox_11->setText(QApplication::translate("urpmi", "BDK", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("urpmi", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit->setStatusTip(QApplication::translate("urpmi", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QApplication::translate("urpmi", "Consola de procesos, donde se detalla al m\303\241ximo lo que va procesando.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        textEdit->setHtml(QApplication::translate("urpmi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Nimbus Sans L Condensed'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:7pt; font-weight:600;\"><br /></span></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        progressBar->setToolTip(QApplication::translate("urpmi", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        progressBar->setStatusTip(QApplication::translate("urpmi", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        progressBar->setWhatsThis(QApplication::translate("urpmi", "Ratio de procesos realizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("urpmi", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("urpmi", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("urpmi", "Nos vamos..", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("urpmi", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class urpmi: public Ui_urpmi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URPMI_H
