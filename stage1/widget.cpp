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
int TIMELIMIT=10;
int step=0;
Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::Widget)//初始化ui界面
{
    #define PAINT_X 114
    #define PAINT_Y 51
    setFixedSize(1070,700);
    setWindowTitle("NoGo_group5");
    ui->setupUi(this);

    //设置窗口大小和标题
    this->init();
    m_isBlackTurn = true;//黑子先行

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
    }
}
void Widget::mousePressEvent(QMouseEvent * e) //鼠标按下事件
{
    /*QSoundEffect effect;
    effect.setSource(QUrl::fromLocalFile(":/images/open_win.wav"));
    effect.setLoopCount(1);
    effect.setVolume(1.0);
    effect.play();*/
    //暂时删除的游戏音效↑
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
void Widget::if_scanned_init()//在递归回溯时记录已经判断过的棋子，避免造成死循环
{
    for(int i1=0;i1<9;i1++)for(int j1=0;j1<9;j1++)if_scanned[i1][j1]=0;
}
void Widget::init()//游戏开局时初始化：设置每步限时，初始化计时器
{

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
            dialog1->information(this, content, QString("    BLACK LOSE!    \n    Total Steps: %1    ").arg(step) );
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
Widget::~Widget()//析构函数
{
    delete ui;
}
void Widget::on_pushButton_clicked()//当按下认输按钮
{
     pTimer->stop();
    if(Widget::m_isBlackTurn){
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
    Widget::init();
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            ExistChess[i][j]=0;
        }
    }
}
