#include "widget.h"
#include <QApplication>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>//垂直布局
#include<QVBoxLayout>//水平布局
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel *info1Label =new QLabel;
    QLabel *info2Label =new QLabel;
    QLineEdit *LineEdit1 =new QLineEdit;
    QLineEdit *LineEdit2 =new QLineEdit;
    QPushButton *startButton =new QPushButton;
    info1Label->setText("player1:");
    info2Label->setText("player2:");
    startButton->setText("start");
    QVBoxLayout *cmdLayout =new QVBoxLayout;
    cmdLayout->addWidget(info1Label);
    cmdLayout->addWidget(LineEdit1);
    cmdLayout->addWidget(info2Label);
    cmdLayout->addWidget(LineEdit2);
    cmdLayout->addWidget(startButton);
    cmdLayout->setStretchFactor(info1Label, 1);
    cmdLayout->setStretchFactor(LineEdit1, 1);
    cmdLayout->setStretchFactor(info2Label, 1);
    cmdLayout->setStretchFactor(LineEdit2, 1);
    cmdLayout->setSpacing(100);

    Widget w;
    w.show();
    return a.exec();
}
