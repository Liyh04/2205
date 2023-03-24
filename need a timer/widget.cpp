#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <chess.h>
#include <QDebug>
#include<QHBoxLayout>//垂直布局
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
#include <QMessageBox>
#define TIMELIMIT 10

Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::Widget)
{
    #define PAINT_X 114
    #define PAINT_Y 51
    setFixedSize(1000,700);
    setWindowTitle("NoGo_group5");
    ui->setupUi(this);
    //设置窗口大小和标题
    this->init();
    m_isBlackTurn = true;//黑子先行
}
void Widget::paintEvent(QPaintEvent *)
{
    DrawChessboard();        //画棋盘
    DrawChesses();            //画棋子
    update();//实时更新
}
void Widget::DrawChessboard()
{
    //设置画家
    QPainter painter_Yujx_board(this);
    //图片-棋盘
    QPixmap pix_chessmap;
    pix_chessmap.load(":/images/qipan.jpg");
    //改变大小，500*500
    pix_chessmap=pix_chessmap.scaled(500,500,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //画图
    painter_Yujx_board.drawPixmap(PAINT_X,PAINT_Y,pix_chessmap);
}
void Widget::DrawChesses()
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
    }
}
void Widget::mousePressEvent(QMouseEvent * e) //鼠标按下事件
{

    //求鼠标点击处的棋子点pt
    QPoint pt;
    int x=e->pos().x() ;
    int y=e->pos().y();

    //如果鼠标不是在棋盘区域按下,则放弃
    if (x<30+PAINT_X || x>470+PAINT_X || y<30+PAINT_Y || y>470+PAINT_Y )
        return;

    //判定鼠标的位置更接近哪一个座标点, 将该座标点作为要下棋子的点
    if ((x-PAINT_X)%Widget::width<=Widget::width/2)
        pt.setX( PAINT_X+((x-PAINT_X) / Widget::width)*Widget::width-20);
    else
        pt.setX( PAINT_X+((x-PAINT_X) / Widget::width+1)*Widget::width-20);

    if ((y-PAINT_Y)%Widget::height<=Widget::height/2)
        pt.setY( PAINT_Y+((y-PAINT_Y) / Widget::height)*Widget::height-20);
    else
        pt.setY( PAINT_Y+((y-PAINT_Y) / Widget::height+1)*Widget::height-20);


//    qDebug()<<pt.rx();
//    qDebug()<<pt.ry();

    //如果已存在棋子，就什么也不做
    for (int i = 0; i<m_Chess.size(); i++) //遍历已下棋子的座标
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

    //不存在棋子，则构造一个棋子
    Chess chess_to_set(pt,m_isBlackTurn);
    pTimer->stop();
    this->baseTime=this->baseTime.currentTime();
    pTimer->start(1);

    if(m_isBlackTurn)//这个设计的是下一次棋子就改变一下颜色
    {
        m_isBlackTurn=0;
    }
    else
    {
        m_isBlackTurn=1;
    }
    m_Chess+=chess_to_set;//添加到已下棋子容器中
}

void Widget::init()
{
    this->pTimer=new QTimer;
    connect(this->pTimer,SIGNAL(timeout()),this,SLOT(updatedisplay()));
    QString min_str=QString::number(TIMELIMIT/60);
    QString minstr=QString("%2").arg(min_str.toInt(), 2, 10, QLatin1Char('0'));
    QString sec_str=QString::number(TIMELIMIT%60);
    QString secstr=QString("%2").arg(sec_str.toInt(), 2, 10, QLatin1Char('0'));
    this->ui->lcd_min->display(minstr);
    this->ui->lcd_sec->display(secstr);
}
void Widget::updatedisplay()
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
        }
        else
        {
            //pTimer->setSingleShot(true);
            /*QObject::connect(pTimer, &QTimer::timeout, [&]() {
                QString content=QString("Time limit exceed");
                QMessageBox *dialog1=new QMessageBox;
                dialog1->resize(1000,700);
                dialog1->information(nullptr, content, "    YOU LOSE!    ");
                QString min_str=QString::number(0);
                QString minstr=QString("%2").arg(min_str.toInt(), 2, 10, QLatin1Char('0'));
                QString sec_str=QString::number(0);
                QString secstr=QString("%2").arg(sec_str.toInt(), 2, 10, QLatin1Char('0'));
                this->ui->lcd_min->display(minstr);
                this->ui->lcd_sec->display(secstr);
                pTimer->stop();
                m_Chess.clear();
                m_isBlackTurn=1;
            });*/
            QString content=QString("Time limit exceed");
            QMessageBox *dialog1=new QMessageBox;
            dialog1->resize(1000,700);
            if(Widget::m_isBlackTurn)
            dialog1->information(nullptr, content, "    BLACK LOSE!    ");
            else dialog1->information(nullptr, content, "    WHITE LOSE!    ");
            restart();
         }
    }
}

//初始化静态成员
int Widget::height=50;
int Widget::width=50;
int Widget::n_row=9;
int Widget::n_column=9;
Widget::~Widget()
{
    delete ui;
}
void Widget::on_pushButton_clicked()
{
    pTimer->stop();
    if(!Widget::m_isBlackTurn)QMessageBox::information(nullptr, "Surrender", "    BLACK LOSE!    ");
    else QMessageBox::information(nullptr, "Surrender", "    WHITE LOSE!    ");
    restart();
}
void Widget::restart(){
    pTimer->stop();
    m_Chess.clear();
    m_isBlackTurn=1;
}
