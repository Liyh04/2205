#include "chessrule.h"
#include <QDebug>
//#include <widget.h>
ChessRule::ChessRule()
{
    po[0].rx()=-50;
    po[0].ry()=0;//👈
    po[1].rx()=0;
    po[1].ry()=50;//👆
    po[2].rx()=50;
    po[2].ry()=0;//👉
    po[3].rx()=0;
    po[3].ry()=-50;//👇
    po[4].rx()=0;
    po[4].ry()=0;//不动
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            SighMap[i][j]=0;

        }
    }
    for (int i = 0; i < 5; ++i)
    {
        SighMax[i]=0;

    }

}

void ChessRule::calcuate(QPoint& pt,bool color,int num)//这个颜色是要下的
{
    if(SearchMap[pt.rx()][pt.ry()]==1)
        return ;
    for (int i = 0; i < 4; ++i)
    {
        SearchMap[pt.rx()][pt.ry()]=1;

        QPoint n_pt=pt+po[i];
        Chess temp1(n_pt,color);
        Chess temp2(n_pt,!color);//相反颜色

        //qDebug()<<"n_pt="<<n_pt.rx()<<","<<n_pt.ry();
        if(m_Chess.contains(temp1)&&SearchMap[n_pt.rx()][n_pt.ry()]==0)
        {
           qDebug()<<"enter递归";
           calcuate(n_pt,color,num);
        }
        else if(!m_Chess.contains(temp2))
        {
            //qDebug()<<"enter++";
            SighMap[n_pt.rx()][n_pt.ry()]++;

            SighMax[num]++;
        }
    }

    if(SighMap[pt.rx()][pt.ry()]<SighMax[num])
    {
        SighMap[pt.rx()][pt.ry()]=SighMax[num];
    }


}
