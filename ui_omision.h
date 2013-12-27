/********************************************************************************
** Form generated from reading UI file 'omision.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OMISION_H
#define UI_OMISION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Omision
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *Omision)
    {
        if (Omision->objectName().isEmpty())
            Omision->setObjectName(QString::fromUtf8("Omision"));
        Omision->resize(761, 390);
        QFont font;
        font.setPointSize(7);
        Omision->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/Excluir.png"), QSize(), QIcon::Normal, QIcon::Off);
        Omision->setWindowIcon(icon);
        gridLayout = new QGridLayout(Omision);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(Omision);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 9);

        label_2 = new QLabel(Omision);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 2);

        label = new QLabel(Omision);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 7pt \"DejaVu Sans\";\n"
"color: rgb(255, 0, 0);\n"
"font: bold;"));

        gridLayout->addWidget(label, 2, 0, 1, 9);

        pushButton_2 = new QPushButton(Omision);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_2, 5, 8, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 7, 1, 1);

        label_3 = new QLabel(Omision);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 7);

        pushButton = new QPushButton(Omision);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton, 5, 0, 1, 1);

        pushButton_3 = new QPushButton(Omision);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/borrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_3, 5, 6, 1, 1);

        pushButton_4 = new QPushButton(Omision);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/boli.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon4);
        pushButton_4->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_4, 5, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 5, 1, 1, 4);


        retranslateUi(Omision);

        QMetaObject::connectSlotsByName(Omision);
    } // setupUi

    void retranslateUi(QDialog *Omision)
    {
        Omision->setWindowTitle(QApplication::translate("Omision", "Omitir en la sincronizacion v.0.1.0.", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QApplication::translate("Omision", "Ventana para introduccion de filtros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        textEdit->setStatusTip(QApplication::translate("Omision", "Ventana para introduccion de filtros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QApplication::translate("Omision", "Ventana para introduccion de filtros", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("Omision", "Nombre del objetivo:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Omision", "<html><head/><body><p><span style=\" text-decoration: underline; color:#ff0000;\">Como crear los filtros:</span></p><p><span style=\" color:#ff0000;\">- Los datos tienen que ir separados por (</span><span style=\" color:#0000ff;\">;</span><span style=\" color:#ff0000;\">). (Ejem. prueba;DIR:prueba2).</span></p><p><span style=\" color:#ff0000;\">- Si quieres filtrar directorios tienes que poner (</span><span style=\" color:#0000ff;\">DIR:</span><span style=\" color:#ff0000;\">) seguido de la palabra a filtrar (Ejem. DIR:prueba2).</span></p><p><span style=\" color:#ff0000;\">- El filtro es sensible a MAYUSCULAS y minusculas.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("Omision", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("Omision", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("Omision", "Nos vamos...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("Omision", "Salir", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("Omision", "Nombre del objetivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_3->setStatusTip(QApplication::translate("Omision", "Nombre del objetivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_3->setWhatsThis(QApplication::translate("Omision", "Nombre del objetivo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("Omision", "Guardar los filtros actuales", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("Omision", "Guardar los filtros actuales", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("Omision", "Guardar los filtros actuales", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("Omision", "Guardar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("Omision", "Borra todos los filtros (si no se guarda no habra modificacion)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("Omision", "Borra todos los filtros (si no se guarda no habra modificacion)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("Omision", "Borra todos los filtros (si no se guarda no habra modificacion)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("Omision", "Borrar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("Omision", "Editar el texto introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("Omision", "Editar el texto introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("Omision", "Editar el texto introducido", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("Omision", "Editar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Omision: public Ui_Omision {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OMISION_H
