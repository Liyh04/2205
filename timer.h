#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include <mainwindow.h>

class timer : public QObject
{
    Q_OBJECT
public:
    explicit timer(QObject *parent = nullptr);
    ~timer();
    QTimer *mytimer;
public slots:
    void myslot();
signals:

};

#endif // TIMER_H
