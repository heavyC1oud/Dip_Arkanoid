#ifndef BORDER_H
#define BORDER_H

#include "consts.h"
#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>

class Border: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Border(QObject *parent = nullptr);
    void setBorder(int posX, int posY, qreal rotation);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // BORDER_H
