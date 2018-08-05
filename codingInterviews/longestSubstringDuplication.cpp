#include<iostream>

/*
最长不含重复字符的子字符串
*/

int longestSubstringWithDuplication(const std::string& str)
{
	int curLength = 0;
	int maxLength = 0;

	int *position = new int[26];
	memset(position, -1, sizeof(position));

	for (int i = 0; i < str.length(); ++i)
	{
		int preIndex = position[str[i] - 'a'];
		int distance = i - preIndex;
		if (preIndex < 0 || distance > curLength)
			++curLength;
		else
		{
			if (curLength > maxLength)
				maxLength = curLength;
	
			curLength = distance;
		}
		position[str[i] - 'a'] = i;
	}
	if (curLength > maxLength)
	{
		maxLength = curLength;
	}
	delete[]position;
	return maxLength;
}

void test()
{
	std::string str0 = "aaa";
	std::string str1 = "a";
	std::string str2 = "arabcacfr";

	std::cout << longestSubstringWithDuplication(str0) << "  ";
	std::cout << longestSubstringWithDuplication(str1) << "  ";
	std::cout << longestSubstringWithDuplication(str2) << "  ";
}

int main()
{
	test();
	return 0;
}