/********************************************************************************
** Form generated from reading UI file 'televideo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELEVIDEO_H
#define UI_TELEVIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QWidget>
#include <phonon/videoplayer.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_Televideo
{
public:
    QGridLayout *gridLayout_5;
    Phonon::VideoPlayer *videoPlayer;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    Phonon::VolumeSlider *volumeSlider_6;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_3;
    QTableView *tableView;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;

    void setupUi(QDialog *Televideo)
    {
        if (Televideo->objectName().isEmpty())
            Televideo->setObjectName(QString::fromUtf8("Televideo"));
        Televideo->resize(696, 635);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/Television.png"), QSize(), QIcon::Normal, QIcon::Off);
        Televideo->setWindowIcon(icon);
        gridLayout_5 = new QGridLayout(Televideo);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        videoPlayer = new Phonon::VideoPlayer(Televideo);
        videoPlayer->setObjectName(QString::fromUtf8("videoPlayer"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(videoPlayer->sizePolicy().hasHeightForWidth());
        videoPlayer->setSizePolicy(sizePolicy);
        videoPlayer->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout_5->addWidget(videoPlayer, 0, 0, 1, 1);

        widget = new QWidget(Televideo);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMaximumSize(QSize(16777215, 220));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        volumeSlider_6 = new Phonon::VolumeSlider(groupBox);
        volumeSlider_6->setObjectName(QString::fromUtf8("volumeSlider_6"));
        sizePolicy.setHeightForWidth(volumeSlider_6->sizePolicy().hasHeightForWidth());
        volumeSlider_6->setSizePolicy(sizePolicy);
        volumeSlider_6->setMaximumSize(QSize(251, 21));

        gridLayout->addWidget(volumeSlider_6, 0, 8, 1, 1);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy2.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon2);

        gridLayout->addWidget(pushButton_6, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/abrir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon3);

        gridLayout->addWidget(pushButton_2, 0, 4, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon4);

        gridLayout->addWidget(pushButton_4, 0, 5, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/tv.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon5);

        gridLayout->addWidget(pushButton_5, 0, 7, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy2.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy2);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/stop1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon6);

        gridLayout->addWidget(pushButton_3, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 6, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableView = new QTableView(widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy3);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout_3->addWidget(tableView, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy4);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_9 = new QPushButton(groupBox_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy5);
        pushButton_9->setIcon(icon);

        gridLayout_2->addWidget(pushButton_9, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon7);

        gridLayout_2->addWidget(pushButton_8, 1, 0, 1, 1);

        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Imagenes/sustituir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon8);

        gridLayout_2->addWidget(pushButton_7, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);


        gridLayout_5->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(Televideo);

        QMetaObject::connectSlotsByName(Televideo);
    } // setupUi

    void retranslateUi(QDialog *Televideo)
    {
        Televideo->setWindowTitle(QApplication::translate("Televideo", "TeleDrake v.0.1.0", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("Televideo", "Play", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Televideo", "Pausa", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Televideo", "Abrir", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Televideo", "Salir", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Televideo", "Pantalla completa", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Televideo", "Stop", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        pushButton_9->setText(QApplication::translate("Televideo", "Cargar sop", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("Televideo", "Quitar emisora", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("Televideo", "Ocultar lista", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Televideo: public Ui_Televideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELEVIDEO_H
