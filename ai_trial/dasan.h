#ifndef DASAN_H
#define DASAN_H
#include <QObject>
#include <QVector>
#include <QRandomGenerator>
#include <cmath>
struct Point {
    int x;
    int y;
    Point(int x_, int y_) : x(x_), y(y_) {}
};
class DaSan:public QObject
{
public:
    DaSan();

    int calculateManhattanDistance(const Point& p1, const Point& p2); //计算曼哈顿距离
    Q_OBJECT

    public:

        // 打散棋盘
        Point shuffleBoard(int chess[13][13],bool black);

};

#endif // DASAN_H
