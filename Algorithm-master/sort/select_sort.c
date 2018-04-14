void select_sort(int *a, int size)
{
	int min_seek = 0;//最小值的下标
	for (int i = 0; i < size; ++i)
	{
		int min = a[i];
		for (int j = i; j < size; ++j)//找出a[i]-a[size]中的最小元素
		{
			if (a[j] < min)
			{
				min = a[j];
				min_seek = j;
			}
		}
		a[min_seek] = a[i];//a[0] - a[i-1]有序，a[i] - a[size]无序，最小值与a[i]交换。
		a[i] = min;
		//交换完毕后a[0] - a[i + 1]有序
	}
}