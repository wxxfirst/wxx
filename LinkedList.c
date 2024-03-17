#define _CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"

int main()
{
	int number = 0;
	//选项

	ListN L1 = NULL;
	//单链表表头

	ListN t = NULL;
	//单链表指针变量

	twoL L2 = NULL;
	//双向链表表头

	twoL T = NULL;
	//双向链表指针变量

	int i = 0;
	//位序变量

	ElemType e = 0;
	//数据存储变量

	do
	{

		menus();
		printf("请输入你想要进行的操作的序号：");
		scanf("%d", &number);


	switch (number) {
		case 0:
			printf("退出\n");
			break;

		case 1:
			L1 = InitList();
			if (!L1)
				print(ERROR);
			else
				print(OK);
			break;

		case 2:
			printf("请输入你需要构造的链表的结点数目：\n");
			scanf("%d", &i);
			print(CreateList1(L1, i));

			t = L1->next;
			while (t)
			{
				printf("%d ", t->data);
				t = t->next;
			}
			printf("\n");
			//输出链表数据排列

			break;

		case 3:
			printf("请输入你需要构造的链表的结点数目：\n");
			scanf("%d", &i);
			print(CreateList2(L1, i));

			t = L1->next;
			while (t)
			{
				printf("%d ", t->data);
				t = t->next;
			}
			printf("\n");
			break;

		case 4:
			print(DestroyList(&L1));
			break;

		case 5:
			print(ClearList(L1));
			break;

		case 6:
			if (List_IsEmpty(L1))
				printf("该链表是空表\n");
			else
				printf("该链表不是空表\n");
			//链表不存在直接退出程序
			break;

		case 7:
			printf("该链表的长度为:%d\n", ListLength(L1));
			break;

		case 8:
			printf("请输入你需要查找的元素的位置：");
			scanf("%d", &i);

			if (GetElem(L1,i,&e))
			{
				print(OK);
				printf("%d\n", e);
			}
			else
			{
				print(ERROR);
			}
			break;

		case 9:
			printf("请输入你要查找的元素：");
			scanf("%d", &e);
			i = LocateElem(L1,e);
			if (i)
				printf("你要查找的元素的位置为：%d\n", i);
			else
				printf("链表无法查找到该元素的位置\n");
			break;

		case 10:
			printf("请分别输入你要插入的元素的位置及元素值：");
				scanf("%d %d", &i, &e);
				print(InsertElem(L1, e, i));
			break;

		case 11:
			printf("请输入你要删除的元素：");
			scanf("%d", &e);
			print(DeleteElem1(L1, e));
			break;

		case 12:
			printf("请输入你要删除的元素的位置：");
			scanf("%d", &i);
			print(DeleteElem2(L1, i));
			break;

		case 13:
			t = L1;
			while (t->next)
			{
				printf("%d ", t->data);
				t = t->next;
			}

			print(Exchange(L1));
			//交换前后对比

			t = L1;
			while (t->next)
			{
				printf("%d ", t->data);
				t = t->next;
			}
			break;

		case 14:
			t = LocateMidpoint(L1);
			if (ListLength(L1) % 2 == 0)
				printf("该链表中点的数值分别为：%d %d\n", t->data, t->next->data);
			else
				printf("该链表中点的数值为：%d\n", t->data);
			break;

		case 15:
			if (IsCircle_List(L1))
				printf("该链表成环\n");
			else
				printf("该链表为单链表\n");
			break;

		case 16:
			t = L1;
			while (t->next)
			{
				printf("%d ", t->data);
				t = t->next;
			}

			t = ReverseList1(L1);
			while (t->next)
			{
				printf("%d ", t->data);
				t = t->next;
			}
			break;

		case 17:
			t = L1;
			while (t->next)
			{
				printf("%d ", t->data);
				t = t->next;
			}

			t = ReverseList2(NULL, L1);
			while (t->next)
			{
				printf("%d ", t->data);
				t = t->next;
			}
			break;

		case 18: 
			L2 = Init_two_ways_List();
			if (!L2)
				print(ERROR);
			else
				print(OK);
			break;

		case 19:
			printf("请输入你需要构造的链表的结点数目：\n");
			scanf("%d", &i);
			print(Create_two_ways_List1(L2, i));

			break;

		case 20:
			printf("请输入你需要构造的链表的结点数目：\n");
			scanf("%d", &i);
			print(Create_two_ways_List2(L2, i));

			break;

		case 21:
			print(Destroy_two_ways_List(&L2));
			break;

		case 22:
			print(Clear_two_ways_List(L2));
			break;

		case 23:
			printf("请输入你要查找的元素后继的位置：");
			scanf("%d", &i);
			if (GetElem_Prior(L2, i, &e))
			{
				print(OK);
				printf("该前驱元素为：%d", e);
			}
			else
			{
				print(ERROR);
			}
			break;

		case 24:
			printf("请分别输入你要插入的元素的位置及元素值：");
			scanf("%d %d", &i, &e);
			print(InsertElem_two_ways(L2,e,i));
			break;

		case 26:
			printf("请输入你要删除的元素的位置：");
			scanf("%d", &i);
			print(Delete_two_ways_List1(L2, i));
			break;

		case 25:
			printf("请输入你要删除的元素：");
			scanf("%d", &e);
			print(Delete_two_ways_List2(L2, e));
			break;

		case 27:
			printf("请输入循环的起点：");
			scanf("%d", &i);
			print(CreateCircleList(L1, i));
			break;

		default:
			printf("你输入错误！\n");
			break;

		}

	}while (number);

	return 0;
}