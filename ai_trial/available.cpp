
#include "available.h"

available::available()
{

}
int available::ava_number(int ExistChess[13][13],int n_row,int black)
{
    int arr[13][13];
    int flag=0;
    for(int i=0;i<n_row;i++)
    {
        for(int j=0;j<n_row;j++)
        {
            arr[i][j]=ExistChess[i][j];
        }
    }
    for(int i=0;i<n_row;i++)
    {
        for(int j=0;j<n_row;j++)
        {
            if(arr[i][j])continue;
            arr[i][j]=black?1:2;
            if(illegal_operation_judging(arr,n_row,i,j))flag++;
            arr[i][j]=0;
        }
    }
    return flag;
}
