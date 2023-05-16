
#include "rules.h"

Rules::Rules()
{

}
int Rules::if_legal(int ExistChess[9][9],int x,int y)
{
    if(!ExistChess[x][y])return 1;
    if((x>0&&!ExistChess[x-1][y])||(x<8&&!ExistChess[x+1][y])||(y>0&&!ExistChess[x][y-1])||(y<8&&!ExistChess[x][y+1]))return 1;
    int flag=0;
    for(int i=0;i<=3;i++)
    {
        if(i==0)
        {
            if(x==0)continue;
            if(ExistChess[x-1][y]!=ExistChess[x][y])continue;
            if(if_scanned[x-1][y])continue;
            if(ExistChess[x-1][y]==ExistChess[x][y])
            {if_scanned[x][y]=1;flag+=if_legal(ExistChess,x-1,y);}
        }
        if(i==1)
        {
            if(x==8)continue;
            if(ExistChess[x+1][y]!=ExistChess[x][y])continue;
            if(if_scanned[x+1][y])continue;
            if(ExistChess[x+1][y]==ExistChess[x][y])
            {if_scanned[x][y]=1;flag+=if_legal(ExistChess,x+1,y);}
        }
        if(i==2)
        {
            if(y==0)continue;
            if(ExistChess[x][y-1]!=ExistChess[x][y])continue;
            if(if_scanned[x][y-1])continue;
            if(ExistChess[x][y-1]==ExistChess[x][y])
            {if_scanned[x][y]=1;flag+=if_legal(ExistChess,x,y-1);}
        }
        if(i==3)
        {
            if(y==8)continue;
            if(ExistChess[x][y+1]!=ExistChess[x][y])continue;
            if(if_scanned[x][y+1])continue;
            if(ExistChess[x][y+1]==ExistChess[x][y])
            {if_scanned[x][y]=1;flag+=if_legal(ExistChess,x,y+1);}
        }
    }
    return flag;
}
void Rules::if_scanned_init()
{
    for(int i=0;i<=8;i++)for(int j=0;j<=8;j++)if_scanned[i][j]=0;
}
bool Rules::illegal_operation_judging(int ExistChess[9][9],int X,int Y)
{
    //以下5个if函数分别判断点击处以及上下左右五个棋子是否存活
    if_scanned_init();
    if(!if_legal(ExistChess,X,Y))return false;
    if_scanned_init();
    if(X>0&&!if_legal(ExistChess,X-1,Y))return false;
    if_scanned_init();
    if(X<8&&!if_legal(ExistChess,X+1,Y))return false;
    if_scanned_init();
    if(Y>0&&!if_legal(ExistChess,X,Y-1))return false;
    if_scanned_init();
    if(Y<8&&!if_legal(ExistChess,X,Y+1))return false;
    return true;
}
