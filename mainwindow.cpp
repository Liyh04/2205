#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->usernameEdit=new QLineEdit(this);
    //this->usernameEdit->setGeometry(10,ui->chatEdit->y(),61,21);
    this->usernameEdit->setText(QString("Zhangsan"));
    this->usernameEdit->show();
    //qDebug()<<this->usernameEdit->geometry()<<""<<this->ui->chatEdit->geometry();
}

MainWindow::~MainWindow()
{
    delete ui;
}

