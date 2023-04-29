#include<QMessageBox>
#include "rules.h"

rules::rules()
{

}
int rules::if_legal(int x,int y)
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
            {if_scanned[x][y]=1;flag+=if_legal(x-1,y);}
        }
        if(i==1)
        {
            if(x==8)continue;
            if(ExistChess[x+1][y]!=ExistChess[x][y])continue;
            if(if_scanned[x+1][y])continue;
            if(ExistChess[x+1][y]==ExistChess[x][y])
            {if_scanned[x][y]=1;flag+=if_legal(x+1,y);}
        }
        if(i==2)
        {
            if(y==0)continue;
            if(ExistChess[x][y-1]!=ExistChess[x][y])continue;
            if(if_scanned[x][y-1])continue;
            if(ExistChess[x][y-1]==ExistChess[x][y])
            {if_scanned[x][y]=1;flag+=if_legal(x,y-1);}
        }
        if(i==3)
        {
            if(y==8)continue;
            if(ExistChess[x][y+1]!=ExistChess[x][y])continue;
            if(if_scanned[x][y+1])continue;
            if(ExistChess[x][y+1]==ExistChess[x][y])
            {if_scanned[x][y]=1;flag+=if_legal(x,y+1);}
        }
    }
    return flag;
}
bool rules::illegal_warning(int X,int Y)
{
    rules::if_scanned_init();
    if(m_isBlackTurn)ExistChess[X][Y]=1;
    if(!m_isBlackTurn)ExistChess[X][Y]=2;
    //判断合法前，先假设点击的位置已经下了棋子，如果不合法，则将数组中对应元素重置为0
    //以下5个if函数分别判断点击处以及上下左右五个棋子是否存活
    if(!if_legal(X,Y))
    {
        ExistChess[X][Y]=0;
        QMessageBox *warning1=new QMessageBox;
        warning1->information(this, "Warning", QString("Illegal operation. Please try again."));
        return 1;
    }
    rules::if_scanned_init();
    if(X>0&&!if_legal(X-1,Y))
    {
        ExistChess[X][Y]=0;
        QMessageBox *warning1=new QMessageBox;
        warning1->information(this, "Warning", QString("Illegal operation. Please try again."));
        return 1;
    }
    rules::if_scanned_init();
    if(X<8&&!if_legal(X+1,Y))
    {
        ExistChess[X][Y]=0;
        QMessageBox *warning1=new QMessageBox;
        warning1->information(this, "Warning", QString("Illegal operation. Please try again."));
        return 1;
    }
    rules::if_scanned_init();
    if(Y>0&&!if_legal(X,Y-1))
    {
        ExistChess[X][Y]=0;
        QMessageBox *warning1=new QMessageBox;
        warning1->information(this, "Warning", QString("Illegal operation. Please try again."));
        return 1;
    }
    rules::if_scanned_init();
    if(Y<8&&!if_legal(X,Y+1))
    {
        ExistChess[X][Y]=0;
        QMessageBox *warning1=new QMessageBox;
        warning1->information(this, "Warning", QString("Illegal operation. Please try again."));
        return 1;
    }
    return 0;
}
void rules::if_scanned_init()
{
    for(int i1=0;i1<9;i1++)for(int j1=0;j1<9;j1++)if_scanned[i1][j1]=0;
}
