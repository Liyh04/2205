#include "timer.h"
#include "ui_timer.h"
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
#include <QMessageBox>
#define TIMELIMIT 10
Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->init();
    //ui->groupBox->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);

    //mytimer=new QTimer(this);
    //onesec=new QTimer(this);
}

void Widget::init()
{
    this->pTimer=new QTimer;
    connect(this->pTimer,SIGNAL(timeout()),this,SLOT(updatedisplay()));
    QString min_str=QString::number(TIMELIMIT/60);
    QString minstr=QString("%2").arg(min_str.toInt(), 2, 10, QLatin1Char('0'));
    QString sec_str=QString::number(TIMELIMIT%60);
    QString secstr=QString("%2").arg(sec_str.toInt(), 2, 10, QLatin1Char('0'));
    this->ui->lcd_min->display(minstr);
    this->ui->lcd_sec->display(secstr);
}
void Widget::updatedisplay()
{
    {
        QTime curTime=QTime::currentTime();
        int t=this->baseTime.msecsTo(curTime);
        QTime showTime(0,0,0,0);
        showTime=showTime.addMSecs(t);
        int sec=(1000*TIMELIMIT-t)/1000;
        if(t<=1000*TIMELIMIT)
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
                QString content=QString("Time limit exceed");
                QMessageBox *dialog1=new QMessageBox;
                dialog1->resize(1000,700);
                dialog1->information(nullptr, content, "    YOU LOSE!    ");
                QString min_str=QString::number(0);
                QString minstr=QString("%2").arg(min_str.toInt(), 2, 10, QLatin1Char('0'));
                QString sec_str=QString::number(0);
                QString secstr=QString("%2").arg(sec_str.toInt(), 2, 10, QLatin1Char('0'));
                this->ui->lcd_min->display(minstr);
                this->ui->lcd_sec->display(secstr);


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

