int partition(int *a, int i, int j)//划分算法
{
	int temp = a[i];//暂存基准记录
	while (i < j)//从表（即序列a[i]-a[j]）的两端交替向中间扫描
	{
		while (i < j && a[j] >= temp)
			//从右向左扫描查找第一个关键字小于temp 的记录a[j]
		{
			--j;
		}
		if (i < j)
		{
			a[i] = a[j];
			++i;
		}
		while (i < j && a[i] <= temp)
			//从左向右扫描查找第一个关键字大于temp 的记录a[i]
		{
			++i;
		}
		if (i < j)
		{
			a[j] = a[i];
		}
	}
	a[i] = temp;
	return i;//返回基准记录a[0]最终放置的位置

}

void quik_sort(int *a, int s, int t)
{
	int i;
	if (s < t)
	{
		i = partition(a, s, t);//i为基准记录的位置并由此位置将表分为a[s]-a[i-1],a[i+1]-a[t]两部分
		quik_sort(a, s, i - 1);//对表a[s]-a[i-1]进行快速排序
		quik_sort(a, i + 1, t);
	}
}