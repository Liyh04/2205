
#include "widget.h"
#include "chess.h"
#include"paint.h"
#include"rules.h"
#include"timer.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::Widget)//初始化ui界面
{

    setFixedSize(1070,700);
    setWindowTitle("NoGo_group5");
    ui->setupUi(this);

    //设置窗口大小和标题
    this->init();
    m_isBlackTurn = true;//黑子先行



}
Widget::~Widget()//析构函数
{
    delete ui;
}
void Widget::on_pushButton_clicked()//当按下认输按钮
{
    pTimer->stop();
    if(m_isBlackTurn){
        step++;
        QMessageBox::information(this, "Game Over", QString("BLACK LOSE!\nTotal Steps: %1").arg(step) );
        step=0;
    }
    else {
        step++;
        QMessageBox::information(this, "Game Over", QString("WHITE LOSE!\nTotal Steps: %1").arg(step) );
        step=0;
    }
    restart();
}
void Widget::restart()//游戏重开
{
    pTimer->stop();
    m_Chess.clear();
    m_isBlackTurn=1;
    ui->label_3->setText("BLACK");
    step=0;
    init();
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            ExistChess[i][j]=0;
        }
    }
}
void Widget::mousePressEvent(QMouseEvent * e)
{
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
        if ((x-PAINT_X)%width<=width/2)
            pt.setX( PAINT_X+((x-PAINT_X) / width)*width-20);
        else
            pt.setX( PAINT_X+((x-PAINT_X) / width+1)*width-20);

        if ((y-PAINT_Y)%height<=height/2)
            pt.setY( PAINT_Y+((y-PAINT_Y) / height)*height-20);
        else
            pt.setY( PAINT_Y+((y-PAINT_Y) / height+1)*height-20);
    }
    int X=(pt.y()-PAINT_Y)/height;
    int Y=(pt.x()-PAINT_X)/width;
    int I=(pt.y()-PAINT_Y)/height;
    int J=(pt.x()-PAINT_X)/width;
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
    if(ExistChess[I][J])return;
    class rules r;
    if(!r.illegal_warning(X,Y))
    {
        Chess chess_to_set(pt,m_isBlackTurn);
        pTimer->stop();//计时器重新开始计时
        baseTime=baseTime.currentTime();
        pTimer->start(1);
        if(m_isBlackTurn)//这个设计的是下一次棋子就改变一下颜色
        {
            m_isBlackTurn=0;
            ExistChess[I][J]=1;

        }
        else
        {
            m_isBlackTurn=1;
            ExistChess[I][J]=2;

        }
        m_Chess+=chess_to_set;//添加到已下棋子容器中
        //m_Chess.push_back(chess_to_set);
        //m_Chess[9*I+J]=chess_to_set;
        step++;
    }
    //如果不存在棋子，则先判断这一步是否合法，如果合法，则构造一个棋子

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
        Chess chess_seted (m_Chess[i].m_ChessPossition,m_Chess[i].m_ChessColor);//拷贝构造

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
void Widget::init()//游戏开局时初始化：设置每步限时，初始化计时器
{

    TIMELIMIT=10;
    step=0;
    bool ok=false;
    QString dlgTitle="Timelimit Setting";
    QString txtLabel="Please enter the timelimit of each step(an integer).";
    int timelimit=QInputDialog::getInt(this,dlgTitle,txtLabel,30,10,3600,1,&ok);
    if(ok)
    {
        TIMELIMIT=timelimit;
    }
    pTimer=new QTimer;
    connect(pTimer,SIGNAL(timeout()),this,SLOT(updatedisplay()));
    QString min_str=QString::number(TIMELIMIT/60);
    QString minstr=QString("%2").arg(min_str.toInt(), 2, 10, QLatin1Char('0'));
    QString sec_str=QString::number(TIMELIMIT%60);
    QString secstr=QString("%2").arg(sec_str.toInt(), 2, 10, QLatin1Char('0'));
    this->ui->lcd_min->display(minstr);
    this->ui->lcd_sec->display(secstr);
    ui->label_3->setText("BLACK");
}
