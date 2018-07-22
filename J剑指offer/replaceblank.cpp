//从后往前遍历，时间复杂度小
#include<iostream>
#include<assert.h>
using namespace std;

#define N 100

void replaceblank(char *string, int length)
{
	assert(string);
	int blank_count = 0;
	int real_length = strlen(string);
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			++blank_count;
		}
		++i;
	}
	int new_length = real_length + blank_count * 2;
	if (new_length > length)
	{
		return;
	}

	while(new_length >= 0 && new_length > real_length)
	{
		if (string[i] != ' ')
		{
			string[new_length--] = string[real_length--];
		}
		else
		{
			string[new_length--] = '0';
			string[new_length--] = '2';
			string[new_length--] = '%';
			--real_length;
		}
		--i;
	}
}

int main()
{
	char string[N] = "we are happy";
	replaceblank(string, N);
	int i = 0;
	while (string[i] != '\0')
	{
		cout << string[i];
		++i;
	}
	cout << endl;
	return 0;
}