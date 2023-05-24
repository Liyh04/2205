#ifndef REPLAY_H
#define REPLAY_H

#include <QWidget>

namespace Ui {
class replay;
}

class replay : public QWidget
{
    Q_OBJECT

public:
    explicit replay(QWidget *parent = nullptr);
    ~replay();

private:
    Ui::replay *ui;
};

#endif // REPLAY_H
