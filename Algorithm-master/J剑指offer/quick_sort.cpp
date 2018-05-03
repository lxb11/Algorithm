#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int *data, int start, int end)
{
	if (data == NULL || start > end)
	{
		throw new std::exception("invalid input");
	}

	int index = start;
	swap(data[index], data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
			{
				swap(data[index], data[small]);
			}
		}
	}
	++small;
	swap(data[small], data[end]);
	return small;
}

void quicksort(int *data, int start, int end)
{
	if (start == end)
	{
		return;
	}
	int index = partition(data, start, end);
	if (index > start)
	{
		quicksort(data, start, index - 1);
	}
	if (index < end)
	{
		quicksort(data, index + 1, end);
	}
}

int main(void)
{
	int data[] = { 1,4,8,0,9,7,5, };
	quicksort(data, 0, 6);
	for (auto index = begin(data); index != end(data); ++index)
	{
		cout << *index << "	";
	}
	cout << endl;
	return 0;
}