#include<iostream>
using namespace std;

bool scanUnsignInteger(const char **str)
{
	const char *before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
	{
		++(*str);
	}
	//��str�д�������0-9�������ǣ�����true
	return *str > before;//��ַ�ıȽϣ�*str�������ƣ���ַ����
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
	//��������
	bool numeric = scanInteger(&str);

	//�������'.'��������������ֵ�С������
	if (*str == '.')
	{
		++str;
		//����һ�д�����||��ԭ��
		//1.С������û���������֣���.123
		//2.С����������û�����֣���2223.
		//3.С����ǰ��ͺ��涼����������,��123.123
		numeric = scanUnsignInteger(&str) || numeric;//
	}
	//��ѧ����
	if (*str == 'e' || *str == 'E')
	{
		++str;
		//����һ����&&��ԭ��
		//1.��e��Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣���.e1
		//2.��e��E����û������ʱ��ͬ�����ܱ�ʾ���֣���12e��
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
