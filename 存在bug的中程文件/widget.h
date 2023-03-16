#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <chess.h>
#include <QElapsedTimer>
#include <QWidget>
#include <QTime>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT


protected:
    //paint
    void paintEvent(QPaintEvent *);

    //mouse
    void mousePressEvent(QMouseEvent *);
public:
    Widget(QWidget *parent = nullptr);
    void init();
    //void timesleep(int msec);
    ~Widget();
    QTimer *mytimer;
    QTimer *onesec;
    QTime baseTime;
    QTimer *pTimer;
    QElapsedTimer *mycounter;

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
public slots:
    void updatedisplay();
    void on_Btnstart_clicked();
    //void on_btnstop_clicked();

private slots:
    void on_pushButton_2_clicked();
};
#endif // WIDGET_H
