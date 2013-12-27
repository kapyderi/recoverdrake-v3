/********************************************************************************
** Form generated from reading UI file 'acceso.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCESO_H
#define UI_ACCESO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_acceso
{
public:
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QFrame *line;
    QPushButton *pushButton;
    QFrame *line_3;
    QLabel *label_3;
    QCheckBox *checkBox_2;
    QFrame *line_2;
    QLabel *label_16;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QLabel *label_15;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout_5;
    QLabel *label_12;
    QLabel *label_17;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_5;
    QGridLayout *gridLayout_6;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_7;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_8;
    QLabel *label_10;
    QLineEdit *lineEdit;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_18;
    QLabel *label_19;

    void setupUi(QDialog *acceso)
    {
        if (acceso->objectName().isEmpty())
            acceso->setObjectName(QString::fromUtf8("acceso"));
        acceso->setWindowModality(Qt::NonModal);
        acceso->setEnabled(true);
        acceso->resize(490, 664);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(acceso->sizePolicy().hasHeightForWidth());
        acceso->setSizePolicy(sizePolicy);
        acceso->setMaximumSize(QSize(490, 664));
        QFont font;
        font.setPointSize(7);
        acceso->setFont(font);
        acceso->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        acceso->setWindowIcon(icon);
        acceso->setStyleSheet(QString::fromUtf8(""));
        acceso->setModal(false);
        gridLayout_7 = new QGridLayout(acceso);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox = new QGroupBox(acceso);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout->addWidget(checkBox, 0, 0, 1, 2);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Sans Serif"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        comboBox->setFont(font2);
        comboBox->setStyleSheet(QString::fromUtf8("font: 10pt \"Sans Serif\";\n"
"font: Bold;"));

        gridLayout->addWidget(comboBox, 1, 0, 1, 2);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(85, 16777215));
        label_13->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout->addWidget(label_13, 2, 0, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold;"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_14, 2, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 2);


        gridLayout_7->addWidget(groupBox, 2, 1, 1, 4);

        groupBox_2 = new QGroupBox(acceso);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font1);
        gridLayout_8 = new QGridLayout(groupBox_2);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setFont(font2);
        lineEdit_2->setStyleSheet(QString::fromUtf8("font: 10pt \"Sans Serif\";\n"
"font: Bold;"));
        lineEdit_2->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEdit_2, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_2, 3, 1, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 4, 2, 1, 2);

        line = new QFrame(acceso);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line, 7, 0, 1, 5);

        pushButton = new QPushButton(acceso);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(85, 0));
        pushButton->setMaximumSize(QSize(85, 16777215));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));

        gridLayout_7->addWidget(pushButton, 4, 1, 1, 1);

        line_3 = new QFrame(acceso);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_3, 13, 0, 1, 5);

        label_3 = new QLabel(acceso);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_7->addWidget(label_3, 0, 1, 1, 4);

        checkBox_2 = new QCheckBox(acceso);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout_7->addWidget(checkBox_2, 8, 0, 1, 2);

        line_2 = new QFrame(acceso);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_2, 11, 0, 1, 5);

        label_16 = new QLabel(acceso);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy2);
        label_16->setFrameShape(QFrame::Panel);
        label_16->setFrameShadow(QFrame::Sunken);
        label_16->setLineWidth(6);
        label_16->setScaledContents(false);
        label_16->setAlignment(Qt::AlignCenter);
        label_16->setWordWrap(false);

        gridLayout_7->addWidget(label_16, 14, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(acceso);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"font: bold italic;"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        label_15 = new QLabel(acceso);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"font: bold italic;"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_15, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 1, 1, 1, 4);

        pushButton_3 = new QPushButton(acceso);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 9pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout_7->addWidget(pushButton_3, 5, 1, 1, 4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_12 = new QLabel(acceso);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font: 12pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"font: bold;"));
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_12, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_5, 12, 0, 1, 1);

        label_17 = new QLabel(acceso);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("font: 12pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"font: bold;"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_17, 14, 1, 1, 4);

        pushButton_4 = new QPushButton(acceso);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_7->addWidget(pushButton_4, 12, 4, 1, 1);

        pushButton_2 = new QPushButton(acceso);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(85, 0));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/bad.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(25, 25));

        gridLayout_7->addWidget(pushButton_2, 4, 4, 1, 1);

        label_4 = new QLabel(acceso);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(170, 170, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_4->setPalette(palette);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Sans Serif"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("font: 18pt \"Sans Serif\";\n"
"color: rgb(0, 0, 255);\n"
"font: Bold;"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_4, 6, 1, 1, 2);

        label_5 = new QLabel(acceso);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        QBrush brush2(QColor(120, 122, 124, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_5->setPalette(palette1);
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        label_5->setFont(font4);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_5, 6, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        radioButton = new QRadioButton(acceso);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/SPAIN.png"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton->setIcon(icon3);
        radioButton->setIconSize(QSize(30, 30));

        gridLayout_6->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(acceso);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/ingles.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        radioButton_2->setIcon(icon4);
        radioButton_2->setIconSize(QSize(30, 30));

        gridLayout_6->addWidget(radioButton_2, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 6, 3, 1, 2);

        label_7 = new QLabel(acceso);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_7, 0, 0, 6, 1);

        groupBox_3 = new QGroupBox(acceso);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold;"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 0, 0, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 1, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(300, 16777215));
        lineEdit->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout_4->addWidget(lineEdit, 1, 1, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(30, 25));
        label_11->setMaximumSize(QSize(30, 25));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/Imagenes/good.png")));
        label_11->setScaledContents(true);

        gridLayout_4->addWidget(label_11, 1, 2, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setEnabled(false);
        label_9->setMaximumSize(QSize(16777215, 30));
        label_9->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold;"));

        gridLayout_4->addWidget(label_9, 0, 1, 1, 2);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_4->addWidget(label_18, 2, 0, 1, 3);


        gridLayout_7->addWidget(groupBox_3, 9, 0, 1, 5);

        label_19 = new QLabel(acceso);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        label_19->setFont(font5);
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_19, 8, 2, 1, 3);

        QWidget::setTabOrder(comboBox, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);
        QWidget::setTabOrder(pushButton_3, checkBox);
        QWidget::setTabOrder(checkBox, lineEdit);
        QWidget::setTabOrder(lineEdit, pushButton_4);

        retranslateUi(acceso);

        QMetaObject::connectSlotsByName(acceso);
    } // setupUi

    void retranslateUi(QDialog *acceso)
    {
        acceso->setWindowTitle(QApplication::translate("acceso", "Datos de acceso", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("acceso", "Usuario (*)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox->setToolTip(QApplication::translate("acceso", "Si se marca aparece el usuario de mantenimiento", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox->setStatusTip(QApplication::translate("acceso", "Si se marca aparece el usuario de mantenimiento", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox->setWhatsThis(QApplication::translate("acceso", "Si se marca aparece el usuario de mantenimiento", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox->setText(QApplication::translate("acceso", "Modo administrador (Para mantenimiento)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        comboBox->setToolTip(QApplication::translate("acceso", "Usuarios activos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        comboBox->setStatusTip(QApplication::translate("acceso", "Usuarios activos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        comboBox->setWhatsThis(QApplication::translate("acceso", "Usuarios activos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_13->setText(QApplication::translate("acceso", "Ultimo acceso:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QString());
        label->setText(QApplication::translate("acceso", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:7pt; font-weight:600; color:#0000ff;\">(*) Solo se muestran los usuarios activos.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("acceso", "Contrasena (**)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("acceso", "Clave de acceso del usuario seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit_2->setStatusTip(QApplication::translate("acceso", "Clave de acceso del usuario seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit_2->setWhatsThis(QApplication::translate("acceso", "Clave de acceso del usuario seleccionado", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("acceso", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:7pt; font-weight:600; color:#0000ff;\">(**) Por defecto &quot;admin&quot; para el usuario &quot;admin&quot;</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("acceso", "Continuar con RecoverDrake", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("acceso", "Continuar con RecoverDrake", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton->setWhatsThis(QApplication::translate("acceso", "Continuar con RecoverDrake", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton->setText(QApplication::translate("acceso", "Aceptar", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("acceso", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/Imagenes/RDrake1.png\" width=\"310\" height=\"100\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        checkBox_2->setToolTip(QApplication::translate("acceso", "Muestra el el numero de serie y el registro", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        checkBox_2->setStatusTip(QApplication::translate("acceso", "Muestra el el numero de serie y el registro", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        checkBox_2->setWhatsThis(QApplication::translate("acceso", "Muestra el el numero de serie y el registro", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        checkBox_2->setText(QApplication::translate("acceso", "Mostrar datos de registro", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_16->setToolTip(QApplication::translate("acceso", "Muestra MAYUSCULAS/minusculas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        label_16->setStatusTip(QApplication::translate("acceso", "Muestra MAYUSCULAS/minusculas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        label_16->setWhatsThis(QApplication::translate("acceso", "Muestra MAYUSCULAS/minusculas", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_16->setText(QApplication::translate("acceso", "minusculas", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("acceso", "Vacio", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("acceso", "RecoverDrake -- Proyecto Derix", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("acceso", "Recuperar usuario", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("acceso", "Recuperar usuario", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_3->setWhatsThis(QApplication::translate("acceso", "Recuperar usuario", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_3->setText(QApplication::translate("acceso", "Olvidaste tu contrasena ?", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("acceso", "Copia registrada.", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("acceso", "Todos somos Linux... (kapyderi)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("acceso", "Genera clave y registra al ser un programa totalmente gratuito", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("acceso", "Genera clave y registra al ser un programa totalmente gratuito", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_4->setWhatsThis(QApplication::translate("acceso", "Genera clave y registra al ser un programa totalmente gratuito", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_4->setText(QApplication::translate("acceso", "Registrar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("acceso", "Salir de RecoverDrake", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("acceso", "Salir de RecoverDrake", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("acceso", "Salir de RecoverDrake", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QApplication::translate("acceso", "Salir", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("acceso", "Vacio", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("acceso", "<html><head/><body><p><span style=\" font-size:10pt; color:#0000ff;\">Optimizado para...</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        label_7->setText(QApplication::translate("acceso", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/Imagenes/stop.png\" width=\"75\" height=\"75\" /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:600; font-style:italic; color:#2f2f23;\">Control</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:600; font-style:italic; color:#2f2f23;\">de</span></p"
                        ">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:600; font-style:italic; color:#2f2f23;\">Acceso</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/Imagenes/URI_www_kapyderi_blogspog.png\" width=\"75\" height=\"75\" /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px"
                        "; font-size:9pt;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/Imagenes/hibrido.png\" /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("acceso", "Datos de registro", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("acceso", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:7pt; font-weight:600; color:#0000ff;\">Numero de Serie:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("acceso", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:7pt; font-weight:600; color:#0000ff;\">Clave de registro:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        label_9->setText(QApplication::translate("acceso", "Vacio", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("acceso", "Vacio", 0, QApplication::UnicodeUTF8));
        label_19->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class acceso: public Ui_acceso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCESO_H
