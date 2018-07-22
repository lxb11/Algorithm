/*************************************************************************
	> File Name: shizi.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月25日 星期二 01时31分23秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
#define L 4

void Traceback(int i,int j,int * *s);
int MatrixChain(int *p,int n,int * *m,int * *s,int * *M,int * *S);
void display(int * *array);

int main()
{
    int p[L] = {4,4,5,9};

    int * *s = new int *[L];
    int * *S = new int *[L];
    int * *m = new int *[L];
    int * *M = new int *[L];


    for(int i = 0; i < L; i++)
    {
        s[i] = new int[L];
        S[i] = new int[L];
        m[i] = new int[L];
        M[i] = new int[L];
    }


    MatrixChain(p,L,m,s,M,S);
    cout<<"Min Score："<<m[0][L - 1]<<endl;
    cout<<"Max Score："<<M[0][L - 1]<<endl;
    //Traceback(1,L,s);  
    cout<<"\n\n";

    printf("m[i][j]\n");
    display(m);
    printf("M[i][j]\n");
    display(M);
    cout<<"最优计算次序为："<<endl;
    display(s);
    cout<<endl;
    display(S);

    return 0;
}


int MatrixChain(int *p,int n,int * *m,int * *s,int * *M,int * *S)
{
    int sum[n + 1] = {0};

    for(int i = 1; i < n + 1; i++)
    {
        if(i == 1)
        {
            sum[i] = p[i - 1];
        }
        else
        {
            sum[i] = sum[i - 1] + p[i - 1];
        }
    }
    for(int i = 0;i < n;i++) m[i][i] = M[i][i] = 0;
    for(int r = 2;r <= n;r++) //r为当前计算的链长（子问题规模）
    {
        for(int i = 0;i < n - r + 1;i++)//n-r+1为最后一个r链的前边界 
        {
            int j = i + r - 1;//计算前边界为r，链长为r的链的后边界
            m[i][j] = m[i + 1][j] + sum[j + 1] - sum[i];//将链ij划分为A(i)\
            * ( A[i+1:j]  )
            M[i][j] = M[i + 1][j] + sum[j + 1] - sum[i];
            s[i][j] = S[i][j] = i + 1;
            for(int k = i + 1;k < j;k++)
            {
                //将链ij划分为( A[i:k]  )* (A[k+1:j])
                int t1 = m[i][k] + m[k + 1][j] + sum[j + 1] - sum[i];
                int t2 = M[i][k] + M[k + 1][j] + sum[j + 1] - sum[i];
                if(t1 < m[i][j])
                {
                    m[i][j] = t1;
                    s[i][j] = k + 1;
                }
                if(t2 > M[i][j])
                {
                    M[i][j] = t2;
                    S[i][j] = k + 1;
                }
            }
        }
    }
}

void Traceback(int i,int j,int * *s)
{
    if(i == j)
    {
        return;
    }
    Traceback(i,s[i][j],s);
    Traceback(s[i][j] + 1,j,s);

    cout<<"Mulitiply A"<<i<<","<<s[i][j];
    cout<<"and A"<<(s[i][j] + 1)<<","<<j<<endl;
}                                                                                

void display(int * * array)
{
    
    for(int i = 0; i < L; i++)
    {
        for(int j = 0; j < L; j++)
        {
            printf("%-8d",array[i][j]);
        }
        cout<<endl;
    }                               
}
