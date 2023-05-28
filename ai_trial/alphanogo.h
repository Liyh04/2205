#ifndef ALPHANOGO_H
#define ALPHANOGO_H
#include <QVector>
#include "dasan.h"
#include "randomnumbergenerator.h"
//int NewChessBoardOfAI[13][13];


class AlphaNoGO
{
public:
    AlphaNoGO();
    Point search(int ExistChess[13][13],bool isblackturn);
};

#endif // ALPHANOGO_H
