#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void adjustHeap(int *data, int parent, int size)
{
	int max = parent;
	for (int i = (parent + 1) * 2 - 1; i <= size; i = (max + 1) * 2 - 1)
	{
		if (i + 1 <= size && data[i] < data[i + 1])
		{
			max = i + 1;
		}
		else
		{
			max = i;
		}
		if (data[max] < data[parent])
		{
			break;
		}
		swap(data[max], data[parent]);
		parent = max;
	}
}

void createHeap(int *data, int size)
{
	for (int i = (size - 1) / 2; i >= 0; --i)
	{
		adjustHeap(data, i, size);
	}
}

void heapSort(int *data, int size)
{
	createHeap(data, size);

	for (int i = 0; i < size; ++i)
	{
		swap(data[0], data[size - i]);
		adjustHeap(data, 0, size - i - 1);
	}
}

int main()
{
	int data[] = { 1,25,2,7,2,0,1,7 };
	int length = sizeof(data) / sizeof(int);
	heapSort(data, length - 1);
	for (auto index = begin(data); index != end(data); ++index)
	{
		cout << *index << "    ";
	}
	cout << endl;
	return 0;
}
