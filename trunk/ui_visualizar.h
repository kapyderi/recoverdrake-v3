/********************************************************************************
** Form generated from reading UI file 'visualizar.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALIZAR_H
#define UI_VISUALIZAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Visualizar
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QTableView *tableView;
    QTextEdit *textEdit;

    void setupUi(QDialog *Visualizar)
    {
        if (Visualizar->objectName().isEmpty())
            Visualizar->setObjectName(QString::fromUtf8("Visualizar"));
        Visualizar->resize(520, 440);
        Visualizar->setMinimumSize(QSize(520, 440));
        QFont font;
        font.setPointSize(7);
        Visualizar->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/ojo2.png"), QSize(), QIcon::Normal, QIcon::Off);
        Visualizar->setWindowIcon(icon);
        Visualizar->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Visualizar);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(117, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        pushButton = new QPushButton(Visualizar);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        gridLayout->addWidget(pushButton, 3, 2, 1, 1);

        tableView = new QTableView(Visualizar);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setAlternatingRowColors(true);

        gridLayout->addWidget(tableView, 0, 0, 2, 4);

        textEdit = new QTextEdit(Visualizar);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 4);


        retranslateUi(Visualizar);
        QObject::connect(pushButton, SIGNAL(clicked()), Visualizar, SLOT(close()));

        QMetaObject::connectSlotsByName(Visualizar);
    } // setupUi

    void retranslateUi(QDialog *Visualizar)
    {
        Visualizar->setWindowTitle(QApplication::translate("Visualizar", "Logs de accesos a RecoverDrake", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Visualizar", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Visualizar: public Ui_Visualizar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZAR_H
