#include<stdio.h>
#define MaxSize 20
typedef struct
{
    int key;
}RecType;
typedef struct
{
    RecType R[MaxSize + 1];
}RecList;
int BinSearch(RecList l, int key, int length)
{
    int low = 1;
    int high = length;             //置区间初值
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == l.R[mid].key)
        {
            return mid+1;//如果要查找值key == l.r[mid].key返回mid下标
        }
        else if (key < l.R[mid].key)
        {
            high = mid - 1; //未找到，把high往mid前移一位在前半区间查找
        }
        else
        {
            low = mid + 1;          //在后半区间查找
        }
    }
    return 0;
}
int main()
{
    RecList L = { 2,3,6,33,45,66,88,100 };  //初始化线性表
    if (BinSearch(L, 6, 8) == 0)
    {
        printf("没有关键字6的信息！\n");
    }
    else
    {
        printf("关键字6的位置在：%d\n", BinSearch(L, 6, 8));
    }

    if (BinSearch(L, 89, 8) == 0)
    {
        printf("没有关键字89的信息！\n");
    }
    else
    {
        printf("关键字89的位置在：%d\n", BinSearch(L, 89, 8));
    }
    return 0;
}
