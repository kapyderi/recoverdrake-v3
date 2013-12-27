/********************************************************************************
** Form generated from reading UI file 'repvideo.ui'
**
** Created: Sat Dec 17 12:02:25 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPVIDEO_H
#define UI_REPVIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include <phonon/videoplayer.h>

QT_BEGIN_NAMESPACE

class Ui_RepVideo
{
public:
    Phonon::VideoPlayer *videoPlayer;

    void setupUi(QWidget *RepVideo)
    {
        if (RepVideo->objectName().isEmpty())
            RepVideo->setObjectName(QString::fromUtf8("RepVideo"));
        RepVideo->resize(607, 413);
        videoPlayer = new Phonon::VideoPlayer(RepVideo);
        videoPlayer->setObjectName(QString::fromUtf8("videoPlayer"));
        videoPlayer->setGeometry(QRect(10, 50, 581, 351));

        retranslateUi(RepVideo);

        QMetaObject::connectSlotsByName(RepVideo);
    } // setupUi

    void retranslateUi(QWidget *RepVideo)
    {
        RepVideo->setWindowTitle(QApplication::translate("RepVideo", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RepVideo: public Ui_RepVideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPVIDEO_H
