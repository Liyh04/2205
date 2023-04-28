
#ifndef TIMER_H
#define TIMER_H
#include "widget.h"
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>



class Widget;
class timer:public Widget
{
public:
    timer();

    void init();//游戏开局时初始化
public slots:
    void updatedisplay();//更新计时器显示
};

#endif // TIMER_H
