/*************************************************************************
	> File Name: lingqian.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月08日 星期一 08时54分57秒
 ************************************************************************/

#include<iostream>
using namespace std;

void lingqian(float *m,int n,float sum);
void Maopao(float *d,int n);

int main()
{
    float sum;
    cout<<"请输入需要找的钱数:"<<endl;
    cin>>sum;

    int n;
    cout<<"请输入零钱种类:"<<endl;
    cin>>n;

    float m[n];
    cout<<"请输入零钱的大小:"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>m[i];
    }

    cout<<"最优找法："<<endl;
    lingqian(m,n,sum);

    return 0;
}

void lingqian(float *m,int n,float sum)
{
    float t[100];
    int i = 0;
    int j = 0;
    Maopao(m,n);

    if(m[n - 1] > sum)
    {
        cout<<"无法找零"<<endl;
        return;
    }
    while(sum >= m[n - 1])
    {
        if(sum >= m[j])
        {
            sum = sum - m[j];
            t[i] = m[j];
            i++;
        }
        else
        {
            j++;
        }
    }

    for(int k = 0; k < i; k++)
    {
        cout<<t[k]<<"   ";
    }
    cout<<endl;
}

void Maopao(float *d,int n)
{
    int i,j,flag;
    float temp;

    for(i = 0; i < n; i++)
    {
        flag = 0;
        for(j = n - 1; j > i; j--)
        {
            if(d[j] > d[j - 1])
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
