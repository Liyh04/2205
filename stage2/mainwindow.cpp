#include "Widget.h"
#include "ui_Widget.h"
#include "networkdata.h"
#include <QPushButton>
#include <QDebug>
#include"networksocket.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 本地 IP，所有电脑都可以用这个 IP 指向自己
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

    connect(this->socket->base(),&QTcpSocket::connected,this,[&](){this->ui->connectLabel->setText("connection succeed");});
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

Widget::~Widget()
{
    delete ui;
}

void Widget::receieveData(QTcpSocket* client, NetworkData data)
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
    if(data.data2=='w'){
        flag_color=1;
    }//如果客户端请求白棋
    if(data.data2=='b'){
        flag_color=2;
    }//如果客户端请求黑棋
}

void Widget::receieveDataFromServer(NetworkData data)
{
    qDebug()<<"Client get a data: "<<data.encode();
    this->ui->clientGetEdit->setText(data.data1);
    this->ui->clientGet->setText(data.data2);
}

void Widget::onClientSendButtonClicked()
{
    this->socket->send(NetworkData(OPCODE::CHAT_OP,this->ui->clientSendEdit->text(),this->ui->clientSend->text()));//有点问题

    //this->socket->send(NetworkData(OPCODE::CHAT_OP,this->ui->clientSend->text(),"send by client"));//有点问题
}


void Widget::onServerSendButtonClicked()
{
    if(lastOne)
        this->server->send(lastOne,NetworkData(OPCODE::CHAT_OP,this->ui->serverSendEdit->text(),this->ui->ServerSend->text()));
    //if(lastOne)
       // this->server->send(lastOne,NetworkData(OPCODE::CHAT_OP,this->ui->ServerSend->text(),"send by server"));
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
    this->socket->send(NetworkData(OPCODE::READY_OP,this->ui->clientSendEdit->text(),this->ui->clientSend->text()));
    //receive处的data2对应客户端棋子的颜色另一个则为服务端棋子的颜色
}

void Widget::on_SREADY_OP_clicked()//服务端同意
{
    this->socket->send(NetworkData(OPCODE::READY_OP,this->ui->clientSendEdit->text(),this->ui->clientSend->text()));
    flag_start=1;//游戏可以开始
}
void Widget::on_SREJECT_OP_clicked()//客户端拒绝
{
    this->socket->send(NetworkData(OPCODE::READY_OP,this->ui->clientSendEdit->text(),this->ui->clientSend->text()));
    flag_start=-1;//游戏不能开始
}
void Widget::on_CREJECT_OP_clicked(){}//多余的但是不能删除

void Widget::on_CilentGiveup_clicked()//客户端投降
{
    if(flag_color==1){//客户端白棋

    }
    if(flag_color==2){//客户端黑棋

    }
}


void Widget::on_ServerGiveup_2_clicked()//服务端投降
{
    if(flag_color==1){//服务端黑棋

    }
    if(flag_color==2){//服务端白棋

    }
}



void Widget::on_CLEAVE_OP_clicked()
{
    this->socket->send(NetworkData(OPCODE::LEAVE_OP,"LEAVEOP",""));
    socket->bye();
}


void Widget::on_SLEAVE_OP_clicked()
{
    this->socket->send(NetworkData(OPCODE::LEAVE_OP,"LEAVEOP",""));

}

