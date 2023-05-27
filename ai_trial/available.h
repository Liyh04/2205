
#ifndef AVAILABLE_H
#define AVAILABLE_H
#include"rules.h"



class available:public Rules
{
public:
    available();
    int ava_number(int ExistChess[13][13],int n_row,int black);

};

#endif // AVAILABLE_H
