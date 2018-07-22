/*************************************************************************
	> File Name: juzhen.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月23日 星期日 16时51分15秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;


//void matrixMultiply(int * *a,int * *b,int * *c,int ra,int ca,int rb,int cb);

void Traceback(int i,int j,int * *s);
int MatrixChain(int *p,int n,int * *m,int * *s);
#define L 7

int main()
{
    int p[L] = {30,35,15,5,10,20,25};

    int * *s = new int *[L];
    int * *m = new int *[L];


    for(int i = 0; i < L; i++)
    {
        s[i] = new int[L];
        m[i] = new int[L];
    }


    cout<<"矩阵的最少计算次数为："<<MatrixChain(p,6,m,s)<<endl;
    cout<<"矩阵最优计算次序为："<<endl; 
    Traceback(1,L - 1,s);  
    cout<<"\n\n";

    printf("m[i][j]\n");
    for(int i = 1; i < L; i++)
    {
        for(int j = 1; j < L; j++)
        {
            printf("%-8d",m[i][j]);
        }
        cout<<endl;
    }                              
    
    cout<<endl<<endl;
    printf("s[i][j]\n");
    for(int i = 1; i < L; i++)
    {
        for(int j = 1; j < L; j++)
        {
            printf("%-8d",s[i][j]);
        }
        cout<<endl;
    }

    return 0;
}

/*void matrixMultiply(int * *a,int * *b,int * *c,int ra,int ca,int rb,int cb)
{
    if(ca != rb)
    {
        printf("矩阵不可乘\n");
        return;
    }
    for(int i = 0;i < ra;i++)
    {
        for(int j = 0;j < cb;j++)
        {
            int sum = a[i][0] * b[0][j];
            for(int k = 1;k < ca;k++)
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}*/

int MatrixChain(int *p,int n,int * *m,int * *s)
{
    for(int i = 1;i <= n;i++) m[i][i] = 0;
    for(int r = 2;r <= n;r++) //r为当前计算的链长（子问题规模）
    {
        for(int i = 1;i <= n - r + 1;i++)//n-r+1为最后一个r链的前边界 
        {
            int j = i + r - 1;//计算前边界为r，链长为r的链的后边界
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i]*p[j];//将链ij划分为A(i)\
            * ( A[i+1:j]  )
            s[i][j] = i;
            for(int k = i + 1;k < j;k++)
            {
                //将链ij划分为( A[i:k]  )* (A[k+1:j])
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k]*p[j];
                if(t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][L-1];
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

