
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
#define PAINT_X 114
#define PAINT_Y 51
int TIMELIMIT=10;
int step=0;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
static int ExistChess[9][9];//0代表没有棋子，1代表黑棋，2代表白棋
static bool m_isBlackTurn;
static QTime baseTime;
static QTimer *pTimer;

class Chess;
class rules;
class timer;
class paint;
class Widget : public QWidget

{
    Q_OBJECT

public:

    Widget(QWidget *parent = nullptr);
    //Widget(const Widget&){};
    ~Widget();
    Chess *chess;
    rules *rules;
    timer *timer;
    paint *paint;
    void init();
    void restart();
    void on_pushButton_clicked();//当按下认输按钮
    static int height;
    static int width;
    static int n_row;
    static int n_column;
    Ui::Widget *ui;
};
int Widget::height=50;
int Widget::width=50;
int Widget::n_row=9;
int Widget::n_column=9;
#endif // WIDGET_H
