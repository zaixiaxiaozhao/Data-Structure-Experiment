#include<stdio.h>
#include<math.h>
#include<time.h>
clock_t start, stop;
int main()
{
	start = clock();
	int m, n, i, k, num = 1;
	double C;
	printf("输入所求数的值：\n");
	scanf_s("%d", &m);
	printf("2 ");
	for (n = 3; n <= m; n += 2)
	{
		k = sqrt(n);       //开方省步骤
		for (i = 2; i <= k; i++)
			if (n % i == 0)break;
		if (i == k + 1)
		{
			printf("%d ", n);
			num++;
			if (num % 10 == 0)
				printf("\n");
		}
	}
	stop = clock();
	C = ((double)(stop - start)) / CLK_TCK;
	printf("%f", C);
	printf("\n统计结果：小于等于n的素数有%d个。\n", num);

	return 0;
}
