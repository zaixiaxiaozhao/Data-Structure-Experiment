#include <stdio.h>  
#define MAXSIZE 100  
                                                        //三元组的定义   
typedef struct
{
    int row, col;                                       //表示行列   
    int e;                                              //表示值   
}Triple;
  
typedef struct                                          //三元组容器的定义   
{
    Triple data[MAXSIZE];
    int m, n, len;
}TSMatrix;
        
void TransposeTSMatrix(TSMatrix A, TSMatrix* B)         //实现转置   
{
    int i, j, k,a,b;
    B->m = A.n;
    B->n = A.m;
    B->len = A.len;
    j = 0;
    for (k = 0; k <= A.len; k++)
    {
        for (i = 0; i <= A.len; i++)
        {
            if (A.data[i].col == k)
            {
                B->data[j].row = A.data[i].col;
                B->data[j].col = A.data[i].row;
                B->data[j].e = A.data[i].e;
                j++;
            }
        }
    }

}

int main()
{
    TSMatrix A, B;
    int i, j, e;
    int b;
    int k = 0;
    int a = 1;
    printf("请输入三元组：\n");
    while (a!=0)
    {
        scanf_s("%d%d%d", &i, &j, &e);
        A.data[k].row = i - 1;
        A.data[k].col = j - 1;
        A.data[k].e = e;
        k =k+1;
        A.len = k;
        printf("输出下组数据请输入1，停止输入数据请输入0\n");
        scanf_s("%d", &b);
        if (b == 1)
            printf("\n请输入三元组：\n");
        a = b;
    }
    printf("\n原始三元组为:\n");
    for (i = 0; i < A.len; ++i)
    {
        printf("%3d%3d%3d\n", A.data[i].row + 1, A.data[i].col + 1, A.data[i].e);
    }
    printf("\n转置后:\n");
    TransposeTSMatrix(A, &B);
    for (i = 0; i < B.len; i++)
    {
        printf("%3d%3d%3d\n", B.data[i].row + 1, B.data[i].col + 1, B.data[i].e);
    }
    return 0;
}
