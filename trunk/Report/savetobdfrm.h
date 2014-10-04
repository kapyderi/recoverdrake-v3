#ifndef SAVETOBDFRM_H
#define SAVETOBDFRM_H

#include <QDialog>
#include <QModelIndex>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "opciones.h"
#include "Smpt/SmtpMime"
#include "Report/paper.h"
#include <Report/reportrenderer.h>

namespace Ui {
class SaveToBDFrm;
}

class SaveToBDFrm : public QDialog
{
    Q_OBJECT
    
public:
    explicit SaveToBDFrm(QWidget *parent = 0);
    ~SaveToBDFrm();
    QString nombre;
    QString desc;
    int grad;    
    void Valor(QString valor, QString tipo, QString Id, QString ruta);
    int Posicion;
    QString tabla;
    QString Ruta;
    int Tipo;
    static EmailAddress * stringToEmail(const QString & str);
    QString Formato;
    QString RutaPDF;

protected:
    virtual bool eventFilter(QObject *, QEvent *);

private slots:
    void currentRowChanged(const QModelIndex & current, const QModelIndex & previous);
    void on_txtNombre_textChanged(const QString &arg1);
    void on_txtDesc_textChanged(const QString &arg1);
    void on_spinGrd_valueChanged(int arg1);
    void Comprobar();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_comboCampo_currentIndexChanged(const QString &arg1);
    void Cambiar();
    void ValorRuta(QString Valor);
    void Comprueba(int a);
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_addAttachment_clicked();    
    void on_btnBold_clicked(bool checked);
    void on_btnItalic_clicked(bool checked);
    void on_btnUnder_clicked(bool checked);
    void on_btnColor_clicked();
    void on_btnLeft_clicked();
    void on_btnCenter_clicked();
    void on_btnRigth_clicked();
    void on_sizeSpin_valueChanged(int arg1);
    void on_fontComboBox_currentIndexChanged(const QString &arg1);
    void on_pushButton_5_clicked();
    void Cambiar1();
    void Cambiar2();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_btnAcept_clicked();
    void on_btnCancel_clicked();
    void Comenzar();
    void print();
    void pdf();
    void previewReady();
    void on_pushButton_6_clicked();
    void on_tableView_2_doubleClicked(const QModelIndex &index);
    void on_lineEdit_2_textChanged(const QString &arg1);
    void Imprimir(QPrinter *printer);

private:
    Ui::SaveToBDFrm *ui;
    QSqlTableModel* model;
    int Value;
    int Dir;
    opciones *opcion;
    QSqlDatabase db;
    QString cantidadDefecto;
    QString cantidad47;
    QString cantidad48;
    QString cantidad49;
    QString DatoTalla;
    QString DatoNegro;
    QString cantidad50;
    QString cantidad51;
    QString Stilo;
    QString user;
    QString Listado;
    Paper paper;
    ReportRenderer* render;
    QString IDUser;
    QString Conexion;
    QString RutaImp;

};

#endif // SAVETOBDFRM_H
