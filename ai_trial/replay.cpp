#include "replay.h"
#include "ui_replay.h"

replay::replay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::replay)
{
    ui->setupUi(this);
}

replay::~replay()
{
    delete ui;
}
