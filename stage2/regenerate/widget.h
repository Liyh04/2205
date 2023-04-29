
#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>//垂直布局
#include<QVBoxLayout>//水平布局
#include <QElapsedTimer>
#include <QWidget>
#include <QTime>
#include <QSet>
#include <QPainter>
#include <QMouseEvent>
#include "chess.h"
#include <QDebug>
#include <QTimer>
#include <QMessageBox>
#include <QInputDialog>
//#include <QSoundEffect>
#include <QBrush>
#include <qcolor.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
static int ExistChess[9][9];//0代表没有棋子，1代表黑棋，2代表白棋
static QTime baseTime;
static QTimer *pTimer;
class QWidget;
class Chess;
class rules;
class timer;
class paint;
#define height 50
#define width 50
#define PAINT_X 114
#define PAINT_Y 51
static int TIMELIMIT;
static int step;
#define n_row 9
#define n_column 9
static bool m_isBlackTurn;    //当前该黑棋下
/*class Widget : public QWidget

{
    Q_OBJECT

public:

    Widget(QWidget *parent = nullptr);
    //Widget(const Widget&){};
    ~Widget();
    Chess *chess=NULL;
    rules *rules=NULL;
    timer *timer=NULL;
    paint *paint=NULL;
    void restart();


    QVector<Chess> m_Chess;//已下的棋子座标容器
    Ui::Widget *ui;

    void DrawChesses();     //画已下的棋子
    void init();//游戏开局时初始化
    friend class paint;
    void paintEvent(QPaintEvent *);

    void DrawChessboard();  //画棋盘
signals:
    void updateSignal();
public slots:
    void mousePressEvent(QMouseEvent * e);
    void on_pushButton_clicked();//当按下认输按钮
};*/
class Widget : public QWidget
{
    Q_OBJECT

public:
    void restart();//重新开局

protected:
    //paint
    void paintEvent(QPaintEvent *);
    //mouse
    void mousePressEvent(QMouseEvent *);
public:

    Widget(QWidget *parent = nullptr);
    void init();//游戏开局时初始化
    void if_scanned_init();//将if_scanned数组所有元素重置为0
    QTime baseTime;
    QTimer *pTimer;
    ~Widget();

public slots:
    void on_pushButton_clicked();//当按下认输按钮
public slots:
    void updatedisplay();//更新计时器显示
public:
    Ui::Widget *ui;

    QVector<Chess> m_Chess;//已下的棋子座标容器

    void DrawChessboard();  //画棋盘
    void DrawChesses();     //画已下的棋子
    void DrawChessAtPoint(QPainter& painter,QPoint& pt);//在pt 位置,以Painter 画棋子
    void StopGame();  //停止当前棋局（暂未实现）
    void RepentanceGame(); //悔棋（暂未实现）
    rules *r;
signals:
    void updateSignal();
    void illegal_warnings();
};



#endif // WIDGET_H
