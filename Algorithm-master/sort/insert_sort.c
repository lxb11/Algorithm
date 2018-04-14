void insert_sort(int *a, int size)
{
	assert(a);

	for (int i = 1; i < size; ++i)//进行n-1趟排序
	{
		int j = i - 1;
		int temp = a[i];
		if (a[i] < a[j])//小于a[i - 1],将i插入到有序序列a[0]-a[i-1]中
		{
			while (a[j] > temp && j >= 0)//将值大的顺移到后面
			{
				a[j + 1] = a[j];
				--j;
			}
			a[j + 1] = temp;//插入a[i]
		}
		
	}
}