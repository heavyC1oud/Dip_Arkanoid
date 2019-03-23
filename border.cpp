#include "border.h"


Border::Border(QObject *parent):
    QObject(parent), QGraphicsItem()
{

}

void Border::setBorder(int posX, int posY, qreal rotation)
{
    this->setX(posX);
    this->setY(posY);
    this->setRotation(rotation);
}

QRectF Border::boundingRect() const
{
    return QRectF(0, 0, BORDER_WIDTH, BORDER_HEIGHT);
}

void Border::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen borderPen;
    borderPen.setWidth(BORDER_THICKNESS);
    borderPen.setColor(QColor(Qt::white));

    painter->setPen(borderPen);

    painter->drawRect(0, 0, BORDER_WIDTH, BORDER_HEIGHT);


}
