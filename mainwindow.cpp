#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QLineEdit *countLine = new QLineEdit(this);
//    countLine->setText("sdfsd");
//    ui->graphicsView->resize(10,10);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
//    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
//    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    pointGridLayout = new QGridLayout();

    for(int i = 0; i < 3; i++)
    {
        QLabel *l0 = new QLabel();
        QLineEdit *l1 = new QLineEdit();
        QLineEdit *l2 = new QLineEdit();

        l0->setText(QString::number(i + 1));
        labelList.push_back(l0);
        l0->setStyleSheet("border: 0px solid black;");
        lineEditList.push_back(l1);
        lineEditList.push_back(l2);
        pointGridLayout->addWidget(l0,i,0);
        pointGridLayout->addWidget(l1,i,1);
        pointGridLayout->addWidget(l2,i,2);
    }
    ui->scrollArea->widget()->setLayout(pointGridLayout);


//    graphicsView->setGeometry(20, 20, width() - 40, height()-40);
//    scene->addEllipse(100,220, 1000,1000, QPen(Qt::black));

//    setCentralWidget(graphicsView);

//    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    QVector<Point> p = {Point(50,300),Point(250,50), Point(450,300)};
    baz = new Bazier(p, scene);
    baz->drawBazierCurve();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
//    static int a = 0;
//    qDebug() << ++a;
//    a += 10;
//    QPainter painter(this);
//    painter.setRenderHint(QPainter:: Antialiasing, true);
//    painter.setPen(QPen(QBrush(QColor(Qt::black)), 1 ));
//    painter.drawLine(150, 0, 150, 300);
//    painter.drawLine(0, 150, 300, 150);
//    painter.setPen(QPen(QBrush(QColor(Qt::red)), 5 ));
//    painter.drawPoint( 200, 200 );
//    for(double t = 0; t <= 1; t+=0.0001){
//         painter.drawPoint(350 * qPow(1 - t, 2) + 2*t*550*(1 - t) + qPow(t, 2)* 700,350 * qPow(1 - t, 2) + 2*t*200*(1 - t) + qPow(t, 2)* 600);
//    }
//    painter.setPen(QPen(Qt::blue,1,Qt::SolidLine, Qt::RoundCap, Qt::SvgMiterJoin));



//    QPainterPath path;
//    path.moveTo(900+a, 350+a);
//    for(double t = 0; t <= 1; t+=0.001){
//       path.lineTo(900.0 * qPow(1 - t, 2) + 2.0*t*450.0*(1 - t) + qPow(t, 2)* 700.0,350.0 * qPow(1 - t, 2) + 2*t*200.0*(1 - t) + qPow(t, 2)* 600.0);
//    }

//    scene->addPath(path, QPen(QBrush(QColor(Qt::red)), 5 ));
//    painter.setPen(QPen(QBrush(QColor(Qt::red)), 5 ));
//    painter.drawPath(path);



}

void MainWindow::on_pushButton_2_clicked()
{

//      scene->destroyItemGroup(lineGroup);
//      scene->destroyItemGroup(pointGroup);

//    delete lineGroup;
//    delete pointGroup;
//    delete curveGroup;

//    lineGroup = new QGraphicsItemGroup;
//    pointGroup = new QGraphicsItemGroup;
//    curveGroup = new  QGraphicsItemGroup;

//    scene->addItem(lineGroup);
//    scene->addItem(curveGroup);
//    scene->addItem(pointGroup);

    QVector<Point> bazierPoint = {};
    for(int i = 1; i < lineEditList.size(); i += 2){
        bazierPoint.push_back(Point(lineEditList[i - 1]->text().toDouble(),lineEditList[i]->text().toDouble()));

    }
    delete baz;
    baz = new Bazier(bazierPoint, scene);
    baz->drawBazierCurve();
}


void MainWindow::on_pushButton_clicked()
{

    int count = ui->lineEdit->text().toInt();
    if(count < 3) return;
    for(auto i: lineEditList)
        delete i;
    for(auto i: labelList)
        delete i;

    lineEditList.clear();
    labelList.clear();

    for(int i = 0; i < count; i++)
    {
        QLabel *l0 = new QLabel();
        QLineEdit *l1 = new QLineEdit();
        QLineEdit *l2 = new QLineEdit();

        l0->setText(QString::number(i + 1));
        l0->setStyleSheet("border: 0px solid black;");
        labelList.push_back(l0);
        lineEditList.push_back(l1);
        lineEditList.push_back(l2);
        pointGridLayout->addWidget(l0,i,0);
        pointGridLayout->addWidget(l1,i,1);
        pointGridLayout->addWidget(l2,i,2);
    }

}


