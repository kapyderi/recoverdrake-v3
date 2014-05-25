#ifndef PAPER_H
#define PAPER_H

#include <QFileDialog>
#include <QApplication>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QPrinter>
#include <QDomNode>
#include "Report/detailsection.h"
#include "Report/pageheadersection.h"
#include <QKeyEvent>

class Paper :public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    explicit Paper(QGraphicsItem *parent = 0);
    Q_PROPERTY(_Orientacion Orientacion READ Orientacion WRITE setOrientacion NOTIFY orientacionChanged)
    Q_PROPERTY(double margenSuperior READ margenSuperior WRITE setmargenSuperior NOTIFY margenSuperiorChanged)
    Q_PROPERTY(double margenInferior READ margenInferior WRITE setmargenInferior NOTIFY margenInferiroChanged)
    Q_PROPERTY(double margenIzquierdo READ margenIzquierdo WRITE setmargenIzquierdo NOTIFY margenIzquierdoChanged)
    Q_PROPERTY(double margenDerecho READ margenDerecho WRITE setmargenDerecho NOTIFY margenDerechoChanged)
    Q_ENUMS (_Orientacion)
    enum _Orientacion { Retrato , Apaisado };
    Q_ENUMS (_Sizes)
    enum _Sizes { A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,
                  B0,B1,B2,B3,B4,B5,B6,B7,B8,B9,B10,
                  C5E,Comm10E,DLE,Executive,Folio,
                  Ledger,Legal,Letter,Tabloid,
                  Custom};
    Q_ENUMS (itemType)
    enum itemType { RoundRectIt, Label, Linea, CodeBarIt, Imagen, Campo, CampoRelacional, Parametro, Acumulador};
    _Orientacion Orientacion() const;
    QRectF margin();
    QRectF paper();
    _Sizes StandartSize();
    double margenSuperior() const;
    double margenInferior() const;
    double margenIzquierdo() const;
    double margenDerecho() const;
    int SFondo() const;
    void setSize(_Sizes siz, double w=0, double h=0, _Orientacion o=Retrato);
    bool addSection(QString nombre ,Section::SectionType sectionType);
    void removeSection(QString nombre);
    void prepareItemInsert(itemType sectionType);
    void stopInsertingItems();
    bool parseXML(QString xml, QString &error);
    int save(QString file );
    QDomDocument preview();
    QList<Section *> getSeccionPool() const;
    void removeItems(QList<QGraphicsItem *> items);
    void insertSection(Section* sec);
    void subirSeccion(QString name);
    void bajarSeccion(QString name);
    void borrarSeccion(QString name);
    void updatePaper();
    static qreal cmToPx(double cm);
    static qreal pxTocm(int px);
    void Seccion();
    void Fondo(QBrush fondo);

signals:    
    void orientacionChanged(_Orientacion arg);
    void margenSuperiorChanged(double arg);
    void margenInferiroChanged(double arg);
    void margenIzquierdoChanged(double arg);
    void margenDerechoChanged(double arg);
    void itemInserted();

public slots:
    void setOrientacion(_Orientacion arg);
    void setMargen(double arg);
    void setmargenSuperior(double arg);
    void setmargenInferior(double arg);
    void setmargenIzquierdo(double arg);
    void setmargenDerecho(double arg);
    void reCalculateSeccion(Section * = 0);
    void newDoc();

private slots:
    void itemMoved(Container *);

private:
    _Orientacion m_orientacion;    
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);    
    void setSize(double w, double h);
    _Sizes mySize;
    double m_margenSuperior;
    itemType _insertingType;
    bool _inserting;
    QPointF _insertingPoint;
    QList<Section *> seccionPool;
    void _insertSection(Section* sec);
    QList<Container*> itemPool;
    void insertRoundRect(Section *);
    void insertLabel(Section *sec);
    void insertLinea(Section *);
    void insertImagen(Section *);
    void insertCampo(Section *sec);
    void insertCodeBar(Section *);
    void insertCampoRelacional(Section *sec);
    void insertParametro(Section *sec);
    void insertAcumulador(Section *sec);
    double m_margenInferiro;
    double m_margenIzquierdo;
    double m_margenDerecho;
    QBrush CFondo;

};

#endif // PAPER_H
