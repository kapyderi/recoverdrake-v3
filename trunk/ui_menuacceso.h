/********************************************************************************
** Form generated from reading UI file 'menuacceso.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUACCESO_H
#define UI_MENUACCESO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_MenuAcceso
{
public:
    QLabel *label_6;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QFrame *line;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QFrame *line_2;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QTextEdit *textEdit;
    QLabel *label_4;
    QPushButton *pushButton_6;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QLabel *label_11;
    QTextEdit *textEdit_4;
    QLabel *label_2;
    QTextEdit *textEdit_3;
    QTableView *tableView;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *MenuAcceso)
    {
        if (MenuAcceso->objectName().isEmpty())
            MenuAcceso->setObjectName(QString::fromUtf8("MenuAcceso"));
        MenuAcceso->setWindowModality(Qt::ApplicationModal);
        MenuAcceso->resize(760, 606);
        QFont font;
        font.setPointSize(7);
        MenuAcceso->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/tirachinas.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuAcceso->setWindowIcon(icon);
        MenuAcceso->setStyleSheet(QString::fromUtf8(""));
        label_6 = new QLabel(MenuAcceso);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(702, 494, 124, 71));
        label_6->setMinimumSize(QSize(124, 71));
        label_6->setMaximumSize(QSize(124, 71));
        label_6->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(MenuAcceso);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_2 = new QGroupBox(MenuAcceso);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 1, 0, 1, 4);

        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/embudo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon1);

        gridLayout_3->addWidget(pushButton_5, 3, 3, 1, 1);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);

        gridLayout_3->addWidget(pushButton_3, 5, 0, 1, 1);

        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/borrar.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon3);

        gridLayout_3->addWidget(pushButton_7, 3, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon4);

        gridLayout_3->addWidget(pushButton_4, 5, 3, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/sustituir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon5);

        gridLayout_3->addWidget(pushButton_2, 0, 3, 1, 1);

        line_2 = new QFrame(groupBox_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 4, 0, 1, 4);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon6);

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 2, 2, 1, 1);

        groupBox = new QGroupBox(MenuAcceso);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(501, 211));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 6, 0, 1, 3);

        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 8, 1, 1, 2);

        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 80));

        gridLayout->addWidget(textEdit, 5, 0, 1, 3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMaximumSize(QSize(92, 26));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/thumbs_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon7);

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 2, 1, 1, 2);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setMaximumSize(QSize(61, 20));

        gridLayout->addWidget(lineEdit_3, 0, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 8, 0, 1, 1);

        textEdit_4 = new QTextEdit(groupBox);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setMaximumSize(QSize(16777215, 80));

        gridLayout->addWidget(textEdit_4, 7, 0, 1, 3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 3);

        textEdit_3 = new QTextEdit(groupBox);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(textEdit_3, 3, 1, 1, 2);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 1);

        tableView = new QTableView(MenuAcceso);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setAlternatingRowColors(true);
        tableView->setSortingEnabled(true);

        gridLayout_2->addWidget(tableView, 4, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 2, 1, 1);


        retranslateUi(MenuAcceso);

        QMetaObject::connectSlotsByName(MenuAcceso);
    } // setupUi

    void retranslateUi(QDialog *MenuAcceso)
    {
        MenuAcceso->setWindowTitle(QApplication::translate("MenuAcceso", "Lanzador de paquetes del menu del escritorio", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MenuAcceso", "Navegacion", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MenuAcceso", "Filtrar", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MenuAcceso", "Eliminar", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("MenuAcceso", "Limpiar", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MenuAcceso", "Salir", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MenuAcceso", "Modificar", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MenuAcceso", "Insertar", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MenuAcceso", "Caracteristicas del Lanzador", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MenuAcceso", "Comentario en espanol", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MenuAcceso", "Categoria", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MenuAcceso", "Lanzar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MenuAcceso", "Nombre", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MenuAcceso", "Ejecutable", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MenuAcceso", "Codigo", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MenuAcceso", "Nombre en espanol", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MenuAcceso", "Comentario", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MenuAcceso: public Ui_MenuAcceso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUACCESO_H
