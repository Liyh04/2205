#ifndef ALPHANOGO_H
#define ALPHANOGO_H

#include "dasan.h"
int NewChessBoard[13][13];


class AlphaNoGO
{
public:
    AlphaNoGO();
    Point search(int ExistChess[9][9],bool isblackturn);
};

#endif // ALPHANOGO_H
