/********************************************************************************
** Form generated from reading UI file 'sonido.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONIDO_H
#define UI_SONIDO_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Sonido
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QCheckBox *checkBox_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_20;
    QGridLayout *gridLayout_31;
    QLabel *label_175;
    QSlider *verticalSlider_2;
    QSlider *verticalSlider_9;
    QSlider *verticalSlider_10;
    QLabel *label_178;
    QLabel *label_179;
    QSlider *verticalSlider_3;
    QSlider *verticalSlider_5;
    QSlider *verticalSlider_7;
    QSlider *verticalSlider_8;
    QLabel *label_181;
    QLabel *label_177;
    QLabel *label_176;
    QLabel *label_180;
    QSlider *verticalSlider_6;
    QLabel *label_182;
    QSlider *verticalSlider_4;
    QSlider *verticalSlider;
    QLabel *label_174;
    QLabel *label_183;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Sonido)
    {
        if (Sonido->objectName().isEmpty())
            Sonido->setObjectName(QString::fromUtf8("Sonido"));
        Sonido->resize(522, 300);
        Sonido->setMaximumSize(QSize(522, 300));
        QFont font;
        font.setPointSize(7);
        Sonido->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        Sonido->setWindowIcon(icon);
        gridLayout = new QGridLayout(Sonido);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(Sonido);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/thumbs_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        checkBox_4 = new QCheckBox(Sonido);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout->addWidget(checkBox_4, 0, 0, 1, 5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(Sonido);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);

        gridLayout->addWidget(pushButton_2, 2, 2, 1, 1);

        pushButton_3 = new QPushButton(Sonido);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);

        gridLayout->addWidget(pushButton_3, 2, 4, 1, 1);

        groupBox_20 = new QGroupBox(Sonido);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        gridLayout_31 = new QGridLayout(groupBox_20);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        gridLayout_31->setContentsMargins(0, 0, 0, 0);
        label_175 = new QLabel(groupBox_20);
        label_175->setObjectName(QString::fromUtf8("label_175"));
        label_175->setAlignment(Qt::AlignCenter);

        gridLayout_31->addWidget(label_175, 1, 8, 1, 1);

        verticalSlider_2 = new QSlider(groupBox_20);
        verticalSlider_2->setObjectName(QString::fromUtf8("verticalSlider_2"));
        verticalSlider_2->setMinimum(-12);
        verticalSlider_2->setMaximum(12);
        verticalSlider_2->setOrientation(Qt::Vertical);
        verticalSlider_2->setTickPosition(QSlider::TicksBothSides);

        gridLayout_31->addWidget(verticalSlider_2, 0, 2, 1, 1);

        verticalSlider_9 = new QSlider(groupBox_20);
        verticalSlider_9->setObjectName(QString::fromUtf8("verticalSlider_9"));
        verticalSlider_9->setMinimum(-12);
        verticalSlider_9->setMaximum(12);
        verticalSlider_9->setOrientation(Qt::Vertical);
        verticalSlider_9->setTickPosition(QSlider::TicksBothSides);

        gridLayout_31->addWidget(verticalSlider_9, 0, 16, 1, 1);

        verticalSlider_10 = new QSlider(groupBox_20);
        verticalSlider_10->setObjectName(QString::fromUtf8("verticalSlider_10"));
        verticalSlider_10->setMinimum(-12);
        verticalSlider_10->setMaximum(12);
        verticalSlider_10->setOrientation(Qt::Vertical);
        verticalSlider_10->setTickPosition(QSlider::TicksBothSides);

        gridLayout_31->addWidget(verticalSlider_10, 0, 18, 1, 1);

        label_178 = new QLabel(groupBox_20);
        label_178->setObjectName(QString::fromUtf8("label_178"));
        label_178->setAlignment(Qt::AlignCenter);

        gridLayout_31->addWidget(label_178, 1, 4, 1, 1);

        label_179 = new QLabel(groupBox_20);
        label_179->setObjectName(QString::fromUtf8("label_179"));
        label_179->setAlignment(Qt::AlignCenter);

        gridLayout_31->addWidget(label_179, 1, 12, 1, 1);

        verticalSlider_3 = new QSlider(groupBox_20);
        verticalSlider_3->setObjectName(QString::fromUtf8("verticalSlider_3"));
        verticalSlider_3->setMinimum(-12);
        verticalSlider_3->setMaximum(12);
        verticalSlider_3->setOrientation(Qt::Vertical);
        verticalSlider_3->setTickPosition(QSlider::TicksBothSides);

        gridLayout_31->addWidget(verticalSlider_3, 0, 4, 1, 1);

        verticalSlider_5 = new QSlider(groupBox_20);
        verticalSlider_5->setObjectName(QString::fromUtf8("verticalSlider_5"));
        verticalSlider_5->setMinimum(-12);
        verticalSlider_5->setMaximum(12);
        verticalSlider_5->setValue(0);
        verticalSlider_5->setOrientation(Qt::Vertical);
        verticalSlider_5->setTickPosition(QSlider::TicksBothSides);

        gridLayout_31->addWidget(verticalSlider_5, 0, 8, 1, 1);

        verticalSlider_7 = new QSlider(groupBox_20);
        verticalSlider_7->setObjectName(QString::fromUtf8("verticalSlider_7"));
        verticalSlider_7->setMinimum(-12);
        verticalSlider_7->setMaximum(12);
        verticalSlider_7->setOrientation(Qt::Vertical);
        verticalSlider_7->setTickPosition(QSlider::TicksBothSides);

        gridLayout_31->addWidget(verticalSlider_7, 0, 12, 1, 1);

        verticalSlider_8 = new QSlider(groupBox_20);
        verticalSlider_8->setObjectName(QString::fromUtf8("verticalSlider_8"));
        verticalSlider_8->setMinimum(-12);
        verticalSlider_8->setMaximum(12);
        verticalSlider_8->setOrientation(Qt::Vertical);
        verticalSlider_8->setTickPosition(QSlider::TicksBothSides);

        gridLayout_31->addWidget(verticalSlider_8, 0, 14, 1, 1);

        label_181 = new QLabel(groupBox_20);
        label_181->setObjectName(QString::fromUtf8("label_181"));
        label_181->setAlignment(Qt::AlignCenter);

        gridLayout_31->addWidget(label_181, 1, 18, 1, 1);

        label_177 = new QLabel(groupBox_20);
        label_177->setObjectName(QString::fromUtf8("label_177"));
        label_177->setAlignment(Qt::AlignCenter);

        gridLayout_31->addWidget(label_177, 1, 14, 1, 1);

        label_176 = new QLabel(groupBox_20);
        label_176->setObjectName(QString::fromUtf8("label_176"));
        label_176->setAlignment(Qt::AlignCenter);

        gridLayout_31->addWidget(label_176, 1, 10, 1, 1);

        label_180 = new QLabel(groupBox_20);
        label_180->setObjectName(QString::fromUtf8("label_180"));
        label_180->setAlignment(Qt::AlignCenter);

        gridLayout_31->addWidget(label_180, 1, 0, 1, 1);

        verticalSlider_6 = new QSlider(groupBox_20);
        verticalSlider_6->setObjectName(QString::fromUtf8("verticalSlider_6"));
        verticalSlider_6->setMinimum(-12);
        verticalSlider_6->setMaximum(12);
        verticalSlider_6->setOrientation(Qt::Vertical);
        verticalSlider_6->setTickPosition(QSlider::TicksBothSides);

        gridLayout_31->addWidget(verticalSlider_6, 0, 10, 1, 1);

        label_182 = new QLabel(groupBox_20);
        label_182->setObjectName(QString::fromUtf8("label_182"));
        label_182->setAlignment(Qt::AlignCenter);

        gridLayout_31->addWidget(label_182, 1, 16, 1, 1);

        verticalSlider_4 = new QSlider(groupBox_20);
        verticalSlider_4->setObjectName(QString::fromUtf8("verticalSlider_4"));
        verticalSlider_4->setMinimum(-12);
        verticalSlider_4->setMaximum(12);
        verticalSlider_4->setOrientation(Qt::Vertical);
        verticalSlider_4->setTickPosition(QSlider::TicksBothSides);

        gridLayout_31->addWidget(verticalSlider_4, 0, 6, 1, 1);

        verticalSlider = new QSlider(groupBox_20);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setMinimum(-12);
        verticalSlider->setMaximum(12);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setTickPosition(QSlider::TicksBothSides);

        gridLayout_31->addWidget(verticalSlider, 0, 0, 1, 1);

        label_174 = new QLabel(groupBox_20);
        label_174->setObjectName(QString::fromUtf8("label_174"));
        label_174->setAlignment(Qt::AlignCenter);

        gridLayout_31->addWidget(label_174, 1, 2, 1, 1);

        label_183 = new QLabel(groupBox_20);
        label_183->setObjectName(QString::fromUtf8("label_183"));
        label_183->setAlignment(Qt::AlignCenter);

        gridLayout_31->addWidget(label_183, 1, 6, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_31->addItem(horizontalSpacer_5, 0, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_31->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_31->addItem(horizontalSpacer_6, 0, 7, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_31->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_31->addItem(horizontalSpacer_7, 0, 9, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_31->addItem(horizontalSpacer_8, 0, 11, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_31->addItem(horizontalSpacer_9, 0, 13, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_31->addItem(horizontalSpacer_10, 0, 15, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_31->addItem(horizontalSpacer_11, 0, 17, 1, 1);


        gridLayout->addWidget(groupBox_20, 1, 0, 1, 5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);


        retranslateUi(Sonido);

        QMetaObject::connectSlotsByName(Sonido);
    } // setupUi

    void retranslateUi(QDialog *Sonido)
    {
        Sonido->setWindowTitle(QApplication::translate("Sonido", "Ecualizador", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Sonido", "Aceptar", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("Sonido", "Activar ecualizador", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Sonido", "Restaurar", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Sonido", "Cancelar", 0, QApplication::UnicodeUTF8));
        groupBox_20->setTitle(QApplication::translate("Sonido", "Ecualizador", 0, QApplication::UnicodeUTF8));
        label_175->setText(QApplication::translate("Sonido", "500", 0, QApplication::UnicodeUTF8));
        label_178->setText(QApplication::translate("Sonido", "125", 0, QApplication::UnicodeUTF8));
        label_179->setText(QApplication::translate("Sonido", "2K", 0, QApplication::UnicodeUTF8));
        label_181->setText(QApplication::translate("Sonido", "16K", 0, QApplication::UnicodeUTF8));
        label_177->setText(QApplication::translate("Sonido", "4K", 0, QApplication::UnicodeUTF8));
        label_176->setText(QApplication::translate("Sonido", "1K", 0, QApplication::UnicodeUTF8));
        label_180->setText(QApplication::translate("Sonido", "32", 0, QApplication::UnicodeUTF8));
        label_182->setText(QApplication::translate("Sonido", "8K", 0, QApplication::UnicodeUTF8));
        label_174->setText(QApplication::translate("Sonido", "64", 0, QApplication::UnicodeUTF8));
        label_183->setText(QApplication::translate("Sonido", "250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Sonido: public Ui_Sonido {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONIDO_H
