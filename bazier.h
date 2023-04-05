#ifndef BAZIER_H
#define BAZIER_H

#include "point.h"
#include "MoveBazierPoint.h"
#include "QVector"
#include <QtMath>
#include <QDebug>
#include <QObject>

#include <QList>

#include <QGraphicsScene>

#include <QPainterPath>

class Bazier: public QObject
{
    Q_OBJECT
private:
    QVector<Point> bazierPoint;
    QVector<Point> bazierCurve;
    QVector<int> binomialCoeff;
    QVector<QGraphicsItem*> pointGroup;
    QGraphicsItemGroup *lineGroup;
    QGraphicsItemGroup *curveGroup;
    QGraphicsScene *scene;

    void creatBazierPoint(double step);

public:
    explicit Bazier(QVector<Point> &p, QGraphicsScene *grScene, double step = 0.001, QObject *parent = nullptr);
    ~Bazier();

    QVector<Point> getBazierCurve();
    void drawBazierCurve();

public slots:
    void reDraw(int numberPoint, qreal x, qreal y);

};

#endif // BAZIER_H
