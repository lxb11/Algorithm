#include<iostream>
using namespace std;

//��̬�滮�������
int maxProductAfterCutting(int length)
{
	if (length < 2)//���ӳ���>1
	{
		return 0; 
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}

	int *product = new int[length + 1];
	
	product[0] = 0;
	product[1] = 1;
	product[2] = 2;
	product[3] = 3;

	int max = 0;

	for (int i = 4; i <= length; ++i)
	{
		max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			int tmp = product[j] * product[i - j];
			if (max < tmp)
			{
				max = tmp;
			}
			product[i] = max;
		}
	}
	max = product[length];
	delete[]product;

	return max;
}

int greedMaxProductAfterCutting(int length)
{
	if (length < 2)//���ӳ���>1
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}
	//�����ܶ�ļ�ȥ����Ϊ3�����Ӷ�
	int timesOf3 = length / 3;
	//���������ʣ�µĳ���Ϊ4��ʱ�򣬲����ټ�ȥ����Ϊ3�����Ӷ�
	//2 * 2  > 3 * 1 
	if (length - timesOf3 * 3 == 1)
	{
		timesOf3 -= 1;
	}
	int timesOf2 = (length - 3 * timesOf3) / 2;

	return (int)(pow(3, timesOf3) * pow(2, timesOf2));
}



int main()
{

	int length1 = 10;
	int length2 = 3;
	int length3 = 0;
	cout << maxProductAfterCutting(length1) << "   " << greedMaxProductAfterCutting(length1) << endl;
	cout << maxProductAfterCutting(length2) << "   " << greedMaxProductAfterCutting(length2) << endl;
	cout << maxProductAfterCutting(length3) << "   " << greedMaxProductAfterCutting(length3) << endl;

	

	return 0;
}

