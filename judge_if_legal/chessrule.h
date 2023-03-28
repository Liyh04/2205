#ifndef CHESSRULE_H
#define CHESSRULE_H


class chessrule
{
public:
    chessrule();
    static int ExistChess[9][9];
    static void chesscolorinit()
    {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                ExistChess[i][j]=0;
    }
    static bool if_legal()
    {
        return true;
    }
};

#endif // CHESSRULE_H
