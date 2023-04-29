
#ifndef CHESS_H
#define CHESS_H
#include<QMouseEvent>
#include <QPainter>
#include <QObject>
#include <QPoint>
#include <QBrush>
#include <qcolor.h>
#include<vector>
class rules;
class timer;
class Widget;
class QWidget;
/*class Chess:public Widget
{
public:
    Chess(const Chess& c):m_ChessPossition(c.m_ChessPossition),m_ChessColor(c.m_ChessColor){}


    Chess();//(QObject *parent = nullptr);
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
    friend class Widget;
};
//Chess m_Chess[n_row*n_column];//已下的棋子座标容器*/
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
