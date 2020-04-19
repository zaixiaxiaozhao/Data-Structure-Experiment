#include<stdio.h>
#define Size 20
typedef struct Table                            //自定义顺序表
{
	int* head;
	int length;
	int size;
}table;

table initTable()                               //初始化表
{
	table t;
	t.head = (int*)malloc(Size * sizeof(int));
	if (!t.head)
	{
		print("初始化失败");
		exit(0);
	}
	t.length = 0;
	t.size = Size;
	return t;
}

void displayTable(table t)						//输出顺序表中元素
{
	for (int i = 0; i < t.length; i++)
	{
		printf("%d ", t.head[i]);
	}
	printf("/n");
}

void Maximum(table t)							//输出顺序表中的最大值
{
	int max = t.head[0];
	for (int i = 1; i < t.length; i++)
	{
		if (t.head[i] > max)
			max = t.head[i];
	}
	printf("顺序表中的最大值为%d/n", max);
}

void Minimum(table t)							//输出顺序表中的最小值
{
	int min = t.head[0];
	for (int i = 1; i < t.length; i++)
	{
		if (t.head[i] < min)
			min = t.head[i];
	}
	printf("顺序表中的最小值为%d/n", min);
}

int LocateElem(table t, int elem)				//查找数值返回信息
{
	for (int i = 0; i < t.length; i++)
	{
		if (t.head[i] == elem)
			return("/n该数值在表中的第%d位/n", i);
	}
	return("/n该数值不在表中/n");
}

table delTable(table t, int add)					//删除元素
{
	if (add > t.length || add < 1) {
		printf("被删除元素的位置有误/n");
		exit(0);
	}
	for (int i = add; i < t.length; i++)
		t.head[i - 1] = t.head[i];
	t.length--;
	return t;
}

table addTable(table t, int elem, int add)		//插入元素
{
	if (add > t.length + 1 || add < 1) {
		printf("插入位置有问题");
		return t;
	}
	if (t.length == t.size) {
		t.head = (int*)realloc(t.head, (t.size + 1) * sizeof(int));
		if (!t.head) {
			printf("存储分配失败");
			return t;
		}
		t.size += 1;
	}
	for (int i = t.length - 1; i >= add - 1; i--)
	{
		t.head[i + 1] = t.head[i];
	}
	t.head[add - 1] = elem;
	t.length++;
}

int main()
{
	int elem;
	table t = initTable();
	for (int i = 1; i <= 10; i++)				//向顺序表中添加元素
	{
		t.head[i - 1] = i * 10;
		t.length++;
	}

	//（1）输出顺序表中的所有元素；
	printf("原顺序表：");
	displayTable(t);
	printf("/n");

	//（2）输出顺序表中的最大值和最小值；
	printf("顺序表中的最大值和最小值");
	Maximum(t);
	Minimum(t);
	printf("/n");

	//（3）键盘输入一个数x，如x在表中返回其在表中的位序，不在返回相应提示信息。
	printf("查找元素位置/n");
	printf("请输入您要查找的数：");
	scanf_s("%d", &elem);
	LocateElem(t, elem);

	//（4）删除顺序表中的第8个元素，并输出顺序表中的所有元素；
	printf("删除第8个元素/n");
	delTable(t, 8);
	displayTable(t);

	//（5）在第5个元素后面插入新元素55，并输出顺序表中的所有元素；
	printf("在第5个元素后面插入新元素55/n");
	addTable(t, 55, 5);
	displayTable(t);

	//（6）输出顺序表的长度。* /
	printf("顺序表的长度为%d/n：", t.length);
	return 0;
}
