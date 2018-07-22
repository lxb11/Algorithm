void bubble_sort(int *a, int size)//冒泡排序
{
	assert(a);

	for (int i = 0; i < size - 1; ++i)
	{
		int flag = 0;
		for (int j = 0; j < size - 1; ++j)
		{
			if (a[j + 1] < a[j])
			{
				swap(a[j + 1], a[j]);
				flag = 1;
			}
		}
		if (0 == flag)//本次循环没有交换，则序列已经有序
		{
			break;
		}
	}

}