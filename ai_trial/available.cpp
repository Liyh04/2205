
#include "available.h"

available::available()
{

}
int available::ava_number(int ExistChess[9][9],int black)
{
    int arr[9][9];
    int flag=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            arr[i][j]=ExistChess[i][j];
        }
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(arr[i][j])continue;
            arr[i][j]=black?1:2;
            if(illegal_operation_judging(arr,i,j))flag++;
            arr[i][j]=0;
        }
    }
    return flag;
}
