#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <cmath>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    tmr = new QTimer();

    connect(tmr, SIGNAL(timeout()), this, SLOT(updatePict()));

    Ax = 200;
    Ay = 200;
    dX = 150;
    dY = 150;
    Fx = 1;
    Fy = 2;
    t = 0;
    dt = 0.01;

    tmr->setInterval(dt * 1000);

    tmr->start();

    ui->graphicsView->setScene(scene);

    /*
    scene->addLine(0,0, 100,200);
    scene->addEllipse(50,50, 100,50);
    scene->addEllipse(500,50, 100,50);
    */

}
void
Widget::updatePict(){
    int x, y;
    t = t + dt;
    x = dX + Ax*cos(2 * M_PI * Fx * t);
    y = dY + Ay*sin(2 * M_PI * Fy * t) ;

    scene->clear();
    scene->addEllipse(x, y, 20, 20);

}

Widget::~Widget()
{
    delete ui;
}
