
#include "paint.h"

paint::paint()
{

}
void paint::paintEvent(QPaintEvent *)
{
    DrawChessboard();        //画棋盘
    update();//实时更新
}
void paint::DrawChessboard()
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

