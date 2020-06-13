#include<stdio.h>  
typedef int KeyType;
typedef char InfoType;

void swap(int& x, int& y)
{
	int tmp = x;
	x = y; y = tmp;
}

void disp(int a[])						//display函数
{
	int i;

	for (i = 0; i < 12; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void insertsort(int a[], int n)         //直接插入排序
{
	int i = 0, temp = 0, j = 0;
	for (i = 1; i < n; i++)
	{

		if (a[i] < a[i - 1])
		{
			temp = a[i];
			for (j = i - 1; j >= 0 && a[j] > temp; j--)
				a[j + 1] = a[j];
			a[j + 1] = temp;
		}

	}
}

void BinInsertSort(int a[], int n)			//折半插入排序
{
	int i, j, low, high, mid;
	int tmp;
	for (i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			tmp = a[i];
			low = 0; high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (tmp < a[mid])
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (j = i - 1; j >= high + 1; j--)
				a[j + 1] = a[j];
			a[high + 1] = tmp;
		}
	}
}


void SelectSort(int a[], int n)      //选择排序
{
	int i, j, k, e;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[k])
				k = j;
		if (k != i)
		{
			e = a[i];
			a[i] = a[k];
			a[k] = e;
		}

	}
}

void BubbleSort(int a[], int n)//冒泡排序
{
	int i, j;
	bool exchange;
	for (i = 0; i < n - 1; i++)
	{
		exchange = false;
		for (j = n - 1; j > i; j--)
			if (a[j] < a[j - i])
			{
				swap(a[j], a[j - 1]);
				exchange = true;
			}
		if (!exchange)
			return;
	}
}

int partition(int a[], int s, int t)
{
	int i = s, j = t;
	int temp = a[i];
	while (i < j)
	{
		while (j > i&& a[j] >= temp)
			j--;
		a[i] = a[j];
		while (i < j && a[i] <= temp)
			i++;
		a[j] = a[i];
	}
	a[i] = temp;
	return i;
}
void QuickSort(int a[], int s, int t)		//快速排序
{
	int i;
	if (s < t)
	{
		i = partition(a, s, t);
		QuickSort(a, s, i - 1);
		QuickSort(a, i + 1, t);
	}
}

void ShellSort(int a[], int n)			//希尔排序
{
	int i, j, d;
	int temp;
	d = n / 2;
	while (d > 0)
	{
		for (i = d; i < n; i++)
		{
			temp = a[i];
			j = i - d;
			while (j >= 0 && temp < a[j])
			{
				a[j + d] = a[j];
				j = j - d;
			}
			a[j + d] = temp;
		}
		d = d / 2;
	}
}

int main()
{
	int i = 0, length = 0;
	int a[] = {3,6,2,10,1,20,88,8,5,7,4,9};
	length = sizeof(a) / sizeof(a[0]);
	insertsort(a, length);
	printf("直接插入排序结果：\n");
	disp(a);
	BinInsertSort(a, length);
	printf("折半插入排序结果：\n");
	disp(a);
	ShellSort(a, length);
	printf("希尔排序结果：\n");
	disp(a);
	BubbleSort(a, length);
	printf("冒泡排序结果：\n");
	disp(a);
	QuickSort(a, 3, 9);
	printf("快速排序结果：\n");
	disp(a);
	SelectSort(a, length);
	printf("简单选择排序结果：\n");
	disp(a);


	return 0;
}
