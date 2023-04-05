#include "MoveBazierPoint.h"

MoveBazierPoint::MoveBazierPoint(double x, double y, int number, QObject *parent) :
    QObject(parent), Px(x), Py(y), numberPoint(number)
{

}

MoveBazierPoint::~MoveBazierPoint()
{

}

QRectF MoveBazierPoint::boundingRect() const
{
    return QRectF (Px - 7, Py - 7,14 ,14);
}

void MoveBazierPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(Qt::red));
    painter->setBrush(QBrush(Qt::red));
    painter->drawEllipse(Px - 7, Py - 7, 14, 14);
    this->setZValue(3);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MoveBazierPoint::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//    qDebug() << "move";
    Px = event->pos().x();
    Py = event->pos().y();
    this->setPos(event->scenePos());
//    update();
    emit pointMoving(numberPoint,event->scenePos().x(), event->scenePos().y());
}

void MoveBazierPoint::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
//    qDebug() << "press";
    Q_UNUSED(event);
}

void MoveBazierPoint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
//    qDebug() << "release";

    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
