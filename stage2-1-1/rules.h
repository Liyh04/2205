
#ifndef RULES_H
#define RULES_H




class Rules
{
public:
    Rules();
    int if_legal(int ExistChess[9][9],int x,int y);//判断x行y列的棋子是否存活
    int if_scanned[9][9];//在递归回溯时记录已经判断过的棋子，避免造成死循环
    void if_scanned_init();//将if_scanned数组所有元素重置为0
    bool illegal_operation_judging(int ExistChess[9][9],int X,int Y);
};

#endif // RULES_H
