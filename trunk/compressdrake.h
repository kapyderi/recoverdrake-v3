#ifndef COMPRESSDRAKE_H
#define COMPRESSDRAKE_H

#include <QDialog>
#include <stdio.h>
#include <QSqlDatabase>
#include "ayuda.h"
#include <QTableWidgetItem>

#define MAX_CODE_SIZE 32
#define CHARS_LIMIT 256

namespace Ui {
class CompressDrake;
}

class CompressDrake : public QDialog
{
    Q_OBJECT

public:
    explicit CompressDrake(QWidget *parent = 0);
    ~CompressDrake();
    QString RecibirFileName();
    void huffmanEncode(const char* inputFile);
    void huffmanDecode(const char* inputFile, const char* outputFile);
    unsigned int getFileSize(FILE * src);
    unsigned int calcNumOfFreq(unsigned int * freqList);

protected:
    void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *, QEvent *);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void Comprobar();
    void on_pushButton_7_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void Comprobar1();
    void on_pushButton_6_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_13_clicked();

private:
    Ui::CompressDrake *ui;
    Ayuda *ayuda;
    QString FileInName;
    QString FileOutName;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QString Stilo;
    QSqlDatabase db;
    QString user;
    QString inputFileName;
    QString getRpm(QString Valor);
    QString getLista(QString Valor);
    QString getListado(QString Comando);
    int Comprobacion;
    void getCodigo(QString Archivo, QString Tipo);
    QList<QTableWidgetItem *> items;
    void outputFilePath(const char * path, char * outputPath, const char * fileExtension);
    void showDoneMessage(const char * msg);
    struct HuffNode
    {
        unsigned int freq;
        unsigned char charCode;
        bool leaf;
        HuffNode * next;
        HuffNode * left;
        HuffNode * right;
    };
    struct HuffCode
    {
        unsigned char code[MAX_CODE_SIZE];
        unsigned int length;
    };
    struct HuffHeader
    {
        unsigned int numOfFreq;
        unsigned int fileSize;
    };
    struct HuffFreq
    {
        unsigned int freq;
        unsigned char charCode;
    };
    void calcCharFreq(FILE * src, unsigned int * freqList);
    void buildNodeList(HuffNode ** nodeList, unsigned int * freqList);
    void addToNodeList(HuffNode ** nodeList, HuffNode * newNode);
    void buildHuffTree(HuffNode ** nodeList);
    bool buildHuffCode(HuffNode * treeRoot, HuffCode * hCode, unsigned char goalChar);
    void writeHeader(FILE * dest, HuffHeader hHeader, unsigned int numOfFreq, unsigned int fileSize);
    void writeFreq(FILE * dest, unsigned int * freqList, HuffFreq hFreq);
    void writeEncodedData(FILE * src, FILE * dest, HuffCode * huffCodeTable, unsigned int fileSize);
    void freeHuffTree(HuffNode * treeRoot);
    void buildNodeList(HuffNode ** nodeList, HuffFreq * hFreq, unsigned int numOfFreq);
    void addToNodeLista(HuffNode ** nodeList, HuffNode * newNode);
    void writeDecodedData(FILE * src, FILE * dest, HuffNode * rootTree, unsigned int fileSize);
    int Posicion;

};

#endif // COMPRESSDRAKE_H
