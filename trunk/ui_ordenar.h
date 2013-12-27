/********************************************************************************
** Form generated from reading UI file 'ordenar.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDENAR_H
#define UI_ORDENAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ordenar
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QFrame *line;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QComboBox *comboBox_3;
    QFrame *line_2;
    QComboBox *comboBox_4;
    QLabel *label_5;
    QFrame *line_3;

    void setupUi(QDialog *ordenar)
    {
        if (ordenar->objectName().isEmpty())
            ordenar->setObjectName(QString::fromUtf8("ordenar"));
        ordenar->resize(480, 380);
        QFont font;
        font.setPointSize(7);
        ordenar->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Imagenes/impresora.png"), QSize(), QIcon::Normal, QIcon::Off);
        ordenar->setWindowIcon(icon);
        pushButton = new QPushButton(ordenar);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(390, 350, 83, 25));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Imagenes/puerta.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(25, 25));
        pushButton_2 = new QPushButton(ordenar);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 350, 83, 25));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Imagenes/good.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(25, 25));
        label = new QLabel(ordenar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 451, 31));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"Sans Serif\";\n"
"font: bold;"));
        label->setAlignment(Qt::AlignCenter);
        pushButton_3 = new QPushButton(ordenar);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 210, 141, 25));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Imagenes/drakfont-mdk.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);
        pushButton_3->setIconSize(QSize(25, 25));
        comboBox = new QComboBox(ordenar);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 90, 200, 24));
        comboBox->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        lineEdit = new QLineEdit(ordenar);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 210, 301, 24));
        lineEdit->setAlignment(Qt::AlignCenter);
        line = new QFrame(ordenar);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 40, 461, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_4 = new QPushButton(ordenar);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 250, 141, 25));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Imagenes/pantone.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon4);
        pushButton_4->setIconSize(QSize(25, 25));
        lineEdit_2 = new QLineEdit(ordenar);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 250, 301, 24));
        lineEdit_2->setAlignment(Qt::AlignCenter);
        pushButton_5 = new QPushButton(ordenar);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 290, 181, 25));
        pushButton_5->setIcon(icon4);
        pushButton_5->setIconSize(QSize(25, 25));
        lineEdit_3 = new QLineEdit(ordenar);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(210, 290, 261, 24));
        lineEdit_3->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(ordenar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 201, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: bold;"));
        label_3 = new QLabel(ordenar);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(250, 60, 201, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: bold;"));
        comboBox_2 = new QComboBox(ordenar);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(250, 90, 200, 24));
        comboBox_2->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        label_4 = new QLabel(ordenar);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 130, 201, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: bold;"));
        comboBox_3 = new QComboBox(ordenar);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(20, 160, 200, 24));
        comboBox_3->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        line_2 = new QFrame(ordenar);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 190, 461, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        comboBox_4 = new QComboBox(ordenar);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(250, 160, 200, 24));
        comboBox_4->setStyleSheet(QString::fromUtf8("font: 7pt \"Sans Serif\";\n"
"font: bold"));
        label_5 = new QLabel(ordenar);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 130, 201, 16));
        label_5->setStyleSheet(QString::fromUtf8("font: bold;"));
        line_3 = new QFrame(ordenar);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 330, 461, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        retranslateUi(ordenar);

        QMetaObject::connectSlotsByName(ordenar);
    } // setupUi

    void retranslateUi(QDialog *ordenar)
    {
        ordenar->setWindowTitle(QApplication::translate("ordenar", "Datos de listado", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ordenar", "Salir", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ordenar", "Aceptar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ordenar", "Caracteristicas de listados", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ordenar", "Definir tipo de letra", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ordenar", "Sin filtro (todas las peliculas)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Titulo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Titulo original", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: Todos los publicos", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: Adultos", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: Sin clasificar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Drama", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Comedia", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Accion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Aventura", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Ciencia-Ficcion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Romantica", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Musical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Catastrofes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Suspense", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Fantasia", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Erotico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Porno", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Historico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Policiaco", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Terror", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Western", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Belico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Deportes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Animacion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Documental", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Gore/Zombies", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Actor principal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Actor secundario", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 10 (Obra Maestra)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Soporte", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Posicion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Visionada: Si", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Visionada: No", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Color", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "B/W", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Version Original", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Subtitulada", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Doblada", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: DVD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: avi", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: VCD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: VHS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: mkv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: LD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: B-Ray", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Director", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Fecha", 0, QApplication::UnicodeUTF8)
        );
        lineEdit->setText(QApplication::translate("ordenar", "Este el el tipo de letra", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("ordenar", "Definir color de letra", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setText(QApplication::translate("ordenar", "Este es el color de letra", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("ordenar", "Definir color de encabezado", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setText(QApplication::translate("ordenar", "Este es el color del encabezado", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ordenar", "Listado de PELICULAS:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ordenar", "Listado de MUSICA:", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("ordenar", "Sin filtro (todas las peliculas)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Titulo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Titulo original", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: Todos los publicos", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: Adultos", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: Sin clasificar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Drama", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Comedia", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Accion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Aventura", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Ciencia-Ficcion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Romantica", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Musical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Catastrofes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Suspense", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Fantasia", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Erotico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Porno", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Historico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Policiaco", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Terror", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Western", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Belico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Deportes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Animacion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Documental", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Gore/Zombies", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Actor principal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Actor secundario", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 10 (Obra Maestra)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Soporte", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Posicion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Visionada: Si", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Visionada: No", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Color", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "B/W", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Version Original", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Subtitulada", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Doblada", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: DVD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: avi", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: VCD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: VHS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: mkv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: LD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: B-Ray", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Director", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Fecha", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("ordenar", "Listado de LIBROS:", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("ordenar", "Sin filtro (todas las peliculas)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Titulo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Titulo original", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: Todos los publicos", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: Adultos", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: Sin clasificar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Drama", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Comedia", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Accion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Aventura", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Ciencia-Ficcion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Romantica", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Musical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Catastrofes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Suspense", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Fantasia", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Erotico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Porno", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Historico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Policiaco", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Terror", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Western", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Belico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Deportes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Animacion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Documental", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Gore/Zombies", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Actor principal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Actor secundario", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 10 (Obra Maestra)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Soporte", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Posicion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Visionada: Si", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Visionada: No", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Color", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "B/W", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Version Original", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Subtitulada", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Doblada", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: DVD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: avi", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: VCD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: VHS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: mkv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: LD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: B-Ray", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Director", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Fecha", 0, QApplication::UnicodeUTF8)
        );
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("ordenar", "Sin filtro (todas las peliculas)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Titulo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Titulo original", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: Todos los publicos", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: N.R. a menores de 18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: Adultos", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Calificacion: Sin clasificar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Drama", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Comedia", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Accion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Aventura", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Ciencia-Ficcion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Romantica", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Musical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Catastrofes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Suspense", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Fantasia", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Erotico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Porno", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Historico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Policiaco", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Terror", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Western", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Belico", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Deportes", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Animacion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Documental", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Genero: Gore/Zombies", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Actor principal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Actor secundario", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Valoracion: 10 (Obra Maestra)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Soporte", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Posicion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Visionada: Si", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Visionada: No", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Color", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "B/W", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Version Original", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Subtitulada", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Doblada", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: DVD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: avi", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: VCD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: VHS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: mkv", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: LD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Formato: B-Ray", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Director", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ordenar", "Fecha", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("ordenar", "Listado de Claves:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ordenar: public Ui_ordenar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDENAR_H
