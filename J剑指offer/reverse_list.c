List ReverseList(List L)//��ת����
{
	if (NULL == L->next || NULL == L->next->next)
	{
		return L;
	}
	List tmp = L->next;
	List tmp0 = tmp->next;
	List tmp1 = tmp0->next;
	L->next->next = NULL;//��ͷ���ĵ�һ���ڵ�next = null
	while (1)
	{
		tmp0->next = tmp;
		if (NULL == tmp1)
		{
			L->next = tmp0;
			return L;
		}
		tmp = tmp0;
		tmp0 = tmp1;
		tmp1 = tmp1->next;
	}
}