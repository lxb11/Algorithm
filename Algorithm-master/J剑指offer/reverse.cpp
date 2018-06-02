#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool isEven(int n)
{
	return (n & 1) == 0;
}

void ReorderOddEven(int *data, unsigned int length, bool (*fun)(int))
{
	if (data == NULL || length <= 0)
		return;
	int *start = data;
	int *end = data + length - 1;

	while (start < end)
	{
		while (!fun(*end) && start < end)
		{
			++start;
		}
		while (fun(*start) && start < end)
		{
			--end;
		}
		if (start < end)
		{
			swap(*start, *end);
		}
	}
}

void test1()
{
	int data[] = { 1,2,3,4,5 };
	int length = sizeof(data) / sizeof(int);
	ReorderOddEven(data, length, isEven);
	for (auto index = begin(data); index != end(data); ++index)
	{
		cout << *index << "  ";
	}
	cout << endl;
}

void test2()
{
	int data[] = { 1,3,5,2,4,4 };
	int length = sizeof(data) / sizeof(int);
	ReorderOddEven(data, length, isEven);
	for (auto index = begin(data); index != end(data); ++index)
	{
		cout << *index << "  ";
	}
	cout << endl;
}

void test3()
{
	int data[] = { 2,4,6,8,1,3,5 };
	int length = sizeof(data) / sizeof(int);
	ReorderOddEven(data, length, isEven);
	for (auto index = begin(data); index != end(data); ++index)
	{
		cout << *index << "  ";
	}
	cout << endl;
}

int main()
{
	test1();
	test2();
	test3();

	return 0;
}