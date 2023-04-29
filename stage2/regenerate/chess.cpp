
#include "chess.h"
#include "widget.h"

#include"paint.h"
#include"rules.h"
#include"timer.h"
Chess::Chess()
{

}
Chess::Chess(QPoint pt,bool bChessColor):
    m_ChessPossition(pt),
    m_ChessColor( bChessColor){}//初始化列表初始化



