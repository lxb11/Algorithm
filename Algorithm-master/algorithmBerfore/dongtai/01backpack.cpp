/*************************************************************************
	> File Name: 01backpack.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月27日 星期四 04时27分15秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
int min(int a,int b);
int max(int a,int b);
int Knapsack(int v[],int w[],int c,int n,int * *m);
void Traceback(int * *m,int w[],int c,int n,int x[]);

int main()
{
    int s;
    int w[15];
    int v[15];
    int x[15];
    int n,i;
    int c;

    cout<<"请输入背包的最大载重量\n";
    cin>>c;
    cout<<"请输入物品个数\n";
    cin>>n;
    cout<<"请分别输入物品重量\n";
    for(int i = 1; i < n + 1; i++)
    {
        cin>>w[i];
    }
    cout<<"请分别输入物品价值\n";
    for(int i = 1; i < n + 1; i++)
    {
        cin>>v[i];
    }
    int * *m = new int *[100];
    for(int i = 0; i < 100; i++)
    {
        m[i] = new int[100];
    }
    s = Knapsack(v,w,c,n,m);
    Traceback(m,w,c,n,x);

    cout<<"最大装载价值：  "<<s<<endl;
    for(int i = 1; i < c + 1; i++)
    {
        for(int j = 1; j < c + 1; j++)
        {
            printf("%-4d",m[i][j]);
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    for(int i = 1; i < n + 1; i++)
    {
        printf("%-4d",x[i]);
    }
    putchar(10);
    return 0;
}

int Knapsack(int v[],int w[],int c,int n,int * *m)
{
    int jMax = min(w[n] - 1,c);
    for(int j = 0; j <= jMax; j++) m[n][j] = 0;
    for(int j = w[n]; j <= c; j++) m[n][j] = v[n];
    for(int i = n - 1; i > 1; i--)
    {
        jMax = min(w[i] - 1,c);
        for(int j = 0; j <= jMax; j++) m[i][j] = m[i + 1][j];
        for(int j = w[i]; j <= c; j++) m[i][j] = max(m[i + 1][j],m[i + 1][j - w[i]] + v[i]);
    }
    m[1][c] = m[2][c];
    if(c >= w[1])
    {
        m[1][c] = max(m[1][c],m[2][c - w[1]] + v[1]);
    }
    return m[1][c];
    
}

void Traceback(int * *m,int w[],int c,int n,int x[])
{
    for(int i = 1; i < n; i++)
    {
        if(m[i][c] == m[i + 1][c])
        {
            x[i] = 0;
        }
        else
        {
            x[i] = 1;
            c -= w[i];
        }
    }
    x[n] = (m[n][c]) ? 1 : 0;
}

int min(int a,int b)
{
    if(a >= b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int max(int a,int b)
{
    if(a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
