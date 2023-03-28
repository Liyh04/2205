#ifndef CHESS_H
#define CHESS_H

#include <QObject>

class chess : public QObject
{
    Q_OBJECT
public:
    explicit chess(QObject *parent = nullptr);

signals:

};

#endif // CHESS_H
