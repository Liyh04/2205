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
#include "networkserver.h"
#include "networksocket.h"
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    QString clientName;
    QString serverName;
    int twice;
    int X_Other;
    int Y_Other;
    bool is_server=false;
    bool is_client=false;
    void DrawChess(int X,int Y);
    bool client_color_white=false;
    bool server_color_black=false;
    // 服务端
    NetworkServer* server;
    // 客户端
    //NetworkData data;
    NetworkSocket* socket1;
    NetworkSocket* socket;
    // 最后一个客户端
    QTcpSocket* lastOne;
    QString IP;
    int PORT;
    // 客户端池，NetworkServer 有一个 QList 的，但这里我想用 set，所以又弄了一个
    QSet<QTcpSocket*> clients;
    int flag_start;
    int flag_color;
    int if_client;

private slots:
    void receieveData(QTcpSocket* client, NetworkData data);
    void receieveDataFromServer(NetworkData data);
    void onClientSendButtonClicked();
    void onServerSendButtonClicked();
    void reStartServer();
    void reConnect();
    void reSet();

    void on_CREADY_OP_clicked();

    void on_CREJECT_OP_clicked();

    void on_SREADY_OP_clicked();

    void on_SREJECT_OP_clicked();

    void on_CilentGiveup_clicked();

    void on_ServerGiveup_2_clicked();

    void on_CLEAVE_OP_clicked();

    void on_SLEAVE_OP_clicked();

    void TIMEOUT_END_OP_send();

public:
    void restart();//重新开局
    void on_saveButton_clicked();//save
    //复现
    void on_fxbtn_clicked();
    void onInputFinished(const QString& text);
    
public slots:
    void updatedisplay();//更新计时器显示
protected:
    //paint
    void paintEvent(QPaintEvent *);
    //mouse
    void mousePressEvent(QMouseEvent *);
public:
     //save功能，结构体用来按顺序存储棋子的落点；
    struct Chesspo
    {
        int x;
        int y;
        char c_y;
    }chesspo[81];
    //复现&save
    QMap<char,int> char2num = {{'A',1},{'B',2},{'C',3},{'D',4},{'E',5},{'F',6},{'G',7},{'H',8},{'I',9}};
    QMap <int,char> num2char = {{1,'A'},{2,'B'},{3,'C'},{4,'D'},{5,'E'},{6,'F'},{7,'G'},{8,'H'},{9,'I'}};
    bool legalInput(QChar c1,QChar c2);

    void getCY();//获取坐标的函数

    int fail_state;//代表输了的状态，1-tle，2-giveup，0-初始值；

    Widget(QWidget *parent = nullptr);
    void init();//游戏开局时初始化
    QTime baseTime;
    QTimer *pTimer;
    ~Widget();
    //静态成员
    static int height;
    static int width;
    static int n_row;
    static int n_column;
    int ExistChess[9][9]={{0,0}};//0代表没有棋子，1代表黑棋，2代表白棋
   

private slots:
    void give_up_clicked();//当按下认输按钮

private:
    Ui::Widget *ui;
    bool m_isBlackTurn;    //当前该黑棋下
    QVector<Chess> m_Chess;//已下的棋子座标容器

    void DrawChessboard();  //画棋盘
    void DrawChesses();     //画已下的棋子
    void DrawChessAtPoint(QPainter& painter,QPoint& pt);//在pt 位置,以Painter 画棋子
    void StopGame();  //停止当前棋局（暂未实现）
    void RepentanceGame(); //悔棋（暂未实现）

};
#endif // WIDGET_H
