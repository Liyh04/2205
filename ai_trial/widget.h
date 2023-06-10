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
#include"alphanogo.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class replay;
class Widget : public QWidget
{
    Q_OBJECT
public:
    bool isAIturn;
    bool AI_is_black;

    QString clientName;
    QString serverName;
    void Go();//托管下棋函数
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

private slots://实现网络部分的函数
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
    void on_fxbtn_clicked();    //点击复现
    void onInputFinished(const QString& text);//复现编码输入完成，准备开始复现播放
    void onInputNumFinished(const QString& text);//转到第n步的局面
    void onPlayButtonClicked();//开始播放
    void fx_drawChesses();//用于在复现的时候呈现棋盘
    void onPauseButtonClicked();//暂停播放
    void onNextButtonClicked();//播放下一步
    void onPreviousButtonClicked();//播放上一步
    void onExitReplayButtonClicked();//退出复现
    void onReplayToStepButtonClicked();//点击“到第n步”按钮
    void on_new_try_btn_clicked();//开始新的尝试
    void on_exit_try_btn_clicked();//退出新的尝试
    void local_giveup();//单机模式下的认输
public slots:
    void updatedisplay();//更新计时器显示
protected:
    //paint
    void paintEvent(QPaintEvent *);//调用库中的update函数，实时更新棋盘
    //mouse
    void mousePressEvent(QMouseEvent *);//鼠标点击棋盘，根据鼠标点击位置执行对应的操作
public:
     //save功能，结构体用来按顺序存储棋子的落点；
    struct Chesspo
    {
        int x;
        int y;
        char c_y;
    }chesspo[169];
    //复现&save
    QMap<char,int> char2num = {{'A',1},{'B',2},{'C',3},{'D',4},{'E',5},{'F',6},{'G',7},{'H',8},{'I',9},{'J',10},{'K',11},{'L',12},{'M',13}};
    QMap <int,char> num2char = {{1,'A'},{2,'B'},{3,'C'},{4,'D'},{5,'E'},{6,'F'},{7,'G'},{8,'H'},{9,'I'},{10,'J'},{11,'K'},{12,'L'},{13,'M'}};
    bool legalInput(QChar c1,QChar c2);//判断输入的复现编码是否合法

    void getCY();//获取坐标的函数

    int fail_state;//代表输了的状态，1-tle，2-giveup，0-初始值；

    Widget(QWidget *parent = nullptr);
    void setmode();//打开游戏界面前设置模式
    void init();//游戏开局时初始化
    QTime baseTime;
    qint64 curtime;
    QTimer *pTimer;
    QTimer* fxtimer;//用于复现
    int currentIndex;
    ~Widget();
    //静态成员
    static int height;
    static int width;
    static int n_row;
    static int n_column;
    int ExistChess[13][13];//0代表没有棋子，1代表黑棋，2代表白棋
   

private slots:
    void give_up_clicked();//当按下认输按钮

    void on_pushButton_2_clicked();//加入AI按钮

    void on_pushButton_clicked();//关闭AI按钮

public:
    Ui::Widget *ui;
    bool m_isBlackTurn;    //当前是否该黑棋下
    bool m_isTryMode;//是否为尝试模式
    bool m_isReplayMode;   //是否处于复现模式
    QVector<Chess> m_Chess;//已下的棋子座标容器
    QVector<Chess> toReplay;//用于复现

    QPushButton* rpbtn;//播放按钮
    QPushButton *psbtn;//暂停按钮
    QPushButton *prebtn;//上一步按钮
    QPushButton *etbtn;//退出复现按钮
    QPushButton *ntbtn;//下一步按钮
    QPushButton *fxbtn;//复现按钮
    QPushButton *r2sbtn;//到第n步按钮
    QPushButton *new_try_btn;//新的尝试按钮
    QPushButton *exit_try_btn;//退出尝试按钮

    void DrawChessboard();  //画棋盘
    void DrawChesses();     //画已下的棋子
    void DrawChessAtPoint(QPainter& painter,QPoint& pt);//在pt 位置,以Painter 画棋子
    //void GG(bool black_turn,bool if_client,bool client_color_white,int opcode);
};
#endif // WIDGET_H
