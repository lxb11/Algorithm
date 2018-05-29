#include<iostream>
using namespace std;

/*实现一个函数用来匹配包含'.'和'*'的正则表达式。
模式中的字符'.'表示一个字符,而'*'表示他前面的字
符可以出现任意次（含0次）。例如“aaa”与模式'a.a'
和“ab*ac*a”匹配*/


bool matchCore(char *str, char *pattern)
{
	if (*str == '\0' && *pattern == '\0')//匹配成功
	{
		return true;
	}

	if (*str != '\0' && *pattern == '\0')//匹配失败
	{
		return false;
	}

	if (*(pattern + 1) == '*')//第二个字符是*的情况
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