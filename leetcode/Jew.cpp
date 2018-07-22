#include<stdio.h>
/*��õ����ַ���J�����鱦��ʯͷ���ͣ�S������ӵ�еı�ʯ�� S�е�ÿ����ɫ������ӵ�е�һ��ʯͷ��
����֪�����ж��ٱ�ʯҲ���鱦��

J�е���ĸ��֤��ͬ��J��S�е������ַ�������ĸ����ĸ���ִ�Сд�����'a'����Ϊ������'A'�Ĳ�ͬ���͵�ʯͷ��
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

