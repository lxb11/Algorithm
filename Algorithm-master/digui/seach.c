/*************************************************************************
	> File Name: seach.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月23日 星期四 11时04分13秒
 ************************************************************************/

#include<stdio.h>
int BinarySearch(int a[],int key,int left,int right);

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(a)/sizeof(int);
    int key = 5;
    int j = BinarySearch(a,key,0,n);

    printf("%d",j);
    return 0;

}

int BinarySearch(int a[],int key,int left,int right)
{
    if(left > right)
    {
        return -1;
    }
    else
    {
        int middle = (left + right) / 2;
        if(key == a[middle]) 
        {
            return middle;
        }
        if(key < a[middle]) 
        {
            return BinarySearch(a,key,left,middle + 1);
        }
        else return BinarySearch(a,key,middle - 1,right);
    }
}
