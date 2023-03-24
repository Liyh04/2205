#ifndef TIMER_H
#define TIMER_H

#include <QElapsedTimer>
#include <QWidget>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
private:

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

public slots:
    void updatedisplay();
    void on_Btnstart_clicked();
    //void on_btnstop_clicked();

private:
    Ui::Widget *ui;
};
#endif // TIMER_H
