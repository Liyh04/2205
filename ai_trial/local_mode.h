#ifndef LOCAL_MODE_H
#define LOCAL_MODE_H

#include <QWidget>

namespace Ui {
class local_mode;
}

class local_mode : public QWidget
{
    Q_OBJECT

public:
    explicit local_mode(QWidget *parent = nullptr);
    ~local_mode();

private:
    Ui::local_mode *ui;
};

#endif // LOCAL_MODE_H
