#include<iostream>
using namespace std;

template<typename T>
T partition(T *data, T left, T right)
{
	if (data == NULL || right < left)
	{
		return -1;
	}

	T tmp = data[left];
	while (left < right)
	{
		while (left < right && data[right] >= tmp)
		{
			--right;
		}
		data[left] = data[right];
		while (left < right && data[left] <= tmp)
		{
			++left;
		}
		data[right] = data[left];
	}
	data[left] = tmp;
	return left;
}

template<typename T>
void sort(T *data, T left, T right)
{
	if (data == NULL || left >= right)//“Ï≥£
	{
		return;
	}

	T position = partition(data, left, right);
	sort(data, left, position - 1);
	sort(data, position + 1, right);
}

template<typename T>
void quikSort(T *data, T length)
{
	if (data == NULL || length <= 0)
	{
		return;
	}

	
	sort(data, 0, length - 1);
}

int main()
{
	int data[] = { 2,3,1,5,8,2,9,0 };
	int length = sizeof(data) / sizeof(int);
	quikSort(data, length);
	for (auto index = begin(data); index != end(data); ++index)
	{
		cout << *index << "  ";
	}
	cout << endl;
	return 0;
}