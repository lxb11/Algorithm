/*************************************************************************
	> File Name: bubbleSort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月21日 星期六 23时29分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(int *data, int length)
{
    bool flag = false;
    int sortbroud = length - 1;
    int last_swap = 0;
    for(int i = 0; i < length; ++i)
    {
        for(int j = 0 ; j < sortbroud; ++j)
        {
            if(data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
                flag = true; 
                last_swap = j;
            }
        }
        sortbroud = last_swap;
        if(!flag)
        {
            break;
        }
    }
}

int main()
{
    int data[] = { 6,1,7,3,5,9,0 };

    int length = sizeof(data) / sizeof(int);
    bubbleSort(data, length);

    for(auto index = begin(data); index != end(data); ++index)
    {
        cout << *index << "  ";
    }
    cout << endl;
    return 0;
}
