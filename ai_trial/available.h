
#ifndef AVAILABLE_H
#define AVAILABLE_H
#include"rules.h"



class available:public Rules
{
public:
    available();
    int ava_number(int ExistChess[9][9],int black);
};

#endif // AVAILABLE_H
