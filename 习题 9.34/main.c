#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//定义二叉树结点
typedef struct _bitree
{
    ElemType data;
    struct _bitree *lchild;
    struct _bitree *rchild;
}*bitree;

void PrintX(bitree t,int x)
{
    //递归出口，右子树不存在，并且结点的数据域不小于x,就输出该结点的数据
    //如果左子树也不存在，就可退出递归了
    //如果左子树存在，则继续搜索左子树
    if(!t->rchild)
    {
        if(t->data >= x)
            printf("%d",t->data);

        if(!t->lchild)
            return;

        else
        {
            PrintX(t->lchild,x);
        }
    }

    //如果右子树存在，就继续搜索右子树
    else
    {
        PrintX(t->rchild,x);
        //右子树搜索完成后，如果该结点的值不小于x，打印该结点的值
        if(t->data >= x)
            printf("%d",t->data);

        //如果同时左子树也存在，就继续搜索左子树
        if(t->lchild)
            PrintX(t->lchild,x);
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
