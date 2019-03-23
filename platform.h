#ifndef PLATFORM_H
#define PLATFORM_H

#include "consts.h"
#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>

class Platform : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Platform(QObject *parent = nullptr);
    void placePlatform(void);
    void movePlatform(Move_Platform_Typedef direction);
    void setEnableFlag(PlatformMoveEnable_Typedef flag);
    PlatformMoveEnable_Typedef getEnableFlag(void);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int platformWidth;
    int platformHeight;
    PlatformMoveEnable_Typedef enableFlag;

};

#endif // PLATFORM_H
