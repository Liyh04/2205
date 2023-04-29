
#ifndef TIMER_H
#define TIMER_H
#include "widget.h"
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
#include<QWidget>

class QWidget;
class Widget;
class timer:public Widget
{
public:
    timer();


public slots:
    void updatedisplay();//更新计时器显示
};

#endif // TIMER_H
