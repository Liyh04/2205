
#ifndef AVAILABLE_H
#define AVAILABLE_H
#include"rules.h"



class available:public Rules
{
public:
    available();
    int ava_number(int ExistChess[13][13],int n_row,int black);//返回黑方/白方当前剩余合法点数

};

#endif // AVAILABLE_H
