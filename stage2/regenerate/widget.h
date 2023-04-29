
#ifndef WIDGET_H
#define WIDGET_H
#include<QMessageBox>
#include <QWidget>
#include<QInputDialog>
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>//垂直布局
#include<QVBoxLayout>//水平布局
#include<QObject>
#include<QDebug>
#include<QPainter>
#include<QVector>
#include<vector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
static int ExistChess[9][9];//0代表没有棋子，1代表黑棋，2代表白棋
static bool m_isBlackTurn;
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

class Widget : public QWidget

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
    void on_pushButton_clicked();//当按下认输按钮

    QVector<Chess> m_Chess;//已下的棋子座标容器
    Ui::Widget *ui;
    void mousePressEvent(QMouseEvent * e);
    void DrawChesses();     //画已下的棋子
    void init();//游戏开局时初始化
    friend class paint;
};




#endif // WIDGET_H
