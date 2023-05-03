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
//#include <QSoundEffect>
#include <QBrush>
#include <qcolor.h>
int TIMELIMIT=30;
int step=0;
Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::Widget)//初始化ui界面
{
    #define PAINT_X 112
    #define PAINT_Y 75
    setFixedSize(1400,700);
    setWindowTitle("NoGo_group5");
    m_isBlackTurn = true;//黑子先行
    ui->setupUi(this);
    //设置窗口大小和标题
    this->init();
    IP = "127.0.0.1";
    // 端口，不要太简单，要避免和别的软件冲突
    PORT = 16667;
    this->ui->IPEdit->setText(IP);
    this->ui->PORTEdit->setText(QString::number(PORT));
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
        ui->SGG_OP->setEnabled(false);
        ui->SLEAVE_OP->setEnabled(false);
        ui->SMOVE_OP->setEnabled(false);
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
        ui->CGG_OP->setEnabled(true);
        ui->CLEAVE_OP->setEnabled(true);
        ui->CMOVE_OP->setEnabled(true);
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
    connect(this->ui->reStartButton,&QPushButton::clicked,this,&Widget::reStart);
    // 客户端向 IP:PORT 连接，不会连到自己
    this->socket->hello(IP,PORT);
    // 阻塞等待，2000ms超时
    this->socket->base()->waitForConnected(2000);


}
Widget::~Widget()//析构函数
{
    delete ui;
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
    if(data.op==OPCODE::READY_OP)
        clientName=this->ui->serverGetEdit->text();
    if(data.op==OPCODE::MOVE_OP){
        QString  qstr = data.data1;
        std::string str = qstr.toStdString();
        X_Other=str[0]-'A';
        Y_Other=str[1]-'1';
        DrawChess(X_Other,Y_Other);
       // m_isBlackTurn=!m_isBlackTurn;
    }
    if(data.op==OPCODE::GIVEUP_OP){
        if(client_color_white)
            m_isBlackTurn=0;
        else
            m_isBlackTurn=1;
        on_pushButton_clicked();
    }
    if(data.op==OPCODE::LEAVE_OP){
        pTimer->stop();
        flag_start=0;
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
        on_pushButton_clicked();
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

void Widget::reStart()
{
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
    ui->SGG_OP->setEnabled(true);
    ui->SLEAVE_OP->setEnabled(true);
    ui->SMOVE_OP->setEnabled(true);
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
    ui->CGG_OP->setEnabled(false);
    ui->CLEAVE_OP->setEnabled(false);
    ui->CMOVE_OP->setEnabled(false);
    ui->CREADY_OP->setEnabled(false);
    ui->CREJECT_OP->setEnabled(false);
    ui->CilentGiveup->setEnabled(false);
    ui->reConnectButton->setEnabled(false);//
}

void Widget::reConnect()
{
    qDebug()<<"client reconnect to the server.";
    this->ui->connectLabel->setText("connection fail");

    this->socket->bye();
    this->socket->hello(IP,PORT);
    if(!this->socket->base()->waitForConnected(3000)){
        qDebug()<<"reconnect fail";
    }
}

void Widget::reSet()
{
    this->ui->connectLabel->setText("connection fail");
    IP=this->ui->IPEdit->text();
    PORT=this->ui->PORTEdit->text().toInt();
    this->reStart();
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
    this->socket->send(NetworkData(OPCODE::GIVEUP_OP,"",""));
    if(client_color_white){
        m_isBlackTurn=0;
        on_pushButton_clicked();
    }
    else{
        m_isBlackTurn=1;
        on_pushButton_clicked();
    }

}
void Widget::on_ServerGiveup_2_clicked()//服务端投降
{
    if(lastOne)
    this->server->send(lastOne,NetworkData(OPCODE::GIVEUP_OP,"",""));
    if(!client_color_white){
        m_isBlackTurn=0;
        on_pushButton_clicked();
    }
    else{
        m_isBlackTurn=1;
        on_pushButton_clicked();
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
void Widget::paintEvent(QPaintEvent *)//画棋盘和棋子
{
    DrawChessboard();        //画棋盘
    DrawChesses();            //画棋子
    update();//实时更新
}
void Widget::DrawChessboard()//初始化棋盘
{
    //设置画家
    QPainter painter_Yujx_board(this);
    //图片-棋盘
    QPixmap pix_chessmap;
    pix_chessmap.load(":/images/qipan.jpg");
    //改变大小，500,500
    pix_chessmap=pix_chessmap.scaled(500,500,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //画图
    painter_Yujx_board.drawPixmap(PAINT_X,PAINT_Y,pix_chessmap);
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
            QColor PaleVioletRed(0xDB7093);//设置颜色--苍白的紫罗兰红色~
            QPen pen(PaleVioletRed);//定义画笔
            pen.setWidth(2);//
            // pen.setStyle(Qt::DashDotDotLine);
            painter_Yu_chess.setPen(pen);
            painter_Yu_chess.drawEllipse(chess_seted.m_ChessPossition.rx(),chess_seted.m_ChessPossition.ry(),40,40);
            // painter_Yu_chess.setBrush();
        }
    }
}
void Widget::mousePressEvent(QMouseEvent * e) //鼠标按下事件
{
    if(flag_start!=1)return;
    if(is_client&&client_color_white&&m_isBlackTurn)return;
    if(is_client&&!client_color_white&&!m_isBlackTurn)return;
    if(!is_client&&server_color_black&&!m_isBlackTurn)return;
    if(!is_client&&!server_color_black&&m_isBlackTurn)return;
    //求鼠标点击处的棋子点pt↓
    QPoint pt;
    int x=e->pos().x() ;
    int y=e->pos().y();
    //如果鼠标不是在棋盘区域按下,则放弃
    {
    if (x<30+PAINT_X || x>470+PAINT_X || y<30+PAINT_Y || y>470+PAINT_Y )
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
    Widget::if_scanned_init();
    if(m_isBlackTurn)ExistChess[X][Y]=1;
    if(!m_isBlackTurn)ExistChess[X][Y]=2;
    //判断合法前，先假设点击的位置已经下了棋子，如果不合法，则将数组中对应元素重置为0
    //以下5个if函数分别判断点击处以及上下左右五个棋子是否存活
    if(!if_legal(X,Y))
    {
        ExistChess[X][Y]=0;
        //this->ui->lcdNumber->display(3);
        QMessageBox *warning1=new QMessageBox;
        warning1->information(this, "Warning", QString("Illegal operation. Please try again."));
        return;
    }
    Widget::if_scanned_init();
    if(X>0&&!if_legal(X-1,Y))
    {
        ExistChess[X][Y]=0;
        //this->ui->lcdNumber->display(4);
        QMessageBox *warning1=new QMessageBox;
        warning1->information(this, "Warning", QString("Illegal operation. Please try again."));
        return;
    }
    Widget::if_scanned_init();
    if(X<8&&!if_legal(X+1,Y))
    {
        ExistChess[X][Y]=0;
        //this->ui->lcdNumber->display(5);
        QMessageBox *warning1=new QMessageBox;
        warning1->information(this, "Warning", QString("Illegal operation. Please try again."));
        return;
    }
    Widget::if_scanned_init();
    if(Y>0&&!if_legal(X,Y-1))
    {
        ExistChess[X][Y]=0;
        //this->ui->lcdNumber->display(6);
        QMessageBox *warning1=new QMessageBox;
        warning1->information(this, "Warning", QString("Illegal operation. Please try again."));
        return;
    }
    Widget::if_scanned_init();
    if(Y<8&&!if_legal(X,Y+1))
    {
        ExistChess[X][Y]=0;
        //this->ui->lcdNumber->display(7);
        QMessageBox *warning1=new QMessageBox;
        warning1->information(this, "Warning", QString("Illegal operation. Please try again."));
        return;
    }
    Widget::if_scanned_init();
    ExistChess[X][Y]=0;
    Widget::if_scanned_init();
    Chess chess_to_set(pt,m_isBlackTurn);
    pTimer->stop();//计时器重新开始计时
    this->baseTime=this->baseTime.currentTime();
    pTimer->start(1);
    if(is_client){
        if(m_isBlackTurn){
            if(!client_color_white){//客户端是黑
                QString st;
                std::string s;
                s=X+'A';
                st=QString::fromStdString(s);
                this->socket->send(NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(st).arg(Y+1),""));//客户端传下的棋子过去
            }
        }
        else{
            if(client_color_white){//客户端是白
                QString st;
                std::string s;
                s=X+'A';
                st=QString::fromStdString(s);
                this->socket->send(NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(st).arg(Y+1),""));
            }
        }
    }
    if(is_server){
        if(m_isBlackTurn){
            if(server_color_black){
                QString st;
                std::string s;
                s=X+'A';
                st=QString::fromStdString(s);
                if(lastOne)
                this->server->send(lastOne,NetworkData(OPCODE::MOVE_OP,QString("%1%2").arg(st).arg(Y+1),""));
            }
        }
        if(!m_isBlackTurn){
            if(!server_color_black){
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
        ExistChess[(pt.y()-PAINT_Y)/Widget::height][(pt.x()-PAINT_X)/Widget::width]=1;
        //this->ui->lcd_row->display((pt.y()-PAINT_Y)/Widget::height);
        //this->ui->lcd_coloum->display((pt.x()-PAINT_X)/Widget::width);//测试专用，显示坐标信息
    }
    else
    {
        m_isBlackTurn=1;
        ExistChess[(pt.y()-PAINT_Y)/Widget::height][(pt.x()-PAINT_X)/Widget::width]=2;
        //this->ui->lcd_row->display((pt.y()-PAINT_Y)/Widget::height);
        //this->ui->lcd_coloum->display((pt.x()-PAINT_X)/Widget::width);//测试专用，显示坐标信息
    }
    m_Chess+=chess_to_set;//添加到已下棋子容器中
    step++;

}


void Widget::DrawChess(int X,int Y)
{
    QPoint pt;
    pt.setY(X*Widget::height+PAINT_Y+30);
    pt.setX(Y*Widget::width+PAINT_X+30);


    Chess chess_to_set(pt,m_isBlackTurn);
    pTimer->stop();//计时器重新开始计时
    this->baseTime=this->baseTime.currentTime();
    pTimer->start(1);
    if(m_isBlackTurn)//这个设计的是下一次棋子就改变一下颜色
    {
        m_isBlackTurn=0;
        ExistChess[X][Y]=1;
        //this->ui->lcd_row->display((pt.y()-PAINT_Y)/Widget::height);
        //this->ui->lcd_coloum->display((pt.x()-PAINT_X)/Widget::width);//测试专用，显示坐标信息
    }
    else
    {
        m_isBlackTurn=1;
        ExistChess[X][Y]=2;
        //this->ui->lcd_row->display((pt.y()-PAINT_Y)/Widget::height);
        //this->ui->lcd_coloum->display((pt.x()-PAINT_X)/Widget::width);//测试专用，显示坐标信息
    }
    m_Chess+=chess_to_set;//添加到已下棋子容器中
    step++;


}


void Widget::if_scanned_init()//在递归回溯时记录已经判断过的棋子，避免造成死循环
{
    for(int i1=0;i1<9;i1++)for(int j1=0;j1<9;j1++)if_scanned[i1][j1]=0;
}
void Widget::init()//游戏开局时初始化：设置每步限时，初始化计时器
{

    flag_start=0;
    /*bool ok=false;
    QString dlgTitle="Timelimit Setting";
    QString txtLabel="Please enter the timelimit of each step(an integer).";
    int timelimit=QInputDialog::getInt(this,dlgTitle,txtLabel,30,10,3600,1,&ok);
    if(ok)
    {
        TIMELIMIT=timelimit;
    }*/
    this->pTimer=new QTimer;
    connect(this->pTimer,SIGNAL(timeout()),this,SLOT(updatedisplay()));
    QString min_str=QString::number(TIMELIMIT/60);
    QString minstr=QString("%2").arg(min_str.toInt(), 2, 10, QLatin1Char('0'));
    QString sec_str=QString::number(TIMELIMIT%60);
    QString secstr=QString("%2").arg(sec_str.toInt(), 2, 10, QLatin1Char('0'));
    this->ui->lcd_min->display(minstr);
    this->ui->lcd_sec->display(secstr);
    ui->label_3->setText("BLACK");
    ui->serverGet->setEnabled(false);
    ui->serverGetEdit->setEnabled(false);
    ui->serverSend->setEnabled(false);
    ui->serverSendEdit->setEnabled(false);
    ui->getButton_2->setEnabled(false);
    ui->serverSendButton->setEnabled(false);
    ui->SGG_OP->setEnabled(false);
    ui->SLEAVE_OP->setEnabled(false);
    ui->SMOVE_OP->setEnabled(false);
    ui->SREADY_OP->setEnabled(false);
    ui->SREJECT_OP->setEnabled(false);
    ui->ServerGiveup_2->setEnabled(false);
    ui->reStartButton->setEnabled(true);//
    ui->clientGet->setEnabled(false);
    ui->clientGetEdit->setEnabled(false);
    ui->clientSend->setEnabled(false);
    ui->clientSendEdit->setEnabled(false);
    ui->getButton_1->setEnabled(false);
    ui->clientSendButton->setEnabled(false);
    ui->CGG_OP->setEnabled(false);
    ui->CLEAVE_OP->setEnabled(false);
    ui->CMOVE_OP->setEnabled(false);
    ui->CREADY_OP->setEnabled(false);
    ui->CREJECT_OP->setEnabled(false);
    ui->CilentGiveup->setEnabled(false);
    ui->reConnectButton->setEnabled(true);//

}
void Widget::updatedisplay()//实时更新计时器
{
    {
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

            if(m_isBlackTurn)
            {
                //ui->player->display("BLACK");

                ui->label_3->setText("BLACK");
            }
            if(!m_isBlackTurn)
            {
                //ui->player->display("WHITE");

                ui->label_3->setText("WHITE");
            }
        }
        else
        {

            QString content=QString("Time limit exceed");
            QMessageBox *dialog1=new QMessageBox;
            dialog1->resize(1000,700);
            if(Widget::m_isBlackTurn)
            dialog1->information(this, content, QString("    BLACK LOSE!    \n    Total Steps: %1   ").arg(step) );
            else dialog1->information(this, content, QString("    WHITE LOSE!    \n    Total Steps: %1    ").arg(step));
            restart();
         }
    }
}
//初始化静态成员
int Widget::height=50;
int Widget::width=50;
int Widget::n_row=9;
int Widget::n_column=9;

void Widget::on_pushButton_clicked()//当按下认输按钮
{
     pTimer->stop();
    if(Widget::m_isBlackTurn){
        step++;
        if(!client_color_white){
            QString strr=" (BLACK) LOSE!\nTotal Steps: ";
            QString message=QString("%1 %2 %3").arg(clientName).arg(strr).arg(step);
            QMessageBox::information(this, "Game Over", message );
        }
        else{
            QString strr=" (BLACK) LOSE!\nTotal Steps: ";
            QString message=QString("%1 %2 %3").arg(serverName).arg(strr).arg(step);
            QMessageBox::information(this, "Game Over", message );
        }
        step=0;
    }
    else {
        step++;
        if(!client_color_white){
            QString strr=" (White) LOSE!\nTotal Steps: ";
            QString message=QString("%1 %2 %3").arg(serverName).arg(strr).arg(step);
            QMessageBox::information(this, "Game Over", message );
        }
        else{
            QString strr=" (White) LOSE!\nTotal Steps: ";
            QString message=QString("%1 %2 %3").arg(clientName).arg(strr).arg(step);
            QMessageBox::information(this, "Game Over", message );
        }
        step=0;
    }
    restart();
}
void Widget::restart()//游戏重开
{
    pTimer->stop();
    m_Chess.clear();
    m_isBlackTurn=1;
    client_color_white=false;
    server_color_black=false;
    ui->label_3->setText("BLACK");
    step=0;
    Widget::init();
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            ExistChess[i][j]=0;
        }
    }
}

