/*************************************************************************
	> File Name: Maopao.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月06日 星期六 21时52分53秒
 ************************************************************************/

#include<stdio.h>
void Maopao(int *d,int n);
int main()
{
    int a[] = {1,4,6,2,5,3};
    Maopao(a,sizeof(a) / sizeof(int));
    for(int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        printf("%-4d",a[i]);
    }
    putchar(10);
    return 0;
}
void Maopao(int *d,int n)
{
    int i,j,k;
    int temp;

    for(i = 0; i < n - 1; i++)
    {
        k = i;
        for(j = i + 1; j < n; j++)
        {
            if(d[k] <= d[j])
            {
                k = j;
            }
            if(k != i)
            {
                temp = d[i];
                d[i] = d[k];
                d[k] = temp;
            }
        }
    }
}
