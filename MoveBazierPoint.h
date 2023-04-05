#ifndef MOVEBAZIERPOINT_H
#define MOVEBAZIERPOINT_H


#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <bazier.h>

class MoveBazierPoint : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    MoveBazierPoint(double x, double y, int number,QObject *parent = 0);
    ~MoveBazierPoint();

signals:
    void pointMoving(int pointNumber, qreal x, qreal y);
private:
    int numberPoint;
    qreal Px;
    qreal Py;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};
#endif // MOVEBAZIERPOINT_H
