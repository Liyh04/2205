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
#include <QSet>
//#include "networkserver.h"
//#include "networksocket.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    void restart();//重新开局
    void on_saveButton_clicked();//save功能
public slots:
    void updatedisplay();//更新计时器显示
protected:
    //paint
    void paintEvent(QPaintEvent *);
    //mouse
    void mousePressEvent(QMouseEvent *);
public:
    //结构体用来按顺序存储棋子的落点；
    struct Chesspo
    {
        int x;
        int y;
        char c_y;
    }chesspo[81];
    //数组用来确定y坐标的字母表示
    char getC_y[10];
    void getCY();//获取坐标的函数
    int fail_state;//代表输了的状态，1-tle，2-giveup，0-初始值；
    
    Widget(QWidget *parent = nullptr);
    void init();//游戏开局时初始化
    void if_scanned_init();//将if_scanned数组所有元素重置为0
    //QTimer *mytimer;
    //QTimer *onesec;
    QTime baseTime;
    QTimer *pTimer;
    //QElapsedTimer *mycounter;
    ~Widget();
    //静态成员
    static int height;
    static int width;
    static int n_row;
    static int n_column;
    int ExistChess[9][9]={0};//0代表没有棋子，1代表黑棋，2代表白棋
    int if_scanned[9][9]={0};//在递归回溯时记录已经判断过的棋子，避免造成死循环
    //int tempx=0,tempy=0;
    int if_legal(int x,int y)//判断x行y列的棋子是否存活
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

private slots:
    void on_pushButton_clicked();//当按下认输按钮

private:
    Ui::Widget *ui;
    bool m_isBlackTurn;    //当前该黑棋下
    QVector<Chess> m_Chess;//已下的棋子座标容器

    void DrawChessboard();  //画棋盘
    void DrawChesses();     //画已下的棋子
    void DrawChessAtPoint(QPainter& painter,QPoint& pt);//在pt 位置,以Painter 画棋子
    void StopGame();  //停止当前棋局（暂未实现）
    void RepentanceGame(); //悔棋（暂未实现）
    // 服务端
    //NetworkServer* server;
    // 客户端
    //NetworkSocket* socket;
    // 最后一个客户端
    //QTcpSocket* lastOne;
    //QString IP;
    //int PORT;
    // 客户端池，NetworkServer 有一个 QList 的，但这里我想用 set，所以又弄了一个
    //QSet<QTcpSocket*> clients;


//private slots:
    //void receieveData(QTcpSocket* client, NetworkData data);
    //void receieveDataFromServer(NetworkData data);
    //void onClientSendButtonClicked();
    //void onServerSendButtonClicked();
    //void reStart();
    //void reConnect();
    //void reSet();
};
#endif // WIDGET_H
