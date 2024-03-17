#define _CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"

int main()
{
	int number = 0;
	//ѡ��

	ListN L1 = NULL;
	//�������ͷ

	ListN t = NULL;
	//������ָ�����

	twoL L2 = NULL;
	//˫�������ͷ

	twoL T = NULL;
	//˫������ָ�����

	int i = 0;
	//λ�����

	ElemType e = 0;
	//���ݴ洢����

	do
	{

		menus();
		printf("����������Ҫ���еĲ�������ţ�");
		scanf("%d", &number);


	switch (number) {
		case 0:
			printf("�˳�\n");
			break;

		case 1:
			L1 = InitList();
			if (!L1)
				print(ERROR);
			else
				print(OK);
			break;

		case 2:
			printf("����������Ҫ���������Ľ����Ŀ��\n");
			scanf("%d", &i);
			print(CreateList1(L1, i));

			t = L1->next;
			while (t)
			{
				printf("%d ", t->data);
				t = t->next;
			}
			printf("\n");
			//���������������

			break;

		case 3:
			printf("����������Ҫ���������Ľ����Ŀ��\n");
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
				printf("�������ǿձ�\n");
			else
				printf("�������ǿձ�\n");
			//��������ֱ���˳�����
			break;

		case 7:
			printf("������ĳ���Ϊ:%d\n", ListLength(L1));
			break;

		case 8:
			printf("����������Ҫ���ҵ�Ԫ�ص�λ�ã�");
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
			printf("��������Ҫ���ҵ�Ԫ�أ�");
			scanf("%d", &e);
			i = LocateElem(L1,e);
			if (i)
				printf("��Ҫ���ҵ�Ԫ�ص�λ��Ϊ��%d\n", i);
			else
				printf("�����޷����ҵ���Ԫ�ص�λ��\n");
			break;

		case 10:
			printf("��ֱ�������Ҫ�����Ԫ�ص�λ�ü�Ԫ��ֵ��");
				scanf("%d %d", &i, &e);
				print(InsertElem(L1, e, i));
			break;

		case 11:
			printf("��������Ҫɾ����Ԫ�أ�");
			scanf("%d", &e);
			print(DeleteElem1(L1, e));
			break;

		case 12:
			printf("��������Ҫɾ����Ԫ�ص�λ�ã�");
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
			//����ǰ��Ա�

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
				printf("�������е����ֵ�ֱ�Ϊ��%d %d\n", t->data, t->next->data);
			else
				printf("�������е����ֵΪ��%d\n", t->data);
			break;

		case 15:
			if (IsCircle_List(L1))
				printf("������ɻ�\n");
			else
				printf("������Ϊ������\n");
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
			printf("����������Ҫ���������Ľ����Ŀ��\n");
			scanf("%d", &i);
			print(Create_two_ways_List1(L2, i));

			break;

		case 20:
			printf("����������Ҫ���������Ľ����Ŀ��\n");
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
			printf("��������Ҫ���ҵ�Ԫ�غ�̵�λ�ã�");
			scanf("%d", &i);
			if (GetElem_Prior(L2, i, &e))
			{
				print(OK);
				printf("��ǰ��Ԫ��Ϊ��%d", e);
			}
			else
			{
				print(ERROR);
			}
			break;

		case 24:
			printf("��ֱ�������Ҫ�����Ԫ�ص�λ�ü�Ԫ��ֵ��");
			scanf("%d %d", &i, &e);
			print(InsertElem_two_ways(L2,e,i));
			break;

		case 26:
			printf("��������Ҫɾ����Ԫ�ص�λ�ã�");
			scanf("%d", &i);
			print(Delete_two_ways_List1(L2, i));
			break;

		case 25:
			printf("��������Ҫɾ����Ԫ�أ�");
			scanf("%d", &e);
			print(Delete_two_ways_List2(L2, e));
			break;

		case 27:
			printf("������ѭ������㣺");
			scanf("%d", &i);
			print(CreateCircleList(L1, i));
			break;

		default:
			printf("���������\n");
			break;

		}

	}while (number);

	return 0;
}