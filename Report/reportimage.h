#ifndef REPORTIMAGE_H
#define REPORTIMAGE_H

#include "container.h"
#include <QFile>

class ReportImage : public Container
{
    Q_OBJECT
    Q_PROPERTY(QString ruta READ ruta WRITE setruta NOTIFY rutaChanged)
    Q_PROPERTY(bool fromDB READ fromDB WRITE setfromDB NOTIFY fromDBChanged)
    Q_PROPERTY(bool dinamica READ dinamica WRITE setdinamica NOTIFY dinamicaChanged)

public:
    explicit ReportImage(QString name, QGraphicsItem *parent = 0);
    QDomElement xml(QDomDocument doc, QPointF relPos,QList<Section*> sectionPool);
    void parseXml(QDomElement element, QPointF origin);
    void editMe();
    int type() const
    {
        return Type;
    }
    QString query();
    QString ruta() const;
    bool fromDB() const;
    bool dinamica() const;

signals:    
    void rutaChanged(QString arg);
    void fromDBChanged(bool arg);
    void dinamicaChanged(bool arg);

public slots:
    void setruta(QString arg);
    void setfromDB(bool arg);
    void setdinamica(bool arg);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QString m_ruta;
    bool m_fromDB;
    QImage m_image;
    bool m_dinamica;

};

#endif // REPORTIMAGE_H
