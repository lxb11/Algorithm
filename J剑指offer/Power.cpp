#include<iostream>
using namespace std;

bool InvalidInput = false;//������ʾ
int equal(double first, double second)
{
	if ((first - second) < (1E-7) && (second - first) < (1E-7))
	{
		return 1;
	}
	return 0;
}


double PowerWithUnsignedExponent(double base, int exponent)//��ȷ����Ч�Ľⷨ
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

double PowerWithUnsignedExponentEffect(double base, int exponent)//��ȷ��Ч��д��
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
//a^n = a^(2/n) * a^(2/n)  nΪż��
//a^n = a^((n-1)/2) * a^((n-1)/2)   nΪ����
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


