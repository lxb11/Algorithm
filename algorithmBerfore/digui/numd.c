#include<stdio.h>
void display(int n);
void split(int n,int m);
int x[50] = {0};

int main()
{
    int n;
    printf("please input 'n'(0 < n < 100)\n");
    scanf("%d",&n);
    split(n,0);
    return 0;
}

void display(int m)
{
    int i;
    for(i = 0;i < m;i++)
    {
        printf("%-2d",x[i]);
    }
    putchar(10);

}

void split(int n,int m)
{
    int i;
    if(0 == n)
    {
        display(m);
    }
    else
    {
        for(i = n;i > 0;i--)
        if(0 == m || i <= x[m - 1])
        {
            x[m] = i;
            split(n - i,m + 1);
        }
    }
}
