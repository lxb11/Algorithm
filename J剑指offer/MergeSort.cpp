#include<iostream>
#include<assert.h>
using namespace std;

//把data[start - mid] 与 data[mid + 1  - end]合并到tmp[]中
//再将排好序的tmp[]赋值给data[start - end]
void MergeSortData(int *data, int start, int mid, int end, int *tmp)
{
	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end)
	{
		if (data[i] < data[j])
		{
			tmp[k] = data[i];
			++k;
			++i;
		}
		else
		{
			tmp[k] = data[j];
			++k;
			++j;
		}
	}
	while (i <= mid)
	{
		tmp[k] = data[i];
		++k;
		++i;
	}
	while (j <= end)
	{
		tmp[k] = data[j];
		++k;
		++j;
	}
	for (int i = 0; i < k; ++i)
	{
		data[start + i] = tmp[i];
	}

}

void Merge(int *data, int start, int end, int *tmp)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		Merge(data, start, mid, tmp);
		Merge(data, mid + 1, end, tmp);
		MergeSortData(data, start, mid, end, tmp);
	}
}

void MergeSort(int *data, int length)
{
	int start = 0;
	int end = length - 1;
	int *tmp = new int[length];
	assert(tmp);
	Merge(data, start, end, tmp);
	delete[]tmp;
}

int main()
{
	int data[] = { 3,5,8,2,1,4,7 };
	int length = sizeof(data) / sizeof(int);
	MergeSort(data, length);
	for (int i = 0; i < length; ++i)
	{
		cout << data[i] << "  ";
	}
	cout << endl;
}