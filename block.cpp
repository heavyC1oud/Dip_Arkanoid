#include "block.h"

Block::Block(QObject *parent):
    QObject(parent), QGraphicsItem()
{
    blockWidth = BLOCK_WIDTH;
    blockHeight = BLOCK_HEIGHT;
}

int Block::getBlockWidth()
{
    return blockWidth;
}

int Block::getBlockHeight()
{
    return blockHeight;
}

QRectF Block::boundingRect() const
{
    return QRectF(0, 0, blockWidth, blockHeight);
}

void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen blockPen;
    blockPen.setWidth(BLOCK_BORDER_WIDTH);
    blockPen.setColor(QColor(Qt::lightGray));

    painter->setPen(blockPen);


    painter->setBrush(Qt::yellow);
    painter->drawRect(0, 0, blockWidth, blockHeight);


}
