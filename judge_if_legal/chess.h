#ifndef CHESS_H
#define CHESS_H

#include <QObject>
#include <QPoint>

class Chess //:// public QObject
{
   // Q_OBJECT
public:
    explicit Chess();//(QObject *parent = nullptr);
    //无参构造函数
    //Chess();
    //构造函数
    Chess(QPoint pt,bool bChessColor);

    //重载相等，即坐标和颜色都相同
    bool operator==(const Chess &t1)const
        {
            return ((m_ChessPossition == t1.m_ChessPossition) && (m_ChessColor == t1.m_ChessColor));
        }

    QPoint m_ChessPossition; //位置座标

    bool m_ChessColor; //颜色


signals:


};

#endif // CHESS_H
