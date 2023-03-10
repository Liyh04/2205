#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->usernameEdit=new QLineEdit(this);
    this->usernameEdit->setText(QString("Zhangsan"));
    this->usernameEdit->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}

