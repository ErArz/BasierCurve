#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "point.h"
#include <QtMath>
#include <QPainterPath>
#include <QPoint>
#include <QLineEdit>
#include <QIntValidator>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItemGroup>
#include <QGridLayout>
#include <QLabel>

#include "point.h"
#include <QVector>
#include "bazier.h"

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

#include <QMouseEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    virtual void paintEvent(QPaintEvent *event);

    Bazier *baz;
    QVector<QLineEdit*> lineEditList;

    QGridLayout *pointGridLayout;

    QVector<QLabel*> labelList;

    QGraphicsScene *scene;
    QGraphicsItemGroup *itemGroup_1;
    QGraphicsItemGroup *itemGroup_2;

    QGraphicsItemGroup *pointGroup;
    QGraphicsItemGroup *lineGroup;
    QGraphicsItemGroup *curveGroup;


    QGraphicsItem *itemElement_1;
    QGraphicsItem *itemElement_2;
    QGraphicsItem *itemElement_3;

    QPen *bluePen;
    QPen *redPen;
    QPen *blackPen;


};
#endif // MAINWINDOW_H
