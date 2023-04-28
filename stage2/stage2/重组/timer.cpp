
#include "timer.h"
#include "ui_widget.h"

timer::timer()
{

}
void timer::init()//游戏开局时初始化：设置每步限时，初始化计时器
{

    bool ok=false;
    QString dlgTitle="Timelimit Setting";
    QString txtLabel="Please enter the timelimit of each step(an integer).";
    int timelimit=QInputDialog::getInt(this,dlgTitle,txtLabel,30,10,3600,1,&ok);
    if(ok)
    {
        TIMELIMIT=timelimit;
    }
    pTimer=new QTimer;
    connect(pTimer,SIGNAL(timeout()),this,SLOT(updatedisplay()));
    QString min_str=QString::number(TIMELIMIT/60);
    QString minstr=QString("%2").arg(min_str.toInt(), 2, 10, QLatin1Char('0'));
    QString sec_str=QString::number(TIMELIMIT%60);
    QString secstr=QString("%2").arg(sec_str.toInt(), 2, 10, QLatin1Char('0'));
    this->ui->lcd_min->display(minstr);
    this->ui->lcd_sec->display(secstr);
    ui->label_3->setText("BLACK");
}
void timer::updatedisplay()//实时更新计时器
{
    {
        QTime curTime=QTime::currentTime();
        int t=baseTime.msecsTo(curTime);
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

            if(m_isBlackTurn)
            {
                //ui->player->display("BLACK");

                ui->label_3->setText("BLACK");
            }
            if(!m_isBlackTurn)
            {
                //ui->player->display("WHITE");

                ui->label_3->setText("WHITE");
            }
        }
        else
        {

            QString content=QString("Time limit exceed");
            QMessageBox *dialog1=new QMessageBox;
            dialog1->resize(1000,700);
            if(m_isBlackTurn)
                dialog1->information(this, content, QString("    BLACK LOSE!    \n    Total Steps: %1    ").arg(step) );
            else dialog1->information(this, content, QString("    WHITE LOSE!    \n    Total Steps: %1    ").arg(step));
            restart();
        }
    }
}
