#ifndef CONSTS_H
#define CONSTS_H

static const int BORDER_BLOCK_SIZE = 7;
static const int BETWEEN_BLOCK_SIZE = 9;
static const int BLOCK_COLUMN = 9;
static const int BLOCK_ROW = 11;

static const int BLOCK_BORDER_WIDTH = 2;
static const int BLOCK_WIDTH = 72;
static const int BLOCK_HEIGHT = 22;

static const int PLATFORM_BORDER_WIDTH = 2;
static const int PLATFORM_WIDTH = 180;
static const int PLATFORM_HEIGHT = 17;
static const int PLATFORM_START_X = 270;
static const int PLATFORM_START_Y = 700;
static const int PLATFORM_MOVE_STEP = 11;
static const int PLATFORM_OUTER_BORDER_LEFT = -272;
static const int PLATFORM_OUTER_BORDER_RIGHT = 272;
static const int MOVE_PLATFORM_TIMER_MS = 19;

static const int BALL_WIDTH = 16;
static const int BALL_HEIGHT = 16;
static const int BALL_START_X = 354;
static const int BALL_START_Y = 681;
static const int BALL_MOVE_STEP = 1;
static const int MOVE_BALL_TIMER_MS = 3;

static const int BORDER_WIDTH = 720;
static const int BORDER_HEIGHT = 1;
static const int BORDER_TOP_X = 0;
static const int BORDER_TOP_Y = 0;
static const int BORDER_RIGHT_X = BORDER_WIDTH;
static const int BORDER_RIGHT_Y = 0;
static const int BORDER_BOT_X = 0;
static const int BORDER_BOT_Y = BORDER_WIDTH;
static const int BORDER_LEFT_X = 0;
static const int BORDER_LEFT_Y = 0;

static const int RUS_MOVE_LEFT_BUT = 1060;
static const int RUS_MOVE_RIGHT_BUT = 1042;



static const int BORDER_THICKNESS = 2;


typedef enum {
    PLATFORM_MOVE_LEFT,
    PLATFORM_MOVE_RIGHT,
} Move_Platform_Typedef;


typedef enum {
    BALL_MOVE_TOP_RIGHT,
    BALL_MOVE_BOT_RIGHT,
    BALL_MOVE_BOT_LEFT,
    BALL_MOVE_TOP_LEFT,
} Ball_Move_Direction_Typedef;

typedef enum {
    PLATFORM_MOVE_ENABLE,
    PLATFORM_MOVE_DISABLE,
} PlatformMoveEnable_Typedef;




#endif // CONSTS_H
