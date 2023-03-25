#include "chess.h"


Chess::Chess()//(QObject *parent) //  : QObject{parent}
{

}
//无参构造函数
//Chess::Chess()
//{};
//构造函数
Chess::Chess(QPoint pt,bool bChessColor):
    m_ChessPossition(pt),
    m_ChessColor( bChessColor)//初始化列表初始化
{

}
