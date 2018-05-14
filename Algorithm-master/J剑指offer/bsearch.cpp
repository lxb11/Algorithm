//旋转数组的最小数字
#include<iostream>
using namespace std;

int order(int *data, int start, int end)
{
	if (NULL == data || start > end)
	{
		throw new std::exception("invalid input");
	}
	int min = data[start];
	for (int i = start + 1; i <= end; ++i)
	{
		if (min > data[i])
		{
			min = data[i];
		}
	}
	return min;
}

int bsearch(int *data, int length)
{
	if (NULL == data || length < 0)
	{
		throw new std::exception("invalid input!");
	}

	int start = 0;
	int end = length - 1;
	int mid = start;

	while (data[start] >= data[end])
	{
		if (end - start == 1)
		{
			mid = end;
			break;
		}

		mid = (start + end) / 2;
			
		//如果下表为start和end，mid三个值相等，调用order函数顺序查找

		if (data[start] == data[mid] && data[end] == data[start])
		{
			return order(data, start, end);
		}
		if (data[mid] >= data[start])
		{
			start = mid;
		}
		else if (data[mid] <= data[end])
		{
			end = mid;
		}
	}
	return data[mid];
}

int main()
{
	int data[] = { 5,6,7,1,3,4, };
	cout << bsearch(data, 6) << endl;

	return 0;
}