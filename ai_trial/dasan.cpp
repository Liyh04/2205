#include "dasan.h"
#include"rules.h"
#include"available.h"
DaSan::DaSan()
{

}
Rules r;
int DaSan::calculateManhattanDistance(const Point& p1, const Point& p2) {
    return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
}

Point DaSan::shuffleBoard(int chess[13][13],bool black) {
    // 存储所有可下点的坐标
    Point *point=new Point(0,0);
    int NewChessBoardOfAI[13][13];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            NewChessBoardOfAI[i][j]=chess[i][j];
        }
    }
    QVector<Point> emptyPoints;
    // 第一步：选出所有可下点
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if(NewChessBoardOfAI[i][j])continue;
            NewChessBoardOfAI[i][j]=black?1:2;
            if (!r.illegal_operation_judging( NewChessBoardOfAI,9,i,j)) {
                emptyPoints.append(Point(i, j));
            }
            NewChessBoardOfAI[i][j]=0;
        }
    }
    // 没有可下点，直接返回空列表
    if (emptyPoints.isEmpty()) {
        return *point;
    }
    // 第二步：计算所有可下点与棋盘已有子的曼哈顿距离的最小值
    int minDistance = 9 * 2; // 初始化为一个较大的值
    for (const auto& emptyPoint : emptyPoints) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if(NewChessBoardOfAI[i][j])continue;
                NewChessBoardOfAI[i][j]=black?1:2;
                if (!r.illegal_operation_judging( NewChessBoardOfAI,9,i,j)) {
                    int distance = calculateManhattanDistance(emptyPoint, Point(i, j));
                    minDistance = std::min(minDistance, distance);
                }
                NewChessBoardOfAI[i][j]=0;
            }
        }
    }
    // 第三步：找出最小距离的最大值，并标记相应的点
    QVector<Point> candidates;
    for (const auto& emptyPoint : emptyPoints){
        int maxDistance = 0;
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j) {
                if(NewChessBoardOfAI[i][j])continue;
                NewChessBoardOfAI[i][j]=black?1:2;
                if (!r.illegal_operation_judging( NewChessBoardOfAI,9,i,j)) {
                    int distance = calculateManhattanDistance(emptyPoint, Point(i, j));
                    if (distance == minDistance) {
                        maxDistance = std::max(maxDistance, distance);
                    }
                }
                NewChessBoardOfAI[i][j]=0;
            }
        }
        if (maxDistance == minDistance){
            candidates.append(emptyPoint);
            *point=emptyPoint;
        }
    }
    return *point;
}
