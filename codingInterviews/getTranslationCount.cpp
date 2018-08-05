#include<iostream>
#include<string>
using namespace std;

/*
°ÑÊý×Ö·­Òë³É×Ö·û´®  0 -> a£»25 -> z£»
*/


int GetTranslationCount(int number);
int GetTranslationCount(const string & str);

int GetTranslationCount(int number)
{
	if (number < 0)
		return 0;
	string numericInString = to_string(number);
	return GetTranslationCount(numericInString);
}

int GetTranslationCount(const string & str)
{
	int length = str.length();
	int *counts = new int[length];
	int count = 0;

	for (int i = length - 1; i >= 0; --i)
	{
		if (i < length - 1)
			count = counts[i + 1];
		else
			count = 1;

		if (i < length - 1)
		{
			int digit1 = str[i] - '0';
			int digit2 = str[i + 1] - '0';
			int converted = digit1 * 10 + digit2;
			if (converted >= 10 && converted <= 25)
			{
				if (i < length - 2)
					count += counts[i + 2];
				else
					++count;
			}

		}
		counts[i] = count;
	}
	delete[]counts;
	return count;
}

void test()
{
	int number0 = 111111;
	int number1 = 112258;
	int number2 = 0;
	int number3 = 3;
	cout << GetTranslationCount(number0) << "  ";
	cout << GetTranslationCount(number1) << "  ";
	cout << GetTranslationCount(number2) << "  ";
	cout << GetTranslationCount(number3) << "  ";
}

int main()
{
	test();
	cout << endl;
	getchar();
	return 0;
}
