#define _CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"

void menus()
{
	printf("********************************************************************\n");
	printf("*                                                                  *\n");
	printf("*                                                                  *\n");
	printf("*************************menus**************************************\n");
	printf("* 0、退出                               1、单链表初始化            *\n");
	printf("* 2、头插法构造单链表                   3、尾插法构建单链表        *\n");
	printf("* 4、销毁单链表                         5、清空单链表              *\n");
	printf("* 6、判断空单链表                       7、统计单链表长            *\n");
	printf("* 8、寻找单链表第i位元素                9、寻找单链表中e元素的位置 *\n");
	printf("*10、在单链表第i位插入e元素             11、删除单链表中的e元素    *\n");
	printf("*12、删除单链表第i位元素                13、单链表中奇、偶序对调   *\n");
	printf("*14、单链表中点                         15、判断单链表是否成环     *\n");
	printf("*16、非递归反转链表                     17、递归反转链表           *\n");
	printf("*18、初始化双向链表                     19、头指针构造双向链表     *\n");
	printf("*20、尾插法构造双向链表                 21、销毁双向链表           *\n");
	printf("*22、清空双向链表                       23、寻找前驱元素           *\n");
	printf("*24、在双向链表第i位插入元素            25、删除双向链表的e元素    *\n");
	printf("*26、删除双向链表的第i位元素            27、构造循环链表           *\n");            
	printf("********************************************************************\n");
}

void print(Status c)
{
	if (c == OK)
		printf("操作成功！\n");
	else
			printf("操作失败，请重试！\n");
}

ListN  InitList()
{
	ListN L = (ListNode*)malloc(sizeof(ListNode));


	if (!L)
		return ERROR;
	//判断空间是否开辟成功（！！！）
	//想到另一种写法
	/*
	do{
	L=(ListNode*)malloc(sizeof(ListNode));
	}while(!L)
	但是发现如果一直开辟不成功，就一直循环？？？
	*/

	L->next = NULL;

	return L;

}

Status CreateList1(ListN L, int n)
{
	if (!L || n <= 0)
		return ERROR;

	ListN p = NULL;

	while (n--)
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		if (!p)
			n++;
		else {
			printf("请输入元素值：");
			scanf("%d", &p->data);
			p->next = L->next;
			L->next = p;
		}
	}

	p = NULL;

	return OK;

}

Status CreateList2(ListN L, int n)
{
	if (!L || n <= 0)
		return ERROR;

	ListN p = NULL;
	ListN rear = NULL;

	rear = L;

	while (n--)
	{
		p = (ListNode*)malloc(sizeof(ListNode));
		if (!p)
			n++;
		else
		{
			printf("请输入元素值：");
			scanf("%d", &p->data);
			rear->next = p;
			rear = p;
			rear->next = NULL;
		}
	}

	p = NULL;
	rear = NULL;

	return OK;

}

Status DestroyList(ListN* L)
{
	if(!(*L))
		return OK;

	ListN p = NULL;


	while (*L)
	{
		p = *L;
		*L = (*L)->next;
		free(p);
	}

	return OK;

}

Status ClearList(ListN L)
{
	if (!L)
		return ERROR;

	if (!L->next)
		return OK;

	ListN p = NULL;
	ListN q =NULL;

	p = L->next;

	while (p)
	{
		L->next = p->next;
		q = p;
		if (q)
		{
			q = NULL;
			free(q);
		}
		p = L->next;
	}

	return OK;

}

bool List_IsEmpty(ListN L)
{
	if (!L)
		exit(0);

	if (!L->next)
		return true;
	else
		return false;

}

int ListLength(ListN L)
{
	if (!L)
		return 0;

	ListN p = NULL;

	p = L;

	int len = 0;

	while (p)
	{
		p = p->next;
		len++;
	}

	return len-1;
}

Status GetElem(ListN L, int i, ElemType* e)
{
	if (!L)
		return ERROR;

	ListN p = NULL;
	int j = 0;

	p = L->next;

	while (p &&j<i-1)
	{
		p = p->next;
		j++;
	}

	if (!p || j > i - 1)
		return ERROR;

	*e= p->data;

	return OK;

}

int LocateElem(ListN L, ElemType e)
{
	if (!L)
		return -1;

	ListN p = NULL;
	int i = 1;

	p = L->next;

	while (p)
	{
		if (p->data == e)
			return i;
		p = p->next;
		i++;
	}

	return -1;

}

Status InsertElem(ListN L, ElemType e, int i)
{
	if (!L)
		return ERROR;

	ListN p = NULL;
	ListN q = NULL;
	int j = 0;

	p = L;

	q = (ListNode*)malloc(sizeof(ListNode));

	if (!q)
		return ERROR;

	q->data = e;

	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}

	if (!p || j > i - 1)
		return ERROR;

	q->next = p->next;
	p->next = q;

	return OK;

}

Status DeleteElem1(ListN L, ElemType e)
{
	if (!L)
		return ERROR;

	ListN p = NULL;
	ListN q = NULL;
	int num = 0;

	p = L;
	num = LocateElem(L, e);
	num--;

	while (num--)
	{
		p = p->next;
	}

	q = p->next;
	p->next = q->next;
	free(q);
	q = NULL;
	p = NULL;

	return OK;

}

Status DeleteElem2(ListN L, int i)
{
	if (!L)
		return ERROR;

	ListN p = NULL;
	ListN q = NULL;
	int j = 0;

	p = L;

	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}

	if (!p || j > i - 1)
		return ERROR;

	q = p->next;
	p->next = q->next;
	free(q);
	q = NULL;

	return OK;

}

Status Exchange(ListN L)
{
	if (!L || !L->next)
		return ERROR;

	if (ListLength(L) == 1)
		return ERROR;

	ListN odd = NULL;
	ListN even = NULL;

	odd = L->next;
	even = odd->next;

	while (odd && even)
	{
		ElemType e;
		e = odd->data;
		odd->data = even->data;
		even->data = e;

		if (odd->next)
			odd = odd->next->next;
		else
			break;

		if (even->next)
			even = even->next->next;
		else
			break;
	}

	return OK;

}

ListN LocateMidpoint(ListN L)
{
	if (!L)
		return NULL;

	if (ListLength(L) <= 1)
		return L;

	ListN fast = NULL;
	ListN slow = NULL;

	fast = L->next;
	slow = L;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	if (!fast)
		return slow;
	else
		return slow->next; 
}

bool IsCircle_List(ListN L)
{
	if (!L)
		return false;

	if (L == L->next)
		return true;

	ListN fast = NULL;
	ListN slow = NULL;

	fast = L->next;
	slow = L;

	while (fast && fast->next)
	{
		if (slow == fast)
			return true;
		fast = fast->next->next;
		slow = slow->next;
	}

	return false;
}

ListN ReverseList1(ListN L)
{
	if (!L || !L->next)
		return L;

	ListN pre = NULL;
	ListN cur = NULL;

	cur = L;

	while (cur)
	{
		ListN p = NULL;

		p = cur;
		cur = cur->next;
		p->next = pre;
		pre = p;

	}

	return pre;
}

ListN ReverseList2(ListN pre, ListN cur)
{
	if (!cur)
		return pre;
	else
	{
		ListN p = NULL;

		p = cur->next;
		cur->next = pre;
		pre = p;
		return ReverseList2(cur, pre);
	}
}


twoL Init_two_ways_List()
{
	twoL L = (twoL)malloc(sizeof(two_ListNode));

	if (!L)
		return NULL;

	L->next = NULL;
	L->prior = NULL;
	return L;
}


Status Create_two_ways_List1(twoL L, int n)
{
	if (!L || n <= 0)
		return ERROR;

	twoL p = NULL;

	while (n--)
	{
		p = (twoL)malloc(sizeof(two_ListNode));
		if (!p)
			n++;
		else {
			printf("请输入元素数值：");
			scanf("%d", &p->data);
			p->next = L->next;
			L->next = p;
			p->prior = L;
			if (!p->next)
				continue;
			p->next->prior = p;
		}
	}

	p = NULL;
	return OK;
}


Status Create_two_ways_List2(twoL L, int n)
{
	if (!L || n <= 0)
		return ERROR;

	twoL p = NULL;
	twoL rear = NULL;

	rear = L;

	while (n--)
	{
		p = (twoL)malloc(sizeof(two_ListNode));
		if (!p)
			n++;
		else
		{
			printf("请输入元素数值：");
			scanf("%d", &p->data);
			rear->next = p;
			p->prior = rear;
			rear = p;
			rear->next = NULL;
		}
	}

	rear = NULL;
	p = NULL;

	return OK;
}


Status Destroy_two_ways_List(twoL* L)
{
	if (!(*L))
		return OK;

	twoL p = NULL;

	p =* L;

	while (p)
	{
		*L = (*L)->next;
		p = NULL;
		free(p);
		p = *L;
		if (!(*L))
			break;
		(*L)->prior = NULL;
	}

	return OK;
}

//清空双向链表
Status Clear_two_ways_List(twoL L)
{
	if (!L)
		return ERROR;

	twoL p = NULL;

	p = L->next;

	while (L)
	{
		L->next = p->next;
		free(p);
		p = L->next;
		if (!L->next)
			break;
		L->next->prior = L;
	}

	return OK;
}

int two_ways_LocateElem(twoL L, ElemType e)
{
	assert(!L);

	twoL p = NULL;
	int i = 0;

	p = L;

	while (p)
	{
		if (p->data == e)
			return i;
		p = p->next;
	}

	return 0;
}

bool two_ways_IsEmpty(twoL L)
{
	assert(!L);

	if (!L->next)
		return true;
	else
		return false;
}

int two_ways_ListLength(twoL L)
{
	assert(!L);

	twoL p = NULL;
	int i = 0;

	p = L;
	while (p)
	{
		p = p->next;
		i++;
	}

	return i-1;
}

Status  GetElem_Prior(twoL L, int i, ElemType* e)
{
	if (!L)
		return ERROR;

	twoL p = NULL;
	int j = 0;

	p = L;

	while (p && j < i )
	{
		p = p->next;
		j++;
	}

	if (!p || j > i )
		return ERROR;

	*e = p->prior->data;

	return OK;
}

Status InsertElem_two_ways(twoL L, ElemType e, int i)
{
	if (!L)
		return ERROR;

	twoL p = NULL;
	twoL q = NULL;
	int j = 0;

	p = L;
	q = (twoL)malloc(sizeof(two_ListNode));

	if (!q)
		return ERROR;

	q->data = e;
	q->prior = NULL;
	q->next = NULL;

	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}

	q->prior = p;
	q->next = p->next;
	p->next = q;
	if (!q->next)
		return OK;
	q->next->prior = q;

	p = NULL;
	q = NULL;

	return OK;

}

Status Delete_two_ways_List1(twoL L, int i)
{
	if (!L)
		return ERROR;

	twoL p = NULL;
	int j = 0;

	p = L;

	while (p && j < i)
	{
		p = p->next;
		j++;
	}

	if (!p || j > i)
		return ERROR;

	p->prior->next = p->next;
	if (!p->next)
	{
		free(p);
		p = NULL;
		return OK;
	}
	p->next->prior = p->prior;
	free(p);
	p = NULL;
	return OK;
}

Status Delete_two_ways_List2(twoL L, ElemType e)
{
	if (!L)
		return ERROR;

	twoL p = NULL;

	p = L;

	while (p)
	{
		if (p->data == e)
			break;
		p = p->next;
	}

	p->prior->next = p->next;
	if(p->next)
		p->next->prior = p->prior;

	free(p);
	p = NULL;

	return OK;
}

Status CreateCircleList(ListN L,int n)
{
	if (!L)
		return ERROR;

	ListN head = NULL;
	ListN rear = NULL;
	int j = 0;

	head = L;
	rear = L;

	while (head&&j<n-1)
	{
		head = head->next;
		rear = rear->next;
		j++;
	}

	if (!head&&j > n - 1)
		return ERROR;

	while (rear)
	{
		if (!rear->next)
			break;
		rear = rear->next;
	}

	rear->next = head;

	return OK;
}