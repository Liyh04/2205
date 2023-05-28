#ifndef ALPHANOGO_H
#define ALPHANOGO_H

#include "dasan.h"
//int NewChessBoardOfAI[13][13];


class AlphaNoGO
{
public:
    AlphaNoGO();
    Point search(int ExistChess[13][13],bool isblackturn);
};

#endif // ALPHANOGO_H
