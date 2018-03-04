#ifndef WIDGET_H
#define WIDGET_H

#include <QGraphicsScene>
#include <QWidget>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    QTimer *tmr;

    int Ay, Ax, Fx, Fy, dX, dY;
    float t;
    float dt;

private slots:
    void updatePict();
};

#endif // WIDGET_H
