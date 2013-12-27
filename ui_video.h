/********************************************************************************
** Form generated from reading UI file 'video.ui'
**
** Created: Fri Aug 16 04:21:17 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_H
#define UI_VIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMdiArea>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Video
{
public:
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Video)
    {
        if (Video->objectName().isEmpty())
            Video->setObjectName(QString::fromUtf8("Video"));
        Video->resize(527, 420);
        gridLayout = new QGridLayout(Video);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mdiArea = new QMdiArea(Video);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(mdiArea, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);


        retranslateUi(Video);

        QMetaObject::connectSlotsByName(Video);
    } // setupUi

    void retranslateUi(QDialog *Video)
    {
        Video->setWindowTitle(QApplication::translate("Video", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Video: public Ui_Video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H
