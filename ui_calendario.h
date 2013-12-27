/********************************************************************************
** Form generated from reading UI file 'calendario.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARIO_H
#define UI_CALENDARIO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Calendario
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QFrame *line_3;
    QFrame *line_2;
    QFrame *line;
    QProgressBar *progressBar;
    QPushButton *pushButton_6;
    QTextEdit *textEdit;
    QCalendarWidget *calendarWidget;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_9;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *Calendario)
    {
        if (Calendario->objectName().isEmpty())
            Calendario->setObjectName(QString::fromUtf8("Calendario"));
        Calendario->resize(1155, 590);
        QFont font;
        font.setPointSize(7);
        Calendario->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Calendario->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(Calendario);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        line_3 = new QFrame(Calendario);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 10, 4, 1, 1);

        line_2 = new QFrame(Calendario);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 6, 7, 1, 1);

        line = new QFrame(Calendario);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 6, 2, 1, 1);

        progressBar = new QProgressBar(Calendario);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setValue(0);

        gridLayout_2->addWidget(progressBar, 9, 0, 1, 12);

        pushButton_6 = new QPushButton(Calendario);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/lupaO.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon1);
        pushButton_6->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_6, 6, 0, 1, 1);

        textEdit = new QTextEdit(Calendario);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(textEdit, 8, 0, 1, 12);

        calendarWidget = new QCalendarWidget(Calendario);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy2);
        calendarWidget->setMinimumSize(QSize(0, 250));
        calendarWidget->setGridVisible(true);
        calendarWidget->setDateEditEnabled(false);

        gridLayout_2->addWidget(calendarWidget, 0, 0, 6, 12);

        pushButton_3 = new QPushButton(Calendario);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_3, 10, 0, 1, 1);

        tableWidget = new QTableWidget(Calendario);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setSortingEnabled(true);

        gridLayout_2->addWidget(tableWidget, 7, 0, 1, 12);

        pushButton_2 = new QPushButton(Calendario);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_2, 6, 6, 1, 1);

        pushButton_9 = new QPushButton(Calendario);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon3);
        pushButton_9->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_9, 6, 8, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 6, 9, 1, 3);

        pushButton = new QPushButton(Calendario);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon4);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton, 10, 11, 1, 1);

        pushButton_8 = new QPushButton(Calendario);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/console-mdk.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon5);
        pushButton_8->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_8, 10, 10, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 10, 9, 1, 1);

        pushButton_11 = new QPushButton(Calendario);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/BACKUP.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon6);
        pushButton_11->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_11, 6, 1, 1, 1);

        pushButton_10 = new QPushButton(Calendario);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon7);
        pushButton_10->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_10, 10, 5, 1, 1);

        pushButton_12 = new QPushButton(Calendario);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_12->setIcon(icon8);
        pushButton_12->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_12, 6, 3, 1, 1);

        pushButton_5 = new QPushButton(Calendario);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Imagenes/menos.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon9);
        pushButton_5->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_5, 10, 3, 1, 1);

        pushButton_4 = new QPushButton(Calendario);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Imagenes/mas.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon10);
        pushButton_4->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_4, 10, 1, 1, 2);

        pushButton_7 = new QPushButton(Calendario);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Imagenes/peligro.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon11);
        pushButton_7->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_7, 6, 4, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(Calendario);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(Calendario);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        gridLayout_3->addLayout(verticalLayout, 1, 0, 1, 1);


        retranslateUi(Calendario);

        QMetaObject::connectSlotsByName(Calendario);
    } // setupUi

    void retranslateUi(QDialog *Calendario)
    {
        Calendario->setWindowTitle(QApplication::translate("Calendario", "Recuperador de copias de sincronizacion v.0.1.0", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QApplication::translate("Calendario", "Filtra por fecha seleccionada o volver a estado original", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_6->setStatusTip(QApplication::translate("Calendario", "Filtra por fecha seleccionada o volver a estado original", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_6->setWhatsThis(QApplication::translate("Calendario", "Filtra por fecha seleccionada o volver a estado original", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_6->setText(QApplication::translate("Calendario", "Filtrar por fecha", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("Calendario", "Consola de procesos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit->setStatusTip(QApplication::translate("Calendario", "Consola de procesos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QApplication::translate("Calendario", "Consola de procesos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        calendarWidget->setToolTip(QApplication::translate("Calendario", "Calendario para ver cronologicamente las copias guardadas de sincronizacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        calendarWidget->setStatusTip(QApplication::translate("Calendario", "Calendario para ver cronologicamente las copias guardadas de sincronizacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        calendarWidget->setWhatsThis(QApplication::translate("Calendario", "Calendario para ver cronologicamente las copias guardadas de sincronizacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("Calendario", "Marcar o desmarcar individualmente el registro seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("Calendario", "Marcar o desmarcar individualmente el registro seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("Calendario", "Marcar o desmarcar individualmente el registro seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("Calendario", "Marcar/Desmarcar", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Calendario", "Nombre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Calendario", "Fecha", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Calendario", "Ruta", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Calendario", "Seleccionar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tableWidget->setToolTip(QApplication::translate("Calendario", "Visualizador de copias sincronizadas (Desde la fecha seleccionada hasta la actual)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        tableWidget->setStatusTip(QApplication::translate("Calendario", "Visualizador de copias sincronizadas (Desde la fecha seleccionada hasta la actual)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableWidget->setWhatsThis(QApplication::translate("Calendario", "Visualizador de copias sincronizadas (Desde la fecha seleccionada hasta la actual)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("Calendario", "Recuperar datos seleccionados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("Calendario", "Recuperar datos seleccionados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("Calendario", "Recuperar datos seleccionados", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("Calendario", "Recuperar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_9->setToolTip(QApplication::translate("Calendario", "Parar los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_9->setStatusTip(QApplication::translate("Calendario", "Parar los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_9->setWhatsThis(QApplication::translate("Calendario", "Parar los procesos en ejecucion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_9->setText(QApplication::translate("Calendario", "Parar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("Calendario", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("Calendario", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("Calendario", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("Calendario", "Salir", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Calendario", "Mostrar consola", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_11->setToolTip(QApplication::translate("Calendario", "Muestra solo las backups realizadas a mano", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_11->setStatusTip(QApplication::translate("Calendario", "Muestra solo las backups realizadas a mano", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_11->setWhatsThis(QApplication::translate("Calendario", "Muestra solo las backups realizadas a mano", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_11->setText(QApplication::translate("Calendario", "Mostrar Backup", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QApplication::translate("Calendario", "Realiza una copia de seguridad exclusiva del fichero seleccionado. No se borrara salvo que se elimine manualmente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_10->setStatusTip(QApplication::translate("Calendario", "Realiza una copia de seguridad exclusiva del fichero seleccionado. No se borrara salvo que se elimine manualmente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_10->setWhatsThis(QApplication::translate("Calendario", "Realiza una copia de seguridad exclusiva del fichero seleccionado. No se borrara salvo que se elimine manualmente", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_10->setText(QApplication::translate("Calendario", "Hacer Backup", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_12->setToolTip(QApplication::translate("Calendario", "Elimina el archivo seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_12->setStatusTip(QApplication::translate("Calendario", "Elimina el archivo seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_12->setWhatsThis(QApplication::translate("Calendario", "Elimina el archivo seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_12->setText(QApplication::translate("Calendario", "Eliminar seleccionado", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QApplication::translate("Calendario", "Desmarcar de forma masiva todos los registros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_5->setStatusTip(QApplication::translate("Calendario", "Desmarcar de forma masiva todos los registros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_5->setWhatsThis(QApplication::translate("Calendario", "Desmarcar de forma masiva todos los registros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_5->setText(QApplication::translate("Calendario", "Desmarcar Todo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("Calendario", "Marcar de forma masiva todos los registros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("Calendario", "Marcar de forma masiva todos los registros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("Calendario", "Marcar de forma masiva todos los registros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("Calendario", "Marcar Todo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QApplication::translate("Calendario", "Eliminar fisicamente la copia de los archivos sincronizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_7->setStatusTip(QApplication::translate("Calendario", "Eliminar fisicamente la copia de los archivos sincronizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_7->setWhatsThis(QApplication::translate("Calendario", "Eliminar fisicamente la copia de los archivos sincronizados.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_7->setText(QApplication::translate("Calendario", "Eliminar todo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("Calendario", "Ruta de la copia de sincronizacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_2->setStatusTip(QApplication::translate("Calendario", "Ruta de la copia de sincronizacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_2->setWhatsThis(QApplication::translate("Calendario", "Ruta de la copia de sincronizacion", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QString());
        label->setText(QApplication::translate("Calendario", "Ruta :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Calendario: public Ui_Calendario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARIO_H
