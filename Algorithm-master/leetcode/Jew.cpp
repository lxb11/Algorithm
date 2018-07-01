#include<stdio.h>
/*你得到的字符串J代表珠宝的石头类型，S代表你拥有的宝石。 S中的每个角色都是你拥有的一种石头。
你想知道你有多少宝石也是珠宝。

J中的字母保证不同，J和S中的所有字符都是字母。字母区分大小写，因此'a'被认为是来自'A'的不同类型的石头。
*/

/*Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:

Input: J = "z", S = "ZZ"
Output: 0
*/
int numJewelsInStones(char* J, char* S) {


	int count = 0;
	while (*S != '\0')
	{

		char *j = J;
		while (*j != '\0')
		{
			if (*S == *j)
			{
				++count;
			}
			++j;
		}
		++S;
	}
	return count;
}

int main()
{
	char *J = "aA";
	char *S = "aAAbbbb";
	printf("%d", numJewelsInStones(J, S));

	return 0;
}

