#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <chess.h>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>//垂直布局
#include<QVBoxLayout>//水平布局
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    QVBoxLayout *cmdLayout =new QVBoxLayout;
    QLabel *info1Label =new QLabel;
    QLabel *info2Label =new QLabel;
    QLineEdit *LineEdit1 =new QLineEdit;
    QLineEdit *LineEdit2 =new QLineEdit;
    QPushButton *startButton =new QPushButton;
    QPushButton *concedeButton =new QPushButton;

protected:
    //paint
    void paintEvent(QPaintEvent *);

    //mouse
    void mousePressEvent(QMouseEvent *);
public:

    Widget(QWidget *parent = nullptr);
    ~Widget();

//    void StopGame();  //停止当前棋局
//    void RepentanceGame(); //悔棋

    //静态成员
    static int height;
    static int width;
    static int n_row;
    static int n_column;

private:
    Ui::Widget *ui;
    bool m_isBlackTurn;    //当前该黑棋下
    QVector<Chess> m_Chess;//已下的棋子座标容器

    void DrawChessboard();  //画棋盘
    void DrawChesses();     //画已下的棋子
    void DrawChessAtPoint(QPainter& painter,QPoint& pt);//在pt 位置,以Painter 画棋子
    void StopGame();  //停止当前棋局
    void RepentanceGame(); //悔棋
};
#endif // WIDGET_H