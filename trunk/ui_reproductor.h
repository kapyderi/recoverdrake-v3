/********************************************************************************
** Form generated from reading UI file 'reproductor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPRODUCTOR_H
#define UI_REPRODUCTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>
#include <phonon/seekslider.h>
#include <phonon/videoplayer.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_Reproductor
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    Phonon::VolumeSlider *volumeSlider_5;
    QLCDNumber *lcdNumber;
    Phonon::SeekSlider *seekSlider;
    Phonon::VideoPlayer *videoPlayer;

    void setupUi(QWidget *Reproductor)
    {
        if (Reproductor->objectName().isEmpty())
            Reproductor->setObjectName(QString::fromUtf8("Reproductor"));
        Reproductor->resize(650, 493);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Reproductor->sizePolicy().hasHeightForWidth());
        Reproductor->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(7);
        Reproductor->setFont(font);
        Reproductor->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/multimedia.png"), QSize(), QIcon::Normal, QIcon::Off);
        Reproductor->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(Reproductor);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Reproductor);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 150));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/stop1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);

        gridLayout->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon3);

        gridLayout->addWidget(pushButton_6, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/abrir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);

        gridLayout->addWidget(pushButton_2, 0, 4, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon5);

        gridLayout->addWidget(pushButton_4, 0, 5, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/tv.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon6);

        gridLayout->addWidget(pushButton_5, 0, 7, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 6, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 4);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setStyleSheet(QString::fromUtf8("font: 8pt \"Sans Serif\";"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        volumeSlider_5 = new Phonon::VolumeSlider(widget);
        volumeSlider_5->setObjectName(QString::fromUtf8("volumeSlider_5"));
        sizePolicy2.setHeightForWidth(volumeSlider_5->sizePolicy().hasHeightForWidth());
        volumeSlider_5->setSizePolicy(sizePolicy2);
        volumeSlider_5->setMaximumSize(QSize(251, 21));

        gridLayout_2->addWidget(volumeSlider_5, 0, 2, 1, 1);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(88, 23));
        lcdNumber->setMaximumSize(QSize(122, 23));
        lcdNumber->setFont(font);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Sunken);
        lcdNumber->setLineWidth(1);
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setDigitCount(8);
        lcdNumber->setMode(QLCDNumber::Dec);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(0));
        lcdNumber->setProperty("intValue", QVariant(0));

        gridLayout_2->addWidget(lcdNumber, 0, 3, 1, 1);

        seekSlider = new Phonon::SeekSlider(widget);
        seekSlider->setObjectName(QString::fromUtf8("seekSlider"));
        sizePolicy2.setHeightForWidth(seekSlider->sizePolicy().hasHeightForWidth());
        seekSlider->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(seekSlider, 0, 0, 1, 2);


        gridLayout_3->addWidget(widget, 1, 0, 1, 1);

        videoPlayer = new Phonon::VideoPlayer(Reproductor);
        videoPlayer->setObjectName(QString::fromUtf8("videoPlayer"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(videoPlayer->sizePolicy().hasHeightForWidth());
        videoPlayer->setSizePolicy(sizePolicy4);
        videoPlayer->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(videoPlayer, 0, 0, 1, 1);


        retranslateUi(Reproductor);

        QMetaObject::connectSlotsByName(Reproductor);
    } // setupUi

    void retranslateUi(QWidget *Reproductor)
    {
        Reproductor->setWindowTitle(QApplication::translate("Reproductor", "VideoDrake v.0.1.0", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("Reproductor", "Play", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Reproductor", "Stop", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("Reproductor", "Pausa", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Reproductor", "Abrir", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Reproductor", "Salir", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Reproductor", "Pantalla completa", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Reproductor: public Ui_Reproductor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPRODUCTOR_H
