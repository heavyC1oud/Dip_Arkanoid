#include "ball.h"

Ball::Ball(QObject *parent):
    QObject(parent), QGraphicsItem()
{
    placeBall();
}

void Ball::placeBall()
{
    this->setPos(BALL_START_X, BALL_START_Y);
}


QRectF Ball::boundingRect() const
{
    return QRectF(0, 0, BALL_WIDTH, BALL_HEIGHT);
}


void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    painter->drawEllipse(0, 0, BALL_WIDTH, BALL_HEIGHT);
}
