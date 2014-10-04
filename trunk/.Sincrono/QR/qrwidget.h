#ifndef QRWIDGET_H
#define QRWIDGET_H

#include <QWidget>

class QRWidget : public QWidget
{
    Q_OBJECT

private:
    QString data;

public:
    explicit QRWidget(QWidget *parent = 0);
    void setQRData(QString dat);
    void paint(QPainter &painter);
    QString Comprobar();

protected:
    void paintEvent(QPaintEvent *);

};

#endif // QRWIDGET_H
