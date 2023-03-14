#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->init();
    ui->groupBox->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);

    mytimer=new QTimer(this);
    onesec=new QTimer(this);
}

void Widget::init()
{
    this->pTimer=new QTimer;
    connect(this->pTimer,SIGNAL(timeout()),this,SLOT(updatedisplay()));
}
void Widget::updatedisplay()
{
    {
        QTime curTime=QTime::currentTime();
        int t=this->baseTime.msecsTo(curTime);
        QTime showTime(0,0,0,0);
        showTime=showTime.addMSecs(t);
        int sec=t/1000;
        this->ui->lcd_min->display(sec/60);
        this->ui->lcd_sec->display(sec%60);
    }

}
Widget::~Widget()
{
    delete ui;
}


void Widget::on_Btnstart_clicked()
{
    this->baseTime=this->baseTime.currentTime();
    this->pTimer->start(1);
    ui->Btnstart->setEnabled(false);
    /*mytimer->setInterval(120000);
    onesec->setInterval(1000);
    mytimer->setSingleShot(true);
    onesec->setSingleShot(false);
    mytimer->setTimerType(Qt::PreciseTimer);
    onesec->setTimerType(Qt::PreciseTimer);
    mytimer->start();
    onesec->start(10);

    ui->btnstop->setEnabled(true);
        connect(mytimer,SIGNAL(timeout()),this,SLOT(updatedisplay()));
    while(mytimer->remainingTime())
        updatedisplay();*/
}

