#include<iostream>
/*
动态规划：礼物的最大值
maxValues[]前面j个数字分别是当前第i行前面j各个子礼物的最大值
之后的数字保存前面i-1行n-j个格子礼物的最大价值
*/

int getMaxValue(const int* value, int rows, int cols)
{
	if (value == NULL || rows <= 0 || cols <= 0)
	{
		return 0;
	}

	int* maxValues = new int[cols];
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			int up = 0;
			int left = 0;
			if (i > 0)
			{
				up = maxValues[j];
			}
			if (j > 0)
			{
				left = maxValues[j - 1];
			}
			maxValues[j] = std::_Max_value(up, left) + value[i * cols + j];
		}
	}
	int maxValue = maxValues[cols - 1];
	delete[]maxValues;
	return maxValue;
}

void test0()
{
	int value[] = { 1,10,3,8,
		12,3,9,6,
		5,7,4,11,
		3,7,16,5 };
	int rows = 4;
	int cols = 4;
	std::cout << getMaxValue(value, rows, cols) << "    ";
}

void test1()
{
	int value[] = { 1 };
	int rows = 1;
	int cols = 1;
	std::cout << getMaxValue(value, rows, cols) << "    ";
}

void test2()
{
	int value[] = { 1,10,3,8 };
	int rows = 1;
	int cols = 4;
	std::cout << getMaxValue(value, rows, cols) << "    ";
}

void test3()
{
	int value[] = { 1,
		10,
		3,
		8 };
	int rows = 4;
	int cols = 1;
	std::cout << getMaxValue(value, rows, cols) << "    ";
}

int main()
{
	test0();
	test1();
	test2();
	test3();
	return 0;
}