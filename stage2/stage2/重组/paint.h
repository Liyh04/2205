
#ifndef PAINT_H
#define PAINT_H

#include "widget.h"
#include <QPainter>
#include <QBrush>
#include <qcolor.h>
class Chess;
class Widget;
class paint:public Widget
{
public:
    paint();
    void paintEvent(QPaintEvent *);
    void DrawChessboard();  //画棋盘
};

#endif // PAINT_H
