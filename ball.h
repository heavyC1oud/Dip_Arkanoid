#ifndef BALL_H
#define BALL_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtWidgets>

#include "consts.h"

class Ball : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Ball(QObject *parent = nullptr);
    void placeBall(void);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BALL_H
