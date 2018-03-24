/************************************************************************
	> File Name: chess.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月09日 星期日 18时18分09秒
 ************************************************************************/

#include<stdio.h>
#define N 100
void set_table(int n);
int diaplay(int n);
void chessboard(int tr,int tc,int dr,int dc,int size);
int a[N][N] = {0};
int tile = 2;
int n;

int main()
{
    int tr = 0,tc = 0,dr,dc;
    printf("请输入方格大小（n × n）特殊方格位置\n");
    scanf("%d %d %d",&n,&dr,&dc);
    a[dr][dc] = 1;
    printf("方格初始化如下 \n");
    display(n);
    chessboard(0,0,dr,dc,n);
    //display(n);
    return 0;
}


/*void set_table(int n)
{
    int a[n][n] = {0};
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            printf("%-2d",a[i][j]);
        }
        putchar(10);
    }
}*/

int display(int n)
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            printf("%-2d",a[i][j]);
        }
        putchar(10);
    }
    return 0;

}

void chessboard(int tr,int tc,int dr,int dc,int size)
{
    if(size == 1) return ;
    int t = tile++;//L型骨牌
    int s = size / 2;//分割棋盘
    //覆盖左上角子棋盘
    if(dr < tr + s && dc < tc + s)
    //特殊方格在此棋盘中
    {
        chessboard(tr,tc,dr,dc,s);
        putchar(10);
        //display(n);
    }
    else
    {
        a[tr + s - 1][tc + s - 1] = t;
        chessboard(tr,tc,tr + s - 1,tc + s - 1,s);//覆盖其余方格
        putchar(10);
        display(n);
    }
    if(dr < tr + s && dc >= tc + s)
    //特殊方格在此棋盘中
    {
        chessboard(tr,tc + s,dr,dc,s);
        putchar(10);
        //display(n);
    }
    else//次棋盘中无特殊方格
    {
        a[tr + s - 1][tc + s] = t;
        chessboard(tr,tc + s,tr + s - 1,tc + s,s);
        putchar(10);
        display(n);
    }
    if(dr >= tr + s && dc < tc + s)
    {
        chessboard(tr + s,tc,dr,dc,s);
        putchar(10);
        //display(n);
    }
    else
    {
        a[tr + s][tc + s - 1] = t;
        //覆盖其余方格
        chessboard(tr + s,tc,tr + s,tc + s - 1,s);
        putchar(10);
        display(n);
    }
    if(dr >= tr + s && dc >= tc + s)
    //特殊方格在此棋盘中
    {
        chessboard(tr + s,tc + s,dr,dc,s);
        putchar(10);
        //display(n);
    }
    else
    {//用t号L型骨牌覆盖其左上角
        a[tr + s][tc + s] = t;
        //覆盖其方格
        chessboard(tr + s,tc + s,tr + s,tc + s,s);
        putchar(10);
        display(n);
    }
}
