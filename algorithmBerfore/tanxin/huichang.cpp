/*************************************************************************
	> File Name: huichang.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 20时22分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

int huichang(int k,int *s,int *f);
void Maopao(int *s,int *f,int n);

int main()
{
    int k;

    cout<<"请输入待安排活动的个数："<<endl;
    cin>>k;

    int s[k];
    int f[k];
    cout<<"请分别输入活动开始时间和结束时间："<<endl;
    for(int i = 0; i < k; i++)
    {
        cin>>s[i];
        cin>>f[i];
    }
    Maopao(s,f,k);

    cout<<"使用的最少会场会场数："<<huichang(k,s,f)<<endl;

    return 0;
}

int huichang(int k,int *s,int *f)
{
    int j = 0;
    int count = 1;

    for(int i = 1; i < k; i++)
    {
        if(s[i] >= f[j])
        {
            j = i;
        }
        else
        {
            count++;
        }
    }

    return count;
}

void Maopao(int *s,int *f,int n)
{
    int i,j,flag;
    int temp1,temp2;

    for(i = 0; i < n; i++)
    {
        flag = 0;
        for(j = n - 1; j > i; j--)
        {
            if(s[j] < s[j - 1])
            {
                temp1 = f[j];
                f[j] = f[j - 1];
                f[j - 1] = temp1;
                flag = 1;
                temp2 = s[j];
                s[j] = s[j - 1];
                s[j - 1] = temp2;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}                                     
