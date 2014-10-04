#include "compressdrake.h"
#include "ui_compressdrake.h"
#include <QFileDialog>
#include <QSqlQuery>
#include <QDebug>
#include "drakesistema.h"
#include <QMessageBox>
#include <QKeyEvent>
#include <QFile>
#include <QProgressDialog>
#include <QProcess>
#include <QFuture>
#include <QtConcurrentRun>

CompressDrake::CompressDrake(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompressDrake)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PRINCIPAL");
    drakeSistema drake;
    user = drake.getUser();
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
        Stilo = "A";
    }
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Comprobar()));
    connect(ui->checkBox_2,SIGNAL(clicked()),this,SLOT(Comprobar1()));
    ui->radioButton->setChecked(true);
    ui->stackedWidget->setCurrentIndex(0);
    this->Comprobar();
    this->installEventFilter(this);
    Comprobacion = 0;
    ui->pushButton_12->setVisible(false);
    ui->pushButton_14->setVisible(false);
    ui->pushButton_15->setVisible(false);
    ui->tableWidget_2->hideColumn(2);
}

CompressDrake::~CompressDrake()
{
    delete ui;
}

void CompressDrake::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

bool CompressDrake::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == this)
    {
        if (event->type() == QEvent::KeyRelease)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_F1)
            {
                ayuda = new Ayuda(this);
                ayuda->show();
                ayuda->Valor(tr("CompressDrake"));
                return true;
            }
        }
        return false;
    }
    return QDialog::eventFilter(obj, event);
}

void CompressDrake::on_pushButton_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    FileInName = QFileDialog::getSaveFileName(this, tr("Nombre de destino"),path,tr("Compresion RDK (*.rdk)"));
    if (FileInName.isEmpty())
        return;
    if (FileInName.endsWith(".rdk") == false)
        FileInName = FileInName+".rdk";
    ui->lineEdit->setText(FileInName);
}

void CompressDrake::on_pushButton_2_clicked()
{
    close();
}

void CompressDrake::Comprobar()
{
    if (ui->radioButton->isChecked())
    {
         ui->stackedWidget->setCurrentIndex(0);
         ui->checkBox_2->setVisible(true);
         ui->groupBox_2->setVisible(true);
         ui->groupBox_3->setVisible(false);
         ui->pushButton_9->setVisible(false);
    }
    if (ui->radioButton_2->isChecked())
    {
         ui->stackedWidget->setCurrentIndex(1);
         ui->checkBox_2->setVisible(false);
         ui->groupBox_2->setVisible(false);
         ui->groupBox_3->setVisible(true);
         ui->pushButton_9->setVisible(true);
         if (Comprobacion ==0)
         {
             QString Localizar = getRpm("hexedit");
             if (Localizar.contains(tr("instalado")) || Localizar.contains("installed") || Localizar.contains("instalado"))
             {
                 QMessageBox m;
                 if (Stilo == "A")
                     m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                 m.setText(tr("No se puede utilizar las opciones de visualizar/editar codigo hexadecimal/binario, debido a que no tienes instalado el paquete \"hexedit\" en el sistema.<p>Seran deshabilitadas y deberas utilizar la opcion de dependencias para realizar la actualizacion."));
                 m.exec();
                 Comprobacion = 1;
                 ui->pushButton_9->setEnabled(false);
                 ui->pushButton_10->setEnabled(false);
                 ui->pushButton_11->setEnabled(false);
                 return;
             }
         }
    }
}

void CompressDrake::Comprobar1()
{
    if (ui->checkBox_2->isChecked())
    {
        if (FileInName.endsWith(".tar"))
        {
            FileInName = FileInName.remove(".tar");
            ui->lineEdit->setText(FileInName);
        }
    }
    else
    {
        if (ui->tableWidget->rowCount() > 1)
        {
            if (!FileInName.endsWith(".tar"))
            {
                FileInName = FileInName.append(".tar");
                ui->lineEdit->setText(FileInName);
            }
        }
    }
}

void CompressDrake::on_pushButton_3_clicked()
{
    QTableWidgetItem *item1,*item2,*item3;
    QString rutaAbs;
    float f;
    int iFilas;
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QStringList FileIn = QFileDialog::getOpenFileNames(this, tr("Archivos a insertar"),path,tr("Todos los archivos (*.* *)"));
    for (int a=0;a<FileIn.count();a++)
    {
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        item3=new QTableWidgetItem;
        rutaAbs = FileIn.value(a);
        items = ui->tableWidget->findItems(rutaAbs, Qt::MatchExactly);
        if (items.count() == 0)
        {
            QFile file(rutaAbs);
            float size = QFileInfo(file).size();
            item1->setText(tr(QFileInfo(file).fileName()));
            item2->setText(tr(rutaAbs));
            f = size;
            if (f > 0)
            {
                if (f <= 999)
                    item3->setText(""+QString::number(f)+" B");
                if (f > 999 && f <= 999999)
                {
                    f = (size + 1023) / 1024;
                    item3->setText(""+QString::number(f,'f',1)+" kB");
                }
                if (f > 999999 && f <= 999999999)
                {
                    f = (size + 1023) / 1024;
                    f = f / 1024;
                    item3->setText(""+QString::number(f,'f',1)+" MB");
                }
                if (f > 999999999)
                {
                    f = (size + 1023) / 1024;
                    f = f / 1024;
                    f = f / 1024;
                    item3->setText(""+QString::number(f,'f',1)+" GB");
                }
                iFilas=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(iFilas);
                ui->tableWidget->setItem(iFilas,0,item1);
                ui->tableWidget->setItem(iFilas,1,item2);
                ui->tableWidget->setItem(iFilas,2,item3);
                ui->tableWidget->resizeRowsToContents();
                ui->tableWidget->resizeColumnsToContents();
            }
        }
    }
    if (!ui->checkBox_2->isChecked())
    {
        ui->groupBox_2->setEnabled(true);
        if (ui->tableWidget->rowCount() > 1)
        {
            if (!FileInName.endsWith(".tar"))
            {
                FileInName = FileInName.append(".tar");
                ui->lineEdit->setText(FileInName);
            }
        }
    }
    else
        ui->groupBox_2->setEnabled(false);
}

void CompressDrake::on_pushButton_7_clicked()
{
    int Borrado, x;
    Borrado = ui->tableWidget->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    if (FileInName.endsWith(".tar"))
    {
        FileInName = FileInName.remove(".tar");
        ui->lineEdit->setText(FileInName);
    }
}

void CompressDrake::on_pushButton_5_clicked()
{
    QTableWidgetItem *item1, *item0;
    QString activo1, activo2;
    int itemCount = ui->tableWidget->rowCount();
    if (itemCount == 0)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QProgressDialog progressDialog(tr("Comprimiendo..."), tr("Cancelar"), 0, itemCount, this);
        progressDialog.setWindowModality(Qt::WindowModal);
        progressDialog.show();
        progressDialog.setValue(0);
        for(int i=0;i<itemCount;i++)
        {
            if (progressDialog.wasCanceled())
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Compresion abortada!"));
                m.exec();
                break;
            }
            item0 = ui->tableWidget->item(i,0);
            item1 = ui->tableWidget->item(i,1);
            activo1 = item1->text();
            activo2 = item0->text();
            QByteArray byteArray1 = activo1.toUtf8();
            const char* inputFile = byteArray1.constData();
            huffmanEncode(inputFile);
            progressDialog.setValue(i);
            ui->tableWidget->selectRow(i+1);
            progressDialog.setLabelText(tr("Comprimiendo... ")+activo2);
        }
        progressDialog.setValue(ui->tableWidget->rowCount());
        if (ui->checkBox_2->isChecked())
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Todos los trabajos realizados."));
            m.exec();
            return;
        }
        else
        {
            if (ui->tableWidget->rowCount() > 1)
            {
                QString Resto = "'";
                QString Archivos = getLista("/home/"+user+"/TempRDK/");
                QStringList Parcial = Archivos.split("\n");
                QProgressDialog progressDialog(tr("Empaquetando..."), tr("Cancelar"), 0, Parcial.count(), this);
                progressDialog.setWindowModality(Qt::WindowModal);
                progressDialog.show();
                progressDialog.setValue(0);
                for (int a=0;a<Parcial.count();a++)
                {
                    QString Valor = Parcial.value(a);
                    if (a == 0)
                        Resto.append(Valor+"' ");
                    else if (a == Parcial.count()-1)
                        Resto.append("'"+Valor+"'");
                    else
                        Resto.append("'"+Valor+"' ");
                    progressDialog.setValue(a);
                }
                system("su - "+user+" -c \"tar -vcf "+ui->lineEdit->text()+" -C /home/"+user+"/TempRDK/ "+Resto+"\"");
                progressDialog.setValue(Parcial.count());
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Todos los trabajos realizados.<p>Ha sido empaquetado con extension \".rdk.tar\"."));
                m.exec();
                system("rm -R /home/"+user+"/TempRDK/");
                return;
            }
            else
            {
                QMessageBox m;
                if (Stilo == "A")
                    m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                m.setText(tr("Todos los trabajos realizados."));
                m.exec();
                return;
            }
        }
    }
}

QString CompressDrake::getLista(QString Valor)
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << Valor;
    procesoRPM->start("ls",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res =  QString(Paquete);
    res.chop(1);
    return res;
}

void CompressDrake::huffmanEncode(const char* inputFile)
{
    FILE * src = fopen(inputFile, "rb");
    char outputPath[1000];
    const char * fileExtension = ".rdk";
    if (ui->checkBox_2->isChecked())
    {
        if (ui->tableWidget->rowCount() > 1)
            outputFilePath(inputFile, outputPath, fileExtension);
        else
        {
            QString Dato = ui->lineEdit->text();
            strcpy (outputPath, Dato.toStdString().c_str());
        }
    }
    else if (!ui->checkBox_2->isChecked())
    {
        if (ui->tableWidget->rowCount() == 1)
        {
            QString Dato = ui->lineEdit->text();
            strcpy (outputPath, Dato.toStdString().c_str());
        }
        else if (ui->tableWidget->rowCount() > 1)
        {
            QString path=tr("/home/%1/TempRDK/");
            path=path.arg(user);
            QString Explora;
            Explora = "find \"%1\"";
            Explora = Explora.arg(path);
            drakeSistema drake;
            QString value = drake.getStart(Explora);
            if (value == "")
                system("su - "+user+" -c \"mkdir -pv /home/"+user+"/TempRDK/\"");
            QStringList RutaFinal = QString(inputFile).split("/");
            QString Rute = RutaFinal.value(RutaFinal.count()-1);
            const char* Dato = Rute.toStdString().c_str();
            const char * RutaTemp = ""+path+""+Dato+"";
            outputFilePath(RutaTemp, outputPath, fileExtension);
        }
    }
    FILE * dest = fopen(outputPath, "wb");
    if (src == NULL || dest == NULL)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se encuentran los archivos seleccionados, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    unsigned int fileSize;
    fileSize = getFileSize(src);
    unsigned int * freqList;
    freqList = (unsigned int *)calloc(CHARS_LIMIT, sizeof(unsigned int));
    calcCharFreq(src, freqList);
    unsigned int numOfFreq;
    numOfFreq = calcNumOfFreq(freqList);
    HuffNode * nodeList = NULL;
    buildNodeList(&nodeList, freqList);
    buildHuffTree(&nodeList);
    HuffNode * treeRoot = nodeList;
    unsigned int i;
    HuffCode newCode;
    HuffCode * huffCodeTable;
    huffCodeTable = (HuffCode *)calloc(CHARS_LIMIT, sizeof(HuffCode));
    for(i=0; i<CHARS_LIMIT; i++)
    {
        if(freqList[i] > 0)
        {
            newCode.length = 0;
            buildHuffCode(treeRoot, &newCode, i);
            huffCodeTable[i] = newCode;
        }
    }
    HuffHeader hHeader;
    writeHeader(dest, hHeader, numOfFreq, fileSize);
    HuffFreq hFreq;
    writeFreq(dest, freqList, hFreq);
    writeEncodedData(src, dest, huffCodeTable, fileSize);
    freeHuffTree(treeRoot);
    treeRoot = NULL;
    free(huffCodeTable);
    free(freqList);
    fclose(src);
    fclose(dest);
}

void CompressDrake::outputFilePath(const char *path, char * outputPath, const char *fileExtension)
{
    int i;
    const int pathLength = strlen(path);
    for(i=0; i<pathLength; i++)
        outputPath[i] = path[i];
    outputPath[i] = 0;
    strcat(outputPath, fileExtension);
}

unsigned int CompressDrake::getFileSize(FILE * src)
{
    unsigned int fileSize = 0;
    unsigned int c;
    while((c = fgetc(src)) != EOF)
        fileSize++;
    rewind(src);
    return fileSize;
}

void CompressDrake::calcCharFreq(FILE * src, unsigned int * freqList)
{
    unsigned int c;
    while((c = fgetc(src)) != EOF)
        freqList[c]++;
    rewind(src);
}

unsigned int CompressDrake::calcNumOfFreq(unsigned int * freqList)
{
    unsigned int i;
    unsigned int numOfFreq = 0;
    for(i=0; i<CHARS_LIMIT; i++)
    {
        if(freqList[i] > 0)
            numOfFreq++;
    }
    return numOfFreq;
}

void CompressDrake::buildNodeList(HuffNode ** nodeList, unsigned int * freqList)
{
    unsigned int i;
    HuffNode * newNode;
    for(i=0; i<CHARS_LIMIT; i++)
    {
        if(freqList[i] > 0)
        {
            newNode = (HuffNode *)calloc(1, sizeof(HuffNode));
            newNode->charCode = i;
            newNode->freq = freqList[i];
            newNode->next = NULL;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->leaf = true;
            addToNodeList(nodeList, newNode);
        }
    }
}

void CompressDrake::addToNodeList(HuffNode ** nodeList, HuffNode * newNode)
{
    HuffNode * prevNode = NULL;
    HuffNode * currNode = *nodeList;
    while(currNode != NULL && currNode->freq < newNode->freq)
    {
        prevNode = currNode;
        currNode = prevNode->next;
    }
    newNode->next = currNode;
    if(prevNode == NULL)
        *nodeList = newNode;
    else
        prevNode->next = newNode;
}

void CompressDrake::buildHuffTree(HuffNode ** nodeList)
{
    HuffNode * leftNode, * rightNode;
    HuffNode * newNode;
    while((*nodeList)->next)
    {
        leftNode = *nodeList;
        *nodeList = leftNode->next;
        rightNode = *nodeList;
        *nodeList = rightNode->next;
        newNode = (HuffNode *)calloc(1, sizeof(HuffNode));
        newNode->charCode = 0;
        newNode->freq = leftNode->freq + rightNode->freq;
        newNode->next = NULL;
        newNode->left = leftNode;
        newNode->right = rightNode;
        newNode->leaf = false;
        addToNodeList(nodeList, newNode);
    }
}

bool CompressDrake::buildHuffCode(HuffNode * treeRoot, HuffCode * hCode, unsigned char goalChar)
{
    if(treeRoot->charCode == goalChar && treeRoot->leaf)
        return true;
    if(treeRoot->left)
    {
        hCode->code[hCode->length] = '0';
        hCode->length++;
        if(hCode->length == MAX_CODE_SIZE)
        {
            QMessageBox m;
            if (Stilo == "A")
                m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
            m.setText(tr("Limite de rango de codigos excedido!"));
            m.exec();
            return false;
        }
        if(buildHuffCode(treeRoot->left, hCode, goalChar))
        {
            hCode->code[hCode->length] = 0;
            return true;
        }
        else
        {
            hCode->length--;
            hCode->code[hCode->length] = 0;
        }
    }
    if(treeRoot->right)
    {
        hCode->code[hCode->length] = '1';
        hCode->length++;
        if(buildHuffCode(treeRoot->right, hCode, goalChar))
            return true;
        else
        {
            hCode->length--;
            hCode->code[hCode->length] = 0;
        }
    }
    return false;
}

void CompressDrake::writeHeader(FILE * dest, HuffHeader hHeader, unsigned int numOfFreq, unsigned int fileSize)
{
    hHeader.numOfFreq = numOfFreq;
    hHeader.fileSize = fileSize;
    fwrite(&hHeader, sizeof(hHeader), 1, dest);
}

void CompressDrake::writeFreq(FILE * dest, unsigned int * freqList, HuffFreq hFreq)
{
    unsigned int i;
    for(i=0; i<CHARS_LIMIT; i++)
    {
        if(freqList[i] > 0)
        {
            hFreq.charCode = i;
            hFreq.freq = freqList[i];
            fwrite(&hFreq, sizeof(HuffFreq), 1, dest);
        }
    }
}

void CompressDrake::writeEncodedData(FILE * src, FILE * dest, HuffCode * huffCodeTable, unsigned int fileSize)
{
    Q_UNUSED(fileSize);
    unsigned int i, c;
    unsigned int bits = 0;
    char currChar = 0;
    HuffCode currCode;
    while((c = fgetc(src)) != EOF)
    {
        currCode = huffCodeTable[c];
        for(i=0; i<currCode.length; i++)
        {
            currChar = (currChar << 1) + (currCode.code[i] == '1' ? 1 : 0);
            bits++;
            if(bits == 8)
            {
                fputc(currChar, dest);
                currChar = 0;
                bits = 0;
            }
        }
    }
    if(bits > 0)
    {
        currChar = currChar << (8 - bits);
        fputc(currChar, dest);
    }
}

void CompressDrake::freeHuffTree(HuffNode * treeRoot)
{
    if(treeRoot)
    {
        freeHuffTree(treeRoot->left);
        freeHuffTree(treeRoot->right);
        free(treeRoot);
    }
}

void CompressDrake::on_pushButton_4_clicked()
{
    int j;
    j=ui->tableWidget->currentRow();
    if (j == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes realizar lo que has solicitado."));
        m.exec();
        return;
    }
    else
    {
        ui->tableWidget->removeRow(j);
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();
    }
    if (ui->tableWidget->rowCount() <= 1)
    {
        if (FileInName.endsWith(".tar"))
        {
            FileInName = FileInName.remove(".tar");
            ui->lineEdit->setText(FileInName);
        }
    }
}

void CompressDrake::on_pushButton_9_clicked()
{
    if (ui->lineEdit_2->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ruta seleccionada, por lo que no puedes visualizar el codigo hexadecimal/binario."));
        m.exec();
        return;
    }
    QString Tipo = "Ver";
    QFuture<void> f1 = QtConcurrent::run(this, &CompressDrake::getCodigo,ui->lineEdit_2->text(),Tipo);
    Q_UNUSED(f1);
}

void CompressDrake::getCodigo(QString Archivo, QString Tipo)
{
    if (Tipo == "Ver")
        system("konsole --noclose -e hexdump -C "+Archivo+"");
    if (Tipo == "Editar")
        system("konsole --noclose -e hexedit "+Archivo+"");
}

void CompressDrake::on_pushButton_8_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    FileOutName = QFileDialog::getOpenFileName(this, tr("Nombre de origen"),path,tr("Compresion RDK (*.rdk *.rdk.tar)"));
    if (FileOutName.isEmpty())
        return;
    ui->lineEdit_2->setText(FileOutName);
    int Borrado, x;
    Borrado = ui->tableWidget_2->rowCount();
    for(x=0;x<Borrado;x++)
    {
         ui->tableWidget_2->removeRow(x);
         x=x-1;
         Borrado=Borrado-1;
    }
    QString Lista, Value;
    float f;
    int iFilas;
    QTableWidgetItem *item1,*item2,*item3;
    if (FileOutName.contains(".tar"))
    {
        ui->pushButton_12->setVisible(true);
        ui->pushButton_14->setVisible(true);
        ui->pushButton_15->setVisible(true);
        ui->tableWidget_2->showColumn(2);
        Value = "su - %2 -c \"tar -t --list -f '%1'\"";
        Value = Value.arg(FileOutName).arg(user);
        Lista = getListado(Value);
        QStringList Parcial = Lista.split("\n");
        for(int a=0;a<Parcial.count();a++)
        {
            QString FFinal = Parcial.value(a);
            FFinal.replace(QRegExp("\\s+"), " ");
            FFinal.trimmed();
            QStringList Final = FFinal.split(" ");
            item1=new QTableWidgetItem;
            item2=new QTableWidgetItem;
            item3=new QTableWidgetItem;
            QString size= Final.value(2);
            QString Juntar;
            for (int h=5;h<Final.count();h++)
                Juntar.append(Final.value(h)+" ");
            item1->setText(Juntar);
            f = size.toFloat();
            if (f > 0)
            {
                if (f <= 999)
                    item2->setText(""+QString::number(f)+" B");
                if (f > 999 && f <= 999999)
                {
                    f = (f + 1023) / 1024;
                    item2->setText(""+QString::number(f,'f',1)+" kB");
                }
                if (f > 999999 && f <= 999999999)
                {
                    f = (f + 1023) / 1024;
                    f = f / 1024;
                    item2->setText(""+QString::number(f,'f',1)+" MB");
                }
                if (f > 999999999)
                {
                    f = (f + 1023) / 1024;
                    f = f / 1024;
                    f = f / 1024;
                    item2->setText(""+QString::number(f,'f',1)+" Gb");
                }
            }
            item3->setText(tr("Si"));
            iFilas=ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(iFilas);
            ui->tableWidget_2->setItem(iFilas,0,item1);
            ui->tableWidget_2->setItem(iFilas,1,item2);
            ui->tableWidget_2->setItem(iFilas,2,item3);
            ui->tableWidget_2->item(iFilas,2)->setIcon(QIcon(":/Imagenes/good.png"));
            ui->tableWidget_2->resizeRowsToContents();
            ui->tableWidget_2->resizeColumnsToContents();
        }
    }
    else
    {
        ui->pushButton_12->setVisible(false);
        ui->pushButton_14->setVisible(false);
        ui->pushButton_15->setVisible(false);
        ui->tableWidget_2->hideColumn(2);
        item1=new QTableWidgetItem;
        item2=new QTableWidgetItem;
        QFile file(FileOutName);
        float size = QFileInfo(file).size();
        item1->setText(tr(QFileInfo(file).fileName()));
        float f;
        f = size;
        if (f > 0)
        {
            if (f <= 999)
                item2->setText(""+QString::number(f)+" B");
            if (f > 999 && f <= 999999)
            {
                f = (f + 1023) / 1024;
                item2->setText(""+QString::number(f,'f',1)+" kB");
            }
            if (f > 999999 && f <= 999999999)
            {
                f = (f + 1023) / 1024;
                f = f / 1024;
                item2->setText(""+QString::number(f,'f',1)+" MB");
            }
            if (f > 999999999)
            {
                f = (f + 1023) / 1024;
                f = f / 1024;
                f = f / 1024;
                item2->setText(""+QString::number(f,'f',1)+" Gb");
            }
        }
        iFilas=ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(iFilas);
        ui->tableWidget_2->setItem(iFilas,0,item1);
        ui->tableWidget_2->setItem(iFilas,1,item2);
        ui->tableWidget_2->resizeRowsToContents();
        ui->tableWidget_2->resizeColumnsToContents();
    }
}


QString CompressDrake::getListado(QString Comando)
{
    QProcess *procesoRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    procesoRPM->start(Comando);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    delete procesoRPM;
    QString res = QString(Paquete);
    res.chop(1);
    return res;
}

void CompressDrake::on_pushButton_10_clicked()
{
    if (ui->lineEdit_2->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ruta seleccionada, por lo que no puedes visualizar el codigo hexadecimal/binario."));
        m.exec();
        return;
    }
    QString Tipo = "Editar";
    QFuture<void> f1 = QtConcurrent::run(this, &CompressDrake::getCodigo,ui->lineEdit_2->text(),Tipo);
    Q_UNUSED(f1);
}

QString CompressDrake::getRpm(QString Valor)
{
    QProcess *procesoRPM;
    QStringList argumentosRPM;
    QByteArray Paquete;
    procesoRPM=new QProcess(this);
    argumentosRPM << "-q" << Valor;
    procesoRPM->start("rpm",argumentosRPM);
    if (! procesoRPM->waitForStarted())
        return QString("");
    procesoRPM->waitForFinished();
    Paquete = QString(procesoRPM->readAllStandardOutput());
    procesoRPM->waitForFinished();
    delete procesoRPM;
    QString res =  QString(Paquete);
    res.chop(1);
    return res;
}

void CompressDrake::on_pushButton_11_clicked()
{
    if (ui->lineEdit_2->text() == "")
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ruta seleccionada, por lo que no puedes exportar el codigo hexadecimal/binario."));
        m.exec();
        return;
    }
    QString FileName;
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    FileName = QFileDialog::getSaveFileName(this, tr("Nombre de destino"),path,tr("Archivos txt (*.txt)"));
    if (FileName.isEmpty())
        return;
    if (FileName.endsWith(".txt") == false)
        FileName = FileName+".txt";
    system("hexdump -C "+ui->lineEdit_2->text()+" >> "+FileName+"");
    QMessageBox m;
    m.setIcon(QMessageBox::Information);
    if (Stilo == "A")
        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
    m.setText(tr("Archivo guardado correctamente."));
    m.exec();
    return;
}

void CompressDrake::on_pushButton_6_clicked()
{
    int itemCount = ui->tableWidget_2->rowCount();
    if (itemCount == 0)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No hay ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QString Ruta, Destino;
        QString ListaPermisos = "'";
        if (ui->lineEdit_3->text() == "")
        {
            QStringList ParteRuta = ui->lineEdit_2->text().split("/");
            Ruta = ui->lineEdit_2->text().remove(ParteRuta.value(ParteRuta.count()-1));
        }
        else
        {
            if (ui->lineEdit_3->text().endsWith("/") == false)
                Ruta = ui->lineEdit_3->text()+"/";
            else
                Ruta = ui->lineEdit_3->text();
        }
        if (itemCount == 1)
        {
            QStringList ParcialRuta = FileOutName.split("/");
            QString RestoRuta = ParcialRuta.value(ParcialRuta.count()-1);
            RestoRuta = RestoRuta.remove(".rdk");
            Destino = Ruta + RestoRuta;
            ListaPermisos.append(Destino+"''");
            QByteArray byteArray1 = FileOutName.toUtf8();
            const char* inputFile = byteArray1.constData();
            QByteArray byteArray2 = Destino.toUtf8();
            const char* outputFile = byteArray2.constData();
            huffmanDecode(inputFile,outputFile);
        }
        else
        {
            QTableWidgetItem *item, *item1;
            QString activo, activo1;
            QString Resto;
            for(int i=0;i<itemCount;i++)
            {
                item = ui->tableWidget_2->item(i,0);
                item1 = ui->tableWidget_2->item(i,2);
                activo = item->text();
                activo = activo.simplified();
                activo1 = item1->text();
                if (activo1 == tr("Si"))
                    Resto.append(" '"+activo+"' ");
            }
            Resto = Resto.simplified();
            Posicion = 0;
            QString path=tr("/home/%1/TempRDK/");
            path=path.arg(user);
            QString Explora;
            Explora = "find \"%1\"";
            Explora = Explora.arg(path);
            drakeSistema drake;
            QString value = drake.getStart(Explora);
            if (value == "")
                system("su - "+user+" -c \"mkdir -pv /home/"+user+"/TempRDK/\"");
            system("su - "+user+" -c \"tar -vxf "+ui->lineEdit_2->text()+" -C /home/"+user+"/TempRDK/ "+Resto+"\"");
            QString Lista = getListado("ls "+path);
            QStringList Parcial = Lista.split("\n");
            QProgressDialog progressDialog(tr("Descomprimiendo..."), tr("Cancelar"), 0, itemCount, this);
            progressDialog.setWindowModality(Qt::WindowModal);
            progressDialog.show();
            progressDialog.setValue(0);
            for(int a=0;a<Parcial.count();a++)
            {
                if (Posicion == 1)
                    return;
                if (progressDialog.wasCanceled())
                {
                    QMessageBox m;
                    if (Stilo == "A")
                        m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
                    m.setText(tr("Descompresion abortada!"));
                    m.exec();
                    break;
                }
                QString Inicio = "/home/%1/TempRDK/"+Parcial.value(a);
                Inicio=Inicio.arg(user);
                QString RestoRuta = Parcial.value(a);
                RestoRuta = RestoRuta.remove(".rdk");
                Destino = Ruta + RestoRuta;
                if (a == 0)
                    ListaPermisos.append(Destino+"' ");
                else if (a == Parcial.count()-1)
                    ListaPermisos.append("'"+Destino+"'");
                else
                    ListaPermisos.append("'"+Destino+"' ");
                QByteArray byteArray1 = Inicio.toUtf8();
                const char* inputFile = byteArray1.constData();
                QByteArray byteArray2 = Destino.toUtf8();
                const char* outputFile = byteArray2.constData();
                huffmanDecode(inputFile,outputFile);
                progressDialog.setValue(a);
                progressDialog.setLabelText(tr("Descomprimiendo... ")+Parcial.value(a));
            }
            progressDialog.setValue(itemCount);
        }
        system("chown "+user+":"+user+" "+ListaPermisos+"");
        if (Ruta.contains("/home/"+user))
            system("chown "+user+":"+user+" "+Ruta+"");
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("Todos los trabajos realizados."));
        m.exec();
        system("rm -R /home/"+user+"/TempRDK/");
        return;
    }
}

void CompressDrake::huffmanDecode(const char* inputFile, const char* outputFile)
{
    FILE * src = fopen(inputFile, "rb");
    FILE * dest = fopen(outputFile, "wb");
    if (src == NULL || dest == NULL)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No se encuentran los archivos seleccionados, por lo que no puedes procesar la solicitud."));
        m.exec();
        Posicion = 1;
        return;
    }
    HuffHeader hHeader;
    fread(&hHeader, sizeof(hHeader), 1, src);
    HuffFreq *hFreq = (HuffFreq *)calloc(hHeader.numOfFreq, sizeof(HuffFreq));
    fread(hFreq, sizeof(HuffFreq), hHeader.numOfFreq, src);
    HuffNode * nodeList = NULL;
    buildNodeList(&nodeList, hFreq, hHeader.numOfFreq);
    buildHuffTree(&nodeList);
    writeDecodedData(src, dest, nodeList, hHeader.fileSize);
    freeHuffTree(nodeList);
    nodeList = NULL;
    free(hFreq);
    fclose(src);
    fclose(dest);
}

void CompressDrake::buildNodeList(HuffNode ** nodeList, HuffFreq * hFreq, unsigned int numOfFreq)
{
    unsigned int i;
    HuffNode * newNode;
    for (i = 0; i < numOfFreq; i++)
    {
        newNode = (HuffNode *) malloc(sizeof(HuffNode));
        newNode->charCode = hFreq[i].charCode;
        newNode->freq = hFreq[i].freq;
        newNode->next = NULL;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->leaf = true;
        addToNodeLista(nodeList, newNode);
    }
}

void CompressDrake::addToNodeLista(HuffNode ** nodeList, HuffNode * newNode)
{
    HuffNode * prevNode = NULL;
    HuffNode * currNode = *nodeList;
    while ((currNode != NULL && currNode->freq < newNode->freq))
    {
        prevNode = currNode;
        currNode = prevNode->next;
    }
    newNode->next = currNode;
    if (prevNode == NULL)
        *nodeList = newNode;
    else
        prevNode->next = newNode;
}

void CompressDrake::writeDecodedData(FILE * src, FILE * dest, HuffNode * rootTree, unsigned int fileSize)
{
    int bit = -1;
    unsigned int c;
    unsigned int bytesWritten = 0;
    HuffNode * currNode = rootTree;
    while(bytesWritten < fileSize)
    {
        if(bit < 0)
        {
            c = fgetc(src);
            if(c == EOF)
                break;
            bit = 7;
        }
        if((c >> bit) & 1)
            currNode = currNode->right;
        else
            currNode = currNode->left;
        if(currNode->leaf)
        {
            fputc(currNode->charCode, dest);
            bytesWritten++;
            currNode = rootTree;
        }
        bit--;
    }
}

void CompressDrake::on_pushButton_12_clicked()
{
    int iFilas;
    QString activo;
    iFilas=ui->tableWidget_2->currentRow();
    if (iFilas == -1)
    {
        QMessageBox m;
        if (Stilo == "A")
            m.setStyleSheet("background-color: "+cantidad51+"; color: "+cantidad50+"; font-size: "+cantidad49+"pt; font-style: "+DatoTalla+"; font-family: "+cantidad47+"; font-weight: "+DatoNegro+"");
        m.setText(tr("No has seleccionado ningun registro, por lo que no puedes procesar la solicitud."));
        m.exec();
        return;
    }
    else
    {
        QTableWidgetItem *item;
        item=new QTableWidgetItem;
        item=ui->tableWidget_2->item(iFilas,2);
        activo = item->text();
        if (activo == tr("Si"))
        {
            item->setText(tr("No"));
            ui->tableWidget_2->setItem(iFilas,2,item);
            ui->tableWidget_2->item(iFilas,2)->setIcon(QIcon(":/Imagenes/bad.png"));
        }
        else if (activo == tr("No"))
        {
            item->setText(tr("Si"));
            ui->tableWidget_2->setItem(iFilas,2,item);
            ui->tableWidget_2->item(iFilas,2)->setIcon(QIcon(":/Imagenes/good.png"));
        }
    }
    ui->tableWidget_2->resizeRowsToContents();
    ui->tableWidget_2->resizeColumnsToContents();
}

void CompressDrake::on_pushButton_14_clicked()
{
    int iFilas, a;
    iFilas=ui->tableWidget_2->rowCount();
    for(a=0;a<iFilas;a++)
    {
        QTableWidgetItem *item;
        item=new QTableWidgetItem;
        qApp->processEvents();
        item->setText(tr("Si"));
        ui->tableWidget_2->setItem(a,2,item);
        ui->tableWidget_2->item(a,2)->setIcon(QIcon(":/Imagenes/good.png"));
    }
    ui->tableWidget_2->resizeRowsToContents();
    ui->tableWidget_2->resizeColumnsToContents();
}

void CompressDrake::on_pushButton_15_clicked()
{
    int iFilas, a;
    iFilas=ui->tableWidget_2->rowCount();
    for(a=0;a<iFilas;a++)
    {
        QTableWidgetItem *item;
        item=new QTableWidgetItem;
        qApp->processEvents();
        item->setText(tr("No"));
        ui->tableWidget_2->setItem(a,2,item);
        ui->tableWidget_2->item(a,2)->setIcon(QIcon(":/Imagenes/bad.png"));
    }
    ui->tableWidget_2->resizeRowsToContents();
    ui->tableWidget_2->resizeColumnsToContents();
}

void CompressDrake::on_pushButton_13_clicked()
{
    QString path=tr("/home/%1/Documentos/");
    path=path.arg(user);
    QString fileNameDirectori = QFileDialog::getExistingDirectory(this,tr("Directorio donde guardar archivos descomprimidos?"),path,QFileDialog::ShowDirsOnly);
    if (fileNameDirectori.isEmpty())
        return;
    ui->lineEdit_3->setText(fileNameDirectori);
}
