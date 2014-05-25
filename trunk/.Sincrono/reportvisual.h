#ifndef REPORTVISUAL_H
#define REPORTVISUAL_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMessageBox>
#include <QPrintDialog>
#include <QPrinter>
#include <QFile>
#include <QTime>
#include <QProgressDialog>
#include <QApplication>
#include <QThread>
#include "Report/paper.h"
#include "Report/reportview.h"
#include "Report/reportrenderer.h"
#include "Report/sectioneditordlg.h"
#include "Report/container.h"
#include <QSettings>
#include <QSqlDatabase>

namespace Ui {
class ReportVisual;
}

class ReportVisual : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReportVisual(QWidget *parent = 0);
    ~ReportVisual();

protected:
    virtual bool eventFilter(QObject *, QEvent *);

private slots:
    void element_toggled(bool arg1);
    void on_actionGuardar_triggered();
    void on_actionAbrir_triggered();
    void stopInsert();    
    void on_actionVista_Previa_triggered();
    void previewReady();
    void on_actionBlock_triggered();
    void on_actionSalir_triggered();
    void on_actionConfigurar_modelo_triggered();
    void on_actionCrear_seccion_triggered();
    void on_actionDestruir_bloque_triggered();
    void on_actionVer_contorno_objetos_triggered(bool chekcked);
    void on_actionAlinear_Izquierda_triggered();
    void on_actionAlinear_Derecha_triggered();
    void on_actionAlinear_Centro_triggered();
    void on_actionAlinear_Arriba_triggered();
    void on_actionAlinear_centro_triggered();
    void on_actionAlinear_abajo_triggered();
    void on_actionNuevo_triggered();
    void refreshItems();
    void itemChanged (QListWidgetItem * item);
    void sceneSelectionChanged();
    void on_itemList_itemDoubleClicked(QListWidgetItem *item);
    void on_itemList_itemSelectionChanged();
    void nameChanged (Container * c);
    void Comprobar();
    void on_actionLimitar_vista_previa_triggered(bool checked);
    void on_actionMostrar_ocultar_lista_de_campos_triggered();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

public slots:
    void on_actionBorrar_triggered();

private:
    Ui::ReportVisual *ui;
    QGraphicsScene scene;
    Paper paper;
    ReportView view;
    QAction* insertor;
    ReportRenderer* render;
    SectionEditorDlg *dlg;
    Container *contenedor;
    QMap<QListWidgetItem* , Container*> _itemList;
    int Posicion;
    QString Titulo;
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

};

#endif // REPORTVISUAL_H
