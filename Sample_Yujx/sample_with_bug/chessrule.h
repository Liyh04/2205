#ifndef CHESSRULE_H
#define CHESSRULE_H
#include <chess.h>
#include <QPoint>
#include <widget.h>
class ChessRule:public Widget//试一试继承
{
public:
    ChessRule();

    void calcuate(QPoint& pt,bool color,int num);//计算气，每下一次子前计算周围的子

    //bool isValid(QPoint& pt);//能不能下棋，落子前的判断


    QPoint po[5];//={(-1,0),(0,0)};

    int SighMap[9][9];//记录一下每个点的气
    int SighMax[5];    //4
//    int leftSighMax; //0
//    int rightSighMax;//2
//    int upSighMax;   //1
//    int downSighMax; //3

    int SearchMap[9][9];
    //int SearchMapW[9][9];//记录一下搜过没有，0代表没有，1代表有，每下一次子初始化一下
};

#endif // CHESSRULE_H
