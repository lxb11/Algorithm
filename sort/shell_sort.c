void shell_sort(int *a, int size, int d)//d为步长,与直接插入排序类似。
{
	assert(a);

	for (int i = d; i < size; ++i)
	{
		int j = i - d;
		int temp = a[i];
		if (a[i] < a[i - d])
		{
			while (a[j] > temp && j >= 0)
			{
				a[j + d] = a[j];
				j = j - d;
			}
			a[j + d] = temp;
		}
	}
}