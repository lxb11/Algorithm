/*************************************************************************
	> File Name: car.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年05月09日 星期二 17时11分41秒
 ************************************************************************/

#include<iostream>
using namespace std;

int car(int n,int k,int *m);

int main()
{
    int n;
    int k;
    cout<<"请输入汽车满油后所能行使得距离："<<endl;
    cin>>n;
    cout<<"请输入加油站总数："<<endl;
    cin>>k;

    int m[k + 1];
    cout<<"请分别输入相邻加油站之间的距离："<<endl;
    for(int i = 0; i < k + 1; i++)
    {
        cin>>m[i];
    }
    cout<<"最少加油次数："<<car(n,k,m)<<endl;
}

int car(int n,int k,int *m)
{
    int sum1 = 0;
    int sum2 = 0;
    int j = 0;
    int count = 0;

    while(k >= j)
    {
        if(sum1 <= k && sum2 > k)
        {
            sum1 = 0;
            sum2 = 0;
            count++;
        }
        else
        {
            sum1 = sum1 + m[j];
            sum2 = sum1 + m[j + 1];
            j++;
        }
    }



    return count;
}
