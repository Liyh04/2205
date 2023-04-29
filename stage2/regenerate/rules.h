
#ifndef RULES_H
#define RULES_H
#include "widget.h"


class Widget;
class rules:public Widget
{
public:
    rules();

    static int if_scanned[9][9];//在递归回溯时记录已经判断过的棋子，避免造成死循环
    static int if_legal(int x,int y);//判断x行y列的棋子是否存活
    bool illegal_warning(int x,int y);
    static void if_scanned_init();
private:
};

#endif // RULES_H
