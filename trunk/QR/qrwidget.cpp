#include "qrwidget.h"
#include <QPainter>
#include <QDebug>
#include <qrencode.h>

QRWidget::QRWidget(QWidget *parent) :
    QWidget(parent),
    data("RecoverDrake")
{
}

QString QRWidget::Comprobar()
{
    return data;
}

void QRWidget::setQRData(QString dat)
{
    this->data=dat;
    update();
}

void QRWidget::paintEvent(QPaintEvent *pe)
{
    Q_UNUSED(pe);
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    paint(painter);
    painter.end();
}

void QRWidget::paint(QPainter &painter)
{    
    QRcode *qr = QRcode_encodeString(data.toStdString().c_str(), 1, QR_ECLEVEL_L, QR_MODE_8, 0);
    if (0!=qr)
    {
        QColor fg("black");
        QColor bg("white");
        painter.setBrush(bg);
        painter.setPen(Qt::NoPen);
        //painter.drawRect(0,0,width(),height());
        painter.drawRect(0,0,height(),height());
        painter.setBrush(fg);
        const int s=qr->width>0?qr->width:1;
        const double w=width();
        const double h=height();
        const double aspect=w/h;
        const double scale=((aspect>1.0)?h:w)/s;
        for(int y=0;y<s;y++)
        {
            const int yy=y*s;
            for(int x=0;x<s;x++)
            {
                const int xx=yy+x;
                const unsigned char b=qr->data[xx];
                if(b &0x01)
                {
                    const double rx1=x*scale, ry1=y*scale;
                    QRectF r(rx1, ry1, scale, scale);
                    painter.drawRects(&r,1);
                }
            }
        }
        QRcode_free(qr);
        this->setMaximumWidth(740);
        this->setMaximumHeight(740);
    }
    else
    {
        QColor error("red");

        painter.setBrush(error);
        painter.drawRect(0,0,width(),height());
    }
    qr=0;
}
