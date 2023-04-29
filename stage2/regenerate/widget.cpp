
#include "widget.h"
#include "chess.h"
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
    Chess::m_Chess.clear();
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
