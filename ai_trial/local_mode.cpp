#include "local_mode.h"
#include "ui_local_mode.h"

local_mode::local_mode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::local_mode)
{
    ui->setupUi(this);
}

local_mode::~local_mode()
{
    delete ui;
}
