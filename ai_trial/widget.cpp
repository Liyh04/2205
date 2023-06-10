#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <chess.h>
#include <QDebug>
#include <QHBoxLayout>//垂直布局
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
#include <QMessageBox>
#include <QLabel>
#include <QInputDialog>
#include <QBrush>
#include <qcolor.h>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <inputdialog.h>
#include <rules.h>
#include"alphanogo.h"
#include "available.h"
//初始化静态成员
int Widget::height=50;
int Widget::width=50;
int Widget::n_row;
bool if_netmode;
bool replay_mode=false;
int TIMELIMIT=30;
int step=0;
bool AI_is_Awake;
Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::Widget)//初始化ui界面
{
    #define PAINT_X 0
    #define PAINT_Y 0
    setFixedSize(1200,700);
    ui->setupUi(this);

    this->setmode();
    this->init();

    //设置标题
    setWindowTitle("NoGo_group5");
    m_isBlackTurn = true;//黑子先行
    fail_state=0;
    //复现---
    if(n_row==9)
    {
        fxbtn = new QPushButton("复现",this);
        fxbtn->move(1000,60);
        fxbtn->resize(90,25);
        connect(fxbtn,&QPushButton::clicked,this,&Widget::on_fxbtn_clicked);
        m_isReplayMode = false;
        fxtimer = new QTimer(this);
        currentIndex = 0;

        connect(fxtimer,&QTimer::timeout,this,&Widget::fx_drawChesses);//待改正

        rpbtn = new QPushButton("播放",this);
        rpbtn->move(20,540);
        rpbtn->resize(110,22);
        connect(rpbtn,&QPushButton::clicked,this,&Widget::onPlayButtonClicked);
        rpbtn->setDisabled(true);

        psbtn = new QPushButton("暂停",this);
        psbtn->move(20,570);
        psbtn->resize(110,22);
        connect(psbtn,&QPushButton::clicked,this,&Widget::onPauseButtonClicked);
        psbtn->setDisabled(true);

        prebtn = new QPushButton("上一个",this);
        prebtn->move(140,540);
        prebtn->resize(110,22);
        connect(prebtn,&QPushButton::clicked,this,&Widget::onPreviousButtonClicked);
        prebtn->setDisabled(true);

        ntbtn = new QPushButton("下一个",this);
        ntbtn->move(260,540);
        ntbtn->resize(110,22);
        connect(ntbtn,&QPushButton::clicked,this,&Widget::onNextButtonClicked);
        ntbtn->setDisabled(true);

        etbtn = new QPushButton("退出复现",this);
        etbtn->move(260,570);
        etbtn->resize(110,22);
        connect(etbtn,&QPushButton::clicked,this,&Widget::onExitReplayButtonClicked);
        etbtn->setDisabled(true);

        r2sbtn = new QPushButton("到第n步",this);
        r2sbtn->move(140,570);
        r2sbtn->resize(110,22);
        connect(r2sbtn,&QPushButton::clicked,this,&Widget::onReplayToStepButtonClicked);
        r2sbtn->setDisabled(true);

        new_try_btn = new QPushButton("新的尝试",this);
        new_try_btn->move(380,540);
        new_try_btn->resize(110,22);
        connect(new_try_btn,&QPushButton::clicked,this,&Widget::on_new_try_btn_clicked);
        new_try_btn->setDisabled(true);

        exit_try_btn = new QPushButton("退出尝试",this);
        exit_try_btn->move(380,570);
        exit_try_btn->resize(110,22);
        connect(exit_try_btn,&QPushButton::clicked,this,&Widget::on_exit_try_btn_clicked);
        exit_try_btn->setDisabled(true);

    }
    IP = "127.0.0.1";
    // 端口，不要太简单，要避免和别的软件冲突
    PORT = 16677;
    this->ui->IPEdit->setText(IP);

    // 创建一个服务端
    this->server = new NetworkServer(this);
    lastOne = nullptr;
    // 创建一个客户端
    this->socket = new NetworkSocket(new QTcpSocket(),this);
    connect(this->socket->base(),&QTcpSocket::connected,this,[&]()
            {this->ui->connectLabel->setText("connection succeed");
            if_client=1;
        ui->serverGet->setEnabled(false);
        ui->serverGetEdit->setEnabled(false);
        ui->serverSend->setEnabled(false);
        ui->serverSendEdit->setEnabled(false);
        ui->getButton_2->setEnabled(false);
        ui->serverSendButton->setEnabled(false);
        ui->SLEAVE_OP->setEnabled(false);
        ui->SREADY_OP->setEnabled(false);
        ui->SREJECT_OP->setEnabled(false);
        ui->ServerGiveup_2->setEnabled(false);
        ui->reStartButton->setEnabled(false);//
        ui->clientGet->setEnabled(true);
        ui->clientGetEdit->setEnabled(true);
        ui->clientSend->setEnabled(true);
        ui->clientSendEdit->setEnabled(true);
        ui->getButton_1->setEnabled(true);
        ui->clientSendButton->setEnabled(true);
        ui->CLEAVE_OP->setEnabled(true);
        ui->CREADY_OP->setEnabled(true);
        ui->CREJECT_OP->setEnabled(true);
        ui->CilentGiveup->setEnabled(true);
        ui->reConnectButton->setEnabled(true);});
    connect(this->socket,&NetworkSocket::receive,this,&Widget::receieveDataFromServer);
    connect(this->server,&NetworkServer::receive,this,&Widget::receieveData);
    connect(this->ui->clientSendButton,&QPushButton::clicked,this,&Widget::onClientSendButtonClicked);
    connect(this->ui->serverSendButton,&QPushButton::clicked,this,&Widget::onServerSendButtonClicked);
    connect(this->ui->showClientButton,&QPushButton::clicked,this,[&](){qDebug()<<clients;});
    connect(this->ui->reSetButton,&QPushButton::clicked,this,&Widget::reSet);
    connect(this->ui->reConnectButton,&QPushButton::clicked,this,&Widget::reConnect);
    connect(this->ui->reStartButton,&QPushButton::clicked,this,&Widget::reStartServer);
    connect(this->ui->local_giveup,&QPushButton::clicked,this,&Widget::local_giveup);
    // 客户端向 IP:PORT 连接，不会连到自己
    IP=this->ui->IPEdit->text();
    this->socket->hello(IP,PORT);
    // 阻塞等待，2000ms超时
    this->socket->base()->waitForConnected(2000);

}
Widget::~Widget()//析构函数
{
    delete ui;
}


void Widget::Go(){
    if(n_row!=9)return;
    AlphaNoGO Ai;
    if(AI_is_Awake){
        if(m_isBlackTurn){
            Point point=Ai.search(ExistChess,m_isBlackTurn);
            if(point.x==-1&&!if_netmode){local_giveup();return;}
            if(point.x==-1)
            {
                if(if_client)on_CilentGiveup_clicked();
                else on_ServerGiveup_2_clicked();
                return;
            }
            if(ExistChess[point.x][point.y])return;
            DrawChess(point.x,point.y);
            m_isBlackTurn=0;
            if(if_client==1&&if_netmode){
                //this->socket->send(NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(point.x).arg(point.y),""));
                QString st;
                std::string s;
                s=point.x+'A';
                st=QString::fromStdString(s);
                this->socket->send(NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(st).arg(point.y+1),""));//客户端传下的棋子过去
            }
            if(if_client==0&&if_netmode){
                 //this->server->send(lastOne,NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(point.x).arg(point.y),""));
                QString st;
                std::string s;
                s=point.x+'A';
                st=QString::fromStdString(s);
                this->server->send(lastOne,NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(st).arg(point.y+1),""));
            }
            return;
        }
        if(!m_isBlackTurn){
            Point point=Ai.search(ExistChess,m_isBlackTurn);
            if(point.x==-1&&!if_netmode){local_giveup();return;}
            if(point.x==-1)
            {
                if(if_client)on_CilentGiveup_clicked();
                else on_ServerGiveup_2_clicked();
                return;
            }
            DrawChess(point.x,point.y);
            m_isBlackTurn=1;
            if(if_client==1&&if_netmode){
                //this->socket->send(NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(point.x).arg(point.y),""));
                QString st;
                std::string s;
                s=point.x+'A';
                st=QString::fromStdString(s);
                this->socket->send(NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(st).arg(point.y+1),""));//客户端传下的棋子过去
            }
            if(if_client==0&&if_netmode){
                 //this->server->send(lastOne,NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(point.x).arg(point.y),""));
                QString st;
                std::string s;
                s=point.x+'A';
                st=QString::fromStdString(s);
                this->server->send(lastOne,NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(st).arg(point.y+1),""));
            }
            return;
        }
    }
}

void Widget::setmode()
{
    QPushButton *netmode,*singlemode_9,*singlemode_11,*singlemode_13;
    QMessageBox *MyBox=new QMessageBox;
    MyBox->setText("请选择游戏模式");
    netmode=MyBox->addButton("联机模式",QMessageBox::YesRole);
    singlemode_9=MyBox->addButton("单机9路",QMessageBox::YesRole);
    singlemode_11=MyBox->addButton("单机11路",QMessageBox::YesRole);
    singlemode_13=MyBox->addButton("单机13路",QMessageBox::YesRole);
    connect(netmode,&QPushButton::clicked,this,[&](){if_netmode=true;n_row=9;});
    connect(singlemode_9,&QPushButton::clicked,this,[&](){if_netmode=false;n_row=9;});
    connect(singlemode_11,&QPushButton::clicked,this,[&](){if_netmode=false;AI_is_Awake=false;n_row=11;
    ui->pushButton->setEnabled(false);ui->pushButton_2->setEnabled(false);});
    connect(singlemode_13,&QPushButton::clicked,this,[&](){if_netmode=false;AI_is_Awake=false;n_row=13;
    ui->pushButton->setEnabled(false);ui->pushButton_2->setEnabled(false);});
    MyBox->exec();
}
//复现--------
void Widget::on_fxbtn_clicked()
{
    InputDialog* inputDialog = new InputDialog(this);
    connect(inputDialog,&InputDialog::inputFinished,this,&Widget::onInputFinished);
    inputDialog->show();
    m_isReplayMode=true;
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<13;j++)
        {
            ExistChess[i][j]=0;
        }
    }

}
bool Widget::legalInput(QChar c1,QChar c2)
{
    if('A'<=c1&&c1<='I'&&c2>='1'&&c2>='1'&&c2<='9')
        return true;
    else
        return false;
}

void Widget::receieveData(QTcpSocket* client, NetworkData data)//这是服务端
{
    qDebug()<<"Server get a data: "<<client<<" "<<data.encode();
    lastOne=client;
    // 获得地址的字符串表示，调试用
    QString ptrStr = QString("0x%1").arg((quintptr)client,
                                         QT_POINTER_SIZE, 16, QChar('0'));
    this->ui->lastOneLabel->setText("LastOne: "+ptrStr);
    this->clients.insert(client);
    this->ui->serverGetEdit->setText(data.data1);
    this->ui->serverGet->setText(data.data2);
    if(data.data2=='w'&&data.op==OPCODE::READY_OP){
        client_color_white=true;
        server_color_black=true;
        clientName=this->ui->serverGetEdit->text();
    }//如果客户端请求白棋

    //READY_OP部分
    if(data.op==OPCODE::READY_OP){
        clientName=this->ui->serverGetEdit->text();
        QString color;
        QString color2;
        if(data.data2=='w'){
            color="(white)";
            color2="(black)";
        }
        else{
            color="(black)";
            color2="(white)";
        }
        QString strr="  Wanana play with you ";
        QString message=QString("%1%2%3%4").arg(clientName).arg(color).arg(strr).arg(color2);
        QMessageBox::StandardButton r = QMessageBox::question(this, "Ask For Play", message ,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if (r == QMessageBox::Yes){
            if(lastOne)
                this->server->send(lastOne,NetworkData(OPCODE::READY_OP,this->ui->serverSendEdit->text(),this->ui->serverSend->text()));
            serverName=this->ui->serverSendEdit->text();
            is_server=true;
            flag_start=1;//游戏可以开始
        }
        if(r==QMessageBox::No){
            if(lastOne)this->server->send(lastOne,NetworkData(OPCODE::REJECT_OP,this->ui->serverSendEdit->text(),this->ui->serverSend->text()));
            flag_start=-1;//游戏不能开始
        }
        //注意这里需要准备操作就是在确定服务端之后服务端在收到弹窗前要把name设置好
    }


    if(data.op==OPCODE::MOVE_OP){
        QString  qstr = data.data1;
        std::string str = qstr.toStdString();
        X_Other=str[0]-'A';
        Y_Other=str[1]-'1';
        DrawChess(X_Other,Y_Other);
        Go();
       // m_isBlackTurn=!m_isBlackTurn;
    }


    if(data.op==OPCODE::GIVEUP_OP){
        if(client_color_white)
            m_isBlackTurn=0;
        else
            m_isBlackTurn=1;
        if(lastOne)this->server->send(lastOne,NetworkData(OPCODE::GIVEUP_END_OP,serverName,"wenhouyu"));//客户端先发送GG_OP
        twice=1;
        give_up_clicked();
        //this->server->send(lastOne,NetworkData(OPCODE::GIVEUP_END_OP,serverName,"wenhouyu"));//客户端先发送GG_OP
        //twice=1;
    }


    if(data.op==OPCODE::LEAVE_OP){
        pTimer->stop();
        flag_start=0;
    }

    if(data.op==OPCODE::GIVEUP_END_OP){

        if(twice==1){
            twice=2;

                if(lastOne)this->server->send(lastOne,NetworkData(OPCODE::GIVEUP_END_OP,serverName,"wenhouyu"));
        }
    }

    if(data.op==OPCODE::TIMEOUT_END_OP){

        if(twice==1){
                twice=2;

                if(lastOne)this->server->send(lastOne,NetworkData(OPCODE::TIMEOUT_END_OP,serverName,"wenhouyu"));
        }
    }

    if(data.op==OPCODE::SUICIDE_END_OP){

        if(twice==1){
                twice=2;

                if(lastOne)this->server->send(lastOne,NetworkData(OPCODE::SUICIDE_END_OP,serverName,"wenhouyu"));
        }
    }
}

void Widget::receieveDataFromServer(NetworkData data)
{
    qDebug()<<"Client get a data: "<<data.encode();
    this->ui->clientGetEdit->setText(data.data1);
    this->ui->clientGet->setText(data.data2);


    if(data.op==OPCODE::LEAVE_OP){
        socket->bye();
    }
    if(data.op==OPCODE::MOVE_OP){
        //int tmp = str.toInt();字符串转化为int
        QString  qstr = data.data1;
        std::string str = qstr.toStdString();
        X_Other=str[0]-'A';
        Y_Other=str[1]-'1';
        DrawChess(X_Other,Y_Other);
        Go();
    }


    if(data.op==OPCODE::READY_OP){
        flag_start=1;
        serverName=this->ui->clientGetEdit->text();
    }


    if(data.op==OPCODE::GIVEUP_OP){
        if(!client_color_white)
            m_isBlackTurn=0;
        else
            m_isBlackTurn=1;
        twice=1;
        this->socket->send(NetworkData(OPCODE::GIVEUP_END_OP,clientName,"wenhouyu"));
        give_up_clicked();
    }

    if(data.op==OPCODE::GIVEUP_END_OP){
        if(twice==1){
            twice=2;
            this->socket->send(NetworkData(OPCODE::GIVEUP_END_OP,clientName,"wenhouyu"));
        }       
    }

    if(data.op==OPCODE::TIMEOUT_END_OP){
        if(twice==1){
            twice=2;
            this->socket->send(NetworkData(OPCODE::TIMEOUT_END_OP,clientName,"wenhouyu"));
        }
    }

    if(data.op==OPCODE::SUICIDE_END_OP){
        if(twice==1){
            twice=2;
            this->socket->send(NetworkData(OPCODE::SUICIDE_END_OP,clientName,"wenhouyu"));
        }
    }
}

void Widget::onClientSendButtonClicked()
{
    this->socket->send(NetworkData(OPCODE::CHAT_OP,this->ui->clientSendEdit->text(),this->ui->clientSend->text()));//有点问题
}

void Widget::onServerSendButtonClicked()
{
    if(lastOne)
        this->server->send(lastOne,NetworkData(OPCODE::CHAT_OP,this->ui->serverSendEdit->text(),this->ui->serverSend->text()));
}

void Widget::reStartServer()
{
    IP=this->ui->IPEdit->text();
    PORT=this->ui->PORTEdit->text().toInt();
    qDebug()<<"restart the server.";
    this->ui->lastOneLabel->setText("LastOne: ");
    this->ui->connectLabel->setText("disconnect");
    disconnect(this->server,&NetworkServer::receive,this,&Widget::receieveData);
    clients.clear();
    delete this->server;
    this->server = new NetworkServer(this);
    // 端口相当于传信息的窗户，收的人要在这守着
    this->server->listen(QHostAddress::Any,PORT);
    lastOne = nullptr;
    connect(this->server,&NetworkServer::receive,this,&Widget::receieveData);
    if_client=0;
    ui->serverGet->setEnabled(true);
    ui->serverGetEdit->setEnabled(true);
    ui->serverSend->setEnabled(true);
    ui->serverSendEdit->setEnabled(true);
    ui->getButton_2->setEnabled(true);
    ui->serverSendButton->setEnabled(true);
    ui->SLEAVE_OP->setEnabled(true);
    ui->SREADY_OP->setEnabled(true);
    ui->SREJECT_OP->setEnabled(true);
    ui->ServerGiveup_2->setEnabled(true);
    ui->reStartButton->setEnabled(true);//
    ui->clientGet->setEnabled(false);
    ui->clientGetEdit->setEnabled(false);
    ui->clientSend->setEnabled(false);
    ui->clientSendEdit->setEnabled(false);
    ui->getButton_1->setEnabled(false);
    ui->clientSendButton->setEnabled(false);
    ui->CLEAVE_OP->setEnabled(false);
    ui->CREADY_OP->setEnabled(false);
    ui->CREJECT_OP->setEnabled(false);
    ui->CilentGiveup->setEnabled(false);
    ui->reConnectButton->setEnabled(false);//
}

void Widget::reConnect()
{
    IP=this->ui->IPEdit->text();
    PORT=this->ui->PORTEdit->text().toInt();
    qDebug()<<"client reconnect to the server.";
    this->ui->connectLabel->setText("connection fail");
    if_client=1;
    this->socket->bye();
    this->socket->hello(IP,PORT);
    if(!this->socket->base()->waitForConnected(3000)){
        qDebug()<<"reconnect fail";
    }
}

void Widget::reSet()//供客户端点击
{
    this->ui->connectLabel->setText("connection fail");
    IP=this->ui->IPEdit->text();
    PORT=this->ui->PORTEdit->text().toInt();
    this->reStartServer();
    this->reConnect();
}

void Widget::on_CREADY_OP_clicked()//客户端申请
{
    clientName=this->ui->clientSendEdit->text();
    is_client=true;
    const QString w="w";
    if(this->ui->clientSend->text()==w)
        client_color_white=true;//只判断客户端是不是白棋
    this->socket->send(NetworkData(OPCODE::READY_OP,this->ui->clientSendEdit->text(),this->ui->clientSend->text()));
    //receive处的data2对应客户端棋子的颜色另一个则为服务端棋子的颜色
}

void Widget::on_SREADY_OP_clicked()//服务端同意
{
    if(lastOne)
        this->server->send(lastOne,NetworkData(OPCODE::READY_OP,this->ui->serverSendEdit->text(),this->ui->serverSend->text()));
    serverName=this->ui->serverSendEdit->text();
    is_server=true;
    flag_start=1;//游戏可以开始
}

void Widget::on_SREJECT_OP_clicked()//服务端拒绝
{
    this->server->send(lastOne,NetworkData(OPCODE::REJECT_OP,this->ui->serverSendEdit->text(),this->ui->serverSend->text()));
    flag_start=-1;//游戏不能开始
}
void Widget::on_CREJECT_OP_clicked(){
    this->server->send(lastOne,NetworkData(OPCODE::LEAVE_OP,"LEAVE_OP",""));
}//多余的但是不能删除

void Widget::on_CilentGiveup_clicked()//客户端投降
{
   if((client_color_white&&!m_isBlackTurn)||(!client_color_white&&m_isBlackTurn)){
        this->socket->send(NetworkData(OPCODE::GIVEUP_OP,"",""));

        if(client_color_white){
            m_isBlackTurn=0;
            give_up_clicked();
        }
        else{
            m_isBlackTurn=1;
            give_up_clicked();
        }
    }

}
void Widget::on_ServerGiveup_2_clicked()//服务端投降
{
   if((client_color_white&&m_isBlackTurn)||(!client_color_white&&!m_isBlackTurn)){
        if(lastOne)
        this->server->send(lastOne,NetworkData(OPCODE::GIVEUP_OP,"",""));
        if(!client_color_white){
            m_isBlackTurn=0;
            give_up_clicked();
        }
        else{
            m_isBlackTurn=1;
            give_up_clicked();
        }
    }
}
void Widget::on_CLEAVE_OP_clicked()
{
    this->socket->send(NetworkData(OPCODE::LEAVE_OP,"LEAVEOP",""));
    pTimer->stop();
    socket->bye();
}
void Widget::on_SLEAVE_OP_clicked()
{
    this->server->send(lastOne,NetworkData(OPCODE::LEAVE_OP,"LEAVEOP",""));

}
void Widget::TIMEOUT_END_OP_send()
{

}

void Widget::paintEvent(QPaintEvent *)//画棋盘和棋子
{
    DrawChessboard();        //画棋盘
    DrawChesses();            //画棋子
    update();//实时更新
}
void Widget::DrawChessboard()//初始化棋盘
{
    //设置画家
    if(n_row!=9)
    {
        QPainter painter(this);
        int squareSize = 50;
        int x = PAINT_X+50;
        int y = PAINT_Y+50;

        for (int row = 0; row < n_row-1; ++row) {
            for (int col = 0; col < n_row-1; ++col) {
                QRectF square(x, y, squareSize, squareSize);
                painter.drawRect(square);
                x += squareSize;
            }
            x = PAINT_X+50;
            y += squareSize;
        }
    }
    else
    {
        QPainter painter_Yujx_board(this);
        //图片-棋盘
        QPixmap pix_chessmap;
        pix_chessmap.load(":/images/qipan.jpg");
        //改变大小，500,500
        pix_chessmap=pix_chessmap.scaled(500,500,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        //画图
        painter_Yujx_board.drawPixmap(PAINT_X,PAINT_Y,pix_chessmap);
    }
}
void Widget::DrawChesses()//画棋子
{
    //设置画家
    QPainter painter_Yu_chess(this);
    //图片-白子和黑子
    QPixmap pix_chessmap_White;
    pix_chessmap_White.load(":/images/white.png");
    QPixmap pix_chessmap_Black;
    pix_chessmap_Black.load(":/images/black.png");
    //改变大小，40*40
    pix_chessmap_Black=pix_chessmap_Black.scaled(40,40,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    pix_chessmap_White=pix_chessmap_White.scaled(40,40,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    for (int i = 0; i<m_Chess.size(); i++) //重新绘制每一个已下的棋子
    {
        Chess chess_seted ( m_Chess[i]);//拷贝构造
        if (chess_seted.m_ChessColor)//如果是该下黑子了
        {
            //画黑子
            painter_Yu_chess.drawPixmap(chess_seted.m_ChessPossition,pix_chessmap_Black);
        }
        else
        {
            //画白子
            painter_Yu_chess.drawPixmap(chess_seted.m_ChessPossition,pix_chessmap_White);
        }
        //高亮棋子

        if(i==m_Chess.size()-1||i==m_Chess.size()-2)
        {
            QColor Viva_Magenta(0xCE0B4D);//设置颜色--Viva_Magenta_18-1750_2023年度色彩_By_Pantone，
            QPen pen(Viva_Magenta);//定义画笔
            pen.setWidth(2);//
            // pen.setStyle(Qt::DashDotDotLine);
            painter_Yu_chess.setPen(pen);
            painter_Yu_chess.drawEllipse(chess_seted.m_ChessPossition.rx(),chess_seted.m_ChessPossition.ry(),40,40);
           // painter_Yu_chess.setBrush();
        }
    }
}
void Widget::on_new_try_btn_clicked()
{
    m_isReplayMode=false;
    m_isTryMode=true;
    rpbtn->setEnabled(false);
    psbtn->setEnabled(false);
    prebtn->setEnabled(false);
    ntbtn->setEnabled(false);
    r2sbtn->setEnabled(false);
    exit_try_btn->setEnabled(true);
    onPauseButtonClicked();
}
void Widget::on_exit_try_btn_clicked()
{
    m_isReplayMode=true;
    m_isTryMode=false;
    rpbtn->setEnabled(true);
    psbtn->setEnabled(true);
    prebtn->setEnabled(true);
    ntbtn->setEnabled(true);
    r2sbtn->setEnabled(true);
    exit_try_btn->setEnabled(false);
    m_Chess.clear();
    for(int i=0;i<9;i++)for(int j=0;j<9;j++)ExistChess[i][j]=0;
    std::copy_n(toReplay.begin(),currentIndex,std::back_inserter(m_Chess));
    for(int i=0;i<m_Chess.size();i++)
    {
        int X=(m_Chess[i].m_ChessPossition.y()-PAINT_Y)/Widget::height;
        int Y=(m_Chess[i].m_ChessPossition.x()-PAINT_X)/Widget::width;
        if(m_Chess[i].m_ChessColor)ExistChess[X][Y]=1;
        else ExistChess[X][Y]=2;
    }
    available a;
    ui->b_avi->setText(QString("Black_ava:%1").arg(a.ava_number(ExistChess,n_row,1)));
    ui->w_avi->setText(QString("White_ava:%1").arg(a.ava_number(ExistChess,n_row,0)));
    if(m_Chess.back().m_ChessColor)ui->label_3->setText("WHITE");
    else ui->label_3->setText("BLACK");
    DrawChesses();
}
void Widget::onInputFinished(const QString& text)
{
    m_isBlackTurn=1;
    pTimer->stop();
    m_Chess.clear();//G3 H3 F3 G4 G5 G6 G
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            ExistChess[i][j]=0;
        }
    }
    if(text.size()==1)
        return;
    for (QString::const_iterator it = text.begin()+1;it!=text.end();it+=3)
    {
        QChar c1 = *(it-1);//G
        char c_1 = c1.toLatin1();
        QChar c2 = (*it);//3
        int c_2  = (int)(c2.toLatin1())-'0';

        if(!legalInput(c1,c2))
        {
            QMessageBox *warning=new QMessageBox;
            warning->information(this, "Warning", QString("Illegal input."));
            delete warning;
            return;
        }
        else
        {
            Chess a;
            a.m_ChessColor=m_isBlackTurn;
            a.m_ChessPossition.setY((char2num[(char)c_1])*height+PAINT_Y-20);
            a.m_ChessPossition.setX((c_2)*width+PAINT_X-20);
            toReplay+=a;
            m_isBlackTurn=!m_isBlackTurn;
        }
    }
    m_isReplayMode = true;
    fxbtn->setDisabled(true);
    rpbtn->setEnabled(true);
    psbtn->setEnabled(true);
    prebtn->setEnabled(true);
    ntbtn->setEnabled(true);
    etbtn->setEnabled(true);
    r2sbtn->setEnabled(true);
    new_try_btn->setEnabled(true);
}
void Widget::onInputNumFinished(const QString& text)
{
    int n = text.toInt();
    currentIndex = n;
    //qDebug()<<"n==-----------------------"<<n<<"-----"<<toReplay.size();
    if(n<0||n>toReplay.size())
    {
        QMessageBox *warning=new QMessageBox;
        warning->information(this, "Warning", QString("Illegal input."));
        delete warning;
        return;
    }
    m_Chess.clear();
    for(int i=0;i<13;i++)for(int j=0;j<13;j++)ExistChess[i][j]=0;
    std::copy_n(toReplay.begin(),currentIndex,std::back_inserter(m_Chess));
    for(int i=0;i<m_Chess.size();i++)
    {
        int X=(m_Chess[i].m_ChessPossition.y()-PAINT_Y)/Widget::height;
        int Y=(m_Chess[i].m_ChessPossition.x()-PAINT_X)/Widget::width;
        if(m_Chess[i].m_ChessColor)ExistChess[X][Y]=1;
        else ExistChess[X][Y]=2;
    }
    available a;
    ui->b_avi->setText(QString("Black_ava:%1").arg(a.ava_number(ExistChess,n_row,1)));
    ui->w_avi->setText(QString("White_ava:%1").arg(a.ava_number(ExistChess,n_row,0)));
    if(m_Chess.back().m_ChessColor)ui->label_3->setText("WHITE");
    else ui->label_3->setText("BLACK");
    DrawChesses();
}
void Widget::fx_drawChesses()
{
    if(currentIndex >= toReplay.size())
    {
        QMessageBox *inf=new QMessageBox;
        inf->information(this, "🤣", QString("已经是最后一个啦"));
        delete inf;
        return;
    }
    m_Chess+=toReplay[currentIndex];
    int X=(toReplay[currentIndex].m_ChessPossition.y()-PAINT_Y)/Widget::height;
    int Y=(toReplay[currentIndex].m_ChessPossition.x()-PAINT_X)/Widget::width;
    if(toReplay[currentIndex].m_ChessColor)ExistChess[X][Y]=1;
    else ExistChess[X][Y]=2;
    available a;
    ui->b_avi->setText(QString("Black_ava:%1").arg(a.ava_number(ExistChess,n_row,1)));
    ui->w_avi->setText(QString("White_ava:%1").arg(a.ava_number(ExistChess,n_row,0)));
    if(m_Chess.back().m_ChessColor)ui->label_3->setText("WHITE");
    else ui->label_3->setText("BLACK");
    currentIndex++;

    DrawChesses();

    if(currentIndex >= toReplay.size())
    {
        fxtimer->stop();
        disconnect(fxtimer,&QTimer::timeout,this,&Widget::fx_drawChesses);
        QMessageBox *inf=new QMessageBox;
        inf->information(this, "😊", QString("复现完成啦"));
        delete inf;
    }

}
void Widget::onPlayButtonClicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    if(!m_isReplayMode)
        return;
    fxtimer->setInterval(800);

    fxtimer->start();

}
void Widget::onPauseButtonClicked()
{
    fxtimer->stop();
}
void Widget::onNextButtonClicked()
{
    if(currentIndex >= toReplay.size())
    {
        QMessageBox *inf=new QMessageBox;
        inf->information(this, "🤣", QString("已经是最后一个啦"));
        delete inf;
        return;
    }
    //m_Chess+=toReplay[currentIndex];
    currentIndex++;
    QString text=QString::number(currentIndex);
    onInputNumFinished(text);
}
void Widget::onPreviousButtonClicked()
{
    if(currentIndex<=0)
    {
        QMessageBox *inf=new QMessageBox;
        inf->information(this, "🤣", QString("已经是第一个啦"));
        delete inf;
        return;
    }
    else if(currentIndex==1)
    {
        m_Chess.clear();
        currentIndex=0;
        ui->label_3->setText("BLACK");
        DrawChesses();
        return;
    }
    currentIndex--;
    QString text=QString::number(currentIndex);
    onInputNumFinished(text);
}
void Widget::onReplayToStepButtonClicked()
{
    InputDialog* inputDialog1 = new InputDialog(this);
    connect(inputDialog1,&InputDialog::inputFinished,this,&Widget::onInputNumFinished);
    inputDialog1->show();
}
void Widget::onExitReplayButtonClicked()
{
    fxtimer->stop();
    m_Chess.clear();
    toReplay.clear();
    m_isBlackTurn=1;
    m_isReplayMode=false;
    m_isTryMode=false;
    ui->label_3->setText("BLACK");
    for(int i=0;i<13;i++)for(int j=0;j<13;j++)ExistChess[i][j]=0;
    ui->b_avi->setText(QString("Black_ava:81"));
    ui->w_avi->setText(QString("White_ava:81"));
    m_isReplayMode = false;
    rpbtn->setDisabled(true);
    prebtn->setDisabled(true);
    psbtn->setDisabled(true);
    etbtn->setDisabled(true);
    ntbtn->setDisabled(true);
    r2sbtn->setDisabled(true);
    fxbtn->setEnabled(true);
    new_try_btn->setEnabled(false);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
}
void Widget::getCY()
{
    for (int i = 0; i<m_Chess.size(); i++)
    {
        chesspo[i].x=(m_Chess[i].m_ChessPossition.rx()-PAINT_X)/Widget::width+1;
        chesspo[i].y=(m_Chess[i].m_ChessPossition.ry()-PAINT_Y)/Widget::height+1;
        chesspo[i].c_y=num2char[chesspo[i].y];
        //qDebug()<<chesspo[i].x<<","<<chesspo[i].y<<"."<<chesspo[i].c_y;
    }
}
void Widget::mousePressEvent(QMouseEvent * e) //鼠标按下事件
{
    if(if_netmode&&!m_isTryMode)
    {
        if(flag_start!=1)return;
        if(is_client&&client_color_white&&m_isBlackTurn)return;
        if(is_client&&!client_color_white&&!m_isBlackTurn)return;
        if(!is_client&&server_color_black&&!m_isBlackTurn)return;
        if(!is_client&&!server_color_black&&m_isBlackTurn)return;
    }
    if(m_isReplayMode)return;
    if(ui->label_3->text()=="BLACK")m_isBlackTurn=1;
    else m_isBlackTurn=0;
    //求鼠标点击处的棋子点pt↓
    QPoint pt;
    int x=e->pos().x() ;
    int y=e->pos().y();
    //如果鼠标不是在棋盘区域按下,则放弃
    {
    if (x<30+PAINT_X || x>50*n_row+20+PAINT_X || y<30+PAINT_Y || y>50*n_row+20+PAINT_Y )
        return;
    }
    //判定鼠标的位置更接近哪一个座标点, 将该座标点作为要下棋子的点
    {
    if ((x-PAINT_X)%Widget::width<=Widget::width/2)
        pt.setX( PAINT_X+((x-PAINT_X) / Widget::width)*Widget::width-20);
    else
        pt.setX( PAINT_X+((x-PAINT_X) / Widget::width+1)*Widget::width-20);

    if ((y-PAINT_Y)%Widget::height<=Widget::height/2)
        pt.setY( PAINT_Y+((y-PAINT_Y) / Widget::height)*Widget::height-20);
    else
        pt.setY( PAINT_Y+((y-PAINT_Y) / Widget::height+1)*Widget::height-20);
    }
    int X=(pt.y()-PAINT_Y)/Widget::height;
    int Y=(pt.x()-PAINT_X)/Widget::width;
    //如果已存在棋子，就什么也不做
    for (int i = 0; i<m_Chess.size(); i++) //遍历已下棋子的座标，判定是否已存在棋子
    {
        Chess chess;
        chess.m_ChessColor=m_Chess[i].m_ChessColor;
        chess.m_ChessPossition=m_Chess[i].m_ChessPossition;
        //不知道为什么不能拷贝构造。。。。。
        //知道了，应该是QObject的原因，我把它注释掉了
        //Chess chess1=m_Chess[i];//err0r;
        if (chess.m_ChessPossition == pt) //判定是否已存在棋子
        {
            return;
        }
    }
    //如果不存在棋子，则先判断这一步是否合法，如果合法，则构造一个棋子
    if(m_isBlackTurn){ExistChess[X][Y]=1;}
    if(!m_isBlackTurn){ExistChess[X][Y]=2;}
    //判断合法前，先假设点击的位置已经下了棋子，如果不合法，则将数组中对应元素重置为0
    Rules r;
    if(!r.Rules::illegal_operation_judging(ExistChess,n_row,X,Y))
    {
        ExistChess[X][Y]=0;
        QMessageBox *warning1=new QMessageBox;
        warning1->information(this, "Warning", QString("Illegal operation. Please try again."));
        return;
    }
    if(m_isBlackTurn){ui->label_3->setText("WHITE");}
    if(!m_isBlackTurn){ui->label_3->setText("BLACK");}
    Chess chess_to_set(pt,m_isBlackTurn);
    if(!m_isReplayMode&&!m_isTryMode)
    {
        pTimer->stop();//计时器重新开始计时
        this->baseTime=this->baseTime.currentTime();
        pTimer->start(1);
    }
    if(if_netmode)
    {
        if(is_client){
            if(m_isBlackTurn^client_color_white){
                QString st;
                std::string s;
                s=X+'A';
                st=QString::fromStdString(s);
                this->socket->send(NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(st).arg(Y+1),""));//客户端传下的棋子过去
            }
        }
        if(is_server){
            if(m_isBlackTurn==server_color_black){
                QString st;
                std::string s;
                s=X+'A';
                st=QString::fromStdString(s);
                if(lastOne)
                    this->server->send(lastOne,NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(st).arg(Y+1),""));
            }
        }
    }
    if(m_isBlackTurn)//这个设计的是下一次棋子就改变一下颜色
    {
        m_isBlackTurn=0;
        ExistChess[X][Y]=1;
    }
    else
    {
        m_isBlackTurn=1;
        ExistChess[X][Y]=2;
    }
    m_Chess+=chess_to_set;//添加到已下棋子容器中
    available a;
    ui->b_avi->setText(QString("Black_ava:%1").arg(a.ava_number(ExistChess,n_row,1)));
    ui->w_avi->setText(QString("White_ava:%1").arg(a.ava_number(ExistChess,n_row,0)));
    step++;
    if(n_row==9)Go();
}

void Widget::DrawChess(int X,int Y)
{
    QPoint pt;
    pt.setY(X*Widget::height+PAINT_Y+30);
    pt.setX(Y*Widget::width+PAINT_X+30);
    Chess chess_to_set(pt,m_isBlackTurn);
    if(m_isBlackTurn)//这个设计的是下一次棋子就改变一下颜色
    {
        m_isBlackTurn=0;
        ExistChess[X][Y]=1;
        ui->label_3->setText("WHITE");
    }
    else
    {
        m_isBlackTurn=1;
        ExistChess[X][Y]=2;
        ui->label_3->setText("BLACK");
    }
    m_Chess+=chess_to_set;//添加到已下棋子容器中
    step++;
    Rules r;
    if(!r.illegal_operation_judging(ExistChess,n_row,X,Y))
    {
        pTimer->stop();
        fail_state=1;
        QString content=QString("suicide");
        //按顺序获取已下棋子的坐标
        if(n_row==9)getCY();
        if(!Widget::m_isBlackTurn){
                step++;
                if(!client_color_white){
                if(is_server){
                    twice=1;
                    if(lastOne)this->server->send(lastOne,NetworkData(OPCODE::SUICIDE_END_OP,"SUICIDE_END_OP",""));
                    else;
                }
                QString strr=" (BLACK) LOSE!\nTotal Steps: ";
                QString message=QString("%1 %2 %3").arg(clientName).arg(strr).arg(step);
                QMessageBox TLEbox(QMessageBox::Information,content,
                                   message,
                                   QMessageBox::Close,this);

                QAbstractButton* save_button=TLEbox.addButton("Save",QMessageBox::YesRole);

                connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);

                TLEbox.exec();
                }
                else{
                if(is_client){
                    twice=1;
                    this->socket->send(NetworkData(OPCODE::SUICIDE_END_OP,"SUICIDE_END_OP",""));
                }
                QString strr=" (BLACK) LOSE!\nTotal Steps: ";
                QString message=QString("%1 %2 %3").arg(serverName).arg(strr).arg(step);
                QMessageBox TLEbox(QMessageBox::Information,content,
                                   message,
                                   QMessageBox::Close,this);

                QAbstractButton* save_button=TLEbox.addButton("Save",QMessageBox::YesRole);

                connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);

                TLEbox.exec();
                }
                step=0;
        }
        else {
                step++;
                if(!client_color_white){
                if(is_client){
                    twice=1;
                    this->socket->send(NetworkData(OPCODE::SUICIDE_END_OP,"SUICIDE_END_OP",""));
                }
                QString strr=" (White) LOSE!\nTotal Steps: ";
                QString message=QString("%1 %2 %3").arg(serverName).arg(strr).arg(step);
                QMessageBox TLEbox(QMessageBox::Information,content,
                                   message,
                                   QMessageBox::Close,this);

                QAbstractButton* save_button=TLEbox.addButton("Save",QMessageBox::YesRole);

                connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);

                TLEbox.exec();
                }
                else{
                if(is_server){
                    twice=1;
                    if(lastOne)this->server->send(lastOne,NetworkData(OPCODE::SUICIDE_END_OP,"SUICIDE_END_OP",""));
                    else;
                }
                QString strr=" (White) LOSE!\nTotal Steps: ";
                QString message=QString("%1 %2 %3").arg(clientName).arg(strr).arg(step);
                QMessageBox TLEbox(QMessageBox::Information,content,
                                   message,
                                   QMessageBox::Close,this);

                QAbstractButton* save_button=TLEbox.addButton("Save",QMessageBox::YesRole);

                connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);

                TLEbox.exec();
                }
                step=0;
        }
        restart();
        return;
    }
    pTimer->stop();//计时器重新开始计时
    this->baseTime=this->baseTime.currentTime();
    pTimer->start(1);
    available a;
    ui->b_avi->setText(QString("Black_ava:%1").arg(a.ava_number(ExistChess,n_row,1)));
    ui->w_avi->setText(QString("White_ava:%1").arg(a.ava_number(ExistChess,n_row,0)));

}

void Widget::init()//游戏开局时初始化：设置每步限时，初始化计时器
{
    if(!if_netmode)
    {
        ui->serverGet->setEnabled(false);
        ui->serverGetEdit->setEnabled(false);
        ui->serverSend->setEnabled(false);
        ui->serverSendEdit->setEnabled(false);
        ui->getButton_2->setEnabled(false);
        ui->serverSendButton->setEnabled(false);
        ui->SLEAVE_OP->setEnabled(false);
        ui->SREADY_OP->setEnabled(false);
        ui->SREJECT_OP->setEnabled(false);
        ui->ServerGiveup_2->setEnabled(false);
        ui->reStartButton->setEnabled(false);//
        ui->clientGet->setEnabled(false);
        ui->clientGetEdit->setEnabled(false);
        ui->clientSend->setEnabled(false);
        ui->clientSendEdit->setEnabled(false);
        ui->getButton_1->setEnabled(false);
        ui->clientSendButton->setEnabled(false);
        ui->CLEAVE_OP->setEnabled(false);
        ui->CREADY_OP->setEnabled(false);
        ui->CREJECT_OP->setEnabled(false);
        ui->CilentGiveup->setEnabled(false);
        ui->reConnectButton->setEnabled(false);
        ui->reSetButton->setEnabled(false);
        ui->showClientButton->setEnabled(false);
        ui->IPEdit->setEnabled(false);
        ui->PORTEdit->setEnabled(false);
    }
    else ui->local_giveup->setEnabled(false);
    for(int i=0;i<13;i++)for(int j=0;j<13;j++)ExistChess[i][j]=0;
    m_Chess.clear();
    flag_start=0;
    twice=0;
    bool ok=false;
    QString dlgTitle="Timelimit Setting";
    QString txtLabel="Please enter the timelimit of each step(an integer).";
    int timelimit=QInputDialog::getInt(this,dlgTitle,txtLabel,30,10,3600,1,&ok);
    if(ok)
    {
        TIMELIMIT=timelimit;
    }
    this->pTimer=new QTimer;
    connect(this->pTimer,SIGNAL(timeout()),this,SLOT(updatedisplay()));
    QString min_str=QString::number(TIMELIMIT/60);
    QString minstr=QString("%2").arg(min_str.toInt(), 2, 10, QLatin1Char('0'));
    QString sec_str=QString::number(TIMELIMIT%60);
    QString secstr=QString("%2").arg(sec_str.toInt(), 2, 10, QLatin1Char('0'));
    this->ui->lcd_min->display(minstr);
    this->ui->lcd_sec->display(secstr);
    ui->label_3->setText("BLACK");
    ui->b_avi->setText(QString("Black_ava:%1").arg(n_row*n_row));
    ui->w_avi->setText(QString("White_ava:%1").arg(n_row*n_row));
}
void Widget::updatedisplay()//实时更新计时器
{
    {
        if(n_row==9)fxbtn->setEnabled(false);
        QTime curTime=QTime::currentTime();
        int t=this->baseTime.msecsTo(curTime);
        QTime showTime(0,0,0,0);
        showTime=showTime.addMSecs(t);
        int sec=(1000*TIMELIMIT-t)/1000;
        if(t<=1000*TIMELIMIT)
        {
            QString min_str=QString::number(sec/60);
            QString minstr=QString("%2").arg(min_str.toInt(), 2, 10, QLatin1Char('0'));
            QString sec_str=QString::number(sec%60);
            QString secstr=QString("%2").arg(sec_str.toInt(), 2, 10, QLatin1Char('0'));
            this->ui->lcd_min->display(minstr);
            this->ui->lcd_sec->display(secstr);
            if(n_row==9)
            {
                if(m_isBlackTurn)
                {
                    ui->label_3->setText("BLACK");
                }
                if(!m_isBlackTurn)
                {
                    ui->label_3->setText("WHITE");
                }
            }

        }
        else
        {
            QString content=QString("Time limit exceed");
            pTimer->stop();
            fail_state=1;           
            //按顺序获取已下棋子的坐标
            if(n_row==9)getCY();
            if(Widget::m_isBlackTurn){
                step++;
                if(!client_color_white){
                if(is_server){
                    twice=1;
                    if(lastOne)this->server->send(lastOne,NetworkData(OPCODE::TIMEOUT_END_OP,"TIMEOUT_END_OP",""));
                }
                QString strr=" (BLACK) LOSE!\nTotal Steps: ";
                QString message=QString("%1 %2 %3").arg(clientName).arg(strr).arg(step);
                QMessageBox TLEbox(QMessageBox::Information,content,
                                   message,
                                   QMessageBox::Close,this);
                if(n_row==9)
                {
                    QAbstractButton* save_button=TLEbox.addButton("Save",QMessageBox::YesRole);
                    connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);
                }

                TLEbox.exec();
                }
                else{
                if(is_client){
                    twice=1;
                    this->socket->send(NetworkData(OPCODE::TIMEOUT_END_OP,"TIMEOUT_END_OP",""));
                }
                QString strr=" (BLACK) LOSE!\nTotal Steps: ";
                QString message=QString("%1 %2 %3").arg(serverName).arg(strr).arg(step);
                QMessageBox TLEbox(QMessageBox::Information,content,
                                   message,
                                   QMessageBox::Close,this);
                if(n_row==9)
                {
                    QAbstractButton* save_button=TLEbox.addButton("Save",QMessageBox::YesRole);
                    connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);
                }
                TLEbox.exec();
                }
                step=0;
            }
            else {
                step++;
                if(!client_color_white){
                if(is_client){
                    twice=1;
                    this->socket->send(NetworkData(OPCODE::TIMEOUT_END_OP,"TIMEOUT_END_OP",""));
                }
                QString strr=" (White) LOSE!\nTotal Steps: ";
                QString message=QString("%1 %2 %3").arg(serverName).arg(strr).arg(step);
                QMessageBox TLEbox(QMessageBox::Information,content,
                                   message,
                                   QMessageBox::Close,this);
                if(n_row==9)
                {
                    QAbstractButton* save_button=TLEbox.addButton("Save",QMessageBox::YesRole);
                    connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);
                }
                TLEbox.exec();
                }
                else{
                if(is_server){
                    twice=1;
                    if(lastOne)this->server->send(lastOne,NetworkData(OPCODE::TIMEOUT_END_OP,"TIMEOUT_END_OP",""));
                }
                QString strr=" (White) LOSE!\nTotal Steps: ";
                QString message=QString("%1 %2 %3").arg(clientName).arg(strr).arg(step);
                QMessageBox TLEbox(QMessageBox::Information,content,
                                   message,
                                   QMessageBox::Close,this);
                if(n_row==9)
                {
                    QAbstractButton* save_button=TLEbox.addButton("Save",QMessageBox::YesRole);
                    connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);
                }
                TLEbox.exec();
                }
                step=0;
            }
            restart();

         }
    }
}
void Widget::on_saveButton_clicked()
{
        // 弹出一个对话框，让用户选择文件保存的目录
        QString dir = QFileDialog::getExistingDirectory(this, tr("选择文件保存目录"), QDir::homePath());

        // 如果用户取消选择，返回
        if (dir.isEmpty())
            return;
    
        // 生成一个当前时间的字符串
        QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
        // 将当前时间的字符串添加到文件名中
        QString fileName = QString("save_%1.txt").arg(timestamp);
        // 将选定的目录与文件名结合起来形成完整的文件路径
        QString filePath = dir + "/" + fileName;

        // 创建一个新文件
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        // 创建一个QTextEdit对象textEdit
        QTextEdit *textEdit = new QTextEdit(this);
        //获得save内容
        if(n_row==9)getCY();
        for (int i = 0; i < m_Chess.size(); ++i)
        {
            textEdit->insertPlainText(chesspo[i].c_y+QString::number(chesspo[i].x)+" ");
        }
        //结尾标识结束状态
        if(fail_state==1)
            textEdit->insertPlainText("T");
        else textEdit->insertPlainText("G");
        // 使用QTextStream类将textEdit写入新文件
        QTextStream out(&file);
        out << textEdit->toPlainText().trimmed().toUtf8();
        file.close();
}

void Widget::give_up_clicked()//当按下认输按钮
{
    pTimer->stop();
    
    fail_state=2;
    //按顺序获取已下棋子的坐标
    if(n_row==9)getCY();
    
    if(Widget::m_isBlackTurn){
        step++;
        if(!client_color_white){
        
            QString strr=" (BLACK) LOSE!\nTotal Steps: ";
            QString message=QString("%1 %2 %3").arg(clientName).arg(strr).arg(step);
            QMessageBox GIVEUPbox(QMessageBox::Information,"Game Over",
                           message,
                           QMessageBox::Close,this);
            QAbstractButton* save_button=GIVEUPbox.addButton("Save",QMessageBox::YesRole);

            connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);

            GIVEUPbox.exec();     
        }
        else{
            QString strr=" (BLACK) LOSE!\nTotal Steps: ";
            QString message=QString("%1 %2 %3").arg(serverName).arg(strr).arg(step);
            QMessageBox GIVEUPbox(QMessageBox::Information,"Game Over",
                           message,
                           QMessageBox::Close,this);
            QAbstractButton* save_button=GIVEUPbox.addButton("Save",QMessageBox::YesRole);

            connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);

            GIVEUPbox.exec();   
        }
        step=0;
    }
    else {
        step++;
        if(!client_color_white){
            QString strr=" (White) LOSE!\nTotal Steps: ";
            QString message=QString("%1 %2 %3").arg(serverName).arg(strr).arg(step);
            
            QMessageBox GIVEUPbox(QMessageBox::Information,"Game Over",
                           message,
                           QMessageBox::Close,this);
            QAbstractButton* save_button=GIVEUPbox.addButton("Save",QMessageBox::YesRole);

            connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);

            GIVEUPbox.exec();   
        }
        else{
            QString strr=" (White) LOSE!\nTotal Steps: ";
            QString message=QString("%1 %2 %3").arg(clientName).arg(strr).arg(step);
            QMessageBox GIVEUPbox(QMessageBox::Information,"Game Over",
                           message,
                           QMessageBox::Close,this);
            QAbstractButton* save_button=GIVEUPbox.addButton("Save",QMessageBox::YesRole);

            connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);

            GIVEUPbox.exec();   
        }
        step=0;
    }
    restart();
}
void Widget::local_giveup()
{
    pTimer->stop();
    fail_state=2;
    if(Widget::m_isBlackTurn){
        step++;
        QString strr=" (Black) LOSE!\nTotal Steps: ";
        QString message=QString("%1 %2 %3").arg(clientName).arg(strr).arg(step);
        QMessageBox GIVEUPbox(QMessageBox::Information,"Game Over",
                              message,
                              QMessageBox::Close,this);
        if(n_row==9)
        {
            QAbstractButton* save_button=GIVEUPbox.addButton("Save",QMessageBox::YesRole);
            connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);
        }

        GIVEUPbox.exec();
        step=0;
    }
    else {
        step++;
        QString strr=" (White) LOSE!\nTotal Steps: ";
        QString message=QString("%1 %2 %3").arg(clientName).arg(strr).arg(step);
        QMessageBox GIVEUPbox(QMessageBox::Information,"Game Over",
                              message,
                              QMessageBox::Close,this);
        if(n_row==9)
        {
            QAbstractButton* save_button=GIVEUPbox.addButton("Save",QMessageBox::YesRole);
            connect(save_button, &QAbstractButton::clicked, this, &Widget::on_saveButton_clicked);
        }

        GIVEUPbox.exec();
        step=0;
    }
    restart();
}
void Widget::restart()//游戏重开
{
    if(n_row==9)fxbtn->setEnabled(true);
    pTimer->stop();
    m_Chess.clear();
    m_isBlackTurn=1;
    client_color_white=false;
    server_color_black=false;
    ui->label_3->setText("BLACK");
    step=0;
    Widget::init();
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<13;j++)
        {
            ExistChess[i][j]=0;
        }
    }
}

void Widget::on_pushButton_2_clicked()
{
    AI_is_Awake=true;
    Go();
}


void Widget::on_pushButton_clicked()
{
    AI_is_Awake=false;
}

