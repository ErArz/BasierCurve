#include "bazier.h"

Bazier::Bazier(QVector<Point> &p, QGraphicsScene *grScene, double step, QObject *parent): QObject(parent), bazierPoint(p), scene(grScene){
    creatBazierPoint(step);
//    MoveBazierPoint a;

}

QVector<Point> Bazier::getBazierCurve(){
    return bazierCurve;
}

void Bazier::creatBazierPoint(double step){
    int n = bazierPoint.size() - 1; // binomial degree
    binomialCoeff.resize(n + 1);
    binomialCoeff[0] = 1;
    binomialCoeff[n] = 1;
    int a = 1, b = n;
    int temp = n;
    for(int i = 1; i < n; ++i){
        binomialCoeff[i] = temp;
        temp = (temp * --b) / ++a;
    }

//    Point p(2, 3);
//    Point sd = 2 + p;
//    for(int i : binomialCoeff)
//        qDebug() << i;
   for(double t = 0; t <= 1; t += step){
        double x = 0, y = 0;

        for(int i = 0; i <= n; ++i){
            double tmp = binomialCoeff[i] * qPow(1 - t, n - i) * qPow(t, i);
            x += bazierPoint[i].getX() * tmp;
            y += bazierPoint[i].getY() * tmp;
        }
        bazierCurve.push_back(Point(x, y));
    }

//    qDebug() << "-------------";
//   for(auto b: bazierCurve)
//    qDebug()<< b.getX() << " " << b.getY();

}


void Bazier::drawBazierCurve(){


    lineGroup = new QGraphicsItemGroup;

    curveGroup = new  QGraphicsItemGroup;
//    pointGroup = new QGraphicsItemGroup;

    scene->addItem(lineGroup);
    scene->addItem(curveGroup);
//    scene->addItem(pointGroup);



    QPainterPath path;
    path.moveTo(bazierCurve[0].getX(), bazierCurve[0].getY());
    for(int i = 1; i < bazierCurve.size(); ++i){
        path.lineTo(bazierCurve[i].getX(), bazierCurve[i].getY());
    }

    curveGroup->addToGroup(scene->addPath(path, QPen(QBrush(QColor(Qt::blue)), 3.2)));

    for(int i = 1; i < bazierPoint.size(); ++i){
        lineGroup->addToGroup(scene->addLine(bazierPoint[i - 1].getX(), bazierPoint[i - 1].getY(), bazierPoint[i].getX(), bazierPoint[i].getY(), QPen(QBrush(QColor(161, 161, 161,180)),1.1)));
    }

    for(int i = 0; i < bazierPoint.size(); ++i){
        MoveBazierPoint *mbp = new MoveBazierPoint(bazierPoint[i].getX(), bazierPoint[i].getY(), i);
//        mbp->setPos(p.getX(),p.getY());
        QObject::connect(mbp, SIGNAL(pointMoving(int, qreal, qreal)), this, SLOT(reDraw(int, qreal, qreal)));
        pointGroup.push_back(mbp);
        scene->addItem(mbp);

    }
}

void Bazier::reDraw(int numberPoint, qreal x, qreal y){
//    qDebug() << "redraw " << numberPoint << x << y;
    delete lineGroup;
    delete curveGroup;

    lineGroup = new QGraphicsItemGroup;
    curveGroup = new  QGraphicsItemGroup;


    scene->addItem(lineGroup);
    scene->addItem(curveGroup);

    bazierPoint[numberPoint].setX(x);
    bazierPoint[numberPoint].setY(y);

    bazierCurve = {};
    int n = bazierPoint.size() - 1;
    for(double t = 0; t <= 1; t += 0.001){
         double x = 0, y = 0;

         for(int i = 0; i <= n; ++i){
             double tmp = binomialCoeff[i] * qPow(1 - t, n - i) * qPow(t, i);
             x += bazierPoint[i].getX() * tmp;
             y += bazierPoint[i].getY() * tmp;
         }
         bazierCurve.push_back(Point(x, y));
     }

    QPainterPath path;
    path.moveTo(bazierCurve[0].getX(), bazierCurve[0].getY());
    for(int i = 1; i < bazierCurve.size(); ++i){
        path.lineTo(bazierCurve[i].getX(), bazierCurve[i].getY());
    }

    curveGroup->addToGroup(scene->addPath(path, QPen(QBrush(QColor(Qt::blue)), 3.2)));

    for(int i = 1; i < bazierPoint.size(); ++i){
        lineGroup->addToGroup(scene->addLine(bazierPoint[i - 1].getX(), bazierPoint[i - 1].getY(), bazierPoint[i].getX(), bazierPoint[i].getY(), QPen(QBrush(QColor(161, 161, 161,180)),1.1)));
    }
//    pointGroup[numberPoint]->setPos(x,y);
}

Bazier::~Bazier(){
    for(auto *a: pointGroup){
        delete a;
    }
    delete lineGroup;
    delete curveGroup;
//    delete pointGroup;
};
