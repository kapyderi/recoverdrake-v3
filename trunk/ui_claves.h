/********************************************************************************
** Form generated from reading UI file 'claves.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLAVES_H
#define UI_CLAVES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_claves
{
public:
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QFrame *line_2;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QRadioButton *radioButton;
    QLabel *label_8;
    QRadioButton *radioButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton_3;
    QFrame *line;
    QLabel *label_5;
    QLabel *label_9;
    QLineEdit *lineEdit_4;
    QLabel *label_10;
    QLabel *label_6;
    QLineEdit *lineEdit_5;
    QLabel *label_7;
    QCheckBox *checkBox;

    void setupUi(QWidget *claves)
    {
        if (claves->objectName().isEmpty())
            claves->setObjectName(QString::fromUtf8("claves"));
        claves->resize(650, 520);
        claves->setMinimumSize(QSize(650, 520));
        claves->setMaximumSize(QSize(650, 520));
        QFont font;
        font.setPointSize(7);
        claves->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/usuario.png"), QSize(), QIcon::Normal, QIcon::Off);
        claves->setWindowIcon(icon);
        claves->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(claves);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(claves);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 3, 0, 1, 1);

        lineEdit_3 = new QLineEdit(claves);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setMaximumSize(QSize(50, 16777215));

        gridLayout_3->addWidget(lineEdit_3, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        pushButton_7 = new QPushButton(claves);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/nucleo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon1);
        pushButton_7->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_7, 3, 3, 1, 1);

        pushButton_4 = new QPushButton(claves);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);
        pushButton_4->setIconSize(QSize(25, 25));

        gridLayout_3->addWidget(pushButton_4, 3, 4, 1, 1);

        tableView = new QTableView(claves);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        gridLayout_3->addWidget(tableView, 2, 0, 1, 5);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(claves);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(claves);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/sustituir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(claves);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon4);
        pushButton_3->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        pushButton_6 = new QPushButton(claves);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/borrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon5);
        pushButton_6->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_6, 0, 4, 1, 1);

        pushButton_5 = new QPushButton(claves);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/embudo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon6);
        pushButton_5->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_5, 0, 5, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 5);

        groupBox = new QGroupBox(claves);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 0, 4, 5, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 5, 1, 2);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 2);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 1, 2, 1, 2);

        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        gridLayout_2->addWidget(radioButton, 1, 5, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 2, 2, 1, 2);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_2->addWidget(radioButton_2, 2, 5, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 3, 0, 1, 3);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 3, 3, 1, 1);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_2->addWidget(radioButton_3, 3, 5, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 5, 0, 3, 7);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 9, 0, 1, 2);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 12pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout_2->addWidget(label_9, 9, 2, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_2->addWidget(lineEdit_4, 9, 3, 1, 3);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(10, 16777215));
        label_10->setStyleSheet(QString::fromUtf8("font: 12pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout_2->addWidget(label_10, 9, 6, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 10, 0, 1, 2);

        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout_2->addWidget(lineEdit_5, 10, 2, 1, 5);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 8, 0, 1, 7);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_2->addWidget(checkBox, 0, 0, 1, 4);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 5);


        retranslateUi(claves);

        QMetaObject::connectSlotsByName(claves);
    } // setupUi

    void retranslateUi(QWidget *claves)
    {
        claves->setWindowTitle(QApplication::translate("claves", "Introducir usuarios y clave", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("claves", "Cod.", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("claves", "Mostrar Administrador (Solo mantenimiento)", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("claves", "Continuar", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("claves", "Insertar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("claves", "Modificar", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("claves", "Eliminar", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("claves", "Limpiar", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("claves", "Filtrar", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("claves", "Usuarios del sistema", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("claves", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Niveles de seguridad</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("claves", "Usuario(*)", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("claves", "Nivel 1 (Bajo)", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("claves", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:6pt; color:#ff0000;\">(*) El Usuario no se puede modificar.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("claves", "Nivel 2 (Medio)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("claves", "Contrasena", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("claves", "Nivel 3 (Alto)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("claves", "Pregunta:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("claves", "\302\277", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("claves", "?", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("claves", "Respuesta:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("claves", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Recuperador de claves de acceso</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("claves", "Activo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class claves: public Ui_claves {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLAVES_H
