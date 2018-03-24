/*************************************************************************
	> File Name: FlowShop.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月06日 星期六 21时09分52秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Jobtype
{
    public:
    int operator <= (Jobtype a) const
    {return (key <= a.key); }
    int key,index;
    bool job;
};

int FlowShop(int n,int a[],int b[],int c[]);
void Maopao(Jobtype *d,int n);
#define N 6

int main()
{
    int a[] = {2,5,7,10,5,2};
    int b[] = {3,8,4,11,3,4};
    int c[N];

    cout<<"作业在机器1上的运行时间为："<<endl;
    for(int i = 0; i < N; i++)
    {
        cout<<b[i]<<"  ";
    }
    cout<<endl;
    cout<<"作业在机器2上的运行时间为："<<endl;
    for(int i = 0; i < N; i++)
    {
        cout<<b[i]<<"  ";
    }
    cout<<endl;


    FlowShop(N,a,b,c);
    cout<<"完成作业最短时间的作业顺序为："<<endl;
    for(int i = 0; i < N; i++)
    {
        cout<<c[i] + 1<<"  ";
    }
    cout<<endl;
    return 0;
}

int FlowShop(int n,int a[],int b[],int c[])
{
    Jobtype *d = new Jobtype [n];
    for (int i = 0;i < n;i++)
    {
        d[i].key = a[i] > b[i] ? b[i]:a[i];
        d[i].job = a[i] <= b[i];
        d[i].index = i;
    }

    Maopao(d,n);

    int j = 0,k = n - 1;
    for(int i = 0;i < n;i++)
    {
        if(d[i].job) c[j++] = d[i].index;
        else c[k--] = d[i].index;
    }
     
    j = a[c[0]];
    k = j + b[c[0]];
    for(int i = 1;i < n;i++)
    {
        j += a[c[i]];
        k = j < k?k + b[c[i]]:j + b[c[i]];
    }
    delete d;
    return k;
}              

void Maopao(Jobtype *d,int n)
{
    int i,j,flag;
    Jobtype temp;

    for(i = 0; i < n; i++)
    {
        for(j = n - 1; j > i; j--)
        {
            if(d[i] <= d[j])
            {
                temp = d[j];
                d[j] = d[j - 1];
                d[j - 1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}
