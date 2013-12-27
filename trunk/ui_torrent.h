/********************************************************************************
** Form generated from reading UI file 'torrent.ui'
**
** Created: Sun Oct 7 12:38:31 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TORRENT_H
#define UI_TORRENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_torrent
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *torrent)
    {
        if (torrent->objectName().isEmpty())
            torrent->setObjectName(QString::fromUtf8("torrent"));
        torrent->resize(800, 600);
        centralwidget = new QWidget(torrent);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 430, 73, 23));
        torrent->setCentralWidget(centralwidget);
        menubar = new QMenuBar(torrent);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        torrent->setMenuBar(menubar);
        statusbar = new QStatusBar(torrent);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        torrent->setStatusBar(statusbar);

        retranslateUi(torrent);

        QMetaObject::connectSlotsByName(torrent);
    } // setupUi

    void retranslateUi(QMainWindow *torrent)
    {
        torrent->setWindowTitle(QApplication::translate("torrent", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("torrent", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class torrent: public Ui_torrent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TORRENT_H
