
#ifndef CHESS_H
#define CHESS_H
#include "rules.h"
#include<QMouseEvent>
#include <QPainter>
#include <QObject>
#include <QPoint>
#include <QBrush>
#include <qcolor.h>
class rules;
class timer;
class Widget;
class Chess:public Widget
{
public:
    Chess(const Chess&){}
    static QVector<Chess> m_Chess;//已下的棋子座标容器
    void mousePressEvent(QMouseEvent * e);
    explicit Chess();//(QObject *parent = nullptr);
    //无参构造函数
    //Chess();
    //构造函数
    Chess(QPoint pt,bool bChessColor);
    void DrawChesses();     //画已下的棋子
    //重载相等，即坐标和颜色都相同
    bool operator==(const Chess &t1)const
    {
        return ((m_ChessPossition == t1.m_ChessPossition) && (m_ChessColor == t1.m_ChessColor));
    }

    QPoint m_ChessPossition; //位置座标

    bool m_ChessColor; //颜色
};

#endif // CHESS_H
