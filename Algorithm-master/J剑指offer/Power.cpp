#include<iostream>
using namespace std;

bool InvalidInput = false;//错误提示
int equal(double first, double second)
{
	if ((first - second) < (1E-7) && (second - first) < (1E-7))
	{
		return 1;
	}
	return 0;
}


double PowerWithUnsignedExponent(double base, int exponent)//正确不高效的解法
{
	if (exponent == 0)
	{
		return 1.0;
	}
	for (int i = 1; i < exponent; ++i)
	{
		 base *= base;
	}
	return base;
}

double PowerWithUnsignedExponentEffect(double base, int exponent)//正确高效的写法
{
	if (exponent == 0)
	{
		return 0.0;
	}
	if (exponent == 1)
	{
		return base;
	}
	
	double result = PowerWithUnsignedExponentEffect(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1 == 1)
	{
		result *= result;
	}
	return result;
}
//a^n = a^(2/n) * a^(2/n)  n为偶数
//a^n = a^((n-1)/2) * a^((n-1)/2)   n为奇数
//

double Power(double base, int exponent)
{
	if (equal(base, 0.0) && exponent < 0)
	{
		InvalidInput = true;
		return 0.0;
	}

	unsigned int abs = (unsigned int)exponent;
	if (exponent < 0)
	{
		abs = (unsigned int)(-exponent);
	}
	double result = PowerWithUnsignedExponentEffect(base, abs);
	if (exponent < 0)
	{
		result = 1 / result;
	}
	return result;
}


int main()
{
	cout << Power(-0.25, -1) << endl;

}


