/*************************************************************************
	> File Name: Perm.c
	> Author: 
	> Mail: 
	> Created Time: 2017年04月09日 星期日 16时43分43秒
 ************************************************************************/

#include<stdio.h>
void Perm(int list[],int k,int m);
void Swap(int a,int b);

int main()
{
    int list[5] = {1,2,3,4,5};
    Perm(list,0,4);
    return 0;
}

void Perm(int list[],int k,int m) //产生list[k：m]的所有序列
{
    if(k == m)
    {
        for(int i = 0;i <= m;i++)//只剩1个元素
        {
            printf("%-2d",list[i]);
        }
        putchar(10);
    }
    else//还有多各院素待排列，递归产生排列
    {
        for(int i = k;i <= m;i++)
        {
            Swap(list[k],list[i]);
            Perm(list,k + 1,m);
            Swap(list[k],list[i]);       
        }
    }

}

void Swap(int a,int b)
{
    int temp = a;
    a = b;
    b =temp;
}
