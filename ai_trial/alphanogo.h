#ifndef ALPHANOGO_H
#define ALPHANOGO_H
#include <QVector>


struct Point {
    int x;
    int y;
    Point(int x_, int y_) : x(x_), y(y_) {}
};

class AlphaNoGO
{
public:
    AlphaNoGO();
    Point search(int ExistChess[13][13],bool isblackturn);//AI返回一个落子点
};

#endif // ALPHANOGO_H
