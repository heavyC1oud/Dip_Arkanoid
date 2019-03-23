#include "platform.h"

Platform::Platform(QObject *parent):
    QObject(parent), QGraphicsItem()
{
    platformWidth = PLATFORM_WIDTH;
    platformHeight = PLATFORM_HEIGHT;

    enableFlag = PLATFORM_MOVE_ENABLE;
}

void Platform::placePlatform()
{
    this->setPos(PLATFORM_START_X, PLATFORM_START_Y);
}


QRectF Platform::boundingRect() const
{
    return QRectF(PLATFORM_START_X, PLATFORM_START_Y, platformWidth, platformHeight);
}


void Platform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPen platformPen;
    platformPen.setWidth(PLATFORM_BORDER_WIDTH);
    platformPen.setColor(QColor(Qt::darkRed));

    painter->setPen(platformPen);


    painter->setBrush(Qt::darkGray);
    painter->drawRect(PLATFORM_START_X, PLATFORM_START_Y, platformWidth, platformHeight);

}


void Platform::movePlatform(Move_Platform_Typedef direction)
{
    if(enableFlag == PLATFORM_MOVE_DISABLE) {
        return;
    }
    qreal xPos;

    if(direction == PLATFORM_MOVE_LEFT) {
        xPos = this->x();

        if((xPos - PLATFORM_MOVE_STEP)  > PLATFORM_OUTER_BORDER_LEFT) {
            this->setX(xPos - PLATFORM_MOVE_STEP);
        }
    }
    else if(direction == PLATFORM_MOVE_RIGHT) {
        xPos = this->x();

        if((xPos + PLATFORM_MOVE_STEP)  < PLATFORM_OUTER_BORDER_RIGHT) {
            this->setX(xPos + PLATFORM_MOVE_STEP);
        }
    }
}


void Platform::setEnableFlag(PlatformMoveEnable_Typedef flag)
{
    enableFlag = flag;
}

PlatformMoveEnable_Typedef Platform::getEnableFlag()
{
    return enableFlag;
}
