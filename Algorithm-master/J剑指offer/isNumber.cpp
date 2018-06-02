#include<iostream>
using namespace std;

bool scanUnsignInteger(const char **str)
{
	const char *before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
	{
		++(*str);
	}
	//当str中存在若干0-9的数字是，返回true
	return *str > before;//地址的比较，*str会往后移，地址增大
}

bool scanInteger(const char **str)
{
	if (**str == '+' || **str == '-')
	{
		++(*str);
	}
	return scanUnsignInteger(str);
}

bool isNumber(const char *str)
{
	if (str == NULL)
	{
		return false;
	}
	//整数部分
	bool numeric = scanInteger(&str);

	//如果出现'.'，则接下来是数字的小数部分
	if (*str == '.')
	{
		++str;
		//线面一行代码用||的原因
		//1.小数可以没有整数部分，如.123
		//2.小数点后面可以没有数字，如2223.
		//3.小数点前面和后面都可以有数字,如123.123
		numeric = scanUnsignInteger(&str) || numeric;//
	}
	//科学计数
	if (*str == 'e' || *str == 'E')
	{
		++str;
		//下面一行用&&的原因：
		//1.当e或E前面没有数字时，整个字符串不能表示数字，如.e1
		//2.当e或E后面没有整数时，同样不能表示数字，如12e，
		numeric = numeric && scanInteger(&str);
	}
	return numeric && *str == '\0';
}

void test1()
{
	char *str = "-12.3";
	cout << isNumber(str) << endl;
}

void test2()
{
	char *str = ".3e2";
	cout << isNumber(str) << endl;
}

void test3()
{
	char *str = ".345";
	cout << isNumber(str) << endl;
}

void test4()
{
	char *str = ".345e-+2";
	cout << isNumber(str) << endl;
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}
