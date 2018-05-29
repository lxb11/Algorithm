#include<iostream>
using namespace std;

void PrintNumber(char *number)//从第一个非零的字符打印
{
	bool isBeginning0 = true;
	int nlength = strlen(number);

	for (int i = 0; i < nlength; ++i)
	{
		if (isBeginning0 && number[i] != '0')
		{
			isBeginning0 = false;
		}

		if (!isBeginning0)
		{
			cout << number[i];
		}
	}
	cout << "    ";
}

void Print1ToMaxOfNDigitsRecursion(char *number, int length, int index)//递归打印全排列
{
	if (index == length)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		number[index] = i + '0';
		Print1ToMaxOfNDigitsRecursion(number, length, index + 1);
	}
}

void Print1ToMaxOfDigits(int n)
{
	if (n <= 0)
	{
		return;
	}

	char *number = new char[n + 1];
	number[n] = '\0';

	Print1ToMaxOfNDigitsRecursion(number, n, 0);
	
	delete[]number;
}

int main()
{
	Print1ToMaxOfDigits(0);
	Print1ToMaxOfDigits(2);
	return 0;
}