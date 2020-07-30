#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//定义二叉树结点
typedef struct _bitree
{
    ElemType data;
    struct _bitree *lchild;
    struct _bitree *rchild;
}*bitreptr;


void Exchange(bitreptr p)
{
    if(!p)
    {
        return;
    }

    else
    {
        bitreptr x;

        x = p->lchild;
        p->lchild = p->rchild;
        p->rchild = x;

        Exchange(p->lchild);
        Exchange(p->rchild);
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
