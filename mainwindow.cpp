#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arkScene = new QGraphicsScene();
    arkView = new QGraphicsView();
    arkPlatform = new Platform();
    arkBall = new Ball();
    ballDir = BALL_MOVE_TOP_RIGHT;

    arkBorderTop = new Border();
    arkBorderRight = new Border();
    arkBorderBot = new Border();
    arkBorderLeft = new Border();
    arkBorderTop->setBorder(BORDER_TOP_X, BORDER_TOP_Y, 0);
    arkBorderRight->setBorder(BORDER_RIGHT_X, BORDER_RIGHT_Y, 90);
    arkBorderBot->setBorder(BORDER_BOT_X, BORDER_BOT_Y, 0);
    arkBorderLeft->setBorder(BORDER_LEFT_X, BORDER_LEFT_Y, 90);

    //  таймер отвечающий за движение мяча
    arkMoveBall = new QTimer();
    arkMoveBall->setInterval(MOVE_BALL_TIMER_MS);

    //  таймер отвечающий за движение платформы
    arkMovePlatform = new QTimer();
    arkMovePlatform->setInterval(MOVE_PLATFORM_TIMER_MS);

    setBlocks();

    arkScene->addItem(arkPlatform);
    arkScene->addItem(arkBall);
    arkScene->addItem(arkBorderTop);
    arkScene->addItem(arkBorderRight);
    arkScene->addItem(arkBorderBot);
    arkScene->addItem(arkBorderLeft);

    arkView->setScene(arkScene);
    arkScene->setBackgroundBrush(Qt::black);
    arkScene->setSceneRect(0, 0, 720, 720);

    ui->backGroundLay->addWidget(arkView);    

    connect(arkMoveBall, &QTimer::timeout, this, &MainWindow::moveBall);
    arkMoveBall->start();

    connect(arkMovePlatform, &QTimer::timeout, this, &MainWindow::movePlatform);
    arkMovePlatform->start();

    arkStartSound = new QSound(":/wav/wav/Mortal_Kombat.wav");
    arkStartSound->setLoops(QSound::Loop::Infinite);
    arkStartSound->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: setBlocks()
{
    for(int i = 0; i < BLOCK_ROW; i++) {
        for(int j = 0; j < BLOCK_COLUMN; j++) {
            Block *block = new Block();

            block->setPos((((block->getBlockWidth() + BORDER_BLOCK_SIZE) * j) + BETWEEN_BLOCK_SIZE), (((block->getBlockHeight() + BORDER_BLOCK_SIZE) * i) + BETWEEN_BLOCK_SIZE));

            arkBlocks.push_back(block);

            arkScene->addItem(block);
        }
    }
}


//  для быстрой реакции на нажатие клавиш при движении платформы
//  движение осуществляется по интервалу таймера с заданным шагом
//  пока нажата соответстующая кнопка управления
//  после отпускания кнопки движение прекращается
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if((event->key() == Qt::Key_A) || (event->key() == RUS_MOVE_LEFT_BUT)) {
        movePlatformLeft = true;
    }
    else if((event->key() == Qt::Key_D) || (event->key() == RUS_MOVE_RIGHT_BUT)) {
        movePlatformRight = true;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if((event->key() == Qt::Key_A) || (event->key() == RUS_MOVE_LEFT_BUT)) {
        movePlatformLeft = false;
    }
    else if((event->key() == Qt::Key_D) || (event->key() == RUS_MOVE_RIGHT_BUT)) {
        movePlatformRight = false;
    }
}


void MainWindow::movePlatform()
{
    if(movePlatformLeft) {
        arkPlatform->movePlatform(PLATFORM_MOVE_LEFT);
    }
    else if(movePlatformRight) {
        arkPlatform->movePlatform(PLATFORM_MOVE_RIGHT);
    }

}


//  при каждом шаге перемещения шара проверяется столкновение с другими объектами
//  при обнаружении кстолкновения шаг отменяется и осуществляется необходимое действие
//  в зависимости от объекта с которым произошла коллизияо столкновение
void MainWindow::moveBall()
{
    moveBallStep(ballDir);

    QList <QGraphicsItem *> colItems = arkScene->collidingItems(arkBall);

    if(!colItems.isEmpty()) {
        foreach(QGraphicsItem *colItem, colItems) {
            //  столкновение с правой границей
            if(colItem == arkBorderRight) {
                switch (ballDir) {
                case BALL_MOVE_TOP_RIGHT:
                    moveBallStep(BALL_MOVE_BOT_LEFT);
                    ballDir = BALL_MOVE_TOP_LEFT;
                    break;
                case BALL_MOVE_BOT_RIGHT:
                    moveBallStep(BALL_MOVE_TOP_LEFT);
                    ballDir = BALL_MOVE_BOT_LEFT;
                    break;
                default:
                    break;
                }

                QSound::play(":/wav/wav/Wall_collision.wav");
            }
            //  столкновение с нижней границей
            else if(colItem == arkBorderBot) {
                switch (ballDir) {
                case BALL_MOVE_BOT_RIGHT:
                    moveBallStep(BALL_MOVE_TOP_LEFT);
                    ballDir = BALL_MOVE_TOP_RIGHT;
                    break;
                case BALL_MOVE_BOT_LEFT:
                    moveBallStep(BALL_MOVE_TOP_RIGHT);
                    ballDir = BALL_MOVE_TOP_LEFT;
                    break;
                default:
                    break;
                }

                arkPlatform->setEnableFlag(PLATFORM_MOVE_DISABLE);

                this->gameover();
            }
            //  столкновение с левой границей
            else if(colItem == arkBorderLeft) {
                switch (ballDir) {
                case BALL_MOVE_BOT_LEFT:
                    moveBallStep(BALL_MOVE_TOP_RIGHT);
                    ballDir = BALL_MOVE_BOT_RIGHT;
                    break;
                case BALL_MOVE_TOP_LEFT:
                    moveBallStep(BALL_MOVE_BOT_RIGHT);
                    ballDir = BALL_MOVE_TOP_RIGHT;
                    break;
                default:
                    break;
                }

                QSound::play(":/wav/wav/Wall_collision.wav");
            }
            //  столкновение с верхней границей
            else if(colItem == arkBorderTop) {
                switch (ballDir) {
                case BALL_MOVE_TOP_RIGHT:
                    moveBallStep(BALL_MOVE_BOT_LEFT);
                    ballDir = BALL_MOVE_BOT_RIGHT;
                    break;
                case BALL_MOVE_TOP_LEFT:
                    moveBallStep(BALL_MOVE_BOT_RIGHT);
                    ballDir = BALL_MOVE_BOT_LEFT;
                    break;
                default:
                    break;
                }

                QSound::play(":/wav/wav/Wall_collision.wav");
            }
            //  столкновение с платформой
            else if(colItem == arkPlatform) {
                switch (ballDir) {
                case BALL_MOVE_BOT_RIGHT:
                    moveBallStep(BALL_MOVE_TOP_LEFT);
                    ballDir = BALL_MOVE_TOP_RIGHT;
                    break;
                case BALL_MOVE_BOT_LEFT:
                    moveBallStep(BALL_MOVE_TOP_RIGHT);
                    ballDir = BALL_MOVE_TOP_LEFT;
                    break;
                default:
                    break;
                }

                QSound::play(":/wav/wav/Platform_collision.wav");
            }
            //  столкновение с блоком
            else {
                foreach(Block *i, arkBlocks) {
                    if(colItem == i) {
                        switch (ballDir) {
                        case BALL_MOVE_TOP_RIGHT:
                            moveBallStep(BALL_MOVE_BOT_LEFT);
                            ballDir = BALL_MOVE_BOT_RIGHT;
                            break;
                        case BALL_MOVE_TOP_LEFT:
                            moveBallStep(BALL_MOVE_BOT_RIGHT);
                            ballDir = BALL_MOVE_BOT_LEFT;
                            break;
                        default:
                            break;
                        }

                        QSound::play(":/wav/wav/Destroy_Block.wav");

                        arkScene->removeItem(i);
                        arkBlocks.removeOne(i);
                    }
                }
            }
        }
    }
}


void MainWindow::moveBallStep(Ball_Move_Direction_Typedef direction)
{
    switch (direction) {
    case BALL_MOVE_TOP_RIGHT:
        arkBall->setPos((arkBall->x() + BALL_MOVE_STEP), (arkBall->y() - BALL_MOVE_STEP));
        break;
    case BALL_MOVE_BOT_RIGHT:
        arkBall->setPos((arkBall->x() + BALL_MOVE_STEP), (arkBall->y() + BALL_MOVE_STEP));
        break;
    case BALL_MOVE_BOT_LEFT:
        arkBall->setPos((arkBall->x() - BALL_MOVE_STEP), (arkBall->y() + BALL_MOVE_STEP));
        break;
    case BALL_MOVE_TOP_LEFT:
        arkBall->setPos((arkBall->x() - BALL_MOVE_STEP), (arkBall->y() - BALL_MOVE_STEP));
        break;
    default:
        break;
    }
}

void MainWindow::gameover()
{
    arkMoveBall->stop();

    arkStartSound->stop();

    QSound::play(":/wav/wav/haha.wav");

    arkView->close();

    arkEndLabel = new QLabel();
    arkEndLabel->setScaledContents(true);

    QPixmap endPic(":/image/img/gameover.jpg");
    arkEndLabel->setPixmap(endPic);

    ui->backGroundLay->addWidget(arkEndLabel);



}




