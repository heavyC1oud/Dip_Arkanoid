#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QPushButton>
#include <QLayout>
#include <QRect>
#include <QRectF>
#include <QSize>
#include <QVector>
#include <QTimer>
#include <QLabel>
#include <QPicture>
#include <QSound>

#include "consts.h"
#include "block.h"
#include "platform.h"
#include "ball.h"
#include "border.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void moveBall(void);
    void movePlatform(void);

private slots:


private:
    Ui::MainWindow *ui;

    QGraphicsScene *arkScene;
    QGraphicsView *arkView;
    Border *arkBorderTop;
    Border *arkBorderRight;
    Border *arkBorderBot;
    Border *arkBorderLeft;
    QLabel *arkEndLabel;
    QPicture *arkEndPicture;
    QSound *arkStartSound;


    Ball *arkBall;
    Platform *arkPlatform;

    Block *arkBlock;
    QVector<Block*> arkBlocks;

    QTimer *arkMoveBall;
    QTimer *arkMovePlatform;
    Ball_Move_Direction_Typedef ballDir;

    bool movePlatformLeft;
    bool movePlatformRight;


    void setBlocks(void);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void moveBallStep(Ball_Move_Direction_Typedef direction);
    void gameover(void);

};

#endif // MAINWINDOW_H
