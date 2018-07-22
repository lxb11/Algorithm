#include<iostream>
using namespace std;

/*ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
ģʽ�е��ַ�'.'��ʾһ���ַ�,��'*'��ʾ��ǰ�����
�����Գ�������Σ���0�Σ������硰aaa����ģʽ'a.a'
�͡�ab*ac*a��ƥ��*/


bool matchCore(char *str, char *pattern)
{
	if (*str == '\0' && *pattern == '\0')//ƥ��ɹ�
	{
		return true;
	}

	if (*str != '\0' && *pattern == '\0')//ƥ��ʧ��
	{
		return false;
	}

	if (*(pattern + 1) == '*')//�ڶ����ַ���*�����
	{
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
		{			//ignore a'*'
			return matchCore(str, pattern + 2)
				//move on the next state
				|| matchCore(str + 1, pattern + 2)
				//stay on the current state
				|| matchCore(str + 1, pattern);
		}
		else
			//ignore a'*'
			return matchCore(str, pattern + 2);
	}
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
	{
		return matchCore(str + 1, pattern + 1);
	}
	return false;
}

bool match(char *str, char *pattern)
{
	if (str == NULL || pattern == NULL)
	{
		return false;
	}
	return matchCore(str, pattern);
}

void test1()
{
	char *str = "aaa";
	char *pattern = "ab*ac*a";
	cout << match(str, pattern) << endl;
}

void test2()
{
	char *str = "";
	char *pattern = "*";
	cout << match(str, pattern) << endl;
}

void test3()
{
	char *str = "a";
	char *pattern = ".";
	cout << match(str, pattern) << endl;
}

void test4()
{
	char *str = "a";
	char *pattern = "*";
	cout << match(str, pattern) << endl;
}

int main()
{
	test1();
	test2();
	test3();
	test4();

	return 0;
}