#include "alphanogo.h"
#include"dasan.h"
#include"available.h"
#include <algorithm>
#include <iterator>
#include "qdebug.h"
#include"rules.h"
int flagg=0;
int flagg_2=0;
AlphaNoGO::AlphaNoGO()
{

}
Point AlphaNoGO::search(int ExistChess[13][13],bool isblackturn){//黑1 白2 空0
    int NewChessBoardOfAI[13][13];
    DaSan D;
    Point *p_start=new Point(0,0);
    if(ExistChess[4][4]==0){
        p_start->x=4;
        p_start->y=4;
        return *p_start;
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            NewChessBoardOfAI[i][j]=ExistChess[i][j];
        }
    }
    available av;
    int init_score_black=av.ava_number(ExistChess,9,1)-av.ava_number(ExistChess,9,2);
    Point *p=new Point(0,0);
    int max_score_black=-999;//init_score_black;
    int max_score_white=-999;//-init_score_black;
    int init_score_white=-init_score_black;

//先找最理想的点
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(ExistChess[i][j])continue;
            Rules r;

            if(isblackturn){
                int new_score;
                NewChessBoardOfAI[i][j]=1;//下子了
                if(!r.illegal_operation_judging( NewChessBoardOfAI,9,i,j)){NewChessBoardOfAI[i][j]=0;continue;}
                new_score=av.ava_number(NewChessBoardOfAI,9,1)-av.ava_number(NewChessBoardOfAI,9,0);
                qDebug()<<new_score<<' '<<i<<' '<<j<<' ';
                if(max_score_black<new_score){
                    p->x=i;
                    p->y=j;
                    max_score_black=new_score;
                }
                NewChessBoardOfAI[i][j]=0;
            }
            else{
                int new_score;
                NewChessBoardOfAI[i][j]=2;
                if(!r.illegal_operation_judging( NewChessBoardOfAI,9,i,j)){NewChessBoardOfAI[i][j]=0;continue;}
                new_score=-av.ava_number(NewChessBoardOfAI,9,1)+av.ava_number(NewChessBoardOfAI,9,0);
                if(max_score_white<new_score){
                    p->x=i;
                    p->y=j;
                    max_score_white=new_score;
                }
                NewChessBoardOfAI[i][j]=0;
            }
        }
    }
    //if(max_score_black>=init_score_black||max_score_white>=init_score_white)
    {
        return *p;
    }



    //差点
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(ExistChess[i][j])continue;
            Rules r;

            if(isblackturn){
                int new_score;
                NewChessBoardOfAI[i][j]=1;
                if(!r.illegal_operation_judging( NewChessBoardOfAI,9,i,j)){NewChessBoardOfAI[i][j]=0;continue;}
                flagg++;
                new_score=av.ava_number(NewChessBoardOfAI,9,1)-av.ava_number(NewChessBoardOfAI,9,0);
                if(init_score_black>new_score){
                    flagg_2++;
                }
                NewChessBoardOfAI[i][j]=0;
            }
            else{
                int new_score;
                NewChessBoardOfAI[i][j]=2;
                if(!r.illegal_operation_judging( NewChessBoardOfAI,9,i,j)){NewChessBoardOfAI[i][j]=0;continue;}
                flagg++;
                new_score=-av.ava_number(NewChessBoardOfAI,9,1)+av.ava_number(NewChessBoardOfAI,9,0);

                if(init_score_black>new_score){
                    flagg_2++;
                }
                NewChessBoardOfAI[i][j]=0;
            }
        }
    }

    if(flagg==flagg_2){//只能下差点
        Point p= D.shuffleBoard(ExistChess);
        return p;
    }


    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(ExistChess[i][j])continue;
            Rules r;


            if(isblackturn){
                int new_score;
                NewChessBoardOfAI[i][j]=1;
                if(!r.illegal_operation_judging( NewChessBoardOfAI,9,i,j)){NewChessBoardOfAI[i][j]=3;continue;}
                new_score=av.ava_number(NewChessBoardOfAI,9,1)-av.ava_number(NewChessBoardOfAI,9,0);
                if(init_score_black>new_score){
                    NewChessBoardOfAI[i][j]=3;
                }
            }
            else{
                int new_score;
                NewChessBoardOfAI[i][j]=2;
                if(!r.illegal_operation_judging( NewChessBoardOfAI,9,i,j)){NewChessBoardOfAI[i][j]=3;continue;}
                new_score=-av.ava_number(NewChessBoardOfAI,9,1)+av.ava_number(NewChessBoardOfAI,9,0);
                if(init_score_black>new_score){
                    NewChessBoardOfAI[i][j]=3;
                }
            }
        }
    }
        Point pp= D.shuffleBoard(NewChessBoardOfAI);
        return pp;
}





