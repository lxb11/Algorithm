/*************************************************************************
	> File Name: numde.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月20日 星期一 20时46分23秒
 ************************************************************************/

#include<stdio.h>
int q(int n,int m);

int main()
{
    int n,m;
    printf("请输入要分解的整数\n");
    scanf("%d",&n);
    printf("请输入最大加数\n");
    scanf("%d",&m);
    int s=q(n,m);
    printf("共有%d种分法！",s);
    putchar(10);
    return 0;
}

int q(int n, int m)
{

    if((n < 1)||(m < 1)) return 0;
    if((n == 1)||(m == 1)) return 1;
    if(n < m) return q(n,n);
    if(n == m) return q(n,m - 1) + 1;
    return q(n,m - 1) + q(n - m,m);

}                                     
