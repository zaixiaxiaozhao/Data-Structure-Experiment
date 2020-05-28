#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNote;
typedef struct LNode {			
	ElemType data;
	struct LNode* next;			//指向后继节点	
}LinkNode;						//声明单链表节点类型

ElemType n = 10;
ElemType a[] = { 10,20,30,40,50,60,70,80,90,100 };

void CreateList(LinkNode*&L, ElemType a[], ElemType n)			//头插法建立单链表
{
	LinkNode* s;
	int i;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (i = n-1; i >=0; i--)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void Display(LinkNode* L)			//输出单链表
{
	while (L->next != NULL)
	{
		L = L->next;
		printf("%d ", L->data);
	}
	printf("\n");
}

void MaxMinList(LinkNode* L)			//输出单链表中的最大值和最小值
{
	int max, min;
	max = min = L->next->data;
	while (L->next != NULL)
	{
		L = L->next;
		min = min > L->data ? L->data : min;
		max = max < L->data ? L->data : max;
	}
	printf("最大值最小值分别为: %d  %d\n", max, min);
}

void LocList(LinkNode* L, int x)		//键盘输入一个值x，输出链表中第一个值为x的元素的位序
{
	int a = 0;
	while (L->next != NULL)
	{
		L = L->next;
		a++;
		if (L->data == x)
		{
			printf("查找的数的位置为第%d位\n", a);
			return;
		}
	}
	printf("此数不在链表中");
}

void InterData(LinkNode* L, int b)		//（4）键盘输入一位序值b，在第b个元素之前插入值为500的元素，输出链表中的所有数据；
{
	if (b > n)
	{
		printf("超出范围");
		return;
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	for (int i = 1; i <= b; i++){L = L->next;}
	s->next = L->next;
	L->next = s;
	n++;
	s->data = 500;
}

void DeleteE(LinkNode* L, int m)  //键盘输入位序值m，删除位序为m的元素，输出链表中的所有数据；
{

	if (m > n)
	{
		printf("超出范围");;
		return;
	}
	for (int i = 1; i < m; i++)
	{
		L = L->next;
	}
	LinkNode* t = L->next->next;
	free(L->next);
	L->next = t;
	n--;
}

int main()
{
	LinkNode* L;
	//（1）头插法或尾插法建立单链表，并输出单链表中所有元素；	
	CreateList(L, a, n);		
	Display(L);

	//（2）输出单链表中的最大值和最小值；
	MaxMinList(L);

	//（3）键盘输入一个值x，输出链表中第一个值为x的元素的位序；
	int x;
	printf("输入你要查找的数值\n");
	scanf_s("%d", &x);
	LocList(L, x);

	//（4）键盘输入一位序值b，在第b个元素之前插入值为500的元素，输出链表中的所有数据；
	printf("输入你将数值插入的序值\n");
	int n,m;
	scanf_s("%d", &n);
	InterData(L, n - 1);
	printf("当前链表为\n");
	Display(L);

	//（5）键盘输入位序值m，删除位序为m的元素，输出链表中的所有数据；
	printf("输入你将数值删除的序值\n");
	scanf_s("%d", &m);
	DeleteE(L, m);
	printf("当前链表为\n");
	Display(L);

	//（6）输出单链表的长度。
	printf("此时的长度为:\%d\n", n);
	return 0;
}
