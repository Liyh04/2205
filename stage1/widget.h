#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "chess.h"
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>//垂直布局
#include<QVBoxLayout>//水平布局
#include <QElapsedTimer>
#include <QWidget>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    void restart();
public slots:
    void updatedisplay();
    //void on_Btnstart_clicked();
protected:
    //paint
    void paintEvent(QPaintEvent *);
    //mouse
    void mousePressEvent(QMouseEvent *);
public:

    Widget(QWidget *parent = nullptr);
    void init();
    void if_scanned_init();
    QTimer *mytimer;
    QTimer *onesec;
    QTime baseTime;
    QTimer *pTimer;
    QElapsedTimer *mycounter;
    ~Widget();

//    void StopGame();  //停止当前棋局
//    void RepentanceGame(); //悔棋

    //静态成员
    static int height;
    static int width;
    static int n_row;
    static int n_column;
    int ExistChess[9][9]={0};//0代表没有棋子，1代表黑棋，2代表白棋
    int if_scanned[9][9]={0};
    int tempx=0,tempy=0;
    int if_legal(int x,int y)
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
                {if(x!=tempx&&y!=tempy)if_scanned[x][y]=1;flag+=if_legal(x-1,y);}
            }
            if(i==1)
            {
                if(x==8)continue;
                if(ExistChess[x+1][y]!=ExistChess[x][y])continue;
                if(if_scanned[x+1][y])continue;
                if(ExistChess[x+1][y]==ExistChess[x][y])
                {if(x!=tempx&&y!=tempy)if_scanned[x][y]=1;flag+=if_legal(x+1,y);}
            }
            if(i==2)
            {
                if(y==0)continue;
                if(ExistChess[x][y-1]!=ExistChess[x][y])continue;
                if(if_scanned[x][y-1])continue;
                if(ExistChess[x][y-1]==ExistChess[x][y])
                {if(x!=tempx&&y!=tempy)if_scanned[x][y]=1;flag+=if_legal(x,y-1);}
            }
            if(i==3)
            {
                if(y==8)continue;
                if(ExistChess[x][y+1]!=ExistChess[x][y])continue;
                if(if_scanned[x][y+1])continue;
                if(ExistChess[x][y+1]==ExistChess[x][y])
                {if(x!=tempx&&y!=tempy)if_scanned[x][y]=1;flag+=if_legal(x,y+1);}
            }
        }
        if(x==tempx&&y==tempy)return flag;
        else return 0;
    }


private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    bool m_isBlackTurn;    //当前该黑棋下
    QVector<Chess> m_Chess;//已下的棋子座标容器

    void DrawChessboard();  //画棋盘
    void DrawChesses();     //画已下的棋子
    void DrawChessAtPoint(QPainter& painter,QPoint& pt);//在pt 位置,以Painter 画棋子
    void StopGame();  //停止当前棋局
    void RepentanceGame(); //悔棋

};
#endif // WIDGET_H
