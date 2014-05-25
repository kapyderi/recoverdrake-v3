#include "container.h"
#include <QKeyEvent>
#include "paper.h"
#include "reportvisual.h"

QMap<Container*,QString> Container::_items;
QMap<Container *, QString> Container::_acums;
bool Container::_showBorder = true;

Container::Container(QString name, QGraphicsItem *parent) :
    QGraphicsRectItem(parent)
{
    _items.insert(this,name);
    this->_onResize = false;
    this->m_active = true;
    this->setAcceptHoverEvents(true);
    this->setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setFlag(QGraphicsItem::ItemIsMovable);
}

Container::~Container()
{
    if(_items.contains(this))
        _items.remove(this);
    if(_acums.contains(this))
        _acums.remove(this);
}

void Container::setSize(int w, int h)
{
    this->setRect(0,0,w,h);
}

void Container::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    if(this->isSelected())
    {
        if(_onResize)
            painter->fillRect(this->rect(),QColor(199,196,196,150));
        QRectF r = this->rect();
        qreal a = 16;
        qreal b = 5;
        painter->drawRect(r.width()/2 -8,1,a,b);
        painter->drawRect(1,r.bottom()/2-8,b,a);
        painter->drawRect(r.right()-6,r.bottom()/2-8 ,b,a);
        painter->drawRect(r.width()/2 -8,r.bottom()-6,a,b);
    }
    if(Container::getShowBorder() || this->isSelected())
        QGraphicsRectItem::paint(painter,option,widget);
    painter->restore();
}

void Container::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    if(this->isSelected())
    {
        QRectF r = this->rect();
        QRectF corner1(r.width()/2 -8,0,16,5);
        QRectF corner2(0,r.bottom()/2-8,5,16);
        QRectF corner3(r.right()-5,r.bottom()/2-8,5,16);
        QRectF corner4(r.width()/2 -8,r.bottom()-5,16,5);
        if(corner1.contains(event->pos()))
        {
            _onResize = true;
            _resizeType = 0;
        }
        else if(corner2.contains(event->pos()))
        {
            _onResize = true;
            _resizeType = 1;
        }
        else if(corner3.contains(event->pos()))
        {
            _onResize = true;
            _resizeType = 2;
        }
        else if(corner4.contains(event->pos()))
        {
            _onResize = true;
            _resizeType = 3;
        }
    }
}

void Container::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    _onResize = false;
    QGraphicsItem::mouseReleaseEvent(event);
}

void Container::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    prepareGeometryChange();
    if(_onResize)
    {        
        switch (_resizeType) {
        case 0:
            if(this->rect().bottom()-event->pos().ry() > 15 && mapToScene(event->pos()).ry()>0)
            {
                this->setRect(0,
                              0,
                              this->rect().width(),
                              this->rect().bottom()-event->pos().ry()
                              );
                this->setPos(pos().x(),mapToScene(event->pos()).ry());
            }
            break;
        case 1:
            if(this->rect().right() - event->pos().rx()> 15 && mapToScene(event->pos()).rx()>margins.left())
            {
                this->setRect(0,
                              0,
                              this->rect().right() - event->pos().rx(),
                              this->rect().height()
                              );
                this->setPos(mapToScene(event->pos()).rx(),pos().y());
            }
            break;
        case 2:
            if(this->rect().left() + event->pos().rx()> 15 && mapToScene(event->pos()).rx()<margins.right())
            {
                this->setRect(0,
                              0,
                              event->pos().rx() - this->rect().left(),
                              this->rect().height()
                              );
            }
            break;
        default:
            if(this->rect().top() + event->pos().ry()> 15 && mapToScene(event->pos()).ry()<margins.bottom())
            {
                this->setRect(0,
                              0,
                              this->rect().width(),
                              event->pos().ry() - this->rect().top()
                              );
            }
            break;
        }
    }
    else
        QGraphicsItem::mouseMoveEvent(event);
}

void Container::apendXML(QDomElement &element, QDomDocument doc , QPointF relPos)
{
    Q_UNUSED(doc);
    element.setAttribute("x",QString::number(this->pos().x() - relPos.x(), 'f', 4));
    element.setAttribute("y",QString::number(this->pos().y() - relPos.y(), 'f', 4));
    element.setAttribute("w",QString::number(this->rect().width() , 'f', 4));
    element.setAttribute("h",QString::number(this->rect().height(), 'f', 4));
    element.setAttribute("name",_items.value(this));
}

QString Container::ColorString(QColor c)
{
    return QString("%1,%2,%3,%4").arg(c.red()).arg(c.green()).arg(c.blue()).arg(c.alpha());
}

QColor Container::ColorFromString(QString s)
{
    QStringList l= s.split(",");
    QColor c;
    c.setRed(l.at(0).toDouble());
    c.setGreen(l.at(1).toDouble());
    c.setBlue(l.at(2).toDouble());
    c.setAlpha(l.at(3).toDouble());
    return c;
}

QVariant Container::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange) {
            QPointF newPos = value.toPointF();
            QPointF rigthBottom = QPointF(newPos.x()+this->rect().width(),newPos.y()+this->rect().height());
            if (!margins.contains(newPos) || !margins.contains(rigthBottom)) {
                newPos.setX(qMin(margins.right(), qMax(newPos.x(), margins.left()+1)));
                newPos.setY(qMin(margins.bottom(), qMax(newPos.y(), margins.top()+1)));
                if(!margins.contains(rigthBottom))
                {
                    newPos.setX(qMax(margins.left(), qMin(newPos.x(),margins.right()-this->rect().width())));
                    newPos.setY(qMax(margins.top(), qMin(newPos.y(),margins.bottom()-this->rect().height())));                    
                }                
                return newPos;
            }
            emit moved(this);
     }
    else if(change == ItemSelectedChange)
    {
        bool b = value.toBool();
        if(b)
            this->grabKeyboard();
        else
            this->ungrabKeyboard();
    }
    return QGraphicsItem::itemChange(change, value);
}

QRectF Container::boundingRect() const
{
    return this->rect();
}

void Container::registerAsAcum()
{
    _acums.insert(this,this->name());
}

bool Container::getShowBorder()
{
    return _showBorder;
}

void Container::setShowBorder(bool value)
{
    _showBorder = value;
}


QMap<Container *, QString> Container::items()
{
    return _items;
}

QMap<Container *, QString> Container::acumlators()
{
    return _acums;
}

void Container::removeItem(Container * cont )
{
    if(_items.contains(cont))
        _items.remove(cont);
    if(_acums.contains(cont))
        _acums.remove(cont);
}

QStringList Container::acums()
{
    return _acums.values();
}

bool Container::isActive() const
{   
    return m_active;
}

void Container::setActive(bool active)
{
    m_active = active;
    this->setAcceptHoverEvents(m_active);
    this->setFlag(QGraphicsItem::ItemSendsGeometryChanges,m_active);
    this->setFlag(QGraphicsItem::ItemIsSelectable,m_active);
    this->setFlag(QGraphicsItem::ItemIsMovable,m_active);
}

void Container::setName(QString n)
{
    if(n != name())
    {
        _items[this] = n;
        if(_acums.contains(this))
            _acums[this] = n;
        emit nameChanged(this);
    }
}

QString Container::name()
{
    return _items.value(this);
}

QRectF Container::getMargins() const
{
    return margins;
}

void Container::setMargins(const QRectF &value)
{
    margins = value;
}

void Container::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    editMe();
}

void Container::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up :
        if(event->modifiers() == Qt::ControlModifier)
            this->moveBy(0,-10);
        else
            this->moveBy(0,-1);
        break;
    case Qt::Key_Down :
        if(event->modifiers() == Qt::ControlModifier)
            this->moveBy(0,10);
        else
            this->moveBy(0,1);
        break;
    case Qt::Key_Left :
        if(event->modifiers() == Qt::ControlModifier)
            this->moveBy(-10,0);
        else
            this->moveBy(-1,0);
        break;
    case Qt::Key_Right :
        if(event->modifiers() == Qt::ControlModifier)
            this->moveBy(10,0);
        else
            this->moveBy(1,0);
        break;
    default:
        break;
    }
}
