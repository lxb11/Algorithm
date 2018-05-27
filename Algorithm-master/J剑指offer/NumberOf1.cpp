#include<iostream>
using namespace std;

int NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1) & n;
	}
	return count;
}

int main()
{
	int n = 0xf;
	cout << NumberOf1(n)<<endl;
	return 0;
}