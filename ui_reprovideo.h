/********************************************************************************
** Form generated from reading UI file 'reprovideo.ui'
**
** Created: Sat Jul 28 13:56:57 2012
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPROVIDEO_H
#define UI_REPROVIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include <phonon/seekslider.h>
#include <phonon/videoplayer.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_ReproVideo
{
public:
    QGridLayout *gridLayout_3;
    Phonon::VideoPlayer *videoPlayer;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    Phonon::SeekSlider *seekSlider;
    QLCDNumber *lcdNumber;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label;
    Phonon::VolumeSlider *volumeSlider;

    void setupUi(QDialog *ReproVideo)
    {
        if (ReproVideo->objectName().isEmpty())
            ReproVideo->setObjectName(QString::fromUtf8("ReproVideo"));
        ReproVideo->resize(599, 470);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/multimedia.png"), QSize(), QIcon::Normal, QIcon::Off);
        ReproVideo->setWindowIcon(icon);
        ReproVideo->setWindowOpacity(0);
        gridLayout_3 = new QGridLayout(ReproVideo);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        videoPlayer = new Phonon::VideoPlayer(ReproVideo);
        videoPlayer->setObjectName(QString::fromUtf8("videoPlayer"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(videoPlayer->sizePolicy().hasHeightForWidth());
        videoPlayer->setSizePolicy(sizePolicy);
        videoPlayer->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout_3->addWidget(videoPlayer, 0, 0, 1, 1);

        widget = new QWidget(ReproVideo);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 121));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        seekSlider = new Phonon::SeekSlider(widget);
        seekSlider->setObjectName(QString::fromUtf8("seekSlider"));
        sizePolicy.setHeightForWidth(seekSlider->sizePolicy().hasHeightForWidth());
        seekSlider->setSizePolicy(sizePolicy);
        seekSlider->setMinimumSize(QSize(485, 23));

        gridLayout_2->addWidget(seekSlider, 0, 0, 1, 2);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(88, 23));
        lcdNumber->setMaximumSize(QSize(122, 23));
        QFont font;
        font.setPointSize(7);
        lcdNumber->setFont(font);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Sunken);
        lcdNumber->setLineWidth(1);
        lcdNumber->setSmallDecimalPoint(true);
        lcdNumber->setNumDigits(8);
        lcdNumber->setMode(QLCDNumber::Dec);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(0));
        lcdNumber->setProperty("intValue", QVariant(0));

        gridLayout_2->addWidget(lcdNumber, 0, 2, 1, 1);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMaximumSize(QSize(56, 24));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMaximumSize(QSize(59, 24));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/stop1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);

        gridLayout->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMaximumSize(QSize(68, 24));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon3);

        gridLayout->addWidget(pushButton_6, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMaximumSize(QSize(59, 24));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/abrir.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);

        gridLayout->addWidget(pushButton_2, 0, 4, 1, 1);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMaximumSize(QSize(57, 24));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Imagenes/puerta.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon5);

        gridLayout->addWidget(pushButton_4, 0, 5, 1, 1);

        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setMaximumSize(QSize(159, 26));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Imagenes/tv.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon6);

        gridLayout->addWidget(pushButton_5, 0, 6, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 3);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setStyleSheet(QString::fromUtf8("font: 8pt \"Sans Serif\";"));

        gridLayout_2->addWidget(label, 2, 0, 1, 1);

        volumeSlider = new Phonon::VolumeSlider(widget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        sizePolicy.setHeightForWidth(volumeSlider->sizePolicy().hasHeightForWidth());
        volumeSlider->setSizePolicy(sizePolicy);
        volumeSlider->setMaximumSize(QSize(251, 21));

        gridLayout_2->addWidget(volumeSlider, 2, 1, 1, 2);


        gridLayout_3->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(ReproVideo);

        QMetaObject::connectSlotsByName(ReproVideo);
    } // setupUi

    void retranslateUi(QDialog *ReproVideo)
    {
        ReproVideo->setWindowTitle(QApplication::translate("ReproVideo", "Reproductor de Video VideoDrake", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("ReproVideo", "Play", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ReproVideo", "Stop", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("ReproVideo", "Pausa", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ReproVideo", "Abrir", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("ReproVideo", "Salir", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("ReproVideo", "Pantalla completa", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ReproVideo: public Ui_ReproVideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPROVIDEO_H
