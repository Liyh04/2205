#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QMouseEvent>
#include <chess.h>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置窗口大小和标题
    setFixedSize(650,500);
    setWindowTitle("NoGo_group5");

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
    //设置画家——我o(*￣▽￣*)ブ
    QPainter painter_Yujx_board(this);

    //图片-棋盘
    QPixmap pix_chessmap;
    pix_chessmap.load(":/images/qipan.jpg");

    //改变大小，500*500
    pix_chessmap=pix_chessmap.scaled(500,500,Qt::KeepAspectRatio);

    //画图
    painter_Yujx_board.drawPixmap(0,0,pix_chessmap);
}
void Widget::DrawChesses()
{
    //设置画家——还是我o(*￣▽￣*)ブ
    QPainter painter_Yu_chess(this);

    //图片-白子和黑子
    QPixmap pix_chessmap_White;
    pix_chessmap_White.load(":/images/white.png");

    QPixmap pix_chessmap_Black;
    pix_chessmap_Black.load(":/images/black.png");
    //改变大小，40*40
    pix_chessmap_Black=pix_chessmap_Black.scaled(40,40,Qt::KeepAspectRatio);
    pix_chessmap_White=pix_chessmap_White.scaled(40,40,Qt::KeepAspectRatio);




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
    if (x<30 || x>480 || y<30 || y>480 )
        return;

    //判定鼠标的位置更接近哪一个座标点, 将该座标点作为要下棋子的点
    if (x%Widget::width<=Widget::width/2)
        pt.setX( (x / Widget::width)*Widget::width-20);
    else
        pt.setX( (x / Widget::width+1)*Widget::width-20);

    if (y%Widget::height<=Widget::height/2)
        pt.setY( (y / Widget::height)*Widget::height-20);
    else
        pt.setY( (y / Widget::height+1)*Widget::height-20);


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
//初始化静态成员
int Widget::height=50;
int Widget::width=50;
int Widget::n_row=9;
int Widget::n_column=9;

Widget::~Widget()
{
    delete ui;
}

