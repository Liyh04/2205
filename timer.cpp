#include "timer.h"
#include <QTimer>

timer::timer(QObject *parent)
    : QObject{parent}
{
    mytimer=new QTimer(this);
    connect(mytimer,SIGNAL(timeout()),this,SLOT(mySlot()));
}
MainWindow::MainWindow(QMainwindow *parent):QMainwindow(parent),ui(new Ui::MainWindow)
{

}
