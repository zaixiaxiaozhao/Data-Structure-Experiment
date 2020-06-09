#include<stdlib.h>
#include<stdio.h>
#define MaxSize 8
typedef int ElemType;
int a[] = { 50,30,20,10,25,23,80,90 };//先序遍历
int b[] = { 10,20,23,25,30,50,80,90 };//中序遍历
typedef struct node
{
    ElemType data;
    struct node* lchild;
    struct node* rchild;
} BiTree;
BiTree* CreateBTree(ElemType a[], ElemType b[], int n)
{
    //由先序序列a[0..n-1]和中序序列b[0..n-1]建立二叉链存储结构
    if (n <= 0) return NULL;
    int root = a[0];			       //根结点值
    BiTree* bt = (BiTree*)malloc(sizeof(BiTree));
    bt->data = root;
    int k;
    for (k = 0; k < n; k++)			      //在b中查找b[k]=root的根结点
        if (b[k] == root) break;
    bt->lchild = CreateBTree(a + 1, b, k);	       //递归创建左子树
    bt->rchild = CreateBTree(a + k + 1, b + k + 1, n - k - 1);	//递归创建右子树
    return bt;
}

int Node(BiTree* b)//（1）结点个数；
{
    if (b == NULL) return 0;
    else return Node(b->lchild) + Node(b->rchild) + 1;
}
int cnt = 0;

int NodeLeaf(BiTree* b)//（2）叶子结点个数；
{
    if (b == NULL) return 0;
    else
    {
        if (b->lchild == NULL && b->rchild == NULL)
            cnt++;
        NodeLeaf(b->lchild);
        NodeLeaf(b->rchild);
    }
    return cnt;
}
int Height(BiTree* b)//（3）深度；
{
    int hlchild = 0, hrchild = 0;
    if (b == NULL) return 0;
    else
    {
        hlchild = Height(b->lchild);
        hrchild = Height(b->rchild);
        return (hlchild > hrchild) ? (hlchild + 1) : (hrchild + 1);
    }
}
//（4）先序序列、中序序列和后序序列。
void PreOrder(BiTree* b)
{
    if (b == NULL) return;
    else
    {
        printf("%d ", b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}
void InOrder(BiTree* b)
{
    if (b == NULL) return;
    else
    {
        InOrder(b->lchild);
        printf("%d ", b->data);
        InOrder(b->rchild);
    }
}
void PostOrder(BiTree* b)
{
    if (b == NULL) return;
    else
    {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%d ", b->data);
    }
}
int main()
{
    BiTree* t = CreateBTree(a, b, 8);
    printf("二叉树的结点个数为:%d\n", Node(t));
    printf("二叉树的叶子结点为:%d\n", NodeLeaf(t));
    printf("深度为:%d\n", Height(t));
    printf("先序遍历此二叉树的序列为：");
    PreOrder(t);
    printf("\n");
    printf("中序遍历此二叉树的序列为：");
    InOrder(t);
    printf("\n");
    printf("后序遍历此二叉树的序列为：");
    PostOrder(t);
    printf("\n");
    return 0;
}
