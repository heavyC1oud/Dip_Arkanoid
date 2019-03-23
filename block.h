#ifndef BLOCK_H
#define BLOCK_H

#include "consts.h"
#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>

class  Block : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Block(QObject *parent = nullptr);

    int getBlockWidth(void);
    int getBlockHeight(void);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int blockWidth;
    int blockHeight;
    QBrush blockColor;

};

#endif // BLOCK_H
