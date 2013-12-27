/********************************************************************************
** Form generated from reading UI file 'md5sum.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MD5SUM_H
#define UI_MD5SUM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_md5sum
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_13;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *md5sum)
    {
        if (md5sum->objectName().isEmpty())
            md5sum->setObjectName(QString::fromUtf8("md5sum"));
        md5sum->resize(675, 190);
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(7);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        md5sum->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/lupaO.png"), QSize(), QIcon::Normal, QIcon::Off);
        md5sum->setWindowIcon(icon);
        gridLayout = new QGridLayout(md5sum);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(md5sum);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setPointSize(7);
        groupBox->setFont(font1);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(pushButton_3, 0, 1, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 2, 1, 4);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(pushButton_5, 1, 1, 1, 1);

        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_2->addWidget(lineEdit_4, 1, 2, 1, 4);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(150, 30));
        pushButton_4->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/Correcto.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(25, 25));

        gridLayout_2->addWidget(pushButton_4, 3, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 3, 2, 1, 1);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 3, 4, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(30, 25));
        label_13->setMaximumSize(QSize(30, 25));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/good.png")));
        label_13->setScaledContents(true);

        gridLayout_2->addWidget(label_13, 3, 5, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 2, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 4, 1, 2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 5);

        pushButton_2 = new QPushButton(md5sum);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QFont font2;
        font2.setPointSize(7);
        font2.setBold(false);
        font2.setWeight(50);
        pushButton_2->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        label_4 = new QLabel(md5sum);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        pushButton_6 = new QPushButton(md5sum);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon3);
        pushButton_6->setIconSize(QSize(25, 25));

        gridLayout->addWidget(pushButton_6, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);


        retranslateUi(md5sum);

        QMetaObject::connectSlotsByName(md5sum);
    } // setupUi

    void retranslateUi(QDialog *md5sum)
    {
        md5sum->setWindowTitle(QApplication::translate("md5sum", "Validar md5sum", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("md5sum", "Datos de comprabacion md5sum", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("md5sum", "Fichero a validar", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("md5sum", "...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("md5sum", "Fichero de validacion( md5)", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("md5sum", "...", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("md5sum", "Validar Archivo", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("md5sum", "Dato md5sum:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QString());
        label_5->setText(QApplication::translate("md5sum", "Validacion md5:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        pushButton_2->setText(QApplication::translate("md5sum", "Salir", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        pushButton_6->setText(QApplication::translate("md5sum", "Cancelar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class md5sum: public Ui_md5sum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MD5SUM_H
