#include <stdio.h>
#define Maxsize 20
typedef struct
{
	char data[Maxsize];
	int len;
}Sqstring;
char str1[Maxsize];
char str2[Maxsize];

void Strassign(Sqstring &s, char str[])
{
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		s.data[i] = str[i];
		s.len = i;
	}
}
void BF(Sqstring s, Sqstring t)
{
	int i = 0, j = 0;
	while (i < s.len && j < t.len)
	{
		if (s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.len)
		printf("%d\n", i - t.len + 1);
	else
		printf("匹配不成功");
}
int main()
{
	Sqstring s1, s2;
	printf("请输入主串：\n");
	scanf_s("%s", str1, sizeof(str1));
	Strassign(s1, str1);
	printf("请输入子串：\n");
	scanf_s("%s", str2, sizeof(str2));
	Strassign(s2, str2);
	BF(s1, s2);
}
