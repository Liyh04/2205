#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
#include <QMessageBox>
#define TIMELIMIT 120
Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->init();
    ui->groupBox->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);

    //mytimer=new QTimer(this);
    //onesec=new QTimer(this);
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
        int sec=TIMELIMIT-t/1000;
        if(sec>=0)
        {
            QString min_str=QString::number(sec/60);
            QString minstr=QString("%2").arg(min_str.toInt(), 2, 10, QLatin1Char('0'));
            QString sec_str=QString::number(sec%60);
            QString secstr=QString("%2").arg(sec_str.toInt(), 2, 10, QLatin1Char('0'));
            this->ui->lcd_min->display(minstr);
            this->ui->lcd_sec->display(secstr);
        }
        else
        {
            pTimer->setSingleShot(true);
            QObject::connect(pTimer, &QTimer::timeout, [&]() {
                QString min_str=QString::number(0);
                QString minstr=QString("%2").arg(min_str.toInt(), 2, 10, QLatin1Char('0'));
                QString sec_str=QString::number(0);
                QString secstr=QString("%2").arg(sec_str.toInt(), 2, 10, QLatin1Char('0'));
                this->ui->lcd_min->display(minstr);
                this->ui->lcd_sec->display(secstr);
                QString content=QString("%3 seconds elapsed.").arg(TIMELIMIT);
                QMessageBox::information(this, "Timeout", content);

            });
    }
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

}

