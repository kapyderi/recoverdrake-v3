#include "examen.h"
#include "ui_examen.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QTime>
#include <QKeyEvent>
#include <QTest>

examen::examen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::examen)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    qsrand(QTime::currentTime().msec());
    Examen = 1;
    Suma = 0;
    Value = 0;
    Stilo = "B";
    QSqlQuery queryDefecto(db);
    queryDefecto.exec("SELECT Defecto FROM Miscelanea WHERE id=2");
    queryDefecto.first();
    if (queryDefecto.isSelect())
        cantidadDefecto=queryDefecto.value(0).toString();
    if (cantidadDefecto == "0")
    {
        QSqlQuery query47(db);
        query47.exec("SELECT Fuente FROM Font WHERE id=2");
        query47.first();
        if (query47.isSelect())
            cantidad47=query47.value(0).toString();
        QSqlQuery query48(db);
        query48.exec("SELECT Estilo FROM Font WHERE id=2");
        query48.first();
        if (query48.isSelect())
            cantidad48=query48.value(0).toString();
        QSqlQuery query49(db);
        query49.exec("SELECT Talla FROM Font WHERE id=2");
        query49.first();
        if (query49.isSelect())
            cantidad49=query49.value(0).toString();
        if (cantidad48 == "Regular")
        {
            DatoTalla = "normal";
            DatoNegro = "normal";
        }
        if (cantidad48 == "Italic")
        {
            DatoTalla = "italic";
            DatoNegro = "normal";
        }
        if (cantidad48 == "Bold Italic")
        {
            DatoTalla = "italic";
            DatoNegro = "bold";
        }
        if (cantidad48 == "Bold")
        {
            DatoTalla = "normal";
            DatoNegro = "bold";
        }
        QSqlQuery query50(db);
        query50.exec("SELECT ColorTexto FROM Color WHERE id=2");
        query50.first();
        if (query50.isSelect())
            cantidad50=query50.value(0).toString();
        QSqlQuery query51(db);
        query51.exec("SELECT ColorFondo FROM Color WHERE id=2");
        query51.first();
        if (query51.isSelect())
            cantidad51=query51.value(0).toString();
        Stilo ="A";
    }
    int respuesta = 0;
    respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Realizar test")),
                QString::fromUtf8(tr("<center><b>Tipo de test a realizar</center><p>"
                "Puedes realizar el test de forma normal o aleatoria, segun quieras.<p>"
                "&iquest;Hacer el test normal?")), QMessageBox::Ok, QMessageBox::No);
    if (respuesta == QMessageBox::Ok)
    {
        ui->radioButton->setChecked(true);
        this->pregunta();
    }
    else if (respuesta == QMessageBox::No)
    {
        ui->radioButton_2->setChecked(true);
        this->ramdom();
    }
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(AccesoPregunta()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(AccesoRamdom()));
    this->installEventFilter(this);
    CierreTotal = 0;
    Siguiente = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton_6_clicked()));
    QString Spain, English;
    QSqlQuery querySpain(db);
    querySpain.exec("SELECT spanish FROM Idioma WHERE id=2");
    querySpain.first();
    if (querySpain.isValid())
        Spain=querySpain.value(0).toString();
    QSqlQuery queryEnglish(db);
    queryEnglish.exec("SELECT english FROM Idioma WHERE id=2");
    queryEnglish.first();
    if (queryEnglish.isValid())
        English=queryEnglish.value(0).toString();
    QString idioma;
    if (Spain == "2")
        ui->groupBox->setTitle("Pregunta nº");
    else if (English == "2")
        ui->groupBox->setTitle("Question nº");
}

examen::~examen()
{
    delete ui;
}

void examen::on_pushButton_2_clicked()
{
    if (CierreTotal == 1)
        emit Cerrar();
    else
        close();
}

void examen::closeEvent ( QCloseEvent * event )
{
    if (CierreTotal == 1)
    {
        emit Cerrar();
        event->accept();
    }
    else
    {
        close();
        event->accept();
    }
}

void examen::AccesoPregunta()
{
    Examen = 1;
    Suma=0;
    ui->label_8->setText("");
    ui->label_9->setText("");
    ui->label->setText("");
    ui->label_2->setText("");
    this->pregunta();
}

void examen::Valor(QString valor)
{
    if (valor == "Quitar")
    {        
        Value=1;
        CierreTotal = 1;
        ui->textEdit->setStyleSheet("font: 14pt; font: Bold");
        ui->label_4->setStyleSheet("font: 14pt");
        ui->label_5->setStyleSheet("font: 14pt");
        ui->label_6->setStyleSheet("font: 14pt");
    }
    if (this->isMaximized())
    {
        ui->label_9->show();
        ui->verticalSpacer->changeSize(0,0);
    }
    else
    {
        ui->label_9->hide();
        ui->verticalSpacer->changeSize(20,40,QSizePolicy::Expanding,QSizePolicy::Expanding);
    }
}

void examen::AccesoRamdom()
{
    Examen = 1;
    Suma=0;
    ui->label_8->setText("");
    ui->label_9->setText("");
    ui->label->setText("");
    ui->label_2->setText("");
    this->ramdom();
}

void examen::pregunta()
{
    Siguiente = 0;
    ui->pushButton_3->setIcon((QIcon(":/Imagenes/help.png")));
    ui->pushButton_4->setIcon((QIcon(":/Imagenes/help.png")));
    ui->pushButton_5->setIcon((QIcon(":/Imagenes/help.png")));
    if (Examen <= 100)
    {
        QSqlQuery PreTest(db);
        PreTest.exec("SELECT Pregunta FROM Test WHERE id='"+QString::number(Examen)+"'");
        PreTest.first();
        if (PreTest.isSelect())
            CntTest=PreTest.value(0).toString();
        if (CntTest == "")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Ya has contestado a todas las preguntas. Ahora te comento que tal me ha parecido tu experiencia."));
            m.exec();
            int ratio = (Suma*100)/Examen;
            if (ratio <= 20)
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Eres bastante novato. Te queda mucho por aprender."));
                m.exec();
            }
            if (ratio >= 21 && ratio <=40)
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Tienes base, pero te falta algo de experiencia."));
                m.exec();
            }
            if (ratio >= 41 && ratio <=60)
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Vas por buen camino, sigue asi y lo conseguiras."));
                m.exec();
            }
            if (ratio >= 61 && ratio <=80)
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Eres un alumno aventajado, solo te falta un poco mas de experiencia."));
                m.exec();
            }
            if (ratio >= 81 && ratio <=100)
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Eres un experto en este mundo y se nota que te gusta.<p>ENHORABUENA!!!"));
                m.exec();
            }
            if (Value == 0)
            {
                int respuesta = 0;
                respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Realizar de nuevo el test")),
                            QString::fromUtf8(tr("<center><b>Realizar de nuevo el test</center><p>"
                            "Has completado el test, por lo que puedes volver a realizarlo para "
                            "coger experiencia o salir.<p>"
                            "&iquest;Hacer de nuevo el test?")), QMessageBox::Ok, QMessageBox::No);
                if (respuesta == QMessageBox::Ok)
                {
                    Examen = 1;
                    Suma=0;
                    ui->label_8->setText("");
                    ui->label_9->setText("");
                    ui->label->setText("");
                    ui->label_2->setText("");
                    if (CierreTotal == 1)
                    {
                        ui->label_4->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                        ui->label_5->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                        ui->label_6->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                    }
                    else
                    {
                        ui->label_4->setStyleSheet("color: rgb(0,0,0)");
                        ui->label_5->setStyleSheet("color: rgb(0,0,0)");
                        ui->label_6->setStyleSheet("color: rgb(0,0,0)");
                    }
                    this->pregunta();
                }
                else
                    close();
            }
            else if (Value == 1)
            {
                int respuesta = 0;
                respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Realizar de nuevo el test")),
                            QString::fromUtf8(tr("<center><b>Realizar de nuevo el test</center><p>"
                            "Has completado el test, por lo que puedes volver a realizarlo para "
                            "coger experiencia.<p>"
                            "&iquest;Hacer de nuevo el test?")), QMessageBox::Ok, QMessageBox::No);
                if (respuesta == QMessageBox::Ok)
                {
                    Examen = 1;
                    Suma = 0;
                    ui->label_8->setText("");
                    ui->label_9->setText("");
                    ui->label->setText("");
                    ui->label_2->setText("");
                    if (CierreTotal == 1)
                    {
                        ui->label_4->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                        ui->label_5->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                        ui->label_6->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                    }
                    else
                    {
                        ui->label_4->setStyleSheet("color: rgb(0,0,0)");
                        ui->label_5->setStyleSheet("color: rgb(0,0,0)");
                        ui->label_6->setStyleSheet("color: rgb(0,0,0)");
                    }
                    this->pregunta();
                }
            }
        }
        ui->groupBox->setTitle("Pregunta Nº "+QString::number(Examen));
        if (CierreTotal == 1)
        {
            ui->textEdit->setStyleSheet("font: 14pt; font: Bold");
            ui->label_4->setStyleSheet("color: rgb(0,0,0); font: 14pt");
            ui->label_5->setStyleSheet("color: rgb(0,0,0); font: 14pt");
            ui->label_6->setStyleSheet("color: rgb(0,0,0); font: 14pt");
        }
        else
        {
            ui->label_4->setStyleSheet("color: rgb(0,0,0)");
            ui->label_5->setStyleSheet("color: rgb(0,0,0)");
            ui->label_6->setStyleSheet("color: rgb(0,0,0)");
        }
        ui->textEdit->setText(CntTest);
        QSqlQuery ResTest1(db);
        ResTest1.exec("SELECT Respuesta1 FROM Test WHERE Pregunta='"+CntTest+"'");
        ResTest1.first();
        if (ResTest1.isSelect())
            RespTest1=ResTest1.value(0).toString();
        QSqlQuery ResTest2(db);
        ResTest2.exec("SELECT Respuesta2 FROM Test WHERE Pregunta='"+CntTest+"'");
        ResTest2.first();
        if (ResTest2.isSelect())
            RespTest2=ResTest2.value(0).toString();
        QSqlQuery ResTest3(db);
        ResTest3.exec("SELECT Respuesta3 FROM Test WHERE Pregunta='"+CntTest+"'");
        ResTest3.first();
        if (ResTest3.isSelect())
            RespTest3=ResTest3.value(0).toString();
        int valor = qrand() % 2 + 1;
        if (valor == 1)
        {
            ui->label_4->setText(RespTest1);
            ui->label_5->setText(RespTest2);
            ui->label_6->setText(RespTest3);
        }
        else if (valor == 2)
        {
            ui->label_4->setText(RespTest2);
            ui->label_5->setText(RespTest3);
            ui->label_6->setText(RespTest1);
        }
        else if (valor == 3)
        {
            ui->label_4->setText(RespTest3);
            ui->label_5->setText(RespTest1);
            ui->label_6->setText(RespTest2);
        }
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Ya has contestado a todas las preguntas. Ahora te comento que tal me ha parecido tu experiencia."));
        m.exec();
        int ratio = (Suma*100)/Examen;
        if (ratio <= 20)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Eres bastante novato. Te queda mucho por aprender."));
            m.exec();
        }
        if (ratio >= 21 && ratio <=40)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Tienes base, pero te falta algo de experiencia."));
            m.exec();
        }
        if (ratio >= 41 && ratio <=60)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Vas por buen camino, sigue asi y lo conseguiras."));
            m.exec();
        }
        if (ratio >= 61 && ratio <=80)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Eres un alumno aventajado, solo te falta un poco mas de experiencia."));
            m.exec();
        }
        if (ratio >= 81 && ratio <=100)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Eres un experto en este mundo y se nota que te gusta.<p>ENHORABUENA!!!"));
            m.exec();
        }
        if (Value == 0)
        {
            int respuesta = 0;
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Realizar de nuevo el test")),
                        QString::fromUtf8(tr("<center><b>Realizar de nuevo el test</center><p>"
                        "Has completado el test, por lo que puedes volver a realizarlo para "
                        "coger experiencia o salir.<p>"
                        "&iquest;Hacer de nuevo el test?")), QMessageBox::Ok, QMessageBox::No);
            if (respuesta == QMessageBox::Ok)
            {
                Examen = 1;
                Suma=0;
                ui->label_8->setText("");
                ui->label_9->setText("");
                ui->label->setText("");
                ui->label_2->setText("");
                if (CierreTotal == 1)
                {
                    ui->label_4->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                    ui->label_5->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                    ui->label_6->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                }
                else
                {
                    ui->label_4->setStyleSheet("color: rgb(0,0,0)");
                    ui->label_5->setStyleSheet("color: rgb(0,0,0)");
                    ui->label_6->setStyleSheet("color: rgb(0,0,0)");
                }
                this->pregunta();
            }
            else
                close();
        }
        else if (Value == 1)
        {
            int respuesta = 0;
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Realizar de nuevo el test")),
                        QString::fromUtf8(tr("<center><b>Realizar de nuevo el test</center><p>"
                        "Has completado el test, por lo que puedes volver a realizarlo para "
                        "coger experiencia.<p>"
                        "&iquest;Hacer de nuevo el test?")), QMessageBox::Ok, QMessageBox::No);
            if (respuesta == QMessageBox::Ok)
            {
                Examen = 1;
                Suma = 0;
                ui->label_8->setText("");
                ui->label_9->setText("");
                ui->label->setText("");
                ui->label_2->setText("");
                if (CierreTotal == 1)
                {
                    ui->label_4->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                    ui->label_5->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                    ui->label_6->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                }
                else
                {
                    ui->label_4->setStyleSheet("color: rgb(0,0,0)");
                    ui->label_5->setStyleSheet("color: rgb(0,0,0)");
                    ui->label_6->setStyleSheet("color: rgb(0,0,0)");
                }
                this->pregunta();
            }
        }
    }
}

void examen::on_pushButton_3_clicked()
{
    Siguiente = 1;
    QString Comprobar = ""+QString::number(Suma)+" / "+QString::number(Examen-1)+"";
    if (Comprobar == ui->label_2->text() || ui->label_2->text() == "")
    {        
        if (ui->label_4->text() == RespTest1)
        {
            ui->pushButton_3->setIcon((QIcon(":/Imagenes/good.png")));
            ui->pushButton_4->setIcon((QIcon(":/Imagenes/bad.png")));
            ui->pushButton_5->setIcon((QIcon(":/Imagenes/bad.png")));
            if (CierreTotal == 1)
            {
                ui->label_4->setStyleSheet("color: rgb(0,0,255);font: bold; font: 14pt");
                ui->label_5->setStyleSheet("color: rgb(255,0,0); font: 14pt");
                ui->label_6->setStyleSheet("color: rgb(255,0,0); font: 14pt");
            }
            else
            {
                ui->label_4->setStyleSheet("color: rgb(0,0,255)");
                ui->label_5->setStyleSheet("color: rgb(255,0,0)");
                ui->label_6->setStyleSheet("color: rgb(255,0,0)");
            }
            Suma=Suma+1;
            ui->label_2->setText(""+QString::number(Suma)+" / "+QString::number(Examen)+"");
            int ratio = (Suma*100)/Examen;
            ui->label_9->setText(""+QString::number(ratio)+" %");
            ui->label->setText(tr("Correcto"));
        }
        else if (ui->label_4->text() != RespTest1)
        {
            if (CierreTotal == 1)
                ui->label_4->setStyleSheet("color: rgb(255,0,0); font: 14pt");
            else
                ui->label_4->setStyleSheet("color: rgb(255,0,0)");
            ui->label_2->setText(""+QString::number(Suma)+" / "+QString::number(Examen)+"");
            int ratio = (Suma*100)/Examen;
            ui->label_9->setText(""+QString::number(ratio)+" %");
            ui->label_8->setText(tr("Incorrecto"));
            if (ui->label_5->text() == RespTest1)
            {
                ui->pushButton_3->setIcon((QIcon(":/Imagenes/bad.png")));
                ui->pushButton_4->setIcon((QIcon(":/Imagenes/good.png")));
                ui->pushButton_5->setIcon((QIcon(":/Imagenes/bad.png")));
                if (CierreTotal == 1)
                {
                    ui->label_5->setStyleSheet("color: rgb(0,0,255);font: bold; font: 14pt");
                    ui->label_6->setStyleSheet("color: rgb(255,0,0); font: 14pt");
                }
                else
                {
                    ui->label_5->setStyleSheet("color: rgb(0,0,255);font: bold");
                    ui->label_6->setStyleSheet("color: rgb(255,0,0)");
                }
            }
            else if (ui->label_6->text() == RespTest1)
            {
                ui->pushButton_3->setIcon((QIcon(":/Imagenes/bad.png")));
                ui->pushButton_4->setIcon((QIcon(":/Imagenes/bad.png")));
                ui->pushButton_5->setIcon((QIcon(":/Imagenes/good.png")));
                if (CierreTotal == 1)
                {
                    ui->label_5->setStyleSheet("color: rgb(255,0,0); font: 14pt");
                    ui->label_6->setStyleSheet("color: rgb(0,0,255);font: bold; font: 14pt");
                }
                else
                {
                    ui->label_5->setStyleSheet("color: rgb(255,0,0)");
                    ui->label_6->setStyleSheet("color: rgb(0,0,255)");
                }
            }
        }
        timer->start(5000);
    }
}

void examen::on_pushButton_4_clicked()
{
    Siguiente = 1;
    QString Comprobar = ""+QString::number(Suma)+" / "+QString::number(Examen-1)+"";
    if (Comprobar == ui->label_2->text() || ui->label_2->text() == "")
    {
        if (ui->label_5->text() == RespTest1)
        {
            ui->pushButton_3->setIcon((QIcon(":/Imagenes/bad.png")));
            ui->pushButton_4->setIcon((QIcon(":/Imagenes/good.png")));
            ui->pushButton_5->setIcon((QIcon(":/Imagenes/bad.png")));
            if (CierreTotal == 1)
            {
                ui->label_4->setStyleSheet("color: rgb(255,0,0); font: 14pt");
                ui->label_5->setStyleSheet("color: rgb(0,0,255);font: bold; font: 14pt");
                ui->label_6->setStyleSheet("color: rgb(255,0,0); font: 14pt");
            }
            else
            {
                ui->label_4->setStyleSheet("color: rgb(255,0,0)");
                ui->label_5->setStyleSheet("color: rgb(0,0,255)");
                ui->label_6->setStyleSheet("color: rgb(255,0,0)");
            }
            Suma=Suma+1;
            ui->label_2->setText(""+QString::number(Suma)+" / "+QString::number(Examen)+"");
            int ratio = (Suma*100)/Examen;
            ui->label_9->setText(""+QString::number(ratio)+" %");
            ui->label->setText(tr("Correcto"));
        }
        else if (ui->label_5->text() != RespTest1)
        {
            if (CierreTotal == 1)
                ui->label_5->setStyleSheet("color: rgb(255,0,0); font: 14pt");
            else
                ui->label_5->setStyleSheet("color: rgb(255,0,0)");
            ui->label_2->setText(""+QString::number(Suma)+" / "+QString::number(Examen)+"");
            int ratio = (Suma*100)/Examen;
            ui->label_9->setText(""+QString::number(ratio)+" %");
            ui->label_8->setText(tr("Incorrecto"));
            if (ui->label_4->text() == RespTest1)
            {
                ui->pushButton_3->setIcon((QIcon(":/Imagenes/good.png")));
                ui->pushButton_4->setIcon((QIcon(":/Imagenes/bad.png")));
                ui->pushButton_5->setIcon((QIcon(":/Imagenes/bad.png")));
                if (CierreTotal == 1)
                {
                    ui->label_4->setStyleSheet("color: rgb(0,0,255);font: bold; font: 14pt");
                    ui->label_6->setStyleSheet("color: rgb(255,0,0); font: 14pt");
                }
                else
                {
                    ui->label_4->setStyleSheet("color: rgb(0,0,255);font: bold");
                    ui->label_6->setStyleSheet("color: rgb(255,0,0)");
                }
            }
            else if (ui->label_6->text() == RespTest1)
            {
                ui->pushButton_3->setIcon((QIcon(":/Imagenes/bad.png")));
                ui->pushButton_4->setIcon((QIcon(":/Imagenes/bad.png")));
                ui->pushButton_5->setIcon((QIcon(":/Imagenes/good.png")));
                if (CierreTotal == 1)
                {
                    ui->label_4->setStyleSheet("color: rgb(255,0,0); font: 14pt");
                    ui->label_6->setStyleSheet("color: rgb(0,0,255);font: bold; font: 14pt");
                }
                else
                {
                    ui->label_4->setStyleSheet("color: rgb(255,0,0)");
                    ui->label_6->setStyleSheet("color: rgb(0,0,255);font: bold");
                }
            }
        }
        timer->start(5000);
    }
}

void examen::on_pushButton_5_clicked()
{
    Siguiente = 1;
    QString Comprobar = ""+QString::number(Suma)+" / "+QString::number(Examen-1)+"";
    if (Comprobar == ui->label_2->text() || ui->label_2->text() == "")
    {
        if (ui->label_6->text() == RespTest1)
        {
            ui->pushButton_3->setIcon((QIcon(":/Imagenes/bad.png")));
            ui->pushButton_4->setIcon((QIcon(":/Imagenes/bad.png")));
            ui->pushButton_5->setIcon((QIcon(":/Imagenes/good.png")));
            if (CierreTotal == 1)
            {
                ui->label_4->setStyleSheet("color: rgb(255,0,0); font: 14pt");
                ui->label_5->setStyleSheet("color: rgb(255,0,0); font: 14pt");
                ui->label_6->setStyleSheet("color: rgb(0,0,255);font: bold; font: 14pt");
            }
            else
            {
                ui->label_4->setStyleSheet("color: rgb(255,0,0)");
                ui->label_5->setStyleSheet("color: rgb(255,0,0)");
                ui->label_6->setStyleSheet("color: rgb(0,0,255);font: bold");
            }
            Suma=Suma+1;
            ui->label_2->setText(""+QString::number(Suma)+" / "+QString::number(Examen)+"");
            int ratio = (Suma*100)/Examen;
            ui->label_9->setText(""+QString::number(ratio)+" %");
            ui->label->setText(tr("Correcto"));
        }
        else if (ui->label_6->text() != RespTest1)
        {
            if (CierreTotal == 1)
                ui->label_6->setStyleSheet("color: rgb(255,0,0); font: 14pt");
            else
                ui->label_6->setStyleSheet("color: rgb(255,0,0)");
            ui->label_2->setText(""+QString::number(Suma)+" / "+QString::number(Examen)+"");
            int ratio = (Suma*100)/Examen;
            ui->label_9->setText(""+QString::number(ratio)+" %");
            ui->label_8->setText(tr("Incorrecto"));
            if (ui->label_4->text() == RespTest1)
            {
                ui->pushButton_3->setIcon((QIcon(":/Imagenes/good.png")));
                ui->pushButton_4->setIcon((QIcon(":/Imagenes/bad.png")));
                ui->pushButton_5->setIcon((QIcon(":/Imagenes/bad.png")));
                if (CierreTotal == 1)
                {
                    ui->label_4->setStyleSheet("color: rgb(0,0,255);font: bold; font: 14pt");
                    ui->label_6->setStyleSheet("color: rgb(255,0,0); font: 14pt");
                }
                else
                {
                    ui->label_4->setStyleSheet("color: rgb(0,0,255);font: bold");
                    ui->label_6->setStyleSheet("color: rgb(255,0,0)");
                }
            }
            else if (ui->label_5->text() == RespTest1)
            {
                ui->pushButton_3->setIcon((QIcon(":/Imagenes/bad.png")));
                ui->pushButton_4->setIcon((QIcon(":/Imagenes/good.png")));
                ui->pushButton_5->setIcon((QIcon(":/Imagenes/bad.png")));
                if (CierreTotal == 1)
                {
                    ui->label_4->setStyleSheet("color: rgb(255,0,0); font: 14pt");
                    ui->label_5->setStyleSheet("color: rgb(0,0,255);font: bold; font: 14pt");
                }
                else
                {
                    ui->label_4->setStyleSheet("color: rgb(255,0,0)");
                    ui->label_5->setStyleSheet("color: rgb(0,0,255);font: bold");
                }
            }
        }
        timer->start(5000);
    }
}

void examen::on_pushButton_6_clicked()
{
    timer->stop();
    if (Siguiente == 0)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Siguiente respuesta")),
                    QString::fromUtf8(tr("<center><b>Advertencia</center><p>"
                    "No has contestado aun a la pregunta, si aceptas, esta pregunta "
                    "se considerara incorrecta.<p>"
                    "&iquest;Pasar a la siguiente pregunta?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            ui->label_2->setText(""+QString::number(Suma)+" / "+QString::number(Examen)+"");
            int ratio = (Suma*100)/Examen;
            ui->label_9->setText(""+QString::number(ratio)+" %");
            ui->label_8->setText(tr("Incorrecto"));
        }
        else
            return;
    }
    Examen=Examen+1;
    ui->label_8->setText("");
    ui->label->setText("");
    if (CierreTotal == 1)
    {
        ui->label_4->setStyleSheet("color: rgb(0,0,0); font: 14pt");
        ui->label_5->setStyleSheet("color: rgb(0,0,0); font: 14pt");
        ui->label_6->setStyleSheet("color: rgb(0,0,0); font: 14pt");
    }
    else
    {
        ui->label_4->setStyleSheet("color: rgb(0,0,0)");
        ui->label_5->setStyleSheet("color: rgb(0,0,0)");
        ui->label_6->setStyleSheet("color: rgb(0,0,0)");
    }
    if (ui->radioButton->isChecked())
        this->pregunta();
    else if (ui->radioButton_2->isChecked())
        this->ramdom();
}

void examen::on_pushButton_7_clicked()
{
    int ratio = (Suma*100)/Examen;
    if (ratio <= 20)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Eres bastante novato. Te queda mucho por aprender."));
        m.exec();        
    }
    if (ratio >= 21 && ratio <=40)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Tienes base, pero te falta algo de experiencia."));
        m.exec();       
    }
    if (ratio >= 41 && ratio <=60)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Vas por buen camino, sigue asi y lo conseguiras."));
        m.exec();        
    }
    if (ratio >= 61 && ratio <=80)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Eres un alumno aventajado, solo te falta un poco mas de experiencia."));
        m.exec();        
    }
    if (ratio >= 81 && ratio <=100)
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Eres un experto en este mundo y se nota que te gusta.<p>ENHORABUENA!!!"));
        m.exec();
    }
    if (Value == 0)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Realizar de nuevo el test")),
                    QString::fromUtf8(tr("<center><b>Realizar de nuevo el test</center><p>"
                    "Has completado el test, por lo que puedes volver a realizarlo para "
                    "coger experiencia o salir.<p>"
                    "&iquest;Hacer de nuevo el test?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            Examen = 1;
            Suma=0;
            ui->label_8->setText("");
            ui->label_9->setText("");
            ui->label->setText("");
            ui->label_2->setText("");
            if (CierreTotal == 1)
            {
                ui->label_4->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                ui->label_5->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                ui->label_6->setStyleSheet("color: rgb(0,0,0); font: 14pt");
            }
            else
            {
                ui->label_4->setStyleSheet("color: rgb(0,0,0)");
                ui->label_5->setStyleSheet("color: rgb(0,0,0)");
                ui->label_6->setStyleSheet("color: rgb(0,0,0)");
            }
            this->pregunta();
        }
        else
            close();
    }
    else if (Value == 1)
    {
        int respuesta = 0;
        respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Realizar de nuevo el test")),
                    QString::fromUtf8(tr("<center><b>Realizar de nuevo el test</center><p>"
                    "Has completado el test, por lo que puedes volver a realizarlo para "
                    "coger experiencia.<p>"
                    "&iquest;Hacer de nuevo el test?")), QMessageBox::Ok, QMessageBox::No);
        if (respuesta == QMessageBox::Ok)
        {
            Examen = 1;
            Suma = 0;
            ui->label_8->setText("");
            ui->label_9->setText("");
            ui->label->setText("");
            ui->label_2->setText("");
            if (CierreTotal == 1)
            {
                ui->label_4->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                ui->label_5->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                ui->label_6->setStyleSheet("color: rgb(0,0,0); font: 14pt");
            }
            else
            {
                ui->label_4->setStyleSheet("color: rgb(0,0,0)");
                ui->label_5->setStyleSheet("color: rgb(0,0,0)");
                ui->label_6->setStyleSheet("color: rgb(0,0,0)");
            }
            this->pregunta();
        }
    }
}

void examen::ramdom()
{
    if (Examen <= 100)
    {
        int num;
        num=qrand()%99+1;
        QSqlQuery PreTest(db);                
        PreTest.exec("SELECT Pregunta FROM Test WHERE id='"+QString::number(num)+"'");
        PreTest.first();
        if (PreTest.isSelect())
            CntTest=PreTest.value(0).toString();
        else
            CntTest="";
        if (CntTest == "")
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Ya has contestado a todas las preguntas. Ahora te comento que tal me ha parecido tu experiencia."));
            m.exec();
            int ratio = (Suma*100)/Examen;
            if (ratio <= 20)
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Eres bastante novato. Te queda mucho por aprender."));
                m.exec();
            }
            if (ratio >= 21 && ratio <=40)
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Tienes base, pero te falta algo de experiencia."));
                m.exec();
            }
            if (ratio >= 41 && ratio <=60)
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Vas por buen camino, sigue asi y lo conseguiras."));
                m.exec();
            }
            if (ratio >= 61 && ratio <=80)
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Eres un alumno aventajado, solo te falta un poco mas de experiencia."));
                m.exec();
            }
            if (ratio >= 81 && ratio <=100)
            {
                QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Eres un experto en este mundo y se nota que te gusta.<p>ENHORABUENA!!!"));
                m.exec();
            }
            if (Value == 0)
            {
                int respuesta = 0;
                respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Realizar de nuevo el test")),
                            QString::fromUtf8(tr("<center><b>Realizar de nuevo el test</center><p>"
                            "Has completado el test, por lo que puedes volver a realizarlo para "
                            "coger experiencia o salir.<p>"
                            "&iquest;Hacer de nuevo el test?")), QMessageBox::Ok, QMessageBox::No);
                if (respuesta == QMessageBox::Ok)
                {
                    Examen = 1;
                    Suma=0;
                    ui->label_8->setText("");
                    ui->label_9->setText("");
                    ui->label->setText("");
                    ui->label_2->setText("");
                    if (CierreTotal == 1)
                    {
                        ui->label_4->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                        ui->label_5->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                        ui->label_6->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                    }
                    else
                    {
                        ui->label_4->setStyleSheet("color: rgb(0,0,0)");
                        ui->label_5->setStyleSheet("color: rgb(0,0,0)");
                        ui->label_6->setStyleSheet("color: rgb(0,0,0)");
                    }
                    this->pregunta();
                }
                else
                    close();
            }
            else if (Value == 1)
            {
                int respuesta = 0;
                respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Realizar de nuevo el test")),
                            QString::fromUtf8(tr("<center><b>Realizar de nuevo el test</center><p>"
                            "Has completado el test, por lo que puedes volver a realizarlo para "
                            "coger experiencia.<p>"
                            "&iquest;Hacer de nuevo el test?")), QMessageBox::Ok, QMessageBox::No);
                if (respuesta == QMessageBox::Ok)
                {
                    Examen = 1;
                    Suma = 0;
                    ui->label_8->setText("");
                    ui->label_9->setText("");
                    ui->label->setText("");
                    ui->label_2->setText("");
                    if (CierreTotal == 1)
                    {
                        ui->label_4->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                        ui->label_5->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                        ui->label_6->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                    }
                    else
                    {
                        ui->label_4->setStyleSheet("color: rgb(0,0,0)");
                        ui->label_5->setStyleSheet("color: rgb(0,0,0)");
                        ui->label_6->setStyleSheet("color: rgb(0,0,0)");
                    }
                    this->pregunta();
                }
            }
        }
        ui->groupBox->setTitle("Pregunta Nº "+QString::number(Examen));
        ui->textEdit->setText(CntTest);
        QSqlQuery ResTest1(db);
        ResTest1.exec("SELECT Respuesta1 FROM Test WHERE Pregunta='"+CntTest+"'");
        ResTest1.first();
        if (ResTest1.isSelect())
            RespTest1=ResTest1.value(0).toString();
        QSqlQuery ResTest2(db);
        ResTest2.exec("SELECT Respuesta2 FROM Test WHERE Pregunta='"+CntTest+"'");
        ResTest2.first();
        if (ResTest2.isSelect())
            RespTest2=ResTest2.value(0).toString();
        QSqlQuery ResTest3(db);
        ResTest3.exec("SELECT Respuesta3 FROM Test WHERE Pregunta='"+CntTest+"'");
        ResTest3.first();
        if (ResTest3.isSelect())
            RespTest3=ResTest3.value(0).toString();
        int valor = qrand() % 2 + 1;
        if (valor == 1)
        {
            ui->label_4->setText(RespTest1);
            ui->label_5->setText(RespTest2);
            ui->label_6->setText(RespTest3);
        }
        else if (valor == 2)
        {
            ui->label_4->setText(RespTest2);
            ui->label_5->setText(RespTest3);
            ui->label_6->setText(RespTest1);
        }
        else if (valor == 3)
        {
            ui->label_4->setText(RespTest3);
            ui->label_5->setText(RespTest1);
            ui->label_6->setText(RespTest2);
        }
    }
    else
    {
        QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Ya has contestado a todas las preguntas. Ahora te comento que tal me ha parecido tu experiencia."));
        m.exec();
        int ratio = (Suma*100)/Examen;
        if (ratio <= 20)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Eres bastante novato. Te queda mucho por aprender."));
            m.exec();
        }
        if (ratio >= 21 && ratio <=40)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Tienes base, pero te falta algo de experiencia."));
            m.exec();
        }
        if (ratio >= 41 && ratio <=60)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Vas por buen camino, sigue asi y lo conseguiras."));
            m.exec();
        }
        if (ratio >= 61 && ratio <=80)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Eres un alumno aventajado, solo te falta un poco mas de experiencia."));
            m.exec();
        }
        if (ratio >= 81 && ratio <=100)
        {
            QMessageBox m; if (Stilo == "A") m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Eres un experto en este mundo y se nota que te gusta.<p>ENHORABUENA!!!"));
            m.exec();
        }
        if (Value == 0)
        {
            int respuesta = 0;
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Realizar de nuevo el test")),
                        QString::fromUtf8(tr("<center><b>Realizar de nuevo el test</center><p>"
                        "Has completado el test, por lo que puedes volver a realizarlo para "
                        "coger experiencia o salir.<p>"
                        "&iquest;Hacer de nuevo el test?")), QMessageBox::Ok, QMessageBox::No);
            if (respuesta == QMessageBox::Ok)
            {
                Examen = 1;
                Suma=0;
                ui->label_8->setText("");
                ui->label_9->setText("");
                ui->label->setText("");
                ui->label_2->setText("");
                if (CierreTotal == 1)
                {
                    ui->label_4->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                    ui->label_5->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                    ui->label_6->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                }
                else
                {
                    ui->label_4->setStyleSheet("color: rgb(0,0,0)");
                    ui->label_5->setStyleSheet("color: rgb(0,0,0)");
                    ui->label_6->setStyleSheet("color: rgb(0,0,0)");
                }
                this->pregunta();
            }
            else
                close();
        }
        else if (Value == 1)
        {
            int respuesta = 0;
            respuesta = QMessageBox::question(this, QString::fromUtf8(tr("Realizar de nuevo el test")),
                        QString::fromUtf8(tr("<center><b>Realizar de nuevo el test</center><p>"
                        "Has completado el test, por lo que puedes volver a realizarlo para "
                        "coger experiencia.<p>"
                        "&iquest;Hacer de nuevo el test?")), QMessageBox::Ok, QMessageBox::No);
            if (respuesta == QMessageBox::Ok)
            {
                Examen = 1;
                Suma = 0;
                ui->label_8->setText("");
                ui->label_9->setText("");
                ui->label->setText("");
                ui->label_2->setText("");
                if (CierreTotal == 1)
                {
                    ui->label_4->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                    ui->label_5->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                    ui->label_6->setStyleSheet("color: rgb(0,0,0); font: 14pt");
                }
                else
                {
                    ui->label_4->setStyleSheet("color: rgb(0,0,0)");
                    ui->label_5->setStyleSheet("color: rgb(0,0,0)");
                    ui->label_6->setStyleSheet("color: rgb(0,0,0)");
                }
                this->pregunta();
            }
        }
    }
}

bool examen::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Escape)
            {
                if (CierreTotal == 0)
                    close();
                else if (CierreTotal == 1)
                    return true;
            }
        }
        if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("Test de Linux"));
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}
