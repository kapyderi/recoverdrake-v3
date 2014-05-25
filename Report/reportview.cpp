#include "reportview.h"

ReportView::ReportView(QWidget *parent) :
    QGraphicsView(parent)
{
}

void ReportView::wheelEvent(QWheelEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        double scaleFactor = 1.15;
        if(event->delta() > 0) {
            scale(scaleFactor, scaleFactor);
        } else {
            scale(1.0 / scaleFactor, 1.0 / scaleFactor);
        }
    }
    else
        QGraphicsView::wheelEvent(event);
}
