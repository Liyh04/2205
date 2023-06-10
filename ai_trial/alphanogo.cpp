#include "alphanogo.h"
#include"available.h"
#include <algorithm>
#include <iterator>
#include "qdebug.h"
#include"rules.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
int flagg=0;
int flagg_2=0;
AlphaNoGO::AlphaNoGO()
{

}
Point AlphaNoGO::search(int ExistChess[13][13],bool isblackturn){//黑1 白2 空0
    int NewChessBoardOfAI[13][13];
    int size;
    QVector<Point> bests;//用来存放最佳落子位置的容器
    Point *p_start=new Point(-1,-1);
    if(ExistChess[4][4]==0){//如果天元无子，则下天元
        p_start->x=4;
        p_start->y=4;
        return *p_start;
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            NewChessBoardOfAI[i][j]=ExistChess[i][j];
        }
    }
    available av;
    Point *p=new Point(0,0);
    int max_score_black=-999;
    int max_score_white=-999;

//先找最理想的点
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(ExistChess[i][j])continue;
            Rules r;
            if(isblackturn){//如果该黑棋下
                int new_score;
                NewChessBoardOfAI[i][j]=1;//下子了
                if(!r.illegal_operation_judging( NewChessBoardOfAI,9,i,j)){NewChessBoardOfAI[i][j]=0;continue;}
                new_score=av.ava_number(NewChessBoardOfAI,9,1)-av.ava_number(NewChessBoardOfAI,9,0);//估值函数的值等于己方可下点位数-对方可下点位数
                qDebug()<<new_score<<' '<<i<<' '<<j<<' ';
                if(max_score_black<new_score){//如果该点位的函数值大于之前的最大值，则将vector清空，加入这个点位
                    p->x=i;
                    p->y=j;
                    max_score_black=new_score;
                    bests.clear();
                    bests.push_back(*p);
                }
                else if(max_score_black==new_score)//如果该点位的函数值等于之前的最大值，则直接将这个点位加入到vector中
                {
                    p->x=i;
                    p->y=j;
                    bests.push_back(*p);
                }
                NewChessBoardOfAI[i][j]=0;
            }
            else{//白棋同理
                int new_score;
                NewChessBoardOfAI[i][j]=2;
                if(!r.illegal_operation_judging( NewChessBoardOfAI,9,i,j)){NewChessBoardOfAI[i][j]=0;continue;}
                new_score=-av.ava_number(NewChessBoardOfAI,9,1)+av.ava_number(NewChessBoardOfAI,9,0);
                if(max_score_white<new_score){
                    p->x=i;
                    p->y=j;
                    max_score_white=new_score;
                    bests.clear();
                    bests.push_back(*p);
                }
                else if(max_score_white==new_score)
                {
                    p->x=i;
                    p->y=j;
                    bests.push_back(*p);
                }
                NewChessBoardOfAI[i][j]=0;
            }
        }
    }
    if(bests.isEmpty()){
        return *p_start;//如果无子可下，返回一个异常点位
    }
    {
        size=bests.size();
        int num=std::rand()%size;
        return bests[num];//在最佳落子点中随机选择一个作为返回值
    } 
}





