#include<iostream>	
#include<random>
#include<functional>
#include<Windows.h>
using namespace std;

void make_numbers(int *arr, int length)//�����������
{
	random_device rd;
	default_random_engine engine(rd());
	uniform_int_distribution<> dis(1, length - 1);
	auto dice = bind(dis, engine);
	for (int i = 0; i < length; ++i)
	{
		arr[i] = dice();
	}
}

bool find_same(int *arr, int length, int *real)//����Ϊn���������������ֶ���0-n-1��Χ���ҳ��������е��ظ�����
{
	if (arr == NULL || length < 0)
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] < 0 || arr[i] > length - 1)
		{
			return false;
		}
	}
	for (int i = 0; i < length; ++i)
	{
		while (arr[i] != i)
		{
			if (arr[i] == arr[arr[i]])
			{
				*real = arr[i];//�ҵ��ظ�����
				return true;
			}
			else
			{
				int temp = arr[i];
				arr[i] = arr[temp];
				arr[temp] = temp;
			}
		}
	}
}

int count_num(int *arr, int length, int start, int end)//����Ϊn+1�����������ַ�ΧΪ1-�㣬�ҳ����������ظ�����
{
	if (arr == NULL || length < 0)
	{
		return -1;
	}
	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] >= start && arr[i] <= end)
		{
			++count;
		}
	}
	return count;
}
int find_any_same(int *arr, int length)//����Ϊn+1�����������ַ�ΧΪ1-�㣬�ҳ����������ظ�����
{
	if (arr == NULL || length < 1)
	{
		return -1;
	}
	int start = 1;
	int end = length - 1;
	while (start <= end)
	{
		int middle = ((end - start) >> 1) + start;
		int count = count_num(arr, length, start, middle);
		if (end == start)
		{
			if (count > 1)
			{
				return end;
			}
			else
			{
				break;
			}
		}
		if (count > (middle - start + 1))
		{
			end = middle;
		}
		else
		{
			start = middle + 1;
		}
	}
	return -1;
}

int main(void)
{
	int n = 0;//���鳤��n
	cout << "�����������С" << endl;
	cin >> n;
	int *arr = new int[n];
	make_numbers(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] <<"  ";
	}
	cout << endl;
	//int *real = new int[1];
	//if (find_same(arr, n, real))
	//{
	//	cout << *real << endl;
	//}
	

	cout << find_any_same(arr, n);

	system("pause");
	return 0;
}





